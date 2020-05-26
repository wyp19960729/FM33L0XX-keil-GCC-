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
#define const_rchf_Trim8  	HXVAR( uint32_t, 0x1FFFFD40 )	//RC8M ����У׼ֵ
#define const_rchf_Trim16 	HXVAR( uint32_t, 0x1FFFFD3C )	//RC16M ����У׼ֵ
#define const_rchf_Trim24 	HXVAR( uint32_t, 0x1FFFFD38 )	//RC24M ����У׼ֵ
   
#define RSTKEY0  ((uint32_t)0x13579BDF)  //ʹ�����踴λ����key
#define RSTKEY1  ((uint32_t)0x00000000)  //�ر����踴λ����key
/* Exported constants --------------------------------------------------------*/


/* Exported types ------------------------------------------------------------*/
typedef struct
{
	uint32_t			FSEL;		/*!<RCHFƵ��  */
	FunState			RCHFEN;			/*!<RCHFʹ�ܿ���  */
}RCC_RCHF_InitTypeDef;

typedef struct
{            
  uint32_t			PLLDB;		/*!<PLL��Ƶ�����1023,pll��Ƶ�� = PLLDB + 1  */
	uint32_t      REFPRSC;		/* PLL�ο�ʱ��Ԥ��Ƶ */
	uint32_t			PLLOSEL;	/*!<PLL���ѡ�񣬵���Ҫ�������1024��ʱ�����������ģʽ  */
	uint32_t			PLLINSEL;	/*!<PLL����Դѡ��  */
	FunState			PLLEN;		/*!<PLLʹ�ܿ���  */
}RCC_PLL_InitTypeDef;

typedef struct
{
	FunState			LPM_RCLP_OFF;			/*!<����ģʽ��RCLP���ƼĴ���  */
}RCC_RCLP_InitTypeDef;

typedef struct
{
    uint32_t		SYSCLKSEL;		/*!<ϵͳʱ��ѡ�񣬴�����״̬���Ѻ���Զ��ָ�ΪRCHF8M  */
	uint32_t			STCLKSEL;		/* CPU�ں�systick����ʱ��ѡ��  */
	uint32_t			AHBPRES;		/*!<AHBʱ�ӷ�Ƶѡ��  */
	uint32_t			APBPRES;		/*!<APBʱ�ӷ�Ƶѡ��  */
	FunState			SLP_ENEXTI;		/*!<Sleep/DeepSleepģʽ��EXTI��������  */
	FunState			LSCATS;	/* LSCLK�Զ��л�ʹ��  */	
}RCC_SYSCLK_InitTypeDef;

