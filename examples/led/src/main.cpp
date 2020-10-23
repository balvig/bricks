// Bricks
#include <Bricks.Brick.h>
using namespace Bricks;

const int ledPin = LED_BUILTIN;

void setPattern(BRICKS_CALLBACK_SIGNATURE) {
  if(atoi(message.value)) {
    digitalWrite(ledPin, LOW);
  }
  else {
    digitalWrite(ledPin, HIGH);
  }
}

// Main
void setup() {
  // Logging
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);

  // Led
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  // Configure Brick
  gBrick.init("LED");
  gBrick.skills[0] = new Skill("set", &setPattern);
}

void loop() {
  gBrick.loop();
}
