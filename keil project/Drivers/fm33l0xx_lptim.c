/**
  ******************************************************************************
  * @file    fm33l0xx_lptim.c
  * @author  FM33L0 Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33l0xx_lptim.h" 
#include "fm33l0xx_rcc.h" 

/** @addtogroup fm33l0_StdPeriph_Driver
  * @{
  */

/** @defgroup LPTIM 
  * @brief LPTIM driver modules
  * @{
  */ 
  
 /* ETR����ģ���˲�ʹ�� (External Trigger input Analog Filter Enable) ��غ��� */
void LPTIM_CFGR_ETR_AFEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPTIM->CFGR |= (LPTIM_CFGR_ETR_AFEN_Msk);
	}
	else
	{
		LPTIM->CFGR &= ~(LPTIM_CFGR_ETR_AFEN_Msk);
	}
}

FunState LPTIM_CFGR_ETR_AFEN_Getable(void)
{
	if (LPTIM->CFGR & (LPTIM_CFGR_ETR_AFEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ʱ��Ԥ��Ƶ����ѡ�� (Prescaler input Select) ��غ��� */
void LPTIM_CFGR_PSCSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CFGR;
	tmpreg &= ~(LPTIM_CFGR_PSCSEL_Msk);
	tmpreg |= (SetValue & LPTIM_CFGR_PSCSEL_Msk);
	LPTIM->CFGR = tmpreg;
}

uint32_t LPTIM_CFGR_PSCSEL_Get(void)
{
	return (LPTIM->CFGR & LPTIM_CFGR_PSCSEL_Msk);
}

/* ETR����Դѡ�� (External Trigger input source Select) ��غ��� */
void LPTIM_CFGR_INSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CFGR;
	tmpreg &= ~(LPTIM_CFGR_INSEL_Msk);
	tmpreg |= (SetValue & LPTIM_CFGR_INSEL_Msk);
	LPTIM->CFGR = tmpreg;
}

uint32_t LPTIM_CFGR_INSEL_Get(void)
{
	return (LPTIM->CFGR & LPTIM_CFGR_INSEL_Msk);
}

/* ����ʱ�ӷ�Ƶѡ�� (Counter Clock Divider Select) ��غ��� */
void LPTIM_CFGR_DIVSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CFGR;
	tmpreg &= ~(LPTIM_CFGR_DIVSEL_Msk);
	tmpreg |= (SetValue & LPTIM_CFGR_DIVSEL_Msk);
	LPTIM->CFGR = tmpreg;
}

uint32_t LPTIM_CFGR_DIVSEL_Get(void)
{
	return (LPTIM->CFGR & LPTIM_CFGR_DIVSEL_Msk);
}

/* ETR�������ѡ�� (ETR Clock Edge Select) ��غ��� */
void LPTIM_CFGR_EDGESEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CFGR;
	tmpreg &= ~(LPTIM_CFGR_EDGESEL_Msk);
	tmpreg |= (SetValue & LPTIM_CFGR_EDGESEL_Msk);
	LPTIM->CFGR = tmpreg;
}

uint32_t LPTIM_CFGR_EDGESEL_Get(void)
{
	return (LPTIM->CFGR & LPTIM_CFGR_EDGESEL_Msk);
}

/* �ⲿ��������ѡ����ʹ���ڲ�ʱ��ͬ������LPT_ETR��(ETR trigger Configuration) ��غ��� */
void LPTIM_CFGR_TRIGCFG_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CFGR;
	tmpreg &= ~(LPTIM_CFGR_TRIGCFG_Msk);
	tmpreg |= (SetValue & LPTIM_CFGR_TRIGCFG_Msk);
	LPTIM->CFGR = tmpreg;
}

uint32_t LPTIM_CFGR_TRIGCFG_Get(void)
{
	return (LPTIM->CFGR & LPTIM_CFGR_TRIGCFG_Msk);
}

/* ���μ���ģʽʹ�� (One State Timer) ��غ��� */
void LPTIM_CFGR_ONST_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CFGR;
	tmpreg &= ~(LPTIM_CFGR_ONST_Msk);
	tmpreg |= (SetValue & LPTIM_CFGR_ONST_Msk);
	LPTIM->CFGR = tmpreg;
}

uint32_t LPTIM_CFGR_ONST_Get(void)
{
	return (LPTIM->CFGR & LPTIM_CFGR_ONST_Msk);
}

