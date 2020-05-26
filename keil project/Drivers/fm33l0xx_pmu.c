/**
  ******************************************************************************
  * @file    fm33l0xx_pmu.c
  * @author  FM33L0 Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33l0xx_pmu.h" 


/** @addtogroup fm33l0_StdPeriph_Driver
  * @{
  */

/** @defgroup PMU 
  * @brief PMU driver modules
  * @{
  */ 
  
/* LDO�͹���ģʽ���� (LDO Low Power Mode) ��غ��� */
void PMU_CR_LDO_LPM_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = PMU->CR;
	tmpreg &= ~(PMU_CR_LDO_LPM_Msk);
	tmpreg |= (SetValue & PMU_CR_LDO_LPM_Msk);
	PMU->CR = tmpreg;
}

uint32_t PMU_CR_LDO_LPM_Get(void)
{
	return (PMU->CR & PMU_CR_LDO_LPM_Msk);
}

/* LDO15ʹ��״̬��ֻ�� ��غ��� */
FlagStatus PMU_CR_LDO15EN_Chk(void)
{
	if (PMU->CR & PMU_CR_LDO15EN_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

FlagStatus PMU_CR_LDO15EN_B_Chk(void)
{
	if (PMU->CR & PMU_CR_LDO15EN_B_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* Sleep/DeepSleep���Ѻ��ϵͳƵ�� (Wakeup Frequency Select) ��غ��� */
void PMU_CR_WKFSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = PMU->CR;
	tmpreg &= ~(PMU_CR_WKFSEL_Msk);
	tmpreg |= (SetValue & PMU_CR_WKFSEL_Msk);
	PMU->CR = tmpreg;
}

uint32_t PMU_CR_WKFSEL_Get(void)
{
	return (PMU->CR & PMU_CR_WKFSEL_Msk);
}

/* DeepSleep���Ƽ� ��غ��� */
void PMU_CR_SLPDP_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = PMU->CR;
	tmpreg &= ~(PMU_CR_SLPDP_Msk);
	tmpreg |= (SetValue & PMU_CR_SLPDP_Msk);
	PMU->CR = tmpreg;
}

uint32_t PMU_CR_SLPDP_Get(void)
{
	return (PMU->CR & PMU_CR_SLPDP_Msk);
}

/* �͹���ģʽ�ں˵�ѹ����0���͹���ģʽ�²�ʹ���ں˵�ѹ����1���͹���ģʽ�½����ں˵�ѹ ��Sleep�£������λ��SLPDPλ��ΪDeepSleepģʽ����λ����Sleep����Ч ��غ��� */
void PMU_CR_CVS_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		PMU->CR |= (PMU_CR_CVS_Msk);
	}
	else
	{
		PMU->CR &= ~(PMU_CR_CVS_Msk);
	}
}

