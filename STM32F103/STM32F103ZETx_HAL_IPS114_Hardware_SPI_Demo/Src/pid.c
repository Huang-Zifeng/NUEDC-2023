#include "pid.h"

static int error, integral, derivative, lastError;

static int targetCurrent;

/**
 * @brief Get the Current
 * 
 * @return int 
 */
int getCurrent(){
    /*code*/
    return 0;
}

/**
 * @brief 
 * 
 */
void pidControllerInit(){
    int error = targetCurrent - getCurrent();
    integral = 0;
    derivative = 0;
}

/**
 * @brief 
 * 
 * @return int 
 */
int pidControl(){
    int error = targetCurrent - getCurrent();
    integral += error;
    derivative = error - lastError;
    float output = Kp * error + Ki * integral + Kd * derivative;
    lastError = error;
    return output;
}