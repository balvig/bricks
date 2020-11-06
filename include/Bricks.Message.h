#ifndef BRICKS_MESSAGE_H
#define BRICKS_MESSAGE_H

#include <Bricks.Constants.h>

namespace Bricks {
  typedef struct Message {
    char key[KEY_SIZE];
    char value[200];
  } Message;
}
#endif
