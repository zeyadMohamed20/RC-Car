#include"Arduino.h"
#include "Definitions.h"
#include "Static.h"


void mission1_setup()
{
  pinMode(SPEED_PIN1,OUTPUT);
  pinMode(SPEED_PIN2,OUTPUT);
  pinMode(DIR1,OUTPUT);
  pinMode(DIR2,OUTPUT);
  pinMode(DIR3,OUTPUT);
  pinMode(DIR4,OUTPUT);
  base.attach(BASE);
  base.write(BASE_INITIAL_ANGLE,INITIAL_SPEED);
  shoulder.attach(SHOULDER);
  shoulder.write(SHOULDER_INITIAL_ANGLE,INITIAL_SPEED);
  joint.attach(JOINT);
  joint.write(JOINT_INITIAL_ANGLE,INITIAL_SPEED);
  gripper.attach(GRIPPER);
  gripper.write(GRIPPER_INITIAL_ANGLE,INITIAL_SPEED); 
}

void go_forward()
{
  analogWrite(SPEED_PIN1,speedValue);
  analogWrite(SPEED_PIN2,speedValue);
  digitalWrite(DIR1,HIGH); 
  digitalWrite(DIR2,LOW); 
  digitalWrite(DIR3,HIGH); 
  digitalWrite(DIR4,LOW); 
}

void go_backward()
{
  analogWrite(SPEED_PIN1,speedValue);
  analogWrite(SPEED_PIN2,speedValue);
  digitalWrite(DIR1,LOW); 
  digitalWrite(DIR2,HIGH); 
  digitalWrite(DIR3,LOW); 
  digitalWrite(DIR4,HIGH); 
}

void go_left()
{
  analogWrite(SPEED_PIN1,speedValue);
  analogWrite(SPEED_PIN2,speedValue);
  digitalWrite(DIR1,HIGH); 
  digitalWrite(DIR2,LOW); 
  digitalWrite(DIR3,LOW); 
  digitalWrite(DIR4,HIGH); 
}

void go_right()
{
  analogWrite(SPEED_PIN1,speedValue);
  analogWrite(SPEED_PIN2,speedValue);
  digitalWrite(DIR1,LOW); 
  digitalWrite(DIR2,HIGH); 
  digitalWrite(DIR3,HIGH); 
  digitalWrite(DIR4,LOW); 
}

void st()
{
  analogWrite(SPEED_PIN1,0);
  analogWrite(SPEED_PIN2,0);
  digitalWrite(DIR1,LOW); 
  digitalWrite(DIR2,LOW); 
  digitalWrite(DIR3,LOW); 
  digitalWrite(DIR4,LOW); 
}

void direction_control(String dataRecieved)
{       
    if(dataRecieved[1] == 'F')
    {
      
     go_forward(); 
     //Serial.println("Forward");
    }
    else if(dataRecieved[1] == 'B')
    {
     go_backward();
     //Serial.println("Backward");
    }
    else if(dataRecieved[1] == 'R')
    {
     go_right();
     //Serial.println("Right");
    }
    else if(dataRecieved[1] == 'L')
    {
     go_left();
     //Serial.println("Left");
    }
    else if(dataRecieved[1] == 'S')
    {
     st();
     //Serial.println("Stop");
    }
}

void arm_motion(String dataRecieved)
{
       int baseAngle;
       int shoulderAngle;
       int jointAngle;
       int gripperAngle;
  
       if(dataRecieved[0] == 'B')
       {
         baseAngle = (dataRecieved.substring(1,dataRecieved.length())).toInt();
         base.write(baseAngle,BASE_SPEED);
       }
       else if(dataRecieved[0] == 'S')
       {
         shoulderAngle = (dataRecieved.substring(1,dataRecieved.length())).toInt(); 
         shoulder.write(shoulderAngle,SHOULDER_SPEED);
       }
       else if(dataRecieved[0] == 'J')
       {
         jointAngle = (dataRecieved.substring(1,dataRecieved.length())).toInt();
         joint.write(jointAngle,JOINT_SPEED);
       }
       else if(dataRecieved[0] == 'G')
       {
         gripperAngle = map((dataRecieved.substring(1,dataRecieved.length())).toInt(),0,140,140,0);
         gripper.write(gripperAngle,GRIPPER_SPEED);         
       }   
}

void mission1()
{
   String dataRecieved;
      
   while(true)
   {
    if(Serial.available()>0)
    {
        dataRecieved = Serial.readStringUntil('\n');
        if((dataRecieved[0] == 'b'))
        {
          direction_control(dataRecieved);
        }
        else if((dataRecieved[0]== 'G') || (dataRecieved[0]== 'J') || (dataRecieved[0]== 'S') || (dataRecieved[0]== 'B'))
        {
          arm_motion(dataRecieved);
        }
        else if(dataRecieved[0]== 'A')
        {
         speedValue = (dataRecieved.substring(1,dataRecieved.length())).toInt();
        }
        else if(dataRecieved == "M0")
        {
          //Serial.println("Home");
          break;
        }
     } 
     else
     {
        continue;
     }         
   }
}
