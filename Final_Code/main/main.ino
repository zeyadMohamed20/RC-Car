/*
**********************************************************************************************************
@file      Robot_Car
@author    Brute Force Team
@brief     This file contains the  process that control the robot car
*********************************************************************************************************
*/

#include"Mission1.h"
#include"Mission2.h"
#include"Static.h"

void setup() 
{
  Serial.begin(9600);
  mission1_setup ();
  mission2_setup ();
}

void loop() 
{    
     
 if(Serial.available()>0)
  {
    dataRecieved = Serial.readStringUntil ('\n');
   if(dataRecieved == "M1")
   {  
     mission1();     
   }
   else if(dataRecieved == "M2")
   {
     //Serial.print("Mission2");
      mission2();  
          
   }
  }
}     
