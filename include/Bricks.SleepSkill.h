#ifndef BRICKS_SLEEP_SKILL_H
#define BRICKS_SLEEP_SKILL_H

#include <ArduinoLog.h>

#ifdef ESP8266
// For ESP8266 RTC memory
extern "C" {
#include "user_interface.h"
}
#endif

#include <Bricks.Skill.h>
#include <Bricks.Constants.h>
#include <Bricks.Utils.h>

namespace Bricks {
  class SleepSkill : public Skill {
    const uint32_t TIMEOUT = 2000;
    const uint32_t RTC_SLEEP_TIME_REGISTER = 65;
    const uint16_t MAX_SLEEP_TIME = 10800; // seconds = 3 hours

    public:
      SleepSkill(const char *name = "New Brick");
      void callback(BRICKS_CALLBACK_SIGNATURE) override;
      void loop() override;
    private:
      void sendAwakeMessage();
      void deepSleep();
      bool awakeTimeout();
      bool validSleepTime();
      void readSleepTime();
      void writeSleepTime();
      const char *name;
      int16_t sleepTime = -1;
  };
}
#endif
