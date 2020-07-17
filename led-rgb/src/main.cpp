// Local
#include <LedAnimator.h>

// Bricks
#include <Bricks.Brick.h>
#include <Bricks.Inbox.h>
#include <Bricks.Outbox.h>
#include <Bricks.PongAction.h>
using namespace Bricks;

LedAnimator animator;

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
  Log.begin(LOG_LEVEL_TRACE, &Serial);

  // Configure ESPNOW
  gBrick.init();

  // Enable receiving messages
  gInbox.init();
  gInbox.actions[0] = new PongAction("LED - RGB");
  gInbox.actions[1] = new Action("color", &setColor);
  gInbox.actions[2] = new Action("pattern", &setPattern);
}

void loop() {
  animator.loop();
}
