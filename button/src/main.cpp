// Local
#include <EEPROM.h>
#include <RBD_Timer.h>
#include <RBD_Button.h>

// Bricks
#include <Bricks.Brick.h>
#include <Bricks.Constants.h>
#include <Bricks.Inbox.h>
#include <Bricks.Outbox.h>
#include <Bricks.PongAction.h>
#include <Bricks.Utils.h>
using namespace Bricks;

#ifdef ESP8266
RBD::Button button(0);
#elif ESP32
RBD::Button button(GPIO_NUM_17);
#endif

uint8_t gatewayMac[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

void readGatewayMac() {
  // Load from flash memory
  EEPROM.begin(MAC_ADDR_SIZE);
  Log.notice("Reading gateway MAC");
  for (int i = 0; i < MAC_ADDR_SIZE; ++i) {
    gatewayMac[i] = EEPROM.read(i);
  }

  char macStr[MAC_STR_SIZE];
  Bricks::Utils::macToStr(gatewayMac, macStr);
  Log.notice("Gateway MAC: %s", macStr);
}

void storeGatewayMac(const uint8_t *macAddr, const Message message) {
  Log.notice("Storing gateway MAC");
  for (int i = 0; i < MAC_ADDR_SIZE; ++i) {
    gatewayMac[i] = macAddr[i];
    EEPROM.write(i, macAddr[i]);
  }
  EEPROM.commit();
}

bool gatewayKnown() {
  // Figure out a way to know this
  return true; //gatewayMac != defaultGatewayMac;
}

//Main
void setup() {
  // Logger and ESPNOW
  gBrick.init();

  // Load existing gatewayMac if any
  readGatewayMac();

  // Enable receiving messages
  gInbox.init();
  gInbox.actions[0] = new Action("ping", &storeGatewayMac);
  gInbox.actions[1] = new PongAction("button");
}

void loop() {
  if(button.onPressed()) {
    gOutbox.send(gatewayMac, "pressed");
  }

  if(button.onReleased()) {
    gOutbox.send(gatewayMac, "released");
  }
}
