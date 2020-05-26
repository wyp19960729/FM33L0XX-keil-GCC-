/**
  ******************************************************************************
  * @file    fm33l0xx_lptim.h
  * @author  FM33L0xx Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file contains all the functions prototypes for the LPTIM firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33L0XX_LPTIM_H
#define __FM33L0XX_LPTIM_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33L0XX.h" 
   
//-----------------------------------------------------------------------------------------------------------------------------
#define	LPTIM_CFGR_ETR_AFEN_Pos	24	/* ETR输入模拟滤波使能 (External Trigger input Analog Filter Enable) */
#define	LPTIM_CFGR_ETR_AFEN_Msk	(0x1U << LPTIM_CFGR_ETR_AFEN_Pos)
	/* 0：关闭模拟滤波 */
	/* 1：使能模拟滤波，滤波宽度约100ns */

#define	LPTIM_CFGR_PSCSEL_Pos	14	/* 时钟预分频输入选择 (Prescaler input Select) */
#define	LPTIM_CFGR_PSCSEL_Msk	(0x1U << LPTIM_CFGR_PSCSEL_Pos)
#define	LPTIM_CFGR_PSCSEL_CLKSEL	(0x0U << LPTIM_CFGR_PSCSEL_Pos)	/* 0：CLKSEL选择的时钟 */
#define	LPTIM_CFGR_PSCSEL_LPTINSEL	(0x1U << LPTIM_CFGR_PSCSEL_Pos)	/* 1：LPTINSEL选择的信号 */

#define	LPTIM_CFGR_INSEL_Pos	13	/* ETR输入源选择 (External Trigger input source Select) */
#define	LPTIM_CFGR_INSEL_Msk	(0x1U << LPTIM_CFGR_INSEL_Pos)
#define	LPTIM_CFGR_INSEL_PIN	(0x0U << LPTIM_CFGR_INSEL_Pos)	/* 0：引脚输入 */
#define	LPTIM_CFGR_INSEL_ADC_EOC	(0x1U << LPTIM_CFGR_INSEL_Pos)	/* 1：ADC_EOC */

#define	LPTIM_CFGR_DIVSEL_Pos	10	/* 计数时钟分频选择 (Counter Clock Divider Select) */
#define	LPTIM_CFGR_DIVSEL_Msk	(0x7U << LPTIM_CFGR_DIVSEL_Pos)
#define	LPTIM_CFGR_DIVSEL_DIV1	(0x0U << LPTIM_CFGR_DIVSEL_Pos)	/* 000：1分频 */
#define	LPTIM_CFGR_DIVSEL_DIV2	(0x1U << LPTIM_CFGR_DIVSEL_Pos)	/* 001：2分频 */
#define	LPTIM_CFGR_DIVSEL_DIV4	(0x2U << LPTIM_CFGR_DIVSEL_Pos)	/* 010：4分频 */
#define	LPTIM_CFGR_DIVSEL_DIV8	(0x3U << LPTIM_CFGR_DIVSEL_Pos)	/* 011：8分频 */
#define	LPTIM_CFGR_DIVSEL_DIV16	(0x4U << LPTIM_CFGR_DIVSEL_Pos)	/* 100：16分频 */
#define	LPTIM_CFGR_DIVSEL_DIV32	(0x5U << LPTIM_CFGR_DIVSEL_Pos)	/* 101：32分频 */
#define	LPTIM_CFGR_DIVSEL_DIV64	(0x6U << LPTIM_CFGR_DIVSEL_Pos)	/* 110：64分频 */
#define	LPTIM_CFGR_DIVSEL_DIV128	(0x7U << LPTIM_CFGR_DIVSEL_Pos)	/* 111：128分频 */

