#include <Bricks.PirSkill.h>

namespace Bricks {
  PirSkill::PirSkill(const uint8_t pin) : Skill("scanPir") {
    this->pin = pin;
    pinMode(pin, INPUT);
  }

  void PirSkill::callback(BRICKS_CALLBACK_SIGNATURE) {
    sprintf(response, "%i", digitalRead(pin));
  }
}
