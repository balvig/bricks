// Bricks
#include <Bricks.Brick.h>
#include <Bricks.Inbox.h>
#include <Bricks.Outbox.h>
#include <Bricks.PongAction.h>
using namespace Bricks;

const int ledPin = LED_BUILTIN;

void ledOn(const uint8_t *macAddr, const Message message) {
  digitalWrite(ledPin, LOW);
}

void ledOff(const uint8_t *macAddr, const Message message) {
  digitalWrite(ledPin, HIGH);
}

//Main
void setup() {
  // Led
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  // Logger and ESPNOW
  gBrick.init();

  // Enable receiving messages
  gInbox.init();
  gInbox.actions[0] = new PongAction("led");
  gInbox.actions[1] = new Action("on", &ledOn);
  gInbox.actions[2] = new Action("off", &ledOff);
}

void loop() {
}
