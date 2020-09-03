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

**Note:** Bricks currently requires a WiFi network that uses channel 1.

### 3. Create some bricks

[WIP library here](/examples).
For example a button:

```bash
cd examples/button
pio run
```

and an LED:

```bash
cd examples/led
pio run
```

### 4. Scan for bricks

```mqtt
bricks/gateway/scan
```

This will configure all active bricks to use the gateway,
each responding with a "pong" containing their MAC address and name:

```mqtt
bricks/in/ee:fa:bc:8e:89:1e/pong: Button
```

### 5. Connect things in NodeRED

Here is a simple example that allows a button brick to control an LED
brick:

<img src=example.png width=500>
<img src=example.gif width=400>

### Todo

- [x] Button
- [ ] LED
- [ ] Try out [Wemos D1 hack](https://www.youtube.com/watch?v=rfPwOtoGO4E)

## Software

### Todo
- [ ] TravisCI
- [ ] Turn "setRotation" into an action instead for LED Matrix

### Nice to haves
- [ ] Fix errors raised by `pio check` (mainly passing `Message` by value)
- [ ] Write up making a brick
- [ ] Allow BLE scanner to subscribe to beacon notifications
- [ ] More tests
- [ ] Make aliexpress ble button send notifications
- [ ] Idea: Move sender macAddr into message to reduce params to 1?
- [ ] Use same system for defining mqtt responses (instead of hardcoded "scan")
  ```
  // Connect mqtt event stream
  gEvents.init();
  gEvents.events[0] = new ScanEvent();
  gEvents.events[1] = new BroadcastEvent();
  ```
