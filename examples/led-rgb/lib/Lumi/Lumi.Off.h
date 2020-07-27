#ifndef LUMI_OFF_H
#define LUMI_OFF_H

#include <Lumi.Pattern.h>

namespace Lumi {
  class Off : public Pattern {
    public:
      using Pattern::Pattern;
      void update(const uint8_t progress, const uint8_t variation);
  };
}
#endif
