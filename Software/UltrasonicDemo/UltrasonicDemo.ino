// Libraries
#include <RobotDrive.h>
#include <TB6612FNG.h>
#include <Ultrasonic.h>

// Pin Definitions
#define LEFT_MOTOR_A       2
#define LEFT_MOTOR_B       4
#define LEFT_MOTOR PWM     3

#define RIGHT_MOTOR_A      5
#define RIGHT_MOTOR_B      10
#define RIGHT_MOTOR PWM    9

#define STANDBY            6

#define ULTRASONIC_ECHO    10
#define ULTRASONIC_TRIG    11

// Config Constants
#define SPEED_SCALE_FACTOR 0.25
#define TARGET_DISTANCE    3
#define DISTANCE_TOLERANCE 0.1

// Actuators
TB6612FNG left_motor(LEFT_MOTOR_A, LEFT_MOTOR_B, LEFT_MOTOR_PWM, STANDBY);
TB6612FNG right_motor(RIGHT_MOTOR_A, RIGHT_MOTOR_B, RIGHT_MOTOR_PWM, STANDBY);

// Sensors
Ultrasonic distance_sensor(ULTRASONIC_ECHO, ULTRASONIC_TRIG, true);

// Utilities
RobotDrive drivetrain(&left_motor, &right_motor);

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  if (distance_sensor.getDistance() > (TARGET_DISTANCE + DISTANCE_TOLERANCE)) {
    drivetrain.arcadeDrive(1.0 * SPEED_SCALE_FACTOR, 0.0);
  } else if (distance_sensor.getDistance() < (TARGET_DISTANCE - DISTANCE_TOLERANCE)) {
    drivetrain.arcadeDrive(-1.0 * SPEED_SCALE_FACTOR, 0.0);
  } else {
    drivetrain.arcadeDrive(0.0, 0.0);
  }
  
  delay(10);
}
