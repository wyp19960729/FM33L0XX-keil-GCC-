/**
  ******************************************************************************
  * @file    fm33l0xx_opa.h
  * @author  FM33L0xx Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file contains all the functions prototypes for the OPA firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33L0XX_OPA_H
#define __FM33L0XX_OPA_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33L0XX.h" 
   
//------------------------------------------------------------------------------
#define	OPAx_CR_BUFOFF_EN_Pos	31	/* VREF BUFFER使能信号 (VREF buffer enable) */
#define	OPAx_CR_BUFOFF_EN_Msk	(0x1U << OPAx_CR_BUFOFF_EN_Pos)
	/* 0：使能VREF BUFFER */
	/* 1：关闭VREF BUFFER */

#define	OPAx_CR_BUFBYP_Pos	30	/* VREF BUFFER旁路控制 (VREF buffer bypass) */
#define	OPAx_CR_BUFBYP_Msk	(0x1U << OPAx_CR_BUFBYP_Pos)
	/* 0：不bypass VREF BUFFER */
	/* 1：bypass VREF BUFFER */

#define	OPAx_CR_VNSEL_Pos	9	/* OPA负端输入选择 (OPA Negtive Input Select) */
#define	OPAx_CR_VNSEL_Msk	(0x7U << OPAx_CR_VNSEL_Pos)
#define	OPAx_CR_VNSEL_OPA1_INN1	(0x0U << OPAx_CR_VNSEL_Pos)	/* 000：OPA_INN1 */
#define	OPAx_CR_VNSEL_OPA1_INN2	(0x1U << OPAx_CR_VNSEL_Pos)	/* 001：OPA_INN2 */
#define	OPAx_CR_VNSEL_VREF	(0x2U << OPAx_CR_VNSEL_Pos)	/* 010：VREF */
#define	OPAx_CR_VNSEL_3_4_VREF	(0x3U << OPAx_CR_VNSEL_Pos)	/* 011：3/4 VREF */
#define	OPAx_CR_VNSEL_1_2_VREF	(0x4U << OPAx_CR_VNSEL_Pos)	/* 100：1/2 VREF */
#define	OPAx_CR_VNSEL_1_4_VREF	(0x5U << OPAx_CR_VNSEL_Pos)	/* 101：1/4 VREF */
#define	OPAx_CR_VNSEL_1_8_VREF	(0x6U << OPAx_CR_VNSEL_Pos)	/* 110：1/8 VREF */

#define	OPAx_CR_VPSEL_Pos	8	/* OPA正端输入选择 (OPA Positive Input Select) */
#define	OPAx_CR_VPSEL_Msk	(0x1U << OPAx_CR_VPSEL_Pos)
#define	OPAx_CR_VPSEL_OPA1_INP1	(0x0U << OPAx_CR_VPSEL_Pos)	/* 0：OPA_INP1 */
#define	OPAx_CR_VPSEL_OPA1_INP2	(0x1U << OPAx_CR_VPSEL_Pos)	/* 1：OPA_INP2 */

#define	OPAx_CR_DF_Pos	7	/* OPA比较器模式输出数字滤波使能（仅OPA配置为比较器模式下有效） (OPA Comparator mode digital filter) */
#define	OPAx_CR_DF_Msk	(0x1U << OPAx_CR_DF_Pos)
	/* 0：关闭比较器输出数字滤波 */
	/* 1：打开比较器输出数字滤波 */

#define	OPAx_CR_VN_EXC_Pos	6	/* OPA负端连接GPIO，仅OPAxMOD=10时有效
(OPA Negtive Input Connected to GPIO)
 */
#define	OPAx_CR_VN_EXC_Msk	(0x1U << OPAx_CR_VN_EXC_Pos)
	/* 0：PGA模式下OPA1负端不连接GPIO */
	/* 1：PGA模式下OPA1负端同时连接到GPIO */

#define	OPAx_CR_PGA_GAIN_Pos	4	/* PGA增益选择 (PGA gain select) */
#define	OPAx_CR_PGA_GAIN_Msk	(0x3U << OPAx_CR_PGA_GAIN_Pos)
#define	OPAx_CR_PGA_GAIN_GAIN_2	(0x0U << OPAx_CR_PGA_GAIN_Pos)	/* 00：PGA增益x2 */
#define	OPAx_CR_PGA_GAIN_GAIN_4	(0x1U << OPAx_CR_PGA_GAIN_Pos)	/* 01：PGA增益x4 */
#define	OPAx_CR_PGA_GAIN_GAIN_8	(0x2U << OPAx_CR_PGA_GAIN_Pos)	/* 10：PGA增益x8 */
#define	OPAx_CR_PGA_GAIN_GAIN_16	(0x3U << OPAx_CR_PGA_GAIN_Pos)	/* 11：PGA增益x16 */

