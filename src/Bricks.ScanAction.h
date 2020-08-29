#ifndef BRICKS_SCAN_ACTION_H
#define BRICKS_SCAN_ACTION_H

#include <Bricks.Action.h>
#include <Bricks.Outbox.h>

namespace Bricks {
  class ScanAction : public Action {
    public:
      ScanAction();
      void callback(const uint8_t *macAddr, const Message message);
  };
}
#endif
