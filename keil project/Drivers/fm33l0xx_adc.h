/**
  ******************************************************************************
  * @file    fm33l0xx_adc.h
  * @author  FM33l0xx Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file contains all the functions prototypes for the ADC firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __FM33L0XX_ADC_H
#define __FM33L0XX_ADC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33L0XX.h" 

#define	ADC_ISR_AWD_AH_Pos	6	/* 模拟看门狗超出上限中断标志 (Analog Watchdog Above High Threshold)当采样值高于AWD_HT时，硬件置位，软件写1清零. */
#define	ADC_ISR_AWD_AH_Msk	(0x1U << ADC_ISR_AWD_AH_Pos)

#define	ADC_ISR_AWD_UL_Pos	5	/* 模拟看门狗低于下限中断标志 (Analog Watchdog Under Low Threshold)当采样值低于AWD_LT时，硬件置位，软件写1清零 */
#define	ADC_ISR_AWD_UL_Msk	(0x1U << ADC_ISR_AWD_UL_Pos)

#define	ADC_ISR_EOCAL_Pos	4	/* 校准结束 (End Of Calibration)硬件置位，软件写1清零1：校准过程结束0：无校准过程 */
#define	ADC_ISR_EOCAL_Msk	(0x1U << ADC_ISR_EOCAL_Pos)

#define	ADC_ISR_BUSY_Pos	3	/* ADC忙标志 (Busy) 1：ADC正在校准、采样或转换过程中 0：ADC空闲 */
#define	ADC_ISR_BUSY_Msk	(0x1U << ADC_ISR_BUSY_Pos)

#define	ADC_ISR_OVR_Pos	2	/* 数据冲突标志，硬件置位，软件写1清零 (Over Run) 当ADC_DATA寄存器中的上一次转换结果还未被读取，新的转换结果又到来时，硬件置位OVR标志。0：没有数据冲突 1：出现数据冲突 */
#define	ADC_ISR_OVR_Msk	(0x1U << ADC_ISR_OVR_Pos)

#define	ADC_ISR_EOS_Pos	1	/* 转换序列结束 (End Of Sequence)所有使能通道都转换完成后，置位EOS，软件写1清零。 */
#define	ADC_ISR_EOS_Msk	(0x1U << ADC_ISR_EOS_Pos)

#define	ADC_ISR_EOC_Pos	0	/* 单次转换结束 (End Of Conversion)每个通道转换完成后，置位EOC，软件写1清零。 */
#define	ADC_ISR_EOC_Msk	(0x1U << ADC_ISR_EOC_Pos)

#define	ADC_IER_AWD_AHIE_Pos	6	/* 模拟看门狗采样值高于上限中断使能，1有效 (Analog Watchdog Above High Threshold Interrupt Enable) */
#define	ADC_IER_AWD_AHIE_Msk	(0x1U << ADC_IER_AWD_AHIE_Pos)

#define	ADC_IER_AWD_ULIE_Pos	5	/* 模拟看门狗采样值低于上限中断使能，1有效 (Analog Watchdog Under Low Threshold Interrupt Enable) */
#define	ADC_IER_AWD_ULIE_Msk	(0x1U << ADC_IER_AWD_ULIE_Pos)

#define	ADC_IER_EOCALIE_Pos	4	/* 校准结束中断使能寄存器 (End Of Calibration Interrupt Enable) 0：禁止EOCAL中断 1：允许EOCAL中断 */
#define	ADC_IER_EOCALIE_Msk	(0x1U << ADC_IER_EOCALIE_Pos)

#define	ADC_IER_OVRIE_Pos	2	/* 数据冲突中断使能寄存器 (Over Run Interrupt Enable) 0：禁止数据冲突中断 1：允许数据冲突中断 */
#define	ADC_IER_OVRIE_Msk	(0x1U << ADC_IER_OVRIE_Pos)

#define	ADC_IER_EOSIE_Pos	1	/* 转换序列结束中断使能寄存器 (End Of Sequence Interrupt Enable) 0：禁止EOS中断 1：允许EOS中断 */
#define	ADC_IER_EOSIE_Msk	(0x1U << ADC_IER_EOSIE_Pos)

#define	ADC_IER_EOCIE_Pos	0	/* 单次转换结束中断使能寄存器 (End Of Conversion Interrupt Enable) 0：禁止EOC中断 1：允许EOC中断 */
#define	ADC_IER_EOCIE_Msk	(0x1U << ADC_IER_EOCIE_Pos)

#define	ADC_CR_START_Pos	1	/* ADC启动转换寄存器，软件写1启动，硬件自动清零。 */
#define	ADC_CR_START_Msk	(0x1U << ADC_CR_START_Pos)

#define	ADC_CR_ADEN_Pos	0	/* ADC使能寄存器 (ADC Enable) 在启动转换前先要置位ADEN，等待至少5个MCLK后再启动转换。0：关闭ADC 1：使能ADC */
#define	ADC_CR_ADEN_Msk	(0x1U << ADC_CR_ADEN_Pos)

#define	ADC_CFGR_CKS_Pos	30	/* ADC工作时钟选择 (ADC Clock Select) */
#define	ADC_CFGR_CKS_Msk	(0x3U << ADC_CFGR_CKS_Pos)
#define	ADC_CFGR_CKS_ADCCLK	(0x0U << ADC_CFGR_CKS_Pos)	/* 00：ADCCLK */
#define	ADC_CFGR_CKS_APBCLK_2	(0x1U << ADC_CFGR_CKS_Pos)	/* 01：APBCLK/2 */
#define	ADC_CFGR_CKS_APBCLK_4	(0x2U << ADC_CFGR_CKS_Pos)	/* 10：APBCLK/4 */
#define	ADC_CFGR_CKS_APBCLK	(0x3U << ADC_CFGR_CKS_Pos)	/* 11：APBCLK */