#define	OPAx_CR_MOD_Pos	2	/* OPA工作模式 (OPA mode) */
#define	OPAx_CR_MOD_Msk	(0x3U << OPAx_CR_MOD_Pos)
#define	OPAx_CR_MOD_MOD_STANDALONE	(0x0U << OPAx_CR_MOD_Pos)	/* 00：standalone模式 */
#define	OPAx_CR_MOD_MOD_CMP	(0x1U << OPAx_CR_MOD_Pos)	/* 01：比较器模式 */
#define	OPAx_CR_MOD_MOD_PGA	(0x2U << OPAx_CR_MOD_Pos)	/* 10：PGA模式 */
#define	OPAx_CR_MOD_MOD_BUF	(0x3U << OPAx_CR_MOD_Pos)	/* 11：buffer模式 */

#define	OPAx_CR_LPM_Pos	1	/* OPA低功耗控制寄存器 (OPA low power mode) */
#define	OPAx_CR_LPM_Msk	(0x1U << OPAx_CR_LPM_Pos)
#define	OPAx_CR_LPM_NORMAL_POWER	(0x0U << OPAx_CR_LPM_Pos)	/* 0：正常模式 */
#define	OPAx_CR_LPM_LOW_POWER	(0x1U << OPAx_CR_LPM_Pos)	/* 1：低功耗模式 */

#define	OPAx_CR_EN_Pos	0	/* OPA使能寄存器 (OPA enable) */
#define	OPAx_CR_EN_Msk	(0x1U << OPAx_CR_EN_Pos)
	/* 0：关闭OPA */
	/* 1：使能OPA */

#define	OPAx_CALR_NCAL_EN_Pos	31	/* OPA负端输入校准使能 */
#define	OPAx_CALR_NCAL_EN_Msk	(0x1U << OPAx_CALR_NCAL_EN_Pos)
	/* 0：关闭OPA负端校准 */
	/* 1：使能OPA负端校准 */

#define	OPAx_CALR_NCAL_Pos	16	/* OPA负输入端校准trim信号，最高位为符号位 */
#define	OPAx_CALR_NCAL_Msk	(0x1fU << OPAx_CALR_NCAL_Pos)
#define	OPAx_CALR_NCAL_N_DEC_0	(0x0U << OPAx_CALR_NCAL_Pos)	/* 00000：输出电压不变 */
#define	OPAx_CALR_NCAL_N_DEC_1	(0x1U << OPAx_CALR_NCAL_Pos)	/* 00001：输出电压减小最小 */
#define	OPAx_CALR_NCAL_N_DEC_2	(0x2U << OPAx_CALR_NCAL_Pos)
#define	OPAx_CALR_NCAL_N_DEC_3	(0x3U << OPAx_CALR_NCAL_Pos)
#define	OPAx_CALR_NCAL_N_DEC_4	(0x4U << OPAx_CALR_NCAL_Pos)
#define	OPAx_CALR_NCAL_N_DEC_5	(0x5U << OPAx_CALR_NCAL_Pos)
#define	OPAx_CALR_NCAL_N_DEC_6	(0x6U << OPAx_CALR_NCAL_Pos)
#define	OPAx_CALR_NCAL_N_DEC_7	(0x7U << OPAx_CALR_NCAL_Pos)
#define	OPAx_CALR_NCAL_N_DEC_8	(0x8U << OPAx_CALR_NCAL_Pos)
#define	OPAx_CALR_NCAL_N_DEC_9	(0x9U << OPAx_CALR_NCAL_Pos)
#define	OPAx_CALR_NCAL_N_DEC_10	(0xaU << OPAx_CALR_NCAL_Pos)
#define	OPAx_CALR_NCAL_N_DEC_11	(0xbU << OPAx_CALR_NCAL_Pos)
#define	OPAx_CALR_NCAL_N_DEC_12	(0xcU << OPAx_CALR_NCAL_Pos)
#define	OPAx_CALR_NCAL_N_DEC_13	(0xdU << OPAx_CALR_NCAL_Pos)
#define	OPAx_CALR_NCAL_N_DEC_14	(0xeU << OPAx_CALR_NCAL_Pos)
#define	OPAx_CALR_NCAL_N_DEC_15	(0xfU << OPAx_CALR_NCAL_Pos)	/* 01111：输出电压减小最大 */
#define	OPAx_CALR_NCAL_N_INC_0	(0x10U << OPAx_CALR_NCAL_Pos)	/* 10000：输出电压不变 */
#define	OPAx_CALR_NCAL_N_INC_1	(0x11U << OPAx_CALR_NCAL_Pos)	/* 10001：输出电压增加最小 */
#define	OPAx_CALR_NCAL_N_INC_2	(0x12U << OPAx_CALR_NCAL_Pos)
#define	OPAx_CALR_NCAL_N_INC_3	(0x13U << OPAx_CALR_NCAL_Pos)
#define	OPAx_CALR_NCAL_N_INC_4	(0x14U << OPAx_CALR_NCAL_Pos)
#define	OPAx_CALR_NCAL_N_INC_5	(0x15U << OPAx_CALR_NCAL_Pos)
#define	OPAx_CALR_NCAL_N_INC_6	(0x16U << OPAx_CALR_NCAL_Pos)
#define	OPAx_CALR_NCAL_N_INC_7	(0x17U << OPAx_CALR_NCAL_Pos)
#define	OPAx_CALR_NCAL_N_INC_8	(0x18U << OPAx_CALR_NCAL_Pos)
#define	OPAx_CALR_NCAL_N_INC_9	(0x19U << OPAx_CALR_NCAL_Pos)
#define	OPAx_CALR_NCAL_N_INC_10	(0x1aU << OPAx_CALR_NCAL_Pos)
#define	OPAx_CALR_NCAL_N_INC_11	(0x1bU << OPAx_CALR_NCAL_Pos)
#define	OPAx_CALR_NCAL_N_INC_12	(0x1cU << OPAx_CALR_NCAL_Pos)
#define	OPAx_CALR_NCAL_N_INC_13	(0x1dU << OPAx_CALR_NCAL_Pos)
#define	OPAx_CALR_NCAL_N_INC_14	(0x1eU << OPAx_CALR_NCAL_Pos)
#define	OPAx_CALR_NCAL_N_INC_15	(0x1fU << OPAx_CALR_NCAL_Pos)	/* 11111：输出电压增加最大 */

