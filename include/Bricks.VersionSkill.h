#ifndef BRICKS_VERSION_SKILL_H
#define BRICKS_VERSION_SKILL_H

#include <Bricks.Skill.h>

namespace Bricks {
  class VersionSkill : public Skill {
    public:
      VersionSkill();
      void callback(BRICKS_CALLBACK_SIGNATURE) override;
  };
}
#endif
