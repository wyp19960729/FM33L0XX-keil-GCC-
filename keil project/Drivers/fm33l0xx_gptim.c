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
  GPTIMx_CR1_CMS_Set(GPTIMx,GPTIMx_CR1_CMS_EDGE);//边沿对齐模式
  GPTIMx_CR1_DIR_Set(GPTIMx,TIM_TimeBaseInitStruct->TIM_CounterMode);
  GPTIMx_CR1_CKD_Set(GPTIMx,TIM_TimeBaseInitStruct->TIM_ClockDivision);
  
  GPTIMx_ARR_Write(GPTIMx,TIM_TimeBaseInitStruct->TIM_Period);
  GPTIMx_PSC_Write(GPTIMx,TIM_TimeBaseInitStruct->TIM_Prescaler);
  
  GPTIMx_EGR_UG_Setable(GPTIMx,ENABLE);//产生事件更新参数
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

/* Dead time和数字滤波时钟频率分频寄存器（相对CK_INT的分频比）(Counter clocK Divider) 相关函数 */
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

/* Auto-reload预装载使能 (Auto-Reload Preload Enable) 相关函数 */
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

/* 计数器对齐模式选择 (Counter Mode Selection) 相关函数 */
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

/* 计数方向寄存器 (counter Direction) 相关函数 */
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

/* 单脉冲输出模式 (One Pulse Mode) 相关函数 */
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
/* 更新请求选择 (Update Request Selection) 相关函数 */
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
/* 禁止update (Update Disable) 相关函数 */
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

/* 计数器使能 (Counter Enable) 相关函数 */
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

/* 通道1输入源选择 (Timer Input 1 Selection) 相关函数 */
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

/* 主机模式选择，用于配置主机模式下向从机发送的同步触发信号（TRGO）源 (Master Mode Selection) 相关函数 */
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

/* 捕捉/比较 DMA选择 (Capture/Compare DMA Selection) 相关函数 */
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

/* 外部触发信号极性配置 (External Trigger Polarity) 相关函数 */
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

/* 外部时钟使能 (External Clock Enable) 相关函数 */
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

/* 外部触发信号预分频寄存器 (External Trigger Prescaler)
外部触发信号ETRP的频率最多只能是GPTIM工作时钟的1/4，当输入信号频率较高时，可以使用预分频 相关函数 */
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

/* 外部触发信号滤波时钟和长度选择 (External Trigger Filter) 相关函数 */
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

/* 主/从模式 (Master Slave Mode) 相关函数 */
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

/* 触发选择，用于选择同步计数器的触发源 (Trigger Source) 相关函数 */
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

/* 从机模式选择 (Slave Mode Selection) 相关函数 */
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

/* 捕捉比较通道4的DMA模式配置 (CC4 Burst Enable) 相关函数 */
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

/* 捕捉比较通道3的DMA模式配置 (CC3 Burst Enable) 相关函数 */
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

/* 捕捉比较通道2的DMA模式配置 (CC2 Burst Enable) 相关函数 */
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

/* 捕捉比较通道1的DMA模式配置 (CC1 Burst Enable) 相关函数 */
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

/* 外部触发DMA请求使能 (Triggered DMA Enable) 相关函数 */
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

/* 捕捉比较通道4的DMA请求使能 (CC4 DMA Enable) 相关函数 */
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

/* 捕捉比较通道3的DMA请求使能 (CC3 DMA Enable) 相关函数 */
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

/* 捕捉比较通道2的DMA请求使能 (CC2 DMA Enable) 相关函数 */
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

/* 捕捉比较通道1的DMA请求使能 (CC1 DMA Enable) 相关函数 */
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

/* Update Event DMA请求使能 (Update event DMA Enable) 相关函数 */
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

/* 触发事件中断使能 (Trigger event Interrupt Enable) 相关函数 */
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

/* 捕捉/比较通道4中断使能 (CC4 Interrupt Enable) 相关函数 */
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

/* 捕捉/比较通道3中断使能 (CC3 Interrupt Enable) 相关函数 */
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

/* 捕捉/比较通道2中断使能 (CC2 Interrupt Enable) 相关函数 */
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

/* 捕捉/比较通道1中断使能 (CC1 Interrupt Enable) 相关函数 */
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

/* Update事件中断使能 (Update event Interrupt Enable) 相关函数 */
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

