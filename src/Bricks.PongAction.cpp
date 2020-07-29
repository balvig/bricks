#include <Bricks.PongAction.h>

namespace Bricks {
  PongAction::PongAction(const char *name) : Action(BRICKS_PING_ACTION) {
    this->name = name;
    char apName[50];
    sprintf(apName, BRICKS_NAME_PREFIX " [%s]", name);
    WiFi.softAP(apName, "1234567890", 0);
  }

  void PongAction::callback(const uint8_t *macAddr, const Message message) {
    gOutbox.send(macAddr, "pong", name);
  }
}
