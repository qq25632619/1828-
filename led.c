#include "led.h"

u16 code num[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f} ;
u8 time_for_set = 30 ; 
u8 level_for_temperature = 0 , level_for_foot = 0 ; 

void set_display(u16 display_data) 
{
	LED1 = 0 ; LED2 = 0 ; LED3 = 0 ; LED4 = 0 ; 
	LED5 = 0 ; LED6 = 0 ; LED7 = 0 ; LED8 = 0 ; 

	if(display_data & 0x01)
		LED6 = 1 ; 
	if(display_data & 0x02)
		LED5 = 1 ;
	if(display_data & 0x04)
		LED1 = 1 ; 
	if(display_data & 0x08)
		LED4 = 1 ; 

	if(display_data & 0x10)
		LED2 = 1 ; 
	if(display_data & 0x20)
		LED7 = 1 ; 
	if(display_data & 0x40)
		LED8 = 1 ; 
	if(display_data & 0x80)
		LED3 = 1 ; 	
}
/**************************************************/
void display_time()		//在此可以用状态机来实现以下各种if的判断以及数码管的迁移
{
	static 	u8 flag_display = 1 ; 
	
	if((time_display_delay >= display_delay) && (flag_display == 1)) //动态扫描间隔大于20毫秒，且先点亮第一位数码管
//	if(flag_display == 1)
	{
		ds1 = 0 ; ds2 = 0 ;	ds3 = 0 ;	ds4 = 0 ; ds5 = 0 ; //全部关闭，送完数据后再重新打开
		set_display(num[time_for_set/10]) ; 
		time_display_delay = 0 ; 
		flag_display = 2 ; 
		_nop_() ; _nop_() ; 
		ds2 = 1 ; 											//重开位选
	}
	
	if((time_display_delay >= display_delay) && (flag_display == 2))
//	if(flag_display == 2)
	{
		ds1 = 0 ; ds2 = 0 ;	ds3 = 0 ;	ds4 = 0 ; ds5 = 0 ; //全部关闭，送完数据后再重新打开
		set_display(num[time_for_set%10]) ;
		time_display_delay = 0 ; 
		flag_display = 3 ;
		_nop_() ; _nop_() ;
		ds1 = 1 ;											//重开位选
	}
/***********************************************************/	
	if((time_display_delay >= display_delay) && (flag_display == 3)) //动态扫描间隔大于20毫秒，且先点亮第一位数码管
//	if(flag_display == 3)
	{
		ds1 = 0 ; ds2 = 0 ;	ds3 = 0 ;	ds4 = 0 ; ds5 = 0 ; //全部关闭，送完数据后再重新打开 
		set_display(num[level_for_temperature]) ; 
		time_display_delay = 0 ; 
		flag_display = 4 ; 
		_nop_() ; _nop_() ;
		ds3 = 1 ;											//重开位选
	}
/***********************************************************/	
	if((time_display_delay >= display_delay) && (flag_display == 4))
//	if(flag_display == 4)
	{
		ds1 = 0 ; ds2 = 0 ;	ds3 = 0 ;	ds4 = 0 ; ds5 = 0 ; //全部关闭，送完数据后再重新打开
		set_display(num[level_for_foot/10]) ;
		time_display_delay = 0 ; 
		flag_display = 5 ;
		_nop_() ; _nop_() ;
		ds4 = 1 ;											//重开位选
	}

	if((time_display_delay >= display_delay) && (flag_display == 5))
//	if(flag_display == 5)
	{
		ds1 = 0 ; ds2 = 0 ;	ds3 = 0 ;	ds4 = 0 ; ds5 = 0 ; //全部关闭，送完数据后再重新打开
		set_display(num[level_for_foot%10]) ;
		time_display_delay = 0 ; 
		flag_display = 1 ;
		_nop_() ; _nop_() ;
		ds5 = 1 ; 											//重开位选
	}
/***********************************************************/	
}

//void display_2(u16 temp)  //动态扫描显示函数 显示电压
//{
//	u8 sin , ten , hun , thou	, t_thou ;
//	
//	t_thou = temp/10000 ; 
//	thou   = temp%10000/1000 ; 
//	hun    = temp%10000%1000/100 ;
//	ten    = temp%10000%1000%100/10 ;
//	sin	   = temp%10000%1000%100%10 ; 

//	ds1 = 0 ; ds2 = 1 ;	ds3 = 0 ;	ds4 = 0 ; ds5 = 0 ; 	
//	set_display(num[t_thou]) ; 
//	delay(13) ; 
//	
//	ds1 = 1 ; ds2 = 0 ;	ds3 = 0 ;	ds4 = 0 ; ds5 = 0 ;
//	set_display(num[thou]) ; 
//	delay(13) ; 
//	
//	ds1 = 0 ; ds2 = 0 ;	ds3 = 1 ;	ds4 = 0 ; ds5 = 0 ;
//	set_display(num[hun]) ; 
//	delay(13) ; 

//	ds1 = 0 ; ds2 = 0 ;	ds3 = 0 ;	ds4 = 1 ;	ds5 = 0 ;
//	set_display(num[ten]) ; 
//	delay(13) ;
//	
//	ds1 = 0 ; ds2 = 0 ;	ds3 = 0 ;	ds4 = 0 ;	ds5 = 1 ;
//	set_display(num[sin]) ; 
//	delay(13) ;
//}