/* 捕捉/比较通道4的Overcapture中断 (Over-Capture Interrupt Flag for CC4) 相关函数 */
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

/* 捕捉/比较通道3的Overcapture中断 (Over-Capture Interrupt Flag for CC3) 相关函数 */
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

/* 捕捉/比较通道2的Overcapture中断 (Over-Capture Interrupt Flag for CC2) 相关函数 */
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

/* 捕捉/比较通道1的Overcapture中断 (Over-Capture Interrupt Flag for CC1) 相关函数 */
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

/* 触发事件中断标志 相关函数 */
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

/* 捕捉/比较通道4中断标志 (CC4 Interrupt Flag) 相关函数 */
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

/* 捕捉/比较通道3中断标志 (CC3 Interrupt Flag) 相关函数 */
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

/* 捕捉/比较通道2中断标志 (CC2 Interrupt Flag) 相关函数 */
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

/* 捕捉/比较通道1中断标志 (CC1 Interrupt Flag) 相关函数 */
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

/* Update事件中断标志，硬件置位，软件写1清零。(Update event Interrupt Flag) 相关函数 */
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

/* 软件触发，软件置位此寄存器产生触发事件，硬件自动清零 (Trigger Generate) 相关函数 */
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

/* 捕捉/比较通道4软件触发 (CC4 Generate) 相关函数 */
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
/* 捕捉/比较通道3软件触发 (CC3 Generate) 相关函数 */
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
/* 捕捉/比较通道2软件触发 (CC2 Generate) 相关函数 */
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
/* 捕捉/比较通道1软件触发 (CC1 Generate) 相关函数 */
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
/* 软件Update事件，软件置位此寄存器产生Update事件，硬件自动清零 (User Generate) 相关函数 */
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

/* 输出比较2清零使能 (OC2 Clear Enable) 相关函数 */
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

/* 输出比较2模式配置，此寄存器定义OC2REF信号的行为 (OC2 Mode) 相关函数 */
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

/* 输出比较2预装载使能 (OC2 Preload Enable) 相关函数 */
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

/* 输出比较2快速使能 (OC2 Fast Enable) 相关函数 */
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

/* 捕捉/比较2通道选择 (CC2 channel Selection) 相关函数 */
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

/* 输出比较1清零使能 (OC2 Clear Enable) 相关函数 */
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

/* 输出比较1模式配置，此寄存器定义OC1REF信号的行为 (OC1 Mode) 相关函数 */
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

/* 输出比较1预装载使能 (OC1 Preload Enable) 相关函数 */
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

/* 输出比较1快速使能 (OC1 Fast Enable) 相关函数 */
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

/* 捕捉/比较1通道选择 (CC1 channel Selection) 相关函数 */
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

/* 输入捕捉2滤波 (IC2 Filter) 相关函数 */
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

/* 输入捕捉2预分频 (IC2 Prescaler) 相关函数 */
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

/* 输入捕捉1滤波 (IC1 Filter) 相关函数 */
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

/* 输入捕捉1预分频 (IC1 Prescaler) 相关函数 */
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

/* 输出比较4清零使能 (OC4 Clear Enable) 相关函数 */
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

/* 输出比较4模式配置，此寄存器定义OC4REF信号的行为 (OC4 Mode) 相关函数 */
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

/* 输出比较4预装载使能 (OC4 Preload Enable) 相关函数 */
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

/* 输出比较4快速使能 (OC4 Fast Enable) 相关函数 */
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

/* 捕捉/比较4通道选择 (CC4 channel Selection) 相关函数 */
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

/* 输出比较3清零使能 (OC3 Clear Enable) 相关函数 */
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

/* 输出比较3模式配置，此寄存器定义OC3REF信号的行为 (OC3 Mode) 相关函数 */
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

/* 输出比较3预装载使能 (OC3 Preload Enable) 相关函数 */
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

/* 输出比较3快速使能 (OC3 Fast Enable) 相关函数 */
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

/* 捕捉/比较3通道选择 (CC3 channel Selection) 相关函数 */
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

/* 输入捕捉4滤波 (IC4 Filter) 相关函数 */
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

/* 输入捕捉4预分频 (IC4 Prescaler) 相关函数 */
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

/* 输入捕捉3滤波 (IC3 Filter) 相关函数 */
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

/* 输入捕捉3预分频 (IC3 Prescaler) 相关函数 */
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