#define	LPTIM_CFGR_EDGESEL_Pos	7	/* ETR输入边沿选择 (ETR Clock Edge Select) */
#define	LPTIM_CFGR_EDGESEL_Msk	(0x1U << LPTIM_CFGR_EDGESEL_Pos)
#define	LPTIM_CFGR_EDGESEL_RISING	(0x0U << LPTIM_CFGR_EDGESEL_Pos)	/* 0：LPT_ETR的上升沿计数 */
#define	LPTIM_CFGR_EDGESEL_FALLING	(0x1U << LPTIM_CFGR_EDGESEL_Pos)	/* 1：LPT_ETR的下降沿计数 */

#define	LPTIM_CFGR_TRIGCFG_Pos	5	/* 外部触发边沿选择（需使用内部时钟同步采样LPT_ETR）(ETR trigger Configuration) */
#define	LPTIM_CFGR_TRIGCFG_Msk	(0x3U << LPTIM_CFGR_TRIGCFG_Pos)
#define	LPTIM_CFGR_TRIGCFG_RISING	(0x0U << LPTIM_CFGR_TRIGCFG_Pos)	/* 00: LPT_ETR输入信号上升沿触发 */
#define	LPTIM_CFGR_TRIGCFG_FALLING	(0x1U << LPTIM_CFGR_TRIGCFG_Pos)	/* 01: LPT_ETR输入信号下降沿触发 */
#define	LPTIM_CFGR_TRIGCFG_BOTH (0x2U << LPTIM_CFGR_TRIGCFG_Pos)	/* 10：外部输入信号上升下降沿触发 */


#define	LPTIM_CFGR_ONST_Pos	2	/* 单次计数模式使能 (One State Timer) */
#define	LPTIM_CFGR_ONST_Msk	(0x1U << LPTIM_CFGR_ONST_Pos)
#define	LPTIM_CFGR_ONST_CONTINUE	(0x0U << LPTIM_CFGR_ONST_Pos)	/* 0：连续计数模式：计数器被触发后保持运行，直到被关闭为止。计数器达到目标值后回到0重新开始计数，并产生溢出中断。 */
#define	LPTIM_CFGR_ONST_SINGLE	(0x1U << LPTIM_CFGR_ONST_Pos)	/* 1：单次计数模式：计数器被触发后计数到目标值后回到0，并自动停止，产生溢出中断。 */

#define	LPTIM_CFGR_TMOD_Pos	0	/* 工作模式选择 (Timer operation Mode) */
#define	LPTIM_CFGR_TMOD_Msk	(0x3U << LPTIM_CFGR_TMOD_Pos)
#define	LPTIM_CFGR_TMOD_NORMAL	(0x0U << LPTIM_CFGR_TMOD_Pos)	/* 00：普通定时器模式 */
#define	LPTIM_CFGR_TMOD_TRIGGER	(0x1U << LPTIM_CFGR_TMOD_Pos)	/* 01：Trigger脉冲触发计数模式 */
#define	LPTIM_CFGR_TMOD_EXASYN	(0x2U << LPTIM_CFGR_TMOD_Pos)	/* 10：外部异步脉冲计数模式 */
#define	LPTIM_CFGR_TMOD_TIMEOUT	(0x3U << LPTIM_CFGR_TMOD_Pos)	/* 11：Timeout模式 */

#define	LPTIM_CNT_CNT32_Pos	0	/* 32bit计数器当前计数值 (Counter 32bits-wide) */
#define	LPTIM_CNT_CNT32_Msk	(0xffffffffU << LPTIM_CNT_CNT32_Pos)

#define	LPTIM_CCSR_CAP1SSEL_Pos	16	/* 通道1捕捉信号源选择 (Channel 1 Capture Source Select) */
#define	LPTIM_CCSR_CAP1SSEL_Msk	(0x3U << LPTIM_CCSR_CAP1SSEL_Pos)
#define	LPTIM_CCSR_CAP1SSEL_LPT32_CH1	(0x0U << LPTIM_CCSR_CAP1SSEL_Pos)	/* 00：LPT32_CH1输入 */
#define	LPTIM_CCSR_CAP1SSEL_XTLF	(0x1U << LPTIM_CCSR_CAP1SSEL_Pos)	/* 01：XTLF */
#define	LPTIM_CCSR_CAP1SSEL_RCLP	(0x2U << LPTIM_CCSR_CAP1SSEL_Pos)	/* 10：RCLP */
#define	LPTIM_CCSR_CAP1SSEL_RC4M_PSC	(0x3U << LPTIM_CCSR_CAP1SSEL_Pos)	/* 11：RC4M_PSC */

