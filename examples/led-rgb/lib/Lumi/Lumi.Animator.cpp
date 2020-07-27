#include <Lumi.Animator.h>

namespace Lumi {
  Animator::Animator() {
    patterns[0] = new Off(leds, NUM_LEDS);
    patterns[1] = new On(leds, NUM_LEDS);
    patterns[2] = new Glow(leds, NUM_LEDS);
    patterns[3] = new Spin(leds, NUM_LEDS);
    patterns[4] = new Wave(leds, NUM_LEDS);
    FastLED.addLeds<WS2811, PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  }

  void Animator::update() {
    EVERY_N_MILLIS_I(thisTimer, currentDelay) {
      if(progress > UINT8_MAX) {
        progress = 0;
      }
      patterns[currentPattern]->update(progress, currentVariation);
      FastLED.show();
      progress++;
    }

    thisTimer.setPeriod(currentDelay);
  }
}
