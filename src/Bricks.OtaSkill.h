#ifndef BRICKS_OTA_SKILL_H
#define BRICKS_OTA_SKILL_H

#include <ArduinoLog.h>
#include <ArduinoOTA.h>
#include <Bricks.Skill.h>
#include <Bricks.Outbox.h>

namespace Bricks {
  class OtaSkill : public Skill {
    public:
      OtaSkill();
      void loop();
      void callback(const uint8_t *macAddr, const Message message);
    private:
      void initOta();
      void startAP();
  };
}
#endif
