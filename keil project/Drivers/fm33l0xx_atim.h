/**
  ******************************************************************************
  * @file    fm33l0xx_atim.h
  * @author  FM33L0xx Application Team
  * @version V0.1.1
  * @date    6-Dec-2019
  * @brief   This file contains all the functions prototypes for the ATIM firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33L0XX_ATIM_H
#define __FM33L0XX_ATIM_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33L0XX.h" 
#include "fm33l0xx_tim.h" 
//------------------------------------------------------------------------------

#define	ATIM_CR1_CKD_Pos	8	/* Dead time和数字滤波时钟频率分频寄存器 */
#define	ATIM_CR1_CKD_Msk	(0x3U << ATIM_CR1_CKD_Pos)
#define	ATIM_CR1_CKD_1TINT	(0x0U << ATIM_CR1_CKD_Pos)	/* 0：TCK */
#define	ATIM_CR1_CKD_2TINT	(0x1U << ATIM_CR1_CKD_Pos)	/* 1：2TCK */
#define	ATIM_CR1_CKD_4TINT	(0x2U << ATIM_CR1_CKD_Pos)	/* 2：4TCK */

#define	ATIM_CR1_ARPE_Pos	7	/* ARR预装载使能  */
#define	ATIM_CR1_ARPE_Msk	(0x1U << ATIM_CR1_ARPE_Pos)
	/* 0：ARR不使能预装载 */
	/* 1：ARR 使能预装载 */

#define	ATIM_CR1_CMS_Pos	5	/* 计数器对齐模式选择 */
#define	ATIM_CR1_CMS_Msk	(0x3U << ATIM_CR1_CMS_Pos)
#define	ATIM_CR1_CMS_SINGLE 	(0x0U << ATIM_CR1_CMS_Pos)	/* 00：边沿对齐模式 */
#define	ATIM_CR1_CMS_CENTRAL1	(0x1U << ATIM_CR1_CMS_Pos)	/* 01：中央对齐模式1，输出比较中断标志仅在计数器向下计数的过程中置位 */
#define	ATIM_CR1_CMS_CENTRAL2	(0x2U << ATIM_CR1_CMS_Pos)	/* 10：中央对齐模式2，输出比较中断标志仅在计数器向上计数的过程中置位 */
#define	ATIM_CR1_CMS_CENTRAL3	(0x3U << ATIM_CR1_CMS_Pos)	/* 11：中央对齐模式3，输出比较中断标志在计数器向上向下计数的过程中都会置位 */

#define	ATIM_CR1_DIR_Pos	4	/* 计数方向寄存器 */
#define	ATIM_CR1_DIR_Msk	(0x1U << ATIM_CR1_DIR_Pos)
#define	ATIM_CR1_DIR_UP	(0x0U << ATIM_CR1_DIR_Pos)	/* 0：向上计数 */
#define	ATIM_CR1_DIR_DOWN	(0x1U << ATIM_CR1_DIR_Pos)	/* 1：向下计数 */

#define	ATIM_CR1_OPM_Pos	3	/* 单脉冲输出模式 */
#define	ATIM_CR1_OPM_Msk	(0x1U << ATIM_CR1_OPM_Pos)
	/* 0：Update Event发生时计数器不停止 */
	/* 1：Update Event发生时计数器停止（自动清零CEN） */

#define	ATIM_CR1_URS_Pos	2	/* 更新请求选择 */
#define	ATIM_CR1_URS_Msk	(0x1U << ATIM_CR1_URS_Pos)
	/* 0：以下事件能够产生update中断或DMA请求
-计数器上溢出或下溢出
-软件置位UG寄存器
-从机控制器产生update */
	/* 1：仅计数器上溢出或下溢出会产生update中断或DMA请求 */

#define	ATIM_CR1_UDIS_Pos	1	/* 禁止update */
#define	ATIM_CR1_UDIS_Msk	(0x1U << ATIM_CR1_UDIS_Pos)
	/* 0：使能update事件；以下事件发生时产生update事件
-计数器上溢出或下溢出
-软件置位UG寄存器
-从机控制器产生update */
	/* 1：禁止update事件，不更新shadow寄存器。当UG置位或从机控制器收到硬件reset时重新初始化计数器和预分频器 */

#define	ATIM_CR1_CEN_Pos	0	/* 计数器使能 */
#define	ATIM_CR1_CEN_Msk	(0x1U << ATIM_CR1_CEN_Pos)
	/* 0：计数器关闭 */
	/* 1：计数器使能 */

#define	ATIM_CR2_OIS4_Pos	14	/* 参考OIS1 */
#define	ATIM_CR2_OIS4_Msk	(0x1U << ATIM_CR2_OIS4_Pos)

#define	ATIM_CR2_OIS3N_Pos	13	/* 参考OIS1N */
#define	ATIM_CR2_OIS3N_Msk	(0x1U << ATIM_CR2_OIS3N_Pos)

#define	ATIM_CR2_OIS3_Pos	12	/* 参考OIS1 */
#define	ATIM_CR2_OIS3_Msk	(0x1U << ATIM_CR2_OIS3_Pos)

#define	ATIM_CR2_OIS2N_Pos	11	/* 参考OIS1N */
#define	ATIM_CR2_OIS2N_Msk	(0x1U << ATIM_CR2_OIS2N_Pos)

#define	ATIM_CR2_OIS2_Pos	10	/* 参考OIS1 */
#define	ATIM_CR2_OIS2_Msk	(0x1U << ATIM_CR2_OIS2_Pos)

#define	ATIM_CR2_OIS1N_Pos	9	/* OC1N的输出IDLE状态 */
#define	ATIM_CR2_OIS1N_Msk	(0x1U << ATIM_CR2_OIS1N_Pos)
	/* 0：当MOE=0时，经过dead time后，OC1N=0 */
	/* 1：当MOE=0时，经过dead time后，OC1N=1 */

#define	ATIM_CR2_OIS1_Pos	8	/* OC1的输出IDLE状态 */
#define	ATIM_CR2_OIS1_Msk	(0x1U << ATIM_CR2_OIS1_Pos)
	/* 0：当MOE=0时（如果使能了互补输出，需经过dead time后），OC1=0 */
	/* 1：当MOE=0时（如果使能了互补输出，需经过dead time后），OC1=1 */

#define	ATIM_CR2_TI1S_Pos	7	/* ATIM输入TI1选择 */
#define	ATIM_CR2_TI1S_Msk	(0x1U << ATIM_CR2_TI1S_Pos)
#define	ATIM_CR2_TI1S_CH1	(0x0U << ATIM_CR2_TI1S_Pos)	/* 0：ATIM_CH1引脚连接到TI1输入 */
#define	ATIM_CR2_TI1S_XOR	(0x1U << ATIM_CR2_TI1S_Pos)	/* 1：ATIM_CH1、CH2、CH3引脚XOR后连接到TI1输入 */

#define	ATIM_CR2_MMS_Pos	4	/* 主机模式选择，用于配置主机模式下向从机发送的同步触发信号（TRGO）源 */
#define	ATIM_CR2_MMS_Msk	(0x7U << ATIM_CR2_MMS_Pos)
#define	ATIM_CR2_MMS_EGR	(0x0U << ATIM_CR2_MMS_Pos)	/* 000：ATIM_EGR的UG寄存器被用作TRGO */
#define	ATIM_CR2_MMS_CEN	(0x1U << ATIM_CR2_MMS_Pos)	/* 001：计数器使能信号CNT_EN被用作TRGO，可用于同时启动多个定时器 */
#define	ATIM_CR2_MMS_UE	(0x2U << ATIM_CR2_MMS_Pos)	/* 010：UE（update event）信号被用作TRGO */
#define	ATIM_CR2_MMS_COMP	(0x3U << ATIM_CR2_MMS_Pos)	/* 011：比较脉冲，如果CC1IF标志将要置位，TRGO输出一个正脉冲 */
#define	ATIM_CR2_MMS_OC1REF	(0x4U << ATIM_CR2_MMS_Pos)	/* 100：OC1REF用作TRGO */
#define	ATIM_CR2_MMS_OC2REF	(0x5U << ATIM_CR2_MMS_Pos)	/* 101：OC2REF用作TRGO */
#define	ATIM_CR2_MMS_OC3REF	(0x6U << ATIM_CR2_MMS_Pos)	/* 110：OC3REF用作TRGO */
#define	ATIM_CR2_MMS_OC4REF	(0x7U << ATIM_CR2_MMS_Pos)	/* 111：OC4REF用作TRGO */

#define	ATIM_CR2_CCDS_Pos	3	/* 捕捉/比较 DMA选择 */
#define	ATIM_CR2_CCDS_Msk	(0x1U << ATIM_CR2_CCDS_Pos)
#define	ATIM_CR2_CCDS_CC	(0x0U << ATIM_CR2_CCDS_Pos)	/* 0：捕捉/比较事件发生时发送DMA请求 */
#define	ATIM_CR2_CCDS_UE	(0x1U << ATIM_CR2_CCDS_Pos)	/* 1：Update Event发生时发送DMA请求 */

#define	ATIM_CR2_CCUS_Pos	2	/* 捕捉/比较控制寄存器更新选择 */
#define	ATIM_CR2_CCUS_Msk	(0x1U << ATIM_CR2_CCUS_Pos)
#define	ATIM_CR2_CCUS_COMG	(0x0U << ATIM_CR2_CCUS_Pos)	/* 0：当捕捉/比较控制寄存器使能了preload（CCPC=1），他们仅在置位COMG寄存器时更新 */
#define	ATIM_CR2_CCUS_COMG_TRGI	(0x1U << ATIM_CR2_CCUS_Pos)	/* 1：当捕捉/比较控制寄存器使能了preload（CCPC=1），他们在置位COMG寄存器或者TRGI上升沿时更新 */

#define	ATIM_CR2_CCPC_Pos	0
#define	ATIM_CR2_CCPC_Msk	(0x1U << ATIM_CR2_CCPC_Pos)
	/* 0：CCxE, CCxNE, OCxM寄存器不使能preload */

#define	ATIM_SMCR_ETP_Pos	15	/* 外部触发信号极性配置 */
#define	ATIM_SMCR_ETP_Msk	(0x1U << ATIM_SMCR_ETP_Pos)
#define	ATIM_SMCR_ETP_POS	(0x0U << ATIM_SMCR_ETP_Pos)	/* 0：高电平或上升沿有效 */
#define	ATIM_SMCR_ETP_NEG	(0x1U << ATIM_SMCR_ETP_Pos)	/* 1：低电平或下降沿有效 */

#define	ATIM_SMCR_ECE_Pos	14	/* 外部时钟使能 */
#define	ATIM_SMCR_ECE_Msk	(0x1U << ATIM_SMCR_ECE_Pos)
	/* 0：关闭外部时钟模式2 */
	/* 1：使能外部时钟模式2，计数器时钟为ETRF有效沿 */

#define	ATIM_SMCR_ETPS_Pos	12	/* 外部触发信号预分频寄存器,外部触发信号ETRP的频率最多只能是ATIM工作时钟的1/4，当输入信号频率较高时，可以使用预分频 */
#define	ATIM_SMCR_ETPS_Msk	(0x3U << ATIM_SMCR_ETPS_Pos)
#define	ATIM_SMCR_ETPS_DIV1	(0x0U << ATIM_SMCR_ETPS_Pos)	/* 00：不分频 */
#define	ATIM_SMCR_ETPS_DIV2	(0x1U << ATIM_SMCR_ETPS_Pos)	/* 01：2分频 */
#define	ATIM_SMCR_ETPS_DIV4	(0x2U << ATIM_SMCR_ETPS_Pos)	/* 10：4分频 */
#define	ATIM_SMCR_ETPS_DIV8	(0x3U << ATIM_SMCR_ETPS_Pos)	/* 11：8分频 */

