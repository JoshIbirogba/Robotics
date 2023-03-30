# Robotics
This repository contains Arduino (C++) code that controls a robot and servo motor 
This code is for a line-following robot using infrared (IR) sensors. 
The code starts with including the necessary header files, defining some constants (white and black), and declaring a class called LFI (which stands for Line Following Instructions).
The setup function creates an object called robot of the LFI class, and the loop function is the main function that runs repeatedly.
In the loop function, five IR sensors (connected to analog pins A0 to A4) are read and stored in the variables IR0 to IR4.
Then, the robot's behavior is determined based on the readings of the IR sensors. If the three middle sensors see black, the robot waits for 400ms and moves forward. If the middle sensor sees black, the robot moves forward. If the right sensor sees black, the robot turns left, and if the left sensor sees black, the robot turns right. If the farthest right sensor sees black, the robot turns more towards the right, and if the farthest left sensor sees black, the robot turns more towards the left. Finally, if the middle sensor sees white, the robot waits for 350ms, checks again if the middle sensor is still white, and stops the robot if it is still white.
Also, there is also another sensor that detects obstacles 20 cm from the robot, the robot is designed to avoid the obstacle and continue its journney on the black tape.
