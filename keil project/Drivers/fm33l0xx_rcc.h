/**
  ******************************************************************************
  * @file    fm33l0xx_rcc.h
  * @author  FM33L0xx Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file contains all the functions prototypes for the RCC firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33L0XX_RCC_H
#define __FM33L0XX_RCC_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33L0XX.h"

//------------------------------------------------------------------------------

/* Defines------------------------------------------------------------------*/
#define HXVAR(object, addr)   (*((object *) (addr)))
#define const_rchf_Trim8  	HXVAR( uint32_t, 0x1FFFFD40 )	//RC8M 常温校准值
#define const_rchf_Trim16 	HXVAR( uint32_t, 0x1FFFFD3C )	//RC16M 常温校准值
#define const_rchf_Trim24 	HXVAR( uint32_t, 0x1FFFFD38 )	//RC24M 常温校准值
   
#define RSTKEY0  ((uint32_t)0x13579BDF)  //使能外设复位功能key
#define RSTKEY1  ((uint32_t)0x00000000)  //关闭外设复位功能key
/* Exported constants --------------------------------------------------------*/


/* Exported types ------------------------------------------------------------*/
typedef struct
{
	uint32_t			FSEL;		/*!<RCHF频率  */
	FunState			RCHFEN;			/*!<RCHF使能控制  */
}RCC_RCHF_InitTypeDef;

typedef struct
{            
  uint32_t			PLLDB;		/*!<PLL倍频比最大1023,pll倍频数 = PLLDB + 1  */
	uint32_t      REFPRSC;		/* PLL参考时钟预分频 */
	uint32_t			PLLOSEL;	/*!<PLL输出选择，当需要输出超过1024倍时开启两倍输出模式  */
	uint32_t			PLLINSEL;	/*!<PLL输入源选择  */
	FunState			PLLEN;		/*!<PLL使能控制  */
}RCC_PLL_InitTypeDef;

typedef struct
{
	FunState			LPM_RCLP_OFF;			/*!<休眠模式下RCLP控制寄存器  */
}RCC_RCLP_InitTypeDef;

typedef struct
{
    uint32_t		SYSCLKSEL;		/*!<系统时钟选择，从休眠状态唤醒后会自动恢复为RCHF8M  */
	uint32_t			STCLKSEL;		/* CPU内核systick工作时钟选择  */
	uint32_t			AHBPRES;		/*!<AHB时钟分频选择  */
	uint32_t			APBPRES;		/*!<APB时钟分频选择  */
	FunState			SLP_ENEXTI;		/*!<Sleep/DeepSleep模式下EXTI采样设置  */
	FunState			LSCATS;	/* LSCLK自动切换使能  */	
}RCC_SYSCLK_InitTypeDef;

typedef struct
{
	uint32_t			RC4MPSC;		/*!<RC4M频率  */
	FunState			RC4MEN;			/*!<RC4M使能控制  */
}RCC_RC4M_InitTypeDef;

typedef struct
{
  uint32_t SYSCLK_Frequency;		/*!<  SYSCLK clock frequency expressed in Hz */
  uint32_t AHBCLK_Frequency;		/*!<  AHB clock frequency expressed in Hz  */
  uint32_t APBCLK_Frequency;		/*!<  APB clock frequency expressed in Hz  */
  uint32_t RCHF_Frequency;			/*!<  RCHF clock frequency expressed in Hz   */
  uint32_t PLL_Frequency;			/*!<  PLL clock frequency expressed in Hz   */
	uint32_t RC4M_Frequency;   /*!<  RC4M clock frequency expressed in Hz   */
}RCC_ClocksType;

#define	RCC_LKP_CR_RST_EN_Pos	1
#define	RCC_LKP_CR_RST_EN_Msk	(0x1U << RCC_LKP_CR_RST_EN_Pos)
	/* 0：屏蔽CPU LOCKUP复位 */
	/* 1：使能CPU LOCKUP复位 */

#define	RCC_SOFTRST_SOFTRST_Pos	0
#define	RCC_SOFTRST_SOFTRST_Msk	(0xffffffffU << RCC_SOFTRST_SOFTRST_Pos)

#define	RCC_RSTFR_NRSTN_FLAG_Pos	11
#define	RCC_RSTFR_NRSTN_FLAG_Msk	(0x1U << RCC_RSTFR_NRSTN_FLAG_Pos)

#define	RCC_RSTFR_TESTN_FLAG_Pos	10
#define	RCC_RSTFR_TESTN_FLAG_Msk	(0x1U << RCC_RSTFR_TESTN_FLAG_Pos)

#define	RCC_RSTFR_PORN_FLAG_Pos	9
#define	RCC_RSTFR_PORN_FLAG_Msk	(0x1U << RCC_RSTFR_PORN_FLAG_Pos)

#define	RCC_RSTFR_PDRN_FLAG_Pos	8
#define	RCC_RSTFR_PDRN_FLAG_Msk	(0x1U << RCC_RSTFR_PDRN_FLAG_Pos)

#define	RCC_RSTFR_SOFTN_FLAG_Pos	5
#define	RCC_RSTFR_SOFTN_FLAG_Msk	(0x1U << RCC_RSTFR_SOFTN_FLAG_Pos)

#define	RCC_RSTFR_IWDTN_FLAG_Pos	4
#define	RCC_RSTFR_IWDTN_FLAG_Msk	(0x1U << RCC_RSTFR_IWDTN_FLAG_Pos)

#define	RCC_RSTFR_WWDTN_FLAG_Pos	2
#define	RCC_RSTFR_WWDTN_FLAG_Msk	(0x1U << RCC_RSTFR_WWDTN_FLAG_Pos)

#define	RCC_RSTFR_LKUPN_FLAG_Pos	1
#define	RCC_RSTFR_LKUPN_FLAG_Msk	(0x1U << RCC_RSTFR_LKUPN_FLAG_Pos)

#define	RCC_RSTFR_NVICN_FLAG_Pos	0
#define	RCC_RSTFR_NVICN_FLAG_Msk	(0x1U << RCC_RSTFR_NVICN_FLAG_Pos)

#define	RCC_SYSCLK_CR_LSCATS_Pos	27	/* LSCLK自动切换使能 */
#define	RCC_SYSCLK_CR_LSCATS_Msk	(0x1U << RCC_SYSCLK_CR_LSCATS_Pos)
	/* 0：当检测到XTLF异常停振时，不会自动将LSCLK切换到RCLP，软件可以通过写XTLFCR.XTLF_BKSW寄存器手动切换到RCLP */
	/* 1：当检测到XTLF异常停振时，自动使能RCLP并将LSCLK切换到RCLP */

#define	RCC_SYSCLK_CR_SLP_ENEXTI_Pos	25	/* Sleep/DeepSleep模式下EXTI采样设置 */
#define	RCC_SYSCLK_CR_SLP_ENEXTI_Msk	(0x1U << RCC_SYSCLK_CR_SLP_ENEXTI_Pos)
	/* 0：Sleep/DeepSleep模式下禁止外部引脚中断采样 */
	/* 1：Sleep/DeepSleep模式下使能外部引脚中断采样 */

#define	RCC_SYSCLK_CR_APBPRES_Pos	16	/* APB时钟分频选择 */
#define	RCC_SYSCLK_CR_APBPRES_Msk	(0x7U << RCC_SYSCLK_CR_APBPRES_Pos)
#define	RCC_SYSCLK_CR_APBPRES_DIV1	(0x0U << RCC_SYSCLK_CR_APBPRES_Pos)	/* 0XX:不分频 */
#define	RCC_SYSCLK_CR_APBPRES_DIV2	(0x4U << RCC_SYSCLK_CR_APBPRES_Pos)	/* 100：2分频 */
#define	RCC_SYSCLK_CR_APBPRES_DIV4	(0x5U << RCC_SYSCLK_CR_APBPRES_Pos)	/* 101：4分频 */
#define	RCC_SYSCLK_CR_APBPRES_DIV8	(0x6U << RCC_SYSCLK_CR_APBPRES_Pos)	/* 110：8分频 */
#define	RCC_SYSCLK_CR_APBPRES_DIV16	(0x7U << RCC_SYSCLK_CR_APBPRES_Pos)	/* 111：16分频 */

#define	RCC_SYSCLK_CR_AHBPRES_Pos	8	/* AHB时钟分频选择 */
#define	RCC_SYSCLK_CR_AHBPRES_Msk	(0x7U << RCC_SYSCLK_CR_AHBPRES_Pos)
#define	RCC_SYSCLK_CR_AHBPRES_DIV1	(0x0U << RCC_SYSCLK_CR_AHBPRES_Pos)	/* 0XX:不分频 */
#define	RCC_SYSCLK_CR_AHBPRES_DIV2	(0x4U << RCC_SYSCLK_CR_AHBPRES_Pos)	/* 100：2分频 */
#define	RCC_SYSCLK_CR_AHBPRES_DIV4	(0x5U << RCC_SYSCLK_CR_AHBPRES_Pos)	/* 101：4分频 */
#define	RCC_SYSCLK_CR_AHBPRES_DIV8	(0x6U << RCC_SYSCLK_CR_AHBPRES_Pos)	/* 110：8分频 */
#define	RCC_SYSCLK_CR_AHBPRES_DIV16	(0x7U << RCC_SYSCLK_CR_AHBPRES_Pos)	/* 111：16分频 */

#define	RCC_SYSCLK_CR_STCLKSEL_Pos	6	/* CPU内核systick工作时钟选择 */
#define	RCC_SYSCLK_CR_STCLKSEL_Msk	(0x3U << RCC_SYSCLK_CR_STCLKSEL_Pos)
#define	RCC_SYSCLK_CR_STCLKSEL_SCLK	(0x0U << RCC_SYSCLK_CR_STCLKSEL_Pos)	/* 00：SCLK */
#define	RCC_SYSCLK_CR_STCLKSEL_LSCLK	(0x1U << RCC_SYSCLK_CR_STCLKSEL_Pos)	/* 01：LSCLK */
#define	RCC_SYSCLK_CR_STCLKSEL_RC4M	(0x2U << RCC_SYSCLK_CR_STCLKSEL_Pos)	/* 10：RC4M */
#define	RCC_SYSCLK_CR_STCLKSEL_SYSCLK	(0x3U << RCC_SYSCLK_CR_STCLKSEL_Pos)	/* 11：SYSCLK */

