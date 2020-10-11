#ifndef LUMI_ANIMATOR_H
#define LUMI_ANIMATOR_H

#include <FastLED.h>
#include <Lumi.Sequencer.h>
#include <Lumi.Off.h>
#include <Lumi.On.h>
#include <Lumi.Glow.h>
#include <Lumi.Spin.h>
#include <Lumi.Wave.h>

#define NUM_LEDS 7
#define LUMI_ANIMATOR_PIN D2

namespace Lumi {
  class Animator : public Sequencer {
    public:
      Animator();
    protected:
      Pattern *patterns[5];
    private:
      void update();
      CRGB leds[NUM_LEDS];
  };
}
#endif
