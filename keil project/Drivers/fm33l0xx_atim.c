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
  ATIM_CR1_CMS_Set(ATIM_CR1_CMS_SINGLE);//边沿对齐模式
  ATIM_CR1_DIR_Set(TIM_TimeBaseInitStruct->TIM_CounterMode);
  ATIM_CR1_CKD_Set(TIM_TimeBaseInitStruct->TIM_ClockDivision);
  
  ATIM_ARR_Write(TIM_TimeBaseInitStruct->TIM_Period);
  ATIM_PSC_Write(TIM_TimeBaseInitStruct->TIM_Prescaler);
  ATIM_RCR_Write(TIM_TimeBaseInitStruct->TIM_RepetitionCounter);
  
  ATIM_EGR_UG_Setable(ENABLE);//产生事件更新参数
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





/* Dead time和数字滤波时钟频率分频寄存器 相关函数 */
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

/* ARR预装载使能  相关函数 */
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

/* 计数器对齐模式选择 相关函数 */
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

/* 计数方向寄存器 相关函数 */
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

/* 单脉冲输出模式 相关函数 */
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

/* 更新请求选择 相关函数 */
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

/* 禁止update 相关函数 */
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

/* 计数器使能 相关函数 */
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

/* 参考OIS1 相关函数 */
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

/* 参考OIS1N 相关函数 */
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

/* 参考OIS1 相关函数 */
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

/* 参考OIS1N 相关函数 */
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

/* 参考OIS1 相关函数 */
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

/* OC1N的输出IDLE状态 相关函数 */
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

/* OC1的输出IDLE状态 相关函数 */
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

/* ATIM输入TI1选择 相关函数 */
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

/* 主机模式选择，用于配置主机模式下向从机发送的同步触发信号（TRGO）源 相关函数 */
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

/* 捕捉/比较 DMA选择 相关函数 */
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

/* 捕捉/比较控制寄存器更新选择 相关函数 */
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

/* 外部触发信号极性配置 相关函数 */
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

/* 外部时钟使能 相关函数 */
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

/* 外部触发信号预分频寄存器,外部触发信号ETRP的频率最多只能是ATIM工作时钟的1/4，当输入信号频率较高时，可以使用预分频 相关函数 */
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

/* 外部触发信号滤波时钟和长度选择 相关函数 */
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

/* 主机从机模式选 相关函数 */
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

/* 触发选择，用于选择同步计数器的触发源 相关函数 */
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

/* 从机模式选择 相关函数 */
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

/* 捕捉比较通道4的DMA模式配置 相关函数 */
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

/* 捕捉比较通道3的DMA模式配置 相关函数 */
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

/* 捕捉比较通道2的DMA模式配置 相关函数 */
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

/* 捕捉比较通道1的DMA模式配置 相关函数 */
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

/* 外部触发DMA请求使能 相关函数 */
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

/* COM事件DMA请求使能 相关函数 */
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

/* 捕捉比较通道4的DMA请求使能 相关函数 */
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

/* 捕捉比较通道3的DMA请求使能 相关函数 */
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

/* 捕捉比较通道2的DMA请求使能 相关函数 */
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

/* 捕捉比较通道1的DMA请求使能 相关函数 */
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

/* 更新事件DMA请求使能  相关函数 */
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

/* 刹车事件中断使能 相关函数 */
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

/* 触发事件中断使能 相关函数 */
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

/* COM事件中断使能 相关函数 */
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

/* 捕捉/比较通道4中断使能 相关函数 */
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

/* 捕捉/比较通道3中断使能 相关函数 */
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

/* 捕捉/比较通道2中断使能 相关函数 */
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

/* 捕捉/比较通道1中断使能 相关函数 */
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

/* 更新事件中断使能 相关函数 */
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

/* 捕捉/比较通道4的Overcapture中断 相关函数 */
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

/* 捕捉/比较通道3的Overcapture中断 相关函数 */
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

/* 捕捉/比较通道2的Overcapture中断 相关函数 */
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

/* 捕捉/比较通道1的Overcapture中断，此寄存器仅在对应通道设置为输入捕捉模式的情况下有效。硬件置位，软件写1清零 相关函数 */
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

/* 刹车事件中断标志，硬件置位，软件写1清零 相关函数 */
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

/* 触发事件中断标志，硬件置位，软件写1清零 相关函数 */
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

/* COM事件中断标志，硬件置位，软件写1清零 相关函数 */
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

/* 捕捉/比较通道4中断标志，参考CC1IF 相关函数 */
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

/* 捕捉/比较通道3中断标志，参考CC1IF 相关函数 */
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

/* 捕捉/比较通道2中断标志，参考CC1IF 相关函数 */
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

/* 捕捉/比较通道1中断标志，如果CC1通道配置为输出：CC1IF在计数值等于比较值时置位，软件写1清零。
如果CC1通道配置为输入：发生捕捉事件时置位，软件写1清零，或者软件读ATIM_CCR1自动清零 相关函数 */
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

