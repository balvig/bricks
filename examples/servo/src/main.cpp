// Bricks
#include <Bricks.Brick.h>
using namespace Bricks;

// Servo
#include <Servo.h>

const int HAND_PIN = 13;
const int SERVO_POWER_PIN = 14;
const int DONE = -1;
int degrees = DONE;

Servo hand;

void setServoPower(bool powerOn) {
  if (powerOn) {
    Log.notice("SERV: Power on" CR);
    digitalWrite(SERVO_POWER_PIN, HIGH);
  }
  else {
    Log.notice("SERV: Power off" CR);
    digitalWrite(SERVO_POWER_PIN, LOW);
  }
}

void updateHand() {
  setServoPower(true);
  Log.notice("SERV: Moving hand [%d]" CR, degrees);
  hand.attach(HAND_PIN);
  hand.write(degrees);
  Log.trace("SERV: Waiting..." CR);
  delay(1000);  // To avoid interrupting hand
  Log.trace("SERV: Detaching" CR);
  hand.detach();
  setServoPower(false);
  degrees = DONE;
}

void setDegrees(BRICKS_CALLBACK_SIGNATURE) {
  degrees = atoi(message.value);
}

// Main
void setup() {
  // Logging
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);

  // Set up servo power
  pinMode(SERVO_POWER_PIN, OUTPUT);

  // Configure Brick
  gBrick.init("Servo");
  gBrick.skills[0] = new Skill("set", &setDegrees);
}

void loop() {
  gBrick.loop();

  if (degrees > DONE) {
    updateHand();
  }
}
