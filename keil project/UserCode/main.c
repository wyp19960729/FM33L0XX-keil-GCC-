#include "define_all.h"  
#include <string.h>
#define ADC_VREF    (*((uint16_t *)(0x1FFFFD08)))   // 30℃ vref1.22采样值

uint64_t GetVSample;
uint32_t Get122VSample;
uint32_t GetV;


void AdcInit(void)
{
    // 模块时钟
    RCC_OPC_CR2_ADCCKE_Setable(ENABLE);                 // ADC时钟使能
		RCC_OPC_CR2_ADCPRSC_Set(RCC_OPC_CR2_ADCPRSC_DIV8); // ADC时钟8分频
		RCC_OPC_CR2_ADCCKS_Set(RCC_OPC_CR2_ADCCKS_RCHF);    // ADC时钟 RCHF
	
	// 电源控制
		PMU_VREF_CR_EN_Setable(ENABLE);     // EN VREF1.22
		while(!PMU_VREF_SR_RDY_Chk());
	// 复位ADC模块
    RCC_PRST_EN_Write(RSTKEY0);
		RCC_APBRST_CR2_ADCRST_Setable(ENABLE);  // 数字部分复位
    RCC_APBRST_CR2_ADCRST_Setable(DISABLE);
    RCC_APBRST_CR2_ADCCRST_Setable(ENABLE); // 模拟部分复位
    RCC_APBRST_CR2_ADCCRST_Setable(DISABLE);
    RCC_PRST_EN_Write(RSTKEY1);

	//上电校准

		ADC_CR_ADEN_Setable(ENABLE);    // 使能ADC
		ADC_CAL_CALEN_Setable(ENABLE);  // Calibration使能，软件写1启动校准周期，硬件开始校准后自动清零。软件通过EOCAL寄存器查询校准周期结束。
		while(0 == ADC_ISR_EOCAL_Chk());
		ADC_ISR_EOCAL_Clr();            // 清校准结束
    ADC_CR_ADEN_Setable(DISABLE);   // 关闭ADC


    // ADC配置
		ADC_CAL_CONV_CAL_Set(ADC_CAL_CONV_CAL_USE_CAL); //ADC转换使用校准寄存器里的数据

		ADC_SMTR_SMTS1_Set(ADC_SMTR_SMTS1_10_5_TMCLK);
	// ADC配置寄存器
		ADC_CFGR_CKS_Set(ADC_CFGR_CKS_ADCCLK);  // ADCCLK
    ADC_CFGR_CONT_Setable(ENABLE);          // ENABLE：连续转换, DISABLE: 单次转换
    ADC_CFGR_OVRM_Set(ADC_CFGR_OVRM_COVER); // 当overrun发生时，覆盖上次数据
							
    
    GPIOx_ANEN_Setable(GPIOD, GPIO_Pin_2, ENABLE);
		AnalogIO(GPIOD, GPIO_Pin_2);

}

uint32_t GetVref1p22Sample(void)
{
		uint16 ADCRdresult;
		RCC_OPC_CR2_ADCPRSC_Set(RCC_OPC_CR2_ADCPRSC_DIV4); // ADC时钟4分频,VREF的驱动能力较弱,采样时间不能小于10.5*(1/2M)
		RCC_OPC_CR2_ADCCKE_Setable(ENABLE);         // ADC时钟使能
		PMU_BUF_CR_VREFBUFFER_EN_Setable(ENABLE);				// 电压通道使能
		ADC_CHER_REFCH_Setable(ENABLE);	            		// VREF测量通道使能
	
	    ADC_ISR_EOC_Clr();
    ADC_CR_ADEN_Setable(ENABLE);   // 启动ADC
    TicksDelayUs(3);                          // 软件延时至少5个ADC工作时钟	
		ADC_CR_START_Setable(ENABLE);  // 开始转换

    // 等待转换完成
    while (ADC_ISR_EOC_Chk() == RESET);
    ADC_ISR_EOC_Clr();
		ADCRdresult =ADC_DR_Read();

    ADC_CR_ADEN_Setable(DISABLE);   // 关闭ADC
    while(ADC_ISR_BUSY_Chk());
	  RCC_OPC_CR2_ADCCKE_Setable(DISABLE);        // ADC时钟关闭
    PMU_BUF_CR_VREFBUFFER_EN_Setable(DISABLE);  // 电压通道关闭
		ADC_CHER_REFCH_Setable(DISABLE);	        // VREF测量通道关闭	
		
    // 转换结果 
    return ADCRdresult;
}

uint32_t GetVoltageSample(void)
{
		uint08 i;
		uint16 ADCRdresult=0;
		RCC_OPC_CR2_ADCPRSC_Set(RCC_OPC_CR2_ADCPRSC_DIV1); // ADC时钟1分频
		RCC_OPC_CR2_ADCCKE_Setable(ENABLE);         // ADC时钟使能
		ADC_CHER_ECH5_Setable(ENABLE);	            // ADC_IN5测量通道使能
	
    ADC_CR_ADEN_Setable(ENABLE);   // 启动ADC
	  __NOP();__NOP();__NOP();__NOP();__NOP();    //软件延时至少5个ADC工作时钟
		ADC_CR_START_Setable(ENABLE);  // 开始转换
    ADC_ISR_EOC_Clr(); 
    for(i=0;i<8;i++)
		{
			while (ADC_ISR_EOC_Chk() == RESET);
			ADC_ISR_EOC_Clr();  
			ADCRdresult +=ADC_DR_Read();
		}
    ADC_CR_ADEN_Setable(DISABLE);   // 关闭ADC
    while(ADC_ISR_BUSY_Chk());
		RCC_OPC_CR2_ADCCKE_Setable(DISABLE);        // ADC时钟关闭
		ADC_CHER_ECH5_Setable(DISABLE);	            // ADC_IN5测量通道关闭

    // 转换结果 
    return (ADCRdresult/8);
}

int main (void)
{	    

		Init_System();			//系统初始化 
		AdcInit();

    for( ; ; )
    { 

			Get122VSample = GetVref1p22Sample();		

			GetVSample =GetVoltageSample(); 			
			GetV =  (GetVSample *1000*(ADC_VREF*3))/(Get122VSample*4095); 
                        
                        
		
    }	
}

