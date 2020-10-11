#include <Lumi.Sequencer.h>

namespace Lumi {
  Sequencer::Sequencer() {}

  void Sequencer::loop() {
    EVERY_N_MILLIS_I(thisTimer, currentDelay) {
      if(progress > UINT8_MAX) {
        progress = 0;
      }
      patterns[currentPattern]->update(progress, currentVariation);
      update();
      progress++;
    }

    thisTimer.setPeriod(currentDelay);
  }

  void Sequencer::update() {
  }
}
