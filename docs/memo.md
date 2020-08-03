## Strategies for overcoming occasional message loss

While it would be nice to have an ACK/REPLY system built in to bricks and "just work",
it will result in further complexity C++ side and extra processing load on the bricks
(and would still not be a guarantee?)

For many scenarios,  maybe lost messages don't even matter too much?

Where it _does_ matter, these are some approaches that can be taken:

### Outcoming message lost
- Use `AckAction` + retry in Node-RED (examples [here](/node-red)).

### Incoming message lost
- Combine responding to `awake` with Node-RED side cron>

## WiFi limitations
- Channel needs to be same as connected WiFi?
- Channel is _maybe_ hardcoded to 1 when using `WIFI_AP_STA`?
  - https://rntlab.com/question/esp-now-gateway-wifi_mode_sta-with-a-wifi-router/#answer-71229
  - https://github.com/espressif/arduino-esp32/issues/878#issuecomment-578885352

### Test results

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
