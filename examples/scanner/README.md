# Bricks BLE Scanner (WIP)

Scans for BLE devices and responds with `found` for any named devices
found.

## Inbox

| key      | description           | values  |
|----------|-----------------------|---------|
| ping     | Responds with `pong`  |         |
| ping     | Saves gateway MAC     |         |
| scan     | Scan for (x) seconds. | 1-255   |


## Outbox

| key   | description                | values                                       |
|-------|----------------------------|----------------------------------------------|
| pong  | Sent when receiving `ping` | name of brick                                |
| found | Sent when BLE device found | Name, MAC, RSSI `Tile,12:34:56:78:9a:bd,-82` |