/* ����ģʽѡ�� (Timer operation Mode) ��غ��� */
void LPTIM_CFGR_TMOD_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CFGR;
	tmpreg &= ~(LPTIM_CFGR_TMOD_Msk);
	tmpreg |= (SetValue & LPTIM_CFGR_TMOD_Msk);
	LPTIM->CFGR = tmpreg;
}

uint32_t LPTIM_CFGR_TMOD_Get(void)
{
	return (LPTIM->CFGR & LPTIM_CFGR_TMOD_Msk);
}

/* 32bit��������ǰ����ֵ (Counter 32bits-wide) ��غ��� */
void LPTIM_CNT_Write(uint32_t SetValue)
{
	LPTIM->CNT = (SetValue);
}

uint32_t LPTIM_CNT_Read(void)
{
	return (LPTIM->CNT);
}

/* ͨ��1��׽�ź�Դѡ�� (Channel 1 Capture Source Select) ��غ��� */
void LPTIM_CCSR_CAP1SSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CCSR;
	tmpreg &= ~(LPTIM_CCSR_CAP1SSEL_Msk);
	tmpreg |= (SetValue & LPTIM_CCSR_CAP1SSEL_Msk);
	LPTIM->CCSR = tmpreg;
}

uint32_t LPTIM_CCSR_CAP1SSEL_Get(void)
{
	return (LPTIM->CCSR & LPTIM_CCSR_CAP1SSEL_Msk);
}

/* ͨ��2��ǰ����׽�ı��أ���CC2IF��λʱ���� (Channel2 Captured Edge) ��غ��� */
FlagStatus LPTIM_CCSR_CAP2EDGE_Chk(void)
{
	if (LPTIM->CCSR & LPTIM_CCSR_CAP2EDGE_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ͨ��1��ǰ����׽�ı��أ���CC1IF��λʱ���� (Channel 1 Captured Edge) ��غ��� */
FlagStatus LPTIM_CCSR_CAP1EDGE_Chk(void)
{
	if (LPTIM->CCSR & LPTIM_CCSR_CAP1EDGE_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ͨ��2��׽����ѡ�� (Channel 2 Capture edge Config) ��غ��� */
void LPTIM_CCSR_CAPCFG2_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CCSR;
	tmpreg &= ~(LPTIM_CCSR_CAPCFG2_Msk);
	tmpreg |= (SetValue & LPTIM_CCSR_CAPCFG2_Msk);
	LPTIM->CCSR = tmpreg;
}

uint32_t LPTIM_CCSR_CAPCFG2_Get(void)
{
	return (LPTIM->CCSR & LPTIM_CCSR_CAPCFG2_Msk);
}

/* ͨ��1��׽����ѡ�� (Channel 1 Capture edge Config) ��غ��� */
void LPTIM_CCSR_CAPCFG1_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CCSR;
	tmpreg &= ~(LPTIM_CCSR_CAPCFG1_Msk);
	tmpreg |= (SetValue & LPTIM_CCSR_CAPCFG1_Msk);
	LPTIM->CCSR = tmpreg;
}

uint32_t LPTIM_CCSR_CAPCFG1_Get(void)
{
	return (LPTIM->CCSR & LPTIM_CCSR_CAPCFG1_Msk);
}

/* ͨ��2�Ƚ�������μ���ѡ�� (Channel 2 compare output Polarity) ��غ��� */
void LPTIM_CCSR_POLAR2_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CCSR;
	tmpreg &= ~(LPTIM_CCSR_POLAR2_Msk);
	tmpreg |= (SetValue & LPTIM_CCSR_POLAR2_Msk);
	LPTIM->CCSR = tmpreg;
}

uint32_t LPTIM_CCSR_POLAR2_Get(void)
{
	return (LPTIM->CCSR & LPTIM_CCSR_POLAR2_Msk);
}

/* ͨ��1�Ƚ�������μ���ѡ�� (Channel 1 compare output Polarity) ��غ��� */
void LPTIM_CCSR_POLAR1_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CCSR;
	tmpreg &= ~(LPTIM_CCSR_POLAR1_Msk);
	tmpreg |= (SetValue & LPTIM_CCSR_POLAR1_Msk);
	LPTIM->CCSR = tmpreg;
}

