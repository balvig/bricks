# Bricks (super WIP)
<img src=logo.png width=200>

Casual dabbling in the world of IoT still feels a little _too_ hard (or expensive!)

The aim of Bricks is to make turning ideas (even silly ones) into
reality a quick, easy, and fun activity.

Think [Sony Mesh](https://meshprj.com/), but without the hefty price tag,
running entirely on existing Arduino hardware and open source software.

## How it works

**NodeRED** <-MQTT-> **Gateway Brick** <-ESPNow-> **Bricks**

## Usage

### 1. Set up MQTT, NodeRED

Easiest way to get both is https://fred.sensetecnic.com/

### 2. Install a gateway

```bash
cd examples/gateway
make upload
```

### 3. Create some bricks

Find a few [here](/examples).

For example a button:

```bash
cd examples/button
make upload
```

and an LED:

```bash
cd examples/led
make upload
```

### 4. Send out a ping

```mqtt
bricks/out/ff:ff:ff:ff:ff:ff/ping
```

This will configure all bricks to use the gateway,
each responding with a "pong" containing their MAC address:

```mqtt
bricks/in/ee:fa:bc:8e:89:1e/pong: button
```

### 5. Connect things in NodeRED

Here is a simple example that allows a button brick to control an LED
brick:

<img src=example.png width=500>


## Todo

### Next
- [ ] Figure out why `led-rgb` can't find local lib after moving to subfolder
- [ ] Find a way to make `BRICKS_MQTT_TOPIC_PREFIX` configurable
- [ ] Fix errors raised by linter (mainly passing Message by value)
- [ ] Investigate rare gateway crashes
- [ ] Look into permanency of MAC addresses
  - https://randomnerdtutorials.com/get-change-esp32-esp8266-mac-address-arduino/
- [ ] Bricks hardware

### Nice to haves
- [ ] Properly scrollable m5 screen (repurpose https://github.com/totsucom/M5Stack_ScrollTextWindow ?)
- [ ] Rename action "key" to name?
- [ ] Is `WIFI_AP` or `WIFI_STA` better for bricks?
- [ ] Couple of exported NodeRED flows
- [ ] Idea: Reply with de-duped list of "capabilities" instead of name?
- [ ] OTA updates
