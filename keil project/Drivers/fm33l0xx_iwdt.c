/**
  ******************************************************************************
  * @file    fm33l0xx_iwdt.c
  * @author  FM33L0 Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33l0xx_iwdt.h" 


/** @addtogroup fm33l0_StdPeriph_Driver
  * @{
  */

/** @defgroup IWDT 
  * @brief IWDT driver modules
  * @{
  */ 
  
  
/* IWDT清除寄存器 相关函数 */
void IWDT_SERV_Write(uint32_t SetValue)
{
	IWDT->SERV = (SetValue);
}

/* 配置IWDT看门狗溢出时间 相关函数 */
void IWDT_CR_CFG_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = IWDT->CR;
	tmpreg &= ~(IWDT_CR_CFG_Msk);
	tmpreg |= (SetValue & IWDT_CR_CFG_Msk);
	IWDT->CR = tmpreg;
}

uint32_t IWDT_CR_CFG_Get(void)
{
	return (IWDT->CR & IWDT_CR_CFG_Msk);
}

/* IWDT当前计数值 相关函数 */
uint32_t IWDT_CNT_Read(void)
{
	return (IWDT->CNT & IWDT_CNT_CNT_Msk);
}

/* IWDT窗口寄存器 相关函数 */
void IWDT_WIN_Write(uint32_t SetValue)
{
	IWDT->WIN = (SetValue & IWDT_WIN_WIN_Msk);
}

uint32_t IWDT_WIN_Read(void)
{
	return (IWDT->WIN & IWDT_WIN_WIN_Msk);
}

/* IWDT清狗状态标志 相关函数 */
FlagStatus IWDT_SR_BUSY_Chk(void)
{
	if (IWDT->SR & IWDT_SR_BUSY_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}


/* 清狗函数 */
void IWDT_Clr(void)
{
    IWDT->SERV = WDTSERV_key;
}

/******END OF FILE****/
