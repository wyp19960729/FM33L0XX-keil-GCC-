/**
  ******************************************************************************
  * @file    fm33l0xx_gptim.c
  * @author  FM33L0 Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33l0xx_gptim.h" 
#include "fm33l0xx_rcc.h"

/** @addtogroup fm33l0_StdPeriph_Driver
  * @{
  */

/** @defgroup GPTIM 
  * @brief GPTIM driver modules
  * @{
  */ 

void GPTIMx_TimeBaseInit(GPTIM_Type* GPTIMx,TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct)
{
  GPTIMx_CR1_CMS_Set(GPTIMx,GPTIMx_CR1_CMS_EDGE);//���ض���ģʽ
  GPTIMx_CR1_DIR_Set(GPTIMx,TIM_TimeBaseInitStruct->TIM_CounterMode);
  GPTIMx_CR1_CKD_Set(GPTIMx,TIM_TimeBaseInitStruct->TIM_ClockDivision);
  
  GPTIMx_ARR_Write(GPTIMx,TIM_TimeBaseInitStruct->TIM_Period);
  GPTIMx_PSC_Write(GPTIMx,TIM_TimeBaseInitStruct->TIM_Prescaler);
  
  GPTIMx_EGR_UG_Setable(GPTIMx,ENABLE);//�����¼����²���
}

void GPTIMx_ClearITPendingBit(GPTIM_Type* GPTIMx,uint32_t TIM_IT)
{
  GPTIMx->ISR = TIM_IT;
}

void GPTIMx_ITConfig(GPTIM_Type* GPTIMx,uint32_t TIM_IT, FunState NewState)
{  
  if (NewState != DISABLE)
  {
    GPTIMx->DIER |= TIM_IT;
  }
  else
  {
    GPTIMx->DIER &= ~TIM_IT;
  }
}

ITStatus GPTIMx_GetITStatus(GPTIM_Type* GPTIMx,uint32_t TIM_IT)
{ 
  uint32_t itstatus = 0x0, itenable = 0x0;
   
  itstatus = GPTIMx->ISR & TIM_IT;
  
  itenable = GPTIMx->DIER & TIM_IT;
  
  if ((itstatus != RESET) && (itenable != RESET))
  {
    return  SET;
  }
  else
  {
    return  RESET;
  }
}

void GPTIMx_Cmd(GPTIM_Type* GPTIMx,FunState NewState)
{
  
  if (NewState != DISABLE)
  {
    GPTIMx->CR1 |= GPTIMx_CR1_CEN_Msk;
  }
  else
  {
    GPTIMx->CR1 &= ~GPTIMx_CR1_CEN_Msk;
  }
}

void GPTIMx_ICInit(GPTIM_Type* GPTIMx, TIM_ICInitTypeDef* TIM_ICInitStruct)
{ 
  if (TIM_ICInitStruct->TIM_Channel == TIM_Channel_1)
  {   
    GPTIMx_CCER_CC1E_Setable(GPTIMx,DISABLE);
    GPTIMx_CCMR1_CC1S_Set(GPTIMx, TIM_ICInitStruct->TIM_ICSelection);
    GPTIMx_CCMR1_IC1F_Set(GPTIMx,TIM_ICInitStruct->TIM_ICFilter); 
    GPTIMx_CCER_CC1P_Set(GPTIMx,TIM_ICInitStruct->TIM_ICPolarity);
    GPTIMx_CCMR1_IC1PSC_Set(GPTIMx,TIM_ICInitStruct->TIM_ICPrescaler);     
    GPTIMx_CCER_CC1E_Setable(GPTIMx,ENABLE);

  }
  else if (TIM_ICInitStruct->TIM_Channel == TIM_Channel_2)
  {
    GPTIMx_CCER_CC2E_Setable(GPTIMx,DISABLE);
    GPTIMx_CCMR1_CC2S_Set(GPTIMx,TIM_ICInitStruct->TIM_ICSelection);
    GPTIMx_CCMR1_IC2F_Set(GPTIMx,TIM_ICInitStruct->TIM_ICFilter); 
    GPTIMx_CCER_CC2P_Set(GPTIMx,TIM_ICInitStruct->TIM_ICPolarity);
    GPTIMx_CCMR1_IC2PSC_Set(GPTIMx, TIM_ICInitStruct->TIM_ICPrescaler);
    GPTIMx_CCER_CC2E_Setable(GPTIMx,ENABLE);   
  }
  else if (TIM_ICInitStruct->TIM_Channel == TIM_Channel_3)
  {
    GPTIMx_CCER_CC3E_Setable(GPTIMx,DISABLE);
    GPTIMx_CCMR2_CC3S_Set(GPTIMx,TIM_ICInitStruct->TIM_ICSelection);
    GPTIMx_CCMR2_IC3F_Set(GPTIMx,TIM_ICInitStruct->TIM_ICFilter); 
    GPTIMx_CCER_CC3P_Set(GPTIMx,TIM_ICInitStruct->TIM_ICPolarity);
    GPTIMx_CCMR2_IC3PSC_Set(GPTIMx, TIM_ICInitStruct->TIM_ICPrescaler); 
    GPTIMx_CCER_CC3E_Setable(GPTIMx,ENABLE);
    
  }
  else
  {
    GPTIMx_CCER_CC4E_Setable(GPTIMx,DISABLE);
    GPTIMx_CCMR2_CC4S_Set(GPTIMx,TIM_ICInitStruct->TIM_ICSelection);
    GPTIMx_CCMR2_IC4F_Set(GPTIMx,TIM_ICInitStruct->TIM_ICFilter);   
    GPTIMx_CCER_CC4P_Set(GPTIMx,TIM_ICInitStruct->TIM_ICPolarity);
    GPTIMx_CCMR2_IC4PSC_Set(GPTIMx, TIM_ICInitStruct->TIM_ICPrescaler); 
    GPTIMx_CCER_CC4E_Setable(GPTIMx,ENABLE);  
  }
}

/* Dead time�������˲�ʱ��Ƶ�ʷ�Ƶ�Ĵ��������CK_INT�ķ�Ƶ�ȣ�(Counter clocK Divider) ��غ��� */
void GPTIMx_CR1_CKD_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->CR1;
	tmpreg &= ~(GPTIMx_CR1_CKD_Msk);
	tmpreg |= (SetValue & GPTIMx_CR1_CKD_Msk);
	GPTIMx->CR1 = tmpreg;
}

uint32_t GPTIMx_CR1_CKD_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CR1 & GPTIMx_CR1_CKD_Msk);
}

/* Auto-reloadԤװ��ʹ�� (Auto-Reload Preload Enable) ��غ��� */
void GPTIMx_CR1_ARPE_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->CR1 |= (GPTIMx_CR1_ARPE_Msk);
	}
	else
	{
		GPTIMx->CR1 &= ~(GPTIMx_CR1_ARPE_Msk);
	}
}

