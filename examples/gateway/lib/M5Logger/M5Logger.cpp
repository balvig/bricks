#include <M5Logger.h>

void M5Logger::init() {
  M5.begin();
  M5.Lcd.setTextWrap(true, true);
  Log.begin(LOG_LEVEL_NOTICE, &M5.Lcd, false);
  Log.setPrefix(M5Logger::scrollScreen);
}

void M5Logger::scrollScreen(Print* _logOutput) {
  if(M5.Lcd.getCursorY() >= M5.Lcd.height()) {
    M5.Lcd.setCursor(0,0);
    M5.Lcd.clear();
  }
}
