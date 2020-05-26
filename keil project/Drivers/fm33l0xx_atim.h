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

#define	ATIM_CR1_CKD_Pos	8	/* Dead time�������˲�ʱ��Ƶ�ʷ�Ƶ�Ĵ��� */
#define	ATIM_CR1_CKD_Msk	(0x3U << ATIM_CR1_CKD_Pos)
#define	ATIM_CR1_CKD_1TINT	(0x0U << ATIM_CR1_CKD_Pos)	/* 0��TCK */
#define	ATIM_CR1_CKD_2TINT	(0x1U << ATIM_CR1_CKD_Pos)	/* 1��2TCK */
#define	ATIM_CR1_CKD_4TINT	(0x2U << ATIM_CR1_CKD_Pos)	/* 2��4TCK */

#define	ATIM_CR1_ARPE_Pos	7	/* ARRԤװ��ʹ��  */
#define	ATIM_CR1_ARPE_Msk	(0x1U << ATIM_CR1_ARPE_Pos)
	/* 0��ARR��ʹ��Ԥװ�� */
	/* 1��ARR ʹ��Ԥװ�� */

#define	ATIM_CR1_CMS_Pos	5	/* ����������ģʽѡ�� */
#define	ATIM_CR1_CMS_Msk	(0x3U << ATIM_CR1_CMS_Pos)
#define	ATIM_CR1_CMS_SINGLE 	(0x0U << ATIM_CR1_CMS_Pos)	/* 00�����ض���ģʽ */
#define	ATIM_CR1_CMS_CENTRAL1	(0x1U << ATIM_CR1_CMS_Pos)	/* 01���������ģʽ1������Ƚ��жϱ�־���ڼ��������¼����Ĺ�������λ */
#define	ATIM_CR1_CMS_CENTRAL2	(0x2U << ATIM_CR1_CMS_Pos)	/* 10���������ģʽ2������Ƚ��жϱ�־���ڼ��������ϼ����Ĺ�������λ */
#define	ATIM_CR1_CMS_CENTRAL3	(0x3U << ATIM_CR1_CMS_Pos)	/* 11���������ģʽ3������Ƚ��жϱ�־�ڼ������������¼����Ĺ����ж�����λ */

#define	ATIM_CR1_DIR_Pos	4	/* ��������Ĵ��� */
#define	ATIM_CR1_DIR_Msk	(0x1U << ATIM_CR1_DIR_Pos)
#define	ATIM_CR1_DIR_UP	(0x0U << ATIM_CR1_DIR_Pos)	/* 0�����ϼ��� */
#define	ATIM_CR1_DIR_DOWN	(0x1U << ATIM_CR1_DIR_Pos)	/* 1�����¼��� */

#define	ATIM_CR1_OPM_Pos	3	/* ���������ģʽ */
#define	ATIM_CR1_OPM_Msk	(0x1U << ATIM_CR1_OPM_Pos)
	/* 0��Update Event����ʱ��������ֹͣ */
	/* 1��Update Event����ʱ������ֹͣ���Զ�����CEN�� */

#define	ATIM_CR1_URS_Pos	2	/* ��������ѡ�� */
#define	ATIM_CR1_URS_Msk	(0x1U << ATIM_CR1_URS_Pos)
	/* 0�������¼��ܹ�����update�жϻ�DMA����
-������������������
-�����λUG�Ĵ���
-�ӻ�����������update */
	/* 1���������������������������update�жϻ�DMA���� */

#define	ATIM_CR1_UDIS_Pos	1	/* ��ֹupdate */
#define	ATIM_CR1_UDIS_Msk	(0x1U << ATIM_CR1_UDIS_Pos)
	/* 0��ʹ��update�¼��������¼�����ʱ����update�¼�
-������������������
-�����λUG�Ĵ���
-�ӻ�����������update */
	/* 1����ֹupdate�¼���������shadow�Ĵ�������UG��λ��ӻ��������յ�Ӳ��resetʱ���³�ʼ����������Ԥ��Ƶ�� */

#define	ATIM_CR1_CEN_Pos	0	/* ������ʹ�� */
#define	ATIM_CR1_CEN_Msk	(0x1U << ATIM_CR1_CEN_Pos)
	/* 0���������ر� */
	/* 1��������ʹ�� */

#define	ATIM_CR2_OIS4_Pos	14	/* �ο�OIS1 */
#define	ATIM_CR2_OIS4_Msk	(0x1U << ATIM_CR2_OIS4_Pos)

#define	ATIM_CR2_OIS3N_Pos	13	/* �ο�OIS1N */
#define	ATIM_CR2_OIS3N_Msk	(0x1U << ATIM_CR2_OIS3N_Pos)

#define	ATIM_CR2_OIS3_Pos	12	/* �ο�OIS1 */
#define	ATIM_CR2_OIS3_Msk	(0x1U << ATIM_CR2_OIS3_Pos)

#define	ATIM_CR2_OIS2N_Pos	11	/* �ο�OIS1N */
#define	ATIM_CR2_OIS2N_Msk	(0x1U << ATIM_CR2_OIS2N_Pos)

#define	ATIM_CR2_OIS2_Pos	10	/* �ο�OIS1 */
#define	ATIM_CR2_OIS2_Msk	(0x1U << ATIM_CR2_OIS2_Pos)

#define	ATIM_CR2_OIS1N_Pos	9	/* OC1N�����IDLE״̬ */
#define	ATIM_CR2_OIS1N_Msk	(0x1U << ATIM_CR2_OIS1N_Pos)
	/* 0����MOE=0ʱ������dead time��OC1N=0 */
	/* 1����MOE=0ʱ������dead time��OC1N=1 */

#define	ATIM_CR2_OIS1_Pos	8	/* OC1�����IDLE״̬ */
#define	ATIM_CR2_OIS1_Msk	(0x1U << ATIM_CR2_OIS1_Pos)
	/* 0����MOE=0ʱ�����ʹ���˻���������辭��dead time�󣩣�OC1=0 */
	/* 1����MOE=0ʱ�����ʹ���˻���������辭��dead time�󣩣�OC1=1 */

#define	ATIM_CR2_TI1S_Pos	7	/* ATIM����TI1ѡ�� */
#define	ATIM_CR2_TI1S_Msk	(0x1U << ATIM_CR2_TI1S_Pos)
#define	ATIM_CR2_TI1S_CH1	(0x0U << ATIM_CR2_TI1S_Pos)	/* 0��ATIM_CH1�������ӵ�TI1���� */
#define	ATIM_CR2_TI1S_XOR	(0x1U << ATIM_CR2_TI1S_Pos)	/* 1��ATIM_CH1��CH2��CH3����XOR�����ӵ�TI1���� */

#define	ATIM_CR2_MMS_Pos	4	/* ����ģʽѡ��������������ģʽ����ӻ����͵�ͬ�������źţ�TRGO��Դ */
#define	ATIM_CR2_MMS_Msk	(0x7U << ATIM_CR2_MMS_Pos)
#define	ATIM_CR2_MMS_EGR	(0x0U << ATIM_CR2_MMS_Pos)	/* 000��ATIM_EGR��UG�Ĵ���������TRGO */
#define	ATIM_CR2_MMS_CEN	(0x1U << ATIM_CR2_MMS_Pos)	/* 001��������ʹ���ź�CNT_EN������TRGO��������ͬʱ���������ʱ�� */
#define	ATIM_CR2_MMS_UE	(0x2U << ATIM_CR2_MMS_Pos)	/* 010��UE��update event���źű�����TRGO */
#define	ATIM_CR2_MMS_COMP	(0x3U << ATIM_CR2_MMS_Pos)	/* 011���Ƚ����壬���CC1IF��־��Ҫ��λ��TRGO���һ�������� */
#define	ATIM_CR2_MMS_OC1REF	(0x4U << ATIM_CR2_MMS_Pos)	/* 100��OC1REF����TRGO */
#define	ATIM_CR2_MMS_OC2REF	(0x5U << ATIM_CR2_MMS_Pos)	/* 101��OC2REF����TRGO */
#define	ATIM_CR2_MMS_OC3REF	(0x6U << ATIM_CR2_MMS_Pos)	/* 110��OC3REF����TRGO */
#define	ATIM_CR2_MMS_OC4REF	(0x7U << ATIM_CR2_MMS_Pos)	/* 111��OC4REF����TRGO */

#define	ATIM_CR2_CCDS_Pos	3	/* ��׽/�Ƚ� DMAѡ�� */
#define	ATIM_CR2_CCDS_Msk	(0x1U << ATIM_CR2_CCDS_Pos)
#define	ATIM_CR2_CCDS_CC	(0x0U << ATIM_CR2_CCDS_Pos)	/* 0����׽/�Ƚ��¼�����ʱ����DMA���� */
#define	ATIM_CR2_CCDS_UE	(0x1U << ATIM_CR2_CCDS_Pos)	/* 1��Update Event����ʱ����DMA���� */

#define	ATIM_CR2_CCUS_Pos	2	/* ��׽/�ȽϿ��ƼĴ�������ѡ�� */
#define	ATIM_CR2_CCUS_Msk	(0x1U << ATIM_CR2_CCUS_Pos)
#define	ATIM_CR2_CCUS_COMG	(0x0U << ATIM_CR2_CCUS_Pos)	/* 0������׽/�ȽϿ��ƼĴ���ʹ����preload��CCPC=1�������ǽ�����λCOMG�Ĵ���ʱ���� */
#define	ATIM_CR2_CCUS_COMG_TRGI	(0x1U << ATIM_CR2_CCUS_Pos)	/* 1������׽/�ȽϿ��ƼĴ���ʹ����preload��CCPC=1������������λCOMG�Ĵ�������TRGI������ʱ���� */

#define	ATIM_CR2_CCPC_Pos	0
#define	ATIM_CR2_CCPC_Msk	(0x1U << ATIM_CR2_CCPC_Pos)
	/* 0��CCxE, CCxNE, OCxM�Ĵ�����ʹ��preload */

#define	ATIM_SMCR_ETP_Pos	15	/* �ⲿ�����źż������� */
#define	ATIM_SMCR_ETP_Msk	(0x1U << ATIM_SMCR_ETP_Pos)
#define	ATIM_SMCR_ETP_POS	(0x0U << ATIM_SMCR_ETP_Pos)	/* 0���ߵ�ƽ����������Ч */
#define	ATIM_SMCR_ETP_NEG	(0x1U << ATIM_SMCR_ETP_Pos)	/* 1���͵�ƽ���½�����Ч */

#define	ATIM_SMCR_ECE_Pos	14	/* �ⲿʱ��ʹ�� */
#define	ATIM_SMCR_ECE_Msk	(0x1U << ATIM_SMCR_ECE_Pos)
	/* 0���ر��ⲿʱ��ģʽ2 */
	/* 1��ʹ���ⲿʱ��ģʽ2��������ʱ��ΪETRF��Ч�� */

#define	ATIM_SMCR_ETPS_Pos	12	/* �ⲿ�����ź�Ԥ��Ƶ�Ĵ���,�ⲿ�����ź�ETRP��Ƶ�����ֻ����ATIM����ʱ�ӵ�1/4���������ź�Ƶ�ʽϸ�ʱ������ʹ��Ԥ��Ƶ */
#define	ATIM_SMCR_ETPS_Msk	(0x3U << ATIM_SMCR_ETPS_Pos)
#define	ATIM_SMCR_ETPS_DIV1	(0x0U << ATIM_SMCR_ETPS_Pos)	/* 00������Ƶ */
#define	ATIM_SMCR_ETPS_DIV2	(0x1U << ATIM_SMCR_ETPS_Pos)	/* 01��2��Ƶ */
#define	ATIM_SMCR_ETPS_DIV4	(0x2U << ATIM_SMCR_ETPS_Pos)	/* 10��4��Ƶ */
#define	ATIM_SMCR_ETPS_DIV8	(0x3U << ATIM_SMCR_ETPS_Pos)	/* 11��8��Ƶ */

#define	ATIM_SMCR_ETF_Pos	8	/* �ⲿ�����ź��˲�ʱ�Ӻͳ���ѡ�� */
#define	ATIM_SMCR_ETF_Msk	(0xfU << ATIM_SMCR_ETF_Pos)
#define	ATIM_SMCR_ETF_FILT0	(0x0U << ATIM_SMCR_ETF_Pos)	/* 0000�����˲� */
#define	ATIM_SMCR_ETF_FILT1	(0x1U << ATIM_SMCR_ETF_Pos)	/* 0001��fSAMPLING=fCK_INT, N=2 */
#define	ATIM_SMCR_ETF_FILT2	(0x2U << ATIM_SMCR_ETF_Pos)	/* 0010��fSAMPLING=fCK_INT, N=4 */
#define	ATIM_SMCR_ETF_FILT3	(0x3U << ATIM_SMCR_ETF_Pos)	/* 0011��fSAMPLING=fCK_INT, N=8 */
#define	ATIM_SMCR_ETF_FILT4	(0x4U << ATIM_SMCR_ETF_Pos)	/* 0100��fSAMPLING=fDTS/2, N=6 */
#define	ATIM_SMCR_ETF_FILT5	(0x5U << ATIM_SMCR_ETF_Pos)	/* 0101��fSAMPLING=fDTS/2, N=8 */
#define	ATIM_SMCR_ETF_FILT6	(0x6U << ATIM_SMCR_ETF_Pos)	/* 0110��fSAMPLING=fDTS/4, N=6 */
#define	ATIM_SMCR_ETF_FILT7	(0x7U << ATIM_SMCR_ETF_Pos)	/* 0111��fSAMPLING=fDTS/4, N=8 */
#define	ATIM_SMCR_ETF_FILT8	(0x8U << ATIM_SMCR_ETF_Pos)	/* 1000��fSAMPLING=fDTS/8, N=6 */
#define	ATIM_SMCR_ETF_FILT9	(0x9U << ATIM_SMCR_ETF_Pos)	/* 1001��fSAMPLING=fDTS/8, N=8 */
#define	ATIM_SMCR_ETF_FILT10	(0xaU << ATIM_SMCR_ETF_Pos)	/* 1010��fSAMPLING=fDTS/16, N=5 */
#define	ATIM_SMCR_ETF_FILT11	(0xbU << ATIM_SMCR_ETF_Pos)	/* 1011��fSAMPLING=fDTS/16, N=6 */
#define	ATIM_SMCR_ETF_FILT12	(0xcU << ATIM_SMCR_ETF_Pos)	/* 1100��fSAMPLING=fDTS/16, N=8 */
#define	ATIM_SMCR_ETF_FILT13	(0xdU << ATIM_SMCR_ETF_Pos)	/* 1101��fSAMPLING=fDTS/32, N=5 */
#define	ATIM_SMCR_ETF_FILT14	(0xeU << ATIM_SMCR_ETF_Pos)	/* 1110��fSAMPLING=fDTS/32, N=6 */
#define	ATIM_SMCR_ETF_FILT15	(0xfU << ATIM_SMCR_ETF_Pos)	/* 1111��fSAMPLING=fDTS/32, N=8 */

