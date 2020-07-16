#include <Arduino.h>
#include <unity.h>
#include <Bricks.Utils.h>

// void setUp(void) {
// // set stuff up here
// }

// void tearDown(void) {
// // clean stuff up here
// }

void test_mac_to_str() {
  const uint8_t macAddr[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
  char macStr[Bricks::Utils::MAC_STR_SIZE];
  Bricks::Utils::macToStr(macAddr, macStr);

  TEST_ASSERT_EQUAL_STRING("ff:ff:ff:ff:ff:ff", macStr);
}

void test_parse_topic() {
  uint8_t macAddr[Bricks::Utils::MAC_ADDR_SIZE];
  char key[20]; // TODO: Repeated from Bricks.Message.h
  const char *topic = "accounts/balvig/bricks/messages/out/FF:FF:FF:FF:FF:FF/ping";

  Bricks::Utils::parseTopic(topic, macAddr, key);

  TEST_ASSERT_EQUAL_STRING("ping", key);

  char macStr[Bricks::Utils::MAC_STR_SIZE];
  Bricks::Utils::macToStr(macAddr, macStr);
  TEST_ASSERT_EQUAL_STRING("ff:ff:ff:ff:ff:ff", macStr);
}

void setup() {
  delay(2000); // if board doesn't support software reset via Serial.DTR/RTS

  UNITY_BEGIN();
  RUN_TEST(test_mac_to_str);
  RUN_TEST(test_parse_topic);
  UNITY_END();
}

void loop() {
}
