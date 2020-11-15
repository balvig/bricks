# Brick Examples

- [Gateway](gateway)
- [Button](button)
- [Dash Button](button-dash)
- [LED](led)
- [LED RGB](led-rgb)
- [LED 8x8 Matrix](led-matrix)
- [BLE Scanner](ble)
- [IR Controller](ir)
- [PIR Sensor](pir)

## Common skills

| key         | description                                                        | values                     |
|-------------|--------------------------------------------------------------------|----------------------------|
| out/sleep   | Start sleep cycles lasting `value` seconds each                    | 0 (stop sleeping), 1-13612 |
| out/ota     | `pio run -t upload --upload-port 192.168.4.1` when connected to AP |                            |
| out/battery | Ask for battery value                                              |                            |
| out/skills  | Get a list of actions the Brick responds to                        |                            |
| in/awake    | Sent when woken up                                                 | <NAME> - <REASON>          |
