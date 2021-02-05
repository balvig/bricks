const uint8_t fireworksFrames[][GRID_SIZE] = {
  {
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000
  },{
    B00000000,
    B00000000,
    B00000000,
    B00011000,
    B00011000,
    B00000000,
    B00000000,
    B00000000
  },{
    B00000000,
    B00000000,
    B00111100,
    B00100100,
    B00100100,
    B00111100,
    B00000000,
    B00000000
  },{
    B00000000,
    B01111110,
    B01000010,
    B01000010,
    B01000010,
    B01000010,
    B01111110,
    B00000000
  },{
    B11111111,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B11111111
  }
};

const uint8_t scanFrames[][GRID_SIZE] = {
  {
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000
  },{
    B00000000,
    B00000000,
    B00000000,
    B10000000,
    B10000000,
    B00000000,
    B00000000,
    B00000000
  },{
    B00000000,
    B00000000,
    B00000000,
    B11000000,
    B11000000,
    B00000000,
    B00000000,
    B00000000
  },{
    B00000000,
    B00000000,
    B00000000,
    B01100000,
    B01100000,
    B00000000,
    B00000000,
    B00000000
  },{
    B00000000,
    B00000000,
    B00000000,
    B00110000,
    B00110000,
    B00000000,
    B00000000,
    B00000000
  },{
    B00000000,
    B00000000,
    B00000000,
    B00011000,
    B00011000,
    B00000000,
    B00000000,
    B00000000
  },{
    B00000000,
    B00000000,
    B00000000,
    B00001100,
    B00001100,
    B00000000,
    B00000000,
    B00000000
  },{
    B00000000,
    B00000000,
    B00000000,
    B00000110,
    B00000110,
    B00000000,
    B00000000,
    B00000000
  },{
    B00000000,
    B00000000,
    B00000000,
    B00000011,
    B00000011,
    B00000000,
    B00000000,
    B00000000
  },{
    B00000000,
    B00000000,
    B00000000,
    B00000001,
    B00000001,
    B00000000,
    B00000000,
    B00000000
  }};

const uint8_t spinnerFrames[][GRID_SIZE] = {
  {
    B00000000,
    B00000000,
    B00000000,
    B00010000,
    B00000000,
    B00000000,
    B00000000,
    B00000000
  },{
    B00000000,
    B00000000,
    B00000000,
    B00001000,
    B00000000,
    B00000000,
    B00000000,
    B00000000
  },{
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00001000,
    B00000000,
    B00000000,
    B00000000
  },{
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00010000,
    B00000000,
    B00000000,
    B00000000
  }};

extern const uint8_t (*fireworks)[GRID_SIZE] = fireworksFrames;
extern const uint8_t fireworksSize = sizeof(fireworksFrames) / sizeof(fireworksFrames[0]);
extern const uint8_t (*scan)[GRID_SIZE] = scanFrames;
extern const uint8_t scanSize = sizeof(scanFrames) / sizeof(scanFrames[0]);
extern const uint8_t (*spinner)[GRID_SIZE] = spinnerFrames;
extern const uint8_t spinnerSize = sizeof(spinnerFrames) / sizeof(spinnerFrames[0]);
