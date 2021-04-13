#ifndef BRICKS_SLEEP_SKILL_H
#define BRICKS_SLEEP_SKILL_H

#include <ArduinoLog.h>

#include <Bricks.Skill.h>
#include <Bricks.Constants.h>
#include <Bricks.Utils.h>

namespace Bricks {
  class SleepSkill : public Skill {
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
      const char *name;
      int16_t sleepTime = -1;
  };
}
#endif
