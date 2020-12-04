#ifndef MATRIX_COUNT_H
#define MATRIX_COUNT_H

#include <WEMOS_Matrix_GFX.h>
#include <Lumi.Pattern.h>

#define GRID_SIZE 8

namespace Matrix {
  class Count : public Lumi::Pattern {
    public:
      Count(MLED &matrix);
      void update(const uint8_t progress) override;
    private:
      MLED &matrix;
  };
}
#endif
