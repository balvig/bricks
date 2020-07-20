#include "Bricks.Outbox.h"

namespace Bricks {
  void Outbox::send(const uint8_t *macAddr, const char* key, const char* value) {
    pair(macAddr);

    Message message;
    strcpy(message.key, key);
    strcpy(message.value, value);

    char macStr[MAC_STR_SIZE];
    Bricks::Utils::macToStr(macAddr, macStr);
    Log.notice("ESPN: -> %s [%s] [%s]" CR, macStr, message.key, message.value);

    bool ok = WifiEspNow.send(macAddr, reinterpret_cast<const uint8_t*>(&message), sizeof(message));
    if(ok) {
      Log.trace("ESPN: Sent message" CR);
    }
    else {
      Log.error("ESPN: Error sending message" CR);
    }
  }

  void Outbox::pair(const uint8_t *macAddr) {
    if(WifiEspNow.hasPeer(macAddr)) {
      Log.trace("ESPN: Already paired" CR);
      return;
    }

    char macStr[MAC_STR_SIZE];
    Bricks::Utils::macToStr(macAddr, macStr);
    Log.trace("ESPN: Pairing [%s]" CR, macStr);

    if(WifiEspNow.addPeer(macAddr)) {
      Log.trace("ESPN: Paired" CR);
    }
    else {
      Log.error("ESPN: Pairing failed" CR);
    }
  }

  Outbox gOutbox = Outbox();
}