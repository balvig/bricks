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

| in      | out         | description                                                                 | values                          |
|---------|-------------|-----------------------------------------------------------------------------|---------------------------------|
| sleep   | ack:sleep   | Start sleep cycles `value` seconds each                                     | -1 (stop), 0 (forever), 1-13612 |
| ota     | ack:ota     | `pio run -t upload --upload-port 192.168.4.1` when connected to AP          |                                 |
| battery | ack:battery | Ask for battery value                                                       |                                 |
| skills  | ack:skills  | Get a list of actions the Brick responds to                                 |                                 |
| version | ack:version | Get commit hash                                                             |                                 |
|         | awake       | Sent when woken up                                                          | <NAME> - <REASON>               |
|         | sleeping    | Sent when resuming sleep after 2 seconds of being awake during sleep cycles |                                 |
