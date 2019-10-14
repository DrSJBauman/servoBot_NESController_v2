/////////////////////
// Motion Routines //
/////////////////////
/* Servo PWM "write" command takes inputs from 0 to 180, as makes sense for adjusting
the angle of a normal servo. Servos modified for continuous rotation use 0 for rotation
in one direction and 180 for rotation in the opposite direction. 90 attempts to hold the 
servo stationary, though jitter is common.

Intuitively, speed is adjusted by choosing PWM values somewhere between stationary and full rotation 
in a given direction for each motor.

One can use "writeMicroseconds" to instead use the range from 544 to 2400 µs, allowing
the user finer control over the rotation speed in either direction (1500 is stationary).*/

// Motion routines for forward, reverse, turns, and stop
void forward() {
  reAttach();
  servoLeft.write(180);
  servoRight.write(0);
}

void reverse() {
  reAttach();
  servoLeft.write(0);
  servoRight.write(180);
}

void turnRight() {
  reAttach();
  servoLeft.write(180);
  servoRight.write(180);
}

void turnLeft() {
  reAttach();
  servoLeft.write(0);
  servoRight.write(0);
}

void stopRobot() {
  servoLeft.detach();
  servoRight.detach();
}

/////////////////////////////
// Motion routines for combinations of forward/reverse and right/left
void forwardRight() {
  reAttach();
  servoLeft.writeMicroseconds(2400);
  servoRight.writeMicroseconds(1400);
}

void forwardLeft() {
  reAttach();
  servoLeft.writeMicroseconds(1530);
  servoRight.writeMicroseconds(550);
}

void reverseRight() {
  reAttach();
  servoLeft.writeMicroseconds(550);
  servoRight.writeMicroseconds(1530);
}

void reverseLeft() {
  reAttach();
  servoLeft.writeMicroseconds(1400);
  servoRight.writeMicroseconds(2400);
}
