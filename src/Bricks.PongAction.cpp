#include <Bricks.PongAction.h>

namespace Bricks {
  PongAction::PongAction(const char *name) : Action("ping") {
    this->name = name;
    gOutbox.send("pong", name);
  }

  void PongAction::callback(const uint8_t *macAddr, const Message message) {
    gOutbox.send(macAddr, "pong", name);
  }
}
