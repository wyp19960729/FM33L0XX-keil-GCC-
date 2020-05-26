/**
  ******************************************************************************
  * @file    fm33l0xx_gptim.h
  * @author  FM33L0xx Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file contains all the functions prototypes for the GPTIM firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33L0XX_GPTIM_H
#define __FM33L0XX_GPTIM_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33L0XX.h" 
#include "fm33l0xx_atim.h" 
//-----------------------------------------------------------------------------------------------------------------------------
#define TIM_Channel_1                      ((uint16_t)0x0000)
#define TIM_Channel_2                      ((uint16_t)0x0001)
#define TIM_Channel_3                      ((uint16_t)0x0002)
#define TIM_Channel_4                      ((uint16_t)0x0003)
   
#define	GPTIMx_CR1_CKD_Pos	8	/* Dead time和数字滤波时钟频率分频寄存器（相对CK_INT的分频比）(Counter clocK Divider) */
#define	GPTIMx_CR1_CKD_Msk	(0x3U << GPTIMx_CR1_CKD_Pos)
#define	GPTIMx_CR1_CKD_1TINT	(0x0U << GPTIMx_CR1_CKD_Pos)	/* 00：tDTS=tCK_INT */
#define	GPTIMx_CR1_CKD_2TINT	(0x1U << GPTIMx_CR1_CKD_Pos)	/* 01：tDTS=2*tCK_INT */
#define	GPTIMx_CR1_CKD_4TINT	(0x2U << GPTIMx_CR1_CKD_Pos)	/* 10：tDTS=4*tCK_INT */

#define	GPTIMx_CR1_ARPE_Pos	7	/* Auto-reload预装载使能 (Auto-Reload Preload Enable) */
#define	GPTIMx_CR1_ARPE_Msk	(0x1U << GPTIMx_CR1_ARPE_Pos)
	/* 0：ARR寄存器不使能preload */
	/* 1：ARR寄存器使能preload */

#define	GPTIMx_CR1_CMS_Pos	5	/* 计数器对齐模式选择 (Counter Mode Selection) */
#define	GPTIMx_CR1_CMS_Msk	(0x3U << GPTIMx_CR1_CMS_Pos)
#define	GPTIMx_CR1_CMS_EDGE	(0x0U << GPTIMx_CR1_CMS_Pos)	/* 00：边沿对齐模式 */
#define	GPTIMx_CR1_CMS_CENTRAL1	(0x1U << GPTIMx_CR1_CMS_Pos)	/* 01：中央对齐模式1，输出比较中断标志仅在计数器向下计数的过程中置位 */
#define	GPTIMx_CR1_CMS_CENTRAL2	(0x2U << GPTIMx_CR1_CMS_Pos)	/* 10：中央对齐模式2，输出比较中断标志仅在计数器向上计数的过程中置位 */
#define	GPTIMx_CR1_CMS_CENTRAL3	(0x3U << GPTIMx_CR1_CMS_Pos)	/* 11：中央对齐模式3，输出比较中断标志在计数器向上向下计数的过程中都会置位 */

#define	GPTIMx_CR1_DIR_Pos	4	/* 计数方向寄存器 (counter Direction) */
#define	GPTIMx_CR1_DIR_Msk	(0x1U << GPTIMx_CR1_DIR_Pos)
#define	GPTIMx_CR1_DIR_UP	(0x0U << GPTIMx_CR1_DIR_Pos)	/* 0：向上计数 */
#define	GPTIMx_CR1_DIR_DOWN	(0x1U << GPTIMx_CR1_DIR_Pos)	/* 1：向下计数 */

#define	GPTIMx_CR1_OPM_Pos	3	/* 单脉冲输出模式 (One Pulse Mode) */
#define	GPTIMx_CR1_OPM_Msk	(0x1U << GPTIMx_CR1_OPM_Pos)
#define	GPTIMx_CR1_OPM_CONTINUE	(0x0U << GPTIMx_CR1_OPM_Pos)	/* 0：Update Event发生时计数器不停止 */
#define	GPTIMx_CR1_OPM_STOP	(0x1U << GPTIMx_CR1_OPM_Pos)	/* 1：Update Event发生时计数器停止（自动清零CEN） */

#define	GPTIMx_CR1_URS_Pos	2	/* 更新请求选择 (Update Request Selection) */
#define	GPTIMx_CR1_URS_Msk	(0x1U << GPTIMx_CR1_URS_Pos)

#define	GPTIMx_CR1_UDIS_Pos	1	/* 禁止update (Update Disable) */
#define	GPTIMx_CR1_UDIS_Msk	(0x1U << GPTIMx_CR1_UDIS_Pos)
	/* 0：使能update事件；以下事件发生时产生update事件
-计数器上溢出或下溢出
-软件置位UG寄存器
-从机控制器产生update */
	/* 1：禁止update事件，不更新shadow寄存器。当UG置位或从机控制器收到硬件reset时重新初始化计数器和预分频器。 */

#define	GPTIMx_CR1_CEN_Pos	0	/* 计数器使能 (Counter Enable) */
#define	GPTIMx_CR1_CEN_Msk	(0x1U << GPTIMx_CR1_CEN_Pos)
	/* 0：计数器关闭 */
	/* 1：计数器使能 */

#define	GPTIMx_CR2_TI1S_Pos	7	/* 通道1输入源选择 (Timer Input 1 Selection) */
#define	GPTIMx_CR2_TI1S_Msk	(0x1U << GPTIMx_CR2_TI1S_Pos)
#define	GPTIMx_CR2_TI1S_CH1	(0x0U << GPTIMx_CR2_TI1S_Pos)	/* 0：GPTIMx_CH1输入通道1 */
#define	GPTIMx_CR2_TI1S_XOR	(0x1U << GPTIMx_CR2_TI1S_Pos)	/* 1：GPTIMx_CH1, CH2, CH3异或后输入通道1 */

#define	GPTIMx_CR2_MMS_Pos	4	/* 主机模式选择，用于配置主机模式下向从机发送的同步触发信号（TRGO）源 (Master Mode Selection) */
#define	GPTIMx_CR2_MMS_Msk	(0x7U << GPTIMx_CR2_MMS_Pos)
#define	GPTIMx_CR2_MMS_EGR_	(0x0U << GPTIMx_CR2_MMS_Pos)	/* 000：GPTIM_EGR的UG寄存器被用作TRGO */
#define	GPTIMx_CR2_MMS_CNT_EN	(0x1U << GPTIMx_CR2_MMS_Pos)	/* 001：计数器使能信号CNT_EN被用作TRGO，可用于同时启动多个定时器 */
#define	GPTIMx_CR2_MMS_UE_TRGO	(0x2U << GPTIMx_CR2_MMS_Pos)	/* 010：UE（update event）信号被用作TRGO */
#define	GPTIMx_CR2_MMS_CC1CMP	(0x3U << GPTIMx_CR2_MMS_Pos)	/* 011：比较脉冲，如果CC1IF标志将要置位，TRGO输出一个正脉冲 */
#define	GPTIMx_CR2_MMS_OC1REF	(0x4U << GPTIMx_CR2_MMS_Pos)	/* 100：OC1REF用作TRGO */
#define	GPTIMx_CR2_MMS_OC2REF	(0x5U << GPTIMx_CR2_MMS_Pos)	/* 101：OC2REF用作TRGO */
#define	GPTIMx_CR2_MMS_OC3REF	(0x6U << GPTIMx_CR2_MMS_Pos)	/* 110：OC3REF用作TRGO */
#define	GPTIMx_CR2_MMS_OC4REF	(0x7U << GPTIMx_CR2_MMS_Pos)	/* 111：OC4REF用作TRGO */

#define	GPTIMx_CR2_CCDS_Pos	3	/* 捕捉/比较 DMA选择 (Capture/Compare DMA Selection) */
#define	GPTIMx_CR2_CCDS_Msk	(0x1U << GPTIMx_CR2_CCDS_Pos)
#define	GPTIMx_CR2_CCDS_CC	(0x0U << GPTIMx_CR2_CCDS_Pos)	/* 0：捕捉/比较事件发生时发送DMA请求 */
#define	GPTIMx_CR2_CCDS_UE	(0x1U << GPTIMx_CR2_CCDS_Pos)	/* 1：Update Event发生时发送DMA请求 */

#define	GPTIMx_SMCR_ETP_Pos	15	/* 外部触发信号极性配置 (External Trigger Polarity) */
#define	GPTIMx_SMCR_ETP_Msk	(0x1U << GPTIMx_SMCR_ETP_Pos)
#define	GPTIMx_SMCR_ETP_POS	(0x0U << GPTIMx_SMCR_ETP_Pos)	/* 0：高电平或上升沿有效 */
#define	GPTIMx_SMCR_ETP_NEG	(0x1U << GPTIMx_SMCR_ETP_Pos)	/* 1：低电平或下降沿有效 */

#define	GPTIMx_SMCR_ECE_Pos	14	/* 外部时钟使能 (External Clock Enable) */
#define	GPTIMx_SMCR_ECE_Msk	(0x1U << GPTIMx_SMCR_ECE_Pos)
	/* 0：关闭外部时钟模式2 */
	/* 1：使能外部时钟模式2，计数器时钟为ETRF有效沿 */

#define	GPTIMx_SMCR_ETPS_Pos	12	/* 外部触发信号预分频寄存器 (External Trigger Prescaler)
外部触发信号ETRP的频率最多只能是GPTIM工作时钟的1/4，当输入信号频率较高时，可以使用预分频 */
#define	GPTIMx_SMCR_ETPS_Msk	(0x3U << GPTIMx_SMCR_ETPS_Pos)
#define	GPTIMx_SMCR_ETPS_DIV1	(0x0U << GPTIMx_SMCR_ETPS_Pos)	/* 00：不分频 */
#define	GPTIMx_SMCR_ETPS_DIV2	(0x1U << GPTIMx_SMCR_ETPS_Pos)	/* 01：2分频 */
#define	GPTIMx_SMCR_ETPS_DIV4	(0x2U << GPTIMx_SMCR_ETPS_Pos)	/* 10：4分频 */
#define	GPTIMx_SMCR_ETPS_DIV8	(0x3U << GPTIMx_SMCR_ETPS_Pos)	/* 11：8分频 */

#define	GPTIMx_SMCR_ETF_Pos	8	/* 外部触发信号滤波时钟和长度选择 (External Trigger Filter) */
#define	GPTIMx_SMCR_ETF_Msk	(0xfU << GPTIMx_SMCR_ETF_Pos)
#define	GPTIMx_SMCR_ETF_FILT0	(0x0U << GPTIMx_SMCR_ETF_Pos)	/* 0000：无滤波 */
#define	GPTIMx_SMCR_ETF_FILT1	(0x1U << GPTIMx_SMCR_ETF_Pos)	/* 0001：fSAMPLING=fCK_INT, N=2 */
#define	GPTIMx_SMCR_ETF_FILT2	(0x2U << GPTIMx_SMCR_ETF_Pos)	/* 0010：fSAMPLING=fCK_INT, N=4 */
#define	GPTIMx_SMCR_ETF_FILT3	(0x3U << GPTIMx_SMCR_ETF_Pos)	/* 0011：fSAMPLING=fCK_INT, N=8 */
#define	GPTIMx_SMCR_ETF_FILT4	(0x4U << GPTIMx_SMCR_ETF_Pos)	/* 0100：fSAMPLING=fDTS/2, N=6 */
#define	GPTIMx_SMCR_ETF_FILT5	(0x5U << GPTIMx_SMCR_ETF_Pos)	/* 0101：fSAMPLING=fDTS/2, N=8 */
#define	GPTIMx_SMCR_ETF_FILT6	(0x6U << GPTIMx_SMCR_ETF_Pos)	/* 0110：fSAMPLING=fDTS/4, N=6 */
#define	GPTIMx_SMCR_ETF_FILT7	(0x7U << GPTIMx_SMCR_ETF_Pos)	/* 0111：fSAMPLING=fDTS/4, N=8 */
#define	GPTIMx_SMCR_ETF_FILT8	(0x8U << GPTIMx_SMCR_ETF_Pos)	/* 1000：fSAMPLING=fDTS/8, N=6 */
#define	GPTIMx_SMCR_ETF_FILT9	(0x9U << GPTIMx_SMCR_ETF_Pos)	/* 1001：fSAMPLING=fDTS/8, N=8 */
#define	GPTIMx_SMCR_ETF_FILT10	(0xaU << GPTIMx_SMCR_ETF_Pos)	/* 1010：fSAMPLING=fDTS/16, N=5 */
#define	GPTIMx_SMCR_ETF_FILT11	(0xbU << GPTIMx_SMCR_ETF_Pos)	/* 1011：fSAMPLING=fDTS/16, N=6 */
#define	GPTIMx_SMCR_ETF_FILT12	(0xcU << GPTIMx_SMCR_ETF_Pos)	/* 1100：fSAMPLING=fDTS/16, N=8 */
#define	GPTIMx_SMCR_ETF_FILT13	(0xdU << GPTIMx_SMCR_ETF_Pos)	/* 1101：fSAMPLING=fDTS/32, N=5 */
#define	GPTIMx_SMCR_ETF_FILT14	(0xeU << GPTIMx_SMCR_ETF_Pos)	/* 1110：fSAMPLING=fDTS/32, N=6 */
#define	GPTIMx_SMCR_ETF_FILT15	(0xfU << GPTIMx_SMCR_ETF_Pos)	/* 1111：fSAMPLING=fDTS/32, N=8 */

