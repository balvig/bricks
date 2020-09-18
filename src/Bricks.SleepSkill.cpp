#include <Bricks.SleepSkill.h>

namespace Bricks {
#ifdef ESP32
  RTC_DATA_ATTR uint32_t rtcSleepTime = 0;
#endif

  SleepSkill::SleepSkill(const char *name) : Skill("setSleep") {
    this->name = name;
    sendAwakeMessage();

    if(Utils::wokeUpFromDeepSleep()) {
      Log.trace("SLEE: Woke up from deep sleep");
      readSleepTime();
    }
  }

  void SleepSkill::loop() {
    if(awakeTimeout()) {
      deepSleep();
    }
  }

  void SleepSkill::callback(BRICKS_CALLBACK_SIGNATURE) {
    this->sleepTime = atoi(message.value);
    writeSleepTime();

    if(sleepTime > 0) {
      sprintf(response, "Starting %d second sleep cycles", sleepTime);
    }
    else {
      strcpy(response, "Stopping sleep cycles");
    }
  }

  void SleepSkill::sendAwakeMessage() {
    char reason[50];
    char message[100];
    Bricks::Utils::getWakeupReason(reason);

    sprintf(message, "%s - %s", name, reason);
    gOutbox.send("awake", message);
  }

  void SleepSkill::deepSleep() {
    Log.notice("SLEE: Going to sleep for %d second(s)" CR, sleepTime);
    Utils::deepSleep(sleepTime);
  }

  bool SleepSkill::awakeTimeout() {
    return sleepTime > 0 && millis() >= TIMEOUT;
  }

  void SleepSkill::readSleepTime() {
#ifdef ESP8266
    system_rtc_mem_read(RTC_SLEEP_TIME_REGISTER, &sleepTime, sizeof(sleepTime));
#elif ESP32
    sleepTime = Bricks::rtcSleepTime;
#endif
  }

  void SleepSkill::writeSleepTime() {
#ifdef ESP8266
    system_rtc_mem_write(RTC_SLEEP_TIME_REGISTER, &sleepTime, sizeof(sleepTime));
#elif ESP32
    Bricks::rtcSleepTime = sleepTime;
#endif
  }
}
