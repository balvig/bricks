#ifndef BRICKS_BRICK_H
#define BRICKS_BRICK_H

#include <ArduinoLog.h>
#ifdef ESP8266
#include <ESP8266WiFi.h>
#elif ESP32
#include <WiFi.h>
#endif
#include <WifiEspNow.h>

#include <Bricks.Constants.h>

namespace Bricks {
  class Brick {
    public:
      void init(const WiFiMode_t wifiMode = WIFI_AP); // AP is more stable that STA when communication with AT_STA
    private:
      void logMac(WiFiMode_t wifiMode);
  };

  extern Brick gBrick;
}
#endif
