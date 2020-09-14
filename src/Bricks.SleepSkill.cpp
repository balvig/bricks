#include <Bricks.SleepSkill.h>

namespace Bricks {
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

  void SleepSkill::callback(const uint8_t *macAddr, const Message message) {
    this->sleepTime = atoi(message.value);
    writeSleepTime();
  }

  void SleepSkill::sendAwakeMessage() {
    char reason[50];
    char message[100];
    Bricks::Utils::getWakeupReason(reason);
    Log.notice("SLEE: Woke up [%s]" CR, reason);

    sprintf(message, "%s - %s", name, reason);
    gOutbox.send("awake", message);
  }

  void SleepSkill::deepSleep() {
    Log.notice("SLEE: Going to sleep for %d second(s)" CR, sleepTime);
#ifdef ESP8266
    ESP.deepSleep(sleepTime * MICROSECONDS);
#elif ESP32
    esp_bluedroid_disable();
    esp_bluedroid_deinit();
    esp_bt_controller_disable();
    esp_bt_controller_deinit();
    esp_bt_mem_release(ESP_BT_MODE_BTDM);
    adc_power_off();
    esp_wifi_stop();
    esp_deep_sleep(sleepTime * MICROSECONDS);
#endif
  }

  bool SleepSkill::awakeTimeout() {
    return sleepTime > 0 && millis() >= TIMEOUT;
  }

  void SleepSkill::readSleepTime() {
    system_rtc_mem_read(RTC_SLEEP_TIME_REGISTER, &sleepTime, sizeof(sleepTime));
  }

  void SleepSkill::writeSleepTime() {
    system_rtc_mem_write(RTC_SLEEP_TIME_REGISTER, &sleepTime, sizeof(sleepTime));
  }
}
