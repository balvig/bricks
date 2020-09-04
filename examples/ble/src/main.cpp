// Bricks
#include <Bricks.Brick.h>
#include <Bricks.Inbox.h>
#include <Bricks.Outbox.h>
using namespace Bricks;

// Local
#include <NimBLEDevice.h>

BLEScan *pBLEScan;
const int8_t MINIMUM_RSSI = -80;

class BLECallbacks: public BLEAdvertisedDeviceCallbacks {
  void onResult(BLEAdvertisedDevice* device) {
    if(device->getRSSI() > MINIMUM_RSSI) {
      char value[100];
      sprintf(value, "%s,%s,%d", device->getName().c_str(), device->getAddress().toString().c_str(), device->getRSSI());
      gOutbox.send("found", value);
    }
  }
};

void scan(const uint8_t scanTime, const bool activeScan = false) {
  Log.notice("BLES: Scanning for %d second(s)" CR, scanTime);
  pBLEScan->setActiveScan(activeScan);
  pBLEScan->start(scanTime, false);
  pBLEScan->clearResults();
  Log.notice("BLES: Scan done" CR);
}

void passiveScan(const uint8_t *macAddr, const Message message) {
  const uint8_t scanTime = atoi(message.value);
  scan(scanTime, false);
}

// active scan required to get names?
void activeScan(const uint8_t *macAddr, const Message message) {
  const uint8_t scanTime = atoi(message.value);
  scan(scanTime, true);
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

  // Configure ESPNOW
  gBrick.init();

  // Enable receiving messages
  gInbox.init("BLE Scanner");
  gInbox.actions[0] = new Action("scan", &passiveScan);
  gInbox.actions[1] = new Action("activeScan", &activeScan);
}

void loop() {
  gInbox.loop();
}
