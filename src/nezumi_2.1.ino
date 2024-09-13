#include "../lib/motor_control.h"
#include "../lib/maze.h"

void setup() {
  Serial.begin(9600);
  Wire.begin();

  pinMode(LEFT_ENCODER_PIN, INPUT_PULLUP);
  pinMode(RIGHT_ENCODER_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(LEFT_ENCODER_PIN), leftEncoderISR, RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_ENCODER_PIN), rightEncoderISR, RISING);

  pinMode(LEFT_MOTOR_PIN1, OUTPUT);
  pinMode(LEFT_MOTOR_PIN2, OUTPUT);
  pinMode(RIGHT_MOTOR_PIN1, OUTPUT);
  pinMode(RIGHT_MOTOR_PIN2, OUTPUT);

  initializeFloodFill();
}
void leftEncoderISR() {
  left_ticks++;
}

void rightEncoderISR() {
  right_ticks++;
}

void loop() {
  updateFloodFill();
  chooseNextMove();
  moveRobot();
  delay(500);
}
