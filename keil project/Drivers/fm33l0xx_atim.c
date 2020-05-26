/**
  ******************************************************************************
  * @file    fm33l0xx_atim.c
  * @author  FM33L0 Application Team
  * @version V0.1.1
  * @date    6-Dec-2019
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33l0xx_atim.h"  
#include "fm33l0xx_rcc.h"  
/** @addtogroup fm33l0_StdPeriph_Driver
  * @{
  */

/** @defgroup ATIM 
  * @brief ATIM driver modules
  * @{
  */ 

void ATIM_TimeBaseInit(TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct)
{
  ATIM_CR1_CMS_Set(ATIM_CR1_CMS_SINGLE);//���ض���ģʽ
  ATIM_CR1_DIR_Set(TIM_TimeBaseInitStruct->TIM_CounterMode);
  ATIM_CR1_CKD_Set(TIM_TimeBaseInitStruct->TIM_ClockDivision);
  
  ATIM_ARR_Write(TIM_TimeBaseInitStruct->TIM_Period);
  ATIM_PSC_Write(TIM_TimeBaseInitStruct->TIM_Prescaler);
  ATIM_RCR_Write(TIM_TimeBaseInitStruct->TIM_RepetitionCounter);
  
  ATIM_EGR_UG_Setable(ENABLE);//�����¼����²���
}

void ATIM_ClearITPendingBit(uint32_t TIM_IT)
{
  ATIM->ISR = TIM_IT;
}

void ATIM_ITConfig(uint32_t TIM_IT, FunState NewState)
{  
  if (NewState != DISABLE)
  {
    ATIM->DIER |= TIM_IT;
  }
  else
  {
    ATIM->DIER &= ~TIM_IT;
  }
}

ITStatus ATIM_GetITStatus(uint32_t TIM_IT)
{ 
  uint32_t itstatus = 0x0, itenable = 0x0;
   
  itstatus = ATIM->ISR & TIM_IT;
  
  itenable = ATIM->DIER & TIM_IT;
  
  if ((itstatus != RESET) && (itenable != RESET))
  {
    return  SET;
  }
  else
  {
    return  RESET;
  }
}

void ATIM_Cmd(FunState NewState)
{
  
  if (NewState != DISABLE)
  {
    ATIM->CR1 |= ATIM_CR1_CEN_Msk;
  }
  else
  {
    ATIM->CR1 &= ~ATIM_CR1_CEN_Msk;
  }
}





/* Dead time�������˲�ʱ��Ƶ�ʷ�Ƶ�Ĵ��� ��غ��� */
void ATIM_CR1_CKD_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->CR1;
	tmpreg &= ~(ATIM_CR1_CKD_Msk);
	tmpreg |= (SetValue & ATIM_CR1_CKD_Msk);
	ATIM->CR1 = tmpreg;
}

uint32_t ATIM_CR1_CKD_Get(void)
{
	return (ATIM->CR1 & ATIM_CR1_CKD_Msk);
}

/* ARRԤװ��ʹ��  ��غ��� */
void ATIM_CR1_ARPE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->CR1 |= (ATIM_CR1_ARPE_Msk);
	}
	else
	{
		ATIM->CR1 &= ~(ATIM_CR1_ARPE_Msk);
	}
}

FunState ATIM_CR1_ARPE_Getable(void)
{
	if (ATIM->CR1 & (ATIM_CR1_ARPE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����������ģʽѡ�� ��غ��� */
void ATIM_CR1_CMS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->CR1;
	tmpreg &= ~(ATIM_CR1_CMS_Msk);
	tmpreg |= (SetValue & ATIM_CR1_CMS_Msk);
	ATIM->CR1 = tmpreg;
}

uint32_t ATIM_CR1_CMS_Get(void)
{
	return (ATIM->CR1 & ATIM_CR1_CMS_Msk);
}

/* ��������Ĵ��� ��غ��� */
void ATIM_CR1_DIR_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->CR1;
	tmpreg &= ~(ATIM_CR1_DIR_Msk);
	tmpreg |= (SetValue & ATIM_CR1_DIR_Msk);
	ATIM->CR1 = tmpreg;
}

uint32_t ATIM_CR1_DIR_Get(void)
{
	return (ATIM->CR1 & ATIM_CR1_DIR_Msk);
}

/* ���������ģʽ ��غ��� */
void ATIM_CR1_OPM_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->CR1 |= (ATIM_CR1_OPM_Msk);
	}
	else
	{
		ATIM->CR1 &= ~(ATIM_CR1_OPM_Msk);
	}
}

