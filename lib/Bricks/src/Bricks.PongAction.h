#ifndef BRICKS_PONG_ACTION_H
#define BRICKS_PONG_ACTION_H

#include <ArduinoLog.h>
#include <Bricks.Action.h>
#include <Bricks.Inbox.h>
#include <Bricks.Outbox.h>

namespace Bricks {
  class PongAction : public Action {
    public:
      PongAction(const char *name = "brick");
      void callback(const uint8_t *macAddr, const Message message);
    private:
      const char *name;
  };
}
#endif
