#include <Bricks.Action.h>

namespace Bricks {
  Action::Action(const char *key, std::function<void(const uint8_t *macAddr, const Message message)> customCallback) {
    this->key = key;
    this->customCallback = customCallback;
  }

  void Action::callback(const uint8_t *macAddr, const Message message) {
    customCallback(macAddr, message);
  }

  bool Action::respondsTo(const char *compareKey) {
    return (strcmp(key, compareKey) == 0 || strcmp(key, ANY) == 0);
  }
}