#define	LPTIM_CCSR_CAP2EDGE_Pos	13	/* 通道2当前被捕捉的边沿，在CC2IF置位时更新 (Channel2 Captured Edge) */
#define	LPTIM_CCSR_CAP2EDGE_Msk	(0x1U << LPTIM_CCSR_CAP2EDGE_Pos)

#define	LPTIM_CCSR_CAP1EDGE_Pos	12	/* 通道1当前被捕捉的边沿，在CC1IF置位时更新 (Channel 1 Captured Edge) */
#define	LPTIM_CCSR_CAP1EDGE_Msk	(0x1U << LPTIM_CCSR_CAP1EDGE_Pos)

#define	LPTIM_CCSR_CAPCFG2_Pos	10	/* 通道2捕捉边沿选择 (Channel 2 Capture edge Config) */
#define	LPTIM_CCSR_CAPCFG2_Msk	(0x3U << LPTIM_CCSR_CAPCFG2_Pos)
#define	LPTIM_CCSR_CAPCFG2_RISING	(0x0U << LPTIM_CCSR_CAPCFG2_Pos)	/* 00：上升沿捕捉 */
#define	LPTIM_CCSR_CAPCFG2_FALLING	(0x1U << LPTIM_CCSR_CAPCFG2_Pos)	/* 01：下降沿捕捉 */
#define	LPTIM_CCSR_CAPCFG2_BOTH	(0x2U << LPTIM_CCSR_CAPCFG2_Pos)	/* 10：上升下降沿捕捉 */

#define	LPTIM_CCSR_CAPCFG1_Pos	8	/* 通道1捕捉边沿选择 (Channel 1 Capture edge Config) */
#define	LPTIM_CCSR_CAPCFG1_Msk	(0x3U << LPTIM_CCSR_CAPCFG1_Pos)
#define	LPTIM_CCSR_CAPCFG1_RISING	(0x0U << LPTIM_CCSR_CAPCFG1_Pos)	/* 00：上升沿捕捉 */
#define	LPTIM_CCSR_CAPCFG1_FALLING	(0x1U << LPTIM_CCSR_CAPCFG1_Pos)	/* 01：下降沿捕捉 */
#define	LPTIM_CCSR_CAPCFG1_BOTH	(0x2U << LPTIM_CCSR_CAPCFG1_Pos)	/* 10：上升下降沿捕捉 */

#define	LPTIM_CCSR_POLAR2_Pos	5	/* 通道2比较输出波形极性选择 (Channel 2 compare output Polarity) */
#define	LPTIM_CCSR_POLAR2_Msk	(0x1U << LPTIM_CCSR_POLAR2_Pos)
#define	LPTIM_CCSR_POLAR2_POS	(0x0U << LPTIM_CCSR_POLAR2_Pos)	/* 0：正极性波形，起始为低，计数值==比较值时置高，计数值==ARR时恢复为低 */
#define	LPTIM_CCSR_POLAR2_NEG	(0x1U << LPTIM_CCSR_POLAR2_Pos)	/* 1：负极性波形，正极性波形取反 */

#define	LPTIM_CCSR_POLAR1_Pos	4	/* 通道1比较输出波形极性选择 (Channel 1 compare output Polarity) */
#define	LPTIM_CCSR_POLAR1_Msk	(0x1U << LPTIM_CCSR_POLAR1_Pos)
#define	LPTIM_CCSR_POLAR1_POS	(0x0U << LPTIM_CCSR_POLAR1_Pos)	/* 0：正极性波形，起始为低，计数值==比较值时置高，计数值==ARR时恢复为低 */
#define	LPTIM_CCSR_POLAR1_NEG	(0x1U << LPTIM_CCSR_POLAR1_Pos)	/* 1：负极性波形，正极性波形取反 */