#define	ATIM_SMCR_ETF_Pos	8	/* 外部触发信号滤波时钟和长度选择 */
#define	ATIM_SMCR_ETF_Msk	(0xfU << ATIM_SMCR_ETF_Pos)
#define	ATIM_SMCR_ETF_FILT0	(0x0U << ATIM_SMCR_ETF_Pos)	/* 0000：无滤波 */
#define	ATIM_SMCR_ETF_FILT1	(0x1U << ATIM_SMCR_ETF_Pos)	/* 0001：fSAMPLING=fCK_INT, N=2 */
#define	ATIM_SMCR_ETF_FILT2	(0x2U << ATIM_SMCR_ETF_Pos)	/* 0010：fSAMPLING=fCK_INT, N=4 */
#define	ATIM_SMCR_ETF_FILT3	(0x3U << ATIM_SMCR_ETF_Pos)	/* 0011：fSAMPLING=fCK_INT, N=8 */
#define	ATIM_SMCR_ETF_FILT4	(0x4U << ATIM_SMCR_ETF_Pos)	/* 0100：fSAMPLING=fDTS/2, N=6 */
#define	ATIM_SMCR_ETF_FILT5	(0x5U << ATIM_SMCR_ETF_Pos)	/* 0101：fSAMPLING=fDTS/2, N=8 */
#define	ATIM_SMCR_ETF_FILT6	(0x6U << ATIM_SMCR_ETF_Pos)	/* 0110：fSAMPLING=fDTS/4, N=6 */
#define	ATIM_SMCR_ETF_FILT7	(0x7U << ATIM_SMCR_ETF_Pos)	/* 0111：fSAMPLING=fDTS/4, N=8 */
#define	ATIM_SMCR_ETF_FILT8	(0x8U << ATIM_SMCR_ETF_Pos)	/* 1000：fSAMPLING=fDTS/8, N=6 */
#define	ATIM_SMCR_ETF_FILT9	(0x9U << ATIM_SMCR_ETF_Pos)	/* 1001：fSAMPLING=fDTS/8, N=8 */
#define	ATIM_SMCR_ETF_FILT10	(0xaU << ATIM_SMCR_ETF_Pos)	/* 1010：fSAMPLING=fDTS/16, N=5 */
#define	ATIM_SMCR_ETF_FILT11	(0xbU << ATIM_SMCR_ETF_Pos)	/* 1011：fSAMPLING=fDTS/16, N=6 */
#define	ATIM_SMCR_ETF_FILT12	(0xcU << ATIM_SMCR_ETF_Pos)	/* 1100：fSAMPLING=fDTS/16, N=8 */
#define	ATIM_SMCR_ETF_FILT13	(0xdU << ATIM_SMCR_ETF_Pos)	/* 1101：fSAMPLING=fDTS/32, N=5 */
#define	ATIM_SMCR_ETF_FILT14	(0xeU << ATIM_SMCR_ETF_Pos)	/* 1110：fSAMPLING=fDTS/32, N=6 */
#define	ATIM_SMCR_ETF_FILT15	(0xfU << ATIM_SMCR_ETF_Pos)	/* 1111：fSAMPLING=fDTS/32, N=8 */

#define	ATIM_SMCR_MSM_Pos	7	/* 主机从机模式选 */
#define	ATIM_SMCR_MSM_Msk	(0x1U << ATIM_SMCR_MSM_Pos)
#define	ATIM_SMCR_MSM_NONE	(0x0U << ATIM_SMCR_MSM_Pos)	/* 0：无动作 */
#define	ATIM_SMCR_MSM_DELAY	(0x1U << ATIM_SMCR_MSM_Pos)	/* 1：触发模式下，TRGI触发的动作被延迟，以便于通过TRGO实现当前定时器和从机定时器同步 */

#define	ATIM_SMCR_TS_Pos	4	/* 触发选择，用于选择同步计数器的触发源 */
#define	ATIM_SMCR_TS_Msk	(0x7U << ATIM_SMCR_TS_Pos)
#define	ATIM_SMCR_TS_ITR0	(0x0U << ATIM_SMCR_TS_Pos)	/* 000：内部触发信号（ITR0） */
#define	ATIM_SMCR_TS_ITR1	(0x1U << ATIM_SMCR_TS_Pos)	/* 001：内部触发信号（ITR1） */
#define	ATIM_SMCR_TS_ITR2	(0x2U << ATIM_SMCR_TS_Pos)	/* 010：内部触发信号（ITR2） */
#define	ATIM_SMCR_TS_ITR3	(0x3U << ATIM_SMCR_TS_Pos)	/* 011：内部触发信号（ITR3） */
#define	ATIM_SMCR_TS_TI1F_ED	(0x4U << ATIM_SMCR_TS_Pos)	/* 100：TI1边沿检测（TI1F_ED） */
#define	ATIM_SMCR_TS_TI1FP1	(0x5U << ATIM_SMCR_TS_Pos)	/* 101：滤波后TI1（TI1FP1） */
#define	ATIM_SMCR_TS_TI2FP2	(0x6U << ATIM_SMCR_TS_Pos)	/* 110：滤波后TI2（TI2FP2） */
#define	ATIM_SMCR_TS_ETRF	(0x7U << ATIM_SMCR_TS_Pos)	/* 111：外部触发输入（ETRF） */

#define	ATIM_SMCR_SMS_Pos	0	/* 从机模式选择 */
#define	ATIM_SMCR_SMS_Msk	(0x7U << ATIM_SMCR_SMS_Pos)
#define	ATIM_SMCR_SMS_SLAVE_DIS	(0x0U << ATIM_SMCR_SMS_Pos)	/* 000：从机模式禁止；CEN使能后预分频电路时钟源来自内部时钟 */
#define	ATIM_SMCR_SMS_ENCODER1	(0x1U << ATIM_SMCR_SMS_Pos)	/* 001：Encoder模式1；计数器使用TI2FP2边沿，根据TI1电平高低来计数 */
#define	ATIM_SMCR_SMS_ENCODER2	(0x2U << ATIM_SMCR_SMS_Pos)	/* 010：Encoder模式2；计数器使用TI1FP1边沿，根据TI2电平高低来计数 */
#define	ATIM_SMCR_SMS_ENCODER3	(0x3U << ATIM_SMCR_SMS_Pos)	/* 011：Encoder模式3；计数器同时使用TI1FP1和TI2FP2边沿，根据其他输入信号电平来计数 */
#define	ATIM_SMCR_SMS_RESET	(0x4U << ATIM_SMCR_SMS_Pos)	/* 100：复位模式；TRGI上升沿初始化计数器，并触发寄存器update */
#define	ATIM_SMCR_SMS_GATE	(0x5U << ATIM_SMCR_SMS_Pos)	/* 101：闸门模式；TRGI为高电平时，计数时钟使能，TRGI为低电平时，计数时钟停止 */
#define	ATIM_SMCR_SMS_TRIG	(0x6U << ATIM_SMCR_SMS_Pos)	/* 110：触发模式；TRGI上升沿触发计数器开始计数（不会复位计数器） */
#define	ATIM_SMCR_SMS_EXCLK	(0x7U << ATIM_SMCR_SMS_Pos)	/* 111：外部时钟模式1；TRGI上升沿直接驱动计数器 */

#define	ATIM_DIER_CC4BURSTEN_Pos	19	/* 捕捉比较通道4的DMA模式配置 */
#define	ATIM_DIER_CC4BURSTEN_Msk	(0x1U << ATIM_DIER_CC4BURSTEN_Pos)
#define	ATIM_DIER_CC4BURSTEN_SINGLE	(0x0U << ATIM_DIER_CC4BURSTEN_Pos)	/* 0：Single模式，仅访问CCR */
#define	ATIM_DIER_CC4BURSTEN_BURST	(0x1U << ATIM_DIER_CC4BURSTEN_Pos)	/* 1：Burst模式，通过DCR配置访问的地址和长度 */

#define	ATIM_DIER_CC3BURSTEN_Pos	18	/* 捕捉比较通道3的DMA模式配置 */
#define	ATIM_DIER_CC3BURSTEN_Msk	(0x1U << ATIM_DIER_CC3BURSTEN_Pos)
#define	ATIM_DIER_CC3BURSTEN_SINGLE	(0x0U << ATIM_DIER_CC3BURSTEN_Pos)	/* 0：Single模式，仅访问CCR */
#define	ATIM_DIER_CC3BURSTEN_BURST	(0x1U << ATIM_DIER_CC3BURSTEN_Pos)	/* 1：Burst模式，通过DCR配置访问的地址和长度 */

#define	ATIM_DIER_CC2BURSTEN_Pos	17	/* 捕捉比较通道2的DMA模式配置 */
#define	ATIM_DIER_CC2BURSTEN_Msk	(0x1U << ATIM_DIER_CC2BURSTEN_Pos)
#define	ATIM_DIER_CC2BURSTEN_SINGLE	(0x0U << ATIM_DIER_CC2BURSTEN_Pos)	/* 0：Single模式，仅访问CCR */
#define	ATIM_DIER_CC2BURSTEN_BURST	(0x1U << ATIM_DIER_CC2BURSTEN_Pos)	/* 1：Burst模式，通过DCR配置访问的地址和长度 */

#define	ATIM_DIER_CC1BURSTEN_Pos	16	/* 捕捉比较通道1的DMA模式配置 */
#define	ATIM_DIER_CC1BURSTEN_Msk	(0x1U << ATIM_DIER_CC1BURSTEN_Pos)
#define	ATIM_DIER_CC1BURSTEN_SINGLE	(0x0U << ATIM_DIER_CC1BURSTEN_Pos)	/* 0：Single模式，仅访问CCR */
#define	ATIM_DIER_CC1BURSTEN_BURST	(0x1U << ATIM_DIER_CC1BURSTEN_Pos)	/* 1：Burst模式，通过DCR配置访问的地址和长度 */

#define	ATIM_DIER_TDE_Pos	14	/* 外部触发DMA请求使能 */
#define	ATIM_DIER_TDE_Msk	(0x1U << ATIM_DIER_TDE_Pos)
	/* 0：从机模式下，禁止外部触发事件产生DMA请求 */
	/* 1：从机模式下，允许外部触发事件产生DMA请求 */

#define	ATIM_DIER_COMDE_Pos	13	/* COM事件DMA请求使能 */
#define	ATIM_DIER_COMDE_Msk	(0x1U << ATIM_DIER_COMDE_Pos)
	/* 0：COM事件发生时，禁止产生DMA请求 */
	/* 1：COM事件发生时，允许产生DMA请求 */

#define	ATIM_DIER_CC4DE_Pos	12	/* 捕捉比较通道4的DMA请求使能 */
#define	ATIM_DIER_CC4DE_Msk	(0x1U << ATIM_DIER_CC4DE_Pos)
	/* 0：禁止CC4 DMA请求 */
	/* 1：允许CC4 DMA请求 */

#define	ATIM_DIER_CC3DE_Pos	11	/* 捕捉比较通道3的DMA请求使能 */
#define	ATIM_DIER_CC3DE_Msk	(0x1U << ATIM_DIER_CC3DE_Pos)
	/* 0：禁止CC3 DMA请求 */
	/* 1：允许CC3 DMA请求 */

#define	ATIM_DIER_CC2DE_Pos	10	/* 捕捉比较通道2的DMA请求使能 */
#define	ATIM_DIER_CC2DE_Msk	(0x1U << ATIM_DIER_CC2DE_Pos)
	/* 0：禁止CC2 DMA请求 */
	/* 1：允许CC2 DMA请求 */

#define	ATIM_DIER_CC1DE_Pos	9	/* 捕捉比较通道1的DMA请求使能 */
#define	ATIM_DIER_CC1DE_Msk	(0x1U << ATIM_DIER_CC1DE_Pos)
	/* 0：禁止CC1 DMA请求 */
	/* 1：允许CC1 DMA请求 */

#define	ATIM_DIER_UDE_Pos	8	/* 更新事件DMA请求使能  */
#define	ATIM_DIER_UDE_Msk	(0x1U << ATIM_DIER_UDE_Pos)
	/* 0：Update Event发生时，禁止产生DMA请求 */
	/* 1：Update Event发生时，允许产生DMA请求 */

#define	ATIM_DIER_BIE_Pos	7	/* 刹车事件中断使能 */
#define	ATIM_DIER_BIE_Msk	(0x1U << ATIM_DIER_BIE_Pos)
	/* 0：禁止刹车事件中断 */
	/* 1：允许刹车事件中断 */

#define	ATIM_DIER_TIE_Pos	6	/* 触发事件中断使能 */
#define	ATIM_DIER_TIE_Msk	(0x1U << ATIM_DIER_TIE_Pos)
	/* 0：禁止触发事件中断 */
	/* 1：允许触发事件中断 */

#define	ATIM_DIER_COMIE_Pos	5	/* COM事件中断使能 */
#define	ATIM_DIER_COMIE_Msk	(0x1U << ATIM_DIER_COMIE_Pos)
	/* 0：禁止COM事件中断 */
	/* 1：允许COM事件中断 */

#define	ATIM_DIER_CC4IE_Pos	4	/* 捕捉/比较通道4中断使能 */
#define	ATIM_DIER_CC4IE_Msk	(0x1U << ATIM_DIER_CC4IE_Pos)
	/* 0：禁止捕捉/比较4中断 */
	/* 1：允许捕捉/比较4中断 */

#define	ATIM_DIER_CC3IE_Pos	3	/* 捕捉/比较通道3中断使能 */
#define	ATIM_DIER_CC3IE_Msk	(0x1U << ATIM_DIER_CC3IE_Pos)
	/* 0：禁止捕捉/比较3中断 */
	/* 1：允许捕捉/比较3中断 */

#define	ATIM_DIER_CC2IE_Pos	2	/* 捕捉/比较通道2中断使能 */
#define	ATIM_DIER_CC2IE_Msk	(0x1U << ATIM_DIER_CC2IE_Pos)
	/* 0：禁止捕捉/比较2中断 */
	/* 1：允许捕捉/比较2中断 */

#define	ATIM_DIER_CC1IE_Pos	1	/* 捕捉/比较通道1中断使能 */
#define	ATIM_DIER_CC1IE_Msk	(0x1U << ATIM_DIER_CC1IE_Pos)
	/* 0：禁止捕捉/比较1中断 */
	/* 1：允许捕捉/比较1中断 */

#define	ATIM_DIER_UIE_Pos	0	/* 更新事件中断使能 */
#define	ATIM_DIER_UIE_Msk	(0x1U << ATIM_DIER_UIE_Pos)
	/* 0：禁止Update事件中断 */
	/* 1：允许Update事件中断 */

