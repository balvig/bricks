# LED - RGB

For https://docs.wemos.cc/en/latest/d1_mini_shiled/rgb_led.html

## Hardware prep

- Cut SJ3 jumper (disconnect D4 from LEDs)
- Connect D2

## Skills

| in  | out     | description                          | values             |
|-----|---------|--------------------------------------|--------------------|
| set | ack:set | Set LED "<PATTERN> <VALUE> <UPDATE>" | 0..4,0..255,0..255 |