#define	GPTIMx_SMCR_MSM_Pos	7	/* 主/从模式 (Master Slave Mode) */
#define	GPTIMx_SMCR_MSM_Msk	(0x1U << GPTIMx_SMCR_MSM_Pos)
#define	GPTIMx_SMCR_MSM_NONE	(0x0U << GPTIMx_SMCR_MSM_Pos)	/* 0：无动作 */
#define	GPTIMx_SMCR_MSM_DELAY	(0x1U << GPTIMx_SMCR_MSM_Pos)	/* 1：TRGI触发的动作被延迟，以使当前定时器与其从定时器实现完美同步（通过TRGO）。此设置适用于单个外部事件对多个定时器进行同步的情况 */

#define	GPTIMx_SMCR_TS_Pos	4	/* 触发选择，用于选择同步计数器的触发源 (Trigger Source) */
#define	GPTIMx_SMCR_TS_Msk	(0x7U << GPTIMx_SMCR_TS_Pos)
#define	GPTIMx_SMCR_TS_ITR0	(0x0U << GPTIMx_SMCR_TS_Pos)	/* 000：内部触发信号（ITR0） */
#define	GPTIMx_SMCR_TS_ITR1	(0x1U << GPTIMx_SMCR_TS_Pos)	/* 001：内部触发信号（ITR1） */
#define	GPTIMx_SMCR_TS_ITR2	(0x2U << GPTIMx_SMCR_TS_Pos)	/* 010：内部触发信号（ITR2） */
#define	GPTIMx_SMCR_TS_ITR3	(0x3U << GPTIMx_SMCR_TS_Pos)	/* 011：内部触发信号（ITR3） */
#define	GPTIMx_SMCR_TS_TI1F_ED	(0x4U << GPTIMx_SMCR_TS_Pos)	/* 100：TI1边沿检测（TI1F_ED） */
#define	GPTIMx_SMCR_TS_TI1FP1	(0x5U << GPTIMx_SMCR_TS_Pos)	/* 101：滤波后TI1（TI1FP1） */
#define	GPTIMx_SMCR_TS_TI2FP2	(0x6U << GPTIMx_SMCR_TS_Pos)	/* 110：滤波后TI2（TI2FP2） */
#define	GPTIMx_SMCR_TS_ETRF	(0x7U << GPTIMx_SMCR_TS_Pos)	/* 111：外部触发输入（ETRF） */

#define	GPTIMx_SMCR_SMS_Pos	0	/* 从机模式选择 (Slave Mode Selection) */
#define	GPTIMx_SMCR_SMS_Msk	(0x7U << GPTIMx_SMCR_SMS_Pos)
#define	GPTIMx_SMCR_SMS_SLAVE_DIS	(0x0U << GPTIMx_SMCR_SMS_Pos)	/* 000：从机模式禁止；CEN使能后预分频电路时钟源来自内部时钟 */
#define	GPTIMx_SMCR_SMS_ENCODER1	(0x1U << GPTIMx_SMCR_SMS_Pos)	/* 001：Encoder模式1；计数器使用TI2FP1边沿，根据TI1FP2电平高低来计数 */
#define	GPTIMx_SMCR_SMS_ENCODER2	(0x2U << GPTIMx_SMCR_SMS_Pos)	/* 010：Encoder模式2；计数器使用TI1FP2边沿，根据TI2FP1电平高低来计数 */
#define	GPTIMx_SMCR_SMS_ENCODER3	(0x3U << GPTIMx_SMCR_SMS_Pos)	/* 011：Encoder模式3；计数器同时使用TI1FP1和TI2FP2边沿，根据其他输入信号电平来计数 */
#define	GPTIMx_SMCR_SMS_RESET	(0x4U << GPTIMx_SMCR_SMS_Pos)	/* 100：复位模式；TRGI上升沿初始化计数器，并触发寄存器update */
#define	GPTIMx_SMCR_SMS_GATE	(0x5U << GPTIMx_SMCR_SMS_Pos)	/* 101：闸门模式；TRGI为高电平时，计数时钟使能，TRGI为低电平时，计数时钟停止 */
#define	GPTIMx_SMCR_SMS_TIGGER	(0x6U << GPTIMx_SMCR_SMS_Pos)	/* 110：触发模式；TRGI上升沿触发计数器开始计数（不会复位计数器） */
#define	GPTIMx_SMCR_SMS_EXCLK	(0x7U << GPTIMx_SMCR_SMS_Pos)	/* 111：外部时钟模式1；TRGI上升沿直接驱动计数器 */

#define	GPTIMx_DIER_CC4BURSTEN_Pos	19	/* 捕捉比较通道4的DMA模式配置 (CC4 Burst Enable) */
#define	GPTIMx_DIER_CC4BURSTEN_Msk	(0x1U << GPTIMx_DIER_CC4BURSTEN_Pos)
#define	GPTIMx_DIER_CC4BURSTEN_SINGLE	(0x0U << GPTIMx_DIER_CC4BURSTEN_Pos)	/* 0：Single模式，仅访问CCR */
#define	GPTIMx_DIER_CC4BURSTEN_BURST	(0x1U << GPTIMx_DIER_CC4BURSTEN_Pos)	/* 1：Burst模式，通过DCR配置访问的地址和长度 */

#define	GPTIMx_DIER_CC3BURSTEN_Pos	18	/* 捕捉比较通道3的DMA模式配置 (CC3 Burst Enable) */
#define	GPTIMx_DIER_CC3BURSTEN_Msk	(0x1U << GPTIMx_DIER_CC3BURSTEN_Pos)
#define	GPTIMx_DIER_CC3BURSTEN_SINGLE	(0x0U << GPTIMx_DIER_CC3BURSTEN_Pos)	/* 0：Single模式，仅访问CCR */
#define	GPTIMx_DIER_CC3BURSTEN_BURST	(0x1U << GPTIMx_DIER_CC3BURSTEN_Pos)	/* 1：Burst模式，通过DCR配置访问的地址和长度 */

#define	GPTIMx_DIER_CC2BURSTEN_Pos	17	/* 捕捉比较通道2的DMA模式配置 (CC2 Burst Enable) */
#define	GPTIMx_DIER_CC2BURSTEN_Msk	(0x1U << GPTIMx_DIER_CC2BURSTEN_Pos)
#define	GPTIMx_DIER_CC2BURSTEN_SINGLE	(0x0U << GPTIMx_DIER_CC2BURSTEN_Pos)	/* 0：Single模式，仅访问CCR */
#define	GPTIMx_DIER_CC2BURSTEN_BURST	(0x1U << GPTIMx_DIER_CC2BURSTEN_Pos)	/* 1：Burst模式，通过DCR配置访问的地址和长度 */

#define	GPTIMx_DIER_CC1BURSTEN_Pos	16	/* 捕捉比较通道1的DMA模式配置 (CC1 Burst Enable) */
#define	GPTIMx_DIER_CC1BURSTEN_Msk	(0x1U << GPTIMx_DIER_CC1BURSTEN_Pos)
#define	GPTIMx_DIER_CC1BURSTEN_SINGLE	(0x0U << GPTIMx_DIER_CC1BURSTEN_Pos)	/* 0：Single模式，仅访问CCR */
#define	GPTIMx_DIER_CC1BURSTEN_BURST	(0x1U << GPTIMx_DIER_CC1BURSTEN_Pos)	/* 1：Burst模式，通过DCR配置访问的地址和长度 */

#define	GPTIMx_DIER_TDE_Pos	14	/* 外部触发DMA请求使能 (Triggered DMA Enable) */
#define	GPTIMx_DIER_TDE_Msk	(0x1U << GPTIMx_DIER_TDE_Pos)
	/* 0：从机模式下，禁止外部触发事件产生DMA请求 */
	/* 1：从机模式下，允许外部触发事件产生DMA请求（可用于自动更新preload寄存器） */

#define	GPTIMx_DIER_CC4DE_Pos	12	/* 捕捉比较通道4的DMA请求使能 (CC4 DMA Enable) */
#define	GPTIMx_DIER_CC4DE_Msk	(0x1U << GPTIMx_DIER_CC4DE_Pos)
	/* 0：禁止CC4 DMA请求 */
	/* 1：允许CC4 DMA请求 */

#define	GPTIMx_DIER_CC3DE_Pos	11	/* 捕捉比较通道3的DMA请求使能 (CC3 DMA Enable) */
#define	GPTIMx_DIER_CC3DE_Msk	(0x1U << GPTIMx_DIER_CC3DE_Pos)
	/* 0：禁止CC3 DMA请求 */
	/* 1：允许CC3 DMA请求 */

#define	GPTIMx_DIER_CC2DE_Pos	10	/* 捕捉比较通道2的DMA请求使能 (CC2 DMA Enable) */
#define	GPTIMx_DIER_CC2DE_Msk	(0x1U << GPTIMx_DIER_CC2DE_Pos)
	/* 0：禁止CC2 DMA请求 */
	/* 1：允许CC2 DMA请求 */

#define	GPTIMx_DIER_CC1DE_Pos	9	/* 捕捉比较通道1的DMA请求使能 (CC1 DMA Enable) */
#define	GPTIMx_DIER_CC1DE_Msk	(0x1U << GPTIMx_DIER_CC1DE_Pos)
	/* 0：禁止CC1 DMA请求 */
	/* 1：允许CC1 DMA请求 */

#define	GPTIMx_DIER_UDE_Pos	8	/* Update Event DMA请求使能 (Update event DMA Enable) */
#define	GPTIMx_DIER_UDE_Msk	(0x1U << GPTIMx_DIER_UDE_Pos)
	/* 0：Update Event发生时，禁止产生DMA请求 */
	/* 1：Update Event发生时，允许产生DMA请求 */

#define	GPTIMx_DIER_TIE_Pos	6	/* 触发事件中断使能 (Trigger event Interrupt Enable) */
#define	GPTIMx_DIER_TIE_Msk	(0x1U << GPTIMx_DIER_TIE_Pos)
	/* 0：禁止触发事件中断 */
	/* 1：允许触发事件中断 */

#define	GPTIMx_DIER_CC4IE_Pos	4	/* 捕捉/比较通道4中断使能 (CC4 Interrupt Enable) */
#define	GPTIMx_DIER_CC4IE_Msk	(0x1U << GPTIMx_DIER_CC4IE_Pos)
	/* 0：禁止捕捉/比较4中断 */
	/* 1：允许捕捉/比较4中断 */

#define	GPTIMx_DIER_CC3IE_Pos	3	/* 捕捉/比较通道3中断使能 (CC3 Interrupt Enable) */
#define	GPTIMx_DIER_CC3IE_Msk	(0x1U << GPTIMx_DIER_CC3IE_Pos)
	/* 0：禁止捕捉/比较3中断 */
	/* 1：允许捕捉/比较3中断 */

#define	GPTIMx_DIER_CC2IE_Pos	2	/* 捕捉/比较通道2中断使能 (CC2 Interrupt Enable) */
#define	GPTIMx_DIER_CC2IE_Msk	(0x1U << GPTIMx_DIER_CC2IE_Pos)
	/* 0：禁止捕捉/比较2中断 */
	/* 1：允许捕捉/比较2中断 */

#define	GPTIMx_DIER_CC1IE_Pos	1	/* 捕捉/比较通道1中断使能 (CC1 Interrupt Enable) */
#define	GPTIMx_DIER_CC1IE_Msk	(0x1U << GPTIMx_DIER_CC1IE_Pos)
	/* 0：禁止捕捉/比较1中断 */
	/* 1：允许捕捉/比较1中断 */

#define	GPTIMx_DIER_UIE_Pos	0	/* Update事件中断使能 (Update event Interrupt Enable) */
#define	GPTIMx_DIER_UIE_Msk	(0x1U << GPTIMx_DIER_UIE_Pos)
	/* 0：禁止Update事件中断 */
	/* 1：允许Update事件中断 */

#define	GPTIMx_ISR_CC4OF_Pos	12	/* 捕捉/比较通道4的Overcapture中断 (Over-Capture Interrupt Flag for CC4) */
#define	GPTIMx_ISR_CC4OF_Msk	(0x1U << GPTIMx_ISR_CC4OF_Pos)

#define	GPTIMx_ISR_CC3OF_Pos	11	/* 捕捉/比较通道3的Overcapture中断 (Over-Capture Interrupt Flag for CC3) */
#define	GPTIMx_ISR_CC3OF_Msk	(0x1U << GPTIMx_ISR_CC3OF_Pos)

#define	GPTIMx_ISR_CC2OF_Pos	10	/* 捕捉/比较通道2的Overcapture中断 (Over-Capture Interrupt Flag for CC2) */
#define	GPTIMx_ISR_CC2OF_Msk	(0x1U << GPTIMx_ISR_CC2OF_Pos)

#define	GPTIMx_ISR_CC1OF_Pos	9	/* 捕捉/比较通道1的Overcapture中断 (Over-Capture Interrupt Flag for CC1) */
#define	GPTIMx_ISR_CC1OF_Msk	(0x1U << GPTIMx_ISR_CC1OF_Pos)

#define	GPTIMx_ISR_TIF_Pos	6	/* 触发事件中断标志 */
#define	GPTIMx_ISR_TIF_Msk	(0x1U << GPTIMx_ISR_TIF_Pos)

#define	GPTIMx_ISR_CC4IF_Pos	4	/* 捕捉/比较通道4中断标志 (CC4 Interrupt Flag) */
#define	GPTIMx_ISR_CC4IF_Msk	(0x1U << GPTIMx_ISR_CC4IF_Pos)

#define	GPTIMx_ISR_CC3IF_Pos	3	/* 捕捉/比较通道3中断标志 (CC3 Interrupt Flag) */
#define	GPTIMx_ISR_CC3IF_Msk	(0x1U << GPTIMx_ISR_CC3IF_Pos)

