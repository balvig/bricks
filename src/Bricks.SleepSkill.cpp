#include <Bricks.SleepSkill.h>

namespace Bricks {
#ifdef ESP32
  RTC_DATA_ATTR int16_t rtcSleepTime = 0;
#endif

  SleepSkill::SleepSkill(const char *name) : Skill("sleep") {
    this->name = name;
    sendAwakeMessage();
    readSleepTime();
  }

  void SleepSkill::callback(BRICKS_CALLBACK_SIGNATURE) {
    this->sleepTime = atoi(message.value);
    writeSleepTime();

    if(validSleepTime()) {
      sprintf(response, "Starting sleep cycles");
    }
    else {
      sprintf(response, "Stopping sleep (Rec: %d, Max: %d)", sleepTime, MAX_SLEEP_TIME);
    }
  }

  void SleepSkill::loop() {
    if(awakeTimeout()) {
      char message[50];
      sprintf(message, "Going to sleep (Time: %d)", sleepTime);
      gOutbox.send("sleeping", message);

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

  bool SleepSkill::awakeTimeout() {
    return validSleepTime() && millis() >= TIMEOUT;
  }

  bool SleepSkill::validSleepTime() {
    return sleepTime >= 0 && sleepTime <= MAX_SLEEP_TIME;
  }

  void SleepSkill::readSleepTime() {
#ifdef ESP8266
    system_rtc_mem_read(RTC_SLEEP_TIME_REGISTER, &sleepTime, sizeof(sleepTime));
#elif ESP32
    sleepTime = Bricks::rtcSleepTime;
#endif
    Log.trace("SLEE: Sleep time read: %d" CR, sleepTime);
  }

  void SleepSkill::writeSleepTime() {
#ifdef ESP8266
    system_rtc_mem_write(RTC_SLEEP_TIME_REGISTER, &sleepTime, sizeof(sleepTime));
#elif ESP32
    Bricks::rtcSleepTime = sleepTime;
#endif
  }
}
