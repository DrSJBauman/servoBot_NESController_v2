//===============================================================================
//  Main
//===============================================================================
void loop() {

  // Check the auto/manual drive mode switch to determine which loop code to utilize
  drvMode = digitalRead(driveMode);
  if (drvMode == HIGH) {          // Auto drive mode toggled on

    showLED();                    // Show LED indicator
    slowForward();                // Start forward automatically

    // Test bumper switches
    pbLeft = digitalRead(bumpL);
    pbRight = digitalRead(bumpR);

    if (pbLeft == HIGH) {         // If left bumper hit
      Serial.println("Left bump, autosteering");
      slowReverse();
      delay(500);
      slowRight();
      delay(1000);
    }

    if (pbRight == HIGH) {        // If right bumper hit
      Serial.println("Right bump, autosteering");
      slowReverse();
      delay(500);
      slowLeft();
      delay(1000);
    }
  }

  else {                              // Auto drive mode toggled off
    // Manual drive mode condition:
  
    // This function call will return the states of all NES controller's register
    // in a nice 8 bit variable format. Remember to refer to the table and
    // constants in ServoBot_NES_Controller_vX.ino for which button maps where!
    nesRegister = nesRead();

    // If A + directional button press
    if (bitRead(nesRegister, A_BUTTON) == 0 && bitRead(nesRegister, UP_BUTTON) == 0) {   
      //slowForward();
      Serial.println("A + UP");
    } else if (bitRead(nesRegister, A_BUTTON) == 0 && bitRead(nesRegister, DOWN_BUTTON) == 0) {
      //slowReverse();
      Serial.println("A + DOWN");
    } else if (bitRead(nesRegister, A_BUTTON) == 0 && bitRead(nesRegister, RIGHT_BUTTON) == 0) {
      //slowRight();
      Serial.println("A + RIGHT");
    } else if (bitRead(nesRegister, A_BUTTON) == 0 && bitRead(nesRegister, LEFT_BUTTON) == 0) {
      //slowLeft();
      Serial.println("A + LEFT");
    }


    // If B + directional button press
    if (bitRead(nesRegister, B_BUTTON) == 0 && bitRead(nesRegister, UP_BUTTON) == 0) {   
      slowForward();
      Serial.println("B + UP");
    } else if (bitRead(nesRegister, B_BUTTON) == 0 && bitRead(nesRegister, DOWN_BUTTON) == 0) {
      slowReverse();
      Serial.println("B + DOWN");
    } else if (bitRead(nesRegister, B_BUTTON) == 0 && bitRead(nesRegister, RIGHT_BUTTON) == 0) {
      slowRight();
      Serial.println("B + RIGHT");
    } else if (bitRead(nesRegister, B_BUTTON) == 0 && bitRead(nesRegister, LEFT_BUTTON) == 0) {
      slowLeft();
      Serial.println("B + LEFT");
    }
  
    // If Right + Up button press
    else if (bitRead(nesRegister, RIGHT_BUTTON) == 0 && bitRead(nesRegister, UP_BUTTON) == 0) {
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
      Serial.println("DOWN + LEFT");
    }
  
    // If Right button press
    else if (bitRead(nesRegister, RIGHT_BUTTON) == 0) {   
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
  
    // If A button press
    else if (bitRead(nesRegister, A_BUTTON) == 0) {   
        Serial.println("A");
    }

    // If B button press
    else if (bitRead(nesRegister, B_BUTTON) == 0) {   
        Serial.println("B");
    }
  
    // If no button press
    else if (nesRegister == 255) {    
        stopRobot();            // Run the stop motion routine
    }

  }
    // Slight delay before we debug what was pressed so we don't spam the
    // serial monitor.
    delay(100);
}
