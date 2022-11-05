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

| in      | out         | description                                                        | values                                     |
|---------|-------------|--------------------------------------------------------------------|--------------------------------------------|
| sleep   | ack:sleep   | Sleep for  `value` seconds each                                    | 0 (forever), 1-10800                       |
| ota     | ack:ota     | `pio run -t upload --upload-port 192.168.4.1` when connected to AP | "Connect to 'Brick - OTA'"                 |
| battery | ack:battery | Ask for battery value                                              | 0 - 950                                    |
| skills  | ack:skills  | Get a list of actions the Brick responds to                        | "version ota skills battery sleep"         |
| version | ack:version | Get commit hash                                                    | "544d5953eeabf913dedb432103b736b9837cf71b" |
|         | awake       | Sent when woken up                                                 | "LED - wake up from deep-sleep" etc        |