#define	ADC_CFGR_AWDCH_Pos	26	/* 模拟窗口看门狗监视通道选择，仅在AWDSC=1时有效 (Analog Watchdog Channel Select) */
#define	ADC_CFGR_AWDCH_Msk	(0xfU << ADC_CFGR_AWDCH_Pos)
#define	ADC_CFGR_AWDCH_ADC_IN0	(0x0U << ADC_CFGR_AWDCH_Pos)	/* 0000：AWD监视ADC_IN0 */
#define	ADC_CFGR_AWDCH_ADC_IN1	(0x1U << ADC_CFGR_AWDCH_Pos)	/* 0001：AWD监视ADC_IN1 */
#define	ADC_CFGR_AWDCH_ADC_IN2	(0x2U << ADC_CFGR_AWDCH_Pos)	/* 0010：AWD监视ADC_IN2 */
#define	ADC_CFGR_AWDCH_ADC_IN3	(0x3U << ADC_CFGR_AWDCH_Pos)	/* 0011：AWD监视ADC_IN3 */
#define	ADC_CFGR_AWDCH_ADC_IN4	(0x4U << ADC_CFGR_AWDCH_Pos)	/* 0100：AWD监视ADC_IN4 */
#define	ADC_CFGR_AWDCH_ADC_IN5	(0x5U << ADC_CFGR_AWDCH_Pos)	/* 0101：AWD监视ADC_IN5 */
#define	ADC_CFGR_AWDCH_ADC_IN6	(0x6U << ADC_CFGR_AWDCH_Pos)	/* 0110：AWD监视ADC_IN6 */
#define	ADC_CFGR_AWDCH_ADC_IN7	(0x7U << ADC_CFGR_AWDCH_Pos)	/* 0111：AWD监视ADC_IN7 */
#define	ADC_CFGR_AWDCH_ADC_IN8	(0x8U << ADC_CFGR_AWDCH_Pos)	/* 1000：AWD监视ADC_IN8 */
#define	ADC_CFGR_AWDCH_ADC_IN9	(0x9U << ADC_CFGR_AWDCH_Pos)	/* 1001：AWD监视ADC_IN9 */
#define	ADC_CFGR_AWDCH_ADC_IN10	(0xaU << ADC_CFGR_AWDCH_Pos)	/* 1010：AWD监视ADC_IN10 */
#define	ADC_CFGR_AWDCH_ADC_IN11	(0xbU << ADC_CFGR_AWDCH_Pos)	/* 1011：AWD监视ADC_IN11 */

#define	ADC_CFGR_AWDSC_Pos	25	/* 模拟窗口看门狗单通道或全通道选择 (Analog Watchdog Single Channel mode) */
#define	ADC_CFGR_AWDSC_Msk	(0x1U << ADC_CFGR_AWDSC_Pos)
#define	ADC_CFGR_AWDSC_AWD_ALL	(0x0U << ADC_CFGR_AWDSC_Pos)	/* 0：AWD监视所有被使能的外部输入通道 */
#define	ADC_CFGR_AWDSC_AWD_SINGLE	(0x1U << ADC_CFGR_AWDSC_Pos)	/* 1：AWD监视AWDCH指定的单个通道 */

#define	ADC_CFGR_AWDEN_Pos	24	/* 模拟窗口看门狗使能寄存器 (Analog Watchdog Enable) 0：关闭AWD 1：使能AWD 仅能在START=0的情况下使能AWD */
#define	ADC_CFGR_AWDEN_Msk	(0x1U << ADC_CFGR_AWDEN_Pos)

#define	ADC_CFGR_OVSS_Pos	20	/* 过采样移位控制寄存器 (Oversampling Shift) */
#define	ADC_CFGR_OVSS_Msk	(0xfU << ADC_CFGR_OVSS_Pos)
#define	ADC_CFGR_OVSS_R_SHIFT_0	(0x0U << ADC_CFGR_OVSS_Pos)	/* 0000：不移位 */
#define	ADC_CFGR_OVSS_R_SHIFT_1	(0x1U << ADC_CFGR_OVSS_Pos)	/* 0001：右移1bit */
#define	ADC_CFGR_OVSS_R_SHIFT_2	(0x2U << ADC_CFGR_OVSS_Pos)	/* 0010：右移2bit */
#define	ADC_CFGR_OVSS_R_SHIFT_3	(0x3U << ADC_CFGR_OVSS_Pos)	/* 0011：右移3bit */
#define	ADC_CFGR_OVSS_R_SHIFT_4	(0x4U << ADC_CFGR_OVSS_Pos)	/* 0100：右移4bit */
#define	ADC_CFGR_OVSS_R_SHIFT_5	(0x5U << ADC_CFGR_OVSS_Pos)	/* 0101：右移5bit */
#define	ADC_CFGR_OVSS_R_SHIFT_6	(0x6U << ADC_CFGR_OVSS_Pos)	/* 0110：右移6bit */
#define	ADC_CFGR_OVSS_R_SHIFT_7	(0x7U << ADC_CFGR_OVSS_Pos)	/* 0111：右移7bit */
#define	ADC_CFGR_OVSS_R_SHIFT_8	(0x8U << ADC_CFGR_OVSS_Pos)	/* 1000：右移8bit */

