#include <Led.Glow.h>

namespace Led {
  void Glow::update(const uint8_t progress) {
    uint8_t brightness = sin8(progress);

    for(int i = 0; i < numLeds; i++ ) {
      leds[i] = ColorFromPalette(palette, currentIntValue, brightness);
    }
    FastLED.show();
  }
}
