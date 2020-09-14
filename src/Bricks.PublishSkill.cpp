#include "Bricks.PublishSkill.h"

namespace Bricks {
  PublishSkill::PublishSkill() : Skill("*") {
  }

  void PublishSkill::callback(const uint8_t *macAddr, const Message message) {
    gEvents.publish(macAddr, message);
  }
}
