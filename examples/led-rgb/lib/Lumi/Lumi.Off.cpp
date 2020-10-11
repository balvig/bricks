#include <Lumi.Off.h>

namespace Lumi {
  void Off::update(const uint8_t progress) {
    for(int i = 0; i < numLeds; i++ ) {
      leds[i] = CRGB(0, 0, 0);
    }
    FastLED.show();
  }
}
