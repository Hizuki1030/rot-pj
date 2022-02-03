const int stepsPerRevolution = 400;
const int numberOfSteps = stepsPerRevolution/8;
const int dirPin=12; 
const int stepPin=13;
const int rightSensorPin=7;
const int leftSensorPin=8;
const int enablePin=5 ;
boolean rightVal = 0;
boolean leftVal = 0;

void setup()
{
  pinMode(leftSensorPin, INPUT);
  pinMode(rightSensorPin, INPUT);
  pinMode (stepPin, OUTPUT);
  pinMode (dirPin, OUTPUT);
  pinMode (enablePin, OUTPUT);

  digitalWrite(enablePin, LOW);
  Serial.begin (9600);
}
  
void loop ()
{
  rightVal =digitalRead(rightSensorPin);
  leftVal =digitalRead(leftSensorPin);
  
   if (leftVal==LOW && rightVal==HIGH)
  {
    Serial.println("Turning Right");
    digitalWrite(dirPin,LOW); 
    
    for(int steps = 0; steps < numberOfSteps; steps++)
    {
      digitalWrite(stepPin,HIGH);
      delayMicroseconds(10000);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(10000);
    }
    delayMicroseconds(100000);
    rightVal = 0;
    leftVal = 0;
  }
  else if (leftVal==HIGH && rightVal==LOW)
  {
    Serial.println("Turning Left");
    digitalWrite(dirPin,HIGH);
      
    for(int steps = 0; steps < numberOfSteps; steps++)
    {
      digitalWrite(stepPin,HIGH);
      delayMicroseconds(10000);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(10000);
    }
    delayMicroseconds(100000);
    rightVal = 0;
    leftVal = 0;
  }
  else 
  {
    rightVal = 0;
    leftVal = 0;
  }
}
