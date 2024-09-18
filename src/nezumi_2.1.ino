#include "motor_control.h"
#include "maze.h"
#include "constants.h"

void leftEncoderISR() {
  // Determine direction based on the state of the second hall sensor (B)
  if (digitalRead(LEFT_ENCODER_PIN_A) == digitalRead(LEFT_ENCODER_PIN_B)) {
    left_ticks++;  // Moving forward
  } else {
    left_ticks--;  // Moving backward
  }
}

void rightEncoderISR() {
  // Determine direction based on the state of the second hall sensor (B)
  if (digitalRead(RIGHT_ENCODER_PIN_A) == digitalRead(RIGHT_ENCODER_PIN_B)) {
    right_ticks++;  // Moving forward
  } else {
    right_ticks--;  // Moving backward
  }
}

void setup() {
  Serial.begin(9600);
  Wire.begin();

  pinMode(LEFT_ENCODER_PIN_A, INPUT_PULLUP);
  pinMode(LEFT_ENCODER_PIN_B, INPUT_PULLUP);
  pinMode(RIGHT_ENCODER_PIN_A, INPUT_PULLUP);
  pinMode(RIGHT_ENCODER_PIN_B, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(LEFT_ENCODER_PIN_A), leftEncoderISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(RIGHT_ENCODER_PIN_A), rightEncoderISR, CHANGE);

  pinMode(LEFT_MOTOR_PIN1, OUTPUT);
  pinMode(LEFT_MOTOR_PIN2, OUTPUT);
  pinMode(RIGHT_MOTOR_PIN1, OUTPUT);
  pinMode(RIGHT_MOTOR_PIN2, OUTPUT);

  initializeFloodFill();
}

void loop() {
  // Update the maze walls after every movement and sensor read
  updateMazeWalls();
  
  updateFloodFill();
  chooseNextMove();
  moveRobot(direction);  // Move the robot based on chosen direction
  delay(500);
}
