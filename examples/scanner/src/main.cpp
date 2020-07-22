// Bricks
#include <Bricks.Brick.h>
#include <Bricks.Inbox.h>
#include <Bricks.Outbox.h>
#include <Bricks.PongAction.h>
#include <Bricks.StoreGatewayAction.h>
using namespace Bricks;

// Local
#include <NimBLEDevice.h>

// Vars
uint8_t gatewayMac[] = MAC_ALL; // default to broadcasting to all
BLEScan *pBLEScan;
uint8_t scanTime = 5; // seconds
uint8_t waitTime = 1; // seconds
int8_t minRSSI = -40;

// BLE Methods
class BLECallbacks: public BLEAdvertisedDeviceCallbacks {
  void onResult(BLEAdvertisedDevice* device) {
    Log.trace("BLES: Device found [%s]" CR, device->toString().c_str());
    const int8_t RSSI = device->getRSSI();

    if(RSSI >= minRSSI) {
      char value[100];
      sprintf(value, "%s,%d", device->getAddress().toString().c_str(), RSSI);
      gOutbox.send(gatewayMac, "found", value);
    }
    else {
      Log.trace("BLES: Device under minRSSI threshold [%d]" CR, minRSSI);
    }
  }
};

void scan() {
  Log.notice("BLES: Scanning for %d second(s)" CR, scanTime);
  pBLEScan->start(scanTime, false);
  pBLEScan->clearResults();
  Log.notice("BLES: Scan done" CR);
}

// Brick callbacks
void setScan(const uint8_t *macAddr, const Message message) {
  scanTime = atoi(message.value);
}

void setWait(const uint8_t *macAddr, const Message message) {
  waitTime = atoi(message.value);
}

void setMinRSSI(const uint8_t *macAddr, const Message message) {
  minRSSI = atoi(message.value);
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
  // pBLEScan->setActiveScan(true); // required to get names..but does it drain battery of scanned devices?

  // Configure ESPNOW
  gBrick.init();

  // Enable receiving messages
  gInbox.init();
  gInbox.actions[0] = new PongAction("BLE Scanner");
  gInbox.actions[1] = new StoreGatewayAction(gatewayMac);
  gInbox.actions[2] = new Action("setScan", &setScan);
  gInbox.actions[3] = new Action("setWait", &setWait);
  gInbox.actions[4] = new Action("setMinRSSI", &setMinRSSI);
}

void loop() {
  scan();
  Log.notice("BRIC: Waiting for %d second(s)" CR, waitTime);
  delay(waitTime * 1000);
}
