/**
  ******************************************************************************
  * @file    fm33l0xx_pmu.h
  * @author  FM33L0xx Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file contains all the functions prototypes for the PMU firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33L0XX_PMU_H
#define __FM33L0XX_PMU_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33L0XX.h" 
typedef struct
{
	uint32_t PMOD;				/*!<低功耗模式配置  */	
	FunState CVS;				/*!<内核电压降低使能控制  */
	uint32_t SLPDP;				/*!<DeepSleep控制寄存器  */
	uint32_t WKFSEL;		/*!<Sleep/DeepSleep唤醒后的系统频率  */	
	uint32_t LDO_LPM;		/*!<LDO低功耗模式配置  */
	uint32_t SCR;				/*!<M0系统控制寄存器，一般配置为0即可  */	
}PMU_SleepCfg_InitTypeDef;
	 
	 
//------------------------------------------------------------------------------   
#define	PMU_CR_LDO_LPM_Pos	18	/* LDO低功耗模式配置 (LDO Low Power Mode) */
#define	PMU_CR_LDO_LPM_Msk	(0x3U << PMU_CR_LDO_LPM_Pos)
#define	PMU_CR_LDO_LPM_DIS	(0x1U << PMU_CR_LDO_LPM_Pos)	/* 01: 正常模式 */
#define	PMU_CR_LDO_LPM_EN	(0x2U << PMU_CR_LDO_LPM_Pos)	/* 10: LDO进入低功耗模式 */

#define	PMU_CR_LDO15EN_Pos	17	/* LDO15使能状态，只读 */
#define	PMU_CR_LDO15EN_Msk	(0x1U << PMU_CR_LDO15EN_Pos)

#define	PMU_CR_LDO15EN_B_Pos	16
#define	PMU_CR_LDO15EN_B_Msk	(0x1U << PMU_CR_LDO15EN_B_Pos)

#define	PMU_CR_WKFSEL_Pos	10	/* Sleep/DeepSleep唤醒后的系统频率 (Wakeup Frequency Select) */
#define	PMU_CR_WKFSEL_Msk	(0x3U << PMU_CR_WKFSEL_Pos)
#define	PMU_CR_WKFSEL_RCHF_8M	(0x0U << PMU_CR_WKFSEL_Pos)	/* 00：RCHF-8MHz */
#define	PMU_CR_WKFSEL_RCHF_16M	(0x1U << PMU_CR_WKFSEL_Pos)	/* 01：RCHF-16MHz */
#define	PMU_CR_WKFSEL_RCHF_24M	(0x2U << PMU_CR_WKFSEL_Pos)	/* 10/11：RCHF-24MHz */

#define	PMU_CR_SLPDP_Pos	9	/* DeepSleep控制寄 */
#define	PMU_CR_SLPDP_Msk	(0x1U << PMU_CR_SLPDP_Pos)
#define	PMU_CR_SLPDP_SLEEP	(0x0U << PMU_CR_SLPDP_Pos)	/* 0：Sleep模式 */
#define	PMU_CR_SLPDP_DEEPSLEEP	(0x1U << PMU_CR_SLPDP_Pos)	/* 1：DeepSleep模式 */

#define	PMU_CR_CVS_Pos	8	/* 低功耗模式内核电压降低0：低功耗模式下不使能内核电压调整1：低功耗模式下降低内核电压 在Sleep下，如果置位了SLPDP位即为DeepSleep模式；该位仅在Sleep下有效 */
#define	PMU_CR_CVS_Msk	(0x1U << PMU_CR_CVS_Pos)

#define	PMU_CR_PMOD_Pos	0	/* 低功耗模式配置寄存器 (Power Mode) */
#define	PMU_CR_PMOD_Msk	(0x3U << PMU_CR_PMOD_Pos)
#define	PMU_CR_PMOD_ACTIVE	(0x0U << PMU_CR_PMOD_Pos)	/* 00：Active/LP Active mode */
#define	PMU_CR_PMOD_LPRUN	(0x1U << PMU_CR_PMOD_Pos)	/* 01: LPRUN mode */
#define	PMU_CR_PMOD_SLEEP	(0x2U << PMU_CR_PMOD_Pos)	/* 10：Sleep/DeepSleep mode */

