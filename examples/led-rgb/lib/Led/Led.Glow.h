#ifndef LED_GLOW_H
#define LED_GLOW_H

#include <Led.LEDPattern.h>

namespace Led {
  class Glow : public LEDPattern {
    public:
      using LEDPattern::LEDPattern;
      void update(const uint8_t progress);
  };
}
#endif
