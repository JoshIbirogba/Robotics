
//if it doesnt already exist, then include/define the header file LFI
#ifndef LFI_h
#define LFI_h
//include files
#include "Arduino.h"
#include <Wire.h>
#include <Adafruit_MShield.h>

//in the main program(newrobo) white and black are used to describe
//whether the IR sensor is seeing white, or black.
#define white >300
#define black <300



//LFI stands for, line following instructions.
class LFI {

    //the variables are private
  private:
    //the speed of the motors
    int speed = 30;

    Adafruit_MotorShield MShield;

    Adafruit_DCMotor * LeftMotor;
    Adafruit_DCMotor *RightMotor;

    //all the functions are public
  public:
    //constructor
    LFI();
    //stops the robot
    void stopping();
    //moves the robot forward
    void forward();

    //spins the right motor
    void SpinRightM (float AddedSpeed);
    //spins the left motor
    void SpinLeftM (float AddedSpeed);

};

//so the file isnt included more than once
#endif