#define	RCC_SYSCLK_CR_SYSCLKSEL_Pos	0	/* 系统时钟源选择 */
#define	RCC_SYSCLK_CR_SYSCLKSEL_Msk	(0x7U << RCC_SYSCLK_CR_SYSCLKSEL_Pos)
#define	RCC_SYSCLK_CR_SYSCLKSEL_RCHF	(0x0U << RCC_SYSCLK_CR_SYSCLKSEL_Pos)	/* 000：RCHF */
#define	RCC_SYSCLK_CR_SYSCLKSEL_XTHF	(0x1U << RCC_SYSCLK_CR_SYSCLKSEL_Pos)	/* 001：XTHF */
#define	RCC_SYSCLK_CR_SYSCLKSEL_PLL	(0x2U << RCC_SYSCLK_CR_SYSCLKSEL_Pos)	/* 010：PLL */
#define	RCC_SYSCLK_CR_SYSCLKSEL_RC4MPSC	(0x4U << RCC_SYSCLK_CR_SYSCLKSEL_Pos)	/* 100：RC4MPSC */
#define	RCC_SYSCLK_CR_SYSCLKSEL_LSCK	(0x5U << RCC_SYSCLK_CR_SYSCLKSEL_Pos)	/* 101,110,111：LSCLK */

#define	RCC_RCHF_CR_FSEL_Pos	16	/* RCHF频率选择寄存器 */
#define	RCC_RCHF_CR_FSEL_Msk	(0xfU << RCC_RCHF_CR_FSEL_Pos)
#define	RCC_RCHF_CR_FSEL_8MHZ	(0x0U << RCC_RCHF_CR_FSEL_Pos)	/* 0000：8MHz */
#define	RCC_RCHF_CR_FSEL_16MHZ	(0x1U << RCC_RCHF_CR_FSEL_Pos)	/* 0001：16MHz */
#define	RCC_RCHF_CR_FSEL_24MHZ	(0x2U << RCC_RCHF_CR_FSEL_Pos)	/* 0010：24MHz */

#define	RCC_RCHF_CR_EN_Pos	0	/* RCHF使能寄存器 */
#define	RCC_RCHF_CR_EN_Msk	(0x1U << RCC_RCHF_CR_EN_Pos)
	/* 0：关闭RCHF */
	/* 1：使能RCHF */

#define	RCC_RC4M_TR_TRIM_Pos	0	/* RC4M频率调校寄存器 */
#define	RCC_RC4M_TR_TRIM_Msk	(0x7fU << RCC_RC4M_TR_TRIM_Pos)

#define	RCC_PLL_CR_DB_Pos	16	/* PLL倍频比 */
#define	RCC_PLL_CR_DB_Msk	(0x7fU << RCC_PLL_CR_DB_Pos)

#define	RCC_PLL_CR_LOCKED_Pos	7	/* PLL锁定标志 */
#define	RCC_PLL_CR_LOCKED_Msk	(0x1U << RCC_PLL_CR_LOCKED_Pos)

#define	RCC_PLL_CR_REFPRSC_Pos	4	/* PLL参考时钟预分频（目标是产生1MHz参考时钟给PLL） */
#define	RCC_PLL_CR_REFPRSC_Msk	(0x7U << RCC_PLL_CR_REFPRSC_Pos)
#define	RCC_PLL_CR_REFPRSC_DIV1	(0x0U << RCC_PLL_CR_REFPRSC_Pos)	/* 000：不分频 */
#define	RCC_PLL_CR_REFPRSC_DIV2	(0x1U << RCC_PLL_CR_REFPRSC_Pos)	/* 001：2分频 */
#define	RCC_PLL_CR_REFPRSC_DIV4	(0x2U << RCC_PLL_CR_REFPRSC_Pos)	/* 010：4分频 */
#define	RCC_PLL_CR_REFPRSC_DIV8	(0x3U << RCC_PLL_CR_REFPRSC_Pos)	/* 011：8分频 */
#define	RCC_PLL_CR_REFPRSC_DIV12	(0x4U << RCC_PLL_CR_REFPRSC_Pos)	/* 100：12分频 */
#define	RCC_PLL_CR_REFPRSC_DIV16	(0x5U << RCC_PLL_CR_REFPRSC_Pos)	/* 101：16分频 */
#define	RCC_PLL_CR_REFPRSC_DIV24	(0x6U << RCC_PLL_CR_REFPRSC_Pos)	/* 110：24分频 */
#define	RCC_PLL_CR_REFPRSC_DIV32	(0x7U << RCC_PLL_CR_REFPRSC_Pos)	/* 111：32分频 */

#define	RCC_PLL_CR_OSEL_Pos	3	/* PLL输出选择寄存器 */
#define	RCC_PLL_CR_OSEL_Msk	(0x1U << RCC_PLL_CR_OSEL_Pos)
#define	RCC_PLL_CR_OSEL_MUL1	(0x0U << RCC_PLL_CR_OSEL_Pos)	/* 0：选择PLL一倍输出作为数字电路内的PLL时钟 */
#define	RCC_PLL_CR_OSEL_MUL2	(0x1U << RCC_PLL_CR_OSEL_Pos)	/* 1：选择PLL两倍输出作为数字电路内的PLL时钟 */

#define	RCC_PLL_CR_INSEL_Pos	1	/* PLL输入选择寄存器 */
#define	RCC_PLL_CR_INSEL_Msk	(0x1U << RCC_PLL_CR_INSEL_Pos)
#define	RCC_PLL_CR_INSEL_RCHF	(0x0U << RCC_PLL_CR_INSEL_Pos)	/* 0：RCHF */
#define	RCC_PLL_CR_INSEL_XTHF	(0x1U << RCC_PLL_CR_INSEL_Pos)	/* 1：XTHF */

#define	RCC_PLL_CR_EN_Pos	0	/* PLL使能寄存器 */
#define	RCC_PLL_CR_EN_Msk	(0x1U << RCC_PLL_CR_EN_Pos)
	/* 0：关闭PLL */
	/* 1：使能PLL */

#define	RCC_RCLP_CR_OFF_EN_Pos	1	/* RCLP使能标志信号 */
#define	RCC_RCLP_CR_OFF_EN_Msk	(0x1U << RCC_RCLP_CR_OFF_EN_Pos)

#define	RCC_RCLP_CR_LPM_RCLP_OFF_Pos	0	/* 休眠模式下RCLP控制寄存器 */
#define	RCC_RCLP_CR_LPM_RCLP_OFF_Msk	(0x1U << RCC_RCLP_CR_LPM_RCLP_OFF_Pos)
#define	RCC_RCLP_CR_LPM_RCLP_OFF_OPEN	(0x0U << RCC_RCLP_CR_LPM_RCLP_OFF_Pos)	/* 0：休眠模式下RCLP开启 */
#define	RCC_RCLP_CR_LPM_RCLP_OFF_CLOSE	(0x1U << RCC_RCLP_CR_LPM_RCLP_OFF_Pos)	/* 1：休眠模式下RCLP关闭 */

#define	RCC_RCLP_TR_TRIM_Pos	0	/* RCLP调校值寄存器 */
#define	RCC_RCLP_TR_TRIM_Msk	(0xffU << RCC_RCLP_TR_TRIM_Pos)

#define	RCC_XTLF_CR_BKSW_Pos	16	/* XTLF备份时钟手动切换寄存器 */
#define	RCC_XTLF_CR_BKSW_Msk	(0xffU << RCC_XTLF_CR_BKSW_Pos)

#define	RCC_XTLF_CR_EN_Pos	8	/* XTLF使能寄存器 */
#define	RCC_XTLF_CR_EN_Msk	(0xfU << RCC_XTLF_CR_EN_Pos)
#define	RCC_XTLF_CR_EN_DISABLE	(0xaU << RCC_XTLF_CR_EN_Pos)	/* 1010：关闭XTLF和FDET */
#define	RCC_XTLF_CR_EN_ENABLE	(0x5U << RCC_XTLF_CR_EN_Pos)	/* 其他：使能XTLF和FDET */

#define	RCC_XTLF_CR_IPW_Pos	0	/* XTLF工作电流选择 */
#define	RCC_XTLF_CR_IPW_Msk	(0x7U << RCC_XTLF_CR_IPW_Pos)
#define	RCC_XTLF_CR_IPW_450NA	(0x0U << RCC_XTLF_CR_IPW_Pos)
#define	RCC_XTLF_CR_IPW_400NA	(0x1U << RCC_XTLF_CR_IPW_Pos)
#define	RCC_XTLF_CR_IPW_350NA	(0x2U << RCC_XTLF_CR_IPW_Pos)
#define	RCC_XTLF_CR_IPW_300NA	(0x3U << RCC_XTLF_CR_IPW_Pos)
#define	RCC_XTLF_CR_IPW_250NA	(0x4U << RCC_XTLF_CR_IPW_Pos)
#define	RCC_XTLF_CR_IPW_200NA	(0x5U << RCC_XTLF_CR_IPW_Pos)
#define	RCC_XTLF_CR_IPW_150NA	(0x6U << RCC_XTLF_CR_IPW_Pos)
#define	RCC_XTLF_CR_IPW_100NA	(0x7U << RCC_XTLF_CR_IPW_Pos)

#define	RCC_PCLK_CR1_DCU_PCE_Pos	31
#define	RCC_PCLK_CR1_DCU_PCE_Msk	(0x1U << RCC_PCLK_CR1_DCU_PCE_Pos)
	/* DCU总线时钟使能，高使能 */

#define	RCC_PCLK_CR1_BEEP_PCE_Pos	16
#define	RCC_PCLK_CR1_BEEP_PCE_Msk	(0x1U << RCC_PCLK_CR1_BEEP_PCE_Pos)
	/* BEEPER总线时钟使能，高使能 */

#define	RCC_PCLK_CR1_PAD_PCE_Pos	7
#define	RCC_PCLK_CR1_PAD_PCE_Msk	(0x1U << RCC_PCLK_CR1_PAD_PCE_Pos)
	/* PADCFG总线时钟使能，高使能 */

#define	RCC_PCLK_CR1_ANAC_PCE_Pos	6
#define	RCC_PCLK_CR1_ANAC_PCE_Msk	(0x1U << RCC_PCLK_CR1_ANAC_PCE_Pos)
	/* ANAC总线时钟使能，高使能  */

#define	RCC_PCLK_CR1_IWDT_PCE_Pos	5
#define	RCC_PCLK_CR1_IWDT_PCE_Msk	(0x1U << RCC_PCLK_CR1_IWDT_PCE_Pos)
	/* IWDT总线时钟使能，高使能 */

#define	RCC_PCLK_CR1_SCU_PCE_Pos	4
#define	RCC_PCLK_CR1_SCU_PCE_Msk	(0x1U << RCC_PCLK_CR1_SCU_PCE_Pos)
	/* SCU总线时钟使能，高使能 */

#define	RCC_PCLK_CR1_PMU_PCE_Pos	3
#define	RCC_PCLK_CR1_PMU_PCE_Msk	(0x1U << RCC_PCLK_CR1_PMU_PCE_Pos)
	/* PMU总线时钟使能，高使能 */

