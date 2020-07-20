// Bricks
#include <Bricks.Brick.h>
#include <Bricks.Events.h>
#include <Bricks.Inbox.h>
#include <Bricks.Outbox.h>
#include <Bricks.PublishAction.h>
using namespace Bricks;

// Main
void setup() {
  // Logging
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);

  // Configure ESPNOW
  gBrick.init(WIFI_AP_STA);

  // Connect mqtt event stream
  gEvents.init();

  // Enable receiving messages
  gInbox.init();

  // Publish all received messages to mqtt
  gInbox.actions[0] = new PublishAction();
}

void loop() {
  gEvents.loop();
}
