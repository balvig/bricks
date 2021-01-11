#include "Bricks.VersionSkill.h"

namespace Bricks {
  VersionSkill::VersionSkill() : Skill("version") {}

  void VersionSkill::callback(BRICKS_CALLBACK_SIGNATURE) {
    strcpy(response, BRICKS_VERSION);
  }
}