#define	ATIM_SMCR_MSM_Pos	7	/* �����ӻ�ģʽѡ */
#define	ATIM_SMCR_MSM_Msk	(0x1U << ATIM_SMCR_MSM_Pos)
#define	ATIM_SMCR_MSM_NONE	(0x0U << ATIM_SMCR_MSM_Pos)	/* 0���޶��� */
#define	ATIM_SMCR_MSM_DELAY	(0x1U << ATIM_SMCR_MSM_Pos)	/* 1������ģʽ�£�TRGI�����Ķ������ӳ٣��Ա���ͨ��TRGOʵ�ֵ�ǰ��ʱ���ʹӻ���ʱ��ͬ�� */

#define	ATIM_SMCR_TS_Pos	4	/* ����ѡ������ѡ��ͬ���������Ĵ���Դ */
#define	ATIM_SMCR_TS_Msk	(0x7U << ATIM_SMCR_TS_Pos)
#define	ATIM_SMCR_TS_ITR0	(0x0U << ATIM_SMCR_TS_Pos)	/* 000���ڲ������źţ�ITR0�� */
#define	ATIM_SMCR_TS_ITR1	(0x1U << ATIM_SMCR_TS_Pos)	/* 001���ڲ������źţ�ITR1�� */
#define	ATIM_SMCR_TS_ITR2	(0x2U << ATIM_SMCR_TS_Pos)	/* 010���ڲ������źţ�ITR2�� */
#define	ATIM_SMCR_TS_ITR3	(0x3U << ATIM_SMCR_TS_Pos)	/* 011���ڲ������źţ�ITR3�� */
#define	ATIM_SMCR_TS_TI1F_ED	(0x4U << ATIM_SMCR_TS_Pos)	/* 100��TI1���ؼ�⣨TI1F_ED�� */
#define	ATIM_SMCR_TS_TI1FP1	(0x5U << ATIM_SMCR_TS_Pos)	/* 101���˲���TI1��TI1FP1�� */
#define	ATIM_SMCR_TS_TI2FP2	(0x6U << ATIM_SMCR_TS_Pos)	/* 110���˲���TI2��TI2FP2�� */
#define	ATIM_SMCR_TS_ETRF	(0x7U << ATIM_SMCR_TS_Pos)	/* 111���ⲿ�������루ETRF�� */

#define	ATIM_SMCR_SMS_Pos	0	/* �ӻ�ģʽѡ�� */
#define	ATIM_SMCR_SMS_Msk	(0x7U << ATIM_SMCR_SMS_Pos)
#define	ATIM_SMCR_SMS_SLAVE_DIS	(0x0U << ATIM_SMCR_SMS_Pos)	/* 000���ӻ�ģʽ��ֹ��CENʹ�ܺ�Ԥ��Ƶ��·ʱ��Դ�����ڲ�ʱ�� */
#define	ATIM_SMCR_SMS_ENCODER1	(0x1U << ATIM_SMCR_SMS_Pos)	/* 001��Encoderģʽ1��������ʹ��TI2FP2���أ�����TI1��ƽ�ߵ������� */
#define	ATIM_SMCR_SMS_ENCODER2	(0x2U << ATIM_SMCR_SMS_Pos)	/* 010��Encoderģʽ2��������ʹ��TI1FP1���أ�����TI2��ƽ�ߵ������� */
#define	ATIM_SMCR_SMS_ENCODER3	(0x3U << ATIM_SMCR_SMS_Pos)	/* 011��Encoderģʽ3��������ͬʱʹ��TI1FP1��TI2FP2���أ��������������źŵ�ƽ������ */
#define	ATIM_SMCR_SMS_RESET	(0x4U << ATIM_SMCR_SMS_Pos)	/* 100����λģʽ��TRGI�����س�ʼ�����������������Ĵ���update */
#define	ATIM_SMCR_SMS_GATE	(0x5U << ATIM_SMCR_SMS_Pos)	/* 101��բ��ģʽ��TRGIΪ�ߵ�ƽʱ������ʱ��ʹ�ܣ�TRGIΪ�͵�ƽʱ������ʱ��ֹͣ */
#define	ATIM_SMCR_SMS_TRIG	(0x6U << ATIM_SMCR_SMS_Pos)	/* 110������ģʽ��TRGI�����ش�����������ʼ���������Ḵλ�������� */
#define	ATIM_SMCR_SMS_EXCLK	(0x7U << ATIM_SMCR_SMS_Pos)	/* 111���ⲿʱ��ģʽ1��TRGI������ֱ������������ */

#define	ATIM_DIER_CC4BURSTEN_Pos	19	/* ��׽�Ƚ�ͨ��4��DMAģʽ���� */
#define	ATIM_DIER_CC4BURSTEN_Msk	(0x1U << ATIM_DIER_CC4BURSTEN_Pos)
#define	ATIM_DIER_CC4BURSTEN_SINGLE	(0x0U << ATIM_DIER_CC4BURSTEN_Pos)	/* 0��Singleģʽ��������CCR */
#define	ATIM_DIER_CC4BURSTEN_BURST	(0x1U << ATIM_DIER_CC4BURSTEN_Pos)	/* 1��Burstģʽ��ͨ��DCR���÷��ʵĵ�ַ�ͳ��� */

#define	ATIM_DIER_CC3BURSTEN_Pos	18	/* ��׽�Ƚ�ͨ��3��DMAģʽ���� */
#define	ATIM_DIER_CC3BURSTEN_Msk	(0x1U << ATIM_DIER_CC3BURSTEN_Pos)
#define	ATIM_DIER_CC3BURSTEN_SINGLE	(0x0U << ATIM_DIER_CC3BURSTEN_Pos)	/* 0��Singleģʽ��������CCR */
#define	ATIM_DIER_CC3BURSTEN_BURST	(0x1U << ATIM_DIER_CC3BURSTEN_Pos)	/* 1��Burstģʽ��ͨ��DCR���÷��ʵĵ�ַ�ͳ��� */

#define	ATIM_DIER_CC2BURSTEN_Pos	17	/* ��׽�Ƚ�ͨ��2��DMAģʽ���� */
#define	ATIM_DIER_CC2BURSTEN_Msk	(0x1U << ATIM_DIER_CC2BURSTEN_Pos)
#define	ATIM_DIER_CC2BURSTEN_SINGLE	(0x0U << ATIM_DIER_CC2BURSTEN_Pos)	/* 0��Singleģʽ��������CCR */
#define	ATIM_DIER_CC2BURSTEN_BURST	(0x1U << ATIM_DIER_CC2BURSTEN_Pos)	/* 1��Burstģʽ��ͨ��DCR���÷��ʵĵ�ַ�ͳ��� */

#define	ATIM_DIER_CC1BURSTEN_Pos	16	/* ��׽�Ƚ�ͨ��1��DMAģʽ���� */
#define	ATIM_DIER_CC1BURSTEN_Msk	(0x1U << ATIM_DIER_CC1BURSTEN_Pos)
#define	ATIM_DIER_CC1BURSTEN_SINGLE	(0x0U << ATIM_DIER_CC1BURSTEN_Pos)	/* 0��Singleģʽ��������CCR */
#define	ATIM_DIER_CC1BURSTEN_BURST	(0x1U << ATIM_DIER_CC1BURSTEN_Pos)	/* 1��Burstģʽ��ͨ��DCR���÷��ʵĵ�ַ�ͳ��� */

#define	ATIM_DIER_TDE_Pos	14	/* �ⲿ����DMA����ʹ�� */
#define	ATIM_DIER_TDE_Msk	(0x1U << ATIM_DIER_TDE_Pos)
	/* 0���ӻ�ģʽ�£���ֹ�ⲿ�����¼�����DMA���� */
	/* 1���ӻ�ģʽ�£������ⲿ�����¼�����DMA���� */

#define	ATIM_DIER_COMDE_Pos	13	/* COM�¼�DMA����ʹ�� */
#define	ATIM_DIER_COMDE_Msk	(0x1U << ATIM_DIER_COMDE_Pos)
	/* 0��COM�¼�����ʱ����ֹ����DMA���� */
	/* 1��COM�¼�����ʱ���������DMA���� */

#define	ATIM_DIER_CC4DE_Pos	12	/* ��׽�Ƚ�ͨ��4��DMA����ʹ�� */
#define	ATIM_DIER_CC4DE_Msk	(0x1U << ATIM_DIER_CC4DE_Pos)
	/* 0����ֹCC4 DMA���� */
	/* 1������CC4 DMA���� */

#define	ATIM_DIER_CC3DE_Pos	11	/* ��׽�Ƚ�ͨ��3��DMA����ʹ�� */
#define	ATIM_DIER_CC3DE_Msk	(0x1U << ATIM_DIER_CC3DE_Pos)
	/* 0����ֹCC3 DMA���� */
	/* 1������CC3 DMA���� */

#define	ATIM_DIER_CC2DE_Pos	10	/* ��׽�Ƚ�ͨ��2��DMA����ʹ�� */
#define	ATIM_DIER_CC2DE_Msk	(0x1U << ATIM_DIER_CC2DE_Pos)
	/* 0����ֹCC2 DMA���� */
	/* 1������CC2 DMA���� */

#define	ATIM_DIER_CC1DE_Pos	9	/* ��׽�Ƚ�ͨ��1��DMA����ʹ�� */
#define	ATIM_DIER_CC1DE_Msk	(0x1U << ATIM_DIER_CC1DE_Pos)
	/* 0����ֹCC1 DMA���� */
	/* 1������CC1 DMA���� */

#define	ATIM_DIER_UDE_Pos	8	/* �����¼�DMA����ʹ��  */
#define	ATIM_DIER_UDE_Msk	(0x1U << ATIM_DIER_UDE_Pos)
	/* 0��Update Event����ʱ����ֹ����DMA���� */
	/* 1��Update Event����ʱ���������DMA���� */

#define	ATIM_DIER_BIE_Pos	7	/* ɲ���¼��ж�ʹ�� */
#define	ATIM_DIER_BIE_Msk	(0x1U << ATIM_DIER_BIE_Pos)
	/* 0����ֹɲ���¼��ж� */
	/* 1������ɲ���¼��ж� */

#define	ATIM_DIER_TIE_Pos	6	/* �����¼��ж�ʹ�� */
#define	ATIM_DIER_TIE_Msk	(0x1U << ATIM_DIER_TIE_Pos)
	/* 0����ֹ�����¼��ж� */
	/* 1���������¼��ж� */

#define	ATIM_DIER_COMIE_Pos	5	/* COM�¼��ж�ʹ�� */
#define	ATIM_DIER_COMIE_Msk	(0x1U << ATIM_DIER_COMIE_Pos)
	/* 0����ֹCOM�¼��ж� */
	/* 1������COM�¼��ж� */

#define	ATIM_DIER_CC4IE_Pos	4	/* ��׽/�Ƚ�ͨ��4�ж�ʹ�� */
#define	ATIM_DIER_CC4IE_Msk	(0x1U << ATIM_DIER_CC4IE_Pos)
	/* 0����ֹ��׽/�Ƚ�4�ж� */
	/* 1������׽/�Ƚ�4�ж� */

#define	ATIM_DIER_CC3IE_Pos	3	/* ��׽/�Ƚ�ͨ��3�ж�ʹ�� */
#define	ATIM_DIER_CC3IE_Msk	(0x1U << ATIM_DIER_CC3IE_Pos)
	/* 0����ֹ��׽/�Ƚ�3�ж� */
	/* 1������׽/�Ƚ�3�ж� */

#define	ATIM_DIER_CC2IE_Pos	2	/* ��׽/�Ƚ�ͨ��2�ж�ʹ�� */
#define	ATIM_DIER_CC2IE_Msk	(0x1U << ATIM_DIER_CC2IE_Pos)
	/* 0����ֹ��׽/�Ƚ�2�ж� */
	/* 1������׽/�Ƚ�2�ж� */

#define	ATIM_DIER_CC1IE_Pos	1	/* ��׽/�Ƚ�ͨ��1�ж�ʹ�� */
#define	ATIM_DIER_CC1IE_Msk	(0x1U << ATIM_DIER_CC1IE_Pos)
	/* 0����ֹ��׽/�Ƚ�1�ж� */
	/* 1������׽/�Ƚ�1�ж� */

#define	ATIM_DIER_UIE_Pos	0	/* �����¼��ж�ʹ�� */
#define	ATIM_DIER_UIE_Msk	(0x1U << ATIM_DIER_UIE_Pos)
	/* 0����ֹUpdate�¼��ж� */
	/* 1������Update�¼��ж� */

#define	ATIM_ISR_CC4OF_Pos	12	/* ��׽/�Ƚ�ͨ��4��Overcapture�ж� */
#define	ATIM_ISR_CC4OF_Msk	(0x1U << ATIM_ISR_CC4OF_Pos)