#define	LPTIM_CCSR_CC2S_Pos	2	/* 通道2捕捉/比较功能使能 (Channel 2 Capture/Compare Select) */
#define	LPTIM_CCSR_CC2S_Msk	(0x3U << LPTIM_CCSR_CC2S_Pos)
#define	LPTIM_CCSR_CC2S_DISABLE	(0x0U << LPTIM_CCSR_CC2S_Pos)	/* 00：禁止通道2捕捉/比较功能 */
#define	LPTIM_CCSR_CC2S_CAPTURE	(0x1U << LPTIM_CCSR_CC2S_Pos)	/* 01：使能通道2捕捉功能（LPT32_CH2为输入） */
#define	LPTIM_CCSR_CC2S_COMPARE	(0x2U << LPTIM_CCSR_CC2S_Pos)	/* 10：使能通道2比较功能（LPT32_CH2为输出） */

#define	LPTIM_CCSR_CC1S_Pos	0	/* 通道1捕捉/比较功能使能 (Channel 1 Capture/Compare Select) */
#define	LPTIM_CCSR_CC1S_Msk	(0x3U << LPTIM_CCSR_CC1S_Pos)
#define	LPTIM_CCSR_CC1S_DISABLE	(0x0U << LPTIM_CCSR_CC1S_Pos)	/* 00：禁止通道1捕捉/比较功能 */
#define	LPTIM_CCSR_CC1S_CAPTURE	(0x1U << LPTIM_CCSR_CC1S_Pos)	/* 01：使能通道1捕捉功能（LPT32_CH1为输入） */
#define	LPTIM_CCSR_CC1S_COMPARE	(0x2U << LPTIM_CCSR_CC1S_Pos)	/* 10：使能通道1比较功能（LPT32_CH1为输出） */

#define	LPTIM_ARR_ARR_Pos	0	/* 自动重载目标寄存器 (Auto-Reload Register) */
#define	LPTIM_ARR_ARR_Msk	(0xffffffffU << LPTIM_ARR_ARR_Pos)

#define	LPTIM_IER_OVR2IE_Pos	9	/* 通道2捕捉溢出中断使能 (Channel 2 Over-Capture Interrupt Enable) */
#define	LPTIM_IER_OVR2IE_Msk	(0x1U << LPTIM_IER_OVR2IE_Pos)
	/* 0：禁止中断 */
	/* 1：允许中断 */

#define	LPTIM_IER_OVR1IE_Pos	8	/* 通道1捕捉溢出中断使能 (Channel 1 Over-Capture Interrupt Enable) */
#define	LPTIM_IER_OVR1IE_Msk	(0x1U << LPTIM_IER_OVR1IE_Pos)
	/* 0：禁止中断 */
	/* 1：允许中断 */

#define	LPTIM_IER_TRIGIE_Pos	3	/* 外部触发到来中断使能位 (External Trigger Interrupt Enable) */
#define	LPTIM_IER_TRIGIE_Msk	(0x1U << LPTIM_IER_TRIGIE_Pos)
	/* 0：外部触发到来中断禁止 */
	/* 1：外部触发到来中断使能 */

#define	LPTIM_IER_OVIE_Pos	2	/* 计数器溢出中断使能位 (Counter Over-Flow Interrupt Enable) */
#define	LPTIM_IER_OVIE_Msk	(0x1U << LPTIM_IER_OVIE_Pos)
	/* 0：计数器溢出中断禁止 */
	/* 1：计数器溢出中断使能 */

#define	LPTIM_IER_CC2IE_Pos	1	/* 捕捉/比较通道2中断使能位 (Capture/Compare channel 2 Interrupt Enable) */
#define	LPTIM_IER_CC2IE_Msk	(0x1U << LPTIM_IER_CC2IE_Pos)
	/* 0：捕捉/比较通道2中断禁止 */
	/* 1：捕捉/比较通道2中断使能 */