FunState ATIM_CR1_OPM_Getable(void)
{
	if (ATIM->CR1 & (ATIM_CR1_OPM_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��������ѡ�� ��غ��� */
void ATIM_CR1_URS_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->CR1 |= (ATIM_CR1_URS_Msk);
	}
	else
	{
		ATIM->CR1 &= ~(ATIM_CR1_URS_Msk);
	}
}

FunState ATIM_CR1_URS_Getable(void)
{
	if (ATIM->CR1 & (ATIM_CR1_URS_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��ֹupdate ��غ��� */
void ATIM_CR1_UDIS_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->CR1 |= (ATIM_CR1_UDIS_Msk);
	}
	else
	{
		ATIM->CR1 &= ~(ATIM_CR1_UDIS_Msk);
	}
}

FunState ATIM_CR1_UDIS_Getable(void)
{
	if (ATIM->CR1 & (ATIM_CR1_UDIS_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ������ʹ�� ��غ��� */
void ATIM_CR1_CEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->CR1 |= (ATIM_CR1_CEN_Msk);
	}
	else
	{
		ATIM->CR1 &= ~(ATIM_CR1_CEN_Msk);
	}
}

FunState ATIM_CR1_CEN_Getable(void)
{
	if (ATIM->CR1 & (ATIM_CR1_CEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �ο�OIS1 ��غ��� */
void ATIM_CR2_OIS4_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->CR2 |= (ATIM_CR2_OIS4_Msk);
	}
	else
	{
		ATIM->CR2 &= ~(ATIM_CR2_OIS4_Msk);
	}
}

FunState ATIM_CR2_OIS4_Getable(void)
{
	if (ATIM->CR2 & (ATIM_CR2_OIS4_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �ο�OIS1N ��غ��� */
void ATIM_CR2_OIS3N_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->CR2 |= (ATIM_CR2_OIS3N_Msk);
	}
	else
	{
		ATIM->CR2 &= ~(ATIM_CR2_OIS3N_Msk);
	}
}

FunState ATIM_CR2_OIS3N_Getable(void)
{
	if (ATIM->CR2 & (ATIM_CR2_OIS3N_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �ο�OIS1 ��غ��� */
void ATIM_CR2_OIS3_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->CR2 |= (ATIM_CR2_OIS3_Msk);
	}
	else
	{
		ATIM->CR2 &= ~(ATIM_CR2_OIS3_Msk);
	}
}

FunState ATIM_CR2_OIS3_Getable(void)
{
	if (ATIM->CR2 & (ATIM_CR2_OIS3_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �ο�OIS1N ��غ��� */
void ATIM_CR2_OIS2N_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->CR2 |= (ATIM_CR2_OIS2N_Msk);
	}
	else
	{
		ATIM->CR2 &= ~(ATIM_CR2_OIS2N_Msk);
	}
}

FunState ATIM_CR2_OIS2N_Getable(void)
{
	if (ATIM->CR2 & (ATIM_CR2_OIS2N_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �ο�OIS1 ��غ��� */
void ATIM_CR2_OIS2_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->CR2 |= (ATIM_CR2_OIS2_Msk);
	}
	else
	{
		ATIM->CR2 &= ~(ATIM_CR2_OIS2_Msk);
	}
}

FunState ATIM_CR2_OIS2_Getable(void)
{
	if (ATIM->CR2 & (ATIM_CR2_OIS2_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* OC1N�����IDLE״̬ ��غ��� */
void ATIM_CR2_OIS1N_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->CR2 |= (ATIM_CR2_OIS1N_Msk);
	}
	else
	{
		ATIM->CR2 &= ~(ATIM_CR2_OIS1N_Msk);
	}
}

FunState ATIM_CR2_OIS1N_Getable(void)
{
	if (ATIM->CR2 & (ATIM_CR2_OIS1N_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* OC1�����IDLE״̬ ��غ��� */
void ATIM_CR2_OIS1_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->CR2 |= (ATIM_CR2_OIS1_Msk);
	}
	else
	{
		ATIM->CR2 &= ~(ATIM_CR2_OIS1_Msk);
	}
}

FunState ATIM_CR2_OIS1_Getable(void)
{
	if (ATIM->CR2 & (ATIM_CR2_OIS1_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ATIM����TI1ѡ�� ��غ��� */
void ATIM_CR2_TI1S_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->CR2;
	tmpreg &= ~(ATIM_CR2_TI1S_Msk);
	tmpreg |= (SetValue & ATIM_CR2_TI1S_Msk);
	ATIM->CR2 = tmpreg;
}

uint32_t ATIM_CR2_TI1S_Get(void)
{
	return (ATIM->CR2 & ATIM_CR2_TI1S_Msk);
}

/* ����ģʽѡ��������������ģʽ����ӻ����͵�ͬ�������źţ�TRGO��Դ ��غ��� */
void ATIM_CR2_MMS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->CR2;
	tmpreg &= ~(ATIM_CR2_MMS_Msk);
	tmpreg |= (SetValue & ATIM_CR2_MMS_Msk);
	ATIM->CR2 = tmpreg;
}

uint32_t ATIM_CR2_MMS_Get(void)
{
	return (ATIM->CR2 & ATIM_CR2_MMS_Msk);
}

/* ��׽/�Ƚ� DMAѡ�� ��غ��� */
void ATIM_CR2_CCDS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->CR2;
	tmpreg &= ~(ATIM_CR2_CCDS_Msk);
	tmpreg |= (SetValue & ATIM_CR2_CCDS_Msk);
	ATIM->CR2 = tmpreg;
}

uint32_t ATIM_CR2_CCDS_Get(void)
{
	return (ATIM->CR2 & ATIM_CR2_CCDS_Msk);
}

/* ��׽/�ȽϿ��ƼĴ�������ѡ�� ��غ��� */
void ATIM_CR2_CCUS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->CR2;
	tmpreg &= ~(ATIM_CR2_CCUS_Msk);
	tmpreg |= (SetValue & ATIM_CR2_CCUS_Msk);
	ATIM->CR2 = tmpreg;
}

uint32_t ATIM_CR2_CCUS_Get(void)
{
	return (ATIM->CR2 & ATIM_CR2_CCUS_Msk);
}

void ATIM_CR2_CCPC_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->CR2 |= (ATIM_CR2_CCPC_Msk);
	}
	else
	{
		ATIM->CR2 &= ~(ATIM_CR2_CCPC_Msk);
	}
}

FunState ATIM_CR2_CCPC_Getable(void)
{
	if (ATIM->CR2 & (ATIM_CR2_CCPC_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �ⲿ�����źż������� ��غ��� */
void ATIM_SMCR_ETP_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->SMCR;
	tmpreg &= ~(ATIM_SMCR_ETP_Msk);
	tmpreg |= (SetValue & ATIM_SMCR_ETP_Msk);
	ATIM->SMCR = tmpreg;
}

uint32_t ATIM_SMCR_ETP_Get(void)
{
	return (ATIM->SMCR & ATIM_SMCR_ETP_Msk);
}

/* �ⲿʱ��ʹ�� ��غ��� */
void ATIM_SMCR_ECE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->SMCR |= (ATIM_SMCR_ECE_Msk);
	}
	else
	{
		ATIM->SMCR &= ~(ATIM_SMCR_ECE_Msk);
	}
}

FunState ATIM_SMCR_ECE_Getable(void)
{
	if (ATIM->SMCR & (ATIM_SMCR_ECE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �ⲿ�����ź�Ԥ��Ƶ�Ĵ���,�ⲿ�����ź�ETRP��Ƶ�����ֻ����ATIM����ʱ�ӵ�1/4���������ź�Ƶ�ʽϸ�ʱ������ʹ��Ԥ��Ƶ ��غ��� */
void ATIM_SMCR_ETPS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->SMCR;
	tmpreg &= ~(ATIM_SMCR_ETPS_Msk);
	tmpreg |= (SetValue & ATIM_SMCR_ETPS_Msk);
	ATIM->SMCR = tmpreg;
}

uint32_t ATIM_SMCR_ETPS_Get(void)
{
	return (ATIM->SMCR & ATIM_SMCR_ETPS_Msk);
}

/* �ⲿ�����ź��˲�ʱ�Ӻͳ���ѡ�� ��غ��� */
void ATIM_SMCR_ETF_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->SMCR;
	tmpreg &= ~(ATIM_SMCR_ETF_Msk);
	tmpreg |= (SetValue & ATIM_SMCR_ETF_Msk);
	ATIM->SMCR = tmpreg;
}

uint32_t ATIM_SMCR_ETF_Get(void)
{
	return (ATIM->SMCR & ATIM_SMCR_ETF_Msk);
}

/* �����ӻ�ģʽѡ ��غ��� */
void ATIM_SMCR_MSM_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->SMCR;
	tmpreg &= ~(ATIM_SMCR_MSM_Msk);
	tmpreg |= (SetValue & ATIM_SMCR_MSM_Msk);
	ATIM->SMCR = tmpreg;
}

uint32_t ATIM_SMCR_MSM_Get(void)
{
	return (ATIM->SMCR & ATIM_SMCR_MSM_Msk);
}

/* ����ѡ������ѡ��ͬ���������Ĵ���Դ ��غ��� */
void ATIM_SMCR_TS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->SMCR;
	tmpreg &= ~(ATIM_SMCR_TS_Msk);
	tmpreg |= (SetValue & ATIM_SMCR_TS_Msk);
	ATIM->SMCR = tmpreg;
}

uint32_t ATIM_SMCR_TS_Get(void)
{
	return (ATIM->SMCR & ATIM_SMCR_TS_Msk);
}

/* �ӻ�ģʽѡ�� ��غ��� */
void ATIM_SMCR_SMS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->SMCR;
	tmpreg &= ~(ATIM_SMCR_SMS_Msk);
	tmpreg |= (SetValue & ATIM_SMCR_SMS_Msk);
	ATIM->SMCR = tmpreg;
}

uint32_t ATIM_SMCR_SMS_Get(void)
{
	return (ATIM->SMCR & ATIM_SMCR_SMS_Msk);
}

/* ��׽�Ƚ�ͨ��4��DMAģʽ���� ��غ��� */
void ATIM_DIER_CC4BURSTEN_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->DIER;
	tmpreg &= ~(ATIM_DIER_CC4BURSTEN_Msk);
	tmpreg |= (SetValue & ATIM_DIER_CC4BURSTEN_Msk);
	ATIM->DIER = tmpreg;
}

uint32_t ATIM_DIER_CC4BURSTEN_Get(void)
{
	return (ATIM->DIER & ATIM_DIER_CC4BURSTEN_Msk);
}

/* ��׽�Ƚ�ͨ��3��DMAģʽ���� ��غ��� */
void ATIM_DIER_CC3BURSTEN_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->DIER;
	tmpreg &= ~(ATIM_DIER_CC3BURSTEN_Msk);
	tmpreg |= (SetValue & ATIM_DIER_CC3BURSTEN_Msk);
	ATIM->DIER = tmpreg;
}

uint32_t ATIM_DIER_CC3BURSTEN_Get(void)
{
	return (ATIM->DIER & ATIM_DIER_CC3BURSTEN_Msk);
}

/* ��׽�Ƚ�ͨ��2��DMAģʽ���� ��غ��� */
void ATIM_DIER_CC2BURSTEN_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->DIER;
	tmpreg &= ~(ATIM_DIER_CC2BURSTEN_Msk);
	tmpreg |= (SetValue & ATIM_DIER_CC2BURSTEN_Msk);
	ATIM->DIER = tmpreg;
}

uint32_t ATIM_DIER_CC2BURSTEN_Get(void)
{
	return (ATIM->DIER & ATIM_DIER_CC2BURSTEN_Msk);
}

/* ��׽�Ƚ�ͨ��1��DMAģʽ���� ��غ��� */
void ATIM_DIER_CC1BURSTEN_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->DIER;
	tmpreg &= ~(ATIM_DIER_CC1BURSTEN_Msk);
	tmpreg |= (SetValue & ATIM_DIER_CC1BURSTEN_Msk);
	ATIM->DIER = tmpreg;
}

uint32_t ATIM_DIER_CC1BURSTEN_Get(void)
{
	return (ATIM->DIER & ATIM_DIER_CC1BURSTEN_Msk);
}

/* �ⲿ����DMA����ʹ�� ��غ��� */
void ATIM_DIER_TDE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->DIER |= (ATIM_DIER_TDE_Msk);
	}
	else
	{
		ATIM->DIER &= ~(ATIM_DIER_TDE_Msk);
	}
}

