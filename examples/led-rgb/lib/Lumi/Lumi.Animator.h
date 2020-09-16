#ifndef LUMI_ANIMATOR_H
#define LUMI_ANIMATOR_H

#include <FastLED.h>
#include <Lumi.Off.h>
#include <Lumi.On.h>
#include <Lumi.Glow.h>
#include <Lumi.Spin.h>
#include <Lumi.Wave.h>

#define NUM_LEDS 7
#define LUMI_ANIMATOR_PIN D2

namespace Lumi {
  class Animator {
    public:
      Animator();
      void update();
      uint8_t currentPattern = 0;
      uint8_t currentVariation = 0;
      uint8_t currentDelay = 10;
    private:
      uint8_t progress = 0;
      Pattern *patterns[5];
      CRGB leds[NUM_LEDS];
  };
}
#endif
