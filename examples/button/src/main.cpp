// Bricks
#include <Bricks.Brick.h>
#include <Bricks.Constants.h>
#include <Bricks.Inbox.h>
#include <Bricks.Outbox.h>
#include <Bricks.PongAction.h>
#include <Bricks.StoreGatewayAction.h>
using namespace Bricks;

// Local
#include <RBD_Timer.h>
#include <RBD_Button.h>

#ifdef ESP8266
RBD::Button button(0);
#elif ESP32
RBD::Button button(GPIO_NUM_17);
#endif

void setup() {
  // Logging
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);

  // Configure ESPNow
  gBrick.init();

  // Enable receiving messages and store gateway mac on ping
  gInbox.init();
  gInbox.actions[0] = new PongAction("Button (Realtime)");
  gInbox.actions[1] = new StoreGatewayAction();
}

void loop() {
  if(button.onPressed()) {
    gOutbox.send("pressed");
  }

  if(button.onReleased()) {
    gOutbox.send("released");
  }
}