#define	OPAx_CALR_PCAL_EN_Pos	15	/* OPA正端输入校准使能 */
#define	OPAx_CALR_PCAL_EN_Msk	(0x1U << OPAx_CALR_PCAL_EN_Pos)

#define	OPAx_CALR_PCAL_Pos	0	/* OPA正输入端校准trim信号，最高位为符号位 */
#define	OPAx_CALR_PCAL_Msk	(0x1fU << OPAx_CALR_PCAL_Pos)
#define	OPAx_CALR_PCAL_P_DEC_0	(0x0U << OPAx_CALR_PCAL_Pos)	/* 00000：输出电压不变 */
#define	OPAx_CALR_PCAL_P_DEC_1	(0x1U << OPAx_CALR_PCAL_Pos)	/* 00001：输出电压减小最小 */
#define	OPAx_CALR_PCAL_P_DEC_2	(0x2U << OPAx_CALR_PCAL_Pos)
#define	OPAx_CALR_PCAL_P_DEC_3	(0x3U << OPAx_CALR_PCAL_Pos)
#define	OPAx_CALR_PCAL_P_DEC_4	(0x4U << OPAx_CALR_PCAL_Pos)
#define	OPAx_CALR_PCAL_P_DEC_5	(0x5U << OPAx_CALR_PCAL_Pos)
#define	OPAx_CALR_PCAL_P_DEC_6	(0x6U << OPAx_CALR_PCAL_Pos)
#define	OPAx_CALR_PCAL_P_DEC_7	(0x7U << OPAx_CALR_PCAL_Pos)
#define	OPAx_CALR_PCAL_P_DEC_8	(0x8U << OPAx_CALR_PCAL_Pos)
#define	OPAx_CALR_PCAL_P_DEC_9	(0x9U << OPAx_CALR_PCAL_Pos)
#define	OPAx_CALR_PCAL_P_DEC_10	(0xaU << OPAx_CALR_PCAL_Pos)
#define	OPAx_CALR_PCAL_P_DEC_11	(0xbU << OPAx_CALR_PCAL_Pos)
#define	OPAx_CALR_PCAL_P_DEC_12	(0xcU << OPAx_CALR_PCAL_Pos)
#define	OPAx_CALR_PCAL_P_DEC_13	(0xdU << OPAx_CALR_PCAL_Pos)
#define	OPAx_CALR_PCAL_P_DEC_14	(0xeU << OPAx_CALR_PCAL_Pos)
#define	OPAx_CALR_PCAL_P_DEC_15	(0xfU << OPAx_CALR_PCAL_Pos)	/* 01111：输出电压减小最大 */
#define	OPAx_CALR_PCAL_P_INC_0	(0x10U << OPAx_CALR_PCAL_Pos)	/* 10000：输出电压不变 */
#define	OPAx_CALR_PCAL_P_INC_1	(0x11U << OPAx_CALR_PCAL_Pos)	/* 10001：输出电压增加最小 */
#define	OPAx_CALR_PCAL_P_INC_2	(0x12U << OPAx_CALR_PCAL_Pos)
#define	OPAx_CALR_PCAL_P_INC_3	(0x13U << OPAx_CALR_PCAL_Pos)
#define	OPAx_CALR_PCAL_P_INC_4	(0x14U << OPAx_CALR_PCAL_Pos)
#define	OPAx_CALR_PCAL_P_INC_5	(0x15U << OPAx_CALR_PCAL_Pos)
#define	OPAx_CALR_PCAL_P_INC_6	(0x16U << OPAx_CALR_PCAL_Pos)
#define	OPAx_CALR_PCAL_P_INC_7	(0x17U << OPAx_CALR_PCAL_Pos)
#define	OPAx_CALR_PCAL_P_INC_8	(0x18U << OPAx_CALR_PCAL_Pos)
#define	OPAx_CALR_PCAL_P_INC_9	(0x19U << OPAx_CALR_PCAL_Pos)
#define	OPAx_CALR_PCAL_P_INC_10	(0x1aU << OPAx_CALR_PCAL_Pos)
#define	OPAx_CALR_PCAL_P_INC_11	(0x1bU << OPAx_CALR_PCAL_Pos)
#define	OPAx_CALR_PCAL_P_INC_12	(0x1cU << OPAx_CALR_PCAL_Pos)
#define	OPAx_CALR_PCAL_P_INC_13	(0x1dU << OPAx_CALR_PCAL_Pos)
#define	OPAx_CALR_PCAL_P_INC_14	(0x1eU << OPAx_CALR_PCAL_Pos)
#define	OPAx_CALR_PCAL_P_INC_15	(0x1fU << OPAx_CALR_PCAL_Pos)	/* 11111：输出电压增加最大 */

