// Bricks
#include <Bricks.Brick.h>
#include <Bricks.Outbox.h>
using namespace Bricks;

// Local
#include "M5Atom.h"
#include <RBD_Timer.h>
#include <RBD_Button.h>

RBD::Button button(GPIO_NUM_39);

// Bricks callbacks
void setPattern(BRICKS_CALLBACK_SIGNATURE) {
  const int pattern = atoi(message.value);
  CRGB color = 0x000000; // Off

  switch(pattern) {
    case 1:
      color = 0xfff000; // Yellow
      break;
    case 2:
      color = 0xff0000; // Red
      break;
    case 3:
      color = 0x0000f0; // Blue
      break;
    case 4:
      color = 0x00ff00;  // Green
      break;
  }

  M5.dis.setBrightness(100);
  M5.dis.fillpix(color);
}

void setup() {
  // Logging
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);

  // Configure Brick
  gBrick.init("Atom");
  gBrick.skills[0] = new Skill("set", &setPattern);

  // Configure M5 Atom
  M5.begin(true, false, true);
}

void loop() {
  if(button.onPressed()) {
    gOutbox.send("pressed");
  }

  if(button.onReleased()) {
    gOutbox.send("released");
  }

  gBrick.loop();
}
