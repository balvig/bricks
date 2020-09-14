#ifndef BRICKS_SLEEP_SKILL_H
#define BRICKS_SLEEP_SKILL_H

#include <ArduinoLog.h>
#ifdef ESP32
#include <esp_sleep.h>
#include <driver/adc.h>
#include <esp_bt.h>
#include <esp_bt_main.h>
#include <esp_wifi.h>
#endif

#include <Bricks.Skill.h>
#include <Bricks.Constants.h>
#include <Bricks.Outbox.h>
#include <Bricks.Utils.h>

namespace Bricks {
  class SleepSkill : public Skill {
    public:
      SleepSkill(const char *name = "New Brick");
      void callback(const uint8_t *macAddr, const Message message);
    private:
      void sendAwakeMessage();
      void deepSleep(const uint32_t seconds);
      const char *name;
  };
}
#endif
