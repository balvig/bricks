#include "Bricks.PublishSkill.h"

namespace Bricks {
  PublishSkill::PublishSkill() : Skill("*") {
    gEvents.publish(BRICKS_MESSAGES_IN "/gateway/awake");
  }

  void PublishSkill::callback(BRICKS_CALLBACK_SIGNATURE) {
    gEvents.publish(macAddr, message);
  }
}
