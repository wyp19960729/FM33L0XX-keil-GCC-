/**
  ******************************************************************************
  * @file    fm33l0xx_rcc.c
  * @author  FM33L0 Application Team
  * @version V0.1.1
  * @date    6-Dec-2019
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33l0xx_rcc.h" 


/** @addtogroup fm33l0_StdPeriph_Driver
  * @{
  */

/** @defgroup RCC 
  * @brief RCC driver modules
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup RCC_Private_Functions
  * @{
  */

void RCC_LKP_CR_RST_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RCC->LKP_CR |= (RCC_LKP_CR_RST_EN_Msk);
	}
	else
	{
		RCC->LKP_CR &= ~(RCC_LKP_CR_RST_EN_Msk);
	}
}

FunState RCC_LKP_CR_RST_EN_Getable(void)
{
	if (RCC->LKP_CR & (RCC_LKP_CR_RST_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

void RCC_SOFTRST_Write(uint32_t SetValue)
{
	RCC->SOFTRST = (SetValue);
}

void RCC_RSTFR_NRSTN_FLAG_Clr(void)
{
	RCC->RSTFR = RCC_RSTFR_NRSTN_FLAG_Msk;
}

FlagStatus RCC_RSTFR_NRSTN_FLAG_Chk(void)
{
	if (RCC->RSTFR & RCC_RSTFR_NRSTN_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void RCC_RSTFR_TESTN_FLAG_Clr(void)
{
	RCC->RSTFR = RCC_RSTFR_TESTN_FLAG_Msk;
}

FlagStatus RCC_RSTFR_TESTN_FLAG_Chk(void)
{
	if (RCC->RSTFR & RCC_RSTFR_TESTN_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void RCC_RSTFR_PORN_FLAG_Clr(void)
{
	RCC->RSTFR = RCC_RSTFR_PORN_FLAG_Msk;
}

FlagStatus RCC_RSTFR_PORN_FLAG_Chk(void)
{
	if (RCC->RSTFR & RCC_RSTFR_PORN_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void RCC_RSTFR_PDRN_FLAG_Clr(void)
{
	RCC->RSTFR = RCC_RSTFR_PDRN_FLAG_Msk;
}

FlagStatus RCC_RSTFR_PDRN_FLAG_Chk(void)
{
	if (RCC->RSTFR & RCC_RSTFR_PDRN_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void RCC_RSTFR_SOFTN_FLAG_Clr(void)
{
	RCC->RSTFR = RCC_RSTFR_SOFTN_FLAG_Msk;
}

FlagStatus RCC_RSTFR_SOFTN_FLAG_Chk(void)
{
	if (RCC->RSTFR & RCC_RSTFR_SOFTN_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void RCC_RSTFR_IWDTN_FLAG_Clr(void)
{
	RCC->RSTFR = RCC_RSTFR_IWDTN_FLAG_Msk;
}

FlagStatus RCC_RSTFR_IWDTN_FLAG_Chk(void)
{
	if (RCC->RSTFR & RCC_RSTFR_IWDTN_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void RCC_RSTFR_WWDTN_FLAG_Clr(void)
{
	RCC->RSTFR = RCC_RSTFR_WWDTN_FLAG_Msk;
}

FlagStatus RCC_RSTFR_WWDTN_FLAG_Chk(void)
{
	if (RCC->RSTFR & RCC_RSTFR_WWDTN_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void RCC_RSTFR_LKUPN_FLAG_Clr(void)
{
	RCC->RSTFR = RCC_RSTFR_LKUPN_FLAG_Msk;
}

FlagStatus RCC_RSTFR_LKUPN_FLAG_Chk(void)
{
	if (RCC->RSTFR & RCC_RSTFR_LKUPN_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void RCC_RSTFR_NVICN_FLAG_Clr(void)
{
	RCC->RSTFR = RCC_RSTFR_NVICN_FLAG_Msk;
}

FlagStatus RCC_RSTFR_NVICN_FLAG_Chk(void)
{
	if (RCC->RSTFR & RCC_RSTFR_NVICN_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* LSCLK自动切换使能 相关函数 */
void RCC_SYSCLK_CR_LSCATS_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RCC->SYSCLK_CR |= (RCC_SYSCLK_CR_LSCATS_Msk);
	}
	else
	{
		RCC->SYSCLK_CR &= ~(RCC_SYSCLK_CR_LSCATS_Msk);
	}
}

FunState RCC_SYSCLK_CR_LSCATS_Getable(void)
{
	if (RCC->SYSCLK_CR & (RCC_SYSCLK_CR_LSCATS_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Sleep/DeepSleep模式下EXTI采样设置 相关函数 */
void RCC_SYSCLK_CR_SLP_ENEXTI_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RCC->SYSCLK_CR |= (RCC_SYSCLK_CR_SLP_ENEXTI_Msk);
	}
	else
	{
		RCC->SYSCLK_CR &= ~(RCC_SYSCLK_CR_SLP_ENEXTI_Msk);
	}
}

FunState RCC_SYSCLK_CR_SLP_ENEXTI_Getable(void)
{
	if (RCC->SYSCLK_CR & (RCC_SYSCLK_CR_SLP_ENEXTI_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* APB时钟分频选择 相关函数 */
void RCC_SYSCLK_CR_APBPRES_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RCC->SYSCLK_CR;
	tmpreg &= ~(RCC_SYSCLK_CR_APBPRES_Msk);
	tmpreg |= (SetValue & RCC_SYSCLK_CR_APBPRES_Msk);
	RCC->SYSCLK_CR = tmpreg;
}

uint32_t RCC_SYSCLK_CR_APBPRES_Get(void)
{
	return (RCC->SYSCLK_CR & RCC_SYSCLK_CR_APBPRES_Msk);
}

/* AHB时钟分频选择 相关函数 */
void RCC_SYSCLK_CR_AHBPRES_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RCC->SYSCLK_CR;
	tmpreg &= ~(RCC_SYSCLK_CR_AHBPRES_Msk);
	tmpreg |= (SetValue & RCC_SYSCLK_CR_AHBPRES_Msk);
	RCC->SYSCLK_CR = tmpreg;
}

uint32_t RCC_SYSCLK_CR_AHBPRES_Get(void)
{
	return (RCC->SYSCLK_CR & RCC_SYSCLK_CR_AHBPRES_Msk);
}

/* CPU内核systick工作时钟选择 相关函数 */
void RCC_SYSCLK_CR_STCLKSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RCC->SYSCLK_CR;
	tmpreg &= ~(RCC_SYSCLK_CR_STCLKSEL_Msk);
	tmpreg |= (SetValue & RCC_SYSCLK_CR_STCLKSEL_Msk);
	RCC->SYSCLK_CR = tmpreg;
}

uint32_t RCC_SYSCLK_CR_STCLKSEL_Get(void)
{
	return (RCC->SYSCLK_CR & RCC_SYSCLK_CR_STCLKSEL_Msk);
}

/* 系统时钟源选择 相关函数 */
void RCC_SYSCLK_CR_SYSCLKSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RCC->SYSCLK_CR;
	tmpreg &= ~(RCC_SYSCLK_CR_SYSCLKSEL_Msk);
	tmpreg |= (SetValue & RCC_SYSCLK_CR_SYSCLKSEL_Msk);
	RCC->SYSCLK_CR = tmpreg;
}

uint32_t RCC_SYSCLK_CR_SYSCLKSEL_Get(void)
{
	return (RCC->SYSCLK_CR & RCC_SYSCLK_CR_SYSCLKSEL_Msk);
}

/* RCHF频率选择寄存器 相关函数 */
void RCC_RCHF_CR_FSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RCC->RCHF_CR;
	tmpreg &= ~(RCC_RCHF_CR_FSEL_Msk);
	tmpreg |= (SetValue & RCC_RCHF_CR_FSEL_Msk);
	RCC->RCHF_CR = tmpreg;
}

uint32_t RCC_RCHF_CR_FSEL_Get(void)
{
	return (RCC->RCHF_CR & RCC_RCHF_CR_FSEL_Msk);
}

/* RCHF使能寄存器 相关函数 */
void RCC_RCHF_CR_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RCC->RCHF_CR |= (RCC_RCHF_CR_EN_Msk);
	}
	else
	{
		RCC->RCHF_CR &= ~(RCC_RCHF_CR_EN_Msk);
	}
}

FunState RCC_RCHF_CR_EN_Getable(void)
{
	if (RCC->RCHF_CR & (RCC_RCHF_CR_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* RC4M频率调校寄存器 相关函数 */
void RCC_RC4M_TR_Write(uint32_t SetValue)
{
	RCC->RC4M_TR = (SetValue & RCC_RC4M_TR_TRIM_Msk);
}

uint32_t RCC_RC4M_TR_Read(void)
{
	return (RCC->RC4M_TR & RCC_RC4M_TR_TRIM_Msk);
}

/* PLL倍频比 相关函数 */
void RCC_PLL_CR_DB_Set(uint32_t SetValue)
{ 
  uint32_t tmpreg;
  SetValue <<= RCC_PLL_CR_DB_Pos;
	tmpreg = RCC->PLL_CR;
	tmpreg &= ~(RCC_PLL_CR_DB_Msk);
	tmpreg |= (SetValue & RCC_PLL_CR_DB_Msk);
	RCC->PLL_CR = tmpreg;
}

uint32_t RCC_PLL_CR_DB_Get(void)
{
	uint32_t tmpreg;
	
	tmpreg= (RCC->PLL_CR & RCC_PLL_CR_DB_Msk);
	return (tmpreg >> RCC_PLL_CR_DB_Pos);
}

/* PLL锁定标志 相关函数 */
FlagStatus RCC_PLL_CR_LOCKED_Chk(void)
{
	if (RCC->PLL_CR & RCC_PLL_CR_LOCKED_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* PLL参考时钟预分频（目标是产生1MHz参考时钟给PLL） 相关函数 */
void RCC_PLL_CR_REFPRSC_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RCC->PLL_CR;
	tmpreg &= ~(RCC_PLL_CR_REFPRSC_Msk);
	tmpreg |= (SetValue & RCC_PLL_CR_REFPRSC_Msk);
	RCC->PLL_CR = tmpreg;
}

uint32_t RCC_PLL_CR_REFPRSC_Get(void)
{
	return (RCC->PLL_CR & RCC_PLL_CR_REFPRSC_Msk);
}

/* PLL输出选择寄存器 相关函数 */
void RCC_PLL_CR_OSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RCC->PLL_CR;
	tmpreg &= ~(RCC_PLL_CR_OSEL_Msk);
	tmpreg |= (SetValue & RCC_PLL_CR_OSEL_Msk);
	RCC->PLL_CR = tmpreg;
}

uint32_t RCC_PLL_CR_OSEL_Get(void)
{
	return (RCC->PLL_CR & RCC_PLL_CR_OSEL_Msk);
}

/* PLL输入选择寄存器 相关函数 */
void RCC_PLL_CR_INSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RCC->PLL_CR;
	tmpreg &= ~(RCC_PLL_CR_INSEL_Msk);
	tmpreg |= (SetValue & RCC_PLL_CR_INSEL_Msk);
	RCC->PLL_CR = tmpreg;
}

uint32_t RCC_PLL_CR_INSEL_Get(void)
{
	return (RCC->PLL_CR & RCC_PLL_CR_INSEL_Msk);
}

/* PLL使能寄存器 相关函数 */
void RCC_PLL_CR_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RCC->PLL_CR |= (RCC_PLL_CR_EN_Msk);
	}
	else
	{
		RCC->PLL_CR &= ~(RCC_PLL_CR_EN_Msk);
	}
}

FunState RCC_PLL_CR_EN_Getable(void)
{
	if (RCC->PLL_CR & (RCC_PLL_CR_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* RCLP使能标志信号 相关函数 */
FlagStatus RCC_RCLP_CR_OFF_EN_Chk(void)
{
	if (RCC->RCLP_CR & RCC_RCLP_CR_OFF_EN_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 休眠模式下RCLP控制寄存器 相关函数 */
void RCC_RCLP_CR_LPM_RCLP_OFF_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RCC->RCLP_CR |= (RCC_RCLP_CR_LPM_RCLP_OFF_Msk);
	}
	else
	{
		RCC->RCLP_CR &= ~(RCC_RCLP_CR_LPM_RCLP_OFF_Msk);
	}
}

FunState RCC_RCLP_CR_LPM_RCLP_OFF_Getable(void)
{
	if (RCC->RCLP_CR & (RCC_RCLP_CR_LPM_RCLP_OFF_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* RCLP调校值寄存器 相关函数 */
void RCC_RCLP_TR_Write(uint32_t SetValue)
{
	RCC->RCLP_TR = (SetValue & RCC_RCLP_TR_TRIM_Msk);
}

uint32_t RCC_RCLP_TR_Read(void)
{
	return (RCC->RCLP_TR & RCC_RCLP_TR_TRIM_Msk);
}

/* XTLF备份时钟手动切换寄存器 相关函数 */
void RCC_XTLF_CR_Write(uint32_t SetValue)
{
	RCC->XTLF_CR = (SetValue & RCC_XTLF_CR_BKSW_Msk);
}

uint32_t RCC_XTLF_CR_Read(void)
{
	return (RCC->XTLF_CR & RCC_XTLF_CR_BKSW_Msk);
}

/* XTLF使能寄存器 相关函数 */
void RCC_XTLF_CR_EN_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RCC->XTLF_CR;
	tmpreg &= ~(RCC_XTLF_CR_EN_Msk);
	tmpreg |= (SetValue & RCC_XTLF_CR_EN_Msk);
	RCC->XTLF_CR = tmpreg;
}

uint32_t RCC_XTLF_CR_EN_Get(void)
{
	return (RCC->XTLF_CR & RCC_XTLF_CR_EN_Msk);
}

/* XTLF工作电流选择 相关函数 */
void RCC_XTLF_CR_IPW_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RCC->XTLF_CR;
	tmpreg &= ~(RCC_XTLF_CR_IPW_Msk);
	tmpreg |= (SetValue & RCC_XTLF_CR_IPW_Msk);
	RCC->XTLF_CR = tmpreg;
}

uint32_t RCC_XTLF_CR_IPW_Get(void)
{
	return (RCC->XTLF_CR & RCC_XTLF_CR_IPW_Msk);
}

/* AHB Master优先级配置寄存器 相关函数 */
void RCC_AHBM_CR_MPRIL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RCC->AHBM_CR;
	tmpreg &= ~(RCC_AHBM_CR_MPRIL_Msk);
	tmpreg |= (SetValue & RCC_AHBM_CR_MPRIL_Msk);
	RCC->AHBM_CR = tmpreg;
}

uint32_t RCC_AHBM_CR_MPRIL_Get(void)
{
	return (RCC->AHBM_CR & RCC_AHBM_CR_MPRIL_Msk);
}

/* 外设模块复位使能 相关函数 */
void RCC_PRST_EN_Write(uint32_t SetValue)
{
	RCC->PRST_EN = (SetValue);
}

uint32_t RCC_PRST_EN_Read(void)
{
	return (RCC->PRST_EN);
}

/* DMA模块复位 相关函数 */
void RCC_AHBRST_CR_DMARST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
    RCC->AHBRST_CR |= (RCC_AHBRST_CR_DMARST_Msk);
	}
	else
	{
		RCC->AHBRST_CR &= ~(RCC_AHBRST_CR_DMARST_Msk);
	}
}

FunState RCC_AHBRST_CR_DMARST_Getable(void)
{
	if (RCC->AHBRST_CR & (RCC_AHBRST_CR_DMARST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* UART5模块复位 相关函数 */
void RCC_APBRST_CR1_UART5RST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
    RCC->APBRST_CR1 |= (RCC_APBRST_CR1_UART5RST_Msk);
	}
	else
	{
		RCC->APBRST_CR1 &= ~(RCC_APBRST_CR1_UART5RST_Msk);
	}
}

FunState RCC_APBRST_CR1_UART5RST_Getable(void)
{
	if (RCC->APBRST_CR1 & (RCC_APBRST_CR1_UART5RST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* UART4模块复位 相关函数 */
void RCC_APBRST_CR1_UART4RST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
    RCC->APBRST_CR1 |= (RCC_APBRST_CR1_UART4RST_Msk);
	}
	else
	{
		RCC->APBRST_CR1 &= ~(RCC_APBRST_CR1_UART4RST_Msk);
	}
}

FunState RCC_APBRST_CR1_UART4RST_Getable(void)
{
	if (RCC->APBRST_CR1 & (RCC_APBRST_CR1_UART4RST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* GPTIM1模块复位 相关函数 */
void RCC_APBRST_CR1_GT1RST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
    RCC->APBRST_CR1 |= (RCC_APBRST_CR1_GT1RST_Msk);
	}
	else
	{
		RCC->APBRST_CR1 &= ~(RCC_APBRST_CR1_GT1RST_Msk);
	}
}

FunState RCC_APBRST_CR1_GT1RST_Getable(void)
{
	if (RCC->APBRST_CR1 & (RCC_APBRST_CR1_GT1RST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* GPTIM0模块复位 相关函数 */
void RCC_APBRST_CR1_GT0RST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
    RCC->APBRST_CR1 |= (RCC_APBRST_CR1_GT0RST_Msk);
	}
	else
	{
		RCC->APBRST_CR1 &= ~(RCC_APBRST_CR1_GT0RST_Msk);
	}
}

FunState RCC_APBRST_CR1_GT0RST_Getable(void)
{
	if (RCC->APBRST_CR1 & (RCC_APBRST_CR1_GT0RST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* LCD模块复位 相关函数 */
void RCC_APBRST_CR1_LCDRST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
    RCC->APBRST_CR1 |= (RCC_APBRST_CR1_LCDRST_Msk);
	}
	else
	{
		RCC->APBRST_CR1 &= ~(RCC_APBRST_CR1_LCDRST_Msk);
	}
}

FunState RCC_APBRST_CR1_LCDRST_Getable(void)
{
	if (RCC->APBRST_CR1 & (RCC_APBRST_CR1_LCDRST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* U7816模块复位 相关函数 */
void RCC_APBRST_CR1_U7816RST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
    RCC->APBRST_CR1 |= (RCC_APBRST_CR1_U7816RST_Msk);
	}
	else
	{
		RCC->APBRST_CR1 &= ~(RCC_APBRST_CR1_U7816RST_Msk);
	}
}

FunState RCC_APBRST_CR1_U7816RST_Getable(void)
{
	if (RCC->APBRST_CR1 & (RCC_APBRST_CR1_U7816RST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SPI2模块复位 相关函数 */
void RCC_APBRST_CR1_SPI2RST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
    RCC->APBRST_CR1 |= (RCC_APBRST_CR1_SPI2RST_Msk);
	}
	else
	{
		RCC->APBRST_CR1 &= ~(RCC_APBRST_CR1_SPI2RST_Msk);
	}
}

FunState RCC_APBRST_CR1_SPI2RST_Getable(void)
{
	if (RCC->APBRST_CR1 & (RCC_APBRST_CR1_SPI2RST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* LPUART0模块复位 相关函数 */
void RCC_APBRST_CR1_LPUART0RST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
    RCC->APBRST_CR1 |= (RCC_APBRST_CR1_LPUART0RST_Msk);
	}
	else
	{
		RCC->APBRST_CR1 &= ~(RCC_APBRST_CR1_LPUART0RST_Msk);
	}
}

FunState RCC_APBRST_CR1_LPUART0RST_Getable(void)
{
	if (RCC->APBRST_CR1 & (RCC_APBRST_CR1_LPUART0RST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* I2C模块复位 相关函数 */
void RCC_APBRST_CR1_I2CRST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
    RCC->APBRST_CR1 |= (RCC_APBRST_CR1_I2CRST_Msk);
	}
	else
	{
		RCC->APBRST_CR1 &= ~(RCC_APBRST_CR1_I2CRST_Msk);
	}
}

FunState RCC_APBRST_CR1_I2CRST_Getable(void)
{
	if (RCC->APBRST_CR1 & (RCC_APBRST_CR1_I2CRST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* LPTIM32模块复位 相关函数 */
void RCC_APBRST_CR1_LPT32RST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
    RCC->APBRST_CR1 |= (RCC_APBRST_CR1_LPT32RST_Msk);
	}
	else
	{
    RCC->APBRST_CR1 &= ~(RCC_APBRST_CR1_LPT32RST_Msk);
	}
}

FunState RCC_APBRST_CR1_LPT32RST_Getable(void)
{
	if (RCC->APBRST_CR1 & (RCC_APBRST_CR1_LPT32RST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ATIM模块复位 相关函数 */
void RCC_APBRST_CR2_ATRST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
    RCC->APBRST_CR2 |= (RCC_APBRST_CR2_ATRST_Msk);
	}
	else
	{
		RCC->APBRST_CR2 &= ~(RCC_APBRST_CR2_ATRST_Msk);
	}
}

FunState RCC_APBRST_CR2_ATRST_Getable(void)
{
	if (RCC->APBRST_CR2 & (RCC_APBRST_CR2_ATRST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* BSTIM模块复位 相关函数 */
void RCC_APBRST_CR2_BTRST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
    RCC->APBRST_CR2 |= (RCC_APBRST_CR2_BTRST_Msk);
	}
	else
	{
		RCC->APBRST_CR2 &= ~(RCC_APBRST_CR2_BTRST_Msk);
	}
}

FunState RCC_APBRST_CR2_BTRST_Getable(void)
{
	if (RCC->APBRST_CR2 & (RCC_APBRST_CR2_BTRST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ADC控制器复位 相关函数 */
void RCC_APBRST_CR2_ADCCRST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
    RCC->APBRST_CR2 |= (RCC_APBRST_CR2_ADCCRST_Msk);
	}
	else
	{
		RCC->APBRST_CR2 &= ~(RCC_APBRST_CR2_ADCCRST_Msk);
	}
}

FunState RCC_APBRST_CR2_ADCCRST_Getable(void)
{
	if (RCC->APBRST_CR2 & (RCC_APBRST_CR2_ADCCRST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ADC模块复位 相关函数 */
void RCC_APBRST_CR2_ADCRST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
    RCC->APBRST_CR2 |= (RCC_APBRST_CR2_ADCRST_Msk);
	}
	else
	{
		RCC->APBRST_CR2 &= ~(RCC_APBRST_CR2_ADCRST_Msk);
	}
}

FunState RCC_APBRST_CR2_ADCRST_Getable(void)
{
	if (RCC->APBRST_CR2 & (RCC_APBRST_CR2_ADCRST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 运放模块复位 相关函数 */
void RCC_APBRST_CR2_OPARST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
    RCC->APBRST_CR2 |= (RCC_APBRST_CR2_OPARST_Msk);
	}
	else
	{
		RCC->APBRST_CR2 &= ~(RCC_APBRST_CR2_OPARST_Msk);
	}
}

FunState RCC_APBRST_CR2_OPARST_Getable(void)
{
	if (RCC->APBRST_CR2 & (RCC_APBRST_CR2_OPARST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* AES模块复位 相关函数 */
void RCC_APBRST_CR2_AESRST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
    RCC->APBRST_CR2 |= (RCC_APBRST_CR2_AESRST_Msk);
	}
	else
	{
		RCC->APBRST_CR2 &= ~(RCC_APBRST_CR2_AESRST_Msk);
	}
}

FunState RCC_APBRST_CR2_AESRST_Getable(void)
{
	if (RCC->APBRST_CR2 & (RCC_APBRST_CR2_AESRST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* CRC模块复位 相关函数 */
void RCC_APBRST_CR2_CRCRST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
    RCC->APBRST_CR2 |= (RCC_APBRST_CR2_CRCRST_Msk);
	}
	else
	{
		RCC->APBRST_CR2 &= ~(RCC_APBRST_CR2_CRCRST_Msk);
	}
}

FunState RCC_APBRST_CR2_CRCRST_Getable(void)
{
	if (RCC->APBRST_CR2 & (RCC_APBRST_CR2_CRCRST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* RNG模块复位 相关函数 */
void RCC_APBRST_CR2_RNGRST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
    RCC->APBRST_CR2 |= (RCC_APBRST_CR2_RNGRST_Msk);
	}
	else
	{
		RCC->APBRST_CR2 &= ~(RCC_APBRST_CR2_RNGRST_Msk);
	}
}

FunState RCC_APBRST_CR2_RNGRST_Getable(void)
{
	if (RCC->APBRST_CR2 & (RCC_APBRST_CR2_RNGRST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* UART1模块复位 相关函数 */
void RCC_APBRST_CR2_UART1RST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
    RCC->APBRST_CR2 |= (RCC_APBRST_CR2_UART1RST_Msk);
	}
	else
	{
		RCC->APBRST_CR2 &= ~(RCC_APBRST_CR2_UART1RST_Msk);
	}
}

FunState RCC_APBRST_CR2_UART1RST_Getable(void)
{
	if (RCC->APBRST_CR2 & (RCC_APBRST_CR2_UART1RST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* UART0模块复位 相关函数 */
void RCC_APBRST_CR2_UART0RST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
     RCC->APBRST_CR2 |= (RCC_APBRST_CR2_UART0RST_Msk);
	}
	else
	{
		 RCC->APBRST_CR2 &= ~(RCC_APBRST_CR2_UART0RST_Msk);
	}
}

FunState RCC_APBRST_CR2_UART0RST_Getable(void)
{
	if (RCC->APBRST_CR2 & (RCC_APBRST_CR2_UART0RST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SPI1模块复位 相关函数 */
void RCC_APBRST_CR2_SPI1RST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
    RCC->APBRST_CR2 |= (RCC_APBRST_CR2_SPI1RST_Msk);
	}
	else
	{
		RCC->APBRST_CR2 &= ~(RCC_APBRST_CR2_SPI1RST_Msk);
	}
}

FunState RCC_APBRST_CR2_SPI1RST_Getable(void)
{
	if (RCC->APBRST_CR2 & (RCC_APBRST_CR2_SPI1RST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* UART红外调制模块复位 相关函数 */
void RCC_APBRST_CR2_UCIRRST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
    RCC->APBRST_CR2 |= (RCC_APBRST_CR2_UCIRRST_Msk);
	}
	else
	{
		RCC->APBRST_CR2 &= ~(RCC_APBRST_CR2_UCIRRST_Msk);
	}
}

FunState RCC_APBRST_CR2_UCIRRST_Getable(void)
{
	if (RCC->APBRST_CR2 & (RCC_APBRST_CR2_UCIRRST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* LPUART1模块复位 相关函数 */
void RCC_APBRST_CR2_LPUART1RST_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
    RCC->APBRST_CR2 |= (RCC_APBRST_CR2_LPUART1RST_Msk);
	}
	else
	{
		RCC->APBRST_CR2 &= ~(RCC_APBRST_CR2_LPUART1RST_Msk);
	}
}

FunState RCC_APBRST_CR2_LPUART1RST_Getable(void)
{
	if (RCC->APBRST_CR2 & (RCC_APBRST_CR2_LPUART1RST_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}


/* XTHF振荡强度配置 相关函数 */
void RCC_XTHF_CR_CFG_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RCC->XTHF_CR;
	tmpreg &= ~(RCC_XTHF_CR_CFG_Msk);
	tmpreg |= (SetValue & RCC_XTHF_CR_CFG_Msk);
	RCC->XTHF_CR = tmpreg;
}

uint32_t RCC_XTHF_CR_CFG_Get(void)
{
	return (RCC->XTHF_CR & RCC_XTHF_CR_CFG_Msk);
}

/* XTHF使能寄存器 相关函数 */
void RCC_XTHF_CR_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RCC->XTHF_CR |= (RCC_XTHF_CR_EN_Msk);
	}
	else
	{
		RCC->XTHF_CR &= ~(RCC_XTHF_CR_EN_Msk);
	}
}

FunState RCC_XTHF_CR_EN_Getable(void)
{
	if (RCC->XTHF_CR & (RCC_XTHF_CR_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* RC4M输出预分频  相关函数 */
void RCC_RC4M_CR_PSC_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RCC->RC4M_CR;
	tmpreg &= ~(RCC_RC4M_CR_PSC_Msk);
	tmpreg |= (SetValue & RCC_RC4M_CR_PSC_Msk);
	RCC->RC4M_CR = tmpreg;
}

uint32_t RCC_RC4M_CR_PSC_Get(void)
{
	return (RCC->RC4M_CR & RCC_RC4M_CR_PSC_Msk);
}

/* RC4M使能寄存器 相关函数 */
void RCC_RC4M_CR_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RCC->RC4M_CR |= (RCC_RC4M_CR_EN_Msk);
	}
	else
	{
		RCC->RC4M_CR &= ~(RCC_RC4M_CR_EN_Msk);
	}
}

FunState RCC_RC4M_CR_EN_Getable(void)
{
	if (RCC->RC4M_CR & (RCC_RC4M_CR_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* RCHF频率调校寄存器 相关函数 */
void RCC_RCHF_TR_Write(uint32_t SetValue)
{
	RCC->RCHF_TR = (SetValue & RCC_RCHF_TR_TRIM_Msk);
}

uint32_t RCC_RCHF_TR_Read(void)
{
	return (RCC->RCHF_TR & RCC_RCHF_TR_TRIM_Msk);
}

void RCC_OPC_CR1_EXTICKE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RCC->OPC_CR1 |= (RCC_OPC_CR1_EXTICKE_Msk);
	}
	else
	{
		RCC->OPC_CR1 &= ~(RCC_OPC_CR1_EXTICKE_Msk);
	}
}

FunState RCC_OPC_CR1_EXTICKE_Getable(void)
{
	if (RCC->OPC_CR1 & (RCC_OPC_CR1_EXTICKE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* EXTI中断采样时钟选择 相关函数 */
void RCC_OPC_CR1_EXTICKS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RCC->OPC_CR1;
	tmpreg &= ~(RCC_OPC_CR1_EXTICKS_Msk);
	tmpreg |= (SetValue & RCC_OPC_CR1_EXTICKS_Msk);
	RCC->OPC_CR1 = tmpreg;
}

uint32_t RCC_OPC_CR1_EXTICKS_Get(void)
{
	return (RCC->OPC_CR1 & RCC_OPC_CR1_EXTICKS_Msk);
}

void RCC_OPC_CR1_LPUART1CKE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RCC->OPC_CR1 |= (RCC_OPC_CR1_LPUART1CKE_Msk);
	}
	else
	{
		RCC->OPC_CR1 &= ~(RCC_OPC_CR1_LPUART1CKE_Msk);
	}
}

FunState RCC_OPC_CR1_LPUART1CKE_Getable(void)
{
	if (RCC->OPC_CR1 & (RCC_OPC_CR1_LPUART1CKE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

void RCC_OPC_CR1_LPUART0CKE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RCC->OPC_CR1 |= (RCC_OPC_CR1_LPUART0CKE_Msk);
	}
	else
	{
		RCC->OPC_CR1 &= ~(RCC_OPC_CR1_LPUART0CKE_Msk);
	}
}

FunState RCC_OPC_CR1_LPUART0CKE_Getable(void)
{
	if (RCC->OPC_CR1 & (RCC_OPC_CR1_LPUART0CKE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

void RCC_OPC_CR1_LPUART1CKS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RCC->OPC_CR1;
	tmpreg &= ~(RCC_OPC_CR1_LPUART1CKS_Msk);
	tmpreg |= (SetValue & RCC_OPC_CR1_LPUART1CKS_Msk);
	RCC->OPC_CR1 = tmpreg;
}

uint32_t RCC_OPC_CR1_LPUART1CKS_Get(void)
{
	return (RCC->OPC_CR1 & RCC_OPC_CR1_LPUART1CKS_Msk);
}

void RCC_OPC_CR1_LPUART0CKS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RCC->OPC_CR1;
	tmpreg &= ~(RCC_OPC_CR1_LPUART0CKS_Msk);
	tmpreg |= (SetValue & RCC_OPC_CR1_LPUART0CKS_Msk);
	RCC->OPC_CR1 = tmpreg;
}

uint32_t RCC_OPC_CR1_LPUART0CKS_Get(void)
{
	return (RCC->OPC_CR1 & RCC_OPC_CR1_LPUART0CKS_Msk);
}

void RCC_OPC_CR1_BEEPCKE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RCC->OPC_CR1 |= (RCC_OPC_CR1_BEEPCKE_Msk);
	}
	else
	{
		RCC->OPC_CR1 &= ~(RCC_OPC_CR1_BEEPCKE_Msk);
	}
}

FunState RCC_OPC_CR1_BEEPCKE_Getable(void)
{
	if (RCC->OPC_CR1 & (RCC_OPC_CR1_BEEPCKE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

void RCC_OPC_CR1_I2CCKE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RCC->OPC_CR1 |= (RCC_OPC_CR1_I2CCKE_Msk);
	}
	else
	{
		RCC->OPC_CR1 &= ~(RCC_OPC_CR1_I2CCKE_Msk);
	}
}

FunState RCC_OPC_CR1_I2CCKE_Getable(void)
{
	if (RCC->OPC_CR1 & (RCC_OPC_CR1_I2CCKE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

void RCC_OPC_CR1_BEEPCKS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RCC->OPC_CR1;
	tmpreg &= ~(RCC_OPC_CR1_BEEPCKS_Msk);
	tmpreg |= (SetValue & RCC_OPC_CR1_BEEPCKS_Msk);
	RCC->OPC_CR1 = tmpreg;
}

uint32_t RCC_OPC_CR1_BEEPCKS_Get(void)
{
	return (RCC->OPC_CR1 & RCC_OPC_CR1_BEEPCKS_Msk);
}

/* I2C主机工作时钟选择 相关函数 */
void RCC_OPC_CR1_I2CCKS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RCC->OPC_CR1;
	tmpreg &= ~(RCC_OPC_CR1_I2CCKS_Msk);
	tmpreg |= (SetValue & RCC_OPC_CR1_I2CCKS_Msk);
	RCC->OPC_CR1 = tmpreg;
}

uint32_t RCC_OPC_CR1_I2CCKS_Get(void)
{
	return (RCC->OPC_CR1 & RCC_OPC_CR1_I2CCKS_Msk);
}

void RCC_OPC_CR1_UART1CKE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RCC->OPC_CR1 |= (RCC_OPC_CR1_UART1CKE_Msk);
	}
	else
	{
		RCC->OPC_CR1 &= ~(RCC_OPC_CR1_UART1CKE_Msk);
	}
}

FunState RCC_OPC_CR1_UART1CKE_Getable(void)
{
	if (RCC->OPC_CR1 & (RCC_OPC_CR1_UART1CKE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

void RCC_OPC_CR1_UART0CKE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RCC->OPC_CR1 |= (RCC_OPC_CR1_UART0CKE_Msk);
	}
	else
	{
		RCC->OPC_CR1 &= ~(RCC_OPC_CR1_UART0CKE_Msk);
	}
}

FunState RCC_OPC_CR1_UART0CKE_Getable(void)
{
	if (RCC->OPC_CR1 & (RCC_OPC_CR1_UART0CKE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* UART1工作时钟选择 相关函数 */
void RCC_OPC_CR1_UART1CKS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RCC->OPC_CR1;
	tmpreg &= ~(RCC_OPC_CR1_UART1CKS_Msk);
	tmpreg |= (SetValue & RCC_OPC_CR1_UART1CKS_Msk);
	RCC->OPC_CR1 = tmpreg;
}

uint32_t RCC_OPC_CR1_UART1CKS_Get(void)
{
	return (RCC->OPC_CR1 & RCC_OPC_CR1_UART1CKS_Msk);
}

/* UART0工作时钟选择 相关函数 */
void RCC_OPC_CR1_UART0CKS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RCC->OPC_CR1;
	tmpreg &= ~(RCC_OPC_CR1_UART0CKS_Msk);
	tmpreg |= (SetValue & RCC_OPC_CR1_UART0CKS_Msk);
	RCC->OPC_CR1 = tmpreg;
}

uint32_t RCC_OPC_CR1_UART0CKS_Get(void)
{
	return (RCC->OPC_CR1 & RCC_OPC_CR1_UART0CKS_Msk);
}

/* 随机数发生器工作时钟分频 相关函数 */
void RCC_OPC_CR2_RNGPRSC_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RCC->OPC_CR2;
	tmpreg &= ~(RCC_OPC_CR2_RNGPRSC_Msk);
	tmpreg |= (SetValue & RCC_OPC_CR2_RNGPRSC_Msk);
	RCC->OPC_CR2 = tmpreg;
}

uint32_t RCC_OPC_CR2_RNGPRSC_Get(void)
{
	return (RCC->OPC_CR2 & RCC_OPC_CR2_RNGPRSC_Msk);
}

/* ADC工作时钟预分频 相关函数 */
void RCC_OPC_CR2_ADCPRSC_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RCC->OPC_CR2;
	tmpreg &= ~(RCC_OPC_CR2_ADCPRSC_Msk);
	tmpreg |= (SetValue & RCC_OPC_CR2_ADCPRSC_Msk);
	RCC->OPC_CR2 = tmpreg;
}

uint32_t RCC_OPC_CR2_ADCPRSC_Get(void)
{
	return (RCC->OPC_CR2 & RCC_OPC_CR2_ADCPRSC_Msk);
}

void RCC_OPC_CR2_FLSCKE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RCC->OPC_CR2 |= (RCC_OPC_CR2_FLSCKE_Msk);
	}
	else
	{
		RCC->OPC_CR2 &= ~(RCC_OPC_CR2_FLSCKE_Msk);
	}
}

FunState RCC_OPC_CR2_FLSCKE_Getable(void)
{
	if (RCC->OPC_CR2 & (RCC_OPC_CR2_FLSCKE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

void RCC_OPC_CR2_RNGCKE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RCC->OPC_CR2 |= (RCC_OPC_CR2_RNGCKE_Msk);
	}
	else
	{
		RCC->OPC_CR2 &= ~(RCC_OPC_CR2_RNGCKE_Msk);
	}
}

FunState RCC_OPC_CR2_RNGCKE_Getable(void)
{
	if (RCC->OPC_CR2 & (RCC_OPC_CR2_RNGCKE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

void RCC_OPC_CR2_ADCCKE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RCC->OPC_CR2 |= (RCC_OPC_CR2_ADCCKE_Msk);
	}
	else
	{
		RCC->OPC_CR2 &= ~(RCC_OPC_CR2_ADCCKE_Msk);
	}
}

FunState RCC_OPC_CR2_ADCCKE_Getable(void)
{
	if (RCC->OPC_CR2 & (RCC_OPC_CR2_ADCCKE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ADC工作时钟选择 相关函数 */
void RCC_OPC_CR2_ADCCKS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RCC->OPC_CR2;
	tmpreg &= ~(RCC_OPC_CR2_ADCCKS_Msk);
	tmpreg |= (SetValue & RCC_OPC_CR2_ADCCKS_Msk);
	RCC->OPC_CR2 = tmpreg;
}

uint32_t RCC_OPC_CR2_ADCCKS_Get(void)
{
	return (RCC->OPC_CR2 & RCC_OPC_CR2_ADCCKS_Msk);
}

void RCC_OPC_CR2_LPTCKE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RCC->OPC_CR2 |= (RCC_OPC_CR2_LPTCKE_Msk);
	}
	else
	{
		RCC->OPC_CR2 &= ~(RCC_OPC_CR2_LPTCKE_Msk);
	}
}

FunState RCC_OPC_CR2_LPTCKE_Getable(void)
{
	if (RCC->OPC_CR2 & (RCC_OPC_CR2_LPTCKE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* LPTIM工作时钟选择 相关函数 */
void RCC_OPC_CR2_LPTCKS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RCC->OPC_CR2;
	tmpreg &= ~(RCC_OPC_CR2_LPTCKS_Msk);
	tmpreg |= (SetValue & RCC_OPC_CR2_LPTCKS_Msk);
	RCC->OPC_CR2 = tmpreg;
}

uint32_t RCC_OPC_CR2_LPTCKS_Get(void)
{
	return (RCC->OPC_CR2 & RCC_OPC_CR2_LPTCKS_Msk);
}

void RCC_OPC_CR2_BTCKE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RCC->OPC_CR2 |= (RCC_OPC_CR2_BTCKE_Msk);
	}
	else
	{
		RCC->OPC_CR2 &= ~(RCC_OPC_CR2_BTCKE_Msk);
	}
}

FunState RCC_OPC_CR2_BTCKE_Getable(void)
{
	if (RCC->OPC_CR2 & (RCC_OPC_CR2_BTCKE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* BSTIM工作时钟源选择 相关函数 */
void RCC_OPC_CR2_BTCKS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RCC->OPC_CR2;
	tmpreg &= ~(RCC_OPC_CR2_BTCKS_Msk);
	tmpreg |= (SetValue & RCC_OPC_CR2_BTCKS_Msk);
	RCC->OPC_CR2 = tmpreg;
}

uint32_t RCC_OPC_CR2_BTCKS_Get(void)
{
	return (RCC->OPC_CR2 & RCC_OPC_CR2_BTCKS_Msk);
}

/* 外设时钟配置函数 */
void RCC_PERCLK_SetableEx(uint32_t periph_def, FunState NewState)
{
	__IO uint32_t *p_reg = 0;
	uint32_t TempREG;
	
    switch((periph_def & 0x0F000000))
    {
		case 0x01000000:
			p_reg = &(RCC->PCLK_CR1);
			break;
		
		case 0x02000000:
			p_reg = &(RCC->PCLK_CR2);
			break;
		
		case 0x03000000:
			p_reg = &(RCC->PCLK_CR3);
			break;
		
		case 0x04000000:
			p_reg = &(RCC->PCLK_CR4);
			break;
		
		default:
			break;
    }
	if(p_reg)
	{
		periph_def &= 0x000000FF;
		TempREG = (0x1U << periph_def);
		
		if (NewState != DISABLE)
		{
			*p_reg |= TempREG;
		}
		else
		{
			*p_reg &= ~TempREG;
		}
	}
}

/* RCHF初始化 */
void RCC_RCHF_Init( RCC_RCHF_InitTypeDef* para)
{
   RCC_RCHF_CR_FSEL_Set(para->FSEL);
   RCC_RCHF_CR_EN_Setable(para->RCHFEN);
}

/********************************
设置PLL倍频函数
功能:对PLL倍频进行设置
输入：PLL倍频数
 ********************************/
void RCC_PLLDB_WriteEx(uint32_t SetValue)
{	
  RCC_PLL_CR_DB_Set(SetValue);
}
/********************************
读取PLL倍频函数
功能:读取对PLL倍频数
输出：PLL倍频数
 ********************************/
uint32_t RCC_PLLDB_ReadEx(void)
{
	uint32_t tmpreg;
	
	tmpreg =  RCC_PLL_CR_DB_Get();
	return (tmpreg>>RCC_PLL_CR_DB_Pos);
}

/* PLL初始化 */
void RCC_PLL_Init(RCC_PLL_InitTypeDef* para)
{
	RCC_PLLDB_WriteEx(para->PLLDB);
	RCC_PLL_CR_REFPRSC_Set(para->REFPRSC);
	RCC_PLL_CR_OSEL_Set(para->PLLOSEL);
	RCC_PLL_CR_INSEL_Set(para->PLLINSEL);
	RCC_PLL_CR_EN_Setable(para->PLLEN);
}

/* 系统时钟初始化 */
void RCC_SysClk_Init(RCC_SYSCLK_InitTypeDef* para)
{
	RCC_SYSCLK_CR_SYSCLKSEL_Set(para->SYSCLKSEL);
	RCC_SYSCLK_CR_STCLKSEL_Set(para->STCLKSEL);
	RCC_SYSCLK_CR_AHBPRES_Set(para->AHBPRES);
	RCC_SYSCLK_CR_APBPRES_Set(para->APBPRES);
	RCC_SYSCLK_CR_SLP_ENEXTI_Setable(para->SLP_ENEXTI);
	RCC_SYSCLK_CR_LSCATS_Setable(para->LSCATS);
}

/* RC4M初始化 */
void RCC_RC4M_Init(RCC_RC4M_InitTypeDef* para)
{
	RCC_RC4M_CR_PSC_Set(para->RC4MPSC);
	RCC_RC4M_CR_EN_Setable(para->RC4MEN);
}

void RCC_Init_RCHF_Trim( uint8_t ClkMode )
{
	uint32_t Temp32;
	
	if( ClkMode == 1 )	//8M
	{
		Temp32 = const_rchf_Trim8;
	}
	else if( ClkMode == 2 )//16M
	{
		Temp32 = const_rchf_Trim16;
	}
	else if( ClkMode == 3 )//24M
	{
		Temp32 = const_rchf_Trim24;
	}
	else//默认8M
	{
		Temp32 = const_rchf_Trim8;
	}
	
	if( ((Temp32>>16)&0x0000FFFF) == ((~Temp32)&0x0000FFFF) )	//正反码校验判断
	{
		RCC_RCHF_TR_Write(Temp32&0x0000007F);
	}	
	else
	{
		RCC_RCHF_TR_Write(0x00000040);
	}
}
void RCC_GetClocksFreq(RCC_ClocksType* para)
{
	uint32_t tmp32 = 0,tmp_value = 0;

	para->SYSCLK_Frequency = 0;
	para->AHBCLK_Frequency = 0;
	para->APBCLK_Frequency = 0;
	para->RCHF_Frequency = 0;
	para->PLL_Frequency = 0;
	para->RC4M_Frequency = 0;
	
	/* Get RCHF FSEL */
	if(ENABLE == RCC_RCHF_CR_EN_Getable())
	{
		tmp32 = RCC_RCHF_CR_FSEL_Get();
		tmp32 = tmp32 >> RCC_RCHF_CR_FSEL_Pos;  
		/* RCHF clock frequency */
		para->RCHF_Frequency = __RCHF_INITIAL_CLOCK * (tmp32 + 1);
	}

	if(ENABLE == RCC_PLL_CR_EN_Getable())
	{
		/* Get Pll frequency */
		tmp32 = RCC_PLL_CR_INSEL_Get();
		tmp32 = tmp32 >> RCC_PLL_CR_INSEL_Pos;
    
    tmp_value = 1000000;
    		
		tmp32 = RCC_PLL_CR_DB_Get();
		para->PLL_Frequency = (tmp32 + 1) * tmp_value;
	}
	
	/* Get SYSCLK source */
    tmp32 = RCC_SYSCLK_CR_SYSCLKSEL_Get();
    tmp32 = tmp32 >> RCC_SYSCLK_CR_SYSCLKSEL_Pos;
    switch (tmp32)
    {
        case 0x00:  /* RCHF used as system clock source */
            para->SYSCLK_Frequency = para->RCHF_Frequency;
            break;
        case 0x01:  /* XTHF used as system clock  source */
            para->SYSCLK_Frequency = __XTHF_CLOCK;
            break;
        case 0x02:  /* PLL used as system clock  source */
            para->SYSCLK_Frequency = para->PLL_Frequency;
            break;
        case 0x03:  /* RCHF used as system clock  source */
            para->SYSCLK_Frequency = para->RCHF_Frequency;
            break;
				case 0x04:  /* RC4MPSC used as system clock  source */
            para->SYSCLK_Frequency = para->RC4M_Frequency;
            break;
        case 0x05:
            para->SYSCLK_Frequency =__XTLF_CLOCK;
            break;
        case 0x06:
            para->SYSCLK_Frequency =__XTLF_CLOCK;
            break;
        case 0x07:
            para->SYSCLK_Frequency =__XTLF_CLOCK;
            break;
        default:
            para->SYSCLK_Frequency = para->RCHF_Frequency;
            break;
    }
	
	/* Get AHB PRES */
    tmp32 = RCC_SYSCLK_CR_AHBPRES_Get();
    tmp32 = tmp32 >> RCC_SYSCLK_CR_AHBPRES_Pos;  
    switch(tmp32)
    {
        case 0x04: //100:DIV2
            para->AHBCLK_Frequency = para->SYSCLK_Frequency/2;
            break;
        case 0x05: //101:DIV4
            para->AHBCLK_Frequency = para->SYSCLK_Frequency/4;
            break;
        case 0x06: //110:DIV8
            para->AHBCLK_Frequency = para->SYSCLK_Frequency/8;
            break;
        case 0x07: //111:DIV16
            para->AHBCLK_Frequency = para->SYSCLK_Frequency/16;
            break;
        default: //0XX:DIV1
            para->AHBCLK_Frequency = para->SYSCLK_Frequency;
            break;
    }

	/* Get APB PRES */
    tmp32 = RCC_SYSCLK_CR_APBPRES_Get();
    tmp32 = tmp32 >> RCC_SYSCLK_CR_APBPRES_Pos; 
	/* APB clock frequency */
    switch(tmp32)
    {
        case 0x04: //100:DIV2
            para->APBCLK_Frequency = para->AHBCLK_Frequency/2;
            break;
        case 0x05: //101:DIV4
            para->APBCLK_Frequency = para->AHBCLK_Frequency/4;
            break;
        case 0x06: //110:DIV8
            para->APBCLK_Frequency = para->AHBCLK_Frequency/8;
            break;
        case 0x07: //111:DIV16
            para->APBCLK_Frequency = para->AHBCLK_Frequency/16;
            break;
        default: //0XX:DIV1
            para->APBCLK_Frequency = para->AHBCLK_Frequency;
            break;
    }
}

void RCC_FDET_IER_HFDET_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RCC_FDET->IER |= (RCC_FDET_IER_HFDET_IE_Msk);
	}
	else
	{
		RCC_FDET->IER &= ~(RCC_FDET_IER_HFDET_IE_Msk);
	}
}

FunState RCC_FDET_IER_HFDET_IE_Getable(void)
{
	if (RCC_FDET->IER & (RCC_FDET_IER_HFDET_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

void RCC_FDET_IER_LFDET_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RCC_FDET->IER |= (RCC_FDET_IER_LFDET_IE_Msk);
	}
	else
	{
		RCC_FDET->IER &= ~(RCC_FDET_IER_LFDET_IE_Msk);
	}
}

FunState RCC_FDET_IER_LFDET_IE_Getable(void)
{
	if (RCC_FDET->IER & (RCC_FDET_IER_LFDET_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 高频晶体停振检测模块输出 相关函数 */
FlagStatus RCC_FDET_ISR_HFDETO_Chk(void)
{
	if (RCC_FDET->ISR & RCC_FDET_ISR_HFDETO_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 低频晶体停振检测模块输出 相关函数 */
FlagStatus RCC_FDET_ISR_LFDETO_Chk(void)
{
	if (RCC_FDET->ISR & RCC_FDET_ISR_LFDETO_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 高频停振检测中断标志寄存器 相关函数 */
void RCC_FDET_ISR_HFDETIF_Clr(void)
{
	RCC_FDET->ISR = RCC_FDET_ISR_HFDETIF_Msk;
}

FlagStatus RCC_FDET_ISR_HFDETIF_Chk(void)
{
	if (RCC_FDET->ISR & RCC_FDET_ISR_HFDETIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 低频停振检测中断标志寄存器 相关函数 */
void RCC_FDET_ISR_LFDETIF_Clr(void)
{
	RCC_FDET->ISR = RCC_FDET_ISR_LFDETIF_Msk;
}

FlagStatus RCC_FDET_ISR_LFDETIF_Chk(void)
{
	if (RCC_FDET->ISR & RCC_FDET_ISR_LFDETIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 下电复位电压配置 相关函数 */
void RCC_PDR_CR_CFG_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RCC_PDR->CR;
	tmpreg &= ~(RCC_PDR_CR_CFG_Msk);
	tmpreg |= (SetValue & RCC_PDR_CR_CFG_Msk);
	RCC_PDR->CR = tmpreg;
}

uint32_t RCC_PDR_CR_CFG_Get(void)
{
	return (RCC_PDR->CR & RCC_PDR_CR_CFG_Msk);
}

/* 下电复位使能 相关函数 */
void RCC_PDR_CR_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RCC_PDR->CR |= (RCC_PDR_CR_EN_Msk);
	}
	else
	{
		RCC_PDR->CR &= ~(RCC_PDR_CR_EN_Msk);
	}
}

FunState RCC_PDR_CR_EN_Getable(void)
{
	if (RCC_PDR->CR & (RCC_PDR_CR_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 下电复位电压配置 相关函数 */
void RCC_BOR_CR_CFG_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RCC_BOR->CR;
	tmpreg &= ~(RCC_BOR_CR_CFG_Msk);
	tmpreg |= (SetValue & RCC_BOR_CR_CFG_Msk);
	RCC_BOR->CR = tmpreg;
}

uint32_t RCC_BOR_CR_CFG_Get(void)
{
	return (RCC_BOR->CR & RCC_BOR_CR_CFG_Msk);
}

/* 下电复位使能 相关函数 */
void RCC_BOR_CR_OFF_BOR_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
    RCC_BOR->CR |= (RCC_BOR_CR_OFF_BOR_Msk);
	}
	else
	{
		RCC_BOR->CR &= ~(RCC_BOR_CR_OFF_BOR_Msk);
	}
}

FunState RCC_BOR_CR_OFF_BOR_Getable(void)
{
	if (RCC_BOR->CR & (RCC_BOR_CR_OFF_BOR_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/******END OF FILE****/
