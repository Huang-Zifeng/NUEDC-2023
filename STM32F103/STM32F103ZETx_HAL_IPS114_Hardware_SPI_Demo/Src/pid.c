#include "pid.h"

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
void pidControllerInit(pidController* pid, float kp, float ki, float kd, float target, int (*getValue)(), float max, float min){
    pid->Kp = kp;
    pid->Kd = kd;
    pid->Ki = ki;
    pid->targetValue = target;
    pid->maximum = max;
    pid->minimum = min;

    pid->getValue = getValue;

    pid->error = 0;
    pid->integral = 0;
    pid->derivative = 0;
    pid->lastError = 0;
}

/**
 * @brief 
 * 
 * @return int 
 */
int pidControl(pidController *pid){
    pid->error = pid->targetValue - pid->getValue();
    pid->integral += pid->error;
    pid->derivative = pid->error - pid->lastError;

    float output = pid->Kp * pid->error + pid->Ki * pid->integral + pid->Kd * pid->derivative;

    pid->lastError = pid->error;

    return output;
}


/*demo*/
/*
int main()
{
    //创建PID控制器实例
    pidController pid;
    pidControllerInit(&pid, 0.5, 0.2, 0.1, targetVoltage, getVoltage);

    //循环执行PID控制
    while (1) {
        //执行PID控制
        float output = pidControl(&pid);

        //输出控制器输出
        printf("PID output: %f\n", output);
    }

    return 0;
}













*/