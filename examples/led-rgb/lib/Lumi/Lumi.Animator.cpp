#include <Lumi.Animator.h>

namespace Lumi {
  Animator::Animator() : patterns {
    new Off(leds, NUM_LEDS), new On(leds, NUM_LEDS), new Glow(leds, NUM_LEDS), new Spin(leds, NUM_LEDS), new Wave(leds, NUM_LEDS)
  }
  {
    FastLED.addLeds<WS2811, LUMI_ANIMATOR_PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  }

  void Animator::update() {
    FastLED.show();
  }
}