FunState ATIM_DIER_TDE_Getable(void)
{
	if (ATIM->DIER & (ATIM_DIER_TDE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* COM�¼�DMA����ʹ�� ��غ��� */
void ATIM_DIER_COMDE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->DIER |= (ATIM_DIER_COMDE_Msk);
	}
	else
	{
		ATIM->DIER &= ~(ATIM_DIER_COMDE_Msk);
	}
}

FunState ATIM_DIER_COMDE_Getable(void)
{
	if (ATIM->DIER & (ATIM_DIER_COMDE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽�Ƚ�ͨ��4��DMA����ʹ�� ��غ��� */
void ATIM_DIER_CC4DE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->DIER |= (ATIM_DIER_CC4DE_Msk);
	}
	else
	{
		ATIM->DIER &= ~(ATIM_DIER_CC4DE_Msk);
	}
}

FunState ATIM_DIER_CC4DE_Getable(void)
{
	if (ATIM->DIER & (ATIM_DIER_CC4DE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽�Ƚ�ͨ��3��DMA����ʹ�� ��غ��� */
void ATIM_DIER_CC3DE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->DIER |= (ATIM_DIER_CC3DE_Msk);
	}
	else
	{
		ATIM->DIER &= ~(ATIM_DIER_CC3DE_Msk);
	}
}

FunState ATIM_DIER_CC3DE_Getable(void)
{
	if (ATIM->DIER & (ATIM_DIER_CC3DE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽�Ƚ�ͨ��2��DMA����ʹ�� ��غ��� */
void ATIM_DIER_CC2DE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->DIER |= (ATIM_DIER_CC2DE_Msk);
	}
	else
	{
		ATIM->DIER &= ~(ATIM_DIER_CC2DE_Msk);
	}
}

FunState ATIM_DIER_CC2DE_Getable(void)
{
	if (ATIM->DIER & (ATIM_DIER_CC2DE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽�Ƚ�ͨ��1��DMA����ʹ�� ��غ��� */
void ATIM_DIER_CC1DE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->DIER |= (ATIM_DIER_CC1DE_Msk);
	}
	else
	{
		ATIM->DIER &= ~(ATIM_DIER_CC1DE_Msk);
	}
}

FunState ATIM_DIER_CC1DE_Getable(void)
{
	if (ATIM->DIER & (ATIM_DIER_CC1DE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �����¼�DMA����ʹ��  ��غ��� */
void ATIM_DIER_UDE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->DIER |= (ATIM_DIER_UDE_Msk);
	}
	else
	{
		ATIM->DIER &= ~(ATIM_DIER_UDE_Msk);
	}
}

FunState ATIM_DIER_UDE_Getable(void)
{
	if (ATIM->DIER & (ATIM_DIER_UDE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ɲ���¼��ж�ʹ�� ��غ��� */
void ATIM_DIER_BIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->DIER |= (ATIM_DIER_BIE_Msk);
	}
	else
	{
		ATIM->DIER &= ~(ATIM_DIER_BIE_Msk);
	}
}

FunState ATIM_DIER_BIE_Getable(void)
{
	if (ATIM->DIER & (ATIM_DIER_BIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �����¼��ж�ʹ�� ��غ��� */
void ATIM_DIER_TIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->DIER |= (ATIM_DIER_TIE_Msk);
	}
	else
	{
		ATIM->DIER &= ~(ATIM_DIER_TIE_Msk);
	}
}

FunState ATIM_DIER_TIE_Getable(void)
{
	if (ATIM->DIER & (ATIM_DIER_TIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* COM�¼��ж�ʹ�� ��غ��� */
void ATIM_DIER_COMIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->DIER |= (ATIM_DIER_COMIE_Msk);
	}
	else
	{
		ATIM->DIER &= ~(ATIM_DIER_COMIE_Msk);
	}
}

FunState ATIM_DIER_COMIE_Getable(void)
{
	if (ATIM->DIER & (ATIM_DIER_COMIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�ͨ��4�ж�ʹ�� ��غ��� */
void ATIM_DIER_CC4IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->DIER |= (ATIM_DIER_CC4IE_Msk);
	}
	else
	{
		ATIM->DIER &= ~(ATIM_DIER_CC4IE_Msk);
	}
}

FunState ATIM_DIER_CC4IE_Getable(void)
{
	if (ATIM->DIER & (ATIM_DIER_CC4IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�ͨ��3�ж�ʹ�� ��غ��� */
void ATIM_DIER_CC3IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->DIER |= (ATIM_DIER_CC3IE_Msk);
	}
	else
	{
		ATIM->DIER &= ~(ATIM_DIER_CC3IE_Msk);
	}
}

FunState ATIM_DIER_CC3IE_Getable(void)
{
	if (ATIM->DIER & (ATIM_DIER_CC3IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�ͨ��2�ж�ʹ�� ��غ��� */
void ATIM_DIER_CC2IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->DIER |= (ATIM_DIER_CC2IE_Msk);
	}
	else
	{
		ATIM->DIER &= ~(ATIM_DIER_CC2IE_Msk);
	}
}

FunState ATIM_DIER_CC2IE_Getable(void)
{
	if (ATIM->DIER & (ATIM_DIER_CC2IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�ͨ��1�ж�ʹ�� ��غ��� */
void ATIM_DIER_CC1IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->DIER |= (ATIM_DIER_CC1IE_Msk);
	}
	else
	{
		ATIM->DIER &= ~(ATIM_DIER_CC1IE_Msk);
	}
}

FunState ATIM_DIER_CC1IE_Getable(void)
{
	if (ATIM->DIER & (ATIM_DIER_CC1IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �����¼��ж�ʹ�� ��غ��� */
void ATIM_DIER_UIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->DIER |= (ATIM_DIER_UIE_Msk);
	}
	else
	{
		ATIM->DIER &= ~(ATIM_DIER_UIE_Msk);
	}
}

FunState ATIM_DIER_UIE_Getable(void)
{
	if (ATIM->DIER & (ATIM_DIER_UIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�ͨ��4��Overcapture�ж� ��غ��� */
void ATIM_ISR_CC4OF_Clr(void)
{
	ATIM->ISR = ATIM_ISR_CC4OF_Msk;
}

FlagStatus ATIM_ISR_CC4OF_Chk(void)
{
	if (ATIM->ISR & ATIM_ISR_CC4OF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��׽/�Ƚ�ͨ��3��Overcapture�ж� ��غ��� */
void ATIM_ISR_CC3OF_Clr(void)
{
	ATIM->ISR = ATIM_ISR_CC3OF_Msk;
}

FlagStatus ATIM_ISR_CC3OF_Chk(void)
{
	if (ATIM->ISR & ATIM_ISR_CC3OF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��׽/�Ƚ�ͨ��2��Overcapture�ж� ��غ��� */
void ATIM_ISR_CC2OF_Clr(void)
{
	ATIM->ISR = ATIM_ISR_CC2OF_Msk;
}

FlagStatus ATIM_ISR_CC2OF_Chk(void)
{
	if (ATIM->ISR & ATIM_ISR_CC2OF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��׽/�Ƚ�ͨ��1��Overcapture�жϣ��˼Ĵ������ڶ�Ӧͨ������Ϊ���벶׽ģʽ���������Ч��Ӳ����λ�����д1���� ��غ��� */
void ATIM_ISR_CC1OF_Clr(void)
{
	ATIM->ISR = ATIM_ISR_CC1OF_Msk;
}

FlagStatus ATIM_ISR_CC1OF_Chk(void)
{
	if (ATIM->ISR & ATIM_ISR_CC1OF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ɲ���¼��жϱ�־��Ӳ����λ�����д1���� ��غ��� */
void ATIM_ISR_BIF_Clr(void)
{
	ATIM->ISR = ATIM_ISR_BIF_Msk;
}

FlagStatus ATIM_ISR_BIF_Chk(void)
{
	if (ATIM->ISR & ATIM_ISR_BIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �����¼��жϱ�־��Ӳ����λ�����д1���� ��غ��� */
void ATIM_ISR_TIF_Clr(void)
{
	ATIM->ISR = ATIM_ISR_TIF_Msk;
}

FlagStatus ATIM_ISR_TIF_Chk(void)
{
	if (ATIM->ISR & ATIM_ISR_TIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* COM�¼��жϱ�־��Ӳ����λ�����д1���� ��غ��� */
void ATIM_ISR_COMIF_Clr(void)
{
	ATIM->ISR = ATIM_ISR_COMIF_Msk;
}

FlagStatus ATIM_ISR_COMIF_Chk(void)
{
	if (ATIM->ISR & ATIM_ISR_COMIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��׽/�Ƚ�ͨ��4�жϱ�־���ο�CC1IF ��غ��� */
void ATIM_ISR_CC4IF_Clr(void)
{
	ATIM->ISR = ATIM_ISR_CC4IF_Msk;
}

FlagStatus ATIM_ISR_CC4IF_Chk(void)
{
	if (ATIM->ISR & ATIM_ISR_CC4IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��׽/�Ƚ�ͨ��3�жϱ�־���ο�CC1IF ��غ��� */
void ATIM_ISR_CC3IF_Clr(void)
{
	ATIM->ISR = ATIM_ISR_CC3IF_Msk;
}

FlagStatus ATIM_ISR_CC3IF_Chk(void)
{
	if (ATIM->ISR & ATIM_ISR_CC3IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��׽/�Ƚ�ͨ��2�жϱ�־���ο�CC1IF ��غ��� */
void ATIM_ISR_CC2IF_Clr(void)
{
	ATIM->ISR = ATIM_ISR_CC2IF_Msk;
}

FlagStatus ATIM_ISR_CC2IF_Chk(void)
{
	if (ATIM->ISR & ATIM_ISR_CC2IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��׽/�Ƚ�ͨ��1�жϱ�־�����CC1ͨ������Ϊ�����CC1IF�ڼ���ֵ���ڱȽ�ֵʱ��λ�����д1���㡣
���CC1ͨ������Ϊ���룺������׽�¼�ʱ��λ�����д1���㣬���������ATIM_CCR1�Զ����� ��غ��� */
void ATIM_ISR_CC1IF_Clr(void)
{
	ATIM->ISR = ATIM_ISR_CC1IF_Msk;
}

FlagStatus ATIM_ISR_CC1IF_Chk(void)
{
	if (ATIM->ISR & ATIM_ISR_CC1IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �����¼��жϱ�־��Ӳ����λ�����д1���� ��غ��� */
void ATIM_ISR_UIF_Clr(void)
{
	ATIM->ISR = ATIM_ISR_UIF_Msk;
}

FlagStatus ATIM_ISR_UIF_Chk(void)
{
	if (ATIM->ISR & ATIM_ISR_UIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���ɲ���������λ�˼Ĵ�������ɲ���¼���Ӳ���Զ����� ��غ��� */
void ATIM_EGR_BG_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->EGR |= (ATIM_EGR_BG_Msk);
	}
	else
	{
		ATIM->EGR &= ~(ATIM_EGR_BG_Msk);
	}
}

/* ��������������λ�˼Ĵ������������¼���Ӳ���Զ����� ��غ��� */
void ATIM_EGR_TIF_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->EGR |= (ATIM_EGR_TIF_Msk);
	}
	else
	{
		ATIM->EGR &= ~(ATIM_EGR_TIF_Msk);
	}
}

/* ���COM�¼���Ӳ����λ�����д1���� ��غ��� */
void ATIM_EGR_COMG_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->EGR |= (ATIM_EGR_COMG_Msk);
	}
	else
	{
		ATIM->EGR &= ~(ATIM_EGR_COMG_Msk);
	}
}

/* ��׽/�Ƚ�ͨ��4����������ο�CC1G ��غ��� */
void ATIM_EGR_CC4G_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->EGR |= (ATIM_EGR_CC4G_Msk);
	}
	else
	{
		ATIM->EGR &= ~(ATIM_EGR_CC4G_Msk);
	}
}

/* ��׽/�Ƚ�ͨ��3����������ο�CC1G ��غ��� */
void ATIM_EGR_CC3G_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->EGR |= (ATIM_EGR_CC3G_Msk);
	}
	else
	{
		ATIM->EGR &= ~(ATIM_EGR_CC3G_Msk);
	}
}

/* ��׽/�Ƚ�ͨ��2����������ο�CC1G ��غ��� */
void ATIM_EGR_CC2G_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->EGR |= (ATIM_EGR_CC2G_Msk);
	}
	else
	{
		ATIM->EGR &= ~(ATIM_EGR_CC2G_Msk);
	}
}

/* ��׽/�Ƚ�ͨ��1������� ��غ��� */
void ATIM_EGR_CC1G_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->EGR |= (ATIM_EGR_CC1G_Msk);
	}
	else
	{
		ATIM->EGR &= ~(ATIM_EGR_CC1G_Msk);
	}
}

/* ���Update�¼��������λ�˼Ĵ�������Update�¼���Ӳ���Զ����� ��غ��� */
void ATIM_EGR_UG_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->EGR |= (ATIM_EGR_UG_Msk);
	}
	else
	{
		ATIM->EGR &= ~(ATIM_EGR_UG_Msk);
	}
}

/* ����Ƚ�2����ʹ�ܣ��ο�OC1CE ��غ��� */
void ATIM_CCMR1_OC2CE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->CCMR1 |= (ATIM_CCMR1_OC2CE_Msk);
	}
	else
	{
		ATIM->CCMR1 &= ~(ATIM_CCMR1_OC2CE_Msk);
	}
}

FunState ATIM_CCMR1_OC2CE_Getable(void)
{
	if (ATIM->CCMR1 & (ATIM_CCMR1_OC2CE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����Ƚ�2ģʽ���ã��ο�OC1M ��غ��� */
void ATIM_CCMR1_OC2M_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->CCMR1;
	tmpreg &= ~(ATIM_CCMR1_OC2M_Msk);
	tmpreg |= (SetValue & ATIM_CCMR1_OC2M_Msk);
	ATIM->CCMR1 = tmpreg;
}

uint32_t ATIM_CCMR1_OC2M_Get(void)
{
	return (ATIM->CCMR1 & ATIM_CCMR1_OC2M_Msk);
}

/* ����Ƚ�2Ԥװ��ʹ�ܣ��ο�OC1PE ��غ��� */
void ATIM_CCMR1_OC2PE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->CCMR1 |= (ATIM_CCMR1_OC2PE_Msk);
	}
	else
	{
		ATIM->CCMR1 &= ~(ATIM_CCMR1_OC2PE_Msk);
	}
}

FunState ATIM_CCMR1_OC2PE_Getable(void)
{
	if (ATIM->CCMR1 & (ATIM_CCMR1_OC2PE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����Ƚ�2����ʹ�ܣ��ο�OC1FE ��غ��� */
void ATIM_CCMR1_OC2FE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->CCMR1 |= (ATIM_CCMR1_OC2FE_Msk);
	}
	else
	{
		ATIM->CCMR1 &= ~(ATIM_CCMR1_OC2FE_Msk);
	}
}

FunState ATIM_CCMR1_OC2FE_Getable(void)
{
	if (ATIM->CCMR1 & (ATIM_CCMR1_OC2FE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�2ͨ��ѡ�� ��غ��� */
void ATIM_CCMR1_CC2S_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->CCMR1;
	tmpreg &= ~(ATIM_CCMR1_CC2S_Msk);
	tmpreg |= (SetValue & ATIM_CCMR1_CC2S_Msk);
	ATIM->CCMR1 = tmpreg;
}

uint32_t ATIM_CCMR1_CC2S_Get(void)
{
	return (ATIM->CCMR1 & ATIM_CCMR1_CC2S_Msk);
}

/* ����Ƚ�1����ʹ�� ��غ��� */
void ATIM_CCMR1_OC1CE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->CCMR1 |= (ATIM_CCMR1_OC1CE_Msk);
	}
	else
	{
		ATIM->CCMR1 &= ~(ATIM_CCMR1_OC1CE_Msk);
	}
}

FunState ATIM_CCMR1_OC1CE_Getable(void)
{
	if (ATIM->CCMR1 & (ATIM_CCMR1_OC1CE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����Ƚ�1ģʽ���ã��˼Ĵ�������OC1REF�źŵ���Ϊ ��غ��� */
void ATIM_CCMR1_OC1M_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->CCMR1;
	tmpreg &= ~(ATIM_CCMR1_OC1M_Msk);
	tmpreg |= (SetValue & ATIM_CCMR1_OC1M_Msk);
	ATIM->CCMR1 = tmpreg;
}

uint32_t ATIM_CCMR1_OC1M_Get(void)
{
	return (ATIM->CCMR1 & ATIM_CCMR1_OC1M_Msk);
}

/* ����Ƚ�1Ԥװ��ʹ�� ��غ��� */
void ATIM_CCMR1_OC1PE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->CCMR1 |= (ATIM_CCMR1_OC1PE_Msk);
	}
	else
	{
		ATIM->CCMR1 &= ~(ATIM_CCMR1_OC1PE_Msk);
	}
}

FunState ATIM_CCMR1_OC1PE_Getable(void)
{
	if (ATIM->CCMR1 & (ATIM_CCMR1_OC1PE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����Ƚ�1����ʹ�� ��غ��� */
void ATIM_CCMR1_OC1FE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->CCMR1 |= (ATIM_CCMR1_OC1FE_Msk);
	}
	else
	{
		ATIM->CCMR1 &= ~(ATIM_CCMR1_OC1FE_Msk);
	}
}

FunState ATIM_CCMR1_OC1FE_Getable(void)
{
	if (ATIM->CCMR1 & (ATIM_CCMR1_OC1FE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�1ͨ��ѡ�� ��غ��� */
void ATIM_CCMR1_CC1S_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->CCMR1;
	tmpreg &= ~(ATIM_CCMR1_CC1S_Msk);
	tmpreg |= (SetValue & ATIM_CCMR1_CC1S_Msk);
	ATIM->CCMR1 = tmpreg;
}

uint32_t ATIM_CCMR1_CC1S_Get(void)
{
	return (ATIM->CCMR1 & ATIM_CCMR1_CC1S_Msk);
}

/* ���벶׽2�˲� ��غ��� */
void ATIM_CCMR1_IC2F_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->CCMR1;
	tmpreg &= ~(ATIM_CCMR1_IC2F_Msk);
	tmpreg |= (SetValue & ATIM_CCMR1_IC2F_Msk);
	ATIM->CCMR1 = tmpreg;
}

uint32_t ATIM_CCMR1_IC2F_Get(void)
{
	return (ATIM->CCMR1 & ATIM_CCMR1_IC2F_Msk);
}

/* ���벶׽2Ԥ��Ƶ ��غ��� */
void ATIM_CCMR1_IC2PSC_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->CCMR1;
	tmpreg &= ~(ATIM_CCMR1_IC2PSC_Msk);
	tmpreg |= (SetValue & ATIM_CCMR1_IC2PSC_Msk);
	ATIM->CCMR1 = tmpreg;
}

uint32_t ATIM_CCMR1_IC2PSC_Get(void)
{
	return (ATIM->CCMR1 & ATIM_CCMR1_IC2PSC_Msk);
}

/* ���벶׽1�˲� ��غ��� */
void ATIM_CCMR1_IC1F_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->CCMR1;
	tmpreg &= ~(ATIM_CCMR1_IC1F_Msk);
	tmpreg |= (SetValue & ATIM_CCMR1_IC1F_Msk);
	ATIM->CCMR1 = tmpreg;
}

uint32_t ATIM_CCMR1_IC1F_Get(void)
{
	return (ATIM->CCMR1 & ATIM_CCMR1_IC1F_Msk);
}

/* ���벶׽1Ԥ��Ƶ ��غ��� */
void ATIM_CCMR1_IC1PSC_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->CCMR1;
	tmpreg &= ~(ATIM_CCMR1_IC1PSC_Msk);
	tmpreg |= (SetValue & ATIM_CCMR1_IC1PSC_Msk);
	ATIM->CCMR1 = tmpreg;
}

uint32_t ATIM_CCMR1_IC1PSC_Get(void)
{
	return (ATIM->CCMR1 & ATIM_CCMR1_IC1PSC_Msk);
}

/* ����Ƚ�4����ʹ�ܣ��ο�OC1CE ��غ��� */
void ATIM_CCMR2_OC4CE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->CCMR2 |= (ATIM_CCMR2_OC4CE_Msk);
	}
	else
	{
		ATIM->CCMR2 &= ~(ATIM_CCMR2_OC4CE_Msk);
	}
}

FunState ATIM_CCMR2_OC4CE_Getable(void)
{
	if (ATIM->CCMR2 & (ATIM_CCMR2_OC4CE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

void ATIM_CCMR2_OC4M_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->CCMR2;
	tmpreg &= ~(ATIM_CCMR2_OC4M_Msk);
	tmpreg |= (SetValue & ATIM_CCMR2_OC4M_Msk);
	ATIM->CCMR2 = tmpreg;
}

uint32_t ATIM_CCMR2_OC4M_Get(void)
{
	return (ATIM->CCMR2 & ATIM_CCMR2_OC4M_Msk);
}

/* ����Ƚ�4Ԥװ��ʹ�ܣ��ο�OC1PE ��غ��� */
void ATIM_CCMR2_OC4PE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->CCMR2 |= (ATIM_CCMR2_OC4PE_Msk);
	}
	else
	{
		ATIM->CCMR2 &= ~(ATIM_CCMR2_OC4PE_Msk);
	}
}

FunState ATIM_CCMR2_OC4PE_Getable(void)
{
	if (ATIM->CCMR2 & (ATIM_CCMR2_OC4PE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����Ƚ�4����ʹ�ܣ��ο�OC1FE ��غ��� */
void ATIM_CCMR2_OC4FE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->CCMR2 |= (ATIM_CCMR2_OC4FE_Msk);
	}
	else
	{
		ATIM->CCMR2 &= ~(ATIM_CCMR2_OC4FE_Msk);
	}
}

FunState ATIM_CCMR2_OC4FE_Getable(void)
{
	if (ATIM->CCMR2 & (ATIM_CCMR2_OC4FE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�4ͨ��ѡ�� ��غ��� */
void ATIM_CCMR2_CC4S_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->CCMR2;
	tmpreg &= ~(ATIM_CCMR2_CC4S_Msk);
	tmpreg |= (SetValue & ATIM_CCMR2_CC4S_Msk);
	ATIM->CCMR2 = tmpreg;
}

uint32_t ATIM_CCMR2_CC4S_Get(void)
{
	return (ATIM->CCMR2 & ATIM_CCMR2_CC4S_Msk);
}

/* ����Ƚ�1����ʹ�� ��غ��� */
void ATIM_CCMR2_OC3CE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->CCMR2 |= (ATIM_CCMR2_OC3CE_Msk);
	}
	else
	{
		ATIM->CCMR2 &= ~(ATIM_CCMR2_OC3CE_Msk);
	}
}

FunState ATIM_CCMR2_OC3CE_Getable(void)
{
	if (ATIM->CCMR2 & (ATIM_CCMR2_OC3CE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����Ƚ�3ģʽ���ã��˼Ĵ�������OC3REF�źŵ���Ϊ ��غ��� */
void ATIM_CCMR2_OC3M_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->CCMR2;
	tmpreg &= ~(ATIM_CCMR2_OC3M_Msk);
	tmpreg |= (SetValue & ATIM_CCMR2_OC3M_Msk);
	ATIM->CCMR2 = tmpreg;
}

uint32_t ATIM_CCMR2_OC3M_Get(void)
{
	return (ATIM->CCMR2 & ATIM_CCMR2_OC3M_Msk);
}

/* ����Ƚ�3Ԥװ��ʹ�� ��غ��� */
void ATIM_CCMR2_OC3PE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->CCMR2 |= (ATIM_CCMR2_OC3PE_Msk);
	}
	else
	{
		ATIM->CCMR2 &= ~(ATIM_CCMR2_OC3PE_Msk);
	}
}

FunState ATIM_CCMR2_OC3PE_Getable(void)
{
	if (ATIM->CCMR2 & (ATIM_CCMR2_OC3PE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����Ƚ�3����ʹ�� ��غ��� */
void ATIM_CCMR2_OC3FE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->CCMR2 |= (ATIM_CCMR2_OC3FE_Msk);
	}
	else
	{
		ATIM->CCMR2 &= ~(ATIM_CCMR2_OC3FE_Msk);
	}
}

FunState ATIM_CCMR2_OC3FE_Getable(void)
{
	if (ATIM->CCMR2 & (ATIM_CCMR2_OC3FE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�3ͨ��ѡ�� ��غ��� */
void ATIM_CCMR2_CC3S_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->CCMR2;
	tmpreg &= ~(ATIM_CCMR2_CC3S_Msk);
	tmpreg |= (SetValue & ATIM_CCMR2_CC3S_Msk);
	ATIM->CCMR2 = tmpreg;
}

uint32_t ATIM_CCMR2_CC3S_Get(void)
{
	return (ATIM->CCMR2 & ATIM_CCMR2_CC3S_Msk);
}

/* ���벶׽4�˲� ��غ��� */
void ATIM_CCMR2_IC4F_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->CCMR2;
	tmpreg &= ~(ATIM_CCMR2_IC4F_Msk);
	tmpreg |= (SetValue & ATIM_CCMR2_IC4F_Msk);
	ATIM->CCMR2 = tmpreg;
}

uint32_t ATIM_CCMR2_IC4F_Get(void)
{
	return (ATIM->CCMR2 & ATIM_CCMR2_IC4F_Msk);
}

/* ���벶׽4Ԥ��Ƶ ��غ��� */
void ATIM_CCMR2_IC4PSC_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->CCMR2;
	tmpreg &= ~(ATIM_CCMR2_IC4PSC_Msk);
	tmpreg |= (SetValue & ATIM_CCMR2_IC4PSC_Msk);
	ATIM->CCMR2 = tmpreg;
}

uint32_t ATIM_CCMR2_IC4PSC_Get(void)
{
	return (ATIM->CCMR2 & ATIM_CCMR2_IC4PSC_Msk);
}

/* ���벶׽3�˲� ��غ��� */
void ATIM_CCMR2_IC3F_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->CCMR2;
	tmpreg &= ~(ATIM_CCMR2_IC3F_Msk);
	tmpreg |= (SetValue & ATIM_CCMR2_IC3F_Msk);
	ATIM->CCMR2 = tmpreg;
}

uint32_t ATIM_CCMR2_IC3F_Get(void)
{
	return (ATIM->CCMR2 & ATIM_CCMR2_IC3F_Msk);
}

/* ���벶׽3Ԥ��Ƶ ��غ��� */
void ATIM_CCMR2_IC3PSC_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->CCMR2;
	tmpreg &= ~(ATIM_CCMR2_IC3PSC_Msk);
	tmpreg |= (SetValue & ATIM_CCMR2_IC3PSC_Msk);
	ATIM->CCMR2 = tmpreg;
}

uint32_t ATIM_CCMR2_IC3PSC_Get(void)
{
	return (ATIM->CCMR2 & ATIM_CCMR2_IC3PSC_Msk);
}

/* ��׽/�Ƚ�4������ԣ��ο�CC1P ��غ��� */
void ATIM_CCER_CC4P_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->CCER;
	tmpreg &= ~(ATIM_CCER_CC4P_Msk);
	tmpreg |= (SetValue & ATIM_CCER_CC4P_Msk);
	ATIM->CCER = tmpreg;
}

uint32_t ATIM_CCER_CC4P_Get(void)
{
	return (ATIM->CCER & ATIM_CCER_CC4P_Msk);
}

/* ��׽/�Ƚ�4���ʹ�ܣ��ο�CC1E ��غ��� */
void ATIM_CCER_CC4E_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->CCER |= (ATIM_CCER_CC4E_Msk);
	}
	else
	{
		ATIM->CCER &= ~(ATIM_CCER_CC4E_Msk);
	}
}

FunState ATIM_CCER_CC4E_Getable(void)
{
	if (ATIM->CCER & (ATIM_CCER_CC4E_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�3����������ԣ��ο�CC1NP ��غ��� */
void ATIM_CCER_CC3NP_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->CCER;
	tmpreg &= ~(ATIM_CCER_CC3NP_Msk);
	tmpreg |= (SetValue & ATIM_CCER_CC3NP_Msk);
	ATIM->CCER = tmpreg;
}

uint32_t ATIM_CCER_CC3NP_Get(void)
{
	return (ATIM->CCER & ATIM_CCER_CC3NP_Msk);
}

/* ��׽/�Ƚ�3�������ʹ�ܣ��ο�CC1NE ��غ��� */
void ATIM_CCER_CC3NE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->CCER |= (ATIM_CCER_CC3NE_Msk);
	}
	else
	{
		ATIM->CCER &= ~(ATIM_CCER_CC3NE_Msk);
	}
}

FunState ATIM_CCER_CC3NE_Getable(void)
{
	if (ATIM->CCER & (ATIM_CCER_CC3NE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�3������ԣ��ο�CC1P ��غ��� */
void ATIM_CCER_CC3P_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->CCER;
	tmpreg &= ~(ATIM_CCER_CC3P_Msk);
	tmpreg |= (SetValue & ATIM_CCER_CC3P_Msk);
	ATIM->CCER = tmpreg;
}

uint32_t ATIM_CCER_CC3P_Get(void)
{
	return (ATIM->CCER & ATIM_CCER_CC3P_Msk);
}

/* ��׽/�Ƚ�3���ʹ�ܣ��ο�CC1E ��غ��� */
void ATIM_CCER_CC3E_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->CCER |= (ATIM_CCER_CC3E_Msk);
	}
	else
	{
		ATIM->CCER &= ~(ATIM_CCER_CC3E_Msk);
	}
}

FunState ATIM_CCER_CC3E_Getable(void)
{
	if (ATIM->CCER & (ATIM_CCER_CC3E_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�2����������ԣ��ο�CC1NP ��غ��� */
void ATIM_CCER_CC2NP_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->CCER;
	tmpreg &= ~(ATIM_CCER_CC2NP_Msk);
	tmpreg |= (SetValue & ATIM_CCER_CC2NP_Msk);
	ATIM->CCER = tmpreg;
}

uint32_t ATIM_CCER_CC2NP_Get(void)
{
	return (ATIM->CCER & ATIM_CCER_CC2NP_Msk);
}

/* ��׽/�Ƚ�2�������ʹ�ܣ��ο�CC1NE ��غ��� */
void ATIM_CCER_CC2NE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->CCER |= (ATIM_CCER_CC2NE_Msk);
	}
	else
	{
		ATIM->CCER &= ~(ATIM_CCER_CC2NE_Msk);
	}
}

FunState ATIM_CCER_CC2NE_Getable(void)
{
	if (ATIM->CCER & (ATIM_CCER_CC2NE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�2������ԣ��ο�CC1P ��غ��� */
void ATIM_CCER_CC2P_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->CCER;
	tmpreg &= ~(ATIM_CCER_CC2P_Msk);
	tmpreg |= (SetValue & ATIM_CCER_CC2P_Msk);
	ATIM->CCER = tmpreg;
}

uint32_t ATIM_CCER_CC2P_Get(void)
{
	return (ATIM->CCER & ATIM_CCER_CC2P_Msk);
}

/* ��׽/�Ƚ�2���ʹ�ܣ��ο�CC1E ��غ��� */
void ATIM_CCER_CC2E_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->CCER |= (ATIM_CCER_CC2E_Msk);
	}
	else
	{
		ATIM->CCER &= ~(ATIM_CCER_CC2E_Msk);
	}
}

FunState ATIM_CCER_CC2E_Getable(void)
{
	if (ATIM->CCER & (ATIM_CCER_CC2E_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�1����������� ��غ��� */
void ATIM_CCER_CC1NP_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->CCER;
	tmpreg &= ~(ATIM_CCER_CC1NP_Msk);
	tmpreg |= (SetValue & ATIM_CCER_CC1NP_Msk);
	ATIM->CCER = tmpreg;
}

uint32_t ATIM_CCER_CC1NP_Get(void)
{
	return (ATIM->CCER & ATIM_CCER_CC1NP_Msk);
}

/* ��׽/�Ƚ�1�������ʹ�� ��غ��� */
void ATIM_CCER_CC1NE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->CCER |= (ATIM_CCER_CC1NE_Msk);
	}
	else
	{
		ATIM->CCER &= ~(ATIM_CCER_CC1NE_Msk);
	}
}

FunState ATIM_CCER_CC1NE_Getable(void)
{
	if (ATIM->CCER & (ATIM_CCER_CC1NE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�1������� (CC1 Polarity)
CC1ͨ������Ϊ���ʱ
0��OC1�ߵ�ƽactive
1��OC1�͵�ƽactive
CC1ͨ������Ϊ����ʱ
0����ȡ��ģʽ�C��׽��IC1�������ؽ���
1��ȡ��ģʽ�C��׽��IC1���½��ؽ��� ��غ��� */
void ATIM_CCER_CC1P_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->CCER;
	tmpreg &= ~(ATIM_CCER_CC1P_Msk);
	tmpreg |= (SetValue & ATIM_CCER_CC1P_Msk);
	ATIM->CCER = tmpreg;
}

uint32_t ATIM_CCER_CC1P_Get(void)
{
	return (ATIM->CCER & ATIM_CCER_CC1P_Msk);
}

/* ��׽/�Ƚ�1���ʹ�� (CC1 Enable)
CC1ͨ������Ϊ���ʱ
0��OC1��active
1��OC1 active
CC1ͨ������Ϊ����ʱ
0���رղ�׽����
1��ʹ�ܲ�׽���� ��غ��� */
void ATIM_CCER_CC1E_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->CCER |= (ATIM_CCER_CC1E_Msk);
	}
	else
	{
		ATIM->CCER &= ~(ATIM_CCER_CC1E_Msk);
	}
}

FunState ATIM_CCER_CC1E_Getable(void)
{
	if (ATIM->CCER & (ATIM_CCER_CC1E_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ������ֵ ��غ��� */
void ATIM_CNT_Write(uint32_t SetValue)
{
	ATIM->CNT = (SetValue & ATIM_CNT_CNT_Msk);
}

uint32_t ATIM_CNT_Read(void)
{
	return (ATIM->CNT & ATIM_CNT_CNT_Msk);
}

/* ������ʱ��Ԥ��Ƶֵ
fCK_CNT=fCK_PSC/(PSC[15:0]+1)
����һ��preload�Ĵ�������update�¼�����ʱ�����ݱ�����shadow�Ĵ��� ��غ��� */
void ATIM_PSC_Write(uint32_t SetValue)
{
	ATIM->PSC = (SetValue & ATIM_PSC_PSC_Msk);
}

uint32_t ATIM_PSC_Read(void)
{
	return (ATIM->PSC & ATIM_PSC_PSC_Msk);
}

/* �������ʱ���Զ�����ֵ 
����һ��preload�Ĵ�������update�¼�����ʱ�����ݱ�����shadow�Ĵ��� ��غ��� */
void ATIM_ARR_Write(uint32_t SetValue)
{
	ATIM->ARR = (SetValue & ATIM_ARR_ARR_Msk);
}

uint32_t ATIM_ARR_Read(void)
{
	return (ATIM->ARR & ATIM_ARR_ARR_Msk);
}

/* �ظ�����ֵ  ��غ��� */
void ATIM_RCR_Write(uint32_t SetValue)
{
	ATIM->RCR = (SetValue & ATIM_RCR_REP_Msk);
}

uint32_t ATIM_RCR_Read(void)
{
	return (ATIM->RCR & ATIM_RCR_REP_Msk);
}

/* ��׽/�Ƚ�ͨ��1�Ĵ��� 
���ͨ��1����Ϊ�����
����һ��preload�Ĵ����������ݱ�����shadow�Ĵ�����������������Ƚϲ���OC1���
���ͨ��1����Ϊ���룺
CCR1�������һ�����벶׽�¼�����ʱ�ļ�����ֵ����ʱCCR1Ϊֻ�� ��غ��� */
void ATIM_CCR1_Write(uint32_t SetValue)
{
	ATIM->CCR1 = (SetValue & ATIM_CCR1_CCR1_Msk);
}

uint32_t ATIM_CCR1_Read(void)
{
	return (ATIM->CCR1 & ATIM_CCR1_CCR1_Msk);
}

/* ��׽/�Ƚ�ͨ��2�Ĵ��� 
���ͨ��2����Ϊ�����
����һ��preload�Ĵ����������ݱ�����shadow�Ĵ�����������������Ƚϲ���OC2���
���ͨ��2����Ϊ���룺
CCR2�������һ�����벶׽�¼�����ʱ�ļ�����ֵ����ʱCCR2Ϊֻ�� ��غ��� */
void ATIM_CCR2_Write(uint32_t SetValue)
{
	ATIM->CCR2 = (SetValue & ATIM_CCR2_CCR2_Msk);
}

uint32_t ATIM_CCR2_Read(void)
{
	return (ATIM->CCR2 & ATIM_CCR2_CCR2_Msk);
}

/* ��׽/�Ƚ�ͨ��3�Ĵ��� 
���ͨ��3����Ϊ�����
����һ��preload�Ĵ����������ݱ�����shadow�Ĵ�����������������Ƚϲ���OC3���
���ͨ��3����Ϊ���룺
CCR3�������һ�����벶׽�¼�����ʱ�ļ�����ֵ����ʱCCR3Ϊֻ�� ��غ��� */
void ATIM_CCR3_Write(uint32_t SetValue)
{
	ATIM->CCR3 = (SetValue & ATIM_CCR3_CCR3_Msk);
}

uint32_t ATIM_CCR3_Read(void)
{
	return (ATIM->CCR3 & ATIM_CCR3_CCR3_Msk);
}

/* ��׽/�Ƚ�ͨ��4�Ĵ��� 
���ͨ��4����Ϊ�����
����һ��preload�Ĵ����������ݱ�����shadow�Ĵ�����������������Ƚϲ���OC4���
���ͨ��4����Ϊ���룺
CCR4�������һ�����벶׽�¼�����ʱ�ļ�����ֵ����ʱCCR4Ϊֻ�� ��غ��� */
void ATIM_CCR4_Write(uint32_t SetValue)
{
	ATIM->CCR4 = (SetValue & ATIM_CCR4_CCR4_Msk);
}

uint32_t ATIM_CCR4_Read(void)
{
	return (ATIM->CCR4 & ATIM_CCR4_CCR4_Msk);
}

/* ���ʹ������ ��غ��� */
void ATIM_BDTR_MOE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->BDTR |= (ATIM_BDTR_MOE_Msk);
	}
	else
	{
		ATIM->BDTR &= ~(ATIM_BDTR_MOE_Msk);
	}
}

FunState ATIM_BDTR_MOE_Getable(void)
{
	if (ATIM->BDTR & (ATIM_BDTR_MOE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �Զ����ʹ�� ��غ��� */
void ATIM_BDTR_AOE_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->BDTR;
	tmpreg &= ~(ATIM_BDTR_AOE_Msk);
	tmpreg |= (SetValue & ATIM_BDTR_AOE_Msk);
	ATIM->BDTR = tmpreg;
}

uint32_t ATIM_BDTR_AOE_Get(void)
{
	return (ATIM->BDTR & ATIM_BDTR_AOE_Msk);
}

void ATIM_BDTR_BKP_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->BDTR;
	tmpreg &= ~(ATIM_BDTR_BKP_Msk);
	tmpreg |= (SetValue & ATIM_BDTR_BKP_Msk);
	ATIM->BDTR = tmpreg;
}

uint32_t ATIM_BDTR_BKP_Get(void)
{
	return (ATIM->BDTR & ATIM_BDTR_BKP_Msk);
}

void ATIM_BDTR_BKE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->BDTR |= (ATIM_BDTR_BKE_Msk);
	}
	else
	{
		ATIM->BDTR &= ~(ATIM_BDTR_BKE_Msk);
	}
}

FunState ATIM_BDTR_BKE_Getable(void)
{
	if (ATIM->BDTR & (ATIM_BDTR_BKE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

void ATIM_BDTR_OSSR_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->BDTR;
	tmpreg &= ~(ATIM_BDTR_OSSR_Msk);
	tmpreg |= (SetValue & ATIM_BDTR_OSSR_Msk);
	ATIM->BDTR = tmpreg;
}

uint32_t ATIM_BDTR_OSSR_Get(void)
{
	return (ATIM->BDTR & ATIM_BDTR_OSSR_Msk);
}

void ATIM_BDTR_OSSI_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->BDTR;
	tmpreg &= ~(ATIM_BDTR_OSSI_Msk);
	tmpreg |= (SetValue & ATIM_BDTR_OSSI_Msk);
	ATIM->BDTR = tmpreg;
}

uint32_t ATIM_BDTR_OSSI_Get(void)
{
	return (ATIM->BDTR & ATIM_BDTR_OSSI_Msk);
}

/* �Ĵ���д�������� ��غ��� */
void ATIM_BDTR_LOCK_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->BDTR;
	tmpreg &= ~(ATIM_BDTR_LOCK_Msk);
	tmpreg |= (SetValue & ATIM_BDTR_LOCK_Msk);
	ATIM->BDTR = tmpreg;
}

uint32_t ATIM_BDTR_LOCK_Get(void)
{
	return (ATIM->BDTR & ATIM_BDTR_LOCK_Msk);
}

/* ����ʱ����룬�������û���������������ʱ�䳤�� ��غ��� */
void ATIM_BDTR_DTG_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->BDTR;
	tmpreg &= ~(ATIM_BDTR_DTG_Msk);
	tmpreg |= (SetValue & ATIM_BDTR_DTG_Msk);
	ATIM->BDTR = tmpreg;
}

uint32_t ATIM_BDTR_DTG_Get(void)
{
	return (ATIM->BDTR & ATIM_BDTR_DTG_Msk);
}

/* DMA Burst���� ��غ��� */
void ATIM_DCR_DBL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->DCR;
	tmpreg &= ~(ATIM_DCR_DBL_Msk);
	tmpreg |= (SetValue & ATIM_DCR_DBL_Msk);
	ATIM->DCR = tmpreg;
}

uint32_t ATIM_DCR_DBL_Get(void)
{
	return (ATIM->DCR & ATIM_DCR_DBL_Msk);
}

/* DMA����ַ������ָ��Ĵ�����ƫ�Ƶ�ַ ��غ��� */
void ATIM_DCR_DBA_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->DCR;
	tmpreg &= ~(ATIM_DCR_DBA_Msk);
	tmpreg |= (SetValue & ATIM_DCR_DBA_Msk);
	ATIM->DCR = tmpreg;
}

uint32_t ATIM_DCR_DBA_Get(void)
{
	return (ATIM->DCR & ATIM_DCR_DBA_Msk);
}

/* DMA burst���ʼĴ���
��ʹ��DMA burst����ʱ����DMAͨ�������ַ����ΪATIM_DMAR��ATIM�����DBL��ֵ�������DMA���� ��غ��� */
void ATIM_DMAR_Write(uint32_t SetValue)
{
	ATIM->DMAR = (SetValue);
}

uint32_t ATIM_DMAR_Read(void)
{
	return (ATIM->DMAR);
}

/* ATIM_BRK2���������ſ��ź� ��غ��� */
void ATIM_BKCR_BRK2GATE_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->BKCR;
	tmpreg &= ~(ATIM_BKCR_BRK2GATE_Msk);
	tmpreg |= (SetValue & ATIM_BKCR_BRK2GATE_Msk);
	ATIM->BKCR = tmpreg;
}

uint32_t ATIM_BKCR_BRK2GATE_Get(void)
{
	return (ATIM->BKCR & ATIM_BKCR_BRK2GATE_Msk);
}

/* ATIM_BRK1���������ſ��ź� ��غ��� */
void ATIM_BKCR_BRK1GATE_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->BKCR;
	tmpreg &= ~(ATIM_BKCR_BRK1GATE_Msk);
	tmpreg |= (SetValue & ATIM_BKCR_BRK1GATE_Msk);
	ATIM->BKCR = tmpreg;
}

uint32_t ATIM_BKCR_BRK1GATE_Get(void)
{
	return (ATIM->BKCR & ATIM_BKCR_BRK1GATE_Msk);
}

/* ɲ���źŵ��˲�ʱ�Ӻͳ���ѡ��  ��غ��� */
void ATIM_BKCR_BRKF_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->BKCR;
	tmpreg &= ~(ATIM_BKCR_BRKF_Msk);
	tmpreg |= (SetValue & ATIM_BKCR_BRKF_Msk);
	ATIM->BKCR = tmpreg;
}

uint32_t ATIM_BKCR_BRKF_Get(void)
{
	return (ATIM->BKCR & ATIM_BKCR_BRKF_Msk);
}

/* ɲ����Ͽ��� ��غ��� */
void ATIM_BKCR_BRKCOMB_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ATIM->BKCR;
	tmpreg &= ~(ATIM_BKCR_BRKCOMB_Msk);
	tmpreg |= (SetValue & ATIM_BKCR_BRKCOMB_Msk);
	ATIM->BKCR = tmpreg;
}

uint32_t ATIM_BKCR_BRKCOMB_Get(void)
{
	return (ATIM->BKCR & ATIM_BKCR_BRKCOMB_Msk);
}

/* XTHFͣ����ɲ���ź�ʹ�� ��غ��� */
void ATIM_BKCR_HFDET_BRKEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->BKCR |= (ATIM_BKCR_HFDET_BRKEN_Msk);
	}
	else
	{
		ATIM->BKCR &= ~(ATIM_BKCR_HFDET_BRKEN_Msk);
	}
}

FunState ATIM_BKCR_HFDET_BRKEN_Getable(void)
{
	if (ATIM->BKCR & (ATIM_BKCR_HFDET_BRKEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SVDɲ���ź�ʹ�� ��غ��� */
void ATIM_BKCR_SVD_BRKEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->BKCR |= (ATIM_BKCR_SVD_BRKEN_Msk);
	}
	else
	{
		ATIM->BKCR &= ~(ATIM_BKCR_SVD_BRKEN_Msk);
	}
}

FunState ATIM_BKCR_SVD_BRKEN_Getable(void)
{
	if (ATIM->BKCR & (ATIM_BKCR_SVD_BRKEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �Ƚ������ɲ���ź�ʹ�� ��غ��� */
void ATIM_BKCR_COMP_BRKEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ATIM->BKCR |= (ATIM_BKCR_COMP_BRKEN_Msk);
	}
	else
	{
		ATIM->BKCR &= ~(ATIM_BKCR_COMP_BRKEN_Msk);
	}
}

FunState ATIM_BKCR_COMP_BRKEN_Getable(void)
{
	if (ATIM->BKCR & (ATIM_BKCR_COMP_BRKEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}


void ATIM_Deinit(void)
{
	RCC_PRST_EN_Write(RSTKEY0);
  RCC_APBRST_CR2_ATRST_Setable(ENABLE);  
  RCC_APBRST_CR2_ATRST_Setable(DISABLE);
  RCC_PRST_EN_Write(RSTKEY1);
}

/******END OF FILE****/
