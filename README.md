# Bricks (super WIP)
<img src=logo.png width=200>

Casual dabbling in the world of IoT still feels a little _too_ hard (or expensive!)

The aim of Bricks is to make turning ideas (even silly ones) into
reality a quick, easy, and fun activity.

Think [Sony Mesh](https://meshprj.com/), but without the hefty price tag,
running entirely on existing Arduino hardware and open source software.

## How it works

**NodeRED** ←MQTT→ **Brick Gateway** ←ESPNow→ **Bricks**

## Usage

### 1. Set up MQTT, NodeRED

Easiest way to get both is https://fred.sensetecnic.com/

### 2. Install a gateway

```bash
cd examples/gateway
cp include/secrets.sample.h include/secrets.h
vi include/secrets.h
platformio run
```

### 3. Create some bricks

[WIP library here](/examples).
For example a button:

```bash
cd examples/button
platformio run
```

and an LED:

```bash
cd examples/led
platformio run
```

### 4. Send out a ping

```mqtt
bricks/out/ff:ff:ff:ff:ff:ff/ping
```

This will configure all bricks to use the gateway,
each responding with a "pong" containing their MAC address and name:

```mqtt
bricks/in/ee:fa:bc:8e:89:1e/pong: Button
```

### 5. Connect things in NodeRED

Here is a simple example that allows a button brick to control an LED
brick:

<img src=example.png width=500>
<img src=example.gif width=400>


## Todo

### Next
- [ ] Bricks basic kit
  - [ ] Solder button
- [ ] Need an ACK/retry system? (delivery not guaranteed)
  - In particular ESP8266s sometimes bad at receiving messages (mainly pings to MAC_ALL?)
  - Testing out _basic_ ACK in [led-matrix](examples/led-matrix)
- [ ] Battery [read strategies](https://github.com/balvig/bricks/compare/battery)
- [ ] "Pack" of built in actions for all bricks?
- [ ] Refine pairing process
  - Need paired/unpaired status?
  - Instead of ping-pong flow, bricks can scan for gateway? (if not configured)
  - If ACK is built in to all bricks, no need for `pong`?

### Nice to haves
- [ ] Write up making a brick
- [ ] Maybe publish gateway uptime/online events?
- [ ] Fix errors raised by linter (mainly passing Message by value)
- [ ] Allow BLE scanner to subscribe to beacon notifications
- [ ] Properly scrollable m5 screen (repurpose https://github.com/totsucom/M5Stack_ScrollTextWindow ?)
- [ ] NodeRED - Allow payload, topic, mac to take msg input
- [ ] NodeRED - Couple of exported flows
- [ ] More tests
- [ ] Convert wake-up reasons to text?
- [ ] Make aliexpress ble button send notifications
- [ ] Idea: Reply with de-duped list of "capabilities" instead of name?
- [ ] Idea: Move sender macAddr into message to reduce params to 1?
