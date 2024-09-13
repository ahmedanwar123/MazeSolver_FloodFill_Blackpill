# Robot Maze Solver with Ultrasonic Sensors, MPU6050, and Encoders using Flood Fill Algorithm

This repository contains the firmware and control logic for a maze-solving robot that uses three ultrasonic sensors for wall detection, encoders for odometry, and implements the **Flood Fill Algorithm** to navigate through a 16x16 maze.

The project is built using the Arduino IDE and runs on an STM32F4-based Blackpill development board.

## Features
- **Ultrasonic Sensors**: Three ultrasonic sensors detect walls in front and on the sides of the robot.
- **Encoders**: Dual motor encoders track the robot's movement and update its odometry.
- **Flood Fill Algorithm**: The robot navigates through a maze using the flood fill algorithm to find the optimal path.
- **Interrupt-Driven Encoders**: Encoders use interrupt service routines (ISRs) to accurately count wheel rotations.
- **Modular Codebase**: The project is split into multiple modules for sensors, odometry, motor control, and maze-solving logic.

## Project Structure
- `nezumi_2.1.ino`: Main file for the program. Initializes the robot and executes the main loop for movement and maze-solving.
- `motor_control.h`: Contains functions for controlling the robot's movement and motor speed.
- `sensors.h`: Handles ultrasonic sensor readings for wall detection.
- `odometry.h`: Provides functionality to track and update the robot’s position based on encoder feedback.
- `maze.h`: Implements the flood fill algorithm for maze navigation.

## Hardware Setup
- **Microcontroller**: STM32F401 Blackpill (Using the Arduino IDE).
- **Motors**: Two DC motors with encoders for tracking wheel rotations.
- **Ultrasonic Sensors**: Three sensors (front, left, right) for detecting walls.
- **Motor Driver**: A dual-channel motor driver to control motor speed and direction.
- **Power Supply**: Suitable power source for motors and the STM32F4 board.

### Pin Configuration
| Component         | Pin               | Description                    |
|-------------------|-------------------|--------------------------------|
| Left Encoder       | `LEFT_ENCODER_PIN`  | Interrupt pin for left wheel encoder. |
| Right Encoder      | `RIGHT_ENCODER_PIN` | Interrupt pin for right wheel encoder. |
| Ultrasonic Front   | `ULTRASONIC_FRONT_PIN` | Front ultrasonic sensor.       |
| Ultrasonic Left    | `ULTRASONIC_LEFT_PIN`  | Left ultrasonic sensor.        |
| Ultrasonic Right   | `ULTRASONIC_RIGHT_PIN` | Right ultrasonic sensor.       |
| Left Motor Control | `LEFT_MOTOR_PIN1`, `LEFT_MOTOR_PIN2` | Motor driver pins for the left motor. |
| Right Motor Control| `RIGHT_MOTOR_PIN1`, `RIGHT_MOTOR_PIN2`| Motor driver pins for the right motor.|

## Software Setup

### Prerequisites
- **Arduino IDE**: Ensure you have the STM32F4 board package installed.
- **Libraries**: 
  - Wire.h for I2C communication.
  - Standard Arduino libraries for serial communication and interrupts.

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/robot-maze-solver.git
   ```
2. Open `main.ino` in the Arduino IDE.
3. Connect your STM32F401 Blackpill to your computer via USB.
4. Select the appropriate board and port in the Arduino IDE.
5. Click the "Upload" button to flash the firmware onto the microcontroller.

## Usage
Once the firmware is uploaded:
1. Place the robot in the maze.
2. The robot will start detecting walls and begin moving based on the flood fill algorithm.
3. Ultrasonic sensors detect walls and make decisions on turning left, right, or going straight.
4. Encoders track wheel rotations and update the robot’s odometry to ensure precise movements.

## File Descriptions

- **`main.ino`**: 
  - Contains the main loop and setup functions that initialize the encoders, ultrasonic sensors, and motors. The loop runs the maze-solving algorithm.
  
- **`motor_control.h`**: 
  - Contains the `moveRobot()` function responsible for moving the robot forward based on the distance measured by ultrasonic sensors.
  
- **`sensors.h`**:
  - Contains the `readUltrasonicDistance()` function, which takes readings from the ultrasonic sensors to detect walls.
  
- **`odometry.h`**:
  - Defines the `updateOdometry()` function to update the robot’s position based on encoder ticks.
  
- **`maze.h`**:
  - Implements the flood fill algorithm and provides functions to navigate through the maze.
