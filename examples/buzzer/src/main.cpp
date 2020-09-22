// Bricks
#include <Bricks.Brick.h>
using namespace Bricks;

// Local
const int BUZZER = D5;

// Bricks callbacks
void playTone(BRICKS_CALLBACK_SIGNATURE) {
  int frequency;
  int duration;
  sscanf(message.value, "%d,%d", &frequency, &duration);

  tone(BUZZER, frequency, duration);
}

void setup() {
  // Logging
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);

  // Configure buzzer
  pinMode(BUZZER, OUTPUT);

  // Configure Brick
  gBrick.init("Buzzer");
  gBrick.skills[0] = new Skill("tone", &playTone);

}

void loop() {
  gBrick.loop();
}
