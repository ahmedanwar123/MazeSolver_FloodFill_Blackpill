#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <Wire.h>

// Constants for robot geometry and encoders
#define WHEEL_DIAMETER 0.05
#define WHEEL_CIRCUMFERENCE (WHEEL_DIAMETER * 3.14159)
#define TICKS_PER_REVOLUTION 360
#define WHEELBASE 0.15
#define GRID_SIZE 16
#define MPU_ADDR 0x68
#define ULTRASONIC_FRONT_PIN 8
#define ULTRASONIC_LEFT_PIN 9
#define ULTRASONIC_RIGHT_PIN 10
#define LEFT_ENCODER_PIN 2
#define RIGHT_ENCODER_PIN 3

// Motor pins
#define LEFT_MOTOR_PIN1 4
#define LEFT_MOTOR_PIN2 5
#define RIGHT_MOTOR_PIN1 6
#define RIGHT_MOTOR_PIN2 7

// Global variables
volatile int left_ticks = 0;
volatile int right_ticks = 0;
float x = 0.0, y = 0.0, theta = 0.0;
int robotX = 0, robotY = 0;
int maze[GRID_SIZE][GRID_SIZE];
int flood_fill[GRID_SIZE][GRID_SIZE];
int direction = 0;

#endif
