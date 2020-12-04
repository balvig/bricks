#ifndef LED_OFF_H
#define LED_OFF_H

#include <Led.LEDPattern.h>

namespace Led {
  class Off : public LEDPattern {
    public:
      using LEDPattern::LEDPattern;
      void update(const uint8_t progress);
  };
}
#endif
