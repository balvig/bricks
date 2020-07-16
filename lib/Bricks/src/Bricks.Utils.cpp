#include "Bricks.Utils.h"

namespace Bricks {
  void Utils::macToStr(const uint8_t *macAddr, char *macStr) {
    snprintf(macStr, MAC_STR_SIZE, MAC_FORMAT,
        macAddr[0], macAddr[1], macAddr[2], macAddr[3], macAddr[4], macAddr[5]);
  }

  void Utils::parseTopic(const char *topic, uint8_t *macAddr, char *key) {
    sscanf(topic, "accounts/balvig/bricks/out/" MAC_FORMAT "/%s", // TODO: Un-hardcode
        &macAddr[0], &macAddr[1], &macAddr[2], &macAddr[3], &macAddr[4], &macAddr[5], key);
  }
}
