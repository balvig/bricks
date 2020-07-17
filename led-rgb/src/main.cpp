// Local
#include <Adafruit_NeoPixel.h>
#include <RBD_Timer.h>
// Check out https://github.com/DedeHai/NeoPixelPainter/blob/master/examples/ledstrip_animations/ledstrip_animations.ino

// Bricks
#include <Bricks.Brick.h>
#include <Bricks.Inbox.h>
#include <Bricks.Outbox.h>
#include <Bricks.PongAction.h>
using namespace Bricks;

const uint8_t PIN = D4;
const uint8_t MAX_LEDS = 7;
const uint8_t START_LED = 1;
const uint8_t ANIM_DELAY = 150;

uint8_t red = 0;
uint8_t green = 0;
uint8_t blue = 0;
uint8_t currentLed = START_LED;
const char *currentPattern = "";


Adafruit_NeoPixel leds = Adafruit_NeoPixel(MAX_LEDS, PIN, NEO_GRB + NEO_KHZ800);
RBD::Timer timer;


// Bricks callbacks
void changeColor(const uint8_t *macAddr, const Message message) {
  if(red == 20) {
    red = 0;
    green = 20;
  }
  else {
    red = 20;
    green = 0;
  }
}

void changePattern(const uint8_t *macAddr, const Message message) {
  if(strcmp(currentPattern, "spin") == 0) {
    currentPattern = "circle";
  }
  else {
    currentPattern = "spin";
  }
}

// All the animation stuff
void ledSet(const uint8_t number, const uint8_t r = red, const uint8_t g = green, const uint8_t b = blue) {
  leds.setPixelColor(number, leds.Color(r, g, b));
  leds.show();
}

void spinAnimation() {
  ledSet(currentLed);

  if(timer.onRestart()) {
    ledSet(currentLed, 0, 0, 0);
    currentLed++;

    if(currentLed >= MAX_LEDS) {
      currentLed = START_LED;
    }
  }
}

void showCircle() {
  for(int i = 0; i < MAX_LEDS; i++) {
    ledSet(i);
  }
}

void animateLeds() {
  if(strcmp(currentPattern, "spin") == 0) {
    spinAnimation();
  }
  else if(strcmp(currentPattern, "circle") == 0) {
    showCircle();
  }
  else {
    red = 0;
    green = 0;
    blue = 0;
    showCircle();
  }
}

// Main
void setup() {
  // Logging
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_TRACE, &Serial);

  // Configure ESPNOW
  gBrick.init();

  // Enable receiving messages
  gInbox.init();
  gInbox.actions[0] = new PongAction("LED - RGB");
  gInbox.actions[1] = new Action("color", &changeColor);
  gInbox.actions[2] = new Action("pattern", &changePattern);

  // Leds
  leds.begin();
  timer.setTimeout(ANIM_DELAY);
  timer.restart();

}

void loop() {
  animateLeds();
}



// //Main
// void setup() {
  // // Logging
  // Serial.begin(115200);
  // Log.begin(LOG_LEVEL_NOTICE, &Serial);

  // // Configure ESPNOW
  // gBrick.init();

  // // Enable receiving messages
  // gInbox.init();
  // gInbox.actions[0] = new PongAction("LED");
  // gInbox.actions[1] = new Action("on", &ledOn);
  // gInbox.actions[2] = new Action("off", &ledOff);
// }

// void loop() {
// }
