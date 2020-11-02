#ifndef __ADC_H__
#define __ADC_H__

#include "common.h"
#include "led.h"


/*******************************************************************************************************************************/
//P1M0 , P1M1 , ADC_CONTR=[ADC_POWER][SPEED1][SPEED0][ADC_FLAG]    [ADC_START][CHS2][CHS1][CHS0]
//ADC_DATA , ADC_LOW2，AUXR=[T0x12][T1x12][UART_M0x12][EADCI][ESPI][ELVDI][-][-],IE,IP,IPH
/*******************************************************************************************************************************/
#define adc_power_on (ADC_CONTR |= 0x80)
#define adc_power_off (ADC_CONTR &= 0x7f)

#define adc_flag_set (ADC_CONTR |= 0x10)
#define adc_flag_clear (ADC_CONTR &= 0xef)

#define adc_start_on (ADC_CONTR |= 0x08)
#define adc_start_off (ADC_CONTR &= 0xf7)


void adc_init(void) ; //ADC初始化
u16 adc_result()  ; //获取ADC值
u16 adc_hex2dec(float value)  ; //16进制电压值转10进制，单位为mV毫伏


#endif 