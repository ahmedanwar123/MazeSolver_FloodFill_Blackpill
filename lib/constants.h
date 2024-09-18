#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <Wire.h>

// Constants for robot geometry and encoders
#define WHEEL_DIAMETER 0.06
#define WHEEL_CIRCUMFERENCE (WHEEL_DIAMETER * 3.14159)
#define TICKS_PER_REVOLUTION 360
#define WHEELBASE 0.15
#define GRID_SIZE 16
#define MPU_ADDR 0x68
#define CELL_SIZE 1
// Ultrasonic pins
#define ULTRASONIC_LEFT_TRIG 2
#define ULTRASONIC_LEFT_ECHO 3
#define ULTRASONIC_FRONT_TRIG 4
#define ULTRASONIC_FRONT_ECHO 5
#define ULTRASONIC_RIGHT_TRIG 6
#define ULTRASONIC_RIGHT_ECHO 7

// Encoder pins (A and B for each encoder)
#define LEFT_ENCODER_PIN_A 8
#define LEFT_ENCODER_PIN_B 9
#define RIGHT_ENCODER_PIN_A 10
#define RIGHT_ENCODER_PIN_B 11

// Motor pins
#define LEFT_MOTOR_PIN1 12
#define LEFT_MOTOR_PIN2 13
#define RIGHT_MOTOR_PIN1 14
#define RIGHT_MOTOR_PIN2 15

// Global variables
volatile int left_ticks = 0;
volatile int right_ticks = 0;
float x = 0.0, y = 0.0, theta = 0.0;
int robotX = 0, robotY = 0;
int maze[GRID_SIZE][GRID_SIZE];
int flood_fill[GRID_SIZE][GRID_SIZE];
int direction = 0;

#endif
