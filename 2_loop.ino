//===============================================================================
//  Main
//===============================================================================
void loop() {
  // This function call will return the states of all NES controller's register
  // in a nice 8 bit variable format. Remember to refer to the table and
  // constants above for which button maps where!
  nesRegister = nesRead();

  // If Right + Up button press
  if (bitRead(nesRegister, RIGHT_BUTTON) == 0 && bitRead(nesRegister, UP_BUTTON) == 0) {
    forwardRight();                  // Run the forward + right turn motion routine
    Serial.println("UP + RIGHT");
  }

  // If Left + Up button press
  else if (bitRead(nesRegister, LEFT_BUTTON) == 0 && bitRead(nesRegister, UP_BUTTON) == 0) {
    forwardLeft();                   // Run the forward + left turn motion routine
    Serial.println("UP + LEFT");
  }

  // If Right + Down button press
  else if (bitRead(nesRegister, RIGHT_BUTTON) == 0 && bitRead(nesRegister, DOWN_BUTTON) == 0) {
    reverseRight();                  // Run the reverse + right turn motion routine
    Serial.println("DOWN + RIGHT");
  }

  // If Left + Down button press
  else if (bitRead(nesRegister, LEFT_BUTTON) == 0 && bitRead(nesRegister, DOWN_BUTTON) == 0) {
    reverseLeft();                   // Run the reverse + right turn motion routine
    Serial.println("UP + LEFT");
  }
    
  else if (bitRead(nesRegister, RIGHT_BUTTON) == 0) {   // If Right button press
    turnRight();                     // Run the right turn motion routine
    Serial.println("RIGHT");
  }

  // If Left button press
  else if (bitRead(nesRegister, LEFT_BUTTON) == 0) {   
    turnLeft();                      // Run the left turn motion routine
    Serial.println("LEFT");
  }

  // If Down button press
  else if (bitRead(nesRegister, DOWN_BUTTON) == 0) {   
      reverse();                     // Run the reverse motion routine
      Serial.println("DOWN");
  }

  // If Up button press
  else if (bitRead(nesRegister, UP_BUTTON) == 0) {   
      forward();                     // Run the forward motion routine
      Serial.println("UP");
  }

  // If Start button press
  else if (bitRead(nesRegister, START_BUTTON) == 0) {   
      Serial.println("START");
  }

  // If Select button press
  else if (bitRead(nesRegister, SELECT_BUTTON) == 0) {   
      Serial.println("SELECT");
  }

  // If B button press
  else if (bitRead(nesRegister, B_BUTTON) == 0) {   
      Serial.println("B");
      //if (bitRead(nesRegister, UP_BUTTON) == 0 && bitRead(nesRegister, LEFT_BUTTON) == 0) {
        //may need to set up a Up && Turn command that does something like this and then
        //use B or A for a slower turn option or something...
      //}
  }

  // If A button press
  else if (bitRead(nesRegister, A_BUTTON) == 0) {   
      Serial.println("A");
  }

  // If no button press
  else if (nesRegister == 255) {    
      stopRobot();            // Run the stop motion routine
  }

  // Slight delay before we debug what was pressed so we don't spam the
  // serial monitor.
  delay(100);
}