#define	OPAx_IER_FIE_Pos	1	/* OPA比较器模式输出下降沿中断使能
(OPA comparator mode fall interrupt enable)
 */
#define	OPAx_IER_FIE_Msk	(0x1U << OPAx_IER_FIE_Pos)
	/* 0：禁止中断输出 */
	/* 1：使能中断输出 */

#define	OPAx_IER_RIE_Pos	0	/* OPA比较器模式输出上升沿中断使能
(OPA comparator mode rise interrupt enable)
 */
#define	OPAx_IER_RIE_Msk	(0x1U << OPAx_IER_RIE_Pos)
	/* 0：禁止中断输出 */
	/* 1：使能中断输出 */

#define	OPAx_ISR_OUT_Pos	15	/* OPA比较器模式输出电平，只读 
(OPA comparator mode output)
 */
#define	OPAx_ISR_OUT_Msk	(0x1U << OPAx_ISR_OUT_Pos)

#define	OPAx_ISR_FIF_Pos	1	/* OPA比较器模式输出下降沿中断标志，硬件置位，软件写1清零 (OPA comparator mode fall interrupt flag) */
#define	OPAx_ISR_FIF_Msk	(0x1U << OPAx_ISR_FIF_Pos)

#define	OPAx_ISR_RIF_Pos	0	/* OPA比较器模式输出上升沿中断标志，硬件置位，软件写1清零 (OPA comparator mode rise interrupt flag) */
#define	OPAx_ISR_RIF_Msk	(0x1U << OPAx_ISR_RIF_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void OPAx_Deinit(void);

/* VREF BUFFER使能信号 (VREF buffer enable) 相关函数 */
extern void OPAx_CR_BUFOFF_EN_Setable(OPA_Type* OPAx, FunState NewState);
extern FunState OPAx_CR_BUFOFF_EN_Getable(OPA_Type* OPAx);

/* VREF BUFFER旁路控制 (VREF buffer bypass) 相关函数 */
extern void OPAx_CR_BUFBYP_Setable(OPA_Type* OPAx, FunState NewState);
extern FunState OPAx_CR_BUFBYP_Getable(OPA_Type* OPAx);

/* OPA负端输入选择 (OPA Negtive Input Select) 相关函数 */
extern void OPAx_CR_VNSEL_Set(OPA_Type* OPAx, uint32_t SetValue);
extern uint32_t OPAx_CR_VNSEL_Get(OPA_Type* OPAx);

