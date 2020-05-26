/**
  ******************************************************************************
  * @file    fm33l0xx_wwdt.c
  * @author  FM33L0 Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33l0xx_wwdt.h" 


/** @addtogroup fm33l0_StdPeriph_Driver
  * @{
  */

/** @defgroup WWDT 
  * @brief WWDT driver modules
  * @{
  */ 
  
  /* WWDT控制寄存器 相关函数 */
void WWDT_CR_Write(uint32_t SetValue)
{
	WWDT->CR = (SetValue & WWDT_CR_CON_Msk);
}

/* 配置看门狗溢出时间 相关函数 */
void WWDT_CFGR_CFG_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = WWDT->CFGR;
	tmpreg &= ~(WWDT_CFGR_CFG_Msk);
	tmpreg |= (SetValue & WWDT_CFGR_CFG_Msk);
	WWDT->CFGR = tmpreg;
}

uint32_t WWDT_CFGR_CFG_Get(void)
{
	return (WWDT->CFGR & WWDT_CFGR_CFG_Msk);
}

/* WWDT计数寄存器值 相关函数 */
uint32_t WWDT_CNT_Read(void)
{
	return (WWDT->CNT & WWDT_CNT_CNT_Msk);
}

/* WWDT中断使能 相关函数 */
void WWDT_IER_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		WWDT->IER |= (WWDT_IER_IE_Msk);
	}
	else
	{
		WWDT->IER &= ~(WWDT_IER_IE_Msk);
	}
}

FunState WWDT_IER_IE_Getable(void)
{
	if (WWDT->IER & (WWDT_IER_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* WWDT 75%计时中断标志，写1清零 相关函数 */
void WWDT_ISR_IF_Clr(void)
{
	WWDT->ISR = WWDT_ISR_IF_Msk;
}

FlagStatus WWDT_ISR_IF_Chk(void)
{
	if (WWDT->ISR & WWDT_ISR_IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* WWDT的4096预分频计数器 相关函数 */
void WWDT_PSC_Write(uint32_t SetValue)
{
	WWDT->PSC = (SetValue & WWDT_PSC_DIV_CNT_Msk);
}

uint32_t WWDT_PSC_Read(void)
{
	return (WWDT->PSC & WWDT_PSC_DIV_CNT_Msk);
}

/******END OF FILE****/
