//TODO:
//�����ͨ�˲��㷨 OK

#include "stm32f10x.h"
#include "PID.h"

//��ڲ���:��ǰX����ֵ,Ŀ��X����ֵ
//���:PWMֵ,ʹ��ʱ��Ҫ��������޷�
int Position_PID_X (float X_value,float Target_X)
{ 	
	static float error_sum=0,last_value=0,last_error=0;
	float error,bias;
	X_value=X_value*0.7+last_value*0.3;					//�����ͨ�˲��㷨
	error=X_value-Target_X;								//���㵱ǰ���
	error_sum+=error;									//���ּ��ϵ�ǰ���
	if(error_sum>MAX_IX) error_sum=MAX_IX;				//�Ի����޷�
	else if(error_sum<-MAX_IX) error_sum=-MAX_IX;
	bias=error-last_error;								//�����������֮��
	last_error=error;									//���浱ǰ���
	last_value=X_value;									//���浱ǰֵ,�Ա�����˲��㷨
	return PositionX_KP*error+PositionX_KD*bias+PositionX_KI*error_sum;
}


//��ڲ���:��ǰY����ֵ,Ŀ��Y����ֵ
//���:PWMֵ,ʹ��ʱ��Ҫ��������޷�
int Position_PID_Y (float Y_value,float Target_Y)
{ 	
	static float error_sum=0,last_value=0,last_error=0;
	float error,bias;
	Y_value=Y_value*0.7+last_value*0.3;					//�����ͨ�˲��㷨
	error=Y_value-Target_Y;								//���㵱ǰ���
	error_sum+=error;									//���ּ��ϵ�ǰ���
	if(error_sum>MAX_IY) error_sum=MAX_IY;				//�Ի����޷�
	else if(error_sum<-MAX_IY) error_sum=-MAX_IY;
	bias=error-last_error;								//�����������֮��
	last_error=error;									//���浱ǰ���
	last_value=Y_value;									//���浱ǰֵ,�Ա�����˲��㷨
	return PositionY_KP*error+PositionY_KD*bias+PositionY_KI*error_sum;
}