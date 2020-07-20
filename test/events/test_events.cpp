#include <Arduino.h>
#include <ArduinoLog.h>
#include <unity.h>
#include <Bricks.Constants.h>
#include <Bricks.Events.h>
#include <Bricks.Utils.h>

void setUp(void) {
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);
}

void test_parse_topic() {
  uint8_t macAddr[MAC_ADDR_SIZE];
  char key[20]; // TODO: Repeated from Bricks.Message.h
  const char *topic = "accounts/balvig/bricks/out/FF:FF:FF:FF:FF:FF/ping";

  Bricks::Events::parseTopic(topic, macAddr, key);

  TEST_ASSERT_EQUAL_STRING("ping", key);

  char macStr[MAC_STR_SIZE];
  Bricks::Utils::macToStr(macAddr, macStr);
  TEST_ASSERT_EQUAL_STRING("ff:ff:ff:ff:ff:ff", macStr);
}

void setup() {
  delay(2000); // if board doesn't support software reset via Serial.DTR/RTS

  UNITY_BEGIN();
  RUN_TEST(test_parse_topic);
  UNITY_END();
}

void loop() {
}
