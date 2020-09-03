// Bricks
#include <Bricks.Brick.h>
#include <Bricks.Constants.h>
#include <Bricks.Inbox.h>
using namespace Bricks;

void setup() {
  // Logging
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);

  // Configure ESPNow
  gBrick.init();

  // Configure inbox
  gInbox.init("Button");
}

void loop() {
  gInbox.loop();
}
