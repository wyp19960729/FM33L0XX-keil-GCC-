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
  
 /* ETR输入模拟滤波使能 (External Trigger input Analog Filter Enable) 相关函数 */
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

/* 时钟预分频输入选择 (Prescaler input Select) 相关函数 */
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

/* ETR输入源选择 (External Trigger input source Select) 相关函数 */
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

/* 计数时钟分频选择 (Counter Clock Divider Select) 相关函数 */
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

/* ETR输入边沿选择 (ETR Clock Edge Select) 相关函数 */
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

/* 外部触发边沿选择（需使用内部时钟同步采样LPT_ETR）(ETR trigger Configuration) 相关函数 */
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

/* 单次计数模式使能 (One State Timer) 相关函数 */
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

/* 工作模式选择 (Timer operation Mode) 相关函数 */
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

/* 32bit计数器当前计数值 (Counter 32bits-wide) 相关函数 */
void LPTIM_CNT_Write(uint32_t SetValue)
{
	LPTIM->CNT = (SetValue);
}

uint32_t LPTIM_CNT_Read(void)
{
	return (LPTIM->CNT);
}

/* 通道1捕捉信号源选择 (Channel 1 Capture Source Select) 相关函数 */
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

/* 通道2当前被捕捉的边沿，在CC2IF置位时更新 (Channel2 Captured Edge) 相关函数 */
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

/* 通道1当前被捕捉的边沿，在CC1IF置位时更新 (Channel 1 Captured Edge) 相关函数 */
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

/* 通道2捕捉边沿选择 (Channel 2 Capture edge Config) 相关函数 */
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

/* 通道1捕捉边沿选择 (Channel 1 Capture edge Config) 相关函数 */
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

/* 通道2比较输出波形极性选择 (Channel 2 compare output Polarity) 相关函数 */
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

/* 通道1比较输出波形极性选择 (Channel 1 compare output Polarity) 相关函数 */
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

/* 通道2捕捉/比较功能使能 (Channel 2 Capture/Compare Select) 相关函数 */
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

/* 通道1捕捉/比较功能使能 (Channel 1 Capture/Compare Select) 相关函数 */
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

/* 自动重载目标寄存器 (Auto-Reload Register) 相关函数 */
void LPTIM_ARR_Write(uint32_t SetValue)
{
	LPTIM->ARR = (SetValue);
}

uint32_t LPTIM_ARR_Read(void)
{
	return (LPTIM->ARR);
}

/* 通道2捕捉溢出中断使能 (Channel 2 Over-Capture Interrupt Enable) 相关函数 */
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

/* 通道1捕捉溢出中断使能 (Channel 1 Over-Capture Interrupt Enable) 相关函数 */
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

/* 外部触发到来中断使能位 (External Trigger Interrupt Enable) 相关函数 */
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

/* 计数器溢出中断使能位 (Counter Over-Flow Interrupt Enable) 相关函数 */
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

/* 捕捉/比较通道2中断使能位 (Capture/Compare channel 2 Interrupt Enable) 相关函数 */
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

/* 捕捉/比较通道1中断使能位 (Capture/Compare channel 1 Interrupt Enable) 相关函数 */
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

/* 通道2捕捉溢出，硬件置位，软件写1清零 (Channel 2 Over-Capture Interrupt Flag) 相关函数 */
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

/* 通道1捕捉溢出，硬件置位，软件写1清零 (Channel 1 Over-Capture Interrupt Flag) 相关函数 */
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

/* 外部触发到来中断标志位，写1清零 (External Trigger Interrupt Flag) 相关函数 */
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

/* 计数器溢出中断使能位，写1清零 (Counter Over-Flow Interrupt Flag) 相关函数 */
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

/* 捕捉/比较通道2中断标志，硬件置位，软件写1清零 (Capture/Compare channel 2 Interrupt Flag) 相关函数 */
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

/* 捕捉/比较通道1中断标志，硬件置位，软件写1清零 (Capture/Compare channel 1 Interrupt Flag) 相关函数 */
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

/* LPTIM使能位 (LPTIM Enable) 相关函数 */
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

/* 捕捉/比较值寄存器1 (Channel1 Capture/Compare Register) 相关函数 */
void LPTIM_CCR1_Write(uint32_t SetValue)
{
	LPTIM->CCR1 = (SetValue);
}

uint32_t LPTIM_CCR1_Read(void)
{
	return (LPTIM->CCR1);
}

/* 捕捉/比较值寄存器2 (Channel2 Capture/Compare Register) 相关函数 */
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
