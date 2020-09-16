#include "Bricks.PublishSkill.h"

namespace Bricks {
  PublishSkill::PublishSkill() : Skill("*") {
    gEvents.publish(BRICKS_MESSAGES_IN "/gateway/awake");
  }

  void PublishSkill::callback(const uint8_t *macAddr, const Message message) {
    gEvents.publish(macAddr, message);
  }
}