/* 更新事件中断标志，硬件置位，软件写1清零 相关函数 */
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

/* 软件刹车，软件置位此寄存器产生刹车事件，硬件自动清零 相关函数 */
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

/* 软件触发，软件置位此寄存器产生触发事件，硬件自动清零 相关函数 */
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

/* 软件COM事件，硬件置位，软件写1清零 相关函数 */
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

/* 捕捉/比较通道4软件触发，参考CC1G 相关函数 */
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

/* 捕捉/比较通道3软件触发，参考CC1G 相关函数 */
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

/* 捕捉/比较通道2软件触发，参考CC1G 相关函数 */
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

/* 捕捉/比较通道1软件触发 相关函数 */
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

/* 软件Update事件，软件置位此寄存器产生Update事件，硬件自动清零 相关函数 */
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

/* 输出比较2清零使能，参考OC1CE 相关函数 */
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

/* 输出比较2模式配置，参考OC1M 相关函数 */
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

/* 输出比较2预装载使能，参考OC1PE 相关函数 */
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

/* 输出比较2快速使能，参考OC1FE 相关函数 */
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

/* 捕捉/比较2通道选择 相关函数 */
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

/* 输出比较1清零使能 相关函数 */
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

/* 输出比较1模式配置，此寄存器定义OC1REF信号的行为 相关函数 */
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

/* 输出比较1预装载使能 相关函数 */
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

/* 输出比较1快速使能 相关函数 */
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

/* 捕捉/比较1通道选择 相关函数 */
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

/* 输入捕捉2滤波 相关函数 */
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

/* 输入捕捉2预分频 相关函数 */
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

/* 输入捕捉1滤波 相关函数 */
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

/* 输入捕捉1预分频 相关函数 */
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

/* 输出比较4清零使能，参考OC1CE 相关函数 */
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

/* 输出比较4预装载使能，参考OC1PE 相关函数 */
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

/* 输出比较4快速使能，参考OC1FE 相关函数 */
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

/* 捕捉/比较4通道选择 相关函数 */
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

/* 输出比较1清零使能 相关函数 */
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

/* 输出比较3模式配置，此寄存器定义OC3REF信号的行为 相关函数 */
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

/* 输出比较3预装载使能 相关函数 */
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

/* 输出比较3快速使能 相关函数 */
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

/* 捕捉/比较3通道选择 相关函数 */
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

/* 输入捕捉4滤波 相关函数 */
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

/* 输入捕捉4预分频 相关函数 */
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

/* 输入捕捉3滤波 相关函数 */
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

/* 输入捕捉3预分频 相关函数 */
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

/* 捕捉/比较4输出极性，参考CC1P 相关函数 */
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

/* 捕捉/比较4输出使能，参考CC1E 相关函数 */
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

/* 捕捉/比较3互补输出极性，参考CC1NP 相关函数 */
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

/* 捕捉/比较3互补输出使能，参考CC1NE 相关函数 */
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

/* 捕捉/比较3输出极性，参考CC1P 相关函数 */
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

/* 捕捉/比较3输出使能，参考CC1E 相关函数 */
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

/* 捕捉/比较2互补输出极性，参考CC1NP 相关函数 */
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

/* 捕捉/比较2互补输出使能，参考CC1NE 相关函数 */
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

/* 捕捉/比较2输出极性，参考CC1P 相关函数 */
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

/* 捕捉/比较2输出使能，参考CC1E 相关函数 */
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

/* 捕捉/比较1互补输出极性 相关函数 */
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

/* 捕捉/比较1互补输出使能 相关函数 */
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

/* 捕捉/比较1输出极性 (CC1 Polarity)
CC1通道配置为输出时
0：OC1高电平active
1：OC1低电平active
CC1通道配置为输入时
0：非取反模式–捕捉在IC1的上升沿进行
1：取反模式–捕捉在IC1的下降沿进行 相关函数 */
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

/* 捕捉/比较1输出使能 (CC1 Enable)
CC1通道配置为输出时
0：OC1不active
1：OC1 active
CC1通道配置为输入时
0：关闭捕捉功能
1：使能捕捉功能 相关函数 */
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

/* 计数器值 相关函数 */
void ATIM_CNT_Write(uint32_t SetValue)
{
	ATIM->CNT = (SetValue & ATIM_CNT_CNT_Msk);
}

uint32_t ATIM_CNT_Read(void)
{
	return (ATIM->CNT & ATIM_CNT_CNT_Msk);
}

/* 计数器时钟预分频值
fCK_CNT=fCK_PSC/(PSC[15:0]+1)
这是一个preload寄存器，在update事件发生时其内容被载入shadow寄存器 相关函数 */
void ATIM_PSC_Write(uint32_t SetValue)
{
	ATIM->PSC = (SetValue & ATIM_PSC_PSC_Msk);
}

