#include <Bricks.Skill.h>

namespace Bricks {
  Skill::Skill(const char *key, std::function<void(BRICKS_CALLBACK_SIGNATURE)> customCallback, bool sendAck) {
    this->key = key;
    this->customCallback = customCallback;
    this->sendAck = sendAck;
  }

  bool Skill::respondsTo(const char *compareKey) {
    return (strcmp(key, compareKey) == 0 || strcmp(key, ANY) == 0);
  }

  void Skill::process(const uint8_t *macAddr, const Message message) {
    char response[100];
    strcpy(response, message.value);
    callback(macAddr, message, response);

    if(sendAck) {
      ack(response);
    }
  }

  void Skill::callback(BRICKS_CALLBACK_SIGNATURE) {
    customCallback(macAddr, message, response);
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
