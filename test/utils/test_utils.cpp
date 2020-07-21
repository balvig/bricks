#include <Arduino.h>
#include <ArduinoLog.h>
#include <unity.h>
#include <Bricks.Utils.h>

void setUp(void) {
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);
}

void test_mac_to_str() {
  const uint8_t macAddr[] = {0xDE, 0x4F, 0x22, 0x01, 0xB1, 0xC0};
  char macStr[MAC_STR_SIZE];
  Bricks::Utils::macToStr(macAddr, macStr);

  TEST_ASSERT_EQUAL_STRING("de:4f:22:01:b1:c0", macStr);
}

void setup() {
  delay(2000); // if board doesn't support software reset via Serial.DTR/RTS

  UNITY_BEGIN();
  RUN_TEST(test_mac_to_str);
  UNITY_END();
}

void loop() {
}
