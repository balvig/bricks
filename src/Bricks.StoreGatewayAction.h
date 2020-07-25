#ifndef BRICKS_STORE_GATEWAY_ACTION_H
#define BRICKS_STORE_GATEWAY_ACTION_H

#include <ArduinoLog.h>
#include <EEPROM.h>

#include <Bricks.Action.h>
#include <Bricks.Constants.h>
#include <Bricks.Outbox.h>
#include <Bricks.Utils.h>

namespace Bricks {
  class StoreGatewayAction : public Action {
    public:
      StoreGatewayAction();
      void callback(const uint8_t *macAddr, const Message message);
    private:
      void writeMac(const uint8_t *macAddr);
      void readMac();
  };
}
#endif
