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

#define	ADC_ISR_AWD_AH_Pos	6	/* ģ�⿴�Ź����������жϱ�־ (Analog Watchdog Above High Threshold)������ֵ����AWD_HTʱ��Ӳ����λ�����д1����. */
#define	ADC_ISR_AWD_AH_Msk	(0x1U << ADC_ISR_AWD_AH_Pos)

#define	ADC_ISR_AWD_UL_Pos	5	/* ģ�⿴�Ź����������жϱ�־ (Analog Watchdog Under Low Threshold)������ֵ����AWD_LTʱ��Ӳ����λ�����д1���� */
#define	ADC_ISR_AWD_UL_Msk	(0x1U << ADC_ISR_AWD_UL_Pos)

#define	ADC_ISR_EOCAL_Pos	4	/* У׼���� (End Of Calibration)Ӳ����λ�����д1����1��У׼���̽���0����У׼���� */
#define	ADC_ISR_EOCAL_Msk	(0x1U << ADC_ISR_EOCAL_Pos)

#define	ADC_ISR_BUSY_Pos	3	/* ADCæ��־ (Busy) 1��ADC����У׼��������ת�������� 0��ADC���� */
#define	ADC_ISR_BUSY_Msk	(0x1U << ADC_ISR_BUSY_Pos)

#define	ADC_ISR_OVR_Pos	2	/* ���ݳ�ͻ��־��Ӳ����λ�����д1���� (Over Run) ��ADC_DATA�Ĵ����е���һ��ת�������δ����ȡ���µ�ת������ֵ���ʱ��Ӳ����λOVR��־��0��û�����ݳ�ͻ 1���������ݳ�ͻ */
#define	ADC_ISR_OVR_Msk	(0x1U << ADC_ISR_OVR_Pos)

#define	ADC_ISR_EOS_Pos	1	/* ת�����н��� (End Of Sequence)����ʹ��ͨ����ת����ɺ���λEOS�����д1���㡣 */
#define	ADC_ISR_EOS_Msk	(0x1U << ADC_ISR_EOS_Pos)

#define	ADC_ISR_EOC_Pos	0	/* ����ת������ (End Of Conversion)ÿ��ͨ��ת����ɺ���λEOC�����д1���㡣 */
#define	ADC_ISR_EOC_Msk	(0x1U << ADC_ISR_EOC_Pos)

#define	ADC_IER_AWD_AHIE_Pos	6	/* ģ�⿴�Ź�����ֵ���������ж�ʹ�ܣ�1��Ч (Analog Watchdog Above High Threshold Interrupt Enable) */
#define	ADC_IER_AWD_AHIE_Msk	(0x1U << ADC_IER_AWD_AHIE_Pos)

#define	ADC_IER_AWD_ULIE_Pos	5	/* ģ�⿴�Ź�����ֵ���������ж�ʹ�ܣ�1��Ч (Analog Watchdog Under Low Threshold Interrupt Enable) */
#define	ADC_IER_AWD_ULIE_Msk	(0x1U << ADC_IER_AWD_ULIE_Pos)

#define	ADC_IER_EOCALIE_Pos	4	/* У׼�����ж�ʹ�ܼĴ��� (End Of Calibration Interrupt Enable) 0����ֹEOCAL�ж� 1������EOCAL�ж� */
#define	ADC_IER_EOCALIE_Msk	(0x1U << ADC_IER_EOCALIE_Pos)

#define	ADC_IER_OVRIE_Pos	2	/* ���ݳ�ͻ�ж�ʹ�ܼĴ��� (Over Run Interrupt Enable) 0����ֹ���ݳ�ͻ�ж� 1���������ݳ�ͻ�ж� */
#define	ADC_IER_OVRIE_Msk	(0x1U << ADC_IER_OVRIE_Pos)

#define	ADC_IER_EOSIE_Pos	1	/* ת�����н����ж�ʹ�ܼĴ��� (End Of Sequence Interrupt Enable) 0����ֹEOS�ж� 1������EOS�ж� */
#define	ADC_IER_EOSIE_Msk	(0x1U << ADC_IER_EOSIE_Pos)

#define	ADC_IER_EOCIE_Pos	0	/* ����ת�������ж�ʹ�ܼĴ��� (End Of Conversion Interrupt Enable) 0����ֹEOC�ж� 1������EOC�ж� */
#define	ADC_IER_EOCIE_Msk	(0x1U << ADC_IER_EOCIE_Pos)

#define	ADC_CR_START_Pos	1	/* ADC����ת���Ĵ��������д1������Ӳ���Զ����㡣 */
#define	ADC_CR_START_Msk	(0x1U << ADC_CR_START_Pos)

#define	ADC_CR_ADEN_Pos	0	/* ADCʹ�ܼĴ��� (ADC Enable) ������ת��ǰ��Ҫ��λADEN���ȴ�����5��MCLK��������ת����0���ر�ADC 1��ʹ��ADC */
#define	ADC_CR_ADEN_Msk	(0x1U << ADC_CR_ADEN_Pos)

#define	ADC_CFGR_CKS_Pos	30	/* ADC����ʱ��ѡ�� (ADC Clock Select) */
#define	ADC_CFGR_CKS_Msk	(0x3U << ADC_CFGR_CKS_Pos)
#define	ADC_CFGR_CKS_ADCCLK	(0x0U << ADC_CFGR_CKS_Pos)	/* 00��ADCCLK */
#define	ADC_CFGR_CKS_APBCLK_2	(0x1U << ADC_CFGR_CKS_Pos)	/* 01��APBCLK/2 */
#define	ADC_CFGR_CKS_APBCLK_4	(0x2U << ADC_CFGR_CKS_Pos)	/* 10��APBCLK/4 */
#define	ADC_CFGR_CKS_APBCLK	(0x3U << ADC_CFGR_CKS_Pos)	/* 11��APBCLK */