#define	PMU_WKTR_TRHR_Pos	0	/* 唤醒时间控制寄存器 */
#define	PMU_WKTR_TRHR_Msk	(0x3U << PMU_WKTR_TRHR_Pos)
#define	PMU_WKTR_TRHR_0US	(0x0U << PMU_WKTR_TRHR_Pos)	/* 00：0us */
#define	PMU_WKTR_TRHR_4US	(0x1U << PMU_WKTR_TRHR_Pos)	/* 01：4us */
#define	PMU_WKTR_TRHR_8US	(0x2U << PMU_WKTR_TRHR_Pos)	/* 10：8us */
#define	PMU_WKTR_TRHR_16US	(0x3U << PMU_WKTR_TRHR_Pos)	/* 11：16us */

#define	PMU_WKFR_ADCWKF_Pos	31	/* ADC中断唤醒标志 */
#define	PMU_WKFR_ADCWKF_Msk	(0x1U << PMU_WKFR_ADCWKF_Pos)

#define	PMU_WKFR_RTCWKF_Pos	28	/* RTC中断唤醒标志 */
#define	PMU_WKFR_RTCWKF_Msk	(0x1U << PMU_WKFR_RTCWKF_Pos)

#define	PMU_WKFR_SVDWKF_Pos	27	/* SVD中断唤醒标志 */
#define	PMU_WKFR_SVDWKF_Msk	(0x1U << PMU_WKFR_SVDWKF_Pos)

#define	PMU_WKFR_LFDETWKF_Pos	26	/* SVD中断唤醒标志 */
#define	PMU_WKFR_LFDETWKF_Msk	(0x1U << PMU_WKFR_LFDETWKF_Pos)

#define	PMU_WKFR_VREFWKF_Pos	25	/* VREF1P22基准源建立中断唤醒标志 */
#define	PMU_WKFR_VREFWKF_Msk	(0x1U << PMU_WKFR_VREFWKF_Pos)

#define	PMU_WKFR_IOWKF_Pos	24	/* IO中断唤醒标志 */
#define	PMU_WKFR_IOWKF_Msk	(0x1U << PMU_WKFR_IOWKF_Pos)

#define	PMU_WKFR_I2CWKF_Pos	23	/* I2C中断唤醒标志 */
#define	PMU_WKFR_I2CWKF_Msk	(0x1U << PMU_WKFR_I2CWKF_Pos)

#define	PMU_WKFR_LPU1WKF_Pos	21	/* LPUART1中断唤醒标志 */
#define	PMU_WKFR_LPU1WKF_Msk	(0x1U << PMU_WKFR_LPU1WKF_Pos)

#define	PMU_WKFR_LPU0WKF_Pos	20	/* LPUART0中断唤醒标志 */
#define	PMU_WKFR_LPU0WKF_Msk	(0x1U << PMU_WKFR_LPU0WKF_Pos)

#define	PMU_WKFR_UART1WKF_Pos	19	/* UART1中断唤醒标志 */
#define	PMU_WKFR_UART1WKF_Msk	(0x1U << PMU_WKFR_UART1WKF_Pos)

#define	PMU_WKFR_UART0WKF_Pos	18	/* UART0中断唤醒标志 */
#define	PMU_WKFR_UART0WKF_Msk	(0x1U << PMU_WKFR_UART0WKF_Pos)

#define	PMU_WKFR_OPA2WKF_Pos	17	/* OPA2（比较器模式）中断唤醒标志 */
#define	PMU_WKFR_OPA2WKF_Msk	(0x1U << PMU_WKFR_OPA2WKF_Pos)

#define	PMU_WKFR_OPA1WKF_Pos	16	/* OPA1（比较器模式）中断唤醒标志 */
#define	PMU_WKFR_OPA1WKF_Msk	(0x1U << PMU_WKFR_OPA1WKF_Pos)

#define	PMU_WKFR_LPTWKF_Pos	10	/* LPTIM32中断唤醒标志 */
#define	PMU_WKFR_LPTWKF_Msk	(0x1U << PMU_WKFR_LPTWKF_Pos)

#define	PMU_WKFR_BSTWKF_Pos	9	/* BSTIM32中断唤醒标志 */
#define	PMU_WKFR_BSTWKF_Msk	(0x1U << PMU_WKFR_BSTWKF_Pos)

