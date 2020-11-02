#include "key.h"

extern u8 key_number = 0 ; 
extern u8 key_number_final = 0 ; 
u8 aaa = 0 , statues_run = 0 ; 
bit flag_key_3 = 0 ;
bit flag_led = 0 ;
u8 foot_statues = 0 ; 
u8 foot_pwm_width_table_index = 0 ;
bit time_control_flag = 0 ;

/*****************************************
*****************************************/
u8 adc_key_value_process(u16 adc_value)  //ͨ��adcֵ�����ֵ������..........�ú��������⣬��Ҫ��adc��ѹֵ���и��õĴ���
{
#if 1	
        u16 temp_adc_value = adc_value ; //�м����
        temp_adc_value /= 100 ; //��100��ģ��������Ҫ���߾��ȣ��ɸ�100Ϊ��Сֵ
        
        switch (temp_adc_value) //temp_adc_value���ȴ����������⣬��������һ��switch����жϼ�ֵ��ʹ��ѹֵת��Ϊ0-10������
        {
                case 41 :         //����1���µ�ѹֵΪ4100mV����
                        return 1 ;    //����1
                case 35 :
                        return 2 ; 
                case 30 :
                        return 3 ; 
                case 25 :
                        return 4 ; 
                case 21 :
                        return 5 ; 
                case 15 :
                        return 6 ; 
                case 10 :
                        return 7 ; 
                case 5 :
                        return 8 ; 
                case 0 :
                        return 9 ; 
                
                default :        //δ���£�����0
                        return 0 ; 
        }
#endif		
		
#if 0
/************************************************************************************************/		
				if((adc_value >=0 ) && (adc_value <= 5200)) //�����а������£��򰴼��Ժ� 
                {					
                        if((adc_value >= 0)  && (adc_value <= 200)) 
                                return key9;
                        else if((adc_value >  323)  && (adc_value <  723))  //+-200mV
                                return key8;
                        else if((adc_value >  854)  && (adc_value < 1254)) 
                                return key7;
                        else if((adc_value > 1342)  && (adc_value < 1742)) 
                                return key6;
                        else if((adc_value > 1938)  && (adc_value < 2338)) 
                                return key5;
                        else if((adc_value > 2378)  && (adc_value < 2778)) 
                                return key4;
                        else if((adc_value > 2837)  && (adc_value < 3237)) 
                                return key3;
                        else if((adc_value > 3393)  && (adc_value < 3793)) 
                                return key2;
                        else if((adc_value > 3906)  && (adc_value < 4306)) 
                                return key1;
                        else if((adc_value > 4550)  && (adc_value <= 5200))  //�ް�������
                                return key10;
						else 
							return 0 ;
					}
					else 
						return 0 ; 
/**************************************************************************************************/
#endif
}
/*****************************************
*****************************************/
void key_scan(void) //״̬������������״̬����ֵ
{
                static u8 key_statues = key_statues0 ; //�൱��������������ǰ�������꣬��Ҫ��0��Ҳ�ǳ�ʼ̬�������
                static u8 adc_key_number_temp = 0 ; 

				adc_key_number_temp = adc_key_value_process(adc_hex2dec(adc_result())) ;//�ɼ�adc����ת��Ϊ��ֵ
				key_number = adc_key_number_temp ; 
//				key_number = 8 ; 
				switch(key_statues)
				{
						case key_statues0 : //��ʼ̬,Ҳ�൱����						//��һ�ν���switch
								if(0 != key_number) //�����а������£���Ǩ����״̬1------�а�������ʱ��key_number����Ϊ0
										key_statues = key_statues1 ; 
						break ; 
						
						case key_statues1 : //����̬								//�ڶ��ν���switch
								if(0 == key_number)        //���ֻ�Ƕ������򷵻�״̬0
										key_statues = key_statues0 ; 
								
								else
								{
										key_statues = key_statues2 ;  //����ȷʵ�а��£���Ǩ�Ƶ�״̬2
										key_number_final = adc_key_number_temp ; //���ȷʵ�а������£��򱣴���ǰ��key_numberֵ�������ֺ󰴼���Чʱ��Ҫ
#if 1                                        										
										switch(adc_key_number_temp)        //���º��ֵ��Ч�����ж�adc_key_number_temp����
										{
												case 9 :
														aaa = key9 ; 
														break ; 
												
												case 8 :
														aaa = key8 ;
														break ; 
												
												case 7 :
														aaa = key7 ;
														break ; 
												
												case 6 :
														aaa = key6 ;
														break ; 
												
												case 5 :
														aaa = key5 ;
														break ; 
												
												case 4 :
														aaa = key4 ;
														break ; 
												
												case 3 :
														aaa = key3 ;
														break ; 
												
												case 2 :
														aaa = key2 ;
														break ; 
												
												case 1 :
														aaa = key1 ;
														break ; 
//												
//												case 0:			//δ����
//														aaa = 0 ;
//														break ; 
												
												default :
														aaa = 0 ; 
														break ; 
										}
#endif
								}
						break ; 
						
						case key_statues2 : //ȷ�ϰ���̬��ȷ�ϰ���֮���Ӧ���ж��Ƿ����֣�����������	//�����ν���switch
								if(0 == key_number)                //�������֣�Ǩ����״̬3���൱����������
										key_statues = key_statues3 ; 
						break ; 
						
						case key_statues3 : //����̬			//���Ĵν���switch
								if(0 == key_number) //ȷʵ�Ѿ�����
								{        
//										key_statues = key_statues0 ; //�����ȷ���ް������£���״̬Ǩ�ƻ�״̬0������ʼ̬���൱������
										adc_key_number_temp = 0 ; 
									
#if 0 
//										
//										switch(key_number_final)        //���ֺ��ֵ��Ч
//										{
//												case 9 :
//														aaa = key9 ; 
//														break ; 
//												
//												case 8 :
//														aaa = key8 ;
//														break ; 
//												
//												case 7 :
//														aaa = key7 ;
//														break ; 
//												
//												case 6 :
//														aaa = key6 ;
//														break ; 
//												
//												case 5 :
//														aaa = key5 ;
//														break ; 
//												
//												case 4 :
//														aaa = key4 ;
//														break ; 
//												
//												case 3 :
//														aaa = key3 ;
//														break ; 
//												
//												case 2 :
//														aaa = key2 ;
//														break ; 
//												
//												case 1 :
//														aaa = key1 ;
//														break ; 
////												
////												case 0:			//δ����
////														aaa = 0 ;
////														break ; 
//												
//												default :
//														aaa = 0 ; 
//														break ; 
//										}
#endif
										key_statues = key_statues0 ; //�����ȷ���ް������£���״̬Ǩ�ƻ�״̬0������ʼ̬���൱������
								}
								else	
								{
										aaa = 0 ; 
										key_statues = key_statues2 ; //����ص�״̬2�������ж�һ��
								}
						break ; 
				}
}

