#include <Matrix.Graph.h>

namespace Matrix {
  Graph::Graph(MLED &matrix) : matrix(matrix) {}

  void Graph::update(const uint8_t progress) {
    if(played) { return; }
    if(progress == 0) { matrix.clear(); }
    if(progress >= PROGRESS_MAX) { played = true; }

    int values[8];
    int pixelsPainted = 0;
    currentPixel = progress / PIXEL_SIZE;

    sscanf(currentValue, "%u,%u,%u,%u,%u,%u,%u,%u", &values[0], &values[1], &values[2], &values[3], &values[4], &values[5], &values[6], &values[7]);

    for (int x = 0; x < GRID_SIZE; x++) {
      int topY = values[x];

      for(int y = 1; y <= GRID_SIZE; y++) {
        if (pixelsPainted <= currentPixel && y <= topY) {
          matrix.drawPixel(x, GRID_SIZE - y, 1);
          matrix.writeDisplay();
        }
        pixelsPainted++;
      }
    }
  }
}
