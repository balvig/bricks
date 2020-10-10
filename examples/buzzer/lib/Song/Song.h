#ifndef SONG_H
#define SONG_H

typedef struct Song {
  const int length;
  const int melody[100];
  const int timings[100];
} Song;
#endif
