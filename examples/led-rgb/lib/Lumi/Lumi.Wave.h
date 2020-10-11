#ifndef LUMI_WAVE_H
#define LUMI_WAVE_H

#include <Lumi.LEDPattern.h>

namespace Lumi {
  class Wave : public LEDPattern {
    public:
      using LEDPattern::LEDPattern;
      void update(const uint8_t progress);
    private:
      CRGB clr1;
      CRGB clr2;
      uint8_t speed;
      uint8_t loc1;
      uint8_t loc2;
  };
}
#endif
