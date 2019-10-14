//===============================================================================
//  Initialization
//===============================================================================
void setup() {
  // Initialize serial port speed for the serial terminal
  Serial.begin(9600);

  // Set appropriate pins to inputs
  pinMode(nesData, INPUT);

  // Set appropriate pins to outputs
  pinMode(nesClock, OUTPUT);
  pinMode(nesLatch, OUTPUT);

  // Use the attach method to assign each object to a pin
  servoLeft.attach(LServoPin);
  servoRight.attach(RServoPin);

  // Set initial states
  digitalWrite(nesLatch, LOW);
  digitalWrite(nesClock, LOW);
}
