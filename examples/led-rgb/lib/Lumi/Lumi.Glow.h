#ifndef LUMI_GLOW_H
#define LUMI_GLOW_H

#include <Lumi.LEDPattern.h>

namespace Lumi {
  class Glow : public LEDPattern {
    public:
      using LEDPattern::LEDPattern;
      void update(const uint8_t progress);
  };
}
#endif
