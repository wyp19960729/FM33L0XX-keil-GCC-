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
	uint32_t PMOD;				/*!<�͹���ģʽ����  */	
	FunState CVS;				/*!<�ں˵�ѹ����ʹ�ܿ���  */
	uint32_t SLPDP;				/*!<DeepSleep���ƼĴ���  */
	uint32_t WKFSEL;		/*!<Sleep/DeepSleep���Ѻ��ϵͳƵ��  */	
	uint32_t LDO_LPM;		/*!<LDO�͹���ģʽ����  */
	uint32_t SCR;				/*!<M0ϵͳ���ƼĴ�����һ������Ϊ0����  */	
}PMU_SleepCfg_InitTypeDef;
	 
	 
//------------------------------------------------------------------------------   
#define	PMU_CR_LDO_LPM_Pos	18	/* LDO�͹���ģʽ���� (LDO Low Power Mode) */
#define	PMU_CR_LDO_LPM_Msk	(0x3U << PMU_CR_LDO_LPM_Pos)
#define	PMU_CR_LDO_LPM_DIS	(0x1U << PMU_CR_LDO_LPM_Pos)	/* 01: ����ģʽ */
#define	PMU_CR_LDO_LPM_EN	(0x2U << PMU_CR_LDO_LPM_Pos)	/* 10: LDO����͹���ģʽ */

#define	PMU_CR_LDO15EN_Pos	17	/* LDO15ʹ��״̬��ֻ�� */
#define	PMU_CR_LDO15EN_Msk	(0x1U << PMU_CR_LDO15EN_Pos)

#define	PMU_CR_LDO15EN_B_Pos	16
#define	PMU_CR_LDO15EN_B_Msk	(0x1U << PMU_CR_LDO15EN_B_Pos)

#define	PMU_CR_WKFSEL_Pos	10	/* Sleep/DeepSleep���Ѻ��ϵͳƵ�� (Wakeup Frequency Select) */
#define	PMU_CR_WKFSEL_Msk	(0x3U << PMU_CR_WKFSEL_Pos)
#define	PMU_CR_WKFSEL_RCHF_8M	(0x0U << PMU_CR_WKFSEL_Pos)	/* 00��RCHF-8MHz */
#define	PMU_CR_WKFSEL_RCHF_16M	(0x1U << PMU_CR_WKFSEL_Pos)	/* 01��RCHF-16MHz */
#define	PMU_CR_WKFSEL_RCHF_24M	(0x2U << PMU_CR_WKFSEL_Pos)	/* 10/11��RCHF-24MHz */

#define	PMU_CR_SLPDP_Pos	9	/* DeepSleep���Ƽ� */
#define	PMU_CR_SLPDP_Msk	(0x1U << PMU_CR_SLPDP_Pos)
#define	PMU_CR_SLPDP_SLEEP	(0x0U << PMU_CR_SLPDP_Pos)	/* 0��Sleepģʽ */
#define	PMU_CR_SLPDP_DEEPSLEEP	(0x1U << PMU_CR_SLPDP_Pos)	/* 1��DeepSleepģʽ */

#define	PMU_CR_CVS_Pos	8	/* �͹���ģʽ�ں˵�ѹ����0���͹���ģʽ�²�ʹ���ں˵�ѹ����1���͹���ģʽ�½����ں˵�ѹ ��Sleep�£������λ��SLPDPλ��ΪDeepSleepģʽ����λ����Sleep����Ч */
#define	PMU_CR_CVS_Msk	(0x1U << PMU_CR_CVS_Pos)

#define	PMU_CR_PMOD_Pos	0	/* �͹���ģʽ���üĴ��� (Power Mode) */
#define	PMU_CR_PMOD_Msk	(0x3U << PMU_CR_PMOD_Pos)
#define	PMU_CR_PMOD_ACTIVE	(0x0U << PMU_CR_PMOD_Pos)	/* 00��Active/LP Active mode */
#define	PMU_CR_PMOD_LPRUN	(0x1U << PMU_CR_PMOD_Pos)	/* 01: LPRUN mode */
#define	PMU_CR_PMOD_SLEEP	(0x2U << PMU_CR_PMOD_Pos)	/* 10��Sleep/DeepSleep mode */

