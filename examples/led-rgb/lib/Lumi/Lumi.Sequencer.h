#ifndef LUMI_SEQUENCER_H
#define LUMI_SEQUENCER_H

#include <ArduinoLog.h>
#include <RBD_Timer.h>
#include <Lumi.Pattern.h>

#define MAX_PATTERNS 10

namespace Lumi {
  class Sequencer {
    public:
      Sequencer();
      void loop();
      void set(const char *input);
      Pattern *patterns[MAX_PATTERNS];
    private:
      void setPattern(uint8_t pattern);
      void setDelay(uint8_t delay);
      void setValue(const char *value);
      void update();
      void rewind();
      RBD::Timer timer;
      uint8_t currentPattern = 0;
      uint8_t progress = 0;
      bool playing = false;
  };
}
#endif
