// Bricks
#include <Bricks.Brick.h>
using namespace Bricks;

// Local
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRsend.h>
#include <IRutils.h>
#include <IRcode.h>
#include <codes.h>

const uint16_t RECEIVER_PIN = D4;
const uint16_t SEND_PIN = D3;
const uint16_t BUFFER = 1024;
const uint8_t TIMEOUT = 50;
const uint16_t FREQUENCY = 38000;  // in Hz. e.g. 38kHz.

IRrecv irrecv(RECEIVER_PIN, BUFFER, TIMEOUT);
IRsend irsend(SEND_PIN);
decode_results results;

IRCode *code;

// Bricks callbacks
void sendCode(BRICKS_CALLBACK_SIGNATURE) {
  code = codes[atoi(message.value)];
}

void setup() {
  // Logging
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);

  // Start the IR receiver / sender
  irrecv.enableIRIn();
  irsend.begin();

  // Configure Brick
  gBrick.init("IR Controller");
  gBrick.skills[0] = new Skill("sendCode", &sendCode);
}

void loop() {
  if(code) {
    Log.notice("IRED: Sending [%s]" CR, code->key);
    irsend.sendRaw(code->timings, code->length, FREQUENCY);
    code = nullptr;
  }
  else if(irrecv.decode(&results)) {
    Log.notice("IRED: Received signal" CR);
    Log.notice(resultToSourceCode(&results).c_str());
    irrecv.resume();
  }
  gBrick.loop();
}