#define	ADC_CFGR_AWDCH_Pos	26	/* ģ�ⴰ�ڿ��Ź�����ͨ��ѡ�񣬽���AWDSC=1ʱ��Ч (Analog Watchdog Channel Select) */
#define	ADC_CFGR_AWDCH_Msk	(0xfU << ADC_CFGR_AWDCH_Pos)
#define	ADC_CFGR_AWDCH_ADC_IN0	(0x0U << ADC_CFGR_AWDCH_Pos)	/* 0000��AWD����ADC_IN0 */
#define	ADC_CFGR_AWDCH_ADC_IN1	(0x1U << ADC_CFGR_AWDCH_Pos)	/* 0001��AWD����ADC_IN1 */
#define	ADC_CFGR_AWDCH_ADC_IN2	(0x2U << ADC_CFGR_AWDCH_Pos)	/* 0010��AWD����ADC_IN2 */
#define	ADC_CFGR_AWDCH_ADC_IN3	(0x3U << ADC_CFGR_AWDCH_Pos)	/* 0011��AWD����ADC_IN3 */
#define	ADC_CFGR_AWDCH_ADC_IN4	(0x4U << ADC_CFGR_AWDCH_Pos)	/* 0100��AWD����ADC_IN4 */
#define	ADC_CFGR_AWDCH_ADC_IN5	(0x5U << ADC_CFGR_AWDCH_Pos)	/* 0101��AWD����ADC_IN5 */
#define	ADC_CFGR_AWDCH_ADC_IN6	(0x6U << ADC_CFGR_AWDCH_Pos)	/* 0110��AWD����ADC_IN6 */
#define	ADC_CFGR_AWDCH_ADC_IN7	(0x7U << ADC_CFGR_AWDCH_Pos)	/* 0111��AWD����ADC_IN7 */
#define	ADC_CFGR_AWDCH_ADC_IN8	(0x8U << ADC_CFGR_AWDCH_Pos)	/* 1000��AWD����ADC_IN8 */
#define	ADC_CFGR_AWDCH_ADC_IN9	(0x9U << ADC_CFGR_AWDCH_Pos)	/* 1001��AWD����ADC_IN9 */
#define	ADC_CFGR_AWDCH_ADC_IN10	(0xaU << ADC_CFGR_AWDCH_Pos)	/* 1010��AWD����ADC_IN10 */
#define	ADC_CFGR_AWDCH_ADC_IN11	(0xbU << ADC_CFGR_AWDCH_Pos)	/* 1011��AWD����ADC_IN11 */

#define	ADC_CFGR_AWDSC_Pos	25	/* ģ�ⴰ�ڿ��Ź���ͨ����ȫͨ��ѡ�� (Analog Watchdog Single Channel mode) */
#define	ADC_CFGR_AWDSC_Msk	(0x1U << ADC_CFGR_AWDSC_Pos)
#define	ADC_CFGR_AWDSC_AWD_ALL	(0x0U << ADC_CFGR_AWDSC_Pos)	/* 0��AWD�������б�ʹ�ܵ��ⲿ����ͨ�� */
#define	ADC_CFGR_AWDSC_AWD_SINGLE	(0x1U << ADC_CFGR_AWDSC_Pos)	/* 1��AWD����AWDCHָ���ĵ���ͨ�� */

#define	ADC_CFGR_AWDEN_Pos	24	/* ģ�ⴰ�ڿ��Ź�ʹ�ܼĴ��� (Analog Watchdog Enable) 0���ر�AWD 1��ʹ��AWD ������START=0�������ʹ��AWD */
#define	ADC_CFGR_AWDEN_Msk	(0x1U << ADC_CFGR_AWDEN_Pos)

#define	ADC_CFGR_OVSS_Pos	20	/* ��������λ���ƼĴ��� (Oversampling Shift) */
#define	ADC_CFGR_OVSS_Msk	(0xfU << ADC_CFGR_OVSS_Pos)
#define	ADC_CFGR_OVSS_R_SHIFT_0	(0x0U << ADC_CFGR_OVSS_Pos)	/* 0000������λ */
#define	ADC_CFGR_OVSS_R_SHIFT_1	(0x1U << ADC_CFGR_OVSS_Pos)	/* 0001������1bit */
#define	ADC_CFGR_OVSS_R_SHIFT_2	(0x2U << ADC_CFGR_OVSS_Pos)	/* 0010������2bit */
#define	ADC_CFGR_OVSS_R_SHIFT_3	(0x3U << ADC_CFGR_OVSS_Pos)	/* 0011������3bit */
#define	ADC_CFGR_OVSS_R_SHIFT_4	(0x4U << ADC_CFGR_OVSS_Pos)	/* 0100������4bit */
#define	ADC_CFGR_OVSS_R_SHIFT_5	(0x5U << ADC_CFGR_OVSS_Pos)	/* 0101������5bit */
#define	ADC_CFGR_OVSS_R_SHIFT_6	(0x6U << ADC_CFGR_OVSS_Pos)	/* 0110������6bit */
#define	ADC_CFGR_OVSS_R_SHIFT_7	(0x7U << ADC_CFGR_OVSS_Pos)	/* 0111������7bit */
#define	ADC_CFGR_OVSS_R_SHIFT_8	(0x8U << ADC_CFGR_OVSS_Pos)	/* 1000������8bit */

#define	ADC_CFGR_OVSR_Pos	17	/* �������ʿ��� (Oversampling Ratio) */
#define	ADC_CFGR_OVSR_Msk	(0x7U << ADC_CFGR_OVSR_Pos)
#define	ADC_CFGR_OVSR_2x	(0x0U << ADC_CFGR_OVSR_Pos)	/* 000��2x */
#define	ADC_CFGR_OVSR_4x	(0x1U << ADC_CFGR_OVSR_Pos)	/* 001��4x */
#define	ADC_CFGR_OVSR_8x	(0x2U << ADC_CFGR_OVSR_Pos)	/* 010��8x */
#define	ADC_CFGR_OVSR_16x	(0x3U << ADC_CFGR_OVSR_Pos)	/* 011��16x */
#define	ADC_CFGR_OVSR_32x	(0x4U << ADC_CFGR_OVSR_Pos)	/* 100��32x */
#define	ADC_CFGR_OVSR_64x	(0x5U << ADC_CFGR_OVSR_Pos)	/* 101��64x */
#define	ADC_CFGR_OVSR_128x	(0x6U << ADC_CFGR_OVSR_Pos)	/* 110��128x */
#define	ADC_CFGR_OVSR_256x	(0x7U << ADC_CFGR_OVSR_Pos)	/* 111��256x */

