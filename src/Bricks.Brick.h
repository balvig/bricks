#ifndef BRICKS_BRICK_H
#define BRICKS_BRICK_H

#include <ArduinoLog.h>
#include <WifiEspNow.h>

#ifdef ESP8266
#include <ESP8266WiFi.h>
#elif ESP32
#include <WiFi.h>
#endif

#include <Bricks.Constants.h>
#include <Bricks.Message.h>
#include <Bricks.Skill.h>
#include <Bricks.Utils.h>

// Stock skills
#include <Bricks.BatterySkill.h>
#include <Bricks.ListSkill.h>
#include <Bricks.OtaSkill.h>
#include <Bricks.SleepSkill.h>

#define MAX_SKILLS 10

namespace Bricks {
  class Brick {
    public:
      void init(const char *name);
      void initBase(const WiFiMode_t wifiMode = WIFI_AP); // AP is more stable than STA when communicating with AT_STA
      void loop();
      void process(BRICKS_PROCESS_SIGNATURE);
      String listSkills();
      Skill *skills[MAX_SKILLS] = { new Skill(), new Skill(), new Skill(), new Skill(), new Skill(), new Skill(), new Skill(), new Skill(), new Skill(), new Skill() };
    private:
      void logMac(WiFiMode_t wifiMode);
      static void onDataReceived(const uint8_t macAddr[MAC_ADDR_SIZE], const uint8_t *data, size_t len, void *cbarg);
  };

  extern Brick gBrick;
}
#endif
