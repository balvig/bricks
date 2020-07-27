#ifndef LUMI_ON_H
#define LUMI_ON_H

#include <Lumi.Pattern.h>

namespace Lumi {
  class On : public Pattern {
    public:
      using Pattern::Pattern;
      void update(const uint8_t progress, const uint8_t variation);
  };
}
#endif