#define	PMU_WKTR_TRHR_Pos	0	/* ����ʱ����ƼĴ��� */
#define	PMU_WKTR_TRHR_Msk	(0x3U << PMU_WKTR_TRHR_Pos)
#define	PMU_WKTR_TRHR_0US	(0x0U << PMU_WKTR_TRHR_Pos)	/* 00��0us */
#define	PMU_WKTR_TRHR_4US	(0x1U << PMU_WKTR_TRHR_Pos)	/* 01��4us */
#define	PMU_WKTR_TRHR_8US	(0x2U << PMU_WKTR_TRHR_Pos)	/* 10��8us */
#define	PMU_WKTR_TRHR_16US	(0x3U << PMU_WKTR_TRHR_Pos)	/* 11��16us */

#define	PMU_WKFR_ADCWKF_Pos	31	/* ADC�жϻ��ѱ�־ */
#define	PMU_WKFR_ADCWKF_Msk	(0x1U << PMU_WKFR_ADCWKF_Pos)

#define	PMU_WKFR_RTCWKF_Pos	28	/* RTC�жϻ��ѱ�־ */
#define	PMU_WKFR_RTCWKF_Msk	(0x1U << PMU_WKFR_RTCWKF_Pos)

#define	PMU_WKFR_SVDWKF_Pos	27	/* SVD�жϻ��ѱ�־ */
#define	PMU_WKFR_SVDWKF_Msk	(0x1U << PMU_WKFR_SVDWKF_Pos)

#define	PMU_WKFR_LFDETWKF_Pos	26	/* SVD�жϻ��ѱ�־ */
#define	PMU_WKFR_LFDETWKF_Msk	(0x1U << PMU_WKFR_LFDETWKF_Pos)

#define	PMU_WKFR_VREFWKF_Pos	25	/* VREF1P22��׼Դ�����жϻ��ѱ�־ */
#define	PMU_WKFR_VREFWKF_Msk	(0x1U << PMU_WKFR_VREFWKF_Pos)

#define	PMU_WKFR_IOWKF_Pos	24	/* IO�жϻ��ѱ�־ */
#define	PMU_WKFR_IOWKF_Msk	(0x1U << PMU_WKFR_IOWKF_Pos)

#define	PMU_WKFR_I2CWKF_Pos	23	/* I2C�жϻ��ѱ�־ */
#define	PMU_WKFR_I2CWKF_Msk	(0x1U << PMU_WKFR_I2CWKF_Pos)

#define	PMU_WKFR_LPU1WKF_Pos	21	/* LPUART1�жϻ��ѱ�־ */
#define	PMU_WKFR_LPU1WKF_Msk	(0x1U << PMU_WKFR_LPU1WKF_Pos)

#define	PMU_WKFR_LPU0WKF_Pos	20	/* LPUART0�жϻ��ѱ�־ */
#define	PMU_WKFR_LPU0WKF_Msk	(0x1U << PMU_WKFR_LPU0WKF_Pos)

#define	PMU_WKFR_UART1WKF_Pos	19	/* UART1�жϻ��ѱ�־ */
#define	PMU_WKFR_UART1WKF_Msk	(0x1U << PMU_WKFR_UART1WKF_Pos)

#define	PMU_WKFR_UART0WKF_Pos	18	/* UART0�жϻ��ѱ�־ */
#define	PMU_WKFR_UART0WKF_Msk	(0x1U << PMU_WKFR_UART0WKF_Pos)

#define	PMU_WKFR_OPA2WKF_Pos	17	/* OPA2���Ƚ���ģʽ���жϻ��ѱ�־ */
#define	PMU_WKFR_OPA2WKF_Msk	(0x1U << PMU_WKFR_OPA2WKF_Pos)

#define	PMU_WKFR_OPA1WKF_Pos	16	/* OPA1���Ƚ���ģʽ���жϻ��ѱ�־ */
#define	PMU_WKFR_OPA1WKF_Msk	(0x1U << PMU_WKFR_OPA1WKF_Pos)

#define	PMU_WKFR_LPTWKF_Pos	10	/* LPTIM32�жϻ��ѱ�־ */
#define	PMU_WKFR_LPTWKF_Msk	(0x1U << PMU_WKFR_LPTWKF_Pos)

#define	PMU_WKFR_BSTWKF_Pos	9	/* BSTIM32�жϻ��ѱ�־ */
#define	PMU_WKFR_BSTWKF_Msk	(0x1U << PMU_WKFR_BSTWKF_Pos)

#define	PMU_WKFR_DBGWKF_Pos	8	/* CPU Debugger���ѱ�־ */
#define	PMU_WKFR_DBGWKF_Msk	(0x1U << PMU_WKFR_DBGWKF_Pos)

