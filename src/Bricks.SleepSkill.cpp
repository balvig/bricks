#include <Bricks.SleepSkill.h>

namespace Bricks {
  SleepSkill::SleepSkill(const char *name) : Skill("sleep") {
    this->name = name;
    sendAwakeMessage();
  }

  void SleepSkill::callback(const uint8_t *macAddr, const Message message) {
    const uint32_t sleepTime = atoi(message.value);
    deepSleep(sleepTime);
  }

  void SleepSkill::sendAwakeMessage() {
    char reason[50];
    char message[100];
    Bricks::Utils::getWakeupReason(reason);
    Log.notice("SLEE: Woke up [%s]" CR, reason);

    sprintf(message, "%s - %s", name, reason);
    gOutbox.send("awake", message);
  }

  void SleepSkill::deepSleep(const uint32_t seconds) {
    Log.notice("SLEE: Going to sleep for %d second(s)" CR, seconds);
#ifdef ESP8266
    ESP.deepSleep(seconds * MICROSECONDS);
#elif ESP32
    esp_bluedroid_disable();
    esp_bluedroid_deinit();
    esp_bt_controller_disable();
    esp_bt_controller_deinit();
    esp_bt_mem_release(ESP_BT_MODE_BTDM);
    adc_power_off();
    esp_wifi_stop();
    esp_deep_sleep(seconds * MICROSECONDS);
#endif
  }
}
