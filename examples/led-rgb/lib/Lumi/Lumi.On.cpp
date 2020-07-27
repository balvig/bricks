#include <Lumi.On.h>

namespace Lumi {
  void On::update(const uint8_t progress, const uint8_t variation) {
    for(int i = 0; i < NUM_LEDS; i++ ) {
      leds[i] = ColorFromPalette(palette, variation, UINT8_MAX);
    }
  }
}
