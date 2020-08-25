// Bricks
#include <Bricks.Brick.h>
#include <Bricks.Constants.h>
#include <Bricks.Inbox.h>
#include <Bricks.OtaAction.h>
using namespace Bricks;

void setup() {
  // Logging
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);

  // Configure ESPNow
  gBrick.init();

  // Configure inbox
  gInbox.init("Button");
  gInbox.actions[0] = new OtaAction();
}

void loop() {
  ArduinoOTA.handle();
}
