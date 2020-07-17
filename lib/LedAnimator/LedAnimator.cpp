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
    case 2  : {
                rainbowCycle(20);
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

void LedAnimator::rainbowCycle(int SpeedDelay) {
  byte *c;
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< NUM_LEDS; i++) {
      c=Wheel(((i * 256 / NUM_LEDS) + j) & 255);
      setPixel(i, *c, *(c+1), *(c+2));
    }
    showStrip();
    delay(SpeedDelay);
  }
}

byte * LedAnimator::Wheel(byte WheelPos) {
  static byte c[3];

  if(WheelPos < 85) {
    c[0]=WheelPos * 3;
    c[1]=255 - WheelPos * 3;
    c[2]=0;
  } else if(WheelPos < 170) {
    WheelPos -= 85;
    c[0]=255 - WheelPos * 3;
    c[1]=0;
    c[2]=WheelPos * 3;
  } else {
    WheelPos -= 170;
    c[0]=0;
    c[1]=WheelPos * 3;
    c[2]=255 - WheelPos * 3;
  }

  return c;
}

// void Twinkle(byte red, byte green, byte blue, int Count, int SpeedDelay, boolean OnlyOne) {
  // setAll(0,0,0);

  // for (int i=0; i<Count; i++) {
    // setPixel(random(NUM_LEDS),red,green,blue);
    // showStrip();
    // delay(SpeedDelay);
    // if(OnlyOne) {
      // setAll(0,0,0);
    // }
  // }

  // delay(SpeedDelay);
// }

// void TwinkleRandom(int Count, int SpeedDelay, boolean OnlyOne) {
  // setAll(0,0,0);

  // for (int i=0; i<Count; i++) {
    // setPixel(random(NUM_LEDS),random(0,255),random(0,255),random(0,255));
    // showStrip();
    // delay(SpeedDelay);
    // if(OnlyOne) {
      // setAll(0,0,0);
    // }
  // }

  // delay(SpeedDelay);
// }

// void RunningLights(byte red, byte green, byte blue, int WaveDelay) {
  // int Position=0;

  // for(int i=0; i<NUM_LEDS*2; i++)
  // {
    // Position++; // = 0; //Position + Rate;
    // for(int i=0; i<NUM_LEDS; i++) {
      // setPixel(i,((sin(i+Position) * 127 + 128)/255)*red,
          // ((sin(i+Position) * 127 + 128)/255)*green,
          // ((sin(i+Position) * 127 + 128)/255)*blue);
    // }

    // showStrip();
    // delay(WaveDelay);
  // }
// }

// void colorWipe(byte red, byte green, byte blue, int SpeedDelay) {
  // for(uint16_t i=0; i<NUM_LEDS; i++) {
    // setPixel(i, red, green, blue);
    // showStrip();
    // delay(SpeedDelay);
  // }
// }



// // *** REPLACE FROM HERE ***
// void loop() {
  // switch(currentPattern) {

    // case 1  : {
                // // TwinkleRandom - twinkle count, speed delay, only one (true/false)
                // TwinkleRandom(20, 100, false);
                // break;
              // }

    // case 2  : {
                // // Running Lights - Color (red, green, blue), wave dealy
                // RunningLights(0xff,0x00,0x00, 50);  // red
                // RunningLights(0xff,0xff,0xff, 50);  // white
                // RunningLights(0x00,0x00,0xff, 50);  // blue
                // break;
              // }

    // case 3  : {
                // // colorWipe - Color (red, green, blue), speed delay
                // colorWipe(0x00,0xff,0x00, 100);
                // colorWipe(0x00,0x00,0x00, 100);
                // break;
              // }

    // case 4  : {
                // // rainbowCycle - speed delay
                // rainbowCycle(20);
                // break;
              // }
  // }
// }
