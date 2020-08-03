#include <Bricks.BatteryAction.h>

namespace Bricks {
  BatteryAction::BatteryAction(const uint8_t pin) : Action("getBattery") {
    this->pin = pin;
  }

  void BatteryAction::callback(const uint8_t *macAddr, const Message message) {
    char battery[10];
    sprintf(battery, "%i", analogRead(pin));
    gOutbox.send(macAddr, "battery", (const char*)battery);
  }
}
