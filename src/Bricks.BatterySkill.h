#ifndef BRICKS_BATTERY_SKILL_H
#define BRICKS_BATTERY_SKILL_H

#include <ArduinoLog.h>
#include <Bricks.Skill.h>

namespace Bricks {
  class BatterySkill : public Skill {
    public:
      BatterySkill(const uint8_t pin = 17); // A0 on Wemos
      void callback(BRICKS_CALLBACK_SIGNATURE);
    private:
      uint8_t pin;
  };
}
#endif
