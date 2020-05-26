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
#define	LPTIM_CFGR_ETR_AFEN_Pos	24	/* ETR����ģ���˲�ʹ�� (External Trigger input Analog Filter Enable) */
#define	LPTIM_CFGR_ETR_AFEN_Msk	(0x1U << LPTIM_CFGR_ETR_AFEN_Pos)
	/* 0���ر�ģ���˲� */
	/* 1��ʹ��ģ���˲����˲����Լ100ns */

#define	LPTIM_CFGR_PSCSEL_Pos	14	/* ʱ��Ԥ��Ƶ����ѡ�� (Prescaler input Select) */
#define	LPTIM_CFGR_PSCSEL_Msk	(0x1U << LPTIM_CFGR_PSCSEL_Pos)
#define	LPTIM_CFGR_PSCSEL_CLKSEL	(0x0U << LPTIM_CFGR_PSCSEL_Pos)	/* 0��CLKSELѡ���ʱ�� */
#define	LPTIM_CFGR_PSCSEL_LPTINSEL	(0x1U << LPTIM_CFGR_PSCSEL_Pos)	/* 1��LPTINSELѡ����ź� */

#define	LPTIM_CFGR_INSEL_Pos	13	/* ETR����Դѡ�� (External Trigger input source Select) */
#define	LPTIM_CFGR_INSEL_Msk	(0x1U << LPTIM_CFGR_INSEL_Pos)
#define	LPTIM_CFGR_INSEL_PIN	(0x0U << LPTIM_CFGR_INSEL_Pos)	/* 0���������� */
#define	LPTIM_CFGR_INSEL_ADC_EOC	(0x1U << LPTIM_CFGR_INSEL_Pos)	/* 1��ADC_EOC */

#define	LPTIM_CFGR_DIVSEL_Pos	10	/* ����ʱ�ӷ�Ƶѡ�� (Counter Clock Divider Select) */
#define	LPTIM_CFGR_DIVSEL_Msk	(0x7U << LPTIM_CFGR_DIVSEL_Pos)
#define	LPTIM_CFGR_DIVSEL_DIV1	(0x0U << LPTIM_CFGR_DIVSEL_Pos)	/* 000��1��Ƶ */
#define	LPTIM_CFGR_DIVSEL_DIV2	(0x1U << LPTIM_CFGR_DIVSEL_Pos)	/* 001��2��Ƶ */
#define	LPTIM_CFGR_DIVSEL_DIV4	(0x2U << LPTIM_CFGR_DIVSEL_Pos)	/* 010��4��Ƶ */
#define	LPTIM_CFGR_DIVSEL_DIV8	(0x3U << LPTIM_CFGR_DIVSEL_Pos)	/* 011��8��Ƶ */
#define	LPTIM_CFGR_DIVSEL_DIV16	(0x4U << LPTIM_CFGR_DIVSEL_Pos)	/* 100��16��Ƶ */
#define	LPTIM_CFGR_DIVSEL_DIV32	(0x5U << LPTIM_CFGR_DIVSEL_Pos)	/* 101��32��Ƶ */
#define	LPTIM_CFGR_DIVSEL_DIV64	(0x6U << LPTIM_CFGR_DIVSEL_Pos)	/* 110��64��Ƶ */
#define	LPTIM_CFGR_DIVSEL_DIV128	(0x7U << LPTIM_CFGR_DIVSEL_Pos)	/* 111��128��Ƶ */

#define	LPTIM_CFGR_EDGESEL_Pos	7	/* ETR�������ѡ�� (ETR Clock Edge Select) */
#define	LPTIM_CFGR_EDGESEL_Msk	(0x1U << LPTIM_CFGR_EDGESEL_Pos)
#define	LPTIM_CFGR_EDGESEL_RISING	(0x0U << LPTIM_CFGR_EDGESEL_Pos)	/* 0��LPT_ETR�������ؼ��� */
#define	LPTIM_CFGR_EDGESEL_FALLING	(0x1U << LPTIM_CFGR_EDGESEL_Pos)	/* 1��LPT_ETR���½��ؼ��� */

