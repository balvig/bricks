#include <Lumi.Animation.h>

namespace Lumi {
  Animation::Animation(MLED &matrix, const int numFrames, const uint8_t (*frames)[GRID_SIZE]) : matrix(matrix), frames(frames) {
    this->frameSize = (UINT8_MAX + 1.0) / numFrames;
  }

  void Animation::update(const uint8_t progress) {
    currentFrameNum = progress / frameSize;

    matrix.clear();
    matrix.drawBitmap(0, 0, frames[currentFrameNum], GRID_SIZE, GRID_SIZE, LED_ON);
    matrix.writeDisplay();
  }
}
