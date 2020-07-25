#ifndef BRICKS_ACK_ACTION_H
#define BRICKS_ACK_ACTION_H

#include <ArduinoLog.h>
#include <Bricks.Action.h>
#include <Bricks.Outbox.h>

#define BRICKS_ACK_PREFIX "ack:"

namespace Bricks {
  class AckAction : public Action {
    public:
      AckAction();
      void callback(const uint8_t *macAddr, const Message message);
  };
}
#endif