FunState GPTIMx_CR1_ARPE_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->CR1 & (GPTIMx_CR1_ARPE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����������ģʽѡ�� (Counter Mode Selection) ��غ��� */
void GPTIMx_CR1_CMS_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->CR1;
	tmpreg &= ~(GPTIMx_CR1_CMS_Msk);
	tmpreg |= (SetValue & GPTIMx_CR1_CMS_Msk);
	GPTIMx->CR1 = tmpreg;
}

uint32_t GPTIMx_CR1_CMS_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CR1 & GPTIMx_CR1_CMS_Msk);
}

/* ��������Ĵ��� (counter Direction) ��غ��� */
void GPTIMx_CR1_DIR_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->CR1;
	tmpreg &= ~(GPTIMx_CR1_DIR_Msk);
	tmpreg |= (SetValue & GPTIMx_CR1_DIR_Msk);
	GPTIMx->CR1 = tmpreg;
}

uint32_t GPTIMx_CR1_DIR_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CR1 & GPTIMx_CR1_DIR_Msk);
}

/* ���������ģʽ (One Pulse Mode) ��غ��� */
void  GPTIMx_CR1_OPM_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->CR1 |= (GPTIMx_CR1_OPM_Msk);
	}
	else
	{
		GPTIMx->CR1 &= ~(GPTIMx_CR1_OPM_Msk);
	}
}

FunState  GPTIMx_CR1_OPM_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->CR1 & (GPTIMx_CR1_OPM_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}
/* ��������ѡ�� (Update Request Selection) ��غ��� */
void  GPTIMx_CR1_URS_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->CR1 |= (GPTIMx_CR1_URS_Msk);
	}
	else
	{
		GPTIMx->CR1 &= ~(GPTIMx_CR1_URS_Msk);
	}
}

FunState  GPTIMx_CR1_URS_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->CR1 & (GPTIMx_CR1_URS_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}
/* ��ֹupdate (Update Disable) ��غ��� */
void GPTIMx_CR1_UDIS_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->CR1 |= (GPTIMx_CR1_UDIS_Msk);
	}
	else
	{
		GPTIMx->CR1 &= ~(GPTIMx_CR1_UDIS_Msk);
	}
}

FunState GPTIMx_CR1_UDIS_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->CR1 & (GPTIMx_CR1_UDIS_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ������ʹ�� (Counter Enable) ��غ��� */
void GPTIMx_CR1_CEN_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->CR1 |= (GPTIMx_CR1_CEN_Msk);
	}
	else
	{
		GPTIMx->CR1 &= ~(GPTIMx_CR1_CEN_Msk);
	}
}

FunState GPTIMx_CR1_CEN_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->CR1 & (GPTIMx_CR1_CEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ͨ��1����Դѡ�� (Timer Input 1 Selection) ��غ��� */
void GPTIMx_CR2_TI1S_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->CR2;
	tmpreg &= ~(GPTIMx_CR2_TI1S_Msk);
	tmpreg |= (SetValue & GPTIMx_CR2_TI1S_Msk);
	GPTIMx->CR2 = tmpreg;
}

uint32_t GPTIMx_CR2_TI1S_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CR2 & GPTIMx_CR2_TI1S_Msk);
}

/* ����ģʽѡ��������������ģʽ����ӻ����͵�ͬ�������źţ�TRGO��Դ (Master Mode Selection) ��غ��� */
void GPTIMx_CR2_MMS_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->CR2;
	tmpreg &= ~(GPTIMx_CR2_MMS_Msk);
	tmpreg |= (SetValue & GPTIMx_CR2_MMS_Msk);
	GPTIMx->CR2 = tmpreg;
}

uint32_t GPTIMx_CR2_MMS_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CR2 & GPTIMx_CR2_MMS_Msk);
}

/* ��׽/�Ƚ� DMAѡ�� (Capture/Compare DMA Selection) ��غ��� */
void GPTIMx_CR2_CCDS_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->CR2;
	tmpreg &= ~(GPTIMx_CR2_CCDS_Msk);
	tmpreg |= (SetValue & GPTIMx_CR2_CCDS_Msk);
	GPTIMx->CR2 = tmpreg;
}

uint32_t GPTIMx_CR2_CCDS_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CR2 & GPTIMx_CR2_CCDS_Msk);
}

/* �ⲿ�����źż������� (External Trigger Polarity) ��غ��� */
void GPTIMx_SMCR_ETP_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->SMCR;
	tmpreg &= ~(GPTIMx_SMCR_ETP_Msk);
	tmpreg |= (SetValue & GPTIMx_SMCR_ETP_Msk);
	GPTIMx->SMCR = tmpreg;
}

uint32_t GPTIMx_SMCR_ETP_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->SMCR & GPTIMx_SMCR_ETP_Msk);
}

/* �ⲿʱ��ʹ�� (External Clock Enable) ��غ��� */
void GPTIMx_SMCR_ECE_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->SMCR |= (GPTIMx_SMCR_ECE_Msk);
	}
	else
	{
		GPTIMx->SMCR &= ~(GPTIMx_SMCR_ECE_Msk);
	}
}

FunState GPTIMx_SMCR_ECE_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->SMCR & (GPTIMx_SMCR_ECE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �ⲿ�����ź�Ԥ��Ƶ�Ĵ��� (External Trigger Prescaler)
�ⲿ�����ź�ETRP��Ƶ�����ֻ����GPTIM����ʱ�ӵ�1/4���������ź�Ƶ�ʽϸ�ʱ������ʹ��Ԥ��Ƶ ��غ��� */
void GPTIMx_SMCR_ETPS_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->SMCR;
	tmpreg &= ~(GPTIMx_SMCR_ETPS_Msk);
	tmpreg |= (SetValue & GPTIMx_SMCR_ETPS_Msk);
	GPTIMx->SMCR = tmpreg;
}

uint32_t GPTIMx_SMCR_ETPS_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->SMCR & GPTIMx_SMCR_ETPS_Msk);
}

/* �ⲿ�����ź��˲�ʱ�Ӻͳ���ѡ�� (External Trigger Filter) ��غ��� */
void GPTIMx_SMCR_ETF_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->SMCR;
	tmpreg &= ~(GPTIMx_SMCR_ETF_Msk);
	tmpreg |= (SetValue & GPTIMx_SMCR_ETF_Msk);
	GPTIMx->SMCR = tmpreg;
}

uint32_t GPTIMx_SMCR_ETF_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->SMCR & GPTIMx_SMCR_ETF_Msk);
}

/* ��/��ģʽ (Master Slave Mode) ��غ��� */
void GPTIMx_SMCR_MSM_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->SMCR;
	tmpreg &= ~(GPTIMx_SMCR_MSM_Msk);
	tmpreg |= (SetValue & GPTIMx_SMCR_MSM_Msk);
	GPTIMx->SMCR = tmpreg;
}

