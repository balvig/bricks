#ifndef BRICKS_INBOX_H
#define BRICKS_INBOX_H

#include <ArduinoLog.h>
#include <WifiEspNow.h>

#include <Bricks.Skill.h>
#include <Bricks.Constants.h>
#include <Bricks.Message.h>
#include <Bricks.Utils.h>

// Stock skills
#include <Bricks.AckSkill.h>
#include <Bricks.BatterySkill.h>
#include <Bricks.ListSkill.h>
#include <Bricks.OtaSkill.h>
#include <Bricks.SleepSkill.h>

# define MAX_SKILLS 10

namespace Bricks {
  class Inbox {
    public:
      Inbox() {}
      void init(const char *name);
      void initBase();
      void loop();
      void process(const uint8_t *macAddr, const Message message);
      String listSkills(); // The (supposedly) EVIL STRING?
      Skill *skills[MAX_SKILLS] = { new Skill(), new Skill(), new Skill(), new Skill(), new Skill(), new Skill(), new Skill(), new Skill(), new Skill(), new Skill() }; // what the
    private:
      static void onDataReceived(const uint8_t macAddr[MAC_ADDR_SIZE], const uint8_t *data, size_t len, void *cbarg);
  };

  extern Inbox gInbox;
}
#endif