/* OPA正端输入选择 (OPA Positive Input Select) 相关函数 */
extern void OPAx_CR_VPSEL_Set(OPA_Type* OPAx, uint32_t SetValue);
extern uint32_t OPAx_CR_VPSEL_Get(OPA_Type* OPAx);

/* OPA比较器模式输出数字滤波使能（仅OPA配置为比较器模式下有效） (OPA Comparator mode digital filter) 相关函数 */
extern void OPAx_CR_DF_Setable(OPA_Type* OPAx, FunState NewState);
extern FunState OPAx_CR_DF_Getable(OPA_Type* OPAx);

/* OPA负端连接GPIO，仅OPAxMOD=10时有效
(OPA Negtive Input Connected to GPIO)
 相关函数 */
extern void OPAx_CR_VN_EXC_Setable(OPA_Type* OPAx, FunState NewState);
extern FunState OPAx_CR_VN_EXC_Getable(OPA_Type* OPAx);

/* PGA增益选择 (PGA gain select) 相关函数 */
extern void OPAx_CR_PGA_GAIN_Set(OPA_Type* OPAx, uint32_t SetValue);
extern uint32_t OPAx_CR_PGA_GAIN_Get(OPA_Type* OPAx);

/* OPA工作模式 (OPA mode) 相关函数 */
extern void OPAx_CR_MOD_Set(OPA_Type* OPAx, uint32_t SetValue);
extern uint32_t OPAx_CR_MOD_Get(OPA_Type* OPAx);

/* OPA低功耗控制寄存器 (OPA low power mode) 相关函数 */
extern void OPAx_CR_LPM_Set(OPA_Type* OPAx, uint32_t SetValue);
extern uint32_t OPAx_CR_LPM_Get(OPA_Type* OPAx);

/* OPA使能寄存器 (OPA enable) 相关函数 */
extern void OPAx_CR_EN_Setable(OPA_Type* OPAx, FunState NewState);
extern FunState OPAx_CR_EN_Getable(OPA_Type* OPAx);

/* OPA负端输入校准使能 相关函数 */
extern void OPAx_CALR_NCAL_EN_Setable(OPA_Type* OPAx, FunState NewState);
extern FunState OPAx_CALR_NCAL_EN_Getable(OPA_Type* OPAx);

/* OPA负输入端校准trim信号，最高位为符号位 相关函数 */
extern void OPAx_CALR_NCAL_Set(OPA_Type* OPAx, uint32_t SetValue);
extern uint32_t OPAx_CALR_NCAL_Get(OPA_Type* OPAx);

/* OPA正端输入校准使能 相关函数 */
extern void OPAx_CALR_PCAL_EN_Setable(OPA_Type* OPAx, FunState NewState);
extern FunState OPAx_CALR_PCAL_EN_Getable(OPA_Type* OPAx);

/* OPA正输入端校准trim信号，最高位为符号位 相关函数 */
extern void OPAx_CALR_PCAL_Set(OPA_Type* OPAx, uint32_t SetValue);
extern uint32_t OPAx_CALR_PCAL_Get(OPA_Type* OPAx);

/* OPA比较器模式输出下降沿中断使能
(OPA comparator mode fall interrupt enable)
 相关函数 */
extern void OPAx_IER_FIE_Setable(OPA_Type* OPAx, FunState NewState);
extern FunState OPAx_IER_FIE_Getable(OPA_Type* OPAx);

/* OPA比较器模式输出上升沿中断使能
(OPA comparator mode rise interrupt enable)
 相关函数 */
extern void OPAx_IER_RIE_Setable(OPA_Type* OPAx, FunState NewState);
extern FunState OPAx_IER_RIE_Getable(OPA_Type* OPAx);

/* OPA比较器模式输出电平，只读 
(OPA comparator mode output)
 相关函数 */
extern FlagStatus OPAx_ISR_OUT_Chk(OPA_Type* OPAx);

/* OPA比较器模式输出下降沿中断标志，硬件置位，软件写1清零 (OPA comparator mode fall interrupt flag) 相关函数 */
extern void OPAx_ISR_FIF_Clr(OPA_Type* OPAx);
extern FlagStatus OPAx_ISR_FIF_Chk(OPA_Type* OPAx);

/* OPA比较器模式输出上升沿中断标志，硬件置位，软件写1清零 (OPA comparator mode rise interrupt flag) 相关函数 */
extern void OPAx_ISR_RIF_Clr(OPA_Type* OPAx);
extern FlagStatus OPAx_ISR_RIF_Chk(OPA_Type* OPAx);
//Announce_End

#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_DBG_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