#define	ATIM_ISR_CC4OF_Pos	12	/* 捕捉/比较通道4的Overcapture中断 */
#define	ATIM_ISR_CC4OF_Msk	(0x1U << ATIM_ISR_CC4OF_Pos)

#define	ATIM_ISR_CC3OF_Pos	11	/* 捕捉/比较通道3的Overcapture中断 */
#define	ATIM_ISR_CC3OF_Msk	(0x1U << ATIM_ISR_CC3OF_Pos)

#define	ATIM_ISR_CC2OF_Pos	10	/* 捕捉/比较通道2的Overcapture中断 */
#define	ATIM_ISR_CC2OF_Msk	(0x1U << ATIM_ISR_CC2OF_Pos)

#define	ATIM_ISR_CC1OF_Pos	9	/* 捕捉/比较通道1的Overcapture中断，此寄存器仅在对应通道设置为输入捕捉模式的情况下有效。硬件置位，软件写1清零 */
#define	ATIM_ISR_CC1OF_Msk	(0x1U << ATIM_ISR_CC1OF_Pos)

#define	ATIM_ISR_BIF_Pos	7	/* 刹车事件中断标志，硬件置位，软件写1清零 */
#define	ATIM_ISR_BIF_Msk	(0x1U << ATIM_ISR_BIF_Pos)

#define	ATIM_ISR_TIF_Pos	6	/* 触发事件中断标志，硬件置位，软件写1清零 */
#define	ATIM_ISR_TIF_Msk	(0x1U << ATIM_ISR_TIF_Pos)

#define	ATIM_ISR_COMIF_Pos	5	/* COM事件中断标志，硬件置位，软件写1清零 */
#define	ATIM_ISR_COMIF_Msk	(0x1U << ATIM_ISR_COMIF_Pos)

#define	ATIM_ISR_CC4IF_Pos	4	/* 捕捉/比较通道4中断标志，参考CC1IF */
#define	ATIM_ISR_CC4IF_Msk	(0x1U << ATIM_ISR_CC4IF_Pos)

#define	ATIM_ISR_CC3IF_Pos	3	/* 捕捉/比较通道3中断标志，参考CC1IF */
#define	ATIM_ISR_CC3IF_Msk	(0x1U << ATIM_ISR_CC3IF_Pos)

#define	ATIM_ISR_CC2IF_Pos	2	/* 捕捉/比较通道2中断标志，参考CC1IF */
#define	ATIM_ISR_CC2IF_Msk	(0x1U << ATIM_ISR_CC2IF_Pos)

#define	ATIM_ISR_CC1IF_Pos	1	/* 捕捉/比较通道1中断标志，如果CC1通道配置为输出：CC1IF在计数值等于比较值时置位，软件写1清零。如果CC1通道配置为输入：发生捕捉事件时置位，软件写1清零，或者软件读ATIM_CCR1自动清零 */
#define	ATIM_ISR_CC1IF_Msk	(0x1U << ATIM_ISR_CC1IF_Pos)

#define	ATIM_ISR_UIF_Pos	0	/* 更新事件中断标志，硬件置位，软件写1清零 */
#define	ATIM_ISR_UIF_Msk	(0x1U << ATIM_ISR_UIF_Pos)

#define	ATIM_EGR_BG_Pos	7	/* 软件刹车，软件置位此寄存器产生刹车事件，硬件自动清零 */
#define	ATIM_EGR_BG_Msk	(0x1U << ATIM_EGR_BG_Pos)

#define	ATIM_EGR_TIF_Pos	6	/* 软件触发，软件置位此寄存器产生触发事件，硬件自动清零 */
#define	ATIM_EGR_TIF_Msk	(0x1U << ATIM_EGR_TIF_Pos)

#define	ATIM_EGR_COMG_Pos	5	/* 软件COM事件，硬件置位，软件写1清零 */
#define	ATIM_EGR_COMG_Msk	(0x1U << ATIM_EGR_COMG_Pos)

#define	ATIM_EGR_CC4G_Pos	4	/* 捕捉/比较通道4软件触发，参考CC1G */
#define	ATIM_EGR_CC4G_Msk	(0x1U << ATIM_EGR_CC4G_Pos)

#define	ATIM_EGR_CC3G_Pos	3	/* 捕捉/比较通道3软件触发，参考CC1G */
#define	ATIM_EGR_CC3G_Msk	(0x1U << ATIM_EGR_CC3G_Pos)

#define	ATIM_EGR_CC2G_Pos	2	/* 捕捉/比较通道2软件触发，参考CC1G */
#define	ATIM_EGR_CC2G_Msk	(0x1U << ATIM_EGR_CC2G_Pos)

#define	ATIM_EGR_CC1G_Pos	1	/* 捕捉/比较通道1软件触发 */
#define	ATIM_EGR_CC1G_Msk	(0x1U << ATIM_EGR_CC1G_Pos)

#define	ATIM_EGR_UG_Pos	0	/* 软件Update事件，软件置位此寄存器产生Update事件，硬件自动清零 */
#define	ATIM_EGR_UG_Msk	(0x1U << ATIM_EGR_UG_Pos)

#define	ATIM_CCMR1_OC2CE_Pos	15	/* 输出比较2清零使能，参考OC1CE */
#define	ATIM_CCMR1_OC2CE_Msk	(0x1U << ATIM_CCMR1_OC2CE_Pos)

#define	ATIM_CCMR1_OC2M_Pos	12	/* 输出比较2模式配置，参考OC1M */
#define	ATIM_CCMR1_OC2M_Msk	(0x7U << ATIM_CCMR1_OC2M_Pos)
#define	ATIM_CCMR1_OC2M_NONE	(0x0U << ATIM_CCMR1_OC1M_Pos)	/* 000：输出比较寄存器CCR1和计数器CNT的比较结果不会影响输出 */
#define	ATIM_CCMR1_OC2M_HIGH	(0x1U << ATIM_CCMR1_OC1M_Pos)	/* 001：CCR1=CNT时，将OC1REF置高 */
#define	ATIM_CCMR1_OC2M_LOW	(0x2U << ATIM_CCMR1_OC1M_Pos)	/* 010：CCR1=CNT时，将OC1REF置低 */
#define	ATIM_CCMR1_OC2M_TOG	(0x3U << ATIM_CCMR1_OC1M_Pos)	/* 011：CCR1=CNT时，翻转OC1REF */
#define	ATIM_CCMR1_OC2M_INACTIVE	(0x4U << ATIM_CCMR1_OC1M_Pos)	/* 100：OC1REF固定为低（inactive） */
#define	ATIM_CCMR1_OC2M_ACTIVE	(0x5U << ATIM_CCMR1_OC1M_Pos)	/* 101：OC1REF固定为高（active） */
#define	ATIM_CCMR1_OC2M_PWM1	(0x6U << ATIM_CCMR1_OC1M_Pos)	/* 110：PWM模式1 –在向上计数时，OC1REF在CNT<CCR1时置高，否则置低；在向下计数时，OC1REF在CNT>CCR1时置低，否则置高 */
#define	ATIM_CCMR1_OC2M_PWM2	(0x7U << ATIM_CCMR1_OC1M_Pos)	/* 111：PWM模式2 –在向上计数时，OC1REF在CNT<CCR1时置低，否则置高；在向下计数时，OC1REF在CNT>CCR1 时置高，否则置低 */

#define	ATIM_CCMR1_OC2PE_Pos	11	/* 输出比较2预装载使能，参考OC1PE */
#define	ATIM_CCMR1_OC2PE_Msk	(0x1U << ATIM_CCMR1_OC2PE_Pos)

#define	ATIM_CCMR1_OC2FE_Pos	10	/* 输出比较2快速使能，参考OC1FE */
#define	ATIM_CCMR1_OC2FE_Msk	(0x1U << ATIM_CCMR1_OC2FE_Pos)

#define	ATIM_CCMR1_CC2S_Pos	8	/* 捕捉/比较2通道选择 */
#define	ATIM_CCMR1_CC2S_Msk	(0x3U << ATIM_CCMR1_CC2S_Pos)
#define	ATIM_CCMR1_CC2S_OUT	(0x0U << ATIM_CCMR1_CC2S_Pos)	/* 00：CC2通道配置为输出 */
#define	ATIM_CCMR1_CC2S_TI2	(0x1U << ATIM_CCMR1_CC2S_Pos)	/* 01：CC2通道配置为输入，IC2映射到TI2 */
#define	ATIM_CCMR1_CC2S_TI1	(0x2U << ATIM_CCMR1_CC2S_Pos)	/* 10：CC2通道配置为输入，IC2映射到TI1 */
#define	ATIM_CCMR1_CC2S_TRC	(0x3U << ATIM_CCMR1_CC2S_Pos)	/* 11：CC2通道配置为输入，IC2映射到TRC */

#define	ATIM_CCMR1_OC1CE_Pos	7	/* 输出比较1清零使能 */
#define	ATIM_CCMR1_OC1CE_Msk	(0x1U << ATIM_CCMR1_OC1CE_Pos)
	/* 0：OC1REF不受ETRF影响 */
	/* 1：检测到ETRF高电平时，自动清零OC1REF */

#define	ATIM_CCMR1_OC1M_Pos	4	/* 输出比较1模式配置，此寄存器定义OC1REF信号的行为 */
#define	ATIM_CCMR1_OC1M_Msk	(0x7U << ATIM_CCMR1_OC1M_Pos)
#define	ATIM_CCMR1_OC1M_NONE	(0x0U << ATIM_CCMR1_OC1M_Pos)	/* 000：输出比较寄存器CCR1和计数器CNT的比较结果不会影响输出 */
#define	ATIM_CCMR1_OC1M_HIGH	(0x1U << ATIM_CCMR1_OC1M_Pos)	/* 001：CCR1=CNT时，将OC1REF置高 */
#define	ATIM_CCMR1_OC1M_LOW	(0x2U << ATIM_CCMR1_OC1M_Pos)	/* 010：CCR1=CNT时，将OC1REF置低 */
#define	ATIM_CCMR1_OC1M_TOG	(0x3U << ATIM_CCMR1_OC1M_Pos)	/* 011：CCR1=CNT时，翻转OC1REF */
#define	ATIM_CCMR1_OC1M_INACTIVE	(0x4U << ATIM_CCMR1_OC1M_Pos)	/* 100：OC1REF固定为低（inactive） */
#define	ATIM_CCMR1_OC1M_ACTIVE	(0x5U << ATIM_CCMR1_OC1M_Pos)	/* 101：OC1REF固定为高（active） */
#define	ATIM_CCMR1_OC1M_PWM1	(0x6U << ATIM_CCMR1_OC1M_Pos)	/* 110：PWM模式1 –在向上计数时，OC1REF在CNT<CCR1时置高，否则置低；在向下计数时，OC1REF在CNT>CCR1时置低，否则置高 */
#define	ATIM_CCMR1_OC1M_PWM2	(0x7U << ATIM_CCMR1_OC1M_Pos)	/* 111：PWM模式2 –在向上计数时，OC1REF在CNT<CCR1时置低，否则置高；在向下计数时，OC1REF在CNT>CCR1 时置高，否则置低 */

#define	ATIM_CCMR1_OC1PE_Pos	3	/* 输出比较1预装载使能 */
#define	ATIM_CCMR1_OC1PE_Msk	(0x1U << ATIM_CCMR1_OC1PE_Pos)
	/* 0：CCR1 preload寄存器无效，CCR1可以直接写入 */
	/* 1：CCR1 preload寄存器有效，针对CCR1的读写操作都是访问preload寄存器，当update event发生时才将preload寄存器的内容转移到shadow寄存器中 */

#define	ATIM_CCMR1_OC1FE_Pos	2	/* 输出比较1快速使能 */
#define	ATIM_CCMR1_OC1FE_Msk	(0x1U << ATIM_CCMR1_OC1FE_Pos)
	/* 0：关闭快速使能，trigger输入不会影响比较输出 */
	/* 1：打开快速使能，trigger输入会立即将OC1REF改变为比较值匹配时的输出，而不管当前实际比较情况（只用于触发模式） */

#define	ATIM_CCMR1_CC1S_Pos	0	/* 捕捉/比较1通道选择 */
#define	ATIM_CCMR1_CC1S_Msk	(0x3U << ATIM_CCMR1_CC1S_Pos)
#define	ATIM_CCMR1_CC1S_OUT	(0x0U << ATIM_CCMR1_CC1S_Pos)	/* 00：CC1通道配置为输出 */
#define	ATIM_CCMR1_CC1S_TI1	(0x1U << ATIM_CCMR1_CC1S_Pos)	/* 01：CC1通道配置为输入，IC1映射到TI1 */
#define	ATIM_CCMR1_CC1S_TI2	(0x2U << ATIM_CCMR1_CC1S_Pos)	/* 10：CC1通道配置为输入，IC1映射到TI2 */
#define	ATIM_CCMR1_CC1S_TRC	(0x3U << ATIM_CCMR1_CC1S_Pos)	/* 11：CC1通道配置为输入，IC1映射到TRC */

#define	ATIM_CCMR1_IC2F_Pos	12	/* 输入捕捉2滤波 */
#define	ATIM_CCMR1_IC2F_Msk	(0xfU << ATIM_CCMR1_IC2F_Pos)

#define	ATIM_CCMR1_IC2PSC_Pos	10	/* 输入捕捉2预分频 */
#define	ATIM_CCMR1_IC2PSC_Msk	(0x3U << ATIM_CCMR1_IC2PSC_Pos)

