# Bricks BLE Scanner

Scans for BLE devices and responds with `found` for any named devices
found.

## Inbox
- `ping`
- `scan` Value: scan time in seconds. No value will make it get stuck in a never ending scan (!)

## Outbox
- `found` Value: Name, mac, RSSI `Tile,e3:12:0b:13:a5:ae,-82`
