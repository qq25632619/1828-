#ifndef __TIMER1_H__
#define __TIMER1_H__

#include "common.h"
#include "key.h"

extern u8 flag1 , flag2 ;  //两个软定时标志位，前者为LED亮的时间段，后者为灭
extern u16 soft_timer_counter  , led_on_time , led_off_time , for_led_press; //软定时自增变量，led亮时间，LED灭时间
extern u16 time_display_delay ; 
extern u8 aaa ; 
extern u8 adc_translate_delay ; 
extern u8 time_add_delay ; 

extern u16 key_3_delay ;  

extern void timer1_init(void) ; //定时器0初始化
extern void set_timer(u16 led_on_time_temp , u16 led_off_time_temp , VOID funtion1 , VOID funtion2) ;
extern VOID funtion_run ; 

#endif