#define	LPTIM_CFGR_TRIGCFG_Pos	5	/* �ⲿ��������ѡ����ʹ���ڲ�ʱ��ͬ������LPT_ETR��(ETR trigger Configuration) */
#define	LPTIM_CFGR_TRIGCFG_Msk	(0x3U << LPTIM_CFGR_TRIGCFG_Pos)
#define	LPTIM_CFGR_TRIGCFG_RISING	(0x0U << LPTIM_CFGR_TRIGCFG_Pos)	/* 00: LPT_ETR�����ź������ش��� */
#define	LPTIM_CFGR_TRIGCFG_FALLING	(0x1U << LPTIM_CFGR_TRIGCFG_Pos)	/* 01: LPT_ETR�����ź��½��ش��� */
#define	LPTIM_CFGR_TRIGCFG_BOTH (0x2U << LPTIM_CFGR_TRIGCFG_Pos)	/* 10���ⲿ�����ź������½��ش��� */


#define	LPTIM_CFGR_ONST_Pos	2	/* ���μ���ģʽʹ�� (One State Timer) */
#define	LPTIM_CFGR_ONST_Msk	(0x1U << LPTIM_CFGR_ONST_Pos)
#define	LPTIM_CFGR_ONST_CONTINUE	(0x0U << LPTIM_CFGR_ONST_Pos)	/* 0����������ģʽ���������������󱣳����У�ֱ�����ر�Ϊֹ���������ﵽĿ��ֵ��ص�0���¿�ʼ����������������жϡ� */
#define	LPTIM_CFGR_ONST_SINGLE	(0x1U << LPTIM_CFGR_ONST_Pos)	/* 1�����μ���ģʽ���������������������Ŀ��ֵ��ص�0�����Զ�ֹͣ����������жϡ� */

#define	LPTIM_CFGR_TMOD_Pos	0	/* ����ģʽѡ�� (Timer operation Mode) */
#define	LPTIM_CFGR_TMOD_Msk	(0x3U << LPTIM_CFGR_TMOD_Pos)
#define	LPTIM_CFGR_TMOD_NORMAL	(0x0U << LPTIM_CFGR_TMOD_Pos)	/* 00����ͨ��ʱ��ģʽ */
#define	LPTIM_CFGR_TMOD_TRIGGER	(0x1U << LPTIM_CFGR_TMOD_Pos)	/* 01��Trigger���崥������ģʽ */
#define	LPTIM_CFGR_TMOD_EXASYN	(0x2U << LPTIM_CFGR_TMOD_Pos)	/* 10���ⲿ�첽�������ģʽ */
#define	LPTIM_CFGR_TMOD_TIMEOUT	(0x3U << LPTIM_CFGR_TMOD_Pos)	/* 11��Timeoutģʽ */

#define	LPTIM_CNT_CNT32_Pos	0	/* 32bit��������ǰ����ֵ (Counter 32bits-wide) */
#define	LPTIM_CNT_CNT32_Msk	(0xffffffffU << LPTIM_CNT_CNT32_Pos)

#define	LPTIM_CCSR_CAP1SSEL_Pos	16	/* ͨ��1��׽�ź�Դѡ�� (Channel 1 Capture Source Select) */
#define	LPTIM_CCSR_CAP1SSEL_Msk	(0x3U << LPTIM_CCSR_CAP1SSEL_Pos)
#define	LPTIM_CCSR_CAP1SSEL_LPT32_CH1	(0x0U << LPTIM_CCSR_CAP1SSEL_Pos)	/* 00��LPT32_CH1���� */
#define	LPTIM_CCSR_CAP1SSEL_XTLF	(0x1U << LPTIM_CCSR_CAP1SSEL_Pos)	/* 01��XTLF */
#define	LPTIM_CCSR_CAP1SSEL_RCLP	(0x2U << LPTIM_CCSR_CAP1SSEL_Pos)	/* 10��RCLP */
#define	LPTIM_CCSR_CAP1SSEL_RC4M_PSC	(0x3U << LPTIM_CCSR_CAP1SSEL_Pos)	/* 11��RC4M_PSC */

