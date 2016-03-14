// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>
// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);


void setup(void)
{
  pinMode(11,OUTPUT);
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");
  sensors.begin();
}

/*
 * Main function, get and show the temperature
 */
void loop(void)
{ 

  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println(sensors.getTempCByIndex(0)); 
  analogWrite(11,map(sensors.getTempCByIndex(0),20,5,0,255)) ;
  if(sensors.getTempCByIndex(0) >20){
    analogWrite(11,0);
    }
  
}

