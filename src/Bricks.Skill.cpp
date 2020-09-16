#include <Bricks.Skill.h>

namespace Bricks {
  Skill::Skill(const char *key, std::function<void(const uint8_t *macAddr, const Message message)> customCallback) {
    this->key = key;
    this->customCallback = customCallback;
  }

  void Skill::loop() {
    // Do nothing
  }

  void Skill::callback(const uint8_t *macAddr, const Message message) {
    ack(message.value);
    customCallback(macAddr, message);
  }

  bool Skill::respondsTo(const char *compareKey) {
    return (strcmp(key, compareKey) == 0 || strcmp(key, ANY) == 0);
  }

  void Skill:ack(const char *value) {
    char ackKey[KEY_SIZE];
    sprintf(ackKey, BRICKS_ACK_PREFIX "%s", key);
    gOutbox.send(ackKey, value);
  }
}