#define	PMU_WKFR_DBGWKF_Pos	8	/* CPU Debugger唤醒标志 */
#define	PMU_WKFR_DBGWKF_Msk	(0x1U << PMU_WKFR_DBGWKF_Pos)

#define	PMU_WKFR_WKP7F_Pos	7	/* NWKUP7 Pin唤醒标志 */
#define	PMU_WKFR_WKP7F_Msk	(0x1U << PMU_WKFR_WKP7F_Pos)

#define	PMU_WKFR_WKP6F_Pos	6	/* NWKUP6 Pin唤醒标志 */
#define	PMU_WKFR_WKP6F_Msk	(0x1U << PMU_WKFR_WKP6F_Pos)

#define	PMU_WKFR_WKP5F_Pos	5	/* NWKUP5 Pin唤醒标志 */
#define	PMU_WKFR_WKP5F_Msk	(0x1U << PMU_WKFR_WKP5F_Pos)

#define	PMU_WKFR_WKP4F_Pos	4	/* NWKUP4 Pin唤醒标志 */
#define	PMU_WKFR_WKP4F_Msk	(0x1U << PMU_WKFR_WKP4F_Pos)

#define	PMU_WKFR_WKP3F_Pos	3	/* NWKUP3 Pin唤醒标志 */
#define	PMU_WKFR_WKP3F_Msk	(0x1U << PMU_WKFR_WKP3F_Pos)

#define	PMU_WKFR_WKP2F_Pos	2	/* NWKUP2 Pin唤醒标志 */
#define	PMU_WKFR_WKP2F_Msk	(0x1U << PMU_WKFR_WKP2F_Pos)

#define	PMU_WKFR_WKP1F_Pos	1	/* NWKUP1 Pin唤醒标志 */
#define	PMU_WKFR_WKP1F_Msk	(0x1U << PMU_WKFR_WKP1F_Pos)

#define	PMU_WKFR_WKP0F_Pos	0	/* NWKUP0 Pin唤醒标志 */
#define	PMU_WKFR_WKP0F_Msk	(0x1U << PMU_WKFR_WKP0F_Pos)

#define	PMU_IER_LPACTEIE_Pos	2	/* LPACTIVE错误中断使能0：禁止LPACTIVE错误中断1：使能LPACTIVE错误中断 */
#define	PMU_IER_LPACTEIE_Msk	(0x1U << PMU_IER_LPACTEIE_Pos)

#define	PMU_IER_SLPEIE_Pos	1	/* SLEEP错误中断使能0：禁止SLEEP错误中断1：使能SLEEP错误中断 */
#define	PMU_IER_SLPEIE_Msk	(0x1U << PMU_IER_SLPEIE_Pos)

#define	PMU_ISR_LPACTEIF_Pos	2	/* LPACTIVE错误中断标志，硬件置位，软件写1清零 */
#define	PMU_ISR_LPACTEIF_Msk	(0x1U << PMU_ISR_LPACTEIF_Pos)

#define	PMU_ISR_SLPEIF_Pos	1	/* SLEEP错误中断标志，硬件置位，软件写1清零 */
#define	PMU_ISR_SLPEIF_Msk	(0x1U << PMU_ISR_SLPEIF_Pos)

#define	PMU_VREF_CR_EN_Pos	0	/* VREF1p2使能寄存器 (VREF Enable)  0：关闭VREF1p2   1：使能VREF1p2 */
#define	PMU_VREF_CR_EN_Msk	(0x1U << PMU_VREF_CR_EN_Pos)

#define	PMU_VREF_SR_FLAG_B_Pos	8	/* 模拟输出的VREF1p22寄存器电压建立标志 (VREF stable Flag from analog) */
#define	PMU_VREF_SR_FLAG_B_Msk	(0x1U << PMU_VREF_SR_FLAG_B_Pos)

#define	PMU_VREF_SR_RDY_Pos	1	/* VREF1p22基准电压建立标志 (VREF Ready) */
#define	PMU_VREF_SR_RDY_Msk	(0x1U << PMU_VREF_SR_RDY_Pos)

#define	PMU_VREF_SR_IF_Pos	0	/* VREF1p22基准电压建立中断 (VREF Ready Flag) */
#define	PMU_VREF_SR_IF_Msk	(0x1U << PMU_VREF_SR_IF_Pos)

