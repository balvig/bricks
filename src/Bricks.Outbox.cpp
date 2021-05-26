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
    Log.noticeln("ESPN: -> %s [%s] [%s]", macStr, message.key, message.value);

    bool ok = WifiEspNow.send(macAddr, reinterpret_cast<const uint8_t*>(&message), sizeof(message));
    if(ok) {
      Log.traceln("ESPN: Message sent");
    }
    else {
      Log.errorln("ESPN: Error sending message");
    }
  }

  void Outbox::send(const char* key, const char* value) {
    char macStr[MAC_STR_SIZE];
    Bricks::Utils::macToStr(gatewayMac, macStr);
    Log.traceln("ESPN: Using stored gateway MAC [%s]", macStr);

    send(gatewayMac, key, value);
  }

  void Outbox::pair(const uint8_t *macAddr) {
    if(WifiEspNow.hasPeer(macAddr)) {
      Log.traceln("ESPN: Already paired");
      return;
    }

    char macStr[MAC_STR_SIZE];
    Bricks::Utils::macToStr(macAddr, macStr);
    Log.traceln("ESPN: Pairing [%s]", macStr);

    if(WifiEspNow.addPeer(macAddr, BRICKS_WIFI_CHANNEL)) {
      Log.traceln("ESPN: Paired");
    }
    else {
      Log.errorln("ESPN: Pairing failed");
    }
  }

  void Outbox::setGatewayMac() {
    sscanf(BRICKS_GATEWAY_MAC, MAC_FORMAT,
        &gatewayMac[0], &gatewayMac[1], &gatewayMac[2], &gatewayMac[3], &gatewayMac[4], &gatewayMac[5]);
  }

  Outbox gOutbox = Outbox();
}