uint32_t GPTIMx_SMCR_MSM_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->SMCR & GPTIMx_SMCR_MSM_Msk);
}

/* ����ѡ������ѡ��ͬ���������Ĵ���Դ (Trigger Source) ��غ��� */
void GPTIMx_SMCR_TS_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->SMCR;
	tmpreg &= ~(GPTIMx_SMCR_TS_Msk);
	tmpreg |= (SetValue & GPTIMx_SMCR_TS_Msk);
	GPTIMx->SMCR = tmpreg;
}

uint32_t GPTIMx_SMCR_TS_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->SMCR & GPTIMx_SMCR_TS_Msk);
}

/* �ӻ�ģʽѡ�� (Slave Mode Selection) ��غ��� */
void GPTIMx_SMCR_SMS_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->SMCR;
	tmpreg &= ~(GPTIMx_SMCR_SMS_Msk);
	tmpreg |= (SetValue & GPTIMx_SMCR_SMS_Msk);
	GPTIMx->SMCR = tmpreg;
}

uint32_t GPTIMx_SMCR_SMS_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->SMCR & GPTIMx_SMCR_SMS_Msk);
}

/* ��׽�Ƚ�ͨ��4��DMAģʽ���� (CC4 Burst Enable) ��غ��� */
void GPTIMx_DIER_CC4BURSTEN_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->DIER;
	tmpreg &= ~(GPTIMx_DIER_CC4BURSTEN_Msk);
	tmpreg |= (SetValue & GPTIMx_DIER_CC4BURSTEN_Msk);
	GPTIMx->DIER = tmpreg;
}

uint32_t GPTIMx_DIER_CC4BURSTEN_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->DIER & GPTIMx_DIER_CC4BURSTEN_Msk);
}

/* ��׽�Ƚ�ͨ��3��DMAģʽ���� (CC3 Burst Enable) ��غ��� */
void GPTIMx_DIER_CC3BURSTEN_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->DIER;
	tmpreg &= ~(GPTIMx_DIER_CC3BURSTEN_Msk);
	tmpreg |= (SetValue & GPTIMx_DIER_CC3BURSTEN_Msk);
	GPTIMx->DIER = tmpreg;
}

uint32_t GPTIMx_DIER_CC3BURSTEN_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->DIER & GPTIMx_DIER_CC3BURSTEN_Msk);
}

/* ��׽�Ƚ�ͨ��2��DMAģʽ���� (CC2 Burst Enable) ��غ��� */
void GPTIMx_DIER_CC2BURSTEN_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->DIER;
	tmpreg &= ~(GPTIMx_DIER_CC2BURSTEN_Msk);
	tmpreg |= (SetValue & GPTIMx_DIER_CC2BURSTEN_Msk);
	GPTIMx->DIER = tmpreg;
}

uint32_t GPTIMx_DIER_CC2BURSTEN_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->DIER & GPTIMx_DIER_CC2BURSTEN_Msk);
}

/* ��׽�Ƚ�ͨ��1��DMAģʽ���� (CC1 Burst Enable) ��غ��� */
void GPTIMx_DIER_CC1BURSTEN_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->DIER;
	tmpreg &= ~(GPTIMx_DIER_CC1BURSTEN_Msk);
	tmpreg |= (SetValue & GPTIMx_DIER_CC1BURSTEN_Msk);
	GPTIMx->DIER = tmpreg;
}

uint32_t GPTIMx_DIER_CC1BURSTEN_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->DIER & GPTIMx_DIER_CC1BURSTEN_Msk);
}

/* �ⲿ����DMA����ʹ�� (Triggered DMA Enable) ��غ��� */
void GPTIMx_DIER_TDE_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->DIER |= (GPTIMx_DIER_TDE_Msk);
	}
	else
	{
		GPTIMx->DIER &= ~(GPTIMx_DIER_TDE_Msk);
	}
}

FunState GPTIMx_DIER_TDE_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->DIER & (GPTIMx_DIER_TDE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽�Ƚ�ͨ��4��DMA����ʹ�� (CC4 DMA Enable) ��غ��� */
void GPTIMx_DIER_CC4DE_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->DIER |= (GPTIMx_DIER_CC4DE_Msk);
	}
	else
	{
		GPTIMx->DIER &= ~(GPTIMx_DIER_CC4DE_Msk);
	}
}

FunState GPTIMx_DIER_CC4DE_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->DIER & (GPTIMx_DIER_CC4DE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽�Ƚ�ͨ��3��DMA����ʹ�� (CC3 DMA Enable) ��غ��� */
void GPTIMx_DIER_CC3DE_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->DIER |= (GPTIMx_DIER_CC3DE_Msk);
	}
	else
	{
		GPTIMx->DIER &= ~(GPTIMx_DIER_CC3DE_Msk);
	}
}

FunState GPTIMx_DIER_CC3DE_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->DIER & (GPTIMx_DIER_CC3DE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽�Ƚ�ͨ��2��DMA����ʹ�� (CC2 DMA Enable) ��غ��� */
void GPTIMx_DIER_CC2DE_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->DIER |= (GPTIMx_DIER_CC2DE_Msk);
	}
	else
	{
		GPTIMx->DIER &= ~(GPTIMx_DIER_CC2DE_Msk);
	}
}

FunState GPTIMx_DIER_CC2DE_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->DIER & (GPTIMx_DIER_CC2DE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽�Ƚ�ͨ��1��DMA����ʹ�� (CC1 DMA Enable) ��غ��� */
void GPTIMx_DIER_CC1DE_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->DIER |= (GPTIMx_DIER_CC1DE_Msk);
	}
	else
	{
		GPTIMx->DIER &= ~(GPTIMx_DIER_CC1DE_Msk);
	}
}

FunState GPTIMx_DIER_CC1DE_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->DIER & (GPTIMx_DIER_CC1DE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Update Event DMA����ʹ�� (Update event DMA Enable) ��غ��� */
void GPTIMx_DIER_UDE_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->DIER |= (GPTIMx_DIER_UDE_Msk);
	}
	else
	{
		GPTIMx->DIER &= ~(GPTIMx_DIER_UDE_Msk);
	}
}

FunState GPTIMx_DIER_UDE_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->DIER & (GPTIMx_DIER_UDE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �����¼��ж�ʹ�� (Trigger event Interrupt Enable) ��غ��� */
void GPTIMx_DIER_TIE_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->DIER |= (GPTIMx_DIER_TIE_Msk);
	}
	else
	{
		GPTIMx->DIER &= ~(GPTIMx_DIER_TIE_Msk);
	}
}

FunState GPTIMx_DIER_TIE_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->DIER & (GPTIMx_DIER_TIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�ͨ��4�ж�ʹ�� (CC4 Interrupt Enable) ��غ��� */
void GPTIMx_DIER_CC4IE_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->DIER |= (GPTIMx_DIER_CC4IE_Msk);
	}
	else
	{
		GPTIMx->DIER &= ~(GPTIMx_DIER_CC4IE_Msk);
	}
}

