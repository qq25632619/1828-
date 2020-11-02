#include "common.h"
#include "timer1.h"
#include "timer0.h"
#include "key.h"
#include "gpio.h"
#include "led.h"
#include "pwm.h"

void delay(u16 iii)
{
	u16 temp = 0  ; 
	while(iii--)
		for(temp = 0 ; temp < 1000 ; temp++); 
}
/*****************************************
*****************************************/

u8 i = 48 ; 

void main()
{
	
		u8 i = 0 , j = 0 ; 
        led = 1 ;
	
//		seg_config.seg = 0x00 ; 
//		seg_config.seg_struct_select.seg1 = ds2 ; 
//		seg_config.seg_struct_select.seg2 = ds1 ; 
//		seg_config.seg_struct_select.seg3 = ds3 ; 
//		seg_config.seg_struct_select.seg4 = ds4 ; 
//		seg_config.seg_struct_select.seg5 = ds5 ; 
//	
	
		AUXR = 0xc0 ; //定时器0和定时器1均为1T模式
	
//		AUXR = 0x80 ; //定时器0为1T模式

//		AUXR = 0x00 ; //定时器0为12T模式
	
        gpio_init() ; 
        timer1_init() ; 
		timer0_init() ; 
        adc_init() ;
		pwm_init() ; 
        buzz = 0 ;
		set_display(0x3f) ; //先显示00 0 00
		ds1 = 0 ; ds2 = 0 ;	ds3 = 0 ;	ds4 = 0 ; ds5 = 0 ;  //关闭所有数码管	
		delay(500) ; 
	
        while(1)
        {        
//			key_process_display() ;	//主要为按键改变的全局变量
			key_function() ; //按键执行函数，调节各路占空比及频率等
//			display_time() ; //数码管显示函数
			foot_functions() ; //足疗脉冲调节
		}
}

