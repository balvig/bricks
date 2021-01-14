#ifndef BRICKS_UTILS_H
#define BRICKS_UTILS_H

#include <Arduino.h>
#include <ArduinoLog.h>

#ifdef ESP8266
extern "C" {
#include <user_interface.h>
}
#elif ESP32
#include <esp_sleep.h>
#include <driver/adc.h>
#include <esp_bt.h>
#include <esp_bt_main.h>
#include <esp_wifi.h>
#endif

#include <Bricks.Constants.h>

#define MICROSECONDS 1000000ULL

namespace Bricks {
  class Utils {
    public:
      static void macToStr(const uint8_t *macAddr, char *macStr);
      static void deepSleep(uint32_t sleepTime);
      static void getWakeupReason(char *reason);
    private:
      static int resetInfo();
  };
}
#endif