FunState PMU_CR_CVS_Getable(void)
{
	if (PMU->CR & (PMU_CR_CVS_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �͹���ģʽ���üĴ��� (Power Mode) ��غ��� */
void PMU_CR_PMOD_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = PMU->CR;
	tmpreg &= ~(PMU_CR_PMOD_Msk);
	tmpreg |= (SetValue & PMU_CR_PMOD_Msk);
	PMU->CR = tmpreg;
}

uint32_t PMU_CR_PMOD_Get(void)
{
	return (PMU->CR & PMU_CR_PMOD_Msk);
}

/* ����ʱ����ƼĴ��� ��غ��� */
void PMU_WKTR_TRHR_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = PMU->WKTR;
	tmpreg &= ~(PMU_WKTR_TRHR_Msk);
	tmpreg |= (SetValue & PMU_WKTR_TRHR_Msk);
	PMU->WKTR = tmpreg;
}

uint32_t PMU_WKTR_TRHR_Get(void)
{
	return (PMU->WKTR & PMU_WKTR_TRHR_Msk);
}

/* ADC�жϻ��ѱ�־ ��غ��� */
FlagStatus PMU_WKFR_ADCWKF_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_ADCWKF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* RTC�жϻ��ѱ�־ ��غ��� */
FlagStatus PMU_WKFR_RTCWKF_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_RTCWKF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* SVD�жϻ��ѱ�־ ��غ��� */
FlagStatus PMU_WKFR_SVDWKF_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_SVDWKF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* SVD�жϻ��ѱ�־ ��غ��� */
FlagStatus PMU_WKFR_LFDETWKF_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_LFDETWKF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* VREF1P22��׼Դ�����жϻ��ѱ�־ ��غ��� */
FlagStatus PMU_WKFR_VREFWKF_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_VREFWKF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* IO�жϻ��ѱ�־ ��غ��� */
FlagStatus PMU_WKFR_IOWKF_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_IOWKF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* I2C�жϻ��ѱ�־ ��غ��� */
FlagStatus PMU_WKFR_I2CWKF_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_I2CWKF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* LPUART1�жϻ��ѱ�־ ��غ��� */
FlagStatus PMU_WKFR_LPU1WKF_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_LPU1WKF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* LPUART0�жϻ��ѱ�־ ��غ��� */
FlagStatus PMU_WKFR_LPU0WKF_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_LPU0WKF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* UART1�жϻ��ѱ�־ ��غ��� */
FlagStatus PMU_WKFR_UART1WKF_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_UART1WKF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* UART0�жϻ��ѱ�־ ��غ��� */
FlagStatus PMU_WKFR_UART0WKF_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_UART0WKF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* OPA2���Ƚ���ģʽ���жϻ��ѱ�־ ��غ��� */
FlagStatus PMU_WKFR_OPA2WKF_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_OPA2WKF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* OPA1���Ƚ���ģʽ���жϻ��ѱ�־ ��غ��� */
FlagStatus PMU_WKFR_OPA1WKF_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_OPA1WKF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* LPTIM32�жϻ��ѱ�־ ��غ��� */
FlagStatus PMU_WKFR_LPTWKF_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_LPTWKF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* BSTIM32�жϻ��ѱ�־ ��غ��� */
FlagStatus PMU_WKFR_BSTWKF_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_BSTWKF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* CPU Debugger���ѱ�־ ��غ��� */
void PMU_WKFR_DBGWKF_Clr(void)
{
	PMU->WKFR = PMU_WKFR_DBGWKF_Msk;
}

FlagStatus PMU_WKFR_DBGWKF_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_DBGWKF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* NWKUP7 Pin���ѱ�־ ��غ��� */
void PMU_WKFR_WKP7F_Clr(void)
{
	PMU->WKFR = PMU_WKFR_WKP7F_Msk;
}

FlagStatus PMU_WKFR_WKP7F_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_WKP7F_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* NWKUP6 Pin���ѱ�־ ��غ��� */
void PMU_WKFR_WKP6F_Clr(void)
{
	PMU->WKFR = PMU_WKFR_WKP6F_Msk;
}

FlagStatus PMU_WKFR_WKP6F_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_WKP6F_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* NWKUP5 Pin���ѱ�־ ��غ��� */
void PMU_WKFR_WKP5F_Clr(void)
{
	PMU->WKFR = PMU_WKFR_WKP5F_Msk;
}

FlagStatus PMU_WKFR_WKP5F_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_WKP5F_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* NWKUP4 Pin���ѱ�־ ��غ��� */
void PMU_WKFR_WKP4F_Clr(void)
{
	PMU->WKFR = PMU_WKFR_WKP4F_Msk;
}

FlagStatus PMU_WKFR_WKP4F_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_WKP4F_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* NWKUP3 Pin���ѱ�־ ��غ��� */
void PMU_WKFR_WKP3F_Clr(void)
{
	PMU->WKFR = PMU_WKFR_WKP3F_Msk;
}

FlagStatus PMU_WKFR_WKP3F_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_WKP3F_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* NWKUP2 Pin���ѱ�־ ��غ��� */
void PMU_WKFR_WKP2F_Clr(void)
{
	PMU->WKFR = PMU_WKFR_WKP2F_Msk;
}

FlagStatus PMU_WKFR_WKP2F_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_WKP2F_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* NWKUP1 Pin���ѱ�־ ��غ��� */
void PMU_WKFR_WKP1F_Clr(void)
{
	PMU->WKFR = PMU_WKFR_WKP1F_Msk;
}

FlagStatus PMU_WKFR_WKP1F_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_WKP1F_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* NWKUP0 Pin���ѱ�־ ��غ��� */
void PMU_WKFR_WKP0F_Clr(void)
{
	PMU->WKFR = PMU_WKFR_WKP0F_Msk;
}

FlagStatus PMU_WKFR_WKP0F_Chk(void)
{
	if (PMU->WKFR & PMU_WKFR_WKP0F_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* LPACTIVE�����ж�ʹ��0����ֹLPACTIVE�����ж�1��ʹ��LPACTIVE�����ж� ��غ��� */
void PMU_IER_LPACTEIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		PMU->IER |= (PMU_IER_LPACTEIE_Msk);
	}
	else
	{
		PMU->IER &= ~(PMU_IER_LPACTEIE_Msk);
	}
}

FunState PMU_IER_LPACTEIE_Getable(void)
{
	if (PMU->IER & (PMU_IER_LPACTEIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SLEEP�����ж�ʹ��0����ֹSLEEP�����ж�1��ʹ��SLEEP�����ж� ��غ��� */
void PMU_IER_SLPEIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		PMU->IER |= (PMU_IER_SLPEIE_Msk);
	}
	else
	{
		PMU->IER &= ~(PMU_IER_SLPEIE_Msk);
	}
}

FunState PMU_IER_SLPEIE_Getable(void)
{
	if (PMU->IER & (PMU_IER_SLPEIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* LPACTIVE�����жϱ�־��Ӳ����λ�����д1���� ��غ��� */
void PMU_ISR_LPACTEIF_Clr(void)
{
	PMU->ISR = PMU_ISR_LPACTEIF_Msk;
}

FlagStatus PMU_ISR_LPACTEIF_Chk(void)
{
	if (PMU->ISR & PMU_ISR_LPACTEIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* SLEEP�����жϱ�־��Ӳ����λ�����д1���� ��غ��� */
void PMU_ISR_SLPEIF_Clr(void)
{
	PMU->ISR = PMU_ISR_SLPEIF_Msk;
}

FlagStatus PMU_ISR_SLPEIF_Chk(void)
{
	if (PMU->ISR & PMU_ISR_SLPEIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* VREF1p2ʹ�ܼĴ��� (VREF Enable)  0���ر�VREF1p2   1��ʹ��VREF1p2 ��غ��� */
void PMU_VREF_CR_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		PMU_VREF->CR |= (PMU_VREF_CR_EN_Msk);
	}
	else
	{
		PMU_VREF->CR &= ~(PMU_VREF_CR_EN_Msk);
	}
}

FunState PMU_VREF_CR_EN_Getable(void)
{
	if (PMU_VREF->CR & (PMU_VREF_CR_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ģ�������VREF1p22�Ĵ�����ѹ������־ (VREF stable Flag from analog) ��غ��� */
FlagStatus PMU_VREF_SR_FLAG_B_Chk(void)
{
	if (PMU_VREF->SR & PMU_VREF_SR_FLAG_B_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* VREF1p22��׼��ѹ������־ (VREF Ready) ��غ��� */
FlagStatus PMU_VREF_SR_RDY_Chk(void)
{
	if (PMU_VREF->SR & PMU_VREF_SR_RDY_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* VREF1p22��׼��ѹ�����ж� (VREF Ready Flag) ��غ��� */
void PMU_VREF_SR_IF_Clr(void)
{
	PMU_VREF->SR = PMU_VREF_SR_IF_Msk;
}

FlagStatus PMU_VREF_SR_IF_Chk(void)
{
	if (PMU_VREF->SR & PMU_VREF_SR_IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* VREF1p2��׼��ѹ�����ж�ʹ�� (VREF Ready Interrupt Enable) 0����ֹ����VREF��������ж� 1���������VREF��������ж� ��غ��� */
void PMU_VREF_IER_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		PMU_VREF->IER |= (PMU_VREF_IER_IE_Msk);
	}
	else
	{
		PMU_VREF->IER &= ~(PMU_VREF_IER_IE_Msk);
	}
}

FunState PMU_VREF_IER_IE_Getable(void)
{
	if (PMU_VREF->IER & (PMU_VREF_IER_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

void PMU_BUF_ALLDISABLE(void)
{
   PMU_BUF->CR=0;
}

/* ����bandgap���ptat��ѹ(PTAT VREF Enable) 0��Vptat ��ʹ�� 1��Vptat ʹ�� ��غ��� */
void PMU_BUF_CR_VREFPTAT_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		PMU_BUF->CR |= (PMU_BUF_CR_VREFPTAT_EN_Msk);
	}
	else
	{
		PMU_BUF->CR &= ~(PMU_BUF_CR_VREFPTAT_EN_Msk);
	}
}

FunState PMU_BUF_CR_VREFPTAT_EN_Getable(void)
{
	if (PMU_BUF->CR & (PMU_BUF_CR_VREFPTAT_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Vptat Bufferģ�鿪��ͨ�����ʹ���źţ��ߵ�ƽʹ����Ч��(PTAT Buffer Output Enable) 0��Vptat buffer ģ�������ʹ�� 1��Vptat buffer ģ�����ʹ�� ��غ��� */
void PMU_BUF_CR_VPTATBUFFER_OUTEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		PMU_BUF->CR |= (PMU_BUF_CR_VPTATBUFFER_OUTEN_Msk);
	}
	else
	{
		PMU_BUF->CR &= ~(PMU_BUF_CR_VPTATBUFFER_OUTEN_Msk);
	}
}

FunState PMU_BUF_CR_VPTATBUFFER_OUTEN_Getable(void)
{
	if (PMU_BUF->CR & (PMU_BUF_CR_VPTATBUFFER_OUTEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Vptat Bufferģ��ʹ���źţ��ߵ�ƽʹ����Ч��(PTAT Buffer Enable) 0��Vptat buffer ģ�鲻ʹ�� 1��Vptat buffer ģ��ʹ�� ��غ��� */
void PMU_BUF_CR_VPTATBUFFER_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		PMU_BUF->CR |= (PMU_BUF_CR_VPTATBUFFER_EN_Msk);
	}
	else
	{
		PMU_BUF->CR &= ~(PMU_BUF_CR_VPTATBUFFER_EN_Msk);
	}
}

FunState PMU_BUF_CR_VPTATBUFFER_EN_Getable(void)
{
	if (PMU_BUF->CR & (PMU_BUF_CR_VPTATBUFFER_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Vref Bufferģ�鿪��ͨ�����ʹ���źţ��ߵ�ƽʹ����Ч��(VREF Buffer Output Enable) 0��Vref buffer ģ�������ʹ�� 1��Vref buffer ģ�����ʹ�� ��غ��� */
void PMU_BUF_CR_VREFBUFFER_OUTEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		PMU_BUF->CR |= (PMU_BUF_CR_VREFBUFFER_OUTEN_Msk);
	}
	else
	{
		PMU_BUF->CR &= ~(PMU_BUF_CR_VREFBUFFER_OUTEN_Msk);
	}
}

FunState PMU_BUF_CR_VREFBUFFER_OUTEN_Getable(void)
{
	if (PMU_BUF->CR & (PMU_BUF_CR_VREFBUFFER_OUTEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Vref Bufferģ��ʹ���źţ��ߵ�ƽʹ����Ч��(VREF Buffer Enable) 0��Vref buffer ģ�鲻ʹ��  1��Vref buffer ģ��ʹ�� ��غ��� */
void PMU_BUF_CR_VREFBUFFER_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		PMU_BUF->CR |= (PMU_BUF_CR_VREFBUFFER_EN_Msk);
	}
	else
	{
		PMU_BUF->CR &= ~(PMU_BUF_CR_VREFBUFFER_EN_Msk);
	}
}

FunState PMU_BUF_CR_VREFBUFFER_EN_Getable(void)
{
	if (PMU_BUF->CR & (PMU_BUF_CR_VREFBUFFER_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

void PMU_Deinit(void)
{

}

/********************************
�͹���ģʽ�ĳ�ʼ������
����:�͹���ģʽ�¸������ã�SLEEPģʽ��RAM�������ã��ں˵�ѹ�������·�ȡ�
���룺�͹��Ĺ��ܿ���ǰ������.
 ********************************/
void PMU_SleepCfg_Init(PMU_SleepCfg_InitTypeDef* SleepCfg_InitStruct)
{
	PMU_CR_SLPDP_Set(SleepCfg_InitStruct->SLPDP);				/*!<DeepSleep���ƼĴ���  */	
	PMU_CR_CVS_Setable(SleepCfg_InitStruct->CVS);				/*!<�ں˵�ѹ����ʹ�ܿ���  */	
	PMU_CR_WKFSEL_Set(SleepCfg_InitStruct->WKFSEL);			/*!<Sleep/DeepSleep���Ѻ��ϵͳƵ��  */	
	SCB->SCR = SleepCfg_InitStruct->SCR;							/*!<M0ϵͳ���ƼĴ�����һ������Ϊ0����  */
	PMU_CR_PMOD_Set(SleepCfg_InitStruct->PMOD);					/*!<�͹���ģʽ����  */	
	PMU_CR_LDO_LPM_Set(SleepCfg_InitStruct->LDO_LPM);			/*!LDO�͹���ģʽ����00/01/11������ģʽ10��LDO����͹���ģʽ*/
}



/******END OF FILE****/