void key_process_display()	//���������������ʾ
{ 		
//		foot_functions() ; 
        switch(aaa)
        {
				case 0 :
					break ; 
			
                case key1 :   //ʱ��������ӣ�����Ϊ5����ʼ30�����60
//						aaa = 0 ; //������ֹһֱ����
						buzz = 0 ;
//						statues_run = 1 ; //������ű�־λ���������ܵ���������
						time_control_flag = 1 ; 
						if(time_add_delay >= 20)
						{
							statues_run = 1 ; //������ű�־λ���������ܵ���������
							time_add_delay = 0 ;
							time_control_flag = 0 ; 
							time_for_set += 5 ;
//							aaa = 0 ; //������ֹһֱ����
						}							
						if(time_for_set >= 60)
						{
							time_for_set = 60 ; 
//							aaa = 0 ; //������ֹһֱ����
						}
//						if(time_for_set >= 60)   
//							time_for_set = 60 ;
//						else 
//							time_for_set += 5 ; 
						aaa = 0 ; //������ֹһֱ����
                        break ;
                
                case key2 :			//������������						
						aaa = 0 ; 						
						buzz = 0 ;
						statues_run = 2 ;	
						
						if(level_for_temperature >= 9)
							level_for_temperature = 9 ; 
						else 
						{
//							time_control_flag = 1 ; 
//							if(time_add_delay >= 30)
//							{
//								time_add_delay = 0 ; 
//								time_control_flag = 0 ;
								level_for_temperature++ ;
//							}
						}
						aaa = 0 ; //������ֹһֱ����
                        break ; 
                
                case key3 :			//������������
						aaa = 0 ; 
						buzz = 0 ;	
						statues_run = 3 ;
						if(level_for_foot >= 30)
							level_for_foot = 30 ; 
						else 
							level_for_foot++ ;
						
						foot_statues = level_for_foot ; 
						aaa = 0 ; //������ֹһֱ����
                        break ; 
                
                case key4 :	 //ʱ����ڼ�С������Ϊ5����ʼΪ��һ������ʱ���ֵ����СΪ0
						aaa = 0 ; 
						buzz = 0 ;
						statues_run = 4 ;  
						if(time_for_set <= 0)		
							time_for_set = 0  ; 
						else
						{
//							time_control_flag = 1 ; 
//							if(time_add_delay >= 30)
//							{
								time_for_set -= 5 ;
//								time_control_flag = 0 ; 
//								time_add_delay = 0 ;
//							}
						}
						aaa = 0 ; //������ֹһֱ����
                        break ; 
                
                case key5 :	//���ļ��ȼ�С
						aaa = 0 ; 
						buzz = 0 ;
				
						if(level_for_temperature <= 0)
							level_for_temperature = 0 ; 
						else 
						{
//							time_control_flag = 1 ; 
//							if(time_add_delay >= 30)
//							{
//								time_control_flag = 0 ; 
//								time_add_delay = 0 ;
								level_for_temperature-- ;
//							}								
						}
						aaa = 0 ; //������ֹһֱ����
                        break ; 
                
                case key6 :	//���������С
						aaa = 0 ; 
						buzz = 0 ; 
						statues_run = 6 ; 
//						pwm_update_for_hot0_pwm0(0x23 , 0x99) ; 
						if(level_for_foot <= 0)
							level_for_foot = 0 ; 
						else 
							level_for_foot-- ;
						foot_statues = level_for_foot ; 
						aaa = 0 ; //������ֹһֱ����
                        break ; 
                
                case key7 : //���ػ�
						aaa = 0 ; 
						buzz = 0 ;
						statues_run = 7 ; 
						aaa = 0 ; 
                        break ; 
                
                case key8 : //����ǿ�ȣ�����
						aaa = 0 ; 
						buzz = 0 ;
						statues_run = 8 ; 
						aaa = 0 ; //������ֹһֱ����
                        break ; 
                
                case key9 : //��ͣ
						aaa = 0 ; 
						buzz = 0 ;
						statues_run = 9 ; 
						aaa = 0 ; //������ֹһֱ����
                        break ; 
				
//				case key10 :
//						aaa = 0 ; 
//						break ; 
				
				default :
						aaa = 0 ; 
						break ; 
		}
//		break ; 
}


