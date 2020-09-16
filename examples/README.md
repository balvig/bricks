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
| setSleep   | Start sleep cycles lasting `value` seconds each                    | 0 (stop sleeping), 1-13612 |
| setOta     | `pio run -t upload --upload-port 192.168.4.1` when connected to AP |                            |
| getBattery | Ask for battery value                                              |                            |
| getSkills  | Get a list of actions the Brick responds to                        |                            |

### Outbox

| key   | description        | values            |
|-------|--------------------|-------------------|
| awake | Sent when woken up | <NAME> - <REASON> |

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
