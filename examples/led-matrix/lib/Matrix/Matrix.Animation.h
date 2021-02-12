#ifndef MATRIX_ANIMATION_H
#define MATRIX_ANIMATION_H

#include <WEMOS_Matrix_GFX.h>
#include <Matrix.Config.h>
#include <Lumi.Pattern.h>

namespace Matrix {
  class Animation : public Lumi::Pattern {
    public:
      Animation(MLED &matrix, const int numFrames, const uint8_t (*frames)[GRID_SIZE]);
      void update(const uint8_t progress) override;
    private:
      MLED &matrix;
      int currentFrameNum = 0;
      float frameSize;
      const uint8_t (*frames)[GRID_SIZE];
  };
}
#endif
