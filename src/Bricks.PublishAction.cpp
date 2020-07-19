#include "Bricks.PublishAction.h"

namespace Bricks {
  PublishAction::PublishAction() : Action("*") {
  }

  void PublishAction::callback(const uint8_t *macAddr, const Message message) {
    gEvents.publish(macAddr, message);
  }
}