FunState GPTIMx_DIER_CC4IE_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->DIER & (GPTIMx_DIER_CC4IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�ͨ��3�ж�ʹ�� (CC3 Interrupt Enable) ��غ��� */
void GPTIMx_DIER_CC3IE_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->DIER |= (GPTIMx_DIER_CC3IE_Msk);
	}
	else
	{
		GPTIMx->DIER &= ~(GPTIMx_DIER_CC3IE_Msk);
	}
}

FunState GPTIMx_DIER_CC3IE_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->DIER & (GPTIMx_DIER_CC3IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�ͨ��2�ж�ʹ�� (CC2 Interrupt Enable) ��غ��� */
void GPTIMx_DIER_CC2IE_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->DIER |= (GPTIMx_DIER_CC2IE_Msk);
	}
	else
	{
		GPTIMx->DIER &= ~(GPTIMx_DIER_CC2IE_Msk);
	}
}

FunState GPTIMx_DIER_CC2IE_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->DIER & (GPTIMx_DIER_CC2IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�ͨ��1�ж�ʹ�� (CC1 Interrupt Enable) ��غ��� */
void GPTIMx_DIER_CC1IE_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->DIER |= (GPTIMx_DIER_CC1IE_Msk);
	}
	else
	{
		GPTIMx->DIER &= ~(GPTIMx_DIER_CC1IE_Msk);
	}
}

FunState GPTIMx_DIER_CC1IE_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->DIER & (GPTIMx_DIER_CC1IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Update�¼��ж�ʹ�� (Update event Interrupt Enable) ��غ��� */
void GPTIMx_DIER_UIE_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->DIER |= (GPTIMx_DIER_UIE_Msk);
	}
	else
	{
		GPTIMx->DIER &= ~(GPTIMx_DIER_UIE_Msk);
	}
}

FunState GPTIMx_DIER_UIE_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->DIER & (GPTIMx_DIER_UIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�ͨ��4��Overcapture�ж� (Over-Capture Interrupt Flag for CC4) ��غ��� */
void GPTIMx_ISR_CC4OF_Clr(GPTIM_Type* GPTIMx)
{
	GPTIMx->ISR = GPTIMx_ISR_CC4OF_Msk;
}

FlagStatus GPTIMx_ISR_CC4OF_Chk(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->ISR & GPTIMx_ISR_CC4OF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��׽/�Ƚ�ͨ��3��Overcapture�ж� (Over-Capture Interrupt Flag for CC3) ��غ��� */
void GPTIMx_ISR_CC3OF_Clr(GPTIM_Type* GPTIMx)
{
	GPTIMx->ISR = GPTIMx_ISR_CC3OF_Msk;
}

FlagStatus GPTIMx_ISR_CC3OF_Chk(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->ISR & GPTIMx_ISR_CC3OF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��׽/�Ƚ�ͨ��2��Overcapture�ж� (Over-Capture Interrupt Flag for CC2) ��غ��� */
void GPTIMx_ISR_CC2OF_Clr(GPTIM_Type* GPTIMx)
{
	GPTIMx->ISR = GPTIMx_ISR_CC2OF_Msk;
}

FlagStatus GPTIMx_ISR_CC2OF_Chk(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->ISR & GPTIMx_ISR_CC2OF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��׽/�Ƚ�ͨ��1��Overcapture�ж� (Over-Capture Interrupt Flag for CC1) ��غ��� */
void GPTIMx_ISR_CC1OF_Clr(GPTIM_Type* GPTIMx)
{
	GPTIMx->ISR = GPTIMx_ISR_CC1OF_Msk;
}

FlagStatus GPTIMx_ISR_CC1OF_Chk(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->ISR & GPTIMx_ISR_CC1OF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �����¼��жϱ�־ ��غ��� */
void GPTIMx_ISR_TIF_Clr(GPTIM_Type* GPTIMx)
{
	GPTIMx->ISR = GPTIMx_ISR_TIF_Msk;
}

FlagStatus GPTIMx_ISR_TIF_Chk(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->ISR & GPTIMx_ISR_TIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��׽/�Ƚ�ͨ��4�жϱ�־ (CC4 Interrupt Flag) ��غ��� */
void GPTIMx_ISR_CC4IF_Clr(GPTIM_Type* GPTIMx)
{
	GPTIMx->ISR = GPTIMx_ISR_CC4IF_Msk;
}

FlagStatus GPTIMx_ISR_CC4IF_Chk(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->ISR & GPTIMx_ISR_CC4IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��׽/�Ƚ�ͨ��3�жϱ�־ (CC3 Interrupt Flag) ��غ��� */
void GPTIMx_ISR_CC3IF_Clr(GPTIM_Type* GPTIMx)
{
	GPTIMx->ISR = GPTIMx_ISR_CC3IF_Msk;
}

FlagStatus GPTIMx_ISR_CC3IF_Chk(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->ISR & GPTIMx_ISR_CC3IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��׽/�Ƚ�ͨ��2�жϱ�־ (CC2 Interrupt Flag) ��غ��� */
void GPTIMx_ISR_CC2IF_Clr(GPTIM_Type* GPTIMx)
{
	GPTIMx->ISR = GPTIMx_ISR_CC2IF_Msk;
}

FlagStatus GPTIMx_ISR_CC2IF_Chk(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->ISR & GPTIMx_ISR_CC2IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��׽/�Ƚ�ͨ��1�жϱ�־ (CC1 Interrupt Flag) ��غ��� */
void GPTIMx_ISR_CC1IF_Clr(GPTIM_Type* GPTIMx)
{
	GPTIMx->ISR = GPTIMx_ISR_CC1IF_Msk;
}

FlagStatus GPTIMx_ISR_CC1IF_Chk(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->ISR & GPTIMx_ISR_CC1IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* Update�¼��жϱ�־��Ӳ����λ�����д1���㡣(Update event Interrupt Flag) ��غ��� */
void GPTIMx_ISR_UIF_Clr(GPTIM_Type* GPTIMx)
{
	GPTIMx->ISR = GPTIMx_ISR_UIF_Msk;
}

FlagStatus GPTIMx_ISR_UIF_Chk(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->ISR & GPTIMx_ISR_UIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��������������λ�˼Ĵ������������¼���Ӳ���Զ����� (Trigger Generate) ��غ��� */
void GPTIMx_EGR_TG_Setable(GPTIM_Type* GPTIMx,FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->EGR |= (GPTIMx_EGR_TG_Msk);
	}
	else
	{
		GPTIMx->EGR &= ~(GPTIMx_EGR_TG_Msk);
	}
}

/* ��׽/�Ƚ�ͨ��4������� (CC4 Generate) ��غ��� */
void GPTIMx_EGR_CC4G_Setable(GPTIM_Type* GPTIMx,FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->EGR |= (GPTIMx_EGR_CC4G_Msk);
	}
	else
	{
		GPTIMx->EGR &= ~(GPTIMx_EGR_CC4G_Msk);
	}
}
/* ��׽/�Ƚ�ͨ��3������� (CC3 Generate) ��غ��� */
void GPTIMx_EGR_CC3G_Setable(GPTIM_Type* GPTIMx,FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->EGR |= (GPTIMx_EGR_CC3G_Msk);
	}
	else
	{
		GPTIMx->EGR &= ~(GPTIMx_EGR_CC3G_Msk);
	}
}
/* ��׽/�Ƚ�ͨ��2������� (CC2 Generate) ��غ��� */
void GPTIMx_EGR_CC2G_Setable(GPTIM_Type* GPTIMx,FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->EGR |= (GPTIMx_EGR_CC2G_Msk);
	}
	else
	{
		GPTIMx->EGR &= ~(GPTIMx_EGR_CC2G_Msk);
	}
}
/* ��׽/�Ƚ�ͨ��1������� (CC1 Generate) ��غ��� */
void GPTIMx_EGR_CC1G_Setable(GPTIM_Type* GPTIMx,FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->EGR |= (GPTIMx_EGR_CC1G_Msk);
	}
	else
	{
		GPTIMx->EGR &= ~(GPTIMx_EGR_CC1G_Msk);
	}
}
/* ���Update�¼��������λ�˼Ĵ�������Update�¼���Ӳ���Զ����� (User Generate) ��غ��� */
void GPTIMx_EGR_UG_Setable(GPTIM_Type* GPTIMx,FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->EGR |= (GPTIMx_EGR_UG_Msk);
	}
	else
	{
		GPTIMx->EGR &= ~(GPTIMx_EGR_UG_Msk);
	}
}

/* ����Ƚ�2����ʹ�� (OC2 Clear Enable) ��غ��� */
void GPTIMx_CCMR1_OC2CE_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->CCMR1 |= (GPTIMx_CCMR1_OC2CE_Msk);
	}
	else
	{
		GPTIMx->CCMR1 &= ~(GPTIMx_CCMR1_OC2CE_Msk);
	}
}

FunState GPTIMx_CCMR1_OC2CE_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->CCMR1 & (GPTIMx_CCMR1_OC2CE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����Ƚ�2ģʽ���ã��˼Ĵ�������OC2REF�źŵ���Ϊ (OC2 Mode) ��غ��� */
void GPTIMx_CCMR1_OC2M_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->CCMR1;
	tmpreg &= ~(GPTIMx_CCMR1_OC2M_Msk);
	tmpreg |= (SetValue & GPTIMx_CCMR1_OC2M_Msk);
	GPTIMx->CCMR1 = tmpreg;
}

uint32_t GPTIMx_CCMR1_OC2M_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CCMR1 & GPTIMx_CCMR1_OC2M_Msk);
}

/* ����Ƚ�2Ԥװ��ʹ�� (OC2 Preload Enable) ��غ��� */
void GPTIMx_CCMR1_OC2PE_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->CCMR1 |= (GPTIMx_CCMR1_OC2PE_Msk);
	}
	else
	{
		GPTIMx->CCMR1 &= ~(GPTIMx_CCMR1_OC2PE_Msk);
	}
}

