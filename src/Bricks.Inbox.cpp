#include "Bricks.Inbox.h"

namespace Bricks {
  void Inbox::init(const char *name) {
    skills[6] = new OtaSkill();
    skills[7] = new ListSkill();
    skills[8] = new BatterySkill();
    skills[9] = new SleepSkill(name);
    initBase();
  }

  void Inbox::initBase() {
    WifiEspNow.onReceive(Inbox::onDataReceived, nullptr);
  }

  void Inbox::onDataReceived(const uint8_t macAddr[MAC_ADDR_SIZE], const uint8_t *data, size_t len, void *cbarg) {
    Message message;
    memcpy(&message, data, sizeof(message));

    char macStr[MAC_STR_SIZE];
    Bricks::Utils::macToStr(macAddr, macStr);
    Log.notice("ESPN: <- %s [%s] [%s]" CR, macStr, message.key, message.value);

    gInbox.process(macAddr, message);
  }

  void Inbox::loop() {
    for(int i = MAX_SKILLS - 1; i >= 0; i--) {
      skills[i]->loop();
    }
  }

  void Inbox::process(const uint8_t *macAddr, const Message message) {
    for(int i = MAX_SKILLS - 1; i >= 0; i--) {
      if(skills[i]->respondsTo(message.key)) {
        Log.trace("BRIC: Skill found [%s]" CR, message.key);
        skills[i]->callback(macAddr, message);
      }
    }
  }

  String Inbox::listSkills() {
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

  Inbox gInbox = Inbox();
}
