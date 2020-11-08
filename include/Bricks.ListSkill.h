#ifndef BRICKS_LIST_SKILL_H
#define BRICKS_LIST_SKILL_H

#include <Bricks.Skill.h>
#include <Bricks.Brick.h>

namespace Bricks {
  class ListSkill : public Skill {
    public:
      ListSkill();
      void callback(BRICKS_CALLBACK_SIGNATURE) override;
  };
}
#endif
