#include <Bricks.StoreGatewayAction.h>

namespace Bricks {
  StoreGatewayAction::StoreGatewayAction() : Action(BRICKS_PING_ACTION) {
    EEPROM.begin(MAC_ADDR_SIZE);
    readMac();
  }

  void StoreGatewayAction::callback(const uint8_t *macAddr, const Message message) {
    writeMac(macAddr);
  }

  void StoreGatewayAction::writeMac(const uint8_t *macAddr) {
    Log.notice("EEPR: Storing gateway MAC" CR);

    for (int i = 0; i < MAC_ADDR_SIZE; ++i) {
      EEPROM.write(i, macAddr[i]);
    }
    EEPROM.commit();

    gOutbox.setGatewayMac(macAddr);
  }

  void StoreGatewayAction::readMac() {
    Log.notice("EEPR: Reading gateway MAC" CR);

    uint8_t macAddr[MAC_ADDR_SIZE];

    for (int i = 0; i < MAC_ADDR_SIZE; ++i) {
      macAddr[i] = EEPROM.read(i);
    }

    gOutbox.setGatewayMac(macAddr);
  }
}
