#ifndef M5LOGGER_H
#define M5LOGGER_H

#include <ArduinoLog.h>
#include <M5Stack.h>
#include <ScrollTextWindow.h>

#define TOP_FIXED_HEIGHT        24
#define BOTTOM_FIXED_HEIGHT     16

class M5Logger {
  public:
    static void init(int level = LOG_LEVEL_NOTICE);
		static ScrollTextWindow stw(TOP_FIXED_HEIGHT, BOTTOM_FIXED_HEIGHT);
  private:
    static void scrollScreen(Print* _logOutput);
};
#endif
