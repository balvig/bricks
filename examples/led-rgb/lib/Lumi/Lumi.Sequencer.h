#ifndef LUMI_SEQUENCER_H
#define LUMI_SEQUENCER_H

#include <Lumi.Pattern.h>

namespace Lumi {
  class Sequencer {
    public:
      Sequencer();
      void loop();
      uint8_t currentPattern = 0;
      uint8_t currentVariation = 0;
      uint8_t currentDelay = 10;
    protected:
      Pattern *patterns[10];
    private:
      virtual void update();
      uint8_t progress = 0;
  };
}
#endif
