// Callbacks
class BLECallbacks: public BLEAdvertisedDeviceCallbacks {
  void onResult(BLEAdvertisedDevice* device) {
    if(device->haveName()) {
      device->getAddress().toString().c_str();
      device->getName();
      device->getRSSI();
    }
  }
};

BLEScan *pBLEscan;

//Main
void setup() {
  BLEDevice::init("");
  pBLEScan = BLEDevice::getScan();
  pBLEScan->setAdvertisedDeviceCallbacks(callbacks);
  pBLEScan->setActiveScan(true); // does this drain battery of scanned devices? but only way to get name?
}

void loop() {
  pBLEScan->start(SCAN_TIME, false);
  pBLEScan->clearResults();
  delay(WAIT_TIME * 1000);
}
