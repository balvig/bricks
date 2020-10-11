// Bricks
#include <Bricks.Brick.h>
#include <Bricks.Outbox.h>
using namespace Bricks;

// Local
#include <Lumi.Animator.h>

Lumi::Animator animator;

// Bricks callbacks
void setLED(BRICKS_CALLBACK_SIGNATURE) {
  unsigned int pattern;
  unsigned int variation;
  unsigned int delay;

  int matches = sscanf(message.value, "%u,%u,%u", &pattern, &variation, &delay);

  if(matches >= 1) { animator.currentPattern = pattern; }
  if(matches >= 2) { animator.currentVariation = variation; }
  if(matches >= 3) { animator.currentDelay = delay; }
}

void setup() {
  // Logging
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);

  // Configure Brick
  gBrick.init("LED RGB");
  gBrick.skills[0] = new Skill("setLED", &setLED);
}

void loop() {
  gBrick.loop();
  animator.loop();
}
