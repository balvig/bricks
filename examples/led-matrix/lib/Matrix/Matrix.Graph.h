#ifndef MATRIX_GRAPH_H
#define MATRIX_GRAPH_H

#include <WEMOS_Matrix_GFX.h>
#include <Lumi.Pattern.h>

#define GRID_SIZE 8

namespace Matrix {
  class Graph : public Lumi::Pattern {
    public:
      Graph(MLED &matrix);
      void update(const uint8_t progress) override;
    private:
      MLED &matrix;
  };
}
#endif
