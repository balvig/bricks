#include <Bricks.Skill.h>

namespace Bricks {
  Skill::Skill(const char *key, std::function<void(const uint8_t *macAddr, const Message message)> customCallback) {
    this->key = key;
    this->customCallback = customCallback;
  }

  bool Skill::respondsTo(const char *compareKey) {
    return (strcmp(key, compareKey) == 0 || strcmp(key, ANY) == 0);
  }

  void Skill::process(const uint8_t *macAddr, const Message message) {
    char response[100];
    callback(macAddr, message, response);

    // Doesn't work yet. Always true.
    if(response) {
      ack(response);
    }
  }

  void Skill::callback(BRICKS_CALLBACK_SIGNATURE) {
    customCallback(macAddr, message);
  }

  void Skill::loop() {
    // Do nothing by default
  }

  void Skill::ack(const char *response) {
    char ackKey[KEY_SIZE];
    sprintf(ackKey, "%s:%s", ACK_PREFIX, key);
    gOutbox.send(ackKey, response);
  }
}
