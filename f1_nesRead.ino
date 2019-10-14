/////////////
// nesRead //
/////////////
byte nesRead() {
  byte value = 0;                 // Reset the value read from the previous loop cycle
  digitalWrite(nesLatch, HIGH);   // Begin initiating Latch pin to activate shift register
  delayMicroseconds(5);         
  digitalWrite(nesLatch, LOW);    // Cause shift register to "latch" current button presses
  for (int i=0; i<8; i++) {       // Cycle through all 8 bits
    digitalWrite(nesClock, LOW);  // Each clock cycle, one of the bits appears at Data pin
    value |= digitalRead(nesData) << (i); // Read Data pin and store current bit in the
                                           // appropriate position of "dataIn"
    digitalWrite(nesClock, HIGH); // Finish the clock cycle
  }
  return(value);                  // Return the full byte where 0 = button pressed
}
