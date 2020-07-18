// https://www.tweaking4all.com/hardware/arduino/arduino-all-ledstrip-effects-in-one/
#include <LedAnimator.h>

LedAnimator::LedAnimator() {
  FastLED.addLeds<WS2811, PIN, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
}

void LedAnimator::loop() {
  switch(currentPattern) {
    case 0  : {
                allBlack();
                break;
              }
    case 1  : {
                RGBLoop();
                break;
              }
  }
}

// Apply LED color changes
void LedAnimator::showStrip() {
  FastLED.show();
}

// Set a LED color (not yet visible)
void LedAnimator::setPixel(int Pixel, byte red, byte green, byte blue) {
  leds[Pixel].r = red;
  leds[Pixel].g = green;
  leds[Pixel].b = blue;
}

// Set all LEDs to a given color and apply it (visible)
void LedAnimator::setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < NUM_LEDS; i++ ) {
    setPixel(i, red, green, blue);
  }
  showStrip();
}

// Animations
void LedAnimator::allBlack() {
  setAll(0,0,0);
}

void LedAnimator::RGBLoop() {
  // Fade IN
  for(int k = 0; k < 256; k++) {
    switch(currentColor) {
      case 0: setAll(k,0,0); break;
      case 1: setAll(0,k,0); break;
      case 2: setAll(0,0,k); break;
    }
    showStrip();
    delay(3);
  }
  // Fade OUT
  for(int k = 255; k >= 0; k--) {
    switch(currentColor) {
      case 0: setAll(k,0,0); break;
      case 1: setAll(0,k,0); break;
      case 2: setAll(0,0,k); break;
    }
    showStrip();
    delay(3);
  }
}
