#include <Matrix.Graph.h>

namespace Matrix {
  Graph::Graph(MLED &matrix) : matrix(matrix) {}

  void Graph::update(const uint8_t progress) {
    int values[8];

    sscanf(currentValue, "%u,%u,%u,%u,%u,%u,%u,%u", &values[0], &values[1], &values[2], &values[3], &values[4], &values[5], &values[6], &values[7]);

    matrix.clear();

    for (int x = 0 ; x < GRID_SIZE; x++) {
      int topY = values[x];
      for(int y = 1; y <= topY; y++) {
        matrix.drawPixel(x, GRID_SIZE - y, 1);
      }
    }

    matrix.writeDisplay();
  }
}
