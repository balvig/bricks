#include <Lumi.LEDPattern.h>

namespace Lumi {
  LEDPattern::LEDPattern(CRGB *leds, const uint8_t numLeds) {
    this->leds = leds;
    this->numLeds = numLeds;
    this->palette = Rainbow_gp;
  }
}
