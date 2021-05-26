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
const uint8_t TIMEOUT = 100;
const uint16_t FREQUENCY = 38000;  // in Hz. e.g. 38kHz.

IRrecv irrecv(RECEIVER_PIN, BUFFER, TIMEOUT);
IRsend irsend(SEND_PIN);
decode_results results;

IRcode *code;

// Bricks callbacks
void sendCode(BRICKS_CALLBACK_SIGNATURE) {
  code = codes[atoi(message.value)];
  strcpy(response, code->key);
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
  gBrick.skills[0] = new Skill("send", &sendCode);
}

void loop() {
  if(code) {
    Log.noticeln("IRED: Sending [%s]", code->key);
    irsend.sendRaw(code->timings, code->length, FREQUENCY);
    code = nullptr;
  }
  else if(irrecv.decode(&results)) {
    Log.noticeln("IRED: Received signal");
    Log.notice(resultToSourceCode(&results).c_str());
    gOutbox.send("received", resultToHexidecimal(&results).c_str());
    irrecv.resume();
  }
  gBrick.loop();
}