#define	LPTIM_CCSR_CAP2EDGE_Pos	13	/* ͨ��2��ǰ����׽�ı��أ���CC2IF��λʱ���� (Channel2 Captured Edge) */
#define	LPTIM_CCSR_CAP2EDGE_Msk	(0x1U << LPTIM_CCSR_CAP2EDGE_Pos)

#define	LPTIM_CCSR_CAP1EDGE_Pos	12	/* ͨ��1��ǰ����׽�ı��أ���CC1IF��λʱ���� (Channel 1 Captured Edge) */
#define	LPTIM_CCSR_CAP1EDGE_Msk	(0x1U << LPTIM_CCSR_CAP1EDGE_Pos)

#define	LPTIM_CCSR_CAPCFG2_Pos	10	/* ͨ��2��׽����ѡ�� (Channel 2 Capture edge Config) */
#define	LPTIM_CCSR_CAPCFG2_Msk	(0x3U << LPTIM_CCSR_CAPCFG2_Pos)
#define	LPTIM_CCSR_CAPCFG2_RISING	(0x0U << LPTIM_CCSR_CAPCFG2_Pos)	/* 00�������ز�׽ */
#define	LPTIM_CCSR_CAPCFG2_FALLING	(0x1U << LPTIM_CCSR_CAPCFG2_Pos)	/* 01���½��ز�׽ */
#define	LPTIM_CCSR_CAPCFG2_BOTH	(0x2U << LPTIM_CCSR_CAPCFG2_Pos)	/* 10�������½��ز�׽ */

#define	LPTIM_CCSR_CAPCFG1_Pos	8	/* ͨ��1��׽����ѡ�� (Channel 1 Capture edge Config) */
#define	LPTIM_CCSR_CAPCFG1_Msk	(0x3U << LPTIM_CCSR_CAPCFG1_Pos)
#define	LPTIM_CCSR_CAPCFG1_RISING	(0x0U << LPTIM_CCSR_CAPCFG1_Pos)	/* 00�������ز�׽ */
#define	LPTIM_CCSR_CAPCFG1_FALLING	(0x1U << LPTIM_CCSR_CAPCFG1_Pos)	/* 01���½��ز�׽ */
#define	LPTIM_CCSR_CAPCFG1_BOTH	(0x2U << LPTIM_CCSR_CAPCFG1_Pos)	/* 10�������½��ز�׽ */

#define	LPTIM_CCSR_POLAR2_Pos	5	/* ͨ��2�Ƚ�������μ���ѡ�� (Channel 2 compare output Polarity) */
#define	LPTIM_CCSR_POLAR2_Msk	(0x1U << LPTIM_CCSR_POLAR2_Pos)
#define	LPTIM_CCSR_POLAR2_POS	(0x0U << LPTIM_CCSR_POLAR2_Pos)	/* 0�������Բ��Σ���ʼΪ�ͣ�����ֵ==�Ƚ�ֵʱ�øߣ�����ֵ==ARRʱ�ָ�Ϊ�� */
#define	LPTIM_CCSR_POLAR2_NEG	(0x1U << LPTIM_CCSR_POLAR2_Pos)	/* 1�������Բ��Σ������Բ���ȡ�� */

#define	LPTIM_CCSR_POLAR1_Pos	4	/* ͨ��1�Ƚ�������μ���ѡ�� (Channel 1 compare output Polarity) */
#define	LPTIM_CCSR_POLAR1_Msk	(0x1U << LPTIM_CCSR_POLAR1_Pos)
#define	LPTIM_CCSR_POLAR1_POS	(0x0U << LPTIM_CCSR_POLAR1_Pos)	/* 0�������Բ��Σ���ʼΪ�ͣ�����ֵ==�Ƚ�ֵʱ�øߣ�����ֵ==ARRʱ�ָ�Ϊ�� */
#define	LPTIM_CCSR_POLAR1_NEG	(0x1U << LPTIM_CCSR_POLAR1_Pos)	/* 1�������Բ��Σ������Բ���ȡ�� */

