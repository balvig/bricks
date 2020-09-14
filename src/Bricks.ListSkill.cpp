#include "Bricks.ListSkill.h"

namespace Bricks {
  ListSkill::ListSkill() : Skill("getSkills") {
  }

  void ListSkill::callback(const uint8_t *macAddr, const Message message) {
    gOutbox.send(macAddr, "skills", gInbox.listSkills().c_str());
  }
}
