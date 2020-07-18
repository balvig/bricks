# Bricks (super WIP)
<img src=logo.png width=200>

Dabbling in the brave new world of IoT still seems a little _too_ hard (or expensive!)

The aim of Bricks is to make turning ideas (even silly ones) into
reality a quick, easy, and fun activity.

Think [Sony Mesh](https://meshprj.com/), but without the hefty price tag,
running entirely on existing Arduino hardware and open source software.

## Setup

```
NodeRED <-> MQTT <-> Gateway <-> ESPNow --> LED Brick
                                        --> LED RGB Brick
                                        <-- Button Brick
                                        <-> BLE Scanner Brick
                                        <-> Other Brick
```


### Supported devices

- **ESP32**: Supports sending messages to multiple devices via `FF::FF::FF::FF::FF::FF`. Recommended for gateway.
- **ESP8266**: Only supports sending messages to specific MAC addresses. Can be used for bricks.

### 1. Set up MQTT, NodeRED

Easiest way to get both is https://fred.sensetecnic.com/


### 2. Install a gateway

```bash
cd gateway
make upload ENV=... # check platformio.ini for supported devices
```

### 3. Create some bricks

For example a button:

```bash
cd button
make upload ENV=... # check platformio.ini for supported devices
```

### 4. Send out a ping

```mqtt
bricks/out/ff:ff:ff:ff:ff:ff/ping
```

This will connect all bricks to the gateway, each responding with a pong:

```
bricks/in/ee:fa:bc:8e:89:1e/pong: button
```

### 5. Hook things together in NodeRED

Here is a simple example that allows a button brick to control an LED
brick:

<img src=example.png width=500>


## Todo

### Next
- [ ] Find a way to make `BRICKS_MQTT_TOPIC_PREFIX` configurable
- [ ] Investigate rare gateway crashes
- [ ] Look into permanency of MAC addresses
  - https://randomnerdtutorials.com/get-change-esp32-esp8266-mac-address-arduino/

### NodeRED
- [ ] Capture prefix somewhere
  - Seems possible for `/out` but not for `/in` :/
- [ ] message in macros (maybe tricky?)
- [ ] message out macros

### Nice to haves
- [ ] Properly scrollable m5 screen (repurpose https://github.com/totsucom/M5Stack_ScrollTextWindow ?)
- [ ] Rename action "key" to name?
- [ ] Extract library files to library?
- [ ] Is `WIFI_AP` or `WIFI_STA` better for bricks?
- [ ] Idea: Reply with de-duped list of "capabilities" instead of name?
- [ ] OTA updates

## Planned Bricks

### Tethered
- [x] Button
- [x] LED
- [x] RGB LED
- [ ] BLE scanner
- [ ] Matrix

### Battery-driven
https://www.youtube.com/watch?v=nbMfb0dIvYc

- [ ] Button
- [ ] LED
- [ ] Reed switch
- [ ] Servo

## Hardware

- [ ] Cases (Mesh-like form factor?)
- [ ] Batteries: Rechargable? Coin batteries? AAs?
- [ ] Base chip
