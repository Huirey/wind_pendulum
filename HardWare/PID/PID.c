//TODO:
//加入低通滤波算法 OK

#include "stm32f10x.h"
#include "PID.h"

//入口参数:当前X坐标值,目标X坐标值
//输出:PWM值,使用时需要进行输出限幅
int Position_PID_X (float X_value,float Target_X)
{ 	
	static float error_sum=0,last_value=0,last_error=0;
	float error,bias;
	X_value=X_value*0.7+last_value*0.3;					//加入低通滤波算法
	error=X_value-Target_X;								//计算当前误差
	error_sum+=error;									//积分加上当前误差
	if(error_sum>MAX_IX) error_sum=MAX_IX;				//对积分限幅
	else if(error_sum<-MAX_IX) error_sum=-MAX_IX;
	bias=error-last_error;								//计算两次误差之差
	last_error=error;									//保存当前误差
	last_value=X_value;									//保存当前值,以便进行滤波算法
	return PositionX_KP*error+PositionX_KD*bias+PositionX_KI*error_sum;
}


//入口参数:当前Y坐标值,目标Y坐标值
//输出:PWM值,使用时需要进行输出限幅
int Position_PID_Y (float Y_value,float Target_Y)
{ 	
	static float error_sum=0,last_value=0,last_error=0;
	float error,bias;
	Y_value=Y_value*0.7+last_value*0.3;					//加入低通滤波算法
	error=Y_value-Target_Y;								//计算当前误差
	error_sum+=error;									//积分加上当前误差
	if(error_sum>MAX_IY) error_sum=MAX_IY;				//对积分限幅
	else if(error_sum<-MAX_IY) error_sum=-MAX_IY;
	bias=error-last_error;								//计算两次误差之差
	last_error=error;									//保存当前误差
	last_value=Y_value;									//保存当前值,以便进行滤波算法
	return PositionY_KP*error+PositionY_KD*bias+PositionY_KI*error_sum;
}