#ifndef BRICKS_UTILS_H
#define BRICKS_UTILS_H

#include <Arduino.h>
#include <Bricks.Constants.h>

namespace Bricks {
  class Utils {
    public:
      static void macToStr(const uint8_t *macAddr, char *macStr);
  };
}
#endif
