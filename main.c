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
	
		AUXR = 0xc0 ; //��ʱ��0�Ͷ�ʱ��1��Ϊ1Tģʽ
	
//		AUXR = 0x80 ; //��ʱ��0Ϊ1Tģʽ

//		AUXR = 0x00 ; //��ʱ��0Ϊ12Tģʽ
	
        gpio_init() ; 
        timer1_init() ; 
		timer0_init() ; 
        adc_init() ;
		pwm_init() ; 
        buzz = 0 ;
		set_display(0x3f) ; //����ʾ00 0 00
		ds1 = 0 ; ds2 = 0 ;	ds3 = 0 ;	ds4 = 0 ; ds5 = 0 ;  //�ر����������	
		delay(500) ; 
	
        while(1)
        {        
//			key_process_display() ;	//��ҪΪ�����ı��ȫ�ֱ���
			key_function() ; //����ִ�к��������ڸ�·ռ�ձȼ�Ƶ�ʵ�
//			display_time() ; //�������ʾ����
			foot_functions() ; //�����������
		}
}