#define	PMU_VREF_IER_IE_Pos	0	/* VREF1p2基准电压建立中断使能 (VREF Ready Interrupt Enable) 0：禁止产生VREF建立完成中断 1：允许产生VREF建立完成中断 */
#define	PMU_VREF_IER_IE_Msk	(0x1U << PMU_VREF_IER_IE_Pos)

#define	PMU_BUF_CR_VREFPTAT_EN_Pos	4	/* 控制bandgap输出ptat电压(PTAT VREF Enable) 0：Vptat 不使能 1：Vptat 使能 */
#define	PMU_BUF_CR_VREFPTAT_EN_Msk	(0x1U << PMU_BUF_CR_VREFPTAT_EN_Pos)

#define	PMU_BUF_CR_VPTATBUFFER_OUTEN_Pos	3	/* Vptat Buffer模块开关通道输出使能信号，高电平使能有效。(PTAT Buffer Output Enable) 0：Vptat buffer 模块输出不使能 1：Vptat buffer 模块输出使能 */
#define	PMU_BUF_CR_VPTATBUFFER_OUTEN_Msk	(0x1U << PMU_BUF_CR_VPTATBUFFER_OUTEN_Pos)

#define	PMU_BUF_CR_VPTATBUFFER_EN_Pos	2	/* Vptat Buffer模块使能信号，高电平使能有效。(PTAT Buffer Enable) 0：Vptat buffer 模块不使能 1：Vptat buffer 模块使能 */
#define	PMU_BUF_CR_VPTATBUFFER_EN_Msk	(0x1U << PMU_BUF_CR_VPTATBUFFER_EN_Pos)

#define	PMU_BUF_CR_VREFBUFFER_OUTEN_Pos	1	/* Vref Buffer模块开关通道输出使能信号，高电平使能有效。(VREF Buffer Output Enable) 0：Vref buffer 模块输出不使能 1：Vref buffer 模块输出使能 */
#define	PMU_BUF_CR_VREFBUFFER_OUTEN_Msk	(0x1U << PMU_BUF_CR_VREFBUFFER_OUTEN_Pos)

#define	PMU_BUF_CR_VREFBUFFER_EN_Pos	0	/* Vref Buffer模块使能信号，高电平使能有效。(VREF Buffer Enable) 0：Vref buffer 模块不使能  1：Vref buffer 模块使能 */
#define	PMU_BUF_CR_VREFBUFFER_EN_Msk	(0x1U << PMU_BUF_CR_VREFBUFFER_EN_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void PMU_Deinit(void);

/* LDO低功耗模式配置 (LDO Low Power Mode) 相关函数 */
extern void PMU_CR_LDO_LPM_Set(uint32_t SetValue);
extern uint32_t PMU_CR_LDO_LPM_Get(void);

/* LDO15使能状态，只读 相关函数 */
extern FlagStatus PMU_CR_LDO15EN_Chk(void);
extern FlagStatus PMU_CR_LDO15EN_B_Chk(void);

/* Sleep/DeepSleep唤醒后的系统频率 (Wakeup Frequency Select) 相关函数 */
extern void PMU_CR_WKFSEL_Set(uint32_t SetValue);
extern uint32_t PMU_CR_WKFSEL_Get(void);

/* DeepSleep控制寄 相关函数 */
extern void PMU_CR_SLPDP_Set(uint32_t SetValue);
extern uint32_t PMU_CR_SLPDP_Get(void);

/* 低功耗模式内核电压降低0：低功耗模式下不使能内核电压调整1：低功耗模式下降低内核电压 在Sleep下，如果置位了SLPDP位即为DeepSleep模式；该位仅在Sleep下有效 相关函数 */
extern void PMU_CR_CVS_Setable(FunState NewState);
extern FunState PMU_CR_CVS_Getable(void);

/* 低功耗模式配置寄存器 (Power Mode) 相关函数 */
extern void PMU_CR_PMOD_Set(uint32_t SetValue);
extern uint32_t PMU_CR_PMOD_Get(void);

/* 唤醒时间控制寄存器 相关函数 */
extern void PMU_WKTR_TRHR_Set(uint32_t SetValue);
extern uint32_t PMU_WKTR_TRHR_Get(void);

