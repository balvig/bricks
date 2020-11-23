# IR Controller

Sends IR codes predefined in `codes.h`.
Run with serial monitor to capture and transcribe IR codes.

## Skills

| in   | out      | description                      | values |
|------|----------|----------------------------------|--------|
| send | ack:send | Send predefined IR Code          | 0-9    |
|      | received | HEX code for received IR message | 0x.... |
