## Diagrams

http://www.nomnoml.com/

```
#title: gateway
#arrowSize:0.7
#lineWidth: 1
#fill: transparent; #fdf6e3

[In|
[Button Brick]-[<note>pressed]
[pressed]->[Gateway Brick]

[Gateway Brick]-[<note>/bricks/in/$MAC/pressed]
[/bricks/in/$MAC/pressed]->[MQTT]
]

[Out|
[MQTT]-[<note>/bricks/out/$MAC/setPattern: 1]
[/bricks/out/$MAC/setPattern: 1]->[Gateway Brick]

[Gateway Brick]-[<note>setPattern: 1]
[setPattern: 1]->[LED Brick]
]
```

---

```
#title: combine
#arrowSize:0.7
#lineWidth: 1

[Button Brick]-[<note>pressed]
[pressed]->[Gateway Brick]

[LED Brick]<-[<note>setPattern: 1]
[setPattern: 1]-[Gateway Brick]

[Gateway Brick]-[<note>/bricks/in/$MAC/pressed]
[/bricks/in/$MAC/pressed]->[MQTT]

[Gateway Brick]<-[<note>/bricks/out/$MAC/setPattern: 1]
[/bricks/out/$MAC/setPattern: 1]-[MQTT]
```

---

```
#title: mqtt
#arrowSize:0.7
#lineWidth: 1
#direction: right

[<note>bricks/in/ee:fa:bc:8e:89:1e/pressed]->[<note>bricks/out/ee:fa:bc:8e:89:8f/setPattern: 1]
[<note>bricks/in/ee:fa:bc:8e:89:1e/released]->[<note>bricks/out/ee:fa:bc:8e:89:8f/setPattern: 0]
```
