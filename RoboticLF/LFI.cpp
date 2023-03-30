
//LFI stands for, line following instructions.
#include "LFI.h"
#include "Arduino.h"


//the class constructor
LFI::LFI() {

//setting up all 5 IR sensors as input
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A0, INPUT);
  pinMode(A4, INPUT);

  MShield.begin();


  //returning two of the four pre-defined DC motor objects controlled by the shield.
  LeftMotor = MShield.getMotor(3);
  RightMotor = MShield.getMotor(4);

}

//stops the robot
void LFI::stopping() {
  RightMotor->run(RELEASE);
  LeftMotor->run(RELEASE);
}

//makes the robot run forward
void LFI::forward() {
  LeftMotor->setSpeed(speed + 6);
  RightMotor->setSpeed(speed);
  RightMotor->run(FORWARD);
  LeftMotor->run(FORWARD);
}

//spin the left motor depending on the AddedSpeed variable.
void LFI::SpinLeftM (float AddedSpeed) {
  //release both motors before spinning
  RightMotor->run(RELEASE);
  LeftMotor->run(RELEASE);

  //spin the left motor
  LeftMotor->setSpeed(speed + 14 * AddedSpeed);
  LeftMotor->run(FORWARD);
  delay(400);
}

// spin the left motor depending on the AddedSpeed variable.
void LFI::SpinRightM (float AddedSpeed) {
  //release both motors before spinning
  RightMotor->run(RELEASE);
  LeftMotor->run(RELEASE);

  //spin the right motor
  RightMotor->setSpeed(speed + 4 * AddedSpeed );
  RightMotor->run(FORWARD);
  delay(400);
}
