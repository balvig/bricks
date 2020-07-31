#include "Bricks.Events.h"

namespace Bricks {
  void Events::init() {
    mqtt.setServer(BRICKS_MQTT_HOST, 1883);
    mqtt.setCallback(Events::onEvent);

    connectWiFi();
    connectMQTT();
  }

  void Events::loop() {
    if (mqtt.connected()) {
      mqtt.loop();
    }
    else {
      Log.warning("MQTT: disconnected" CR);
      connectMQTT();
    }
  }

  void Events::publish(const uint8_t *macAddr, Message message) {
    publish(macAddr, message.key, message.value);
  }

  void Events::publish(const uint8_t *macAddr, const char *key, const char *value) {
    char macStr[MAC_STR_SIZE];
    Bricks::Utils::macToStr(macAddr, macStr);
    char topic[MAX_TOPIC_SIZE];
    sprintf(topic, BRICKS_MESSAGES_IN "/%s/%s", macStr, key);
    publish(topic, value);
  }

  void Events::publish(const char *topic, const char *value) {
    if (mqtt.connected()) {
      Log.notice("MQTT: -> %s: %s" CR, topic, value);
      mqtt.publish(topic, value);
    }
    else {
      Log.error("MQTT: Publishing failed [disconnected]" CR);
    }
  }

  void Events::onEvent(char *topic, byte *bytes, unsigned int length) {
    bytes[length] = '\0';
    char *value = (char *) bytes;
    Log.notice("MQTT: <- %s: %s" CR, topic, value);

    if(strcmp(BRICKS_MESSAGES_SCAN, topic) == 0) {
      scanForBricks();
    }
    else {
      uint8_t macAddr[MAC_ADDR_SIZE];
      char key[KEY_SIZE];
      parseTopic(topic, macAddr, key);
      gOutbox.send(macAddr, key, value);
    }
  }

  void Events::parseTopic(const char *topic, uint8_t *macAddr, char *key) {
    sscanf(topic, BRICKS_MESSAGES_OUT "/" MAC_FORMAT "/%s",
        &macAddr[0], &macAddr[1], &macAddr[2], &macAddr[3], &macAddr[4], &macAddr[5], key);
  }

  void Events::connectWiFi() {
    Log.notice("WIFI: Connecting [%s]", BRICKS_WIFI_SSID);
    WiFi.begin(BRICKS_WIFI_SSID, BRICKS_WIFI_PASSWORD);

    while(WiFi.status() != WL_CONNECTED) {
      delay(500);
      Log.notice(".");
    }
    Log.notice(CR "WIFI: Connected [%s]" CR, WiFi.localIP().toString().c_str());
  }

  void Events::connectMQTT() {
    Log.notice("MQTT: Connecting" CR);
    while(!mqtt.connected()) {
      if(mqtt.connect(BRICKS_MQTT_CLIENT, BRICKS_MQTT_USER, BRICKS_MQTT_PASSWORD)) {
        Log.notice("MQTT: Connected" CR);
        subscribe(BRICKS_MESSAGES_OUT "/#");
        subscribe(BRICKS_MESSAGES_SCAN);
      }
      else {
        Log.warning("MQTT: Failed [%s]. Retrying in 5 secs" CR, mqtt.state());
        delay(5000);
      }
    }
  }

  void Events::subscribe(const char *topic) {
    mqtt.subscribe(topic);
    Log.notice("MQTT: Subscribed [%s]" CR, topic);
  }

  void Events::scanForBricks() {
    Log.notice("WIFI: Scanning for Bricks" CR);
    const uint8_t scanResults = WiFi.scanNetworks();

    for(int i = 0; i < scanResults; ++i) {
      if(WiFi.SSID(i).indexOf(BRICKS_NAME_PREFIX) == 0) {
        Log.notice("WIFI: Brick found on channel %d" CR, WiFi.channel(i));
        gOutbox.send(WiFi.BSSID(i), BRICKS_PING_ACTION);
      }
    }

    WiFi.scanDelete();
    Log.notice("WIFI: Scan complete" CR);
    gEvents.publish(BRICKS_MESSAGES_SCAN "/done");
  }

  Events gEvents = Events();
}
