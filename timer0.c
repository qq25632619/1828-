#include "timer0.h"

u8 frequent_update_all = 0xff ; 

void timer0_init(void)
{
	TMOD &= 0xf0 ; //清低4位
	TMOD |= 0x02 ; //模式2，8bit自动重装
//	TMOD |= 0x01 ; //模式1，16bit定时计数器模式

//	TH0 = 0x00 ;  //
//	TL0 = 0x00 ;
	
	TH0 = TL0 = frequent_update_all ;

	ET0 = 0 ;  //开中断会影响精度，不需要时不要开
//	ET0 = 1 ; 
	EA = 1 ; 
	TR0 = 1 ; 
}

void timer0_interrupt(void) interrupt 1
{
	TR0 = 0 ; //更改定时器初值前，最好将定时器停止
	
	TH0 = TL0 = frequent_update_all ; 
	
//	TH0 = 0x00 ;  //
//	TL0 = 0xff ;
	
//	TH0 = 0x00 ;  //在模式2时，一般可以将TH0和TL0设置为同一数值
//	TL0 = 0x00 ;
	
	TR0 = 1 ; //重新计数
}