#include <Bricks.ScanAction.h>

namespace Bricks {
  ScanAction::ScanAction() : Action("scan") {
  }

  void ScanAction::callback(const uint8_t *macAddr, const Message message) {
    Log.notice("BRIC: Scanning for Bricks" CR);
    const uint8_t scanResults = WiFi.scanNetworks();

    for(int i = 0; i < scanResults; ++i) {
      if(WiFi.SSID(i).indexOf(BRICKS_NAME_PREFIX) == 0) {
        Log.trace("BRIC: Brick found on channel %d" CR, WiFi.channel(i));
        gOutbox.send(WiFi.BSSID(i), BRICKS_PING_ACTION);
      }
    }

    WiFi.scanDelete();
    Log.notice("BRIC: Scan complete" CR);
  }
}
