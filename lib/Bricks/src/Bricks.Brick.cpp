#include "Bricks.Brick.h"

namespace Bricks {
  void Brick::init(Print* logOutput) {
    // Configure Logging
    Serial.begin(115200);
    Log.begin(LOG_LEVEL_NOTICE, logOutput, false);
    Log.setSuffix(Brick::printNewline);

    // Configure Wi-Fi
    WiFi.mode(WIFI_AP_STA);

    // Connect ESPNOW
    if (WifiEspNow.begin()) {
      Log.notice("ESP-NOW initialized. [%s]", WiFi.softAPmacAddress().c_str());
    }
    else {
      Log.error("Error initializing ESP-NOW");
    }
  }

  void Brick::printNewline(Print* logOutput) {
    logOutput->print("\n");
  }


  Brick gBrick = Brick();
}
