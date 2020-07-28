#include "Bricks.Utils.h"

namespace Bricks {
  void Utils::macToStr(const uint8_t *macAddr, char *macStr) {
    snprintf(macStr, MAC_STR_SIZE, MAC_FORMAT,
        macAddr[0], macAddr[1], macAddr[2], macAddr[3], macAddr[4], macAddr[5]);
  }

  void Utils::getWakeupReason(char *reason) {
#ifdef ESP8266
    switch(ESP.getResetInfoPtr()->reason) {
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
      default:
        strcpy(reason, "unknown");
    }
#elif ESP32
    switch(esp_sleep_get_wakeup_cause()) {
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
      default:
        strcpy(reason, "unknown");
    }
#endif
  }
}
