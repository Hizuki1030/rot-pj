unsigned long time1, time2;
#define distance 60
#define pi 3.141592653589793


void setup(){
 Serial.begin (9600);
 attachInterrupt(digitalPinToInterrupt(2),timer_1,RISING);
 attachInterrupt(digitalPinToInterrupt(3),timer_2,RISING);
}

void loop(){
 if(time1> 0 || time2 > 0){ 
  int tim = time1 - time2;
  Serial.print(tim);
  Serial.print("\n");
  float angle = get_angle(tim);
  Serial.print(angle);
  Serial.print("\n");
  Serial.print(angle*180/pi);
  Serial.print("\n");
 }
 delay(1000);
}

int timer_1(){
  time1 = micros();
  return time1;
}

int timer_2(){
  time2 = micros();
  return time2;
}

float get_angle(int tim){
   double in = 0.3314 * tim / distance;
   float angle = acos(in);
   return angle;
}
