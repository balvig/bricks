#include <Led.Spin.h>

namespace Led {
  void Spin::update(const uint8_t progress) {
    uint8_t segmentSize = UINT8_MAX / numLeds - 1;

    leds[0] = CRGB(0, 0, 0);

    for(int i = 1; i < numLeds; i++ ) {
      int8_t brightness = progress - i * segmentSize;
      if(brightness < 0) {
        brightness = 0;
      }

      leds[i] = ColorFromPalette(palette, currentIntValue, brightness);
    }
    FastLED.show();
  }
}
