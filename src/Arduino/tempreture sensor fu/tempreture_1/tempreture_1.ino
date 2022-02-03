#include <Wire.h>

#define PCTL 0x00
#define RST 0x01
#define FPSC 0x02
#define INTC 0x03
#define STAT 0x04
#define SCLR 0x05
#define AVE 0x07
#define INTHL 0x08
#define TTHL 0x0E
#define INT0 0x10
#define T01L 0x80

#define AMG88_ADDR 0x69 // in 7bit




void setup()
{
    Serial.begin(115200);
    Wire.begin();
    
    int fpsc = B00000000;// 1fps
    datasend(AMG88_ADDR,FPSC,&fpsc,1);
    int intc = 0x00; // diff interrpt mode, INT output reactive
    datasend(AMG88_ADDR,INTC,&intc,1);
    // moving average output mode active
    int tmp = 0x50;
    datasend(AMG88_ADDR,0x1F,&tmp,1);
    tmp = 0x45;
    datasend(AMG88_ADDR,0x1F,&tmp,1);
    tmp = 0x57;
    datasend(AMG88_ADDR,0x1F,&tmp,1);
    tmp = 0x20;
    datasend(AMG88_ADDR,AVE,&tmp,1);
    tmp = 0x00;
    datasend(AMG88_ADDR,0x1F,&tmp,1);

    int sensorTemp[2];
    dataread(AMG88_ADDR,TTHL,sensorTemp,2);
    //Serial.print("sensor temperature:");
    //Serial.println( (sensorTemp[1]*256 + sensorTemp[0])*0.0625);
    
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(get_Tempareture());
  Serial.print("\n");
  delay(1000);
}

float get_Tempareture(){
int sensorData[32];
    float maxt;
    float maxte;
    maxt = 0;
    maxte = 0;
for(int i = 0; i < 4; i++)
    {
        dataread(AMG88_ADDR, T01L + i*0x20, sensorData, 32);
        for(int l = 0 ; l < 16 ; l++)
        {
            int16_t temporaryData = (sensorData[l * 2 + 1] << 8 ) + sensorData[l * 2];
            float temperature;
            if(temporaryData > 0x200)
            {
                temperature = (-temporaryData +  0xfff) * -0.25;
            }else
            {
                temperature = temporaryData * 0.25;
            }
            if(maxt < temperature)
            {
              maxt = temperature;
            }
        }
        if(maxte < maxt)
        {
          maxte = maxt;
        }
    }
return maxte;
}

void datasend(int id,int reg,int *data,int datasize)
{
    Wire.beginTransmission(id);
    Wire.write(reg);
    for(int i=0;i<datasize;i++)
    {
        Wire.write(data[i]);
    }
    Wire.endTransmission();
}

void dataread(int id,int reg,int *data,int datasize)
{
    Wire.beginTransmission(id);
    Wire.write(reg);
    Wire.endTransmission(false);
    Wire.requestFrom(id, datasize, false);
    for(int i=0;i<datasize;i++)
    {
        data[i] = Wire.read();
    }
    Wire.endTransmission(true);
}