#define	RCC_PCLK_CR1_RTC_PCE_Pos	2
#define	RCC_PCLK_CR1_RTC_PCE_Msk	(0x1U << RCC_PCLK_CR1_RTC_PCE_Pos)
	/* RTC总线时钟使能，高使能 */

#define	RCC_PCLK_CR1_LPT_PCE_Pos	0
#define	RCC_PCLK_CR1_LPT_PCE_Msk	(0x1U << RCC_PCLK_CR1_LPT_PCE_Pos)
	/* LPTIM32总线时钟使能，高使能 */

#define	RCC_PCLK_CR2_ADC_PCE_Pos	8
#define	RCC_PCLK_CR2_ADC_PCE_Msk	(0x1U << RCC_PCLK_CR2_ADC_PCE_Pos)
	/* ADC总线时钟使能，高使能 */

#define	RCC_PCLK_CR2_WWDT_PCE_Pos	7
#define	RCC_PCLK_CR2_WWDT_PCE_Msk	(0x1U << RCC_PCLK_CR2_WWDT_PCE_Pos)
	/* WWDT总线时钟使能，高使能 */

#define	RCC_PCLK_CR2_RAMBIST_PCE_Pos	6
#define	RCC_PCLK_CR2_RAMBIST_PCE_Msk	(0x1U << RCC_PCLK_CR2_RAMBIST_PCE_Pos)
	/* RAMBIST总线时钟使能，高使能 */

#define	RCC_PCLK_CR2_FLS_PCE_Pos	5
#define	RCC_PCLK_CR2_FLS_PCE_Msk	(0x1U << RCC_PCLK_CR2_FLS_PCE_Pos)
	/* Flash擦写控制器 总线时钟使能，高使能*/
	
#define	RCC_PCLK_CR2_DMA_PCE_Pos	4
#define	RCC_PCLK_CR2_DMA_PCE_Msk	(0x1U << RCC_PCLK_CR2_DMA_PCE_Pos)
	/* DMA总线时钟使能，高使能 */

#define	RCC_PCLK_CR2_LCD_PCE_Pos	3
#define	RCC_PCLK_CR2_LCD_PCE_Msk	(0x1U << RCC_PCLK_CR2_LCD_PCE_Pos)
	/* LCD总线时钟使能，高使能 */

#define	RCC_PCLK_CR2_AES_PCE_Pos	2
#define	RCC_PCLK_CR2_AES_PCE_Msk	(0x1U << RCC_PCLK_CR2_AES_PCE_Pos)
	/* AES总线时钟使能，高使能 */

#define	RCC_PCLK_CR2_RNG_PCE_Pos	1
#define	RCC_PCLK_CR2_RNG_PCE_Msk	(0x1U << RCC_PCLK_CR2_RNG_PCE_Pos)
	/* RNG总线时钟使能，高使能 */

#define	RCC_PCLK_CR2_CRC_PCE_Pos	0
#define	RCC_PCLK_CR2_CRC_PCE_Msk	(0x1U << RCC_PCLK_CR2_CRC_PCE_Pos)
	/* CRC总线时钟使能，高使能 */

#define	RCC_PCLK_CR3_I2C_PCE_Pos	24
#define	RCC_PCLK_CR3_I2C_PCE_Msk	(0x1U << RCC_PCLK_CR3_I2C_PCE_Pos)
	/* I2C总线时钟使能，高有效 */

#define	RCC_PCLK_CR3_LPUART1_PCE_Pos	18
#define	RCC_PCLK_CR3_LPUART1_PCE_Msk	(0x1U << RCC_PCLK_CR3_LPUART1_PCE_Pos)
	/* LPUART1总线时钟使能，高有效 */

#define	RCC_PCLK_CR3_U7816_PCE_Pos	16
#define	RCC_PCLK_CR3_U7816_PCE_Msk	(0x1U << RCC_PCLK_CR3_U7816_PCE_Pos)
	/* 7816总线时钟使能，高有效 */

#define	RCC_PCLK_CR3_LPUART0_PCE_Pos	15
#define	RCC_PCLK_CR3_LPUART0_PCE_Msk	(0x1U << RCC_PCLK_CR3_LPUART0_PCE_Pos)
	/* LPUART总线时钟使能，高有效 */

#define	RCC_PCLK_CR3_UCIR_PCE_Pos	14
#define	RCC_PCLK_CR3_UCIR_PCE_Msk	(0x1U << RCC_PCLK_CR3_UCIR_PCE_Pos)
	/* UART红外调制工作时钟使能，高有效 */

#define	RCC_PCLK_CR3_UART5_PCE_Pos	13
#define	RCC_PCLK_CR3_UART5_PCE_Msk	(0x1U << RCC_PCLK_CR3_UART5_PCE_Pos)
	/* UART5总线时钟使能，高有效 */

#define	RCC_PCLK_CR3_UART4_PCE_Pos	12
#define	RCC_PCLK_CR3_UART4_PCE_Msk	(0x1U << RCC_PCLK_CR3_UART4_PCE_Pos)
	/* UART4总线时钟使能，高有效 */

#define	RCC_PCLK_CR3_UART1_PCE_Pos	9
#define	RCC_PCLK_CR3_UART1_PCE_Msk	(0x1U << RCC_PCLK_CR3_UART1_PCE_Pos)
	/* UART1总线时钟使能，高有效 */

#define	RCC_PCLK_CR3_UART0_PCE_Pos	8
#define	RCC_PCLK_CR3_UART0_PCE_Msk	(0x1U << RCC_PCLK_CR3_UART0_PCE_Pos)
	/* UART0总线时钟使能，高有效 */

#define	RCC_PCLK_CR3_SPI2_PCE_Pos	1
#define	RCC_PCLK_CR3_SPI2_PCE_Msk	(0x1U << RCC_PCLK_CR3_SPI2_PCE_Pos)
	/* SPI2总线时钟使能，高有效 */

#define	RCC_PCLK_CR3_SPI1_PCE_Pos	0
#define	RCC_PCLK_CR3_SPI1_PCE_Msk	(0x1U << RCC_PCLK_CR3_SPI1_PCE_Pos)
	/* SPI1总线时钟使能，高有效 */

#define	RCC_PCLK_CR4_AT_PCE_Pos	4
#define	RCC_PCLK_CR4_AT_PCE_Msk	(0x1U << RCC_PCLK_CR4_AT_PCE_Pos)
	/* 高级定时器总线时钟使能，高有效 */

#define	RCC_PCLK_CR4_GT1_PCE_Pos	3
#define	RCC_PCLK_CR4_GT1_PCE_Msk	(0x1U << RCC_PCLK_CR4_GT1_PCE_Pos)
	/* 通用定时器1总线时钟使能，高有效 */

#define	RCC_PCLK_CR4_GT0_PCE_Pos	2
#define	RCC_PCLK_CR4_GT0_PCE_Msk	(0x1U << RCC_PCLK_CR4_GT0_PCE_Pos)
	/* 通用定时器0总线时钟使能，高有效 */

#define	RCC_PCLK_CR4_BT_PCE_Pos	0
#define	RCC_PCLK_CR4_BT_PCE_Msk	(0x1U << RCC_PCLK_CR4_BT_PCE_Pos)
	/* 基本定时器0总线时钟使能，高有效 */

#define	RCC_AHBM_CR_MPRIL_Pos	0	/* AHB Master优先级配置寄存器 */
#define	RCC_AHBM_CR_MPRIL_Msk	(0x1U << RCC_AHBM_CR_MPRIL_Pos)
#define	RCC_AHBM_CR_MPRIL_DMA	(0x0U << RCC_AHBM_CR_MPRIL_Pos)
#define	RCC_AHBM_CR_MPRIL_CPU	(0x1U << RCC_AHBM_CR_MPRIL_Pos)

#define	RCC_PRST_EN_PERHRSTEN_Pos	0	/* 外设模块复位使能 */
#define	RCC_PRST_EN_PERHRSTEN_Msk	(0xffffffffU << RCC_PRST_EN_PERHRSTEN_Pos)

#define	RCC_AHBRST_CR_DMARST_Pos	0	/* DMA模块复位 */
#define	RCC_AHBRST_CR_DMARST_Msk	(0x1U << RCC_AHBRST_CR_DMARST_Pos)
#define	RCC_AHBRST_CR_DMARST_NORST	(0x0U << RCC_AHBRST_CR_DMARST_Pos)	/* 0：不复位 */
#define	RCC_AHBRST_CR_DMARST_RST	(0x1U << RCC_AHBRST_CR_DMARST_Pos)	/* 1：复位 */

#define	RCC_APBRST_CR1_UART5RST_Pos	31	/* UART5模块复位 */
#define	RCC_APBRST_CR1_UART5RST_Msk	(0x1U << RCC_APBRST_CR1_UART5RST_Pos)
#define	RCC_APBRST_CR1_UART5RST_NORST	(0x0U << RCC_APBRST_CR1_UART5RST_Pos)	/* 0：不复位 */
#define	RCC_APBRST_CR1_UART5RST_RST	(0x1U << RCC_APBRST_CR1_UART5RST_Pos)	/* 1：复位 */

#define	RCC_APBRST_CR1_UART4RST_Pos	30	/* UART4模块复位 */
#define	RCC_APBRST_CR1_UART4RST_Msk	(0x1U << RCC_APBRST_CR1_UART4RST_Pos)
#define	RCC_APBRST_CR1_UART4RST_NORST	(0x0U << RCC_APBRST_CR1_UART4RST_Pos)	/* 0：不复位 */
#define	RCC_APBRST_CR1_UART4RST_RST	(0x1U << RCC_APBRST_CR1_UART4RST_Pos)	/* 1：复位 */

#define	RCC_APBRST_CR1_GT1RST_Pos	25	/* GPTIM1模块复位 */
#define	RCC_APBRST_CR1_GT1RST_Msk	(0x1U << RCC_APBRST_CR1_GT1RST_Pos)
#define	RCC_APBRST_CR1_GT1RST_NORST	(0x0U << RCC_APBRST_CR1_GT1RST_Pos)	/* 0：不复位 */
#define	RCC_APBRST_CR1_GT1RST_RST	(0x1U << RCC_APBRST_CR1_GT1RST_Pos)	/* 1：复位 */

#define	RCC_APBRST_CR1_GT0RST_Pos	24	/* GPTIM0模块复位 */
#define	RCC_APBRST_CR1_GT0RST_Msk	(0x1U << RCC_APBRST_CR1_GT0RST_Pos)
#define	RCC_APBRST_CR1_GT0RST_NORST	(0x0U << RCC_APBRST_CR1_GT0RST_Pos)	/* 0：不复位 */
#define	RCC_APBRST_CR1_GT0RST_RST	(0x1U << RCC_APBRST_CR1_GT0RST_Pos)	/* 1：复位 */