/* 捕捉/比较4输出极性 (CC4 Polarity) 相关函数 */
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

/* 捕捉/比较4输出使能 (CC4 output Enable) 相关函数 */
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

/* 捕捉/比较3输出极性 (CC3 Polarity) 相关函数 */
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

/* 捕捉/比较3输出使能 (CC3 output Enable) 相关函数 */
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

/* 捕捉/比较2输出极性 (CC2 Polarity) 相关函数 */
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

/* 捕捉/比较2输出使能 (CC2 output Enable) 相关函数 */
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

/* 捕捉/比较1输出极性 (CC1 Polarity) 相关函数 */
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

/* 捕捉/比较1输出使能 (CC1 output Enable) 相关函数 */
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

/* 计数器值 (Counter) 相关函数 */
void GPTIMx_CNT_Write(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	GPTIMx->CNT = (SetValue & GPTIMx_CNT_CNT_Msk);
}

uint32_t GPTIMx_CNT_Read(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CNT & GPTIMx_CNT_CNT_Msk);
}

/* 计数器时钟（CK_CNT）预分频值 (Counter Clock Prescaler) 相关函数 */
void GPTIMx_PSC_Write(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	GPTIMx->PSC = (SetValue & GPTIMx_PSC_PSC_Msk);
}

uint32_t GPTIMx_PSC_Read(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->PSC & GPTIMx_PSC_PSC_Msk);
}

/* 计数溢出时的自动重载值 (Auto-Reload Register) 相关函数 */
void GPTIMx_ARR_Write(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	GPTIMx->ARR = (SetValue & GPTIMx_ARR_ARR_Msk);
}

uint32_t GPTIMx_ARR_Read(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->ARR & GPTIMx_ARR_ARR_Msk);
}

/* 捕捉/比较通道1寄存器 (Capture/Compare channel 1 Register) 相关函数 */
void GPTIMx_CCR1_Write(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	GPTIMx->CCR1 = (SetValue & GPTIMx_CCR1_CCR1_Msk);
}

uint32_t GPTIMx_CCR1_Read(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CCR1 & GPTIMx_CCR1_CCR1_Msk);
}

/* 捕捉/比较通道2寄存器 (Capture/Compare channel 2 Register) 相关函数 */
void GPTIMx_CCR2_Write(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	GPTIMx->CCR2 = (SetValue & GPTIMx_CCR2_CCR2_Msk);
}

uint32_t GPTIMx_CCR2_Read(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CCR2 & GPTIMx_CCR2_CCR2_Msk);
}

/* 捕捉/比较通道3寄存器 (Capture/Compare channel 3 Register) 相关函数 */
void GPTIMx_CCR3_Write(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	GPTIMx->CCR3 = (SetValue & GPTIMx_CCR3_CCR3_Msk);
}

uint32_t GPTIMx_CCR3_Read(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CCR3 & GPTIMx_CCR3_CCR3_Msk);
}

/* 捕捉/比较通道4寄存器 (Capture/Compare channel 4 Register) 相关函数 */
void GPTIMx_CCR4_Write(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	GPTIMx->CCR4 = (SetValue & GPTIMx_CCR4_CCR4_Msk);
}

uint32_t GPTIMx_CCR4_Read(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->CCR4 & GPTIMx_CCR4_CCR4_Msk);
}

/* DMA Burst长度 (DMA Burst Length) 相关函数 */
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

/* DMA基地址，定义指向寄存器的偏移地址 (DMA Burst offset Address) 相关函数 */
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

/* DMA burst访问寄存器 (DMA Burst Access Register) 相关函数 */
void GPTIMx_DMAR_Write(GPTIM_Type* GPTIMx, uint32_t SetValue)
{
	GPTIMx->DMAR = (SetValue & GPTIMx_DMAR_DMAR_Msk);
}

uint32_t GPTIMx_DMAR_Read(GPTIM_Type* GPTIMx)
{
	return (GPTIMx->DMAR & GPTIMx_DMAR_DMAR_Msk);
}

/* ITR输入信号选择 (Internal Trigger Source Selection) 相关函数 */
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

/* ITR输入信号选择 (Internal Trigger Source Selection) 相关函数 */
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

/* ITR输入信号选择 (Internal Trigger Source Selection) 相关函数 */
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

/* ITR输入信号选择 (Internal Trigger Source Selection) 相关函数 */
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
