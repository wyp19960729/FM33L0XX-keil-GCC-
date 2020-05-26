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
  
/* LDO低功耗模式配置 (LDO Low Power Mode) 相关函数 */
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

/* LDO15使能状态，只读 相关函数 */
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

/* Sleep/DeepSleep唤醒后的系统频率 (Wakeup Frequency Select) 相关函数 */
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

/* DeepSleep控制寄 相关函数 */
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

/* 低功耗模式内核电压降低0：低功耗模式下不使能内核电压调整1：低功耗模式下降低内核电压 在Sleep下，如果置位了SLPDP位即为DeepSleep模式；该位仅在Sleep下有效 相关函数 */
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

/* 低功耗模式配置寄存器 (Power Mode) 相关函数 */
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

/* 唤醒时间控制寄存器 相关函数 */
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

/* ADC中断唤醒标志 相关函数 */
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

/* RTC中断唤醒标志 相关函数 */
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

/* SVD中断唤醒标志 相关函数 */
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

/* SVD中断唤醒标志 相关函数 */
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

/* VREF1P22基准源建立中断唤醒标志 相关函数 */
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

/* IO中断唤醒标志 相关函数 */
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

/* I2C中断唤醒标志 相关函数 */
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

/* LPUART1中断唤醒标志 相关函数 */
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

/* LPUART0中断唤醒标志 相关函数 */
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

/* UART1中断唤醒标志 相关函数 */
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

/* UART0中断唤醒标志 相关函数 */
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

/* OPA2（比较器模式）中断唤醒标志 相关函数 */
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

/* OPA1（比较器模式）中断唤醒标志 相关函数 */
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

/* LPTIM32中断唤醒标志 相关函数 */
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

/* BSTIM32中断唤醒标志 相关函数 */
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

/* CPU Debugger唤醒标志 相关函数 */
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

/* NWKUP7 Pin唤醒标志 相关函数 */
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

/* NWKUP6 Pin唤醒标志 相关函数 */
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

/* NWKUP5 Pin唤醒标志 相关函数 */
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

/* NWKUP4 Pin唤醒标志 相关函数 */
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

/* NWKUP3 Pin唤醒标志 相关函数 */
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

/* NWKUP2 Pin唤醒标志 相关函数 */
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

/* NWKUP1 Pin唤醒标志 相关函数 */
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

/* NWKUP0 Pin唤醒标志 相关函数 */
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

/* LPACTIVE错误中断使能0：禁止LPACTIVE错误中断1：使能LPACTIVE错误中断 相关函数 */
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

/* SLEEP错误中断使能0：禁止SLEEP错误中断1：使能SLEEP错误中断 相关函数 */
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

/* LPACTIVE错误中断标志，硬件置位，软件写1清零 相关函数 */
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

/* SLEEP错误中断标志，硬件置位，软件写1清零 相关函数 */
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

/* VREF1p2使能寄存器 (VREF Enable)  0：关闭VREF1p2   1：使能VREF1p2 相关函数 */
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

/* 模拟输出的VREF1p22寄存器电压建立标志 (VREF stable Flag from analog) 相关函数 */
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

/* VREF1p22基准电压建立标志 (VREF Ready) 相关函数 */
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

/* VREF1p22基准电压建立中断 (VREF Ready Flag) 相关函数 */
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

/* VREF1p2基准电压建立中断使能 (VREF Ready Interrupt Enable) 0：禁止产生VREF建立完成中断 1：允许产生VREF建立完成中断 相关函数 */
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

/* 控制bandgap输出ptat电压(PTAT VREF Enable) 0：Vptat 不使能 1：Vptat 使能 相关函数 */
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

/* Vptat Buffer模块开关通道输出使能信号，高电平使能有效。(PTAT Buffer Output Enable) 0：Vptat buffer 模块输出不使能 1：Vptat buffer 模块输出使能 相关函数 */
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

/* Vptat Buffer模块使能信号，高电平使能有效。(PTAT Buffer Enable) 0：Vptat buffer 模块不使能 1：Vptat buffer 模块使能 相关函数 */
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

/* Vref Buffer模块开关通道输出使能信号，高电平使能有效。(VREF Buffer Output Enable) 0：Vref buffer 模块输出不使能 1：Vref buffer 模块输出使能 相关函数 */
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

/* Vref Buffer模块使能信号，高电平使能有效。(VREF Buffer Enable) 0：Vref buffer 模块不使能  1：Vref buffer 模块使能 相关函数 */
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
低功耗模式的初始化函数
功能:低功耗模式下各种设置，SLEEP模式，RAM保持设置，内核电压，晶振电路等。
输入：低功耗功能开启前的设置.
 ********************************/
void PMU_SleepCfg_Init(PMU_SleepCfg_InitTypeDef* SleepCfg_InitStruct)
{
	PMU_CR_SLPDP_Set(SleepCfg_InitStruct->SLPDP);				/*!<DeepSleep控制寄存器  */	
	PMU_CR_CVS_Setable(SleepCfg_InitStruct->CVS);				/*!<内核电压降低使能控制  */	
	PMU_CR_WKFSEL_Set(SleepCfg_InitStruct->WKFSEL);			/*!<Sleep/DeepSleep唤醒后的系统频率  */	
	SCB->SCR = SleepCfg_InitStruct->SCR;							/*!<M0系统控制寄存器，一般配置为0即可  */
	PMU_CR_PMOD_Set(SleepCfg_InitStruct->PMOD);					/*!<低功耗模式配置  */	
	PMU_CR_LDO_LPM_Set(SleepCfg_InitStruct->LDO_LPM);			/*!LDO低功耗模式配置00/01/11：正常模式10：LDO进入低功耗模式*/
}



/******END OF FILE****/
