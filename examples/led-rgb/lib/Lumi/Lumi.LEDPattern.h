#ifndef LUMI_LED_PATTERN_H
#define LUMI_LED_PATTERN_H

#include <Lumi.Pattern.h>
#include <FastLED.h>

namespace Lumi {
  class LEDPattern : public Pattern {
    public:
      LEDPattern(CRGB *leds, const uint8_t numLeds);
    protected:
      CRGB *leds;
      CRGBPalette16 palette;
      uint8_t numLeds;
  };
}
#endif