#define	PMU_WKFR_WKP7F_Pos	7	/* NWKUP7 Pin���ѱ�־ */
#define	PMU_WKFR_WKP7F_Msk	(0x1U << PMU_WKFR_WKP7F_Pos)

#define	PMU_WKFR_WKP6F_Pos	6	/* NWKUP6 Pin���ѱ�־ */
#define	PMU_WKFR_WKP6F_Msk	(0x1U << PMU_WKFR_WKP6F_Pos)

#define	PMU_WKFR_WKP5F_Pos	5	/* NWKUP5 Pin���ѱ�־ */
#define	PMU_WKFR_WKP5F_Msk	(0x1U << PMU_WKFR_WKP5F_Pos)

#define	PMU_WKFR_WKP4F_Pos	4	/* NWKUP4 Pin���ѱ�־ */
#define	PMU_WKFR_WKP4F_Msk	(0x1U << PMU_WKFR_WKP4F_Pos)

#define	PMU_WKFR_WKP3F_Pos	3	/* NWKUP3 Pin���ѱ�־ */
#define	PMU_WKFR_WKP3F_Msk	(0x1U << PMU_WKFR_WKP3F_Pos)

#define	PMU_WKFR_WKP2F_Pos	2	/* NWKUP2 Pin���ѱ�־ */
#define	PMU_WKFR_WKP2F_Msk	(0x1U << PMU_WKFR_WKP2F_Pos)

#define	PMU_WKFR_WKP1F_Pos	1	/* NWKUP1 Pin���ѱ�־ */
#define	PMU_WKFR_WKP1F_Msk	(0x1U << PMU_WKFR_WKP1F_Pos)

#define	PMU_WKFR_WKP0F_Pos	0	/* NWKUP0 Pin���ѱ�־ */
#define	PMU_WKFR_WKP0F_Msk	(0x1U << PMU_WKFR_WKP0F_Pos)

#define	PMU_IER_LPACTEIE_Pos	2	/* LPACTIVE�����ж�ʹ��0����ֹLPACTIVE�����ж�1��ʹ��LPACTIVE�����ж� */
#define	PMU_IER_LPACTEIE_Msk	(0x1U << PMU_IER_LPACTEIE_Pos)

#define	PMU_IER_SLPEIE_Pos	1	/* SLEEP�����ж�ʹ��0����ֹSLEEP�����ж�1��ʹ��SLEEP�����ж� */
#define	PMU_IER_SLPEIE_Msk	(0x1U << PMU_IER_SLPEIE_Pos)

#define	PMU_ISR_LPACTEIF_Pos	2	/* LPACTIVE�����жϱ�־��Ӳ����λ�����д1���� */
#define	PMU_ISR_LPACTEIF_Msk	(0x1U << PMU_ISR_LPACTEIF_Pos)

#define	PMU_ISR_SLPEIF_Pos	1	/* SLEEP�����жϱ�־��Ӳ����λ�����д1���� */
#define	PMU_ISR_SLPEIF_Msk	(0x1U << PMU_ISR_SLPEIF_Pos)

#define	PMU_VREF_CR_EN_Pos	0	/* VREF1p2ʹ�ܼĴ��� (VREF Enable)  0���ر�VREF1p2   1��ʹ��VREF1p2 */
#define	PMU_VREF_CR_EN_Msk	(0x1U << PMU_VREF_CR_EN_Pos)

#define	PMU_VREF_SR_FLAG_B_Pos	8	/* ģ�������VREF1p22�Ĵ�����ѹ������־ (VREF stable Flag from analog) */
#define	PMU_VREF_SR_FLAG_B_Msk	(0x1U << PMU_VREF_SR_FLAG_B_Pos)

#define	PMU_VREF_SR_RDY_Pos	1	/* VREF1p22��׼��ѹ������־ (VREF Ready) */
#define	PMU_VREF_SR_RDY_Msk	(0x1U << PMU_VREF_SR_RDY_Pos)

#define	PMU_VREF_SR_IF_Pos	0	/* VREF1p22��׼��ѹ�����ж� (VREF Ready Flag) */
#define	PMU_VREF_SR_IF_Msk	(0x1U << PMU_VREF_SR_IF_Pos)

#define	PMU_VREF_IER_IE_Pos	0	/* VREF1p2��׼��ѹ�����ж�ʹ�� (VREF Ready Interrupt Enable) 0����ֹ����VREF��������ж� 1���������VREF��������ж� */
#define	PMU_VREF_IER_IE_Msk	(0x1U << PMU_VREF_IER_IE_Pos)

