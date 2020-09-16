#include <Arduino.h>
#include <ArduinoLog.h>
#include <unity.h>
#include <Bricks.Inbox.h>
#include <Bricks.AckSkill.h>
using namespace Bricks;

void setUp(void) {
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_TRACE, &Serial);
}

// void test_ack() {
  // const uint8_t macAddr[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
  // Message message;
  // strcpy(message.key, "ping");

  // gInbox.skills[0] = new AckSkill();
  // gInbox.process(macAddr, message);
// }

void test_list_skills() {
  gInbox.skills[0] = new AckSkill();

  TEST_ASSERT_EQUAL_STRING("*", gInbox.listSkills().c_str());
}

void setup() {
  delay(2000); // if board doesn't support software reset via Serial.DTR/RTS

  UNITY_BEGIN();
  // RUN_TEST(test_ack);
  RUN_TEST(test_list_skills);
  UNITY_END();
}

void loop() {
}
