# Bricks BLE Scanner

Scans for BLE devices and responds with `found` for any named devices
found.

## Inbox
- `ping`
- `setScan` scan time in seconds. No value will make it get stuck in a never ending scan (!)
- `setWait` wait time in seconds between scans.
- `setMinRSSI` minimum RSSI in order to trigger event.

## Outbox
- `found` Mac, RSSI `e3:12:0b:13:a5:ae,-82`