#define	PMU_BUF_CR_VREFPTAT_EN_Pos	4	/* ����bandgap���ptat��ѹ(PTAT VREF Enable) 0��Vptat ��ʹ�� 1��Vptat ʹ�� */
#define	PMU_BUF_CR_VREFPTAT_EN_Msk	(0x1U << PMU_BUF_CR_VREFPTAT_EN_Pos)

#define	PMU_BUF_CR_VPTATBUFFER_OUTEN_Pos	3	/* Vptat Bufferģ�鿪��ͨ�����ʹ���źţ��ߵ�ƽʹ����Ч��(PTAT Buffer Output Enable) 0��Vptat buffer ģ�������ʹ�� 1��Vptat buffer ģ�����ʹ�� */
#define	PMU_BUF_CR_VPTATBUFFER_OUTEN_Msk	(0x1U << PMU_BUF_CR_VPTATBUFFER_OUTEN_Pos)

#define	PMU_BUF_CR_VPTATBUFFER_EN_Pos	2	/* Vptat Bufferģ��ʹ���źţ��ߵ�ƽʹ����Ч��(PTAT Buffer Enable) 0��Vptat buffer ģ�鲻ʹ�� 1��Vptat buffer ģ��ʹ�� */
#define	PMU_BUF_CR_VPTATBUFFER_EN_Msk	(0x1U << PMU_BUF_CR_VPTATBUFFER_EN_Pos)

#define	PMU_BUF_CR_VREFBUFFER_OUTEN_Pos	1	/* Vref Bufferģ�鿪��ͨ�����ʹ���źţ��ߵ�ƽʹ����Ч��(VREF Buffer Output Enable) 0��Vref buffer ģ�������ʹ�� 1��Vref buffer ģ�����ʹ�� */
#define	PMU_BUF_CR_VREFBUFFER_OUTEN_Msk	(0x1U << PMU_BUF_CR_VREFBUFFER_OUTEN_Pos)

#define	PMU_BUF_CR_VREFBUFFER_EN_Pos	0	/* Vref Bufferģ��ʹ���źţ��ߵ�ƽʹ����Ч��(VREF Buffer Enable) 0��Vref buffer ģ�鲻ʹ��  1��Vref buffer ģ��ʹ�� */
#define	PMU_BUF_CR_VREFBUFFER_EN_Msk	(0x1U << PMU_BUF_CR_VREFBUFFER_EN_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void PMU_Deinit(void);

/* LDO�͹���ģʽ���� (LDO Low Power Mode) ��غ��� */
extern void PMU_CR_LDO_LPM_Set(uint32_t SetValue);
extern uint32_t PMU_CR_LDO_LPM_Get(void);

/* LDO15ʹ��״̬��ֻ�� ��غ��� */
extern FlagStatus PMU_CR_LDO15EN_Chk(void);
extern FlagStatus PMU_CR_LDO15EN_B_Chk(void);

/* Sleep/DeepSleep���Ѻ��ϵͳƵ�� (Wakeup Frequency Select) ��غ��� */
extern void PMU_CR_WKFSEL_Set(uint32_t SetValue);
extern uint32_t PMU_CR_WKFSEL_Get(void);

/* DeepSleep���Ƽ� ��غ��� */
extern void PMU_CR_SLPDP_Set(uint32_t SetValue);
extern uint32_t PMU_CR_SLPDP_Get(void);

/* �͹���ģʽ�ں˵�ѹ����0���͹���ģʽ�²�ʹ���ں˵�ѹ����1���͹���ģʽ�½����ں˵�ѹ ��Sleep�£������λ��SLPDPλ��ΪDeepSleepģʽ����λ����Sleep����Ч ��غ��� */
extern void PMU_CR_CVS_Setable(FunState NewState);
extern FunState PMU_CR_CVS_Getable(void);

/* �͹���ģʽ���üĴ��� (Power Mode) ��غ��� */
extern void PMU_CR_PMOD_Set(uint32_t SetValue);
extern uint32_t PMU_CR_PMOD_Get(void);

/* ����ʱ����ƼĴ��� ��غ��� */
extern void PMU_WKTR_TRHR_Set(uint32_t SetValue);
extern uint32_t PMU_WKTR_TRHR_Get(void);

/* ADC�жϻ��ѱ�־ ��غ��� */
extern FlagStatus PMU_WKFR_ADCWKF_Chk(void);

