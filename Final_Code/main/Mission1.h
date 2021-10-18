#ifndef MISSION1
#define MISSION1

extern int speedValue;

void mission1_setup();
void go_forward();
void go_backward();
void go_left();
void go_right();
void st();
void direction_control(String dataRecieved);
void arm_motion(String dataRecieved);
void mission1();

#endif
