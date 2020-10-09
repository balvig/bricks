// Bricks
#include <Bricks.Brick.h>
using namespace Bricks;

// Local
#include <Song.h>
#include <songs.h>
const int BUZZER = D5;

Song *song;

// Bricks callbacks
void cueSong(BRICKS_CALLBACK_SIGNATURE) {
  const int songNumber = atoi(message.value);
  song = &songs[songNumber];
}

void playSong() {
  for (int thisNote = 0; thisNote < song->length; thisNote++) {
    const int noteDuration = 1000 / song->timings[thisNote];
    const int pauseBetweenNotes = noteDuration * 1.30;

    tone(BUZZER, song->melody[thisNote], noteDuration);
    delay(pauseBetweenNotes);
  }

  song = nullptr;
}

void setup() {
  // Logging
  Serial.begin(115200);
  Log.begin(LOG_LEVEL_NOTICE, &Serial);

  // Configure buzzer
  pinMode(BUZZER, OUTPUT);

  // Configure Brick
  gBrick.init("Buzzer");
  gBrick.skills[0] = new Skill("play", &cueSong);
}

void loop() {
  if(song) {
    playSong();
  }
  gBrick.loop();
}
