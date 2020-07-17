#include "Bricks.Brick.h"

namespace Bricks {
  void Brick::init(const WiFiMode_t wifiMode, Print* logOutput) {
    // Configure Logging
    Serial.begin(115200);
    Log.begin(LOG_LEVEL_NOTICE, logOutput, false);
    Log.setSuffix(Brick::printNewline);

    // Configure Wi-Fi
    WiFi.mode(wifiMode);

    // Connect ESPNOW
    if (WifiEspNow.begin()) {
      String macStr = WiFi.softAPmacAddress();
      macStr.toLowerCase();
      Log.notice("ESPN: Initialized [%s]", macStr.c_str());
    }
    else {
      Log.error("ESPN: Error initializing");
    }
  }

  void Brick::printNewline(Print* logOutput) {
    logOutput->print("\n");
  }


  Brick gBrick = Brick();
}
