#define echoPin 2
#define trigPin 3
#include <Arduino.h>
#include <Wire.h>
#include "SHT31.h"

SHT31 sht31 = SHT31();

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  while(!Serial);  
  sht31.begin();
}

void loop(){
  Serial.print(get_distance());
  Serial.print("\n");
  delay(1000);
}

float get_distance(){
  
  float duration, distance;

  float temp = sht31.getTemperature();
  float hum = sht31.getHumidity();
  delay(100);
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * (0.03314 + 0.0000606 * temp);
  return distance;  
}
