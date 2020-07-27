# LED - RGB

For https://docs.wemos.cc/en/latest/d1_mini_shiled/rgb_led.html

## Inbox

| key          | description                           | values                          |
|--------------|---------------------------------------|---------------------------------|
| ping         | Responds with `pong`                  |                                 |
| ping         | Saves gateway MAC                     |                                 |
| sleep        | Sleep for `value` seconds             | 0 (forever), 1-13612            |
| setPattern   | Change LED pattern                    | 0 (off), 1 (on), 2-4 (patterns) |
| setVariation | Set pattern variation (usually color) | 0-255                           |
| setDelay     | Set speed of pattern                  | 0-255                           |

## Outbox

| key   | description                               | values                   |
|-------|-------------------------------------------|--------------------------|
| awake | Sent when woken up                        | wake-up reason           |
| pong  | Sent when receiving `ping`                | name of brick            |