void key_function(void)  	//������Ӧ����Ҫ����Ϊ����PWMռ�ձ� 
{
	static u8 i = 0 , j = 0 , m = 0 , n = 0 ; 

	switch(statues_run) 
	{
		case 1 :
			flag_led = 1 ; 
			set_timer(10 , 2000 , buzz_on , buzz_off) ;		//һ������40ms����Ƶ��Ϊ25Hz��ռ�ձ�50%
			break ; 
		case 2 :
			flag_led = 1 ; 
            set_timer(6 , 6 , led_on , led_off) ; 		//8Hz
			break ; 
		case 3 :
			flag_key_3 = 1 ; 
			set_timer(20 , 20  , led_on , led_off) ;
			if(key_3_delay >= 50) //ÿ�����һ��ռ�ձȣ�
			{
				++i ; 
				if(i >= foot_pwm_width_table_index)
					i = 0 ; 
				pwm_update_for_hot0_pwm0(0x80 , ~pwm_width_table[i]) ; 
				key_3_delay = 0 ;
			}
			break ; 
		case 4 :
//			set_timer(100 , 100  , led_on , led_off) ;
//			pwm_update_for_hot0_pwm0(0xff , 0x80) ; //���Ƶ�ʣ�ռ�ձ�50
//			TH0 = TL0 = 0x37 ; 
			break ; 
		case 5 :
			set_timer(200 , 200  , led_on , led_off) ;
			break ; 
		case 6 :
			flag_key_3 = 1 ;
			set_timer(300 , 300  , led_on , led_off) ;	
			if(key_3_delay >= 50) //ÿ�����һ��ռ�ձȣ�
			{
				++m ; 
				if(m >= foot_pwm_width_table_index)
					m = 0 ; 
				pwm_update_for_hot0_pwm0(0x80 , ~pwm_width_table[m]) ; 
				key_3_delay = 0 ;
			}
			break ; 
		case 7 :
			set_timer(400 , 400  , led_on , led_off) ; 
			break ; 
		case 8 :
			set_timer(500 , 500  , led_on , led_off) ; 
			break ; 
		case 9 :
			set_timer(600 , 600  , buzz_on , buzz_off) ;
			break ;  
	}
}

