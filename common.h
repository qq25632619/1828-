#ifndef __COMMON_H__
#define __COMMON_H__

#include "stc12c5630ad.h"
#include "intrins.h"

typedef unsigned char u8 ; 
typedef unsigned int u16 ; 
typedef void (*VOID)(void) ;  //先定义函数指针

#define buzz                P32
#define led                 P31
#define adc_key         	P11 
#define VCC                 5000

extern VOID funtion_run ; 

extern void buzz_on(void) ; 
extern void buzz_off(void) ; 
extern void led_on(void) ; 
extern void led_off(void) ; 


#endif 