/*******************
*
****HOT1-----P2.5
****HOT0-----P3.7/PWM0
****FAN------P2.7
****LASER----P2.6
****PD11-----P2.4/PWM3
****PWM1-----P3.5/PWM1
****PD12-----P0.1
*
*HOT0	PD11	PWM1			使用硬件PWM
*HOT1	FAN		LASER	PD12	使用定时器1模拟PWM
***************/


#ifndef __PWM_H__
#define __PWM_H__

#include "common.h"
#include "gpio.h"
#include "timer0.h"

#define hot1	P25
#define hot0 	P37
#define fan 	P27
#define laser	P26
#define pd11	P24
#define pwm1	P35
#define pd12	P01

#define fosc 16000000UL

extern void pwm_init(void) ; //pwm端口初始化等，配置初始频率，初始值等等信息。4个步骤最重要
extern void pwm_update_for_hot0_pwm0(u8 freq_for_pwm0 , u8 pwm_width_for_pwm0) ; //艾灸加热PWM更新，参数一为占空比，参数而为频率
extern void pwm_update_for_pd11(u8 freq_for_pd11 , u8 pwm_width_for_pd11) ; //足疗PWM更新，参数一为占空比，参数二为频率
extern void pwm_update_for_pwm1(u8 freq_for_pwm1 , u8 pwm_width_for_pwm1) ; //激光PWM更新，参数一为占空比，参数二为频率
//extern void pwm_update_for_fan(u8 pwm_width_for_fan , u8 freq_for_fan) ; //风扇PWM更新，参数一为占空比，参数二为频率
//extern 

extern u8 code pwm_frequent_table[256] ; 
extern u8 code pwm_width_table[256] ; 

#endif 