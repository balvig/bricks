// Bricks
#include <Bricks.Brick.h>
#include <Bricks.PirSkill.h>
using namespace Bricks;

void setup() {
  // Logging
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);

  // Configure Brick
  gBrick.init("PIR");
  gBrick.skills[0] = new PirSkill();
}

void loop() {
  gBrick.loop();
}
