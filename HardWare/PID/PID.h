#ifndef __PID_H
#define __PID_H
#define PositionX_KP 0
#define PositionX_KI 0
#define PositionX_KD 0

#define PositionY_KP 0
#define PositionY_KI 0
#define PositionY_KD 0

#define MAX_IX 0
#define MAX_IY 0

int Position_PID_X (float X_value,float Target_X);
int Position_PID_Y (float Y_value,float Target_Y);
#endif