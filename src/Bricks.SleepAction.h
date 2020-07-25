#ifndef BRICKS_SLEEP_ACTION_H
#define BRICKS_SLEEP_ACTION_H

#include <ArduinoLog.h>
#ifdef ESP32
#include <esp_sleep.h>
#include <driver/adc.h>
#include <esp_bt.h>
#include <esp_bt_main.h>
#include <esp_wifi.h>
#endif

#include <Bricks.Action.h>
#include <Bricks.Constants.h>
#include <Bricks.Outbox.h>

namespace Bricks {
  class SleepAction : public Action {
    public:
      SleepAction();
      void callback(const uint8_t *macAddr, const Message message);
    private:
      void sendAwakeMessage();
      void deepSleep(const uint32_t seconds);
  };
}
#endif
