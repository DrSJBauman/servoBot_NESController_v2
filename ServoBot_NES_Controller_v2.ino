/*
================================================================================

    File........... NES Controller Basic Use with Servo motors
    Purpose........ To demonstrate how to interface a 2-servo robot to an NES controller
    Author......... Dr Stephen J Bauman
    E-mail......... sjbauman0@gmail.com
    Started........ 10/11/2019
    Finished....... 10/14/2019
    Updated........ --/--/----
 
================================================================================
   Notes
================================================================================  
- Adapted and modified from Arduino Robot Bonanza's TeachbotServo_NES sketch and
  Joseph Corletto's NES_Controller_Test_Code on allaboutcircuits.com

- The NES controller contains one 8-bit shift register inside. 
- This register takes parallel inputs and converts them into a serial output.

- This code first latches the data and then shifts in the first bit on the data line. 
  Then it clocks and shifts in on the data line until all bits are received.
- What is debugged are the button states of the NES controller.
- A logical "1" means the button is not pressed. A logical "0" means the button is
  pressed.
- This code shifts the first bit of data into the LSB (0000000X).

- The order of shifting for the buttons is shown in the table below:
    Button  | Position | Order as shifted onto Data pin
    -------------------------
 *  A       | 11111110 | bit 0
 *  B       | 11111101 | bit 1
 *  SELECT  | 11111011 | bit 2
 *  START   | 11110111 | bit 3
 *  UP      | 11101111 | bit 4
 *  DOWN    | 11011111 | bit 5
 *  LEFT    | 10111111 | bit 6
 *  RIGHT   | 01111111 | bit 7

- The NES controller pinout is shown below (looking into controller's
  connector end):
    __________
   /          |
  /       O 1 | 1 - Ground
  |           | 2 - Clock
  | 7 O   O 2 | 3 - Latch
  |           | 4 - Data Out
  | 6 O   O 3 | 5 - No Connection
  |           | 6 - No Connection
  | 5 O   O 4 | 7 - +5V
  |___________|

================================================================================
  Updates
================================================================================
From v1:
- split into multiple sketches for ease of use
- added forward/reverse + right/left turning functionality
- modified input declarations
- inserted additional comments
*/
