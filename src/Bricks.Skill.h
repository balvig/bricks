#ifndef BRICKS_SKILL_H
#define BRICKS_SKILL_H

#include <ArduinoLog.h>
#include <functional>
#include <Bricks.Message.h>

namespace Bricks {
  class Skill {
    const char *ANY = "*";
    const char *ACK_PREFIX = "ack:"

    public:
      Skill(const char *key = "", std::function<void(const uint8_t *macAddr, const Message message)> customCallback = nullptr);
      bool respondsTo(const char* compareKey);
      virtual void loop();
      virtual void callback(const uint8_t *macAddr, const Message message);
      const char *key;
    private:
      virtual void setAckValue(const char *value);
      void ack();
      const char *ackValue;
      std::function<void(const uint8_t *macAddr, const Message message)> customCallback;
  };
}
#endif
