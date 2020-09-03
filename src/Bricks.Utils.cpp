#include "Bricks.Utils.h"

namespace Bricks {
  void Utils::macToStr(const uint8_t *macAddr, char *macStr) {
    snprintf(macStr, MAC_STR_SIZE, MAC_FORMAT,
        macAddr[0], macAddr[1], macAddr[2], macAddr[3], macAddr[4], macAddr[5]);
  }

  bool Utils::wasManuallyReset() {
    int info = resetInfo();
#ifdef ESP8266
    return info == REASON_DEFAULT_RST || info == REASON_EXT_SYS_RST;
#elif ESP32
    return info == ESP_SLEEP_WAKEUP_UNDEFINED;
#endif
  }

  void Utils::getWakeupReason(char *reason) {
    switch(resetInfo()) {
#ifdef ESP8266
      case REASON_DEFAULT_RST:
        strcpy(reason, "normal startup by power on");
        break;
      case REASON_WDT_RST:
        strcpy(reason, "hardware watch dog reset");
        break;
      case REASON_EXCEPTION_RST:
        strcpy(reason, "exception reset, GPIO status won't change");
        break;
      case REASON_SOFT_WDT_RST:
        strcpy(reason, "software watch dog reset, GPIO status won't change");
        break;
      case REASON_SOFT_RESTART:
        strcpy(reason, "software restart, system_restart, GPIO status won't change");
        break;
      case REASON_DEEP_SLEEP_AWAKE:
        strcpy(reason, "wake up from deep-sleep");
        break;
      case REASON_EXT_SYS_RST:
        strcpy(reason, "external system reset");
        break;
#elif ESP32
      case ESP_SLEEP_WAKEUP_UNDEFINED:
        strcpy(reason, "reset was not caused by exit from deep sleep");
        break;
      case ESP_SLEEP_WAKEUP_EXT0:
        strcpy(reason, "external signal using RTC_IO");
        break;
      case ESP_SLEEP_WAKEUP_EXT1:
        strcpy(reason, "external signal using RTC_CNTL");
        break;
      case ESP_SLEEP_WAKEUP_TIMER:
        strcpy(reason, "timer");
        break;
      case ESP_SLEEP_WAKEUP_TOUCHPAD:
        strcpy(reason, "touchpad");
        break;
      case ESP_SLEEP_WAKEUP_ULP:
        strcpy(reason, "ULP program");
        break;
      case ESP_SLEEP_WAKEUP_GPIO:
        strcpy(reason, "GPIO");
        break;
      case ESP_SLEEP_WAKEUP_UART:
        strcpy(reason, "UART");
        break;
#endif
      default:
        strcpy(reason, "unknown");
    }
  }

  int Utils::resetInfo() {
#ifdef ESP8266
    return ESP.getResetInfoPtr()->reason;
#elif ESP32
    return esp_sleep_get_wakeup_cause();
#endif
  }

}
