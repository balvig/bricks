#include <Bricks.BatterySkill.h>

namespace Bricks {
  BatterySkill::BatterySkill(const uint8_t pin) : Skill("getBattery") {
    this->pin = pin;
  }

  void BatterySkill::setAckValue(const char *value) {
    sprintf(ackValue, "%i", analogRead(pin));
  }
}
