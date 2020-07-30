#ifndef BRICKS_OUTBOX_H
#define BRICKS_OUTBOX_H

#include <ArduinoLog.h>
#include <WifiEspNow.h>

#include <Bricks.Constants.h>
#include <Bricks.Message.h>
#include <Bricks.Utils.h>

namespace Bricks {
  class Outbox {
    public:
      Outbox() {}
      void send(const uint8_t *macAddr, const char *key, const char *value = "");
      void send(const char *key, const char *value = "");
      void setGatewayMac(const uint8_t *macAddr);
    private:
      void pair(const uint8_t *macAddr);
      void debugMessages();
      uint8_t gatewayMac[MAC_ADDR_SIZE] = MAC_UNSET;
  };

  extern Outbox gOutbox;
}
#endif
