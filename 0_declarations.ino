//===============================================================================
//  Header Files
//===============================================================================
#include <Servo.h>

//===============================================================================
//  Constants
//===============================================================================
// Here we have a bunch of constants that will become clearer when we look at the
// nesRead() function. Basically, we will use these contents to clear
// a bit. These are chosen according to the table in ServoBot_NES_Controller_vX.ino.
const short A_BUTTON         = 0;
const short B_BUTTON         = 1;
const short SELECT_BUTTON    = 2;
const short START_BUTTON     = 3;
const short UP_BUTTON        = 4;
const short DOWN_BUTTON      = 5;
const short LEFT_BUTTON      = 6;
const short RIGHT_BUTTON     = 7;

// Create objects of the Servo class
Servo servoLeft;
Servo servoRight;

//===============================================================================
//  Variables
//===============================================================================
byte nesRegister  = 0;    // We will use this to hold current button states
int pbLeft = 0;           // Var for left bump (high/low)
int pbRight = 0;          // Var for right bump (high/low)
int drvMode = 0;          // Var for drive mode (high/low)

//===============================================================================
//  Pin Declarations
//===============================================================================
//Inputs:
const short nesData = 7;        // The data pin for the NES controller
const short bumpL = 2;          // The input from left leaf switch bumper
const short bumpR = 3;          // The input from right leaf switch bumper
const short driveMode = 4;      // Input from the auto/manual drive mode switch
const int ledPin = 13;          // Built-in LED

//Outputs:
const short nesClock = 5;      // The clock pin for the NES controller
const short nesLatch = 6;      // The latch pin for the NES controller
const short LServoPin = 9;     // The pin for the left servo motor
const short RServoPin = 10;    // The pin for the right servo motor
