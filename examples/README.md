# Brick Examples

- [Gateway](gateway)
- [Button](button)
- [LED](led)
- [LED RGB](led-rgb)
- [LED 8x8 Matrix](led-matrix)
- [BLE Scanner](ble)
- [IR Controller](ir)
- [PIR Sensor](pir)

## Common skills

### Inbox

| key        | description                                                        | values                     |
|------------|--------------------------------------------------------------------|----------------------------|
| *          | Responds with `ack:<KEY>` to all messages                          |                            |
| setSleep   | Start sleep cycles lasting `value` seconds                         | 0 (stop sleeping), 1-13612 |
| getBattery | Ask to send battery value                                          |                            |
| setOta     | `pio run -t upload --upload-port 192.168.4.1` when connected to AP |                            |

### Outbox

| key     | description           | values            |
|---------|-----------------------|-------------------|
| awake   | Sent when woken up    | <NAME> - <REASON> |
| battery | Current battery value | 0 - 1000+         |

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