#define	ATIM_ISR_CC3OF_Pos	11	/* ��׽/�Ƚ�ͨ��3��Overcapture�ж� */
#define	ATIM_ISR_CC3OF_Msk	(0x1U << ATIM_ISR_CC3OF_Pos)

#define	ATIM_ISR_CC2OF_Pos	10	/* ��׽/�Ƚ�ͨ��2��Overcapture�ж� */
#define	ATIM_ISR_CC2OF_Msk	(0x1U << ATIM_ISR_CC2OF_Pos)

#define	ATIM_ISR_CC1OF_Pos	9	/* ��׽/�Ƚ�ͨ��1��Overcapture�жϣ��˼Ĵ������ڶ�Ӧͨ������Ϊ���벶׽ģʽ���������Ч��Ӳ����λ�����д1���� */
#define	ATIM_ISR_CC1OF_Msk	(0x1U << ATIM_ISR_CC1OF_Pos)

#define	ATIM_ISR_BIF_Pos	7	/* ɲ���¼��жϱ�־��Ӳ����λ�����д1���� */
#define	ATIM_ISR_BIF_Msk	(0x1U << ATIM_ISR_BIF_Pos)

#define	ATIM_ISR_TIF_Pos	6	/* �����¼��жϱ�־��Ӳ����λ�����д1���� */
#define	ATIM_ISR_TIF_Msk	(0x1U << ATIM_ISR_TIF_Pos)

#define	ATIM_ISR_COMIF_Pos	5	/* COM�¼��жϱ�־��Ӳ����λ�����д1���� */
#define	ATIM_ISR_COMIF_Msk	(0x1U << ATIM_ISR_COMIF_Pos)

#define	ATIM_ISR_CC4IF_Pos	4	/* ��׽/�Ƚ�ͨ��4�жϱ�־���ο�CC1IF */
#define	ATIM_ISR_CC4IF_Msk	(0x1U << ATIM_ISR_CC4IF_Pos)

#define	ATIM_ISR_CC3IF_Pos	3	/* ��׽/�Ƚ�ͨ��3�жϱ�־���ο�CC1IF */
#define	ATIM_ISR_CC3IF_Msk	(0x1U << ATIM_ISR_CC3IF_Pos)

#define	ATIM_ISR_CC2IF_Pos	2	/* ��׽/�Ƚ�ͨ��2�жϱ�־���ο�CC1IF */
#define	ATIM_ISR_CC2IF_Msk	(0x1U << ATIM_ISR_CC2IF_Pos)

#define	ATIM_ISR_CC1IF_Pos	1	/* ��׽/�Ƚ�ͨ��1�жϱ�־�����CC1ͨ������Ϊ�����CC1IF�ڼ���ֵ���ڱȽ�ֵʱ��λ�����д1���㡣���CC1ͨ������Ϊ���룺������׽�¼�ʱ��λ�����д1���㣬���������ATIM_CCR1�Զ����� */
#define	ATIM_ISR_CC1IF_Msk	(0x1U << ATIM_ISR_CC1IF_Pos)

#define	ATIM_ISR_UIF_Pos	0	/* �����¼��жϱ�־��Ӳ����λ�����д1���� */
#define	ATIM_ISR_UIF_Msk	(0x1U << ATIM_ISR_UIF_Pos)

#define	ATIM_EGR_BG_Pos	7	/* ���ɲ���������λ�˼Ĵ�������ɲ���¼���Ӳ���Զ����� */
#define	ATIM_EGR_BG_Msk	(0x1U << ATIM_EGR_BG_Pos)

#define	ATIM_EGR_TIF_Pos	6	/* ��������������λ�˼Ĵ������������¼���Ӳ���Զ����� */
#define	ATIM_EGR_TIF_Msk	(0x1U << ATIM_EGR_TIF_Pos)

#define	ATIM_EGR_COMG_Pos	5	/* ���COM�¼���Ӳ����λ�����д1���� */
#define	ATIM_EGR_COMG_Msk	(0x1U << ATIM_EGR_COMG_Pos)

#define	ATIM_EGR_CC4G_Pos	4	/* ��׽/�Ƚ�ͨ��4����������ο�CC1G */
#define	ATIM_EGR_CC4G_Msk	(0x1U << ATIM_EGR_CC4G_Pos)

#define	ATIM_EGR_CC3G_Pos	3	/* ��׽/�Ƚ�ͨ��3����������ο�CC1G */
#define	ATIM_EGR_CC3G_Msk	(0x1U << ATIM_EGR_CC3G_Pos)

#define	ATIM_EGR_CC2G_Pos	2	/* ��׽/�Ƚ�ͨ��2����������ο�CC1G */
#define	ATIM_EGR_CC2G_Msk	(0x1U << ATIM_EGR_CC2G_Pos)

#define	ATIM_EGR_CC1G_Pos	1	/* ��׽/�Ƚ�ͨ��1������� */
#define	ATIM_EGR_CC1G_Msk	(0x1U << ATIM_EGR_CC1G_Pos)

#define	ATIM_EGR_UG_Pos	0	/* ���Update�¼��������λ�˼Ĵ�������Update�¼���Ӳ���Զ����� */
#define	ATIM_EGR_UG_Msk	(0x1U << ATIM_EGR_UG_Pos)

#define	ATIM_CCMR1_OC2CE_Pos	15	/* ����Ƚ�2����ʹ�ܣ��ο�OC1CE */
#define	ATIM_CCMR1_OC2CE_Msk	(0x1U << ATIM_CCMR1_OC2CE_Pos)

#define	ATIM_CCMR1_OC2M_Pos	12	/* ����Ƚ�2ģʽ���ã��ο�OC1M */
#define	ATIM_CCMR1_OC2M_Msk	(0x7U << ATIM_CCMR1_OC2M_Pos)
#define	ATIM_CCMR1_OC2M_NONE	(0x0U << ATIM_CCMR1_OC1M_Pos)	/* 000������ȽϼĴ���CCR1�ͼ�����CNT�ıȽϽ������Ӱ����� */
#define	ATIM_CCMR1_OC2M_HIGH	(0x1U << ATIM_CCMR1_OC1M_Pos)	/* 001��CCR1=CNTʱ����OC1REF�ø� */
#define	ATIM_CCMR1_OC2M_LOW	(0x2U << ATIM_CCMR1_OC1M_Pos)	/* 010��CCR1=CNTʱ����OC1REF�õ� */
#define	ATIM_CCMR1_OC2M_TOG	(0x3U << ATIM_CCMR1_OC1M_Pos)	/* 011��CCR1=CNTʱ����תOC1REF */
#define	ATIM_CCMR1_OC2M_INACTIVE	(0x4U << ATIM_CCMR1_OC1M_Pos)	/* 100��OC1REF�̶�Ϊ�ͣ�inactive�� */
#define	ATIM_CCMR1_OC2M_ACTIVE	(0x5U << ATIM_CCMR1_OC1M_Pos)	/* 101��OC1REF�̶�Ϊ�ߣ�active�� */
#define	ATIM_CCMR1_OC2M_PWM1	(0x6U << ATIM_CCMR1_OC1M_Pos)	/* 110��PWMģʽ1 �C�����ϼ���ʱ��OC1REF��CNT<CCR1ʱ�øߣ������õͣ������¼���ʱ��OC1REF��CNT>CCR1ʱ�õͣ������ø� */
#define	ATIM_CCMR1_OC2M_PWM2	(0x7U << ATIM_CCMR1_OC1M_Pos)	/* 111��PWMģʽ2 �C�����ϼ���ʱ��OC1REF��CNT<CCR1ʱ�õͣ������øߣ������¼���ʱ��OC1REF��CNT>CCR1 ʱ�øߣ������õ� */

#define	ATIM_CCMR1_OC2PE_Pos	11	/* ����Ƚ�2Ԥװ��ʹ�ܣ��ο�OC1PE */
#define	ATIM_CCMR1_OC2PE_Msk	(0x1U << ATIM_CCMR1_OC2PE_Pos)

#define	ATIM_CCMR1_OC2FE_Pos	10	/* ����Ƚ�2����ʹ�ܣ��ο�OC1FE */
#define	ATIM_CCMR1_OC2FE_Msk	(0x1U << ATIM_CCMR1_OC2FE_Pos)

#define	ATIM_CCMR1_CC2S_Pos	8	/* ��׽/�Ƚ�2ͨ��ѡ�� */
#define	ATIM_CCMR1_CC2S_Msk	(0x3U << ATIM_CCMR1_CC2S_Pos)
#define	ATIM_CCMR1_CC2S_OUT	(0x0U << ATIM_CCMR1_CC2S_Pos)	/* 00��CC2ͨ������Ϊ��� */
#define	ATIM_CCMR1_CC2S_TI2	(0x1U << ATIM_CCMR1_CC2S_Pos)	/* 01��CC2ͨ������Ϊ���룬IC2ӳ�䵽TI2 */
#define	ATIM_CCMR1_CC2S_TI1	(0x2U << ATIM_CCMR1_CC2S_Pos)	/* 10��CC2ͨ������Ϊ���룬IC2ӳ�䵽TI1 */
#define	ATIM_CCMR1_CC2S_TRC	(0x3U << ATIM_CCMR1_CC2S_Pos)	/* 11��CC2ͨ������Ϊ���룬IC2ӳ�䵽TRC */

#define	ATIM_CCMR1_OC1CE_Pos	7	/* ����Ƚ�1����ʹ�� */
#define	ATIM_CCMR1_OC1CE_Msk	(0x1U << ATIM_CCMR1_OC1CE_Pos)
	/* 0��OC1REF����ETRFӰ�� */
	/* 1����⵽ETRF�ߵ�ƽʱ���Զ�����OC1REF */

#define	ATIM_CCMR1_OC1M_Pos	4	/* ����Ƚ�1ģʽ���ã��˼Ĵ�������OC1REF�źŵ���Ϊ */
#define	ATIM_CCMR1_OC1M_Msk	(0x7U << ATIM_CCMR1_OC1M_Pos)
#define	ATIM_CCMR1_OC1M_NONE	(0x0U << ATIM_CCMR1_OC1M_Pos)	/* 000������ȽϼĴ���CCR1�ͼ�����CNT�ıȽϽ������Ӱ����� */
#define	ATIM_CCMR1_OC1M_HIGH	(0x1U << ATIM_CCMR1_OC1M_Pos)	/* 001��CCR1=CNTʱ����OC1REF�ø� */
#define	ATIM_CCMR1_OC1M_LOW	(0x2U << ATIM_CCMR1_OC1M_Pos)	/* 010��CCR1=CNTʱ����OC1REF�õ� */
#define	ATIM_CCMR1_OC1M_TOG	(0x3U << ATIM_CCMR1_OC1M_Pos)	/* 011��CCR1=CNTʱ����תOC1REF */
#define	ATIM_CCMR1_OC1M_INACTIVE	(0x4U << ATIM_CCMR1_OC1M_Pos)	/* 100��OC1REF�̶�Ϊ�ͣ�inactive�� */
#define	ATIM_CCMR1_OC1M_ACTIVE	(0x5U << ATIM_CCMR1_OC1M_Pos)	/* 101��OC1REF�̶�Ϊ�ߣ�active�� */
#define	ATIM_CCMR1_OC1M_PWM1	(0x6U << ATIM_CCMR1_OC1M_Pos)	/* 110��PWMģʽ1 �C�����ϼ���ʱ��OC1REF��CNT<CCR1ʱ�øߣ������õͣ������¼���ʱ��OC1REF��CNT>CCR1ʱ�õͣ������ø� */
#define	ATIM_CCMR1_OC1M_PWM2	(0x7U << ATIM_CCMR1_OC1M_Pos)	/* 111��PWMģʽ2 �C�����ϼ���ʱ��OC1REF��CNT<CCR1ʱ�õͣ������øߣ������¼���ʱ��OC1REF��CNT>CCR1 ʱ�øߣ������õ� */

#define	ATIM_CCMR1_OC1PE_Pos	3	/* ����Ƚ�1Ԥװ��ʹ�� */
#define	ATIM_CCMR1_OC1PE_Msk	(0x1U << ATIM_CCMR1_OC1PE_Pos)
	/* 0��CCR1 preload�Ĵ�����Ч��CCR1����ֱ��д�� */
	/* 1��CCR1 preload�Ĵ�����Ч�����CCR1�Ķ�д�������Ƿ���preload�Ĵ�������update event����ʱ�Ž�preload�Ĵ���������ת�Ƶ�shadow�Ĵ����� */

#define	ATIM_CCMR1_OC1FE_Pos	2	/* ����Ƚ�1����ʹ�� */
#define	ATIM_CCMR1_OC1FE_Msk	(0x1U << ATIM_CCMR1_OC1FE_Pos)
	/* 0���رտ���ʹ�ܣ�trigger���벻��Ӱ��Ƚ���� */
	/* 1���򿪿���ʹ�ܣ�trigger�����������OC1REF�ı�Ϊ�Ƚ�ֵƥ��ʱ������������ܵ�ǰʵ�ʱȽ������ֻ���ڴ���ģʽ�� */

#define	ATIM_CCMR1_CC1S_Pos	0	/* ��׽/�Ƚ�1ͨ��ѡ�� */
#define	ATIM_CCMR1_CC1S_Msk	(0x3U << ATIM_CCMR1_CC1S_Pos)
#define	ATIM_CCMR1_CC1S_OUT	(0x0U << ATIM_CCMR1_CC1S_Pos)	/* 00��CC1ͨ������Ϊ��� */
#define	ATIM_CCMR1_CC1S_TI1	(0x1U << ATIM_CCMR1_CC1S_Pos)	/* 01��CC1ͨ������Ϊ���룬IC1ӳ�䵽TI1 */
#define	ATIM_CCMR1_CC1S_TI2	(0x2U << ATIM_CCMR1_CC1S_Pos)	/* 10��CC1ͨ������Ϊ���룬IC1ӳ�䵽TI2 */
#define	ATIM_CCMR1_CC1S_TRC	(0x3U << ATIM_CCMR1_CC1S_Pos)	/* 11��CC1ͨ������Ϊ���룬IC1ӳ�䵽TRC */

