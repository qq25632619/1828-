#ifndef __KEY_H__
#define __KEY_H__

#include "common.h"
#include "adc.h"
#include "timer1.h"
#include "led.h"
#include "pwm.h"

enum key_number  //键值枚举声明
{
        key1 = 1 , key2 , 
        key3 , key4 , 
        key5 , key6 , 
        key7 , key8 , 
        key9   //代表未按下
} ; 

enum key_statues //按键状态枚举，分别为初始状态，按下状态，确认按下状态，松手状态
{
        key_statues0 = 0 , //初始态 
        key_statues1 = 1 , //按下态
        key_statues2 ,     //确认按下态
        key_statues3 ,     //松手态
} ;

enum foot_statues
{
	foot_statues0 = 0 ,
	foot_statues1 = 1 ,
	foot_statues2 , 
	foot_statues3 , 
	foot_statues4 , 
	foot_statues5 , 
	foot_statues6 , 
	foot_statues7 , 
	foot_statues8 , 
	foot_statues9 , 
	foot_statues10 ,
	
	foot_statues11 ,
	foot_statues12 , 
	foot_statues13 , 
	foot_statues14 , 
	foot_statues15 , 
	foot_statues16 , 
	foot_statues17 , 
	foot_statues18 , 
	foot_statues19 , 
	foot_statues20 ,
	
	foot_statues21  ,
	foot_statues22 , 
	foot_statues23 , 
	foot_statues24 , 
	foot_statues25 , 
	foot_statues26 , 
	foot_statues27 , 
	foot_statues28 , 
	foot_statues29 , 
	foot_statues30 ,
} ;  //足疗状态，跟按键相关

extern u8 foot_statues ; 
extern u8 foot_pwm_width_table_index ; 
extern u8 adc_key_value_process(u16 adc_value) ; //通过adc值定义键值并返回..........该函数有问题，需要对adc电压值进行更好的处理
extern void key_scan(void) ;  //状态机函数，返回状态机键值
extern void key_process_display() ; //数码管显示
extern void key_function(void) ; 
extern void foot_functions(void) ;	//按键改变，PWM宽度变化8个步长
extern bit flag_key_3 , flag_led ; 
extern bit time_control_flag ; 
#endif 