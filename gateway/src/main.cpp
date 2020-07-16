// Configuration
#include <secrets.h>

// M5Stack
// #include <M5Stack.h>

// Local
#include <ArduinoLog.h>

// Bricks
#include <Bricks.Brick.h>
#include <Bricks.Events.h>
#include <Bricks.Inbox.h>
#include <Bricks.Outbox.h>
#include <Bricks.PublishAction.h>
using namespace Bricks;


// void scrollScreen(Print* _logOutput) {
  // if(M5.Lcd.getCursorY() >= M5.Lcd.height()) {
    // M5.Lcd.setCursor(0,0);
    // M5.Lcd.clear();
  // }
// }

// Main
void setup() {
  // M5
  // M5.begin();
  // M5.Lcd.setTextWrap(true, true);
  // M5.Lcd.setTextSize(1);

  // Logger and ESPNOW
  gBrick.init();
  // gBrick.init(&M5.Lcd);
  // Log.setPrefix(scrollScreen);

  // Connect mqtt event stream
  gEvents.init(BRICKS_WIFI_SSID, BRICKS_WIFI_PASSWORD, BRICKS_MQTT_HOST, BRICKS_MQTT_CLIENT, BRICKS_MQTT_USER, BRICKS_MQTT_PASSWORD, BRICKS_MQTT_TOPIC_PREFIX);

  // Enable receiving messages
  gInbox.init();
  gInbox.actions[0] = new PublishAction();

  // Announce self
  // uint8_t macAddr[Bricks::Utils::MAC_ADDR_SIZE];
  // WiFi.softAPmacAddress(macAddr);
  // gEvents.publish(macAddr, "gateway", "online");
}

void loop() {
  gEvents.loop();
}
