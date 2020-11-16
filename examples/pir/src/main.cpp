// Bricks
#include <Bricks.Brick.h>
using namespace Bricks;

// Local
const int PIR = D3;

void scan(BRICKS_CALLBACK_SIGNATURE) {
  sprintf(response, "%i", digitalRead(PIR));
}

void setup() {
  // Logging
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);

  // Configure PIR
  pinMode(PIR, INPUT);

  // Configure Brick
  gBrick.init("PIR");
  gBrick.skills[0] = new Skill("scan", &scan);
}

void loop() {
  gBrick.loop();
}
