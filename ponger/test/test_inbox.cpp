#include <Arduino.h>
#include <ArduinoLog.h>
#include <unity.h>
#include <Bricks.Inbox.h>
#include <Bricks.PongAction.h>
using namespace Bricks;

void setUp(void) {
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);
}

void test_process() {
  const uint8_t macAddr[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
  Message message;
  strcpy(message.key, "ping");

  gInbox.actions[0] = new PongAction();
  gInbox.process(macAddr, message);
}

void test_list_actions() {
  gInbox.actions[0] = new PongAction();

  TEST_ASSERT_EQUAL_STRING("ping", gInbox.listActions().c_str());
}

void setup() {
  delay(2000); // if board doesn't support software reset via Serial.DTR/RTS

  UNITY_BEGIN();
  RUN_TEST(test_process);
  RUN_TEST(test_list_actions);
  UNITY_END();
}

void loop() {
}