#define	RCC_APBRST_CR1_LCDRST_Pos	16	/* LCD模块复位 */
#define	RCC_APBRST_CR1_LCDRST_Msk	(0x1U << RCC_APBRST_CR1_LCDRST_Pos)
#define	RCC_APBRST_CR1_LCDRST_NORST	(0x0U << RCC_APBRST_CR1_LCDRST_Pos)	/* 0：不复位 */
#define	RCC_APBRST_CR1_LCDRST_RST	(0x1U << RCC_APBRST_CR1_LCDRST_Pos)	/* 1：复位 */

#define	RCC_APBRST_CR1_U7816RST_Pos	14	/* U7816模块复位 */
#define	RCC_APBRST_CR1_U7816RST_Msk	(0x1U << RCC_APBRST_CR1_U7816RST_Pos)
#define	RCC_APBRST_CR1_U7816RST_NORST	(0x0U << RCC_APBRST_CR1_U7816RST_Pos)	/* 0：不复位 */
#define	RCC_APBRST_CR1_U7816RST_RST	(0x1U << RCC_APBRST_CR1_U7816RST_Pos)	/* 1：复位 */

#define	RCC_APBRST_CR1_SPI2RST_Pos	10	/* SPI2模块复位 */
#define	RCC_APBRST_CR1_SPI2RST_Msk	(0x1U << RCC_APBRST_CR1_SPI2RST_Pos)
#define	RCC_APBRST_CR1_SPI2RST_NORST	(0x0U << RCC_APBRST_CR1_SPI2RST_Pos)	/* 0：不复位 */
#define	RCC_APBRST_CR1_SPI2RST_RST	(0x1U << RCC_APBRST_CR1_SPI2RST_Pos)	/* 1：复位 */

#define	RCC_APBRST_CR1_LPUART0RST_Pos	6	/* LPUART0模块复位 */
#define	RCC_APBRST_CR1_LPUART0RST_Msk	(0x1U << RCC_APBRST_CR1_LPUART0RST_Pos)
#define	RCC_APBRST_CR1_LPUART0RST_NORST	(0x0U << RCC_APBRST_CR1_LPUART0RST_Pos)	/* 0：不复位 */
#define	RCC_APBRST_CR1_LPUART0RST_RST	(0x1U << RCC_APBRST_CR1_LPUART0RST_Pos)	/* 1：复位 */

#define	RCC_APBRST_CR1_I2CRST_Pos	3	/* I2C模块复位 */
#define	RCC_APBRST_CR1_I2CRST_Msk	(0x1U << RCC_APBRST_CR1_I2CRST_Pos)
#define	RCC_APBRST_CR1_I2CRST_NORST	(0x0U << RCC_APBRST_CR1_I2CRST_Pos)	/* 0：不复位 */
#define	RCC_APBRST_CR1_I2CRST_RST	(0x1U << RCC_APBRST_CR1_I2CRST_Pos)	/* 1：复位 */

#define	RCC_APBRST_CR1_LPT32RST_Pos	0	/* LPTIM32模块复位 */
#define	RCC_APBRST_CR1_LPT32RST_Msk	(0x1U << RCC_APBRST_CR1_LPT32RST_Pos)
#define	RCC_APBRST_CR1_LPT32RST_NORST	(0x0U << RCC_APBRST_CR1_LPT32RST_Pos)	/* 0：不复位 */
#define	RCC_APBRST_CR1_LPT32RST_RST	(0x1U << RCC_APBRST_CR1_LPT32RST_Pos)	/* 1：复位 */

#define	RCC_APBRST_CR2_ATRST_Pos	31	/* ATIM模块复位 */
#define	RCC_APBRST_CR2_ATRST_Msk	(0x1U << RCC_APBRST_CR2_ATRST_Pos)
#define	RCC_APBRST_CR2_ATRST_NORST	(0x0U << RCC_APBRST_CR2_ATRST_Pos)	/* 0：不复位 */
#define	RCC_APBRST_CR2_ATRST_RST	(0x1U << RCC_APBRST_CR2_ATRST_Pos)	/* 1：复位 */

#define	RCC_APBRST_CR2_BTRST_Pos	28	/* BSTIM模块复位 */
#define	RCC_APBRST_CR2_BTRST_Msk	(0x1U << RCC_APBRST_CR2_BTRST_Pos)
#define	RCC_APBRST_CR2_BTRST_NORST	(0x0U << RCC_APBRST_CR2_BTRST_Pos)	/* 0：不复位 */
#define	RCC_APBRST_CR2_BTRST_RST	(0x1U << RCC_APBRST_CR2_BTRST_Pos)	/* 1：复位 */

#define	RCC_APBRST_CR2_ADCCRST_Pos	24	/* ADC控制器复位 */
#define	RCC_APBRST_CR2_ADCCRST_Msk	(0x1U << RCC_APBRST_CR2_ADCCRST_Pos)
#define	RCC_APBRST_CR2_ADCCRST_NORST	(0x0U << RCC_APBRST_CR2_ADCCRST_Pos)	/* 0：不复位 */
#define	RCC_APBRST_CR2_ADCCRST_RST	(0x1U << RCC_APBRST_CR2_ADCCRST_Pos)	/* 1：复位 */

#define	RCC_APBRST_CR2_ADCRST_Pos	23	/* ADC模块复位 */
#define	RCC_APBRST_CR2_ADCRST_Msk	(0x1U << RCC_APBRST_CR2_ADCRST_Pos)
#define	RCC_APBRST_CR2_ADCRST_NORST	(0x0U << RCC_APBRST_CR2_ADCRST_Pos)	/* 0：不复位 */
#define	RCC_APBRST_CR2_ADCRST_RST	(0x1U << RCC_APBRST_CR2_ADCRST_Pos)	/* 1：复位 */

#define	RCC_APBRST_CR2_OPARST_Pos	22	/* 运放模块复位 */
#define	RCC_APBRST_CR2_OPARST_Msk	(0x1U << RCC_APBRST_CR2_OPARST_Pos)
#define	RCC_APBRST_CR2_OPARST_NORST	(0x0U << RCC_APBRST_CR2_OPARST_Pos)	/* 0：不复位 */
#define	RCC_APBRST_CR2_OPARST_RST	(0x1U << RCC_APBRST_CR2_OPARST_Pos)	/* 1：复位 */

#define	RCC_APBRST_CR2_AESRST_Pos	18	/* AES模块复位 */
#define	RCC_APBRST_CR2_AESRST_Msk	(0x1U << RCC_APBRST_CR2_AESRST_Pos)
#define	RCC_APBRST_CR2_AESRST_NORST	(0x0U << RCC_APBRST_CR2_AESRST_Pos)	/* 0：不复位 */
#define	RCC_APBRST_CR2_AESRST_RST	(0x1U << RCC_APBRST_CR2_AESRST_Pos)	/* 1：复位 */

#define	RCC_APBRST_CR2_CRCRST_Pos	17	/* CRC模块复位 */
#define	RCC_APBRST_CR2_CRCRST_Msk	(0x1U << RCC_APBRST_CR2_CRCRST_Pos)
#define	RCC_APBRST_CR2_CRCRST_NORST	(0x0U << RCC_APBRST_CR2_CRCRST_Pos)	/* 0：不复位 */
#define	RCC_APBRST_CR2_CRCRST_RST	(0x1U << RCC_APBRST_CR2_CRCRST_Pos)	/* 1：复位 */

#define	RCC_APBRST_CR2_RNGRST_Pos	16	/* RNG模块复位 */
#define	RCC_APBRST_CR2_RNGRST_Msk	(0x1U << RCC_APBRST_CR2_RNGRST_Pos)
#define	RCC_APBRST_CR2_RNGRST_NORST	(0x0U << RCC_APBRST_CR2_RNGRST_Pos)	/* 0：不复位 */
#define	RCC_APBRST_CR2_RNGRST_RST	(0x1U << RCC_APBRST_CR2_RNGRST_Pos)	/* 1：复位 */

#define	RCC_APBRST_CR2_UART1RST_Pos	12	/* UART1模块复位 */
#define	RCC_APBRST_CR2_UART1RST_Msk	(0x1U << RCC_APBRST_CR2_UART1RST_Pos)
#define	RCC_APBRST_CR2_UART1RST_NORST	(0x0U << RCC_APBRST_CR2_UART1RST_Pos)	/* 0：不复位 */
#define	RCC_APBRST_CR2_UART1RST_RST	(0x1U << RCC_APBRST_CR2_UART1RST_Pos)	/* 1：复位 */

#define	RCC_APBRST_CR2_UART0RST_Pos	11	/* UART0模块复位 */
#define	RCC_APBRST_CR2_UART0RST_Msk	(0x1U << RCC_APBRST_CR2_UART0RST_Pos)
#define	RCC_APBRST_CR2_UART0RST_NORST	(0x0U << RCC_APBRST_CR2_UART0RST_Pos)	/* 0：不复位 */
#define	RCC_APBRST_CR2_UART0RST_RST	(0x1U << RCC_APBRST_CR2_UART0RST_Pos)	/* 1：复位 */

#define	RCC_APBRST_CR2_SPI1RST_Pos	9	/* SPI1模块复位 */
#define	RCC_APBRST_CR2_SPI1RST_Msk	(0x1U << RCC_APBRST_CR2_SPI1RST_Pos)
#define	RCC_APBRST_CR2_SPI1RST_NORST	(0x0U << RCC_APBRST_CR2_SPI1RST_Pos)	/* 0：不复位 */
#define	RCC_APBRST_CR2_SPI1RST_RST	(0x1U << RCC_APBRST_CR2_SPI1RST_Pos)	/* 1：复位 */

#define	RCC_APBRST_CR2_UCIRRST_Pos	8	/* UART红外调制模块复位 */
#define	RCC_APBRST_CR2_UCIRRST_Msk	(0x1U << RCC_APBRST_CR2_UCIRRST_Pos)
#define	RCC_APBRST_CR2_UCIRRST_NORST	(0x0U << RCC_APBRST_CR2_UCIRRST_Pos)	/* 0：不复位 */
#define	RCC_APBRST_CR2_UCIRRST_RST	(0x1U << RCC_APBRST_CR2_UCIRRST_Pos)	/* 1：复位 */

#define	RCC_APBRST_CR2_LPUART1RST_Pos	7	/* LPUART1模块复位 */
#define	RCC_APBRST_CR2_LPUART1RST_Msk	(0x1U << RCC_APBRST_CR2_LPUART1RST_Pos)
#define	RCC_APBRST_CR2_LPUART1RST_NORST	(0x0U << RCC_APBRST_CR2_LPUART1RST_Pos)	/* 0：不复位 */
#define	RCC_APBRST_CR2_LPUART1RST_RST	(0x1U << RCC_APBRST_CR2_LPUART1RST_Pos)	/* 1：复位 */

