#include "Bricks.PublishSkill.h"

namespace Bricks {
  PublishSkill::PublishSkill() : Skill("*", nullptr, false), mqtt(wifi) {
    mqtt.setServer(BRICKS_MQTT_HOST, 1883);
    mqtt.setCallback(PublishSkill::onEvent);

    connectWiFi();
    connectMQTT();
    publish(BRICKS_MESSAGES_IN "/gateway/awake");
  }

  void PublishSkill::callback(BRICKS_CALLBACK_SIGNATURE) {
    publish(macAddr, message);
  }

  void PublishSkill::loop() {
    if (mqtt.connected()) {
      mqtt.loop();
    }
    else {
      Log.warning("MQTT: disconnected" CR);
      connectMQTT();
    }
#ifdef ESP32
    delay(25); // https://github.com/knolleary/pubsubclient/issues/55#issuecomment-677787979
#endif
  }

  void PublishSkill::onEvent(char *topic, byte *bytes, unsigned int length) {
    bytes[length] = '\0';
    char *value = (char *) bytes;
    Log.trace("MQTT: <- %s: %s" CR, topic, value);

    uint8_t macAddr[MAC_ADDR_SIZE];
    char key[KEY_SIZE];
    parseTopic(topic, macAddr, key);
    gOutbox.send(macAddr, key, value);
  }

  void PublishSkill::parseTopic(const char *topic, uint8_t *macAddr, char *key) {
    sscanf(topic, BRICKS_MESSAGES_OUT "/" MAC_FORMAT "/%s",
        &macAddr[0], &macAddr[1], &macAddr[2], &macAddr[3], &macAddr[4], &macAddr[5], key);
  }

  void PublishSkill::publish(const uint8_t *macAddr, Message message) {
    publish(macAddr, message.key, message.value);
  }

  void PublishSkill::publish(const uint8_t *macAddr, const char *key, const char *value) {
    char macStr[MAC_STR_SIZE];
    Bricks::Utils::macToStr(macAddr, macStr);
    char topic[MAX_TOPIC_SIZE];
    sprintf(topic, BRICKS_MESSAGES_IN "/%s/%s", macStr, key);
    publish(topic, value);
  }

  void PublishSkill::publish(const char *topic, const char *value) {
    if (mqtt.connected()) {
      Log.trace("MQTT: -> %s: %s" CR, topic, value);
      mqtt.publish(topic, value);
    }
    else {
      Log.error("MQTT: Publishing failed [disconnected]" CR);
    }
  }

  void PublishSkill::connectWiFi() {
    Log.notice("WIFI: Connecting to [%s]" CR, BRICKS_WIFI_SSID);
    WiFi.begin(BRICKS_WIFI_SSID, BRICKS_WIFI_PASSWORD);

    while(WiFi.status() != WL_CONNECTED) {
      delay(500);
      Log.trace("WIFI: Still connecting..." CR);
    }
    Log.notice("WIFI: Connected [%s] [Channel %d]" CR, WiFi.localIP().toString().c_str(), WiFi.channel());

    if(WiFi.channel() != BRICKS_WIFI_CHANNEL) {
      Log.error("WIFI: Bricks currently requires WiFi on channel %d", BRICKS_WIFI_CHANNEL);
    }
  }

  void PublishSkill::connectMQTT() {
    Log.notice("MQTT: Connecting to [%s]" CR, BRICKS_MQTT_HOST);
    while(!mqtt.connected()) {
      if(mqtt.connect(BRICKS_MQTT_CLIENT, BRICKS_MQTT_USER, BRICKS_MQTT_PASSWORD)) {
        Log.notice("MQTT: Connected" CR);
        subscribe(BRICKS_MESSAGES_OUT "/#");
      }
      else {
        Log.warning("MQTT: Failed [%s]. Retrying in 5 secs" CR, mqtt.state());
        delay(5000);
      }
    }
  }

  void PublishSkill::subscribe(const char *topic) {
    mqtt.subscribe(topic);
    Log.trace("MQTT: Subscribed [%s]" CR, topic);
  }
}
