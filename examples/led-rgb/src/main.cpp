// Bricks
#include <Bricks.Brick.h>
#include <Bricks.Inbox.h>
#include <Bricks.Outbox.h>
#include <Bricks.AckAction.h>
#include <Bricks.PongAction.h>
#include <Bricks.SleepAction.h>
#include <Bricks.StoreGatewayAction.h>
using namespace Bricks;

// Local
#include <Lumi.Animator.h>

Lumi::Animator animator;

// Bricks callbacks
void setPattern(const uint8_t *macAddr, const Message message) {
  animator.currentPattern = atoi(message.value);
}

void setVariation(const uint8_t *macAddr, const Message message) {
  animator.currentVariation = atoi(message.value);
}

void setDelay(const uint8_t *macAddr, const Message message) {
  animator.currentDelay = atoi(message.value);
}


void setup() {
  // Logging
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);

  // Configure ESPNOW
  gBrick.init();

  // Enable receiving messages
  gInbox.init();
  gInbox.actions[0] = new AckAction();
  gInbox.actions[1] = new PongAction("LED RGB");
  gInbox.actions[2] = new StoreGatewayAction();
  gInbox.actions[3] = new Action("setPattern", &setPattern);
  gInbox.actions[4] = new Action("setVariation", &setVariation);
  gInbox.actions[5] = new Action("setDelay", &setDelay);
}

void loop() {
  animator.update();
}
