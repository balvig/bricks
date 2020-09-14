// Bricks
#include <Bricks.Brick.h>
#include <Bricks.Events.h>
#include <Bricks.Inbox.h>
#include <Bricks.Outbox.h>
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

  // Configure ESPNOW
  gBrick.init(WIFI_AP_STA);

  // Connect mqtt event stream
  gEvents.init();

  // Configure inbox
  gInbox.initBase();
  gInbox.skills[0] = new PublishSkill(); // Publish all received messages to mqtt
}

void loop() {
  gEvents.loop();
}