#define	LPTIM_IER_CC1IE_Pos	0	/* 捕捉/比较通道1中断使能位 (Capture/Compare channel 1 Interrupt Enable) */
#define	LPTIM_IER_CC1IE_Msk	(0x1U << LPTIM_IER_CC1IE_Pos)
	/* 0：捕捉/比较通道1中断禁止 */
	/* 1：捕捉/比较通道1中断使能 */

#define	LPTIM_ISR_CAP2OVR_Pos	9	/* 通道2捕捉溢出，硬件置位，软件写1清零 (Channel 2 Over-Capture Interrupt Flag) */
#define	LPTIM_ISR_CAP2OVR_Msk	(0x1U << LPTIM_ISR_CAP2OVR_Pos)

#define	LPTIM_ISR_CAP1OVR_Pos	8	/* 通道1捕捉溢出，硬件置位，软件写1清零 (Channel 1 Over-Capture Interrupt Flag) */
#define	LPTIM_ISR_CAP1OVR_Msk	(0x1U << LPTIM_ISR_CAP1OVR_Pos)

#define	LPTIM_ISR_TRIGIF_Pos	3	/* 外部触发到来中断标志位，写1清零 (External Trigger Interrupt Flag) */
#define	LPTIM_ISR_TRIGIF_Msk	(0x1U << LPTIM_ISR_TRIGIF_Pos)

#define	LPTIM_ISR_OVIF_Pos	2	/* 计数器溢出中断使能位，写1清零 (Counter Over-Flow Interrupt Flag) */
#define	LPTIM_ISR_OVIF_Msk	(0x1U << LPTIM_ISR_OVIF_Pos)

#define	LPTIM_ISR_CC2IF_Pos	1	/* 捕捉/比较通道2中断标志，硬件置位，软件写1清零 (Capture/Compare channel 2 Interrupt Flag) */
#define	LPTIM_ISR_CC2IF_Msk	(0x1U << LPTIM_ISR_CC2IF_Pos)

#define	LPTIM_ISR_CC1IF_Pos	0	/* 捕捉/比较通道1中断标志，硬件置位，软件写1清零 (Capture/Compare channel 1 Interrupt Flag) */
#define	LPTIM_ISR_CC1IF_Msk	(0x1U << LPTIM_ISR_CC1IF_Pos)

#define	LPTIM_CR_EN_Pos	0	/* LPTIM使能位 (LPTIM Enable) */
#define	LPTIM_CR_EN_Msk	(0x1U << LPTIM_CR_EN_Pos)
	/* 0：禁止计数器计数 */
	/* 1：使能计数器计数 */

#define	LPTIM_CCR1_CCR1_Pos	0	/* 捕捉/比较值寄存器1 (Channel1 Capture/Compare Register) */
#define	LPTIM_CCR1_CCR1_Msk	(0xffffffffU << LPTIM_CCR1_CCR1_Pos)

#define	LPTIM_CCR2_CCR2_Pos	0	/* 捕捉/比较值寄存器2 (Channel2 Capture/Compare Register) */
#define	LPTIM_CCR2_CCR2_Msk	(0xffffffffU << LPTIM_CCR2_CCR2_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void LPTIM_Deinit(void);

/* ETR输入模拟滤波使能 (External Trigger input Analog Filter Enable) 相关函数 */
extern void LPTIM_CFGR_ETR_AFEN_Setable(FunState NewState);
extern FunState LPTIM_CFGR_ETR_AFEN_Getable(void);

/* 时钟预分频输入选择 (Prescaler input Select) 相关函数 */
extern void LPTIM_CFGR_PSCSEL_Set(uint32_t SetValue);
extern uint32_t LPTIM_CFGR_PSCSEL_Get(void);

/* ETR输入源选择 (External Trigger input source Select) 相关函数 */
extern void LPTIM_CFGR_INSEL_Set(uint32_t SetValue);
extern uint32_t LPTIM_CFGR_INSEL_Get(void);

