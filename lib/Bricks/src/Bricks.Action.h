#ifndef BRICKS_ACTION_H
#define BRICKS_ACTION_H

#include <ArduinoLog.h>
#include <functional>
#include <Bricks.Message.h>

namespace Bricks {
  class Action {
    const char *ANY = "*";

    public:
      Action(const char *key = "", std::function<void(const uint8_t *macAddr, const Message message)> customCallback = nullptr);
      bool respondsTo(const char* compareKey);
      virtual void callback(const uint8_t *macAddr, const Message message);
      const char *key;
    private:
      std::function<void(const uint8_t *macAddr, const Message message)> customCallback;
  };
}
#endif
