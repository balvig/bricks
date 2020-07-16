#include <Arduino.h>
#include <unity.h>
#include <Bricks.Brick.h>
#include <Bricks.Inbox.h>
#include <Bricks.PongAction.h>
using namespace Bricks;

void setUp(void) {
  gBrick.init();
}

void test_process() {
  const uint8_t macAddr[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
  Message message;
  strcpy(message.key, "ping");

  gInbox.actions[0] = new PongAction();
  gInbox.process(macAddr, message);
}

void setup() {
  delay(2000); // if board doesn't support software reset via Serial.DTR/RTS

  UNITY_BEGIN();
  RUN_TEST(test_process);
  UNITY_END();
}

void loop() {
}