#define	LPTIM_CCSR_CC2S_Pos	2	/* ͨ��2��׽/�ȽϹ���ʹ�� (Channel 2 Capture/Compare Select) */
#define	LPTIM_CCSR_CC2S_Msk	(0x3U << LPTIM_CCSR_CC2S_Pos)
#define	LPTIM_CCSR_CC2S_DISABLE	(0x0U << LPTIM_CCSR_CC2S_Pos)	/* 00����ֹͨ��2��׽/�ȽϹ��� */
#define	LPTIM_CCSR_CC2S_CAPTURE	(0x1U << LPTIM_CCSR_CC2S_Pos)	/* 01��ʹ��ͨ��2��׽���ܣ�LPT32_CH2Ϊ���룩 */
#define	LPTIM_CCSR_CC2S_COMPARE	(0x2U << LPTIM_CCSR_CC2S_Pos)	/* 10��ʹ��ͨ��2�ȽϹ��ܣ�LPT32_CH2Ϊ����� */

#define	LPTIM_CCSR_CC1S_Pos	0	/* ͨ��1��׽/�ȽϹ���ʹ�� (Channel 1 Capture/Compare Select) */
#define	LPTIM_CCSR_CC1S_Msk	(0x3U << LPTIM_CCSR_CC1S_Pos)
#define	LPTIM_CCSR_CC1S_DISABLE	(0x0U << LPTIM_CCSR_CC1S_Pos)	/* 00����ֹͨ��1��׽/�ȽϹ��� */
#define	LPTIM_CCSR_CC1S_CAPTURE	(0x1U << LPTIM_CCSR_CC1S_Pos)	/* 01��ʹ��ͨ��1��׽���ܣ�LPT32_CH1Ϊ���룩 */
#define	LPTIM_CCSR_CC1S_COMPARE	(0x2U << LPTIM_CCSR_CC1S_Pos)	/* 10��ʹ��ͨ��1�ȽϹ��ܣ�LPT32_CH1Ϊ����� */

#define	LPTIM_ARR_ARR_Pos	0	/* �Զ�����Ŀ��Ĵ��� (Auto-Reload Register) */
#define	LPTIM_ARR_ARR_Msk	(0xffffffffU << LPTIM_ARR_ARR_Pos)

#define	LPTIM_IER_OVR2IE_Pos	9	/* ͨ��2��׽����ж�ʹ�� (Channel 2 Over-Capture Interrupt Enable) */
#define	LPTIM_IER_OVR2IE_Msk	(0x1U << LPTIM_IER_OVR2IE_Pos)
	/* 0����ֹ�ж� */
	/* 1�������ж� */

#define	LPTIM_IER_OVR1IE_Pos	8	/* ͨ��1��׽����ж�ʹ�� (Channel 1 Over-Capture Interrupt Enable) */
#define	LPTIM_IER_OVR1IE_Msk	(0x1U << LPTIM_IER_OVR1IE_Pos)
	/* 0����ֹ�ж� */
	/* 1�������ж� */

#define	LPTIM_IER_TRIGIE_Pos	3	/* �ⲿ���������ж�ʹ��λ (External Trigger Interrupt Enable) */
#define	LPTIM_IER_TRIGIE_Msk	(0x1U << LPTIM_IER_TRIGIE_Pos)
	/* 0���ⲿ���������жϽ�ֹ */
	/* 1���ⲿ���������ж�ʹ�� */

#define	LPTIM_IER_OVIE_Pos	2	/* ����������ж�ʹ��λ (Counter Over-Flow Interrupt Enable) */
#define	LPTIM_IER_OVIE_Msk	(0x1U << LPTIM_IER_OVIE_Pos)
	/* 0������������жϽ�ֹ */
	/* 1������������ж�ʹ�� */

#define	LPTIM_IER_CC2IE_Pos	1	/* ��׽/�Ƚ�ͨ��2�ж�ʹ��λ (Capture/Compare channel 2 Interrupt Enable) */
#define	LPTIM_IER_CC2IE_Msk	(0x1U << LPTIM_IER_CC2IE_Pos)
	/* 0����׽/�Ƚ�ͨ��2�жϽ�ֹ */
	/* 1����׽/�Ƚ�ͨ��2�ж�ʹ�� */

