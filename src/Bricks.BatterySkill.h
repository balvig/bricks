#ifndef BRICKS_BATTERY_SKILL_H
#define BRICKS_BATTERY_SKILL_H

#include <ArduinoLog.h>
#include <Bricks.Skill.h>
#include <Bricks.Outbox.h>

namespace Bricks {
  class BatterySkill : public Skill {
    public:
      BatterySkill(const uint8_t pin = 17); // A0 on Wemos
      void callback(const uint8_t *macAddr, const Message message);
    private:
      uint8_t pin;
  };
}
#endif
