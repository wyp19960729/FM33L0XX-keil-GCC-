/**
  ******************************************************************************
  * @file    fm33l0xx_opa.c
  * @author  FM33L0 Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33l0xx_opa.h" 
#include "fm33l0xx_rcc.h" 

/** @addtogroup fm33l0_StdPeriph_Driver
  * @{
  */

/** @defgroup OPA 
  * @brief OPA driver modules
  * @{
  */ 

/* VREF BUFFER使能信号 (VREF buffer enable) 相关函数 */
void OPAx_CR_BUFOFF_EN_Setable(OPA_Type* OPAx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		OPAx->CR |= (OPAx_CR_BUFOFF_EN_Msk);
	}
	else
	{
		OPAx->CR &= ~(OPAx_CR_BUFOFF_EN_Msk);
	}
}

FunState OPAx_CR_BUFOFF_EN_Getable(OPA_Type* OPAx)
{
	if (OPAx->CR & (OPAx_CR_BUFOFF_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* VREF BUFFER旁路控制 (VREF buffer bypass) 相关函数 */
void OPAx_CR_BUFBYP_Setable(OPA_Type* OPAx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		OPAx->CR |= (OPAx_CR_BUFBYP_Msk);
	}
	else
	{
		OPAx->CR &= ~(OPAx_CR_BUFBYP_Msk);
	}
}

FunState OPAx_CR_BUFBYP_Getable(OPA_Type* OPAx)
{
	if (OPAx->CR & (OPAx_CR_BUFBYP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* OPA负端输入选择 (OPA Negtive Input Select) 相关函数 */
void OPAx_CR_VNSEL_Set(OPA_Type* OPAx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = OPAx->CR;
	tmpreg &= ~(OPAx_CR_VNSEL_Msk);
	tmpreg |= (SetValue & OPAx_CR_VNSEL_Msk);
	OPAx->CR = tmpreg;
}

uint32_t OPAx_CR_VNSEL_Get(OPA_Type* OPAx)
{
	return (OPAx->CR & OPAx_CR_VNSEL_Msk);
}

/* OPA正端输入选择 (OPA Positive Input Select) 相关函数 */
void OPAx_CR_VPSEL_Set(OPA_Type* OPAx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = OPAx->CR;
	tmpreg &= ~(OPAx_CR_VPSEL_Msk);
	tmpreg |= (SetValue & OPAx_CR_VPSEL_Msk);
	OPAx->CR = tmpreg;
}

uint32_t OPAx_CR_VPSEL_Get(OPA_Type* OPAx)
{
	return (OPAx->CR & OPAx_CR_VPSEL_Msk);
}

/* OPA比较器模式输出数字滤波使能（仅OPA配置为比较器模式下有效） (OPA Comparator mode digital filter) 相关函数 */
void OPAx_CR_DF_Setable(OPA_Type* OPAx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		OPAx->CR |= (OPAx_CR_DF_Msk);
	}
	else
	{
		OPAx->CR &= ~(OPAx_CR_DF_Msk);
	}
}

FunState OPAx_CR_DF_Getable(OPA_Type* OPAx)
{
	if (OPAx->CR & (OPAx_CR_DF_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* OPA负端连接GPIO，仅OPAxMOD=10时有效
(OPA Negtive Input Connected to GPIO)
 相关函数 */
void OPAx_CR_VN_EXC_Setable(OPA_Type* OPAx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		OPAx->CR |= (OPAx_CR_VN_EXC_Msk);
	}
	else
	{
		OPAx->CR &= ~(OPAx_CR_VN_EXC_Msk);
	}
}

FunState OPAx_CR_VN_EXC_Getable(OPA_Type* OPAx)
{
	if (OPAx->CR & (OPAx_CR_VN_EXC_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* PGA增益选择 (PGA gain select) 相关函数 */
void OPAx_CR_PGA_GAIN_Set(OPA_Type* OPAx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = OPAx->CR;
	tmpreg &= ~(OPAx_CR_PGA_GAIN_Msk);
	tmpreg |= (SetValue & OPAx_CR_PGA_GAIN_Msk);
	OPAx->CR = tmpreg;
}

uint32_t OPAx_CR_PGA_GAIN_Get(OPA_Type* OPAx)
{
	return (OPAx->CR & OPAx_CR_PGA_GAIN_Msk);
}

/* OPA工作模式 (OPA mode) 相关函数 */
void OPAx_CR_MOD_Set(OPA_Type* OPAx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = OPAx->CR;
	tmpreg &= ~(OPAx_CR_MOD_Msk);
	tmpreg |= (SetValue & OPAx_CR_MOD_Msk);
	OPAx->CR = tmpreg;
}

uint32_t OPAx_CR_MOD_Get(OPA_Type* OPAx)
{
	return (OPAx->CR & OPAx_CR_MOD_Msk);
}

/* OPA低功耗控制寄存器 (OPA low power mode) 相关函数 */
void OPAx_CR_LPM_Set(OPA_Type* OPAx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = OPAx->CR;
	tmpreg &= ~(OPAx_CR_LPM_Msk);
	tmpreg |= (SetValue & OPAx_CR_LPM_Msk);
	OPAx->CR = tmpreg;
}

uint32_t OPAx_CR_LPM_Get(OPA_Type* OPAx)
{
	return (OPAx->CR & OPAx_CR_LPM_Msk);
}

/* OPA使能寄存器 (OPA enable) 相关函数 */
void OPAx_CR_EN_Setable(OPA_Type* OPAx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		OPAx->CR |= (OPAx_CR_EN_Msk);
	}
	else
	{
		OPAx->CR &= ~(OPAx_CR_EN_Msk);
	}
}

FunState OPAx_CR_EN_Getable(OPA_Type* OPAx)
{
	if (OPAx->CR & (OPAx_CR_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* OPA负端输入校准使能 相关函数 */
void OPAx_CALR_NCAL_EN_Setable(OPA_Type* OPAx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		OPAx->CALR |= (OPAx_CALR_NCAL_EN_Msk);
	}
	else
	{
		OPAx->CALR &= ~(OPAx_CALR_NCAL_EN_Msk);
	}
}

FunState OPAx_CALR_NCAL_EN_Getable(OPA_Type* OPAx)
{
	if (OPAx->CALR & (OPAx_CALR_NCAL_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* OPA负输入端校准trim信号，最高位为符号位 相关函数 */
void OPAx_CALR_NCAL_Set(OPA_Type* OPAx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = OPAx->CALR;
	tmpreg &= ~(OPAx_CALR_NCAL_Msk);
	tmpreg |= (SetValue & OPAx_CALR_NCAL_Msk);
	OPAx->CALR = tmpreg;
}

uint32_t OPAx_CALR_NCAL_Get(OPA_Type* OPAx)
{
	return (OPAx->CALR & OPAx_CALR_NCAL_Msk);
}

/* OPA正端输入校准使能 相关函数 */
void OPAx_CALR_PCAL_EN_Setable(OPA_Type* OPAx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		OPAx->CALR |= (OPAx_CALR_PCAL_EN_Msk);
	}
	else
	{
		OPAx->CALR &= ~(OPAx_CALR_PCAL_EN_Msk);
	}
}

FunState OPAx_CALR_PCAL_EN_Getable(OPA_Type* OPAx)
{
	if (OPAx->CALR & (OPAx_CALR_PCAL_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* OPA正输入端校准trim信号，最高位为符号位 相关函数 */
void OPAx_CALR_PCAL_Set(OPA_Type* OPAx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = OPAx->CALR;
	tmpreg &= ~(OPAx_CALR_PCAL_Msk);
	tmpreg |= (SetValue & OPAx_CALR_PCAL_Msk);
	OPAx->CALR = tmpreg;
}

uint32_t OPAx_CALR_PCAL_Get(OPA_Type* OPAx)
{
	return (OPAx->CALR & OPAx_CALR_PCAL_Msk);
}

/* OPA比较器模式输出下降沿中断使能
(OPA comparator mode fall interrupt enable)
 相关函数 */
void OPAx_IER_FIE_Setable(OPA_Type* OPAx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		OPAx->IER |= (OPAx_IER_FIE_Msk);
	}
	else
	{
		OPAx->IER &= ~(OPAx_IER_FIE_Msk);
	}
}

FunState OPAx_IER_FIE_Getable(OPA_Type* OPAx)
{
	if (OPAx->IER & (OPAx_IER_FIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* OPA比较器模式输出上升沿中断使能
(OPA comparator mode rise interrupt enable)
 相关函数 */
void OPAx_IER_RIE_Setable(OPA_Type* OPAx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		OPAx->IER |= (OPAx_IER_RIE_Msk);
	}
	else
	{
		OPAx->IER &= ~(OPAx_IER_RIE_Msk);
	}
}

FunState OPAx_IER_RIE_Getable(OPA_Type* OPAx)
{
	if (OPAx->IER & (OPAx_IER_RIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* OPA比较器模式输出电平，只读 
(OPA comparator mode output)
 相关函数 */
FlagStatus OPAx_ISR_OUT_Chk(OPA_Type* OPAx)
{
	if (OPAx->ISR & OPAx_ISR_OUT_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* OPA比较器模式输出下降沿中断标志，硬件置位，软件写1清零 (OPA comparator mode fall interrupt flag) 相关函数 */
void OPAx_ISR_FIF_Clr(OPA_Type* OPAx)
{
	OPAx->ISR = OPAx_ISR_FIF_Msk;
}

FlagStatus OPAx_ISR_FIF_Chk(OPA_Type* OPAx)
{
	if (OPAx->ISR & OPAx_ISR_FIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* OPA比较器模式输出上升沿中断标志，硬件置位，软件写1清零 (OPA comparator mode rise interrupt flag) 相关函数 */
void OPAx_ISR_RIF_Clr(OPA_Type* OPAx)
{
	OPAx->ISR = OPAx_ISR_RIF_Msk;
}

FlagStatus OPAx_ISR_RIF_Chk(OPA_Type* OPAx)
{
	if (OPAx->ISR & OPAx_ISR_RIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}


void OPAx_Deinit(void)
{
   RCC_PRST_EN_Write(RSTKEY0);
   RCC_APBRST_CR2_OPARST_Setable(ENABLE); 
   RCC_APBRST_CR2_OPARST_Setable(DISABLE);
   RCC_PRST_EN_Write(RSTKEY1);
}
/******END OF FILE****/