#define	ADC_CFGR_OVSEN_Pos	16	/* ������ʹ�� (Oversampling Enable) 0����ֹ������ 1��ʹ�ܹ����� */
#define	ADC_CFGR_OVSEN_Msk	(0x1U << ADC_CFGR_OVSEN_Pos)

#define	ADC_CFGR_IOTRFEN_Pos	14	/* ���Ŵ����ź������˲�ʹ�� (GPIO Trigger Filter Enable) 0����ֹ�����˲� 1��ʹ�������˲�  */
#define	ADC_CFGR_IOTRFEN_Msk	(0x1U << ADC_CFGR_IOTRFEN_Pos)

#define	ADC_CFGR_TRGCFG_Pos	12	/* �����ź�ʹ�ܺͼ���ѡ�� (Trigger Config) */
#define	ADC_CFGR_TRGCFG_Msk	(0x3U << ADC_CFGR_TRGCFG_Pos)
#define	ADC_CFGR_TRGCFG_DISABLE	(0x0U << ADC_CFGR_TRGCFG_Pos)	/* 00����ֹ���� */
#define	ADC_CFGR_TRGCFG_RISING	(0x1U << ADC_CFGR_TRGCFG_Pos)	/* 01�������ش��� */
#define	ADC_CFGR_TRGCFG_FALLING	(0x2U << ADC_CFGR_TRGCFG_Pos)	/* 10���½��ش��� */
#define	ADC_CFGR_TRGCFG_BOTH	(0x3U << ADC_CFGR_TRGCFG_Pos)	/* 11���������½��ض����� */

#define	ADC_CFGR_SEMI_Pos	11	/* ����ת�����Զ�ģʽ (Semi-automatic)�����ڵ���ת����CONT=0��ʱ��Ч */
#define	ADC_CFGR_SEMI_Msk	(0x1U << ADC_CFGR_SEMI_Pos)
#define	ADC_CFGR_SEMI_AUTO	(0x0U << ADC_CFGR_SEMI_Pos)	/* 0���Զ�ģʽ */
#define	ADC_CFGR_SEMI_HALF_AUTO	(0x1U << ADC_CFGR_SEMI_Pos)	/* 1�����Զ�ģʽ */

#define	ADC_CFGR_WAIT_Pos	10	/* �ȴ�ģʽ���� (wait mode) 0���޵ȴ�������ϴ�ת������û�м�ʱ��ȡ������ܳ���Overrun 1���ȴ�ģʽ�����ϴ�ת�����ݱ���ȡǰ������������һ��ת�� */
#define	ADC_CFGR_WAIT_Msk	(0x1U << ADC_CFGR_WAIT_Pos)

#define	ADC_CFGR_CONT_Pos	9	/* ����ת��ģʽʹ�� (Continuous mode) 0������ת�� 1������ת��  */
#define	ADC_CFGR_CONT_Msk	(0x1U << ADC_CFGR_CONT_Pos)

#define	ADC_CFGR_OVRM_Pos	8	/* Overrunģʽ���� (Overrun mode) */
#define	ADC_CFGR_OVRM_Msk	(0x1U << ADC_CFGR_OVRM_Pos)
#define	ADC_CFGR_OVRM_KEEP	(0x0U << ADC_CFGR_OVRM_Pos)	/* 0����overrun����ʱ�������ϴ����ݣ���������ת��ֵ */
#define	ADC_CFGR_OVRM_COVER	(0x1U << ADC_CFGR_OVRM_Pos)	/* 1����overrun����ʱ�������ϴ����� */

#define	ADC_CFGR_EXTS_Pos	4	/* Ӳ������Դѡ�� (External trigger select) */
#define	ADC_CFGR_EXTS_Msk	(0xfU << ADC_CFGR_EXTS_Pos)
#define	ADC_CFGR_EXTS_PA8	(0x0U << ADC_CFGR_EXTS_Pos)	/* 0000��PA8 */
#define	ADC_CFGR_EXTS_PB9	(0x1U << ADC_CFGR_EXTS_Pos)	/* 0001��PB9 */
#define	ADC_CFGR_EXTS_ATIM_TROG	(0x3U << ADC_CFGR_EXTS_Pos)	/* 0011��ATIM_TRGO */
#define	ADC_CFGR_EXTS_GPTIM1_TROG	(0x4U << ADC_CFGR_EXTS_Pos)	/* 0100��GPTIM1_TRGO */
#define	ADC_CFGR_EXTS_GPTIM2_TROG	(0x5U << ADC_CFGR_EXTS_Pos)	/* 0101��GPTIM2_TRGO */
#define	ADC_CFGR_EXTS_RTC_TROG	(0x7U << ADC_CFGR_EXTS_Pos)	/* 0111��RTC_TRGO */
#define	ADC_CFGR_EXTS_BSTIM1_TROG	(0x8U << ADC_CFGR_EXTS_Pos)	/* 1000��BSTIM1_TRGO */
#define	ADC_CFGR_EXTS_COMP1_TROG	(0xaU << ADC_CFGR_EXTS_Pos)	/* 1010��COMP1_TRGO */
#define	ADC_CFGR_EXTS_COMP2_TROG	(0xbU << ADC_CFGR_EXTS_Pos)	/* 1011��COMP2_TRGO */

#define	ADC_CFGR_LPM_Pos	3	/* ADC�͹���ģʽʹ�ܣ������������ (Low Power Mode) */
#define	ADC_CFGR_LPM_Msk	(0x1U << ADC_CFGR_LPM_Pos)
#define	ADC_CFGR_LPM_LPM_MODE	(0x0U << ADC_CFGR_LPM_Pos)	/* 0������ģʽ */
#define	ADC_CFGR_LPM_NORMAL_MODE	(0x1U << ADC_CFGR_LPM_Pos)	/* 1��ʹ��ADC�͹���ģʽ�������ʱ��Ƶ��4MHz����߲�����250Ksps */

