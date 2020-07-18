// Local
#include <RBD_Timer.h>
#include <RBD_Button.h>

// Bricks
#include <Bricks.Brick.h>
#include <Bricks.Constants.h>
#include <Bricks.Inbox.h>
#include <Bricks.Outbox.h>
#include <Bricks.PongAction.h>
#include <Bricks.StoreGatewayAction.h>
#include <Bricks.Utils.h>
using namespace Bricks;

#ifdef ESP8266
RBD::Button button(0);
#elif ESP32
RBD::Button button(GPIO_NUM_17);
#endif

uint8_t gatewayMac[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}; // default to broadcasting to all

void setup() {
  // Logging
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);

  // Configure ESPNOW
  gBrick.init();

  // Enable receiving messages and store gateway mac on ping
  gInbox.init();
  gInbox.actions[0] = new PongAction("button");
  gInbox.actions[1] = new StoreGatewayAction(gatewayMac);
}

void loop() {
  if(button.onPressed()) {
    gOutbox.send(gatewayMac, "pressed");
  }

  if(button.onReleased()) {
    gOutbox.send(gatewayMac, "released");
  }
}
