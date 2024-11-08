/* 

Thermostat State Machine -- this needs to deal with:
DS18B20 Temp sensor
SSD1306 OLED screen driver
EK1964 IR sensor 
IR LED output
Various buttons on inputs to control

*/

//Screen Stuff
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


// Temperature Sensor Stuff

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 5    // pin number sensor is hooked to

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

// Buttons

int GreyPin=8;
int BluePin=7;
int RedPin=6;

bool Greypressed=false;
bool Redpressed=false;
bool Bluepressed=false;

// Global temperature desired

float TemperatureSetting=24.0;


void setup() {
  // put your setup code here, to run once:

  //Initialize serial interface for debugging
  Serial.begin(9600);


  // Initialize Temp Sensor
  sensors.begin();


  pinMode(GreyPin, INPUT);
  pinMode(BluePin, INPUT);
  pinMode(RedPin, INPUT);


  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }


  display.clearDisplay();

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

}

void loop() {
  // put your main code here, to run repeatedly:

  sensors.requestTemperatures();
  float currentTemp=sensors.getTempCByIndex(0);

  Greypressed=digitalRead(GreyPin);
  Bluepressed=digitalRead(BluePin);
  Redpressed=digitalRead(RedPin);

  if (Bluepressed) {
    TemperatureSetting = TemperatureSetting-0.5;
    Bluepressed=false;
  }

  if (Redpressed) {
    TemperatureSetting = TemperatureSetting+0.5;
    Redpressed=false;
  }

  oledDisplay(currentTemp,TemperatureSetting);

  

  Serial.print("Celsius temperature: ");
  Serial.print(currentTemp,TemperatureSetting);
  Serial.print("\n");


  delay(1000);
}



void oledDisplay(float Temp, float WantedTemp) {
  display.clearDisplay();

  display.setTextSize(2);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 0);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font

  display.setTextSize(1); 
  display.println("Temperature, Now/Set: \n");
  display.setTextSize(1); 
  display.print(Temp);
  display.print("/");
  display.print(WantedTemp);
  display.println("C");
  //display.write(' C');

  display.display();
}