#define	ADC_CFGR_SCANDIR_Pos	2	/* ͨ��ɨ��˳����� (Scan Direction)����16��ͨ����ʵ��ֻ�������ʹ�ܵ�ͨ���� */
#define	ADC_CFGR_SCANDIR_Msk	(0x1U << ADC_CFGR_SCANDIR_Pos)
#define	ADC_CFGR_SCANDIR_FORWARD	(0x0U << ADC_CFGR_SCANDIR_Pos)	/* 0��ǰ��ɨ�裬ADC_IN0->ADC_IN11->REF->TS->OPA1->OPA2 */
#define	ADC_CFGR_SCANDIR_REVERSE	(0x1U << ADC_CFGR_SCANDIR_Pos)	/* 1������ɨ�裬OPA2->OPA1->TS->REF->ADC_IN11->ADC_IN0 */

#define	ADC_CFGR_DMACFG_Pos	1	/* DMAģʽ���� (DMA Config) */
#define	ADC_CFGR_DMACFG_Msk	(0x1U << ADC_CFGR_DMACFG_Pos)
#define	ADC_CFGR_DMACFG_SINGLE	(0x0U << ADC_CFGR_DMACFG_Pos)	/* 0������ģʽ */
#define	ADC_CFGR_DMACFG_CYCLE	(0x1U << ADC_CFGR_DMACFG_Pos)	/* 1��ѭ��ģʽ */

#define	ADC_CFGR_DMAEN_Pos	0	/* DMAʹ�� (DMA Enable) 0����ֹDMA 1��ʹ��DMA  */
#define	ADC_CFGR_DMAEN_Msk	(0x1U << ADC_CFGR_DMAEN_Pos)

#define	ADC_SMTR_CHCG_Pos	8	/* ADC����ͨ���л��ȴ�ʱ�� (Channel Clock Gating) �ڵ�ǰͨ������������ɺ󣬵ȴ�CHCGʱ�䣨CHCG*ADC����ʱ�����ڣ������л�����һ������ͨ�� */
#define	ADC_SMTR_CHCG_Msk	(0xfU << ADC_SMTR_CHCG_Pos)
#define	ADC_SMTR_CHCG_1_TADCCLK	(0x0U << ADC_SMTR_CHCG_Pos)	/* 0000, 0001��1*TADCLK */
#define	ADC_SMTR_CHCG_2_TADCCLK	(0x2U << ADC_SMTR_CHCG_Pos)	/* 0010��2*TADCLK */
#define	ADC_SMTR_CHCG_3_TADCCLK	(0x3U << ADC_SMTR_CHCG_Pos)	/* 0011��3*TADCLK */
#define	ADC_SMTR_CHCG_4_TADCCLK	(0x4U << ADC_SMTR_CHCG_Pos)	/* 0100��4*TADCLK */
#define	ADC_SMTR_CHCG_5_TADCCLK	(0x5U << ADC_SMTR_CHCG_Pos)	/* 0101��5*TADCLK */
#define	ADC_SMTR_CHCG_6_TADCCLK	(0x6U << ADC_SMTR_CHCG_Pos)	/* 0110��6*TADCLK */
#define	ADC_SMTR_CHCG_7_TADCCLK	(0x7U << ADC_SMTR_CHCG_Pos)	/* 0111��7*TADCLK */
#define	ADC_SMTR_CHCG_8_TADCCLK	(0x8U << ADC_SMTR_CHCG_Pos)	/* 1000��8*TADCLK */
#define	ADC_SMTR_CHCG_9_TADCCLK	(0x9U << ADC_SMTR_CHCG_Pos)	/* 1001��9*TADCLK */
#define	ADC_SMTR_CHCG_10_TADCCLK	(0xaU << ADC_SMTR_CHCG_Pos)	/* 1010��10*TADCLK */
#define	ADC_SMTR_CHCG_11_TADCCLK	(0xbU << ADC_SMTR_CHCG_Pos)	/* 1011~1111��11*TADCLK */

#define	ADC_SMTR_SMTS2_Pos	4	/* ����ͨ������ʱ����ƣ�*ADC����ʱ�����ڣ�����������ADC_IN8/9/10/11�ĸ��ⲿͨ�����Լ�OPAͨ���Ĳ���ʱ�� (Sampling Time Select 2)  */
#define	ADC_SMTR_SMTS2_Msk	(0x3U << ADC_SMTR_SMTS2_Pos)
#define	ADC_SMTR_SMTS2_3_5_TMCLK	(0x0U << ADC_SMTR_SMTS2_Pos)	/* 00��3.5*TMCLK */
#define	ADC_SMTR_SMTS2_4_5_TMCLK	(0x1U << ADC_SMTR_SMTS2_Pos)	/* 01��4.5*TMCLK */
#define	ADC_SMTR_SMTS2_6_5_TMCLK	(0x2U << ADC_SMTR_SMTS2_Pos)	/* 10��6.5*TMCLK */
#define	ADC_SMTR_SMTS2_10_5_TMCLK	(0x3U << ADC_SMTR_SMTS2_Pos)	/* 11��10.5*TMCLK */

#define	ADC_SMTR_SMTS1_Pos	0	/* ����ͨ������ʱ����ƣ�*ADC����ʱ�����ڣ�����������ADC_IN8/9/10/11�ĸ��ⲿͨ�����Լ�OPAͨ���Ĳ���ʱ�� (Sampling Time Select 2)  */
#define	ADC_SMTR_SMTS1_Msk	(0x3U << ADC_SMTR_SMTS1_Pos)
#define	ADC_SMTR_SMTS1_3_5_TMCLK	(0x0U << ADC_SMTR_SMTS1_Pos)	/* 00��3.5*TMCLK */
#define	ADC_SMTR_SMTS1_4_5_TMCLK	(0x1U << ADC_SMTR_SMTS1_Pos)	/* 01��4.5*TMCLK */
#define	ADC_SMTR_SMTS1_6_5_TMCLK	(0x2U << ADC_SMTR_SMTS1_Pos)	/* 10��6.5*TMCLK */
#define	ADC_SMTR_SMTS1_10_5_TMCLK	(0x3U << ADC_SMTR_SMTS1_Pos)	/* 11��10.5*TMCLK */

