/*
  TeleopRobotDemo

  Controls a 2-motor drivetrain (default using an L298N Motor Driver). It will be controlled with a game controller

  It is important to note that the drivetrain class can use any child of the SpeedController class.
  For the L298N, the ports must be PWM ports.

  modified 2 Mar 2018
  by Nam Tran

  This example code is in the public domain.
*/

#include <TB6612FNG.h>
#include <RobotDrive.h>
#include <Gamepad.h>

// Left motor ports
#define MOTOR_L_A    4
#define MOTOR_L_B    2
#define MOTOR_L_PWM  3

// Right motor ports
#define MOTOR_R_A    5
#define MOTOR_R_B    10
#define MOTOR_R_PWM  9

#define STANDBY      6

// Bluetooth ports
#define BLUETOOTH_RX 7
#define BLUETOOTH_TX 8

// Variable settings for behaviour
#define MOTOR_SPEED 0.5
#define MOVE_DELAY  2000
#define DEADBAND    0.3

// motors for the drivetrain
TB6612FNG motor_left(MOTOR_L_A, MOTOR_L_B, MOTOR_L_PWM, STANDBY);
TB6612FNG motor_right(MOTOR_R_A, MOTOR_R_B, MOTOR_R_PWM, STANDBY);

// RobotDrive class that comes with most needed drivetrain functions
RobotDrive drivetrain(&motor_left, &motor_right);

Gamepad gamepad(BLUETOOTH_RX, BLUETOOTH_TX);

// the setup function runs once when you press reset or power the board
void setup() {
  // Starts the gamepad reading
  gamepad.begin();
  gamepad.set_deadband(DEADBAND);
}

// the loop function runs over and over again forever
void loop() {
  // Reads game controller bluetooth input
  gamepad.read_gamepad();

  // Controlling the robot movement
  drivetrain.arcadeDrive(-gamepad.get_axis(1), gamepad.get_axis(2));
  
  delay(10);
}
