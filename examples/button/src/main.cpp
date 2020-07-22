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

uint8_t gatewayMac[] = MAC_ALL; // default to broadcasting to all

void getBattery(const uint8_t *macAddr, const Message message) {
  char battery[10];
  sprintf (battery, "%i", analogRead(A0));
  gOutbox.send(macAddr, "battery", (const char*)battery);
}

void setup() {
  // Logging
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_ERROR, &Serial);

  // Configure ESPNow
  gBrick.init();

  // Enable receiving messages and store gateway mac on ping
  gInbox.init();
  gInbox.actions[0] = new PongAction("Button");
  gInbox.actions[1] = new StoreGatewayAction(gatewayMac);
  gInbox.actions[2] = new Action("getBattery", &getBattery);
}

void loop() {
  if(button.onPressed()) {
    gOutbox.send(gatewayMac, "pressed");
  }

  if(button.onReleased()) {
    gOutbox.send(gatewayMac, "released");
  }
}