uint32_t LPTIM_CCSR_POLAR1_Get(void)
{
	return (LPTIM->CCSR & LPTIM_CCSR_POLAR1_Msk);
}

/* ͨ��2��׽/�ȽϹ���ʹ�� (Channel 2 Capture/Compare Select) ��غ��� */
void LPTIM_CCSR_CC2S_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CCSR;
	tmpreg &= ~(LPTIM_CCSR_CC2S_Msk);
	tmpreg |= (SetValue & LPTIM_CCSR_CC2S_Msk);
	LPTIM->CCSR = tmpreg;
}

uint32_t LPTIM_CCSR_CC2S_Get(void)
{
	return (LPTIM->CCSR & LPTIM_CCSR_CC2S_Msk);
}

/* ͨ��1��׽/�ȽϹ���ʹ�� (Channel 1 Capture/Compare Select) ��غ��� */
void LPTIM_CCSR_CC1S_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPTIM->CCSR;
	tmpreg &= ~(LPTIM_CCSR_CC1S_Msk);
	tmpreg |= (SetValue & LPTIM_CCSR_CC1S_Msk);
	LPTIM->CCSR = tmpreg;
}

uint32_t LPTIM_CCSR_CC1S_Get(void)
{
	return (LPTIM->CCSR & LPTIM_CCSR_CC1S_Msk);
}

/* �Զ�����Ŀ��Ĵ��� (Auto-Reload Register) ��غ��� */
void LPTIM_ARR_Write(uint32_t SetValue)
{
	LPTIM->ARR = (SetValue);
}

uint32_t LPTIM_ARR_Read(void)
{
	return (LPTIM->ARR);
}

/* ͨ��2��׽����ж�ʹ�� (Channel 2 Over-Capture Interrupt Enable) ��غ��� */
void LPTIM_IER_OVR2IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPTIM->IER |= (LPTIM_IER_OVR2IE_Msk);
	}
	else
	{
		LPTIM->IER &= ~(LPTIM_IER_OVR2IE_Msk);
	}
}