void foot_functions(void)	//�����ı�pwm��ȣ��仯����8������
{
	switch(foot_statues)
	{
		case foot_statues0 :
			foot_pwm_width_table_index = 0 ; 
			break ; 		
		case foot_statues1 :
			foot_pwm_width_table_index = 8 ; 
			break ; 		
		case foot_statues2 :
			foot_pwm_width_table_index = 16 ; 
			break ; 		
		case foot_statues3 :
			foot_pwm_width_table_index = 24 ; 
			break ; 		
		case foot_statues4 :
			foot_pwm_width_table_index = 32 ; 
			break ; 		
		case foot_statues5 :
			foot_pwm_width_table_index = 40 ; 
			break ; 		
		case foot_statues6 :
			foot_pwm_width_table_index = 48 ; 
			break ; 		
		case foot_statues7 :
			foot_pwm_width_table_index = 56 ; 
			break ; 		
		case foot_statues8 :
			foot_pwm_width_table_index = 64 ; 
			break ; 		
		case foot_statues9 :
			foot_pwm_width_table_index = 72 ; 
			break ; 
		case foot_statues10 :
			foot_pwm_width_table_index = 80 ; 
			break ; 
				
		case foot_statues11 :
			foot_pwm_width_table_index = 96 ; 
			break ; 		
		case foot_statues12 :
			foot_pwm_width_table_index = 106 ; 
			break ; 		
		case foot_statues13 :
			foot_pwm_width_table_index = 112 ; 
			break ; 		
		case foot_statues14 :
			foot_pwm_width_table_index = 120 ; 
			break ; 		
		case foot_statues15 :
			foot_pwm_width_table_index = 128 ; 
			break ; 		
		case foot_statues16 :
			foot_pwm_width_table_index = 136 ; 
			break ; 		
		case foot_statues17 :
			foot_pwm_width_table_index = 144 ; 
			break ; 		
		case foot_statues18 :
			foot_pwm_width_table_index = 152 ; 
			break ; 		
		case foot_statues19 :
			foot_pwm_width_table_index = 160 ; 
			break ; 
		case foot_statues20 :
			foot_pwm_width_table_index = 168 ; 
			break ; 
				
		case foot_statues21 :
			foot_pwm_width_table_index = 176 ; 
			break ; 		
		case foot_statues22 :
			foot_pwm_width_table_index = 184 ; 
			break ; 		
		case foot_statues23 :
			foot_pwm_width_table_index = 192 ; 
			break ; 		
		case foot_statues24 :
			foot_pwm_width_table_index = 200 ; 
			break ; 		
		case foot_statues25 :
			foot_pwm_width_table_index = 208 ; 
			break ; 		
		case foot_statues26 :
			foot_pwm_width_table_index = 216 ; 
			break ; 		
		case foot_statues27 :
			foot_pwm_width_table_index = 224 ; 
			break ; 		
		case foot_statues28 :
			foot_pwm_width_table_index = 232 ; 
			break ; 		
		case foot_statues29 :
			foot_pwm_width_table_index = 240 ; 
			break ; 
		case foot_statues30 :
			foot_pwm_width_table_index = 248 ; 
			break ; 
	}
}