#define	ADC_CHER_AINS_Pos	24	/* ���˺Ͳ��ͨ�����ã�4bit����4��ͨ�����Ƿ�Ϊ������룬0��ʾ�������룬1��ʾ������롣(Analog Input Select)�������Ϊ������룬��ÿ����ֶ�����Ӧ��ͨ����Ҫʹ�ܡ�
���磬��ADC_IN0��ADC_IN1����Ϊ�������ԣ���Ҫ���в�ֲ���ʱ��ECH0��ECH1��Ҫ��1�� */
#define	ADC_CHER_AINS_Msk	(0xfU << ADC_CHER_AINS_Pos)
#define	ADC_CHER_AINS_ADC_IN01	(0x1U << ADC_CHER_AINS_Pos)	/* ����ADC_IN0��ADC_IN1Ϊ������ */
#define	ADC_CHER_AINS_ADC_IN23	(0x2U << ADC_CHER_AINS_Pos)	/* ����ADC_IN2��ADC_IN3Ϊ������ */
#define	ADC_CHER_AINS_ADC_IN45	(0x4U << ADC_CHER_AINS_Pos)	/* ����ADC_IN4��ADC_IN5Ϊ������ */
#define	ADC_CHER_AINS_ADC_IN67	(0x8U << ADC_CHER_AINS_Pos)	/* ����ADC_IN6��ADC_IN7Ϊ������ */

#define	ADC_CHER_OPA2CH_Pos	19	/* OPA2���������д1ʹ�� (OPA2 channel)  */
#define	ADC_CHER_OPA2CH_Msk	(0x1U << ADC_CHER_OPA2CH_Pos)

#define	ADC_CHER_OPA1CH_Pos	18	/* OPA1���������д1ʹ�� (OPA1 channel)  */
#define	ADC_CHER_OPA1CH_Msk	(0x1U << ADC_CHER_OPA1CH_Pos)

#define	ADC_CHER_TSCH_Pos	17	/* �¶ȴ���������ͨ����д1ʹ�� (TempSensor channel)  */
#define	ADC_CHER_TSCH_Msk	(0x1U << ADC_CHER_TSCH_Pos)

#define	ADC_CHER_REFCH_Pos	16	/* �ڲ���׼��ѹ����ͨ����д1ʹ�� (VREF channel)  */
#define	ADC_CHER_REFCH_Msk	(0x1U << ADC_CHER_REFCH_Pos)

#define	ADC_CHER_ECH11_Pos	11	/* ADC_IN11 ����ͨ����д1ʹ��  */
#define	ADC_CHER_ECH11_Msk	(0x1U << ADC_CHER_ECH11_Pos)

#define	ADC_CHER_ECH10_Pos	10	/* ADC_IN10 ����ͨ����д1ʹ��  */
#define	ADC_CHER_ECH10_Msk	(0x1U << ADC_CHER_ECH10_Pos)

#define	ADC_CHER_ECH9_Pos	9	/* ADC_IN9 ����ͨ����д1ʹ�� */
#define	ADC_CHER_ECH9_Msk	(0x1U << ADC_CHER_ECH9_Pos)

#define	ADC_CHER_ECH8_Pos	8	/* ADC_IN8 ����ͨ����д1ʹ�� */
#define	ADC_CHER_ECH8_Msk	(0x1U << ADC_CHER_ECH8_Pos)

#define	ADC_CHER_ECH7_Pos	7	/* ADC_IN7 ����ͨ����д1ʹ�� */
#define	ADC_CHER_ECH7_Msk	(0x1U << ADC_CHER_ECH7_Pos)

#define	ADC_CHER_ECH6_Pos	6	/* ADC_IN6 ����ͨ����д1ʹ�� */
#define	ADC_CHER_ECH6_Msk	(0x1U << ADC_CHER_ECH6_Pos)

#define	ADC_CHER_ECH5_Pos	5	/* ADC_IN5 ����ͨ����д1ʹ�� */
#define	ADC_CHER_ECH5_Msk	(0x1U << ADC_CHER_ECH5_Pos)

#define	ADC_CHER_ECH4_Pos	4	/* ADC_IN4 ����ͨ����д1ʹ�� */
#define	ADC_CHER_ECH4_Msk	(0x1U << ADC_CHER_ECH4_Pos)

#define	ADC_CHER_ECH3_Pos	3	/* ADC_IN3 ����ͨ����д1ʹ�� */
#define	ADC_CHER_ECH3_Msk	(0x1U << ADC_CHER_ECH3_Pos)

#define	ADC_CHER_ECH2_Pos	2	/* ADC_IN2 ����ͨ����д1ʹ�� */
#define	ADC_CHER_ECH2_Msk	(0x1U << ADC_CHER_ECH2_Pos)

#define	ADC_CHER_ECH1_Pos	1	/* ADC_IN1 ����ͨ����д1ʹ�� */
#define	ADC_CHER_ECH1_Msk	(0x1U << ADC_CHER_ECH1_Pos)

#define	ADC_CHER_ECH0_Pos	0	/* ADC_IN0 ����ͨ����д1ʹ�� */
#define	ADC_CHER_ECH0_Msk	(0x1U << ADC_CHER_ECH0_Pos)

#define	ADC_DR_ADC_DATA_Pos	0	/* ADCת����� (ADC conversion data)��û��ʹ�ܹ�����ƽ��������£����Ϊ��12bit����ʹ�ܹ�����ƽ��������£����Ϊ12~16bit
 */
#define	ADC_DR_ADC_DATA_Msk	(0xffffU << ADC_DR_ADC_DATA_Pos)

