## Diagrams

http://www.nomnoml.com/

```
#title: gateway
#arrowSize:0.7
#lineWidth: 1
#fill: #fdf6e3; #fdf6e3

[In|
[Button Brick|00:11:22:33:44:55]-[<note>pressed]
[pressed]->[Gateway Brick]

[Gateway Brick]-[<note>/bricks/in/00:11:22:33:44:55/pressed]
[/bricks/in/00:11:22:33:44:55/pressed]->[MQTT]
]

[Out|
[MQTT]-[<note>/bricks/out/aa:bb:cc:dd:ee:ff/set: 1]
[/bricks/out/aa:bb:cc:dd:ee:ff/set: 1]->[Gateway Brick]

[Gateway Brick]-[<note>set: 1]
[set: 1]->[LED Brick|aa:bb:cc:dd:ee:ff]
]
```

---

```
#title: combine
#arrowSize:0.7
#lineWidth: 1
#fill: #fdf6e3; #fdf6e3

[Button Brick|00:11:22:33:44:55]-[<note>pressed]
[pressed]->[Gateway Brick - in]

[LED Brick|aa:bb:cc:dd:ee:ff]<-[<note>set: 1]
[set: 1]-[Gateway Brick - out]

[Gateway Brick - in]-[<note>/bricks/in/00:11:22:33:44:55/pressed]
[/bricks/in/00:11:22:33:44:55/pressed]->[MQTT]

[Gateway Brick - out]<-[<note>/bricks/out/aa:bb:cc:dd:ee:ff/set: 1]
[/bricks/out/aa:bb:cc:dd:ee:ff/set: 1]-[MQTT]
```

---

```
#title: mqtt
#arrowSize:0.7
#lineWidth: 1
#direction: right
#fill: #fdf6e3; #fdf6e3

[<note>bricks/in/00:11:22:33:44:55/pressed]->[<note>bricks/out/aa:bb:cc:dd:ee:ff/set: 1]
[<note>bricks/in/00:11:22:33:44:55/released]->[<note>bricks/out/aa:bb:cc:dd:ee:ff/set: 0]
```

---

```
#title: gateway
#arrowSize:0.7
#lineWidth: 1
#fill: #fdf6e3; #fdf6e3


[Internet]<-[<label> MQTT]
[MQTT]->[Gateway]

[Gateway]<-[<label> ESP-NOW]
[ESP-NOW]->[LED|set]
[ESP-NOW]->[8x8 Matrix|set]
[ESP-NOW]->[Button|pressed/released]
[ESP-NOW]->[Buzzer|play]
[ESP-NOW]->[Sensor|status]
```
