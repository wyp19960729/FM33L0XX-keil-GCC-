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
  

/* ģ�⿴�Ź����������жϱ�־ (Analog Watchdog Above High Threshold)������ֵ����AWD_HTʱ��Ӳ����λ�����д1����. ��غ��� */
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

/* ģ�⿴�Ź����������жϱ�־ (Analog Watchdog Under Low Threshold)������ֵ����AWD_LTʱ��Ӳ����λ�����д1���� ��غ��� */
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

/* У׼���� (End Of Calibration)Ӳ����λ�����д1����1��У׼���̽���0����У׼���� ��غ��� */
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

/* ADCæ��־ (Busy) 1��ADC����У׼��������ת�������� 0��ADC���� ��غ��� */
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

/* ���ݳ�ͻ��־��Ӳ����λ�����д1���� (Over Run) ��ADC_DATA�Ĵ����е���һ��ת�������δ����ȡ���µ�ת������ֵ���ʱ��Ӳ����λOVR��־��0��û�����ݳ�ͻ 1���������ݳ�ͻ ��غ��� */
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

/* ת�����н��� (End Of Sequence)����ʹ��ͨ����ת����ɺ���λEOS�����д1���㡣 ��غ��� */
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

/* ����ת������ (End Of Conversion)ÿ��ͨ��ת����ɺ���λEOC�����д1���㡣 ��غ��� */
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

/* ģ�⿴�Ź�����ֵ���������ж�ʹ�ܣ�1��Ч (Analog Watchdog Above High Threshold Interrupt Enable) ��غ��� */
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

/* ģ�⿴�Ź�����ֵ���������ж�ʹ�ܣ�1��Ч (Analog Watchdog Under Low Threshold Interrupt Enable) ��غ��� */
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

/* У׼�����ж�ʹ�ܼĴ��� (End Of Calibration Interrupt Enable) 0����ֹEOCAL�ж� 1������EOCAL�ж� ��غ��� */
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

/* ���ݳ�ͻ�ж�ʹ�ܼĴ��� (Over Run Interrupt Enable) 0����ֹ���ݳ�ͻ�ж� 1���������ݳ�ͻ�ж� ��غ��� */
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

/* ת�����н����ж�ʹ�ܼĴ��� (End Of Sequence Interrupt Enable) 0����ֹEOS�ж� 1������EOS�ж� ��غ��� */
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

/* ����ת�������ж�ʹ�ܼĴ��� (End Of Conversion Interrupt Enable) 0����ֹEOC�ж� 1������EOC�ж� ��غ��� */
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

/* ADC����ת���Ĵ��������д1������Ӳ���Զ����㡣 ��غ��� */
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

/* ADCʹ�ܼĴ��� (ADC Enable) ������ת��ǰ��Ҫ��λADEN���ȴ�����5��MCLK��������ת����0���ر�ADC 1��ʹ��ADC ��غ��� */
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

/* ADC����ʱ��ѡ�� (ADC Clock Select) ��غ��� */
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

/* ģ�ⴰ�ڿ��Ź�����ͨ��ѡ�񣬽���AWDSC=1ʱ��Ч (Analog Watchdog Channel Select) ��غ��� */
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

/* ģ�ⴰ�ڿ��Ź���ͨ����ȫͨ��ѡ�� (Analog Watchdog Single Channel mode) ��غ��� */
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

/* ģ�ⴰ�ڿ��Ź�ʹ�ܼĴ��� (Analog Watchdog Enable) 0���ر�AWD 1��ʹ��AWD ������START=0�������ʹ��AWD ��غ��� */
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

/* ��������λ���ƼĴ��� (Oversampling Shift) ��غ��� */
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

/* �������ʿ��� (Oversampling Ratio) ��غ��� */
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

/* ������ʹ�� (Oversampling Enable) 0����ֹ������ 1��ʹ�ܹ����� ��غ��� */
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

/* ���Ŵ����ź������˲�ʹ�� (GPIO Trigger Filter Enable) 0����ֹ�����˲� 1��ʹ�������˲�  ��غ��� */
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

/* �����ź�ʹ�ܺͼ���ѡ�� (Trigger Config) ��غ��� */
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

/* ����ת�����Զ�ģʽ (Semi-automatic)�����ڵ���ת����CONT=0��ʱ��Ч ��غ��� */
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

/* �ȴ�ģʽ���� (wait mode) 0���޵ȴ�������ϴ�ת������û�м�ʱ��ȡ������ܳ���Overrun 1���ȴ�ģʽ�����ϴ�ת�����ݱ���ȡǰ������������һ��ת�� ��غ��� */
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

/* ����ת��ģʽʹ�� (Continuous mode) 0������ת�� 1������ת��  ��غ��� */
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

/* Overrunģʽ���� (Overrun mode) ��غ��� */
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

