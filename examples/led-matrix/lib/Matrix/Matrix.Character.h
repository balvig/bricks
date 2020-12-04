#ifndef MATRIX_CHARACTER_H
#define MATRIX_CHARACTER_H

#include <WEMOS_Matrix_GFX.h>
#include <Lumi.Pattern.h>

namespace Matrix {
  class Character : public Lumi::Pattern {
    public:
      Character(MLED &matrix);
      void update(const uint8_t progress) override;
    private:
      MLED &matrix;
  };
}
#endif
