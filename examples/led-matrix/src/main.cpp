// Bricks
#include <Bricks.Brick.h>
#include <Bricks.Constants.h>
#include <Bricks.Inbox.h>
#include <Bricks.AckAction.h>
#include <Bricks.BatteryAction.h>
#include <Bricks.PongAction.h>
#include <Bricks.StoreGatewayAction.h>
#include <Bricks.SleepAction.h>
#include <Bricks.Utils.h>
using namespace Bricks;

// Local
#include <WEMOS_Matrix_GFX.h>

MLED matrix(5);

// Bricks callbacks
void setValue(const uint8_t *macAddr, const Message message) {
  matrix.clear();
  matrix.setCursor(2, 1);
  matrix.print(message.value);
  matrix.writeDisplay();
}

void setup() {
  // Logging
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);

  // Configure ESPNow
  gBrick.init();

  // Enable receiving messages and store gateway mac on ping
  gInbox.init();
  gInbox.actions[0] = new AckAction(); // ack back all messages
  gInbox.actions[1] = new PongAction("LED - 8x8 Matrix");
  gInbox.actions[2] = new StoreGatewayAction();
  gInbox.actions[3] = new SleepAction();
  gInbox.actions[4] = new BatteryAction();
  gInbox.actions[5] = new Action("setValue", &setValue);
}

void loop() {
}