#define	LPTIM_IER_CC1IE_Pos	0	/* ��׽/�Ƚ�ͨ��1�ж�ʹ��λ (Capture/Compare channel 1 Interrupt Enable) */
#define	LPTIM_IER_CC1IE_Msk	(0x1U << LPTIM_IER_CC1IE_Pos)
	/* 0����׽/�Ƚ�ͨ��1�жϽ�ֹ */
	/* 1����׽/�Ƚ�ͨ��1�ж�ʹ�� */

#define	LPTIM_ISR_CAP2OVR_Pos	9	/* ͨ��2��׽�����Ӳ����λ�����д1���� (Channel 2 Over-Capture Interrupt Flag) */
#define	LPTIM_ISR_CAP2OVR_Msk	(0x1U << LPTIM_ISR_CAP2OVR_Pos)

#define	LPTIM_ISR_CAP1OVR_Pos	8	/* ͨ��1��׽�����Ӳ����λ�����д1���� (Channel 1 Over-Capture Interrupt Flag) */
#define	LPTIM_ISR_CAP1OVR_Msk	(0x1U << LPTIM_ISR_CAP1OVR_Pos)

#define	LPTIM_ISR_TRIGIF_Pos	3	/* �ⲿ���������жϱ�־λ��д1���� (External Trigger Interrupt Flag) */
#define	LPTIM_ISR_TRIGIF_Msk	(0x1U << LPTIM_ISR_TRIGIF_Pos)

#define	LPTIM_ISR_OVIF_Pos	2	/* ����������ж�ʹ��λ��д1���� (Counter Over-Flow Interrupt Flag) */
#define	LPTIM_ISR_OVIF_Msk	(0x1U << LPTIM_ISR_OVIF_Pos)

#define	LPTIM_ISR_CC2IF_Pos	1	/* ��׽/�Ƚ�ͨ��2�жϱ�־��Ӳ����λ�����д1���� (Capture/Compare channel 2 Interrupt Flag) */
#define	LPTIM_ISR_CC2IF_Msk	(0x1U << LPTIM_ISR_CC2IF_Pos)

#define	LPTIM_ISR_CC1IF_Pos	0	/* ��׽/�Ƚ�ͨ��1�жϱ�־��Ӳ����λ�����д1���� (Capture/Compare channel 1 Interrupt Flag) */
#define	LPTIM_ISR_CC1IF_Msk	(0x1U << LPTIM_ISR_CC1IF_Pos)

#define	LPTIM_CR_EN_Pos	0	/* LPTIMʹ��λ (LPTIM Enable) */
#define	LPTIM_CR_EN_Msk	(0x1U << LPTIM_CR_EN_Pos)
	/* 0����ֹ���������� */
	/* 1��ʹ�ܼ��������� */

#define	LPTIM_CCR1_CCR1_Pos	0	/* ��׽/�Ƚ�ֵ�Ĵ���1 (Channel1 Capture/Compare Register) */
#define	LPTIM_CCR1_CCR1_Msk	(0xffffffffU << LPTIM_CCR1_CCR1_Pos)

#define	LPTIM_CCR2_CCR2_Pos	0	/* ��׽/�Ƚ�ֵ�Ĵ���2 (Channel2 Capture/Compare Register) */
#define	LPTIM_CCR2_CCR2_Msk	(0xffffffffU << LPTIM_CCR2_CCR2_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void LPTIM_Deinit(void);

/* ETR����ģ���˲�ʹ�� (External Trigger input Analog Filter Enable) ��غ��� */
extern void LPTIM_CFGR_ETR_AFEN_Setable(FunState NewState);
extern FunState LPTIM_CFGR_ETR_AFEN_Getable(void);

/* ʱ��Ԥ��Ƶ����ѡ�� (Prescaler input Select) ��غ��� */
extern void LPTIM_CFGR_PSCSEL_Set(uint32_t SetValue);
extern uint32_t LPTIM_CFGR_PSCSEL_Get(void);

/* ETR����Դѡ�� (External Trigger input source Select) ��غ��� */
extern void LPTIM_CFGR_INSEL_Set(uint32_t SetValue);
extern uint32_t LPTIM_CFGR_INSEL_Get(void);

