# LED - RGB

For https://docs.wemos.cc/en/latest/d1_mini_shiled/rgb_led.html

## Hardware prep

- Cut SJ3 jumper (disconnect D4 from LEDs)
- Connect D2

## Inbox

| key          | description                           | values                          |
|--------------|---------------------------------------|---------------------------------|
| setPattern   | Change LED pattern                    | 0 (off), 1 (on), 2-4 (patterns) |
| setVariation | Set pattern variation (usually color) | 0-255                           |
| setDelay     | Set speed of pattern                  | 0-255                           |
