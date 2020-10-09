// Bricks
#include <Bricks.Brick.h>
using namespace Bricks;

void setup() {
  // Logging
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);

  // Configure Brick
  gBrick.init("Dash Button");

  // Give a moment to respond to any messages
  delay(300);

  // Put to sleep indefinitely
  Utils::deepSleep(0);
}

void loop() {
}