/* RTC�жϻ��ѱ�־ ��غ��� */
extern FlagStatus PMU_WKFR_RTCWKF_Chk(void);

/* SVD�жϻ��ѱ�־ ��غ��� */
extern FlagStatus PMU_WKFR_SVDWKF_Chk(void);

/* SVD�жϻ��ѱ�־ ��غ��� */
extern FlagStatus PMU_WKFR_LFDETWKF_Chk(void);

/* VREF1P22��׼Դ�����жϻ��ѱ�־ ��غ��� */
extern FlagStatus PMU_WKFR_VREFWKF_Chk(void);

/* IO�жϻ��ѱ�־ ��غ��� */
extern FlagStatus PMU_WKFR_IOWKF_Chk(void);

/* I2C�жϻ��ѱ�־ ��غ��� */
extern FlagStatus PMU_WKFR_I2CWKF_Chk(void);

/* LPUART1�жϻ��ѱ�־ ��غ��� */
extern FlagStatus PMU_WKFR_LPU1WKF_Chk(void);

/* LPUART0�жϻ��ѱ�־ ��غ��� */
extern FlagStatus PMU_WKFR_LPU0WKF_Chk(void);

/* UART1�жϻ��ѱ�־ ��غ��� */
extern FlagStatus PMU_WKFR_UART1WKF_Chk(void);

/* UART0�жϻ��ѱ�־ ��غ��� */
extern FlagStatus PMU_WKFR_UART0WKF_Chk(void);

/* OPA2���Ƚ���ģʽ���жϻ��ѱ�־ ��غ��� */
extern FlagStatus PMU_WKFR_OPA2WKF_Chk(void);

/* OPA1���Ƚ���ģʽ���жϻ��ѱ�־ ��غ��� */
extern FlagStatus PMU_WKFR_OPA1WKF_Chk(void);

/* LPTIM32�жϻ��ѱ�־ ��غ��� */
extern FlagStatus PMU_WKFR_LPTWKF_Chk(void);

/* BSTIM32�жϻ��ѱ�־ ��غ��� */
extern FlagStatus PMU_WKFR_BSTWKF_Chk(void);

/* CPU Debugger���ѱ�־ ��غ��� */
extern void PMU_WKFR_DBGWKF_Clr(void);
extern FlagStatus PMU_WKFR_DBGWKF_Chk(void);

/* NWKUP7 Pin���ѱ�־ ��غ��� */
extern void PMU_WKFR_WKP7F_Clr(void);
extern FlagStatus PMU_WKFR_WKP7F_Chk(void);

/* NWKUP6 Pin���ѱ�־ ��غ��� */
extern void PMU_WKFR_WKP6F_Clr(void);
extern FlagStatus PMU_WKFR_WKP6F_Chk(void);

/* NWKUP5 Pin���ѱ�־ ��غ��� */
extern void PMU_WKFR_WKP5F_Clr(void);
extern FlagStatus PMU_WKFR_WKP5F_Chk(void);

/* NWKUP4 Pin���ѱ�־ ��غ��� */
extern void PMU_WKFR_WKP4F_Clr(void);
extern FlagStatus PMU_WKFR_WKP4F_Chk(void);

/* NWKUP3 Pin���ѱ�־ ��غ��� */
extern void PMU_WKFR_WKP3F_Clr(void);
extern FlagStatus PMU_WKFR_WKP3F_Chk(void);

/* NWKUP2 Pin���ѱ�־ ��غ��� */
extern void PMU_WKFR_WKP2F_Clr(void);
extern FlagStatus PMU_WKFR_WKP2F_Chk(void);

/* NWKUP1 Pin���ѱ�־ ��غ��� */
extern void PMU_WKFR_WKP1F_Clr(void);
extern FlagStatus PMU_WKFR_WKP1F_Chk(void);

/* NWKUP0 Pin���ѱ�־ ��غ��� */
extern void PMU_WKFR_WKP0F_Clr(void);
extern FlagStatus PMU_WKFR_WKP0F_Chk(void);

/* LPACTIVE�����ж�ʹ��0����ֹLPACTIVE�����ж�1��ʹ��LPACTIVE�����ж� ��غ��� */
extern void PMU_IER_LPACTEIE_Setable(FunState NewState);
extern FunState PMU_IER_LPACTEIE_Getable(void);

/* SLEEP�����ж�ʹ��0����ֹSLEEP�����ж�1��ʹ��SLEEP�����ж� ��غ��� */
extern void PMU_IER_SLPEIE_Setable(FunState NewState);
extern FunState PMU_IER_SLPEIE_Getable(void);

