#ifndef BRICKS_ACK_SKILL_H
#define BRICKS_ACK_SKILL_H

#include <ArduinoLog.h>
#include <Bricks.Skill.h>
#include <Bricks.Outbox.h>

#define BRICKS_ACK_PREFIX "ack:"

namespace Bricks {
  class AckSkill : public Skill {
    public:
      AckSkill();
      void callback(const uint8_t *macAddr, const Message message);
  };
}
#endif
