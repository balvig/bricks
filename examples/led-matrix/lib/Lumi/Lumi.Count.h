#ifndef LUMI_COUNT_H
#define LUMI_COUNT_H

#include <WEMOS_Matrix_GFX.h>
#include <Lumi.Pattern.h>

#define GRID_SIZE 8

namespace Lumi {
  class Count : public Pattern {
    public:
      Count(MLED &matrix);
      void update(const uint8_t progress) override;
    private:
      MLED &matrix;
  };
}
#endif