#define	ADC_CFGR_OVSR_Pos	17	/* 过采样率控制 (Oversampling Ratio) */
#define	ADC_CFGR_OVSR_Msk	(0x7U << ADC_CFGR_OVSR_Pos)
#define	ADC_CFGR_OVSR_2x	(0x0U << ADC_CFGR_OVSR_Pos)	/* 000：2x */
#define	ADC_CFGR_OVSR_4x	(0x1U << ADC_CFGR_OVSR_Pos)	/* 001：4x */
#define	ADC_CFGR_OVSR_8x	(0x2U << ADC_CFGR_OVSR_Pos)	/* 010：8x */
#define	ADC_CFGR_OVSR_16x	(0x3U << ADC_CFGR_OVSR_Pos)	/* 011：16x */
#define	ADC_CFGR_OVSR_32x	(0x4U << ADC_CFGR_OVSR_Pos)	/* 100：32x */
#define	ADC_CFGR_OVSR_64x	(0x5U << ADC_CFGR_OVSR_Pos)	/* 101：64x */
#define	ADC_CFGR_OVSR_128x	(0x6U << ADC_CFGR_OVSR_Pos)	/* 110：128x */
#define	ADC_CFGR_OVSR_256x	(0x7U << ADC_CFGR_OVSR_Pos)	/* 111：256x */

#define	ADC_CFGR_OVSEN_Pos	16	/* 过采样使能 (Oversampling Enable) 0：禁止过采样 1：使能过采样 */
#define	ADC_CFGR_OVSEN_Msk	(0x1U << ADC_CFGR_OVSEN_Pos)

#define	ADC_CFGR_IOTRFEN_Pos	14	/* 引脚触发信号数字滤波使能 (GPIO Trigger Filter Enable) 0：禁止数字滤波 1：使能数字滤波  */
#define	ADC_CFGR_IOTRFEN_Msk	(0x1U << ADC_CFGR_IOTRFEN_Pos)

#define	ADC_CFGR_TRGCFG_Pos	12	/* 触发信号使能和极性选择 (Trigger Config) */
#define	ADC_CFGR_TRGCFG_Msk	(0x3U << ADC_CFGR_TRGCFG_Pos)
#define	ADC_CFGR_TRGCFG_DISABLE	(0x0U << ADC_CFGR_TRGCFG_Pos)	/* 00：禁止触发 */
#define	ADC_CFGR_TRGCFG_RISING	(0x1U << ADC_CFGR_TRGCFG_Pos)	/* 01：上升沿触发 */
#define	ADC_CFGR_TRGCFG_FALLING	(0x2U << ADC_CFGR_TRGCFG_Pos)	/* 10：下降沿触发 */
#define	ADC_CFGR_TRGCFG_BOTH	(0x3U << ADC_CFGR_TRGCFG_Pos)	/* 11：上升、下降沿都触发 */

#define	ADC_CFGR_SEMI_Pos	11	/* 单次转换半自动模式 (Semi-automatic)，仅在单次转换（CONT=0）时有效 */
#define	ADC_CFGR_SEMI_Msk	(0x1U << ADC_CFGR_SEMI_Pos)
#define	ADC_CFGR_SEMI_AUTO	(0x0U << ADC_CFGR_SEMI_Pos)	/* 0：自动模式 */
#define	ADC_CFGR_SEMI_HALF_AUTO	(0x1U << ADC_CFGR_SEMI_Pos)	/* 1：半自动模式 */

#define	ADC_CFGR_WAIT_Pos	10	/* 等待模式控制 (wait mode) 0：无等待，如果上次转换数据没有及时读取，则可能出现Overrun 1：等待模式，在上次转换数据被读取前，不会启动下一次转换 */
#define	ADC_CFGR_WAIT_Msk	(0x1U << ADC_CFGR_WAIT_Pos)

#define	ADC_CFGR_CONT_Pos	9	/* 连续转换模式使能 (Continuous mode) 0：单次转换 1：连续转换  */
#define	ADC_CFGR_CONT_Msk	(0x1U << ADC_CFGR_CONT_Pos)

#define	ADC_CFGR_OVRM_Pos	8	/* Overrun模式控制 (Overrun mode) */
#define	ADC_CFGR_OVRM_Msk	(0x1U << ADC_CFGR_OVRM_Pos)
#define	ADC_CFGR_OVRM_KEEP	(0x0U << ADC_CFGR_OVRM_Pos)	/* 0：当overrun发生时，保持上次数据，丢弃本次转换值 */
#define	ADC_CFGR_OVRM_COVER	(0x1U << ADC_CFGR_OVRM_Pos)	/* 1：当overrun发生时，覆盖上次数据 */

#define	ADC_CFGR_EXTS_Pos	4	/* 硬件触发源选择 (External trigger select) */
#define	ADC_CFGR_EXTS_Msk	(0xfU << ADC_CFGR_EXTS_Pos)
#define	ADC_CFGR_EXTS_PA8	(0x0U << ADC_CFGR_EXTS_Pos)	/* 0000：PA8 */
#define	ADC_CFGR_EXTS_PB9	(0x1U << ADC_CFGR_EXTS_Pos)	/* 0001：PB9 */
#define	ADC_CFGR_EXTS_ATIM_TROG	(0x3U << ADC_CFGR_EXTS_Pos)	/* 0011：ATIM_TRGO */
#define	ADC_CFGR_EXTS_GPTIM1_TROG	(0x4U << ADC_CFGR_EXTS_Pos)	/* 0100：GPTIM1_TRGO */
#define	ADC_CFGR_EXTS_GPTIM2_TROG	(0x5U << ADC_CFGR_EXTS_Pos)	/* 0101：GPTIM2_TRGO */
#define	ADC_CFGR_EXTS_RTC_TROG	(0x7U << ADC_CFGR_EXTS_Pos)	/* 0111：RTC_TRGO */
#define	ADC_CFGR_EXTS_BSTIM1_TROG	(0x8U << ADC_CFGR_EXTS_Pos)	/* 1000：BSTIM1_TRGO */
#define	ADC_CFGR_EXTS_COMP1_TROG	(0xaU << ADC_CFGR_EXTS_Pos)	/* 1010：COMP1_TRGO */
#define	ADC_CFGR_EXTS_COMP2_TROG	(0xbU << ADC_CFGR_EXTS_Pos)	/* 1011：COMP2_TRGO */

