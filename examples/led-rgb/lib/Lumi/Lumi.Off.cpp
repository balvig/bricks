#include <Lumi.Off.h>

namespace Lumi {
  void Off::update(const uint8_t progress, const uint8_t variation) {
    for(int i = 0; i < NUM_LEDS; i++ ) {
      leds[i] = CRGB(0, 0, 0);
    }
  }
}