#define	GPTIMx_ISR_CC2IF_Pos	2	/* 捕捉/比较通道2中断标志 (CC2 Interrupt Flag) */
#define	GPTIMx_ISR_CC2IF_Msk	(0x1U << GPTIMx_ISR_CC2IF_Pos)

#define	GPTIMx_ISR_CC1IF_Pos	1	/* 捕捉/比较通道1中断标志 (CC1 Interrupt Flag) */
#define	GPTIMx_ISR_CC1IF_Msk	(0x1U << GPTIMx_ISR_CC1IF_Pos)

#define	GPTIMx_ISR_UIF_Pos	0	/* Update事件中断标志，硬件置位，软件写1清零。(Update event Interrupt Flag) */
#define	GPTIMx_ISR_UIF_Msk	(0x1U << GPTIMx_ISR_UIF_Pos)

#define	GPTIMx_EGR_TG_Pos	6	/* 软件触发，软件置位此寄存器产生触发事件，硬件自动清零 (Trigger Generate) */
#define	GPTIMx_EGR_TG_Msk	(0x1U << GPTIMx_EGR_TG_Pos)
#define	GPTIMx_EGR_TG_RESET	(0x0U << GPTIMx_EGR_TG_Pos)	/* 0:硬件自动清零 */
#define	GPTIMx_EGR_TG_SET	(0x1U << GPTIMx_EGR_TG_Pos)	/* 1：软件置位此寄存器产生触发事件 */

#define	GPTIMx_EGR_CC4G_Pos	4	/* 捕捉/比较通道4软件触发 (CC4 Generate) */
#define	GPTIMx_EGR_CC4G_Msk	(0x1U << GPTIMx_EGR_CC4G_Pos)
#define	GPTIMx_EGR_CC4G_RESET	(0x0U << GPTIMx_EGR_CC4G_Pos)	/* 如果CC4通道配置为输出：CC4IF置位，在使能的情况下可以产生相应的中断和DMA请求
 */
#define	GPTIMx_EGR_CC4G_SET	(0x1U << GPTIMx_EGR_CC4G_Pos)

#define	GPTIMx_EGR_CC3G_Pos	3	/* 捕捉/比较通道3软件触发 (CC3 Generate) */
#define	GPTIMx_EGR_CC3G_Msk	(0x1U << GPTIMx_EGR_CC3G_Pos)
#define	GPTIMx_EGR_CC3G_RESET	(0x0U << GPTIMx_EGR_CC3G_Pos)	/* 如果CC3通道配置为输出：CC3IF置位，在使能的情况下可以产生相应的中断和DMA请求
 */
#define	GPTIMx_EGR_CC3G_SET	(0x1U << GPTIMx_EGR_CC3G_Pos)

#define	GPTIMx_EGR_CC2G_Pos	2	/* 捕捉/比较通道2软件触发 (CC2 Generate) */
#define	GPTIMx_EGR_CC2G_Msk	(0x1U << GPTIMx_EGR_CC2G_Pos)
#define	GPTIMx_EGR_CC2G_RESET	(0x0U << GPTIMx_EGR_CC2G_Pos)	/* 如果CC2通道配置为输出：CC2IF置位，在使能的情况下可以产生相应的中断和DMA请求
 */
#define	GPTIMx_EGR_CC2G_SET	(0x1U << GPTIMx_EGR_CC2G_Pos)

#define	GPTIMx_EGR_CC1G_Pos	1	/* 捕捉/比较通道1软件触发 (CC1 Generate) */
#define	GPTIMx_EGR_CC1G_Msk	(0x1U << GPTIMx_EGR_CC1G_Pos)
#define	GPTIMx_EGR_CC1G_RESET	(0x0U << GPTIMx_EGR_CC1G_Pos)	/* 如果CC1通道配置为输出：CC1IF置位，在使能的情况下可以产生相应的中断和DMA请求
 */
#define	GPTIMx_EGR_CC1G_SET	(0x1U << GPTIMx_EGR_CC1G_Pos)

#define	GPTIMx_EGR_UG_Pos	0	/* 软件Update事件，软件置位此寄存器产生Update事件，硬件自动清零 (User Generate) */
#define	GPTIMx_EGR_UG_Msk	(0x1U << GPTIMx_EGR_UG_Pos)
#define	GPTIMx_EGR_UG_RESET	(0x0U << GPTIMx_EGR_UG_Pos)	/* 软件置位此寄存器产生Update事件，硬件自动清零 (User Generate)
软件置位UG时会重新初始化计数器并更新shadow寄存器，预分频计数器被清零。 */
#define	GPTIMx_EGR_UG_SET	(0x1U << GPTIMx_EGR_UG_Pos)

#define	GPTIMx_CCMR1_OC2CE_Pos	15	/* 输出比较2清零使能 (OC2 Clear Enable) */
#define	GPTIMx_CCMR1_OC2CE_Msk	(0x1U << GPTIMx_CCMR1_OC2CE_Pos)
	/* 0：OC2REF不受ETRF影响 */
	/* 1：检测到ETRF高电平时，自动清零OC2REF */

#define	GPTIMx_CCMR1_OC2M_Pos	12	/* 输出比较2模式配置，此寄存器定义OC2REF信号的行为 (OC2 Mode) */
#define	GPTIMx_CCMR1_OC2M_Msk	(0x7U << GPTIMx_CCMR1_OC2M_Pos)
#define	GPTIMx_CCMR1_OC2M_NONE	(0x0U << GPTIMx_CCMR1_OC2M_Pos)	/* 000：输出比较寄存器CCR2和计数器CNT的比较结果不会影响输出 */
#define	GPTIMx_CCMR1_OC2M_HIGH	(0x1U << GPTIMx_CCMR1_OC2M_Pos)	/* 001：CCR2=CNT时，将OC2REF置高 */
#define	GPTIMx_CCMR1_OC2M_LOW	(0x2U << GPTIMx_CCMR1_OC2M_Pos)	/* 010：CCR2=CNT时，将OC2REF置低 */
#define	GPTIMx_CCMR1_OC2M_TOG	(0x3U << GPTIMx_CCMR1_OC2M_Pos)	/* 011：CCR2=CNT时，翻转OC2REF */
#define	GPTIMx_CCMR1_OC2M_INACTIVE	(0x4U << GPTIMx_CCMR1_OC2M_Pos)	/* 100：OC2REF固定为低（inactive） */
#define	GPTIMx_CCMR1_OC2M_ACTIVE	(0x5U << GPTIMx_CCMR1_OC2M_Pos)	/* 101：OC2REF固定为高（active） */
#define	GPTIMx_CCMR1_OC2M_PWM1	(0x6U << GPTIMx_CCMR1_OC2M_Pos)	/* 110：PWM模式1 –在向上计数时，OC2REF在CNT<CCR2时置高，否则置低；在向下计数时，OC2REF在CNT>CCR2时置低，否则置高 */
#define	GPTIMx_CCMR1_OC2M_PWM2	(0x7U << GPTIMx_CCMR1_OC2M_Pos)	/* 111：PWM模式2 –在向上计数时，OC2REF在CNT<CCR2时置低，否则置高；在向下计数时，OC2REF在CNT>CCR2 时置高，否则置低 */

#define	GPTIMx_CCMR1_OC2PE_Pos	11	/* 输出比较2预装载使能 (OC2 Preload Enable) */
#define	GPTIMx_CCMR1_OC2PE_Msk	(0x1U << GPTIMx_CCMR1_OC2PE_Pos)
	/* 0：CCR2 preload寄存器无效，CCR2可以直接写入 */
	/* 1：CCR2 preload寄存器有效，针对CCR2的读写操作都是访问preload寄存器，当update event发生时才将preload寄存器的内容转移到shadow寄存器中 */

#define	GPTIMx_CCMR1_OC2FE_Pos	10	/* 输出比较2快速使能 (OC2 Fast Enable) */
#define	GPTIMx_CCMR1_OC2FE_Msk	(0x1U << GPTIMx_CCMR1_OC2FE_Pos)
	/* 0：关闭快速使能，trigger输入不会影响比较输出 */
	/* 1：打开快速使能，trigger输入会立即将OC2REF改变为比较值匹配时的输出，而不管当前实际比较情况
此功能仅在当前通道配置为PWM1或PWM2模式时有效 */

#define	GPTIMx_CCMR1_CC2S_Pos	8	/* 捕捉/比较2通道选择 (CC2 channel Selection) */
#define	GPTIMx_CCMR1_CC2S_Msk	(0x3U << GPTIMx_CCMR1_CC2S_Pos)
#define	GPTIMx_CCMR1_CC2S_OUT	(0x0U << GPTIMx_CCMR1_CC2S_Pos)	/* 00：CC2通道配置为输出 */
#define	GPTIMx_CCMR1_CC2S_TI2	(0x1U << GPTIMx_CCMR1_CC2S_Pos)	/* 01：CC2通道配置为输入，IC2映射到TI2 */
#define	GPTIMx_CCMR1_CC2S_TI1	(0x2U << GPTIMx_CCMR1_CC2S_Pos)	/* 10：CC2通道配置为输入，IC2映射到TI1 */
#define	GPTIMx_CCMR1_CC2S_TRC	(0x3U << GPTIMx_CCMR1_CC2S_Pos)	/* 11：CC2通道配置为输入，IC2映射到TRC */

#define	GPTIMx_CCMR1_OC1CE_Pos	7	/* 输出比较1清零使能 (OC2 Clear Enable) */
#define	GPTIMx_CCMR1_OC1CE_Msk	(0x1U << GPTIMx_CCMR1_OC1CE_Pos)
	/* 0：OC1REF不受ETRF影响 */
	/* 1：检测到ETRF高电平时，自动清零OC1REF */

#define	GPTIMx_CCMR1_OC1M_Pos	4	/* 输出比较1模式配置，此寄存器定义OC1REF信号的行为 (OC1 Mode) */
#define	GPTIMx_CCMR1_OC1M_Msk	(0x7U << GPTIMx_CCMR1_OC1M_Pos)
#define	GPTIMx_CCMR1_OC1M_NONE	(0x0U << GPTIMx_CCMR1_OC1M_Pos)	/* 000：输出比较寄存器CCR1和计数器CNT的比较结果不会影响输出 */
#define	GPTIMx_CCMR1_OC1M_HIGH	(0x1U << GPTIMx_CCMR1_OC1M_Pos)	/* 001：CCR1=CNT时，将OC1REF置高 */
#define	GPTIMx_CCMR1_OC1M_LOW	(0x2U << GPTIMx_CCMR1_OC1M_Pos)	/* 010：CCR1=CNT时，将OC1REF置低 */
#define	GPTIMx_CCMR1_OC1M_TOG	(0x3U << GPTIMx_CCMR1_OC1M_Pos)	/* 011：CCR1=CNT时，翻转OC1REF */
#define	GPTIMx_CCMR1_OC1M_INACTIVE	(0x4U << GPTIMx_CCMR1_OC1M_Pos)	/* 100：OC1REF固定为低（inactive） */
#define	GPTIMx_CCMR1_OC1M_ACTIVE	(0x5U << GPTIMx_CCMR1_OC1M_Pos)	/* 101：OC1REF固定为高（active） */
#define	GPTIMx_CCMR1_OC1M_PWM1	(0x6U << GPTIMx_CCMR1_OC1M_Pos)	/* 110：PWM模式1 –在向上计数时，OC1REF在CNT<CCR1时置高，否则置低；在向下计数时，OC1REF在CNT>CCR1时置低，否则置高 */
#define	GPTIMx_CCMR1_OC1M_PWM2	(0x7U << GPTIMx_CCMR1_OC1M_Pos)	/* 111：PWM模式2 –在向上计数时，OC1REF在CNT<CCR1时置低，否则置高；在向下计数时，OC1REF在CNT>CCR1 时置高，否则置低 */

#define	GPTIMx_CCMR1_OC1PE_Pos	3	/* 输出比较1预装载使能 (OC1 Preload Enable) */
#define	GPTIMx_CCMR1_OC1PE_Msk	(0x1U << GPTIMx_CCMR1_OC1PE_Pos)
	/* 0：CCR1 preload寄存器无效，CCR1可以直接写入 */
	/* 1：CCR1 preload寄存器有效，针对CCR1的读写操作都是访问preload寄存器，当update event发生时才将preload寄存器的内容转移到shadow寄存器中 */

#define	GPTIMx_CCMR1_OC1FE_Pos	2	/* 输出比较1快速使能 (OC1 Fast Enable) */
#define	GPTIMx_CCMR1_OC1FE_Msk	(0x1U << GPTIMx_CCMR1_OC1FE_Pos)
	/* 0：关闭快速使能，trigger输入不会影响比较输出 */
	/* 1：打开快速使能，trigger输入会立即将OC1REF改变为比较值匹配时的输出，而不管当前实际比较情况
此功能仅在当前通道配置为PWM1或PWM2模式时有效 */

#define	GPTIMx_CCMR1_CC1S_Pos	0	/* 捕捉/比较1通道选择 (CC1 channel Selection) */
#define	GPTIMx_CCMR1_CC1S_Msk	(0x3U << GPTIMx_CCMR1_CC1S_Pos)
#define	GPTIMx_CCMR1_CC1S_OUT	(0x0U << GPTIMx_CCMR1_CC1S_Pos)	/* 00：CC1通道配置为输出 */
#define	GPTIMx_CCMR1_CC1S_TI1	(0x1U << GPTIMx_CCMR1_CC1S_Pos)	/* 01：CC1通道配置为输入，IC1映射到TI1 */
#define	GPTIMx_CCMR1_CC1S_TI2	(0x2U << GPTIMx_CCMR1_CC1S_Pos)	/* 10：CC1通道配置为输入，IC1映射到TI2 */
#define	GPTIMx_CCMR1_CC1S_TRC	(0x3U << GPTIMx_CCMR1_CC1S_Pos)	/* 11：CC1通道配置为输入，IC1映射到TRC */

