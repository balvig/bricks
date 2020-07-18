// Configuration
#include <secrets.h>

// Local
#include <M5Stack.h>

// Bricks
#include <Bricks.Brick.h>
#include <Bricks.Events.h>
#include <Bricks.Inbox.h>
#include <Bricks.Outbox.h>
#include <Bricks.PublishAction.h>
using namespace Bricks;

void scrollScreen(Print* _logOutput) {
  if(M5.Lcd.getCursorY() >= M5.Lcd.height()) {
    M5.Lcd.setCursor(0,0);
    M5.Lcd.clear();
  }
}

// Main
void setup() {
  // Set up M5
  M5.begin();
  M5.Lcd.setTextWrap(true, true);
  Log.begin(LOG_LEVEL_NOTICE, &M5.Lcd, false);
  Log.setPrefix(scrollScreen);
  Log.notice("M5ST: Gateway online");
  Log.setLevel(LOG_LEVEL_WARNING);

  // Bricks
  gBrick.init(WIFI_AP_STA);
  gEvents.init(BRICKS_WIFI_SSID, BRICKS_WIFI_PASSWORD, BRICKS_MQTT_HOST, BRICKS_MQTT_CLIENT, BRICKS_MQTT_USER, BRICKS_MQTT_PASSWORD);
  gInbox.init();
  gInbox.actions[0] = new PublishAction();
}

void loop() {
  gEvents.loop();
}