#define	ATIM_CCMR1_IC2F_Pos	12	/* ���벶׽2�˲� */
#define	ATIM_CCMR1_IC2F_Msk	(0xfU << ATIM_CCMR1_IC2F_Pos)

#define	ATIM_CCMR1_IC2PSC_Pos	10	/* ���벶׽2Ԥ��Ƶ */
#define	ATIM_CCMR1_IC2PSC_Msk	(0x3U << ATIM_CCMR1_IC2PSC_Pos)

#define	ATIM_CCMR1_IC1F_Pos	4	/* ���벶׽1�˲� */
#define	ATIM_CCMR1_IC1F_Msk	(0xfU << ATIM_CCMR1_IC1F_Pos)
#define	ATIM_CCMR1_IC1F_FILT0	(0x0U << ATIM_CCMR1_IC1F_Pos)	/* 0000�����˲���ʹ��fDTS���� */
#define	ATIM_CCMR1_IC1F_FILT1	(0x1U << ATIM_CCMR1_IC1F_Pos)	/* 0001��fSAMPLING=fCK_INT, N=2 */
#define	ATIM_CCMR1_IC1F_FILT2	(0x2U << ATIM_CCMR1_IC1F_Pos)	/* 0010��fSAMPLING=fCK_INT, N=4 */
#define	ATIM_CCMR1_IC1F_FILT3	(0x3U << ATIM_CCMR1_IC1F_Pos)	/* 0011��fSAMPLING=fCK_INT, N=8 */
#define	ATIM_CCMR1_IC1F_FILT4	(0x4U << ATIM_CCMR1_IC1F_Pos)	/* 0100��fSAMPLING=fDTS/2, N=6 */
#define	ATIM_CCMR1_IC1F_FILT5	(0x5U << ATIM_CCMR1_IC1F_Pos)	/* 0101��fSAMPLING=fDTS/2, N=8 */
#define	ATIM_CCMR1_IC1F_FILT6	(0x6U << ATIM_CCMR1_IC1F_Pos)	/* 0110��fSAMPLING=fDTS/4, N=6 */
#define	ATIM_CCMR1_IC1F_FILT7	(0x7U << ATIM_CCMR1_IC1F_Pos)	/* 0111��fSAMPLING=fDTS/4, N=8 */
#define	ATIM_CCMR1_IC1F_FILT8	(0x8U << ATIM_CCMR1_IC1F_Pos)	/* 1000��fSAMPLING=fDTS/8, N=6 */
#define	ATIM_CCMR1_IC1F_FILT9	(0x9U << ATIM_CCMR1_IC1F_Pos)	/* 1001��fSAMPLING=fDTS/8, N=8 */
#define	ATIM_CCMR1_IC1F_FILT10	(0xaU << ATIM_CCMR1_IC1F_Pos)	/* 1010��fSAMPLING=fDTS/16, N=5 */
#define	ATIM_CCMR1_IC1F_FILT11	(0xbU << ATIM_CCMR1_IC1F_Pos)	/* 1011��fSAMPLING=fDTS/16, N=6 */
#define	ATIM_CCMR1_IC1F_FILT12	(0xcU << ATIM_CCMR1_IC1F_Pos)	/* 1100��fSAMPLING=fDTS/16, N=8 */
#define	ATIM_CCMR1_IC1F_FILT13	(0xdU << ATIM_CCMR1_IC1F_Pos)	/* 1101��fSAMPLING=fDTS/32, N=5 */
#define	ATIM_CCMR1_IC1F_FILT14	(0xeU << ATIM_CCMR1_IC1F_Pos)	/* 1110��fSAMPLING=fDTS/32, N=6 */
#define	ATIM_CCMR1_IC1F_FILT15	(0xfU << ATIM_CCMR1_IC1F_Pos)	/* 1111��fSAMPLING=fDTS/32, N=8 */

#define	ATIM_CCMR1_IC1PSC_Pos	2	/* ���벶׽1Ԥ��Ƶ */
#define	ATIM_CCMR1_IC1PSC_Msk	(0x3U << ATIM_CCMR1_IC1PSC_Pos)
#define	ATIM_CCMR1_IC1PSC_DIV1	(0x0U << ATIM_CCMR1_IC1PSC_Pos)	/* 00���޷�Ƶ */
#define	ATIM_CCMR1_IC1PSC_DIV2	(0x1U << ATIM_CCMR1_IC1PSC_Pos)	/* 01��ÿ2���¼��������һ�β�׽ */
#define	ATIM_CCMR1_IC1PSC_DIV4	(0x2U << ATIM_CCMR1_IC1PSC_Pos)	/* 10��ÿ4���¼��������һ�β�׽ */
#define	ATIM_CCMR1_IC1PSC_DIV8	(0x3U << ATIM_CCMR1_IC1PSC_Pos)	/* 11��ÿ8���¼��������һ�β�׽ */


#define	ATIM_CCMR2_OC4CE_Pos	15	/* ����Ƚ�4����ʹ�ܣ��ο�OC1CE */
#define	ATIM_CCMR2_OC4CE_Msk	(0x1U << ATIM_CCMR2_OC4CE_Pos)

#define	ATIM_CCMR2_OC4M_Pos	12
#define	ATIM_CCMR2_OC4M_Msk	(0x7U << ATIM_CCMR2_OC4M_Pos)
#define	ATIM_CCMR1_OC4M_NONE	(0x0U << ATIM_CCMR1_OC1M_Pos)	/* 000������ȽϼĴ���CCR1�ͼ�����CNT�ıȽϽ������Ӱ����� */
#define	ATIM_CCMR1_OC4M_HIGH	(0x1U << ATIM_CCMR1_OC1M_Pos)	/* 001��CCR1=CNTʱ����OC1REF�ø� */
#define	ATIM_CCMR1_OC4M_LOW	(0x2U << ATIM_CCMR1_OC1M_Pos)	/* 010��CCR1=CNTʱ����OC1REF�õ� */
#define	ATIM_CCMR1_OC4M_TOG	(0x3U << ATIM_CCMR1_OC1M_Pos)	/* 011��CCR1=CNTʱ����תOC1REF */
#define	ATIM_CCMR1_OC4M_INACTIVE	(0x4U << ATIM_CCMR1_OC1M_Pos)	/* 100��OC1REF�̶�Ϊ�ͣ�inactive�� */
#define	ATIM_CCMR1_OC4M_ACTIVE	(0x5U << ATIM_CCMR1_OC1M_Pos)	/* 101��OC1REF�̶�Ϊ�ߣ�active�� */
#define	ATIM_CCMR1_OC4M_PWM1	(0x6U << ATIM_CCMR1_OC1M_Pos)	/* 110��PWMģʽ1 �C�����ϼ���ʱ��OC1REF��CNT<CCR1ʱ�øߣ������õͣ������¼���ʱ��OC1REF��CNT>CCR1ʱ�õͣ������ø� */
#define	ATIM_CCMR1_OC4M_PWM2	(0x7U << ATIM_CCMR1_OC1M_Pos)	/* 111��PWMģʽ2 �C�����ϼ���ʱ��OC1REF��CNT<CCR1ʱ�õͣ������øߣ������¼���ʱ��OC1REF��CNT>CCR1 ʱ�øߣ������õ� */

#define	ATIM_CCMR2_OC4PE_Pos	11	/* ����Ƚ�4Ԥװ��ʹ�ܣ��ο�OC1PE */
#define	ATIM_CCMR2_OC4PE_Msk	(0x1U << ATIM_CCMR2_OC4PE_Pos)

#define	ATIM_CCMR2_OC4FE_Pos	10	/* ����Ƚ�4����ʹ�ܣ��ο�OC1FE */
#define	ATIM_CCMR2_OC4FE_Msk	(0x1U << ATIM_CCMR2_OC4FE_Pos)

#define	ATIM_CCMR2_CC4S_Pos	8	/* ��׽/�Ƚ�4ͨ��ѡ�� */
#define	ATIM_CCMR2_CC4S_Msk	(0x3U << ATIM_CCMR2_CC4S_Pos)
#define	ATIM_CCMR2_CC4S_OUT	(0x0U << ATIM_CCMR2_CC4S_Pos)	/* 00��CC4ͨ������Ϊ��� */
#define	ATIM_CCMR2_CC4S_TI4	(0x1U << ATIM_CCMR2_CC4S_Pos)	/* 01��CC4ͨ������Ϊ���룬IC4ӳ�䵽TI4 */
#define	ATIM_CCMR2_CC4S_TI3	(0x2U << ATIM_CCMR2_CC4S_Pos)	/* 10��CC4ͨ������Ϊ���룬IC4ӳ�䵽TI3 */
#define	ATIM_CCMR2_CC4S_TRC	(0x3U << ATIM_CCMR2_CC4S_Pos)	/* 11��CC4ͨ������Ϊ���룬IC4ӳ�䵽TRC */

#define	ATIM_CCMR2_OC3CE_Pos	7	/* ����Ƚ�1����ʹ�� */
#define	ATIM_CCMR2_OC3CE_Msk	(0x1U << ATIM_CCMR2_OC3CE_Pos)
	/* 0��OC1REF����ETRFӰ�� */
	/* 1����⵽ETRF�ߵ�ƽʱ���Զ�����OC1REF */

#define	ATIM_CCMR2_OC3M_Pos	4	/* ����Ƚ�3ģʽ���ã��˼Ĵ�������OC3REF�źŵ���Ϊ */
#define	ATIM_CCMR2_OC3M_Msk	(0x7U << ATIM_CCMR2_OC3M_Pos)
#define	ATIM_CCMR2_OC3M_NONE	(0x0U << ATIM_CCMR2_OC3M_Pos)	/* 000������ȽϼĴ���CCR3�ͼ�����CNT�ıȽϽ������Ӱ����� */
#define	ATIM_CCMR2_OC3M_HIGH	(0x1U << ATIM_CCMR2_OC3M_Pos)	/* 001��CCR3=CNTʱ����OC1REF�ø� */
#define	ATIM_CCMR2_OC3M_LOW	(0x2U << ATIM_CCMR2_OC3M_Pos)	/* 010��CCR3=CNTʱ����OC1REF�õ� */
#define	ATIM_CCMR2_OC3M_TOG	(0x3U << ATIM_CCMR2_OC3M_Pos)	/* 011��CCR3=CNTʱ����תOC1REF */
#define	ATIM_CCMR2_OC3M_INACTIVE	(0x4U << ATIM_CCMR2_OC3M_Pos)	/* 100��OC3REF�̶�Ϊ�ͣ�inactive�� */
#define	ATIM_CCMR2_OC3M_ACTIVE	(0x5U << ATIM_CCMR2_OC3M_Pos)	/* 101��OC3REF�̶�Ϊ�ߣ�active�� */
#define	ATIM_CCMR2_OC3M_PWM1	(0x6U << ATIM_CCMR2_OC3M_Pos)	/* 110��PWMģʽ1 �C�����ϼ���ʱ��OC3REF��CNT<CCR3ʱ�øߣ������õͣ������¼���ʱ��OC3REF��CNT>CCR3ʱ�õͣ������ø� */
#define	ATIM_CCMR2_OC3M_PWM2	(0x7U << ATIM_CCMR2_OC3M_Pos)	/* 111��PWMģʽ2 �C�����ϼ���ʱ��OC3REF��CNT<CCR3ʱ�õͣ������øߣ������¼���ʱ��OC3REF��CNT>CCR3 ʱ�øߣ������õ� */

#define	ATIM_CCMR2_OC3PE_Pos	3	/* ����Ƚ�3Ԥװ��ʹ�� */
#define	ATIM_CCMR2_OC3PE_Msk	(0x1U << ATIM_CCMR2_OC3PE_Pos)
	/* 0��CCR3 preload�Ĵ�����Ч��CCR3����ֱ��д�� */
	/* 1��CCR3 preload�Ĵ�����Ч�����CCR3�Ķ�д�������Ƿ���preload�Ĵ�������update event����ʱ�Ž�preload�Ĵ���������ת�Ƶ�shadow�Ĵ����� */

#define	ATIM_CCMR2_OC3FE_Pos	2	/* ����Ƚ�3����ʹ�� */
#define	ATIM_CCMR2_OC3FE_Msk	(0x1U << ATIM_CCMR2_OC3FE_Pos)
	/* 0���رտ���ʹ�ܣ�trigger���벻��Ӱ��Ƚ���� */
	/* 1���򿪿���ʹ�ܣ�trigger�����������OC3REF�ı�Ϊ�Ƚ�ֵƥ��ʱ������������ܵ�ǰʵ�ʱȽ���� */

#define	ATIM_CCMR2_CC3S_Pos	0	/* ��׽/�Ƚ�3ͨ��ѡ�� */
#define	ATIM_CCMR2_CC3S_Msk	(0x3U << ATIM_CCMR2_CC3S_Pos)
#define	ATIM_CCMR2_CC3S_OUT	(0x0U << ATIM_CCMR2_CC3S_Pos)	/* 00��CC3ͨ������Ϊ��� */
#define	ATIM_CCMR2_CC3S_TI3	(0x1U << ATIM_CCMR2_CC3S_Pos)	/* 01��CC3ͨ������Ϊ���룬IC1ӳ�䵽TI3 */
#define	ATIM_CCMR2_CC3S_TI4	(0x2U << ATIM_CCMR2_CC3S_Pos)	/* 10��CC3ͨ������Ϊ���룬IC1ӳ�䵽TI4 */
#define	ATIM_CCMR2_CC3S_TRC	(0x3U << ATIM_CCMR2_CC3S_Pos)	/* 11��CC3ͨ������Ϊ���룬IC1ӳ�䵽TRC */

