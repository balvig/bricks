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

    debugMessages();
  }

  void Outbox::send(const char* key, const char* value) {
    char macStr[MAC_STR_SIZE];
    Bricks::Utils::macToStr(gatewayMac, macStr);
    Log.notice("ESPN: Using stored gateway MAC [%s]" CR, macStr);

    send(gatewayMac, key, value);
  }

  void Outbox::pair(const uint8_t *macAddr) {
    if(WifiEspNow.hasPeer(macAddr)) {
      Log.trace("ESPN: Already paired" CR);
      return;
    }

    char macStr[MAC_STR_SIZE];
    Bricks::Utils::macToStr(macAddr, macStr);
    Log.trace("ESPN: Pairing [%s] [%s]" CR, macStr, BRICKS_AP_CHANNEL);

    if(WifiEspNow.addPeer(macAddr, BRICKS_AP_CHANNEL)) {
      Log.trace("ESPN: Paired" CR);
    }
    else {
      Log.error("ESPN: Pairing failed" CR);
    }
  }

  void Outbox::setGatewayMac(const uint8_t *macAddr) {
    for (int i = 0; i < MAC_ADDR_SIZE; ++i) {
      gatewayMac[i] = macAddr[i];
    }

    char macStr[MAC_STR_SIZE];
    Bricks::Utils::macToStr(gatewayMac, macStr);
    Log.notice("BRIC: Current gateway MAC [%s]" CR, macStr);
  }

  // Not used, but keeping around for debugging for now
  void Outbox::debugMessages() {
    Log.notice("ESPN: Last packet result [%d]" CR, WifiEspNow.getSendStatus());

    const int MAX_PEERS = 20;
    WifiEspNowPeerInfo peers[MAX_PEERS];
    int nPeers = std::min(WifiEspNow.listPeers(peers, MAX_PEERS), MAX_PEERS);

    for (int i = 0; i < nPeers; ++i) {
      char macStr[MAC_STR_SIZE];
      Bricks::Utils::macToStr(peers[i].mac, macStr);
      Log.notice("ESPN: Peer %d [%s] [%d]" CR, i, macStr, peers[i].channel);
    }
  }

  Outbox gOutbox = Outbox();
}
