// Bricks
#include <Bricks.Brick.h>
#include <Bricks.Inbox.h>
#include <Bricks.Outbox.h>
#include <Bricks.PongAction.h>
#include <Bricks.SleepAction.h>
#include <Bricks.StoreGatewayAction.h>
using namespace Bricks;

// Local
#include <LedAnimator.h>

LedAnimator animator;

uint8_t gatewayMac[] = MAC_ALL; // default to broadcasting to all

// Bricks callbacks
void setColor(const uint8_t *macAddr, const Message message) {
  animator.currentColor = atoi(message.value);
}

void setPattern(const uint8_t *macAddr, const Message message) {
  animator.currentPattern = atoi(message.value);
}

void setup() {
  // Logging
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);

  // Configure ESPNOW
  gBrick.init();

  // Enable receiving messages
  gInbox.init();
  gInbox.actions[0] = new PongAction("LED - RGB");
  gInbox.actions[1] = new StoreGatewayAction(gatewayMac);
  gInbox.actions[2] = new SleepAction(gatewayMac);
  gInbox.actions[3] = new Action("setColor", &setColor);
  gInbox.actions[4] = new Action("setPattern", &setPattern);
}

void loop() {
  animator.loop();
}
