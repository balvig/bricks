#include <Bricks.BatterySkill.h>

namespace Bricks {
  BatterySkill::BatterySkill(const uint8_t pin) : Skill("battery") {
    this->pin = pin;
  }

  void BatterySkill::callback(BRICKS_CALLBACK_SIGNATURE) {
    sprintf(response, "%i", analogRead(pin));
  }
}