#define	ADC_CFGR_LPM_Pos	3	/* ADC低功耗模式使能，软件可以配置 (Low Power Mode) */
#define	ADC_CFGR_LPM_Msk	(0x1U << ADC_CFGR_LPM_Pos)
#define	ADC_CFGR_LPM_LPM_MODE	(0x0U << ADC_CFGR_LPM_Pos)	/* 0：正常模式 */
#define	ADC_CFGR_LPM_NORMAL_MODE	(0x1U << ADC_CFGR_LPM_Pos)	/* 1：使能ADC低功耗模式，最大工作时钟频率4MHz，最高采样率250Ksps */

#define	ADC_CFGR_SCANDIR_Pos	2	/* 通道扫描顺序控制 (Scan Direction)（共16个通道，实际只会采样被使能的通道） */
#define	ADC_CFGR_SCANDIR_Msk	(0x1U << ADC_CFGR_SCANDIR_Pos)
#define	ADC_CFGR_SCANDIR_FORWARD	(0x0U << ADC_CFGR_SCANDIR_Pos)	/* 0：前向扫描，ADC_IN0->ADC_IN11->REF->TS->OPA1->OPA2 */
#define	ADC_CFGR_SCANDIR_REVERSE	(0x1U << ADC_CFGR_SCANDIR_Pos)	/* 1：反向扫描，OPA2->OPA1->TS->REF->ADC_IN11->ADC_IN0 */

#define	ADC_CFGR_DMACFG_Pos	1	/* DMA模式控制 (DMA Config) */
#define	ADC_CFGR_DMACFG_Msk	(0x1U << ADC_CFGR_DMACFG_Pos)
#define	ADC_CFGR_DMACFG_SINGLE	(0x0U << ADC_CFGR_DMACFG_Pos)	/* 0：单次模式 */
#define	ADC_CFGR_DMACFG_CYCLE	(0x1U << ADC_CFGR_DMACFG_Pos)	/* 1：循环模式 */

#define	ADC_CFGR_DMAEN_Pos	0	/* DMA使能 (DMA Enable) 0：禁止DMA 1：使能DMA  */
#define	ADC_CFGR_DMAEN_Msk	(0x1U << ADC_CFGR_DMAEN_Pos)

#define	ADC_SMTR_CHCG_Pos	8	/* ADC采样通道切换等待时间 (Channel Clock Gating) 在当前通道采样周期完成后，等待CHCG时间（CHCG*ADC工作时钟周期），再切换到下一个采样通道 */
#define	ADC_SMTR_CHCG_Msk	(0xfU << ADC_SMTR_CHCG_Pos)
#define	ADC_SMTR_CHCG_1_TADCCLK	(0x0U << ADC_SMTR_CHCG_Pos)	/* 0000, 0001：1*TADCLK */
#define	ADC_SMTR_CHCG_2_TADCCLK	(0x2U << ADC_SMTR_CHCG_Pos)	/* 0010：2*TADCLK */
#define	ADC_SMTR_CHCG_3_TADCCLK	(0x3U << ADC_SMTR_CHCG_Pos)	/* 0011：3*TADCLK */
#define	ADC_SMTR_CHCG_4_TADCCLK	(0x4U << ADC_SMTR_CHCG_Pos)	/* 0100：4*TADCLK */
#define	ADC_SMTR_CHCG_5_TADCCLK	(0x5U << ADC_SMTR_CHCG_Pos)	/* 0101：5*TADCLK */
#define	ADC_SMTR_CHCG_6_TADCCLK	(0x6U << ADC_SMTR_CHCG_Pos)	/* 0110：6*TADCLK */
#define	ADC_SMTR_CHCG_7_TADCCLK	(0x7U << ADC_SMTR_CHCG_Pos)	/* 0111：7*TADCLK */
#define	ADC_SMTR_CHCG_8_TADCCLK	(0x8U << ADC_SMTR_CHCG_Pos)	/* 1000：8*TADCLK */
#define	ADC_SMTR_CHCG_9_TADCCLK	(0x9U << ADC_SMTR_CHCG_Pos)	/* 1001：9*TADCLK */
#define	ADC_SMTR_CHCG_10_TADCCLK	(0xaU << ADC_SMTR_CHCG_Pos)	/* 1010：10*TADCLK */
#define	ADC_SMTR_CHCG_11_TADCCLK	(0xbU << ADC_SMTR_CHCG_Pos)	/* 1011~1111：11*TADCLK */

#define	ADC_SMTR_SMTS2_Pos	4	/* 慢速通道采样时间控制（*ADC工作时钟周期），用于配置ADC_IN8/9/10/11四个外部通道、以及OPA通道的采样时间 (Sampling Time Select 2)  */
#define	ADC_SMTR_SMTS2_Msk	(0x3U << ADC_SMTR_SMTS2_Pos)
#define	ADC_SMTR_SMTS2_3_5_TMCLK	(0x0U << ADC_SMTR_SMTS2_Pos)	/* 00：3.5*TMCLK */
#define	ADC_SMTR_SMTS2_4_5_TMCLK	(0x1U << ADC_SMTR_SMTS2_Pos)	/* 01：4.5*TMCLK */
#define	ADC_SMTR_SMTS2_6_5_TMCLK	(0x2U << ADC_SMTR_SMTS2_Pos)	/* 10：6.5*TMCLK */
#define	ADC_SMTR_SMTS2_10_5_TMCLK	(0x3U << ADC_SMTR_SMTS2_Pos)	/* 11：10.5*TMCLK */