#define	ADC_CAL_CONV_CAL_Pos	1	/* ADCת������ (Conversion with Calibration data) */
#define	ADC_CAL_CONV_CAL_Msk	(0x1U << ADC_CAL_CONV_CAL_Pos)
#define	ADC_CAL_CONV_CAL_UNUSE_CAL	(0x0U << ADC_CAL_CONV_CAL_Pos)	/* 0��ADCת��ʱ��ʹ��У׼�Ĵ��������� */
#define	ADC_CAL_CONV_CAL_USE_CAL	(0x1U << ADC_CAL_CONV_CAL_Pos)	/* 1��ADCת��ʱʹ��У׼�Ĵ��������� */

#define	ADC_CAL_CALEN_Pos	0	/* Calibrationʹ�� (Calibration Enable)���д1����У׼���ڣ�Ӳ����ʼУ׼���Զ����㡣���ͨ��EOCAL�Ĵ�����ѯУ׼���ڽ��� */
#define	ADC_CAL_CALEN_Msk	(0x1U << ADC_CAL_CALEN_Pos)

#define	ADC_HLTR_AWD_HT_Pos	16	/* AWD���Ӹ���ֵ (Analog Watchdog High Threshold) */
#define	ADC_HLTR_AWD_HT_Msk	(0xfffU << ADC_HLTR_AWD_HT_Pos)

#define	ADC_HLTR_AWD_LT_Pos	0	/* AWD���ӵ���ֵ (Analog Watchdog Low Threshold) */
#define	ADC_HLTR_AWD_LT_Msk	(0xfffU << ADC_HLTR_AWD_LT_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void ADC_Deinit(void);

/* ģ�⿴�Ź����������жϱ�־ (Analog Watchdog Above High Threshold)������ֵ����AWD_HTʱ��Ӳ����λ�����д1����. ��غ��� */
extern void ADC_ISR_AWD_AH_Clr(void);
extern FlagStatus ADC_ISR_AWD_AH_Chk(void);

/* ģ�⿴�Ź����������жϱ�־ (Analog Watchdog Under Low Threshold)������ֵ����AWD_LTʱ��Ӳ����λ�����д1���� ��غ��� */
extern void ADC_ISR_AWD_UL_Clr(void);
extern FlagStatus ADC_ISR_AWD_UL_Chk(void);

/* У׼���� (End Of Calibration)Ӳ����λ�����д1����1��У׼���̽���0����У׼���� ��غ��� */
extern void ADC_ISR_EOCAL_Clr(void);
extern FlagStatus ADC_ISR_EOCAL_Chk(void);

/* ADCæ��־ (Busy) 1��ADC����У׼��������ת�������� 0��ADC���� ��غ��� */
extern FlagStatus ADC_ISR_BUSY_Chk(void);

/* ���ݳ�ͻ��־��Ӳ����λ�����д1���� (Over Run) ��ADC_DATA�Ĵ����е���һ��ת�������δ����ȡ���µ�ת������ֵ���ʱ��Ӳ����λOVR��־��0��û�����ݳ�ͻ 1���������ݳ�ͻ ��غ��� */
extern void ADC_ISR_OVR_Clr(void);
extern FlagStatus ADC_ISR_OVR_Chk(void);

/* ת�����н��� (End Of Sequence)����ʹ��ͨ����ת����ɺ���λEOS�����д1���㡣 ��غ��� */
extern void ADC_ISR_EOS_Clr(void);
extern FlagStatus ADC_ISR_EOS_Chk(void);

/* ����ת������ (End Of Conversion)ÿ��ͨ��ת����ɺ���λEOC�����д1���㡣 ��غ��� */
extern void ADC_ISR_EOC_Clr(void);
extern FlagStatus ADC_ISR_EOC_Chk(void);

/* ģ�⿴�Ź�����ֵ���������ж�ʹ�ܣ�1��Ч (Analog Watchdog Above High Threshold Interrupt Enable) ��غ��� */
extern void ADC_IER_AWD_AHIE_Setable(FunState NewState);
extern FunState ADC_IER_AWD_AHIE_Getable(void);

/* ģ�⿴�Ź�����ֵ���������ж�ʹ�ܣ�1��Ч (Analog Watchdog Under Low Threshold Interrupt Enable) ��غ��� */
extern void ADC_IER_AWD_ULIE_Setable(FunState NewState);
extern FunState ADC_IER_AWD_ULIE_Getable(void);

/* У׼�����ж�ʹ�ܼĴ��� (End Of Calibration Interrupt Enable) 0����ֹEOCAL�ж� 1������EOCAL�ж� ��غ��� */
extern void ADC_IER_EOCALIE_Setable(FunState NewState);
extern FunState ADC_IER_EOCALIE_Getable(void);

/* ���ݳ�ͻ�ж�ʹ�ܼĴ��� (Over Run Interrupt Enable) 0����ֹ���ݳ�ͻ�ж� 1���������ݳ�ͻ�ж� ��غ��� */
extern void ADC_IER_OVRIE_Setable(FunState NewState);
extern FunState ADC_IER_OVRIE_Getable(void);

/* ת�����н����ж�ʹ�ܼĴ��� (End Of Sequence Interrupt Enable) 0����ֹEOS�ж� 1������EOS�ж� ��غ��� */
extern void ADC_IER_EOSIE_Setable(FunState NewState);
extern FunState ADC_IER_EOSIE_Getable(void);

/* ����ת�������ж�ʹ�ܼĴ��� (End Of Conversion Interrupt Enable) 0����ֹEOC�ж� 1������EOC�ж� ��غ��� */
extern void ADC_IER_EOCIE_Setable(FunState NewState);
extern FunState ADC_IER_EOCIE_Getable(void);

/* ADC����ת���Ĵ��������д1������Ӳ���Զ����㡣 ��غ��� */
extern void ADC_CR_START_Setable(FunState NewState);
extern FunState ADC_CR_START_Getable(void);

