#ifndef BRICKS_OTA_SKILL_H
#define BRICKS_OTA_SKILL_H

#include <ArduinoLog.h>
#include <ArduinoOTA.h>
#include <Bricks.Skill.h>

namespace Bricks {
  class OtaSkill : public Skill {
    public:
      OtaSkill();
      void callback(BRICKS_CALLBACK_SIGNATURE) override;
      void loop() override;
    private:
      void initOta();
      void startAP();
  };
}
#endif
