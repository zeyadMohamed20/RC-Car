#include"Arduino.h"
#include"Definitions.h"
#include"Static.h"
#include"Mission1.h"

void mission2_setup()
{
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  
  for(int i=0;i<3;i++)
  {
    pinMode(trigger[i],OUTPUT);
  }
  for(int i=0;i<3;i++)
  {
    pinMode(echo[i],INPUT);
  }
} 

int gyroscope_read()
{ 
    if(millis() - timer > 1000)
    {
      timer = millis();   
    } 
    return mpu6050.getAngleZ(); 
}

void send_readings()
{
      int forwardReading,rightReading,leftReading,angleReading;
      String bestRoute;
      
      angleReading = gyroscope_read();
      forwardReading = ultrasonicForward.ping_cm();
      rightReading = ultrasonicRight.ping_cm();
      leftReading = ultrasonicLeft.ping_cm();

      //To avoid Reading Zero Error//
      if(forwardReading > 300)
      {
        forwardReading = 300;
      }
      if(rightReading > 300)
      {
        rightReading = 300;
      }
      if(leftReading > 300)
      {
        leftReading = 300;
      }
      
      //Compare directions//      
      if(forwardReading > 30)
      {
        bestRoute = "F";       
      }
      else
      {
        if(rightReading > 30) bestRoute = "R";
        else bestRoute = "L";
      }
      
      Serial.print(bestRoute);
      Serial.print("/n");
      Serial.print(forwardReading);
      Serial.print("/n");
      Serial.print(rightReading);
      Serial.print("/n");
      Serial.print(leftReading);
      Serial.print("/n");
      Serial.print(angleReading);
      Serial.println("/n");
      delay(100);
}

void mission2()
{
  while(true)
  {   
    mpu6050.update();
        
    //Sending Data To App// 
    send_readings();
    
    //Receiving Data From App//
    if(Serial.available() > 0)
    {
      dataRecieved = Serial.readStringUntil('\n');
      if((dataRecieved[0] == 'b'))
      {
        direction_control(dataRecieved);
      }
      else if(dataRecieved[0]== 'A')
      {
        speedValue = (dataRecieved.substring(1,dataRecieved.length())).toInt();
      }
      else if(dataRecieved == "M0")
      { 
        break;
      }
    }
    else
    {
      continue;
    }
  }
}
