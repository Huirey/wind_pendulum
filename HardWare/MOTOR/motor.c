#include "motor.h"
#include "stm32f10x.h"
#include "Motor.h"

void Motor1_Init(void)	//A和B马达的IN1和IN2引脚初始化
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //使能PA端口时钟
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_4 |GPIO_Pin_6 |GPIO_Pin_7;	//端口配置
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;      //推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;     //50M
    GPIO_Init(GPIOA, &GPIO_InitStructure);	//根据设定参数初始化GPIOA
}

void Motor2_Init(void)	//A和B马达的IN1和IN2引脚初始化
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //使能PA端口时钟
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_4 |GPIO_Pin_6 |GPIO_Pin_7;	//端口配置
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;      //推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;     //50M
    GPIO_Init(GPIOA, &GPIO_InitStructure);	//根据设定参数初始化GPIOA
}


void Motor1_PWM_Init(u16 arr,u16 psc)	//A,B马达的PWM引脚初始化,一般是100,72
{
    GPIO_InitTypeDef GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    TIM_OCInitTypeDef  TIM_OCInitStructure;

    Motor1_Init();

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//开启时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 |GPIO_Pin_6; 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //复用推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);//初始化定时器。
    TIM_TimeBaseStructure.TIM_Period = arr+1; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值
    TIM_TimeBaseStructure.TIM_Prescaler =psc+1; //设置用来作为TIMx时钟频率除数的预分频值  不分频
    TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
    TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位


    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式1,向上计数时CNT<CCR置有效.>=置无效,
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
    TIM_OCInitStructure.TIM_Pulse = 0;                            //设置待装入捕获比较寄存器的脉冲值,先设置为0,在setspeed函数中再单独设置
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;     //输出极性:TIM输出比较极性高,有效输出为高电平
    TIM_OC2Init(TIM4, &TIM_OCInitStructure);  //根据TIM_OCInitStruct中指定的参数初始化外设TIMx的通道1
	TIM_OC1Init(TIM4, &TIM_OCInitStructure); 

    TIM_ARRPreloadConfig(TIM4, ENABLE); //使能TIMx在ARR上的预装载寄存器
	//可以不用
    TIM_Cmd(TIM4, ENABLE);  //使能TIM4
}

void Motor2_PWM_Init(u16 arr,u16 psc)	//A,B马达的PWM引脚初始化,一般是100,72
{
    GPIO_InitTypeDef GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    TIM_OCInitTypeDef  TIM_OCInitStructure;

    Motor2_Init();

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//开启时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 |GPIO_Pin_6; 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //复用推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);//初始化定时器。
    TIM_TimeBaseStructure.TIM_Period = arr+1; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值
    TIM_TimeBaseStructure.TIM_Prescaler =psc+1; //设置用来作为TIMx时钟频率除数的预分频值  不分频
    TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
    TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位


    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式1,向上计数时CNT<CCR置有效.>=置无效,
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
    TIM_OCInitStructure.TIM_Pulse = 0;                            //设置待装入捕获比较寄存器的脉冲值,先设置为0,在setspeed函数中再单独设置
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;     //输出极性:TIM输出比较极性高,有效输出为高电平
    TIM_OC2Init(TIM4, &TIM_OCInitStructure);  //根据TIM_OCInitStruct中指定的参数初始化外设TIMx的通道1
	TIM_OC1Init(TIM4, &TIM_OCInitStructure); 

    TIM_ARRPreloadConfig(TIM4, ENABLE); //使能TIMx在ARR上的预装载寄存器
	//可以不用
    TIM_Cmd(TIM4, ENABLE);  //使能TIM4
}



void Motor1A_SetSpeed(u16 speed,u8 mode)		//mode 代表正反转 speed PWM占空比即速度
{
	if(mode==0){
		M1_AIN1=1;
		M1_AIN2=0;

	}
	else{
		M1_AIN1=0;
		M1_AIN2=1;
	}
	M1_PWMA=speed;
}

void Motor1B_SetSpeed(u16 speed,u8 mode)		//mode 代表正反转 speed PWM占空比即速度
{
	if(mode==0){
		M1_BIN1=1;
		M1_BIN2=0;

	}
	else{
		M1_BIN1=0;
		M1_BIN2=1;
	}
	M1_PWMB=speed;
}

void Motor2A_SetSpeed(u16 speed,u8 mode)		//mode 代表正反转 speed PWM占空比即速度
{
	if(mode==0){
		M1_BIN1=1;
		M1_BIN2=0;

	}
	else{
		M1_BIN1=0;
		M1_BIN2=1;
	}
	M1_PWMB=speed;
}

void Motor2B_SetSpeed(u16 speed,u8 mode)		//mode 代表正反转 speed PWM占空比即速度
{
	if(mode==0){
		M1_BIN1=1;
		M1_BIN2=0;

	}
	else{
		M1_BIN1=0;
		M1_BIN2=1;
	}
	M1_PWMB=speed;
}