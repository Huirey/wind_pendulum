//#ifndef __DELAY_H
//#define __DELAY_H

//void delay_us(uint32_t us);
//void delay_ms(uint32_t ms);
//void delay_s(uint32_t s);

//#endif

#ifndef __DELAY_H
#define __DELAY_H 			   
#include "sys.h"  

void delay_init(void);
void delay_ms(u16 nms);
void delay_us(u32 nus);

#endif





