#define	RCC_XTHF_CR_CFG_Pos	8	/* XTHF振荡强度配置 */
#define	RCC_XTHF_CR_CFG_Msk	(0x7U << RCC_XTHF_CR_CFG_Pos)

#define	RCC_XTHF_CR_EN_Pos	0	/* XTHF使能寄存器 */
#define	RCC_XTHF_CR_EN_Msk	(0x1U << RCC_XTHF_CR_EN_Pos)
	/* 0：关闭XTHF */
	/* 1：使能XTHF */

#define	RCC_RC4M_CR_PSC_Pos	16	/* RC4M输出预分频  */
#define	RCC_RC4M_CR_PSC_Msk	(0x3U << RCC_RC4M_CR_PSC_Pos)
#define	RCC_RC4M_CR_PSC_DIV1	(0x0U << RCC_RC4M_CR_PSC_Pos)	/* 00：不分频 */
#define	RCC_RC4M_CR_PSC_DIV4	(0x1U << RCC_RC4M_CR_PSC_Pos)	/* 01：4分频 */
#define	RCC_RC4M_CR_PSC_DIV8	(0x2U << RCC_RC4M_CR_PSC_Pos)	/* 10：8分频 */
#define	RCC_RC4M_CR_PSC_DIV16	(0x3U << RCC_RC4M_CR_PSC_Pos)	/* 11：16分频 */

#define	RCC_RC4M_CR_EN_Pos	0	/* RC4M使能寄存器 */
#define	RCC_RC4M_CR_EN_Msk	(0x1U << RCC_RC4M_CR_EN_Pos)
	/* 0：关闭RC4M */
	/* 1：打开RC4M */

#define	RCC_RCHF_TR_TRIM_Pos	0	/* RCHF频率调校寄存器 */
#define	RCC_RCHF_TR_TRIM_Msk	(0x7fU << RCC_RCHF_TR_TRIM_Pos)

#define	RCC_OPC_CR1_EXTICKE_Pos	31
#define	RCC_OPC_CR1_EXTICKE_Msk	(0x1U << RCC_OPC_CR1_EXTICKE_Pos)
	/* EXTI工作时钟使能，高有效 */

#define	RCC_OPC_CR1_EXTICKS_Pos	30	/* EXTI中断采样时钟选择 */
#define	RCC_OPC_CR1_EXTICKS_Msk	(0x1U << RCC_OPC_CR1_EXTICKS_Pos)
#define	RCC_OPC_CR1_EXTICKS_HCLK	(0x0U << RCC_OPC_CR1_EXTICKS_Pos)	/* 0：外部引脚中断使用HCLK采样 */
#define	RCC_OPC_CR1_EXTICKS_LSCLK	(0x1U << RCC_OPC_CR1_EXTICKS_Pos)	/* 1：外部引脚中断使用LSCLK采样 */

#define	RCC_OPC_CR1_LPUART1CKE_Pos	29
#define	RCC_OPC_CR1_LPUART1CKE_Msk	(0x1U << RCC_OPC_CR1_LPUART1CKE_Pos)
	/* LPUART1工作时钟使能，高有效 */

#define	RCC_OPC_CR1_LPUART0CKE_Pos	28
#define	RCC_OPC_CR1_LPUART0CKE_Msk	(0x1U << RCC_OPC_CR1_LPUART0CKE_Pos)
	/* LPUART0工作时钟使能，高有效 */

#define	RCC_OPC_CR1_LPUART1CKS_Pos	26
#define	RCC_OPC_CR1_LPUART1CKS_Msk	(0x3U << RCC_OPC_CR1_LPUART1CKS_Pos)
#define	RCC_OPC_CR1_LPUART1CKS_LSCLK	(0x0U << RCC_OPC_CR1_LPUART1CKS_Pos)	/* LPUART1工作时钟选择 */
#define	RCC_OPC_CR1_LPUART1CKS_RCHFDIV	(0x1U << RCC_OPC_CR1_LPUART1CKS_Pos)
#define	RCC_OPC_CR1_LPUART1CKS_RC4MDIV	(0x2U << RCC_OPC_CR1_LPUART1CKS_Pos)

#define	RCC_OPC_CR1_LPUART0CKS_Pos	24
#define	RCC_OPC_CR1_LPUART0CKS_Msk	(0x3U << RCC_OPC_CR1_LPUART0CKS_Pos)
#define	RCC_OPC_CR1_LPUART0CKS_LSCLK	(0x0U << RCC_OPC_CR1_LPUART0CKS_Pos)	/* LPUART0工作时钟选择 */
#define	RCC_OPC_CR1_LPUART0CKS_RCHFDIV	(0x1U << RCC_OPC_CR1_LPUART0CKS_Pos)
#define	RCC_OPC_CR1_LPUART0CKS_RC4MDIV	(0x2U << RCC_OPC_CR1_LPUART0CKS_Pos)

#define	RCC_OPC_CR1_BEEPCKE_Pos	21
#define	RCC_OPC_CR1_BEEPCKE_Msk	(0x1U << RCC_OPC_CR1_BEEPCKE_Pos)
	/* Beeper工作时钟使能，高有效 */

#define	RCC_OPC_CR1_I2CCKE_Pos	20
#define	RCC_OPC_CR1_I2CCKE_Msk	(0x1U << RCC_OPC_CR1_I2CCKE_Pos)
	/* I2C工作时钟使能 */

#define	RCC_OPC_CR1_BEEPCKS_Pos	18
#define	RCC_OPC_CR1_BEEPCKS_Msk	(0x1U << RCC_OPC_CR1_BEEPCKS_Pos)
#define	RCC_OPC_CR1_BEEPCKS_XTLF	(0x0U << RCC_OPC_CR1_BEEPCKS_Pos)	/* Beeper工作时钟选择 */
#define	RCC_OPC_CR1_BEEPCKS_RCLP	(0x1U << RCC_OPC_CR1_BEEPCKS_Pos)

#define	RCC_OPC_CR1_I2CCKS_Pos	16	/* I2C主机工作时钟选择 */
#define	RCC_OPC_CR1_I2CCKS_Msk	(0x3U << RCC_OPC_CR1_I2CCKS_Pos)
#define	RCC_OPC_CR1_I2CCKS_APBCLK	(0x0U << RCC_OPC_CR1_I2CCKS_Pos)	/* 00：APBCLK */
#define	RCC_OPC_CR1_I2CCKS_RCHF	(0x1U << RCC_OPC_CR1_I2CCKS_Pos)	/* 01：RCHF */
#define	RCC_OPC_CR1_I2CCKS_SYSCLK	(0x2U << RCC_OPC_CR1_I2CCKS_Pos)	/* 10：SYSCLK */
#define	RCC_OPC_CR1_I2CCKS_RC4MPSC	(0x3U << RCC_OPC_CR1_I2CCKS_Pos)	/* 11：RC4M_PSC */

#define	RCC_OPC_CR1_UART1CKE_Pos	9
#define	RCC_OPC_CR1_UART1CKE_Msk	(0x1U << RCC_OPC_CR1_UART1CKE_Pos)
	/* UART1工作时钟使能，高有效 */

#define	RCC_OPC_CR1_UART0CKE_Pos	8
#define	RCC_OPC_CR1_UART0CKE_Msk	(0x1U << RCC_OPC_CR1_UART0CKE_Pos)
	/* UART0工作时钟使能，高有效 */

#define	RCC_OPC_CR1_UART1CKS_Pos	2	/* UART1工作时钟选择 */
#define	RCC_OPC_CR1_UART1CKS_Msk	(0x3U << RCC_OPC_CR1_UART1CKS_Pos)
#define	RCC_OPC_CR1_UART1CKS_APBCLK	(0x0U << RCC_OPC_CR1_UART1CKS_Pos)	/* 00：APBCLK */
#define	RCC_OPC_CR1_UART1CKS_RCHF	(0x1U << RCC_OPC_CR1_UART1CKS_Pos)	/* 01：RCHF */
#define	RCC_OPC_CR1_UART1CKS_SYSCLK	(0x2U << RCC_OPC_CR1_UART1CKS_Pos)	/* 10：SYSCLK */
#define	RCC_OPC_CR1_UART1CKS_RC4MPSC	(0x3U << RCC_OPC_CR1_UART1CKS_Pos)	/* 11：RC4M_PSC */

#define	RCC_OPC_CR1_UART0CKS_Pos	0	/* UART0工作时钟选择 */
#define	RCC_OPC_CR1_UART0CKS_Msk	(0x3U << RCC_OPC_CR1_UART0CKS_Pos)
#define	RCC_OPC_CR1_UART0CKS_APBCLK	(0x0U << RCC_OPC_CR1_UART0CKS_Pos)	/* 00：APBCLK */
#define	RCC_OPC_CR1_UART0CKS_RCHF	(0x1U << RCC_OPC_CR1_UART0CKS_Pos)	/* 01：RCHF */
#define	RCC_OPC_CR1_UART0CKS_SYSCLK	(0x2U << RCC_OPC_CR1_UART0CKS_Pos)	/* 10：SYSCLK */
#define	RCC_OPC_CR1_UART0CKS_RC4MPSC	(0x3U << RCC_OPC_CR1_UART0CKS_Pos)	/* 11：RC4M_PSC */

#define	RCC_OPC_CR2_RNGPRSC_Pos	28	/* 随机数发生器工作时钟分频 */
#define	RCC_OPC_CR2_RNGPRSC_Msk	(0x7U << RCC_OPC_CR2_RNGPRSC_Pos)
#define	RCC_OPC_CR2_RNGPRSC_DIV1	(0x0U << RCC_OPC_CR2_RNGPRSC_Pos)	/* 000：不分频 */
#define	RCC_OPC_CR2_RNGPRSC_DIV2	(0x1U << RCC_OPC_CR2_RNGPRSC_Pos)	/* 001：2分频 */
#define	RCC_OPC_CR2_RNGPRSC_DIV4	(0x2U << RCC_OPC_CR2_RNGPRSC_Pos)	/* 010：4分频 */
#define	RCC_OPC_CR2_RNGPRSC_DIV8	(0x3U << RCC_OPC_CR2_RNGPRSC_Pos)	/* 011：8分频 */
#define	RCC_OPC_CR2_RNGPRSC_DIV16	(0x4U << RCC_OPC_CR2_RNGPRSC_Pos)	/* 100：16分频 */
#define	RCC_OPC_CR2_RNGPRSC_DIV32	(0x5U << RCC_OPC_CR2_RNGPRSC_Pos)	/* 101：32分频 */

