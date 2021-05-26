// Bricks
#include <Bricks.Brick.h>
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
  Log.noticeln("BLES: Scanning for %d second(s)", scanTime);
  pBLEScan->setActiveScan(activeScan);
  pBLEScan->start(scanTime, false);
  pBLEScan->clearResults();
  Log.noticeln("BLES: Scan done");
}

void passiveScan(BRICKS_CALLBACK_SIGNATURE) {
  const uint8_t scanTime = atoi(message.value);
  scan(scanTime, false);
}

// active scan required to get names?
void activeScan(BRICKS_CALLBACK_SIGNATURE) {
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

  // Configure Brick
  gBrick.init("BLE Scanner");
  gBrick.skills[0] = new Skill("scan", &passiveScan);
  gBrick.skills[1] = new Skill("activeScan", &activeScan);
}

void loop() {
  gBrick.loop();
}
