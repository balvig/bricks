// Bricks
#include <Bricks.Brick.h>
using namespace Bricks;

// Local
#include <RBD_Timer.h>

RBD::Timer timer;
const int PIR = D3;
const uint16_t DEFAULT_FREQUENCY = 1000;

uint8_t previousStatus = 0;
uint8_t currentStatus = 0;
char status[1];

void notifyChanges() {
  currentStatus = digitalRead(PIR);

  if(currentStatus != previousStatus) {
    previousStatus = currentStatus;
    sprintf(status, "%i", currentStatus);
    gOutbox.send("status", (const char*)status);
  }
}

void setup() {
  // Logging
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);

  // Configure PIR
  pinMode(PIR, INPUT);
  timer.setTimeout(DEFAULT_FREQUENCY);
  timer.restart();

  // Configure Brick
  gBrick.init("PIR");
}

void loop() {
  if(timer.onRestart()) {
    notifyChanges();
  }
  gBrick.loop();
}
