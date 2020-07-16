#include <Bricks.Brick.h>
#include <Bricks.Inbox.h>
#include <Bricks.Outbox.h>
#include <Bricks.PongAction.h>
using namespace Bricks;

// Custom Actions
void debug(const uint8_t *macAddr, const Message message) {
  Serial.print("ping value: ");
  Serial.println(message.value);
}

void setup() {
  // Logger and ESPNOW
  gBrick.init();

  // Enable receiving messages
  gInbox.init();
  gInbox.actions[0] = new PongAction("ponger");
  gInbox.actions[1] = new Action("ping", &debug);
}

void loop() {
}
