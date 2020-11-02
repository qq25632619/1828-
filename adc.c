#include "adc.h"

void adc_init(void) //ADC��ʼ��
{
        ADC_CONTR = 0x61 ;  //0110 0001 //��adc��270������ת��һ�Σ��ر�־λ���ر�����λ��ѡ��1ͨ��
        adc_power_on ;         //�ؿ�adc
        adc_start_on ;         //����ת��
        adc_flag_clear ; //��adcת����־λ
}

u16 adc_result()  //��ȡADCֵ
{
        u16 result = 0 ; //32bit����װ��10bit��adcת�����ֵ 
        u16 value = 0  ; 
        adc_init() ;         

        while(!(ADC_CONTR & 0x10)) ;  //& 0001 0000���������ת������bit5Ϊ1������0x10����Ϊ1����ȡ��Ϊ0������������ִ����һ�� 
        result = ADC_DATA*4 + ADC_LOW2 ; //ADC_DATA�Ĵ���Ϊ8bit��������λ���ټ���ADC_LOW2��ֵ�����ɵõ�ת����������10bit���
        adc_flag_clear ; //���ADC_FLAG��־λ

        return result ; 
}

u16 adc_hex2dec(float value) //16���Ƶ�ѹֵת10���ƣ���λΪmV����
{
        float value_dec ; 
        value_dec = (VCC * (value))/1024 ;        
        
        return (u16)value_dec ; 
}

