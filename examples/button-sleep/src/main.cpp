// Bricks
#include <Bricks.Brick.h>
#include <Bricks.Constants.h>
#include <Bricks.Inbox.h>
#include <Bricks.AckAction.h>
#include <Bricks.BatteryAction.h>
#include <Bricks.OtaAction.h>
#include <Bricks.PongAction.h>
#include <Bricks.SleepAction.h>
#include <Bricks.StoreGatewayAction.h>
using namespace Bricks;

void setup() {
  // Logging
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);

  // Configure ESPNow
  gBrick.init();

  gInbox.init();
  gInbox.actions[0] = new AckAction();
  gInbox.actions[1] = new PongAction("Button");
  gInbox.actions[2] = new StoreGatewayAction();
  gInbox.actions[3] = new SleepAction();
  gInbox.actions[4] = new OtaAction();
  gInbox.actions[5] = new BatteryAction();
}

void loop() {
  ArduinoOTA.handle();
}
