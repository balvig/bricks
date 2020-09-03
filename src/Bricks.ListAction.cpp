#include "Bricks.ListAction.h"

namespace Bricks {
  ListAction::ListAction() : Action("getActions") {
  }

  void ListAction::callback(const uint8_t *macAddr, const Message message) {
    gOutbox.send(macAddr, "actions", gInbox.listActions().c_str());
  }
}