/* ADCʹ�ܼĴ��� (ADC Enable) ������ת��ǰ��Ҫ��λADEN���ȴ�����5��MCLK��������ת����0���ر�ADC 1��ʹ��ADC ��غ��� */
extern void ADC_CR_ADEN_Setable(FunState NewState);
extern FunState ADC_CR_ADEN_Getable(void);

/* ADC����ʱ��ѡ�� (ADC Clock Select) ��غ��� */
extern void ADC_CFGR_CKS_Set(uint32_t SetValue);
extern uint32_t ADC_CFGR_CKS_Get(void);

/* ģ�ⴰ�ڿ��Ź�����ͨ��ѡ�񣬽���AWDSC=1ʱ��Ч (Analog Watchdog Channel Select) ��غ��� */
extern void ADC_CFGR_AWDCH_Set(uint32_t SetValue);
extern uint32_t ADC_CFGR_AWDCH_Get(void);

/* ģ�ⴰ�ڿ��Ź���ͨ����ȫͨ��ѡ�� (Analog Watchdog Single Channel mode) ��غ��� */
extern void ADC_CFGR_AWDSC_Set(uint32_t SetValue);
extern uint32_t ADC_CFGR_AWDSC_Get(void);

/* ģ�ⴰ�ڿ��Ź�ʹ�ܼĴ��� (Analog Watchdog Enable) 0���ر�AWD 1��ʹ��AWD ������START=0�������ʹ��AWD ��غ��� */
extern void ADC_CFGR_AWDEN_Setable(FunState NewState);
extern FunState ADC_CFGR_AWDEN_Getable(void);

/* ��������λ���ƼĴ��� (Oversampling Shift) ��غ��� */
extern void ADC_CFGR_OVSS_Set(uint32_t SetValue);
extern uint32_t ADC_CFGR_OVSS_Get(void);

/* �������ʿ��� (Oversampling Ratio) ��غ��� */
extern void ADC_CFGR_OVSR_Set(uint32_t SetValue);
extern uint32_t ADC_CFGR_OVSR_Get(void);

/* ������ʹ�� (Oversampling Enable) 0����ֹ������ 1��ʹ�ܹ����� ��غ��� */
extern void ADC_CFGR_OVSEN_Setable(FunState NewState);
extern FunState ADC_CFGR_OVSEN_Getable(void);

/* ���Ŵ����ź������˲�ʹ�� (GPIO Trigger Filter Enable) 0����ֹ�����˲� 1��ʹ�������˲�  ��غ��� */
extern void ADC_CFGR_IOTRFEN_Setable(FunState NewState);
extern FunState ADC_CFGR_IOTRFEN_Getable(void);

/* �����ź�ʹ�ܺͼ���ѡ�� (Trigger Config) ��غ��� */
extern void ADC_CFGR_TRGCFG_Set(uint32_t SetValue);
extern uint32_t ADC_CFGR_TRGCFG_Get(void);

/* ����ת�����Զ�ģʽ (Semi-automatic)�����ڵ���ת����CONT=0��ʱ��Ч ��غ��� */
extern void ADC_CFGR_SEMI_Set(uint32_t SetValue);
extern uint32_t ADC_CFGR_SEMI_Get(void);

/* �ȴ�ģʽ���� (wait mode) 0���޵ȴ�������ϴ�ת������û�м�ʱ��ȡ������ܳ���Overrun 1���ȴ�ģʽ�����ϴ�ת�����ݱ���ȡǰ������������һ��ת�� ��غ��� */
extern void ADC_CFGR_WAIT_Setable(FunState NewState);
extern FunState ADC_CFGR_WAIT_Getable(void);

/* ����ת��ģʽʹ�� (Continuous mode) 0������ת�� 1������ת��  ��غ��� */
extern void ADC_CFGR_CONT_Setable(FunState NewState);
extern FunState ADC_CFGR_CONT_Getable(void);

/* Overrunģʽ���� (Overrun mode) ��غ��� */
extern void ADC_CFGR_OVRM_Set(uint32_t SetValue);
extern uint32_t ADC_CFGR_OVRM_Get(void);

/* Ӳ������Դѡ�� (External trigger select) ��غ��� */
extern void ADC_CFGR_EXTS_Set(uint32_t SetValue);
extern uint32_t ADC_CFGR_EXTS_Get(void);

/* ADC�͹���ģʽʹ�ܣ������������ (Low Power Mode) ��غ��� */
extern void ADC_CFGR_LPM_Set(uint32_t SetValue);
extern uint32_t ADC_CFGR_LPM_Get(void);

/* ͨ��ɨ��˳����� (Scan Direction)����16��ͨ����ʵ��ֻ�������ʹ�ܵ�ͨ���� ��غ��� */
extern void ADC_CFGR_SCANDIR_Set(uint32_t SetValue);
extern uint32_t ADC_CFGR_SCANDIR_Get(void);

/* DMAģʽ���� (DMA Config) ��غ��� */
extern void ADC_CFGR_DMACFG_Set(uint32_t SetValue);
extern uint32_t ADC_CFGR_DMACFG_Get(void);

/* DMAʹ�� (DMA Enable) 0����ֹDMA 1��ʹ��DMA  ��غ��� */
extern void ADC_CFGR_DMAEN_Setable(FunState NewState);
extern FunState ADC_CFGR_DMAEN_Getable(void);

/* ADC����ͨ���л��ȴ�ʱ�� (Channel Clock Gating) �ڵ�ǰͨ������������ɺ󣬵ȴ�CHCGʱ�䣨CHCG*ADC����ʱ�����ڣ������л�����һ������ͨ�� ��غ��� */
extern void ADC_SMTR_CHCG_Set(uint32_t SetValue);
extern uint32_t ADC_SMTR_CHCG_Get(void);

/* ����ͨ������ʱ����ƣ�*ADC����ʱ�����ڣ�����������ADC_IN8/9/10/11�ĸ��ⲿͨ�����Լ�OPAͨ���Ĳ���ʱ�� (Sampling Time Select 2)  ��غ��� */
extern void ADC_SMTR_SMTS2_Set(uint32_t SetValue);
extern uint32_t ADC_SMTR_SMTS2_Get(void);

