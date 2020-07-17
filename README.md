# Bricks (super WIP)
<img src=logo.png width=300>

## Today
- [ ] BLE scanner
- [ ] Matrix

## Todo
- [ ] Find a way to make BRICKS_MQTT_TOPIC_PREFIX configurable
- [ ] Look into garbled mac addresses
- [ ] Encapsulate gateway mac store/retrieve flow
- [ ] Is `WIFI_AP` or `WIFI_STA` better for bricks?
- [ ] Look into permanency of MAC addresses
  - https://randomnerdtutorials.com/get-change-esp32-esp8266-mac-address-arduino/

## NODE-RED
- [ ] Capture prefix somewhere
  - Seems possible for `/out` but not for `/in`
- [ ] message in macros (maybe tricky?)
- [ ] message out macros

## Nice to haves
- [ ] Properly scrollable m5 screen
- [ ] Rename action "key" to name?
- [ ] OTA updates
- [ ] Organize libs, bricks, platformio.ini
- [ ] Idea: Reply with de-duped list of "capabilities" instead of name?

## Bricks

### Tethered
- [x] Button
- [x] LED
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

- ESP32
- ESP8266


## Installing

```bash
cd gateway
make upload serial ENV=... # check platformio.ini for supported devices
```
