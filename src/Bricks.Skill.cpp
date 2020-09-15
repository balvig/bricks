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
    setAckValue(message.value);
    ack(macAddr);
    customCallback(macAddr, message);
  }

  bool Skill::respondsTo(const char *compareKey) {
    return (strcmp(key, compareKey) == 0 || strcmp(key, ANY) == 0);
  }

  void Skill:setAckValue(const char *value) {
    this->ackValue = value;
  }

  void Skill:ack(const uint8_t *macAddr) {
    char ackKey[KEY_SIZE];
    sprintf(ackKey, BRICKS_ACK_PREFIX "%s", message.key);
    gOutbox.send(macAddr, ackKey, ackValue);
  }
}
