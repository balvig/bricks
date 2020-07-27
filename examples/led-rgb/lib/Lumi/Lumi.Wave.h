#ifndef LUMI_WAVE_H
#define LUMI_WAVE_H

#include <Lumi.Pattern.h>

namespace Lumi {
  class Wave : public Pattern {
    public:
      using Pattern::Pattern;
      void update(const uint8_t progress, const uint8_t variation);
    private:
      CRGB clr1;
      CRGB clr2;
      uint8_t speed;
      uint8_t loc1;
      uint8_t loc2;
  };
}
#endif
