#include "adc.h"

void adc_init(void) //ADC初始化
{
        ADC_CONTR = 0x61 ;  //0110 0001 //关adc，270个周期转换一次，关标志位，关闭启动位，选择1通道
        adc_power_on ;         //重开adc
        adc_start_on ;         //开启转换
        adc_flag_clear ; //清adc转换标志位
}

u16 adc_result()  //获取ADC值
{
        u16 result = 0 ; //32bit数据装载10bit的adc转换结果值 
        u16 value = 0  ; 
        adc_init() ;         

        while(!(ADC_CONTR & 0x10)) ;  //& 0001 0000，若是完成转换，则bit5为1，与上0x10，仍为1，再取反为0，则跳过改行执行下一行 
        result = ADC_DATA*4 + ADC_LOW2 ; //ADC_DATA寄存器为8bit，左移两位，再加上ADC_LOW2的值，即可得到转换后完整的10bit结果
        adc_flag_clear ; //清除ADC_FLAG标志位

        return result ; 
}

u16 adc_hex2dec(float value) //16进制电压值转10进制，单位为mV毫伏
{
        float value_dec ; 
        value_dec = (VCC * (value))/1024 ;        
        
        return (u16)value_dec ; 
}

