#ifndef BRICKS_EVENTS_H
#define BRICKS_EVENTS_H

#include <ArduinoLog.h>
#include <PubSubClient.h>
#ifdef ESP8266
#include <ESP8266WiFi.h>
#elif ESP32
#include <WiFi.h>
#endif

#include <Bricks.Constants.h>
#include <Bricks.Message.h>
#include <Bricks.Outbox.h>
#include <Bricks.Utils.h>

// Define in secrets.h file
#ifndef SECRETS_H
#define BRICKS_WIFI_SSID "SSID"
#define BRICKS_WIFI_PASSWORD "PASSWORD"
#define BRICKS_MQTT_HOST "mqtt.host.com"
#define BRICKS_MQTT_CLIENT "bricks"
#define BRICKS_MQTT_USER "user"
#define BRICKS_MQTT_PASSWORD "password"
#define BRICKS_MQTT_TOPIC_PREFIX "accounts/name/bricks"
#endif

#define BRICKS_MESSAGES_IN BRICKS_MQTT_TOPIC_PREFIX "/in"
#define BRICKS_MESSAGES_OUT BRICKS_MQTT_TOPIC_PREFIX "/out"
#define BRICKS_MESSAGES_SCAN BRICKS_MQTT_TOPIC_PREFIX "/gateway/scan"

namespace Bricks {
  class Events {
    static const uint16_t MAX_TOPIC_SIZE = 200;

    public:
      Events() : mqtt(wifi) {}
      void init();
      void loop();
      void publish(const uint8_t *macAddr, Message message);
      void publish(const uint8_t *macAddr, const char *key, const char *value = "");
      void publish(const char *topic, const char *value = "");
      static void onEvent(char *topic, byte *bytes, unsigned int length);
      static void parseTopic(const char *topic, uint8_t *macAddr, char *key);
    private:
      WiFiClient wifi;
      PubSubClient mqtt;
      void connectWiFi();
      void connectMQTT();
      void subscribe(const char *topic);
      static void scanForBricks();
  };

  extern Events gEvents;
}
#endif