#define	GPTIMx_CCMR1_IC2F_Pos	12	/* 输入捕捉2滤波 (IC2 Filter) */
#define	GPTIMx_CCMR1_IC2F_Msk	(0xfU << GPTIMx_CCMR1_IC2F_Pos)
#define	GPTIMx_CCMR1_IC2F_FILT0	(0x0U << GPTIMx_CCMR1_IC2F_Pos)	/* 0000：无滤波，使用fDTS采样 */
#define	GPTIMx_CCMR1_IC2F_FILT1	(0x1U << GPTIMx_CCMR1_IC2F_Pos)	/* 0001：fSAMPLING=fCK_INT, N=2 */
#define	GPTIMx_CCMR1_IC2F_FILT2	(0x2U << GPTIMx_CCMR1_IC2F_Pos)	/* 0010：fSAMPLING=fCK_INT, N=4 */
#define	GPTIMx_CCMR1_IC2F_FILT3	(0x3U << GPTIMx_CCMR1_IC2F_Pos)	/* 0011：fSAMPLING=fCK_INT, N=8 */
#define	GPTIMx_CCMR1_IC2F_FILT4	(0x4U << GPTIMx_CCMR1_IC2F_Pos)	/* 0100：fSAMPLING=fDTS/2, N=6 */
#define	GPTIMx_CCMR1_IC2F_FILT5	(0x5U << GPTIMx_CCMR1_IC2F_Pos)	/* 0101：fSAMPLING=fDTS/2, N=8 */
#define	GPTIMx_CCMR1_IC2F_FILT6	(0x6U << GPTIMx_CCMR1_IC2F_Pos)	/* 0110：fSAMPLING=fDTS/4, N=6 */
#define	GPTIMx_CCMR1_IC2F_FILT7	(0x7U << GPTIMx_CCMR1_IC2F_Pos)	/* 0111：fSAMPLING=fDTS/4, N=8 */
#define	GPTIMx_CCMR1_IC2F_FILT8	(0x8U << GPTIMx_CCMR1_IC2F_Pos)	/* 1000：fSAMPLING=fDTS/8, N=6 */
#define	GPTIMx_CCMR1_IC2F_FILT9	(0x9U << GPTIMx_CCMR1_IC2F_Pos)	/* 1001：fSAMPLING=fDTS/8, N=8 */
#define	GPTIMx_CCMR1_IC2F_FILT10	(0xaU << GPTIMx_CCMR1_IC2F_Pos)	/* 1010：fSAMPLING=fDTS/16, N=5 */
#define	GPTIMx_CCMR1_IC2F_FILT11	(0xbU << GPTIMx_CCMR1_IC2F_Pos)	/* 1011：fSAMPLING=fDTS/16, N=6 */
#define	GPTIMx_CCMR1_IC2F_FILT12	(0xcU << GPTIMx_CCMR1_IC2F_Pos)	/* 1100：fSAMPLING=fDTS/16, N=8 */
#define	GPTIMx_CCMR1_IC2F_FILT13	(0xdU << GPTIMx_CCMR1_IC2F_Pos)	/* 1101：fSAMPLING=fDTS/32, N=5 */
#define	GPTIMx_CCMR1_IC2F_FILT14	(0xeU << GPTIMx_CCMR1_IC2F_Pos)	/* 1110：fSAMPLING=fDTS/32, N=6 */
#define	GPTIMx_CCMR1_IC2F_FILT15	(0xfU << GPTIMx_CCMR1_IC2F_Pos)	/* 1110：fSAMPLING=fDTS/32, N=6 */

#define	GPTIMx_CCMR1_IC2PSC_Pos	10	/* 输入捕捉2预分频 (IC2 Prescaler) */
#define	GPTIMx_CCMR1_IC2PSC_Msk	(0x3U << GPTIMx_CCMR1_IC2PSC_Pos)
#define	GPTIMx_CCMR1_IC2PSC_DIV1	(0x0U << GPTIMx_CCMR1_IC2PSC_Pos)	/* 00：无分频 */
#define	GPTIMx_CCMR1_IC2PSC_DIV2	(0x1U << GPTIMx_CCMR1_IC2PSC_Pos)	/* 01：每2个事件输入产生一次捕捉 */
#define	GPTIMx_CCMR1_IC2PSC_DIV4	(0x2U << GPTIMx_CCMR1_IC2PSC_Pos)	/* 10：每4个事件输入产生一次捕捉 */
#define	GPTIMx_CCMR1_IC2PSC_DIV8	(0x3U << GPTIMx_CCMR1_IC2PSC_Pos)	/* 11：每8个事件输入产生一次捕捉 */

#define	GPTIMx_CCMR1_CC2S_Pos	8	/* 捕捉/比较2通道选择 (Capture/Compare2 channel Selection) */
#define	GPTIMx_CCMR1_CC2S_Msk	(0x3U << GPTIMx_CCMR1_CC2S_Pos)
#define	GPTIMx_CCMR1_CC2S_OUT	(0x0U << GPTIMx_CCMR1_CC2S_Pos)	/* 00：CC2通道配置为输出 */
#define	GPTIMx_CCMR1_CC2S_TI2	(0x1U << GPTIMx_CCMR1_CC2S_Pos)	/* 01：CC2通道配置为输入，IC3映射到TI2 */
#define	GPTIMx_CCMR1_CC2S_TI1	(0x2U << GPTIMx_CCMR1_CC2S_Pos)	/* 10：CC2通道配置为输入，IC3映射到TI1 */
#define	GPTIMx_CCMR1_CC2S_TRC	(0x3U << GPTIMx_CCMR1_CC2S_Pos)	/* 11：CC2通道配置为输入，IC3映射到TRC */

#define	GPTIMx_CCMR1_IC1F_Pos	4	/* 输入捕捉1滤波 (IC1 Filter) */
#define	GPTIMx_CCMR1_IC1F_Msk	(0xfU << GPTIMx_CCMR1_IC1F_Pos)
#define	GPTIMx_CCMR1_IC1F_FILT0	(0x0U << GPTIMx_CCMR1_IC1F_Pos)	/* 0000：无滤波，使用fDTS采样 */
#define	GPTIMx_CCMR1_IC1F_FILT1	(0x1U << GPTIMx_CCMR1_IC1F_Pos)	/* 0001：fSAMPLING=fCK_INT, N=2 */
#define	GPTIMx_CCMR1_IC1F_FILT2	(0x2U << GPTIMx_CCMR1_IC1F_Pos)	/* 0010：fSAMPLING=fCK_INT, N=4 */
#define	GPTIMx_CCMR1_IC1F_FILT3	(0x3U << GPTIMx_CCMR1_IC1F_Pos)	/* 0011：fSAMPLING=fCK_INT, N=8 */
#define	GPTIMx_CCMR1_IC1F_FILT4	(0x4U << GPTIMx_CCMR1_IC1F_Pos)	/* 0100：fSAMPLING=fDTS/2, N=6 */
#define	GPTIMx_CCMR1_IC1F_FILT5	(0x5U << GPTIMx_CCMR1_IC1F_Pos)	/* 0101：fSAMPLING=fDTS/2, N=8 */
#define	GPTIMx_CCMR1_IC1F_FILT6	(0x6U << GPTIMx_CCMR1_IC1F_Pos)	/* 0110：fSAMPLING=fDTS/4, N=6 */
#define	GPTIMx_CCMR1_IC1F_FILT7	(0x7U << GPTIMx_CCMR1_IC1F_Pos)	/* 0111：fSAMPLING=fDTS/4, N=8 */
#define	GPTIMx_CCMR1_IC1F_FILT8	(0x8U << GPTIMx_CCMR1_IC1F_Pos)	/* 1000：fSAMPLING=fDTS/8, N=6 */
#define	GPTIMx_CCMR1_IC1F_FILT9	(0x9U << GPTIMx_CCMR1_IC1F_Pos)	/* 1001：fSAMPLING=fDTS/8, N=8 */
#define	GPTIMx_CCMR1_IC1F_FILT10	(0xaU << GPTIMx_CCMR1_IC1F_Pos)	/* 1010：fSAMPLING=fDTS/16, N=5 */
#define	GPTIMx_CCMR1_IC1F_FILT11	(0xbU << GPTIMx_CCMR1_IC1F_Pos)	/* 1011：fSAMPLING=fDTS/16, N=6 */
#define	GPTIMx_CCMR1_IC1F_FILT12	(0xcU << GPTIMx_CCMR1_IC1F_Pos)	/* 1100：fSAMPLING=fDTS/16, N=8 */
#define	GPTIMx_CCMR1_IC1F_FILT13	(0xdU << GPTIMx_CCMR1_IC1F_Pos)	/* 1101：fSAMPLING=fDTS/32, N=5 */
#define	GPTIMx_CCMR1_IC1F_FILT14	(0xeU << GPTIMx_CCMR1_IC1F_Pos)	/* 1110：fSAMPLING=fDTS/32, N=6 */
#define	GPTIMx_CCMR1_IC1F_FILT15	(0xfU << GPTIMx_CCMR1_IC1F_Pos)	/* 1110：fSAMPLING=fDTS/32, N=8 */

#define	GPTIMx_CCMR1_IC1PSC_Pos	2	/* 输入捕捉1预分频 (IC1 Prescaler) */
#define	GPTIMx_CCMR1_IC1PSC_Msk	(0x3U << GPTIMx_CCMR1_IC1PSC_Pos)
#define	GPTIMx_CCMR1_IC1PSC_DIV1	(0x0U << GPTIMx_CCMR1_IC1PSC_Pos)	/* 00：无分频 */
#define	GPTIMx_CCMR1_IC1PSC_DIV2	(0x1U << GPTIMx_CCMR1_IC1PSC_Pos)	/* 01：每2个事件输入产生一次捕捉 */
#define	GPTIMx_CCMR1_IC1PSC_DIV4	(0x2U << GPTIMx_CCMR1_IC1PSC_Pos)	/* 10：每4个事件输入产生一次捕捉 */
#define	GPTIMx_CCMR1_IC1PSC_DIV8	(0x3U << GPTIMx_CCMR1_IC1PSC_Pos)	/* 11：每8个事件输入产生一次捕捉 */

#define	GPTIMx_CCMR1_CC1S_Pos	0	/* 捕捉/比较1通道选择 (Capture/Compare1 channel Selection) */
#define	GPTIMx_CCMR1_CC1S_Msk	(0x3U << GPTIMx_CCMR1_CC1S_Pos)
#define	GPTIMx_CCMR1_CC1S_OUT	(0x0U << GPTIMx_CCMR1_CC1S_Pos)	/* 00：CC1通道配置为输出 */
#define	GPTIMx_CCMR1_CC1S_TI1	(0x1U << GPTIMx_CCMR1_CC1S_Pos)	/* 01：CC1通道配置为输入，IC1映射到TI1 */
#define	GPTIMx_CCMR1_CC1S_TI2	(0x2U << GPTIMx_CCMR1_CC1S_Pos)	/* 10：CC1通道配置为输入，IC1映射到TI2 */
#define	GPTIMx_CCMR1_CC1S_TRC	(0x3U << GPTIMx_CCMR1_CC1S_Pos)	/* 11：CC1通道配置为输入，IC1映射到TRC */

#define	GPTIMx_CCMR2_OC4CE_Pos	15	/* 输出比较4清零使能 (OC4 Clear Enable) */
#define	GPTIMx_CCMR2_OC4CE_Msk	(0x1U << GPTIMx_CCMR2_OC4CE_Pos)
	/* 0：OC4REF不受ETRF影响 */
	/* 1：检测到ETRF高电平时，自动清零OC4REF */

#define	GPTIMx_CCMR2_OC4M_Pos	12	/* 输出比较4模式配置，此寄存器定义OC4REF信号的行为 (OC4 Mode) */
#define	GPTIMx_CCMR2_OC4M_Msk	(0x7U << GPTIMx_CCMR2_OC4M_Pos)
#define	GPTIMx_CCMR2_OC4M_NONE	(0x0U << GPTIMx_CCMR2_OC4M_Pos)	/* 000：输出比较寄存器CCR4和计数器CNT的比较结果不会影响输出 */
#define	GPTIMx_CCMR2_OC4M_HIGH	(0x1U << GPTIMx_CCMR2_OC4M_Pos)	/* 001：CCR4=CNT时，将OC4REF置高 */
#define	GPTIMx_CCMR2_OC4M_LOW	(0x2U << GPTIMx_CCMR2_OC4M_Pos)	/* 010：CCR4=CNT时，将OC4REF置低 */
#define	GPTIMx_CCMR2_OC4M_TOG	(0x3U << GPTIMx_CCMR2_OC4M_Pos)	/* 011：CCR4=CNT时，翻转OC4REF */
#define	GPTIMx_CCMR2_OC4M_INACTIVE	(0x4U << GPTIMx_CCMR2_OC4M_Pos)	/* 100：OC4REF固定为低（inactive） */
#define	GPTIMx_CCMR2_OC4M_CTIVE	(0x5U << GPTIMx_CCMR2_OC4M_Pos)	/* 101：OC4REF固定为高（active） */
#define	GPTIMx_CCMR2_OC4M_PWM1	(0x6U << GPTIMx_CCMR2_OC4M_Pos)	/* 110：PWM模式1 –在向上计数时，OC4REF在CNT<CCR4时置高，否则置低；在向下计数时，OC4REF在CNT>CCR4时置低，否则置高 */
#define	GPTIMx_CCMR2_OC4M_PWM2	(0x7U << GPTIMx_CCMR2_OC4M_Pos)	/* 111：PWM模式2 –在向上计数时，OC4REF在CNT<CCR4时置低，否则置高；在向下计数时，OC4REF在CNT>CCR4时置高，否则置低 */