/* ����ͨ������ʱ����ƣ�*ADC����ʱ�����ڣ�����������ADC_IN8/9/10/11�ĸ��ⲿͨ�����Լ�OPAͨ���Ĳ���ʱ�� (Sampling Time Select 2)  ��غ��� */
extern void ADC_SMTR_SMTS1_Set(uint32_t SetValue);
extern uint32_t ADC_SMTR_SMTS1_Get(void);

/* ���˺Ͳ��ͨ�����ã�4bit����4��ͨ�����Ƿ�Ϊ������룬0��ʾ�������룬1��ʾ������롣(Analog Input Select)�������Ϊ������룬��ÿ����ֶ�����Ӧ��ͨ����Ҫʹ�ܡ�
���磬��ADC_IN0��ADC_IN1����Ϊ�������ԣ���Ҫ���в�ֲ���ʱ��ECH0��ECH1��Ҫ��1�� ��غ��� */
extern void ADC_CHER_AINS_Set(uint32_t SetValue);
extern uint32_t ADC_CHER_AINS_Get(void);

/* OPA2���������д1ʹ�� (OPA2 channel)  ��غ��� */
extern void ADC_CHER_OPA2CH_Setable(FunState NewState);
extern FunState ADC_CHER_OPA2CH_Getable(void);

/* OPA1���������д1ʹ�� (OPA1 channel)  ��غ��� */
extern void ADC_CHER_OPA1CH_Setable(FunState NewState);
extern FunState ADC_CHER_OPA1CH_Getable(void);

/* �¶ȴ���������ͨ����д1ʹ�� (TempSensor channel)  ��غ��� */
extern void ADC_CHER_TSCH_Setable(FunState NewState);
extern FunState ADC_CHER_TSCH_Getable(void);

/* �ڲ���׼��ѹ����ͨ����д1ʹ�� (VREF channel)  ��غ��� */
extern void ADC_CHER_REFCH_Setable(FunState NewState);
extern FunState ADC_CHER_REFCH_Getable(void);

/* ADC_IN11 ����ͨ����д1ʹ��  ��غ��� */
extern void ADC_CHER_ECH11_Setable(FunState NewState);
extern FunState ADC_CHER_ECH11_Getable(void);

/* ADC_IN10 ����ͨ����д1ʹ��  ��غ��� */
extern void ADC_CHER_ECH10_Setable(FunState NewState);
extern FunState ADC_CHER_ECH10_Getable(void);

/* ADC_IN9 ����ͨ����д1ʹ�� ��غ��� */
extern void ADC_CHER_ECH9_Setable(FunState NewState);
extern FunState ADC_CHER_ECH9_Getable(void);

/* ADC_IN8 ����ͨ����д1ʹ�� ��غ��� */
extern void ADC_CHER_ECH8_Setable(FunState NewState);
extern FunState ADC_CHER_ECH8_Getable(void);

/* ADC_IN7 ����ͨ����д1ʹ�� ��غ��� */
extern void ADC_CHER_ECH7_Setable(FunState NewState);
extern FunState ADC_CHER_ECH7_Getable(void);

/* ADC_IN6 ����ͨ����д1ʹ�� ��غ��� */
extern void ADC_CHER_ECH6_Setable(FunState NewState);
extern FunState ADC_CHER_ECH6_Getable(void);

/* ADC_IN5 ����ͨ����д1ʹ�� ��غ��� */
extern void ADC_CHER_ECH5_Setable(FunState NewState);
extern FunState ADC_CHER_ECH5_Getable(void);

/* ADC_IN4 ����ͨ����д1ʹ�� ��غ��� */
extern void ADC_CHER_ECH4_Setable(FunState NewState);
extern FunState ADC_CHER_ECH4_Getable(void);

/* ADC_IN3 ����ͨ����д1ʹ�� ��غ��� */
extern void ADC_CHER_ECH3_Setable(FunState NewState);
extern FunState ADC_CHER_ECH3_Getable(void);

/* ADC_IN2 ����ͨ����д1ʹ�� ��غ��� */
extern void ADC_CHER_ECH2_Setable(FunState NewState);
extern FunState ADC_CHER_ECH2_Getable(void);

/* ADC_IN1 ����ͨ����д1ʹ�� ��غ��� */
extern void ADC_CHER_ECH1_Setable(FunState NewState);
extern FunState ADC_CHER_ECH1_Getable(void);

/* ADC_IN0 ����ͨ����д1ʹ�� ��غ��� */
extern void ADC_CHER_ECH0_Setable(FunState NewState);
extern FunState ADC_CHER_ECH0_Getable(void);

/* ADCת����� (ADC conversion data)��û��ʹ�ܹ�����ƽ��������£����Ϊ��12bit����ʹ�ܹ�����ƽ��������£����Ϊ12~16bit
 ��غ��� */
extern uint32_t ADC_DR_Read(void);

/* ADCת������ (Conversion with Calibration data) ��غ��� */
extern void ADC_CAL_CONV_CAL_Set(uint32_t SetValue);
extern uint32_t ADC_CAL_CONV_CAL_Get(void);

/* Calibrationʹ�� (Calibration Enable)���д1����У׼���ڣ�Ӳ����ʼУ׼���Զ����㡣���ͨ��EOCAL�Ĵ�����ѯУ׼���ڽ��� ��غ��� */
extern void ADC_CAL_CALEN_Setable(FunState NewState);
extern FunState ADC_CAL_CALEN_Getable(void);

/* AWD���Ӹ���ֵ (Analog Watchdog High Threshold) ��غ��� */
extern void ADC_HLTR_AWD_HT_Set(uint32_t SetValue);
extern uint32_t ADC_HLTR_AWD_HT_Get(void);

/* AWD���ӵ���ֵ (Analog Watchdog Low Threshold) ��غ��� */
extern void ADC_HLTR_AWD_LT_Set(uint32_t SetValue);
extern uint32_t ADC_HLTR_AWD_LT_Get(void);

#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_ADC_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
