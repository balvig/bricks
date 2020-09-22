// Bricks
#include <Bricks.Brick.h>
using namespace Bricks;

// Local
#include <WEMOS_Matrix_GFX.h>

MLED matrix(7);

// Bricks callbacks
void setValue(BRICKS_CALLBACK_SIGNATURE) {
  matrix.clear();
  matrix.setCursor(2, 1);
  matrix.print(message.value);
  matrix.writeDisplay();
}

void setup() {
  // Logging
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);

  // Wemos will be on side
  matrix.setRotation(1);

  // Configure Brick
  gBrick.init("LED 8x8 Matrix");
  gBrick.skills[0] = new Skill("setValue", &setValue);
}

void loop() {
  gBrick.loop();
}
