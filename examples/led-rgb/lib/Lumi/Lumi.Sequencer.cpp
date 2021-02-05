#include <Lumi.Sequencer.h>

namespace Lumi {
  Sequencer::Sequencer() {}

  void Sequencer::loop() {
    if(playing && timer.onRestart()) {
      if(progress > PROGRESS_MAX) {
        rewind();
      }
      update();
      progress++;
    }
  }

  void Sequencer::set(const char *input) {
    unsigned int pattern = 0;
    char value[15] = "";
    unsigned int delay = 0;

    sscanf(input, "%u %s %u", &pattern, value, &delay);

    setPattern(pattern);
    setValue(value);
    setDelay(delay);
  }

  void Sequencer::setPattern(uint8_t pattern) {
    currentPattern = pattern;
  }

  void Sequencer::setDelay(uint8_t delay) {
    if(delay > 0) {
      rewind();
      playing = true;
      timer.setTimeout(delay);
    }
    else {
      fastforward();
      playing = false;
      update();
    }
  }

  void Sequencer::setValue(const char *value) {
    patterns[currentPattern]->setValue(value);
  }

  void Sequencer::update() {
    patterns[currentPattern]->update(progress);
  }

  void Sequencer::rewind() {
    progress = 0;
  }

  void Sequencer::fastforward() {
    progress = PROGRESS_MAX;
  }
}
