#ifndef BRICKS_PUBLISH_SKILL_H
#define BRICKS_PUBLISH_SKILL_H

#include <ArduinoLog.h>

#include <PubSubClient.h>
#ifdef ESP8266
#include <ESP8266WiFi.h>
#elif ESP32
#include <WiFi.h>
#endif

#include <Bricks.Skill.h>
#include <Bricks.Outbox.h>

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

namespace Bricks {
  class PublishSkill : public Skill {
    static const uint16_t MAX_TOPIC_SIZE = 200;

    public:
      PublishSkill();
      void callback(BRICKS_CALLBACK_SIGNATURE);
      void loop();
      static void onEvent(char *topic, byte *bytes, unsigned int length);
      static void parseTopic(const char *topic, uint8_t *macAddr, char *key);
    private:
      WiFiClient wifi;
      PubSubClient mqtt;
      void connectWiFi();
      void connectMQTT();
      void publish(const uint8_t *macAddr, Message message);
      void publish(const uint8_t *macAddr, const char *key, const char *value = "");
      void publish(const char *topic, const char *value = "");
      void subscribe(const char *topic);
  };
}
#endif
