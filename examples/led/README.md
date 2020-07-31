# LED

## Inbox

| key        | description          | values          |
|------------|----------------------|-----------------|
| ping       | Responds with `pong` |                 |
| setPattern | Change LED pattern   | 0 (off), 1 (on) |

## Outbox

| key  | description                | values        |
|------|----------------------------|---------------|
| pong | Sent when receiving `ping` | name of brick |
