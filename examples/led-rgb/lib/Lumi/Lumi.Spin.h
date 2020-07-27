#ifndef LUMI_SPIN_H
#define LUMI_SPIN_H

#include <Lumi.Pattern.h>

namespace Lumi {
  class Spin : public Pattern {
    public:
      using Pattern::Pattern;
      void update(const uint8_t progress, const uint8_t variation);
  };
}
#endif
