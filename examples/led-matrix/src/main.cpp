// Bricks
#include <Bricks.Brick.h>
#include <Bricks.Constants.h>
#include <Bricks.Inbox.h>
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

  // Configure inbox
  gInbox.init("LED 8x8 Matrix");
  gInbox.actions[0] = new Action("setValue", &setValue);
}

void loop() {
}