#define	ADC_SMTR_SMTS1_Pos	0	/* 快速通道采样时间控制（*ADC工作时钟周期），用于配置ADC_IN8/9/10/11四个外部通道、以及OPA通道的采样时间 (Sampling Time Select 2)  */
#define	ADC_SMTR_SMTS1_Msk	(0x3U << ADC_SMTR_SMTS1_Pos)
#define	ADC_SMTR_SMTS1_3_5_TMCLK	(0x0U << ADC_SMTR_SMTS1_Pos)	/* 00：3.5*TMCLK */
#define	ADC_SMTR_SMTS1_4_5_TMCLK	(0x1U << ADC_SMTR_SMTS1_Pos)	/* 01：4.5*TMCLK */
#define	ADC_SMTR_SMTS1_6_5_TMCLK	(0x2U << ADC_SMTR_SMTS1_Pos)	/* 10：6.5*TMCLK */
#define	ADC_SMTR_SMTS1_10_5_TMCLK	(0x3U << ADC_SMTR_SMTS1_Pos)	/* 11：10.5*TMCLK */

#define	ADC_CHER_AINS_Pos	24	/* 单端和差分通道配置，4bit配置4组通道对是否为差分输入，0表示单端输入，1表示差分输入。(Analog Input Select)如果配置为差分输入，则每个差分对所对应的通道都要使能。
比如，将ADC_IN0和ADC_IN1设置为差分输入对，需要进行差分采样时，ECH0和ECH1都要置1。 */
#define	ADC_CHER_AINS_Msk	(0xfU << ADC_CHER_AINS_Pos)
#define	ADC_CHER_AINS_ADC_IN01	(0x1U << ADC_CHER_AINS_Pos)	/* 配置ADC_IN0和ADC_IN1为差分输出 */
#define	ADC_CHER_AINS_ADC_IN23	(0x2U << ADC_CHER_AINS_Pos)	/* 配置ADC_IN2和ADC_IN3为差分输出 */
#define	ADC_CHER_AINS_ADC_IN45	(0x4U << ADC_CHER_AINS_Pos)	/* 配置ADC_IN4和ADC_IN5为差分输出 */
#define	ADC_CHER_AINS_ADC_IN67	(0x8U << ADC_CHER_AINS_Pos)	/* 配置ADC_IN6和ADC_IN7为差分输出 */

#define	ADC_CHER_OPA2CH_Pos	19	/* OPA2输出测量，写1使能 (OPA2 channel)  */
#define	ADC_CHER_OPA2CH_Msk	(0x1U << ADC_CHER_OPA2CH_Pos)

#define	ADC_CHER_OPA1CH_Pos	18	/* OPA1输出测量，写1使能 (OPA1 channel)  */
#define	ADC_CHER_OPA1CH_Msk	(0x1U << ADC_CHER_OPA1CH_Pos)

#define	ADC_CHER_TSCH_Pos	17	/* 温度传感器测量通道，写1使能 (TempSensor channel)  */
#define	ADC_CHER_TSCH_Msk	(0x1U << ADC_CHER_TSCH_Pos)

#define	ADC_CHER_REFCH_Pos	16	/* 内部基准电压测量通道，写1使能 (VREF channel)  */
#define	ADC_CHER_REFCH_Msk	(0x1U << ADC_CHER_REFCH_Pos)

#define	ADC_CHER_ECH11_Pos	11	/* ADC_IN11 测量通道，写1使能  */
#define	ADC_CHER_ECH11_Msk	(0x1U << ADC_CHER_ECH11_Pos)

#define	ADC_CHER_ECH10_Pos	10	/* ADC_IN10 测量通道，写1使能  */
#define	ADC_CHER_ECH10_Msk	(0x1U << ADC_CHER_ECH10_Pos)

#define	ADC_CHER_ECH9_Pos	9	/* ADC_IN9 测量通道，写1使能 */
#define	ADC_CHER_ECH9_Msk	(0x1U << ADC_CHER_ECH9_Pos)

#define	ADC_CHER_ECH8_Pos	8	/* ADC_IN8 测量通道，写1使能 */
#define	ADC_CHER_ECH8_Msk	(0x1U << ADC_CHER_ECH8_Pos)

#define	ADC_CHER_ECH7_Pos	7	/* ADC_IN7 测量通道，写1使能 */
#define	ADC_CHER_ECH7_Msk	(0x1U << ADC_CHER_ECH7_Pos)

#define	ADC_CHER_ECH6_Pos	6	/* ADC_IN6 测量通道，写1使能 */
#define	ADC_CHER_ECH6_Msk	(0x1U << ADC_CHER_ECH6_Pos)

#define	ADC_CHER_ECH5_Pos	5	/* ADC_IN5 测量通道，写1使能 */
#define	ADC_CHER_ECH5_Msk	(0x1U << ADC_CHER_ECH5_Pos)

#define	ADC_CHER_ECH4_Pos	4	/* ADC_IN4 测量通道，写1使能 */
#define	ADC_CHER_ECH4_Msk	(0x1U << ADC_CHER_ECH4_Pos)

#define	ADC_CHER_ECH3_Pos	3	/* ADC_IN3 测量通道，写1使能 */
#define	ADC_CHER_ECH3_Msk	(0x1U << ADC_CHER_ECH3_Pos)

#define	ADC_CHER_ECH2_Pos	2	/* ADC_IN2 测量通道，写1使能 */
#define	ADC_CHER_ECH2_Msk	(0x1U << ADC_CHER_ECH2_Pos)

#define	ADC_CHER_ECH1_Pos	1	/* ADC_IN1 测量通道，写1使能 */
#define	ADC_CHER_ECH1_Msk	(0x1U << ADC_CHER_ECH1_Pos)