FunState LPTIM_IER_OVR2IE_Getable(void)
{
	if (LPTIM->IER & (LPTIM_IER_OVR2IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ͨ��1��׽����ж�ʹ�� (Channel 1 Over-Capture Interrupt Enable) ��غ��� */
void LPTIM_IER_OVR1IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPTIM->IER |= (LPTIM_IER_OVR1IE_Msk);
	}
	else
	{
		LPTIM->IER &= ~(LPTIM_IER_OVR1IE_Msk);
	}
}

FunState LPTIM_IER_OVR1IE_Getable(void)
{
	if (LPTIM->IER & (LPTIM_IER_OVR1IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �ⲿ���������ж�ʹ��λ (External Trigger Interrupt Enable) ��غ��� */
void LPTIM_IER_TRIGIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPTIM->IER |= (LPTIM_IER_TRIGIE_Msk);
	}
	else
	{
		LPTIM->IER &= ~(LPTIM_IER_TRIGIE_Msk);
	}
}

FunState LPTIM_IER_TRIGIE_Getable(void)
{
	if (LPTIM->IER & (LPTIM_IER_TRIGIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����������ж�ʹ��λ (Counter Over-Flow Interrupt Enable) ��غ��� */
void LPTIM_IER_OVIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPTIM->IER |= (LPTIM_IER_OVIE_Msk);
	}
	else
	{
		LPTIM->IER &= ~(LPTIM_IER_OVIE_Msk);
	}
}

FunState LPTIM_IER_OVIE_Getable(void)
{
	if (LPTIM->IER & (LPTIM_IER_OVIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�ͨ��2�ж�ʹ��λ (Capture/Compare channel 2 Interrupt Enable) ��غ��� */
void LPTIM_IER_CC2IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPTIM->IER |= (LPTIM_IER_CC2IE_Msk);
	}
	else
	{
		LPTIM->IER &= ~(LPTIM_IER_CC2IE_Msk);
	}
}

FunState LPTIM_IER_CC2IE_Getable(void)
{
	if (LPTIM->IER & (LPTIM_IER_CC2IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�ͨ��1�ж�ʹ��λ (Capture/Compare channel 1 Interrupt Enable) ��غ��� */
void LPTIM_IER_CC1IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPTIM->IER |= (LPTIM_IER_CC1IE_Msk);
	}
	else
	{
		LPTIM->IER &= ~(LPTIM_IER_CC1IE_Msk);
	}
}

FunState LPTIM_IER_CC1IE_Getable(void)
{
	if (LPTIM->IER & (LPTIM_IER_CC1IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ͨ��2��׽�����Ӳ����λ�����д1���� (Channel 2 Over-Capture Interrupt Flag) ��غ��� */
void LPTIM_ISR_CAP2OVR_Clr(void)
{
	LPTIM->ISR = LPTIM_ISR_CAP2OVR_Msk;
}

FlagStatus LPTIM_ISR_CAP2OVR_Chk(void)
{
	if (LPTIM->ISR & LPTIM_ISR_CAP2OVR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ͨ��1��׽�����Ӳ����λ�����д1���� (Channel 1 Over-Capture Interrupt Flag) ��غ��� */
void LPTIM_ISR_CAP1OVR_Clr(void)
{
	LPTIM->ISR = LPTIM_ISR_CAP1OVR_Msk;
}

FlagStatus LPTIM_ISR_CAP1OVR_Chk(void)
{
	if (LPTIM->ISR & LPTIM_ISR_CAP1OVR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �ⲿ���������жϱ�־λ��д1���� (External Trigger Interrupt Flag) ��غ��� */
void LPTIM_ISR_TRIGIF_Clr(void)
{
	LPTIM->ISR = LPTIM_ISR_TRIGIF_Msk;
}

FlagStatus LPTIM_ISR_TRIGIF_Chk(void)
{
	if (LPTIM->ISR & LPTIM_ISR_TRIGIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ����������ж�ʹ��λ��д1���� (Counter Over-Flow Interrupt Flag) ��غ��� */
void LPTIM_ISR_OVIF_Clr(void)
{
	LPTIM->ISR = LPTIM_ISR_OVIF_Msk;
}

FlagStatus LPTIM_ISR_OVIF_Chk(void)
{
	if (LPTIM->ISR & LPTIM_ISR_OVIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��׽/�Ƚ�ͨ��2�жϱ�־��Ӳ����λ�����д1���� (Capture/Compare channel 2 Interrupt Flag) ��غ��� */
void LPTIM_ISR_CC2IF_Clr(void)
{
	LPTIM->ISR = LPTIM_ISR_CC2IF_Msk;
}

FlagStatus LPTIM_ISR_CC2IF_Chk(void)
{
	if (LPTIM->ISR & LPTIM_ISR_CC2IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��׽/�Ƚ�ͨ��1�жϱ�־��Ӳ����λ�����д1���� (Capture/Compare channel 1 Interrupt Flag) ��غ��� */
void LPTIM_ISR_CC1IF_Clr(void)
{
	LPTIM->ISR = LPTIM_ISR_CC1IF_Msk;
}

FlagStatus LPTIM_ISR_CC1IF_Chk(void)
{
	if (LPTIM->ISR & LPTIM_ISR_CC1IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* LPTIMʹ��λ (LPTIM Enable) ��غ��� */
void LPTIM_CR_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPTIM->CR |= (LPTIM_CR_EN_Msk);
	}
	else
	{
		LPTIM->CR &= ~(LPTIM_CR_EN_Msk);
	}
}

FunState LPTIM_CR_EN_Getable(void)
{
	if (LPTIM->CR & (LPTIM_CR_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�ֵ�Ĵ���1 (Channel1 Capture/Compare Register) ��غ��� */
void LPTIM_CCR1_Write(uint32_t SetValue)
{
	LPTIM->CCR1 = (SetValue);
}

uint32_t LPTIM_CCR1_Read(void)
{
	return (LPTIM->CCR1);
}

/* ��׽/�Ƚ�ֵ�Ĵ���2 (Channel2 Capture/Compare Register) ��غ��� */
void LPTIM_CCR2_Write(uint32_t SetValue)
{
	LPTIM->CCR2 = (SetValue);
}

uint32_t LPTIM_CCR2_Read(void)
{
	return (LPTIM->CCR2);
}


void LPTIM_Deinit(void)
{
   RCC_PRST_EN_Write(RSTKEY0);
   RCC_APBRST_CR1_LPT32RST_Setable(ENABLE);  
   RCC_APBRST_CR1_LPT32RST_Setable(DISABLE);
   RCC_PRST_EN_Write(RSTKEY1);
}
 
/******END OF FILE****/
