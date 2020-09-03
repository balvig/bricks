#include <Bricks.ClaimAction.h>

namespace Bricks {
  ClaimAction::ClaimAction() : Action("claim") {
    readMac();

    if(Utils::wasManuallyReset()) {
      pingGateway();
    }
  }

  void ClaimAction::loop() {
    if(awaitingClaim && claimTimedOut()) {
      startAdvertising();
    }
  }

  void ClaimAction::callback(const uint8_t *macAddr, const Message message) {
    writeMac(macAddr);
    awaitingClaim = false;
  }

  void ClaimAction::writeMac(const uint8_t *macAddr) {
    Log.notice("EEPR: Storing gateway MAC" CR);

    for (int i = 0; i < MAC_ADDR_SIZE; ++i) {
      EEPROM.write(i, macAddr[i]);
    }
    EEPROM.commit();

    gOutbox.setGatewayMac(macAddr);
  }

  void ClaimAction::readMac() {
    Log.notice("EEPR: Reading gateway MAC" CR);
    EEPROM.begin(MAC_ADDR_SIZE);

    uint8_t macAddr[MAC_ADDR_SIZE];

    for (int i = 0; i < MAC_ADDR_SIZE; ++i) {
      macAddr[i] = EEPROM.read(i);
    }

    gOutbox.setGatewayMac(macAddr);
  }

  void ClaimAction::pingGateway() {
    startMillis = millis();
    awaitingClaim = true;
    gOutbox.send("ping", "Brick name");
  }

  bool ClaimAction::claimTimedOut() {
    currentMillis = millis();
    return currentMillis - startMillis >= WAIT_TIME;
  }

  void ClaimAction::startAdvertising() {
    awaitingClaim = false;
    char apName[50];
    sprintf(apName, BRICKS_NAME_PREFIX "%s", WiFi.softAPmacAddress().c_str());
    WiFi.softAP(apName, NULL, BRICKS_WIFI_CHANNEL);
    Log.notice("WIFI: Started advertising [%s]" CR, apName);
  }

  void Events::scanForGateway() {
    Log.notice("WIFI: Scanning for gateway" CR);
    const uint8_t scanResults = WiFi.scanNetworks();

    for(int i = 0; i < scanResults; ++i) {
      if(WiFi.SSID(i).indexOf(BRICKS_NAME_PREFIX) == 0) {
        Log.trace("WIFI: Gateway found on channel %d" CR, WiFi.channel(i));
        gOutbox.send(WiFi.BSSID(i), BRICKS_PING_ACTION);
      }
    }

    WiFi.scanDelete();
    Log.notice("WIFI: Scan complete" CR);
  }
}
