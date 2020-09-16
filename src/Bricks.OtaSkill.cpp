#include "Bricks.OtaSkill.h"

namespace Bricks {
  OtaSkill::OtaSkill() : Skill("ota") {
  }

  void OtaSkill::loop() {
    ArduinoOTA.handle();
  }

  void OtaSkill::callback(const uint8_t *macAddr, const Message message) {
    initOta();
    startAP();
    ack("Connect to Brick - OTA");
  }

  void OtaSkill::initOta() {
    ArduinoOTA.onStart([]() {
      Log.notice("AOTA: Starting OTA" CR);
    });
    ArduinoOTA.onEnd([]() {
      Log.notice("AOTA: Done" CR);
    });
    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
      Log.trace("Progress: %u%%\r", (progress / (total / 100)));
    });
    ArduinoOTA.onError([](ota_error_t error) {
      if (error == OTA_AUTH_ERROR) {
        Log.error("AOTA: Auth Failed");
      }
      else if (error == OTA_BEGIN_ERROR) {
        Log.error("AOTA: Begin Failed");
      }
      else if (error == OTA_CONNECT_ERROR) {
        Log.error("AOTA: Connect Failed");
      }
      else if (error == OTA_RECEIVE_ERROR) {
        Log.error("AOTA: Receive Failed");
      }
      else if (error == OTA_END_ERROR) {
        Log.error("AOTA: End Failed");
      }
    });
    ArduinoOTA.begin();
  }

  void OtaSkill::startAP() {
    WiFi.mode(WIFI_AP);
    WiFi.softAP("Brick - OTA", NULL, BRICKS_WIFI_CHANNEL, false, 1);
  }
}
