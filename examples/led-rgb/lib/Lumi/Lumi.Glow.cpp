#include <Lumi.Glow.h>

namespace Lumi {
  void Glow::update(const uint8_t progress, const uint8_t variation) {
    uint8_t brightness = sin8(progress);

    for(int i = 0; i < NUM_LEDS; i++ ) {
      leds[i] = ColorFromPalette(palette, variation, brightness);
    }
  }
}
