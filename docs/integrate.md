# Integrate

The Bricks Arduino library can be used as the foundation for any ESP-based IoT project.

You will need to first set up a gateway as [described elsewhere](/docs/create.md).
Once that is in place, internet-enabling ESP projects by creating "skills" is a breeze.

The absolute bare bones for a Brick looks like this:

```c++
#include <Bricks.Brick.h>
using namespace Bricks;

void setup() {
  gBrick.initBase();
}

void loop() {
  gBrick.loop();
}
```

Creating a skill is a simple as picking a keyword and associating a method with it:

```c++
#include <Bricks.Brick.h>
using namespace Bricks;

void hello(BRICKS_CALLBACK_SIGNATURE) {
  Serial.print("Message received: ");
  Serial.println(message.value);
}

void setup() {
  gBrick.initBase();
  gBrick.skills[0] = new Skill("hello", &hello);
}

void loop() {
  gBrick.loop();
}
```

You can now trigger this skill by sending messages via MQTT and the gateway:

```mqtt
/bricks/out/<MAC ADDRESS>/hello
hi!
```

The Brick will acknowledge that it received and understood the message:

```mqtt
/bricks/in/<MAC ADDRESS>/ack:hello
hi!
```

If you want to respond with a particular value (for example for sensor readings), you can set the `response` variable
in the skill method:

```c++
void hello(BRICKS_CALLBACK_SIGNATURE) {
  strcpy(response, "Hello there");
}
```

```mqtt
/bricks/in/<MAC ADDRESS>/ack:hello
Hello there
```

Using `init()` instead of `initBase()` automatically adds [a base set of skills](/examples#common-skills):


```c++
void setup() {
  gBrick.init("My Brick");
}
```
