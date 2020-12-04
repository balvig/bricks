#ifndef LED_SPIN_H
#define LED_SPIN_H

#include <Led.LEDPattern.h>

namespace Led {
  class Spin : public LEDPattern {
    public:
      using LEDPattern::LEDPattern;
      void update(const uint8_t progress);
  };
}
#endif
