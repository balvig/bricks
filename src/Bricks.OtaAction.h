#ifndef BRICKS_OTA_ACTION_H
#define BRICKS_OTA_ACTION_H

#include <ArduinoLog.h>
#include <ArduinoOTA.h>
#include <Bricks.Action.h>
#include <Bricks.Outbox.h>

namespace Bricks {
  class OtaAction : public Action {
    public:
      OtaAction();
      void loop();
      void callback(const uint8_t *macAddr, const Message message);
    private:
      void initOta();
  };
}
#endif
