#ifndef BRICKS_PONG_ACTION_H
#define BRICKS_PONG_ACTION_H

#include <ArduinoLog.h>
#include <Bricks.Action.h>
#include <Bricks.Constants.h>
#include <Bricks.Outbox.h>

namespace Bricks {
  class PongAction : public Action {
    public:
      PongAction(const char *name = "New Brick");
      void callback(const uint8_t *macAddr, const Message message);
    private:
      const char *name;
  };
}
#endif
