// Bricks
#include <Bricks.Brick.h>
#include <Bricks.Outbox.h>
using namespace Bricks;

// Local
#include <FastLED.h>
#include <Lumi.Sequencer.h>
#include <Led.Off.h>
#include <Led.Glow.h>
#include <Led.Spin.h>
#include <Led.Wave.h>

#define NUM_LEDS 7
#define LEDS_PIN D2

Lumi::Sequencer sequencer;
CRGB leds[NUM_LEDS];

// Bricks callbacks
void set(BRICKS_CALLBACK_SIGNATURE) {
  sequencer.set(message.value);
}

void setup() {
  // Logging
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);

  // Configure Brick
  gBrick.init("LED RGB");
  gBrick.skills[0] = new Skill("set", &set);

  // Configure LEDs
  FastLED.addLeds<WS2811, LEDS_PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

  // Configure animations
  sequencer.patterns[0] = new Led::Off(leds, NUM_LEDS);
  sequencer.patterns[1] = new Led::Glow(leds, NUM_LEDS);
  sequencer.patterns[2] = new Led::Spin(leds, NUM_LEDS);
  sequencer.patterns[3] = new Led::Wave(leds, NUM_LEDS);
}

void loop() {
  gBrick.loop();
  sequencer.loop();
}