/* ����ʱ�ӷ�Ƶѡ�� (Counter Clock Divider Select) ��غ��� */
extern void LPTIM_CFGR_DIVSEL_Set(uint32_t SetValue);
extern uint32_t LPTIM_CFGR_DIVSEL_Get(void);

/* ETR�������ѡ�� (ETR Clock Edge Select) ��غ��� */
extern void LPTIM_CFGR_EDGESEL_Set(uint32_t SetValue);
extern uint32_t LPTIM_CFGR_EDGESEL_Get(void);

/* �ⲿ��������ѡ����ʹ���ڲ�ʱ��ͬ������LPT_ETR��(ETR trigger Configuration) ��غ��� */
extern void LPTIM_CFGR_TRIGCFG_Set(uint32_t SetValue);
extern uint32_t LPTIM_CFGR_TRIGCFG_Get(void);

/* ���μ���ģʽʹ�� (One State Timer) ��غ��� */
extern void LPTIM_CFGR_ONST_Set(uint32_t SetValue);
extern uint32_t LPTIM_CFGR_ONST_Get(void);

/* ����ģʽѡ�� (Timer operation Mode) ��غ��� */
extern void LPTIM_CFGR_TMOD_Set(uint32_t SetValue);
extern uint32_t LPTIM_CFGR_TMOD_Get(void);

/* 32bit��������ǰ����ֵ (Counter 32bits-wide) ��غ��� */
extern void LPTIM_CNT_Write(uint32_t SetValue);
extern uint32_t LPTIM_CNT_Read(void);

/* ͨ��1��׽�ź�Դѡ�� (Channel 1 Capture Source Select) ��غ��� */
extern void LPTIM_CCSR_CAP1SSEL_Set(uint32_t SetValue);
extern uint32_t LPTIM_CCSR_CAP1SSEL_Get(void);

/* ͨ��2��ǰ����׽�ı��أ���CC2IF��λʱ���� (Channel2 Captured Edge) ��غ��� */
extern FlagStatus LPTIM_CCSR_CAP2EDGE_Chk(void);

/* ͨ��1��ǰ����׽�ı��أ���CC1IF��λʱ���� (Channel 1 Captured Edge) ��غ��� */
extern FlagStatus LPTIM_CCSR_CAP1EDGE_Chk(void);

/* ͨ��2��׽����ѡ�� (Channel 2 Capture edge Config) ��غ��� */
extern void LPTIM_CCSR_CAPCFG2_Set(uint32_t SetValue);
extern uint32_t LPTIM_CCSR_CAPCFG2_Get(void);

/* ͨ��1��׽����ѡ�� (Channel 1 Capture edge Config) ��غ��� */
extern void LPTIM_CCSR_CAPCFG1_Set(uint32_t SetValue);
extern uint32_t LPTIM_CCSR_CAPCFG1_Get(void);

/* ͨ��2�Ƚ�������μ���ѡ�� (Channel 2 compare output Polarity) ��غ��� */
extern void LPTIM_CCSR_POLAR2_Set(uint32_t SetValue);
extern uint32_t LPTIM_CCSR_POLAR2_Get(void);

/* ͨ��1�Ƚ�������μ���ѡ�� (Channel 1 compare output Polarity) ��غ��� */
extern void LPTIM_CCSR_POLAR1_Set(uint32_t SetValue);
extern uint32_t LPTIM_CCSR_POLAR1_Get(void);

/* ͨ��2��׽/�ȽϹ���ʹ�� (Channel 2 Capture/Compare Select) ��غ��� */
extern void LPTIM_CCSR_CC2S_Set(uint32_t SetValue);
extern uint32_t LPTIM_CCSR_CC2S_Get(void);

/* ͨ��1��׽/�ȽϹ���ʹ�� (Channel 1 Capture/Compare Select) ��غ��� */
extern void LPTIM_CCSR_CC1S_Set(uint32_t SetValue);
extern uint32_t LPTIM_CCSR_CC1S_Get(void);

/* �Զ�����Ŀ��Ĵ��� (Auto-Reload Register) ��غ��� */
extern void LPTIM_ARR_Write(uint32_t SetValue);
extern uint32_t LPTIM_ARR_Read(void);

