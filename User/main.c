#include "stm32f10x.h"           
#include "sys.h"
#include "delay.h"
#include "oled.h"
#include "mpu6050.h"  
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h" 
#include "mpuexti.h"
#include "usart.h"

int main(void)
{
	delay_init();
	OLED_Init();
	OLED_Clear();
	uart_init(115200);
	MPU6050_EXTI_Init();
	
	OLED_ShowString(0,6,"Initializing...",16);
	while(mpu_dmp_init())                        //等待初始化完成
	{
		delay_ms(20);
	}
	OLED_Clear();
	OLED_ShowString(0,6,"Initialized!",16);
	while(1){
		printf("$%f %f %f;",pitch,roll,yaw);
	}
}
