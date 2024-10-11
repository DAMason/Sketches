//Sample code from https://forum.arduino.cc/t/28byj-48-4-phase-stepper-motor/1162926


//Includes the Arduino Stepper Library
#include <Stepper.h>
// Defines the number of steps per rotation
const int stepsPerRevolution = 2048;

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
// On pro micro board pins.  6.  8.  7.  9. 
Stepper myStepper = Stepper(stepsPerRevolution, 6, 8, 7, 9);


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

  
	// Rotate CW slowly at 5 RPM
	myStepper.setSpeed(5);
	myStepper.step(stepsPerRevolution);
	delay(1000);
	
	// Rotate CCW quickly at 10 RPM
  // This seems to be the max for this motor + driver
	myStepper.setSpeed(9);
	myStepper.step(-stepsPerRevolution);
	delay(1000);

}
