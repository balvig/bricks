# Bricks LED 8x8 Matrix

## Inbox

| key      | description                             | values           |
|----------|-----------------------------------------|------------------|
| ping     | Saves gateway MAC. Responds with `pong` |                  |
| sleep    | Sleep for `value` seconds.              | 0 (forever), 1-? |
| setValue | Shows one character                     | 0-9 A-Z          |


## Outbox

| key   | description                               | values         |
|-------|-------------------------------------------|----------------|
| ack:* | Responds with `ack:<KEY>` to all messages |                |
| awake | Sent when woken up                        | wake-up reason |
| pong  | Sent when receiving `ping`                |                |

