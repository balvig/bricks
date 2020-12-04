#include <Matrix.Count.h>

namespace Matrix {
  Count::Count(MLED &matrix) : matrix(matrix) {}

  void Count::update(const uint8_t progress) {
    if (currentIntValue > GRID_SIZE * GRID_SIZE) {
      return;
    }

    matrix.clear();
    int y = GRID_SIZE - 1;
    int x = 0;

    for (int i = 0 ; i < currentIntValue; i++) {
      if (x >= GRID_SIZE) {
        x = 0;
        y--;
      }

      matrix.drawPixel(x, y, 1);

      x++;
    }

    matrix.writeDisplay();
  }
}
