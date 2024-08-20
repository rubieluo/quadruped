/* This program is helpful for testing and clocking.

When clocking, change STATES to 1 and change angle_states
to only 1 angle. */

#include <Servo.h>

#define DELAY 500
#define SERVOS 12
#define STATES 3

Servo myservo[SERVOS];  
 
int servo_pins[SERVOS] = {2,3,4,5,6,7,8,9,10,11,12,13}; 
 
int angle_states[STATES] = {0, 90, 180};
 
void setup() {
  for(int i = 0; i < SERVOS; i++) {
     
    // Attach the servo to the servo object 
    myservo[i].attach(servo_pins[i]); 
 
    // Wait 500 milliseconds 
    delay(500);  
  } 
}
  
void loop() {
  // Move in one direction.
  for(int i = 0; i < STATES; i++) {
    for(int j = 0; j < SERVOS; j++) {
      myservo[j].write(angle_states[i]);
      delay(DELAY);
    }
  }
 
  // Move in the other direction
  for(int i = (STATES - 1); i >= 0; i--) {
    for(int j = 0; j < SERVOS; j++) {
      myservo[j].write(angle_states[i]);
      delay(DELAY);
    }
  }
}       