#define	RCC_OPC_CR2_ADCPRSC_Pos	24	/* ADC工作时钟预分频 */
#define	RCC_OPC_CR2_ADCPRSC_Msk	(0x7U << RCC_OPC_CR2_ADCPRSC_Pos)
#define	RCC_OPC_CR2_ADCPRSC_DIV1	(0x0U << RCC_OPC_CR2_ADCPRSC_Pos)	/* 000：不分频 */
#define	RCC_OPC_CR2_ADCPRSC_DIV2	(0x1U << RCC_OPC_CR2_ADCPRSC_Pos)	/* 001：2分频 */
#define	RCC_OPC_CR2_ADCPRSC_DIV4	(0x2U << RCC_OPC_CR2_ADCPRSC_Pos)	/* 010：4分频 */
#define	RCC_OPC_CR2_ADCPRSC_DIV8	(0x3U << RCC_OPC_CR2_ADCPRSC_Pos)	/* 011：8分频 */
#define	RCC_OPC_CR2_ADCPRSC_DIV16	(0x4U << RCC_OPC_CR2_ADCPRSC_Pos)	/* 100：16分频 */
#define	RCC_OPC_CR2_ADCPRSC_DIV32	(0x5U << RCC_OPC_CR2_ADCPRSC_Pos)	/* 101：32分频 */

#define	RCC_OPC_CR2_FLSCKE_Pos	22
#define	RCC_OPC_CR2_FLSCKE_Msk	(0x1U << RCC_OPC_CR2_FLSCKE_Pos)
	/* Flash擦写时钟使能，高有效  */

#define	RCC_OPC_CR2_RNGCKE_Pos	21
#define	RCC_OPC_CR2_RNGCKE_Msk	(0x1U << RCC_OPC_CR2_RNGCKE_Pos)
	/* 随机数发生器工作时钟使能，高有效  */

#define	RCC_OPC_CR2_ADCCKE_Pos	20
#define	RCC_OPC_CR2_ADCCKE_Msk	(0x1U << RCC_OPC_CR2_ADCCKE_Pos)
	/* ADC工作时钟使能，高有效 */

#define	RCC_OPC_CR2_ADCCKS_Pos	16	/* ADC工作时钟选择 */
#define	RCC_OPC_CR2_ADCCKS_Msk	(0x3U << RCC_OPC_CR2_ADCCKS_Pos)
#define	RCC_OPC_CR2_ADCCKS_RC4MPSC	(0x0U << RCC_OPC_CR2_ADCCKS_Pos)	/* 00：RC4M_PSC */
#define	RCC_OPC_CR2_ADCCKS_RCHF	(0x1U << RCC_OPC_CR2_ADCCKS_Pos)	/* 01：RCHF */
#define	RCC_OPC_CR2_ADCCKS_XTHF	(0x2U << RCC_OPC_CR2_ADCCKS_Pos)	/* 10：XTHF */
#define	RCC_OPC_CR2_ADCCKS_PLL	(0x3U << RCC_OPC_CR2_ADCCKS_Pos)	/* 11：PLL */

#define	RCC_OPC_CR2_LPTCKE_Pos	12
#define	RCC_OPC_CR2_LPTCKE_Msk	(0x1U << RCC_OPC_CR2_LPTCKE_Pos)
	/* LPTIM工作时钟使能，高有效 */

#define	RCC_OPC_CR2_LPTCKS_Pos	8	/* LPTIM工作时钟选择 */
#define	RCC_OPC_CR2_LPTCKS_Msk	(0x3U << RCC_OPC_CR2_LPTCKS_Pos)
#define	RCC_OPC_CR2_LPTCKS_APBCLK	(0x0U << RCC_OPC_CR2_LPTCKS_Pos)	/* 00：APBCLK */
#define	RCC_OPC_CR2_LPTCKS_LSCLK	(0x1U << RCC_OPC_CR2_LPTCKS_Pos)	/* 01：LSCLK */
#define	RCC_OPC_CR2_LPTCKS_RCLP	(0x2U << RCC_OPC_CR2_LPTCKS_Pos)	/* 10：RCLP */
#define	RCC_OPC_CR2_LPTCKS_RC4MPSC	(0x3U << RCC_OPC_CR2_LPTCKS_Pos)	/* 11：RC4MPSC */

#define	RCC_OPC_CR2_BTCKE_Pos	4
#define	RCC_OPC_CR2_BTCKE_Msk	(0x1U << RCC_OPC_CR2_BTCKE_Pos)
	/* BSTIM工作时钟使能，高有效 */

#define	RCC_OPC_CR2_BTCKS_Pos	0	/* BSTIM工作时钟源选择 */
#define	RCC_OPC_CR2_BTCKS_Msk	(0x3U << RCC_OPC_CR2_BTCKS_Pos)
#define	RCC_OPC_CR2_BTCKS_APBCLK	(0x0U << RCC_OPC_CR2_BTCKS_Pos)	/* 00：APBCLK */
#define	RCC_OPC_CR2_BTCKS_LSCLK	(0x1U << RCC_OPC_CR2_BTCKS_Pos)	/* 01：LSCLK */
#define	RCC_OPC_CR2_BTCKS_RCLP	(0x2U << RCC_OPC_CR2_BTCKS_Pos)	/* 10：RCLP */
#define	RCC_OPC_CR2_BTCKS_RC4MPSC	(0x3U << RCC_OPC_CR2_BTCKS_Pos)	/* 11：RC4MPSC */

#define	RCC_FDET_IER_HFDET_IE_Pos	1
#define	RCC_FDET_IER_HFDET_IE_Msk	(0x1U << RCC_FDET_IER_HFDET_IE_Pos)
	/* XTHF高频检测报警中断使能，1有效 */

#define	RCC_FDET_IER_LFDET_IE_Pos	0
#define	RCC_FDET_IER_LFDET_IE_Msk	(0x1U << RCC_FDET_IER_LFDET_IE_Pos)
	/* XTLF低频检测报警中断使能，1有效 */

#define	RCC_FDET_ISR_HFDETO_Pos	9	/* 高频晶体停振检测模块输出 */
#define	RCC_FDET_ISR_HFDETO_Msk	(0x1U << RCC_FDET_ISR_HFDETO_Pos)

#define	RCC_FDET_ISR_LFDETO_Pos	8	/* 低频晶体停振检测模块输出 */
#define	RCC_FDET_ISR_LFDETO_Msk	(0x1U << RCC_FDET_ISR_LFDETO_Pos)

#define	RCC_FDET_ISR_HFDETIF_Pos	1	/* 高频停振检测中断标志寄存器 */
#define	RCC_FDET_ISR_HFDETIF_Msk	(0x1U << RCC_FDET_ISR_HFDETIF_Pos)

#define	RCC_FDET_ISR_LFDETIF_Pos	0	/* 低频停振检测中断标志寄存器 */
#define	RCC_FDET_ISR_LFDETIF_Msk	(0x1U << RCC_FDET_ISR_LFDETIF_Pos)

#define	RCC_PDR_CR_CFG_Pos	1	/* 下电复位电压配置 */
#define	RCC_PDR_CR_CFG_Msk	(0x3U << RCC_PDR_CR_CFG_Pos)
#define	RCC_PDR_CR_CFG_1_5V	(0x0U << RCC_PDR_CR_CFG_Pos)	/* 00—1.5V */
#define	RCC_PDR_CR_CFG_1_25V	(0x1U << RCC_PDR_CR_CFG_Pos)	/* 01—1.25V */
#define	RCC_PDR_CR_CFG_1_35V	(0x2U << RCC_PDR_CR_CFG_Pos)	/* 10—1.35V */
#define	RCC_PDR_CR_CFG_1_4V	(0x3U << RCC_PDR_CR_CFG_Pos)	/* 11—1.4V */

#define	RCC_PDR_CR_EN_Pos	0	/* 下电复位使能 */
#define	RCC_PDR_CR_EN_Msk	(0x1U << RCC_PDR_CR_EN_Pos)

#define	RCC_BOR_CR_CFG_Pos	1	/* 下电复位电压配置 */
#define	RCC_BOR_CR_CFG_Msk	(0x3U << RCC_BOR_CR_CFG_Pos)
#define	RCC_BOR_CR_CFG_1_7V	(0x0U << RCC_BOR_CR_CFG_Pos)	/* 00—1.7V */
#define	RCC_BOR_CR_CFG_1_6V	(0x1U << RCC_BOR_CR_CFG_Pos)	/* 01—1.6V */
#define	RCC_BOR_CR_CFG_1_65V	(0x2U << RCC_BOR_CR_CFG_Pos)	/* 10—1.65V */
#define	RCC_BOR_CR_CFG_1_75V	(0x3U << RCC_BOR_CR_CFG_Pos)	/* 11—1.75V */

#define	RCC_BOR_CR_OFF_BOR_Pos	0	/* 下电复位使能 */
#define	RCC_BOR_CR_OFF_BOR_Msk	(0x1U << RCC_BOR_CR_OFF_BOR_Pos)
	/* 0：使能BOR */
	/* 1：关闭BOR */
  
//Macro_End
								
/* Exported functions --------------------------------------------------------*/ 
extern void RCC_Deinit(void);
extern void RCC_LKP_CR_RST_EN_Setable(FunState NewState);
extern FunState RCC_LKP_CR_RST_EN_Getable(void);
extern void RCC_SOFTRST_Write(uint32_t SetValue);
extern void RCC_RSTFR_NRSTN_FLAG_Clr(void);
extern FlagStatus RCC_RSTFR_NRSTN_FLAG_Chk(void);
extern void RCC_RSTFR_TESTN_FLAG_Clr(void);
extern FlagStatus RCC_RSTFR_TESTN_FLAG_Chk(void);
extern void RCC_RSTFR_PORN_FLAG_Clr(void);
extern FlagStatus RCC_RSTFR_PORN_FLAG_Chk(void);
extern void RCC_RSTFR_PDRN_FLAG_Clr(void);
extern FlagStatus RCC_RSTFR_PDRN_FLAG_Chk(void);
extern void RCC_RSTFR_SOFTN_FLAG_Clr(void);
extern FlagStatus RCC_RSTFR_SOFTN_FLAG_Chk(void);
extern void RCC_RSTFR_IWDTN_FLAG_Clr(void);
extern FlagStatus RCC_RSTFR_IWDTN_FLAG_Chk(void);
extern void RCC_RSTFR_WWDTN_FLAG_Clr(void);
extern FlagStatus RCC_RSTFR_WWDTN_FLAG_Chk(void);
extern void RCC_RSTFR_LKUPN_FLAG_Clr(void);
extern FlagStatus RCC_RSTFR_LKUPN_FLAG_Chk(void);
extern void RCC_RSTFR_NVICN_FLAG_Clr(void);
extern FlagStatus RCC_RSTFR_NVICN_FLAG_Chk(void);