#define	ATIM_CCMR2_IC4F_Pos	12	/* ���벶׽4�˲� */
#define	ATIM_CCMR2_IC4F_Msk	(0xfU << ATIM_CCMR2_IC4F_Pos)

#define	ATIM_CCMR2_IC4PSC_Pos	10	/* ���벶׽4Ԥ��Ƶ */
#define	ATIM_CCMR2_IC4PSC_Msk	(0x3U << ATIM_CCMR2_IC4PSC_Pos)

#define	ATIM_CCMR2_IC3F_Pos	4	/* ���벶׽3�˲� */
#define	ATIM_CCMR2_IC3F_Msk	(0xfU << ATIM_CCMR2_IC3F_Pos)
#define	ATIM_CCMR2_IC3F_FILT0	(0x0U << ATIM_CCMR2_IC3F_Pos)	/* 0000�����˲���ʹ��fDTS���� */
#define	ATIM_CCMR2_IC3F_FILT1	(0x1U << ATIM_CCMR2_IC3F_Pos)	/* 0001��fSAMPLING=fCK_INT, N=2 */
#define	ATIM_CCMR2_IC3F_FILT2	(0x2U << ATIM_CCMR2_IC3F_Pos)	/* 0010��fSAMPLING=fCK_INT, N=4 */
#define	ATIM_CCMR2_IC3F_FILT3	(0x3U << ATIM_CCMR2_IC3F_Pos)	/* 0011��fSAMPLING=fCK_INT, N=8 */
#define	ATIM_CCMR2_IC3F_FILT4	(0x4U << ATIM_CCMR2_IC3F_Pos)	/* 0100��fSAMPLING=fDTS/2, N=6 */
#define	ATIM_CCMR2_IC3F_FILT5	(0x5U << ATIM_CCMR2_IC3F_Pos)	/* 0101��fSAMPLING=fDTS/2, N=8 */
#define	ATIM_CCMR2_IC3F_FILT6	(0x6U << ATIM_CCMR2_IC3F_Pos)	/* 0110��fSAMPLING=fDTS/4, N=6 */
#define	ATIM_CCMR2_IC3F_FILT7	(0x7U << ATIM_CCMR2_IC3F_Pos)	/* 0111��fSAMPLING=fDTS/4, N=8 */
#define	ATIM_CCMR2_IC3F_FILT8	(0x8U << ATIM_CCMR2_IC3F_Pos)	/* 1000��fSAMPLING=fDTS/8, N=6 */
#define	ATIM_CCMR2_IC3F_FILT9	(0x9U << ATIM_CCMR2_IC3F_Pos)	/* 1001��fSAMPLING=fDTS/8, N=8 */
#define	ATIM_CCMR2_IC3F_FILT10	(0xaU << ATIM_CCMR2_IC3F_Pos)	/* 1010��fSAMPLING=fDTS/16, N=5 */
#define	ATIM_CCMR2_IC3F_FILT11	(0xbU << ATIM_CCMR2_IC3F_Pos)	/* 1011��fSAMPLING=fDTS/16, N=6 */
#define	ATIM_CCMR2_IC3F_FILT12	(0xcU << ATIM_CCMR2_IC3F_Pos)	/* 1100��fSAMPLING=fDTS/16, N=8 */
#define	ATIM_CCMR2_IC3F_FILT13	(0xdU << ATIM_CCMR2_IC3F_Pos)	/* 1101��fSAMPLING=fDTS/32, N=5 */
#define	ATIM_CCMR2_IC3F_FILT14	(0xeU << ATIM_CCMR2_IC3F_Pos)	/* 1110��fSAMPLING=fDTS/32, N=6 */
#define	ATIM_CCMR2_IC3F_FILT15	(0xfU << ATIM_CCMR2_IC3F_Pos)	/* 1111��fSAMPLING=fDTS/32, N=8 */

#define	ATIM_CCMR2_IC3PSC_Pos	2	/* ���벶׽3Ԥ��Ƶ */
#define	ATIM_CCMR2_IC3PSC_Msk	(0x3U << ATIM_CCMR2_IC3PSC_Pos)
#define	ATIM_CCMR2_IC3PSC_DIV1	(0x0U << ATIM_CCMR2_IC3PSC_Pos)	/* 00���޷�Ƶ */
#define	ATIM_CCMR2_IC3PSC_DIV2	(0x1U << ATIM_CCMR2_IC3PSC_Pos)	/* 01��ÿ2���¼��������һ�β�׽ */
#define	ATIM_CCMR2_IC3PSC_DIV4	(0x2U << ATIM_CCMR2_IC3PSC_Pos)	/* 10��ÿ4���¼��������һ�β�׽ */
#define	ATIM_CCMR2_IC3PSC_DIV8	(0x3U << ATIM_CCMR2_IC3PSC_Pos)	/* 11��ÿ8���¼��������һ�β�׽ */

#define	ATIM_CCER_CC4P_Pos	13	/* ��׽/�Ƚ�4������ԣ��ο�CC1P */
#define	ATIM_CCER_CC4P_Msk	(0x1U << ATIM_CCER_CC4P_Pos)
#define	ATIM_CCER_CC4P_HIGH	(0x0U << ATIM_CCER_CC4P_Pos)
#define	ATIM_CCER_CC4P_LOW	(0x1U << ATIM_CCER_CC4P_Pos)

#define	ATIM_CCER_CC4E_Pos	12	/* ��׽/�Ƚ�4���ʹ�ܣ��ο�CC1E */
#define	ATIM_CCER_CC4E_Msk	(0x1U << ATIM_CCER_CC4E_Pos)

#define	ATIM_CCER_CC3NP_Pos	11	/* ��׽/�Ƚ�3����������ԣ��ο�CC1NP */
#define	ATIM_CCER_CC3NP_Msk	(0x1U << ATIM_CCER_CC3NP_Pos)
#define	ATIM_CCER_CC3NP_HIGH	(0x0U << ATIM_CCER_CC3NP_Pos)
#define	ATIM_CCER_CC3NP_LOW	(0x1U << ATIM_CCER_CC3NP_Pos)

#define	ATIM_CCER_CC3NE_Pos	10	/* ��׽/�Ƚ�3�������ʹ�ܣ��ο�CC1NE */
#define	ATIM_CCER_CC3NE_Msk	(0x1U << ATIM_CCER_CC3NE_Pos)

#define	ATIM_CCER_CC3P_Pos	9	/* ��׽/�Ƚ�3������ԣ��ο�CC1P */
#define	ATIM_CCER_CC3P_Msk	(0x1U << ATIM_CCER_CC3P_Pos)
#define	ATIM_CCER_CC3P_HIGH	(0x0U << ATIM_CCER_CC3P_Pos)
#define	ATIM_CCER_CC3P_LOW	(0x1U << ATIM_CCER_CC3P_Pos)

#define	ATIM_CCER_CC3E_Pos	8	/* ��׽/�Ƚ�3���ʹ�ܣ��ο�CC1E */
#define	ATIM_CCER_CC3E_Msk	(0x1U << ATIM_CCER_CC3E_Pos)

#define	ATIM_CCER_CC2NP_Pos	7	/* ��׽/�Ƚ�2����������ԣ��ο�CC1NP */
#define	ATIM_CCER_CC2NP_Msk	(0x1U << ATIM_CCER_CC2NP_Pos)
#define	ATIM_CCER_CC2NP_HIGH	(0x0U << ATIM_CCER_CC2NP_Pos)
#define	ATIM_CCER_CC2NP_LOW	(0x1U << ATIM_CCER_CC2NP_Pos)

#define	ATIM_CCER_CC2NE_Pos	6	/* ��׽/�Ƚ�2�������ʹ�ܣ��ο�CC1NE */
#define	ATIM_CCER_CC2NE_Msk	(0x1U << ATIM_CCER_CC2NE_Pos)

#define	ATIM_CCER_CC2P_Pos	5	/* ��׽/�Ƚ�2������ԣ��ο�CC1P */
#define	ATIM_CCER_CC2P_Msk	(0x1U << ATIM_CCER_CC2P_Pos)
#define	ATIM_CCER_CC2P_HIGH	(0x0U << ATIM_CCER_CC2P_Pos)
#define	ATIM_CCER_CC2P_LOW	(0x1U << ATIM_CCER_CC2P_Pos)

#define	ATIM_CCER_CC2E_Pos	4	/* ��׽/�Ƚ�2���ʹ�ܣ��ο�CC1E */
#define	ATIM_CCER_CC2E_Msk	(0x1U << ATIM_CCER_CC2E_Pos)

#define	ATIM_CCER_CC1NP_Pos	3	/* ��׽/�Ƚ�1����������� */
#define	ATIM_CCER_CC1NP_Msk	(0x1U << ATIM_CCER_CC1NP_Pos)
#define	ATIM_CCER_CC1NP_HIGH	(0x0U << ATIM_CCER_CC1NP_Pos)	/* 0��OC1N�ߵ�ƽΪactive */
#define	ATIM_CCER_CC1NP_LOW	(0x1U << ATIM_CCER_CC1NP_Pos)	/* 1��OC1N�͵�ƽΪactive */

#define	ATIM_CCER_CC1NE_Pos	2	/* ��׽/�Ƚ�1�������ʹ�� */
#define	ATIM_CCER_CC1NE_Msk	(0x1U << ATIM_CCER_CC1NE_Pos)
	/* 0��OC1N��Ч��OC1N��ƽ��MOE, OSSI, OSSR, OIS1, OIS1N, CC1E�Ĵ������� */

#define	ATIM_CCER_CC1P_Pos	1	/* ��׽/�Ƚ�1������� (CC1 Polarity)
CC1ͨ������Ϊ���ʱ
0��OC1�ߵ�ƽactive
1��OC1�͵�ƽactive
CC1ͨ������Ϊ����ʱ
0����ȡ��ģʽ�C��׽��IC1�������ؽ���
1��ȡ��ģʽ�C��׽��IC1���½��ؽ��� */
#define	ATIM_CCER_CC1P_Msk	(0x1U << ATIM_CCER_CC1P_Pos)
#define	ATIM_CCER_CC1P_HIGH	(0x0U << ATIM_CCER_CC1P_Pos)
#define	ATIM_CCER_CC1P_LOW	(0x1U << ATIM_CCER_CC1P_Pos)

#define	ATIM_CCER_CC1E_Pos	0	/* ��׽/�Ƚ�1���ʹ�� (CC1 Enable)
CC1ͨ������Ϊ���ʱ
0��OC1��active
1��OC1 active
CC1ͨ������Ϊ����ʱ
0���رղ�׽����
1��ʹ�ܲ�׽���� */
#define	ATIM_CCER_CC1E_Msk	(0x1U << ATIM_CCER_CC1E_Pos)


#define	ATIM_CNT_CNT_Pos	0	/* ������ֵ */
#define	ATIM_CNT_CNT_Msk	(0xffffU << ATIM_CNT_CNT_Pos)

#define	ATIM_PSC_PSC_Pos	0	/* ������ʱ��Ԥ��Ƶֵ
fCK_CNT=fCK_PSC/(PSC[15:0]+1)
����һ��preload�Ĵ�������update�¼�����ʱ�����ݱ�����shadow�Ĵ��� */
#define	ATIM_PSC_PSC_Msk	(0xffffU << ATIM_PSC_PSC_Pos)

#define	ATIM_ARR_ARR_Pos	0	/* �������ʱ���Զ�����ֵ 
����һ��preload�Ĵ�������update�¼�����ʱ�����ݱ�����shadow�Ĵ��� */
#define	ATIM_ARR_ARR_Msk	(0xffffU << ATIM_ARR_ARR_Pos)

#define	ATIM_RCR_REP_Pos	0	/* �ظ�����ֵ  */
#define	ATIM_RCR_REP_Msk	(0xffU << ATIM_RCR_REP_Pos)

#define	ATIM_CCR1_CCR1_Pos	0	/* ��׽/�Ƚ�ͨ��1�Ĵ��� 
���ͨ��1����Ϊ�����
����һ��preload�Ĵ����������ݱ�����shadow�Ĵ�����������������Ƚϲ���OC1���
���ͨ��1����Ϊ���룺
CCR1�������һ�����벶׽�¼�����ʱ�ļ�����ֵ����ʱCCR1Ϊֻ�� */
#define	ATIM_CCR1_CCR1_Msk	(0xffffU << ATIM_CCR1_CCR1_Pos)

#define	ATIM_CCR2_CCR2_Pos	0	/* ��׽/�Ƚ�ͨ��2�Ĵ��� 
���ͨ��2����Ϊ�����
����һ��preload�Ĵ����������ݱ�����shadow�Ĵ�����������������Ƚϲ���OC2���
���ͨ��2����Ϊ���룺
CCR2�������һ�����벶׽�¼�����ʱ�ļ�����ֵ����ʱCCR2Ϊֻ�� */
#define	ATIM_CCR2_CCR2_Msk	(0xffffU << ATIM_CCR2_CCR2_Pos)

#define	ATIM_CCR3_CCR3_Pos	0	/* ��׽/�Ƚ�ͨ��3�Ĵ��� 
���ͨ��3����Ϊ�����
����һ��preload�Ĵ����������ݱ�����shadow�Ĵ�����������������Ƚϲ���OC3���
���ͨ��3����Ϊ���룺
CCR3�������һ�����벶׽�¼�����ʱ�ļ�����ֵ����ʱCCR3Ϊֻ�� */
#define	ATIM_CCR3_CCR3_Msk	(0xffffU << ATIM_CCR3_CCR3_Pos)

