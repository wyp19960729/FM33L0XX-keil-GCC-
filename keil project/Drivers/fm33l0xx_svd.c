/**
  ******************************************************************************
  * @file    fm33l0xx_svd.c
  * @author  FM33L0 Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33l0xx_svd.h" 


/** @addtogroup fm33l0_StdPeriph_Driver
  * @{
  */

/** @defgroup SVD
  * @brief SVD driver modules
  * @{
  */ 
  
 /* SVD报警阈值设置(SVD threshold level)
 相关函数 */
void SVD_CFGR_LVL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SVD->CFGR;
	tmpreg &= ~(SVD_CFGR_LVL_Msk);
	tmpreg |= (SetValue & SVD_CFGR_LVL_Msk);
	SVD->CFGR = tmpreg;
}

uint32_t SVD_CFGR_LVL_Get(void)
{
	return (SVD->CFGR & SVD_CFGR_LVL_Msk);
}

/* 数字滤波使能（SVDMODE=1时必须置1）(Digital Filter Enable) 相关函数 */
void SVD_CFGR_DFEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SVD->CFGR |= (SVD_CFGR_DFEN_Msk);
	}
	else
	{
		SVD->CFGR &= ~(SVD_CFGR_DFEN_Msk);
	}
}

FunState SVD_CFGR_DFEN_Getable(void)
{
	if (SVD->CFGR & (SVD_CFGR_DFEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SVD工作模式选择，配置模式后还要置位SVDEN才会启动SVD 相关函数 */
void SVD_CFGR_MOD_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SVD->CFGR;
	tmpreg &= ~(SVD_CFGR_MOD_Msk);
	tmpreg |= (SetValue & SVD_CFGR_MOD_Msk);
	SVD->CFGR = tmpreg;
}

uint32_t SVD_CFGR_MOD_Get(void)
{
	return (SVD->CFGR & SVD_CFGR_MOD_Msk);
}

/* SVD间歇使能间隔(SVD Interval) 相关函数 */
void SVD_CFGR_ITVL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SVD->CFGR;
	tmpreg &= ~(SVD_CFGR_ITVL_Msk);
	tmpreg |= (SetValue & SVD_CFGR_ITVL_Msk);
	SVD->CFGR = tmpreg;
}

uint32_t SVD_CFGR_ITVL_Get(void)
{
	return (SVD->CFGR & SVD_CFGR_ITVL_Msk);
}

/* SVD测试使能，避免写1 (SVD test enable) 相关函数 */
void SVD_CR_TE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SVD->CR |= (SVD_CR_TE_Msk);
	}
	else
	{
		SVD->CR &= ~(SVD_CR_TE_Msk);
	}
}

