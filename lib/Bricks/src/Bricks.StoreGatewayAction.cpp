#include <Bricks.StoreGatewayAction.h>

namespace Bricks {
  StoreGatewayAction::StoreGatewayAction(uint8_t *gatewayMac) : Action("ping") {
    this->gatewayMac = gatewayMac;
    readMac();
  }

  void StoreGatewayAction::callback(const uint8_t *macAddr, const Message message) {
    Log.notice("EEPR: Storing gateway MAC" CR);
    for (int i = 0; i < MAC_ADDR_SIZE; ++i) {
      gatewayMac[i] = macAddr[i];
      EEPROM.write(i, macAddr[i]);
    }
    EEPROM.commit();
  }

  void StoreGatewayAction::readMac() {
    Log.notice("EEPR: Reading gateway MAC" CR);
    EEPROM.begin(MAC_ADDR_SIZE);
    for (int i = 0; i < MAC_ADDR_SIZE; ++i) {
      gatewayMac[i] = EEPROM.read(i);
    }

    char macStr[MAC_STR_SIZE];
    Bricks::Utils::macToStr(gatewayMac, macStr);
    Log.notice("EEPR: Loaded gateway MAC [%s]" CR, macStr);
  }
}
