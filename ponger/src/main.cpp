#include <Bricks.Brick.h>
#include <Bricks.Inbox.h>
#include <Bricks.PongAction.h>
using namespace Bricks;

void setup() {
  // Logger and ESPNOW
  gBrick.init();

  // Enable receiving messages
  gInbox.init();
  gInbox.actions[0] = new PongAction("ponger");
}

void loop() {
}
