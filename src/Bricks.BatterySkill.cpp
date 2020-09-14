#include <Bricks.BatterySkill.h>

namespace Bricks {
  BatterySkill::BatterySkill(const uint8_t pin) : Skill("getBattery") {
    this->pin = pin;
  }

  void BatterySkill::callback(const uint8_t *macAddr, const Message message) {
    char battery[10];
    sprintf(battery, "%i", analogRead(pin));
    gOutbox.send(macAddr, "battery", (const char*)battery);
  }
}
