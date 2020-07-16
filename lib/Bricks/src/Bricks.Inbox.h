#ifndef BRICKS_INBOX_H
#define BRICKS_INBOX_H

#include <ArduinoLog.h>
#include <WifiEspNow.h>

#include <Bricks.Action.h>
#include <Bricks.Message.h>
#include <Bricks.Utils.h>

# define MAX_ACTIONS 10

namespace Bricks {
  class Inbox {
    public:
      Inbox() {}
      void init();
      void process(const uint8_t *macAddr, const Message message);
      Action *actions[MAX_ACTIONS] = { new Action(), new Action(), new Action(), new Action(), new Action(), new Action(), new Action(), new Action(), new Action(), new Action() }; // what the
    private:
      static void onDataReceived(const uint8_t macAddr[6], const uint8_t *data, size_t len, void *cbarg);
  };

  extern Inbox gInbox;
}
#endif