#define	GPTIMx_CCMR2_OC4PE_Pos	11	/* 输出比较4预装载使能 (OC4 Preload Enable) */
#define	GPTIMx_CCMR2_OC4PE_Msk	(0x1U << GPTIMx_CCMR2_OC4PE_Pos)
	/* 0：CCR4 preload寄存器无效，CCR4可以直接写入 */
	/* 1：CCR4 preload寄存器有效，针对CCR4的读写操作都是访问preload寄存器，当update event发生时才将preload寄存器的内容转移到shadow寄存器中 */

#define	GPTIMx_CCMR2_OC4FE_Pos	10	/* 输出比较4快速使能 (OC4 Fast Enable) */
#define	GPTIMx_CCMR2_OC4FE_Msk	(0x1U << GPTIMx_CCMR2_OC4FE_Pos)
	/* 0：关闭快速使能，trigger输入不会影响比较输出 */
	/* 1：打开快速使能，trigger输入会立即将OC4REF改变为比较值匹配时的输出，而不管当前实际比较情况 */

#define	GPTIMx_CCMR2_CC4S_Pos	8	/* 捕捉/比较4通道选择 (CC4 channel Selection) */
#define	GPTIMx_CCMR2_CC4S_Msk	(0x3U << GPTIMx_CCMR2_CC4S_Pos)
#define	GPTIMx_CCMR2_CC4S_OUT	(0x0U << GPTIMx_CCMR2_CC4S_Pos)	/* 00：CC4通道配置为输出 */
#define	GPTIMx_CCMR2_CC4S_TI4	(0x1U << GPTIMx_CCMR2_CC4S_Pos)	/* 01：CC4通道配置为输入，IC4映射到TI4 */
#define	GPTIMx_CCMR2_CC4S_TI3	(0x2U << GPTIMx_CCMR2_CC4S_Pos)	/* 10：CC4通道配置为输入，IC4映射到TI3 */
#define	GPTIMx_CCMR2_CC4S_TRC	(0x3U << GPTIMx_CCMR2_CC4S_Pos)	/* 11：CC4通道配置为输入，IC4映射到TRC */

#define	GPTIMx_CCMR2_OC3CE_Pos	7	/* 输出比较3清零使能 (OC3 Clear Enable) */
#define	GPTIMx_CCMR2_OC3CE_Msk	(0x1U << GPTIMx_CCMR2_OC3CE_Pos)
	/* 0：OC3REF不受ETRF影响 */
	/* 1：检测到ETRF高电平时，自动清零OC3REF */

#define	GPTIMx_CCMR2_OC3M_Pos	4	/* 输出比较3模式配置，此寄存器定义OC3REF信号的行为 (OC3 Mode) */
#define	GPTIMx_CCMR2_OC3M_Msk	(0x7U << GPTIMx_CCMR2_OC3M_Pos)
#define	GPTIMx_CCMR2_OC3M_NONE	(0x0U << GPTIMx_CCMR2_OC3M_Pos)	/* 000：输出比较寄存器CCR3和计数器CNT的比较结果不会影响输出 */
#define	GPTIMx_CCMR2_OC3M_HIGH	(0x1U << GPTIMx_CCMR2_OC3M_Pos)	/* 001：CCR3=CNT时，将OC3REF置高 */
#define	GPTIMx_CCMR2_OC3M_LOW	(0x2U << GPTIMx_CCMR2_OC3M_Pos)	/* 010：CCR3=CNT时，将OC3REF置低 */
#define	GPTIMx_CCMR2_OC3M_TOG	(0x3U << GPTIMx_CCMR2_OC3M_Pos)	/* 011：CCR3=CNT时，翻转OC1REF */
#define	GPTIMx_CCMR2_OC3M_INACTIVE	(0x4U << GPTIMx_CCMR2_OC3M_Pos)	/* 100：OC3REF固定为低（inactive） */
#define	GPTIMx_CCMR2_OC3M_ACTIVE	(0x5U << GPTIMx_CCMR2_OC3M_Pos)	/* 101：OC3REF固定为高（active） */
#define	GPTIMx_CCMR2_OC3M_PWM1	(0x6U << GPTIMx_CCMR2_OC3M_Pos)	/* 110：PWM模式1 –在向上计数时，OC3REF在CNT<CCR3时置高，否则置低；在向下计数时，OC3REF在CNT>CCR3时置低，否则置高 */
#define	GPTIMx_CCMR2_OC3M_PWM2	(0x7U << GPTIMx_CCMR2_OC3M_Pos)	/* 111：PWM模式2 –在向上计数时，OC3REF在CNT<CCR3时置低，否则置高；在向下计数时，OC3REF在CNT>CCR3时置高，否则置低 */

#define	GPTIMx_CCMR2_OC3PE_Pos	3	/* 输出比较3预装载使能 (OC3 Preload Enable) */
#define	GPTIMx_CCMR2_OC3PE_Msk	(0x1U << GPTIMx_CCMR2_OC3PE_Pos)
	/* 0：CCR3 preload寄存器无效，CCR3可以直接写入 */
	/* 1：CCR3 preload寄存器有效，针对CCR3的读写操作都是访问preload寄存器，当update event发生时才将preload寄存器的内容转移到shadow寄存器中 */

#define	GPTIMx_CCMR2_OC3FE_Pos	2	/* 输出比较3快速使能 (OC3 Fast Enable) */
#define	GPTIMx_CCMR2_OC3FE_Msk	(0x1U << GPTIMx_CCMR2_OC3FE_Pos)
	/* 0：关闭快速使能，trigger输入不会影响比较输出 */
	/* 1：打开快速使能，trigger输入会立即将OC3REF改变为比较值匹配时的输出，而不管当前实际比较情况 */

#define	GPTIMx_CCMR2_CC3S_Pos	0	/* 捕捉/比较3通道选择 (CC3 channel Selection) */
#define	GPTIMx_CCMR2_CC3S_Msk	(0x3U << GPTIMx_CCMR2_CC3S_Pos)
#define	GPTIMx_CCMR2_CC3S_OUT	(0x0U << GPTIMx_CCMR2_CC3S_Pos)	/* 00：CC3通道配置为输出 */
#define	GPTIMx_CCMR2_CC3S_TI3	(0x1U << GPTIMx_CCMR2_CC3S_Pos)	/* 01：CC3通道配置为输入，IC1映射到TI3 */
#define	GPTIMx_CCMR2_CC3S_TI4	(0x2U << GPTIMx_CCMR2_CC3S_Pos)	/* 10：CC3通道配置为输入，IC1映射到TI4 */
#define	GPTIMx_CCMR2_CC3S_TRC	(0x3U << GPTIMx_CCMR2_CC3S_Pos)	/* 11：CC3通道配置为输入，IC1映射到TRC */

#define	GPTIMx_CCMR2_IC4F_Pos	12	/* 输入捕捉4滤波 (IC4 Filter) */
#define	GPTIMx_CCMR2_IC4F_Msk	(0xfU << GPTIMx_CCMR2_IC4F_Pos)


#define	GPTIMx_CCMR2_IC4PSC_Pos	10	/* 输入捕捉4预分频 (IC4 Prescaler) */
#define	GPTIMx_CCMR2_IC4PSC_Msk	(0x3U << GPTIMx_CCMR2_IC4PSC_Pos)
#define	GPTIMx_CCMR2_IC4PSC_DIV1	(0x0U << GPTIMx_CCMR2_IC4PSC_Pos)	/* 00：无分频 */
#define	GPTIMx_CCMR2_IC4PSC_DIV2	(0x1U << GPTIMx_CCMR2_IC4PSC_Pos)	/* 01：每2个事件输入产生一次捕捉 */
#define	GPTIMx_CCMR2_IC4PSC_DIV4	(0x2U << GPTIMx_CCMR2_IC4PSC_Pos)	/* 10：每4个事件输入产生一次捕捉 */
#define	GPTIMx_CCMR2_IC4PSC_DIV8	(0x3U << GPTIMx_CCMR2_IC4PSC_Pos)	/* 11：每8个事件输入产生一次捕捉 */

#define	GPTIMx_CCMR2_CC4S_Pos	8	/* 捕捉/比较4通道选择 (CC4 channel Selection) */
#define	GPTIMx_CCMR2_CC4S_Msk	(0x3U << GPTIMx_CCMR2_CC4S_Pos)
#define	GPTIMx_CCMR2_CC4S_OUT	(0x0U << GPTIMx_CCMR2_CC4S_Pos)	/* 00：CC4通道配置为输出 */
#define	GPTIMx_CCMR2_CC4S_TI4	(0x1U << GPTIMx_CCMR2_CC4S_Pos)	/* 01：CC4通道配置为输入，IC4映射到TI4 */
#define	GPTIMx_CCMR2_CC4S_TI3	(0x2U << GPTIMx_CCMR2_CC4S_Pos)	/* 10：CC4通道配置为输入，IC4映射到TI3 */
#define	GPTIMx_CCMR2_CC4S_TRC	(0x3U << GPTIMx_CCMR2_CC4S_Pos)	/* 11：CC4通道配置为输入，IC4映射到TRC */

#define	GPTIMx_CCMR2_IC3F_Pos	4	/* 输入捕捉3滤波 (IC3 Filter) */
#define	GPTIMx_CCMR2_IC3F_Msk	(0xfU << GPTIMx_CCMR2_IC3F_Pos)

#define	GPTIMx_CCMR2_IC3PSC_Pos	2	/* 输入捕捉3预分频 (IC3 Prescaler) */
#define	GPTIMx_CCMR2_IC3PSC_Msk	(0x3U << GPTIMx_CCMR2_IC3PSC_Pos)
#define	GPTIMx_CCMR2_IC3PSC_DIV1	(0x0U << GPTIMx_CCMR2_IC3PSC_Pos)	/* 00：无分频 */
#define	GPTIMx_CCMR2_IC3PSC_DIV2	(0x1U << GPTIMx_CCMR2_IC3PSC_Pos)	/* 01：每2个事件输入产生一次捕捉 */
#define	GPTIMx_CCMR2_IC3PSC_DIV4	(0x2U << GPTIMx_CCMR2_IC3PSC_Pos)	/* 10：每4个事件输入产生一次捕捉 */
#define	GPTIMx_CCMR2_IC3PSC_DIV8	(0x3U << GPTIMx_CCMR2_IC3PSC_Pos)	/* 11：每8个事件输入产生一次捕捉 */

#define	GPTIMx_CCMR2_CC3S_Pos	0	/* 捕捉/比较3通道选择 (CC3 channel Selection) */
#define	GPTIMx_CCMR2_CC3S_Msk	(0x3U << GPTIMx_CCMR2_CC3S_Pos)
#define	GPTIMx_CCMR2_CC3S_OUT	(0x0U << GPTIMx_CCMR2_CC3S_Pos)	/* 00：CC3通道配置为输出 */
#define	GPTIMx_CCMR2_CC3S_TI3	(0x1U << GPTIMx_CCMR2_CC3S_Pos)	/* 01：CC3通道配置为输入，IC1映射到TI3 */
#define	GPTIMx_CCMR2_CC3S_TI4	(0x2U << GPTIMx_CCMR2_CC3S_Pos)	/* 10：CC3通道配置为输入，IC1映射到TI4 */
#define	GPTIMx_CCMR2_CC3S_TRC	(0x3U << GPTIMx_CCMR2_CC3S_Pos)	/* 11：CC3通道配置为输入，IC1映射到TRC */

#define	GPTIMx_CCER_CC4P_Pos	13	/* 捕捉/比较4输出极性 (CC4 Polarity) */
#define	GPTIMx_CCER_CC4P_Msk	(0x1U << GPTIMx_CCER_CC4P_Pos)
#define	GPTIMx_CCER_CC4P_HIGH	(0x0U << GPTIMx_CCER_CC4P_Pos)	/* CC4通道配置为输出时：0：OC4高有效*/
#define	GPTIMx_CCER_CC4P_LOW	(0x1U << GPTIMx_CCER_CC4P_Pos)	/* 1：OC4低有效 */

#define	GPTIMx_CCER_CC4E_Pos	12	/* 捕捉/比较4输出使能 (CC4 output Enable) */
#define	GPTIMx_CCER_CC4E_Msk	(0x1U << GPTIMx_CCER_CC4E_Pos)
	/* CC4通道配置为输出时0：OC4输出关闭，OCx=0，OCx_EN=0*/
	/* 1：OCx=OCxREF+极性选择，OCx_EN=1 */

#define	GPTIMx_CCER_CC3P_Pos	9	/* 捕捉/比较3输出极性 (CC3 Polarity) */
#define	GPTIMx_CCER_CC3P_Msk	(0x1U << GPTIMx_CCER_CC3P_Pos)
#define	GPTIMx_CCER_CC3P_HIGH	(0x0U << GPTIMx_CCER_CC3P_Pos)	/* CC3通道配置为输出时：0：OC3高有效*/
#define	GPTIMx_CCER_CC3P_LOW	(0x1U << GPTIMx_CCER_CC3P_Pos)	/* 1：OC3低有效 */

