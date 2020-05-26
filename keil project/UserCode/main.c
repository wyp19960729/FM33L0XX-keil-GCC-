#include "define_all.h"  
#include <string.h>
#define ADC_VREF    (*((uint16_t *)(0x1FFFFD08)))   // 30�� vref1.22����ֵ

uint64_t GetVSample;
uint32_t Get122VSample;
uint32_t GetV;


void AdcInit(void)
{
    // ģ��ʱ��
    RCC_OPC_CR2_ADCCKE_Setable(ENABLE);                 // ADCʱ��ʹ��
		RCC_OPC_CR2_ADCPRSC_Set(RCC_OPC_CR2_ADCPRSC_DIV8); // ADCʱ��8��Ƶ
		RCC_OPC_CR2_ADCCKS_Set(RCC_OPC_CR2_ADCCKS_RCHF);    // ADCʱ�� RCHF
	
	// ��Դ����
		PMU_VREF_CR_EN_Setable(ENABLE);     // EN VREF1.22
		while(!PMU_VREF_SR_RDY_Chk());
	// ��λADCģ��
    RCC_PRST_EN_Write(RSTKEY0);
		RCC_APBRST_CR2_ADCRST_Setable(ENABLE);  // ���ֲ��ָ�λ
    RCC_APBRST_CR2_ADCRST_Setable(DISABLE);
    RCC_APBRST_CR2_ADCCRST_Setable(ENABLE); // ģ�ⲿ�ָ�λ
    RCC_APBRST_CR2_ADCCRST_Setable(DISABLE);
    RCC_PRST_EN_Write(RSTKEY1);

	//�ϵ�У׼

		ADC_CR_ADEN_Setable(ENABLE);    // ʹ��ADC
		ADC_CAL_CALEN_Setable(ENABLE);  // Calibrationʹ�ܣ����д1����У׼���ڣ�Ӳ����ʼУ׼���Զ����㡣���ͨ��EOCAL�Ĵ�����ѯУ׼���ڽ�����
		while(0 == ADC_ISR_EOCAL_Chk());
		ADC_ISR_EOCAL_Clr();            // ��У׼����
    ADC_CR_ADEN_Setable(DISABLE);   // �ر�ADC


    // ADC����
		ADC_CAL_CONV_CAL_Set(ADC_CAL_CONV_CAL_USE_CAL); //ADCת��ʹ��У׼�Ĵ����������

		ADC_SMTR_SMTS1_Set(ADC_SMTR_SMTS1_10_5_TMCLK);
	// ADC���üĴ���
		ADC_CFGR_CKS_Set(ADC_CFGR_CKS_ADCCLK);  // ADCCLK
    ADC_CFGR_CONT_Setable(ENABLE);          // ENABLE������ת��, DISABLE: ����ת��
    ADC_CFGR_OVRM_Set(ADC_CFGR_OVRM_COVER); // ��overrun����ʱ�������ϴ�����
							
    
    GPIOx_ANEN_Setable(GPIOD, GPIO_Pin_2, ENABLE);
		AnalogIO(GPIOD, GPIO_Pin_2);

}

uint32_t GetVref1p22Sample(void)
{
		uint16 ADCRdresult;
		RCC_OPC_CR2_ADCPRSC_Set(RCC_OPC_CR2_ADCPRSC_DIV4); // ADCʱ��4��Ƶ,VREF��������������,����ʱ�䲻��С��10.5*(1/2M)
		RCC_OPC_CR2_ADCCKE_Setable(ENABLE);         // ADCʱ��ʹ��
		PMU_BUF_CR_VREFBUFFER_EN_Setable(ENABLE);				// ��ѹͨ��ʹ��
		ADC_CHER_REFCH_Setable(ENABLE);	            		// VREF����ͨ��ʹ��
	
	    ADC_ISR_EOC_Clr();
    ADC_CR_ADEN_Setable(ENABLE);   // ����ADC
    TicksDelayUs(3);                          // �����ʱ����5��ADC����ʱ��	
		ADC_CR_START_Setable(ENABLE);  // ��ʼת��

    // �ȴ�ת�����
    while (ADC_ISR_EOC_Chk() == RESET);
    ADC_ISR_EOC_Clr();
		ADCRdresult =ADC_DR_Read();

    ADC_CR_ADEN_Setable(DISABLE);   // �ر�ADC
    while(ADC_ISR_BUSY_Chk());
	  RCC_OPC_CR2_ADCCKE_Setable(DISABLE);        // ADCʱ�ӹر�
    PMU_BUF_CR_VREFBUFFER_EN_Setable(DISABLE);  // ��ѹͨ���ر�
		ADC_CHER_REFCH_Setable(DISABLE);	        // VREF����ͨ���ر�	
		
    // ת����� 
    return ADCRdresult;
}

uint32_t GetVoltageSample(void)
{
		uint08 i;
		uint16 ADCRdresult=0;
		RCC_OPC_CR2_ADCPRSC_Set(RCC_OPC_CR2_ADCPRSC_DIV1); // ADCʱ��1��Ƶ
		RCC_OPC_CR2_ADCCKE_Setable(ENABLE);         // ADCʱ��ʹ��
		ADC_CHER_ECH5_Setable(ENABLE);	            // ADC_IN5����ͨ��ʹ��
	
    ADC_CR_ADEN_Setable(ENABLE);   // ����ADC
	  __NOP();__NOP();__NOP();__NOP();__NOP();    //�����ʱ����5��ADC����ʱ��
		ADC_CR_START_Setable(ENABLE);  // ��ʼת��
    ADC_ISR_EOC_Clr(); 
    for(i=0;i<8;i++)
		{
			while (ADC_ISR_EOC_Chk() == RESET);
			ADC_ISR_EOC_Clr();  
			ADCRdresult +=ADC_DR_Read();
		}
    ADC_CR_ADEN_Setable(DISABLE);   // �ر�ADC
    while(ADC_ISR_BUSY_Chk());
		RCC_OPC_CR2_ADCCKE_Setable(DISABLE);        // ADCʱ�ӹر�
		ADC_CHER_ECH5_Setable(DISABLE);	            // ADC_IN5����ͨ���ر�

    // ת����� 
    return (ADCRdresult/8);
}

int main (void)
{	    

		Init_System();			//ϵͳ��ʼ�� 
		AdcInit();

    for( ; ; )
    { 

			Get122VSample = GetVref1p22Sample();		

			GetVSample =GetVoltageSample(); 			
			GetV =  (GetVSample *1000*(ADC_VREF*3))/(Get122VSample*4095); 
                        
                        
		
    }	
}

