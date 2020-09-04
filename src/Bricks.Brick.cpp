#include "Bricks.Brick.h"

namespace Bricks {
  void Brick::init(const WiFiMode_t wifiMode) {
    // Configure Wi-Fi
    WiFi.mode(wifiMode);
    WiFi.softAP("ESPNOW", NULL, BRICKS_WIFI_CHANNEL, true, 0); // hide AP

    // Connect ESPNOW
    if (WifiEspNow.begin()) {
      logMac(wifiMode);
    }
    else {
      Log.error("ESPN: Error initializing" CR);
    }
  }

  void Brick::logMac(WiFiMode_t wifiMode) {
    String macStr;

    if(wifiMode == WIFI_STA) {
      macStr = WiFi.macAddress();
    }
    else {
      macStr = WiFi.softAPmacAddress();
    }

    macStr.toLowerCase();
    Log.notice("ESPN: Initialized [%s]" CR, macStr.c_str());
  }

  Brick gBrick = Brick();
}