#define	GPTIMx_CCER_CC3E_Pos	8	/* 捕捉/比较3输出使能 (CC3 output Enable) */
#define	GPTIMx_CCER_CC3E_Msk	(0x1U << GPTIMx_CCER_CC3E_Pos)
/* CC3通道配置为输出时0：OC3输出关闭，OCx=0，OCx_EN=0*/
/* 1：OCx=OCxREF+极性选择，OCx_EN=1 */

#define	GPTIMx_CCER_CC2P_Pos	5	/* 捕捉/比较2输出极性 (CC2 Polarity) */
#define	GPTIMx_CCER_CC2P_Msk	(0x1U << GPTIMx_CCER_CC2P_Pos)
#define	GPTIMx_CCER_CC2P_HIGH	(0x0U << GPTIMx_CCER_CC2P_Pos)	/* CC2通道配置为输出时：0：OC2高有效*/
#define	GPTIMx_CCER_CC2P_LOW	(0x1U << GPTIMx_CCER_CC2P_Pos)	/* 1：OC2低有效 */

#define	GPTIMx_CCER_CC2E_Pos	4	/* 捕捉/比较2输出使能 (CC2 output Enable) */
#define	GPTIMx_CCER_CC2E_Msk	(0x1U << GPTIMx_CCER_CC2E_Pos)
/* CC2通道配置为输出时0：OC2输出关闭，OCx=0，OCx_EN=0*/
/* 1：OCx=OCxREF+极性选择，OCx_EN=1 */

#define	GPTIMx_CCER_CC1P_Pos	1	/* 捕捉/比较1输出极性 (CC1 Polarity) */
#define	GPTIMx_CCER_CC1P_Msk	(0x1U << GPTIMx_CCER_CC1P_Pos)
#define	GPTIMx_CCER_CC1P_HIGH	(0x0U << GPTIMx_CCER_CC1P_Pos)	/* CC1通道配置为输出时：0：OC1高有效*/
#define	GPTIMx_CCER_CC1P_LOW	(0x1U << GPTIMx_CCER_CC1P_Pos)	/* 1：OC1低有效 */

#define	GPTIMx_CCER_CC1E_Pos	0	/* 捕捉/比较1输出使能 (CC1 output Enable) */
#define	GPTIMx_CCER_CC1E_Msk	(0x1U << GPTIMx_CCER_CC1E_Pos)
/* CC1通道配置为输出时0：OC1输出关闭，OCx=0，OCx_EN=0*/
/* 1：OCx=OCxREF+极性选择，OCx_EN=1 */

#define	GPTIMx_CNT_CNT_Pos	0	/* 计数器值 (Counter) */
#define	GPTIMx_CNT_CNT_Msk	(0xffffU << GPTIMx_CNT_CNT_Pos)

#define	GPTIMx_PSC_PSC_Pos	0	/* 计数器时钟（CK_CNT）预分频值 (Counter Clock Prescaler) */
#define	GPTIMx_PSC_PSC_Msk	(0xffffU << GPTIMx_PSC_PSC_Pos)

#define	GPTIMx_ARR_ARR_Pos	0	/* 计数溢出时的自动重载值 (Auto-Reload Register) */
#define	GPTIMx_ARR_ARR_Msk	(0xffffU << GPTIMx_ARR_ARR_Pos)

#define	GPTIMx_CCR1_CCR1_Pos	0	/* 捕捉/比较通道1寄存器 (Capture/Compare channel 1 Register) */
#define	GPTIMx_CCR1_CCR1_Msk	(0xffffU << GPTIMx_CCR1_CCR1_Pos)

#define	GPTIMx_CCR2_CCR2_Pos	0	/* 捕捉/比较通道2寄存器 (Capture/Compare channel 2 Register) */
#define	GPTIMx_CCR2_CCR2_Msk	(0xffffU << GPTIMx_CCR2_CCR2_Pos)

#define	GPTIMx_CCR3_CCR3_Pos	0	/* 捕捉/比较通道3寄存器 (Capture/Compare channel 3 Register) */
#define	GPTIMx_CCR3_CCR3_Msk	(0xffffU << GPTIMx_CCR3_CCR3_Pos)

#define	GPTIMx_CCR4_CCR4_Pos	0	/* 捕捉/比较通道4寄存器 (Capture/Compare channel 4 Register) */
#define	GPTIMx_CCR4_CCR4_Msk	(0xffffU << GPTIMx_CCR4_CCR4_Pos)

#define	GPTIMx_DCR_DBL_Pos	8	/* DMA Burst长度 (DMA Burst Length) */
#define	GPTIMx_DCR_DBL_Msk	(0x1fU << GPTIMx_DCR_DBL_Pos)
#define	GPTIMx_DCR_DBL_LENG_1	(0x0U << GPTIMx_DCR_DBL_Pos)	/* 对GPTIM_DMAR寄存器的读写将触发burst DMA操作，burst长度为1~18 00000：长度=1 */
#define	GPTIMx_DCR_DBL_LENG_2	(0x1U << GPTIMx_DCR_DBL_Pos)	/* 00001：长度=2 */
#define	GPTIMx_DCR_DBL_LENG_3	(0x2U << GPTIMx_DCR_DBL_Pos)	/* 00010：长度=3 */
#define	GPTIMx_DCR_DBL_LENG_4	(0x3U << GPTIMx_DCR_DBL_Pos)	/* 00011：长度=4 */
#define	GPTIMx_DCR_DBL_LENG_5	(0x4U << GPTIMx_DCR_DBL_Pos)	/* 00100：长度=5 */
#define	GPTIMx_DCR_DBL_LENG_6	(0x5U << GPTIMx_DCR_DBL_Pos)	/* 00101：长度=6 */
#define	GPTIMx_DCR_DBL_LENG_7	(0x6U << GPTIMx_DCR_DBL_Pos)	/* 00110：长度=7 */
#define	GPTIMx_DCR_DBL_LENG_8	(0x7U << GPTIMx_DCR_DBL_Pos)	/* 00111：长度=8 */
#define	GPTIMx_DCR_DBL_LENG_9	(0x8U << GPTIMx_DCR_DBL_Pos)	/* 01000：长度=9 */
#define	GPTIMx_DCR_DBL_LENG_10	(0x9U << GPTIMx_DCR_DBL_Pos)	/* 01001：长度=10 */
#define	GPTIMx_DCR_DBL_LENG_11	(0xaU << GPTIMx_DCR_DBL_Pos)	/* 01010：长度=11 */
#define	GPTIMx_DCR_DBL_LENG_12	(0xbU << GPTIMx_DCR_DBL_Pos)	/* 01011：长度=12 */
#define	GPTIMx_DCR_DBL_LENG_13	(0xcU << GPTIMx_DCR_DBL_Pos)	/* 01100：长度=13 */
#define	GPTIMx_DCR_DBL_LENG_14	(0xdU << GPTIMx_DCR_DBL_Pos)	/* 01101：长度=14 */
#define	GPTIMx_DCR_DBL_LENG_15	(0xeU << GPTIMx_DCR_DBL_Pos)	/* 01110：长度=15 */
#define	GPTIMx_DCR_DBL_LENG_16	(0xfU << GPTIMx_DCR_DBL_Pos)	/* 01111：长度=16 */
#define	GPTIMx_DCR_DBL_LENG_17	(0x10U << GPTIMx_DCR_DBL_Pos)	/* 10000：长度=17 */
#define	GPTIMx_DCR_DBL_LENG_18	(0x11U << GPTIMx_DCR_DBL_Pos)	/* 10001：长度=18 */

#define	GPTIMx_DCR_DBA_Pos	0	/* DMA基地址，定义指向寄存器的偏移地址 (DMA Burst offset Address) */
#define	GPTIMx_DCR_DBA_Msk	(0x1fU << GPTIMx_DCR_DBA_Pos)
#define	GPTIMx_DCR_DBA_CR1	(0x0U << GPTIMx_DCR_DBA_Pos)	/* 00001：GPTIM_CR1 */
#define	GPTIMx_DCR_DBA_CR2	(0x1U << GPTIMx_DCR_DBA_Pos)	/* 00010：GPTIM_CR2 */
#define	GPTIMx_DCR_DBA_SMCR	(0x2U << GPTIMx_DCR_DBA_Pos)	/* 00011：GPTIM_SMCR */
#define	GPTIMx_DCR_DBA_DIER	(0x3U << GPTIMx_DCR_DBA_Pos)	/* 00100：GPTIM_DIER */
#define	GPTIMx_DCR_DBA_SR	(0x4U << GPTIMx_DCR_DBA_Pos)	/* 00101：GPTIM_SR */
#define	GPTIMx_DCR_DBA_EGR	(0x5U << GPTIMx_DCR_DBA_Pos)	/* 00110：GPTIM_EGR */
#define	GPTIMx_DCR_DBA_CCMR1	(0x6U << GPTIMx_DCR_DBA_Pos)	/* 00111：GPTIM_CCMR1 */
#define	GPTIMx_DCR_DBA_CCMR2	(0x7U << GPTIMx_DCR_DBA_Pos)	/* 01000：GPTIM_CCMR2 */
#define	GPTIMx_DCR_DBA_CCER	(0x8U << GPTIMx_DCR_DBA_Pos)	/* 01001：GPTIM_CCER */
#define	GPTIMx_DCR_DBA_CNT	(0x9U << GPTIMx_DCR_DBA_Pos)	/* 01010：GPTIM_CNT */
#define	GPTIMx_DCR_DBA_PSC	(0xaU << GPTIMx_DCR_DBA_Pos)	/* 01011：GPTIM_PSC */
#define	GPTIMx_DCR_DBA_ARR	(0xbU << GPTIMx_DCR_DBA_Pos)	/* 01100：GPTIM_ARR */
#define	GPTIMx_DCR_DBA_CCR1	(0xcU << GPTIMx_DCR_DBA_Pos)	/* 01101：GPTIM_CCR1 */
#define	GPTIMx_DCR_DBA_CCR2	(0xdU << GPTIMx_DCR_DBA_Pos)	/* 01110：GPTIM_CCR2 */
#define	GPTIMx_DCR_DBA_CCR3	(0xeU << GPTIMx_DCR_DBA_Pos)	/* 01111：GPTIM_CCR3 */
#define	GPTIMx_DCR_DBA_CCR4	(0xfU << GPTIMx_DCR_DBA_Pos)	/* 10000：GPTIM_CCR4 */
#define	GPTIMx_DCR_DBA_DCR	(0x10U << GPTIMx_DCR_DBA_Pos)	/* 10001：GPTIM_DCR */
#define	GPTIMx_DCR_DBA_DMAR	(0x11U << GPTIMx_DCR_DBA_Pos)	/* 10010: GPTIM_DMAR */
#define	GPTIMx_DCR_DBA_ITRSEL	(0x12U << GPTIMx_DCR_DBA_Pos)	/* 10011: GPTIM_ITRSEL */

#define	GPTIMx_DMAR_DMAR_Pos	0	/* DMA burst访问寄存器 (DMA Burst Access Register) */
#define	GPTIMx_DMAR_DMAR_Msk	(0xffffU << GPTIMx_DMAR_DMAR_Pos)

#define GPTIMx_ITRSEL_ITR3SEL_Pos         6       /* ITR输入信号选择 (Internal Trigger Source Selection) */
#define GPTIMx_ITRSEL_ITR3SEL_Msk        (0x3U << GPTIMx_ITRSEL_ITR3SEL_Pos)
#define GPTIM0_ITRSEL_ITR3SEL_COMP1_OUT (0x0U << GPTIMx_ITRSEL_ITR3SEL_Pos)
#define GPTIM0_ITRSEL_ITR3SEL_RC4M      (0x1U << GPTIMx_ITRSEL_ITR3SEL_Pos)
#define GPTIM0_ITRSEL_ITR3SEL_COMP2_OUT (0x2U << GPTIMx_ITRSEL_ITR3SEL_Pos)
#define GPTIM0_ITRSEL_ITR3SEL_LPTOUT1   (0x3U << GPTIMx_ITRSEL_ITR3SEL_Pos)
#define GPTIM1_ITRSEL_ITR3SEL_COMP1_OUT (0x0U << GPTIMx_ITRSEL_ITR3SEL_Pos)
#define GPTIM1_ITRSEL_ITR3SEL_RC4M      (0x1U << GPTIMx_ITRSEL_ITR3SEL_Pos)
#define GPTIM1_ITRSEL_ITR3SEL_COMP2_OUT (0x2U << GPTIMx_ITRSEL_ITR3SEL_Pos)
#define GPTIM1_ITRSEL_ITR3SEL_LPTOUT2   (0x3U << GPTIMx_ITRSEL_ITR3SEL_Pos)

#define GPTIMx_ITRSEL_ITR2SEL_Pos         4       /* ITR输入信号选择 (Internal Trigger Source Selection) */
#define GPTIMx_ITRSEL_ITR2SEL_Msk        (0x3U << GPTIMx_ITRSEL_ITR2SEL_Pos)
#define GPTIM0_ITRSEL_ITR2SEL_BSTIM_TRGO    (0x0U << GPTIMx_ITRSEL_ITR2SEL_Pos)
#define GPTIM0_ITRSEL_ITR2SEL_LPUART1_RX    (0x1U << GPTIMx_ITRSEL_ITR2SEL_Pos)
#define GPTIM0_ITRSEL_ITR2SEL_RCLP          (0x2U << GPTIMx_ITRSEL_ITR2SEL_Pos)
#define GPTIM0_ITRSEL_ITR2SEL_XTLF          (0x3U << GPTIMx_ITRSEL_ITR2SEL_Pos)
#define GPTIM1_ITRSEL_ITR2SEL_BSTIM_TRGO    (0x0U << GPTIMx_ITRSEL_ITR2SEL_Pos)
#define GPTIM1_ITRSEL_ITR2SEL_LSCLK         (0x1U << GPTIMx_ITRSEL_ITR2SEL_Pos)
#define GPTIM1_ITRSEL_ITR2SEL_RCLP          (0x2U << GPTIMx_ITRSEL_ITR2SEL_Pos)
#define GPTIM1_ITRSEL_ITR2SEL_XTLF          (0x3U << GPTIMx_ITRSEL_ITR2SEL_Pos)

