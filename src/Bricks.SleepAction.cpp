#include <Bricks.SleepAction.h>

namespace Bricks {
  SleepAction::SleepAction() : Action("sleep") {
    sendAwakeMessage();
  }

  void SleepAction::callback(const uint8_t *macAddr, const Message message) {
    const uint32_t sleepTime = atoi(message.value);
    deepSleep(sleepTime);
  }

  void SleepAction::sendAwakeMessage() {
    Log.notice("SLEE: Woke up" CR);
    char value[2] = "";
#ifdef ESP8266
    sprintf(value, "%d", ESP.getResetInfoPtr()->reason);
#elif ESP32
    sprintf(value, "%d", esp_sleep_get_wakeup_cause());
#endif
    gOutbox.send("awake", value);
  }

  void SleepAction::deepSleep(const uint32_t seconds) {
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
