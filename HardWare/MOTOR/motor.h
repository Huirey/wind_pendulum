#ifndef __Motor_H
#define __Motor_H
#include "sys.h"

#define M1_PWMA   TIM4->CCR1     
#define M1_PWMB   TIM4->CCR2     
#define M2_PWMA   TIM4->CCR1     
#define M2_PWMB   TIM4->CCR2   

#define M1_AIN1   PAout(4)
#define M1_AIN2   PAout(5)
#define M1_BIN1   PAout(6)
#define M1_BIN2   PAout(7)

#define M1_AIN1   PAout(4)
#define M1_AIN2   PAout(5)
#define M1_BIN1   PAout(6)
#define M1_BIN2   PAout(7)

void Motor1_PWM_Init(u16 arr,u16 psc);
void Motor2_PWM_Init(u16 arr,u16 psc);
void Motor1A_SetSpeed(u16 speed,u8 mode);
void Motor1B_SetSpeed(u16 speed,u8 mode);
void Motor2A_SetSpeed(u16 speed,u8 mode);
void Motor2B_SetSpeed(u16 speed,u8 mode);



#endif