#define	ATIM_CCMR1_IC1F_Pos	4	/* 输入捕捉1滤波 */
#define	ATIM_CCMR1_IC1F_Msk	(0xfU << ATIM_CCMR1_IC1F_Pos)
#define	ATIM_CCMR1_IC1F_FILT0	(0x0U << ATIM_CCMR1_IC1F_Pos)	/* 0000：无滤波，使用fDTS采样 */
#define	ATIM_CCMR1_IC1F_FILT1	(0x1U << ATIM_CCMR1_IC1F_Pos)	/* 0001：fSAMPLING=fCK_INT, N=2 */
#define	ATIM_CCMR1_IC1F_FILT2	(0x2U << ATIM_CCMR1_IC1F_Pos)	/* 0010：fSAMPLING=fCK_INT, N=4 */
#define	ATIM_CCMR1_IC1F_FILT3	(0x3U << ATIM_CCMR1_IC1F_Pos)	/* 0011：fSAMPLING=fCK_INT, N=8 */
#define	ATIM_CCMR1_IC1F_FILT4	(0x4U << ATIM_CCMR1_IC1F_Pos)	/* 0100：fSAMPLING=fDTS/2, N=6 */
#define	ATIM_CCMR1_IC1F_FILT5	(0x5U << ATIM_CCMR1_IC1F_Pos)	/* 0101：fSAMPLING=fDTS/2, N=8 */
#define	ATIM_CCMR1_IC1F_FILT6	(0x6U << ATIM_CCMR1_IC1F_Pos)	/* 0110：fSAMPLING=fDTS/4, N=6 */
#define	ATIM_CCMR1_IC1F_FILT7	(0x7U << ATIM_CCMR1_IC1F_Pos)	/* 0111：fSAMPLING=fDTS/4, N=8 */
#define	ATIM_CCMR1_IC1F_FILT8	(0x8U << ATIM_CCMR1_IC1F_Pos)	/* 1000：fSAMPLING=fDTS/8, N=6 */
#define	ATIM_CCMR1_IC1F_FILT9	(0x9U << ATIM_CCMR1_IC1F_Pos)	/* 1001：fSAMPLING=fDTS/8, N=8 */
#define	ATIM_CCMR1_IC1F_FILT10	(0xaU << ATIM_CCMR1_IC1F_Pos)	/* 1010：fSAMPLING=fDTS/16, N=5 */
#define	ATIM_CCMR1_IC1F_FILT11	(0xbU << ATIM_CCMR1_IC1F_Pos)	/* 1011：fSAMPLING=fDTS/16, N=6 */
#define	ATIM_CCMR1_IC1F_FILT12	(0xcU << ATIM_CCMR1_IC1F_Pos)	/* 1100：fSAMPLING=fDTS/16, N=8 */
#define	ATIM_CCMR1_IC1F_FILT13	(0xdU << ATIM_CCMR1_IC1F_Pos)	/* 1101：fSAMPLING=fDTS/32, N=5 */
#define	ATIM_CCMR1_IC1F_FILT14	(0xeU << ATIM_CCMR1_IC1F_Pos)	/* 1110：fSAMPLING=fDTS/32, N=6 */
#define	ATIM_CCMR1_IC1F_FILT15	(0xfU << ATIM_CCMR1_IC1F_Pos)	/* 1111：fSAMPLING=fDTS/32, N=8 */

#define	ATIM_CCMR1_IC1PSC_Pos	2	/* 输入捕捉1预分频 */
#define	ATIM_CCMR1_IC1PSC_Msk	(0x3U << ATIM_CCMR1_IC1PSC_Pos)
#define	ATIM_CCMR1_IC1PSC_DIV1	(0x0U << ATIM_CCMR1_IC1PSC_Pos)	/* 00：无分频 */
#define	ATIM_CCMR1_IC1PSC_DIV2	(0x1U << ATIM_CCMR1_IC1PSC_Pos)	/* 01：每2个事件输入产生一次捕捉 */
#define	ATIM_CCMR1_IC1PSC_DIV4	(0x2U << ATIM_CCMR1_IC1PSC_Pos)	/* 10：每4个事件输入产生一次捕捉 */
#define	ATIM_CCMR1_IC1PSC_DIV8	(0x3U << ATIM_CCMR1_IC1PSC_Pos)	/* 11：每8个事件输入产生一次捕捉 */


#define	ATIM_CCMR2_OC4CE_Pos	15	/* 输出比较4清零使能，参考OC1CE */
#define	ATIM_CCMR2_OC4CE_Msk	(0x1U << ATIM_CCMR2_OC4CE_Pos)

#define	ATIM_CCMR2_OC4M_Pos	12
#define	ATIM_CCMR2_OC4M_Msk	(0x7U << ATIM_CCMR2_OC4M_Pos)
#define	ATIM_CCMR1_OC4M_NONE	(0x0U << ATIM_CCMR1_OC1M_Pos)	/* 000：输出比较寄存器CCR1和计数器CNT的比较结果不会影响输出 */
#define	ATIM_CCMR1_OC4M_HIGH	(0x1U << ATIM_CCMR1_OC1M_Pos)	/* 001：CCR1=CNT时，将OC1REF置高 */
#define	ATIM_CCMR1_OC4M_LOW	(0x2U << ATIM_CCMR1_OC1M_Pos)	/* 010：CCR1=CNT时，将OC1REF置低 */
#define	ATIM_CCMR1_OC4M_TOG	(0x3U << ATIM_CCMR1_OC1M_Pos)	/* 011：CCR1=CNT时，翻转OC1REF */
#define	ATIM_CCMR1_OC4M_INACTIVE	(0x4U << ATIM_CCMR1_OC1M_Pos)	/* 100：OC1REF固定为低（inactive） */
#define	ATIM_CCMR1_OC4M_ACTIVE	(0x5U << ATIM_CCMR1_OC1M_Pos)	/* 101：OC1REF固定为高（active） */
#define	ATIM_CCMR1_OC4M_PWM1	(0x6U << ATIM_CCMR1_OC1M_Pos)	/* 110：PWM模式1 –在向上计数时，OC1REF在CNT<CCR1时置高，否则置低；在向下计数时，OC1REF在CNT>CCR1时置低，否则置高 */
#define	ATIM_CCMR1_OC4M_PWM2	(0x7U << ATIM_CCMR1_OC1M_Pos)	/* 111：PWM模式2 –在向上计数时，OC1REF在CNT<CCR1时置低，否则置高；在向下计数时，OC1REF在CNT>CCR1 时置高，否则置低 */

#define	ATIM_CCMR2_OC4PE_Pos	11	/* 输出比较4预装载使能，参考OC1PE */
#define	ATIM_CCMR2_OC4PE_Msk	(0x1U << ATIM_CCMR2_OC4PE_Pos)

#define	ATIM_CCMR2_OC4FE_Pos	10	/* 输出比较4快速使能，参考OC1FE */
#define	ATIM_CCMR2_OC4FE_Msk	(0x1U << ATIM_CCMR2_OC4FE_Pos)

#define	ATIM_CCMR2_CC4S_Pos	8	/* 捕捉/比较4通道选择 */
#define	ATIM_CCMR2_CC4S_Msk	(0x3U << ATIM_CCMR2_CC4S_Pos)
#define	ATIM_CCMR2_CC4S_OUT	(0x0U << ATIM_CCMR2_CC4S_Pos)	/* 00：CC4通道配置为输出 */
#define	ATIM_CCMR2_CC4S_TI4	(0x1U << ATIM_CCMR2_CC4S_Pos)	/* 01：CC4通道配置为输入，IC4映射到TI4 */
#define	ATIM_CCMR2_CC4S_TI3	(0x2U << ATIM_CCMR2_CC4S_Pos)	/* 10：CC4通道配置为输入，IC4映射到TI3 */
#define	ATIM_CCMR2_CC4S_TRC	(0x3U << ATIM_CCMR2_CC4S_Pos)	/* 11：CC4通道配置为输入，IC4映射到TRC */

#define	ATIM_CCMR2_OC3CE_Pos	7	/* 输出比较1清零使能 */
#define	ATIM_CCMR2_OC3CE_Msk	(0x1U << ATIM_CCMR2_OC3CE_Pos)
	/* 0：OC1REF不受ETRF影响 */
	/* 1：检测到ETRF高电平时，自动清零OC1REF */

#define	ATIM_CCMR2_OC3M_Pos	4	/* 输出比较3模式配置，此寄存器定义OC3REF信号的行为 */
#define	ATIM_CCMR2_OC3M_Msk	(0x7U << ATIM_CCMR2_OC3M_Pos)
#define	ATIM_CCMR2_OC3M_NONE	(0x0U << ATIM_CCMR2_OC3M_Pos)	/* 000：输出比较寄存器CCR3和计数器CNT的比较结果不会影响输出 */
#define	ATIM_CCMR2_OC3M_HIGH	(0x1U << ATIM_CCMR2_OC3M_Pos)	/* 001：CCR3=CNT时，将OC1REF置高 */
#define	ATIM_CCMR2_OC3M_LOW	(0x2U << ATIM_CCMR2_OC3M_Pos)	/* 010：CCR3=CNT时，将OC1REF置低 */
#define	ATIM_CCMR2_OC3M_TOG	(0x3U << ATIM_CCMR2_OC3M_Pos)	/* 011：CCR3=CNT时，翻转OC1REF */
#define	ATIM_CCMR2_OC3M_INACTIVE	(0x4U << ATIM_CCMR2_OC3M_Pos)	/* 100：OC3REF固定为低（inactive） */
#define	ATIM_CCMR2_OC3M_ACTIVE	(0x5U << ATIM_CCMR2_OC3M_Pos)	/* 101：OC3REF固定为高（active） */
#define	ATIM_CCMR2_OC3M_PWM1	(0x6U << ATIM_CCMR2_OC3M_Pos)	/* 110：PWM模式1 –在向上计数时，OC3REF在CNT<CCR3时置高，否则置低；在向下计数时，OC3REF在CNT>CCR3时置低，否则置高 */
#define	ATIM_CCMR2_OC3M_PWM2	(0x7U << ATIM_CCMR2_OC3M_Pos)	/* 111：PWM模式2 –在向上计数时，OC3REF在CNT<CCR3时置低，否则置高；在向下计数时，OC3REF在CNT>CCR3 时置高，否则置低 */

#define	ATIM_CCMR2_OC3PE_Pos	3	/* 输出比较3预装载使能 */
#define	ATIM_CCMR2_OC3PE_Msk	(0x1U << ATIM_CCMR2_OC3PE_Pos)
	/* 0：CCR3 preload寄存器无效，CCR3可以直接写入 */
	/* 1：CCR3 preload寄存器有效，针对CCR3的读写操作都是访问preload寄存器，当update event发生时才将preload寄存器的内容转移到shadow寄存器中 */

#define	ATIM_CCMR2_OC3FE_Pos	2	/* 输出比较3快速使能 */
#define	ATIM_CCMR2_OC3FE_Msk	(0x1U << ATIM_CCMR2_OC3FE_Pos)
	/* 0：关闭快速使能，trigger输入不会影响比较输出 */
	/* 1：打开快速使能，trigger输入会立即将OC3REF改变为比较值匹配时的输出，而不管当前实际比较情况 */

#define	ATIM_CCMR2_CC3S_Pos	0	/* 捕捉/比较3通道选择 */
#define	ATIM_CCMR2_CC3S_Msk	(0x3U << ATIM_CCMR2_CC3S_Pos)
#define	ATIM_CCMR2_CC3S_OUT	(0x0U << ATIM_CCMR2_CC3S_Pos)	/* 00：CC3通道配置为输出 */
#define	ATIM_CCMR2_CC3S_TI3	(0x1U << ATIM_CCMR2_CC3S_Pos)	/* 01：CC3通道配置为输入，IC1映射到TI3 */
#define	ATIM_CCMR2_CC3S_TI4	(0x2U << ATIM_CCMR2_CC3S_Pos)	/* 10：CC3通道配置为输入，IC1映射到TI4 */
#define	ATIM_CCMR2_CC3S_TRC	(0x3U << ATIM_CCMR2_CC3S_Pos)	/* 11：CC3通道配置为输入，IC1映射到TRC */

#define	ATIM_CCMR2_IC4F_Pos	12	/* 输入捕捉4滤波 */
#define	ATIM_CCMR2_IC4F_Msk	(0xfU << ATIM_CCMR2_IC4F_Pos)

#define	ATIM_CCMR2_IC4PSC_Pos	10	/* 输入捕捉4预分频 */
#define	ATIM_CCMR2_IC4PSC_Msk	(0x3U << ATIM_CCMR2_IC4PSC_Pos)

