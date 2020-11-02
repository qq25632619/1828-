#include "timer0.h"

u8 frequent_update_all = 0xff ; 

void timer0_init(void)
{
	TMOD &= 0xf0 ; //���4λ
	TMOD |= 0x02 ; //ģʽ2��8bit�Զ���װ
//	TMOD |= 0x01 ; //ģʽ1��16bit��ʱ������ģʽ

//	TH0 = 0x00 ;  //
//	TL0 = 0x00 ;
	
	TH0 = TL0 = frequent_update_all ;

	ET0 = 0 ;  //���жϻ�Ӱ�쾫�ȣ�����Ҫʱ��Ҫ��
//	ET0 = 1 ; 
	EA = 1 ; 
	TR0 = 1 ; 
}

void timer0_interrupt(void) interrupt 1
{
	TR0 = 0 ; //���Ķ�ʱ����ֵǰ����ý���ʱ��ֹͣ
	
	TH0 = TL0 = frequent_update_all ; 
	
//	TH0 = 0x00 ;  //
//	TL0 = 0xff ;
	
//	TH0 = 0x00 ;  //��ģʽ2ʱ��һ����Խ�TH0��TL0����Ϊͬһ��ֵ
//	TL0 = 0x00 ;
	
	TR0 = 1 ; //���¼���
}