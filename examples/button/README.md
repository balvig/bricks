# Button

"Always on" button.
Very responsive but will consume battery/should probably be plugged in.

## Inbox

| key  | description          | values |
|------|----------------------|--------|
| ping | Responds with `pong` |        |
| ping | Saves gateway MAC    |        |


## Outbox

| key  | description                | values        |
|------|----------------------------|---------------|
| pong | Sent when receiving `ping` | name of brick |
| on   | Turns LED on               |               |
| off  | Turns LED off              |               |