#define	ADC_CHER_ECH0_Pos	0	/* ADC_IN0 测量通道，写1使能 */
#define	ADC_CHER_ECH0_Msk	(0x1U << ADC_CHER_ECH0_Pos)

#define	ADC_DR_ADC_DATA_Pos	0	/* ADC转换结果 (ADC conversion data)在没有使能过采样平均的情况下，结果为低12bit；在使能过采样平均的情况下，结果为12~16bit
 */
#define	ADC_DR_ADC_DATA_Msk	(0xffffU << ADC_DR_ADC_DATA_Pos)

#define	ADC_CAL_CONV_CAL_Pos	1	/* ADC转换配置 (Conversion with Calibration data) */
#define	ADC_CAL_CONV_CAL_Msk	(0x1U << ADC_CAL_CONV_CAL_Pos)
#define	ADC_CAL_CONV_CAL_UNUSE_CAL	(0x0U << ADC_CAL_CONV_CAL_Pos)	/* 0：ADC转换时不使用校准寄存器的数据 */
#define	ADC_CAL_CONV_CAL_USE_CAL	(0x1U << ADC_CAL_CONV_CAL_Pos)	/* 1：ADC转换时使用校准寄存器的数据 */

#define	ADC_CAL_CALEN_Pos	0	/* Calibration使能 (Calibration Enable)软件写1启动校准周期，硬件开始校准后自动清零。软件通过EOCAL寄存器查询校准周期结束 */
#define	ADC_CAL_CALEN_Msk	(0x1U << ADC_CAL_CALEN_Pos)

#define	ADC_HLTR_AWD_HT_Pos	16	/* AWD监视高阈值 (Analog Watchdog High Threshold) */
#define	ADC_HLTR_AWD_HT_Msk	(0xfffU << ADC_HLTR_AWD_HT_Pos)

#define	ADC_HLTR_AWD_LT_Pos	0	/* AWD监视低阈值 (Analog Watchdog Low Threshold) */
#define	ADC_HLTR_AWD_LT_Msk	(0xfffU << ADC_HLTR_AWD_LT_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void ADC_Deinit(void);

/* 模拟看门狗超出上限中断标志 (Analog Watchdog Above High Threshold)当采样值高于AWD_HT时，硬件置位，软件写1清零. 相关函数 */
extern void ADC_ISR_AWD_AH_Clr(void);
extern FlagStatus ADC_ISR_AWD_AH_Chk(void);

/* 模拟看门狗低于下限中断标志 (Analog Watchdog Under Low Threshold)当采样值低于AWD_LT时，硬件置位，软件写1清零 相关函数 */
extern void ADC_ISR_AWD_UL_Clr(void);
extern FlagStatus ADC_ISR_AWD_UL_Chk(void);

/* 校准结束 (End Of Calibration)硬件置位，软件写1清零1：校准过程结束0：无校准过程 相关函数 */
extern void ADC_ISR_EOCAL_Clr(void);
extern FlagStatus ADC_ISR_EOCAL_Chk(void);

/* ADC忙标志 (Busy) 1：ADC正在校准、采样或转换过程中 0：ADC空闲 相关函数 */
extern FlagStatus ADC_ISR_BUSY_Chk(void);

/* 数据冲突标志，硬件置位，软件写1清零 (Over Run) 当ADC_DATA寄存器中的上一次转换结果还未被读取，新的转换结果又到来时，硬件置位OVR标志。0：没有数据冲突 1：出现数据冲突 相关函数 */
extern void ADC_ISR_OVR_Clr(void);
extern FlagStatus ADC_ISR_OVR_Chk(void);

/* 转换序列结束 (End Of Sequence)所有使能通道都转换完成后，置位EOS，软件写1清零。 相关函数 */
extern void ADC_ISR_EOS_Clr(void);
extern FlagStatus ADC_ISR_EOS_Chk(void);

/* 单次转换结束 (End Of Conversion)每个通道转换完成后，置位EOC，软件写1清零。 相关函数 */
extern void ADC_ISR_EOC_Clr(void);
extern FlagStatus ADC_ISR_EOC_Chk(void);

/* 模拟看门狗采样值高于上限中断使能，1有效 (Analog Watchdog Above High Threshold Interrupt Enable) 相关函数 */
extern void ADC_IER_AWD_AHIE_Setable(FunState NewState);
extern FunState ADC_IER_AWD_AHIE_Getable(void);

/* 模拟看门狗采样值低于上限中断使能，1有效 (Analog Watchdog Under Low Threshold Interrupt Enable) 相关函数 */
extern void ADC_IER_AWD_ULIE_Setable(FunState NewState);
extern FunState ADC_IER_AWD_ULIE_Getable(void);

/* 校准结束中断使能寄存器 (End Of Calibration Interrupt Enable) 0：禁止EOCAL中断 1：允许EOCAL中断 相关函数 */
extern void ADC_IER_EOCALIE_Setable(FunState NewState);
extern FunState ADC_IER_EOCALIE_Getable(void);

/* 数据冲突中断使能寄存器 (Over Run Interrupt Enable) 0：禁止数据冲突中断 1：允许数据冲突中断 相关函数 */
extern void ADC_IER_OVRIE_Setable(FunState NewState);
extern FunState ADC_IER_OVRIE_Getable(void);

/* 转换序列结束中断使能寄存器 (End Of Sequence Interrupt Enable) 0：禁止EOS中断 1：允许EOS中断 相关函数 */
extern void ADC_IER_EOSIE_Setable(FunState NewState);
extern FunState ADC_IER_EOSIE_Getable(void);

