#ifndef LED_ANIMATOR_H
#define LED_ANIMATOR_H

#include <FastLED.h>
#define NUM_LEDS 7
#define PIN D4

class LedAnimator {

  public:
    LedAnimator();
    void loop();
    uint8_t currentPattern = 0;
    uint8_t currentColor = 0; // 0 red, 1 green, 2 blue
  private:
    CRGB leds[NUM_LEDS];
    void showStrip();
    void setPixel(int Pixel, byte red, byte green, byte blue);
    void setAll(byte red, byte green, byte blue);

    // Animations
    void allBlack();
    void RGBLoop();
    void rainbowCycle(int SpeedDelay);
    byte * Wheel(byte WheelPos);
};
#endif
