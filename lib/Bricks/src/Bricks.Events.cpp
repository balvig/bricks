#include "Bricks.Events.h"

namespace Bricks {
  void Events::init(const char *wifiSSID, const char *wifiPassword, const char *mqttHost, const char *mqttClient, const char *mqttUser, const char *mqttPassword) {
    this->mqttClient = mqttClient;
    this->mqttUser = mqttUser;
    this->mqttPassword = mqttPassword;

    mqtt.setServer(mqttHost, 1883);
    mqtt.setBufferSize(1024); // Extract to global var
    mqtt.setCallback(Events::onEvent); // How to capture this?

    connectWiFi(wifiSSID, wifiPassword);
    connectMQTT();
  }

  void Events::loop() {
    if (mqtt.connected()) {
      mqtt.loop();
    }
    else {
      Log.warning("MQTT: disconnected");
      connectMQTT();
    }
  }

  void Events::publish(const uint8_t *macAddr, Message message) {
    if (mqtt.connected()) {
      char macStr[MAC_STR_SIZE];
      Bricks::Utils::macToStr(macAddr, macStr);
      char topic[MAX_TOPIC_SIZE];
      sprintf(topic, BRICKS_MESSAGES_IN "/%s/%s", macStr, message.key);

      Log.notice("MQTT: -> %s: %s", topic, message.value);
      mqtt.publish(topic, message.value);
    }
    else {
      Log.error("MQTT: Publishing failed [disconnected]");
    }
  }

  void Events::publish(const uint8_t *macAddr, const char *key, const char *value) {
    Message message;
    strcpy(message.key, key);
    strcpy(message.value, value);
    publish(macAddr, message);
  }

  void Events::onEvent(char *topic, byte *bytes, unsigned int length) {
    bytes[length] = '\0';
    char *value = (char *) bytes;
    uint8_t macAddr[MAC_ADDR_SIZE];
    char key[20]; // TODO: Repeated from Bricks.Message.h
    parseTopic(topic, macAddr, key);

    Log.notice("MQTT: <- %s: %s", topic, value);
    gOutbox.send(macAddr, key, value);
  }

  void Events::parseTopic(const char *topic, uint8_t *macAddr, char *key) {
    sscanf(topic, BRICKS_MESSAGES_OUT "/" MAC_FORMAT "/%s",
        &macAddr[0], &macAddr[1], &macAddr[2], &macAddr[3], &macAddr[4], &macAddr[5], key);
  }

  void Events::connectWiFi(const char *ssid, const char *password) {
    Log.notice("WIFI: Connecting [%s]", ssid);
    WiFi.begin(ssid, password);

    while(WiFi.status() != WL_CONNECTED) {
      delay(500);
      Log.notice("WIFI: Still connecting...");
    }
    Log.notice("WIFI: Connected [%s]", WiFi.localIP().toString().c_str());
  }

  void Events::connectMQTT() {
    while(!mqtt.connected()) {
      Log.notice("MQTT: Connecting");

      if(mqtt.connect(mqttClient, mqttUser, mqttPassword)) {
        Log.notice("MQTT: Connected");
        Log.notice("MQTT: Subscribing [" BRICKS_MESSAGES_OUT "/#]");
        mqtt.subscribe(BRICKS_MESSAGES_OUT "/#");
      }
      else {
        Log.warning("MQTT: Failed [%s]", mqtt.state());
        Log.warning("MQTT: Retrying in 5 secs");
        delay(5000);
      }
    }
  }
  Events gEvents = Events();
}
