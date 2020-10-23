#include <Lumi.Wave.h>

namespace Lumi {
  // https://github.com/atuline/FastLED-Demos/blob/9f6efc456308968f612aa73034aa1ea47d2143ee/blendwave/blendwave.ino
  void Wave::update(const uint8_t progress) {
    speed = beatsin8(6,0,255);

    clr1 = blend(CHSV(beatsin8(3,0,255),255,255), CHSV(beatsin8(4,0,255),255,255), speed);
    clr2 = blend(CHSV(beatsin8(4,0,255),255,255), CHSV(beatsin8(3,0,255),255,255), speed);

    loc1 = beatsin8(10,0,numLeds-1);

    fill_gradient_RGB(leds, 0, clr2, loc1, clr1);
    fill_gradient_RGB(leds, loc1, clr2, numLeds-1, clr1);
    FastLED.show();
  }
}
