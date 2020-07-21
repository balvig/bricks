# Brick Examples

- [Gateway](gateway)
- [Ponger](ponger)
- [Button](button)
- [LED](led)
- [LED RGB](led-rgb)
- [LED 8x8 Matrix](matrix)
- [BLE Scanner](scanner)
- [Gateway using m5stack LCD for logs](gateway-m5)

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
