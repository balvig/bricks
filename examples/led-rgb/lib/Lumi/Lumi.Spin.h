#ifndef LUMI_SPIN_H
#define LUMI_SPIN_H

#include <Lumi.LEDPattern.h>

namespace Lumi {
  class Spin : public LEDPattern {
    public:
      using LEDPattern::LEDPattern;
      void update(const uint8_t progress);
  };
}
#endif
