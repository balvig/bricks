#include "Bricks.Events.h"

namespace Bricks {
  void Events::init(const char *wifiSSID, const char *wifiPassword, const char *mqttHost, const char *mqttClient, const char *mqttUser, const char *mqttPassword, const char *topicPrefix) {
    this->mqttClient = mqttClient;
    this->mqttUser = mqttUser;
    this->mqttPassword = mqttPassword;
    this->topicPrefix = topicPrefix;

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
      Log.notice("MQTT disconnected");
      connectMQTT();
    }
  }

  void Events::publish(const uint8_t *macAddr, Message message) {
    //TODO: Look into this for crashiness
    if (mqtt.connected()) {
      char macStr[Bricks::Utils::MAC_STR_SIZE];
      Bricks::Utils::macToStr(macAddr, macStr);
      char topic[MAX_TOPIC_SIZE];
      sprintf(topic, "%s/" BRICKS_MESSAGES_IN "/%s/%s", topicPrefix, macStr, message.key);

      Log.notice("Publishing %s: %s", topic, message.value);

      mqtt.publish(topic, message.value);
    }
    else {
      Log.warning("Attempted to publish but mqtt wasn't connected");
    }
  }

  void Events::publish(const uint8_t *macAddr, const char *key, const char *value) {
    Message message;
    strcpy(message.key, key);
    strcpy(message.value, value);
    publish(macAddr, message);
  }

  void Events::onEvent(char *topic, byte *bytes, unsigned int length) {
    //TODO: Look into this for crashiness
    Log.notice("Event received: %s", topic);

    bytes[length] = '\0';
    char *value = (char *) bytes;
    uint8_t macAddr[Bricks::Utils::MAC_ADDR_SIZE];
    char key[20]; // TODO: Repeated from Bricks.Message.h
    Bricks::Utils::parseTopic(topic, macAddr, key);

    gOutbox.send(macAddr, key, value);
  }

  void Events::connectWiFi(const char *ssid, const char *password) {
    Log.notice("Connecting to: %s", ssid);
    WiFi.begin(ssid, password);

    while(WiFi.status() != WL_CONNECTED) {
      delay(500);
      Log.notice("Still connecting...");
    }
    Log.notice("Connected. IP: %s", WiFi.localIP().toString().c_str());
  }

  void Events::connectMQTT() {
    while(!mqtt.connected()) {
      Log.notice("Connecting MQTT");

      if(mqtt.connect(mqttClient, mqttUser, mqttPassword)) {
        Log.notice("Connected");
        char topic[MAX_TOPIC_SIZE];
        sprintf(topic, "%s/" BRICKS_MESSAGES_OUT "/#", topicPrefix);
        Log.notice("Subscribing %s", topic);
        mqtt.subscribe(topic);
      }
      else {
        Log.warning("Failed, rc= %s", mqtt.state());
        Log.warning("Retrying in 5 secs");
        delay(5000);
      }
    }
  }
  Events gEvents = Events();
}