/* ADC中断唤醒标志 相关函数 */
extern FlagStatus PMU_WKFR_ADCWKF_Chk(void);

/* RTC中断唤醒标志 相关函数 */
extern FlagStatus PMU_WKFR_RTCWKF_Chk(void);

/* SVD中断唤醒标志 相关函数 */
extern FlagStatus PMU_WKFR_SVDWKF_Chk(void);

/* SVD中断唤醒标志 相关函数 */
extern FlagStatus PMU_WKFR_LFDETWKF_Chk(void);

/* VREF1P22基准源建立中断唤醒标志 相关函数 */
extern FlagStatus PMU_WKFR_VREFWKF_Chk(void);

/* IO中断唤醒标志 相关函数 */
extern FlagStatus PMU_WKFR_IOWKF_Chk(void);

/* I2C中断唤醒标志 相关函数 */
extern FlagStatus PMU_WKFR_I2CWKF_Chk(void);

/* LPUART1中断唤醒标志 相关函数 */
extern FlagStatus PMU_WKFR_LPU1WKF_Chk(void);

/* LPUART0中断唤醒标志 相关函数 */
extern FlagStatus PMU_WKFR_LPU0WKF_Chk(void);

/* UART1中断唤醒标志 相关函数 */
extern FlagStatus PMU_WKFR_UART1WKF_Chk(void);

/* UART0中断唤醒标志 相关函数 */
extern FlagStatus PMU_WKFR_UART0WKF_Chk(void);

/* OPA2（比较器模式）中断唤醒标志 相关函数 */
extern FlagStatus PMU_WKFR_OPA2WKF_Chk(void);

/* OPA1（比较器模式）中断唤醒标志 相关函数 */
extern FlagStatus PMU_WKFR_OPA1WKF_Chk(void);

/* LPTIM32中断唤醒标志 相关函数 */
extern FlagStatus PMU_WKFR_LPTWKF_Chk(void);

/* BSTIM32中断唤醒标志 相关函数 */
extern FlagStatus PMU_WKFR_BSTWKF_Chk(void);

/* CPU Debugger唤醒标志 相关函数 */
extern void PMU_WKFR_DBGWKF_Clr(void);
extern FlagStatus PMU_WKFR_DBGWKF_Chk(void);

/* NWKUP7 Pin唤醒标志 相关函数 */
extern void PMU_WKFR_WKP7F_Clr(void);
extern FlagStatus PMU_WKFR_WKP7F_Chk(void);

/* NWKUP6 Pin唤醒标志 相关函数 */
extern void PMU_WKFR_WKP6F_Clr(void);
extern FlagStatus PMU_WKFR_WKP6F_Chk(void);

/* NWKUP5 Pin唤醒标志 相关函数 */
extern void PMU_WKFR_WKP5F_Clr(void);
extern FlagStatus PMU_WKFR_WKP5F_Chk(void);

/* NWKUP4 Pin唤醒标志 相关函数 */
extern void PMU_WKFR_WKP4F_Clr(void);
extern FlagStatus PMU_WKFR_WKP4F_Chk(void);

/* NWKUP3 Pin唤醒标志 相关函数 */
extern void PMU_WKFR_WKP3F_Clr(void);
extern FlagStatus PMU_WKFR_WKP3F_Chk(void);

/* NWKUP2 Pin唤醒标志 相关函数 */
extern void PMU_WKFR_WKP2F_Clr(void);
extern FlagStatus PMU_WKFR_WKP2F_Chk(void);

/* NWKUP1 Pin唤醒标志 相关函数 */
extern void PMU_WKFR_WKP1F_Clr(void);
extern FlagStatus PMU_WKFR_WKP1F_Chk(void);

/* NWKUP0 Pin唤醒标志 相关函数 */
extern void PMU_WKFR_WKP0F_Clr(void);
extern FlagStatus PMU_WKFR_WKP0F_Chk(void);

/* LPACTIVE错误中断使能0：禁止LPACTIVE错误中断1：使能LPACTIVE错误中断 相关函数 */
extern void PMU_IER_LPACTEIE_Setable(FunState NewState);
extern FunState PMU_IER_LPACTEIE_Getable(void);

