#ifndef LUMI_OFF_H
#define LUMI_OFF_H

#include <Lumi.LEDPattern.h>

namespace Lumi {
  class Off : public LEDPattern {
    public:
      using LEDPattern::LEDPattern;
      void update(const uint8_t progress);
  };
}
#endif
