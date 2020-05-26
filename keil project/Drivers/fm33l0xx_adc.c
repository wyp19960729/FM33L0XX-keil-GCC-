/**
  ******************************************************************************
  * @file    fm33l0xx_adc.c
  * @author  FM33L0 Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33l0xx_adc.h" 
#include "fm33l0xx_rcc.h" 

/** @addtogroup fm33l0_StdPeriph_Driver
  * @{
  */

/** @defgroup ADC 
  * @brief ADC driver modules
  * @{
  */ 
  

/* 模拟看门狗超出上限中断标志 (Analog Watchdog Above High Threshold)当采样值高于AWD_HT时，硬件置位，软件写1清零. 相关函数 */
void ADC_ISR_AWD_AH_Clr(void)
{
	ADC->ISR = ADC_ISR_AWD_AH_Msk;
}

FlagStatus ADC_ISR_AWD_AH_Chk(void)
{
	if (ADC->ISR & ADC_ISR_AWD_AH_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 模拟看门狗低于下限中断标志 (Analog Watchdog Under Low Threshold)当采样值低于AWD_LT时，硬件置位，软件写1清零 相关函数 */
void ADC_ISR_AWD_UL_Clr(void)
{
	ADC->ISR = ADC_ISR_AWD_UL_Msk;
}

FlagStatus ADC_ISR_AWD_UL_Chk(void)
{
	if (ADC->ISR & ADC_ISR_AWD_UL_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 校准结束 (End Of Calibration)硬件置位，软件写1清零1：校准过程结束0：无校准过程 相关函数 */
void ADC_ISR_EOCAL_Clr(void)
{
	ADC->ISR = ADC_ISR_EOCAL_Msk;
}

FlagStatus ADC_ISR_EOCAL_Chk(void)
{
	if (ADC->ISR & ADC_ISR_EOCAL_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ADC忙标志 (Busy) 1：ADC正在校准、采样或转换过程中 0：ADC空闲 相关函数 */
FlagStatus ADC_ISR_BUSY_Chk(void)
{
	if (ADC->ISR & ADC_ISR_BUSY_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 数据冲突标志，硬件置位，软件写1清零 (Over Run) 当ADC_DATA寄存器中的上一次转换结果还未被读取，新的转换结果又到来时，硬件置位OVR标志。0：没有数据冲突 1：出现数据冲突 相关函数 */
void ADC_ISR_OVR_Clr(void)
{
	ADC->ISR = ADC_ISR_OVR_Msk;
}

FlagStatus ADC_ISR_OVR_Chk(void)
{
	if (ADC->ISR & ADC_ISR_OVR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 转换序列结束 (End Of Sequence)所有使能通道都转换完成后，置位EOS，软件写1清零。 相关函数 */
void ADC_ISR_EOS_Clr(void)
{
	ADC->ISR = ADC_ISR_EOS_Msk;
}

FlagStatus ADC_ISR_EOS_Chk(void)
{
	if (ADC->ISR & ADC_ISR_EOS_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 单次转换结束 (End Of Conversion)每个通道转换完成后，置位EOC，软件写1清零。 相关函数 */
void ADC_ISR_EOC_Clr(void)
{
	ADC->ISR = ADC_ISR_EOC_Msk;
}

FlagStatus ADC_ISR_EOC_Chk(void)
{
	if (ADC->ISR & ADC_ISR_EOC_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 模拟看门狗采样值高于上限中断使能，1有效 (Analog Watchdog Above High Threshold Interrupt Enable) 相关函数 */
void ADC_IER_AWD_AHIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->IER |= (ADC_IER_AWD_AHIE_Msk);
	}
	else
	{
		ADC->IER &= ~(ADC_IER_AWD_AHIE_Msk);
	}
}

FunState ADC_IER_AWD_AHIE_Getable(void)
{
	if (ADC->IER & (ADC_IER_AWD_AHIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 模拟看门狗采样值低于上限中断使能，1有效 (Analog Watchdog Under Low Threshold Interrupt Enable) 相关函数 */
void ADC_IER_AWD_ULIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->IER |= (ADC_IER_AWD_ULIE_Msk);
	}
	else
	{
		ADC->IER &= ~(ADC_IER_AWD_ULIE_Msk);
	}
}

FunState ADC_IER_AWD_ULIE_Getable(void)
{
	if (ADC->IER & (ADC_IER_AWD_ULIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 校准结束中断使能寄存器 (End Of Calibration Interrupt Enable) 0：禁止EOCAL中断 1：允许EOCAL中断 相关函数 */
void ADC_IER_EOCALIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->IER |= (ADC_IER_EOCALIE_Msk);
	}
	else
	{
		ADC->IER &= ~(ADC_IER_EOCALIE_Msk);
	}
}

FunState ADC_IER_EOCALIE_Getable(void)
{
	if (ADC->IER & (ADC_IER_EOCALIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 数据冲突中断使能寄存器 (Over Run Interrupt Enable) 0：禁止数据冲突中断 1：允许数据冲突中断 相关函数 */
void ADC_IER_OVRIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->IER |= (ADC_IER_OVRIE_Msk);
	}
	else
	{
		ADC->IER &= ~(ADC_IER_OVRIE_Msk);
	}
}

FunState ADC_IER_OVRIE_Getable(void)
{
	if (ADC->IER & (ADC_IER_OVRIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 转换序列结束中断使能寄存器 (End Of Sequence Interrupt Enable) 0：禁止EOS中断 1：允许EOS中断 相关函数 */
void ADC_IER_EOSIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->IER |= (ADC_IER_EOSIE_Msk);
	}
	else
	{
		ADC->IER &= ~(ADC_IER_EOSIE_Msk);
	}
}

FunState ADC_IER_EOSIE_Getable(void)
{
	if (ADC->IER & (ADC_IER_EOSIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 单次转换结束中断使能寄存器 (End Of Conversion Interrupt Enable) 0：禁止EOC中断 1：允许EOC中断 相关函数 */
void ADC_IER_EOCIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->IER |= (ADC_IER_EOCIE_Msk);
	}
	else
	{
		ADC->IER &= ~(ADC_IER_EOCIE_Msk);
	}
}

FunState ADC_IER_EOCIE_Getable(void)
{
	if (ADC->IER & (ADC_IER_EOCIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ADC启动转换寄存器，软件写1启动，硬件自动清零。 相关函数 */
void ADC_CR_START_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->CR |= (ADC_CR_START_Msk);
	}
	else
	{
		ADC->CR &= ~(ADC_CR_START_Msk);
	}
}

FunState ADC_CR_START_Getable(void)
{
	if (ADC->CR & (ADC_CR_START_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ADC使能寄存器 (ADC Enable) 在启动转换前先要置位ADEN，等待至少5个MCLK后再启动转换。0：关闭ADC 1：使能ADC 相关函数 */
void ADC_CR_ADEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->CR |= (ADC_CR_ADEN_Msk);
	}
	else
	{
		ADC->CR &= ~(ADC_CR_ADEN_Msk);
	}
}

FunState ADC_CR_ADEN_Getable(void)
{
	if (ADC->CR & (ADC_CR_ADEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ADC工作时钟选择 (ADC Clock Select) 相关函数 */
void ADC_CFGR_CKS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ADC->CFGR;
	tmpreg &= ~(ADC_CFGR_CKS_Msk);
	tmpreg |= (SetValue & ADC_CFGR_CKS_Msk);
	ADC->CFGR = tmpreg;
}

uint32_t ADC_CFGR_CKS_Get(void)
{
	return (ADC->CFGR & ADC_CFGR_CKS_Msk);
}

/* 模拟窗口看门狗监视通道选择，仅在AWDSC=1时有效 (Analog Watchdog Channel Select) 相关函数 */
void ADC_CFGR_AWDCH_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ADC->CFGR;
	tmpreg &= ~(ADC_CFGR_AWDCH_Msk);
	tmpreg |= (SetValue & ADC_CFGR_AWDCH_Msk);
	ADC->CFGR = tmpreg;
}

uint32_t ADC_CFGR_AWDCH_Get(void)
{
	return (ADC->CFGR & ADC_CFGR_AWDCH_Msk);
}

/* 模拟窗口看门狗单通道或全通道选择 (Analog Watchdog Single Channel mode) 相关函数 */
void ADC_CFGR_AWDSC_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ADC->CFGR;
	tmpreg &= ~(ADC_CFGR_AWDSC_Msk);
	tmpreg |= (SetValue & ADC_CFGR_AWDSC_Msk);
	ADC->CFGR = tmpreg;
}

uint32_t ADC_CFGR_AWDSC_Get(void)
{
	return (ADC->CFGR & ADC_CFGR_AWDSC_Msk);
}

/* 模拟窗口看门狗使能寄存器 (Analog Watchdog Enable) 0：关闭AWD 1：使能AWD 仅能在START=0的情况下使能AWD 相关函数 */
void ADC_CFGR_AWDEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->CFGR |= (ADC_CFGR_AWDEN_Msk);
	}
	else
	{
		ADC->CFGR &= ~(ADC_CFGR_AWDEN_Msk);
	}
}

FunState ADC_CFGR_AWDEN_Getable(void)
{
	if (ADC->CFGR & (ADC_CFGR_AWDEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 过采样移位控制寄存器 (Oversampling Shift) 相关函数 */
void ADC_CFGR_OVSS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ADC->CFGR;
	tmpreg &= ~(ADC_CFGR_OVSS_Msk);
	tmpreg |= (SetValue & ADC_CFGR_OVSS_Msk);
	ADC->CFGR = tmpreg;
}

uint32_t ADC_CFGR_OVSS_Get(void)
{
	return (ADC->CFGR & ADC_CFGR_OVSS_Msk);
}

/* 过采样率控制 (Oversampling Ratio) 相关函数 */
void ADC_CFGR_OVSR_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ADC->CFGR;
	tmpreg &= ~(ADC_CFGR_OVSR_Msk);
	tmpreg |= (SetValue & ADC_CFGR_OVSR_Msk);
	ADC->CFGR = tmpreg;
}

uint32_t ADC_CFGR_OVSR_Get(void)
{
	return (ADC->CFGR & ADC_CFGR_OVSR_Msk);
}

/* 过采样使能 (Oversampling Enable) 0：禁止过采样 1：使能过采样 相关函数 */
void ADC_CFGR_OVSEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->CFGR |= (ADC_CFGR_OVSEN_Msk);
	}
	else
	{
		ADC->CFGR &= ~(ADC_CFGR_OVSEN_Msk);
	}
}

FunState ADC_CFGR_OVSEN_Getable(void)
{
	if (ADC->CFGR & (ADC_CFGR_OVSEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 引脚触发信号数字滤波使能 (GPIO Trigger Filter Enable) 0：禁止数字滤波 1：使能数字滤波  相关函数 */
void ADC_CFGR_IOTRFEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->CFGR |= (ADC_CFGR_IOTRFEN_Msk);
	}
	else
	{
		ADC->CFGR &= ~(ADC_CFGR_IOTRFEN_Msk);
	}
}

FunState ADC_CFGR_IOTRFEN_Getable(void)
{
	if (ADC->CFGR & (ADC_CFGR_IOTRFEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 触发信号使能和极性选择 (Trigger Config) 相关函数 */
void ADC_CFGR_TRGCFG_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ADC->CFGR;
	tmpreg &= ~(ADC_CFGR_TRGCFG_Msk);
	tmpreg |= (SetValue & ADC_CFGR_TRGCFG_Msk);
	ADC->CFGR = tmpreg;
}

uint32_t ADC_CFGR_TRGCFG_Get(void)
{
	return (ADC->CFGR & ADC_CFGR_TRGCFG_Msk);
}

/* 单次转换半自动模式 (Semi-automatic)，仅在单次转换（CONT=0）时有效 相关函数 */
void ADC_CFGR_SEMI_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ADC->CFGR;
	tmpreg &= ~(ADC_CFGR_SEMI_Msk);
	tmpreg |= (SetValue & ADC_CFGR_SEMI_Msk);
	ADC->CFGR = tmpreg;
}

uint32_t ADC_CFGR_SEMI_Get(void)
{
	return (ADC->CFGR & ADC_CFGR_SEMI_Msk);
}

/* 等待模式控制 (wait mode) 0：无等待，如果上次转换数据没有及时读取，则可能出现Overrun 1：等待模式，在上次转换数据被读取前，不会启动下一次转换 相关函数 */
void ADC_CFGR_WAIT_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->CFGR |= (ADC_CFGR_WAIT_Msk);
	}
	else
	{
		ADC->CFGR &= ~(ADC_CFGR_WAIT_Msk);
	}
}

FunState ADC_CFGR_WAIT_Getable(void)
{
	if (ADC->CFGR & (ADC_CFGR_WAIT_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 连续转换模式使能 (Continuous mode) 0：单次转换 1：连续转换  相关函数 */
void ADC_CFGR_CONT_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->CFGR |= (ADC_CFGR_CONT_Msk);
	}
	else
	{
		ADC->CFGR &= ~(ADC_CFGR_CONT_Msk);
	}
}

FunState ADC_CFGR_CONT_Getable(void)
{
	if (ADC->CFGR & (ADC_CFGR_CONT_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Overrun模式控制 (Overrun mode) 相关函数 */
void ADC_CFGR_OVRM_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ADC->CFGR;
	tmpreg &= ~(ADC_CFGR_OVRM_Msk);
	tmpreg |= (SetValue & ADC_CFGR_OVRM_Msk);
	ADC->CFGR = tmpreg;
}

uint32_t ADC_CFGR_OVRM_Get(void)
{
	return (ADC->CFGR & ADC_CFGR_OVRM_Msk);
}

/* 硬件触发源选择 (External trigger select) 相关函数 */
void ADC_CFGR_EXTS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ADC->CFGR;
	tmpreg &= ~(ADC_CFGR_EXTS_Msk);
	tmpreg |= (SetValue & ADC_CFGR_EXTS_Msk);
	ADC->CFGR = tmpreg;
}

uint32_t ADC_CFGR_EXTS_Get(void)
{
	return (ADC->CFGR & ADC_CFGR_EXTS_Msk);
}

/* ADC低功耗模式使能，软件可以配置 (Low Power Mode) 相关函数 */
void ADC_CFGR_LPM_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ADC->CFGR;
	tmpreg &= ~(ADC_CFGR_LPM_Msk);
	tmpreg |= (SetValue & ADC_CFGR_LPM_Msk);
	ADC->CFGR = tmpreg;
}

uint32_t ADC_CFGR_LPM_Get(void)
{
	return (ADC->CFGR & ADC_CFGR_LPM_Msk);
}

/* 通道扫描顺序控制 (Scan Direction)（共16个通道，实际只会采样被使能的通道） 相关函数 */
void ADC_CFGR_SCANDIR_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ADC->CFGR;
	tmpreg &= ~(ADC_CFGR_SCANDIR_Msk);
	tmpreg |= (SetValue & ADC_CFGR_SCANDIR_Msk);
	ADC->CFGR = tmpreg;
}

uint32_t ADC_CFGR_SCANDIR_Get(void)
{
	return (ADC->CFGR & ADC_CFGR_SCANDIR_Msk);
}

/* DMA模式控制 (DMA Config) 相关函数 */
void ADC_CFGR_DMACFG_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ADC->CFGR;
	tmpreg &= ~(ADC_CFGR_DMACFG_Msk);
	tmpreg |= (SetValue & ADC_CFGR_DMACFG_Msk);
	ADC->CFGR = tmpreg;
}

uint32_t ADC_CFGR_DMACFG_Get(void)
{
	return (ADC->CFGR & ADC_CFGR_DMACFG_Msk);
}

/* DMA使能 (DMA Enable) 0：禁止DMA 1：使能DMA  相关函数 */
void ADC_CFGR_DMAEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->CFGR |= (ADC_CFGR_DMAEN_Msk);
	}
	else
	{
		ADC->CFGR &= ~(ADC_CFGR_DMAEN_Msk);
	}
}

FunState ADC_CFGR_DMAEN_Getable(void)
{
	if (ADC->CFGR & (ADC_CFGR_DMAEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ADC采样通道切换等待时间 (Channel Clock Gating) 在当前通道采样周期完成后，等待CHCG时间（CHCG*ADC工作时钟周期），再切换到下一个采样通道 相关函数 */
void ADC_SMTR_CHCG_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ADC->SMTR;
	tmpreg &= ~(ADC_SMTR_CHCG_Msk);
	tmpreg |= (SetValue & ADC_SMTR_CHCG_Msk);
	ADC->SMTR = tmpreg;
}

uint32_t ADC_SMTR_CHCG_Get(void)
{
	return (ADC->SMTR & ADC_SMTR_CHCG_Msk);
}

/* 慢速通道采样时间控制（*ADC工作时钟周期），用于配置ADC_IN8/9/10/11四个外部通道、以及OPA通道的采样时间 (Sampling Time Select 2)  相关函数 */
void ADC_SMTR_SMTS2_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ADC->SMTR;
	tmpreg &= ~(ADC_SMTR_SMTS2_Msk);
	tmpreg |= (SetValue & ADC_SMTR_SMTS2_Msk);
	ADC->SMTR = tmpreg;
}

uint32_t ADC_SMTR_SMTS2_Get(void)
{
	return (ADC->SMTR & ADC_SMTR_SMTS2_Msk);
}

/* 快速通道采样时间控制（*ADC工作时钟周期），用于配置ADC_IN8/9/10/11四个外部通道、以及OPA通道的采样时间 (Sampling Time Select 2)  相关函数 */
void ADC_SMTR_SMTS1_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ADC->SMTR;
	tmpreg &= ~(ADC_SMTR_SMTS1_Msk);
	tmpreg |= (SetValue & ADC_SMTR_SMTS1_Msk);
	ADC->SMTR = tmpreg;
}

uint32_t ADC_SMTR_SMTS1_Get(void)
{
	return (ADC->SMTR & ADC_SMTR_SMTS1_Msk);
}

/* 单端和差分通道配置，4bit配置4组通道对是否为差分输入，0表示单端输入，1表示差分输入。(Analog Input Select)如果配置为差分输入，则每个差分对所对应的通道都要使能。
比如，将ADC_IN0和ADC_IN1设置为差分输入对，需要进行差分采样时，ECH0和ECH1都要置1。 相关函数 */
void ADC_CHER_AINS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ADC->CHER;
	tmpreg &= ~(ADC_CHER_AINS_Msk);
	tmpreg |= (SetValue & ADC_CHER_AINS_Msk);
	ADC->CHER = tmpreg;
}

uint32_t ADC_CHER_AINS_Get(void)
{
	return (ADC->CHER & ADC_CHER_AINS_Msk);
}

/* OPA2输出测量，写1使能 (OPA2 channel)  相关函数 */
void ADC_CHER_OPA2CH_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->CHER |= (ADC_CHER_OPA2CH_Msk);
	}
	else
	{
		ADC->CHER &= ~(ADC_CHER_OPA2CH_Msk);
	}
}

FunState ADC_CHER_OPA2CH_Getable(void)
{
	if (ADC->CHER & (ADC_CHER_OPA2CH_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* OPA1输出测量，写1使能 (OPA1 channel)  相关函数 */
void ADC_CHER_OPA1CH_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->CHER |= (ADC_CHER_OPA1CH_Msk);
	}
	else
	{
		ADC->CHER &= ~(ADC_CHER_OPA1CH_Msk);
	}
}

FunState ADC_CHER_OPA1CH_Getable(void)
{
	if (ADC->CHER & (ADC_CHER_OPA1CH_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 温度传感器测量通道，写1使能 (TempSensor channel)  相关函数 */
void ADC_CHER_TSCH_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->CHER |= (ADC_CHER_TSCH_Msk);
	}
	else
	{
		ADC->CHER &= ~(ADC_CHER_TSCH_Msk);
	}
}

FunState ADC_CHER_TSCH_Getable(void)
{
	if (ADC->CHER & (ADC_CHER_TSCH_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 内部基准电压测量通道，写1使能 (VREF channel)  相关函数 */
void ADC_CHER_REFCH_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->CHER |= (ADC_CHER_REFCH_Msk);
	}
	else
	{
		ADC->CHER &= ~(ADC_CHER_REFCH_Msk);
	}
}

FunState ADC_CHER_REFCH_Getable(void)
{
	if (ADC->CHER & (ADC_CHER_REFCH_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ADC_IN11 测量通道，写1使能  相关函数 */
void ADC_CHER_ECH11_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->CHER |= (ADC_CHER_ECH11_Msk);
	}
	else
	{
		ADC->CHER &= ~(ADC_CHER_ECH11_Msk);
	}
}

FunState ADC_CHER_ECH11_Getable(void)
{
	if (ADC->CHER & (ADC_CHER_ECH11_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ADC_IN10 测量通道，写1使能  相关函数 */
void ADC_CHER_ECH10_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->CHER |= (ADC_CHER_ECH10_Msk);
	}
	else
	{
		ADC->CHER &= ~(ADC_CHER_ECH10_Msk);
	}
}

FunState ADC_CHER_ECH10_Getable(void)
{
	if (ADC->CHER & (ADC_CHER_ECH10_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ADC_IN9 测量通道，写1使能 相关函数 */
void ADC_CHER_ECH9_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->CHER |= (ADC_CHER_ECH9_Msk);
	}
	else
	{
		ADC->CHER &= ~(ADC_CHER_ECH9_Msk);
	}
}

FunState ADC_CHER_ECH9_Getable(void)
{
	if (ADC->CHER & (ADC_CHER_ECH9_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ADC_IN8 测量通道，写1使能 相关函数 */
void ADC_CHER_ECH8_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->CHER |= (ADC_CHER_ECH8_Msk);
	}
	else
	{
		ADC->CHER &= ~(ADC_CHER_ECH8_Msk);
	}
}

FunState ADC_CHER_ECH8_Getable(void)
{
	if (ADC->CHER & (ADC_CHER_ECH8_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ADC_IN7 测量通道，写1使能 相关函数 */
void ADC_CHER_ECH7_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->CHER |= (ADC_CHER_ECH7_Msk);
	}
	else
	{
		ADC->CHER &= ~(ADC_CHER_ECH7_Msk);
	}
}

FunState ADC_CHER_ECH7_Getable(void)
{
	if (ADC->CHER & (ADC_CHER_ECH7_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ADC_IN6 测量通道，写1使能 相关函数 */
void ADC_CHER_ECH6_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->CHER |= (ADC_CHER_ECH6_Msk);
	}
	else
	{
		ADC->CHER &= ~(ADC_CHER_ECH6_Msk);
	}
}

FunState ADC_CHER_ECH6_Getable(void)
{
	if (ADC->CHER & (ADC_CHER_ECH6_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ADC_IN5 测量通道，写1使能 相关函数 */
void ADC_CHER_ECH5_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->CHER |= (ADC_CHER_ECH5_Msk);
	}
	else
	{
		ADC->CHER &= ~(ADC_CHER_ECH5_Msk);
	}
}

FunState ADC_CHER_ECH5_Getable(void)
{
	if (ADC->CHER & (ADC_CHER_ECH5_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ADC_IN4 测量通道，写1使能 相关函数 */
void ADC_CHER_ECH4_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->CHER |= (ADC_CHER_ECH4_Msk);
	}
	else
	{
		ADC->CHER &= ~(ADC_CHER_ECH4_Msk);
	}
}

FunState ADC_CHER_ECH4_Getable(void)
{
	if (ADC->CHER & (ADC_CHER_ECH4_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ADC_IN3 测量通道，写1使能 相关函数 */
void ADC_CHER_ECH3_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->CHER |= (ADC_CHER_ECH3_Msk);
	}
	else
	{
		ADC->CHER &= ~(ADC_CHER_ECH3_Msk);
	}
}

FunState ADC_CHER_ECH3_Getable(void)
{
	if (ADC->CHER & (ADC_CHER_ECH3_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ADC_IN2 测量通道，写1使能 相关函数 */
void ADC_CHER_ECH2_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->CHER |= (ADC_CHER_ECH2_Msk);
	}
	else
	{
		ADC->CHER &= ~(ADC_CHER_ECH2_Msk);
	}
}

FunState ADC_CHER_ECH2_Getable(void)
{
	if (ADC->CHER & (ADC_CHER_ECH2_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ADC_IN1 测量通道，写1使能 相关函数 */
void ADC_CHER_ECH1_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->CHER |= (ADC_CHER_ECH1_Msk);
	}
	else
	{
		ADC->CHER &= ~(ADC_CHER_ECH1_Msk);
	}
}

FunState ADC_CHER_ECH1_Getable(void)
{
	if (ADC->CHER & (ADC_CHER_ECH1_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ADC_IN0 测量通道，写1使能 相关函数 */
void ADC_CHER_ECH0_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->CHER |= (ADC_CHER_ECH0_Msk);
	}
	else
	{
		ADC->CHER &= ~(ADC_CHER_ECH0_Msk);
	}
}

FunState ADC_CHER_ECH0_Getable(void)
{
	if (ADC->CHER & (ADC_CHER_ECH0_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ADC转换结果 (ADC conversion data)在没有使能过采样平均的情况下，结果为低12bit；在使能过采样平均的情况下，结果为12~16bit
 相关函数 */
uint32_t ADC_DR_Read(void)
{
	return (ADC->DR & ADC_DR_ADC_DATA_Msk);
}

/* ADC转换配置 (Conversion with Calibration data) 相关函数 */
void ADC_CAL_CONV_CAL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ADC->CAL;
	tmpreg &= ~(ADC_CAL_CONV_CAL_Msk);
	tmpreg |= (SetValue & ADC_CAL_CONV_CAL_Msk);
	ADC->CAL = tmpreg;
}

uint32_t ADC_CAL_CONV_CAL_Get(void)
{
	return (ADC->CAL & ADC_CAL_CONV_CAL_Msk);
}

/* Calibration使能 (Calibration Enable)软件写1启动校准周期，硬件开始校准后自动清零。软件通过EOCAL寄存器查询校准周期结束 相关函数 */
void ADC_CAL_CALEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ADC->CAL |= (ADC_CAL_CALEN_Msk);
	}
	else
	{
		ADC->CAL &= ~(ADC_CAL_CALEN_Msk);
	}
}

FunState ADC_CAL_CALEN_Getable(void)
{
	if (ADC->CAL & (ADC_CAL_CALEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* AWD监视高阈值 (Analog Watchdog High Threshold) 相关函数 */
void ADC_HLTR_AWD_HT_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ADC->HLTR;
	tmpreg &= ~(ADC_HLTR_AWD_HT_Msk);
	tmpreg |= (SetValue & ADC_HLTR_AWD_HT_Msk);
	ADC->HLTR = tmpreg;
}

uint32_t ADC_HLTR_AWD_HT_Get(void)
{
	return (ADC->HLTR & ADC_HLTR_AWD_HT_Msk);
}

/* AWD监视低阈值 (Analog Watchdog Low Threshold) 相关函数 */
void ADC_HLTR_AWD_LT_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ADC->HLTR;
	tmpreg &= ~(ADC_HLTR_AWD_LT_Msk);
	tmpreg |= (SetValue & ADC_HLTR_AWD_LT_Msk);
	ADC->HLTR = tmpreg;
}

uint32_t ADC_HLTR_AWD_LT_Get(void)
{
	return (ADC->HLTR & ADC_HLTR_AWD_LT_Msk);
}


void ADC_Deinit(void)
{
   RCC_PRST_EN_Write(RSTKEY0);
   RCC_APBRST_CR2_ADCRST_Setable(ENABLE);  // 数字部分复位
   RCC_APBRST_CR2_ADCRST_Setable(DISABLE);
   RCC_APBRST_CR2_ADCCRST_Setable(ENABLE); // 模拟部分复位
   RCC_APBRST_CR2_ADCCRST_Setable(DISABLE);
   RCC_PRST_EN_Write(RSTKEY1);
}
//Code_End  
/******END OF FILE****/
