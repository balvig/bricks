#ifndef LED_LED_PATTERN_H
#define LED_LED_PATTERN_H

#include <Lumi.Pattern.h>
#include <FastLED.h>

namespace Led {
  class LEDPattern : public Lumi::Pattern {
    public:
      LEDPattern(CRGB *leds, const uint8_t numLeds);
    protected:
      CRGB *leds;
      CRGBPalette16 palette;
      uint8_t numLeds;
  };
}
#endif
