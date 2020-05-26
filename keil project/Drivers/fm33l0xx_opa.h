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
#define	OPAx_CR_BUFOFF_EN_Pos	31	/* VREF BUFFERʹ���ź� (VREF buffer enable) */
#define	OPAx_CR_BUFOFF_EN_Msk	(0x1U << OPAx_CR_BUFOFF_EN_Pos)
	/* 0��ʹ��VREF BUFFER */
	/* 1���ر�VREF BUFFER */

#define	OPAx_CR_BUFBYP_Pos	30	/* VREF BUFFER��·���� (VREF buffer bypass) */
#define	OPAx_CR_BUFBYP_Msk	(0x1U << OPAx_CR_BUFBYP_Pos)
	/* 0����bypass VREF BUFFER */
	/* 1��bypass VREF BUFFER */

#define	OPAx_CR_VNSEL_Pos	9	/* OPA��������ѡ�� (OPA Negtive Input Select) */
#define	OPAx_CR_VNSEL_Msk	(0x7U << OPAx_CR_VNSEL_Pos)
#define	OPAx_CR_VNSEL_OPA1_INN1	(0x0U << OPAx_CR_VNSEL_Pos)	/* 000��OPA_INN1 */
#define	OPAx_CR_VNSEL_OPA1_INN2	(0x1U << OPAx_CR_VNSEL_Pos)	/* 001��OPA_INN2 */
#define	OPAx_CR_VNSEL_VREF	(0x2U << OPAx_CR_VNSEL_Pos)	/* 010��VREF */
#define	OPAx_CR_VNSEL_3_4_VREF	(0x3U << OPAx_CR_VNSEL_Pos)	/* 011��3/4 VREF */
#define	OPAx_CR_VNSEL_1_2_VREF	(0x4U << OPAx_CR_VNSEL_Pos)	/* 100��1/2 VREF */
#define	OPAx_CR_VNSEL_1_4_VREF	(0x5U << OPAx_CR_VNSEL_Pos)	/* 101��1/4 VREF */
#define	OPAx_CR_VNSEL_1_8_VREF	(0x6U << OPAx_CR_VNSEL_Pos)	/* 110��1/8 VREF */

#define	OPAx_CR_VPSEL_Pos	8	/* OPA��������ѡ�� (OPA Positive Input Select) */
#define	OPAx_CR_VPSEL_Msk	(0x1U << OPAx_CR_VPSEL_Pos)
#define	OPAx_CR_VPSEL_OPA1_INP1	(0x0U << OPAx_CR_VPSEL_Pos)	/* 0��OPA_INP1 */
#define	OPAx_CR_VPSEL_OPA1_INP2	(0x1U << OPAx_CR_VPSEL_Pos)	/* 1��OPA_INP2 */

#define	OPAx_CR_DF_Pos	7	/* OPA�Ƚ���ģʽ��������˲�ʹ�ܣ���OPA����Ϊ�Ƚ���ģʽ����Ч�� (OPA Comparator mode digital filter) */
#define	OPAx_CR_DF_Msk	(0x1U << OPAx_CR_DF_Pos)
	/* 0���رձȽ�����������˲� */
	/* 1���򿪱Ƚ�����������˲� */

#define	OPAx_CR_VN_EXC_Pos	6	/* OPA��������GPIO����OPAxMOD=10ʱ��Ч
(OPA Negtive Input Connected to GPIO)
 */
#define	OPAx_CR_VN_EXC_Msk	(0x1U << OPAx_CR_VN_EXC_Pos)
	/* 0��PGAģʽ��OPA1���˲�����GPIO */
	/* 1��PGAģʽ��OPA1����ͬʱ���ӵ�GPIO */

#define	OPAx_CR_PGA_GAIN_Pos	4	/* PGA����ѡ�� (PGA gain select) */
#define	OPAx_CR_PGA_GAIN_Msk	(0x3U << OPAx_CR_PGA_GAIN_Pos)
#define	OPAx_CR_PGA_GAIN_GAIN_2	(0x0U << OPAx_CR_PGA_GAIN_Pos)	/* 00��PGA����x2 */
#define	OPAx_CR_PGA_GAIN_GAIN_4	(0x1U << OPAx_CR_PGA_GAIN_Pos)	/* 01��PGA����x4 */
#define	OPAx_CR_PGA_GAIN_GAIN_8	(0x2U << OPAx_CR_PGA_GAIN_Pos)	/* 10��PGA����x8 */
#define	OPAx_CR_PGA_GAIN_GAIN_16	(0x3U << OPAx_CR_PGA_GAIN_Pos)	/* 11��PGA����x16 */

