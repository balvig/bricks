# LED - RGB

For https://docs.wemos.cc/en/latest/d1_mini_shiled/rgb_led.html
Flashes all LEDs on reset so left out sleep functions :/

## Inbox

| key          | description                           | values                          |
|--------------|---------------------------------------|---------------------------------|
| ping         | Responds with `pong`                  |                                 |
| ping         | Saves gateway MAC                     |                                 |
| getBattery   | Ask to send battery value             |                                 |
| setPattern   | Change LED pattern                    | 0 (off), 1 (on), 2-4 (patterns) |
| setVariation | Set pattern variation (usually color) | 0-255                           |
| setDelay     | Set speed of pattern                  | 0-255                           |

## Outbox

| key     | description                               | values                   |
|---------|-------------------------------------------|--------------------------|
| *       | Responds with `ack:<KEY>` to all messages | same as received message |
| pong    | Sent when receiving `ping`                | name of brick            |
| battery | Current battery value                     | 0 - 1000+                |
