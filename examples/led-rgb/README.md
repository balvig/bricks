# LED - RGB

For https://docs.wemos.cc/en/latest/d1_mini_shiled/rgb_led.html

## Hardware prep

- Cut SJ3 jumper (disconnect D4 from LEDs)
- Connect D2

## Skills

| key              | description                           | values                          |
|------------------|---------------------------------------|---------------------------------|
| out/setPattern   | Change LED pattern                    | 0 (off), 1 (on), 2-4 (patterns) |
| out/setVariation | Set pattern variation (usually color) | 0-255                           |
| out/setDelay     | Set speed of pattern                  | 0-255                           |
