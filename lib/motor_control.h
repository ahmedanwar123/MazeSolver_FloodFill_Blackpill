#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include "constants.h"
#include "odometry.h"
void turnRobot(float angle) {
  float turnTime = fabs(angle) / (PI / 2);
  analogWrite(LEFT_MOTOR_PIN1, angle > 0 ? 255 : 0);
  analogWrite(LEFT_MOTOR_PIN2, angle > 0 ? 0 : 255);
  analogWrite(RIGHT_MOTOR_PIN1, angle > 0 ? 0 : 255);
  analogWrite(RIGHT_MOTOR_PIN2, angle > 0 ? 255 : 0);
  delay(turnTime * 1000);  // Turn for calculated time
  updateOdometry();
}
void moveRobot(int direction) {
  switch (direction) {
    case 0:  // Move forward
      analogWrite(LEFT_MOTOR_PIN1, 255);
      analogWrite(LEFT_MOTOR_PIN2, 0);
      analogWrite(RIGHT_MOTOR_PIN1, 255);
      analogWrite(RIGHT_MOTOR_PIN2, 0);
      delay(1000);  // Move forward for 1 second
      updateOdometry();
      break;

    case 1:  // Turn right
      turnRobot(90);
      break;

    case 2:  // Move backward
      analogWrite(LEFT_MOTOR_PIN1, 0);
      analogWrite(LEFT_MOTOR_PIN2, 255);
      analogWrite(RIGHT_MOTOR_PIN1, 0);
      analogWrite(RIGHT_MOTOR_PIN2, 255);
      delay(1000);  // Move backward for 1 second
      updateOdometry();
      break;

    case 3:  // Turn left
      turnRobot(-90);
      break;
  }
}


#endif
