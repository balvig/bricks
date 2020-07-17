#include "Bricks.Inbox.h"

namespace Bricks {
  void Inbox::init() {
    WifiEspNow.onReceive(Inbox::onDataReceived, nullptr);
  }

  void Inbox::onDataReceived(const uint8_t macAddr[6], const uint8_t *data, size_t len, void *cbarg) {
    Message message;
    memcpy(&message, data, sizeof(message));

    char macStr[MAC_STR_SIZE];
    Bricks::Utils::macToStr(macAddr, macStr);
    Log.notice("ESPN: <- %s [%s] [%s]", macStr, message.key, message.value);

    gInbox.process(macAddr, message);
  }

  void Inbox::process(const uint8_t *macAddr, const Message message) {
    for(int i = 0; i < MAX_ACTIONS; i++) {
      if(actions[i]->respondsTo(message.key)) {
        Log.trace("BRIC: Action found [%s]", message.key);
        actions[i]->callback(macAddr, message);
      }
    }
  }

  String Inbox::listActions() {
    String actionList = "";

    for(int i = 0; i < MAX_ACTIONS; i++) {
      if(strcmp(actions[i]->key, "") != 0) {
        actionList += actions[i]->key;
        actionList += " ";
      }
    }

    actionList.trim();

    return actionList;
  }

  Inbox gInbox = Inbox();
}
