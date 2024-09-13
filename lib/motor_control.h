#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include "constants.h"
#include "sensors.h"
#include "odometry.h"

void moveRobot() {
  float frontDistance = readUltrasonicDistance(ULTRASONIC_FRONT_PIN);
  if (frontDistance > 10) {
    analogWrite(LEFT_MOTOR_PIN1, 255);
    analogWrite(LEFT_MOTOR_PIN2, 0);
    analogWrite(RIGHT_MOTOR_PIN1, 255);
    analogWrite(RIGHT_MOTOR_PIN2, 0);
    delay(1000);
    analogWrite(LEFT_MOTOR_PIN1, 0);
    analogWrite(LEFT_MOTOR_PIN2, 0);
    analogWrite(RIGHT_MOTOR_PIN1, 0);
    analogWrite(RIGHT_MOTOR_PIN2, 0);
    updateOdometry();
  }
}

void turnRobot(float angle) {
  float turnTime = fabs(angle) / (PI / 2);
  analogWrite(LEFT_MOTOR_PIN1, angle > 0 ? 255 : 0);
  analogWrite(LEFT_MOTOR_PIN2, angle > 0 ? 0 : 255);
  analogWrite(RIGHT_MOTOR_PIN1, angle > 0 ? 0 : 255);
  analogWrite(RIGHT_MOTOR_PIN2, angle > 0 ? 255 : 0);
  delay(turnTime * 1000);
}

#endif
