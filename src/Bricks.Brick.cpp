#include "Bricks.Brick.h"

namespace Bricks {
  void Brick::init(const WiFiMode_t wifiMode) {
    // Configure Wi-Fi
    WiFi.mode(wifiMode);

    // Connect ESPNOW
    if (WifiEspNow.begin()) {
      String macStr = WiFi.softAPmacAddress();
      macStr.toLowerCase();
      Log.notice("ESPN: Initialized [%s]" CR, macStr.c_str());
    }
    else {
      Log.error("ESPN: Error initializing" CR);
    }
  }

  Brick gBrick = Brick();
}
