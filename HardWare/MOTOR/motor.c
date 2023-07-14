#include "motor.h"
#include "stm32f10x.h"
#include "Motor.h"

void Motor1_Init(void)	//A��B����IN1��IN2���ų�ʼ��
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //ʹ��PA�˿�ʱ��
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_4 |GPIO_Pin_6 |GPIO_Pin_7;	//�˿�����
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;      //�������
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;     //50M
    GPIO_Init(GPIOA, &GPIO_InitStructure);	//�����趨������ʼ��GPIOA
}

void Motor2_Init(void)	//A��B����IN1��IN2���ų�ʼ��
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //ʹ��PA�˿�ʱ��
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_4 |GPIO_Pin_6 |GPIO_Pin_7;	//�˿�����
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;      //�������
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;     //50M
    GPIO_Init(GPIOA, &GPIO_InitStructure);	//�����趨������ʼ��GPIOA
}


void Motor1_PWM_Init(u16 arr,u16 psc)	//A,B����PWM���ų�ʼ��,һ����100,72
{
    GPIO_InitTypeDef GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    TIM_OCInitTypeDef  TIM_OCInitStructure;

    Motor1_Init();

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//����ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 |GPIO_Pin_6; 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //�����������
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);//��ʼ����ʱ����
    TIM_TimeBaseStructure.TIM_Period = arr+1; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ
    TIM_TimeBaseStructure.TIM_Prescaler =psc+1; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  ����Ƶ
    TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
    TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ


    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1,���ϼ���ʱCNT<CCR����Ч.>=����Ч,
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
    TIM_OCInitStructure.TIM_Pulse = 0;                            //���ô�װ�벶��ȽϼĴ���������ֵ,������Ϊ0,��setspeed�������ٵ�������
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;     //�������:TIM����Ƚϼ��Ը�,��Ч���Ϊ�ߵ�ƽ
    TIM_OC2Init(TIM4, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx��ͨ��1
	TIM_OC1Init(TIM4, &TIM_OCInitStructure); 

    TIM_ARRPreloadConfig(TIM4, ENABLE); //ʹ��TIMx��ARR�ϵ�Ԥװ�ؼĴ���
	//���Բ���
    TIM_Cmd(TIM4, ENABLE);  //ʹ��TIM4
}

void Motor2_PWM_Init(u16 arr,u16 psc)	//A,B����PWM���ų�ʼ��,һ����100,72
{
    GPIO_InitTypeDef GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    TIM_OCInitTypeDef  TIM_OCInitStructure;

    Motor2_Init();

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//����ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 |GPIO_Pin_6; 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //�����������
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);//��ʼ����ʱ����
    TIM_TimeBaseStructure.TIM_Period = arr+1; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ
    TIM_TimeBaseStructure.TIM_Prescaler =psc+1; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  ����Ƶ
    TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
    TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ


    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1,���ϼ���ʱCNT<CCR����Ч.>=����Ч,
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
    TIM_OCInitStructure.TIM_Pulse = 0;                            //���ô�װ�벶��ȽϼĴ���������ֵ,������Ϊ0,��setspeed�������ٵ�������
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;     //�������:TIM����Ƚϼ��Ը�,��Ч���Ϊ�ߵ�ƽ
    TIM_OC2Init(TIM4, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx��ͨ��1
	TIM_OC1Init(TIM4, &TIM_OCInitStructure); 

    TIM_ARRPreloadConfig(TIM4, ENABLE); //ʹ��TIMx��ARR�ϵ�Ԥװ�ؼĴ���
	//���Բ���
    TIM_Cmd(TIM4, ENABLE);  //ʹ��TIM4
}



void Motor1A_SetSpeed(u16 speed,u8 mode)		//mode ��������ת speed PWMռ�ձȼ��ٶ�
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

void Motor1B_SetSpeed(u16 speed,u8 mode)		//mode ��������ת speed PWMռ�ձȼ��ٶ�
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

void Motor2A_SetSpeed(u16 speed,u8 mode)		//mode ��������ת speed PWMռ�ձȼ��ٶ�
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

void Motor2B_SetSpeed(u16 speed,u8 mode)		//mode ��������ת speed PWMռ�ձȼ��ٶ�
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