#include <Lumi.Pattern.h>

namespace Lumi {
  Pattern::Pattern(CRGB *leds, const uint8_t numLeds) {
    this->leds = leds;
    this->NUM_LEDS = numLeds;
    this->palette = Rainbow_gp;
  }

  void Pattern::update(const uint8_t progress, const uint8_t variation) {
    // Override
  }
}
