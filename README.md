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
platformio run
```

**Note:** Bricks currently requires a WiFi network that uses channel 1.

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


## Todo

### Next
- [ ] Battery [read strategies](https://github.com/balvig/bricks/compare/battery)
- [ ] "Pack" of built in actions for all bricks?
- [ ] Solve dropped messages problem
- [ ] Refine pairing process
  - Need paired/unpaired status?
  - If ACK is built in to all bricks, no need for `pong`?
  - Should Bricks stop advertising once paired? (what's the power usage difference)
  - Raise an error if Brick is found on "incompatible" channel?

### Nice to haves
- [ ] Allow BLE scanner to subscribe to beacon notifications
- [ ] Properly scrollable m5 screen (repurpose https://github.com/totsucom/M5Stack_ScrollTextWindow ?)
- [ ] Fix errors raised by `pio check` (mainly passing `Message` by value)
  - Also, get `pio check` running again!
- [ ] Write up making a brick
- [ ] Maybe publish gateway uptime/online events?
- [ ] More tests
- [ ] Make aliexpress ble button send notifications
- [ ] Idea: Move sender macAddr into message to reduce params to 1?
- [ ] Idea: Reply with de-duped list of "capabilities" instead of name?
- [ ] NodeRED - Allow topic, mac to take msg input
- [ ] NodeRED - Couple of exported flows
- [ ] Use same system for defining mqtt responses (instead of hardcoded "scan")
  ```
  // Connect mqtt event stream
  gEvents.init();
  gEvents.events[0] = new ScanEvent();
  gEvents.events[1] = new BroadcastEvent();
  ```


### Limitations
- Channel needs to be same as connected WiFi
- Channel is _maybe_ hardcoded to 1 when using `WIFI_AP_STA`?
  - https://rntlab.com/question/esp-now-gateway-wifi_mode_sta-with-a-wifi-router/#answer-71229
  - https://github.com/espressif/arduino-esp32/issues/878#issuecomment-578885352
- Some level of dropping is expected? (how much?) Need to have [manual ACK/retry system](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/network/esp_now.html#send-esp-now-data)?
  - Testing out _basic_ ACK in [led-matrix](examples/led-matrix)

#### Test results

| Gateway AP | Gateway Peer | Brick AP | Brick Peer | Ping | Pong |
|------------|--------------|----------|------------|------|------|
| 1          | 1            | 1        | 1          | OK   | OK   |
| 6          | 1            | 1        | 1          | OK   | OK   |
| 1          | 6            | 1        | 1          | OK   | OK   |
| 6          | 6            | 1        | 1          | OK   | OK   |
| 1          | 1            | 6        | 1          | NG   | NG   |
| 1          | 1            | 1        | 6          | OK   | NG   |
| 1          | 1            | 6        | 6          | NG   | NG   |
| 1          | 1            | 2        | 1          | OK   | NG   |
