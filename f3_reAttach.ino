//////////////
// reAttach //
//////////////
// Reattaches servos to chosen pins
void reAttach() {
  if(!servoLeft.attached())
    servoLeft.attach(LServoPin);
  if(!servoRight.attached())
    servoRight.attach(RServoPin);
}
