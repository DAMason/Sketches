
//Based on tutorial at https://randomnerdtutorials.com/guide-for-ds18b20-temperature-sensor-with-arduino/

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 5    // pin number

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);


void setup() {
  // put your setup code here, to run once:

  // Start serial connection
  Serial.begin(9600);

  sensors.begin();

}

void loop() {
  // put your main code here, to run repeatedly:


  sensors.requestTemperatures();

  Serial.print("Celsius temperature: ");
  Serial.print(sensors.getTempCByIndex(0));
  Serial.print("\n");

  delay(1000);

}