#define	OPAx_CR_MOD_Pos	2	/* OPA����ģʽ (OPA mode) */
#define	OPAx_CR_MOD_Msk	(0x3U << OPAx_CR_MOD_Pos)
#define	OPAx_CR_MOD_MOD_STANDALONE	(0x0U << OPAx_CR_MOD_Pos)	/* 00��standaloneģʽ */
#define	OPAx_CR_MOD_MOD_CMP	(0x1U << OPAx_CR_MOD_Pos)	/* 01���Ƚ���ģʽ */
#define	OPAx_CR_MOD_MOD_PGA	(0x2U << OPAx_CR_MOD_Pos)	/* 10��PGAģʽ */
#define	OPAx_CR_MOD_MOD_BUF	(0x3U << OPAx_CR_MOD_Pos)	/* 11��bufferģʽ */

#define	OPAx_CR_LPM_Pos	1	/* OPA�͹��Ŀ��ƼĴ��� (OPA low power mode) */
#define	OPAx_CR_LPM_Msk	(0x1U << OPAx_CR_LPM_Pos)
#define	OPAx_CR_LPM_NORMAL_POWER	(0x0U << OPAx_CR_LPM_Pos)	/* 0������ģʽ */
#define	OPAx_CR_LPM_LOW_POWER	(0x1U << OPAx_CR_LPM_Pos)	/* 1���͹���ģʽ */

#define	OPAx_CR_EN_Pos	0	/* OPAʹ�ܼĴ��� (OPA enable) */
#define	OPAx_CR_EN_Msk	(0x1U << OPAx_CR_EN_Pos)
	/* 0���ر�OPA */
	/* 1��ʹ��OPA */

#define	OPAx_CALR_NCAL_EN_Pos	31	/* OPA��������У׼ʹ�� */
#define	OPAx_CALR_NCAL_EN_Msk	(0x1U << OPAx_CALR_NCAL_EN_Pos)
	/* 0���ر�OPA����У׼ */
	/* 1��ʹ��OPA����У׼ */

#define	OPAx_CALR_NCAL_Pos	16	/* OPA�������У׼trim�źţ����λΪ����λ */
#define	OPAx_CALR_NCAL_Msk	(0x1fU << OPAx_CALR_NCAL_Pos)
#define	OPAx_CALR_NCAL_N_DEC_0	(0x0U << OPAx_CALR_NCAL_Pos)	/* 00000�������ѹ���� */
#define	OPAx_CALR_NCAL_N_DEC_1	(0x1U << OPAx_CALR_NCAL_Pos)	/* 00001�������ѹ��С��С */
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
#define	OPAx_CALR_NCAL_N_DEC_15	(0xfU << OPAx_CALR_NCAL_Pos)	/* 01111�������ѹ��С��� */
#define	OPAx_CALR_NCAL_N_INC_0	(0x10U << OPAx_CALR_NCAL_Pos)	/* 10000�������ѹ���� */
#define	OPAx_CALR_NCAL_N_INC_1	(0x11U << OPAx_CALR_NCAL_Pos)	/* 10001�������ѹ������С */
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
#define	OPAx_CALR_NCAL_N_INC_15	(0x1fU << OPAx_CALR_NCAL_Pos)	/* 11111�������ѹ������� */

#define	OPAx_CALR_PCAL_EN_Pos	15	/* OPA��������У׼ʹ�� */
#define	OPAx_CALR_PCAL_EN_Msk	(0x1U << OPAx_CALR_PCAL_EN_Pos)

