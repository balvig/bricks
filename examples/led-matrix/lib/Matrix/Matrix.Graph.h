#ifndef MATRIX_GRAPH_H
#define MATRIX_GRAPH_H

#include <WEMOS_Matrix_GFX.h>
#include <Matrix.Config.h>
#include <Lumi.Pattern.h>

namespace Matrix {
  class Graph : public Lumi::Pattern {
    public:
      Graph(MLED &matrix);
      void update(const uint8_t progress) override;
    private:
      MLED &matrix;
      int currentPixel = 0;
      bool played = false;
      const uint8_t PIXEL_SIZE = (PROGRESS_MAX + 1.0) / (GRID_SIZE * GRID_SIZE);
  };
}
#endif
