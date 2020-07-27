#include <Lumi.Spin.h>

namespace Lumi {
  void Spin::update(const uint8_t progress, const uint8_t variation) {
    uint8_t segmentSize = UINT8_MAX / NUM_LEDS - 1;

    leds[0] = CRGB(0, 0, 0);

    for(int i = 1; i < NUM_LEDS; i++ ) {
      int8_t brightness = progress - i * segmentSize;
      if(brightness < 0) {
        brightness = 0;
      }

      leds[i] = ColorFromPalette(palette, variation, brightness);
    }
  }
}