uint32_t ATIM_PSC_Read(void)
{
	return (ATIM->PSC & ATIM_PSC_PSC_Msk);
}

/* 计数溢出时的自动重载值 
这是一个preload寄存器，在update事件发生时其内容被载入shadow寄存器 相关函数 */
void ATIM_ARR_Write(uint32_t SetValue)
{
	ATIM->ARR = (SetValue & ATIM_ARR_ARR_Msk);
}

uint32_t ATIM_ARR_Read(void)
{
	return (ATIM->ARR & ATIM_ARR_ARR_Msk);
}

/* 重复计数值  相关函数 */
void ATIM_RCR_Write(uint32_t SetValue)
{
	ATIM->RCR = (SetValue & ATIM_RCR_REP_Msk);
}

uint32_t ATIM_RCR_Read(void)
{
	return (ATIM->RCR & ATIM_RCR_REP_Msk);
}

/* 捕捉/比较通道1寄存器 
如果通道1配置为输出：
这是一个preload寄存器，其内容被载入shadow寄存器后用于与计数器比较产生OC1输出
如果通道1配置为输入：
CCR1保存最近一次输入捕捉事件发生时的计数器值，此时CCR1为只读 相关函数 */
void ATIM_CCR1_Write(uint32_t SetValue)
{
	ATIM->CCR1 = (SetValue & ATIM_CCR1_CCR1_Msk);
}

uint32_t ATIM_CCR1_Read(void)
{
	return (ATIM->CCR1 & ATIM_CCR1_CCR1_Msk);
}

/* 捕捉/比较通道2寄存器 
如果通道2配置为输出：
这是一个preload寄存器，其内容被载入shadow寄存器后用于与计数器比较产生OC2输出
如果通道2配置为输入：
CCR2保存最近一次输入捕捉事件发生时的计数器值，此时CCR2为只读 相关函数 */
void ATIM_CCR2_Write(uint32_t SetValue)
{
	ATIM->CCR2 = (SetValue & ATIM_CCR2_CCR2_Msk);
}

uint32_t ATIM_CCR2_Read(void)
{
	return (ATIM->CCR2 & ATIM_CCR2_CCR2_Msk);
}

/* 捕捉/比较通道3寄存器 
如果通道3配置为输出：
这是一个preload寄存器，其内容被载入shadow寄存器后用于与计数器比较产生OC3输出
如果通道3配置为输入：
CCR3保存最近一次输入捕捉事件发生时的计数器值，此时CCR3为只读 相关函数 */
void ATIM_CCR3_Write(uint32_t SetValue)
{
	ATIM->CCR3 = (SetValue & ATIM_CCR3_CCR3_Msk);
}

uint32_t ATIM_CCR3_Read(void)
{
	return (ATIM->CCR3 & ATIM_CCR3_CCR3_Msk);
}

/* 捕捉/比较通道4寄存器 
如果通道4配置为输出：
这是一个preload寄存器，其内容被载入shadow寄存器后用于与计数器比较产生OC4输出
如果通道4配置为输入：
CCR4保存最近一次输入捕捉事件发生时的计数器值，此时CCR4为只读 相关函数 */
void ATIM_CCR4_Write(uint32_t SetValue)
{
	ATIM->CCR4 = (SetValue & ATIM_CCR4_CCR4_Msk);
}

uint32_t ATIM_CCR4_Read(void)
{
	return (ATIM->CCR4 & ATIM_CCR4_CCR4_Msk);
}

/* 输出使能主控 相关函数 */
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

/* 自动输出使能 相关函数 */
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

/* 寄存器写保护配置 相关函数 */
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

/* 死区时间插入，用于配置互补输出插入的死区时间长度 相关函数 */
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

/* DMA Burst长度 相关函数 */
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

/* DMA基地址，定义指向寄存器的偏移地址 相关函数 */
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

/* DMA burst访问寄存器
在使用DMA burst传输时，将DMA通道外设地址设置为ATIM_DMAR，ATIM会根据DBL的值产生多次DMA请求 相关函数 */
void ATIM_DMAR_Write(uint32_t SetValue)
{
	ATIM->DMAR = (SetValue);
}

uint32_t ATIM_DMAR_Read(void)
{
	return (ATIM->DMAR);
}

/* ATIM_BRK2引脚输入门控信号 相关函数 */
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

/* ATIM_BRK1引脚输入门控信号 相关函数 */
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

/* 刹车信号的滤波时钟和长度选择  相关函数 */
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

/* 刹车组合控制 相关函数 */
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

/* XTHF停振检测刹车信号使能 相关函数 */
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

/* SVD刹车信号使能 相关函数 */
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

/* 比较器输出刹车信号使能 相关函数 */
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
