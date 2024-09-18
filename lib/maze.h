#ifndef MAZE_H
#define MAZE_H

#include "constants.h"
#include "sensors.h"
#include "motor_control.h"
void initializeFloodFill() {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      flood_fill[i][j] = GRID_SIZE * GRID_SIZE;
    }
  }
  flood_fill[GRID_SIZE / 2][GRID_SIZE / 2] = 0;
}

void updateMazeWalls() {
  float leftDistance = readUltrasonicDistance(ULTRASONIC_LEFT_TRIG, ULTRASONIC_LEFT_ECHO);
  float frontDistance = readUltrasonicDistance(ULTRASONIC_FRONT_TRIG, ULTRASONIC_FRONT_ECHO);
  float rightDistance = readUltrasonicDistance(ULTRASONIC_RIGHT_TRIG, ULTRASONIC_RIGHT_ECHO);

  // Check the robot’s current position in the maze and update the walls accordingly
  if (frontDistance < 4) {
    maze[robotX][robotY] |= 0x01;  // Front wall
  }
  if (rightDistance < 4) {
    maze[robotX][robotY] |= 0x02;  // Right wall
  }
  if (leftDistance < 4) {
    maze[robotX][robotY] |= 0x04;  // Left wall
  }
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
    direction = 0;  // Move Left
  } else if (robotX < GRID_SIZE - 1 && flood_fill[robotX + 1][robotY] < min_value) {
    direction = 2;  // Move Right
  } else if (robotY > 0 && flood_fill[robotX][robotY - 1] < min_value) {
    direction = 3;  // Move Backward
  } else if (robotY < GRID_SIZE - 1 && flood_fill[robotX][robotY + 1] < min_value) {
    direction = 1;  // Move Forward
  }
}

#endif
