# 1 "C:\\Users\\HP\\AppData\\Local\\Temp\\tmp1mm_o30a"
#include <Arduino.h>
# 1 "C:/Users/HP/Documents/PlatformIO/Projects/Nezumi2.1-blackpill_f401cc/src/nezumi_2.1.ino"
#include "../lib/motor_control.h"
#include "../lib/maze.h"
void setup();
void leftEncoderISR();
void rightEncoderISR();
void loop();
#line 4 "C:/Users/HP/Documents/PlatformIO/Projects/Nezumi2.1-blackpill_f401cc/src/nezumi_2.1.ino"
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