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

## Todo

### Next
- [ ] [ACK/retry](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/network/esp_now.html#send-esp-now-data)
- [ ] Battery [read strategies](https://github.com/balvig/bricks/compare/battery)
- [ ] Refine pairing process
  - Need paired/unpaired status?
  - If ACK is built in to all bricks, no need for `pong`?
  - Should Bricks stop advertising once paired?

### Thoughts on ACK/Reply

For v0.1, could this be done entirely NodeRED side?

While it would be nice to have it built in to bricks and "just work",
it will result in further complexity C++ side and extra processing load
on the bricks.

Some scenarios maybe lost messages don't even matter too much?

Scenarios to solve:

| Scenario         | Solution                                                             |
|------------------|----------------------------------------------------------------------|
| `setValue`       | Simple retry unless ACK is received                                  |
| `sleep`          | Simple retry unless ACK is received                                  |
| `awake` - Button | Manual repress                                                       |
| `awake` - timed  | Schedule future ping after `sleep`. Send ping if no response by then |

### Nice to haves
- [ ] Allow BLE scanner to subscribe to beacon notifications
- [ ] Fix errors raised by `pio check` (mainly passing `Message` by value)
  - Also, get `pio check` running again!
- [ ] Write up making a brick
- [ ] "Pack" of built in actions for all bricks?
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
