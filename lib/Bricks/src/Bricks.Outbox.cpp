#include "Bricks.Outbox.h"

namespace Bricks {
  void Outbox::send(const uint8_t *macAddr, const char* key, const char* value) {
    pair(macAddr);

    Message message;
    strcpy(message.key, key);
    strcpy(message.value, value);

    char macStr[Bricks::Utils::MAC_STR_SIZE];
    Bricks::Utils::macToStr(macAddr, macStr);
    Log.notice("Sending message. <key: %s, value: %s, mac: %s>", message.key, message.value, macStr);

    bool ok = WifiEspNow.send(macAddr, reinterpret_cast<const uint8_t*>(&message), sizeof(message));
    if(ok) {
      Log.notice("Sent");
    }
    else {
      Log.error("Error sending the data");
    }
  }

  void Outbox::pair(const uint8_t *macAddr) {
    if(WifiEspNow.hasPeer(macAddr)) {
      Log.notice("Already paired");
    }
    else {
      char macStr[Bricks::Utils::MAC_STR_SIZE];
      Bricks::Utils::macToStr(macAddr, macStr);
      Log.notice("Pairing with %s", macStr);

      if(WifiEspNow.addPeer(macAddr)) {
        Log.notice("Paired");
      }
      else {
        Log.error("Pairing failed");
      }
    }
  }

  Outbox gOutbox = Outbox();
}
