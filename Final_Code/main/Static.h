#include"Definitions.h"

static String dataRecieved;
static VarSpeedServo base,shoulder,joint,gripper;
static int speedValue;
static int trigger[3] = {A2,12,A0};
static int echo[3] = {A3,13,A1};
static NewPing ultrasonicLeft(trigger[0],echo[0],MAX_DISTANCE);
static NewPing ultrasonicForward(trigger[1],echo[1],MAX_DISTANCE);
static NewPing ultrasonicRight(trigger[2],echo[2],MAX_DISTANCE);

///////////////////Gyroscope ///////////////////////
static MPU6050 mpu6050(Wire);
static int timer = 0;