FunState GPTIMx_CCMR1_OC2PE_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->CCMR1 & (GPTIMx_CCMR1_OC2PE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����Ƚ�2����ʹ�� (OC2 Fast Enable) ��غ��� */
void GPTIMx_CCMR1_OC2FE_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->CCMR1 |= (GPTIMx_CCMR1_OC2FE_Msk);
	}
	else
	{
		GPTIMx->CCMR1 &= ~(GPTIMx_CCMR1_OC2FE_Msk);
	}
}

FunState GPTIMx_CCMR1_OC2FE_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->CCMR1 & (GPTIMx_CCMR1_OC2FE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�2ͨ��ѡ�� (CC2 channel Selection) ��غ��� */
void GPTIMx_CCMR1_CC2S_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->CCMR1;
	tmpreg &= ~(GPTIMx_CCMR1_CC2S_Msk);
	tmpreg |= (SetValue & GPTIMx_CCMR1_CC2S_Msk);
	GPTIMx->CCMR1 = tmpreg;
}

uint32_t GPTIMx_CCMR1_CC2S_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CCMR1 & GPTIMx_CCMR1_CC2S_Msk);
}

/* ����Ƚ�1����ʹ�� (OC2 Clear Enable) ��غ��� */
void GPTIMx_CCMR1_OC1CE_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->CCMR1 |= (GPTIMx_CCMR1_OC1CE_Msk);
	}
	else
	{
		GPTIMx->CCMR1 &= ~(GPTIMx_CCMR1_OC1CE_Msk);
	}
}

FunState GPTIMx_CCMR1_OC1CE_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->CCMR1 & (GPTIMx_CCMR1_OC1CE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����Ƚ�1ģʽ���ã��˼Ĵ�������OC1REF�źŵ���Ϊ (OC1 Mode) ��غ��� */
void GPTIMx_CCMR1_OC1M_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->CCMR1;
	tmpreg &= ~(GPTIMx_CCMR1_OC1M_Msk);
	tmpreg |= (SetValue & GPTIMx_CCMR1_OC1M_Msk);
	GPTIMx->CCMR1 = tmpreg;
}

uint32_t GPTIMx_CCMR1_OC1M_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CCMR1 & GPTIMx_CCMR1_OC1M_Msk);
}

/* ����Ƚ�1Ԥװ��ʹ�� (OC1 Preload Enable) ��غ��� */
void GPTIMx_CCMR1_OC1PE_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->CCMR1 |= (GPTIMx_CCMR1_OC1PE_Msk);
	}
	else
	{
		GPTIMx->CCMR1 &= ~(GPTIMx_CCMR1_OC1PE_Msk);
	}
}

FunState GPTIMx_CCMR1_OC1PE_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->CCMR1 & (GPTIMx_CCMR1_OC1PE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����Ƚ�1����ʹ�� (OC1 Fast Enable) ��غ��� */
void GPTIMx_CCMR1_OC1FE_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->CCMR1 |= (GPTIMx_CCMR1_OC1FE_Msk);
	}
	else
	{
		GPTIMx->CCMR1 &= ~(GPTIMx_CCMR1_OC1FE_Msk);
	}
}

FunState GPTIMx_CCMR1_OC1FE_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->CCMR1 & (GPTIMx_CCMR1_OC1FE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�1ͨ��ѡ�� (CC1 channel Selection) ��غ��� */
void GPTIMx_CCMR1_CC1S_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->CCMR1;
	tmpreg &= ~(GPTIMx_CCMR1_CC1S_Msk);
	tmpreg |= (SetValue & GPTIMx_CCMR1_CC1S_Msk);
	GPTIMx->CCMR1 = tmpreg;
}

uint32_t GPTIMx_CCMR1_CC1S_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CCMR1 & GPTIMx_CCMR1_CC1S_Msk);
}