typedef struct
{
	uint32_t			RC4MPSC;		/*!<RC4MƵ��  */
	FunState			RC4MEN;			/*!<RC4Mʹ�ܿ���  */
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
	/* 0������CPU LOCKUP��λ */
	/* 1��ʹ��CPU LOCKUP��λ */

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

#define	RCC_SYSCLK_CR_LSCATS_Pos	27	/* LSCLK�Զ��л�ʹ�� */
#define	RCC_SYSCLK_CR_LSCATS_Msk	(0x1U << RCC_SYSCLK_CR_LSCATS_Pos)
	/* 0������⵽XTLF�쳣ͣ��ʱ�������Զ���LSCLK�л���RCLP���������ͨ��дXTLFCR.XTLF_BKSW�Ĵ����ֶ��л���RCLP */
	/* 1������⵽XTLF�쳣ͣ��ʱ���Զ�ʹ��RCLP����LSCLK�л���RCLP */

#define	RCC_SYSCLK_CR_SLP_ENEXTI_Pos	25	/* Sleep/DeepSleepģʽ��EXTI�������� */
#define	RCC_SYSCLK_CR_SLP_ENEXTI_Msk	(0x1U << RCC_SYSCLK_CR_SLP_ENEXTI_Pos)
	/* 0��Sleep/DeepSleepģʽ�½�ֹ�ⲿ�����жϲ��� */
	/* 1��Sleep/DeepSleepģʽ��ʹ���ⲿ�����жϲ��� */

#define	RCC_SYSCLK_CR_APBPRES_Pos	16	/* APBʱ�ӷ�Ƶѡ�� */
#define	RCC_SYSCLK_CR_APBPRES_Msk	(0x7U << RCC_SYSCLK_CR_APBPRES_Pos)
#define	RCC_SYSCLK_CR_APBPRES_DIV1	(0x0U << RCC_SYSCLK_CR_APBPRES_Pos)	/* 0XX:����Ƶ */
#define	RCC_SYSCLK_CR_APBPRES_DIV2	(0x4U << RCC_SYSCLK_CR_APBPRES_Pos)	/* 100��2��Ƶ */
#define	RCC_SYSCLK_CR_APBPRES_DIV4	(0x5U << RCC_SYSCLK_CR_APBPRES_Pos)	/* 101��4��Ƶ */
#define	RCC_SYSCLK_CR_APBPRES_DIV8	(0x6U << RCC_SYSCLK_CR_APBPRES_Pos)	/* 110��8��Ƶ */
#define	RCC_SYSCLK_CR_APBPRES_DIV16	(0x7U << RCC_SYSCLK_CR_APBPRES_Pos)	/* 111��16��Ƶ */

#define	RCC_SYSCLK_CR_AHBPRES_Pos	8	/* AHBʱ�ӷ�Ƶѡ�� */
#define	RCC_SYSCLK_CR_AHBPRES_Msk	(0x7U << RCC_SYSCLK_CR_AHBPRES_Pos)
#define	RCC_SYSCLK_CR_AHBPRES_DIV1	(0x0U << RCC_SYSCLK_CR_AHBPRES_Pos)	/* 0XX:����Ƶ */
#define	RCC_SYSCLK_CR_AHBPRES_DIV2	(0x4U << RCC_SYSCLK_CR_AHBPRES_Pos)	/* 100��2��Ƶ */
#define	RCC_SYSCLK_CR_AHBPRES_DIV4	(0x5U << RCC_SYSCLK_CR_AHBPRES_Pos)	/* 101��4��Ƶ */
#define	RCC_SYSCLK_CR_AHBPRES_DIV8	(0x6U << RCC_SYSCLK_CR_AHBPRES_Pos)	/* 110��8��Ƶ */
#define	RCC_SYSCLK_CR_AHBPRES_DIV16	(0x7U << RCC_SYSCLK_CR_AHBPRES_Pos)	/* 111��16��Ƶ */

#define	RCC_SYSCLK_CR_STCLKSEL_Pos	6	/* CPU�ں�systick����ʱ��ѡ�� */
#define	RCC_SYSCLK_CR_STCLKSEL_Msk	(0x3U << RCC_SYSCLK_CR_STCLKSEL_Pos)
#define	RCC_SYSCLK_CR_STCLKSEL_SCLK	(0x0U << RCC_SYSCLK_CR_STCLKSEL_Pos)	/* 00��SCLK */
#define	RCC_SYSCLK_CR_STCLKSEL_LSCLK	(0x1U << RCC_SYSCLK_CR_STCLKSEL_Pos)	/* 01��LSCLK */
#define	RCC_SYSCLK_CR_STCLKSEL_RC4M	(0x2U << RCC_SYSCLK_CR_STCLKSEL_Pos)	/* 10��RC4M */
#define	RCC_SYSCLK_CR_STCLKSEL_SYSCLK	(0x3U << RCC_SYSCLK_CR_STCLKSEL_Pos)	/* 11��SYSCLK */

#define	RCC_SYSCLK_CR_SYSCLKSEL_Pos	0	/* ϵͳʱ��Դѡ�� */
#define	RCC_SYSCLK_CR_SYSCLKSEL_Msk	(0x7U << RCC_SYSCLK_CR_SYSCLKSEL_Pos)
#define	RCC_SYSCLK_CR_SYSCLKSEL_RCHF	(0x0U << RCC_SYSCLK_CR_SYSCLKSEL_Pos)	/* 000��RCHF */
#define	RCC_SYSCLK_CR_SYSCLKSEL_XTHF	(0x1U << RCC_SYSCLK_CR_SYSCLKSEL_Pos)	/* 001��XTHF */
#define	RCC_SYSCLK_CR_SYSCLKSEL_PLL	(0x2U << RCC_SYSCLK_CR_SYSCLKSEL_Pos)	/* 010��PLL */
#define	RCC_SYSCLK_CR_SYSCLKSEL_RC4MPSC	(0x4U << RCC_SYSCLK_CR_SYSCLKSEL_Pos)	/* 100��RC4MPSC */
#define	RCC_SYSCLK_CR_SYSCLKSEL_LSCK	(0x5U << RCC_SYSCLK_CR_SYSCLKSEL_Pos)	/* 101,110,111��LSCLK */

#define	RCC_RCHF_CR_FSEL_Pos	16	/* RCHFƵ��ѡ��Ĵ��� */
#define	RCC_RCHF_CR_FSEL_Msk	(0xfU << RCC_RCHF_CR_FSEL_Pos)
#define	RCC_RCHF_CR_FSEL_8MHZ	(0x0U << RCC_RCHF_CR_FSEL_Pos)	/* 0000��8MHz */
#define	RCC_RCHF_CR_FSEL_16MHZ	(0x1U << RCC_RCHF_CR_FSEL_Pos)	/* 0001��16MHz */
#define	RCC_RCHF_CR_FSEL_24MHZ	(0x2U << RCC_RCHF_CR_FSEL_Pos)	/* 0010��24MHz */

#define	RCC_RCHF_CR_EN_Pos	0	/* RCHFʹ�ܼĴ��� */
#define	RCC_RCHF_CR_EN_Msk	(0x1U << RCC_RCHF_CR_EN_Pos)
	/* 0���ر�RCHF */
	/* 1��ʹ��RCHF */

#define	RCC_RC4M_TR_TRIM_Pos	0	/* RC4MƵ�ʵ�У�Ĵ��� */
#define	RCC_RC4M_TR_TRIM_Msk	(0x7fU << RCC_RC4M_TR_TRIM_Pos)

#define	RCC_PLL_CR_DB_Pos	16	/* PLL��Ƶ�� */
#define	RCC_PLL_CR_DB_Msk	(0x7fU << RCC_PLL_CR_DB_Pos)

#define	RCC_PLL_CR_LOCKED_Pos	7	/* PLL������־ */
#define	RCC_PLL_CR_LOCKED_Msk	(0x1U << RCC_PLL_CR_LOCKED_Pos)

#define	RCC_PLL_CR_REFPRSC_Pos	4	/* PLL�ο�ʱ��Ԥ��Ƶ��Ŀ���ǲ���1MHz�ο�ʱ�Ӹ�PLL�� */
#define	RCC_PLL_CR_REFPRSC_Msk	(0x7U << RCC_PLL_CR_REFPRSC_Pos)
#define	RCC_PLL_CR_REFPRSC_DIV1	(0x0U << RCC_PLL_CR_REFPRSC_Pos)	/* 000������Ƶ */
#define	RCC_PLL_CR_REFPRSC_DIV2	(0x1U << RCC_PLL_CR_REFPRSC_Pos)	/* 001��2��Ƶ */
#define	RCC_PLL_CR_REFPRSC_DIV4	(0x2U << RCC_PLL_CR_REFPRSC_Pos)	/* 010��4��Ƶ */
#define	RCC_PLL_CR_REFPRSC_DIV8	(0x3U << RCC_PLL_CR_REFPRSC_Pos)	/* 011��8��Ƶ */
#define	RCC_PLL_CR_REFPRSC_DIV12	(0x4U << RCC_PLL_CR_REFPRSC_Pos)	/* 100��12��Ƶ */
#define	RCC_PLL_CR_REFPRSC_DIV16	(0x5U << RCC_PLL_CR_REFPRSC_Pos)	/* 101��16��Ƶ */
#define	RCC_PLL_CR_REFPRSC_DIV24	(0x6U << RCC_PLL_CR_REFPRSC_Pos)	/* 110��24��Ƶ */
#define	RCC_PLL_CR_REFPRSC_DIV32	(0x7U << RCC_PLL_CR_REFPRSC_Pos)	/* 111��32��Ƶ */

#define	RCC_PLL_CR_OSEL_Pos	3	/* PLL���ѡ��Ĵ��� */
#define	RCC_PLL_CR_OSEL_Msk	(0x1U << RCC_PLL_CR_OSEL_Pos)
#define	RCC_PLL_CR_OSEL_MUL1	(0x0U << RCC_PLL_CR_OSEL_Pos)	/* 0��ѡ��PLLһ�������Ϊ���ֵ�·�ڵ�PLLʱ�� */
#define	RCC_PLL_CR_OSEL_MUL2	(0x1U << RCC_PLL_CR_OSEL_Pos)	/* 1��ѡ��PLL���������Ϊ���ֵ�·�ڵ�PLLʱ�� */

#define	RCC_PLL_CR_INSEL_Pos	1	/* PLL����ѡ��Ĵ��� */
#define	RCC_PLL_CR_INSEL_Msk	(0x1U << RCC_PLL_CR_INSEL_Pos)
#define	RCC_PLL_CR_INSEL_RCHF	(0x0U << RCC_PLL_CR_INSEL_Pos)	/* 0��RCHF */
#define	RCC_PLL_CR_INSEL_XTHF	(0x1U << RCC_PLL_CR_INSEL_Pos)	/* 1��XTHF */

#define	RCC_PLL_CR_EN_Pos	0	/* PLLʹ�ܼĴ��� */
#define	RCC_PLL_CR_EN_Msk	(0x1U << RCC_PLL_CR_EN_Pos)
	/* 0���ر�PLL */
	/* 1��ʹ��PLL */

#define	RCC_RCLP_CR_OFF_EN_Pos	1	/* RCLPʹ�ܱ�־�ź� */
#define	RCC_RCLP_CR_OFF_EN_Msk	(0x1U << RCC_RCLP_CR_OFF_EN_Pos)

#define	RCC_RCLP_CR_LPM_RCLP_OFF_Pos	0	/* ����ģʽ��RCLP���ƼĴ��� */
#define	RCC_RCLP_CR_LPM_RCLP_OFF_Msk	(0x1U << RCC_RCLP_CR_LPM_RCLP_OFF_Pos)
#define	RCC_RCLP_CR_LPM_RCLP_OFF_OPEN	(0x0U << RCC_RCLP_CR_LPM_RCLP_OFF_Pos)	/* 0������ģʽ��RCLP���� */
#define	RCC_RCLP_CR_LPM_RCLP_OFF_CLOSE	(0x1U << RCC_RCLP_CR_LPM_RCLP_OFF_Pos)	/* 1������ģʽ��RCLP�ر� */

#define	RCC_RCLP_TR_TRIM_Pos	0	/* RCLP��Уֵ�Ĵ��� */
#define	RCC_RCLP_TR_TRIM_Msk	(0xffU << RCC_RCLP_TR_TRIM_Pos)

#define	RCC_XTLF_CR_BKSW_Pos	16	/* XTLF����ʱ���ֶ��л��Ĵ��� */
#define	RCC_XTLF_CR_BKSW_Msk	(0xffU << RCC_XTLF_CR_BKSW_Pos)

#define	RCC_XTLF_CR_EN_Pos	8	/* XTLFʹ�ܼĴ��� */
#define	RCC_XTLF_CR_EN_Msk	(0xfU << RCC_XTLF_CR_EN_Pos)
#define	RCC_XTLF_CR_EN_DISABLE	(0xaU << RCC_XTLF_CR_EN_Pos)	/* 1010���ر�XTLF��FDET */
#define	RCC_XTLF_CR_EN_ENABLE	(0x5U << RCC_XTLF_CR_EN_Pos)	/* ������ʹ��XTLF��FDET */

#define	RCC_XTLF_CR_IPW_Pos	0	/* XTLF��������ѡ�� */
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
	/* DCU����ʱ��ʹ�ܣ���ʹ�� */

#define	RCC_PCLK_CR1_BEEP_PCE_Pos	16
#define	RCC_PCLK_CR1_BEEP_PCE_Msk	(0x1U << RCC_PCLK_CR1_BEEP_PCE_Pos)
	/* BEEPER����ʱ��ʹ�ܣ���ʹ�� */

#define	RCC_PCLK_CR1_PAD_PCE_Pos	7
#define	RCC_PCLK_CR1_PAD_PCE_Msk	(0x1U << RCC_PCLK_CR1_PAD_PCE_Pos)
	/* PADCFG����ʱ��ʹ�ܣ���ʹ�� */

#define	RCC_PCLK_CR1_ANAC_PCE_Pos	6
#define	RCC_PCLK_CR1_ANAC_PCE_Msk	(0x1U << RCC_PCLK_CR1_ANAC_PCE_Pos)
	/* ANAC����ʱ��ʹ�ܣ���ʹ��  */

#define	RCC_PCLK_CR1_IWDT_PCE_Pos	5
#define	RCC_PCLK_CR1_IWDT_PCE_Msk	(0x1U << RCC_PCLK_CR1_IWDT_PCE_Pos)
	/* IWDT����ʱ��ʹ�ܣ���ʹ�� */

#define	RCC_PCLK_CR1_SCU_PCE_Pos	4
#define	RCC_PCLK_CR1_SCU_PCE_Msk	(0x1U << RCC_PCLK_CR1_SCU_PCE_Pos)
	/* SCU����ʱ��ʹ�ܣ���ʹ�� */

#define	RCC_PCLK_CR1_PMU_PCE_Pos	3
#define	RCC_PCLK_CR1_PMU_PCE_Msk	(0x1U << RCC_PCLK_CR1_PMU_PCE_Pos)
	/* PMU����ʱ��ʹ�ܣ���ʹ�� */

#define	RCC_PCLK_CR1_RTC_PCE_Pos	2
#define	RCC_PCLK_CR1_RTC_PCE_Msk	(0x1U << RCC_PCLK_CR1_RTC_PCE_Pos)
	/* RTC����ʱ��ʹ�ܣ���ʹ�� */

#define	RCC_PCLK_CR1_LPT_PCE_Pos	0
#define	RCC_PCLK_CR1_LPT_PCE_Msk	(0x1U << RCC_PCLK_CR1_LPT_PCE_Pos)
	/* LPTIM32����ʱ��ʹ�ܣ���ʹ�� */

#define	RCC_PCLK_CR2_ADC_PCE_Pos	8
#define	RCC_PCLK_CR2_ADC_PCE_Msk	(0x1U << RCC_PCLK_CR2_ADC_PCE_Pos)
	/* ADC����ʱ��ʹ�ܣ���ʹ�� */

#define	RCC_PCLK_CR2_WWDT_PCE_Pos	7
#define	RCC_PCLK_CR2_WWDT_PCE_Msk	(0x1U << RCC_PCLK_CR2_WWDT_PCE_Pos)
	/* WWDT����ʱ��ʹ�ܣ���ʹ�� */

#define	RCC_PCLK_CR2_RAMBIST_PCE_Pos	6
#define	RCC_PCLK_CR2_RAMBIST_PCE_Msk	(0x1U << RCC_PCLK_CR2_RAMBIST_PCE_Pos)
	/* RAMBIST����ʱ��ʹ�ܣ���ʹ�� */

#define	RCC_PCLK_CR2_FLS_PCE_Pos	5
#define	RCC_PCLK_CR2_FLS_PCE_Msk	(0x1U << RCC_PCLK_CR2_FLS_PCE_Pos)
	/* Flash��д������ ����ʱ��ʹ�ܣ���ʹ��*/
	
#define	RCC_PCLK_CR2_DMA_PCE_Pos	4
#define	RCC_PCLK_CR2_DMA_PCE_Msk	(0x1U << RCC_PCLK_CR2_DMA_PCE_Pos)
	/* DMA����ʱ��ʹ�ܣ���ʹ�� */

#define	RCC_PCLK_CR2_LCD_PCE_Pos	3
#define	RCC_PCLK_CR2_LCD_PCE_Msk	(0x1U << RCC_PCLK_CR2_LCD_PCE_Pos)
	/* LCD����ʱ��ʹ�ܣ���ʹ�� */

#define	RCC_PCLK_CR2_AES_PCE_Pos	2
#define	RCC_PCLK_CR2_AES_PCE_Msk	(0x1U << RCC_PCLK_CR2_AES_PCE_Pos)
	/* AES����ʱ��ʹ�ܣ���ʹ�� */

#define	RCC_PCLK_CR2_RNG_PCE_Pos	1
#define	RCC_PCLK_CR2_RNG_PCE_Msk	(0x1U << RCC_PCLK_CR2_RNG_PCE_Pos)
	/* RNG����ʱ��ʹ�ܣ���ʹ�� */

#define	RCC_PCLK_CR2_CRC_PCE_Pos	0
#define	RCC_PCLK_CR2_CRC_PCE_Msk	(0x1U << RCC_PCLK_CR2_CRC_PCE_Pos)
	/* CRC����ʱ��ʹ�ܣ���ʹ�� */

#define	RCC_PCLK_CR3_I2C_PCE_Pos	24
#define	RCC_PCLK_CR3_I2C_PCE_Msk	(0x1U << RCC_PCLK_CR3_I2C_PCE_Pos)
	/* I2C����ʱ��ʹ�ܣ�����Ч */

#define	RCC_PCLK_CR3_LPUART1_PCE_Pos	18
#define	RCC_PCLK_CR3_LPUART1_PCE_Msk	(0x1U << RCC_PCLK_CR3_LPUART1_PCE_Pos)
	/* LPUART1����ʱ��ʹ�ܣ�����Ч */

#define	RCC_PCLK_CR3_U7816_PCE_Pos	16
#define	RCC_PCLK_CR3_U7816_PCE_Msk	(0x1U << RCC_PCLK_CR3_U7816_PCE_Pos)
	/* 7816����ʱ��ʹ�ܣ�����Ч */

#define	RCC_PCLK_CR3_LPUART0_PCE_Pos	15
#define	RCC_PCLK_CR3_LPUART0_PCE_Msk	(0x1U << RCC_PCLK_CR3_LPUART0_PCE_Pos)
	/* LPUART����ʱ��ʹ�ܣ�����Ч */

#define	RCC_PCLK_CR3_UCIR_PCE_Pos	14
#define	RCC_PCLK_CR3_UCIR_PCE_Msk	(0x1U << RCC_PCLK_CR3_UCIR_PCE_Pos)
	/* UART������ƹ���ʱ��ʹ�ܣ�����Ч */

#define	RCC_PCLK_CR3_UART5_PCE_Pos	13
#define	RCC_PCLK_CR3_UART5_PCE_Msk	(0x1U << RCC_PCLK_CR3_UART5_PCE_Pos)
	/* UART5����ʱ��ʹ�ܣ�����Ч */

#define	RCC_PCLK_CR3_UART4_PCE_Pos	12
#define	RCC_PCLK_CR3_UART4_PCE_Msk	(0x1U << RCC_PCLK_CR3_UART4_PCE_Pos)
	/* UART4����ʱ��ʹ�ܣ�����Ч */

#define	RCC_PCLK_CR3_UART1_PCE_Pos	9
#define	RCC_PCLK_CR3_UART1_PCE_Msk	(0x1U << RCC_PCLK_CR3_UART1_PCE_Pos)
	/* UART1����ʱ��ʹ�ܣ�����Ч */

#define	RCC_PCLK_CR3_UART0_PCE_Pos	8
#define	RCC_PCLK_CR3_UART0_PCE_Msk	(0x1U << RCC_PCLK_CR3_UART0_PCE_Pos)
	/* UART0����ʱ��ʹ�ܣ�����Ч */

#define	RCC_PCLK_CR3_SPI2_PCE_Pos	1
#define	RCC_PCLK_CR3_SPI2_PCE_Msk	(0x1U << RCC_PCLK_CR3_SPI2_PCE_Pos)
	/* SPI2����ʱ��ʹ�ܣ�����Ч */

#define	RCC_PCLK_CR3_SPI1_PCE_Pos	0
#define	RCC_PCLK_CR3_SPI1_PCE_Msk	(0x1U << RCC_PCLK_CR3_SPI1_PCE_Pos)
	/* SPI1����ʱ��ʹ�ܣ�����Ч */

#define	RCC_PCLK_CR4_AT_PCE_Pos	4
#define	RCC_PCLK_CR4_AT_PCE_Msk	(0x1U << RCC_PCLK_CR4_AT_PCE_Pos)
	/* �߼���ʱ������ʱ��ʹ�ܣ�����Ч */

#define	RCC_PCLK_CR4_GT1_PCE_Pos	3
#define	RCC_PCLK_CR4_GT1_PCE_Msk	(0x1U << RCC_PCLK_CR4_GT1_PCE_Pos)
	/* ͨ�ö�ʱ��1����ʱ��ʹ�ܣ�����Ч */

#define	RCC_PCLK_CR4_GT0_PCE_Pos	2
#define	RCC_PCLK_CR4_GT0_PCE_Msk	(0x1U << RCC_PCLK_CR4_GT0_PCE_Pos)
	/* ͨ�ö�ʱ��0����ʱ��ʹ�ܣ�����Ч */

#define	RCC_PCLK_CR4_BT_PCE_Pos	0
#define	RCC_PCLK_CR4_BT_PCE_Msk	(0x1U << RCC_PCLK_CR4_BT_PCE_Pos)
	/* ������ʱ��0����ʱ��ʹ�ܣ�����Ч */

#define	RCC_AHBM_CR_MPRIL_Pos	0	/* AHB Master���ȼ����üĴ��� */
#define	RCC_AHBM_CR_MPRIL_Msk	(0x1U << RCC_AHBM_CR_MPRIL_Pos)
#define	RCC_AHBM_CR_MPRIL_DMA	(0x0U << RCC_AHBM_CR_MPRIL_Pos)
#define	RCC_AHBM_CR_MPRIL_CPU	(0x1U << RCC_AHBM_CR_MPRIL_Pos)

#define	RCC_PRST_EN_PERHRSTEN_Pos	0	/* ����ģ�鸴λʹ�� */
#define	RCC_PRST_EN_PERHRSTEN_Msk	(0xffffffffU << RCC_PRST_EN_PERHRSTEN_Pos)

#define	RCC_AHBRST_CR_DMARST_Pos	0	/* DMAģ�鸴λ */
#define	RCC_AHBRST_CR_DMARST_Msk	(0x1U << RCC_AHBRST_CR_DMARST_Pos)
#define	RCC_AHBRST_CR_DMARST_NORST	(0x0U << RCC_AHBRST_CR_DMARST_Pos)	/* 0������λ */
#define	RCC_AHBRST_CR_DMARST_RST	(0x1U << RCC_AHBRST_CR_DMARST_Pos)	/* 1����λ */

#define	RCC_APBRST_CR1_UART5RST_Pos	31	/* UART5ģ�鸴λ */
#define	RCC_APBRST_CR1_UART5RST_Msk	(0x1U << RCC_APBRST_CR1_UART5RST_Pos)
#define	RCC_APBRST_CR1_UART5RST_NORST	(0x0U << RCC_APBRST_CR1_UART5RST_Pos)	/* 0������λ */
#define	RCC_APBRST_CR1_UART5RST_RST	(0x1U << RCC_APBRST_CR1_UART5RST_Pos)	/* 1����λ */

#define	RCC_APBRST_CR1_UART4RST_Pos	30	/* UART4ģ�鸴λ */
#define	RCC_APBRST_CR1_UART4RST_Msk	(0x1U << RCC_APBRST_CR1_UART4RST_Pos)
#define	RCC_APBRST_CR1_UART4RST_NORST	(0x0U << RCC_APBRST_CR1_UART4RST_Pos)	/* 0������λ */
#define	RCC_APBRST_CR1_UART4RST_RST	(0x1U << RCC_APBRST_CR1_UART4RST_Pos)	/* 1����λ */

#define	RCC_APBRST_CR1_GT1RST_Pos	25	/* GPTIM1ģ�鸴λ */
#define	RCC_APBRST_CR1_GT1RST_Msk	(0x1U << RCC_APBRST_CR1_GT1RST_Pos)
#define	RCC_APBRST_CR1_GT1RST_NORST	(0x0U << RCC_APBRST_CR1_GT1RST_Pos)	/* 0������λ */
#define	RCC_APBRST_CR1_GT1RST_RST	(0x1U << RCC_APBRST_CR1_GT1RST_Pos)	/* 1����λ */

#define	RCC_APBRST_CR1_GT0RST_Pos	24	/* GPTIM0ģ�鸴λ */
#define	RCC_APBRST_CR1_GT0RST_Msk	(0x1U << RCC_APBRST_CR1_GT0RST_Pos)
#define	RCC_APBRST_CR1_GT0RST_NORST	(0x0U << RCC_APBRST_CR1_GT0RST_Pos)	/* 0������λ */
#define	RCC_APBRST_CR1_GT0RST_RST	(0x1U << RCC_APBRST_CR1_GT0RST_Pos)	/* 1����λ */

#define	RCC_APBRST_CR1_LCDRST_Pos	16	/* LCDģ�鸴λ */
#define	RCC_APBRST_CR1_LCDRST_Msk	(0x1U << RCC_APBRST_CR1_LCDRST_Pos)
#define	RCC_APBRST_CR1_LCDRST_NORST	(0x0U << RCC_APBRST_CR1_LCDRST_Pos)	/* 0������λ */
#define	RCC_APBRST_CR1_LCDRST_RST	(0x1U << RCC_APBRST_CR1_LCDRST_Pos)	/* 1����λ */

#define	RCC_APBRST_CR1_U7816RST_Pos	14	/* U7816ģ�鸴λ */
#define	RCC_APBRST_CR1_U7816RST_Msk	(0x1U << RCC_APBRST_CR1_U7816RST_Pos)
#define	RCC_APBRST_CR1_U7816RST_NORST	(0x0U << RCC_APBRST_CR1_U7816RST_Pos)	/* 0������λ */
#define	RCC_APBRST_CR1_U7816RST_RST	(0x1U << RCC_APBRST_CR1_U7816RST_Pos)	/* 1����λ */

#define	RCC_APBRST_CR1_SPI2RST_Pos	10	/* SPI2ģ�鸴λ */
#define	RCC_APBRST_CR1_SPI2RST_Msk	(0x1U << RCC_APBRST_CR1_SPI2RST_Pos)
#define	RCC_APBRST_CR1_SPI2RST_NORST	(0x0U << RCC_APBRST_CR1_SPI2RST_Pos)	/* 0������λ */
#define	RCC_APBRST_CR1_SPI2RST_RST	(0x1U << RCC_APBRST_CR1_SPI2RST_Pos)	/* 1����λ */

#define	RCC_APBRST_CR1_LPUART0RST_Pos	6	/* LPUART0ģ�鸴λ */
#define	RCC_APBRST_CR1_LPUART0RST_Msk	(0x1U << RCC_APBRST_CR1_LPUART0RST_Pos)
#define	RCC_APBRST_CR1_LPUART0RST_NORST	(0x0U << RCC_APBRST_CR1_LPUART0RST_Pos)	/* 0������λ */
#define	RCC_APBRST_CR1_LPUART0RST_RST	(0x1U << RCC_APBRST_CR1_LPUART0RST_Pos)	/* 1����λ */

#define	RCC_APBRST_CR1_I2CRST_Pos	3	/* I2Cģ�鸴λ */
#define	RCC_APBRST_CR1_I2CRST_Msk	(0x1U << RCC_APBRST_CR1_I2CRST_Pos)
#define	RCC_APBRST_CR1_I2CRST_NORST	(0x0U << RCC_APBRST_CR1_I2CRST_Pos)	/* 0������λ */
#define	RCC_APBRST_CR1_I2CRST_RST	(0x1U << RCC_APBRST_CR1_I2CRST_Pos)	/* 1����λ */

#define	RCC_APBRST_CR1_LPT32RST_Pos	0	/* LPTIM32ģ�鸴λ */
#define	RCC_APBRST_CR1_LPT32RST_Msk	(0x1U << RCC_APBRST_CR1_LPT32RST_Pos)
#define	RCC_APBRST_CR1_LPT32RST_NORST	(0x0U << RCC_APBRST_CR1_LPT32RST_Pos)	/* 0������λ */
#define	RCC_APBRST_CR1_LPT32RST_RST	(0x1U << RCC_APBRST_CR1_LPT32RST_Pos)	/* 1����λ */

#define	RCC_APBRST_CR2_ATRST_Pos	31	/* ATIMģ�鸴λ */
#define	RCC_APBRST_CR2_ATRST_Msk	(0x1U << RCC_APBRST_CR2_ATRST_Pos)
#define	RCC_APBRST_CR2_ATRST_NORST	(0x0U << RCC_APBRST_CR2_ATRST_Pos)	/* 0������λ */
#define	RCC_APBRST_CR2_ATRST_RST	(0x1U << RCC_APBRST_CR2_ATRST_Pos)	/* 1����λ */

#define	RCC_APBRST_CR2_BTRST_Pos	28	/* BSTIMģ�鸴λ */
#define	RCC_APBRST_CR2_BTRST_Msk	(0x1U << RCC_APBRST_CR2_BTRST_Pos)
#define	RCC_APBRST_CR2_BTRST_NORST	(0x0U << RCC_APBRST_CR2_BTRST_Pos)	/* 0������λ */
#define	RCC_APBRST_CR2_BTRST_RST	(0x1U << RCC_APBRST_CR2_BTRST_Pos)	/* 1����λ */

#define	RCC_APBRST_CR2_ADCCRST_Pos	24	/* ADC��������λ */
#define	RCC_APBRST_CR2_ADCCRST_Msk	(0x1U << RCC_APBRST_CR2_ADCCRST_Pos)
#define	RCC_APBRST_CR2_ADCCRST_NORST	(0x0U << RCC_APBRST_CR2_ADCCRST_Pos)	/* 0������λ */
#define	RCC_APBRST_CR2_ADCCRST_RST	(0x1U << RCC_APBRST_CR2_ADCCRST_Pos)	/* 1����λ */

#define	RCC_APBRST_CR2_ADCRST_Pos	23	/* ADCģ�鸴λ */
#define	RCC_APBRST_CR2_ADCRST_Msk	(0x1U << RCC_APBRST_CR2_ADCRST_Pos)
#define	RCC_APBRST_CR2_ADCRST_NORST	(0x0U << RCC_APBRST_CR2_ADCRST_Pos)	/* 0������λ */
#define	RCC_APBRST_CR2_ADCRST_RST	(0x1U << RCC_APBRST_CR2_ADCRST_Pos)	/* 1����λ */

#define	RCC_APBRST_CR2_OPARST_Pos	22	/* �˷�ģ�鸴λ */
#define	RCC_APBRST_CR2_OPARST_Msk	(0x1U << RCC_APBRST_CR2_OPARST_Pos)
#define	RCC_APBRST_CR2_OPARST_NORST	(0x0U << RCC_APBRST_CR2_OPARST_Pos)	/* 0������λ */
#define	RCC_APBRST_CR2_OPARST_RST	(0x1U << RCC_APBRST_CR2_OPARST_Pos)	/* 1����λ */

#define	RCC_APBRST_CR2_AESRST_Pos	18	/* AESģ�鸴λ */
#define	RCC_APBRST_CR2_AESRST_Msk	(0x1U << RCC_APBRST_CR2_AESRST_Pos)
#define	RCC_APBRST_CR2_AESRST_NORST	(0x0U << RCC_APBRST_CR2_AESRST_Pos)	/* 0������λ */
#define	RCC_APBRST_CR2_AESRST_RST	(0x1U << RCC_APBRST_CR2_AESRST_Pos)	/* 1����λ */

#define	RCC_APBRST_CR2_CRCRST_Pos	17	/* CRCģ�鸴λ */
#define	RCC_APBRST_CR2_CRCRST_Msk	(0x1U << RCC_APBRST_CR2_CRCRST_Pos)
#define	RCC_APBRST_CR2_CRCRST_NORST	(0x0U << RCC_APBRST_CR2_CRCRST_Pos)	/* 0������λ */
#define	RCC_APBRST_CR2_CRCRST_RST	(0x1U << RCC_APBRST_CR2_CRCRST_Pos)	/* 1����λ */

#define	RCC_APBRST_CR2_RNGRST_Pos	16	/* RNGģ�鸴λ */
#define	RCC_APBRST_CR2_RNGRST_Msk	(0x1U << RCC_APBRST_CR2_RNGRST_Pos)
#define	RCC_APBRST_CR2_RNGRST_NORST	(0x0U << RCC_APBRST_CR2_RNGRST_Pos)	/* 0������λ */
#define	RCC_APBRST_CR2_RNGRST_RST	(0x1U << RCC_APBRST_CR2_RNGRST_Pos)	/* 1����λ */

#define	RCC_APBRST_CR2_UART1RST_Pos	12	/* UART1ģ�鸴λ */
#define	RCC_APBRST_CR2_UART1RST_Msk	(0x1U << RCC_APBRST_CR2_UART1RST_Pos)
#define	RCC_APBRST_CR2_UART1RST_NORST	(0x0U << RCC_APBRST_CR2_UART1RST_Pos)	/* 0������λ */
#define	RCC_APBRST_CR2_UART1RST_RST	(0x1U << RCC_APBRST_CR2_UART1RST_Pos)	/* 1����λ */

#define	RCC_APBRST_CR2_UART0RST_Pos	11	/* UART0ģ�鸴λ */
#define	RCC_APBRST_CR2_UART0RST_Msk	(0x1U << RCC_APBRST_CR2_UART0RST_Pos)
#define	RCC_APBRST_CR2_UART0RST_NORST	(0x0U << RCC_APBRST_CR2_UART0RST_Pos)	/* 0������λ */
#define	RCC_APBRST_CR2_UART0RST_RST	(0x1U << RCC_APBRST_CR2_UART0RST_Pos)	/* 1����λ */

#define	RCC_APBRST_CR2_SPI1RST_Pos	9	/* SPI1ģ�鸴λ */
#define	RCC_APBRST_CR2_SPI1RST_Msk	(0x1U << RCC_APBRST_CR2_SPI1RST_Pos)
#define	RCC_APBRST_CR2_SPI1RST_NORST	(0x0U << RCC_APBRST_CR2_SPI1RST_Pos)	/* 0������λ */
#define	RCC_APBRST_CR2_SPI1RST_RST	(0x1U << RCC_APBRST_CR2_SPI1RST_Pos)	/* 1����λ */

#define	RCC_APBRST_CR2_UCIRRST_Pos	8	/* UART�������ģ�鸴λ */
#define	RCC_APBRST_CR2_UCIRRST_Msk	(0x1U << RCC_APBRST_CR2_UCIRRST_Pos)
#define	RCC_APBRST_CR2_UCIRRST_NORST	(0x0U << RCC_APBRST_CR2_UCIRRST_Pos)	/* 0������λ */
#define	RCC_APBRST_CR2_UCIRRST_RST	(0x1U << RCC_APBRST_CR2_UCIRRST_Pos)	/* 1����λ */

#define	RCC_APBRST_CR2_LPUART1RST_Pos	7	/* LPUART1ģ�鸴λ */
#define	RCC_APBRST_CR2_LPUART1RST_Msk	(0x1U << RCC_APBRST_CR2_LPUART1RST_Pos)
#define	RCC_APBRST_CR2_LPUART1RST_NORST	(0x0U << RCC_APBRST_CR2_LPUART1RST_Pos)	/* 0������λ */
#define	RCC_APBRST_CR2_LPUART1RST_RST	(0x1U << RCC_APBRST_CR2_LPUART1RST_Pos)	/* 1����λ */

#define	RCC_XTHF_CR_CFG_Pos	8	/* XTHF��ǿ������ */
#define	RCC_XTHF_CR_CFG_Msk	(0x7U << RCC_XTHF_CR_CFG_Pos)

#define	RCC_XTHF_CR_EN_Pos	0	/* XTHFʹ�ܼĴ��� */
#define	RCC_XTHF_CR_EN_Msk	(0x1U << RCC_XTHF_CR_EN_Pos)
	/* 0���ر�XTHF */
	/* 1��ʹ��XTHF */

#define	RCC_RC4M_CR_PSC_Pos	16	/* RC4M���Ԥ��Ƶ  */
#define	RCC_RC4M_CR_PSC_Msk	(0x3U << RCC_RC4M_CR_PSC_Pos)
#define	RCC_RC4M_CR_PSC_DIV1	(0x0U << RCC_RC4M_CR_PSC_Pos)	/* 00������Ƶ */
#define	RCC_RC4M_CR_PSC_DIV4	(0x1U << RCC_RC4M_CR_PSC_Pos)	/* 01��4��Ƶ */
#define	RCC_RC4M_CR_PSC_DIV8	(0x2U << RCC_RC4M_CR_PSC_Pos)	/* 10��8��Ƶ */
#define	RCC_RC4M_CR_PSC_DIV16	(0x3U << RCC_RC4M_CR_PSC_Pos)	/* 11��16��Ƶ */

#define	RCC_RC4M_CR_EN_Pos	0	/* RC4Mʹ�ܼĴ��� */
#define	RCC_RC4M_CR_EN_Msk	(0x1U << RCC_RC4M_CR_EN_Pos)
	/* 0���ر�RC4M */
	/* 1����RC4M */

#define	RCC_RCHF_TR_TRIM_Pos	0	/* RCHFƵ�ʵ�У�Ĵ��� */
#define	RCC_RCHF_TR_TRIM_Msk	(0x7fU << RCC_RCHF_TR_TRIM_Pos)

#define	RCC_OPC_CR1_EXTICKE_Pos	31
#define	RCC_OPC_CR1_EXTICKE_Msk	(0x1U << RCC_OPC_CR1_EXTICKE_Pos)
	/* EXTI����ʱ��ʹ�ܣ�����Ч */

#define	RCC_OPC_CR1_EXTICKS_Pos	30	/* EXTI�жϲ���ʱ��ѡ�� */
#define	RCC_OPC_CR1_EXTICKS_Msk	(0x1U << RCC_OPC_CR1_EXTICKS_Pos)
#define	RCC_OPC_CR1_EXTICKS_HCLK	(0x0U << RCC_OPC_CR1_EXTICKS_Pos)	/* 0���ⲿ�����ж�ʹ��HCLK���� */
#define	RCC_OPC_CR1_EXTICKS_LSCLK	(0x1U << RCC_OPC_CR1_EXTICKS_Pos)	/* 1���ⲿ�����ж�ʹ��LSCLK���� */

#define	RCC_OPC_CR1_LPUART1CKE_Pos	29
#define	RCC_OPC_CR1_LPUART1CKE_Msk	(0x1U << RCC_OPC_CR1_LPUART1CKE_Pos)
	/* LPUART1����ʱ��ʹ�ܣ�����Ч */

#define	RCC_OPC_CR1_LPUART0CKE_Pos	28
#define	RCC_OPC_CR1_LPUART0CKE_Msk	(0x1U << RCC_OPC_CR1_LPUART0CKE_Pos)
	/* LPUART0����ʱ��ʹ�ܣ�����Ч */

#define	RCC_OPC_CR1_LPUART1CKS_Pos	26
#define	RCC_OPC_CR1_LPUART1CKS_Msk	(0x3U << RCC_OPC_CR1_LPUART1CKS_Pos)
#define	RCC_OPC_CR1_LPUART1CKS_LSCLK	(0x0U << RCC_OPC_CR1_LPUART1CKS_Pos)	/* LPUART1����ʱ��ѡ�� */
#define	RCC_OPC_CR1_LPUART1CKS_RCHFDIV	(0x1U << RCC_OPC_CR1_LPUART1CKS_Pos)
#define	RCC_OPC_CR1_LPUART1CKS_RC4MDIV	(0x2U << RCC_OPC_CR1_LPUART1CKS_Pos)

#define	RCC_OPC_CR1_LPUART0CKS_Pos	24
#define	RCC_OPC_CR1_LPUART0CKS_Msk	(0x3U << RCC_OPC_CR1_LPUART0CKS_Pos)
#define	RCC_OPC_CR1_LPUART0CKS_LSCLK	(0x0U << RCC_OPC_CR1_LPUART0CKS_Pos)	/* LPUART0����ʱ��ѡ�� */
#define	RCC_OPC_CR1_LPUART0CKS_RCHFDIV	(0x1U << RCC_OPC_CR1_LPUART0CKS_Pos)
#define	RCC_OPC_CR1_LPUART0CKS_RC4MDIV	(0x2U << RCC_OPC_CR1_LPUART0CKS_Pos)

#define	RCC_OPC_CR1_BEEPCKE_Pos	21
#define	RCC_OPC_CR1_BEEPCKE_Msk	(0x1U << RCC_OPC_CR1_BEEPCKE_Pos)
	/* Beeper����ʱ��ʹ�ܣ�����Ч */

#define	RCC_OPC_CR1_I2CCKE_Pos	20
#define	RCC_OPC_CR1_I2CCKE_Msk	(0x1U << RCC_OPC_CR1_I2CCKE_Pos)
	/* I2C����ʱ��ʹ�� */

#define	RCC_OPC_CR1_BEEPCKS_Pos	18
#define	RCC_OPC_CR1_BEEPCKS_Msk	(0x1U << RCC_OPC_CR1_BEEPCKS_Pos)
#define	RCC_OPC_CR1_BEEPCKS_XTLF	(0x0U << RCC_OPC_CR1_BEEPCKS_Pos)	/* Beeper����ʱ��ѡ�� */
#define	RCC_OPC_CR1_BEEPCKS_RCLP	(0x1U << RCC_OPC_CR1_BEEPCKS_Pos)

#define	RCC_OPC_CR1_I2CCKS_Pos	16	/* I2C��������ʱ��ѡ�� */
#define	RCC_OPC_CR1_I2CCKS_Msk	(0x3U << RCC_OPC_CR1_I2CCKS_Pos)
#define	RCC_OPC_CR1_I2CCKS_APBCLK	(0x0U << RCC_OPC_CR1_I2CCKS_Pos)	/* 00��APBCLK */
#define	RCC_OPC_CR1_I2CCKS_RCHF	(0x1U << RCC_OPC_CR1_I2CCKS_Pos)	/* 01��RCHF */
#define	RCC_OPC_CR1_I2CCKS_SYSCLK	(0x2U << RCC_OPC_CR1_I2CCKS_Pos)	/* 10��SYSCLK */
#define	RCC_OPC_CR1_I2CCKS_RC4MPSC	(0x3U << RCC_OPC_CR1_I2CCKS_Pos)	/* 11��RC4M_PSC */

#define	RCC_OPC_CR1_UART1CKE_Pos	9
#define	RCC_OPC_CR1_UART1CKE_Msk	(0x1U << RCC_OPC_CR1_UART1CKE_Pos)
	/* UART1����ʱ��ʹ�ܣ�����Ч */

#define	RCC_OPC_CR1_UART0CKE_Pos	8
#define	RCC_OPC_CR1_UART0CKE_Msk	(0x1U << RCC_OPC_CR1_UART0CKE_Pos)
	/* UART0����ʱ��ʹ�ܣ�����Ч */

#define	RCC_OPC_CR1_UART1CKS_Pos	2	/* UART1����ʱ��ѡ�� */
#define	RCC_OPC_CR1_UART1CKS_Msk	(0x3U << RCC_OPC_CR1_UART1CKS_Pos)
#define	RCC_OPC_CR1_UART1CKS_APBCLK	(0x0U << RCC_OPC_CR1_UART1CKS_Pos)	/* 00��APBCLK */
#define	RCC_OPC_CR1_UART1CKS_RCHF	(0x1U << RCC_OPC_CR1_UART1CKS_Pos)	/* 01��RCHF */
#define	RCC_OPC_CR1_UART1CKS_SYSCLK	(0x2U << RCC_OPC_CR1_UART1CKS_Pos)	/* 10��SYSCLK */
#define	RCC_OPC_CR1_UART1CKS_RC4MPSC	(0x3U << RCC_OPC_CR1_UART1CKS_Pos)	/* 11��RC4M_PSC */

#define	RCC_OPC_CR1_UART0CKS_Pos	0	/* UART0����ʱ��ѡ�� */
#define	RCC_OPC_CR1_UART0CKS_Msk	(0x3U << RCC_OPC_CR1_UART0CKS_Pos)
#define	RCC_OPC_CR1_UART0CKS_APBCLK	(0x0U << RCC_OPC_CR1_UART0CKS_Pos)	/* 00��APBCLK */
#define	RCC_OPC_CR1_UART0CKS_RCHF	(0x1U << RCC_OPC_CR1_UART0CKS_Pos)	/* 01��RCHF */
#define	RCC_OPC_CR1_UART0CKS_SYSCLK	(0x2U << RCC_OPC_CR1_UART0CKS_Pos)	/* 10��SYSCLK */
#define	RCC_OPC_CR1_UART0CKS_RC4MPSC	(0x3U << RCC_OPC_CR1_UART0CKS_Pos)	/* 11��RC4M_PSC */

#define	RCC_OPC_CR2_RNGPRSC_Pos	28	/* ���������������ʱ�ӷ�Ƶ */
#define	RCC_OPC_CR2_RNGPRSC_Msk	(0x7U << RCC_OPC_CR2_RNGPRSC_Pos)
#define	RCC_OPC_CR2_RNGPRSC_DIV1	(0x0U << RCC_OPC_CR2_RNGPRSC_Pos)	/* 000������Ƶ */
#define	RCC_OPC_CR2_RNGPRSC_DIV2	(0x1U << RCC_OPC_CR2_RNGPRSC_Pos)	/* 001��2��Ƶ */
#define	RCC_OPC_CR2_RNGPRSC_DIV4	(0x2U << RCC_OPC_CR2_RNGPRSC_Pos)	/* 010��4��Ƶ */
#define	RCC_OPC_CR2_RNGPRSC_DIV8	(0x3U << RCC_OPC_CR2_RNGPRSC_Pos)	/* 011��8��Ƶ */
#define	RCC_OPC_CR2_RNGPRSC_DIV16	(0x4U << RCC_OPC_CR2_RNGPRSC_Pos)	/* 100��16��Ƶ */
#define	RCC_OPC_CR2_RNGPRSC_DIV32	(0x5U << RCC_OPC_CR2_RNGPRSC_Pos)	/* 101��32��Ƶ */

#define	RCC_OPC_CR2_ADCPRSC_Pos	24	/* ADC����ʱ��Ԥ��Ƶ */
#define	RCC_OPC_CR2_ADCPRSC_Msk	(0x7U << RCC_OPC_CR2_ADCPRSC_Pos)
#define	RCC_OPC_CR2_ADCPRSC_DIV1	(0x0U << RCC_OPC_CR2_ADCPRSC_Pos)	/* 000������Ƶ */
#define	RCC_OPC_CR2_ADCPRSC_DIV2	(0x1U << RCC_OPC_CR2_ADCPRSC_Pos)	/* 001��2��Ƶ */
#define	RCC_OPC_CR2_ADCPRSC_DIV4	(0x2U << RCC_OPC_CR2_ADCPRSC_Pos)	/* 010��4��Ƶ */
#define	RCC_OPC_CR2_ADCPRSC_DIV8	(0x3U << RCC_OPC_CR2_ADCPRSC_Pos)	/* 011��8��Ƶ */
#define	RCC_OPC_CR2_ADCPRSC_DIV16	(0x4U << RCC_OPC_CR2_ADCPRSC_Pos)	/* 100��16��Ƶ */
#define	RCC_OPC_CR2_ADCPRSC_DIV32	(0x5U << RCC_OPC_CR2_ADCPRSC_Pos)	/* 101��32��Ƶ */

#define	RCC_OPC_CR2_FLSCKE_Pos	22
#define	RCC_OPC_CR2_FLSCKE_Msk	(0x1U << RCC_OPC_CR2_FLSCKE_Pos)
	/* Flash��дʱ��ʹ�ܣ�����Ч  */

#define	RCC_OPC_CR2_RNGCKE_Pos	21
#define	RCC_OPC_CR2_RNGCKE_Msk	(0x1U << RCC_OPC_CR2_RNGCKE_Pos)
	/* ���������������ʱ��ʹ�ܣ�����Ч  */

#define	RCC_OPC_CR2_ADCCKE_Pos	20
#define	RCC_OPC_CR2_ADCCKE_Msk	(0x1U << RCC_OPC_CR2_ADCCKE_Pos)
	/* ADC����ʱ��ʹ�ܣ�����Ч */

#define	RCC_OPC_CR2_ADCCKS_Pos	16	/* ADC����ʱ��ѡ�� */
#define	RCC_OPC_CR2_ADCCKS_Msk	(0x3U << RCC_OPC_CR2_ADCCKS_Pos)
#define	RCC_OPC_CR2_ADCCKS_RC4MPSC	(0x0U << RCC_OPC_CR2_ADCCKS_Pos)	/* 00��RC4M_PSC */
#define	RCC_OPC_CR2_ADCCKS_RCHF	(0x1U << RCC_OPC_CR2_ADCCKS_Pos)	/* 01��RCHF */
#define	RCC_OPC_CR2_ADCCKS_XTHF	(0x2U << RCC_OPC_CR2_ADCCKS_Pos)	/* 10��XTHF */
#define	RCC_OPC_CR2_ADCCKS_PLL	(0x3U << RCC_OPC_CR2_ADCCKS_Pos)	/* 11��PLL */

#define	RCC_OPC_CR2_LPTCKE_Pos	12
#define	RCC_OPC_CR2_LPTCKE_Msk	(0x1U << RCC_OPC_CR2_LPTCKE_Pos)
	/* LPTIM����ʱ��ʹ�ܣ�����Ч */

#define	RCC_OPC_CR2_LPTCKS_Pos	8	/* LPTIM����ʱ��ѡ�� */
#define	RCC_OPC_CR2_LPTCKS_Msk	(0x3U << RCC_OPC_CR2_LPTCKS_Pos)
#define	RCC_OPC_CR2_LPTCKS_APBCLK	(0x0U << RCC_OPC_CR2_LPTCKS_Pos)	/* 00��APBCLK */
#define	RCC_OPC_CR2_LPTCKS_LSCLK	(0x1U << RCC_OPC_CR2_LPTCKS_Pos)	/* 01��LSCLK */
#define	RCC_OPC_CR2_LPTCKS_RCLP	(0x2U << RCC_OPC_CR2_LPTCKS_Pos)	/* 10��RCLP */
#define	RCC_OPC_CR2_LPTCKS_RC4MPSC	(0x3U << RCC_OPC_CR2_LPTCKS_Pos)	/* 11��RC4MPSC */

#define	RCC_OPC_CR2_BTCKE_Pos	4
#define	RCC_OPC_CR2_BTCKE_Msk	(0x1U << RCC_OPC_CR2_BTCKE_Pos)
	/* BSTIM����ʱ��ʹ�ܣ�����Ч */

#define	RCC_OPC_CR2_BTCKS_Pos	0	/* BSTIM����ʱ��Դѡ�� */
#define	RCC_OPC_CR2_BTCKS_Msk	(0x3U << RCC_OPC_CR2_BTCKS_Pos)
#define	RCC_OPC_CR2_BTCKS_APBCLK	(0x0U << RCC_OPC_CR2_BTCKS_Pos)	/* 00��APBCLK */
#define	RCC_OPC_CR2_BTCKS_LSCLK	(0x1U << RCC_OPC_CR2_BTCKS_Pos)	/* 01��LSCLK */
#define	RCC_OPC_CR2_BTCKS_RCLP	(0x2U << RCC_OPC_CR2_BTCKS_Pos)	/* 10��RCLP */
#define	RCC_OPC_CR2_BTCKS_RC4MPSC	(0x3U << RCC_OPC_CR2_BTCKS_Pos)	/* 11��RC4MPSC */

#define	RCC_FDET_IER_HFDET_IE_Pos	1
#define	RCC_FDET_IER_HFDET_IE_Msk	(0x1U << RCC_FDET_IER_HFDET_IE_Pos)
	/* XTHF��Ƶ��ⱨ���ж�ʹ�ܣ�1��Ч */

#define	RCC_FDET_IER_LFDET_IE_Pos	0
#define	RCC_FDET_IER_LFDET_IE_Msk	(0x1U << RCC_FDET_IER_LFDET_IE_Pos)
	/* XTLF��Ƶ��ⱨ���ж�ʹ�ܣ�1��Ч */

#define	RCC_FDET_ISR_HFDETO_Pos	9	/* ��Ƶ����ͣ����ģ����� */
#define	RCC_FDET_ISR_HFDETO_Msk	(0x1U << RCC_FDET_ISR_HFDETO_Pos)

#define	RCC_FDET_ISR_LFDETO_Pos	8	/* ��Ƶ����ͣ����ģ����� */
#define	RCC_FDET_ISR_LFDETO_Msk	(0x1U << RCC_FDET_ISR_LFDETO_Pos)

#define	RCC_FDET_ISR_HFDETIF_Pos	1	/* ��Ƶͣ�����жϱ�־�Ĵ��� */
#define	RCC_FDET_ISR_HFDETIF_Msk	(0x1U << RCC_FDET_ISR_HFDETIF_Pos)

#define	RCC_FDET_ISR_LFDETIF_Pos	0	/* ��Ƶͣ�����жϱ�־�Ĵ��� */
#define	RCC_FDET_ISR_LFDETIF_Msk	(0x1U << RCC_FDET_ISR_LFDETIF_Pos)

#define	RCC_PDR_CR_CFG_Pos	1	/* �µ縴λ��ѹ���� */
#define	RCC_PDR_CR_CFG_Msk	(0x3U << RCC_PDR_CR_CFG_Pos)
#define	RCC_PDR_CR_CFG_1_5V	(0x0U << RCC_PDR_CR_CFG_Pos)	/* 00��1.5V */
#define	RCC_PDR_CR_CFG_1_25V	(0x1U << RCC_PDR_CR_CFG_Pos)	/* 01��1.25V */
#define	RCC_PDR_CR_CFG_1_35V	(0x2U << RCC_PDR_CR_CFG_Pos)	/* 10��1.35V */
#define	RCC_PDR_CR_CFG_1_4V	(0x3U << RCC_PDR_CR_CFG_Pos)	/* 11��1.4V */

#define	RCC_PDR_CR_EN_Pos	0	/* �µ縴λʹ�� */
#define	RCC_PDR_CR_EN_Msk	(0x1U << RCC_PDR_CR_EN_Pos)

#define	RCC_BOR_CR_CFG_Pos	1	/* �µ縴λ��ѹ���� */
#define	RCC_BOR_CR_CFG_Msk	(0x3U << RCC_BOR_CR_CFG_Pos)
#define	RCC_BOR_CR_CFG_1_7V	(0x0U << RCC_BOR_CR_CFG_Pos)	/* 00��1.7V */
#define	RCC_BOR_CR_CFG_1_6V	(0x1U << RCC_BOR_CR_CFG_Pos)	/* 01��1.6V */
#define	RCC_BOR_CR_CFG_1_65V	(0x2U << RCC_BOR_CR_CFG_Pos)	/* 10��1.65V */
#define	RCC_BOR_CR_CFG_1_75V	(0x3U << RCC_BOR_CR_CFG_Pos)	/* 11��1.75V */

#define	RCC_BOR_CR_OFF_BOR_Pos	0	/* �µ縴λʹ�� */
#define	RCC_BOR_CR_OFF_BOR_Msk	(0x1U << RCC_BOR_CR_OFF_BOR_Pos)
	/* 0��ʹ��BOR */
	/* 1���ر�BOR */
  
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

/* LSCLK�Զ��л�ʹ�� ��غ��� */
extern void RCC_SYSCLK_CR_LSCATS_Setable(FunState NewState);
extern FunState RCC_SYSCLK_CR_LSCATS_Getable(void);

/* Sleep/DeepSleepģʽ��EXTI�������� ��غ��� */
extern void RCC_SYSCLK_CR_SLP_ENEXTI_Setable(FunState NewState);
extern FunState RCC_SYSCLK_CR_SLP_ENEXTI_Getable(void);

/* APBʱ�ӷ�Ƶѡ�� ��غ��� */
extern void RCC_SYSCLK_CR_APBPRES_Set(uint32_t SetValue);
extern uint32_t RCC_SYSCLK_CR_APBPRES_Get(void);

/* AHBʱ�ӷ�Ƶѡ�� ��غ��� */
extern void RCC_SYSCLK_CR_AHBPRES_Set(uint32_t SetValue);
extern uint32_t RCC_SYSCLK_CR_AHBPRES_Get(void);

/* CPU�ں�systick����ʱ��ѡ�� ��غ��� */
extern void RCC_SYSCLK_CR_STCLKSEL_Set(uint32_t SetValue);
extern uint32_t RCC_SYSCLK_CR_STCLKSEL_Get(void);

/* ϵͳʱ��Դѡ�� ��غ��� */
extern void RCC_SYSCLK_CR_SYSCLKSEL_Set(uint32_t SetValue);
extern uint32_t RCC_SYSCLK_CR_SYSCLKSEL_Get(void);

/* RCHFƵ��ѡ��Ĵ��� ��غ��� */
extern void RCC_RCHF_CR_FSEL_Set(uint32_t SetValue);
extern uint32_t RCC_RCHF_CR_FSEL_Get(void);

/* RCHFʹ�ܼĴ��� ��غ��� */
extern void RCC_RCHF_CR_EN_Setable(FunState NewState);
extern FunState RCC_RCHF_CR_EN_Getable(void);

/* RC4MƵ�ʵ�У�Ĵ��� ��غ��� */
extern void RCC_RC4M_TR_Write(uint32_t SetValue);
extern uint32_t RCC_RC4M_TR_Read(void);

/* PLL��Ƶ�� ��غ��� */
extern void RCC_PLL_CR_Write(uint32_t SetValue);
extern uint32_t RCC_PLL_CR_Read(void);

/* PLL������־ ��غ��� */
extern FlagStatus RCC_PLL_CR_LOCKED_Chk(void);

/* PLL�ο�ʱ��Ԥ��Ƶ��Ŀ���ǲ���1MHz�ο�ʱ�Ӹ�PLL�� ��غ��� */
extern void RCC_PLL_CR_REFPRSC_Set(uint32_t SetValue);
extern uint32_t RCC_PLL_CR_REFPRSC_Get(void);

/* PLL���ѡ��Ĵ��� ��غ��� */
extern void RCC_PLL_CR_OSEL_Set(uint32_t SetValue);
extern uint32_t RCC_PLL_CR_OSEL_Get(void);

/* PLL����ѡ��Ĵ��� ��غ��� */
extern void RCC_PLL_CR_INSEL_Set(uint32_t SetValue);
extern uint32_t RCC_PLL_CR_INSEL_Get(void);

/* PLLʹ�ܼĴ��� ��غ��� */
extern void RCC_PLL_CR_EN_Setable(FunState NewState);
extern FunState RCC_PLL_CR_EN_Getable(void);

/* RCLPʹ�ܱ�־�ź� ��غ��� */
extern FlagStatus RCC_RCLP_CR_OFF_EN_Chk(void);

/* ����ģʽ��RCLP���ƼĴ��� ��غ��� */
extern void RCC_RCLP_CR_LPM_RCLP_OFF_Setable(FunState NewState);
extern FunState RCC_RCLP_CR_LPM_RCLP_OFF_Getable(void);

/* RCLP��Уֵ�Ĵ��� ��غ��� */
extern void RCC_RCLP_TR_Write(uint32_t SetValue);
extern uint32_t RCC_RCLP_TR_Read(void);

/* XTLF����ʱ���ֶ��л��Ĵ��� ��غ��� */
extern void RCC_XTLF_CR_Write(uint32_t SetValue);
extern uint32_t RCC_XTLF_CR_Read(void);

/* XTLFʹ�ܼĴ��� ��غ��� */
extern void RCC_XTLF_CR_EN_Set(uint32_t SetValue);
extern uint32_t RCC_XTLF_CR_EN_Get(void);

/* XTLF��������ѡ�� ��غ��� */
extern void RCC_XTLF_CR_IPW_Set(uint32_t SetValue);
extern uint32_t RCC_XTLF_CR_IPW_Get(void);

/* AHB Master���ȼ����üĴ��� ��غ��� */
extern void RCC_AHBM_CR_MPRIL_Set(uint32_t SetValue);
extern uint32_t RCC_AHBM_CR_MPRIL_Get(void);

/* ����ģ�鸴λʹ�� ��غ��� */
extern void RCC_PRST_EN_Write(uint32_t SetValue);
extern uint32_t RCC_PRST_EN_Read(void);

/* DMAģ�鸴λ ��غ��� */
extern void RCC_AHBRST_CR_DMARST_Setable(FunState NewState);
extern FunState RCC_AHBRST_CR_DMARST_Getable(void);

/* UART5ģ�鸴λ ��غ��� */
extern void RCC_APBRST_CR1_UART5RST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR1_UART5RST_Getable(void);

/* UART4ģ�鸴λ ��غ��� */
extern void RCC_APBRST_CR1_UART4RST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR1_UART4RST_Getable(void);

/* GPTIM1ģ�鸴λ ��غ��� */
extern void RCC_APBRST_CR1_GT1RST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR1_GT1RST_Getable(void);

/* GPTIM0ģ�鸴λ ��غ��� */
extern void RCC_APBRST_CR1_GT0RST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR1_GT0RST_Getable(void);

/* LCDģ�鸴λ ��غ��� */
extern void RCC_APBRST_CR1_LCDRST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR1_LCDRST_Getable(void);

/* U7816ģ�鸴λ ��غ��� */
extern void RCC_APBRST_CR1_U7816RST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR1_U7816RST_Getable(void);

/* SPI2ģ�鸴λ ��غ��� */
extern void RCC_APBRST_CR1_SPI2RST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR1_SPI2RST_Getable(void);

/* LPUART0ģ�鸴λ ��غ��� */
extern void RCC_APBRST_CR1_LPUART0RST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR1_LPUART0RST_Getable(void);

/* I2Cģ�鸴λ ��غ��� */
extern void RCC_APBRST_CR1_I2CRST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR1_I2CRST_Getable(void);

/* LPTIM32ģ�鸴λ ��غ��� */
extern void RCC_APBRST_CR1_LPT32RST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR1_LPT32RST_Getable(void);

/* ATIMģ�鸴λ ��غ��� */
extern void RCC_APBRST_CR2_ATRST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR2_ATRST_Getable(void);

/* BSTIMģ�鸴λ ��غ��� */
extern void RCC_APBRST_CR2_BTRST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR2_BTRST_Getable(void);

/* ADC��������λ ��غ��� */
extern void RCC_APBRST_CR2_ADCCRST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR2_ADCCRST_Getable(void);

/* ADCģ�鸴λ ��غ��� */
extern void RCC_APBRST_CR2_ADCRST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR2_ADCRST_Getable(void);

/* �˷�ģ�鸴λ ��غ��� */
extern void RCC_APBRST_CR2_OPARST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR2_OPARST_Getable(void);

/* AESģ�鸴λ ��غ��� */
extern void RCC_APBRST_CR2_AESRST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR2_AESRST_Getable(void);

/* CRCģ�鸴λ ��غ��� */
extern void RCC_APBRST_CR2_CRCRST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR2_CRCRST_Getable(void);

/* RNGģ�鸴λ ��غ��� */
extern void RCC_APBRST_CR2_RNGRST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR2_RNGRST_Getable(void);

/* UART1ģ�鸴λ ��غ��� */
extern void RCC_APBRST_CR2_UART1RST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR2_UART1RST_Getable(void);

/* UART0ģ�鸴λ ��غ��� */
extern void RCC_APBRST_CR2_UART0RST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR2_UART0RST_Getable(void);

/* SPI1ģ�鸴λ ��غ��� */
extern void RCC_APBRST_CR2_SPI1RST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR2_SPI1RST_Getable(void);

/* UART�������ģ�鸴λ ��غ��� */
extern void RCC_APBRST_CR2_UCIRRST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR2_UCIRRST_Getable(void);

/* LPUART1ģ�鸴λ ��غ��� */
extern void RCC_APBRST_CR2_LPUART1RST_Setable(FunState NewState);
extern FunState RCC_APBRST_CR2_LPUART1RST_Getable(void);

/* XTHF��ǿ������ ��غ��� */
extern void RCC_XTHF_CR_CFG_Set(uint32_t SetValue);
extern uint32_t RCC_XTHF_CR_CFG_Get(void);

/* XTHFʹ�ܼĴ��� ��غ��� */
extern void RCC_XTHF_CR_EN_Setable(FunState NewState);
extern FunState RCC_XTHF_CR_EN_Getable(void);

/* RC4M���Ԥ��Ƶ  ��غ��� */
extern void RCC_RC4M_CR_PSC_Set(uint32_t SetValue);
extern uint32_t RCC_RC4M_CR_PSC_Get(void);

/* RC4Mʹ�ܼĴ��� ��غ��� */
extern void RCC_RC4M_CR_EN_Setable(FunState NewState);
extern FunState RCC_RC4M_CR_EN_Getable(void);

/* RCHFƵ�ʵ�У�Ĵ��� ��غ��� */
extern void RCC_RCHF_TR_Write(uint32_t SetValue);
extern uint32_t RCC_RCHF_TR_Read(void);

extern void RCC_OPC_CR1_EXTICKE_Setable(FunState NewState);
extern FunState RCC_OPC_CR1_EXTICKE_Getable(void);

/* EXTI�жϲ���ʱ��ѡ�� ��غ��� */
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

/* I2C��������ʱ��ѡ�� ��غ��� */
extern void RCC_OPC_CR1_I2CCKS_Set(uint32_t SetValue);
extern uint32_t RCC_OPC_CR1_I2CCKS_Get(void);
extern void RCC_OPC_CR1_UART1CKE_Setable(FunState NewState);
extern FunState RCC_OPC_CR1_UART1CKE_Getable(void);
extern void RCC_OPC_CR1_UART0CKE_Setable(FunState NewState);
extern FunState RCC_OPC_CR1_UART0CKE_Getable(void);

/* UART1����ʱ��ѡ�� ��غ��� */
extern void RCC_OPC_CR1_UART1CKS_Set(uint32_t SetValue);
extern uint32_t RCC_OPC_CR1_UART1CKS_Get(void);

/* UART0����ʱ��ѡ�� ��غ��� */
extern void RCC_OPC_CR1_UART0CKS_Set(uint32_t SetValue);
extern uint32_t RCC_OPC_CR1_UART0CKS_Get(void);

/* ���������������ʱ�ӷ�Ƶ ��غ��� */
extern void RCC_OPC_CR2_RNGPRSC_Set(uint32_t SetValue);
extern uint32_t RCC_OPC_CR2_RNGPRSC_Get(void);

/* ADC����ʱ��Ԥ��Ƶ ��غ��� */
extern void RCC_OPC_CR2_ADCPRSC_Set(uint32_t SetValue);
extern uint32_t RCC_OPC_CR2_ADCPRSC_Get(void);
extern void RCC_OPC_CR2_FLSCKE_Setable(FunState NewState);
extern FunState RCC_OPC_CR2_FLSCKE_Getable(void);
extern void RCC_OPC_CR2_RNGCKE_Setable(FunState NewState);
extern FunState RCC_OPC_CR2_RNGCKE_Getable(void);
extern void RCC_OPC_CR2_ADCCKE_Setable(FunState NewState);
extern FunState RCC_OPC_CR2_ADCCKE_Getable(void);

/* ADC����ʱ��ѡ�� ��غ��� */
extern void RCC_OPC_CR2_ADCCKS_Set(uint32_t SetValue);
extern uint32_t RCC_OPC_CR2_ADCCKS_Get(void);
extern void RCC_OPC_CR2_LPTCKE_Setable(FunState NewState);
extern FunState RCC_OPC_CR2_LPTCKE_Getable(void);

/* LPTIM����ʱ��ѡ�� ��غ��� */
extern void RCC_OPC_CR2_LPTCKS_Set(uint32_t SetValue);
extern uint32_t RCC_OPC_CR2_LPTCKS_Get(void);
extern void RCC_OPC_CR2_BTCKE_Setable(FunState NewState);
extern FunState RCC_OPC_CR2_BTCKE_Getable(void);

/* BSTIM����ʱ��Դѡ�� ��غ��� */
extern void RCC_OPC_CR2_BTCKS_Set(uint32_t SetValue);
extern uint32_t RCC_OPC_CR2_BTCKS_Get(void);

/* ����ʱ�����ú��� */
extern void RCC_PERCLK_SetableEx(uint32_t periph_def, FunState NewState);

/* RCHF��ʼ�� */
void RCC_RCHF_Init(RCC_RCHF_InitTypeDef* para);

/* PLL��ʼ�� */
void RCC_PLL_Init(RCC_PLL_InitTypeDef* para);

/* ϵͳʱ�ӳ�ʼ�� */
void RCC_SysClk_Init(RCC_SYSCLK_InitTypeDef* para);

/* RC4M��ʼ�� */
void RCC_RC4M_Init(RCC_RC4M_InitTypeDef* para);

extern void RCC_Init_RCHF_Trim( uint8_t ClkMode );

extern void RCC_GetClocksFreq(RCC_ClocksType* para);

extern void RCC_FDET_IER_HFDET_IE_Setable(FunState NewState);
extern FunState RCC_FDET_IER_HFDET_IE_Getable(void);
extern void RCC_FDET_IER_LFDET_IE_Setable(FunState NewState);
extern FunState RCC_FDET_IER_LFDET_IE_Getable(void);

/* ��Ƶ����ͣ����ģ����� ��غ��� */
extern void RCC_FDET_ISR_HFDETO_Clr(void);
extern FlagStatus RCC_FDET_ISR_HFDETO_Chk(void);

/* ��Ƶ����ͣ����ģ����� ��غ��� */
extern FlagStatus RCC_FDET_ISR_LFDETO_Chk(void);

/* ��Ƶͣ�����жϱ�־�Ĵ��� ��غ��� */
extern FlagStatus RCC_FDET_ISR_HFDETIF_Chk(void);

/* ��Ƶͣ�����жϱ�־�Ĵ��� ��غ��� */
extern void RCC_FDET_ISR_LFDETIF_Clr(void);
extern FlagStatus RCC_FDET_ISR_LFDETIF_Chk(void);

/* �µ縴λ��ѹ���� ��غ��� */
extern void RCC_PDR_CR_CFG_Set(uint32_t SetValue);
extern uint32_t RCC_PDR_CR_CFG_Get(void);

/* �µ縴λʹ�� ��غ��� */
extern void RCC_PDR_CR_EN_Setable(FunState NewState);
extern FunState RCC_PDR_CR_EN_Getable(void);

extern void RCC_BOR_Deinit(void);

/* �µ縴λ��ѹ���� ��غ��� */
extern void RCC_BOR_CR_CFG_Set(uint32_t SetValue);
extern uint32_t RCC_BOR_CR_CFG_Get(void);

/* �µ縴λʹ�� ��غ��� */
extern void RCC_BOR_CR_OFF_BOR_Setable(FunState NewState);
extern FunState RCC_BOR_CR_OFF_BOR_Getable(void);

/* �����궨�� */
//����ʱ�ӿ��Ʋ�������
#define	DCUCLK			(0x01000000 + RCC_PCLK_CR1_DCU_PCE_Pos)	//31	//DCU����ʱ��ʹ�ܣ���ʹ��
#define	BEEPCLK		  (0x01000000 + RCC_PCLK_CR1_BEEP_PCE_Pos)	//16	//BEEPER����ʱ��ʹ�ܣ���ʹ��
#define	PADCLK		  (0x01000000 + RCC_PCLK_CR1_PAD_PCE_Pos)	//7	//PADCFG����ʱ��ʹ�ܣ���ʹ��
#define	ANACCLK			(0x01000000 + RCC_PCLK_CR1_ANAC_PCE_Pos)	//6	//ANAC����ʱ��ʹ�ܣ���ʹ��
#define	IWDTCLK			(0x01000000 + RCC_PCLK_CR1_IWDT_PCE_Pos)	//5	//IWDT����ʱ��ʹ�ܣ���ʹ��
#define	SCUCLK			(0x01000000 + RCC_PCLK_CR1_SCU_PCE_Pos)	//4	//SCU����ʱ��ʹ�ܣ���ʹ��
#define	PMUCLK			(0x01000000 + RCC_PCLK_CR1_PMU_PCE_Pos)	//3	//PMU����ʱ��ʹ�ܣ���ʹ��
#define	RTCCLK			(0x01000000 + RCC_PCLK_CR1_RTC_PCE_Pos)	//2	//RTC����ʱ��ʹ�ܣ���ʹ��
#define	LPTCLK			(0x01000000 + RCC_PCLK_CR1_LPT_PCE_Pos)	//0	//LPTIM����ʱ��ʹ�ܣ���ʹ��   

#define	ADCCLK			(0x02000000 + RCC_PCLK_CR2_ADC_PCE_Pos)	//8	/* ADCʱ��ʹ�ܣ���ʹ�� */
#define	WWDTCLK			(0x02000000 + RCC_PCLK_CR2_WWDT_PCE_Pos)	//7	/* WWDTʱ��ʹ�ܣ���ʹ�� */
#define	RAMBISTCLK	(0x02000000 + RCC_PCLK_CR2_RAMBIST_PCE_Pos)	//6	/* RAMBISTʱ��ʹ�ܣ���ʹ�� */
#define	FLSCLK			(0x02000000 + RCC_PCLK_CR2_FLS_PCE_Pos)	//5	/* FLSC��Flash��д��������ʱ��ʹ�ܣ���ʹ�� */
#define	DMACLK			(0x02000000 + RCC_PCLK_CR2_DMA_PCE_Pos)	//4	/* DMAʱ��ʹ�ܣ���ʹ�� */
#define	LCDCLK			(0x02000000 + RCC_PCLK_CR2_LCD_PCE_Pos)	//3	/* LCDʱ��ʹ�ܣ���ʹ�� */
#define	AESCLK			(0x02000000 + RCC_PCLK_CR2_AES_PCE_Pos)	//2	/* AESʱ��ʹ�ܣ���ʹ�� */
#define	RNGCLK			(0x02000000 + RCC_PCLK_CR2_RNG_PCE_Pos)	//1	/* RNGʱ��ʹ�ܣ���ʹ�� */
#define	CRCCLK			(0x02000000 + RCC_PCLK_CR2_CRC_PCE_Pos)	//0	/* CRCʱ��ʹ�ܣ���ʹ�� */

#define	I2CCLK			(0x03000000 + RCC_PCLK_CR3_I2C_PCE_Pos)	//24	//I2C����ʱ��ʹ��
#define	LPUART1CLK		(0x03000000 + RCC_PCLK_CR3_LPUART1_PCE_Pos)	//18	//LPUART1����ʱ��ʹ��
#define	U7816CLK		(0x03000000 + RCC_PCLK_CR3_U7816_PCE_Pos)	//16	//U7816����ʱ��ʹ�ܣ���ʹ��
#define	LPUART0CLK		(0x03000000 + RCC_PCLK_CR3_LPUART0_PCE_Pos)	//15	//LPUART0����ʱ��ʹ��
#define	UCIRCLK   	(0x03000000 + RCC_PCLK_CR3_UCIR_PCE_Pos)	//14	//UART�����������ʱ��ʹ��
#define	UART5CLK		(0x03000000 + RCC_PCLK_CR3_UART5_PCE_Pos)	//13	//UART5����ʱ��ʹ��
#define	UART4CLK		(0x03000000 + RCC_PCLK_CR3_UART4_PCE_Pos)	//12	//UART4����ʱ��ʹ��
#define	UART1CLK		(0x03000000 + RCC_PCLK_CR3_UART1_PCE_Pos)	//9	//UART1����ʱ��ʹ��
#define	UART0CLK		(0x03000000 + RCC_PCLK_CR3_UART0_PCE_Pos)	//8	//UART0����ʱ��ʹ��
#define	SPI2CLK			(0x03000000 + RCC_PCLK_CR3_SPI2_PCE_Pos)	//1	/* SPI2ʱ��ʹ�� */
#define	SPI1CLK			(0x03000000 + RCC_PCLK_CR3_SPI1_PCE_Pos)	//0	/* SPI1ʱ��ʹ�� */

#define	ATCLK		(0x04000000 + RCC_PCLK_CR4_AT_PCE_Pos)	//4	/* ����ģ���·ʱ��1ʹ�ܣ���ʹ�� */
#define	GT1CLK		(0x04000000 + RCC_PCLK_CR4_GT1_PCE_Pos)	//3	/* ����ģ���·ʱ��2(ҲΪ����ʱ��)ʹ�ܣ���ʹ�� */
#define	GT0CLK		(0x04000000 + RCC_PCLK_CR4_GT0_PCE_Pos)	//2/* ������Ԫ�Ĵ���ʱ��ʹ�� */
#define	BTCLK			(0x04000000 + RCC_PCLK_CR4_BT_PCE_Pos)		//0	/* PAEʱ��ʹ�ܣ���ʹ�� */						
         
#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_RCC_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