#define GPTIMx_ITRSEL_ITR1SEL_Pos         2       /* ITR输入信号选择 (Internal Trigger Source Selection) */
#define GPTIMx_ITRSEL_ITR1SEL_Msk        (0x3U << GPTIMx_ITRSEL_ITR1SEL_Pos)
#define GPTIM0_ITRSEL_ITR1SEL_GPTIM1_TRGO   (0x0U << GPTIMx_ITRSEL_ITR1SEL_Pos)
#define GPTIM0_ITRSEL_ITR1SEL_XTHF          (0x1U << GPTIMx_ITRSEL_ITR1SEL_Pos)
#define GPTIM0_ITRSEL_ITR1SEL_RCHF          (0x2U << GPTIMx_ITRSEL_ITR1SEL_Pos)
#define GPTIM0_ITRSEL_ITR1SEL_LPUART0_RX    (0x3U << GPTIMx_ITRSEL_ITR1SEL_Pos)
#define GPTIM1_ITRSEL_ITR1SEL_GPTIM0_TRGO   (0x0U << GPTIMx_ITRSEL_ITR1SEL_Pos)
#define GPTIM1_ITRSEL_ITR1SEL_XTHF          (0x1U << GPTIMx_ITRSEL_ITR1SEL_Pos)
#define GPTIM1_ITRSEL_ITR1SEL_RCHF          (0x2U << GPTIMx_ITRSEL_ITR1SEL_Pos)
#define GPTIM1_ITRSEL_ITR1SEL_ADC_EOC       (0x3U << GPTIMx_ITRSEL_ITR1SEL_Pos)

#define GPTIMx_ITRSEL_ITR0SEL_Pos         0       /* ITR输入信号选择 (Internal Trigger Source Selection) */
#define GPTIMx_ITRSEL_ITR0SEL_Msk        (0x3U << GPTIMx_ITRSEL_ITR0SEL_Pos)
#define GPTIM1_ITRSEL_ITR0SEL_ATIM_TRGO     (0x0U << GPTIMx_ITRSEL_ITR0SEL_Pos)
#define GPTIM1_ITRSEL_ITR0SEL_UART0_RX      (0x1U << GPTIMx_ITRSEL_ITR0SEL_Pos)
#define GPTIM1_ITRSEL_ITR0SEL_UART1_RX      (0x2U << GPTIMx_ITRSEL_ITR0SEL_Pos)
#define GPTIM1_ITRSEL_ITR0SEL_UART4_RX      (0x3U << GPTIMx_ITRSEL_ITR0SEL_Pos)
#define GPTIM2_ITRSEL_ITR0SEL_ATIM_TRGO     (0x0U << GPTIMx_ITRSEL_ITR0SEL_Pos)
#define GPTIM2_ITRSEL_ITR0SEL_UART0_RX      (0x1U << GPTIMx_ITRSEL_ITR0SEL_Pos)
#define GPTIM2_ITRSEL_ITR0SEL_UART1_RX      (0x2U << GPTIMx_ITRSEL_ITR0SEL_Pos)
#define GPTIM2_ITRSEL_ITR0SEL_UART5_RX      (0x3U << GPTIMx_ITRSEL_ITR0SEL_Pos)

//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void GPTIMx_Deinit(GPTIM_Type* GPTIMx);

/* Dead time和数字滤波时钟频率分频寄存器（相对CK_INT的分频比）(Counter clocK Divider) 相关函数 */
extern void GPTIMx_CR1_CKD_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CR1_CKD_Get(GPTIM_Type* GPTIMx);

/* Auto-reload预装载使能 (Auto-Reload Preload Enable) 相关函数 */
extern void GPTIMx_CR1_ARPE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CR1_ARPE_Getable(GPTIM_Type* GPTIMx);

/* 计数器对齐模式选择 (Counter Mode Selection) 相关函数 */
extern void GPTIMx_CR1_CMS_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CR1_CMS_Get(GPTIM_Type* GPTIMx);

/* 计数方向寄存器 (counter Direction) 相关函数 */
extern void GPTIMx_CR1_DIR_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CR1_DIR_Get(GPTIM_Type* GPTIMx);

/* 单脉冲输出模式 (One Pulse Mode) 相关函数 */
extern void GPTIMx_CR1_OPM_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CR1_OPM_Getable(GPTIM_Type* GPTIMx);

/* 更新请求选择 (Update Request Selection) 相关函数 */
extern void GPTIMx_CR1_URS_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CR1_URS_Getable(GPTIM_Type* GPTIMx);

/* 禁止update (Update Disable) 相关函数 */
extern void GPTIMx_CR1_UDIS_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CR1_UDIS_Getable(GPTIM_Type* GPTIMx);

/* 计数器使能 (Counter Enable) 相关函数 */
extern void GPTIMx_CR1_CEN_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CR1_CEN_Getable(GPTIM_Type* GPTIMx);

/* 通道1输入源选择 (Timer Input 1 Selection) 相关函数 */
extern void GPTIMx_CR2_TI1S_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CR2_TI1S_Get(GPTIM_Type* GPTIMx);

/* 主机模式选择，用于配置主机模式下向从机发送的同步触发信号（TRGO）源 (Master Mode Selection) 相关函数 */
extern void GPTIMx_CR2_MMS_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CR2_MMS_Get(GPTIM_Type* GPTIMx);

/* 捕捉/比较 DMA选择 (Capture/Compare DMA Selection) 相关函数 */
extern void GPTIMx_CR2_CCDS_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CR2_CCDS_Get(GPTIM_Type* GPTIMx);

/* 外部触发信号极性配置 (External Trigger Polarity) 相关函数 */
extern void GPTIMx_SMCR_ETP_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_SMCR_ETP_Get(GPTIM_Type* GPTIMx);

/* 外部时钟使能 (External Clock Enable) 相关函数 */
extern void GPTIMx_SMCR_ECE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_SMCR_ECE_Getable(GPTIM_Type* GPTIMx);

/* 外部触发信号预分频寄存器 (External Trigger Prescaler)
外部触发信号ETRP的频率最多只能是GPTIM工作时钟的1/4，当输入信号频率较高时，可以使用预分频 相关函数 */
extern void GPTIMx_SMCR_ETPS_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_SMCR_ETPS_Get(GPTIM_Type* GPTIMx);

/* 外部触发信号滤波时钟和长度选择 (External Trigger Filter) 相关函数 */
extern void GPTIMx_SMCR_ETF_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_SMCR_ETF_Get(GPTIM_Type* GPTIMx);

/* 主/从模式 (Master Slave Mode) 相关函数 */
extern void GPTIMx_SMCR_MSM_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_SMCR_MSM_Get(GPTIM_Type* GPTIMx);

/* 触发选择，用于选择同步计数器的触发源 (Trigger Source) 相关函数 */
extern void GPTIMx_SMCR_TS_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_SMCR_TS_Get(GPTIM_Type* GPTIMx);

/* 从机模式选择 (Slave Mode Selection) 相关函数 */
extern void GPTIMx_SMCR_SMS_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_SMCR_SMS_Get(GPTIM_Type* GPTIMx);

/* 捕捉比较通道4的DMA模式配置 (CC4 Burst Enable) 相关函数 */
extern void GPTIMx_DIER_CC4BURSTEN_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_DIER_CC4BURSTEN_Get(GPTIM_Type* GPTIMx);

/* 捕捉比较通道3的DMA模式配置 (CC3 Burst Enable) 相关函数 */
extern void GPTIMx_DIER_CC3BURSTEN_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_DIER_CC3BURSTEN_Get(GPTIM_Type* GPTIMx);

/* 捕捉比较通道2的DMA模式配置 (CC2 Burst Enable) 相关函数 */
extern void GPTIMx_DIER_CC2BURSTEN_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_DIER_CC2BURSTEN_Get(GPTIM_Type* GPTIMx);

/* 捕捉比较通道1的DMA模式配置 (CC1 Burst Enable) 相关函数 */
extern void GPTIMx_DIER_CC1BURSTEN_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_DIER_CC1BURSTEN_Get(GPTIM_Type* GPTIMx);

/* 外部触发DMA请求使能 (Triggered DMA Enable) 相关函数 */
extern void GPTIMx_DIER_TDE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_DIER_TDE_Getable(GPTIM_Type* GPTIMx);

/* 捕捉比较通道4的DMA请求使能 (CC4 DMA Enable) 相关函数 */
extern void GPTIMx_DIER_CC4DE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_DIER_CC4DE_Getable(GPTIM_Type* GPTIMx);

/* 捕捉比较通道3的DMA请求使能 (CC3 DMA Enable) 相关函数 */
extern void GPTIMx_DIER_CC3DE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_DIER_CC3DE_Getable(GPTIM_Type* GPTIMx);

/* 捕捉比较通道2的DMA请求使能 (CC2 DMA Enable) 相关函数 */
extern void GPTIMx_DIER_CC2DE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_DIER_CC2DE_Getable(GPTIM_Type* GPTIMx);

/* 捕捉比较通道1的DMA请求使能 (CC1 DMA Enable) 相关函数 */
extern void GPTIMx_DIER_CC1DE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_DIER_CC1DE_Getable(GPTIM_Type* GPTIMx);

/* Update Event DMA请求使能 (Update event DMA Enable) 相关函数 */
extern void GPTIMx_DIER_UDE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_DIER_UDE_Getable(GPTIM_Type* GPTIMx);

/* 触发事件中断使能 (Trigger event Interrupt Enable) 相关函数 */
extern void GPTIMx_DIER_TIE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_DIER_TIE_Getable(GPTIM_Type* GPTIMx);

/* 捕捉/比较通道4中断使能 (CC4 Interrupt Enable) 相关函数 */
extern void GPTIMx_DIER_CC4IE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_DIER_CC4IE_Getable(GPTIM_Type* GPTIMx);

/* 捕捉/比较通道3中断使能 (CC3 Interrupt Enable) 相关函数 */
extern void GPTIMx_DIER_CC3IE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_DIER_CC3IE_Getable(GPTIM_Type* GPTIMx);

/* 捕捉/比较通道2中断使能 (CC2 Interrupt Enable) 相关函数 */
extern void GPTIMx_DIER_CC2IE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_DIER_CC2IE_Getable(GPTIM_Type* GPTIMx);

/* 捕捉/比较通道1中断使能 (CC1 Interrupt Enable) 相关函数 */
extern void GPTIMx_DIER_CC1IE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_DIER_CC1IE_Getable(GPTIM_Type* GPTIMx);

/* Update事件中断使能 (Update event Interrupt Enable) 相关函数 */
extern void GPTIMx_DIER_UIE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_DIER_UIE_Getable(GPTIM_Type* GPTIMx);

/* 捕捉/比较通道4的Overcapture中断 (Over-Capture Interrupt Flag for CC4) 相关函数 */
extern void GPTIMx_ISR_CC4OF_Clr(GPTIM_Type* GPTIMx);
extern FlagStatus GPTIMx_ISR_CC4OF_Chk(GPTIM_Type* GPTIMx);

/* 捕捉/比较通道3的Overcapture中断 (Over-Capture Interrupt Flag for CC3) 相关函数 */
extern void GPTIMx_ISR_CC3OF_Clr(GPTIM_Type* GPTIMx);
extern FlagStatus GPTIMx_ISR_CC3OF_Chk(GPTIM_Type* GPTIMx);

/* 捕捉/比较通道2的Overcapture中断 (Over-Capture Interrupt Flag for CC2) 相关函数 */
extern void GPTIMx_ISR_CC2OF_Clr(GPTIM_Type* GPTIMx);
extern FlagStatus GPTIMx_ISR_CC2OF_Chk(GPTIM_Type* GPTIMx);

/* 捕捉/比较通道1的Overcapture中断 (Over-Capture Interrupt Flag for CC1) 相关函数 */
extern void GPTIMx_ISR_CC1OF_Clr(GPTIM_Type* GPTIMx);
extern FlagStatus GPTIMx_ISR_CC1OF_Chk(GPTIM_Type* GPTIMx);

/* 触发事件中断标志 相关函数 */
extern void GPTIMx_ISR_TIF_Clr(GPTIM_Type* GPTIMx);
extern FlagStatus GPTIMx_ISR_TIF_Chk(GPTIM_Type* GPTIMx);

/* 捕捉/比较通道4中断标志 (CC4 Interrupt Flag) 相关函数 */
extern void GPTIMx_ISR_CC4IF_Clr(GPTIM_Type* GPTIMx);
extern FlagStatus GPTIMx_ISR_CC4IF_Chk(GPTIM_Type* GPTIMx);

/* 捕捉/比较通道3中断标志 (CC3 Interrupt Flag) 相关函数 */
extern void GPTIMx_ISR_CC3IF_Clr(GPTIM_Type* GPTIMx);
extern FlagStatus GPTIMx_ISR_CC3IF_Chk(GPTIM_Type* GPTIMx);