/* ���벶׽2�˲� (IC2 Filter) ��غ��� */
void GPTIMx_CCMR1_IC2F_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->CCMR1;
	tmpreg &= ~(GPTIMx_CCMR1_IC2F_Msk);
	tmpreg |= (SetValue & GPTIMx_CCMR1_IC2F_Msk);
	GPTIMx->CCMR1 = tmpreg;
}

uint32_t GPTIMx_CCMR1_IC2F_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CCMR1 & GPTIMx_CCMR1_IC2F_Msk);
}

/* ���벶׽2Ԥ��Ƶ (IC2 Prescaler) ��غ��� */
void GPTIMx_CCMR1_IC2PSC_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->CCMR1;
	tmpreg &= ~(GPTIMx_CCMR1_IC2PSC_Msk);
	tmpreg |= (SetValue & GPTIMx_CCMR1_IC2PSC_Msk);
	GPTIMx->CCMR1 = tmpreg;
}

uint32_t GPTIMx_CCMR1_IC2PSC_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CCMR1 & GPTIMx_CCMR1_IC2PSC_Msk);
}

/* ���벶׽1�˲� (IC1 Filter) ��غ��� */
void GPTIMx_CCMR1_IC1F_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->CCMR1;
	tmpreg &= ~(GPTIMx_CCMR1_IC1F_Msk);
	tmpreg |= (SetValue & GPTIMx_CCMR1_IC1F_Msk);
	GPTIMx->CCMR1 = tmpreg;
}

uint32_t GPTIMx_CCMR1_IC1F_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CCMR1 & GPTIMx_CCMR1_IC1F_Msk);
}

/* ���벶׽1Ԥ��Ƶ (IC1 Prescaler) ��غ��� */
void GPTIMx_CCMR1_IC1PSC_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->CCMR1;
	tmpreg &= ~(GPTIMx_CCMR1_IC1PSC_Msk);
	tmpreg |= (SetValue & GPTIMx_CCMR1_IC1PSC_Msk);
	GPTIMx->CCMR1 = tmpreg;
}

uint32_t GPTIMx_CCMR1_IC1PSC_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CCMR1 & GPTIMx_CCMR1_IC1PSC_Msk);
}

/* ����Ƚ�4����ʹ�� (OC4 Clear Enable) ��غ��� */
void GPTIMx_CCMR2_OC4CE_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->CCMR2 |= (GPTIMx_CCMR2_OC4CE_Msk);
	}
	else
	{
		GPTIMx->CCMR2 &= ~(GPTIMx_CCMR2_OC4CE_Msk);
	}
}

FunState GPTIMx_CCMR2_OC4CE_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->CCMR2 & (GPTIMx_CCMR2_OC4CE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����Ƚ�4ģʽ���ã��˼Ĵ�������OC4REF�źŵ���Ϊ (OC4 Mode) ��غ��� */
void GPTIMx_CCMR2_OC4M_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->CCMR2;
	tmpreg &= ~(GPTIMx_CCMR2_OC4M_Msk);
	tmpreg |= (SetValue & GPTIMx_CCMR2_OC4M_Msk);
	GPTIMx->CCMR2 = tmpreg;
}

uint32_t GPTIMx_CCMR2_OC4M_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CCMR2 & GPTIMx_CCMR2_OC4M_Msk);
}

/* ����Ƚ�4Ԥװ��ʹ�� (OC4 Preload Enable) ��غ��� */
void GPTIMx_CCMR2_OC4PE_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->CCMR2 |= (GPTIMx_CCMR2_OC4PE_Msk);
	}
	else
	{
		GPTIMx->CCMR2 &= ~(GPTIMx_CCMR2_OC4PE_Msk);
	}
}

FunState GPTIMx_CCMR2_OC4PE_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->CCMR2 & (GPTIMx_CCMR2_OC4PE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����Ƚ�4����ʹ�� (OC4 Fast Enable) ��غ��� */
void GPTIMx_CCMR2_OC4FE_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->CCMR2 |= (GPTIMx_CCMR2_OC4FE_Msk);
	}
	else
	{
		GPTIMx->CCMR2 &= ~(GPTIMx_CCMR2_OC4FE_Msk);
	}
}

FunState GPTIMx_CCMR2_OC4FE_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->CCMR2 & (GPTIMx_CCMR2_OC4FE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�4ͨ��ѡ�� (CC4 channel Selection) ��غ��� */
void GPTIMx_CCMR2_CC4S_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->CCMR2;
	tmpreg &= ~(GPTIMx_CCMR2_CC4S_Msk);
	tmpreg |= (SetValue & GPTIMx_CCMR2_CC4S_Msk);
	GPTIMx->CCMR2 = tmpreg;
}

uint32_t GPTIMx_CCMR2_CC4S_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CCMR2 & GPTIMx_CCMR2_CC4S_Msk);
}

/* ����Ƚ�3����ʹ�� (OC3 Clear Enable) ��غ��� */
void GPTIMx_CCMR2_OC3CE_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->CCMR2 |= (GPTIMx_CCMR2_OC3CE_Msk);
	}
	else
	{
		GPTIMx->CCMR2 &= ~(GPTIMx_CCMR2_OC3CE_Msk);
	}
}

FunState GPTIMx_CCMR2_OC3CE_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->CCMR2 & (GPTIMx_CCMR2_OC3CE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����Ƚ�3ģʽ���ã��˼Ĵ�������OC3REF�źŵ���Ϊ (OC3 Mode) ��غ��� */
void GPTIMx_CCMR2_OC3M_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->CCMR2;
	tmpreg &= ~(GPTIMx_CCMR2_OC3M_Msk);
	tmpreg |= (SetValue & GPTIMx_CCMR2_OC3M_Msk);
	GPTIMx->CCMR2 = tmpreg;
}

uint32_t GPTIMx_CCMR2_OC3M_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CCMR2 & GPTIMx_CCMR2_OC3M_Msk);
}

/* ����Ƚ�3Ԥװ��ʹ�� (OC3 Preload Enable) ��غ��� */
void GPTIMx_CCMR2_OC3PE_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->CCMR2 |= (GPTIMx_CCMR2_OC3PE_Msk);
	}
	else
	{
		GPTIMx->CCMR2 &= ~(GPTIMx_CCMR2_OC3PE_Msk);
	}
}

FunState GPTIMx_CCMR2_OC3PE_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->CCMR2 & (GPTIMx_CCMR2_OC3PE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����Ƚ�3����ʹ�� (OC3 Fast Enable) ��غ��� */
void GPTIMx_CCMR2_OC3FE_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->CCMR2 |= (GPTIMx_CCMR2_OC3FE_Msk);
	}
	else
	{
		GPTIMx->CCMR2 &= ~(GPTIMx_CCMR2_OC3FE_Msk);
	}
}

