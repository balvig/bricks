#ifndef BRICKS_PIR_SKILL_H
#define BRICKS_PIR_SKILL_H

#include <Bricks.Skill.h>

namespace Bricks {
  class PirSkill : public Skill {
    public:
      PirSkill(const uint8_t pin = D3); // D3 on Wemos
      void callback(BRICKS_CALLBACK_SIGNATURE) override;
    private:
      uint8_t pin;
  };
}
#endif
