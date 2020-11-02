#include "timer1.h"

u8 flag1 , flag2 ;  //������ʱ��־λ��ǰ��ΪLED����ʱ��Σ�����Ϊ��
u16 soft_timer_counter  , led_on_time , led_off_time ; //��ʱ����������led��ʱ�䣬LED��ʱ��
u8 adc_translate_delay = 0 ;

u16 key_3_delay = 0 ; 
u8 time_add_delay = 0 ; 


void timer0_init(void) ; //��ʱ��0��ʼ��
void set_timer(u16 led_on_time_temp , u16 led_off_time_temp , VOID funtion1 , VOID funtion2) ;
VOID funtion_run ; 

u16 time_display_delay = 0 ; 

/*****************************************
*****************************************/
void timer1_init(void)  //��ʱ��0��ʼ��
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
                funtion_run = funtion1 ; //ָ��ָ��������
                funtion_run() ;                  //��������ָ��ĺ���
        }
        if(flag2 == 1)
        {
                flag2 = 0 ;
                funtion_run = funtion2 ; //ָ��ָ������
                funtion_run() ;                  //��������ָ��ĺ���
        }
		flag_led = 0 ;
}

/*****************************************
*****************************************/
void timer1_interrupt(void) interrupt 3  //��ʱ��1�жϺ�����1ms�ж�
{
	#if 0 
        static u16 tt = 0 , pwm_tt = 0 ; 
//        TR1 = 0 ;
//        TH1 = 0xfa ; 
//        TL1 = 0xca ; 
//		TR1 = 1 ; 
	
       if(++tt >= 20) //20ms����һ��ɨ��
        {
                tt = 0 ; 
                key_scan() ; 
				key_process_display() ;	//��ҪΪ�����ı��ȫ�ֱ���
        } 	
		
		++time_display_delay ; 
		display_time() ; 
////		if(++time_display_delay >= display_delay) //��̬�������ʱ��������
//		{			
//			display_time() ;
//			time_display_delay = 0 ; 
//		}
	
		if(time_control_flag == 1)
			time_add_delay++ ; 
	
      

//		if(flag_led)
//		{
			if(++soft_timer_counter >= (led_on_time+led_off_time)) //�����ʱ�䣬ͬʱҲ���׿���ռ�ձȼ�on/��on+off�����Լ�Ƶ�ʼ�1000/(on+off)
					soft_timer_counter = 0 ;         //��0        
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
	
       if(++tt >= 20) //20ms����һ��ɨ��
        {
                tt = 0 ; 
                key_scan() ; 
				key_process_display() ;	//��ҪΪ�����ı��ȫ�ֱ���
        } 	
		
		++time_display_delay ; 
		display_time() ; 
	
		if(time_control_flag == 1)
			time_add_delay++ ; 
	
		if(++soft_timer_counter >= (led_on_time+led_off_time)) //�����ʱ�䣬ͬʱҲ���׿���ռ�ձȼ�on/��on+off�����Լ�Ƶ�ʼ�1000/(on+off)
				soft_timer_counter = 0 ;         //��0        
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