#define	ATIM_CCR4_CCR4_Pos	0	/* ��׽/�Ƚ�ͨ��4�Ĵ��� 
���ͨ��4����Ϊ�����
����һ��preload�Ĵ����������ݱ�����shadow�Ĵ�����������������Ƚϲ���OC4���
���ͨ��4����Ϊ���룺
CCR4�������һ�����벶׽�¼�����ʱ�ļ�����ֵ����ʱCCR4Ϊֻ�� */
#define	ATIM_CCR4_CCR4_Msk	(0xffffU << ATIM_CCR4_CCR4_Pos)

#define	ATIM_BDTR_MOE_Pos	15	/* ���ʹ������ */
#define	ATIM_BDTR_MOE_Msk	(0x1U << ATIM_BDTR_MOE_Pos)
	/* 0���ر�OC��OCN���������IO���״̬��OSSI���� */
	/* 1��ʹ��OC��OCN��� */

#define	ATIM_BDTR_AOE_Pos	14	/* �Զ����ʹ�� */
#define	ATIM_BDTR_AOE_Msk	(0x1U << ATIM_BDTR_AOE_Pos)
#define	ATIM_BDTR_AOE_SOFT	     (0x0U << ATIM_BDTR_AOE_Pos)	/* 0��MOE�����������λ */
#define	ATIM_BDTR_AOE_SOFTAEVENT (0x1U << ATIM_BDTR_AOE_Pos)	/* 1��MOE���������λ��������update�¼��Զ���λ */

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

#define	ATIM_BDTR_LOCK_Pos	8	/* �Ĵ���д�������� */
#define	ATIM_BDTR_LOCK_Msk	(0x3U << ATIM_BDTR_LOCK_Pos)
#define	ATIM_BDTR_LOCK_NONE	(0x0U << ATIM_BDTR_LOCK_Pos)	/* 00����д���� */
#define	ATIM_BDTR_LOCK_PROTECT1	(0x1U << ATIM_BDTR_LOCK_Pos)	/* 01�������ȼ�1 �C DTG, OISx, OISxN, BKE, BKP, AOE���ܸ�д */
#define	ATIM_BDTR_LOCK_PROTECT2	(0x2U << ATIM_BDTR_LOCK_Pos)	/* 10�������ȼ�2 �C�ڵȼ�1�����ϣ�CCxP, CCxNP, OSSR, OSSI���ܸ�д */
#define	ATIM_BDTR_LOCK_PROTECT3	(0x3U << ATIM_BDTR_LOCK_Pos)	/* 11�������ȼ�3 �C�ڵȼ�2�����ϣ�OCxM, OcxPE����Ӧͨ������Ϊ���ʱ���ܸ�д */

#define	ATIM_BDTR_DTG_Pos	0	/* ����ʱ����룬�������û���������������ʱ�䳤�� */
#define	ATIM_BDTR_DTG_Msk	(0xffU << ATIM_BDTR_DTG_Pos)
#define	ATIM_BDTR_DTG_N_DTG	(0x0U << ATIM_BDTR_DTG_Pos)	/* DTG[7:5]=0xx��DT=DTG[7:0] * tDTS */
#define	ATIM_BDTR_DTG_64_DTG_2T	(0x4U << ATIM_BDTR_DTG_Pos)	/* DTG[7:5]=10x��DT=(64+DTG[5:0]) * 2 * tDTS */
#define	ATIM_BDTR_DTG_32_DTG_8T	(0x6U << ATIM_BDTR_DTG_Pos)	/* DTG[7:5]=110��DT=(32+DTG[4:0]) * 8 * tDTS */
#define	ATIM_BDTR_DTG_32_DTG_16T	(0x7U << ATIM_BDTR_DTG_Pos)	/* DTG[7:5]=111��DT=(32+DTG[4:0]) * 16 * tDTS */

#define	ATIM_DCR_DBL_Pos	8	/* DMA Burst���� */
#define	ATIM_DCR_DBL_Msk	(0x1fU << ATIM_DCR_DBL_Pos)

#define	ATIM_DCR_DBA_Pos	0	/* DMA����ַ������ָ��Ĵ�����ƫ�Ƶ�ַ */
#define	ATIM_DCR_DBA_Msk	(0x1fU << ATIM_DCR_DBA_Pos)
#define	ATIM_DCR_DBA_ATIM_CR1	(0x0U << ATIM_DCR_DBA_Pos)	/* 00000��ATIM_CR1 */
#define	ATIM_DCR_DBA_ATIM_CR2	(0x1U << ATIM_DCR_DBA_Pos)	/* 00001��ATIM_CR2 */
#define	ATIM_DCR_DBA_ATIM_SMCR	(0x2U << ATIM_DCR_DBA_Pos)	/* 00010��ATIM_SMCR */

#define	ATIM_DMAR_DMAR_Pos	0	/* DMA burst���ʼĴ���
��ʹ��DMA burst����ʱ����DMAͨ�������ַ����ΪATIM_DMAR��ATIM�����DBL��ֵ�������DMA���� */
#define	ATIM_DMAR_DMAR_Msk	(0xffffffffU << ATIM_DMAR_DMAR_Pos)

#define	ATIM_BKCR_BRK2GATE_Pos	9	/* ATIM_BRK2���������ſ��ź� */
#define	ATIM_BKCR_BRK2GATE_Msk	(0x1U << ATIM_BKCR_BRK2GATE_Pos)
#define	ATIM_BKCR_BRK2GATE_ZERO	(0x0U << ATIM_BKCR_BRK2GATE_Pos)	/* 0����ATIM_BRK2�������ſس�0 */
#define	ATIM_BKCR_BRK2GATE_NO_CR	(0x1U << ATIM_BKCR_BRK2GATE_Pos)	/* 1�����ſ� */

#define	ATIM_BKCR_BRK1GATE_Pos	8	/* ATIM_BRK1���������ſ��ź� */
#define	ATIM_BKCR_BRK1GATE_Msk	(0x1U << ATIM_BKCR_BRK1GATE_Pos)
#define	ATIM_BKCR_BRK1GATE_ZERO	(0x0U << ATIM_BKCR_BRK1GATE_Pos)	/* 0����ATIM_BRK1�������ſس�0 */
#define	ATIM_BKCR_BRK1GATE_NO_CR	(0x1U << ATIM_BKCR_BRK1GATE_Pos)	/* 1�����ſ� */

#define	ATIM_BKCR_BRKF_Pos	4	/* ɲ���źŵ��˲�ʱ�Ӻͳ���ѡ��  */
#define	ATIM_BKCR_BRKF_Msk	(0xfU << ATIM_BKCR_BRKF_Pos)
#define	ATIM_BKCR_BRKF_FILT0	(0x0U << ATIM_BKCR_BRKF_Pos)	/* 0000�����˲� */
#define	ATIM_BKCR_BRKF_FILT1	(0x1U << ATIM_BKCR_BRKF_Pos)	/* 0001��fSAMPLING=fCK_INT, N=2 */
#define	ATIM_BKCR_BRKF_FILT2	(0x2U << ATIM_BKCR_BRKF_Pos)	/* 0010��fSAMPLING=fCK_INT, N=4 */
#define	ATIM_BKCR_BRKF_FILT3	(0x3U << ATIM_BKCR_BRKF_Pos)	/* 0011��fSAMPLING=fCK_INT, N=8 */
#define	ATIM_BKCR_BRKF_FILT4	(0x4U << ATIM_BKCR_BRKF_Pos)	/* 0100��fSAMPLING=fDTS/2, N=6 */
#define	ATIM_BKCR_BRKF_FILT5	(0x5U << ATIM_BKCR_BRKF_Pos)	/* 0101��fSAMPLING=fDTS/2, N=8 */
#define	ATIM_BKCR_BRKF_FILT6	(0x6U << ATIM_BKCR_BRKF_Pos)	/* 0110��fSAMPLING=fDTS/4, N=6 */
#define	ATIM_BKCR_BRKF_FILT7	(0x7U << ATIM_BKCR_BRKF_Pos)	/* 0111��fSAMPLING=fDTS/4, N=8 */
#define	ATIM_BKCR_BRKF_FILT8	(0x8U << ATIM_BKCR_BRKF_Pos)	/* 1000��fSAMPLING=fDTS/8, N=6 */
#define	ATIM_BKCR_BRKF_FILT9	(0x9U << ATIM_BKCR_BRKF_Pos)	/* 1001��fSAMPLING=fDTS/8, N=8 */
#define	ATIM_BKCR_BRKF_FILT10	(0xaU << ATIM_BKCR_BRKF_Pos)	/* 1010��fSAMPLING=fDTS/16, N=5 */
#define	ATIM_BKCR_BRKF_FILT11	(0xbU << ATIM_BKCR_BRKF_Pos)	/* 1011��fSAMPLING=fDTS/16, N=6 */
#define	ATIM_BKCR_BRKF_FILT12	(0xcU << ATIM_BKCR_BRKF_Pos)	/* 1100��fSAMPLING=fDTS/16, N=8 */
#define	ATIM_BKCR_BRKF_FILT13	(0xdU << ATIM_BKCR_BRKF_Pos)	/* 1101��fSAMPLING=fDTS/32, N=5 */
#define	ATIM_BKCR_BRKF_FILT14	(0xeU << ATIM_BKCR_BRKF_Pos)	/* 1110��fSAMPLING=fDTS/32, N=6 */
#define	ATIM_BKCR_BRKF_FILT15	(0xfU << ATIM_BKCR_BRKF_Pos)	/* 1111��fSAMPLING=fDTS/32, N=8 */

#define	ATIM_BKCR_BRKCOMB_Pos	3	/* ɲ����Ͽ��� */
#define	ATIM_BKCR_BRKCOMB_Msk	(0x1U << ATIM_BKCR_BRKCOMB_Pos)
#define	ATIM_BKCR_BRKCOMB_OR	(0x0U << ATIM_BKCR_BRKCOMB_Pos)	/* 0����·ɲ���ź���� */
#define	ATIM_BKCR_BRKCOMB_AND	(0x1U << ATIM_BKCR_BRKCOMB_Pos)	/* 1����·ɲ���ź����� */

#define	ATIM_BKCR_HFDET_BRKEN_Pos	2	/* XTHFͣ����ɲ���ź�ʹ�� */
#define	ATIM_BKCR_HFDET_BRKEN_Msk	(0x1U << ATIM_BKCR_HFDET_BRKEN_Pos)
	/* 0����ֹHFDETɲ���ź� */
	/* 1��ʹ��HFDETɲ���ź� */

#define	ATIM_BKCR_SVD_BRKEN_Pos	1	/* SVDɲ���ź�ʹ�� */
#define	ATIM_BKCR_SVD_BRKEN_Msk	(0x1U << ATIM_BKCR_SVD_BRKEN_Pos)
	/* 0����ֹSVDɲ���ź� */
	/* 1��ʹ��SVDɲ���ź� */

#define	ATIM_BKCR_COMP_BRKEN_Pos	0	/* �Ƚ������ɲ���ź�ʹ�� */
#define	ATIM_BKCR_COMP_BRKEN_Msk	(0x1U << ATIM_BKCR_COMP_BRKEN_Pos)
	/* 0����ֹ�Ƚ���ɲ���ź� */
	/* 1��ʹ�ܱȽ���ɲ���ź� */
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void ATIM_Deinit(void);

/* Dead time�������˲�ʱ��Ƶ�ʷ�Ƶ�Ĵ��� ��غ��� */
extern void ATIM_CR1_CKD_Set(uint32_t SetValue);
extern uint32_t ATIM_CR1_CKD_Get(void);

/* ARRԤװ��ʹ��  ��غ��� */
extern void ATIM_CR1_ARPE_Setable(FunState NewState);
extern FunState ATIM_CR1_ARPE_Getable(void);

/* ����������ģʽѡ�� ��غ��� */
extern void ATIM_CR1_CMS_Set(uint32_t SetValue);
extern uint32_t ATIM_CR1_CMS_Get(void);

/* ��������Ĵ��� ��غ��� */
extern void ATIM_CR1_DIR_Set(uint32_t SetValue);
extern uint32_t ATIM_CR1_DIR_Get(void);

/* ���������ģʽ ��غ��� */
extern void ATIM_CR1_OPM_Setable(FunState NewState);
extern FunState ATIM_CR1_OPM_Getable(void);

/* ��������ѡ�� ��غ��� */
extern void ATIM_CR1_URS_Setable(FunState NewState);
extern FunState ATIM_CR1_URS_Getable(void);

/* ��ֹupdate ��غ��� */
extern void ATIM_CR1_UDIS_Setable(FunState NewState);
extern FunState ATIM_CR1_UDIS_Getable(void);

/* ������ʹ�� ��غ��� */
extern void ATIM_CR1_CEN_Setable(FunState NewState);
extern FunState ATIM_CR1_CEN_Getable(void);

/* �ο�OIS1 ��غ��� */
extern void ATIM_CR2_OIS4_Setable(FunState NewState);
extern FunState ATIM_CR2_OIS4_Getable(void);

/* �ο�OIS1N ��غ��� */
extern void ATIM_CR2_OIS3N_Setable(FunState NewState);
extern FunState ATIM_CR2_OIS3N_Getable(void);

/* �ο�OIS1 ��غ��� */
extern void ATIM_CR2_OIS3_Setable(FunState NewState);
extern FunState ATIM_CR2_OIS3_Getable(void);

/* �ο�OIS1N ��غ��� */
extern void ATIM_CR2_OIS2N_Setable(FunState NewState);
extern FunState ATIM_CR2_OIS2N_Getable(void);

/* �ο�OIS1 ��غ��� */
extern void ATIM_CR2_OIS2_Setable(FunState NewState);
extern FunState ATIM_CR2_OIS2_Getable(void);

/* OC1N�����IDLE״̬ ��غ��� */
extern void ATIM_CR2_OIS1N_Setable(FunState NewState);
extern FunState ATIM_CR2_OIS1N_Getable(void);

/* OC1�����IDLE״̬ ��غ��� */
extern void ATIM_CR2_OIS1_Setable(FunState NewState);
extern FunState ATIM_CR2_OIS1_Getable(void);