/* 计数时钟分频选择 (Counter Clock Divider Select) 相关函数 */
extern void LPTIM_CFGR_DIVSEL_Set(uint32_t SetValue);
extern uint32_t LPTIM_CFGR_DIVSEL_Get(void);

/* ETR输入边沿选择 (ETR Clock Edge Select) 相关函数 */
extern void LPTIM_CFGR_EDGESEL_Set(uint32_t SetValue);
extern uint32_t LPTIM_CFGR_EDGESEL_Get(void);

/* 外部触发边沿选择（需使用内部时钟同步采样LPT_ETR）(ETR trigger Configuration) 相关函数 */
extern void LPTIM_CFGR_TRIGCFG_Set(uint32_t SetValue);
extern uint32_t LPTIM_CFGR_TRIGCFG_Get(void);

/* 单次计数模式使能 (One State Timer) 相关函数 */
extern void LPTIM_CFGR_ONST_Set(uint32_t SetValue);
extern uint32_t LPTIM_CFGR_ONST_Get(void);

/* 工作模式选择 (Timer operation Mode) 相关函数 */
extern void LPTIM_CFGR_TMOD_Set(uint32_t SetValue);
extern uint32_t LPTIM_CFGR_TMOD_Get(void);

/* 32bit计数器当前计数值 (Counter 32bits-wide) 相关函数 */
extern void LPTIM_CNT_Write(uint32_t SetValue);
extern uint32_t LPTIM_CNT_Read(void);

/* 通道1捕捉信号源选择 (Channel 1 Capture Source Select) 相关函数 */
extern void LPTIM_CCSR_CAP1SSEL_Set(uint32_t SetValue);
extern uint32_t LPTIM_CCSR_CAP1SSEL_Get(void);

/* 通道2当前被捕捉的边沿，在CC2IF置位时更新 (Channel2 Captured Edge) 相关函数 */
extern FlagStatus LPTIM_CCSR_CAP2EDGE_Chk(void);

/* 通道1当前被捕捉的边沿，在CC1IF置位时更新 (Channel 1 Captured Edge) 相关函数 */
extern FlagStatus LPTIM_CCSR_CAP1EDGE_Chk(void);

/* 通道2捕捉边沿选择 (Channel 2 Capture edge Config) 相关函数 */
extern void LPTIM_CCSR_CAPCFG2_Set(uint32_t SetValue);
extern uint32_t LPTIM_CCSR_CAPCFG2_Get(void);

/* 通道1捕捉边沿选择 (Channel 1 Capture edge Config) 相关函数 */
extern void LPTIM_CCSR_CAPCFG1_Set(uint32_t SetValue);
extern uint32_t LPTIM_CCSR_CAPCFG1_Get(void);

/* 通道2比较输出波形极性选择 (Channel 2 compare output Polarity) 相关函数 */
extern void LPTIM_CCSR_POLAR2_Set(uint32_t SetValue);
extern uint32_t LPTIM_CCSR_POLAR2_Get(void);

/* 通道1比较输出波形极性选择 (Channel 1 compare output Polarity) 相关函数 */
extern void LPTIM_CCSR_POLAR1_Set(uint32_t SetValue);
extern uint32_t LPTIM_CCSR_POLAR1_Get(void);

/* 通道2捕捉/比较功能使能 (Channel 2 Capture/Compare Select) 相关函数 */
extern void LPTIM_CCSR_CC2S_Set(uint32_t SetValue);
extern uint32_t LPTIM_CCSR_CC2S_Get(void);

/* 通道1捕捉/比较功能使能 (Channel 1 Capture/Compare Select) 相关函数 */
extern void LPTIM_CCSR_CC1S_Set(uint32_t SetValue);
extern uint32_t LPTIM_CCSR_CC1S_Get(void);

/* 自动重载目标寄存器 (Auto-Reload Register) 相关函数 */
extern void LPTIM_ARR_Write(uint32_t SetValue);
extern uint32_t LPTIM_ARR_Read(void);

