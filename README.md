# Bricks (super WIP)
<img src=logo.png width=300>

## Todo
- [ ] Remove `/bricks/` prefix
- [ ] Find a way to make BRICKS_MQTT_TOPIC_PREFIX configurable
- [ ] Investigate random gateway crashes
- [ ] Look into permanency of MAC addresses
  - https://randomnerdtutorials.com/get-change-esp32-esp8266-mac-address-arduino/

## NODE-RED
- [ ] Capture prefix somewhere
  - Seems possible for `/out` but not for `/in`
- [ ] message in macros (maybe tricky?)
- [ ] message out macros

## Nice to haves
- [ ] Properly scrollable m5 screen
- [ ] Is `WIFI_AP` or `WIFI_STA` better for bricks?
- [ ] Rename action "key" to name?
- [ ] OTA updates
- [ ] Extract library files to library. Organize libs, bricks, platformio.ini
- [ ] Idea: Reply with de-duped list of "capabilities" instead of name?

## Bricks

### Tethered
- [x] Button
- [x] LED
- [ ] RGB LED
- [ ] BLE scanner
- [ ] Matrix

### Battery-driven
- [ ] Button
- [ ] LED
- [ ] Reed switch
- [ ] Servo

## Physical

- [ ] Cases
- [ ] Coin battery hookup


## Supported platforms

- ESP32: Supports sending messages to all via `FF::FF::FF::FF::FF::FF`. Recommended for gateway.
- ESP8266: Only supports sending messages to specific MAC addresses.


## Installing

```bash
cd gateway
make upload serial ENV=... # check platformio.ini for supported devices
```
