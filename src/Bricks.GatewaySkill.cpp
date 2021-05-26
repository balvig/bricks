#include "Bricks.GatewaySkill.h"

namespace Bricks {
  GatewaySkill::GatewaySkill() : Skill("*", nullptr, false), mqtt(wifi) {
    mqtt.setServer(BRICKS_MQTT_HOST, 1883);
    mqtt.setCallback(GatewaySkill::onEvent);

    connectWiFi();
    connectMQTT();
  }

  void GatewaySkill::callback(BRICKS_CALLBACK_SIGNATURE) {
    publish(macAddr, message);
  }

  void GatewaySkill::loop() {
    if (mqtt.connected()) {
      mqtt.loop();
    }
    else {
      Log.warningln("MQTT: disconnected");
      connectMQTT();
    }
#ifdef ESP32
    delay(25); // https://github.com/knolleary/pubsubclient/issues/55#issuecomment-677787979
#endif
  }

  void GatewaySkill::onEvent(char *topic, byte *bytes, unsigned int length) {
    bytes[length] = '\0';
    char *value = (char *) bytes;
    Log.traceln("MQTT: <- %s: %s", topic, value);

    uint8_t macAddr[MAC_ADDR_SIZE];
    char key[KEY_SIZE];
    parseTopic(topic, macAddr, key);
    gOutbox.send(macAddr, key, value);
  }

  void GatewaySkill::parseTopic(const char *topic, uint8_t *macAddr, char *key) {
    sscanf(topic, BRICKS_MESSAGES_OUT "/" MAC_FORMAT "/%20s",
        &macAddr[0], &macAddr[1], &macAddr[2], &macAddr[3], &macAddr[4], &macAddr[5], key);
  }

  void GatewaySkill::publish(const uint8_t *macAddr, Message message) {
    publish(macAddr, message.key, message.value);
  }

  void GatewaySkill::publish(const uint8_t *macAddr, const char *key, const char *value) {
    char macStr[MAC_STR_SIZE];
    Bricks::Utils::macToStr(macAddr, macStr);
    char topic[MAX_TOPIC_SIZE];
    sprintf(topic, BRICKS_MESSAGES_IN "/%s/%s", macStr, key);
    publish(topic, value);
  }

  void GatewaySkill::publish(const char *topic, const char *value) {
    if (mqtt.connected()) {
      Log.traceln("MQTT: -> %s: %s", topic, value);
      mqtt.publish(topic, value);
    }
    else {
      Log.errorln("MQTT: Publishing failed [disconnected]");
    }
  }

  void GatewaySkill::connectWiFi() {
    Log.noticeln("WIFI: Connecting to [%s]", BRICKS_WIFI_SSID);
    WiFi.begin(BRICKS_WIFI_SSID, BRICKS_WIFI_PASSWORD);

    while(WiFi.status() != WL_CONNECTED) {
      delay(500);
      Log.traceln("WIFI: Still connecting...");
    }
    Log.noticeln("WIFI: Connected [%s] [Channel %d]", WiFi.localIP().toString().c_str(), WiFi.channel());

    if(WiFi.channel() != BRICKS_WIFI_CHANNEL) {
      Log.error("WIFI: Bricks currently requires WiFi on channel %d", BRICKS_WIFI_CHANNEL);
    }
  }

  void GatewaySkill::connectMQTT() {
    Log.noticeln("MQTT: Connecting to [%s]", BRICKS_MQTT_HOST);
    while(!mqtt.connected()) {
      if(mqtt.connect(BRICKS_MQTT_CLIENT, BRICKS_MQTT_USER, BRICKS_MQTT_PASSWORD)) {
        Log.noticeln("MQTT: Connected");
        subscribe(BRICKS_MESSAGES_OUT "/#");
      }
      else {
        Log.warningln("MQTT: Failed [%d]. Retrying in 5 secs", mqtt.state());
        delay(5000);
      }
    }
  }

  void GatewaySkill::subscribe(const char *topic) {
    mqtt.subscribe(topic);
    Log.traceln("MQTT: Subscribed [%s]", topic);
  }
}
