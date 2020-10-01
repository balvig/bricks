# Recreate (WIP)

Easiest way to get up an running quickly is https://fred.sensetecnic.com/, but
if you want to host locally, take a look at the [`docker` directory](/docker).

## Parts

- [LOLIN D1 Mini](https://www.aliexpress.com/item/32529101036.html)
- [Dual Base](https://www.aliexpress.com/item/32642733925.html)
- [Battery Shield](https://www.aliexpress.com/item/32679485736.html)
- [900mAh Lipo](https://www.aliexpress.com/item/32952515649.html)
- [Accessory Shield](https://docs.wemos.cc/en/latest/d1_mini_shiled/index.html)

## Steps

### D1 Mini

- Add male headers

### Battery shield
- Connect A0 battery read jumper
- Solder male/female headers to shield
- Check battery power and `getBattery` skill using "LED" example

### Double base

- Connect D0 - RST (snip off)
- Solder shield headers to double base
- Add female headers for accessory
- Test `setSleep` by adding D1 in accessory header
- Snip off
