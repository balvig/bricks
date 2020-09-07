#include "Bricks.Inbox.h"

namespace Bricks {
  void Inbox::init(const char *name) {
    actions[5] = new OtaAction();
    actions[6] = new ListAction();
    actions[7] = new BatteryAction();
    actions[8] = new SleepAction(name);
    actions[9] = new AckAction();
    initBase();
  }

  void Inbox::initBase() {
    WifiEspNow.onReceive(Inbox::onDataReceived, nullptr);
  }

  void Inbox::onDataReceived(const uint8_t macAddr[MAC_ADDR_SIZE], const uint8_t *data, size_t len, void *cbarg) {
    Message message;
    memcpy(&message, data, sizeof(message));

    char macStr[MAC_STR_SIZE];
    Bricks::Utils::macToStr(macAddr, macStr);
    Log.notice("ESPN: <- %s [%s] [%s]" CR, macStr, message.key, message.value);

    gInbox.process(macAddr, message);
  }

  void Inbox::loop() {
    for(int i = MAX_ACTIONS - 1; i >= 0; i--) {
      actions[i]->loop();
    }
  }

  void Inbox::process(const uint8_t *macAddr, const Message message) {
    for(int i = MAX_ACTIONS - 1; i >= 0; i--) {
      if(actions[i]->respondsTo(message.key)) {
        Log.trace("BRIC: Action found [%s]" CR, message.key);
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
