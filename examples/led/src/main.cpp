// Bricks
#include <Bricks.Brick.h>
#include <Bricks.Inbox.h>
using namespace Bricks;

const int ledPin = LED_BUILTIN;

void setPattern(const uint8_t *macAddr, const Message message) {
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

  // Configure ESPNOW
  gBrick.init();

  // Enable receiving messages
  gInbox.init("LED");
  gInbox.skills[0] = new Skill("setPattern", &setPattern);
}

void loop() {
  gInbox.loop();
}
