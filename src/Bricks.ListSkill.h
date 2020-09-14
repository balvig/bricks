#ifndef BRICKS_LIST_SKILL_H
#define BRICKS_LIST_SKILL_H

#include <Bricks.Skill.h>
#include <Bricks.Inbox.h>
#include <Bricks.Outbox.h>

namespace Bricks {
  class ListSkill : public Skill {
    public:
      ListSkill();
      void callback(const uint8_t *macAddr, const Message message);
  };
}
#endif
