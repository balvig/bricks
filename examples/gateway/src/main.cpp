// Bricks
#include <Bricks.Brick.h>
#include <Bricks.PublishSkill.h>
using namespace Bricks;

#ifdef ARDUINO_M5Stack_Core_ESP32
#include <M5Stack.h>
#include <ScrollTextWindow.h>
ScrollTextWindow stw;
#endif

// Main
void setup() {
  // Logging
#ifdef ARDUINO_M5Stack_Core_ESP32
  M5.begin();
  Log.begin(LOG_LEVEL_NOTICE, &stw);
#else
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);
#endif

  // Configure Brick
  gBrick.initBase(WIFI_AP_STA);
  gBrick.skills[0] = new PublishSkill(); // Publish all received messages to mqtt
}

void loop() {
  gBrick.loop();
}
