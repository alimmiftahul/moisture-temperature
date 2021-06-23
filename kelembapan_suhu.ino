#include <OneWire.h>
#include <DallasTemperature.h>

int sensorPin = A0; 
int sensorValue;  
int limit = 300; 
#define dsb 4

float result;

OneWire oneWire(dsb);
DallasTemperature sensors(&oneWire);

void suhu(){
  sensors.requestTemperatures();   
  Serial.print("Temperature DSB: ");
  result = sensors.getTempCByIndex(0);
  Serial.println(celcius); 
  delay(1000);
}

void setup() {
Serial.begin(9600);
pinMode(13, OUTPUT);
}

void loop() {  
sensorValue = analogRead(sensorPin);
Serial.println("Analog Value : ");
Serial.println(sensorValue);
if (sensorValue<limit) {
digitalWrite(13, HIGH); 
}
else {
digitalWrite(13, LOW);
 }
delay(1000); 

suhu();
}
