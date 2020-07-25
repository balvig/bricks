# Bricks LED 8x8 Matrix

<img src=demo.jpg width=500>

## Inbox

| key      | description               | values               |
|----------|---------------------------|----------------------|
| ping     | Responds with `pong`      |                      |
| ping     | Saves gateway MAC         |                      |
| sleep    | Sleep for `value` seconds | 0 (forever), 1-13612 |
| setValue | Shows one character       | 0-9 A-Z              |


## Outbox

| key   | description                               | values                   |
|-------|-------------------------------------------|--------------------------|
| *     | Responds with `ack:<KEY>` to all messages | same as received message |
| awake | Sent when woken up                        | wake-up reason           |
| pong  | Sent when receiving `ping`                | name of brick            |
