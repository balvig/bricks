// Bricks
#include <Bricks.Brick.h>
using namespace Bricks;

// Local
#include <WEMOS_Matrix_GFX.h>
#include <Lumi.Sequencer.h>
#include <Lumi.Animation.h>
#include <Lumi.Character.h>
#include <animations.h>

MLED matrix(7);

Lumi::Sequencer sequencer;

// Bricks callbacks
void set(BRICKS_CALLBACK_SIGNATURE) {
  sequencer.set(message.value);
}

void rotate(BRICKS_CALLBACK_SIGNATURE) {
  matrix.setRotation(atoi(message.value));
}

void setup() {
  // Logging
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);

  // Configure Brick
  gBrick.init("LED 8x8 Matrix");
  gBrick.skills[0] = new Skill("set", &set);
  gBrick.skills[1] = new Skill("rotate", &rotate);

  // Configure Matrix
  matrix.setRotation(1); // Matrix will be sideways in Brick

  // Configure animations
  sequencer.patterns[0] = new Lumi::Character(matrix);
  sequencer.patterns[1] = new Lumi::Animation(matrix, fireworksSize, fireworks); // TODO: simplify this
}

void loop() {
  gBrick.loop();
  sequencer.loop();
}
