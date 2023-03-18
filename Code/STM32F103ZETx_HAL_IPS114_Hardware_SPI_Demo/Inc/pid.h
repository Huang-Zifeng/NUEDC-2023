#ifndef PID_H_
#define PID_H_

// #define Kp 0.5
// #define Ki 0.2
// #define Kd 0

int getCurrent();
void pidControllerInit();
int pidControl();

#endif