FunState GPTIMx_CCMR2_OC3FE_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->CCMR2 & (GPTIMx_CCMR2_OC3FE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�3ͨ��ѡ�� (CC3 channel Selection) ��غ��� */
void GPTIMx_CCMR2_CC3S_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->CCMR2;
	tmpreg &= ~(GPTIMx_CCMR2_CC3S_Msk);
	tmpreg |= (SetValue & GPTIMx_CCMR2_CC3S_Msk);
	GPTIMx->CCMR2 = tmpreg;
}

uint32_t GPTIMx_CCMR2_CC3S_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CCMR2 & GPTIMx_CCMR2_CC3S_Msk);
}

/* ���벶׽4�˲� (IC4 Filter) ��غ��� */
void GPTIMx_CCMR2_IC4F_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->CCMR2;
	tmpreg &= ~(GPTIMx_CCMR2_IC4F_Msk);
	tmpreg |= (SetValue & GPTIMx_CCMR2_IC4F_Msk);
	GPTIMx->CCMR2 = tmpreg;
}

uint32_t GPTIMx_CCMR2_IC4F_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CCMR2 & GPTIMx_CCMR2_IC4F_Msk);
}

/* ���벶׽4Ԥ��Ƶ (IC4 Prescaler) ��غ��� */
void GPTIMx_CCMR2_IC4PSC_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->CCMR2;
	tmpreg &= ~(GPTIMx_CCMR2_IC4PSC_Msk);
	tmpreg |= (SetValue & GPTIMx_CCMR2_IC4PSC_Msk);
	GPTIMx->CCMR2 = tmpreg;
}

uint32_t GPTIMx_CCMR2_IC4PSC_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CCMR2 & GPTIMx_CCMR2_IC4PSC_Msk);
}

/* ���벶׽3�˲� (IC3 Filter) ��غ��� */
void GPTIMx_CCMR2_IC3F_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->CCMR2;
	tmpreg &= ~(GPTIMx_CCMR2_IC3F_Msk);
	tmpreg |= (SetValue & GPTIMx_CCMR2_IC3F_Msk);
	GPTIMx->CCMR2 = tmpreg;
}

uint32_t GPTIMx_CCMR2_IC3F_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CCMR2 & GPTIMx_CCMR2_IC3F_Msk);
}

/* ���벶׽3Ԥ��Ƶ (IC3 Prescaler) ��غ��� */
void GPTIMx_CCMR2_IC3PSC_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->CCMR2;
	tmpreg &= ~(GPTIMx_CCMR2_IC3PSC_Msk);
	tmpreg |= (SetValue & GPTIMx_CCMR2_IC3PSC_Msk);
	GPTIMx->CCMR2 = tmpreg;
}

uint32_t GPTIMx_CCMR2_IC3PSC_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CCMR2 & GPTIMx_CCMR2_IC3PSC_Msk);
}

/* ��׽/�Ƚ�4������� (CC4 Polarity) ��غ��� */
void GPTIMx_CCER_CC4P_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->CCER;
	tmpreg &= ~(GPTIMx_CCER_CC4P_Msk);
	tmpreg |= (SetValue & GPTIMx_CCER_CC4P_Msk);
	GPTIMx->CCER = tmpreg;
}

uint32_t GPTIMx_CCER_CC4P_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CCER & GPTIMx_CCER_CC4P_Msk);
}

/* ��׽/�Ƚ�4���ʹ�� (CC4 output Enable) ��غ��� */
void GPTIMx_CCER_CC4E_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->CCER |= (GPTIMx_CCER_CC4E_Msk);
	}
	else
	{
		GPTIMx->CCER &= ~(GPTIMx_CCER_CC4E_Msk);
	}
}

FunState GPTIMx_CCER_CC4E_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->CCER & (GPTIMx_CCER_CC4E_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�3������� (CC3 Polarity) ��غ��� */
void GPTIMx_CCER_CC3P_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->CCER;
	tmpreg &= ~(GPTIMx_CCER_CC3P_Msk);
	tmpreg |= (SetValue & GPTIMx_CCER_CC3P_Msk);
	GPTIMx->CCER = tmpreg;
}

uint32_t GPTIMx_CCER_CC3P_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CCER & GPTIMx_CCER_CC3P_Msk);
}

/* ��׽/�Ƚ�3���ʹ�� (CC3 output Enable) ��غ��� */
void GPTIMx_CCER_CC3E_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->CCER |= (GPTIMx_CCER_CC3E_Msk);
	}
	else
	{
		GPTIMx->CCER &= ~(GPTIMx_CCER_CC3E_Msk);
	}
}

FunState GPTIMx_CCER_CC3E_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->CCER & (GPTIMx_CCER_CC3E_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�2������� (CC2 Polarity) ��غ��� */
void GPTIMx_CCER_CC2P_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->CCER;
	tmpreg &= ~(GPTIMx_CCER_CC2P_Msk);
	tmpreg |= (SetValue & GPTIMx_CCER_CC2P_Msk);
	GPTIMx->CCER = tmpreg;
}

uint32_t GPTIMx_CCER_CC2P_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CCER & GPTIMx_CCER_CC2P_Msk);
}

/* ��׽/�Ƚ�2���ʹ�� (CC2 output Enable) ��غ��� */
void GPTIMx_CCER_CC2E_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->CCER |= (GPTIMx_CCER_CC2E_Msk);
	}
	else
	{
		GPTIMx->CCER &= ~(GPTIMx_CCER_CC2E_Msk);
	}
}

FunState GPTIMx_CCER_CC2E_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->CCER & (GPTIMx_CCER_CC2E_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽/�Ƚ�1������� (CC1 Polarity) ��غ��� */
void GPTIMx_CCER_CC1P_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->CCER;
	tmpreg &= ~(GPTIMx_CCER_CC1P_Msk);
	tmpreg |= (SetValue & GPTIMx_CCER_CC1P_Msk);
	GPTIMx->CCER = tmpreg;
}

uint32_t GPTIMx_CCER_CC1P_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CCER & GPTIMx_CCER_CC1P_Msk);
}

/* ��׽/�Ƚ�1���ʹ�� (CC1 output Enable) ��غ��� */
void GPTIMx_CCER_CC1E_Setable(GPTIM_Type* GPTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPTIMx->CCER |= (GPTIMx_CCER_CC1E_Msk);
	}
	else
	{
		GPTIMx->CCER &= ~(GPTIMx_CCER_CC1E_Msk);
	}
}