#define	ATIM_CCMR2_IC3F_Pos	4	/* 输入捕捉3滤波 */
#define	ATIM_CCMR2_IC3F_Msk	(0xfU << ATIM_CCMR2_IC3F_Pos)
#define	ATIM_CCMR2_IC3F_FILT0	(0x0U << ATIM_CCMR2_IC3F_Pos)	/* 0000：无滤波，使用fDTS采样 */
#define	ATIM_CCMR2_IC3F_FILT1	(0x1U << ATIM_CCMR2_IC3F_Pos)	/* 0001：fSAMPLING=fCK_INT, N=2 */
#define	ATIM_CCMR2_IC3F_FILT2	(0x2U << ATIM_CCMR2_IC3F_Pos)	/* 0010：fSAMPLING=fCK_INT, N=4 */
#define	ATIM_CCMR2_IC3F_FILT3	(0x3U << ATIM_CCMR2_IC3F_Pos)	/* 0011：fSAMPLING=fCK_INT, N=8 */
#define	ATIM_CCMR2_IC3F_FILT4	(0x4U << ATIM_CCMR2_IC3F_Pos)	/* 0100：fSAMPLING=fDTS/2, N=6 */
#define	ATIM_CCMR2_IC3F_FILT5	(0x5U << ATIM_CCMR2_IC3F_Pos)	/* 0101：fSAMPLING=fDTS/2, N=8 */
#define	ATIM_CCMR2_IC3F_FILT6	(0x6U << ATIM_CCMR2_IC3F_Pos)	/* 0110：fSAMPLING=fDTS/4, N=6 */
#define	ATIM_CCMR2_IC3F_FILT7	(0x7U << ATIM_CCMR2_IC3F_Pos)	/* 0111：fSAMPLING=fDTS/4, N=8 */
#define	ATIM_CCMR2_IC3F_FILT8	(0x8U << ATIM_CCMR2_IC3F_Pos)	/* 1000：fSAMPLING=fDTS/8, N=6 */
#define	ATIM_CCMR2_IC3F_FILT9	(0x9U << ATIM_CCMR2_IC3F_Pos)	/* 1001：fSAMPLING=fDTS/8, N=8 */
#define	ATIM_CCMR2_IC3F_FILT10	(0xaU << ATIM_CCMR2_IC3F_Pos)	/* 1010：fSAMPLING=fDTS/16, N=5 */
#define	ATIM_CCMR2_IC3F_FILT11	(0xbU << ATIM_CCMR2_IC3F_Pos)	/* 1011：fSAMPLING=fDTS/16, N=6 */
#define	ATIM_CCMR2_IC3F_FILT12	(0xcU << ATIM_CCMR2_IC3F_Pos)	/* 1100：fSAMPLING=fDTS/16, N=8 */
#define	ATIM_CCMR2_IC3F_FILT13	(0xdU << ATIM_CCMR2_IC3F_Pos)	/* 1101：fSAMPLING=fDTS/32, N=5 */
#define	ATIM_CCMR2_IC3F_FILT14	(0xeU << ATIM_CCMR2_IC3F_Pos)	/* 1110：fSAMPLING=fDTS/32, N=6 */
#define	ATIM_CCMR2_IC3F_FILT15	(0xfU << ATIM_CCMR2_IC3F_Pos)	/* 1111：fSAMPLING=fDTS/32, N=8 */

#define	ATIM_CCMR2_IC3PSC_Pos	2	/* 输入捕捉3预分频 */
#define	ATIM_CCMR2_IC3PSC_Msk	(0x3U << ATIM_CCMR2_IC3PSC_Pos)
#define	ATIM_CCMR2_IC3PSC_DIV1	(0x0U << ATIM_CCMR2_IC3PSC_Pos)	/* 00：无分频 */
#define	ATIM_CCMR2_IC3PSC_DIV2	(0x1U << ATIM_CCMR2_IC3PSC_Pos)	/* 01：每2个事件输入产生一次捕捉 */
#define	ATIM_CCMR2_IC3PSC_DIV4	(0x2U << ATIM_CCMR2_IC3PSC_Pos)	/* 10：每4个事件输入产生一次捕捉 */
#define	ATIM_CCMR2_IC3PSC_DIV8	(0x3U << ATIM_CCMR2_IC3PSC_Pos)	/* 11：每8个事件输入产生一次捕捉 */

#define	ATIM_CCER_CC4P_Pos	13	/* 捕捉/比较4输出极性，参考CC1P */
#define	ATIM_CCER_CC4P_Msk	(0x1U << ATIM_CCER_CC4P_Pos)
#define	ATIM_CCER_CC4P_HIGH	(0x0U << ATIM_CCER_CC4P_Pos)
#define	ATIM_CCER_CC4P_LOW	(0x1U << ATIM_CCER_CC4P_Pos)

#define	ATIM_CCER_CC4E_Pos	12	/* 捕捉/比较4输出使能，参考CC1E */
#define	ATIM_CCER_CC4E_Msk	(0x1U << ATIM_CCER_CC4E_Pos)

#define	ATIM_CCER_CC3NP_Pos	11	/* 捕捉/比较3互补输出极性，参考CC1NP */
#define	ATIM_CCER_CC3NP_Msk	(0x1U << ATIM_CCER_CC3NP_Pos)
#define	ATIM_CCER_CC3NP_HIGH	(0x0U << ATIM_CCER_CC3NP_Pos)
#define	ATIM_CCER_CC3NP_LOW	(0x1U << ATIM_CCER_CC3NP_Pos)

#define	ATIM_CCER_CC3NE_Pos	10	/* 捕捉/比较3互补输出使能，参考CC1NE */
#define	ATIM_CCER_CC3NE_Msk	(0x1U << ATIM_CCER_CC3NE_Pos)

#define	ATIM_CCER_CC3P_Pos	9	/* 捕捉/比较3输出极性，参考CC1P */
#define	ATIM_CCER_CC3P_Msk	(0x1U << ATIM_CCER_CC3P_Pos)
#define	ATIM_CCER_CC3P_HIGH	(0x0U << ATIM_CCER_CC3P_Pos)
#define	ATIM_CCER_CC3P_LOW	(0x1U << ATIM_CCER_CC3P_Pos)

#define	ATIM_CCER_CC3E_Pos	8	/* 捕捉/比较3输出使能，参考CC1E */
#define	ATIM_CCER_CC3E_Msk	(0x1U << ATIM_CCER_CC3E_Pos)

#define	ATIM_CCER_CC2NP_Pos	7	/* 捕捉/比较2互补输出极性，参考CC1NP */
#define	ATIM_CCER_CC2NP_Msk	(0x1U << ATIM_CCER_CC2NP_Pos)
#define	ATIM_CCER_CC2NP_HIGH	(0x0U << ATIM_CCER_CC2NP_Pos)
#define	ATIM_CCER_CC2NP_LOW	(0x1U << ATIM_CCER_CC2NP_Pos)

#define	ATIM_CCER_CC2NE_Pos	6	/* 捕捉/比较2互补输出使能，参考CC1NE */
#define	ATIM_CCER_CC2NE_Msk	(0x1U << ATIM_CCER_CC2NE_Pos)

#define	ATIM_CCER_CC2P_Pos	5	/* 捕捉/比较2输出极性，参考CC1P */
#define	ATIM_CCER_CC2P_Msk	(0x1U << ATIM_CCER_CC2P_Pos)
#define	ATIM_CCER_CC2P_HIGH	(0x0U << ATIM_CCER_CC2P_Pos)
#define	ATIM_CCER_CC2P_LOW	(0x1U << ATIM_CCER_CC2P_Pos)

#define	ATIM_CCER_CC2E_Pos	4	/* 捕捉/比较2输出使能，参考CC1E */
#define	ATIM_CCER_CC2E_Msk	(0x1U << ATIM_CCER_CC2E_Pos)

#define	ATIM_CCER_CC1NP_Pos	3	/* 捕捉/比较1互补输出极性 */
#define	ATIM_CCER_CC1NP_Msk	(0x1U << ATIM_CCER_CC1NP_Pos)
#define	ATIM_CCER_CC1NP_HIGH	(0x0U << ATIM_CCER_CC1NP_Pos)	/* 0：OC1N高电平为active */
#define	ATIM_CCER_CC1NP_LOW	(0x1U << ATIM_CCER_CC1NP_Pos)	/* 1：OC1N低电平为active */

#define	ATIM_CCER_CC1NE_Pos	2	/* 捕捉/比较1互补输出使能 */
#define	ATIM_CCER_CC1NE_Msk	(0x1U << ATIM_CCER_CC1NE_Pos)
	/* 0：OC1N无效，OC1N电平由MOE, OSSI, OSSR, OIS1, OIS1N, CC1E寄存器决定 */

#define	ATIM_CCER_CC1P_Pos	1	/* 捕捉/比较1输出极性 (CC1 Polarity)
CC1通道配置为输出时
0：OC1高电平active
1：OC1低电平active
CC1通道配置为输入时
0：非取反模式–捕捉在IC1的上升沿进行
1：取反模式–捕捉在IC1的下降沿进行 */
#define	ATIM_CCER_CC1P_Msk	(0x1U << ATIM_CCER_CC1P_Pos)
#define	ATIM_CCER_CC1P_HIGH	(0x0U << ATIM_CCER_CC1P_Pos)
#define	ATIM_CCER_CC1P_LOW	(0x1U << ATIM_CCER_CC1P_Pos)

#define	ATIM_CCER_CC1E_Pos	0	/* 捕捉/比较1输出使能 (CC1 Enable)
CC1通道配置为输出时
0：OC1不active
1：OC1 active
CC1通道配置为输入时
0：关闭捕捉功能
1：使能捕捉功能 */
#define	ATIM_CCER_CC1E_Msk	(0x1U << ATIM_CCER_CC1E_Pos)


#define	ATIM_CNT_CNT_Pos	0	/* 计数器值 */
#define	ATIM_CNT_CNT_Msk	(0xffffU << ATIM_CNT_CNT_Pos)

#define	ATIM_PSC_PSC_Pos	0	/* 计数器时钟预分频值
fCK_CNT=fCK_PSC/(PSC[15:0]+1)
这是一个preload寄存器，在update事件发生时其内容被载入shadow寄存器 */
#define	ATIM_PSC_PSC_Msk	(0xffffU << ATIM_PSC_PSC_Pos)

#define	ATIM_ARR_ARR_Pos	0	/* 计数溢出时的自动重载值 
这是一个preload寄存器，在update事件发生时其内容被载入shadow寄存器 */
#define	ATIM_ARR_ARR_Msk	(0xffffU << ATIM_ARR_ARR_Pos)

#define	ATIM_RCR_REP_Pos	0	/* 重复计数值  */
#define	ATIM_RCR_REP_Msk	(0xffU << ATIM_RCR_REP_Pos)

#define	ATIM_CCR1_CCR1_Pos	0	/* 捕捉/比较通道1寄存器 
如果通道1配置为输出：
这是一个preload寄存器，其内容被载入shadow寄存器后用于与计数器比较产生OC1输出
如果通道1配置为输入：
CCR1保存最近一次输入捕捉事件发生时的计数器值，此时CCR1为只读 */
#define	ATIM_CCR1_CCR1_Msk	(0xffffU << ATIM_CCR1_CCR1_Pos)

#define	ATIM_CCR2_CCR2_Pos	0	/* 捕捉/比较通道2寄存器 
如果通道2配置为输出：
这是一个preload寄存器，其内容被载入shadow寄存器后用于与计数器比较产生OC2输出
如果通道2配置为输入：
CCR2保存最近一次输入捕捉事件发生时的计数器值，此时CCR2为只读 */
#define	ATIM_CCR2_CCR2_Msk	(0xffffU << ATIM_CCR2_CCR2_Pos)

#define	ATIM_CCR3_CCR3_Pos	0	/* 捕捉/比较通道3寄存器 
如果通道3配置为输出：
这是一个preload寄存器，其内容被载入shadow寄存器后用于与计数器比较产生OC3输出
如果通道3配置为输入：
CCR3保存最近一次输入捕捉事件发生时的计数器值，此时CCR3为只读 */
#define	ATIM_CCR3_CCR3_Msk	(0xffffU << ATIM_CCR3_CCR3_Pos)

#define	ATIM_CCR4_CCR4_Pos	0	/* 捕捉/比较通道4寄存器 
如果通道4配置为输出：
这是一个preload寄存器，其内容被载入shadow寄存器后用于与计数器比较产生OC4输出
如果通道4配置为输入：
CCR4保存最近一次输入捕捉事件发生时的计数器值，此时CCR4为只读 */
#define	ATIM_CCR4_CCR4_Msk	(0xffffU << ATIM_CCR4_CCR4_Pos)

#define	ATIM_BDTR_MOE_Pos	15	/* 输出使能主控 */
#define	ATIM_BDTR_MOE_Msk	(0x1U << ATIM_BDTR_MOE_Pos)
	/* 0：关闭OC和OCN输出，具体IO输出状态由OSSI决定 */
	/* 1：使能OC和OCN输出 */

#define	ATIM_BDTR_AOE_Pos	14	/* 自动输出使能 */
#define	ATIM_BDTR_AOE_Msk	(0x1U << ATIM_BDTR_AOE_Pos)
#define	ATIM_BDTR_AOE_SOFT	     (0x0U << ATIM_BDTR_AOE_Pos)	/* 0：MOE仅能由软件置位 */
#define	ATIM_BDTR_AOE_SOFTAEVENT (0x1U << ATIM_BDTR_AOE_Pos)	/* 1：MOE可以软件置位，或者由update事件自动置位 */

#define	ATIM_BDTR_BKP_Pos	13
#define	ATIM_BDTR_BKP_Msk	(0x1U << ATIM_BDTR_BKP_Pos)
#define	ATIM_BDTR_BKP_LOW	(0x0U << ATIM_BDTR_BKP_Pos)
#define	ATIM_BDTR_BKP_HIGH	(0x1U << ATIM_BDTR_BKP_Pos)

