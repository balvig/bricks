#include <Arduino.h>
#include <ArduinoLog.h>
#include <unity.h>
#include <Bricks.Brick.h>
#include <Bricks.BatterySkill.h>
using namespace Bricks;

void setUp(void) {
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_TRACE, &Serial);
}

void test_battery() {
  const uint8_t macAddr[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
  Message message;
  strcpy(message.key, "getBattery");

  gBrick.skills[0] = new BatterySkill();
  gBrick.process(macAddr, message);
}

void test_list_skills() {
  gBrick.skills[0] = new BatterySkill();

  TEST_ASSERT_EQUAL_STRING("getBattery", gBrick.listSkills().c_str());
}

void setup() {
  delay(2000); // if board doesn't support software reset via Serial.DTR/RTS

  UNITY_BEGIN();
  RUN_TEST(test_battery);
  RUN_TEST(test_list_skills);
  UNITY_END();
}

void loop() {
}
