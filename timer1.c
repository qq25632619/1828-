#include "timer1.h"

u8 flag1 , flag2 ;  //两个软定时标志位，前者为LED亮的时间段，后者为灭
u16 soft_timer_counter  , led_on_time , led_off_time ; //软定时自增变量，led亮时间，LED灭时间
u8 adc_translate_delay = 0 ;

u16 key_3_delay = 0 ; 
u8 time_add_delay = 0 ; 


void timer0_init(void) ; //定时器0初始化
void set_timer(u16 led_on_time_temp , u16 led_off_time_temp , VOID funtion1 , VOID funtion2) ;
VOID funtion_run ; 

u16 time_display_delay = 0 ; 

/*****************************************
*****************************************/
void timer1_init(void)  //定时器0初始化
{
        TMOD = 0x10 ; 
//        TH1 = 0xfa ;  //1ms,12T
//        TL1 = 0xca ;
        
//		TH1 = 0xc1 ;  //1ms,1T
//		TL0 = 0x80 ;
	
		TH0 = 0xf8 ; //125uS in 1T
		TL0 = 0x30 ; 
	
        ET1 = 1 ; 
        EA = 1 ; 
        
        TR1 = 1 ; 
}


void set_timer(u16 led_on_time_temp , u16 led_off_time_temp , VOID funtion1 , VOID funtion2) 
{      
        led_on_time = led_on_time_temp ; 
        led_off_time = led_off_time_temp ;
        
        if(flag1 == 1)
        {
                flag1 = 0 ; 
                funtion_run = funtion1 ; //指针指向亮函数
                funtion_run() ;                  //并运行所指向的函数
        }
        if(flag2 == 1)
        {
                flag2 = 0 ;
                funtion_run = funtion2 ; //指针指向灭函数
                funtion_run() ;                  //并运行所指向的函数
        }
		flag_led = 0 ;
}

/*****************************************
*****************************************/
void timer1_interrupt(void) interrupt 3  //定时器1中断函数，1ms中断
{
	#if 0 
        static u16 tt = 0 , pwm_tt = 0 ; 
//        TR1 = 0 ;
//        TH1 = 0xfa ; 
//        TL1 = 0xca ; 
//		TR1 = 1 ; 
	
       if(++tt >= 20) //20ms进行一次扫描
        {
                tt = 0 ; 
                key_scan() ; 
				key_process_display() ;	//主要为按键改变的全局变量
        } 	
		
		++time_display_delay ; 
		display_time() ; 
////		if(++time_display_delay >= display_delay) //动态数码管延时自增变量
//		{			
//			display_time() ;
//			time_display_delay = 0 ; 
//		}
	
		if(time_control_flag == 1)
			time_add_delay++ ; 
	
      

//		if(flag_led)
//		{
			if(++soft_timer_counter >= (led_on_time+led_off_time)) //亮灭的时间，同时也容易看出占空比即on/（on+off），以及频率即1000/(on+off)
					soft_timer_counter = 0 ;         //清0        
			if(soft_timer_counter < led_on_time)  
			{
					flag1 = 1 ;
	//				led_on() ; 
			}			
			else      
			{
					flag2 = 1 ;
	//				led_off() ; 
			}
//		}
		
//		if(++pwm_tt >= 60000)
//			pwm_tt = 0 ; 
		if(pwm_tt >= 5000)
			laser = 1 ; 
		else 
			laser = 0 ; 

		if(flag_key_3)
			key_3_delay++ ; 
		
	    TH1 = 0xc1 ; 
        TL1 = 0x80 ; 
		
//        TH1 = 0xfa ;  //1ms,12T
//        TL1 = 0xca ;	
	#endif
		
       static u16 tt = 0 , pwm_tt = 0 ; 
	
       if(++tt >= 20) //20ms进行一次扫描
        {
                tt = 0 ; 
                key_scan() ; 
				key_process_display() ;	//主要为按键改变的全局变量
        } 	
		
		++time_display_delay ; 
		display_time() ; 
	
		if(time_control_flag == 1)
			time_add_delay++ ; 
	
		if(++soft_timer_counter >= (led_on_time+led_off_time)) //亮灭的时间，同时也容易看出占空比即on/（on+off），以及频率即1000/(on+off)
				soft_timer_counter = 0 ;         //清0        
		if(soft_timer_counter < led_on_time)  
		{
				flag1 = 1 ;
		}			
		else      
		{
				flag2 = 1 ;
		}
		
		if(pwm_tt >= 5000)
			laser = 1 ; 
		else 
			laser = 0 ; 

		if(flag_key_3)
			key_3_delay++ ; 
		
	    TH1 = 0xf8 ; 
        TL1 = 0x30 ; 
}