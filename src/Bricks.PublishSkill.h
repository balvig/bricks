#ifndef BRICKS_PUBLISH_SKILL_H
#define BRICKS_PUBLISH_SKILL_H

#include <ArduinoLog.h>
#include <Bricks.Skill.h>
#include <Bricks.Events.h>

namespace Bricks {
  class PublishSkill : public Skill {
    public:
      PublishSkill();
      void callback(BRICKS_CALLBACK_SIGNATURE);
  };
}
#endif
