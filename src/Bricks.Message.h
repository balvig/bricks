#ifndef BRICKS_MESSAGE_H
#define BRICKS_MESSAGE_H

namespace Bricks {
  typedef struct Message {
    char key[20];
    char value[200];
  } Message;
}
#endif
