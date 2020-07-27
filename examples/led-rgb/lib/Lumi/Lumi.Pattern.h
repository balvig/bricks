#ifndef LUMI_PATTERN_H
#define LUMI_PATTERN_H

#include <FastLED.h>

namespace Lumi {
  class Pattern {
    public:
      Pattern(CRGB *leds, const uint8_t numLeds);
      virtual void update(const uint8_t progress, const uint8_t variation);
    protected:
      CRGB *leds;
      CRGBPalette16 palette;
      uint8_t NUM_LEDS;
  };
}
#endif
