/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
  DAM: Additional loop to count the delay down  
  This example code is in the public domain.
 */
 
// Arduino Leonardo doesn't have the standard pin 13 LED, so picking a pin to connect an LED + resistor to

int led = 10;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}

int j;

// the loop routine runs over and over again forever:

// But can't just do the simple blinking bit...  Sort of count down now

void loop() {
  for (j=2000;j>0;j-=100) {
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(j);               // wait for a j/1000th of a second
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    delay(j);               // wait for a j/1000th of a second
  }
}
