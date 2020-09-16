#include "Bricks.ListSkill.h"

namespace Bricks {
  ListSkill::ListSkill() : Skill("skills") {
  }

  void ListSkill::callback(const uint8_t *macAddr, const Message message) {
    ack(gInbox.listSkills().c_str());
  }
}
