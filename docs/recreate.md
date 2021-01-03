# Recreate (WIP)

## Building a Brick PCB

This guide shows how to build a battery-driven Brick PCB based on the ubiquitous
Wemos/LOLIN D1 Mini, that allows swapping out accessories (sensors,
buttons, LEDs etc) as/when needed.

### Parts

- [LOLIN D1 Mini](https://www.aliexpress.com/item/32529101036.html)
- [Dual Base](https://www.aliexpress.com/item/32642733925.html)
- [Battery Shield](https://www.aliexpress.com/item/32679485736.html)
- [900mAh Lipo](https://www.aliexpress.com/item/32952515649.html)
- [Accessory Shield](https://docs.wemos.cc/en/latest/d1_mini_shiled/index.html)

### Prepare D1 Mini

#### 1. Add male headers

<img src=01.jpg width=40%> <img src=02.jpg width=40%>

### Prepare Battery Shield

#### 1. Connect A0-BAT jumper

<img src=03.jpg width=40%>

#### 2. Solder male/female headers to shield

<img src=04.jpg width=40%>

#### 3. Check battery power

- Connect a battery.
- Flash the D1 Mini with the [LED example](examples/led).
- Check reading from `getBattery`.

### Assemble Dual Base

#### 1. Connect D0/16 - RST on base

<img src=05.jpg width=40%>

- Enables wake up from sleep.
- Use a cable or solder.
- Snip off any protruding ends.

#### 2. Solder shield headers to base

<img src=06.jpg width=40%>

#### 3. Test sleep wake up

- Attach D1 Mini
- Test `setSleep:5` and see if it wakes up in 5 sconds.

#### 4. Add female headers for accessory

<img src=07.jpg width=40%>

## Building a Brick case (WIP)

### Snip off headers

### Cover up header "spikes"

### Insert and connect battery

### Insert base

### Add screws

### Close lid

## Software (WIP)

Easiest way to get up an running quickly with Node-RED and MQTT is [Fred](https://fred.sensetecnic.com/) for a hosted solution, or you could use [IOTstack](https://sensorsiot.github.io/IOTstack/Getting-Started/) or the minimal [docker image](/docker) on a Raspberry Pi or other local machine.
