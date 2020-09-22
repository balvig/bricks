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

| key            | description                                                        | values                     |
|----------------|--------------------------------------------------------------------|----------------------------|
| out/setSleep   | Start sleep cycles lasting `value` seconds each                    | 0 (stop sleeping), 1-13612 |
| out/setOta     | `pio run -t upload --upload-port 192.168.4.1` when connected to AP |                            |
| out/getBattery | Ask for battery value                                              |                            |
| out/getSkills  | Get a list of actions the Brick responds to                        |                            |
| in/awake       | Sent when woken up                                                 | <NAME> - <REASON>          |

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
