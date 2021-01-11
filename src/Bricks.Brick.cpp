#include "Bricks.Brick.h"

namespace Bricks {
  void Brick::init(const char *name) {
    initBase();
    skills[5] = new VersionSkill();
    skills[6] = new OtaSkill();
    skills[7] = new ListSkill();
    skills[8] = new BatterySkill();
    skills[9] = new SleepSkill(name);
  }

  void Brick::initBase(const WiFiMode_t wifiMode) {
    // Configure Wi-Fi
    WiFi.mode(wifiMode);
    WiFi.softAP("ESPNOW", NULL, BRICKS_WIFI_CHANNEL, true, 0); // hide AP

    // Connect ESPNOW
    if (WifiEspNow.begin()) {
      WifiEspNow.onReceive(Brick::onDataReceived, nullptr);
      logMac(wifiMode);
    }
    else {
      Log.error("ESPN: Error initializing" CR);
    }
  }

  void Brick::onDataReceived(const uint8_t macAddr[MAC_ADDR_SIZE], const uint8_t *data, size_t len, void *cbarg) {
    Message message;
    memcpy(&message, data, sizeof(message));

    char macStr[MAC_STR_SIZE];
    Bricks::Utils::macToStr(macAddr, macStr);
    Log.notice("ESPN: <- %s [%s] [%s]" CR, macStr, message.key, message.value);

    gBrick.process(macAddr, message);
  }

  void Brick::loop() {
    for(int i = MAX_SKILLS - 1; i >= 0; i--) {
      skills[i]->loop();
    }
  }

  void Brick::process(BRICKS_PROCESS_SIGNATURE) {
    for(int i = MAX_SKILLS - 1; i >= 0; i--) {
      if(skills[i]->respondsTo(message.key)) {
        Log.trace("BRIC: Skill found [%s]" CR, message.key);
        skills[i]->process(macAddr, message);
      }
    }
  }

  String Brick::listSkills() {
    String skillList = "";

    for(int i = 0; i < MAX_SKILLS; i++) {
      if(strcmp(skills[i]->key, "") != 0) {
        skillList += skills[i]->key;
        skillList += " ";
      }
    }

    skillList.trim();

    return skillList;
  }

  void Brick::logMac(WiFiMode_t wifiMode) {
    String macStr;

    if(wifiMode == WIFI_STA) {
      macStr = WiFi.macAddress();
    }
    else {
      macStr = WiFi.softAPmacAddress();
    }

    macStr.toLowerCase();
    Log.notice("ESPN: Initialized [%s]" CR, macStr.c_str());
  }

  Brick gBrick = Brick();
}