/* ATIM����TI1ѡ�� ��غ��� */
extern void ATIM_CR2_TI1S_Set(uint32_t SetValue);
extern uint32_t ATIM_CR2_TI1S_Get(void);

/* ����ģʽѡ��������������ģʽ����ӻ����͵�ͬ�������źţ�TRGO��Դ ��غ��� */
extern void ATIM_CR2_MMS_Set(uint32_t SetValue);
extern uint32_t ATIM_CR2_MMS_Get(void);

/* ��׽/�Ƚ� DMAѡ�� ��غ��� */
extern void ATIM_CR2_CCDS_Set(uint32_t SetValue);
extern uint32_t ATIM_CR2_CCDS_Get(void);

/* ��׽/�ȽϿ��ƼĴ�������ѡ�� ��غ��� */
extern void ATIM_CR2_CCUS_Set(uint32_t SetValue);
extern uint32_t ATIM_CR2_CCUS_Get(void);
extern void ATIM_CR2_CCPC_Setable(FunState NewState);
extern FunState ATIM_CR2_CCPC_Getable(void);

/* �ⲿ�����źż������� ��غ��� */
extern void ATIM_SMCR_ETP_Set(uint32_t SetValue);
extern uint32_t ATIM_SMCR_ETP_Get(void);

/* �ⲿʱ��ʹ�� ��غ��� */
extern void ATIM_SMCR_ECE_Setable(FunState NewState);
extern FunState ATIM_SMCR_ECE_Getable(void);

/* �ⲿ�����ź�Ԥ��Ƶ�Ĵ���,�ⲿ�����ź�ETRP��Ƶ�����ֻ����ATIM����ʱ�ӵ�1/4���������ź�Ƶ�ʽϸ�ʱ������ʹ��Ԥ��Ƶ ��غ��� */
extern void ATIM_SMCR_ETPS_Set(uint32_t SetValue);
extern uint32_t ATIM_SMCR_ETPS_Get(void);

/* �ⲿ�����ź��˲�ʱ�Ӻͳ���ѡ�� ��غ��� */
extern void ATIM_SMCR_ETF_Set(uint32_t SetValue);
extern uint32_t ATIM_SMCR_ETF_Get(void);

/* �����ӻ�ģʽѡ ��غ��� */
extern void ATIM_SMCR_MSM_Set(uint32_t SetValue);
extern uint32_t ATIM_SMCR_MSM_Get(void);

/* ����ѡ������ѡ��ͬ���������Ĵ���Դ ��غ��� */
extern void ATIM_SMCR_TS_Set(uint32_t SetValue);
extern uint32_t ATIM_SMCR_TS_Get(void);

/* �ӻ�ģʽѡ�� ��غ��� */
extern void ATIM_SMCR_SMS_Set(uint32_t SetValue);
extern uint32_t ATIM_SMCR_SMS_Get(void);

/* ��׽�Ƚ�ͨ��4��DMAģʽ���� ��غ��� */
extern void ATIM_DIER_CC4BURSTEN_Set(uint32_t SetValue);
extern uint32_t ATIM_DIER_CC4BURSTEN_Get(void);

/* ��׽�Ƚ�ͨ��3��DMAģʽ���� ��غ��� */
extern void ATIM_DIER_CC3BURSTEN_Set(uint32_t SetValue);
extern uint32_t ATIM_DIER_CC3BURSTEN_Get(void);

/* ��׽�Ƚ�ͨ��2��DMAģʽ���� ��غ��� */
extern void ATIM_DIER_CC2BURSTEN_Set(uint32_t SetValue);
extern uint32_t ATIM_DIER_CC2BURSTEN_Get(void);

/* ��׽�Ƚ�ͨ��1��DMAģʽ���� ��غ��� */
extern void ATIM_DIER_CC1BURSTEN_Set(uint32_t SetValue);
extern uint32_t ATIM_DIER_CC1BURSTEN_Get(void);

/* �ⲿ����DMA����ʹ�� ��غ��� */
extern void ATIM_DIER_TDE_Setable(FunState NewState);
extern FunState ATIM_DIER_TDE_Getable(void);

/* COM�¼�DMA����ʹ�� ��غ��� */
extern void ATIM_DIER_COMDE_Setable(FunState NewState);
extern FunState ATIM_DIER_COMDE_Getable(void);

/* ��׽�Ƚ�ͨ��4��DMA����ʹ�� ��غ��� */
extern void ATIM_DIER_CC4DE_Setable(FunState NewState);
extern FunState ATIM_DIER_CC4DE_Getable(void);

/* ��׽�Ƚ�ͨ��3��DMA����ʹ�� ��غ��� */
extern void ATIM_DIER_CC3DE_Setable(FunState NewState);
extern FunState ATIM_DIER_CC3DE_Getable(void);

/* ��׽�Ƚ�ͨ��2��DMA����ʹ�� ��غ��� */
extern void ATIM_DIER_CC2DE_Setable(FunState NewState);
extern FunState ATIM_DIER_CC2DE_Getable(void);

/* ��׽�Ƚ�ͨ��1��DMA����ʹ�� ��غ��� */
extern void ATIM_DIER_CC1DE_Setable(FunState NewState);
extern FunState ATIM_DIER_CC1DE_Getable(void);

/* �����¼�DMA����ʹ��  ��غ��� */
extern void ATIM_DIER_UDE_Setable(FunState NewState);
extern FunState ATIM_DIER_UDE_Getable(void);

/* ɲ���¼��ж�ʹ�� ��غ��� */
extern void ATIM_DIER_BIE_Setable(FunState NewState);
extern FunState ATIM_DIER_BIE_Getable(void);

/* �����¼��ж�ʹ�� ��غ��� */
extern void ATIM_DIER_TIE_Setable(FunState NewState);
extern FunState ATIM_DIER_TIE_Getable(void);

/* COM�¼��ж�ʹ�� ��غ��� */
extern void ATIM_DIER_COMIE_Setable(FunState NewState);
extern FunState ATIM_DIER_COMIE_Getable(void);

/* ��׽/�Ƚ�ͨ��4�ж�ʹ�� ��غ��� */
extern void ATIM_DIER_CC4IE_Setable(FunState NewState);
extern FunState ATIM_DIER_CC4IE_Getable(void);

/* ��׽/�Ƚ�ͨ��3�ж�ʹ�� ��غ��� */
extern void ATIM_DIER_CC3IE_Setable(FunState NewState);
extern FunState ATIM_DIER_CC3IE_Getable(void);

/* ��׽/�Ƚ�ͨ��2�ж�ʹ�� ��غ��� */
extern void ATIM_DIER_CC2IE_Setable(FunState NewState);
extern FunState ATIM_DIER_CC2IE_Getable(void);

/* ��׽/�Ƚ�ͨ��1�ж�ʹ�� ��غ��� */
extern void ATIM_DIER_CC1IE_Setable(FunState NewState);
extern FunState ATIM_DIER_CC1IE_Getable(void);

/* �����¼��ж�ʹ�� ��غ��� */
extern void ATIM_DIER_UIE_Setable(FunState NewState);
extern FunState ATIM_DIER_UIE_Getable(void);

/* ��׽/�Ƚ�ͨ��4��Overcapture�ж� ��غ��� */
extern void ATIM_ISR_CC4OF_Clr(void);
extern FlagStatus ATIM_ISR_CC4OF_Chk(void);

/* ��׽/�Ƚ�ͨ��3��Overcapture�ж� ��غ��� */
extern void ATIM_ISR_CC3OF_Clr(void);
extern FlagStatus ATIM_ISR_CC3OF_Chk(void);

/* ��׽/�Ƚ�ͨ��2��Overcapture�ж� ��غ��� */
extern void ATIM_ISR_CC2OF_Clr(void);
extern FlagStatus ATIM_ISR_CC2OF_Chk(void);

/* ��׽/�Ƚ�ͨ��1��Overcapture�жϣ��˼Ĵ������ڶ�Ӧͨ������Ϊ���벶׽ģʽ���������Ч��Ӳ����λ�����д1���� ��غ��� */
extern void ATIM_ISR_CC1OF_Clr(void);
extern FlagStatus ATIM_ISR_CC1OF_Chk(void);

/* ɲ���¼��жϱ�־��Ӳ����λ�����д1���� ��غ��� */
extern void ATIM_ISR_BIF_Clr(void);
extern FlagStatus ATIM_ISR_BIF_Chk(void);

/* �����¼��жϱ�־��Ӳ����λ�����д1���� ��غ��� */
extern void ATIM_ISR_TIF_Clr(void);
extern FlagStatus ATIM_ISR_TIF_Chk(void);

/* COM�¼��жϱ�־��Ӳ����λ�����д1���� ��غ��� */
extern void ATIM_ISR_COMIF_Clr(void);
extern FlagStatus ATIM_ISR_COMIF_Chk(void);

/* ��׽/�Ƚ�ͨ��4�жϱ�־���ο�CC1IF ��غ��� */
extern void ATIM_ISR_CC4IF_Clr(void);
extern FlagStatus ATIM_ISR_CC4IF_Chk(void);

/* ��׽/�Ƚ�ͨ��3�жϱ�־���ο�CC1IF ��غ��� */
extern void ATIM_ISR_CC3IF_Clr(void);
extern FlagStatus ATIM_ISR_CC3IF_Chk(void);

/* ��׽/�Ƚ�ͨ��2�жϱ�־���ο�CC1IF ��غ��� */
extern void ATIM_ISR_CC2IF_Clr(void);
extern FlagStatus ATIM_ISR_CC2IF_Chk(void);

/* ��׽/�Ƚ�ͨ��1�жϱ�־�����CC1ͨ������Ϊ�����CC1IF�ڼ���ֵ���ڱȽ�ֵʱ��λ�����д1���㡣
���CC1ͨ������Ϊ���룺������׽�¼�ʱ��λ�����д1���㣬���������ATIM_CCR1�Զ����� ��غ��� */
extern void ATIM_ISR_CC1IF_Clr(void);
extern FlagStatus ATIM_ISR_CC1IF_Chk(void);

/* �����¼��жϱ�־��Ӳ����λ�����д1���� ��غ��� */
extern void ATIM_ISR_UIF_Clr(void);
extern FlagStatus ATIM_ISR_UIF_Chk(void);

/* ���ɲ���������λ�˼Ĵ�������ɲ���¼���Ӳ���Զ����� ��غ��� */
extern void ATIM_EGR_BG_Setable(FunState NewState);

/* ��������������λ�˼Ĵ������������¼���Ӳ���Զ����� ��غ��� */
extern void ATIM_EGR_TIF_Setable(FunState NewState);

/* ���COM�¼���Ӳ����λ�����д1���� ��غ��� */
extern void ATIM_EGR_COMG_Setable(FunState NewState);

/* ��׽/�Ƚ�ͨ��4����������ο�CC1G ��غ��� */
extern void ATIM_EGR_CC4G_Setable(FunState NewState);

/* ��׽/�Ƚ�ͨ��3����������ο�CC1G ��غ��� */
extern void ATIM_EGR_CC3G_Setable(FunState NewState);

/* ��׽/�Ƚ�ͨ��2����������ο�CC1G ��غ��� */
extern void ATIM_EGR_CC2G_Setable(FunState NewState);

/* ��׽/�Ƚ�ͨ��1������� ��غ��� */
extern void ATIM_EGR_CC1G_Setable(FunState NewState);

/* ���Update�¼��������λ�˼Ĵ�������Update�¼���Ӳ���Զ����� ��غ��� */
extern void ATIM_EGR_UG_Setable(FunState NewState);

/* ����Ƚ�2����ʹ�ܣ��ο�OC1CE ��غ��� */
extern void ATIM_CCMR1_OC2CE_Setable(FunState NewState);
extern FunState ATIM_CCMR1_OC2CE_Getable(void);

/* ����Ƚ�2ģʽ���ã��ο�OC1M ��غ��� */
extern void ATIM_CCMR1_OC2M_Set(uint32_t SetValue);
extern uint32_t ATIM_CCMR1_OC2M_Get(void);

/* ����Ƚ�2Ԥװ��ʹ�ܣ��ο�OC1PE ��غ��� */
extern void ATIM_CCMR1_OC2PE_Setable(FunState NewState);
extern FunState ATIM_CCMR1_OC2PE_Getable(void);

/* ����Ƚ�2����ʹ�ܣ��ο�OC1FE ��غ��� */
extern void ATIM_CCMR1_OC2FE_Setable(FunState NewState);
extern FunState ATIM_CCMR1_OC2FE_Getable(void);

/* ��׽/�Ƚ�2ͨ��ѡ�� ��غ��� */
extern void ATIM_CCMR1_CC2S_Set(uint32_t SetValue);
extern uint32_t ATIM_CCMR1_CC2S_Get(void);

/* ����Ƚ�1����ʹ�� ��غ��� */
extern void ATIM_CCMR1_OC1CE_Setable(FunState NewState);
extern FunState ATIM_CCMR1_OC1CE_Getable(void);

/* ����Ƚ�1ģʽ���ã��˼Ĵ�������OC1REF�źŵ���Ϊ ��غ��� */
extern void ATIM_CCMR1_OC1M_Set(uint32_t SetValue);
extern uint32_t ATIM_CCMR1_OC1M_Get(void);

/* ����Ƚ�1Ԥװ��ʹ�� ��غ��� */
extern void ATIM_CCMR1_OC1PE_Setable(FunState NewState);
extern FunState ATIM_CCMR1_OC1PE_Getable(void);

/* ����Ƚ�1����ʹ�� ��غ��� */
extern void ATIM_CCMR1_OC1FE_Setable(FunState NewState);
extern FunState ATIM_CCMR1_OC1FE_Getable(void);

/* ��׽/�Ƚ�1ͨ��ѡ�� ��غ��� */
extern void ATIM_CCMR1_CC1S_Set(uint32_t SetValue);
extern uint32_t ATIM_CCMR1_CC1S_Get(void);

