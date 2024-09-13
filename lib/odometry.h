#ifndef ODOMETRY_H
#define ODOMETRY_H

#include "constants.h"

void updateOdometry() {
  float deltaLeft = (left_ticks / (float)TICKS_PER_REVOLUTION) * WHEEL_CIRCUMFERENCE;
  float deltaRight = (right_ticks / (float)TICKS_PER_REVOLUTION) * WHEEL_CIRCUMFERENCE;
  float deltaDist = (deltaLeft + deltaRight) / 2.0;
  float deltaTheta = (deltaRight - deltaLeft) / WHEELBASE;
  x += deltaDist * cos(theta + deltaTheta / 2.0);
  y += deltaDist * sin(theta + deltaTheta / 2.0);
  theta += deltaTheta;
  left_ticks = 0;
  right_ticks = 0;
}

#endif
