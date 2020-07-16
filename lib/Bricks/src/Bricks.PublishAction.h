#ifndef BRICKS_PUBLISH_ACTION_H
#define BRICKS_PUBLISH_ACTION_H

#include <ArduinoLog.h>
#include <Bricks.Action.h>
#include <Bricks.Events.h>

namespace Bricks {
  class PublishAction : public Action {
    public:
      PublishAction();
      void callback(const uint8_t *macAddr, const Message message);
  };
}
#endif
