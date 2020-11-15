# BLE Scanner (WIP)

Scans for BLE devices and responds with `found` for any named devices
found.

## Skills

| in   | out      | description                | values                                       |
|------|----------|----------------------------|----------------------------------------------|
| scan | ack:scan | Scan for (x) seconds.      | 1-255                                        |
|      | found    | Sent when BLE device found | Name, MAC, RSSI `Tile,12:34:56:78:9a:bd,-82` |
