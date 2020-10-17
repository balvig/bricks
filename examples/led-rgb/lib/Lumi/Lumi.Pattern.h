#ifndef LUMI_PATTERN_H
#define LUMI_PATTERN_H

#include <Arduino.h>

namespace Lumi {
  class Pattern {
    public:
      virtual void update(const uint8_t progress) {};
      void setValue(const char *value) {
        strcpy(currentValue, value);
        currentIntValue = atoi(value);
      }
    protected:
      char currentValue[3];
      uint8_t currentIntValue;
  };
}
#endif
