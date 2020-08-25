#ifndef IRCODE_H
#define IRCODE_H

typedef struct IRCode {
  const char *key;
  const uint16_t length;
  const uint16_t timings[650];
} IRCode;
#endif