/* 通道2捕捉溢出中断使能 (Channel 2 Over-Capture Interrupt Enable) 相关函数 */
extern void LPTIM_IER_OVR2IE_Setable(FunState NewState);
extern FunState LPTIM_IER_OVR2IE_Getable(void);

/* 通道1捕捉溢出中断使能 (Channel 1 Over-Capture Interrupt Enable) 相关函数 */
extern void LPTIM_IER_OVR1IE_Setable(FunState NewState);
extern FunState LPTIM_IER_OVR1IE_Getable(void);

/* 外部触发到来中断使能位 (External Trigger Interrupt Enable) 相关函数 */
extern void LPTIM_IER_TRIGIE_Setable(FunState NewState);
extern FunState LPTIM_IER_TRIGIE_Getable(void);

/* 计数器溢出中断使能位 (Counter Over-Flow Interrupt Enable) 相关函数 */
extern void LPTIM_IER_OVIE_Setable(FunState NewState);
extern FunState LPTIM_IER_OVIE_Getable(void);

/* 捕捉/比较通道2中断使能位 (Capture/Compare channel 2 Interrupt Enable) 相关函数 */
extern void LPTIM_IER_CC2IE_Setable(FunState NewState);
extern FunState LPTIM_IER_CC2IE_Getable(void);

/* 捕捉/比较通道1中断使能位 (Capture/Compare channel 1 Interrupt Enable) 相关函数 */
extern void LPTIM_IER_CC1IE_Setable(FunState NewState);
extern FunState LPTIM_IER_CC1IE_Getable(void);

/* 通道2捕捉溢出，硬件置位，软件写1清零 (Channel 2 Over-Capture Interrupt Flag) 相关函数 */
extern void LPTIM_ISR_CAP2OVR_Clr(void);
extern FlagStatus LPTIM_ISR_CAP2OVR_Chk(void);

/* 通道1捕捉溢出，硬件置位，软件写1清零 (Channel 1 Over-Capture Interrupt Flag) 相关函数 */
extern void LPTIM_ISR_CAP1OVR_Clr(void);
extern FlagStatus LPTIM_ISR_CAP1OVR_Chk(void);

/* 外部触发到来中断标志位，写1清零 (External Trigger Interrupt Flag) 相关函数 */
extern void LPTIM_ISR_TRIGIF_Clr(void);
extern FlagStatus LPTIM_ISR_TRIGIF_Chk(void);

/* 计数器溢出中断使能位，写1清零 (Counter Over-Flow Interrupt Flag) 相关函数 */
extern void LPTIM_ISR_OVIF_Clr(void);
extern FlagStatus LPTIM_ISR_OVIF_Chk(void);

/* 捕捉/比较通道2中断标志，硬件置位，软件写1清零 (Capture/Compare channel 2 Interrupt Flag) 相关函数 */
extern void LPTIM_ISR_CC2IF_Clr(void);
extern FlagStatus LPTIM_ISR_CC2IF_Chk(void);

/* 捕捉/比较通道1中断标志，硬件置位，软件写1清零 (Capture/Compare channel 1 Interrupt Flag) 相关函数 */
extern void LPTIM_ISR_CC1IF_Clr(void);
extern FlagStatus LPTIM_ISR_CC1IF_Chk(void);

/* LPTIM使能位 (LPTIM Enable) 相关函数 */
extern void LPTIM_CR_EN_Setable(FunState NewState);
extern FunState LPTIM_CR_EN_Getable(void);

/* 捕捉/比较值寄存器1 (Channel1 Capture/Compare Register) 相关函数 */
extern void LPTIM_CCR1_Write(uint32_t SetValue);
extern uint32_t LPTIM_CCR1_Read(void);

/* 捕捉/比较值寄存器2 (Channel2 Capture/Compare Register) 相关函数 */
extern void LPTIM_CCR2_Write(uint32_t SetValue);
extern uint32_t LPTIM_CCR2_Read(void);
                
#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_LPTIM_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
