#ifndef LUMI_GLOW_H
#define LUMI_GLOW_H

#include <Lumi.Pattern.h>

namespace Lumi {
  class Glow : public Pattern {
    public:
      using Pattern::Pattern;
      void update(const uint8_t progress, const uint8_t variation);
  };
}
#endif
