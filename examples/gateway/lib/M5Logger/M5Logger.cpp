#include <M5Logger.h>

void M5Logger::init(int level) {
  M5.begin();
  // M5.Lcd.setTextWrap(true, true);

  M5.begin();
  M5.Lcd.fillScreen(TFT_BLACK);

  //固定エリアの描画
  M5.Lcd.setTextDatum(MC_DATUM);
  M5.Lcd.setTextColor(TFT_WHITE, TFT_BLUE);

  //上部固定エリア
  M5.Lcd.fillRect(0, 0, SCREEN_WIDTH, TOP_FIXED_HEIGHT, TFT_BLUE);
  M5.Lcd.drawString("TOP FIXED AREA", SCREEN_WIDTH/2, TOP_FIXED_HEIGHT/2);

  //下部固定エリア
  M5.Lcd.fillRect(0, SCREEN_HEIGHT-BOTTOM_FIXED_HEIGHT, SCREEN_WIDTH, BOTTOM_FIXED_HEIGHT, TFT_BLUE);
  M5.Lcd.drawString("BOTTOM FIXED AREA", SCREEN_WIDTH/2, SCREEN_HEIGHT - BOTTOM_FIXED_HEIGHT/2);

  M5.Lcd.setTextDatum(TL_DATUM);
  M5.Lcd.setTextColor(TFT_WHITE, TFT_BLACK);

  //スクロールクラスの初期化

  // Log.begin(level, &M5.Lcd, false);
  Log.begin(level, &stw, false);
  // Log.setPrefix(M5Logger::scrollScreen);
}

void M5Logger::scrollScreen(Print* _logOutput) {
  if(M5.Lcd.getCursorY() >= M5.Lcd.height()) {
    M5.Lcd.setCursor(0,0);
    M5.Lcd.clear();
  }
}
