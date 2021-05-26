#include "Bricks.OtaSkill.h"

namespace Bricks {
  OtaSkill::OtaSkill() : Skill("ota") {
  }

  void OtaSkill::callback(BRICKS_CALLBACK_SIGNATURE) {
    initOta();
    startAP();
    strcpy(response, "Connect to 'Brick - OTA'");
  }

  void OtaSkill::loop() {
    ArduinoOTA.handle();
  }

  void OtaSkill::initOta() {
    ArduinoOTA.onStart([]() {
      Log.noticeln("AOTA: Starting OTA");
    });
    ArduinoOTA.onEnd([]() {
      Log.noticeln("AOTA: Done");
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
