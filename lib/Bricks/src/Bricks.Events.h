#ifndef BRICKS_EVENTS_H
#define BRICKS_EVENTS_H

#include <ArduinoLog.h>
#include <PubSubClient.h>
#ifdef ESP8266
#include <ESP8266WiFi.h>
#elif ESP32
#include <WiFi.h>
#endif

#include <Bricks.Message.h>
#include <Bricks.Outbox.h>
#include <Bricks.Utils.h>

#define BRICKS_MESSAGES_IN "in"
#define BRICKS_MESSAGES_OUT "out"

namespace Bricks {
  class Events {
    static const uint16_t MAX_TOPIC_SIZE = 200;

    public:
      Events() : mqtt(wifi) {}
      void init(const char *wifiSSID, const char *wifiPassword, const char *mqttHost, const char *mqttClient, const char *mqttUser, const char *mqttPassword, const char *topicPrefix = "bricks");
      void loop();
      void publish(const uint8_t *macAddr, Message message);
      void publish(const uint8_t *macAddr, const char *key, const char *value = "");
      static void onEvent(char *topic, byte *bytes, unsigned int length);
    private:
      WiFiClient wifi;
      PubSubClient mqtt;
      const char *mqttClient;
      const char *mqttUser;
      const char *mqttPassword;
      const char *topicPrefix;
      void connectWiFi(const char *ssid, const char *password);
      void connectMQTT();
  };

  extern Events gEvents;
}
#endif