/* 捕捉/比较通道2中断标志 (CC2 Interrupt Flag) 相关函数 */
extern void GPTIMx_ISR_CC2IF_Clr(GPTIM_Type* GPTIMx);
extern FlagStatus GPTIMx_ISR_CC2IF_Chk(GPTIM_Type* GPTIMx);

/* 捕捉/比较通道1中断标志 (CC1 Interrupt Flag) 相关函数 */
extern void GPTIMx_ISR_CC1IF_Clr(GPTIM_Type* GPTIMx);
extern FlagStatus GPTIMx_ISR_CC1IF_Chk(GPTIM_Type* GPTIMx);

/* Update事件中断标志，硬件置位，软件写1清零。(Update event Interrupt Flag) 相关函数 */
extern void GPTIMx_ISR_UIF_Clr(GPTIM_Type* GPTIMx);
extern FlagStatus GPTIMx_ISR_UIF_Chk(GPTIM_Type* GPTIMx);

/* 软件触发，软件置位此寄存器产生触发事件，硬件自动清零 (Trigger Generate) 相关函数 */
extern void GPTIMx_EGR_TG_Setable(GPTIM_Type* GPTIMx, FunState NewState);

/* 捕捉/比较通道4软件触发 (CC4 Generate) 相关函数 */
extern void GPTIMx_EGR_CC4G_Setable(GPTIM_Type* GPTIMx, FunState NewState);

/* 捕捉/比较通道3软件触发 (CC3 Generate) 相关函数 */
extern void GPTIMx_EGR_CC3G_Setable(GPTIM_Type* GPTIMx, FunState NewState);

/* 捕捉/比较通道2软件触发 (CC2 Generate) 相关函数 */
extern void GPTIMx_EGR_CC2G_Setable(GPTIM_Type* GPTIMx, FunState NewState);

/* 捕捉/比较通道1软件触发 (CC1 Generate) 相关函数 */
extern void GPTIMx_EGR_CC1G_Setable(GPTIM_Type* GPTIMx, FunState NewState);

/* 软件Update事件，软件置位此寄存器产生Update事件，硬件自动清零 (User Generate) 相关函数 */
extern void GPTIMx_EGR_UG_Setable(GPTIM_Type* GPTIMx, FunState NewState);

/* 输出比较2清零使能 (OC2 Clear Enable) 相关函数 */
extern void GPTIMx_CCMR1_OC2CE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CCMR1_OC2CE_Getable(GPTIM_Type* GPTIMx);

/* 输出比较2模式配置，此寄存器定义OC2REF信号的行为 (OC2 Mode) 相关函数 */
extern void GPTIMx_CCMR1_OC2M_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCMR1_OC2M_Get(GPTIM_Type* GPTIMx);

/* 输出比较2预装载使能 (OC2 Preload Enable) 相关函数 */
extern void GPTIMx_CCMR1_OC2PE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CCMR1_OC2PE_Getable(GPTIM_Type* GPTIMx);

/* 输出比较2快速使能 (OC2 Fast Enable) 相关函数 */
extern void GPTIMx_CCMR1_OC2FE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CCMR1_OC2FE_Getable(GPTIM_Type* GPTIMx);

/* 捕捉/比较2通道选择 (CC2 channel Selection) 相关函数 */
extern void GPTIMx_CCMR1_CC2S_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCMR1_CC2S_Get(GPTIM_Type* GPTIMx);

/* 输出比较1清零使能 (OC2 Clear Enable) 相关函数 */
extern void GPTIMx_CCMR1_OC1CE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CCMR1_OC1CE_Getable(GPTIM_Type* GPTIMx);

/* 输出比较1模式配置，此寄存器定义OC1REF信号的行为 (OC1 Mode) 相关函数 */
extern void GPTIMx_CCMR1_OC1M_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCMR1_OC1M_Get(GPTIM_Type* GPTIMx);

/* 输出比较1预装载使能 (OC1 Preload Enable) 相关函数 */
extern void GPTIMx_CCMR1_OC1PE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CCMR1_OC1PE_Getable(GPTIM_Type* GPTIMx);

/* 输出比较1快速使能 (OC1 Fast Enable) 相关函数 */
extern void GPTIMx_CCMR1_OC1FE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CCMR1_OC1FE_Getable(GPTIM_Type* GPTIMx);

/* 捕捉/比较1通道选择 (CC1 channel Selection) 相关函数 */
extern void GPTIMx_CCMR1_CC1S_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCMR1_CC1S_Get(GPTIM_Type* GPTIMx);

/* 输入捕捉2滤波 (IC2 Filter) 相关函数 */
extern void GPTIMx_CCMR1_IC2F_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCMR1_IC2F_Get(GPTIM_Type* GPTIMx);

/* 输入捕捉2预分频 (IC2 Prescaler) 相关函数 */
extern void GPTIMx_CCMR1_IC2PSC_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCMR1_IC2PSC_Get(GPTIM_Type* GPTIMx);

/* 输入捕捉1滤波 (IC1 Filter) 相关函数 */
extern void GPTIMx_CCMR1_IC1F_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCMR1_IC1F_Get(GPTIM_Type* GPTIMx);

/* 输入捕捉1预分频 (IC1 Prescaler) 相关函数 */
extern void GPTIMx_CCMR1_IC1PSC_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCMR1_IC1PSC_Get(GPTIM_Type* GPTIMx);

/* 输出比较4清零使能 (OC4 Clear Enable) 相关函数 */
extern void GPTIMx_CCMR2_OC4CE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CCMR2_OC4CE_Getable(GPTIM_Type* GPTIMx);

/* 输出比较4模式配置，此寄存器定义OC4REF信号的行为 (OC4 Mode) 相关函数 */
extern void GPTIMx_CCMR2_OC4M_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCMR2_OC4M_Get(GPTIM_Type* GPTIMx);

/* 输出比较4预装载使能 (OC4 Preload Enable) 相关函数 */
extern void GPTIMx_CCMR2_OC4PE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CCMR2_OC4PE_Getable(GPTIM_Type* GPTIMx);

/* 输出比较4快速使能 (OC4 Fast Enable) 相关函数 */
extern void GPTIMx_CCMR2_OC4FE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CCMR2_OC4FE_Getable(GPTIM_Type* GPTIMx);

/* 捕捉/比较4通道选择 (CC4 channel Selection) 相关函数 */
extern void GPTIMx_CCMR2_CC4S_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCMR2_CC4S_Get(GPTIM_Type* GPTIMx);

/* 输出比较3清零使能 (OC3 Clear Enable) 相关函数 */
extern void GPTIMx_CCMR2_OC3CE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CCMR2_OC3CE_Getable(GPTIM_Type* GPTIMx);

/* 输出比较3模式配置，此寄存器定义OC3REF信号的行为 (OC3 Mode) 相关函数 */
extern void GPTIMx_CCMR2_OC3M_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCMR2_OC3M_Get(GPTIM_Type* GPTIMx);

/* 输出比较3预装载使能 (OC3 Preload Enable) 相关函数 */
extern void GPTIMx_CCMR2_OC3PE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CCMR2_OC3PE_Getable(GPTIM_Type* GPTIMx);

/* 输出比较3快速使能 (OC3 Fast Enable) 相关函数 */
extern void GPTIMx_CCMR2_OC3FE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CCMR2_OC3FE_Getable(GPTIM_Type* GPTIMx);

/* 捕捉/比较3通道选择 (CC3 channel Selection) 相关函数 */
extern void GPTIMx_CCMR2_CC3S_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCMR2_CC3S_Get(GPTIM_Type* GPTIMx);

/* 输入捕捉4滤波 (IC4 Filter) 相关函数 */
extern void GPTIMx_CCMR2_IC4F_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCMR2_IC4F_Get(GPTIM_Type* GPTIMx);

/* 输入捕捉4预分频 (IC4 Prescaler) 相关函数 */
extern void GPTIMx_CCMR2_IC4PSC_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCMR2_IC4PSC_Get(GPTIM_Type* GPTIMx);

/* 输入捕捉3滤波 (IC3 Filter) 相关函数 */
extern void GPTIMx_CCMR2_IC3F_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCMR2_IC3F_Get(GPTIM_Type* GPTIMx);

/* 输入捕捉3预分频 (IC3 Prescaler) 相关函数 */
extern void GPTIMx_CCMR2_IC3PSC_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCMR2_IC3PSC_Get(GPTIM_Type* GPTIMx);

/* 捕捉/比较4输出极性 (CC4 Polarity) 相关函数 */
extern void GPTIMx_CCER_CC4P_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCER_CC4P_Get(GPTIM_Type* GPTIMx);

/* 捕捉/比较4输出使能 (CC4 output Enable) 相关函数 */
extern void GPTIMx_CCER_CC4E_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CCER_CC4E_Getable(GPTIM_Type* GPTIMx);

/* 捕捉/比较3输出极性 (CC3 Polarity) 相关函数 */
extern void GPTIMx_CCER_CC3P_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCER_CC3P_Get(GPTIM_Type* GPTIMx);

/* 捕捉/比较3输出使能 (CC3 output Enable) 相关函数 */
extern void GPTIMx_CCER_CC3E_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CCER_CC3E_Getable(GPTIM_Type* GPTIMx);

/* 捕捉/比较2输出极性 (CC2 Polarity) 相关函数 */
extern void GPTIMx_CCER_CC2P_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCER_CC2P_Get(GPTIM_Type* GPTIMx);

/* 捕捉/比较2输出使能 (CC2 output Enable) 相关函数 */
extern void GPTIMx_CCER_CC2E_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CCER_CC2E_Getable(GPTIM_Type* GPTIMx);

/* 捕捉/比较1输出极性 (CC1 Polarity) 相关函数 */
extern void GPTIMx_CCER_CC1P_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCER_CC1P_Get(GPTIM_Type* GPTIMx);

/* 捕捉/比较1输出使能 (CC1 output Enable) 相关函数 */
extern void GPTIMx_CCER_CC1E_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CCER_CC1E_Getable(GPTIM_Type* GPTIMx);

/* 计数器值 (Counter) 相关函数 */
extern void GPTIMx_CNT_Write(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CNT_Read(GPTIM_Type* GPTIMx);

/* 计数器时钟（CK_CNT）预分频值 (Counter Clock Prescaler) 相关函数 */
extern void GPTIMx_PSC_Write(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_PSC_Read(GPTIM_Type* GPTIMx);

/* 计数溢出时的自动重载值 (Auto-Reload Register) 相关函数 */
extern void GPTIMx_ARR_Write(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_ARR_Read(GPTIM_Type* GPTIMx);

/* 捕捉/比较通道1寄存器 (Capture/Compare channel 1 Register) 相关函数 */
extern void GPTIMx_CCR1_Write(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCR1_Read(GPTIM_Type* GPTIMx);

/* 捕捉/比较通道2寄存器 (Capture/Compare channel 2 Register) 相关函数 */
extern void GPTIMx_CCR2_Write(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCR2_Read(GPTIM_Type* GPTIMx);

/* 捕捉/比较通道3寄存器 (Capture/Compare channel 3 Register) 相关函数 */
extern void GPTIMx_CCR3_Write(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCR3_Read(GPTIM_Type* GPTIMx);

/* 捕捉/比较通道4寄存器 (Capture/Compare channel 4 Register) 相关函数 */
extern void GPTIMx_CCR4_Write(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCR4_Read(GPTIM_Type* GPTIMx);

/* DMA Burst长度 (DMA Burst Length) 相关函数 */
extern void GPTIMx_DCR_DBL_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_DCR_DBL_Get(GPTIM_Type* GPTIMx);

/* DMA基地址，定义指向寄存器的偏移地址 (DMA Burst offset Address) 相关函数 */
extern void GPTIMx_DCR_DBA_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_DCR_DBA_Get(GPTIM_Type* GPTIMx);

/* DMA burst访问寄存器 (DMA Burst Access Register) 相关函数 */
extern void GPTIMx_DMAR_Write(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_DMAR_Read(GPTIM_Type* GPTIMx);

/* ITR输入信号选择 (Internal Trigger Source Selection) 相关函数 */
extern void GPTIMx_ITRSEL_ITR3SEL_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_ITRSEL_ITR3SEL_Get(GPTIM_Type* GPTIMx);

/* ITR输入信号选择 (Internal Trigger Source Selection) 相关函数 */
extern void GPTIMx_ITRSEL_ITR2SEL_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_ITRSEL_ITR2SEL_Get(GPTIM_Type* GPTIMx);

/* ITR输入信号选择 (Internal Trigger Source Selection) 相关函数 */
extern void GPTIMx_ITRSEL_ITR1SEL_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_ITRSEL_ITR1SEL_Get(GPTIM_Type* GPTIMx);

/* ITR输入信号选择 (Internal Trigger Source Selection) 相关函数 */
extern void GPTIMx_ITRSEL_ITR0SEL_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_ITRSEL_ITR0SEL_Get(GPTIM_Type* GPTIMx);

extern void GPTIMx_TimeBaseInit(GPTIM_Type* GPTIMx,TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);
extern void GPTIMx_ClearITPendingBit(GPTIM_Type* GPTIMx,uint32_t TIM_IT);
extern void GPTIMx_ITConfig(GPTIM_Type* GPTIMx,uint32_t TIM_IT, FunState NewState);
extern ITStatus GPTIMx_GetITStatus(GPTIM_Type* GPTIMx,uint32_t TIM_IT);
extern void GPTIMx_Cmd(GPTIM_Type* GPTIMx,FunState NewState);
extern void GPTIMx_ICInit(GPTIM_Type* GPTIMx, TIM_ICInitTypeDef* TIM_ICInitStruct);
#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_GPTIM_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