#define	OPAx_CALR_PCAL_Pos	0	/* OPA�������У׼trim�źţ����λΪ����λ */
#define	OPAx_CALR_PCAL_Msk	(0x1fU << OPAx_CALR_PCAL_Pos)
#define	OPAx_CALR_PCAL_P_DEC_0	(0x0U << OPAx_CALR_PCAL_Pos)	/* 00000�������ѹ���� */
#define	OPAx_CALR_PCAL_P_DEC_1	(0x1U << OPAx_CALR_PCAL_Pos)	/* 00001�������ѹ��С��С */
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
#define	OPAx_CALR_PCAL_P_DEC_15	(0xfU << OPAx_CALR_PCAL_Pos)	/* 01111�������ѹ��С��� */
#define	OPAx_CALR_PCAL_P_INC_0	(0x10U << OPAx_CALR_PCAL_Pos)	/* 10000�������ѹ���� */
#define	OPAx_CALR_PCAL_P_INC_1	(0x11U << OPAx_CALR_PCAL_Pos)	/* 10001�������ѹ������С */
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
#define	OPAx_CALR_PCAL_P_INC_15	(0x1fU << OPAx_CALR_PCAL_Pos)	/* 11111�������ѹ������� */

#define	OPAx_IER_FIE_Pos	1	/* OPA�Ƚ���ģʽ����½����ж�ʹ��
(OPA comparator mode fall interrupt enable)
 */
#define	OPAx_IER_FIE_Msk	(0x1U << OPAx_IER_FIE_Pos)
	/* 0����ֹ�ж���� */
	/* 1��ʹ���ж���� */

#define	OPAx_IER_RIE_Pos	0	/* OPA�Ƚ���ģʽ����������ж�ʹ��
(OPA comparator mode rise interrupt enable)
 */
#define	OPAx_IER_RIE_Msk	(0x1U << OPAx_IER_RIE_Pos)
	/* 0����ֹ�ж���� */
	/* 1��ʹ���ж���� */

#define	OPAx_ISR_OUT_Pos	15	/* OPA�Ƚ���ģʽ�����ƽ��ֻ�� 
(OPA comparator mode output)
 */
#define	OPAx_ISR_OUT_Msk	(0x1U << OPAx_ISR_OUT_Pos)

#define	OPAx_ISR_FIF_Pos	1	/* OPA�Ƚ���ģʽ����½����жϱ�־��Ӳ����λ�����д1���� (OPA comparator mode fall interrupt flag) */
#define	OPAx_ISR_FIF_Msk	(0x1U << OPAx_ISR_FIF_Pos)

#define	OPAx_ISR_RIF_Pos	0	/* OPA�Ƚ���ģʽ����������жϱ�־��Ӳ����λ�����д1���� (OPA comparator mode rise interrupt flag) */
#define	OPAx_ISR_RIF_Msk	(0x1U << OPAx_ISR_RIF_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void OPAx_Deinit(void);

/* VREF BUFFERʹ���ź� (VREF buffer enable) ��غ��� */
extern void OPAx_CR_BUFOFF_EN_Setable(OPA_Type* OPAx, FunState NewState);
extern FunState OPAx_CR_BUFOFF_EN_Getable(OPA_Type* OPAx);

/* VREF BUFFER��·���� (VREF buffer bypass) ��غ��� */
extern void OPAx_CR_BUFBYP_Setable(OPA_Type* OPAx, FunState NewState);
extern FunState OPAx_CR_BUFBYP_Getable(OPA_Type* OPAx);

/* OPA��������ѡ�� (OPA Negtive Input Select) ��غ��� */
extern void OPAx_CR_VNSEL_Set(OPA_Type* OPAx, uint32_t SetValue);
extern uint32_t OPAx_CR_VNSEL_Get(OPA_Type* OPAx);

/* OPA��������ѡ�� (OPA Positive Input Select) ��غ��� */
extern void OPAx_CR_VPSEL_Set(OPA_Type* OPAx, uint32_t SetValue);
extern uint32_t OPAx_CR_VPSEL_Get(OPA_Type* OPAx);

/* OPA�Ƚ���ģʽ��������˲�ʹ�ܣ���OPA����Ϊ�Ƚ���ģʽ����Ч�� (OPA Comparator mode digital filter) ��غ��� */
extern void OPAx_CR_DF_Setable(OPA_Type* OPAx, FunState NewState);
extern FunState OPAx_CR_DF_Getable(OPA_Type* OPAx);

