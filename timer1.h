#ifndef __TIMER1_H__
#define __TIMER1_H__

#include "common.h"
#include "key.h"

extern u8 flag1 , flag2 ;  //������ʱ��־λ��ǰ��ΪLED����ʱ��Σ�����Ϊ��
extern u16 soft_timer_counter  , led_on_time , led_off_time , for_led_press; //��ʱ����������led��ʱ�䣬LED��ʱ��
extern u16 time_display_delay ; 
extern u8 aaa ; 
extern u8 adc_translate_delay ; 
extern u8 time_add_delay ; 

extern u16 key_3_delay ;  

extern void timer1_init(void) ; //��ʱ��0��ʼ��
extern void set_timer(u16 led_on_time_temp , u16 led_off_time_temp , VOID funtion1 , VOID funtion2) ;
extern VOID funtion_run ; 

#endif