/* ͨ��2��׽����ж�ʹ�� (Channel 2 Over-Capture Interrupt Enable) ��غ��� */
extern void LPTIM_IER_OVR2IE_Setable(FunState NewState);
extern FunState LPTIM_IER_OVR2IE_Getable(void);

/* ͨ��1��׽����ж�ʹ�� (Channel 1 Over-Capture Interrupt Enable) ��غ��� */
extern void LPTIM_IER_OVR1IE_Setable(FunState NewState);
extern FunState LPTIM_IER_OVR1IE_Getable(void);

/* �ⲿ���������ж�ʹ��λ (External Trigger Interrupt Enable) ��غ��� */
extern void LPTIM_IER_TRIGIE_Setable(FunState NewState);
extern FunState LPTIM_IER_TRIGIE_Getable(void);

/* ����������ж�ʹ��λ (Counter Over-Flow Interrupt Enable) ��غ��� */
extern void LPTIM_IER_OVIE_Setable(FunState NewState);
extern FunState LPTIM_IER_OVIE_Getable(void);

/* ��׽/�Ƚ�ͨ��2�ж�ʹ��λ (Capture/Compare channel 2 Interrupt Enable) ��غ��� */
extern void LPTIM_IER_CC2IE_Setable(FunState NewState);
extern FunState LPTIM_IER_CC2IE_Getable(void);

/* ��׽/�Ƚ�ͨ��1�ж�ʹ��λ (Capture/Compare channel 1 Interrupt Enable) ��غ��� */
extern void LPTIM_IER_CC1IE_Setable(FunState NewState);
extern FunState LPTIM_IER_CC1IE_Getable(void);

/* ͨ��2��׽�����Ӳ����λ�����д1���� (Channel 2 Over-Capture Interrupt Flag) ��غ��� */
extern void LPTIM_ISR_CAP2OVR_Clr(void);
extern FlagStatus LPTIM_ISR_CAP2OVR_Chk(void);

/* ͨ��1��׽�����Ӳ����λ�����д1���� (Channel 1 Over-Capture Interrupt Flag) ��غ��� */
extern void LPTIM_ISR_CAP1OVR_Clr(void);
extern FlagStatus LPTIM_ISR_CAP1OVR_Chk(void);

/* �ⲿ���������жϱ�־λ��д1���� (External Trigger Interrupt Flag) ��غ��� */
extern void LPTIM_ISR_TRIGIF_Clr(void);
extern FlagStatus LPTIM_ISR_TRIGIF_Chk(void);

/* ����������ж�ʹ��λ��д1���� (Counter Over-Flow Interrupt Flag) ��غ��� */
extern void LPTIM_ISR_OVIF_Clr(void);
extern FlagStatus LPTIM_ISR_OVIF_Chk(void);

/* ��׽/�Ƚ�ͨ��2�жϱ�־��Ӳ����λ�����д1���� (Capture/Compare channel 2 Interrupt Flag) ��غ��� */
extern void LPTIM_ISR_CC2IF_Clr(void);
extern FlagStatus LPTIM_ISR_CC2IF_Chk(void);

/* ��׽/�Ƚ�ͨ��1�жϱ�־��Ӳ����λ�����д1���� (Capture/Compare channel 1 Interrupt Flag) ��غ��� */
extern void LPTIM_ISR_CC1IF_Clr(void);
extern FlagStatus LPTIM_ISR_CC1IF_Chk(void);

/* LPTIMʹ��λ (LPTIM Enable) ��غ��� */
extern void LPTIM_CR_EN_Setable(FunState NewState);
extern FunState LPTIM_CR_EN_Getable(void);

/* ��׽/�Ƚ�ֵ�Ĵ���1 (Channel1 Capture/Compare Register) ��غ��� */
extern void LPTIM_CCR1_Write(uint32_t SetValue);
extern uint32_t LPTIM_CCR1_Read(void);

/* ��׽/�Ƚ�ֵ�Ĵ���2 (Channel2 Capture/Compare Register) ��غ��� */
extern void LPTIM_CCR2_Write(uint32_t SetValue);
extern uint32_t LPTIM_CCR2_Read(void);
                
#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_LPTIM_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
