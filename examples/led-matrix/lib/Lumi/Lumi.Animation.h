#ifndef LUMI_ANIMATION_H
#define LUMI_ANIMATION_H

#include <WEMOS_Matrix_GFX.h>
#include <Lumi.Sequencer.h>
#include <Lumi.Pattern.h>

#define GRID_SIZE 8

namespace Lumi {
  class Animation : public Pattern {
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