/* LSCLK自动切换使能 相关函数 */
extern void RCC_SYSCLK_CR_LSCATS_Setable(FunState NewState);
extern FunState RCC_SYSCLK_CR_LSCATS_Getable(void);

/* Sleep/DeepSleep模式下EXTI采样设置 相关函数 */
extern void RCC_SYSCLK_CR_SLP_ENEXTI_Setable(FunState NewState);
extern FunState RCC_SYSCLK_CR_SLP_ENEXTI_Getable(void);

/* APB时钟分频选择 相关函数 */
extern void RCC_SYSCLK_CR_APBPRES_Set(uint32_t SetValue);
extern uint32_t RCC_SYSCLK_CR_APBPRES_Get(void);

/* AHB时钟分频选择 相关函数 */
extern void RCC_SYSCLK_CR_AHBPRES_Set(uint32_t SetValue);
extern uint32_t RCC_SYSCLK_CR_AHBPRES_Get(void);

/* CPU内核systick工作时钟选择 相关函数 */
extern void RCC_SYSCLK_CR_STCLKSEL_Set(uint32_t SetValue);
extern uint32_t RCC_SYSCLK_CR_STCLKSEL_Get(void);

/* 系统时钟源选择 相关函数 */
extern void RCC_SYSCLK_CR_SYSCLKSEL_Set(uint32_t SetValue);
extern uint32_t RCC_SYSCLK_CR_SYSCLKSEL_Get(void);

/* RCHF频率选择寄存器 相关函数 */
extern void RCC_RCHF_CR_FSEL_Set(uint32_t SetValue);
extern uint32_t RCC_RCHF_CR_FSEL_Get(void);

/* RCHF使能寄存器 相关函数 */
extern void RCC_RCHF_CR_EN_Setable(FunState NewState);
extern FunState RCC_RCHF_CR_EN_Getable(void);

/* RC4M频率调校寄存器 相关函数 */
extern void RCC_RC4M_TR_Write(uint32_t SetValue);
extern uint32_t RCC_RC4M_TR_Read(void);

/* PLL倍频比 相关函数 */
extern void RCC_PLL_CR_Write(uint32_t SetValue);
extern uint32_t RCC_PLL_CR_Read(void);

/* PLL锁定标志 相关函数 */
extern FlagStatus RCC_PLL_CR_LOCKED_Chk(void);

/* PLL参考时钟预分频（目标是产生1MHz参考时钟给PLL） 相关函数 */
extern void RCC_PLL_CR_REFPRSC_Set(uint32_t SetValue);
extern uint32_t RCC_PLL_CR_REFPRSC_Get(void);

/* PLL输出选择寄存器 相关函数 */
extern void RCC_PLL_CR_OSEL_Set(uint32_t SetValue);
extern uint32_t RCC_PLL_CR_OSEL_Get(void);

/* PLL输入选择寄存器 相关函数 */
extern void RCC_PLL_CR_INSEL_Set(uint32_t SetValue);
extern uint32_t RCC_PLL_CR_INSEL_Get(void);

/* PLL使能寄存器 相关函数 */
extern void RCC_PLL_CR_EN_Setable(FunState NewState);
extern FunState RCC_PLL_CR_EN_Getable(void);

/* RCLP使能标志信号 相关函数 */
extern FlagStatus RCC_RCLP_CR_OFF_EN_Chk(void);

/* 休眠模式下RCLP控制寄存器 相关函数 */
extern void RCC_RCLP_CR_LPM_RCLP_OFF_Setable(FunState NewState);
extern FunState RCC_RCLP_CR_LPM_RCLP_OFF_Getable(void);

/* RCLP调校值寄存器 相关函数 */
extern void RCC_RCLP_TR_Write(uint32_t SetValue);
extern uint32_t RCC_RCLP_TR_Read(void);

/* XTLF备份时钟手动切换寄存器 相关函数 */
extern void RCC_XTLF_CR_Write(uint32_t SetValue);
extern uint32_t RCC_XTLF_CR_Read(void);

/* XTLF使能寄存器 相关函数 */
extern void RCC_XTLF_CR_EN_Set(uint32_t SetValue);
extern uint32_t RCC_XTLF_CR_EN_Get(void);

/* XTLF工作电流选择 相关函数 */
extern void RCC_XTLF_CR_IPW_Set(uint32_t SetValue);
extern uint32_t RCC_XTLF_CR_IPW_Get(void);

/* AHB Master优先级配置寄存器 相关函数 */
extern void RCC_AHBM_CR_MPRIL_Set(uint32_t SetValue);
extern uint32_t RCC_AHBM_CR_MPRIL_Get(void);

/* 外设模块复位使能 相关函数 */
extern void RCC_PRST_EN_Write(uint32_t SetValue);
extern uint32_t RCC_PRST_EN_Read(void);

/* DMA模块复位 相关函数 */
extern void RCC_AHBRST_CR_DMARST_Setable(FunState NewState);
extern FunState RCC_AHBRST_CR_DMARST_Getable(void);

/* UART5模块复位 相关函数 */
extern void RCC_APBRST_CR1_UART5RST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR1_UART5RST_Getable(void);

/* UART4模块复位 相关函数 */
extern void RCC_APBRST_CR1_UART4RST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR1_UART4RST_Getable(void);

/* GPTIM1模块复位 相关函数 */
extern void RCC_APBRST_CR1_GT1RST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR1_GT1RST_Getable(void);

/* GPTIM0模块复位 相关函数 */
extern void RCC_APBRST_CR1_GT0RST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR1_GT0RST_Getable(void);

/* LCD模块复位 相关函数 */
extern void RCC_APBRST_CR1_LCDRST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR1_LCDRST_Getable(void);

/* U7816模块复位 相关函数 */
extern void RCC_APBRST_CR1_U7816RST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR1_U7816RST_Getable(void);

/* SPI2模块复位 相关函数 */
extern void RCC_APBRST_CR1_SPI2RST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR1_SPI2RST_Getable(void);

/* LPUART0模块复位 相关函数 */
extern void RCC_APBRST_CR1_LPUART0RST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR1_LPUART0RST_Getable(void);

/* I2C模块复位 相关函数 */
extern void RCC_APBRST_CR1_I2CRST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR1_I2CRST_Getable(void);

/* LPTIM32模块复位 相关函数 */
extern void RCC_APBRST_CR1_LPT32RST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR1_LPT32RST_Getable(void);

/* ATIM模块复位 相关函数 */
extern void RCC_APBRST_CR2_ATRST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR2_ATRST_Getable(void);

/* BSTIM模块复位 相关函数 */
extern void RCC_APBRST_CR2_BTRST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR2_BTRST_Getable(void);

/* ADC控制器复位 相关函数 */
extern void RCC_APBRST_CR2_ADCCRST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR2_ADCCRST_Getable(void);

/* ADC模块复位 相关函数 */
extern void RCC_APBRST_CR2_ADCRST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR2_ADCRST_Getable(void);

/* 运放模块复位 相关函数 */
extern void RCC_APBRST_CR2_OPARST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR2_OPARST_Getable(void);

/* AES模块复位 相关函数 */
extern void RCC_APBRST_CR2_AESRST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR2_AESRST_Getable(void);

/* CRC模块复位 相关函数 */
extern void RCC_APBRST_CR2_CRCRST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR2_CRCRST_Getable(void);

/* RNG模块复位 相关函数 */
extern void RCC_APBRST_CR2_RNGRST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR2_RNGRST_Getable(void);

/* UART1模块复位 相关函数 */
extern void RCC_APBRST_CR2_UART1RST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR2_UART1RST_Getable(void);

/* UART0模块复位 相关函数 */
extern void RCC_APBRST_CR2_UART0RST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR2_UART0RST_Getable(void);

/* SPI1模块复位 相关函数 */
extern void RCC_APBRST_CR2_SPI1RST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR2_SPI1RST_Getable(void);

/* UART红外调制模块复位 相关函数 */
extern void RCC_APBRST_CR2_UCIRRST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR2_UCIRRST_Getable(void);

/* LPUART1模块复位 相关函数 */
extern void RCC_APBRST_CR2_LPUART1RST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR2_LPUART1RST_Getable(void);

/* XTHF振荡强度配置 相关函数 */
extern void RCC_XTHF_CR_CFG_Set(uint32_t SetValue);
extern uint32_t RCC_XTHF_CR_CFG_Get(void);

/* XTHF使能寄存器 相关函数 */
extern void RCC_XTHF_CR_EN_Setable(FunState NewState);
extern FunState RCC_XTHF_CR_EN_Getable(void);

/* RC4M输出预分频  相关函数 */
extern void RCC_RC4M_CR_PSC_Set(uint32_t SetValue);
extern uint32_t RCC_RC4M_CR_PSC_Get(void);

/* RC4M使能寄存器 相关函数 */
extern void RCC_RC4M_CR_EN_Setable(FunState NewState);
extern FunState RCC_RC4M_CR_EN_Getable(void);

/* RCHF频率调校寄存器 相关函数 */
extern void RCC_RCHF_TR_Write(uint32_t SetValue);
extern uint32_t RCC_RCHF_TR_Read(void);

extern void RCC_OPC_CR1_EXTICKE_Setable(FunState NewState);
extern FunState RCC_OPC_CR1_EXTICKE_Getable(void);

/* EXTI中断采样时钟选择 相关函数 */
extern void RCC_OPC_CR1_EXTICKS_Set(uint32_t SetValue);
extern uint32_t RCC_OPC_CR1_EXTICKS_Get(void);
extern void RCC_OPC_CR1_LPUART1CKE_Setable(FunState NewState);
extern FunState RCC_OPC_CR1_LPUART1CKE_Getable(void);
extern void RCC_OPC_CR1_LPUART0CKE_Setable(FunState NewState);
extern FunState RCC_OPC_CR1_LPUART0CKE_Getable(void);
extern void RCC_OPC_CR1_LPUART1CKS_Set(uint32_t SetValue);
extern uint32_t RCC_OPC_CR1_LPUART1CKS_Get(void);
extern void RCC_OPC_CR1_LPUART0CKS_Set(uint32_t SetValue);
extern uint32_t RCC_OPC_CR1_LPUART0CKS_Get(void);
extern void RCC_OPC_CR1_BEEPCKE_Setable(FunState NewState);
extern FunState RCC_OPC_CR1_BEEPCKE_Getable(void);
extern void RCC_OPC_CR1_I2CCKE_Setable(FunState NewState);
extern FunState RCC_OPC_CR1_I2CCKE_Getable(void);
extern void RCC_OPC_CR1_BEEPCKS_Set(uint32_t SetValue);
extern uint32_t RCC_OPC_CR1_BEEPCKS_Get(void);

