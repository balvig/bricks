#include "Bricks.AckSkill.h"

namespace Bricks {
  AckSkill::AckSkill() : Skill("*") {
  }

  void AckSkill::callback(const uint8_t *macAddr, const Message message) {
    char ackKey[KEY_SIZE];
    sprintf(ackKey, BRICKS_ACK_PREFIX "%s", message.key);
    gOutbox.send(macAddr, ackKey, message.value);
  }
}