/* 单次转换结束中断使能寄存器 (End Of Conversion Interrupt Enable) 0：禁止EOC中断 1：允许EOC中断 相关函数 */
extern void ADC_IER_EOCIE_Setable(FunState NewState);
extern FunState ADC_IER_EOCIE_Getable(void);

/* ADC启动转换寄存器，软件写1启动，硬件自动清零。 相关函数 */
extern void ADC_CR_START_Setable(FunState NewState);
extern FunState ADC_CR_START_Getable(void);

/* ADC使能寄存器 (ADC Enable) 在启动转换前先要置位ADEN，等待至少5个MCLK后再启动转换。0：关闭ADC 1：使能ADC 相关函数 */
extern void ADC_CR_ADEN_Setable(FunState NewState);
extern FunState ADC_CR_ADEN_Getable(void);

/* ADC工作时钟选择 (ADC Clock Select) 相关函数 */
extern void ADC_CFGR_CKS_Set(uint32_t SetValue);
extern uint32_t ADC_CFGR_CKS_Get(void);

/* 模拟窗口看门狗监视通道选择，仅在AWDSC=1时有效 (Analog Watchdog Channel Select) 相关函数 */
extern void ADC_CFGR_AWDCH_Set(uint32_t SetValue);
extern uint32_t ADC_CFGR_AWDCH_Get(void);

/* 模拟窗口看门狗单通道或全通道选择 (Analog Watchdog Single Channel mode) 相关函数 */
extern void ADC_CFGR_AWDSC_Set(uint32_t SetValue);
extern uint32_t ADC_CFGR_AWDSC_Get(void);

/* 模拟窗口看门狗使能寄存器 (Analog Watchdog Enable) 0：关闭AWD 1：使能AWD 仅能在START=0的情况下使能AWD 相关函数 */
extern void ADC_CFGR_AWDEN_Setable(FunState NewState);
extern FunState ADC_CFGR_AWDEN_Getable(void);

/* 过采样移位控制寄存器 (Oversampling Shift) 相关函数 */
extern void ADC_CFGR_OVSS_Set(uint32_t SetValue);
extern uint32_t ADC_CFGR_OVSS_Get(void);

/* 过采样率控制 (Oversampling Ratio) 相关函数 */
extern void ADC_CFGR_OVSR_Set(uint32_t SetValue);
extern uint32_t ADC_CFGR_OVSR_Get(void);

/* 过采样使能 (Oversampling Enable) 0：禁止过采样 1：使能过采样 相关函数 */
extern void ADC_CFGR_OVSEN_Setable(FunState NewState);
extern FunState ADC_CFGR_OVSEN_Getable(void);

/* 引脚触发信号数字滤波使能 (GPIO Trigger Filter Enable) 0：禁止数字滤波 1：使能数字滤波  相关函数 */
extern void ADC_CFGR_IOTRFEN_Setable(FunState NewState);
extern FunState ADC_CFGR_IOTRFEN_Getable(void);

/* 触发信号使能和极性选择 (Trigger Config) 相关函数 */
extern void ADC_CFGR_TRGCFG_Set(uint32_t SetValue);
extern uint32_t ADC_CFGR_TRGCFG_Get(void);

/* 单次转换半自动模式 (Semi-automatic)，仅在单次转换（CONT=0）时有效 相关函数 */
extern void ADC_CFGR_SEMI_Set(uint32_t SetValue);
extern uint32_t ADC_CFGR_SEMI_Get(void);

/* 等待模式控制 (wait mode) 0：无等待，如果上次转换数据没有及时读取，则可能出现Overrun 1：等待模式，在上次转换数据被读取前，不会启动下一次转换 相关函数 */
extern void ADC_CFGR_WAIT_Setable(FunState NewState);
extern FunState ADC_CFGR_WAIT_Getable(void);

/* 连续转换模式使能 (Continuous mode) 0：单次转换 1：连续转换  相关函数 */
extern void ADC_CFGR_CONT_Setable(FunState NewState);
extern FunState ADC_CFGR_CONT_Getable(void);

/* Overrun模式控制 (Overrun mode) 相关函数 */
extern void ADC_CFGR_OVRM_Set(uint32_t SetValue);
extern uint32_t ADC_CFGR_OVRM_Get(void);

/* 硬件触发源选择 (External trigger select) 相关函数 */
extern void ADC_CFGR_EXTS_Set(uint32_t SetValue);
extern uint32_t ADC_CFGR_EXTS_Get(void);

/* ADC低功耗模式使能，软件可以配置 (Low Power Mode) 相关函数 */
extern void ADC_CFGR_LPM_Set(uint32_t SetValue);
extern uint32_t ADC_CFGR_LPM_Get(void);

/* 通道扫描顺序控制 (Scan Direction)（共16个通道，实际只会采样被使能的通道） 相关函数 */
extern void ADC_CFGR_SCANDIR_Set(uint32_t SetValue);
extern uint32_t ADC_CFGR_SCANDIR_Get(void);

/* DMA模式控制 (DMA Config) 相关函数 */
extern void ADC_CFGR_DMACFG_Set(uint32_t SetValue);
extern uint32_t ADC_CFGR_DMACFG_Get(void);

/* DMA使能 (DMA Enable) 0：禁止DMA 1：使能DMA  相关函数 */
extern void ADC_CFGR_DMAEN_Setable(FunState NewState);
extern FunState ADC_CFGR_DMAEN_Getable(void);

/* ADC采样通道切换等待时间 (Channel Clock Gating) 在当前通道采样周期完成后，等待CHCG时间（CHCG*ADC工作时钟周期），再切换到下一个采样通道 相关函数 */
extern void ADC_SMTR_CHCG_Set(uint32_t SetValue);
extern uint32_t ADC_SMTR_CHCG_Get(void);

