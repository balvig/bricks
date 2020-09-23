<h1><img src=logo.svg height=50 alt=Bricks></h1>

Casual IoT tinkering and DIY for people who love modern programming languages.

**NOTE:** This project is _heavily_ WIP.

## What is Bricks?

I come up with dumb gadget ideas all the time.

"Wouldn't it be cool if a light goes on when I take my keys out of the
key tray or if a message is posted to the coffee chat whenever I put the
kettle on?"

They're fun for a while, add spice to everyday life, and maybe even
inspire _actual_ useful ideas, but mostly are disposable one-offs.

I'm a developer by profession, but spending days writing C++, flashing
microcontrollers, soldering custom PCBs, and building enclosures for
what are essentially throwaway projects always felt a little harder than it should.

That led to the idea of building a suite of pre-programmed IoT "Bricks".

Individual LEDs, buttons, sensors, that could be pulled out when needed, were all internet-enabled,
and whose behavior could easily be programmed ad hoc using modern program
languages such as Ruby or JavaScript.

You could say Bricks is [Sony Mesh](https://meshprj.com/) without the hefty price tag,
running entirely on existing Arduino-compatible hardware and open source software,
and made for people who already know how to code.

## How to use Bricks?

This repository contains all the info required to build a collection of Bricks.

Depending on your needs, it could be used to:

- [**Create** Bricks using any ESP8266/ESP32s you have and the examples found in this library.](docs/create.md)
- [**Integrate** just the C++ library to easily internet-enable your own ESP8266/ESP32 projects.](docs/integrate.md)
- [**Recreate** the full original suite of Bricks including Node-RED flows, hardware, and enclosures.](docs/recreate.md)

## Todo

### Software

- [ ] Turn "setRotation" into a skill instead for LED Matrix
- [ ] TravisCI
- [ ] "Dash button" implementation that won't trigger when ESP8266 wakes up for other reasons

#### Nice to haves
- [ ] Move `logMac` to utils
- [ ] Consolidate `gOutbox` into `gBrick`?
- [ ] Consolidate `gEvents` into `publishSkill`?
- [ ] Consider using `qos=1` for sending messages
- [ ] Fix errors raised by `pio check` (mainly passing `Message` by value)
- [ ] Write up making a brick
- [ ] Allow BLE scanner to subscribe to beacon notifications
- [ ] More tests
- [ ] Make aliexpress ble button send notifications
- [ ] Idea: Move sender macAddr into message to reduce params? Or maybe leave out entirely?
- [ ] ESP32 suffers from random brownouts on boot. Should sleep care about reset reason?

### Hardware

- [ ] Find a way to make use of battery connector instead of soldering
- [ ] Wooden panels
- [ ] Sturdier PCB attachment
- [ ] Nicer stickers
- [ ] Reset Button
- [ ] Try out [Wemos D1 hack](https://www.youtube.com/watch?v=rfPwOtoGO4E)