/* I2C主机工作时钟选择 相关函数 */
extern void RCC_OPC_CR1_I2CCKS_Set(uint32_t SetValue);
extern uint32_t RCC_OPC_CR1_I2CCKS_Get(void);
extern void RCC_OPC_CR1_UART1CKE_Setable(FunState NewState);
extern FunState RCC_OPC_CR1_UART1CKE_Getable(void);
extern void RCC_OPC_CR1_UART0CKE_Setable(FunState NewState);
extern FunState RCC_OPC_CR1_UART0CKE_Getable(void);

/* UART1工作时钟选择 相关函数 */
extern void RCC_OPC_CR1_UART1CKS_Set(uint32_t SetValue);
extern uint32_t RCC_OPC_CR1_UART1CKS_Get(void);

/* UART0工作时钟选择 相关函数 */
extern void RCC_OPC_CR1_UART0CKS_Set(uint32_t SetValue);
extern uint32_t RCC_OPC_CR1_UART0CKS_Get(void);

/* 随机数发生器工作时钟分频 相关函数 */
extern void RCC_OPC_CR2_RNGPRSC_Set(uint32_t SetValue);
extern uint32_t RCC_OPC_CR2_RNGPRSC_Get(void);

/* ADC工作时钟预分频 相关函数 */
extern void RCC_OPC_CR2_ADCPRSC_Set(uint32_t SetValue);
extern uint32_t RCC_OPC_CR2_ADCPRSC_Get(void);
extern void RCC_OPC_CR2_FLSCKE_Setable(FunState NewState);
extern FunState RCC_OPC_CR2_FLSCKE_Getable(void);
extern void RCC_OPC_CR2_RNGCKE_Setable(FunState NewState);
extern FunState RCC_OPC_CR2_RNGCKE_Getable(void);
extern void RCC_OPC_CR2_ADCCKE_Setable(FunState NewState);
extern FunState RCC_OPC_CR2_ADCCKE_Getable(void);

/* ADC工作时钟选择 相关函数 */
extern void RCC_OPC_CR2_ADCCKS_Set(uint32_t SetValue);
extern uint32_t RCC_OPC_CR2_ADCCKS_Get(void);
extern void RCC_OPC_CR2_LPTCKE_Setable(FunState NewState);
extern FunState RCC_OPC_CR2_LPTCKE_Getable(void);

/* LPTIM工作时钟选择 相关函数 */
extern void RCC_OPC_CR2_LPTCKS_Set(uint32_t SetValue);
extern uint32_t RCC_OPC_CR2_LPTCKS_Get(void);
extern void RCC_OPC_CR2_BTCKE_Setable(FunState NewState);
extern FunState RCC_OPC_CR2_BTCKE_Getable(void);

/* BSTIM工作时钟源选择 相关函数 */
extern void RCC_OPC_CR2_BTCKS_Set(uint32_t SetValue);
extern uint32_t RCC_OPC_CR2_BTCKS_Get(void);

/* 外设时钟配置函数 */
extern void RCC_PERCLK_SetableEx(uint32_t periph_def, FunState NewState);

/* RCHF初始化 */
void RCC_RCHF_Init(RCC_RCHF_InitTypeDef* para);

/* PLL初始化 */
void RCC_PLL_Init(RCC_PLL_InitTypeDef* para);

/* 系统时钟初始化 */
void RCC_SysClk_Init(RCC_SYSCLK_InitTypeDef* para);

/* RC4M初始化 */
void RCC_RC4M_Init(RCC_RC4M_InitTypeDef* para);

extern void RCC_Init_RCHF_Trim( uint8_t ClkMode );

extern void RCC_GetClocksFreq(RCC_ClocksType* para);

extern void RCC_FDET_IER_HFDET_IE_Setable(FunState NewState);
extern FunState RCC_FDET_IER_HFDET_IE_Getable(void);
extern void RCC_FDET_IER_LFDET_IE_Setable(FunState NewState);
extern FunState RCC_FDET_IER_LFDET_IE_Getable(void);

/* 高频晶体停振检测模块输出 相关函数 */
extern void RCC_FDET_ISR_HFDETO_Clr(void);
extern FlagStatus RCC_FDET_ISR_HFDETO_Chk(void);

/* 低频晶体停振检测模块输出 相关函数 */
extern FlagStatus RCC_FDET_ISR_LFDETO_Chk(void);

/* 高频停振检测中断标志寄存器 相关函数 */
extern FlagStatus RCC_FDET_ISR_HFDETIF_Chk(void);

/* 低频停振检测中断标志寄存器 相关函数 */
extern void RCC_FDET_ISR_LFDETIF_Clr(void);
extern FlagStatus RCC_FDET_ISR_LFDETIF_Chk(void);

/* 下电复位电压配置 相关函数 */
extern void RCC_PDR_CR_CFG_Set(uint32_t SetValue);
extern uint32_t RCC_PDR_CR_CFG_Get(void);

/* 下电复位使能 相关函数 */
extern void RCC_PDR_CR_EN_Setable(FunState NewState);
extern FunState RCC_PDR_CR_EN_Getable(void);

extern void RCC_BOR_Deinit(void);

/* 下电复位电压配置 相关函数 */
extern void RCC_BOR_CR_CFG_Set(uint32_t SetValue);
extern uint32_t RCC_BOR_CR_CFG_Get(void);

/* 下电复位使能 相关函数 */
extern void RCC_BOR_CR_OFF_BOR_Setable(FunState NewState);
extern FunState RCC_BOR_CR_OFF_BOR_Getable(void);

/* 其他宏定义 */
//外设时钟控制参数定义
#define	DCUCLK			(0x01000000 + RCC_PCLK_CR1_DCU_PCE_Pos)	//31	//DCU总线时钟使能，高使能
#define	BEEPCLK		  (0x01000000 + RCC_PCLK_CR1_BEEP_PCE_Pos)	//16	//BEEPER总线时钟使能，高使能
#define	PADCLK		  (0x01000000 + RCC_PCLK_CR1_PAD_PCE_Pos)	//7	//PADCFG总线时钟使能，高使能
#define	ANACCLK			(0x01000000 + RCC_PCLK_CR1_ANAC_PCE_Pos)	//6	//ANAC总线时钟使能，高使能
#define	IWDTCLK			(0x01000000 + RCC_PCLK_CR1_IWDT_PCE_Pos)	//5	//IWDT总线时钟使能，高使能
#define	SCUCLK			(0x01000000 + RCC_PCLK_CR1_SCU_PCE_Pos)	//4	//SCU总线时钟使能，高使能
#define	PMUCLK			(0x01000000 + RCC_PCLK_CR1_PMU_PCE_Pos)	//3	//PMU总线时钟使能，高使能
#define	RTCCLK			(0x01000000 + RCC_PCLK_CR1_RTC_PCE_Pos)	//2	//RTC总线时钟使能，高使能
#define	LPTCLK			(0x01000000 + RCC_PCLK_CR1_LPT_PCE_Pos)	//0	//LPTIM总线时钟使能，高使能   

#define	ADCCLK			(0x02000000 + RCC_PCLK_CR2_ADC_PCE_Pos)	//8	/* ADC时钟使能，高使能 */
#define	WWDTCLK			(0x02000000 + RCC_PCLK_CR2_WWDT_PCE_Pos)	//7	/* WWDT时钟使能，高使能 */
#define	RAMBISTCLK	(0x02000000 + RCC_PCLK_CR2_RAMBIST_PCE_Pos)	//6	/* RAMBIST时钟使能，高使能 */
#define	FLSCLK			(0x02000000 + RCC_PCLK_CR2_FLS_PCE_Pos)	//5	/* FLSC（Flash擦写控制器）时钟使能，高使能 */
#define	DMACLK			(0x02000000 + RCC_PCLK_CR2_DMA_PCE_Pos)	//4	/* DMA时钟使能，高使能 */
#define	LCDCLK			(0x02000000 + RCC_PCLK_CR2_LCD_PCE_Pos)	//3	/* LCD时钟使能，高使能 */
#define	AESCLK			(0x02000000 + RCC_PCLK_CR2_AES_PCE_Pos)	//2	/* AES时钟使能，高使能 */
#define	RNGCLK			(0x02000000 + RCC_PCLK_CR2_RNG_PCE_Pos)	//1	/* RNG时钟使能，高使能 */
#define	CRCCLK			(0x02000000 + RCC_PCLK_CR2_CRC_PCE_Pos)	//0	/* CRC时钟使能，高使能 */

#define	I2CCLK			(0x03000000 + RCC_PCLK_CR3_I2C_PCE_Pos)	//24	//I2C总线时钟使能
#define	LPUART1CLK		(0x03000000 + RCC_PCLK_CR3_LPUART1_PCE_Pos)	//18	//LPUART1总线时钟使能
#define	U7816CLK		(0x03000000 + RCC_PCLK_CR3_U7816_PCE_Pos)	//16	//U7816总线时钟使能，高使能
#define	LPUART0CLK		(0x03000000 + RCC_PCLK_CR3_LPUART0_PCE_Pos)	//15	//LPUART0总线时钟使能
#define	UCIRCLK   	(0x03000000 + RCC_PCLK_CR3_UCIR_PCE_Pos)	//14	//UART红外调制总线时钟使能
#define	UART5CLK		(0x03000000 + RCC_PCLK_CR3_UART5_PCE_Pos)	//13	//UART5总线时钟使能
#define	UART4CLK		(0x03000000 + RCC_PCLK_CR3_UART4_PCE_Pos)	//12	//UART4总线时钟使能
#define	UART1CLK		(0x03000000 + RCC_PCLK_CR3_UART1_PCE_Pos)	//9	//UART1总线时钟使能
#define	UART0CLK		(0x03000000 + RCC_PCLK_CR3_UART0_PCE_Pos)	//8	//UART0总线时钟使能
#define	SPI2CLK			(0x03000000 + RCC_PCLK_CR3_SPI2_PCE_Pos)	//1	/* SPI2时钟使能 */
#define	SPI1CLK			(0x03000000 + RCC_PCLK_CR3_SPI1_PCE_Pos)	//0	/* SPI1时钟使能 */

#define	ATCLK		(0x04000000 + RCC_PCLK_CR4_AT_PCE_Pos)	//4	/* 计量模拟电路时钟1使能，高使能 */
#define	GT1CLK		(0x04000000 + RCC_PCLK_CR4_GT1_PCE_Pos)	//3	/* 计量模拟电路时钟2(也为数字时钟)使能，高使能 */
#define	GT0CLK		(0x04000000 + RCC_PCLK_CR4_GT0_PCE_Pos)	//2/* 计量单元寄存器时钟使能 */
#define	BTCLK			(0x04000000 + RCC_PCLK_CR4_BT_PCE_Pos)		//0	/* PAE时钟使能，高使能 */						
         
#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_RCC_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