FunState SVD_CR_TE_Getable(void)
{
	if (SVD->CR & (SVD_CR_TE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SVS外部电源检测通道控制信号(SVS external monitor channel enable) 相关函数 */
void SVD_CR_SVSEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SVD->CR |= (SVD_CR_SVSEN_Msk);
	}
	else
	{
		SVD->CR &= ~(SVD_CR_SVSEN_Msk);
	}
}

FunState SVD_CR_SVSEN_Getable(void)
{
	if (SVD->CR & (SVD_CR_SVSEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SVD使能 (SVD enable) 相关函数 */
void SVD_CR_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SVD->CR |= (SVD_CR_EN_Msk);
	}
	else
	{
		SVD->CR &= ~(SVD_CR_EN_Msk);
	}
}

FunState SVD_CR_EN_Getable(void)
{
	if (SVD->CR & (SVD_CR_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 电源跌落中断使能(Power Fall interrupt enable) 相关函数 */
void SVD_IER_PFIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SVD->IER |= (SVD_IER_PFIE_Msk);
	}
	else
	{
		SVD->IER &= ~(SVD_IER_PFIE_Msk);
	}
}

FunState SVD_IER_PFIE_Getable(void)
{
	if (SVD->IER & (SVD_IER_PFIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 电源恢复中断使能(Power Rise interrupt enable) 相关函数 */
void SVD_IER_PRIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SVD->IER |= (SVD_IER_PRIE_Msk);
	}
	else
	{
		SVD->IER &= ~(SVD_IER_PRIE_Msk);
	}
}

FunState SVD_IER_PRIE_Getable(void)
{
	if (SVD->IER & (SVD_IER_PRIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SVD电源检测输出 (SVD output) 相关函数 */
FlagStatus SVD_ISR_SVDO_Chk(void)
{
	if (SVD->ISR & SVD_ISR_SVDO_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* SVD输出锁存信号，数字电路锁存的SVD状态 相关函数 */
FlagStatus SVD_ISR_SVDR_Chk(void)
{
	if (SVD->ISR & SVD_ISR_SVDR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 电源跌落中断标志 相关函数 */
void SVD_ISR_PFF_Clr(void)
{
	SVD->ISR = SVD_ISR_PFF_Msk;
}

FlagStatus SVD_ISR_PFF_Chk(void)
{
	if (SVD->ISR & SVD_ISR_PFF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 电源恢复中断标志 相关函数 */
void SVD_ISR_PRF_Clr(void)
{
	SVD->ISR = SVD_ISR_PRF_Msk;
}

FlagStatus SVD_ISR_PRF_Chk(void)
{
	if (SVD->ISR & SVD_ISR_PRF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 0.85V基准输入使能信号 (0.85V reference enable) 相关函数 */
void SVD_VSR_V0P85EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SVD->VSR |= (SVD_VSR_V0P85EN_Msk);
	}
	else
	{
		SVD->VSR &= ~(SVD_VSR_V0P85EN_Msk);
	}
}

FunState SVD_VSR_V0P85EN_Getable(void)
{
	if (SVD->VSR & (SVD_VSR_V0P85EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 0.8V基准输入使能信号 (0.8V reference enable) 相关函数 */
void SVD_VSR_V0P8EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SVD->VSR |= (SVD_VSR_V0P8EN_Msk);
	}
	else
	{
		SVD->VSR &= ~(SVD_VSR_V0P8EN_Msk);
	}
}

FunState SVD_VSR_V0P8EN_Getable(void)
{
	if (SVD->VSR & (SVD_VSR_V0P8EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 0.75V基准输入使能信号 (0.75V reference enable) 相关函数 */
void SVD_VSR_V0P75EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SVD->VSR |= (SVD_VSR_V0P75EN_Msk);
	}
	else
	{
		SVD->VSR &= ~(SVD_VSR_V0P75EN_Msk);
	}
}

FunState SVD_VSR_V0P75EN_Getable(void)
{
	if (SVD->VSR & (SVD_VSR_V0P75EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}


void SVD_Deinit(void)
{
	//SVD->CFGR = 0x00000008;
	//SVD->CR = 0x00000000;
	//SVD->IER = 0x00000000;
	//SVD->ISR = 0x00000000;
	//SVD->VSR = 0x00000004;
} 
/*********************************
SVD初始化配置函数 
功能：SVD初始化配置
输入: ANAC_SVD_InitTypeDef* para，结构体函数中配置工作模式、阈值、数字滤波等功能
输出: 无
*********************************/
void SVD_Init(ANAC_SVD_InitTypeDef* para)
{
	SVD_CFGR_MOD_Set(para->SVDMOD);	//SVD工作模式选择
	SVD_CFGR_ITVL_Set(para->SVDITVL);	//SVD间歇使能间隔设置
	SVD_CFGR_LVL_Set(para->SVDLVL);	//SVD报警阈值设置
	SVD_CFGR_DFEN_Setable(para->DFEN);	//SVD数字滤波设置（SVDMODE=1时必须置1）
	SVD_IER_PFIE_Setable(para->PFIE);	//SVD电源跌落中断设置
	SVD_IER_PRIE_Setable(para->PRIE);	//SVD电源恢复中断设置
	SVD_CR_TE_Setable(DISABLE);	//关闭测试功能
	SVD_CR_EN_Setable(para->SVDEN);	//SVD使能设置
}
/******END OF FILE****/
