#include "Servo.h"
#include "Ultrasonic.h"

#define LEFTMOTOR_PIN 15
#define RIGHTMOTOR_PIN 16

Ultrasonic frontUltrasonic(28, 29, true);

Servo leftMotor;
Servo rightMotor;

void Tank_Drive(double move, double rotate) {
  double leftSpeed, rightSpeed;

 
  move = constrain(move, -1.0, 1.0);
  rotate = constrain(rotate, -1.0, 1.0);

  if (move > 0.0) {
    if (rotate > 0.0) {
      leftSpeed =  move - rotate;
      rightSpeed = max(move, rotate);
    } else {
      leftSpeed = max(move, -rotate);
      rightSpeed = move + rotate;
    }
  } else {
    if (rotate > 0.0) {
      leftSpeed = -max(-move, rotate);
      rightSpeed = move + rotate;
    } else {
      leftSpeed = move - rotate;
      rightSpeed = -max(-move, -rotate);
    }
  }

 leftMotor.write(constrain(leftSpeed, -1.0, 1.0));
 rightMotor.write(-constrain(rightSpeed, -1.0, 1.0));

}


void setup() {
  // put your setup code here, to run once:
leftMotor.attach(LEFTMOTOR_PIN);
rightMotor.attach(RIGHTMOTOR_PIN);
}

void loop() {
  // put your main code here, to run repeatedly:
if (frontUltrasonic.getDistance() > 3) {
        Tank_Drive(0.3, 0.0);
        delay(200);
        Tank_Drive(0.0, 0.0);
        delay(400);
      }
if (frontUltrasonic.getDistance() < 3){
        Tank_Drive(0.3, 0.3);
        delay(200);
        Tank_Drive(0.0, 0.0);
        delay(400);
      }
}
