#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);
long timer = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop() {
  mpu6050.update();
  if(millis() - timer > 1000)
  {
  Serial.println(mpu6050.getAngleZ());
  timer = millis();   
  if(mpu6050.getAngleZ() > 360 || mpu6050.getAngleZ() < -360)
    {
      mpu6050.getAngleZ() = 0;
    }
  }
  

}
