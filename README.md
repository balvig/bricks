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

Easiest way to get both is https://fred.sensetecnic.com/.

If you want to run these services locally, take a look at the [`docker` directory](/docker).

### 2. Install a gateway

```bash
cd examples/gateway
cp include/secrets.sample.h include/secrets.h
vi include/secrets.h
pio run
```

Make a note of the gateway's MAC address:

```bash
Initialized [82:7d:3a:79:14:79]
```

**Note:** Bricks currently requires a WiFi network that uses channel 1.

### 3. Create some bricks

[WIP catalogue here](/examples).
For example a button and an LED:

```bash
export PLATFORMIO_BUILD_FLAGS="'-DBRICKS_GATEWAY_MAC=\"82:7d:3a:79:14:79\"'"

cd examples/button
pio run

cd examples/led
pio run
```

### 4. Communicate with bricks using MQTT

Bricks announce themselves and their MAC addresses when they come online:

```mqtt
bricks/in/ee:fa:bc:8e:89:1e/awake: Button - external system reset
bricks/in/ee:fa:bc:8e:89:8f/awake: LED - external system reset
```

Use the MAC address to send messages to the bricks:

```mqtt
bricks/out/ee:fa:bc:8e:89:8f/setPattern: 1
```

### 5. Connect bricks in NodeRED

Here is a simple example that allows a button brick to control an LED
brick:

<img src=example.png width=500>
<img src=example.gif width=400>

## Software

### Todo
- [ ] Turn "setRotation" into a skill instead for LED Matrix
- [ ] TravisCI
- [ ] "Dash button" implementation that won't trigger when ESP8266 wakes up for other reasons

### Nice to haves
- [ ] Consider using `qos=1` for sending messages
- [ ] Fix errors raised by `pio check` (mainly passing `Message` by value)
- [ ] Write up making a brick
- [ ] Allow BLE scanner to subscribe to beacon notifications
- [ ] More tests
- [ ] Make aliexpress ble button send notifications
- [ ] Idea: Move sender macAddr into message to reduce params? Or maybe leave out entirely?
- [ ] ESP32 suffers from random brownouts on boot. Should sleep care about reset reason?

## Hardware

### Todo
- [ ] Wooden panels
- [ ] Sturdier PCB attachment
- [ ] Nicer stickers
- [ ] Reset Button
- [ ] LED
- [ ] Try out [Wemos D1 hack](https://www.youtube.com/watch?v=rfPwOtoGO4E)
