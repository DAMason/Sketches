/*
  USBSerial
  Sketch dorking around with serial output -- first just some repeating numbers
 */


int j=0;  // just a counter -- should be global
 
// the setup routine runs once when you press reset 
// or when the serial connection is initiated...:

void setup() {                
  // initialize the Serial library -- 9600 baud
  Serial.begin(9600); 
}


// the loop routine runs over and over again forever:


void loop() {
  if (j>=86400) j=0;   // reset each day
  Serial.println(j);  // print out j 
  j++;
  delay (1000);   // 1 sec delay
}


