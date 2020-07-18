// Local
#include <NimBLEDevice.h>

// Bricks
#include <Bricks.Brick.h>
// #include <Bricks.Inbox.h>
// #include <Bricks.PongAction.h>

using namespace Bricks;
const uint8_t SCAN_TIME = 5; // In seconds
const uint8_t WAIT_TIME = 1; // In seconds
BLEScan *pBLEScan;

// Callbacks
class BLECallbacks: public BLEAdvertisedDeviceCallbacks {
  void onResult(BLEAdvertisedDevice* device) {
    if(device->haveName()) {
      Serial.printf("Advertised Device: %s \n", device->toString().c_str());
      // device->getAddress().toString().c_str();
      // device->getName();
      // device->getRSSI();
    }
  }
};


//Main
void setup() {
  Serial.begin(115200);
  Serial.println("Scanning...");
  BLEDevice::init("");
  pBLEScan = BLEDevice::getScan();
  pBLEScan->setAdvertisedDeviceCallbacks(new BLECallbacks());
  pBLEScan->setActiveScan(true); // does this drain battery of scanned devices? but only way to get name?
}

void loop() {
  pBLEScan->start(SCAN_TIME, false);
  pBLEScan->clearResults();
  delay(WAIT_TIME * 1000);
}
