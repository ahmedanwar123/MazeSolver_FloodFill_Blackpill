#ifndef ODOMETRY_H
#define ODOMETRY_H

#include "constants.h"
#include "maze.h"

void updateOdometry() {
  float deltaLeft = (left_ticks / (float)TICKS_PER_REVOLUTION) * WHEEL_CIRCUMFERENCE;
  float deltaRight = (right_ticks / (float)TICKS_PER_REVOLUTION) * WHEEL_CIRCUMFERENCE;
  float deltaDist = (deltaLeft + deltaRight) / 2.0;
  float deltaTheta = (deltaRight - deltaLeft) / WHEELBASE;

  // Calculate new robot position
  x += deltaDist * cos(theta + deltaTheta / 2.0);
  y += deltaDist * sin(theta + deltaTheta / 2.0);
  theta += deltaTheta;

  // Check if robot has moved a full cell (e.g., 10 cm)
  if (deltaDist >= CELL_SIZE) {  // Assuming CELL_SIZE is defined as the size of a cell in meters (0.10 for 10 cm)
    left_ticks = 0;
    right_ticks = 0;
    
    // Update the robot's logical position in the grid
    if (direction == 0) robotX--;
    else if (direction == 2) robotX++;
    else if (direction == 3) robotY++;
    
    // Update the flood fill based on the new position
    updateFloodFill();
  }
}


#endif
