#ifndef M5LOGGER_H
#define M5LOGGER_H

#include <ArduinoLog.h>
#include <M5Stack.h>

class M5Logger {
  public:
    static void init();
  private:
    static void scrollScreen(Print* _logOutput);
};
#endif
