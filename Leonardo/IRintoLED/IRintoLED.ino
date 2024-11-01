/*
  IRintoLED
  Flashes an LED whenever IR sensor detects IR light
  IR sensor in this case is an EK1964  
 */
 

int led = 10;
int IRsensor = 9;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);  
  // initialize pin 10 as digital input.
  pinMode(IRsensor, INPUT);  

  digitalWrite(led, LOW); 
}

int j;
int val=LOW;

// the loop routine runs over and over again forever:

// it appears the IR sensor, at least in the example circuit,
// defaults HIGH, then drops to LOW when it detects IR light.

void loop() {
  val=digitalRead(IRsensor);
  if (val==LOW) {
    digitalWrite(led, HIGH);
  }
  digitalWrite(led,LOW);
}
