#include"NewPing.h"
#include"VarSpeedServo.h"
#include<Wire.h>
#include <MPU6050_tockn.h>

#define TX 0
#define RX 1
#define SPEED_PIN1 6
#define DIR1 8
#define DIR2 7
#define SPEED_PIN2 11
#define DIR3 2 
#define DIR4 4
#define BASE_SPEED 200
#define BASE 10
#define BASE_INITIAL_ANGLE 0
#define SHOULDER_SPEED 100 
#define SHOULDER 9
#define SHOULDER_INITIAL_ANGLE 60
#define JOINT_SPEED 200
#define JOINT 5
#define JOINT_INITIAL_ANGLE 40
#define GRIPPER_SPEED 150
#define GRIPPER 3 
#define GRIPPER_INITIAL_ANGLE 90
#define MAX_DISTANCE 400
#define INITIAL_SPEED 20