/* OPA��������GPIO����OPAxMOD=10ʱ��Ч
(OPA Negtive Input Connected to GPIO)
 ��غ��� */
extern void OPAx_CR_VN_EXC_Setable(OPA_Type* OPAx, FunState NewState);
extern FunState OPAx_CR_VN_EXC_Getable(OPA_Type* OPAx);

/* PGA����ѡ�� (PGA gain select) ��غ��� */
extern void OPAx_CR_PGA_GAIN_Set(OPA_Type* OPAx, uint32_t SetValue);
extern uint32_t OPAx_CR_PGA_GAIN_Get(OPA_Type* OPAx);

/* OPA����ģʽ (OPA mode) ��غ��� */
extern void OPAx_CR_MOD_Set(OPA_Type* OPAx, uint32_t SetValue);
extern uint32_t OPAx_CR_MOD_Get(OPA_Type* OPAx);

/* OPA�͹��Ŀ��ƼĴ��� (OPA low power mode) ��غ��� */
extern void OPAx_CR_LPM_Set(OPA_Type* OPAx, uint32_t SetValue);
extern uint32_t OPAx_CR_LPM_Get(OPA_Type* OPAx);

/* OPAʹ�ܼĴ��� (OPA enable) ��غ��� */
extern void OPAx_CR_EN_Setable(OPA_Type* OPAx, FunState NewState);
extern FunState OPAx_CR_EN_Getable(OPA_Type* OPAx);

/* OPA��������У׼ʹ�� ��غ��� */
extern void OPAx_CALR_NCAL_EN_Setable(OPA_Type* OPAx, FunState NewState);
extern FunState OPAx_CALR_NCAL_EN_Getable(OPA_Type* OPAx);

/* OPA�������У׼trim�źţ����λΪ����λ ��غ��� */
extern void OPAx_CALR_NCAL_Set(OPA_Type* OPAx, uint32_t SetValue);
extern uint32_t OPAx_CALR_NCAL_Get(OPA_Type* OPAx);

/* OPA��������У׼ʹ�� ��غ��� */
extern void OPAx_CALR_PCAL_EN_Setable(OPA_Type* OPAx, FunState NewState);
extern FunState OPAx_CALR_PCAL_EN_Getable(OPA_Type* OPAx);

/* OPA�������У׼trim�źţ����λΪ����λ ��غ��� */
extern void OPAx_CALR_PCAL_Set(OPA_Type* OPAx, uint32_t SetValue);
extern uint32_t OPAx_CALR_PCAL_Get(OPA_Type* OPAx);

/* OPA�Ƚ���ģʽ����½����ж�ʹ��
(OPA comparator mode fall interrupt enable)
 ��غ��� */
extern void OPAx_IER_FIE_Setable(OPA_Type* OPAx, FunState NewState);
extern FunState OPAx_IER_FIE_Getable(OPA_Type* OPAx);

/* OPA�Ƚ���ģʽ����������ж�ʹ��
(OPA comparator mode rise interrupt enable)
 ��غ��� */
extern void OPAx_IER_RIE_Setable(OPA_Type* OPAx, FunState NewState);
extern FunState OPAx_IER_RIE_Getable(OPA_Type* OPAx);

/* OPA�Ƚ���ģʽ�����ƽ��ֻ�� 
(OPA comparator mode output)
 ��غ��� */
extern FlagStatus OPAx_ISR_OUT_Chk(OPA_Type* OPAx);

/* OPA�Ƚ���ģʽ����½����жϱ�־��Ӳ����λ�����д1���� (OPA comparator mode fall interrupt flag) ��غ��� */
extern void OPAx_ISR_FIF_Clr(OPA_Type* OPAx);
extern FlagStatus OPAx_ISR_FIF_Chk(OPA_Type* OPAx);

/* OPA�Ƚ���ģʽ����������жϱ�־��Ӳ����λ�����д1���� (OPA comparator mode rise interrupt flag) ��غ��� */
extern void OPAx_ISR_RIF_Clr(OPA_Type* OPAx);
extern FlagStatus OPAx_ISR_RIF_Chk(OPA_Type* OPAx);
//Announce_End

#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_DBG_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
