// Bricks
#include <Bricks.Brick.h>
#include <Bricks.Inbox.h>
#include <Bricks.OtaAction.h>
using namespace Bricks;

// Local
const int BUZZER = D5;

// Bricks callbacks
void playTone(const uint8_t *macAddr, const Message message) {
  int frequency;
  int duration;
  sscanf(message.value, "%d,%d", &frequency, &duration);

  tone(BUZZER, frequency, duration);
}

void setup() {
  // Logging
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);

  // Configure ESPNow
  gBrick.init();

  // Configure inbox
  gInbox.init("Buzzer");
  gInbox.actions[0] = new OtaAction();
  gInbox.actions[1] = new Action("tone", &playTone);

  // Configure buzzer
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  ArduinoOTA.handle();
}