#define	ATIM_BDTR_BKE_Pos	12
#define	ATIM_BDTR_BKE_Msk	(0x1U << ATIM_BDTR_BKE_Pos)

#define	ATIM_BDTR_OSSR_Pos	11
#define	ATIM_BDTR_OSSR_Msk	(0x1U << ATIM_BDTR_OSSR_Pos)
#define	ATIM_BDTR_OSSR_NO_GPIO	(0x0U << ATIM_BDTR_OSSR_Pos)
#define	ATIM_BDTR_OSSR_GPIO	(0x1U << ATIM_BDTR_OSSR_Pos)

#define	ATIM_BDTR_OSSI_Pos	10
#define	ATIM_BDTR_OSSI_Msk	(0x1U << ATIM_BDTR_OSSI_Pos)
#define	ATIM_BDTR_OSSI_NO_GPIO	(0x0U << ATIM_BDTR_OSSI_Pos)
#define	ATIM_BDTR_OSSI_GPIO	(0x1U << ATIM_BDTR_OSSI_Pos)

#define	ATIM_BDTR_LOCK_Pos	8	/* 寄存器写保护配置 */
#define	ATIM_BDTR_LOCK_Msk	(0x3U << ATIM_BDTR_LOCK_Pos)
#define	ATIM_BDTR_LOCK_NONE	(0x0U << ATIM_BDTR_LOCK_Pos)	/* 00：无写保护 */
#define	ATIM_BDTR_LOCK_PROTECT1	(0x1U << ATIM_BDTR_LOCK_Pos)	/* 01：保护等级1 – DTG, OISx, OISxN, BKE, BKP, AOE不能改写 */
#define	ATIM_BDTR_LOCK_PROTECT2	(0x2U << ATIM_BDTR_LOCK_Pos)	/* 10：保护等级2 –在等级1基础上，CCxP, CCxNP, OSSR, OSSI不能改写 */
#define	ATIM_BDTR_LOCK_PROTECT3	(0x3U << ATIM_BDTR_LOCK_Pos)	/* 11：保护等级3 –在等级2基础上，OCxM, OcxPE在相应通道配置为输出时不能改写 */

#define	ATIM_BDTR_DTG_Pos	0	/* 死区时间插入，用于配置互补输出插入的死区时间长度 */
#define	ATIM_BDTR_DTG_Msk	(0xffU << ATIM_BDTR_DTG_Pos)
#define	ATIM_BDTR_DTG_N_DTG	(0x0U << ATIM_BDTR_DTG_Pos)	/* DTG[7:5]=0xx：DT=DTG[7:0] * tDTS */
#define	ATIM_BDTR_DTG_64_DTG_2T	(0x4U << ATIM_BDTR_DTG_Pos)	/* DTG[7:5]=10x：DT=(64+DTG[5:0]) * 2 * tDTS */
#define	ATIM_BDTR_DTG_32_DTG_8T	(0x6U << ATIM_BDTR_DTG_Pos)	/* DTG[7:5]=110：DT=(32+DTG[4:0]) * 8 * tDTS */
#define	ATIM_BDTR_DTG_32_DTG_16T	(0x7U << ATIM_BDTR_DTG_Pos)	/* DTG[7:5]=111：DT=(32+DTG[4:0]) * 16 * tDTS */

#define	ATIM_DCR_DBL_Pos	8	/* DMA Burst长度 */
#define	ATIM_DCR_DBL_Msk	(0x1fU << ATIM_DCR_DBL_Pos)

#define	ATIM_DCR_DBA_Pos	0	/* DMA基地址，定义指向寄存器的偏移地址 */
#define	ATIM_DCR_DBA_Msk	(0x1fU << ATIM_DCR_DBA_Pos)
#define	ATIM_DCR_DBA_ATIM_CR1	(0x0U << ATIM_DCR_DBA_Pos)	/* 00000：ATIM_CR1 */
#define	ATIM_DCR_DBA_ATIM_CR2	(0x1U << ATIM_DCR_DBA_Pos)	/* 00001：ATIM_CR2 */
#define	ATIM_DCR_DBA_ATIM_SMCR	(0x2U << ATIM_DCR_DBA_Pos)	/* 00010：ATIM_SMCR */

#define	ATIM_DMAR_DMAR_Pos	0	/* DMA burst访问寄存器
在使用DMA burst传输时，将DMA通道外设地址设置为ATIM_DMAR，ATIM会根据DBL的值产生多次DMA请求 */
#define	ATIM_DMAR_DMAR_Msk	(0xffffffffU << ATIM_DMAR_DMAR_Pos)

#define	ATIM_BKCR_BRK2GATE_Pos	9	/* ATIM_BRK2引脚输入门控信号 */
#define	ATIM_BKCR_BRK2GATE_Msk	(0x1U << ATIM_BKCR_BRK2GATE_Pos)
#define	ATIM_BKCR_BRK2GATE_ZERO	(0x0U << ATIM_BKCR_BRK2GATE_Pos)	/* 0：将ATIM_BRK2的输入门控成0 */
#define	ATIM_BKCR_BRK2GATE_NO_CR	(0x1U << ATIM_BKCR_BRK2GATE_Pos)	/* 1：不门控 */

#define	ATIM_BKCR_BRK1GATE_Pos	8	/* ATIM_BRK1引脚输入门控信号 */
#define	ATIM_BKCR_BRK1GATE_Msk	(0x1U << ATIM_BKCR_BRK1GATE_Pos)
#define	ATIM_BKCR_BRK1GATE_ZERO	(0x0U << ATIM_BKCR_BRK1GATE_Pos)	/* 0：将ATIM_BRK1的输入门控成0 */
#define	ATIM_BKCR_BRK1GATE_NO_CR	(0x1U << ATIM_BKCR_BRK1GATE_Pos)	/* 1：不门控 */

#define	ATIM_BKCR_BRKF_Pos	4	/* 刹车信号的滤波时钟和长度选择  */
#define	ATIM_BKCR_BRKF_Msk	(0xfU << ATIM_BKCR_BRKF_Pos)
#define	ATIM_BKCR_BRKF_FILT0	(0x0U << ATIM_BKCR_BRKF_Pos)	/* 0000：无滤波 */
#define	ATIM_BKCR_BRKF_FILT1	(0x1U << ATIM_BKCR_BRKF_Pos)	/* 0001：fSAMPLING=fCK_INT, N=2 */
#define	ATIM_BKCR_BRKF_FILT2	(0x2U << ATIM_BKCR_BRKF_Pos)	/* 0010：fSAMPLING=fCK_INT, N=4 */
#define	ATIM_BKCR_BRKF_FILT3	(0x3U << ATIM_BKCR_BRKF_Pos)	/* 0011：fSAMPLING=fCK_INT, N=8 */
#define	ATIM_BKCR_BRKF_FILT4	(0x4U << ATIM_BKCR_BRKF_Pos)	/* 0100：fSAMPLING=fDTS/2, N=6 */
#define	ATIM_BKCR_BRKF_FILT5	(0x5U << ATIM_BKCR_BRKF_Pos)	/* 0101：fSAMPLING=fDTS/2, N=8 */
#define	ATIM_BKCR_BRKF_FILT6	(0x6U << ATIM_BKCR_BRKF_Pos)	/* 0110：fSAMPLING=fDTS/4, N=6 */
#define	ATIM_BKCR_BRKF_FILT7	(0x7U << ATIM_BKCR_BRKF_Pos)	/* 0111：fSAMPLING=fDTS/4, N=8 */
#define	ATIM_BKCR_BRKF_FILT8	(0x8U << ATIM_BKCR_BRKF_Pos)	/* 1000：fSAMPLING=fDTS/8, N=6 */
#define	ATIM_BKCR_BRKF_FILT9	(0x9U << ATIM_BKCR_BRKF_Pos)	/* 1001：fSAMPLING=fDTS/8, N=8 */
#define	ATIM_BKCR_BRKF_FILT10	(0xaU << ATIM_BKCR_BRKF_Pos)	/* 1010：fSAMPLING=fDTS/16, N=5 */
#define	ATIM_BKCR_BRKF_FILT11	(0xbU << ATIM_BKCR_BRKF_Pos)	/* 1011：fSAMPLING=fDTS/16, N=6 */
#define	ATIM_BKCR_BRKF_FILT12	(0xcU << ATIM_BKCR_BRKF_Pos)	/* 1100：fSAMPLING=fDTS/16, N=8 */
#define	ATIM_BKCR_BRKF_FILT13	(0xdU << ATIM_BKCR_BRKF_Pos)	/* 1101：fSAMPLING=fDTS/32, N=5 */
#define	ATIM_BKCR_BRKF_FILT14	(0xeU << ATIM_BKCR_BRKF_Pos)	/* 1110：fSAMPLING=fDTS/32, N=6 */
#define	ATIM_BKCR_BRKF_FILT15	(0xfU << ATIM_BKCR_BRKF_Pos)	/* 1111：fSAMPLING=fDTS/32, N=8 */

#define	ATIM_BKCR_BRKCOMB_Pos	3	/* 刹车组合控制 */
#define	ATIM_BKCR_BRKCOMB_Msk	(0x1U << ATIM_BKCR_BRKCOMB_Pos)
#define	ATIM_BKCR_BRKCOMB_OR	(0x0U << ATIM_BKCR_BRKCOMB_Pos)	/* 0：两路刹车信号相或 */
#define	ATIM_BKCR_BRKCOMB_AND	(0x1U << ATIM_BKCR_BRKCOMB_Pos)	/* 1：两路刹车信号相与 */

#define	ATIM_BKCR_HFDET_BRKEN_Pos	2	/* XTHF停振检测刹车信号使能 */
#define	ATIM_BKCR_HFDET_BRKEN_Msk	(0x1U << ATIM_BKCR_HFDET_BRKEN_Pos)
	/* 0：禁止HFDET刹车信号 */
	/* 1：使能HFDET刹车信号 */

#define	ATIM_BKCR_SVD_BRKEN_Pos	1	/* SVD刹车信号使能 */
#define	ATIM_BKCR_SVD_BRKEN_Msk	(0x1U << ATIM_BKCR_SVD_BRKEN_Pos)
	/* 0：禁止SVD刹车信号 */
	/* 1：使能SVD刹车信号 */

#define	ATIM_BKCR_COMP_BRKEN_Pos	0	/* 比较器输出刹车信号使能 */
#define	ATIM_BKCR_COMP_BRKEN_Msk	(0x1U << ATIM_BKCR_COMP_BRKEN_Pos)
	/* 0：禁止比较器刹车信号 */
	/* 1：使能比较器刹车信号 */
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void ATIM_Deinit(void);

/* Dead time和数字滤波时钟频率分频寄存器 相关函数 */
extern void ATIM_CR1_CKD_Set(uint32_t SetValue);
extern uint32_t ATIM_CR1_CKD_Get(void);

/* ARR预装载使能  相关函数 */
extern void ATIM_CR1_ARPE_Setable(FunState NewState);
extern FunState ATIM_CR1_ARPE_Getable(void);

/* 计数器对齐模式选择 相关函数 */
extern void ATIM_CR1_CMS_Set(uint32_t SetValue);
extern uint32_t ATIM_CR1_CMS_Get(void);

/* 计数方向寄存器 相关函数 */
extern void ATIM_CR1_DIR_Set(uint32_t SetValue);
extern uint32_t ATIM_CR1_DIR_Get(void);

/* 单脉冲输出模式 相关函数 */
extern void ATIM_CR1_OPM_Setable(FunState NewState);
extern FunState ATIM_CR1_OPM_Getable(void);

/* 更新请求选择 相关函数 */
extern void ATIM_CR1_URS_Setable(FunState NewState);
extern FunState ATIM_CR1_URS_Getable(void);

/* 禁止update 相关函数 */
extern void ATIM_CR1_UDIS_Setable(FunState NewState);
extern FunState ATIM_CR1_UDIS_Getable(void);

/* 计数器使能 相关函数 */
extern void ATIM_CR1_CEN_Setable(FunState NewState);
extern FunState ATIM_CR1_CEN_Getable(void);

/* 参考OIS1 相关函数 */
extern void ATIM_CR2_OIS4_Setable(FunState NewState);
extern FunState ATIM_CR2_OIS4_Getable(void);

/* 参考OIS1N 相关函数 */
extern void ATIM_CR2_OIS3N_Setable(FunState NewState);
extern FunState ATIM_CR2_OIS3N_Getable(void);

/* 参考OIS1 相关函数 */
extern void ATIM_CR2_OIS3_Setable(FunState NewState);
extern FunState ATIM_CR2_OIS3_Getable(void);

/* 参考OIS1N 相关函数 */
extern void ATIM_CR2_OIS2N_Setable(FunState NewState);
extern FunState ATIM_CR2_OIS2N_Getable(void);

/* 参考OIS1 相关函数 */
extern void ATIM_CR2_OIS2_Setable(FunState NewState);
extern FunState ATIM_CR2_OIS2_Getable(void);

/* OC1N的输出IDLE状态 相关函数 */
extern void ATIM_CR2_OIS1N_Setable(FunState NewState);
extern FunState ATIM_CR2_OIS1N_Getable(void);

