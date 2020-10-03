#ifndef IRCODE_H
#define IRCODE_H

typedef struct IRcode {
  const char *key;
  const uint16_t length;
  const uint16_t timings[650];
} IRcode;
#endif
