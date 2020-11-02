#ifndef __LED_H__
#define __LED_H__

#include "common.h"
#include "timer1.h"

extern u16 code num[10] ; 
extern u8 time_for_set ;
extern u8 level_for_temperature , level_for_foot ; 

#define LED1 P16
#define LED2 P17
#define LED3 P20
#define LED4 P21
#define LED5 P15
#define LED6 P03
#define LED7 P14
#define LED8 P13

#define ds3 P02
#define ds1 P23
#define ds2 P22
#define ds4 P34
#define ds5 P33

#define display_delay 3
 
void set_display(u16 display_data) ; 
void display_time() ; 
	
#endif