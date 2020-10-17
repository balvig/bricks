#ifndef LUMI_CHARACTER_H
#define LUMI_CHARACTER_H

#include <WEMOS_Matrix_GFX.h>
#include <Lumi.Pattern.h>

namespace Lumi {
  class Character : public Pattern {
    public:
      Character(MLED &matrix);
      void update(const uint8_t progress) override;
    private:
      MLED &matrix;
  };
}
#endif