/* OC1的输出IDLE状态 相关函数 */
extern void ATIM_CR2_OIS1_Setable(FunState NewState);
extern FunState ATIM_CR2_OIS1_Getable(void);

/* ATIM输入TI1选择 相关函数 */
extern void ATIM_CR2_TI1S_Set(uint32_t SetValue);
extern uint32_t ATIM_CR2_TI1S_Get(void);

/* 主机模式选择，用于配置主机模式下向从机发送的同步触发信号（TRGO）源 相关函数 */
extern void ATIM_CR2_MMS_Set(uint32_t SetValue);
extern uint32_t ATIM_CR2_MMS_Get(void);

/* 捕捉/比较 DMA选择 相关函数 */
extern void ATIM_CR2_CCDS_Set(uint32_t SetValue);
extern uint32_t ATIM_CR2_CCDS_Get(void);

/* 捕捉/比较控制寄存器更新选择 相关函数 */
extern void ATIM_CR2_CCUS_Set(uint32_t SetValue);
extern uint32_t ATIM_CR2_CCUS_Get(void);
extern void ATIM_CR2_CCPC_Setable(FunState NewState);
extern FunState ATIM_CR2_CCPC_Getable(void);

/* 外部触发信号极性配置 相关函数 */
extern void ATIM_SMCR_ETP_Set(uint32_t SetValue);
extern uint32_t ATIM_SMCR_ETP_Get(void);

/* 外部时钟使能 相关函数 */
extern void ATIM_SMCR_ECE_Setable(FunState NewState);
extern FunState ATIM_SMCR_ECE_Getable(void);

/* 外部触发信号预分频寄存器,外部触发信号ETRP的频率最多只能是ATIM工作时钟的1/4，当输入信号频率较高时，可以使用预分频 相关函数 */
extern void ATIM_SMCR_ETPS_Set(uint32_t SetValue);
extern uint32_t ATIM_SMCR_ETPS_Get(void);

/* 外部触发信号滤波时钟和长度选择 相关函数 */
extern void ATIM_SMCR_ETF_Set(uint32_t SetValue);
extern uint32_t ATIM_SMCR_ETF_Get(void);

/* 主机从机模式选 相关函数 */
extern void ATIM_SMCR_MSM_Set(uint32_t SetValue);
extern uint32_t ATIM_SMCR_MSM_Get(void);

/* 触发选择，用于选择同步计数器的触发源 相关函数 */
extern void ATIM_SMCR_TS_Set(uint32_t SetValue);
extern uint32_t ATIM_SMCR_TS_Get(void);

/* 从机模式选择 相关函数 */
extern void ATIM_SMCR_SMS_Set(uint32_t SetValue);
extern uint32_t ATIM_SMCR_SMS_Get(void);

/* 捕捉比较通道4的DMA模式配置 相关函数 */
extern void ATIM_DIER_CC4BURSTEN_Set(uint32_t SetValue);
extern uint32_t ATIM_DIER_CC4BURSTEN_Get(void);

/* 捕捉比较通道3的DMA模式配置 相关函数 */
extern void ATIM_DIER_CC3BURSTEN_Set(uint32_t SetValue);
extern uint32_t ATIM_DIER_CC3BURSTEN_Get(void);

/* 捕捉比较通道2的DMA模式配置 相关函数 */
extern void ATIM_DIER_CC2BURSTEN_Set(uint32_t SetValue);
extern uint32_t ATIM_DIER_CC2BURSTEN_Get(void);

/* 捕捉比较通道1的DMA模式配置 相关函数 */
extern void ATIM_DIER_CC1BURSTEN_Set(uint32_t SetValue);
extern uint32_t ATIM_DIER_CC1BURSTEN_Get(void);

/* 外部触发DMA请求使能 相关函数 */
extern void ATIM_DIER_TDE_Setable(FunState NewState);
extern FunState ATIM_DIER_TDE_Getable(void);

/* COM事件DMA请求使能 相关函数 */
extern void ATIM_DIER_COMDE_Setable(FunState NewState);
extern FunState ATIM_DIER_COMDE_Getable(void);

/* 捕捉比较通道4的DMA请求使能 相关函数 */
extern void ATIM_DIER_CC4DE_Setable(FunState NewState);
extern FunState ATIM_DIER_CC4DE_Getable(void);

/* 捕捉比较通道3的DMA请求使能 相关函数 */
extern void ATIM_DIER_CC3DE_Setable(FunState NewState);
extern FunState ATIM_DIER_CC3DE_Getable(void);

/* 捕捉比较通道2的DMA请求使能 相关函数 */
extern void ATIM_DIER_CC2DE_Setable(FunState NewState);
extern FunState ATIM_DIER_CC2DE_Getable(void);

/* 捕捉比较通道1的DMA请求使能 相关函数 */
extern void ATIM_DIER_CC1DE_Setable(FunState NewState);
extern FunState ATIM_DIER_CC1DE_Getable(void);

/* 更新事件DMA请求使能  相关函数 */
extern void ATIM_DIER_UDE_Setable(FunState NewState);
extern FunState ATIM_DIER_UDE_Getable(void);

/* 刹车事件中断使能 相关函数 */
extern void ATIM_DIER_BIE_Setable(FunState NewState);
extern FunState ATIM_DIER_BIE_Getable(void);

/* 触发事件中断使能 相关函数 */
extern void ATIM_DIER_TIE_Setable(FunState NewState);
extern FunState ATIM_DIER_TIE_Getable(void);

/* COM事件中断使能 相关函数 */
extern void ATIM_DIER_COMIE_Setable(FunState NewState);
extern FunState ATIM_DIER_COMIE_Getable(void);

/* 捕捉/比较通道4中断使能 相关函数 */
extern void ATIM_DIER_CC4IE_Setable(FunState NewState);
extern FunState ATIM_DIER_CC4IE_Getable(void);

/* 捕捉/比较通道3中断使能 相关函数 */
extern void ATIM_DIER_CC3IE_Setable(FunState NewState);
extern FunState ATIM_DIER_CC3IE_Getable(void);

/* 捕捉/比较通道2中断使能 相关函数 */
extern void ATIM_DIER_CC2IE_Setable(FunState NewState);
extern FunState ATIM_DIER_CC2IE_Getable(void);

/* 捕捉/比较通道1中断使能 相关函数 */
extern void ATIM_DIER_CC1IE_Setable(FunState NewState);
extern FunState ATIM_DIER_CC1IE_Getable(void);

/* 更新事件中断使能 相关函数 */
extern void ATIM_DIER_UIE_Setable(FunState NewState);
extern FunState ATIM_DIER_UIE_Getable(void);

/* 捕捉/比较通道4的Overcapture中断 相关函数 */
extern void ATIM_ISR_CC4OF_Clr(void);
extern FlagStatus ATIM_ISR_CC4OF_Chk(void);

/* 捕捉/比较通道3的Overcapture中断 相关函数 */
extern void ATIM_ISR_CC3OF_Clr(void);
extern FlagStatus ATIM_ISR_CC3OF_Chk(void);

/* 捕捉/比较通道2的Overcapture中断 相关函数 */
extern void ATIM_ISR_CC2OF_Clr(void);
extern FlagStatus ATIM_ISR_CC2OF_Chk(void);

/* 捕捉/比较通道1的Overcapture中断，此寄存器仅在对应通道设置为输入捕捉模式的情况下有效。硬件置位，软件写1清零 相关函数 */
extern void ATIM_ISR_CC1OF_Clr(void);
extern FlagStatus ATIM_ISR_CC1OF_Chk(void);

/* 刹车事件中断标志，硬件置位，软件写1清零 相关函数 */
extern void ATIM_ISR_BIF_Clr(void);
extern FlagStatus ATIM_ISR_BIF_Chk(void);

/* 触发事件中断标志，硬件置位，软件写1清零 相关函数 */
extern void ATIM_ISR_TIF_Clr(void);
extern FlagStatus ATIM_ISR_TIF_Chk(void);

/* COM事件中断标志，硬件置位，软件写1清零 相关函数 */
extern void ATIM_ISR_COMIF_Clr(void);
extern FlagStatus ATIM_ISR_COMIF_Chk(void);

/* 捕捉/比较通道4中断标志，参考CC1IF 相关函数 */
extern void ATIM_ISR_CC4IF_Clr(void);
extern FlagStatus ATIM_ISR_CC4IF_Chk(void);

/* 捕捉/比较通道3中断标志，参考CC1IF 相关函数 */
extern void ATIM_ISR_CC3IF_Clr(void);
extern FlagStatus ATIM_ISR_CC3IF_Chk(void);

/* 捕捉/比较通道2中断标志，参考CC1IF 相关函数 */
extern void ATIM_ISR_CC2IF_Clr(void);
extern FlagStatus ATIM_ISR_CC2IF_Chk(void);

/* 捕捉/比较通道1中断标志，如果CC1通道配置为输出：CC1IF在计数值等于比较值时置位，软件写1清零。
如果CC1通道配置为输入：发生捕捉事件时置位，软件写1清零，或者软件读ATIM_CCR1自动清零 相关函数 */
extern void ATIM_ISR_CC1IF_Clr(void);
extern FlagStatus ATIM_ISR_CC1IF_Chk(void);

/* 更新事件中断标志，硬件置位，软件写1清零 相关函数 */
extern void ATIM_ISR_UIF_Clr(void);
extern FlagStatus ATIM_ISR_UIF_Chk(void);

/* 软件刹车，软件置位此寄存器产生刹车事件，硬件自动清零 相关函数 */
extern void ATIM_EGR_BG_Setable(FunState NewState);

/* 软件触发，软件置位此寄存器产生触发事件，硬件自动清零 相关函数 */
extern void ATIM_EGR_TIF_Setable(FunState NewState);

/* 软件COM事件，硬件置位，软件写1清零 相关函数 */
extern void ATIM_EGR_COMG_Setable(FunState NewState);

/* 捕捉/比较通道4软件触发，参考CC1G 相关函数 */
extern void ATIM_EGR_CC4G_Setable(FunState NewState);

/* 捕捉/比较通道3软件触发，参考CC1G 相关函数 */
extern void ATIM_EGR_CC3G_Setable(FunState NewState);

/* 捕捉/比较通道2软件触发，参考CC1G 相关函数 */
extern void ATIM_EGR_CC2G_Setable(FunState NewState);

/* 捕捉/比较通道1软件触发 相关函数 */
extern void ATIM_EGR_CC1G_Setable(FunState NewState);

/* 软件Update事件，软件置位此寄存器产生Update事件，硬件自动清零 相关函数 */
extern void ATIM_EGR_UG_Setable(FunState NewState);

/* 输出比较2清零使能，参考OC1CE 相关函数 */
extern void ATIM_CCMR1_OC2CE_Setable(FunState NewState);
extern FunState ATIM_CCMR1_OC2CE_Getable(void);

/* 输出比较2模式配置，参考OC1M 相关函数 */
extern void ATIM_CCMR1_OC2M_Set(uint32_t SetValue);
extern uint32_t ATIM_CCMR1_OC2M_Get(void);

/* 输出比较2预装载使能，参考OC1PE 相关函数 */
extern void ATIM_CCMR1_OC2PE_Setable(FunState NewState);
extern FunState ATIM_CCMR1_OC2PE_Getable(void);

/* 输出比较2快速使能，参考OC1FE 相关函数 */
extern void ATIM_CCMR1_OC2FE_Setable(FunState NewState);
extern FunState ATIM_CCMR1_OC2FE_Getable(void);

/* 捕捉/比较2通道选择 相关函数 */
extern void ATIM_CCMR1_CC2S_Set(uint32_t SetValue);
extern uint32_t ATIM_CCMR1_CC2S_Get(void);

/* 输出比较1清零使能 相关函数 */
extern void ATIM_CCMR1_OC1CE_Setable(FunState NewState);
extern FunState ATIM_CCMR1_OC1CE_Getable(void);

/* 输出比较1模式配置，此寄存器定义OC1REF信号的行为 相关函数 */
extern void ATIM_CCMR1_OC1M_Set(uint32_t SetValue);
extern uint32_t ATIM_CCMR1_OC1M_Get(void);

/* 输出比较1预装载使能 相关函数 */
extern void ATIM_CCMR1_OC1PE_Setable(FunState NewState);
extern FunState ATIM_CCMR1_OC1PE_Getable(void);

/* 输出比较1快速使能 相关函数 */
extern void ATIM_CCMR1_OC1FE_Setable(FunState NewState);
extern FunState ATIM_CCMR1_OC1FE_Getable(void);

/* 捕捉/比较1通道选择 相关函数 */
extern void ATIM_CCMR1_CC1S_Set(uint32_t SetValue);
extern uint32_t ATIM_CCMR1_CC1S_Get(void);

/* 输入捕捉2滤波 相关函数 */
extern void ATIM_CCMR1_IC2F_Set(uint32_t SetValue);
extern uint32_t ATIM_CCMR1_IC2F_Get(void);

/* 输入捕捉2预分频 相关函数 */
extern void ATIM_CCMR1_IC2PSC_Set(uint32_t SetValue);
extern uint32_t ATIM_CCMR1_IC2PSC_Get(void);

