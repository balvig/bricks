#include "Bricks.ListSkill.h"

namespace Bricks {
  ListSkill::ListSkill() : Skill("skills") {
  }

  void ListSkill::callback(BRICKS_CALLBACK_SIGNATURE) {
    strcpy(response, gInbox.listSkills().c_str());
  }
}
