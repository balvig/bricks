#ifndef BRICKS_BRICK_H
#define BRICKS_BRICK_H

#include <ArduinoLog.h>
#ifdef ESP8266
#include <ESP8266WiFi.h>
#elif ESP32
#include <WiFi.h>
#endif
#include <WifiEspNow.h>

namespace Bricks {
  class Brick {
    public:
      void init(const WiFiMode_t wifiMode = WIFI_AP, Print* logOutput = &Serial);
    private:
      static void printNewline(Print* logOutput);
  };

  extern Brick gBrick;
}
#endif
