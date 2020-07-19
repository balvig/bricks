// Configuration
#include <secrets.h>

// Bricks
#include <Bricks.Brick.h>
#include <Bricks.Events.h>
#include <Bricks.Inbox.h>
#include <Bricks.Outbox.h>
#include <Bricks.PublishAction.h>
using namespace Bricks;

// Main
void setup() {
  // Logging
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);

  // Configure ESPNOW
  gBrick.init(WIFI_AP_STA);

  // Connect mqtt event stream
  gEvents.init(BRICKS_WIFI_SSID, BRICKS_WIFI_PASSWORD, BRICKS_MQTT_HOST, BRICKS_MQTT_CLIENT, BRICKS_MQTT_USER, BRICKS_MQTT_PASSWORD);

  // Enable receiving messages
  gInbox.init();

  // Publish all received messages to mqtt
  gInbox.actions[0] = new PublishAction();
}

void loop() {
  gEvents.loop();
}
