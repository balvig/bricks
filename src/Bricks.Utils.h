#ifndef BRICKS_UTILS_H
#define BRICKS_UTILS_H

#include <Arduino.h>
#ifdef ESP8266
extern "C" {
#include <user_interface.h>
}
#endif

#include <Bricks.Constants.h>

namespace Bricks {
  class Utils {
    public:
      static void macToStr(const uint8_t *macAddr, char *macStr);
      static void getWakeupReason(char *reason);
  };
}
#endif