/* 输入捕捉1滤波 相关函数 */
extern void ATIM_CCMR1_IC1F_Set(uint32_t SetValue);
extern uint32_t ATIM_CCMR1_IC1F_Get(void);

/* 输入捕捉1预分频 相关函数 */
extern void ATIM_CCMR1_IC1PSC_Set(uint32_t SetValue);
extern uint32_t ATIM_CCMR1_IC1PSC_Get(void);

/* 输出比较4清零使能，参考OC1CE 相关函数 */
extern void ATIM_CCMR2_OC4CE_Setable(FunState NewState);
extern FunState ATIM_CCMR2_OC4CE_Getable(void);
extern void ATIM_CCMR2_OC4M_Set(uint32_t SetValue);
extern uint32_t ATIM_CCMR2_OC4M_Get(void);

/* 输出比较4预装载使能，参考OC1PE 相关函数 */
extern void ATIM_CCMR2_OC4PE_Setable(FunState NewState);
extern FunState ATIM_CCMR2_OC4PE_Getable(void);

/* 输出比较4快速使能，参考OC1FE 相关函数 */
extern void ATIM_CCMR2_OC4FE_Setable(FunState NewState);
extern FunState ATIM_CCMR2_OC4FE_Getable(void);

/* 捕捉/比较4通道选择 相关函数 */
extern void ATIM_CCMR2_CC4S_Set(uint32_t SetValue);
extern uint32_t ATIM_CCMR2_CC4S_Get(void);

/* 输出比较1清零使能 相关函数 */
extern void ATIM_CCMR2_OC3CE_Setable(FunState NewState);
extern FunState ATIM_CCMR2_OC3CE_Getable(void);

/* 输出比较3模式配置，此寄存器定义OC3REF信号的行为 相关函数 */
extern void ATIM_CCMR2_OC3M_Set(uint32_t SetValue);
extern uint32_t ATIM_CCMR2_OC3M_Get(void);

/* 输出比较3预装载使能 相关函数 */
extern void ATIM_CCMR2_OC3PE_Setable(FunState NewState);
extern FunState ATIM_CCMR2_OC3PE_Getable(void);

/* 输出比较3快速使能 相关函数 */
extern void ATIM_CCMR2_OC3FE_Setable(FunState NewState);
extern FunState ATIM_CCMR2_OC3FE_Getable(void);

/* 捕捉/比较3通道选择 相关函数 */
extern void ATIM_CCMR2_CC3S_Set(uint32_t SetValue);
extern uint32_t ATIM_CCMR2_CC3S_Get(void);

/* 输入捕捉4滤波 相关函数 */
extern void ATIM_CCMR2_IC4F_Set(uint32_t SetValue);
extern uint32_t ATIM_CCMR2_IC4F_Get(void);

/* 输入捕捉4预分频 相关函数 */
extern void ATIM_CCMR2_IC4PSC_Set(uint32_t SetValue);
extern uint32_t ATIM_CCMR2_IC4PSC_Get(void);

/* 输入捕捉3滤波 相关函数 */
extern void ATIM_CCMR2_IC3F_Set(uint32_t SetValue);
extern uint32_t ATIM_CCMR2_IC3F_Get(void);

/* 输入捕捉3预分频 相关函数 */
extern void ATIM_CCMR2_IC3PSC_Set(uint32_t SetValue);
extern uint32_t ATIM_CCMR2_IC3PSC_Get(void);

/* 捕捉/比较4输出极性，参考CC1P 相关函数 */
extern void ATIM_CCER_CC4P_Set(uint32_t SetValue);
extern uint32_t ATIM_CCER_CC4P_Get(void);

/* 捕捉/比较4输出使能，参考CC1E 相关函数 */
extern void ATIM_CCER_CC4E_Setable(FunState NewState);
extern FunState ATIM_CCER_CC4E_Getable(void);

/* 捕捉/比较3互补输出极性，参考CC1NP 相关函数 */
extern void ATIM_CCER_CC3NP_Set(uint32_t SetValue);
extern uint32_t ATIM_CCER_CC3NP_Get(void);

/* 捕捉/比较3互补输出使能，参考CC1NE 相关函数 */
extern void ATIM_CCER_CC3NE_Setable(FunState NewState);
extern FunState ATIM_CCER_CC3NE_Getable(void);

/* 捕捉/比较3输出极性，参考CC1P 相关函数 */
extern void ATIM_CCER_CC3P_Set(uint32_t SetValue);
extern uint32_t ATIM_CCER_CC3P_Get(void);

/* 捕捉/比较3输出使能，参考CC1E 相关函数 */
extern void ATIM_CCER_CC3E_Setable(FunState NewState);
extern FunState ATIM_CCER_CC3E_Getable(void);

/* 捕捉/比较2互补输出极性，参考CC1NP 相关函数 */
extern void ATIM_CCER_CC2NP_Set(uint32_t SetValue);
extern uint32_t ATIM_CCER_CC2NP_Get(void);

/* 捕捉/比较2互补输出使能，参考CC1NE 相关函数 */
extern void ATIM_CCER_CC2NE_Setable(FunState NewState);
extern FunState ATIM_CCER_CC2NE_Getable(void);

/* 捕捉/比较2输出极性，参考CC1P 相关函数 */
extern void ATIM_CCER_CC2P_Set(uint32_t SetValue);
extern uint32_t ATIM_CCER_CC2P_Get(void);

/* 捕捉/比较2输出使能，参考CC1E 相关函数 */
extern void ATIM_CCER_CC2E_Setable(FunState NewState);
extern FunState ATIM_CCER_CC2E_Getable(void);

/* 捕捉/比较1互补输出极性 相关函数 */
extern void ATIM_CCER_CC1NP_Set(uint32_t SetValue);
extern uint32_t ATIM_CCER_CC1NP_Get(void);

/* 捕捉/比较1互补输出使能 相关函数 */
extern void ATIM_CCER_CC1NE_Setable(FunState NewState);
extern FunState ATIM_CCER_CC1NE_Getable(void);

/* 捕捉/比较1输出极性 (CC1 Polarity)
CC1通道配置为输出时
0：OC1高电平active
1：OC1低电平active
CC1通道配置为输入时
0：非取反模式–捕捉在IC1的上升沿进行
1：取反模式–捕捉在IC1的下降沿进行 相关函数 */
extern void ATIM_CCER_CC1P_Set(uint32_t SetValue);
extern uint32_t ATIM_CCER_CC1P_Get(void);

/* 捕捉/比较1输出使能 (CC1 Enable)
CC1通道配置为输出时
0：OC1不active
1：OC1 active
CC1通道配置为输入时
0：关闭捕捉功能
1：使能捕捉功能 相关函数 */
extern void ATIM_CCER_CC1E_Setable(FunState NewState);
extern FunState ATIM_CCER_CC1E_Getable(void);

/* 计数器值 相关函数 */
extern void ATIM_CNT_Write(uint32_t SetValue);
extern uint32_t ATIM_CNT_Read(void);

/* 计数器时钟预分频值
fCK_CNT=fCK_PSC/(PSC[15:0]+1)
这是一个preload寄存器，在update事件发生时其内容被载入shadow寄存器 相关函数 */
extern void ATIM_PSC_Write(uint32_t SetValue);
extern uint32_t ATIM_PSC_Read(void);

/* 计数溢出时的自动重载值 
这是一个preload寄存器，在update事件发生时其内容被载入shadow寄存器 相关函数 */
extern void ATIM_ARR_Write(uint32_t SetValue);
extern uint32_t ATIM_ARR_Read(void);

/* 重复计数值  相关函数 */
extern void ATIM_RCR_Write(uint32_t SetValue);
extern uint32_t ATIM_RCR_Read(void);

/* 捕捉/比较通道1寄存器 
如果通道1配置为输出：
这是一个preload寄存器，其内容被载入shadow寄存器后用于与计数器比较产生OC1输出
如果通道1配置为输入：
CCR1保存最近一次输入捕捉事件发生时的计数器值，此时CCR1为只读 相关函数 */
extern void ATIM_CCR1_Write(uint32_t SetValue);
extern uint32_t ATIM_CCR1_Read(void);

/* 捕捉/比较通道2寄存器 
如果通道2配置为输出：
这是一个preload寄存器，其内容被载入shadow寄存器后用于与计数器比较产生OC2输出
如果通道2配置为输入：
CCR2保存最近一次输入捕捉事件发生时的计数器值，此时CCR2为只读 相关函数 */
extern void ATIM_CCR2_Write(uint32_t SetValue);
extern uint32_t ATIM_CCR2_Read(void);

/* 捕捉/比较通道3寄存器 
如果通道3配置为输出：
这是一个preload寄存器，其内容被载入shadow寄存器后用于与计数器比较产生OC3输出
如果通道3配置为输入：
CCR3保存最近一次输入捕捉事件发生时的计数器值，此时CCR3为只读 相关函数 */
extern void ATIM_CCR3_Write(uint32_t SetValue);
extern uint32_t ATIM_CCR3_Read(void);

/* 捕捉/比较通道4寄存器 
如果通道4配置为输出：
这是一个preload寄存器，其内容被载入shadow寄存器后用于与计数器比较产生OC4输出
如果通道4配置为输入：
CCR4保存最近一次输入捕捉事件发生时的计数器值，此时CCR4为只读 相关函数 */
extern void ATIM_CCR4_Write(uint32_t SetValue);
extern uint32_t ATIM_CCR4_Read(void);

/* 输出使能主控 相关函数 */
extern void ATIM_BDTR_MOE_Setable(FunState NewState);
extern FunState ATIM_BDTR_MOE_Getable(void);

/* 自动输出使能 相关函数 */
extern void ATIM_BDTR_AOE_Set(uint32_t SetValue);
extern uint32_t ATIM_BDTR_AOE_Get(void);
extern void ATIM_BDTR_BKP_Set(uint32_t SetValue);
extern uint32_t ATIM_BDTR_BKP_Get(void);
extern void ATIM_BDTR_BKE_Setable(FunState NewState);
extern FunState ATIM_BDTR_BKE_Getable(void);
extern void ATIM_BDTR_OSSR_Set(uint32_t SetValue);
extern uint32_t ATIM_BDTR_OSSR_Get(void);
extern void ATIM_BDTR_OSSI_Set(uint32_t SetValue);
extern uint32_t ATIM_BDTR_OSSI_Get(void);

/* 寄存器写保护配置 相关函数 */
extern void ATIM_BDTR_LOCK_Set(uint32_t SetValue);
extern uint32_t ATIM_BDTR_LOCK_Get(void);

/* 死区时间插入，用于配置互补输出插入的死区时间长度 相关函数 */
extern void ATIM_BDTR_DTG_Set(uint32_t SetValue);
extern uint32_t ATIM_BDTR_DTG_Get(void);

/* DMA Burst长度 相关函数 */
extern void ATIM_DCR_DBL_Set(uint32_t SetValue);
extern uint32_t ATIM_DCR_DBL_Get(void);

/* DMA基地址，定义指向寄存器的偏移地址 相关函数 */
extern void ATIM_DCR_DBA_Set(uint32_t SetValue);
extern uint32_t ATIM_DCR_DBA_Get(void);

/* DMA burst访问寄存器
在使用DMA burst传输时，将DMA通道外设地址设置为ATIM_DMAR，ATIM会根据DBL的值产生多次DMA请求 相关函数 */
extern void ATIM_DMAR_Write(uint32_t SetValue);
extern uint32_t ATIM_DMAR_Read(void);

/* ATIM_BRK2引脚输入门控信号 相关函数 */
extern void ATIM_BKCR_BRK2GATE_Set(uint32_t SetValue);
extern uint32_t ATIM_BKCR_BRK2GATE_Get(void);

/* ATIM_BRK1引脚输入门控信号 相关函数 */
extern void ATIM_BKCR_BRK1GATE_Set(uint32_t SetValue);
extern uint32_t ATIM_BKCR_BRK1GATE_Get(void);

/* 刹车信号的滤波时钟和长度选择  相关函数 */
extern void ATIM_BKCR_BRKF_Set(uint32_t SetValue);
extern uint32_t ATIM_BKCR_BRKF_Get(void);

/* 刹车组合控制 相关函数 */
extern void ATIM_BKCR_BRKCOMB_Set(uint32_t SetValue);
extern uint32_t ATIM_BKCR_BRKCOMB_Get(void);

/* XTHF停振检测刹车信号使能 相关函数 */
extern void ATIM_BKCR_HFDET_BRKEN_Setable(FunState NewState);
extern FunState ATIM_BKCR_HFDET_BRKEN_Getable(void);

/* SVD刹车信号使能 相关函数 */
extern void ATIM_BKCR_SVD_BRKEN_Setable(FunState NewState);
extern FunState ATIM_BKCR_SVD_BRKEN_Getable(void);

/* 比较器输出刹车信号使能 相关函数 */
extern void ATIM_BKCR_COMP_BRKEN_Setable(FunState NewState);
extern FunState ATIM_BKCR_COMP_BRKEN_Getable(void);
 
extern void ATIM_TimeBaseInit(TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);
extern void ATIM_ClearITPendingBit(uint32_t TIM_IT);
extern void ATIM_ITConfig(uint32_t TIM_IT, FunState NewState);
extern ITStatus ATIM_GetITStatus(uint32_t TIM_IT);
extern void ATIM_Cmd(FunState NewState);
#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_ATIM_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
