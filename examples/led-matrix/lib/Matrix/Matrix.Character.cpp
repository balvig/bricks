#include <Matrix.Character.h>

namespace Matrix {
  Character::Character(MLED &matrix) : matrix(matrix) {}

  void Character::update(const uint8_t progress) {
    matrix.clear();
    matrix.setCursor(2, 1);
    matrix.print(currentValue);
    matrix.writeDisplay();
  }
}
