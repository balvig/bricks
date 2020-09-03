#ifndef BRICKS_CLAIM_ACTION_H
#define BRICKS_CLAIM_ACTION_H

#include <ArduinoLog.h>
#include <EEPROM.h>

#include <Bricks.Action.h>
#include <Bricks.Constants.h>
#include <Bricks.Outbox.h>
#include <Bricks.Utils.h>

namespace Bricks {
  class ClaimAction : public Action {
    public:
      ClaimAction();
      void loop();
      void callback(const uint8_t *macAddr, const Message message);
    private:
      void writeMac(const uint8_t *macAddr);
      void readMac();
      void pingGateway();
      bool claimTimedOut();
      void startAdvertising();
      bool awaitingClaim = false;
      unsigned long startMillis;
      unsigned long currentMillis;
      const unsigned long WAIT_TIME = 5000;
  };
}
#endif
