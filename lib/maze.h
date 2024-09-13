#ifndef MAZE_H
#define MAZE_H

#include "constants.h"

void initializeFloodFill() {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      flood_fill[i][j] = GRID_SIZE * GRID_SIZE;
    }
  }
  flood_fill[GRID_SIZE / 2][GRID_SIZE / 2] = 0;
}

void updateFloodFill() {
  bool updated;
  do {
    updated = false;
    for (int i = 0; i < GRID_SIZE; i++) {
      for (int j = 0; j < GRID_SIZE; j++) {
        if (maze[i][j] == 0) {
          int min_val = flood_fill[i][j];
          if (i > 0 && flood_fill[i - 1][j] + 1 < min_val) {
            flood_fill[i][j] = flood_fill[i - 1][j] + 1;
            updated = true;
          }
          if (i < GRID_SIZE - 1 && flood_fill[i + 1][j] + 1 < min_val) {
            flood_fill[i][j] = flood_fill[i + 1][j] + 1;
            updated = true;
          }
          if (j > 0 && flood_fill[i][j - 1] + 1 < min_val) {
            flood_fill[i][j] = flood_fill[i][j - 1] + 1;
            updated = true;
          }
          if (j < GRID_SIZE - 1 && flood_fill[i][j + 1] + 1 < min_val) {
            flood_fill[i][j] = flood_fill[i][j + 1] + 1;
            updated = true;
          }
        }
      }
    }
  } while (updated);
}

void chooseNextMove() {
  int min_value = flood_fill[robotX][robotY];
  if (robotX > 0 && flood_fill[robotX - 1][robotY] < min_value) {
    direction = 0;
  } else if (robotX < GRID_SIZE - 1 && flood_fill[robotX + 1][robotY] < min_value) {
    direction = 2;
  } else if (robotY > 0 && flood_fill[robotX][robotY - 1] < min_value) {
    direction = 3;
  } else if (robotY < GRID_SIZE - 1 && flood_fill[robotX][robotY + 1] < min_value) {
    direction = 1;
  }
}

#endif