/* LPACTIVE�����жϱ�־��Ӳ����λ�����д1���� ��غ��� */
extern void PMU_ISR_LPACTEIF_Clr(void);
extern FlagStatus PMU_ISR_LPACTEIF_Chk(void);

/* SLEEP�����жϱ�־��Ӳ����λ�����д1���� ��غ��� */
extern void PMU_ISR_SLPEIF_Clr(void);
extern FlagStatus PMU_ISR_SLPEIF_Chk(void);

/* VREF1p2ʹ�ܼĴ��� (VREF Enable)  0���ر�VREF1p2   1��ʹ��VREF1p2 ��غ��� */
extern void PMU_VREF_CR_EN_Setable(FunState NewState);
extern FunState PMU_VREF_CR_EN_Getable(void);

/* ģ�������VREF1p22�Ĵ�����ѹ������־ (VREF stable Flag from analog) ��غ��� */
extern FlagStatus PMU_VREF_SR_FLAG_B_Chk(void);

/* VREF1p22��׼��ѹ������־ (VREF Ready) ��غ��� */
extern FlagStatus PMU_VREF_SR_RDY_Chk(void);

/* VREF1p22��׼��ѹ�����ж� (VREF Ready Flag) ��غ��� */
extern void PMU_VREF_SR_IF_Clr(void);
extern FlagStatus PMU_VREF_SR_IF_Chk(void);

/* VREF1p2��׼��ѹ�����ж�ʹ�� (VREF Ready Interrupt Enable) 0����ֹ����VREF��������ж� 1���������VREF��������ж� ��غ��� */
extern void PMU_VREF_IER_IE_Setable(FunState NewState);
extern FunState PMU_VREF_IER_IE_Getable(void);

/* ����bandgap���ptat��ѹ(PTAT VREF Enable) 0��Vptat ��ʹ�� 1��Vptat ʹ�� ��غ��� */
extern void PMU_BUF_CR_VREFPTAT_EN_Setable(FunState NewState);
extern FunState PMU_BUF_CR_VREFPTAT_EN_Getable(void);

/* Vptat Bufferģ�鿪��ͨ�����ʹ���źţ��ߵ�ƽʹ����Ч��(PTAT Buffer Output Enable) 0��Vptat buffer ģ�������ʹ�� 1��Vptat buffer ģ�����ʹ�� ��غ��� */
extern void PMU_BUF_CR_VPTATBUFFER_OUTEN_Setable(FunState NewState);
extern FunState PMU_BUF_CR_VPTATBUFFER_OUTEN_Getable(void);

/* Vptat Bufferģ��ʹ���źţ��ߵ�ƽʹ����Ч��(PTAT Buffer Enable) 0��Vptat buffer ģ�鲻ʹ�� 1��Vptat buffer ģ��ʹ�� ��غ��� */
extern void PMU_BUF_CR_VPTATBUFFER_EN_Setable(FunState NewState);
extern FunState PMU_BUF_CR_VPTATBUFFER_EN_Getable(void);

/* Vref Bufferģ�鿪��ͨ�����ʹ���źţ��ߵ�ƽʹ����Ч��(VREF Buffer Output Enable) 0��Vref buffer ģ�������ʹ�� 1��Vref buffer ģ�����ʹ�� ��غ��� */
extern void PMU_BUF_CR_VREFBUFFER_OUTEN_Setable(FunState NewState);
extern FunState PMU_BUF_CR_VREFBUFFER_OUTEN_Getable(void);

/* Vref Bufferģ��ʹ���źţ��ߵ�ƽʹ����Ч��(VREF Buffer Enable) 0��Vref buffer ģ�鲻ʹ��  1��Vref buffer ģ��ʹ�� ��غ��� */
extern void PMU_BUF_CR_VREFBUFFER_EN_Setable(FunState NewState);
extern FunState PMU_BUF_CR_VREFBUFFER_EN_Getable(void);

extern void PMU_BUF_ALLDISABLE(void);
/********************************
�͹���ģʽ�ĳ�ʼ������
����:�͹���ģʽ�¸������ã�SLEEPģʽ��RAM�������ã��ں˵�ѹ�������·�ȡ�
���룺�͹��Ĺ��ܿ���ǰ������.
 ********************************/
extern void PMU_SleepCfg_Init(PMU_SleepCfg_InitTypeDef* SleepCfg_InitStruct);

#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_PMU_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
