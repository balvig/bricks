# Button - Sleep

"Sleepable" button/trigger.
Should be put to sleep "permanently" and use RST wake-up as trigger.

## Inbox

| key   | description               | values               |
|-------|---------------------------|----------------------|
| ping  | Responds with `pong`      |                      |
| ping  | Saves gateway MAC         |                      |
| sleep | Sleep for `value` seconds | 0 (forever), 1-13612 |


## Outbox

| key   | description                | values         |
|-------|----------------------------|----------------|
| awake | Sent when woken up         | wake-up reason |
| pong  | Sent when receiving `ping` | name of brick  |