/* SLEEP错误中断使能0：禁止SLEEP错误中断1：使能SLEEP错误中断 相关函数 */
extern void PMU_IER_SLPEIE_Setable(FunState NewState);
extern FunState PMU_IER_SLPEIE_Getable(void);

/* LPACTIVE错误中断标志，硬件置位，软件写1清零 相关函数 */
extern void PMU_ISR_LPACTEIF_Clr(void);
extern FlagStatus PMU_ISR_LPACTEIF_Chk(void);

/* SLEEP错误中断标志，硬件置位，软件写1清零 相关函数 */
extern void PMU_ISR_SLPEIF_Clr(void);
extern FlagStatus PMU_ISR_SLPEIF_Chk(void);

/* VREF1p2使能寄存器 (VREF Enable)  0：关闭VREF1p2   1：使能VREF1p2 相关函数 */
extern void PMU_VREF_CR_EN_Setable(FunState NewState);
extern FunState PMU_VREF_CR_EN_Getable(void);

/* 模拟输出的VREF1p22寄存器电压建立标志 (VREF stable Flag from analog) 相关函数 */
extern FlagStatus PMU_VREF_SR_FLAG_B_Chk(void);

/* VREF1p22基准电压建立标志 (VREF Ready) 相关函数 */
extern FlagStatus PMU_VREF_SR_RDY_Chk(void);

/* VREF1p22基准电压建立中断 (VREF Ready Flag) 相关函数 */
extern void PMU_VREF_SR_IF_Clr(void);
extern FlagStatus PMU_VREF_SR_IF_Chk(void);

/* VREF1p2基准电压建立中断使能 (VREF Ready Interrupt Enable) 0：禁止产生VREF建立完成中断 1：允许产生VREF建立完成中断 相关函数 */
extern void PMU_VREF_IER_IE_Setable(FunState NewState);
extern FunState PMU_VREF_IER_IE_Getable(void);

/* 控制bandgap输出ptat电压(PTAT VREF Enable) 0：Vptat 不使能 1：Vptat 使能 相关函数 */
extern void PMU_BUF_CR_VREFPTAT_EN_Setable(FunState NewState);
extern FunState PMU_BUF_CR_VREFPTAT_EN_Getable(void);

/* Vptat Buffer模块开关通道输出使能信号，高电平使能有效。(PTAT Buffer Output Enable) 0：Vptat buffer 模块输出不使能 1：Vptat buffer 模块输出使能 相关函数 */
extern void PMU_BUF_CR_VPTATBUFFER_OUTEN_Setable(FunState NewState);
extern FunState PMU_BUF_CR_VPTATBUFFER_OUTEN_Getable(void);

/* Vptat Buffer模块使能信号，高电平使能有效。(PTAT Buffer Enable) 0：Vptat buffer 模块不使能 1：Vptat buffer 模块使能 相关函数 */
extern void PMU_BUF_CR_VPTATBUFFER_EN_Setable(FunState NewState);
extern FunState PMU_BUF_CR_VPTATBUFFER_EN_Getable(void);

/* Vref Buffer模块开关通道输出使能信号，高电平使能有效。(VREF Buffer Output Enable) 0：Vref buffer 模块输出不使能 1：Vref buffer 模块输出使能 相关函数 */
extern void PMU_BUF_CR_VREFBUFFER_OUTEN_Setable(FunState NewState);
extern FunState PMU_BUF_CR_VREFBUFFER_OUTEN_Getable(void);

/* Vref Buffer模块使能信号，高电平使能有效。(VREF Buffer Enable) 0：Vref buffer 模块不使能  1：Vref buffer 模块使能 相关函数 */
extern void PMU_BUF_CR_VREFBUFFER_EN_Setable(FunState NewState);
extern FunState PMU_BUF_CR_VREFBUFFER_EN_Getable(void);

extern void PMU_BUF_ALLDISABLE(void);
/********************************
低功耗模式的初始化函数
功能:低功耗模式下各种设置，SLEEP模式，RAM保持设置，内核电压，晶振电路等。
输入：低功耗功能开启前的设置.
 ********************************/
extern void PMU_SleepCfg_Init(PMU_SleepCfg_InitTypeDef* SleepCfg_InitStruct);

#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_PMU_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
