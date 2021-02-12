#include <Bricks.SleepSkill.h>

namespace Bricks {
  SleepSkill::SleepSkill(const char *name) : Skill("sleep") {
    this->name = name;
    sendAwakeMessage();
  }

  void SleepSkill::callback(BRICKS_CALLBACK_SIGNATURE) {
    this->sleepTime = atoi(message.value);

    if(validSleepTime()) {
      sprintf(response, "Going to sleep (Time: %d)", sleepTime);
    }
    else {
      sprintf(response, "Invalid sleep time (Rec: %d, Max: %d)", sleepTime, MAX_SLEEP_TIME);
    }
  }

  void SleepSkill::loop() {
    if(validSleepTime()) {
      deepSleep();
    }
  }

  void SleepSkill::sendAwakeMessage() {
    char reason[50];
    char message[100];
    Utils::getWakeupReason(reason);

    sprintf(message, "%s - %s", name, reason);
    gOutbox.send("awake", message);
  }

  void SleepSkill::deepSleep() {
    Utils::deepSleep(sleepTime);
  }

  bool SleepSkill::validSleepTime() {
    return sleepTime >= 0 && sleepTime <= MAX_SLEEP_TIME;
  }
}
