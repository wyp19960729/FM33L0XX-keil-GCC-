/**
  ******************************************************************************
  * @file    fm33l0xx_bstim.c
  * @author  FM33L0 Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33l0xx_bstim.h" 
#include "fm33l0xx_rcc.h" 

/** @addtogroup fm33l0_StdPeriph_Driver
  * @{
  */

/** @defgroup BSTIM 
  * @brief BSTIM driver modules
  * @{
  */ 
  
/* Auto-reload预装载使能 相关函数 */
void BSTIM_CR1_ARPE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		BSTIM->CR1 |= (BSTIM_CR1_ARPE_Msk);
	}
	else
	{
		BSTIM->CR1 &= ~(BSTIM_CR1_ARPE_Msk);
	}
}

FunState BSTIM_CR1_ARPE_Getable(void)
{
	if (BSTIM->CR1 & (BSTIM_CR1_ARPE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 单脉冲输出模式 (One Pulse Mode) 相关函数 */
void BSTIM_CR1_OPM_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BSTIM->CR1;
	tmpreg &= ~(BSTIM_CR1_OPM_Msk);
	tmpreg |= (SetValue & BSTIM_CR1_OPM_Msk);
	BSTIM->CR1 = tmpreg;
}

uint32_t BSTIM_CR1_OPM_Get(void)
{
	return (BSTIM->CR1 & BSTIM_CR1_OPM_Msk);
}

/* 更新请求选择 (Update Request Select) 相关函数 */
void BSTIM_CR1_URS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BSTIM->CR1;
	tmpreg &= ~(BSTIM_CR1_URS_Msk);
	tmpreg |= (SetValue & BSTIM_CR1_URS_Msk);
	BSTIM->CR1 = tmpreg;
}

uint32_t BSTIM_CR1_URS_Get(void)
{
	return (BSTIM->CR1 & BSTIM_CR1_URS_Msk);
}

/* 禁止update (Update Disable) 相关函数 */
void BSTIM_CR1_UDIS_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		BSTIM->CR1 |= (BSTIM_CR1_UDIS_Msk);
	}
	else
	{
		BSTIM->CR1 &= ~(BSTIM_CR1_UDIS_Msk);
	}
}

FunState BSTIM_CR1_UDIS_Getable(void)
{
	if (BSTIM->CR1 & (BSTIM_CR1_UDIS_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 计数器使能 (Counter Enable) 相关函数 */
void BSTIM_CR1_CEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		BSTIM->CR1 |= (BSTIM_CR1_CEN_Msk);
	}
	else
	{
		BSTIM->CR1 &= ~(BSTIM_CR1_CEN_Msk);
	}
}

FunState BSTIM_CR1_CEN_Getable(void)
{
	if (BSTIM->CR1 & (BSTIM_CR1_CEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 主机模式选择，用于配置主机模式下向从机发送的同步触发信号（TRGO）源 (Master Mode Select) 相关函数 */
void BSTIM_CR2_MMS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BSTIM->CR2;
	tmpreg &= ~(BSTIM_CR2_MMS_Msk);
	tmpreg |= (SetValue & BSTIM_CR2_MMS_Msk);
	BSTIM->CR2 = tmpreg;
}

uint32_t BSTIM_CR2_MMS_Get(void)
{
	return (BSTIM->CR2 & BSTIM_CR2_MMS_Msk);
}

/* Update事件中断使能 (Update event Interrupt Enable) 相关函数 */
void BSTIM_IER_UIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		BSTIM->IER |= (BSTIM_IER_UIE_Msk);
	}
	else
	{
		BSTIM->IER &= ~(BSTIM_IER_UIE_Msk);
	}
}

FunState BSTIM_IER_UIE_Getable(void)
{
	if (BSTIM->IER & (BSTIM_IER_UIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Update事件中断标志，硬件置位，软件写1清零。(Update event Interrupt Flag)
当以下事件发生时，UIF置位，并更新shadow寄存器 相关函数 */
void BSTIM_ISR_UIF_Clr(void)
{
	BSTIM->ISR = BSTIM_ISR_UIF_Msk;
}

FlagStatus BSTIM_ISR_UIF_Chk(void)
{
	if (BSTIM->ISR & BSTIM_ISR_UIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 软件Update事件，软件置位此寄存器产生Update事件，硬件自动清零 (User Generate) 相关函数 */
void BSTIM_EGR_UG_Clr(void)
{
	BSTIM->EGR = BSTIM_EGR_UG_Msk;
}

/* 计数器值 (Counter) 相关函数 */
void BSTIM_CNT_Write(uint32_t SetValue)
{
	BSTIM->CNT = (SetValue);
}

uint32_t BSTIM_CNT_Read(void)
{
	return (BSTIM->CNT);
}

/* 计数器时钟（CK_CNT）预分频值 (Counter Clock Prescaler) 相关函数 */
void BSTIM_PSC_Write(uint32_t SetValue)
{
	BSTIM->PSC = (SetValue);
}

uint32_t BSTIM_PSC_Read(void)
{
	return (BSTIM->PSC);
}

/* 计数溢出时的自动重载值 (Auto-Reload Register) 相关函数 */
void BSTIM_ARR_Write(uint32_t SetValue)
{
	BSTIM->ARR = (SetValue);
}

uint32_t BSTIM_ARR_Read(void)
{
	return (BSTIM->ARR);
}


void BSTIM_Deinit(void)
{
  RCC_PRST_EN_Write(RSTKEY0);
  RCC_APBRST_CR2_BTRST_Setable(ENABLE);  
  RCC_APBRST_CR2_BTRST_Setable(DISABLE);
  RCC_PRST_EN_Write(RSTKEY1);
} 
/******END OF FILE****/
