// Bricks
#include <Bricks.Brick.h>
#include <Bricks.Events.h>
#include <Bricks.Inbox.h>
#include <Bricks.Outbox.h>
#include <Bricks.PublishAction.h>
using namespace Bricks;

#ifdef ARDUINO_M5Stack_Core_ESP32
#include <M5Stack.h>
#include <ScrollTextWindow.h>
#define TOP_FIXED_HEIGHT 24
#define BOTTOM_FIXED_HEIGHT 16

ScrollTextWindow stw(TOP_FIXED_HEIGHT, BOTTOM_FIXED_HEIGHT);
// #include <M5Logger.h>
#endif

// Main
void setup() {
  // Logging
#ifdef ARDUINO_M5Stack_Core_ESP32
  // M5Logger::init(LOG_LEVEL_NOTICE); // unstable with high activity
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
  Log.begin(LOG_LEVEL_NOTICE, &stw);
#else
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);
#endif

  // Configure ESPNOW
  gBrick.init(WIFI_AP_STA);

  // Connect mqtt event stream
  gEvents.init();

  // Enable receiving messages
  gInbox.init();
  gInbox.actions[0] = new PublishAction(); // Publish all received messages to mqtt
}

void loop() {
  gEvents.loop();
}
