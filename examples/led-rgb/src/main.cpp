// Bricks
#include <Bricks.Brick.h>
#include <Bricks.Outbox.h>
using namespace Bricks;

// Local
#include <Lumi.Animator.h>

Lumi::Animator animator;

// Bricks callbacks
void setPattern(BRICKS_CALLBACK_SIGNATURE) {
  animator.currentPattern = atoi(message.value);
}

void setVariation(BRICKS_CALLBACK_SIGNATURE) {
  animator.currentVariation = atoi(message.value);
}

void setDelay(BRICKS_CALLBACK_SIGNATURE) {
  animator.currentDelay = atoi(message.value);
}


void setup() {
  // Logging
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);

  // Configure Brick
  gBrick.init("LED RGB");
  gBrick.skills[0] = new Skill("setPattern", &setPattern);
  gBrick.skills[1] = new Skill("setVariation", &setVariation);
  gBrick.skills[2] = new Skill("setDelay", &setDelay);
}

void loop() {
  gBrick.loop();
  animator.update();
}
