#include <Bricks.PongAction.h>

namespace Bricks {
  PongAction::PongAction(const char *name) : Action(BRICKS_PING_ACTION) {
    this->name = name;
    advertise();
  }

  void PongAction::callback(const uint8_t *macAddr, const Message message) {
    gOutbox.send(macAddr, "pong", name);
  }

  void PongAction::advertise() {
    char apName[50]; // Need unique name?
    sprintf(apName, BRICKS_NAME_PREFIX "%s (%s)", name, WiFi.softAPmacAddress().c_str());
    WiFi.softAP(apName, NULL, BRICKS_WIFI_CHANNEL);
  }
}
