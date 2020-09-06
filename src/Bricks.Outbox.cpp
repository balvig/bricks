#include "Bricks.Outbox.h"

namespace Bricks {
  Outbox::Outbox() {
    setGatewayMac();
  }

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

  void Outbox::send(const char* key, const char* value) {
    char macStr[MAC_STR_SIZE];
    Bricks::Utils::macToStr(gatewayMac, macStr);
    Log.trace("ESPN: Using stored gateway MAC [%s]" CR, macStr);

    send(gatewayMac, key, value);
  }

  void Outbox::pair(const uint8_t *macAddr) {
    if(WifiEspNow.hasPeer(macAddr)) {
      Log.trace("ESPN: Already paired" CR);
      return;
    }

    char macStr[MAC_STR_SIZE];
    Bricks::Utils::macToStr(macAddr, macStr);
    Log.trace("ESPN: Pairing [%s]" CR, macStr);

    if(WifiEspNow.addPeer(macAddr, BRICKS_WIFI_CHANNEL)) {
      Log.trace("ESPN: Paired" CR);
    }
    else {
      Log.error("ESPN: Pairing failed" CR);
    }
  }

  void Outbox::setGatewayMac() {
    sscanf(BRICKS_GATEWAY_MAC, MAC_FORMAT,
        &gatewayMac[0], &gatewayMac[1], &gatewayMac[2], &gatewayMac[3], &gatewayMac[4], &gatewayMac[5]);
  }

  Outbox gOutbox = Outbox();
}
