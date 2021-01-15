#include <dht.h>
#define sensor 14 //D5 PIN ESP8266
dht DHT;
const int sensor_pin = A0;

void setup() {
  Serial.begin(115200);
  delay(500);
  
  Serial.println("Sensor Suhu dan Kelembaban Udara DHT11 Warriornux");
  delay(1000);
 
}
 
void loop() {
  float moisture_percentage;
  moisture_percentage = ( 100.00 - ( (analogRead(sensor_pin)/1023.00) * 100.00 ) );
  DHT.read11(sensor);
  
  Serial.print("Kelembaban udara = ");
  Serial.print(DHT.humidity);
  Serial.print("% ");
  Serial.print("Suhu = ");
  Serial.print(DHT.temperature); 
  Serial.println(" C ");

  Serial.print("Soil Moisture(in Percentage) = ");
  Serial.print(moisture_percentage);
  Serial.println("%");

  Serial.println("");
  delay(2000);
 
}