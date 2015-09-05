/*
  USBSerial
  Sketch dorking around with serial output -- first just some repeating numbers
 */


int j;  // just a counter -- should be global
 
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the Serial library -- 9600 baud
  Serial.begin(9600); 
  j=0;  // initialze / reset   
}


// the loop routine runs over and over again forever:


void loop() {
  j++;
  if (j>86400) j=0;   // reset each day
  Serial.println(j);  // print out j 
  delay (1000);   // 1 sec delay
}


