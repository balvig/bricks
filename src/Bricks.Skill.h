#ifndef BRICKS_SKILL_H
#define BRICKS_SKILL_H

#include <ArduinoLog.h>
#include <functional>
#include <Bricks.Message.h>
#include <Bricks.Outbox.h>

#define BRICKS_CALLBACK_SIGNATURE const uint8_t *macAddr, const Message message, char *response

namespace Bricks {
  class Skill {
    const char *ANY = "*";
    const char *ACK_PREFIX = "ack";

    public:
      Skill(const char *key = "", std::function<void(BRICKS_CALLBACK_SIGNATURE)> customCallback = nullptr, bool sendAck = true);
      bool respondsTo(const char* compareKey);
      void process(const uint8_t *macAddr, const Message message);
      virtual void callback(BRICKS_CALLBACK_SIGNATURE);
      virtual void loop();
      const char *key;
    private:
      void ack(const char *response);
      bool sendAck;
      std::function<void(BRICKS_CALLBACK_SIGNATURE)> customCallback;
  };
}
#endif
