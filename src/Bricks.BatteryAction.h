#ifndef BRICKS_BATTERY_ACTION_H
#define BRICKS_BATTERY_ACTION_H

#include <ArduinoLog.h>
#include <Bricks.Action.h>
#include <Bricks.Outbox.h>

namespace Bricks {
  class BatteryAction : public Action {
    public:
      BatteryAction(const uint8_t pin = 17); // A0 on Wemos
      void callback(const uint8_t *macAddr, const Message message);
    private:
      uint8_t pin;
  };
}
#endif
