# Brick Examples

- [Gateway](gateway)
- [Button (realtime)](button)
- [Button (sleeps)](button-sleep)
- [LED](led)
- [LED RGB](led-rgb)
- [LED 8x8 Matrix](led-matrix)
- [BLE Scanner](scanner)
- [IR Controller](ir)
- [PIR Sensor](pir)

## Common actions

### Inbox

| key        | description                               | values               |
|------------|-------------------------------------------|----------------------|
| *          | Responds with `ack:<KEY>` to all messages |                      |
| ping       | Saves gateway MAC, responds with `pong`   |                      |
| sleep      | Sleep for `value` seconds                 | 0 (forever), 1-13612 |
| getBattery | Ask to send battery value                 |                      |

### Outbox

| key     | description                            | values         |
|---------|----------------------------------------|----------------|
| awake   | Sent when woken up                     | wake-up reason |
| battery | Current battery value                  | 0 - 1000+      |
| pong    | Sent on boot and when receiving `ping` | name of brick  |

## Planned Bricks

### Basic set

- Gateway
- Color LED
- Button
- Light sensor
- PIR
- BLE Scanner

### Extended set

- 8x8 Matrix
- Ambient light
- Temperature & Humidity
- IR (send/receive)
- Reed switch
- Servo
- LED strip
