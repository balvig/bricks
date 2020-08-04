// Bricks
#include <Bricks.Brick.h>
#include <Bricks.Inbox.h>
#include <Bricks.Outbox.h>
#include <Bricks.AckAction.h>
#include <Bricks.OtaAction.h>
#include <Bricks.PongAction.h>
#include <Bricks.SleepAction.h>
#include <Bricks.StoreGatewayAction.h>
using namespace Bricks;

// Local
#include <NimBLEDevice.h>

BLEScan *pBLEScan;
const int8_t MINIMUM_RSSI = -70;

class BLECallbacks: public BLEAdvertisedDeviceCallbacks {
  void onResult(BLEAdvertisedDevice* device) {
    if(device->getRSSI() > MINIMUM_RSSI) {
      char value[100];
      sprintf(value, "%s,%s,%d", device->getName().c_str(), device->getAddress().toString().c_str(), device->getRSSI());
      gOutbox.send("found", value);
    }
  }
};

void scan(const uint8_t *macAddr, const Message message) {
  const uint8_t scanTime = atoi(message.value);
  Log.notice("BLES: Scanning for %d second(s)" CR, scanTime);
  pBLEScan->start(scanTime, false);
  pBLEScan->clearResults();
  Log.notice("BLES: Scan done" CR);
}

//Main
void setup() {
  // Logging
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);

  // Configure BLE
  BLEDevice::init("");
  pBLEScan = BLEDevice::getScan();
  pBLEScan->setAdvertisedDeviceCallbacks(new BLECallbacks());
  // pBLEScan->setActiveScan(true); // required to get names?

  // Configure ESPNOW
  gBrick.init();

  // Enable receiving messages
  gInbox.init();
  gInbox.actions[0] = new AckAction();
  gInbox.actions[1] = new PongAction("BLE Scanner");
  gInbox.actions[2] = new OtaAction();
  gInbox.actions[3] = new StoreGatewayAction();
  gInbox.actions[4] = new SleepAction();
  gInbox.actions[5] = new Action("scan", &scan);
}

void loop() {
  ArduinoOTA.handle();
}
