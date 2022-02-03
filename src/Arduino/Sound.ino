const int stepsPerRevolution = 400;  // change this to fit the number of steps per revolution for your motor
const int numberOfSteps = stepsPerRevolution/8; //45 degree turns
const int rightSensorPin=7;
const int leftSensorPin=8;
boolean rightVal = 0;
boolean leftVal = 0;

#include <Servo.h>
Servo servo;

void setup()
{
  pinMode(leftSensorPin, INPUT); //Make pin 8 an input pin.
  pinMode(rightSensorPin, INPUT); //Make pin 7 an input pin/

  servo.attach(6);
  servo.write(90);
  delay(400);

  Serial.begin (9600); // initialize the serial port:
  
}
  
void loop ()
{
  //poll inputs for signal
  rightVal =digitalRead(rightSensorPin);
  leftVal =digitalRead(leftSensorPin);
  
  // when the sensor detects a signal above the threshold value set on sensor, turn finder to the direction of sound
  if (leftVal==LOW && rightVal==HIGH)
  {
    Serial.println("Turning Right");
      servo.write(45);
      delay(400);
      
    delayMicroseconds(50000);
    rightVal = 0;
    leftVal = 0;
  }
  else if (leftVal==HIGH && rightVal==LOW)
  {
    Serial.println("Turning Left");
      servo.write(135);
      delay(400);
      
    delayMicroseconds(50000);
    rightVal = 0;
    leftVal = 0;
  }
  else 
  {
    //Do nothing
    rightVal = 0;
    leftVal = 0;
  }
}
