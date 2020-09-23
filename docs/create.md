## Creating Bricks

To illustrate how Bricks works, this simple example will allow pressing
a button Brick to turn on/off an LED Brick.

<img src=/docs/example.gif width=400>

The example uses:

- 3 x [LOLIN D1 Minis](https://www.aliexpress.com/item/32529101036.html)
- 1 x [LOLIN Button Shield](https://www.aliexpress.com/item/32575988167.html)

However, basically any combination of ESP8266/ESP32 boards and capabilities will do, and you can modify the existing [examples](/examples) or [write your own](/docs/integrate.md) as needed.

### 1. Create a Gateway Brick

One board will act as the _Gateway Brick_.

The gateway receives messages from other Bricks via ESP-NOW and converts them into [MQTT](https://mqtt.org/), and vice versa:

<img src=/docs/gateway.svg>

Once you have a gateway running, you can use something like [Node-RED](https://nodered.org/) or other client that speaks MQTT to easily control any number of Bricks and how they interact with each other:

<img src=/docs/combine.svg>

The gateway is the only Brick that connects to WiFi + MQTT and can be configured by editing `secrets.h`:

```bash
cd examples/gateway
cp include/secrets.sample.h include/secrets.h
vi include/secrets.h
pio run
```

Make a note of the gateway's MAC address output on the serial monitor, as this is needed to configure the other Bricks.

```bash
Initialized [82:7d:3a:79:14:79]
```

**Note:** Bricks currently requires a WiFi network that uses channel 1.

### 2. Create an LED Brick

The [LED Brick example](/examples/led) defaults to using the built-in LED, allowing it to
be turned on/off by sending `setPattern` messages with values of `1` or `0`.

```bash
export PLATFORMIO_BUILD_FLAGS="'-DBRICKS_GATEWAY_MAC=\"82:7d:3a:79:14:79\"'"

cd examples/led
pio run
```

### 3. Create a Button Brick

The [Button Brick example](/examples/button) assumes a button attached
to GPIO 0, and will send `pressed` and `released` messages.

```bash
export PLATFORMIO_BUILD_FLAGS="'-DBRICKS_GATEWAY_MAC=\"82:7d:3a:79:14:79\"'"

cd examples/button
pio run
```

### 4. Define Brick behavior using MQTT

Bricks announce themselves and their MAC addresses when they come online:

```mqtt
bricks/in/ee:fa:bc:8e:89:1e/awake: Button - external system reset
bricks/in/ee:fa:bc:8e:89:8f/awake: LED - external system reset
```

Use these MAC addresses to send/receive messages to/from specific
Bricks.

For this example, a Node-RED solution could be a simple as:

<img src=/docs/mqtt.svg>