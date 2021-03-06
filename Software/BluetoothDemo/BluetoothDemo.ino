// Libraries
#include <RobotDrive.h>
//#include <TB6612FNG.h>

//// Pin Definitions
//#define LEFT_MOTOR_A       2
//#define LEFT_MOTOR_B       4
//#define LEFT_MOTOR PWM     3
//
//#define RIGHT_MOTOR_A      5
//#define RIGHT_MOTOR_B      10
//#define RIGHT_MOTOR PWM    9
//
//#define STANDBY            6
//
//// Actuators
//TB6612FNG left_motor(LEFT_MOTOR_A, LEFT_MOTOR_B, LEFT_MOTOR_PWM, STANDBY);
//TB6612FNG right_motor(RIGHT_MOTOR_A, RIGHT_MOTOR_B, RIGHT_MOTOR_PWM, STANDBY);
//
//// Utilities
//RobotDrive drivetrain(&left_motor, &right_motor);

String message = "";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available()) {
    message += char(Serial.read());
  }

  if (!Serial.available()) {
    if (message != "") {
      Serial.println(message);
      message = "";
    }
  }

  delay(5000);
}
