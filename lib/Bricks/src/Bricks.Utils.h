#ifndef BRICKS_UTILS_H
#define BRICKS_UTILS_H

#include <ArduinoLog.h>

#define MAC_FORMAT "%2hhx:%2hhx:%2hhx:%2hhx:%2hhx:%2hhx"

namespace Bricks {
  class Utils {
    public:
      static const uint8_t MAC_ADDR_SIZE = 6;
      static const uint8_t MAC_STR_SIZE = 18;
      static void macToStr(const uint8_t *macAddr, char *macStr);
      static void parseTopic(const char *topic, uint8_t *macAddr, char *key);
  };
}
#endif
