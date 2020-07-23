// Bricks
#include <Bricks.Brick.h>
#include <Bricks.Constants.h>
#include <Bricks.Inbox.h>
#include <Bricks.PongAction.h>
#include <Bricks.SleepAction.h>
#include <Bricks.StoreGatewayAction.h>
using namespace Bricks;

uint8_t gatewayMac[] = MAC_ALL; // default to broadcasting to all

void setup() {
  // Logging
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);

  // Configure ESPNow
  gBrick.init();

  // Enable receiving messages, store gateway mac on ping, allow sleep
  gInbox.init();
  gInbox.actions[0] = new PongAction("Button - Sleep");
  gInbox.actions[1] = new StoreGatewayAction(gatewayMac);
  gInbox.actions[2] = new SleepAction(gatewayMac);
}

void loop() {
}
