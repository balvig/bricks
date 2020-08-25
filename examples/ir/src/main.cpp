// Bricks
#include <Bricks.Brick.h>
#include <Bricks.Constants.h>
#include <Bricks.Inbox.h>
#include <Bricks.OtaAction.h>
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
void sendCode(const uint8_t *macAddr, const Message message) {
  code = codes[atoi(message.value)];
}

void setup() {
  // Logging
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);

  // Configure ESPNow
  gBrick.init();

  gInbox.init("IR Controller");
  gInbox.actions[0] = new OtaAction();
  gInbox.actions[1] = new Action("sendCode", &sendCode);

  // Start the IR receiver / sender
  irrecv.enableIRIn();
  irsend.begin();
}

void loop() {
  if(code) {
    Log.notice("IRED: Sending [%s]", code->key);
    irsend.sendRaw(code->timings, code->length, FREQUENCY);
    code = nullptr;
  }
  else if(irrecv.decode(&results)) {
    Log.notice("IRED: Received signal");
    Log.notice(resultToSourceCode(&results).c_str());
    irrecv.resume();
  }
  ArduinoOTA.handle();
}
