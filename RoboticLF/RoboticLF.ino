
//including the header file, where the class is located
//LFI stands for, line following instructions.
#include "LFI.h"
//creating a pointer


void setup() {
  //creating an object called robot
  robot = new LFI();
}


void loop() {

  //ir sensors
  //theses are the 5 ir sensors (being read from pin A0-A4) into the variables IR0 to IR4
  int IR0 = (analogRead(A0)); //farthest left sensor
  int IR1 = (analogRead(A1));
  int IR2 = (analogRead(A2)); //middle sensor
  int IR3 = (analogRead(A3));
  int IR4 = (analogRead(A4)); //farthest right sensor

  // If the 3 middle sensors all black, then wait for 400ms being going foward
  if (IR2 black && IR3  black && IR1 black) { //white and black are defined in the header file
    delay(400);
    robot->forward();
  }

  //if the middle sensor sees black, then go forward
  else if (IR2 black) robot->forward();

  //  if the right sees black then turn towards the right
  else if (IR3  black ) robot->SpinLeftM(1); //0.5

  //if the left sensor sees black then turn towards the left
  else if (IR1 black ) robot->SpinRightM(1);

  //  if the farthest right sess black then turn 'more' towards the right
  else if ( IR4 black )robot->SpinLeftM(1.3);

  //  if the farthest left sess black then turn 'more' towards the left
  else if ( IR0 black) robot->SpinRightM(1.3);

  //if the middle sensor sees white. wait 350ms and check again if the middle sensor is still white
  //if it is, then stop the robot.
  else if (IR2 white) {
    delay(350);
    if (IR2 black) {}
    else {
      robot->stopping();
    }
  }

}
