#ifndef BRICKS_LIST_ACTION_H
#define BRICKS_LIST_ACTION_H

#include <Bricks.Action.h>
#include <Bricks.Inbox.h>
#include <Bricks.Outbox.h>

namespace Bricks {
  class ListAction : public Action {
    public:
      ListAction();
      void callback(const uint8_t *macAddr, const Message message);
  };
}
#endif
