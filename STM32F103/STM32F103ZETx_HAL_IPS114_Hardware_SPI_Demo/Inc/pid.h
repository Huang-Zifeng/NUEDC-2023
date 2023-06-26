#ifndef PID_H_
#define PID_H_

void pidControllerInit(pidController* pid, float kp, float ki, float kd, float target, int (*getValue)(), float max, float min);
int pidControl();

typedef struct {
    // PID 参数
    float Kp;
    float Ki;
    float Kd;
    float targetValue;
    int (*getValue)();
    float maximum, minimum;
    // 误差量
    float error ,integral ,derivative ,lastError;
} pidController, *ppid_t;

#endif