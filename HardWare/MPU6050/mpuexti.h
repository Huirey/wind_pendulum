#ifndef __MPUEXTI_H
#define __MPUEXTI_H

extern float pitch,roll,yaw;
extern short ax,ay,az;
extern short gx,gy,gz;

void MPU6050_EXTI_Init(void);

#endif