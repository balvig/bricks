# Brick Examples

- [Gateway](gateway)
- [Gateway using m5stack LCD for logs](gateway-m5)
- [Button](button)
- [Button (sleeps)](button-sleep)
- [LED](led)
- [LED RGB](led-rgb)
- [LED 8x8 Matrix](led-matrix)
- [BLE Scanner](scanner)

## Creating a brick

### Inbox/Outbox

### Actions

### "Pong"


## Planned Bricks

- Battery button (https://www.youtube.com/watch?v=nbMfb0dIvYc)
- Battery LED
- Battery reed switch
- Battery servo
- ...more!

## Supported Platforms

- **ESP32**: Supports sending messages to multiple devices via `FF::FF::FF::FF::FF::FF`. Recommended for gateway.
- **ESP8266**: Only supports sending messages to specific MAC addresses. Can be used for bricks.

## Hardware

- [ ] Cases (Mesh-like form factor?)
- [ ] Batteries: Rechargable? Coin batteries? AAs?
- [ ] Base chip, what to use?

## Specs

- Built-in battery (aim: 30-day battery life, currently 11 hours :D)
- Deep sleep:
  - can't go lower than 0.016~0.030A for Wemos ESP32/ESP8266 with LEDs (even when LEDs not on)?
  - no lower than 0.06A _without_ LEDs? (ESP8266)
  - ESP8266 needs D0/16 <-> RST connection to wake up (but that prevents flashing?)
  - Could hook up button both to GPIO and RST to catch long-presses?
  - https://diyprojects.io/esp8266-deep-sleep-mode-test-wake-pir-motion-detector/#.XxrGDPgzblx
- USB port for charging and powering?
- On/off/reset/check battery-button?
- Easy to attach to each other?