/* ���벶׽2�˲� ��غ��� */
extern void ATIM_CCMR1_IC2F_Set(uint32_t SetValue);
extern uint32_t ATIM_CCMR1_IC2F_Get(void);

/* ���벶׽2Ԥ��Ƶ ��غ��� */
extern void ATIM_CCMR1_IC2PSC_Set(uint32_t SetValue);
extern uint32_t ATIM_CCMR1_IC2PSC_Get(void);

/* ���벶׽1�˲� ��غ��� */
extern void ATIM_CCMR1_IC1F_Set(uint32_t SetValue);
extern uint32_t ATIM_CCMR1_IC1F_Get(void);

/* ���벶׽1Ԥ��Ƶ ��غ��� */
extern void ATIM_CCMR1_IC1PSC_Set(uint32_t SetValue);
extern uint32_t ATIM_CCMR1_IC1PSC_Get(void);

/* ����Ƚ�4����ʹ�ܣ��ο�OC1CE ��غ��� */
extern void ATIM_CCMR2_OC4CE_Setable(FunState NewState);
extern FunState ATIM_CCMR2_OC4CE_Getable(void);
extern void ATIM_CCMR2_OC4M_Set(uint32_t SetValue);
extern uint32_t ATIM_CCMR2_OC4M_Get(void);

/* ����Ƚ�4Ԥװ��ʹ�ܣ��ο�OC1PE ��غ��� */
extern void ATIM_CCMR2_OC4PE_Setable(FunState NewState);
extern FunState ATIM_CCMR2_OC4PE_Getable(void);

/* ����Ƚ�4����ʹ�ܣ��ο�OC1FE ��غ��� */
extern void ATIM_CCMR2_OC4FE_Setable(FunState NewState);
extern FunState ATIM_CCMR2_OC4FE_Getable(void);

/* ��׽/�Ƚ�4ͨ��ѡ�� ��غ��� */
extern void ATIM_CCMR2_CC4S_Set(uint32_t SetValue);
extern uint32_t ATIM_CCMR2_CC4S_Get(void);

/* ����Ƚ�1����ʹ�� ��غ��� */
extern void ATIM_CCMR2_OC3CE_Setable(FunState NewState);
extern FunState ATIM_CCMR2_OC3CE_Getable(void);

/* ����Ƚ�3ģʽ���ã��˼Ĵ�������OC3REF�źŵ���Ϊ ��غ��� */
extern void ATIM_CCMR2_OC3M_Set(uint32_t SetValue);
extern uint32_t ATIM_CCMR2_OC3M_Get(void);

/* ����Ƚ�3Ԥװ��ʹ�� ��غ��� */
extern void ATIM_CCMR2_OC3PE_Setable(FunState NewState);
extern FunState ATIM_CCMR2_OC3PE_Getable(void);

/* ����Ƚ�3����ʹ�� ��غ��� */
extern void ATIM_CCMR2_OC3FE_Setable(FunState NewState);
extern FunState ATIM_CCMR2_OC3FE_Getable(void);

/* ��׽/�Ƚ�3ͨ��ѡ�� ��غ��� */
extern void ATIM_CCMR2_CC3S_Set(uint32_t SetValue);
extern uint32_t ATIM_CCMR2_CC3S_Get(void);

/* ���벶׽4�˲� ��غ��� */
extern void ATIM_CCMR2_IC4F_Set(uint32_t SetValue);
extern uint32_t ATIM_CCMR2_IC4F_Get(void);

/* ���벶׽4Ԥ��Ƶ ��غ��� */
extern void ATIM_CCMR2_IC4PSC_Set(uint32_t SetValue);
extern uint32_t ATIM_CCMR2_IC4PSC_Get(void);

/* ���벶׽3�˲� ��غ��� */
extern void ATIM_CCMR2_IC3F_Set(uint32_t SetValue);
extern uint32_t ATIM_CCMR2_IC3F_Get(void);

/* ���벶׽3Ԥ��Ƶ ��غ��� */
extern void ATIM_CCMR2_IC3PSC_Set(uint32_t SetValue);
extern uint32_t ATIM_CCMR2_IC3PSC_Get(void);

/* ��׽/�Ƚ�4������ԣ��ο�CC1P ��غ��� */
extern void ATIM_CCER_CC4P_Set(uint32_t SetValue);
extern uint32_t ATIM_CCER_CC4P_Get(void);

/* ��׽/�Ƚ�4���ʹ�ܣ��ο�CC1E ��غ��� */
extern void ATIM_CCER_CC4E_Setable(FunState NewState);
extern FunState ATIM_CCER_CC4E_Getable(void);

/* ��׽/�Ƚ�3����������ԣ��ο�CC1NP ��غ��� */
extern void ATIM_CCER_CC3NP_Set(uint32_t SetValue);
extern uint32_t ATIM_CCER_CC3NP_Get(void);

/* ��׽/�Ƚ�3�������ʹ�ܣ��ο�CC1NE ��غ��� */
extern void ATIM_CCER_CC3NE_Setable(FunState NewState);
extern FunState ATIM_CCER_CC3NE_Getable(void);

/* ��׽/�Ƚ�3������ԣ��ο�CC1P ��غ��� */
extern void ATIM_CCER_CC3P_Set(uint32_t SetValue);
extern uint32_t ATIM_CCER_CC3P_Get(void);

/* ��׽/�Ƚ�3���ʹ�ܣ��ο�CC1E ��غ��� */
extern void ATIM_CCER_CC3E_Setable(FunState NewState);
extern FunState ATIM_CCER_CC3E_Getable(void);

/* ��׽/�Ƚ�2����������ԣ��ο�CC1NP ��غ��� */
extern void ATIM_CCER_CC2NP_Set(uint32_t SetValue);
extern uint32_t ATIM_CCER_CC2NP_Get(void);

/* ��׽/�Ƚ�2�������ʹ�ܣ��ο�CC1NE ��غ��� */
extern void ATIM_CCER_CC2NE_Setable(FunState NewState);
extern FunState ATIM_CCER_CC2NE_Getable(void);

/* ��׽/�Ƚ�2������ԣ��ο�CC1P ��غ��� */
extern void ATIM_CCER_CC2P_Set(uint32_t SetValue);
extern uint32_t ATIM_CCER_CC2P_Get(void);

/* ��׽/�Ƚ�2���ʹ�ܣ��ο�CC1E ��غ��� */
extern void ATIM_CCER_CC2E_Setable(FunState NewState);
extern FunState ATIM_CCER_CC2E_Getable(void);

/* ��׽/�Ƚ�1����������� ��غ��� */
extern void ATIM_CCER_CC1NP_Set(uint32_t SetValue);
extern uint32_t ATIM_CCER_CC1NP_Get(void);

/* ��׽/�Ƚ�1�������ʹ�� ��غ��� */
extern void ATIM_CCER_CC1NE_Setable(FunState NewState);
extern FunState ATIM_CCER_CC1NE_Getable(void);

/* ��׽/�Ƚ�1������� (CC1 Polarity)
CC1ͨ������Ϊ���ʱ
0��OC1�ߵ�ƽactive
1��OC1�͵�ƽactive
CC1ͨ������Ϊ����ʱ
0����ȡ��ģʽ�C��׽��IC1�������ؽ���
1��ȡ��ģʽ�C��׽��IC1���½��ؽ��� ��غ��� */
extern void ATIM_CCER_CC1P_Set(uint32_t SetValue);
extern uint32_t ATIM_CCER_CC1P_Get(void);

/* ��׽/�Ƚ�1���ʹ�� (CC1 Enable)
CC1ͨ������Ϊ���ʱ
0��OC1��active
1��OC1 active
CC1ͨ������Ϊ����ʱ
0���رղ�׽����
1��ʹ�ܲ�׽���� ��غ��� */
extern void ATIM_CCER_CC1E_Setable(FunState NewState);
extern FunState ATIM_CCER_CC1E_Getable(void);

/* ������ֵ ��غ��� */
extern void ATIM_CNT_Write(uint32_t SetValue);
extern uint32_t ATIM_CNT_Read(void);

/* ������ʱ��Ԥ��Ƶֵ
fCK_CNT=fCK_PSC/(PSC[15:0]+1)
����һ��preload�Ĵ�������update�¼�����ʱ�����ݱ�����shadow�Ĵ��� ��غ��� */
extern void ATIM_PSC_Write(uint32_t SetValue);
extern uint32_t ATIM_PSC_Read(void);

/* �������ʱ���Զ�����ֵ 
����һ��preload�Ĵ�������update�¼�����ʱ�����ݱ�����shadow�Ĵ��� ��غ��� */
extern void ATIM_ARR_Write(uint32_t SetValue);
extern uint32_t ATIM_ARR_Read(void);

/* �ظ�����ֵ  ��غ��� */
extern void ATIM_RCR_Write(uint32_t SetValue);
extern uint32_t ATIM_RCR_Read(void);

/* ��׽/�Ƚ�ͨ��1�Ĵ��� 
���ͨ��1����Ϊ�����
����һ��preload�Ĵ����������ݱ�����shadow�Ĵ�����������������Ƚϲ���OC1���
���ͨ��1����Ϊ���룺
CCR1�������һ�����벶׽�¼�����ʱ�ļ�����ֵ����ʱCCR1Ϊֻ�� ��غ��� */
extern void ATIM_CCR1_Write(uint32_t SetValue);
extern uint32_t ATIM_CCR1_Read(void);

/* ��׽/�Ƚ�ͨ��2�Ĵ��� 
���ͨ��2����Ϊ�����
����һ��preload�Ĵ����������ݱ�����shadow�Ĵ�����������������Ƚϲ���OC2���
���ͨ��2����Ϊ���룺
CCR2�������һ�����벶׽�¼�����ʱ�ļ�����ֵ����ʱCCR2Ϊֻ�� ��غ��� */
extern void ATIM_CCR2_Write(uint32_t SetValue);
extern uint32_t ATIM_CCR2_Read(void);

/* ��׽/�Ƚ�ͨ��3�Ĵ��� 
���ͨ��3����Ϊ�����
����һ��preload�Ĵ����������ݱ�����shadow�Ĵ�����������������Ƚϲ���OC3���
���ͨ��3����Ϊ���룺
CCR3�������һ�����벶׽�¼�����ʱ�ļ�����ֵ����ʱCCR3Ϊֻ�� ��غ��� */
extern void ATIM_CCR3_Write(uint32_t SetValue);
extern uint32_t ATIM_CCR3_Read(void);

/* ��׽/�Ƚ�ͨ��4�Ĵ��� 
���ͨ��4����Ϊ�����
����һ��preload�Ĵ����������ݱ�����shadow�Ĵ�����������������Ƚϲ���OC4���
���ͨ��4����Ϊ���룺
CCR4�������һ�����벶׽�¼�����ʱ�ļ�����ֵ����ʱCCR4Ϊֻ�� ��غ��� */
extern void ATIM_CCR4_Write(uint32_t SetValue);
extern uint32_t ATIM_CCR4_Read(void);

/* ���ʹ������ ��غ��� */
extern void ATIM_BDTR_MOE_Setable(FunState NewState);
extern FunState ATIM_BDTR_MOE_Getable(void);

/* �Զ����ʹ�� ��غ��� */
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

/* �Ĵ���д�������� ��غ��� */
extern void ATIM_BDTR_LOCK_Set(uint32_t SetValue);
extern uint32_t ATIM_BDTR_LOCK_Get(void);

/* ����ʱ����룬�������û���������������ʱ�䳤�� ��غ��� */
extern void ATIM_BDTR_DTG_Set(uint32_t SetValue);
extern uint32_t ATIM_BDTR_DTG_Get(void);

/* DMA Burst���� ��غ��� */
extern void ATIM_DCR_DBL_Set(uint32_t SetValue);
extern uint32_t ATIM_DCR_DBL_Get(void);

/* DMA����ַ������ָ��Ĵ�����ƫ�Ƶ�ַ ��غ��� */
extern void ATIM_DCR_DBA_Set(uint32_t SetValue);
extern uint32_t ATIM_DCR_DBA_Get(void);

/* DMA burst���ʼĴ���
��ʹ��DMA burst����ʱ����DMAͨ�������ַ����ΪATIM_DMAR��ATIM�����DBL��ֵ�������DMA���� ��غ��� */
extern void ATIM_DMAR_Write(uint32_t SetValue);
extern uint32_t ATIM_DMAR_Read(void);

/* ATIM_BRK2���������ſ��ź� ��غ��� */
extern void ATIM_BKCR_BRK2GATE_Set(uint32_t SetValue);
extern uint32_t ATIM_BKCR_BRK2GATE_Get(void);

/* ATIM_BRK1���������ſ��ź� ��غ��� */
extern void ATIM_BKCR_BRK1GATE_Set(uint32_t SetValue);
extern uint32_t ATIM_BKCR_BRK1GATE_Get(void);

/* ɲ���źŵ��˲�ʱ�Ӻͳ���ѡ��  ��غ��� */
extern void ATIM_BKCR_BRKF_Set(uint32_t SetValue);
extern uint32_t ATIM_BKCR_BRKF_Get(void);

/* ɲ����Ͽ��� ��غ��� */
extern void ATIM_BKCR_BRKCOMB_Set(uint32_t SetValue);
extern uint32_t ATIM_BKCR_BRKCOMB_Get(void);

/* XTHFͣ����ɲ���ź�ʹ�� ��غ��� */
extern void ATIM_BKCR_HFDET_BRKEN_Setable(FunState NewState);
extern FunState ATIM_BKCR_HFDET_BRKEN_Getable(void);

/* SVDɲ���ź�ʹ�� ��غ��� */
extern void ATIM_BKCR_SVD_BRKEN_Setable(FunState NewState);
extern FunState ATIM_BKCR_SVD_BRKEN_Getable(void);

/* �Ƚ������ɲ���ź�ʹ�� ��غ��� */
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
