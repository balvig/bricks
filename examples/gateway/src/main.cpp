// Bricks
#include <Bricks.Brick.h>
#include <Bricks.Events.h>
#include <Bricks.Inbox.h>
#include <Bricks.Outbox.h>
#include <Bricks.PublishAction.h>
using namespace Bricks;

#ifdef ARDUINO_M5Stack_Core_ESP32
#include <M5Logger.h>
#endif

// Main
void setup() {
  // Logging
#ifdef ARDUINO_M5Stack_Core_ESP32
  M5Logger::init(LOG_LEVEL_NOTICE); // unstable with high activity
#else
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);
#endif

  // Configure ESPNOW
  gBrick.init(WIFI_AP_STA);

  // Connect mqtt event stream
  gEvents.init();

  // Enable receiving messages
  gInbox.init();
  gInbox.actions[0] = new PublishAction(); // Publish all received messages to mqtt
}

void loop() {
  gEvents.loop();
}
