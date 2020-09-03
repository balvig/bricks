#ifndef BRICKS_INBOX_H
#define BRICKS_INBOX_H

#include <ArduinoLog.h>
#include <WifiEspNow.h>

#include <Bricks.Action.h>
#include <Bricks.Constants.h>
#include <Bricks.Message.h>
#include <Bricks.Utils.h>

// Stock actions
#include <Bricks.AckAction.h>
#include <Bricks.BatteryAction.h>
#include <Bricks.ListAction.h>
#include <Bricks.OtaAction.h>
#include <Bricks.PongAction.h>
#include <Bricks.SleepAction.h>
#include <Bricks.StoreGatewayAction.h>

# define MAX_ACTIONS 10

namespace Bricks {
  class Inbox {
    public:
      Inbox() {}
      void init(const char *name);
      void initBase();
      void loop();
      void process(const uint8_t *macAddr, const Message message);
      String listActions(); // The (supposedly) EVIL STRING?
      Action *actions[MAX_ACTIONS] = { new Action(), new Action(), new Action(), new Action(), new Action(), new Action(), new Action(), new Action(), new Action(), new Action() }; // what the
    private:
      static void onDataReceived(const uint8_t macAddr[6], const uint8_t *data, size_t len, void *cbarg);
  };

  extern Inbox gInbox;
}
#endif