/* Ӳ������Դѡ�� (External trigger select) ��غ��� */
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

/* ADC�͹���ģʽʹ�ܣ������������ (Low Power Mode) ��غ��� */
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

/* ͨ��ɨ��˳����� (Scan Direction)����16��ͨ����ʵ��ֻ�������ʹ�ܵ�ͨ���� ��غ��� */
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

/* DMAģʽ���� (DMA Config) ��غ��� */
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

/* DMAʹ�� (DMA Enable) 0����ֹDMA 1��ʹ��DMA  ��غ��� */
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

/* ADC����ͨ���л��ȴ�ʱ�� (Channel Clock Gating) �ڵ�ǰͨ������������ɺ󣬵ȴ�CHCGʱ�䣨CHCG*ADC����ʱ�����ڣ������л�����һ������ͨ�� ��غ��� */
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

/* ����ͨ������ʱ����ƣ�*ADC����ʱ�����ڣ�����������ADC_IN8/9/10/11�ĸ��ⲿͨ�����Լ�OPAͨ���Ĳ���ʱ�� (Sampling Time Select 2)  ��غ��� */
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

/* ����ͨ������ʱ����ƣ�*ADC����ʱ�����ڣ�����������ADC_IN8/9/10/11�ĸ��ⲿͨ�����Լ�OPAͨ���Ĳ���ʱ�� (Sampling Time Select 2)  ��غ��� */
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

/* ���˺Ͳ��ͨ�����ã�4bit����4��ͨ�����Ƿ�Ϊ������룬0��ʾ�������룬1��ʾ������롣(Analog Input Select)�������Ϊ������룬��ÿ����ֶ�����Ӧ��ͨ����Ҫʹ�ܡ�
���磬��ADC_IN0��ADC_IN1����Ϊ�������ԣ���Ҫ���в�ֲ���ʱ��ECH0��ECH1��Ҫ��1�� ��غ��� */
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

/* OPA2���������д1ʹ�� (OPA2 channel)  ��غ��� */
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

/* OPA1���������д1ʹ�� (OPA1 channel)  ��غ��� */
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

/* �¶ȴ���������ͨ����д1ʹ�� (TempSensor channel)  ��غ��� */
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

/* �ڲ���׼��ѹ����ͨ����д1ʹ�� (VREF channel)  ��غ��� */
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

/* ADC_IN11 ����ͨ����д1ʹ��  ��غ��� */
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

/* ADC_IN10 ����ͨ����д1ʹ��  ��غ��� */
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

/* ADC_IN9 ����ͨ����д1ʹ�� ��غ��� */
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

/* ADC_IN8 ����ͨ����д1ʹ�� ��غ��� */
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

/* ADC_IN7 ����ͨ����д1ʹ�� ��غ��� */
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

/* ADC_IN6 ����ͨ����д1ʹ�� ��غ��� */
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

/* ADC_IN5 ����ͨ����д1ʹ�� ��غ��� */
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

/* ADC_IN4 ����ͨ����д1ʹ�� ��غ��� */
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

/* ADC_IN3 ����ͨ����д1ʹ�� ��غ��� */
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

/* ADC_IN2 ����ͨ����д1ʹ�� ��غ��� */
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

/* ADC_IN1 ����ͨ����д1ʹ�� ��غ��� */
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

/* ADC_IN0 ����ͨ����д1ʹ�� ��غ��� */
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

/* ADCת����� (ADC conversion data)��û��ʹ�ܹ�����ƽ��������£����Ϊ��12bit����ʹ�ܹ�����ƽ��������£����Ϊ12~16bit
 ��غ��� */
uint32_t ADC_DR_Read(void)
{
	return (ADC->DR & ADC_DR_ADC_DATA_Msk);
}

/* ADCת������ (Conversion with Calibration data) ��غ��� */
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

/* Calibrationʹ�� (Calibration Enable)���д1����У׼���ڣ�Ӳ����ʼУ׼���Զ����㡣���ͨ��EOCAL�Ĵ�����ѯУ׼���ڽ��� ��غ��� */
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

/* AWD���Ӹ���ֵ (Analog Watchdog High Threshold) ��غ��� */
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

/* AWD���ӵ���ֵ (Analog Watchdog Low Threshold) ��غ��� */
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
   RCC_APBRST_CR2_ADCRST_Setable(ENABLE);  // ���ֲ��ָ�λ
   RCC_APBRST_CR2_ADCRST_Setable(DISABLE);
   RCC_APBRST_CR2_ADCCRST_Setable(ENABLE); // ģ�ⲿ�ָ�λ
   RCC_APBRST_CR2_ADCCRST_Setable(DISABLE);
   RCC_PRST_EN_Write(RSTKEY1);
}
//Code_End  
/******END OF FILE****/