/* 慢速通道采样时间控制（*ADC工作时钟周期），用于配置ADC_IN8/9/10/11四个外部通道、以及OPA通道的采样时间 (Sampling Time Select 2)  相关函数 */
extern void ADC_SMTR_SMTS2_Set(uint32_t SetValue);
extern uint32_t ADC_SMTR_SMTS2_Get(void);

/* 快速通道采样时间控制（*ADC工作时钟周期），用于配置ADC_IN8/9/10/11四个外部通道、以及OPA通道的采样时间 (Sampling Time Select 2)  相关函数 */
extern void ADC_SMTR_SMTS1_Set(uint32_t SetValue);
extern uint32_t ADC_SMTR_SMTS1_Get(void);

/* 单端和差分通道配置，4bit配置4组通道对是否为差分输入，0表示单端输入，1表示差分输入。(Analog Input Select)如果配置为差分输入，则每个差分对所对应的通道都要使能。
比如，将ADC_IN0和ADC_IN1设置为差分输入对，需要进行差分采样时，ECH0和ECH1都要置1。 相关函数 */
extern void ADC_CHER_AINS_Set(uint32_t SetValue);
extern uint32_t ADC_CHER_AINS_Get(void);

/* OPA2输出测量，写1使能 (OPA2 channel)  相关函数 */
extern void ADC_CHER_OPA2CH_Setable(FunState NewState);
extern FunState ADC_CHER_OPA2CH_Getable(void);

/* OPA1输出测量，写1使能 (OPA1 channel)  相关函数 */
extern void ADC_CHER_OPA1CH_Setable(FunState NewState);
extern FunState ADC_CHER_OPA1CH_Getable(void);

/* 温度传感器测量通道，写1使能 (TempSensor channel)  相关函数 */
extern void ADC_CHER_TSCH_Setable(FunState NewState);
extern FunState ADC_CHER_TSCH_Getable(void);

/* 内部基准电压测量通道，写1使能 (VREF channel)  相关函数 */
extern void ADC_CHER_REFCH_Setable(FunState NewState);
extern FunState ADC_CHER_REFCH_Getable(void);

/* ADC_IN11 测量通道，写1使能  相关函数 */
extern void ADC_CHER_ECH11_Setable(FunState NewState);
extern FunState ADC_CHER_ECH11_Getable(void);

/* ADC_IN10 测量通道，写1使能  相关函数 */
extern void ADC_CHER_ECH10_Setable(FunState NewState);
extern FunState ADC_CHER_ECH10_Getable(void);

/* ADC_IN9 测量通道，写1使能 相关函数 */
extern void ADC_CHER_ECH9_Setable(FunState NewState);
extern FunState ADC_CHER_ECH9_Getable(void);

/* ADC_IN8 测量通道，写1使能 相关函数 */
extern void ADC_CHER_ECH8_Setable(FunState NewState);
extern FunState ADC_CHER_ECH8_Getable(void);

/* ADC_IN7 测量通道，写1使能 相关函数 */
extern void ADC_CHER_ECH7_Setable(FunState NewState);
extern FunState ADC_CHER_ECH7_Getable(void);

/* ADC_IN6 测量通道，写1使能 相关函数 */
extern void ADC_CHER_ECH6_Setable(FunState NewState);
extern FunState ADC_CHER_ECH6_Getable(void);

/* ADC_IN5 测量通道，写1使能 相关函数 */
extern void ADC_CHER_ECH5_Setable(FunState NewState);
extern FunState ADC_CHER_ECH5_Getable(void);

/* ADC_IN4 测量通道，写1使能 相关函数 */
extern void ADC_CHER_ECH4_Setable(FunState NewState);
extern FunState ADC_CHER_ECH4_Getable(void);

/* ADC_IN3 测量通道，写1使能 相关函数 */
extern void ADC_CHER_ECH3_Setable(FunState NewState);
extern FunState ADC_CHER_ECH3_Getable(void);

/* ADC_IN2 测量通道，写1使能 相关函数 */
extern void ADC_CHER_ECH2_Setable(FunState NewState);
extern FunState ADC_CHER_ECH2_Getable(void);

/* ADC_IN1 测量通道，写1使能 相关函数 */
extern void ADC_CHER_ECH1_Setable(FunState NewState);
extern FunState ADC_CHER_ECH1_Getable(void);

/* ADC_IN0 测量通道，写1使能 相关函数 */
extern void ADC_CHER_ECH0_Setable(FunState NewState);
extern FunState ADC_CHER_ECH0_Getable(void);

/* ADC转换结果 (ADC conversion data)在没有使能过采样平均的情况下，结果为低12bit；在使能过采样平均的情况下，结果为12~16bit
 相关函数 */
extern uint32_t ADC_DR_Read(void);

/* ADC转换配置 (Conversion with Calibration data) 相关函数 */
extern void ADC_CAL_CONV_CAL_Set(uint32_t SetValue);
extern uint32_t ADC_CAL_CONV_CAL_Get(void);

/* Calibration使能 (Calibration Enable)软件写1启动校准周期，硬件开始校准后自动清零。软件通过EOCAL寄存器查询校准周期结束 相关函数 */
extern void ADC_CAL_CALEN_Setable(FunState NewState);
extern FunState ADC_CAL_CALEN_Getable(void);

/* AWD监视高阈值 (Analog Watchdog High Threshold) 相关函数 */
extern void ADC_HLTR_AWD_HT_Set(uint32_t SetValue);
extern uint32_t ADC_HLTR_AWD_HT_Get(void);

/* AWD监视低阈值 (Analog Watchdog Low Threshold) 相关函数 */
extern void ADC_HLTR_AWD_LT_Set(uint32_t SetValue);
extern uint32_t ADC_HLTR_AWD_LT_Get(void);

#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_ADC_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
