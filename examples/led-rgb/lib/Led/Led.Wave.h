#ifndef LED_WAVE_H
#define LED_WAVE_H

#include <Led.LEDPattern.h>

namespace Led {
  class Wave : public LEDPattern {
    public:
      using LEDPattern::LEDPattern;
      void update(const uint8_t progress);
    private:
      CRGB clr1;
      CRGB clr2;
      uint8_t speed;
      uint8_t loc1;
      uint8_t loc2;
  };
}
#endif
