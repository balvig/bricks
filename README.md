# Bricks (super WIP)
<img src=logo.png width=300>

## Todo

- [ ] Reply with list of actions instead of name
- [ ] Find a way to make BRICKS_MQTT_TOPIC_PREFIX configurable
- [ ] Encapsulate gateway mac store/retrieve flow
- [ ] Isolate M5/Gateway code
- [ ] Investigate flakiness in ESP8266 messages to ESP32 gateway
- [ ] Organize libs, bricks, platformio.ini
- [ ] Look into permanency of MAC addresses
  - https://randomnerdtutorials.com/get-change-esp32-esp8266-mac-address-arduino/

## NODE-RED

- [ ] message in/out macros
- [ ] Capture prefix somewhere

## Nice to haves
- [ ] Clean up logs with CAPS
- [ ] Downcase/upcase consistency for mac addresses
- [ ] Rename action "key" to name?
- [ ] Maybe only set gateway to AP_STA? Set rest to STA?
- [ ] Find out why/when gateway reboots
- [ ] OTA updates

## Bricks

### Tethered
- [x] Button
- [x] LED
- [ ] BLE scanner
- [ ] Reed switch
- [ ] Matrix
- [ ] Servo

### Battery-driven
- [ ] Button
- [ ] LED
- [ ] Reed switch
- [ ] Servo

## Physical

- [ ] Cases


## Supported platforms

- ESP32
- ESP8266 (some flakiness when sending messages)


## Installing

```bash
cd gateway
make upload serial ENV=... # check platformio.ini for supported devices
```