FunState GPTIMx_CCER_CC1E_Getable(GPTIM_Type* GPTIMx)
{
	if (GPTIMx->CCER & (GPTIMx_CCER_CC1E_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ������ֵ (Counter) ��غ��� */
void GPTIMx_CNT_Write(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	GPTIMx->CNT = (SetValue & GPTIMx_CNT_CNT_Msk);
}

uint32_t GPTIMx_CNT_Read(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CNT & GPTIMx_CNT_CNT_Msk);
}

/* ������ʱ�ӣ�CK_CNT��Ԥ��Ƶֵ (Counter Clock Prescaler) ��غ��� */
void GPTIMx_PSC_Write(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	GPTIMx->PSC = (SetValue & GPTIMx_PSC_PSC_Msk);
}

uint32_t GPTIMx_PSC_Read(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->PSC & GPTIMx_PSC_PSC_Msk);
}

/* �������ʱ���Զ�����ֵ (Auto-Reload Register) ��غ��� */
void GPTIMx_ARR_Write(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	GPTIMx->ARR = (SetValue & GPTIMx_ARR_ARR_Msk);
}

uint32_t GPTIMx_ARR_Read(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->ARR & GPTIMx_ARR_ARR_Msk);
}

/* ��׽/�Ƚ�ͨ��1�Ĵ��� (Capture/Compare channel 1 Register) ��غ��� */
void GPTIMx_CCR1_Write(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	GPTIMx->CCR1 = (SetValue & GPTIMx_CCR1_CCR1_Msk);
}

uint32_t GPTIMx_CCR1_Read(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CCR1 & GPTIMx_CCR1_CCR1_Msk);
}

/* ��׽/�Ƚ�ͨ��2�Ĵ��� (Capture/Compare channel 2 Register) ��غ��� */
void GPTIMx_CCR2_Write(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	GPTIMx->CCR2 = (SetValue & GPTIMx_CCR2_CCR2_Msk);
}

uint32_t GPTIMx_CCR2_Read(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CCR2 & GPTIMx_CCR2_CCR2_Msk);
}

/* ��׽/�Ƚ�ͨ��3�Ĵ��� (Capture/Compare channel 3 Register) ��غ��� */
void GPTIMx_CCR3_Write(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	GPTIMx->CCR3 = (SetValue & GPTIMx_CCR3_CCR3_Msk);
}

uint32_t GPTIMx_CCR3_Read(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CCR3 & GPTIMx_CCR3_CCR3_Msk);
}

/* ��׽/�Ƚ�ͨ��4�Ĵ��� (Capture/Compare channel 4 Register) ��غ��� */
void GPTIMx_CCR4_Write(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	GPTIMx->CCR4 = (SetValue & GPTIMx_CCR4_CCR4_Msk);
}

uint32_t GPTIMx_CCR4_Read(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CCR4 & GPTIMx_CCR4_CCR4_Msk);
}

/* DMA Burst���� (DMA Burst Length) ��غ��� */
void GPTIMx_DCR_DBL_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->DCR;
	tmpreg &= ~(GPTIMx_DCR_DBL_Msk);
	tmpreg |= (SetValue & GPTIMx_DCR_DBL_Msk);
	GPTIMx->DCR = tmpreg;
}

uint32_t GPTIMx_DCR_DBL_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->DCR & GPTIMx_DCR_DBL_Msk);
}

/* DMA����ַ������ָ��Ĵ�����ƫ�Ƶ�ַ (DMA Burst offset Address) ��غ��� */
void GPTIMx_DCR_DBA_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->DCR;
	tmpreg &= ~(GPTIMx_DCR_DBA_Msk);
	tmpreg |= (SetValue & GPTIMx_DCR_DBA_Msk);
	GPTIMx->DCR = tmpreg;
}

uint32_t GPTIMx_DCR_DBA_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->DCR & GPTIMx_DCR_DBA_Msk);
}

/* DMA burst���ʼĴ��� (DMA Burst Access Register) ��غ��� */
void GPTIMx_DMAR_Write(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	GPTIMx->DMAR = (SetValue & GPTIMx_DMAR_DMAR_Msk);
}

uint32_t GPTIMx_DMAR_Read(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->DMAR & GPTIMx_DMAR_DMAR_Msk);
}

/* ITR�����ź�ѡ�� (Internal Trigger Source Selection) ��غ��� */
void GPTIMx_ITRSEL_ITR3SEL_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->ITRSEL;
	tmpreg &= ~(GPTIMx_ITRSEL_ITR3SEL_Msk);
	tmpreg |= (SetValue & GPTIMx_ITRSEL_ITR3SEL_Msk);
	GPTIMx->ITRSEL = tmpreg;
}

uint32_t GPTIMx_ITRSEL_ITR3SEL_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->ITRSEL & GPTIMx_ITRSEL_ITR3SEL_Msk);
}

/* ITR�����ź�ѡ�� (Internal Trigger Source Selection) ��غ��� */
void GPTIMx_ITRSEL_ITR2SEL_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->ITRSEL;
	tmpreg &= ~(GPTIMx_ITRSEL_ITR2SEL_Msk);
	tmpreg |= (SetValue & GPTIMx_ITRSEL_ITR2SEL_Msk);
	GPTIMx->ITRSEL = tmpreg;
}

uint32_t GPTIMx_ITRSEL_ITR2SEL_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->ITRSEL & GPTIMx_ITRSEL_ITR2SEL_Msk);
}

/* ITR�����ź�ѡ�� (Internal Trigger Source Selection) ��غ��� */
void GPTIMx_ITRSEL_ITR1SEL_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->ITRSEL;
	tmpreg &= ~(GPTIMx_ITRSEL_ITR1SEL_Msk);
	tmpreg |= (SetValue & GPTIMx_ITRSEL_ITR1SEL_Msk);
	GPTIMx->ITRSEL = tmpreg;
}

uint32_t GPTIMx_ITRSEL_ITR1SEL_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->ITRSEL & GPTIMx_ITRSEL_ITR1SEL_Msk);
}

/* ITR�����ź�ѡ�� (Internal Trigger Source Selection) ��غ��� */
void GPTIMx_ITRSEL_ITR0SEL_Set(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPTIMx->ITRSEL;
	tmpreg &= ~(GPTIMx_ITRSEL_ITR0SEL_Msk);
	tmpreg |= (SetValue & GPTIMx_ITRSEL_ITR0SEL_Msk);
	GPTIMx->ITRSEL = tmpreg;
}

uint32_t GPTIMx_ITRSEL_ITR0SEL_Get(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->ITRSEL & GPTIMx_ITRSEL_ITR0SEL_Msk);
}


void GPTIMx_Deinit(GPTIM_Type* GPTIMx)
{
	if(GPTIMx==GPTIM0)
  {
    RCC_PRST_EN_Write(RSTKEY0);
    RCC_APBRST_CR1_GT0RST_Setable(ENABLE);  
    RCC_APBRST_CR1_GT0RST_Setable(DISABLE);
    RCC_PRST_EN_Write(RSTKEY1);
  }
  if(GPTIMx==GPTIM1)
  {
    RCC_PRST_EN_Write(RSTKEY0);
    RCC_APBRST_CR1_GT1RST_Setable(ENABLE);  
    RCC_APBRST_CR1_GT1RST_Setable(DISABLE);
    RCC_PRST_EN_Write(RSTKEY1);
  }
  
}  
/******END OF FILE****/
