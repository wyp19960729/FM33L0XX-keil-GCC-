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
   
#define	GPTIMx_CR1_CKD_Pos	8	/* Dead time�������˲�ʱ��Ƶ�ʷ�Ƶ�Ĵ��������CK_INT�ķ�Ƶ�ȣ�(Counter clocK Divider) */
#define	GPTIMx_CR1_CKD_Msk	(0x3U << GPTIMx_CR1_CKD_Pos)
#define	GPTIMx_CR1_CKD_1TINT	(0x0U << GPTIMx_CR1_CKD_Pos)	/* 00��tDTS=tCK_INT */
#define	GPTIMx_CR1_CKD_2TINT	(0x1U << GPTIMx_CR1_CKD_Pos)	/* 01��tDTS=2*tCK_INT */
#define	GPTIMx_CR1_CKD_4TINT	(0x2U << GPTIMx_CR1_CKD_Pos)	/* 10��tDTS=4*tCK_INT */

#define	GPTIMx_CR1_ARPE_Pos	7	/* Auto-reloadԤװ��ʹ�� (Auto-Reload Preload Enable) */
#define	GPTIMx_CR1_ARPE_Msk	(0x1U << GPTIMx_CR1_ARPE_Pos)
	/* 0��ARR�Ĵ�����ʹ��preload */
	/* 1��ARR�Ĵ���ʹ��preload */

#define	GPTIMx_CR1_CMS_Pos	5	/* ����������ģʽѡ�� (Counter Mode Selection) */
#define	GPTIMx_CR1_CMS_Msk	(0x3U << GPTIMx_CR1_CMS_Pos)
#define	GPTIMx_CR1_CMS_EDGE	(0x0U << GPTIMx_CR1_CMS_Pos)	/* 00�����ض���ģʽ */
#define	GPTIMx_CR1_CMS_CENTRAL1	(0x1U << GPTIMx_CR1_CMS_Pos)	/* 01���������ģʽ1������Ƚ��жϱ�־���ڼ��������¼����Ĺ�������λ */
#define	GPTIMx_CR1_CMS_CENTRAL2	(0x2U << GPTIMx_CR1_CMS_Pos)	/* 10���������ģʽ2������Ƚ��жϱ�־���ڼ��������ϼ����Ĺ�������λ */
#define	GPTIMx_CR1_CMS_CENTRAL3	(0x3U << GPTIMx_CR1_CMS_Pos)	/* 11���������ģʽ3������Ƚ��жϱ�־�ڼ������������¼����Ĺ����ж�����λ */

#define	GPTIMx_CR1_DIR_Pos	4	/* ��������Ĵ��� (counter Direction) */
#define	GPTIMx_CR1_DIR_Msk	(0x1U << GPTIMx_CR1_DIR_Pos)
#define	GPTIMx_CR1_DIR_UP	(0x0U << GPTIMx_CR1_DIR_Pos)	/* 0�����ϼ��� */
#define	GPTIMx_CR1_DIR_DOWN	(0x1U << GPTIMx_CR1_DIR_Pos)	/* 1�����¼��� */

#define	GPTIMx_CR1_OPM_Pos	3	/* ���������ģʽ (One Pulse Mode) */
#define	GPTIMx_CR1_OPM_Msk	(0x1U << GPTIMx_CR1_OPM_Pos)
#define	GPTIMx_CR1_OPM_CONTINUE	(0x0U << GPTIMx_CR1_OPM_Pos)	/* 0��Update Event����ʱ��������ֹͣ */
#define	GPTIMx_CR1_OPM_STOP	(0x1U << GPTIMx_CR1_OPM_Pos)	/* 1��Update Event����ʱ������ֹͣ���Զ�����CEN�� */

#define	GPTIMx_CR1_URS_Pos	2	/* ��������ѡ�� (Update Request Selection) */
#define	GPTIMx_CR1_URS_Msk	(0x1U << GPTIMx_CR1_URS_Pos)

#define	GPTIMx_CR1_UDIS_Pos	1	/* ��ֹupdate (Update Disable) */
#define	GPTIMx_CR1_UDIS_Msk	(0x1U << GPTIMx_CR1_UDIS_Pos)
	/* 0��ʹ��update�¼��������¼�����ʱ����update�¼�
-������������������
-�����λUG�Ĵ���
-�ӻ�����������update */
	/* 1����ֹupdate�¼���������shadow�Ĵ�������UG��λ��ӻ��������յ�Ӳ��resetʱ���³�ʼ����������Ԥ��Ƶ���� */

#define	GPTIMx_CR1_CEN_Pos	0	/* ������ʹ�� (Counter Enable) */
#define	GPTIMx_CR1_CEN_Msk	(0x1U << GPTIMx_CR1_CEN_Pos)
	/* 0���������ر� */
	/* 1��������ʹ�� */

#define	GPTIMx_CR2_TI1S_Pos	7	/* ͨ��1����Դѡ�� (Timer Input 1 Selection) */
#define	GPTIMx_CR2_TI1S_Msk	(0x1U << GPTIMx_CR2_TI1S_Pos)
#define	GPTIMx_CR2_TI1S_CH1	(0x0U << GPTIMx_CR2_TI1S_Pos)	/* 0��GPTIMx_CH1����ͨ��1 */
#define	GPTIMx_CR2_TI1S_XOR	(0x1U << GPTIMx_CR2_TI1S_Pos)	/* 1��GPTIMx_CH1, CH2, CH3��������ͨ��1 */

#define	GPTIMx_CR2_MMS_Pos	4	/* ����ģʽѡ��������������ģʽ����ӻ����͵�ͬ�������źţ�TRGO��Դ (Master Mode Selection) */
#define	GPTIMx_CR2_MMS_Msk	(0x7U << GPTIMx_CR2_MMS_Pos)
#define	GPTIMx_CR2_MMS_EGR_	(0x0U << GPTIMx_CR2_MMS_Pos)	/* 000��GPTIM_EGR��UG�Ĵ���������TRGO */
#define	GPTIMx_CR2_MMS_CNT_EN	(0x1U << GPTIMx_CR2_MMS_Pos)	/* 001��������ʹ���ź�CNT_EN������TRGO��������ͬʱ���������ʱ�� */
#define	GPTIMx_CR2_MMS_UE_TRGO	(0x2U << GPTIMx_CR2_MMS_Pos)	/* 010��UE��update event���źű�����TRGO */
#define	GPTIMx_CR2_MMS_CC1CMP	(0x3U << GPTIMx_CR2_MMS_Pos)	/* 011���Ƚ����壬���CC1IF��־��Ҫ��λ��TRGO���һ�������� */
#define	GPTIMx_CR2_MMS_OC1REF	(0x4U << GPTIMx_CR2_MMS_Pos)	/* 100��OC1REF����TRGO */
#define	GPTIMx_CR2_MMS_OC2REF	(0x5U << GPTIMx_CR2_MMS_Pos)	/* 101��OC2REF����TRGO */
#define	GPTIMx_CR2_MMS_OC3REF	(0x6U << GPTIMx_CR2_MMS_Pos)	/* 110��OC3REF����TRGO */
#define	GPTIMx_CR2_MMS_OC4REF	(0x7U << GPTIMx_CR2_MMS_Pos)	/* 111��OC4REF����TRGO */

#define	GPTIMx_CR2_CCDS_Pos	3	/* ��׽/�Ƚ� DMAѡ�� (Capture/Compare DMA Selection) */
#define	GPTIMx_CR2_CCDS_Msk	(0x1U << GPTIMx_CR2_CCDS_Pos)
#define	GPTIMx_CR2_CCDS_CC	(0x0U << GPTIMx_CR2_CCDS_Pos)	/* 0����׽/�Ƚ��¼�����ʱ����DMA���� */
#define	GPTIMx_CR2_CCDS_UE	(0x1U << GPTIMx_CR2_CCDS_Pos)	/* 1��Update Event����ʱ����DMA���� */

#define	GPTIMx_SMCR_ETP_Pos	15	/* �ⲿ�����źż������� (External Trigger Polarity) */
#define	GPTIMx_SMCR_ETP_Msk	(0x1U << GPTIMx_SMCR_ETP_Pos)
#define	GPTIMx_SMCR_ETP_POS	(0x0U << GPTIMx_SMCR_ETP_Pos)	/* 0���ߵ�ƽ����������Ч */
#define	GPTIMx_SMCR_ETP_NEG	(0x1U << GPTIMx_SMCR_ETP_Pos)	/* 1���͵�ƽ���½�����Ч */

#define	GPTIMx_SMCR_ECE_Pos	14	/* �ⲿʱ��ʹ�� (External Clock Enable) */
#define	GPTIMx_SMCR_ECE_Msk	(0x1U << GPTIMx_SMCR_ECE_Pos)
	/* 0���ر��ⲿʱ��ģʽ2 */
	/* 1��ʹ���ⲿʱ��ģʽ2��������ʱ��ΪETRF��Ч�� */

#define	GPTIMx_SMCR_ETPS_Pos	12	/* �ⲿ�����ź�Ԥ��Ƶ�Ĵ��� (External Trigger Prescaler)
�ⲿ�����ź�ETRP��Ƶ�����ֻ����GPTIM����ʱ�ӵ�1/4���������ź�Ƶ�ʽϸ�ʱ������ʹ��Ԥ��Ƶ */
#define	GPTIMx_SMCR_ETPS_Msk	(0x3U << GPTIMx_SMCR_ETPS_Pos)
#define	GPTIMx_SMCR_ETPS_DIV1	(0x0U << GPTIMx_SMCR_ETPS_Pos)	/* 00������Ƶ */
#define	GPTIMx_SMCR_ETPS_DIV2	(0x1U << GPTIMx_SMCR_ETPS_Pos)	/* 01��2��Ƶ */
#define	GPTIMx_SMCR_ETPS_DIV4	(0x2U << GPTIMx_SMCR_ETPS_Pos)	/* 10��4��Ƶ */
#define	GPTIMx_SMCR_ETPS_DIV8	(0x3U << GPTIMx_SMCR_ETPS_Pos)	/* 11��8��Ƶ */

#define	GPTIMx_SMCR_ETF_Pos	8	/* �ⲿ�����ź��˲�ʱ�Ӻͳ���ѡ�� (External Trigger Filter) */
#define	GPTIMx_SMCR_ETF_Msk	(0xfU << GPTIMx_SMCR_ETF_Pos)
#define	GPTIMx_SMCR_ETF_FILT0	(0x0U << GPTIMx_SMCR_ETF_Pos)	/* 0000�����˲� */
#define	GPTIMx_SMCR_ETF_FILT1	(0x1U << GPTIMx_SMCR_ETF_Pos)	/* 0001��fSAMPLING=fCK_INT, N=2 */
#define	GPTIMx_SMCR_ETF_FILT2	(0x2U << GPTIMx_SMCR_ETF_Pos)	/* 0010��fSAMPLING=fCK_INT, N=4 */
#define	GPTIMx_SMCR_ETF_FILT3	(0x3U << GPTIMx_SMCR_ETF_Pos)	/* 0011��fSAMPLING=fCK_INT, N=8 */
#define	GPTIMx_SMCR_ETF_FILT4	(0x4U << GPTIMx_SMCR_ETF_Pos)	/* 0100��fSAMPLING=fDTS/2, N=6 */
#define	GPTIMx_SMCR_ETF_FILT5	(0x5U << GPTIMx_SMCR_ETF_Pos)	/* 0101��fSAMPLING=fDTS/2, N=8 */
#define	GPTIMx_SMCR_ETF_FILT6	(0x6U << GPTIMx_SMCR_ETF_Pos)	/* 0110��fSAMPLING=fDTS/4, N=6 */
#define	GPTIMx_SMCR_ETF_FILT7	(0x7U << GPTIMx_SMCR_ETF_Pos)	/* 0111��fSAMPLING=fDTS/4, N=8 */
#define	GPTIMx_SMCR_ETF_FILT8	(0x8U << GPTIMx_SMCR_ETF_Pos)	/* 1000��fSAMPLING=fDTS/8, N=6 */
#define	GPTIMx_SMCR_ETF_FILT9	(0x9U << GPTIMx_SMCR_ETF_Pos)	/* 1001��fSAMPLING=fDTS/8, N=8 */
#define	GPTIMx_SMCR_ETF_FILT10	(0xaU << GPTIMx_SMCR_ETF_Pos)	/* 1010��fSAMPLING=fDTS/16, N=5 */
#define	GPTIMx_SMCR_ETF_FILT11	(0xbU << GPTIMx_SMCR_ETF_Pos)	/* 1011��fSAMPLING=fDTS/16, N=6 */
#define	GPTIMx_SMCR_ETF_FILT12	(0xcU << GPTIMx_SMCR_ETF_Pos)	/* 1100��fSAMPLING=fDTS/16, N=8 */
#define	GPTIMx_SMCR_ETF_FILT13	(0xdU << GPTIMx_SMCR_ETF_Pos)	/* 1101��fSAMPLING=fDTS/32, N=5 */
#define	GPTIMx_SMCR_ETF_FILT14	(0xeU << GPTIMx_SMCR_ETF_Pos)	/* 1110��fSAMPLING=fDTS/32, N=6 */
#define	GPTIMx_SMCR_ETF_FILT15	(0xfU << GPTIMx_SMCR_ETF_Pos)	/* 1111��fSAMPLING=fDTS/32, N=8 */

#define	GPTIMx_SMCR_MSM_Pos	7	/* ��/��ģʽ (Master Slave Mode) */
#define	GPTIMx_SMCR_MSM_Msk	(0x1U << GPTIMx_SMCR_MSM_Pos)
#define	GPTIMx_SMCR_MSM_NONE	(0x0U << GPTIMx_SMCR_MSM_Pos)	/* 0���޶��� */
#define	GPTIMx_SMCR_MSM_DELAY	(0x1U << GPTIMx_SMCR_MSM_Pos)	/* 1��TRGI�����Ķ������ӳ٣���ʹ��ǰ��ʱ������Ӷ�ʱ��ʵ������ͬ����ͨ��TRGO���������������ڵ����ⲿ�¼��Զ����ʱ������ͬ������� */

#define	GPTIMx_SMCR_TS_Pos	4	/* ����ѡ������ѡ��ͬ���������Ĵ���Դ (Trigger Source) */
#define	GPTIMx_SMCR_TS_Msk	(0x7U << GPTIMx_SMCR_TS_Pos)
#define	GPTIMx_SMCR_TS_ITR0	(0x0U << GPTIMx_SMCR_TS_Pos)	/* 000���ڲ������źţ�ITR0�� */
#define	GPTIMx_SMCR_TS_ITR1	(0x1U << GPTIMx_SMCR_TS_Pos)	/* 001���ڲ������źţ�ITR1�� */
#define	GPTIMx_SMCR_TS_ITR2	(0x2U << GPTIMx_SMCR_TS_Pos)	/* 010���ڲ������źţ�ITR2�� */
#define	GPTIMx_SMCR_TS_ITR3	(0x3U << GPTIMx_SMCR_TS_Pos)	/* 011���ڲ������źţ�ITR3�� */
#define	GPTIMx_SMCR_TS_TI1F_ED	(0x4U << GPTIMx_SMCR_TS_Pos)	/* 100��TI1���ؼ�⣨TI1F_ED�� */
#define	GPTIMx_SMCR_TS_TI1FP1	(0x5U << GPTIMx_SMCR_TS_Pos)	/* 101���˲���TI1��TI1FP1�� */
#define	GPTIMx_SMCR_TS_TI2FP2	(0x6U << GPTIMx_SMCR_TS_Pos)	/* 110���˲���TI2��TI2FP2�� */
#define	GPTIMx_SMCR_TS_ETRF	(0x7U << GPTIMx_SMCR_TS_Pos)	/* 111���ⲿ�������루ETRF�� */

#define	GPTIMx_SMCR_SMS_Pos	0	/* �ӻ�ģʽѡ�� (Slave Mode Selection) */
#define	GPTIMx_SMCR_SMS_Msk	(0x7U << GPTIMx_SMCR_SMS_Pos)
#define	GPTIMx_SMCR_SMS_SLAVE_DIS	(0x0U << GPTIMx_SMCR_SMS_Pos)	/* 000���ӻ�ģʽ��ֹ��CENʹ�ܺ�Ԥ��Ƶ��·ʱ��Դ�����ڲ�ʱ�� */
#define	GPTIMx_SMCR_SMS_ENCODER1	(0x1U << GPTIMx_SMCR_SMS_Pos)	/* 001��Encoderģʽ1��������ʹ��TI2FP1���أ�����TI1FP2��ƽ�ߵ������� */
#define	GPTIMx_SMCR_SMS_ENCODER2	(0x2U << GPTIMx_SMCR_SMS_Pos)	/* 010��Encoderģʽ2��������ʹ��TI1FP2���أ�����TI2FP1��ƽ�ߵ������� */
#define	GPTIMx_SMCR_SMS_ENCODER3	(0x3U << GPTIMx_SMCR_SMS_Pos)	/* 011��Encoderģʽ3��������ͬʱʹ��TI1FP1��TI2FP2���أ��������������źŵ�ƽ������ */
#define	GPTIMx_SMCR_SMS_RESET	(0x4U << GPTIMx_SMCR_SMS_Pos)	/* 100����λģʽ��TRGI�����س�ʼ�����������������Ĵ���update */
#define	GPTIMx_SMCR_SMS_GATE	(0x5U << GPTIMx_SMCR_SMS_Pos)	/* 101��բ��ģʽ��TRGIΪ�ߵ�ƽʱ������ʱ��ʹ�ܣ�TRGIΪ�͵�ƽʱ������ʱ��ֹͣ */
#define	GPTIMx_SMCR_SMS_TIGGER	(0x6U << GPTIMx_SMCR_SMS_Pos)	/* 110������ģʽ��TRGI�����ش�����������ʼ���������Ḵλ�������� */
#define	GPTIMx_SMCR_SMS_EXCLK	(0x7U << GPTIMx_SMCR_SMS_Pos)	/* 111���ⲿʱ��ģʽ1��TRGI������ֱ������������ */

#define	GPTIMx_DIER_CC4BURSTEN_Pos	19	/* ��׽�Ƚ�ͨ��4��DMAģʽ���� (CC4 Burst Enable) */
#define	GPTIMx_DIER_CC4BURSTEN_Msk	(0x1U << GPTIMx_DIER_CC4BURSTEN_Pos)
#define	GPTIMx_DIER_CC4BURSTEN_SINGLE	(0x0U << GPTIMx_DIER_CC4BURSTEN_Pos)	/* 0��Singleģʽ��������CCR */
#define	GPTIMx_DIER_CC4BURSTEN_BURST	(0x1U << GPTIMx_DIER_CC4BURSTEN_Pos)	/* 1��Burstģʽ��ͨ��DCR���÷��ʵĵ�ַ�ͳ��� */

#define	GPTIMx_DIER_CC3BURSTEN_Pos	18	/* ��׽�Ƚ�ͨ��3��DMAģʽ���� (CC3 Burst Enable) */
#define	GPTIMx_DIER_CC3BURSTEN_Msk	(0x1U << GPTIMx_DIER_CC3BURSTEN_Pos)
#define	GPTIMx_DIER_CC3BURSTEN_SINGLE	(0x0U << GPTIMx_DIER_CC3BURSTEN_Pos)	/* 0��Singleģʽ��������CCR */
#define	GPTIMx_DIER_CC3BURSTEN_BURST	(0x1U << GPTIMx_DIER_CC3BURSTEN_Pos)	/* 1��Burstģʽ��ͨ��DCR���÷��ʵĵ�ַ�ͳ��� */

#define	GPTIMx_DIER_CC2BURSTEN_Pos	17	/* ��׽�Ƚ�ͨ��2��DMAģʽ���� (CC2 Burst Enable) */
#define	GPTIMx_DIER_CC2BURSTEN_Msk	(0x1U << GPTIMx_DIER_CC2BURSTEN_Pos)
#define	GPTIMx_DIER_CC2BURSTEN_SINGLE	(0x0U << GPTIMx_DIER_CC2BURSTEN_Pos)	/* 0��Singleģʽ��������CCR */
#define	GPTIMx_DIER_CC2BURSTEN_BURST	(0x1U << GPTIMx_DIER_CC2BURSTEN_Pos)	/* 1��Burstģʽ��ͨ��DCR���÷��ʵĵ�ַ�ͳ��� */

#define	GPTIMx_DIER_CC1BURSTEN_Pos	16	/* ��׽�Ƚ�ͨ��1��DMAģʽ���� (CC1 Burst Enable) */
#define	GPTIMx_DIER_CC1BURSTEN_Msk	(0x1U << GPTIMx_DIER_CC1BURSTEN_Pos)
#define	GPTIMx_DIER_CC1BURSTEN_SINGLE	(0x0U << GPTIMx_DIER_CC1BURSTEN_Pos)	/* 0��Singleģʽ��������CCR */
#define	GPTIMx_DIER_CC1BURSTEN_BURST	(0x1U << GPTIMx_DIER_CC1BURSTEN_Pos)	/* 1��Burstģʽ��ͨ��DCR���÷��ʵĵ�ַ�ͳ��� */

#define	GPTIMx_DIER_TDE_Pos	14	/* �ⲿ����DMA����ʹ�� (Triggered DMA Enable) */
#define	GPTIMx_DIER_TDE_Msk	(0x1U << GPTIMx_DIER_TDE_Pos)
	/* 0���ӻ�ģʽ�£���ֹ�ⲿ�����¼�����DMA���� */
	/* 1���ӻ�ģʽ�£������ⲿ�����¼�����DMA���󣨿������Զ�����preload�Ĵ����� */

#define	GPTIMx_DIER_CC4DE_Pos	12	/* ��׽�Ƚ�ͨ��4��DMA����ʹ�� (CC4 DMA Enable) */
#define	GPTIMx_DIER_CC4DE_Msk	(0x1U << GPTIMx_DIER_CC4DE_Pos)
	/* 0����ֹCC4 DMA���� */
	/* 1������CC4 DMA���� */

#define	GPTIMx_DIER_CC3DE_Pos	11	/* ��׽�Ƚ�ͨ��3��DMA����ʹ�� (CC3 DMA Enable) */
#define	GPTIMx_DIER_CC3DE_Msk	(0x1U << GPTIMx_DIER_CC3DE_Pos)
	/* 0����ֹCC3 DMA���� */
	/* 1������CC3 DMA���� */

#define	GPTIMx_DIER_CC2DE_Pos	10	/* ��׽�Ƚ�ͨ��2��DMA����ʹ�� (CC2 DMA Enable) */
#define	GPTIMx_DIER_CC2DE_Msk	(0x1U << GPTIMx_DIER_CC2DE_Pos)
	/* 0����ֹCC2 DMA���� */
	/* 1������CC2 DMA���� */

#define	GPTIMx_DIER_CC1DE_Pos	9	/* ��׽�Ƚ�ͨ��1��DMA����ʹ�� (CC1 DMA Enable) */
#define	GPTIMx_DIER_CC1DE_Msk	(0x1U << GPTIMx_DIER_CC1DE_Pos)
	/* 0����ֹCC1 DMA���� */
	/* 1������CC1 DMA���� */

#define	GPTIMx_DIER_UDE_Pos	8	/* Update Event DMA����ʹ�� (Update event DMA Enable) */
#define	GPTIMx_DIER_UDE_Msk	(0x1U << GPTIMx_DIER_UDE_Pos)
	/* 0��Update Event����ʱ����ֹ����DMA���� */
	/* 1��Update Event����ʱ���������DMA���� */

#define	GPTIMx_DIER_TIE_Pos	6	/* �����¼��ж�ʹ�� (Trigger event Interrupt Enable) */
#define	GPTIMx_DIER_TIE_Msk	(0x1U << GPTIMx_DIER_TIE_Pos)
	/* 0����ֹ�����¼��ж� */
	/* 1���������¼��ж� */

#define	GPTIMx_DIER_CC4IE_Pos	4	/* ��׽/�Ƚ�ͨ��4�ж�ʹ�� (CC4 Interrupt Enable) */
#define	GPTIMx_DIER_CC4IE_Msk	(0x1U << GPTIMx_DIER_CC4IE_Pos)
	/* 0����ֹ��׽/�Ƚ�4�ж� */
	/* 1������׽/�Ƚ�4�ж� */

#define	GPTIMx_DIER_CC3IE_Pos	3	/* ��׽/�Ƚ�ͨ��3�ж�ʹ�� (CC3 Interrupt Enable) */
#define	GPTIMx_DIER_CC3IE_Msk	(0x1U << GPTIMx_DIER_CC3IE_Pos)
	/* 0����ֹ��׽/�Ƚ�3�ж� */
	/* 1������׽/�Ƚ�3�ж� */

#define	GPTIMx_DIER_CC2IE_Pos	2	/* ��׽/�Ƚ�ͨ��2�ж�ʹ�� (CC2 Interrupt Enable) */
#define	GPTIMx_DIER_CC2IE_Msk	(0x1U << GPTIMx_DIER_CC2IE_Pos)
	/* 0����ֹ��׽/�Ƚ�2�ж� */
	/* 1������׽/�Ƚ�2�ж� */

#define	GPTIMx_DIER_CC1IE_Pos	1	/* ��׽/�Ƚ�ͨ��1�ж�ʹ�� (CC1 Interrupt Enable) */
#define	GPTIMx_DIER_CC1IE_Msk	(0x1U << GPTIMx_DIER_CC1IE_Pos)
	/* 0����ֹ��׽/�Ƚ�1�ж� */
	/* 1������׽/�Ƚ�1�ж� */

#define	GPTIMx_DIER_UIE_Pos	0	/* Update�¼��ж�ʹ�� (Update event Interrupt Enable) */
#define	GPTIMx_DIER_UIE_Msk	(0x1U << GPTIMx_DIER_UIE_Pos)
	/* 0����ֹUpdate�¼��ж� */
	/* 1������Update�¼��ж� */

#define	GPTIMx_ISR_CC4OF_Pos	12	/* ��׽/�Ƚ�ͨ��4��Overcapture�ж� (Over-Capture Interrupt Flag for CC4) */
#define	GPTIMx_ISR_CC4OF_Msk	(0x1U << GPTIMx_ISR_CC4OF_Pos)

#define	GPTIMx_ISR_CC3OF_Pos	11	/* ��׽/�Ƚ�ͨ��3��Overcapture�ж� (Over-Capture Interrupt Flag for CC3) */
#define	GPTIMx_ISR_CC3OF_Msk	(0x1U << GPTIMx_ISR_CC3OF_Pos)

#define	GPTIMx_ISR_CC2OF_Pos	10	/* ��׽/�Ƚ�ͨ��2��Overcapture�ж� (Over-Capture Interrupt Flag for CC2) */
#define	GPTIMx_ISR_CC2OF_Msk	(0x1U << GPTIMx_ISR_CC2OF_Pos)

#define	GPTIMx_ISR_CC1OF_Pos	9	/* ��׽/�Ƚ�ͨ��1��Overcapture�ж� (Over-Capture Interrupt Flag for CC1) */
#define	GPTIMx_ISR_CC1OF_Msk	(0x1U << GPTIMx_ISR_CC1OF_Pos)

#define	GPTIMx_ISR_TIF_Pos	6	/* �����¼��жϱ�־ */
#define	GPTIMx_ISR_TIF_Msk	(0x1U << GPTIMx_ISR_TIF_Pos)

#define	GPTIMx_ISR_CC4IF_Pos	4	/* ��׽/�Ƚ�ͨ��4�жϱ�־ (CC4 Interrupt Flag) */
#define	GPTIMx_ISR_CC4IF_Msk	(0x1U << GPTIMx_ISR_CC4IF_Pos)

#define	GPTIMx_ISR_CC3IF_Pos	3	/* ��׽/�Ƚ�ͨ��3�жϱ�־ (CC3 Interrupt Flag) */
#define	GPTIMx_ISR_CC3IF_Msk	(0x1U << GPTIMx_ISR_CC3IF_Pos)

#define	GPTIMx_ISR_CC2IF_Pos	2	/* ��׽/�Ƚ�ͨ��2�жϱ�־ (CC2 Interrupt Flag) */
#define	GPTIMx_ISR_CC2IF_Msk	(0x1U << GPTIMx_ISR_CC2IF_Pos)

#define	GPTIMx_ISR_CC1IF_Pos	1	/* ��׽/�Ƚ�ͨ��1�жϱ�־ (CC1 Interrupt Flag) */
#define	GPTIMx_ISR_CC1IF_Msk	(0x1U << GPTIMx_ISR_CC1IF_Pos)

#define	GPTIMx_ISR_UIF_Pos	0	/* Update�¼��жϱ�־��Ӳ����λ�����д1���㡣(Update event Interrupt Flag) */
#define	GPTIMx_ISR_UIF_Msk	(0x1U << GPTIMx_ISR_UIF_Pos)

#define	GPTIMx_EGR_TG_Pos	6	/* ��������������λ�˼Ĵ������������¼���Ӳ���Զ����� (Trigger Generate) */
#define	GPTIMx_EGR_TG_Msk	(0x1U << GPTIMx_EGR_TG_Pos)
#define	GPTIMx_EGR_TG_RESET	(0x0U << GPTIMx_EGR_TG_Pos)	/* 0:Ӳ���Զ����� */
#define	GPTIMx_EGR_TG_SET	(0x1U << GPTIMx_EGR_TG_Pos)	/* 1�������λ�˼Ĵ������������¼� */

#define	GPTIMx_EGR_CC4G_Pos	4	/* ��׽/�Ƚ�ͨ��4������� (CC4 Generate) */
#define	GPTIMx_EGR_CC4G_Msk	(0x1U << GPTIMx_EGR_CC4G_Pos)
#define	GPTIMx_EGR_CC4G_RESET	(0x0U << GPTIMx_EGR_CC4G_Pos)	/* ���CC4ͨ������Ϊ�����CC4IF��λ����ʹ�ܵ�����¿��Բ�����Ӧ���жϺ�DMA����
 */
#define	GPTIMx_EGR_CC4G_SET	(0x1U << GPTIMx_EGR_CC4G_Pos)

#define	GPTIMx_EGR_CC3G_Pos	3	/* ��׽/�Ƚ�ͨ��3������� (CC3 Generate) */
#define	GPTIMx_EGR_CC3G_Msk	(0x1U << GPTIMx_EGR_CC3G_Pos)
#define	GPTIMx_EGR_CC3G_RESET	(0x0U << GPTIMx_EGR_CC3G_Pos)	/* ���CC3ͨ������Ϊ�����CC3IF��λ����ʹ�ܵ�����¿��Բ�����Ӧ���жϺ�DMA����
 */
#define	GPTIMx_EGR_CC3G_SET	(0x1U << GPTIMx_EGR_CC3G_Pos)

#define	GPTIMx_EGR_CC2G_Pos	2	/* ��׽/�Ƚ�ͨ��2������� (CC2 Generate) */
#define	GPTIMx_EGR_CC2G_Msk	(0x1U << GPTIMx_EGR_CC2G_Pos)
#define	GPTIMx_EGR_CC2G_RESET	(0x0U << GPTIMx_EGR_CC2G_Pos)	/* ���CC2ͨ������Ϊ�����CC2IF��λ����ʹ�ܵ�����¿��Բ�����Ӧ���жϺ�DMA����
 */
#define	GPTIMx_EGR_CC2G_SET	(0x1U << GPTIMx_EGR_CC2G_Pos)

#define	GPTIMx_EGR_CC1G_Pos	1	/* ��׽/�Ƚ�ͨ��1������� (CC1 Generate) */
#define	GPTIMx_EGR_CC1G_Msk	(0x1U << GPTIMx_EGR_CC1G_Pos)
#define	GPTIMx_EGR_CC1G_RESET	(0x0U << GPTIMx_EGR_CC1G_Pos)	/* ���CC1ͨ������Ϊ�����CC1IF��λ����ʹ�ܵ�����¿��Բ�����Ӧ���жϺ�DMA����
 */
#define	GPTIMx_EGR_CC1G_SET	(0x1U << GPTIMx_EGR_CC1G_Pos)

#define	GPTIMx_EGR_UG_Pos	0	/* ���Update�¼��������λ�˼Ĵ�������Update�¼���Ӳ���Զ����� (User Generate) */
#define	GPTIMx_EGR_UG_Msk	(0x1U << GPTIMx_EGR_UG_Pos)
#define	GPTIMx_EGR_UG_RESET	(0x0U << GPTIMx_EGR_UG_Pos)	/* �����λ�˼Ĵ�������Update�¼���Ӳ���Զ����� (User Generate)
�����λUGʱ�����³�ʼ��������������shadow�Ĵ�����Ԥ��Ƶ�����������㡣 */
#define	GPTIMx_EGR_UG_SET	(0x1U << GPTIMx_EGR_UG_Pos)

#define	GPTIMx_CCMR1_OC2CE_Pos	15	/* ����Ƚ�2����ʹ�� (OC2 Clear Enable) */
#define	GPTIMx_CCMR1_OC2CE_Msk	(0x1U << GPTIMx_CCMR1_OC2CE_Pos)
	/* 0��OC2REF����ETRFӰ�� */
	/* 1����⵽ETRF�ߵ�ƽʱ���Զ�����OC2REF */

#define	GPTIMx_CCMR1_OC2M_Pos	12	/* ����Ƚ�2ģʽ���ã��˼Ĵ�������OC2REF�źŵ���Ϊ (OC2 Mode) */
#define	GPTIMx_CCMR1_OC2M_Msk	(0x7U << GPTIMx_CCMR1_OC2M_Pos)
#define	GPTIMx_CCMR1_OC2M_NONE	(0x0U << GPTIMx_CCMR1_OC2M_Pos)	/* 000������ȽϼĴ���CCR2�ͼ�����CNT�ıȽϽ������Ӱ����� */
#define	GPTIMx_CCMR1_OC2M_HIGH	(0x1U << GPTIMx_CCMR1_OC2M_Pos)	/* 001��CCR2=CNTʱ����OC2REF�ø� */
#define	GPTIMx_CCMR1_OC2M_LOW	(0x2U << GPTIMx_CCMR1_OC2M_Pos)	/* 010��CCR2=CNTʱ����OC2REF�õ� */
#define	GPTIMx_CCMR1_OC2M_TOG	(0x3U << GPTIMx_CCMR1_OC2M_Pos)	/* 011��CCR2=CNTʱ����תOC2REF */
#define	GPTIMx_CCMR1_OC2M_INACTIVE	(0x4U << GPTIMx_CCMR1_OC2M_Pos)	/* 100��OC2REF�̶�Ϊ�ͣ�inactive�� */
#define	GPTIMx_CCMR1_OC2M_ACTIVE	(0x5U << GPTIMx_CCMR1_OC2M_Pos)	/* 101��OC2REF�̶�Ϊ�ߣ�active�� */
#define	GPTIMx_CCMR1_OC2M_PWM1	(0x6U << GPTIMx_CCMR1_OC2M_Pos)	/* 110��PWMģʽ1 �C�����ϼ���ʱ��OC2REF��CNT<CCR2ʱ�øߣ������õͣ������¼���ʱ��OC2REF��CNT>CCR2ʱ�õͣ������ø� */
#define	GPTIMx_CCMR1_OC2M_PWM2	(0x7U << GPTIMx_CCMR1_OC2M_Pos)	/* 111��PWMģʽ2 �C�����ϼ���ʱ��OC2REF��CNT<CCR2ʱ�õͣ������øߣ������¼���ʱ��OC2REF��CNT>CCR2 ʱ�øߣ������õ� */

#define	GPTIMx_CCMR1_OC2PE_Pos	11	/* ����Ƚ�2Ԥװ��ʹ�� (OC2 Preload Enable) */
#define	GPTIMx_CCMR1_OC2PE_Msk	(0x1U << GPTIMx_CCMR1_OC2PE_Pos)
	/* 0��CCR2 preload�Ĵ�����Ч��CCR2����ֱ��д�� */
	/* 1��CCR2 preload�Ĵ�����Ч�����CCR2�Ķ�д�������Ƿ���preload�Ĵ�������update event����ʱ�Ž�preload�Ĵ���������ת�Ƶ�shadow�Ĵ����� */

#define	GPTIMx_CCMR1_OC2FE_Pos	10	/* ����Ƚ�2����ʹ�� (OC2 Fast Enable) */
#define	GPTIMx_CCMR1_OC2FE_Msk	(0x1U << GPTIMx_CCMR1_OC2FE_Pos)
	/* 0���رտ���ʹ�ܣ�trigger���벻��Ӱ��Ƚ���� */
	/* 1���򿪿���ʹ�ܣ�trigger�����������OC2REF�ı�Ϊ�Ƚ�ֵƥ��ʱ������������ܵ�ǰʵ�ʱȽ����
�˹��ܽ��ڵ�ǰͨ������ΪPWM1��PWM2ģʽʱ��Ч */

#define	GPTIMx_CCMR1_CC2S_Pos	8	/* ��׽/�Ƚ�2ͨ��ѡ�� (CC2 channel Selection) */
#define	GPTIMx_CCMR1_CC2S_Msk	(0x3U << GPTIMx_CCMR1_CC2S_Pos)
#define	GPTIMx_CCMR1_CC2S_OUT	(0x0U << GPTIMx_CCMR1_CC2S_Pos)	/* 00��CC2ͨ������Ϊ��� */
#define	GPTIMx_CCMR1_CC2S_TI2	(0x1U << GPTIMx_CCMR1_CC2S_Pos)	/* 01��CC2ͨ������Ϊ���룬IC2ӳ�䵽TI2 */
#define	GPTIMx_CCMR1_CC2S_TI1	(0x2U << GPTIMx_CCMR1_CC2S_Pos)	/* 10��CC2ͨ������Ϊ���룬IC2ӳ�䵽TI1 */
#define	GPTIMx_CCMR1_CC2S_TRC	(0x3U << GPTIMx_CCMR1_CC2S_Pos)	/* 11��CC2ͨ������Ϊ���룬IC2ӳ�䵽TRC */

#define	GPTIMx_CCMR1_OC1CE_Pos	7	/* ����Ƚ�1����ʹ�� (OC2 Clear Enable) */
#define	GPTIMx_CCMR1_OC1CE_Msk	(0x1U << GPTIMx_CCMR1_OC1CE_Pos)
	/* 0��OC1REF����ETRFӰ�� */
	/* 1����⵽ETRF�ߵ�ƽʱ���Զ�����OC1REF */

#define	GPTIMx_CCMR1_OC1M_Pos	4	/* ����Ƚ�1ģʽ���ã��˼Ĵ�������OC1REF�źŵ���Ϊ (OC1 Mode) */
#define	GPTIMx_CCMR1_OC1M_Msk	(0x7U << GPTIMx_CCMR1_OC1M_Pos)
#define	GPTIMx_CCMR1_OC1M_NONE	(0x0U << GPTIMx_CCMR1_OC1M_Pos)	/* 000������ȽϼĴ���CCR1�ͼ�����CNT�ıȽϽ������Ӱ����� */
#define	GPTIMx_CCMR1_OC1M_HIGH	(0x1U << GPTIMx_CCMR1_OC1M_Pos)	/* 001��CCR1=CNTʱ����OC1REF�ø� */
#define	GPTIMx_CCMR1_OC1M_LOW	(0x2U << GPTIMx_CCMR1_OC1M_Pos)	/* 010��CCR1=CNTʱ����OC1REF�õ� */
#define	GPTIMx_CCMR1_OC1M_TOG	(0x3U << GPTIMx_CCMR1_OC1M_Pos)	/* 011��CCR1=CNTʱ����תOC1REF */
#define	GPTIMx_CCMR1_OC1M_INACTIVE	(0x4U << GPTIMx_CCMR1_OC1M_Pos)	/* 100��OC1REF�̶�Ϊ�ͣ�inactive�� */
#define	GPTIMx_CCMR1_OC1M_ACTIVE	(0x5U << GPTIMx_CCMR1_OC1M_Pos)	/* 101��OC1REF�̶�Ϊ�ߣ�active�� */
#define	GPTIMx_CCMR1_OC1M_PWM1	(0x6U << GPTIMx_CCMR1_OC1M_Pos)	/* 110��PWMģʽ1 �C�����ϼ���ʱ��OC1REF��CNT<CCR1ʱ�øߣ������õͣ������¼���ʱ��OC1REF��CNT>CCR1ʱ�õͣ������ø� */
#define	GPTIMx_CCMR1_OC1M_PWM2	(0x7U << GPTIMx_CCMR1_OC1M_Pos)	/* 111��PWMģʽ2 �C�����ϼ���ʱ��OC1REF��CNT<CCR1ʱ�õͣ������øߣ������¼���ʱ��OC1REF��CNT>CCR1 ʱ�øߣ������õ� */

#define	GPTIMx_CCMR1_OC1PE_Pos	3	/* ����Ƚ�1Ԥװ��ʹ�� (OC1 Preload Enable) */
#define	GPTIMx_CCMR1_OC1PE_Msk	(0x1U << GPTIMx_CCMR1_OC1PE_Pos)
	/* 0��CCR1 preload�Ĵ�����Ч��CCR1����ֱ��д�� */
	/* 1��CCR1 preload�Ĵ�����Ч�����CCR1�Ķ�д�������Ƿ���preload�Ĵ�������update event����ʱ�Ž�preload�Ĵ���������ת�Ƶ�shadow�Ĵ����� */

#define	GPTIMx_CCMR1_OC1FE_Pos	2	/* ����Ƚ�1����ʹ�� (OC1 Fast Enable) */
#define	GPTIMx_CCMR1_OC1FE_Msk	(0x1U << GPTIMx_CCMR1_OC1FE_Pos)
	/* 0���رտ���ʹ�ܣ�trigger���벻��Ӱ��Ƚ���� */
	/* 1���򿪿���ʹ�ܣ�trigger�����������OC1REF�ı�Ϊ�Ƚ�ֵƥ��ʱ������������ܵ�ǰʵ�ʱȽ����
�˹��ܽ��ڵ�ǰͨ������ΪPWM1��PWM2ģʽʱ��Ч */

#define	GPTIMx_CCMR1_CC1S_Pos	0	/* ��׽/�Ƚ�1ͨ��ѡ�� (CC1 channel Selection) */
#define	GPTIMx_CCMR1_CC1S_Msk	(0x3U << GPTIMx_CCMR1_CC1S_Pos)
#define	GPTIMx_CCMR1_CC1S_OUT	(0x0U << GPTIMx_CCMR1_CC1S_Pos)	/* 00��CC1ͨ������Ϊ��� */
#define	GPTIMx_CCMR1_CC1S_TI1	(0x1U << GPTIMx_CCMR1_CC1S_Pos)	/* 01��CC1ͨ������Ϊ���룬IC1ӳ�䵽TI1 */
#define	GPTIMx_CCMR1_CC1S_TI2	(0x2U << GPTIMx_CCMR1_CC1S_Pos)	/* 10��CC1ͨ������Ϊ���룬IC1ӳ�䵽TI2 */
#define	GPTIMx_CCMR1_CC1S_TRC	(0x3U << GPTIMx_CCMR1_CC1S_Pos)	/* 11��CC1ͨ������Ϊ���룬IC1ӳ�䵽TRC */

#define	GPTIMx_CCMR1_IC2F_Pos	12	/* ���벶׽2�˲� (IC2 Filter) */
#define	GPTIMx_CCMR1_IC2F_Msk	(0xfU << GPTIMx_CCMR1_IC2F_Pos)
#define	GPTIMx_CCMR1_IC2F_FILT0	(0x0U << GPTIMx_CCMR1_IC2F_Pos)	/* 0000�����˲���ʹ��fDTS���� */
#define	GPTIMx_CCMR1_IC2F_FILT1	(0x1U << GPTIMx_CCMR1_IC2F_Pos)	/* 0001��fSAMPLING=fCK_INT, N=2 */
#define	GPTIMx_CCMR1_IC2F_FILT2	(0x2U << GPTIMx_CCMR1_IC2F_Pos)	/* 0010��fSAMPLING=fCK_INT, N=4 */
#define	GPTIMx_CCMR1_IC2F_FILT3	(0x3U << GPTIMx_CCMR1_IC2F_Pos)	/* 0011��fSAMPLING=fCK_INT, N=8 */
#define	GPTIMx_CCMR1_IC2F_FILT4	(0x4U << GPTIMx_CCMR1_IC2F_Pos)	/* 0100��fSAMPLING=fDTS/2, N=6 */
#define	GPTIMx_CCMR1_IC2F_FILT5	(0x5U << GPTIMx_CCMR1_IC2F_Pos)	/* 0101��fSAMPLING=fDTS/2, N=8 */
#define	GPTIMx_CCMR1_IC2F_FILT6	(0x6U << GPTIMx_CCMR1_IC2F_Pos)	/* 0110��fSAMPLING=fDTS/4, N=6 */
#define	GPTIMx_CCMR1_IC2F_FILT7	(0x7U << GPTIMx_CCMR1_IC2F_Pos)	/* 0111��fSAMPLING=fDTS/4, N=8 */
#define	GPTIMx_CCMR1_IC2F_FILT8	(0x8U << GPTIMx_CCMR1_IC2F_Pos)	/* 1000��fSAMPLING=fDTS/8, N=6 */
#define	GPTIMx_CCMR1_IC2F_FILT9	(0x9U << GPTIMx_CCMR1_IC2F_Pos)	/* 1001��fSAMPLING=fDTS/8, N=8 */
#define	GPTIMx_CCMR1_IC2F_FILT10	(0xaU << GPTIMx_CCMR1_IC2F_Pos)	/* 1010��fSAMPLING=fDTS/16, N=5 */
#define	GPTIMx_CCMR1_IC2F_FILT11	(0xbU << GPTIMx_CCMR1_IC2F_Pos)	/* 1011��fSAMPLING=fDTS/16, N=6 */
#define	GPTIMx_CCMR1_IC2F_FILT12	(0xcU << GPTIMx_CCMR1_IC2F_Pos)	/* 1100��fSAMPLING=fDTS/16, N=8 */
#define	GPTIMx_CCMR1_IC2F_FILT13	(0xdU << GPTIMx_CCMR1_IC2F_Pos)	/* 1101��fSAMPLING=fDTS/32, N=5 */
#define	GPTIMx_CCMR1_IC2F_FILT14	(0xeU << GPTIMx_CCMR1_IC2F_Pos)	/* 1110��fSAMPLING=fDTS/32, N=6 */
#define	GPTIMx_CCMR1_IC2F_FILT15	(0xfU << GPTIMx_CCMR1_IC2F_Pos)	/* 1110��fSAMPLING=fDTS/32, N=6 */

#define	GPTIMx_CCMR1_IC2PSC_Pos	10	/* ���벶׽2Ԥ��Ƶ (IC2 Prescaler) */
#define	GPTIMx_CCMR1_IC2PSC_Msk	(0x3U << GPTIMx_CCMR1_IC2PSC_Pos)
#define	GPTIMx_CCMR1_IC2PSC_DIV1	(0x0U << GPTIMx_CCMR1_IC2PSC_Pos)	/* 00���޷�Ƶ */
#define	GPTIMx_CCMR1_IC2PSC_DIV2	(0x1U << GPTIMx_CCMR1_IC2PSC_Pos)	/* 01��ÿ2���¼��������һ�β�׽ */
#define	GPTIMx_CCMR1_IC2PSC_DIV4	(0x2U << GPTIMx_CCMR1_IC2PSC_Pos)	/* 10��ÿ4���¼��������һ�β�׽ */
#define	GPTIMx_CCMR1_IC2PSC_DIV8	(0x3U << GPTIMx_CCMR1_IC2PSC_Pos)	/* 11��ÿ8���¼��������һ�β�׽ */

#define	GPTIMx_CCMR1_CC2S_Pos	8	/* ��׽/�Ƚ�2ͨ��ѡ�� (Capture/Compare2 channel Selection) */
#define	GPTIMx_CCMR1_CC2S_Msk	(0x3U << GPTIMx_CCMR1_CC2S_Pos)
#define	GPTIMx_CCMR1_CC2S_OUT	(0x0U << GPTIMx_CCMR1_CC2S_Pos)	/* 00��CC2ͨ������Ϊ��� */
#define	GPTIMx_CCMR1_CC2S_TI2	(0x1U << GPTIMx_CCMR1_CC2S_Pos)	/* 01��CC2ͨ������Ϊ���룬IC3ӳ�䵽TI2 */
#define	GPTIMx_CCMR1_CC2S_TI1	(0x2U << GPTIMx_CCMR1_CC2S_Pos)	/* 10��CC2ͨ������Ϊ���룬IC3ӳ�䵽TI1 */
#define	GPTIMx_CCMR1_CC2S_TRC	(0x3U << GPTIMx_CCMR1_CC2S_Pos)	/* 11��CC2ͨ������Ϊ���룬IC3ӳ�䵽TRC */

#define	GPTIMx_CCMR1_IC1F_Pos	4	/* ���벶׽1�˲� (IC1 Filter) */
#define	GPTIMx_CCMR1_IC1F_Msk	(0xfU << GPTIMx_CCMR1_IC1F_Pos)
#define	GPTIMx_CCMR1_IC1F_FILT0	(0x0U << GPTIMx_CCMR1_IC1F_Pos)	/* 0000�����˲���ʹ��fDTS���� */
#define	GPTIMx_CCMR1_IC1F_FILT1	(0x1U << GPTIMx_CCMR1_IC1F_Pos)	/* 0001��fSAMPLING=fCK_INT, N=2 */
#define	GPTIMx_CCMR1_IC1F_FILT2	(0x2U << GPTIMx_CCMR1_IC1F_Pos)	/* 0010��fSAMPLING=fCK_INT, N=4 */
#define	GPTIMx_CCMR1_IC1F_FILT3	(0x3U << GPTIMx_CCMR1_IC1F_Pos)	/* 0011��fSAMPLING=fCK_INT, N=8 */
#define	GPTIMx_CCMR1_IC1F_FILT4	(0x4U << GPTIMx_CCMR1_IC1F_Pos)	/* 0100��fSAMPLING=fDTS/2, N=6 */
#define	GPTIMx_CCMR1_IC1F_FILT5	(0x5U << GPTIMx_CCMR1_IC1F_Pos)	/* 0101��fSAMPLING=fDTS/2, N=8 */
#define	GPTIMx_CCMR1_IC1F_FILT6	(0x6U << GPTIMx_CCMR1_IC1F_Pos)	/* 0110��fSAMPLING=fDTS/4, N=6 */
#define	GPTIMx_CCMR1_IC1F_FILT7	(0x7U << GPTIMx_CCMR1_IC1F_Pos)	/* 0111��fSAMPLING=fDTS/4, N=8 */
#define	GPTIMx_CCMR1_IC1F_FILT8	(0x8U << GPTIMx_CCMR1_IC1F_Pos)	/* 1000��fSAMPLING=fDTS/8, N=6 */
#define	GPTIMx_CCMR1_IC1F_FILT9	(0x9U << GPTIMx_CCMR1_IC1F_Pos)	/* 1001��fSAMPLING=fDTS/8, N=8 */
#define	GPTIMx_CCMR1_IC1F_FILT10	(0xaU << GPTIMx_CCMR1_IC1F_Pos)	/* 1010��fSAMPLING=fDTS/16, N=5 */
#define	GPTIMx_CCMR1_IC1F_FILT11	(0xbU << GPTIMx_CCMR1_IC1F_Pos)	/* 1011��fSAMPLING=fDTS/16, N=6 */
#define	GPTIMx_CCMR1_IC1F_FILT12	(0xcU << GPTIMx_CCMR1_IC1F_Pos)	/* 1100��fSAMPLING=fDTS/16, N=8 */
#define	GPTIMx_CCMR1_IC1F_FILT13	(0xdU << GPTIMx_CCMR1_IC1F_Pos)	/* 1101��fSAMPLING=fDTS/32, N=5 */
#define	GPTIMx_CCMR1_IC1F_FILT14	(0xeU << GPTIMx_CCMR1_IC1F_Pos)	/* 1110��fSAMPLING=fDTS/32, N=6 */
#define	GPTIMx_CCMR1_IC1F_FILT15	(0xfU << GPTIMx_CCMR1_IC1F_Pos)	/* 1110��fSAMPLING=fDTS/32, N=8 */

#define	GPTIMx_CCMR1_IC1PSC_Pos	2	/* ���벶׽1Ԥ��Ƶ (IC1 Prescaler) */
#define	GPTIMx_CCMR1_IC1PSC_Msk	(0x3U << GPTIMx_CCMR1_IC1PSC_Pos)
#define	GPTIMx_CCMR1_IC1PSC_DIV1	(0x0U << GPTIMx_CCMR1_IC1PSC_Pos)	/* 00���޷�Ƶ */
#define	GPTIMx_CCMR1_IC1PSC_DIV2	(0x1U << GPTIMx_CCMR1_IC1PSC_Pos)	/* 01��ÿ2���¼��������һ�β�׽ */
#define	GPTIMx_CCMR1_IC1PSC_DIV4	(0x2U << GPTIMx_CCMR1_IC1PSC_Pos)	/* 10��ÿ4���¼��������һ�β�׽ */
#define	GPTIMx_CCMR1_IC1PSC_DIV8	(0x3U << GPTIMx_CCMR1_IC1PSC_Pos)	/* 11��ÿ8���¼��������һ�β�׽ */

#define	GPTIMx_CCMR1_CC1S_Pos	0	/* ��׽/�Ƚ�1ͨ��ѡ�� (Capture/Compare1 channel Selection) */
#define	GPTIMx_CCMR1_CC1S_Msk	(0x3U << GPTIMx_CCMR1_CC1S_Pos)
#define	GPTIMx_CCMR1_CC1S_OUT	(0x0U << GPTIMx_CCMR1_CC1S_Pos)	/* 00��CC1ͨ������Ϊ��� */
#define	GPTIMx_CCMR1_CC1S_TI1	(0x1U << GPTIMx_CCMR1_CC1S_Pos)	/* 01��CC1ͨ������Ϊ���룬IC1ӳ�䵽TI1 */
#define	GPTIMx_CCMR1_CC1S_TI2	(0x2U << GPTIMx_CCMR1_CC1S_Pos)	/* 10��CC1ͨ������Ϊ���룬IC1ӳ�䵽TI2 */
#define	GPTIMx_CCMR1_CC1S_TRC	(0x3U << GPTIMx_CCMR1_CC1S_Pos)	/* 11��CC1ͨ������Ϊ���룬IC1ӳ�䵽TRC */

#define	GPTIMx_CCMR2_OC4CE_Pos	15	/* ����Ƚ�4����ʹ�� (OC4 Clear Enable) */
#define	GPTIMx_CCMR2_OC4CE_Msk	(0x1U << GPTIMx_CCMR2_OC4CE_Pos)
	/* 0��OC4REF����ETRFӰ�� */
	/* 1����⵽ETRF�ߵ�ƽʱ���Զ�����OC4REF */

#define	GPTIMx_CCMR2_OC4M_Pos	12	/* ����Ƚ�4ģʽ���ã��˼Ĵ�������OC4REF�źŵ���Ϊ (OC4 Mode) */
#define	GPTIMx_CCMR2_OC4M_Msk	(0x7U << GPTIMx_CCMR2_OC4M_Pos)
#define	GPTIMx_CCMR2_OC4M_NONE	(0x0U << GPTIMx_CCMR2_OC4M_Pos)	/* 000������ȽϼĴ���CCR4�ͼ�����CNT�ıȽϽ������Ӱ����� */
#define	GPTIMx_CCMR2_OC4M_HIGH	(0x1U << GPTIMx_CCMR2_OC4M_Pos)	/* 001��CCR4=CNTʱ����OC4REF�ø� */
#define	GPTIMx_CCMR2_OC4M_LOW	(0x2U << GPTIMx_CCMR2_OC4M_Pos)	/* 010��CCR4=CNTʱ����OC4REF�õ� */
#define	GPTIMx_CCMR2_OC4M_TOG	(0x3U << GPTIMx_CCMR2_OC4M_Pos)	/* 011��CCR4=CNTʱ����תOC4REF */
#define	GPTIMx_CCMR2_OC4M_INACTIVE	(0x4U << GPTIMx_CCMR2_OC4M_Pos)	/* 100��OC4REF�̶�Ϊ�ͣ�inactive�� */
#define	GPTIMx_CCMR2_OC4M_CTIVE	(0x5U << GPTIMx_CCMR2_OC4M_Pos)	/* 101��OC4REF�̶�Ϊ�ߣ�active�� */
#define	GPTIMx_CCMR2_OC4M_PWM1	(0x6U << GPTIMx_CCMR2_OC4M_Pos)	/* 110��PWMģʽ1 �C�����ϼ���ʱ��OC4REF��CNT<CCR4ʱ�øߣ������õͣ������¼���ʱ��OC4REF��CNT>CCR4ʱ�õͣ������ø� */
#define	GPTIMx_CCMR2_OC4M_PWM2	(0x7U << GPTIMx_CCMR2_OC4M_Pos)	/* 111��PWMģʽ2 �C�����ϼ���ʱ��OC4REF��CNT<CCR4ʱ�õͣ������øߣ������¼���ʱ��OC4REF��CNT>CCR4ʱ�øߣ������õ� */

#define	GPTIMx_CCMR2_OC4PE_Pos	11	/* ����Ƚ�4Ԥװ��ʹ�� (OC4 Preload Enable) */
#define	GPTIMx_CCMR2_OC4PE_Msk	(0x1U << GPTIMx_CCMR2_OC4PE_Pos)
	/* 0��CCR4 preload�Ĵ�����Ч��CCR4����ֱ��д�� */
	/* 1��CCR4 preload�Ĵ�����Ч�����CCR4�Ķ�д�������Ƿ���preload�Ĵ�������update event����ʱ�Ž�preload�Ĵ���������ת�Ƶ�shadow�Ĵ����� */

#define	GPTIMx_CCMR2_OC4FE_Pos	10	/* ����Ƚ�4����ʹ�� (OC4 Fast Enable) */
#define	GPTIMx_CCMR2_OC4FE_Msk	(0x1U << GPTIMx_CCMR2_OC4FE_Pos)
	/* 0���رտ���ʹ�ܣ�trigger���벻��Ӱ��Ƚ���� */
	/* 1���򿪿���ʹ�ܣ�trigger�����������OC4REF�ı�Ϊ�Ƚ�ֵƥ��ʱ������������ܵ�ǰʵ�ʱȽ���� */

#define	GPTIMx_CCMR2_CC4S_Pos	8	/* ��׽/�Ƚ�4ͨ��ѡ�� (CC4 channel Selection) */
#define	GPTIMx_CCMR2_CC4S_Msk	(0x3U << GPTIMx_CCMR2_CC4S_Pos)
#define	GPTIMx_CCMR2_CC4S_OUT	(0x0U << GPTIMx_CCMR2_CC4S_Pos)	/* 00��CC4ͨ������Ϊ��� */
#define	GPTIMx_CCMR2_CC4S_TI4	(0x1U << GPTIMx_CCMR2_CC4S_Pos)	/* 01��CC4ͨ������Ϊ���룬IC4ӳ�䵽TI4 */
#define	GPTIMx_CCMR2_CC4S_TI3	(0x2U << GPTIMx_CCMR2_CC4S_Pos)	/* 10��CC4ͨ������Ϊ���룬IC4ӳ�䵽TI3 */
#define	GPTIMx_CCMR2_CC4S_TRC	(0x3U << GPTIMx_CCMR2_CC4S_Pos)	/* 11��CC4ͨ������Ϊ���룬IC4ӳ�䵽TRC */

#define	GPTIMx_CCMR2_OC3CE_Pos	7	/* ����Ƚ�3����ʹ�� (OC3 Clear Enable) */
#define	GPTIMx_CCMR2_OC3CE_Msk	(0x1U << GPTIMx_CCMR2_OC3CE_Pos)
	/* 0��OC3REF����ETRFӰ�� */
	/* 1����⵽ETRF�ߵ�ƽʱ���Զ�����OC3REF */

#define	GPTIMx_CCMR2_OC3M_Pos	4	/* ����Ƚ�3ģʽ���ã��˼Ĵ�������OC3REF�źŵ���Ϊ (OC3 Mode) */
#define	GPTIMx_CCMR2_OC3M_Msk	(0x7U << GPTIMx_CCMR2_OC3M_Pos)
#define	GPTIMx_CCMR2_OC3M_NONE	(0x0U << GPTIMx_CCMR2_OC3M_Pos)	/* 000������ȽϼĴ���CCR3�ͼ�����CNT�ıȽϽ������Ӱ����� */
#define	GPTIMx_CCMR2_OC3M_HIGH	(0x1U << GPTIMx_CCMR2_OC3M_Pos)	/* 001��CCR3=CNTʱ����OC3REF�ø� */
#define	GPTIMx_CCMR2_OC3M_LOW	(0x2U << GPTIMx_CCMR2_OC3M_Pos)	/* 010��CCR3=CNTʱ����OC3REF�õ� */
#define	GPTIMx_CCMR2_OC3M_TOG	(0x3U << GPTIMx_CCMR2_OC3M_Pos)	/* 011��CCR3=CNTʱ����תOC1REF */
#define	GPTIMx_CCMR2_OC3M_INACTIVE	(0x4U << GPTIMx_CCMR2_OC3M_Pos)	/* 100��OC3REF�̶�Ϊ�ͣ�inactive�� */
#define	GPTIMx_CCMR2_OC3M_ACTIVE	(0x5U << GPTIMx_CCMR2_OC3M_Pos)	/* 101��OC3REF�̶�Ϊ�ߣ�active�� */
#define	GPTIMx_CCMR2_OC3M_PWM1	(0x6U << GPTIMx_CCMR2_OC3M_Pos)	/* 110��PWMģʽ1 �C�����ϼ���ʱ��OC3REF��CNT<CCR3ʱ�øߣ������õͣ������¼���ʱ��OC3REF��CNT>CCR3ʱ�õͣ������ø� */
#define	GPTIMx_CCMR2_OC3M_PWM2	(0x7U << GPTIMx_CCMR2_OC3M_Pos)	/* 111��PWMģʽ2 �C�����ϼ���ʱ��OC3REF��CNT<CCR3ʱ�õͣ������øߣ������¼���ʱ��OC3REF��CNT>CCR3ʱ�øߣ������õ� */

#define	GPTIMx_CCMR2_OC3PE_Pos	3	/* ����Ƚ�3Ԥװ��ʹ�� (OC3 Preload Enable) */
#define	GPTIMx_CCMR2_OC3PE_Msk	(0x1U << GPTIMx_CCMR2_OC3PE_Pos)
	/* 0��CCR3 preload�Ĵ�����Ч��CCR3����ֱ��д�� */
	/* 1��CCR3 preload�Ĵ�����Ч�����CCR3�Ķ�д�������Ƿ���preload�Ĵ�������update event����ʱ�Ž�preload�Ĵ���������ת�Ƶ�shadow�Ĵ����� */

#define	GPTIMx_CCMR2_OC3FE_Pos	2	/* ����Ƚ�3����ʹ�� (OC3 Fast Enable) */
#define	GPTIMx_CCMR2_OC3FE_Msk	(0x1U << GPTIMx_CCMR2_OC3FE_Pos)
	/* 0���رտ���ʹ�ܣ�trigger���벻��Ӱ��Ƚ���� */
	/* 1���򿪿���ʹ�ܣ�trigger�����������OC3REF�ı�Ϊ�Ƚ�ֵƥ��ʱ������������ܵ�ǰʵ�ʱȽ���� */

#define	GPTIMx_CCMR2_CC3S_Pos	0	/* ��׽/�Ƚ�3ͨ��ѡ�� (CC3 channel Selection) */
#define	GPTIMx_CCMR2_CC3S_Msk	(0x3U << GPTIMx_CCMR2_CC3S_Pos)
#define	GPTIMx_CCMR2_CC3S_OUT	(0x0U << GPTIMx_CCMR2_CC3S_Pos)	/* 00��CC3ͨ������Ϊ��� */
#define	GPTIMx_CCMR2_CC3S_TI3	(0x1U << GPTIMx_CCMR2_CC3S_Pos)	/* 01��CC3ͨ������Ϊ���룬IC1ӳ�䵽TI3 */
#define	GPTIMx_CCMR2_CC3S_TI4	(0x2U << GPTIMx_CCMR2_CC3S_Pos)	/* 10��CC3ͨ������Ϊ���룬IC1ӳ�䵽TI4 */
#define	GPTIMx_CCMR2_CC3S_TRC	(0x3U << GPTIMx_CCMR2_CC3S_Pos)	/* 11��CC3ͨ������Ϊ���룬IC1ӳ�䵽TRC */

#define	GPTIMx_CCMR2_IC4F_Pos	12	/* ���벶׽4�˲� (IC4 Filter) */
#define	GPTIMx_CCMR2_IC4F_Msk	(0xfU << GPTIMx_CCMR2_IC4F_Pos)


#define	GPTIMx_CCMR2_IC4PSC_Pos	10	/* ���벶׽4Ԥ��Ƶ (IC4 Prescaler) */
#define	GPTIMx_CCMR2_IC4PSC_Msk	(0x3U << GPTIMx_CCMR2_IC4PSC_Pos)
#define	GPTIMx_CCMR2_IC4PSC_DIV1	(0x0U << GPTIMx_CCMR2_IC4PSC_Pos)	/* 00���޷�Ƶ */
#define	GPTIMx_CCMR2_IC4PSC_DIV2	(0x1U << GPTIMx_CCMR2_IC4PSC_Pos)	/* 01��ÿ2���¼��������һ�β�׽ */
#define	GPTIMx_CCMR2_IC4PSC_DIV4	(0x2U << GPTIMx_CCMR2_IC4PSC_Pos)	/* 10��ÿ4���¼��������һ�β�׽ */
#define	GPTIMx_CCMR2_IC4PSC_DIV8	(0x3U << GPTIMx_CCMR2_IC4PSC_Pos)	/* 11��ÿ8���¼��������һ�β�׽ */

#define	GPTIMx_CCMR2_CC4S_Pos	8	/* ��׽/�Ƚ�4ͨ��ѡ�� (CC4 channel Selection) */
#define	GPTIMx_CCMR2_CC4S_Msk	(0x3U << GPTIMx_CCMR2_CC4S_Pos)
#define	GPTIMx_CCMR2_CC4S_OUT	(0x0U << GPTIMx_CCMR2_CC4S_Pos)	/* 00��CC4ͨ������Ϊ��� */
#define	GPTIMx_CCMR2_CC4S_TI4	(0x1U << GPTIMx_CCMR2_CC4S_Pos)	/* 01��CC4ͨ������Ϊ���룬IC4ӳ�䵽TI4 */
#define	GPTIMx_CCMR2_CC4S_TI3	(0x2U << GPTIMx_CCMR2_CC4S_Pos)	/* 10��CC4ͨ������Ϊ���룬IC4ӳ�䵽TI3 */
#define	GPTIMx_CCMR2_CC4S_TRC	(0x3U << GPTIMx_CCMR2_CC4S_Pos)	/* 11��CC4ͨ������Ϊ���룬IC4ӳ�䵽TRC */

#define	GPTIMx_CCMR2_IC3F_Pos	4	/* ���벶׽3�˲� (IC3 Filter) */
#define	GPTIMx_CCMR2_IC3F_Msk	(0xfU << GPTIMx_CCMR2_IC3F_Pos)

#define	GPTIMx_CCMR2_IC3PSC_Pos	2	/* ���벶׽3Ԥ��Ƶ (IC3 Prescaler) */
#define	GPTIMx_CCMR2_IC3PSC_Msk	(0x3U << GPTIMx_CCMR2_IC3PSC_Pos)
#define	GPTIMx_CCMR2_IC3PSC_DIV1	(0x0U << GPTIMx_CCMR2_IC3PSC_Pos)	/* 00���޷�Ƶ */
#define	GPTIMx_CCMR2_IC3PSC_DIV2	(0x1U << GPTIMx_CCMR2_IC3PSC_Pos)	/* 01��ÿ2���¼��������һ�β�׽ */
#define	GPTIMx_CCMR2_IC3PSC_DIV4	(0x2U << GPTIMx_CCMR2_IC3PSC_Pos)	/* 10��ÿ4���¼��������һ�β�׽ */
#define	GPTIMx_CCMR2_IC3PSC_DIV8	(0x3U << GPTIMx_CCMR2_IC3PSC_Pos)	/* 11��ÿ8���¼��������һ�β�׽ */

#define	GPTIMx_CCMR2_CC3S_Pos	0	/* ��׽/�Ƚ�3ͨ��ѡ�� (CC3 channel Selection) */
#define	GPTIMx_CCMR2_CC3S_Msk	(0x3U << GPTIMx_CCMR2_CC3S_Pos)
#define	GPTIMx_CCMR2_CC3S_OUT	(0x0U << GPTIMx_CCMR2_CC3S_Pos)	/* 00��CC3ͨ������Ϊ��� */
#define	GPTIMx_CCMR2_CC3S_TI3	(0x1U << GPTIMx_CCMR2_CC3S_Pos)	/* 01��CC3ͨ������Ϊ���룬IC1ӳ�䵽TI3 */
#define	GPTIMx_CCMR2_CC3S_TI4	(0x2U << GPTIMx_CCMR2_CC3S_Pos)	/* 10��CC3ͨ������Ϊ���룬IC1ӳ�䵽TI4 */
#define	GPTIMx_CCMR2_CC3S_TRC	(0x3U << GPTIMx_CCMR2_CC3S_Pos)	/* 11��CC3ͨ������Ϊ���룬IC1ӳ�䵽TRC */

#define	GPTIMx_CCER_CC4P_Pos	13	/* ��׽/�Ƚ�4������� (CC4 Polarity) */
#define	GPTIMx_CCER_CC4P_Msk	(0x1U << GPTIMx_CCER_CC4P_Pos)
#define	GPTIMx_CCER_CC4P_HIGH	(0x0U << GPTIMx_CCER_CC4P_Pos)	/* CC4ͨ������Ϊ���ʱ��0��OC4����Ч*/
#define	GPTIMx_CCER_CC4P_LOW	(0x1U << GPTIMx_CCER_CC4P_Pos)	/* 1��OC4����Ч */

#define	GPTIMx_CCER_CC4E_Pos	12	/* ��׽/�Ƚ�4���ʹ�� (CC4 output Enable) */
#define	GPTIMx_CCER_CC4E_Msk	(0x1U << GPTIMx_CCER_CC4E_Pos)
	/* CC4ͨ������Ϊ���ʱ0��OC4����رգ�OCx=0��OCx_EN=0*/
	/* 1��OCx=OCxREF+����ѡ��OCx_EN=1 */

#define	GPTIMx_CCER_CC3P_Pos	9	/* ��׽/�Ƚ�3������� (CC3 Polarity) */
#define	GPTIMx_CCER_CC3P_Msk	(0x1U << GPTIMx_CCER_CC3P_Pos)
#define	GPTIMx_CCER_CC3P_HIGH	(0x0U << GPTIMx_CCER_CC3P_Pos)	/* CC3ͨ������Ϊ���ʱ��0��OC3����Ч*/
#define	GPTIMx_CCER_CC3P_LOW	(0x1U << GPTIMx_CCER_CC3P_Pos)	/* 1��OC3����Ч */

#define	GPTIMx_CCER_CC3E_Pos	8	/* ��׽/�Ƚ�3���ʹ�� (CC3 output Enable) */
#define	GPTIMx_CCER_CC3E_Msk	(0x1U << GPTIMx_CCER_CC3E_Pos)
/* CC3ͨ������Ϊ���ʱ0��OC3����رգ�OCx=0��OCx_EN=0*/
/* 1��OCx=OCxREF+����ѡ��OCx_EN=1 */

#define	GPTIMx_CCER_CC2P_Pos	5	/* ��׽/�Ƚ�2������� (CC2 Polarity) */
#define	GPTIMx_CCER_CC2P_Msk	(0x1U << GPTIMx_CCER_CC2P_Pos)
#define	GPTIMx_CCER_CC2P_HIGH	(0x0U << GPTIMx_CCER_CC2P_Pos)	/* CC2ͨ������Ϊ���ʱ��0��OC2����Ч*/
#define	GPTIMx_CCER_CC2P_LOW	(0x1U << GPTIMx_CCER_CC2P_Pos)	/* 1��OC2����Ч */

#define	GPTIMx_CCER_CC2E_Pos	4	/* ��׽/�Ƚ�2���ʹ�� (CC2 output Enable) */
#define	GPTIMx_CCER_CC2E_Msk	(0x1U << GPTIMx_CCER_CC2E_Pos)
/* CC2ͨ������Ϊ���ʱ0��OC2����رգ�OCx=0��OCx_EN=0*/
/* 1��OCx=OCxREF+����ѡ��OCx_EN=1 */

#define	GPTIMx_CCER_CC1P_Pos	1	/* ��׽/�Ƚ�1������� (CC1 Polarity) */
#define	GPTIMx_CCER_CC1P_Msk	(0x1U << GPTIMx_CCER_CC1P_Pos)
#define	GPTIMx_CCER_CC1P_HIGH	(0x0U << GPTIMx_CCER_CC1P_Pos)	/* CC1ͨ������Ϊ���ʱ��0��OC1����Ч*/
#define	GPTIMx_CCER_CC1P_LOW	(0x1U << GPTIMx_CCER_CC1P_Pos)	/* 1��OC1����Ч */

#define	GPTIMx_CCER_CC1E_Pos	0	/* ��׽/�Ƚ�1���ʹ�� (CC1 output Enable) */
#define	GPTIMx_CCER_CC1E_Msk	(0x1U << GPTIMx_CCER_CC1E_Pos)
/* CC1ͨ������Ϊ���ʱ0��OC1����رգ�OCx=0��OCx_EN=0*/
/* 1��OCx=OCxREF+����ѡ��OCx_EN=1 */

#define	GPTIMx_CNT_CNT_Pos	0	/* ������ֵ (Counter) */
#define	GPTIMx_CNT_CNT_Msk	(0xffffU << GPTIMx_CNT_CNT_Pos)

#define	GPTIMx_PSC_PSC_Pos	0	/* ������ʱ�ӣ�CK_CNT��Ԥ��Ƶֵ (Counter Clock Prescaler) */
#define	GPTIMx_PSC_PSC_Msk	(0xffffU << GPTIMx_PSC_PSC_Pos)

#define	GPTIMx_ARR_ARR_Pos	0	/* �������ʱ���Զ�����ֵ (Auto-Reload Register) */
#define	GPTIMx_ARR_ARR_Msk	(0xffffU << GPTIMx_ARR_ARR_Pos)

#define	GPTIMx_CCR1_CCR1_Pos	0	/* ��׽/�Ƚ�ͨ��1�Ĵ��� (Capture/Compare channel 1 Register) */
#define	GPTIMx_CCR1_CCR1_Msk	(0xffffU << GPTIMx_CCR1_CCR1_Pos)

#define	GPTIMx_CCR2_CCR2_Pos	0	/* ��׽/�Ƚ�ͨ��2�Ĵ��� (Capture/Compare channel 2 Register) */
#define	GPTIMx_CCR2_CCR2_Msk	(0xffffU << GPTIMx_CCR2_CCR2_Pos)

#define	GPTIMx_CCR3_CCR3_Pos	0	/* ��׽/�Ƚ�ͨ��3�Ĵ��� (Capture/Compare channel 3 Register) */
#define	GPTIMx_CCR3_CCR3_Msk	(0xffffU << GPTIMx_CCR3_CCR3_Pos)

#define	GPTIMx_CCR4_CCR4_Pos	0	/* ��׽/�Ƚ�ͨ��4�Ĵ��� (Capture/Compare channel 4 Register) */
#define	GPTIMx_CCR4_CCR4_Msk	(0xffffU << GPTIMx_CCR4_CCR4_Pos)

#define	GPTIMx_DCR_DBL_Pos	8	/* DMA Burst���� (DMA Burst Length) */
#define	GPTIMx_DCR_DBL_Msk	(0x1fU << GPTIMx_DCR_DBL_Pos)
#define	GPTIMx_DCR_DBL_LENG_1	(0x0U << GPTIMx_DCR_DBL_Pos)	/* ��GPTIM_DMAR�Ĵ����Ķ�д������burst DMA������burst����Ϊ1~18 00000������=1 */
#define	GPTIMx_DCR_DBL_LENG_2	(0x1U << GPTIMx_DCR_DBL_Pos)	/* 00001������=2 */
#define	GPTIMx_DCR_DBL_LENG_3	(0x2U << GPTIMx_DCR_DBL_Pos)	/* 00010������=3 */
#define	GPTIMx_DCR_DBL_LENG_4	(0x3U << GPTIMx_DCR_DBL_Pos)	/* 00011������=4 */
#define	GPTIMx_DCR_DBL_LENG_5	(0x4U << GPTIMx_DCR_DBL_Pos)	/* 00100������=5 */
#define	GPTIMx_DCR_DBL_LENG_6	(0x5U << GPTIMx_DCR_DBL_Pos)	/* 00101������=6 */
#define	GPTIMx_DCR_DBL_LENG_7	(0x6U << GPTIMx_DCR_DBL_Pos)	/* 00110������=7 */
#define	GPTIMx_DCR_DBL_LENG_8	(0x7U << GPTIMx_DCR_DBL_Pos)	/* 00111������=8 */
#define	GPTIMx_DCR_DBL_LENG_9	(0x8U << GPTIMx_DCR_DBL_Pos)	/* 01000������=9 */
#define	GPTIMx_DCR_DBL_LENG_10	(0x9U << GPTIMx_DCR_DBL_Pos)	/* 01001������=10 */
#define	GPTIMx_DCR_DBL_LENG_11	(0xaU << GPTIMx_DCR_DBL_Pos)	/* 01010������=11 */
#define	GPTIMx_DCR_DBL_LENG_12	(0xbU << GPTIMx_DCR_DBL_Pos)	/* 01011������=12 */
#define	GPTIMx_DCR_DBL_LENG_13	(0xcU << GPTIMx_DCR_DBL_Pos)	/* 01100������=13 */
#define	GPTIMx_DCR_DBL_LENG_14	(0xdU << GPTIMx_DCR_DBL_Pos)	/* 01101������=14 */
#define	GPTIMx_DCR_DBL_LENG_15	(0xeU << GPTIMx_DCR_DBL_Pos)	/* 01110������=15 */
#define	GPTIMx_DCR_DBL_LENG_16	(0xfU << GPTIMx_DCR_DBL_Pos)	/* 01111������=16 */
#define	GPTIMx_DCR_DBL_LENG_17	(0x10U << GPTIMx_DCR_DBL_Pos)	/* 10000������=17 */
#define	GPTIMx_DCR_DBL_LENG_18	(0x11U << GPTIMx_DCR_DBL_Pos)	/* 10001������=18 */

#define	GPTIMx_DCR_DBA_Pos	0	/* DMA����ַ������ָ��Ĵ�����ƫ�Ƶ�ַ (DMA Burst offset Address) */
#define	GPTIMx_DCR_DBA_Msk	(0x1fU << GPTIMx_DCR_DBA_Pos)
#define	GPTIMx_DCR_DBA_CR1	(0x0U << GPTIMx_DCR_DBA_Pos)	/* 00001��GPTIM_CR1 */
#define	GPTIMx_DCR_DBA_CR2	(0x1U << GPTIMx_DCR_DBA_Pos)	/* 00010��GPTIM_CR2 */
#define	GPTIMx_DCR_DBA_SMCR	(0x2U << GPTIMx_DCR_DBA_Pos)	/* 00011��GPTIM_SMCR */
#define	GPTIMx_DCR_DBA_DIER	(0x3U << GPTIMx_DCR_DBA_Pos)	/* 00100��GPTIM_DIER */
#define	GPTIMx_DCR_DBA_SR	(0x4U << GPTIMx_DCR_DBA_Pos)	/* 00101��GPTIM_SR */
#define	GPTIMx_DCR_DBA_EGR	(0x5U << GPTIMx_DCR_DBA_Pos)	/* 00110��GPTIM_EGR */
#define	GPTIMx_DCR_DBA_CCMR1	(0x6U << GPTIMx_DCR_DBA_Pos)	/* 00111��GPTIM_CCMR1 */
#define	GPTIMx_DCR_DBA_CCMR2	(0x7U << GPTIMx_DCR_DBA_Pos)	/* 01000��GPTIM_CCMR2 */
#define	GPTIMx_DCR_DBA_CCER	(0x8U << GPTIMx_DCR_DBA_Pos)	/* 01001��GPTIM_CCER */
#define	GPTIMx_DCR_DBA_CNT	(0x9U << GPTIMx_DCR_DBA_Pos)	/* 01010��GPTIM_CNT */
#define	GPTIMx_DCR_DBA_PSC	(0xaU << GPTIMx_DCR_DBA_Pos)	/* 01011��GPTIM_PSC */
#define	GPTIMx_DCR_DBA_ARR	(0xbU << GPTIMx_DCR_DBA_Pos)	/* 01100��GPTIM_ARR */
#define	GPTIMx_DCR_DBA_CCR1	(0xcU << GPTIMx_DCR_DBA_Pos)	/* 01101��GPTIM_CCR1 */
#define	GPTIMx_DCR_DBA_CCR2	(0xdU << GPTIMx_DCR_DBA_Pos)	/* 01110��GPTIM_CCR2 */
#define	GPTIMx_DCR_DBA_CCR3	(0xeU << GPTIMx_DCR_DBA_Pos)	/* 01111��GPTIM_CCR3 */
#define	GPTIMx_DCR_DBA_CCR4	(0xfU << GPTIMx_DCR_DBA_Pos)	/* 10000��GPTIM_CCR4 */
#define	GPTIMx_DCR_DBA_DCR	(0x10U << GPTIMx_DCR_DBA_Pos)	/* 10001��GPTIM_DCR */
#define	GPTIMx_DCR_DBA_DMAR	(0x11U << GPTIMx_DCR_DBA_Pos)	/* 10010: GPTIM_DMAR */
#define	GPTIMx_DCR_DBA_ITRSEL	(0x12U << GPTIMx_DCR_DBA_Pos)	/* 10011: GPTIM_ITRSEL */

#define	GPTIMx_DMAR_DMAR_Pos	0	/* DMA burst���ʼĴ��� (DMA Burst Access Register) */
#define	GPTIMx_DMAR_DMAR_Msk	(0xffffU << GPTIMx_DMAR_DMAR_Pos)

#define GPTIMx_ITRSEL_ITR3SEL_Pos         6       /* ITR�����ź�ѡ�� (Internal Trigger Source Selection) */
#define GPTIMx_ITRSEL_ITR3SEL_Msk        (0x3U << GPTIMx_ITRSEL_ITR3SEL_Pos)
#define GPTIM0_ITRSEL_ITR3SEL_COMP1_OUT (0x0U << GPTIMx_ITRSEL_ITR3SEL_Pos)
#define GPTIM0_ITRSEL_ITR3SEL_RC4M      (0x1U << GPTIMx_ITRSEL_ITR3SEL_Pos)
#define GPTIM0_ITRSEL_ITR3SEL_COMP2_OUT (0x2U << GPTIMx_ITRSEL_ITR3SEL_Pos)
#define GPTIM0_ITRSEL_ITR3SEL_LPTOUT1   (0x3U << GPTIMx_ITRSEL_ITR3SEL_Pos)
#define GPTIM1_ITRSEL_ITR3SEL_COMP1_OUT (0x0U << GPTIMx_ITRSEL_ITR3SEL_Pos)
#define GPTIM1_ITRSEL_ITR3SEL_RC4M      (0x1U << GPTIMx_ITRSEL_ITR3SEL_Pos)
#define GPTIM1_ITRSEL_ITR3SEL_COMP2_OUT (0x2U << GPTIMx_ITRSEL_ITR3SEL_Pos)
#define GPTIM1_ITRSEL_ITR3SEL_LPTOUT2   (0x3U << GPTIMx_ITRSEL_ITR3SEL_Pos)

#define GPTIMx_ITRSEL_ITR2SEL_Pos         4       /* ITR�����ź�ѡ�� (Internal Trigger Source Selection) */
#define GPTIMx_ITRSEL_ITR2SEL_Msk        (0x3U << GPTIMx_ITRSEL_ITR2SEL_Pos)
#define GPTIM0_ITRSEL_ITR2SEL_BSTIM_TRGO    (0x0U << GPTIMx_ITRSEL_ITR2SEL_Pos)
#define GPTIM0_ITRSEL_ITR2SEL_LPUART1_RX    (0x1U << GPTIMx_ITRSEL_ITR2SEL_Pos)
#define GPTIM0_ITRSEL_ITR2SEL_RCLP          (0x2U << GPTIMx_ITRSEL_ITR2SEL_Pos)
#define GPTIM0_ITRSEL_ITR2SEL_XTLF          (0x3U << GPTIMx_ITRSEL_ITR2SEL_Pos)
#define GPTIM1_ITRSEL_ITR2SEL_BSTIM_TRGO    (0x0U << GPTIMx_ITRSEL_ITR2SEL_Pos)
#define GPTIM1_ITRSEL_ITR2SEL_LSCLK         (0x1U << GPTIMx_ITRSEL_ITR2SEL_Pos)
#define GPTIM1_ITRSEL_ITR2SEL_RCLP          (0x2U << GPTIMx_ITRSEL_ITR2SEL_Pos)
#define GPTIM1_ITRSEL_ITR2SEL_XTLF          (0x3U << GPTIMx_ITRSEL_ITR2SEL_Pos)

#define GPTIMx_ITRSEL_ITR1SEL_Pos         2       /* ITR�����ź�ѡ�� (Internal Trigger Source Selection) */
#define GPTIMx_ITRSEL_ITR1SEL_Msk        (0x3U << GPTIMx_ITRSEL_ITR1SEL_Pos)
#define GPTIM0_ITRSEL_ITR1SEL_GPTIM1_TRGO   (0x0U << GPTIMx_ITRSEL_ITR1SEL_Pos)
#define GPTIM0_ITRSEL_ITR1SEL_XTHF          (0x1U << GPTIMx_ITRSEL_ITR1SEL_Pos)
#define GPTIM0_ITRSEL_ITR1SEL_RCHF          (0x2U << GPTIMx_ITRSEL_ITR1SEL_Pos)
#define GPTIM0_ITRSEL_ITR1SEL_LPUART0_RX    (0x3U << GPTIMx_ITRSEL_ITR1SEL_Pos)
#define GPTIM1_ITRSEL_ITR1SEL_GPTIM0_TRGO   (0x0U << GPTIMx_ITRSEL_ITR1SEL_Pos)
#define GPTIM1_ITRSEL_ITR1SEL_XTHF          (0x1U << GPTIMx_ITRSEL_ITR1SEL_Pos)
#define GPTIM1_ITRSEL_ITR1SEL_RCHF          (0x2U << GPTIMx_ITRSEL_ITR1SEL_Pos)
#define GPTIM1_ITRSEL_ITR1SEL_ADC_EOC       (0x3U << GPTIMx_ITRSEL_ITR1SEL_Pos)

#define GPTIMx_ITRSEL_ITR0SEL_Pos         0       /* ITR�����ź�ѡ�� (Internal Trigger Source Selection) */
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

/* Dead time�������˲�ʱ��Ƶ�ʷ�Ƶ�Ĵ��������CK_INT�ķ�Ƶ�ȣ�(Counter clocK Divider) ��غ��� */
extern void GPTIMx_CR1_CKD_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CR1_CKD_Get(GPTIM_Type* GPTIMx);

/* Auto-reloadԤװ��ʹ�� (Auto-Reload Preload Enable) ��غ��� */
extern void GPTIMx_CR1_ARPE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CR1_ARPE_Getable(GPTIM_Type* GPTIMx);

/* ����������ģʽѡ�� (Counter Mode Selection) ��غ��� */
extern void GPTIMx_CR1_CMS_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CR1_CMS_Get(GPTIM_Type* GPTIMx);

/* ��������Ĵ��� (counter Direction) ��غ��� */
extern void GPTIMx_CR1_DIR_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CR1_DIR_Get(GPTIM_Type* GPTIMx);

/* ���������ģʽ (One Pulse Mode) ��غ��� */
extern void GPTIMx_CR1_OPM_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CR1_OPM_Getable(GPTIM_Type* GPTIMx);

/* ��������ѡ�� (Update Request Selection) ��غ��� */
extern void GPTIMx_CR1_URS_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CR1_URS_Getable(GPTIM_Type* GPTIMx);

/* ��ֹupdate (Update Disable) ��غ��� */
extern void GPTIMx_CR1_UDIS_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CR1_UDIS_Getable(GPTIM_Type* GPTIMx);

/* ������ʹ�� (Counter Enable) ��غ��� */
extern void GPTIMx_CR1_CEN_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CR1_CEN_Getable(GPTIM_Type* GPTIMx);

/* ͨ��1����Դѡ�� (Timer Input 1 Selection) ��غ��� */
extern void GPTIMx_CR2_TI1S_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CR2_TI1S_Get(GPTIM_Type* GPTIMx);

/* ����ģʽѡ��������������ģʽ����ӻ����͵�ͬ�������źţ�TRGO��Դ (Master Mode Selection) ��غ��� */
extern void GPTIMx_CR2_MMS_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CR2_MMS_Get(GPTIM_Type* GPTIMx);

/* ��׽/�Ƚ� DMAѡ�� (Capture/Compare DMA Selection) ��غ��� */
extern void GPTIMx_CR2_CCDS_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CR2_CCDS_Get(GPTIM_Type* GPTIMx);

/* �ⲿ�����źż������� (External Trigger Polarity) ��غ��� */
extern void GPTIMx_SMCR_ETP_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_SMCR_ETP_Get(GPTIM_Type* GPTIMx);

/* �ⲿʱ��ʹ�� (External Clock Enable) ��غ��� */
extern void GPTIMx_SMCR_ECE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_SMCR_ECE_Getable(GPTIM_Type* GPTIMx);

/* �ⲿ�����ź�Ԥ��Ƶ�Ĵ��� (External Trigger Prescaler)
�ⲿ�����ź�ETRP��Ƶ�����ֻ����GPTIM����ʱ�ӵ�1/4���������ź�Ƶ�ʽϸ�ʱ������ʹ��Ԥ��Ƶ ��غ��� */
extern void GPTIMx_SMCR_ETPS_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_SMCR_ETPS_Get(GPTIM_Type* GPTIMx);

/* �ⲿ�����ź��˲�ʱ�Ӻͳ���ѡ�� (External Trigger Filter) ��غ��� */
extern void GPTIMx_SMCR_ETF_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_SMCR_ETF_Get(GPTIM_Type* GPTIMx);

/* ��/��ģʽ (Master Slave Mode) ��غ��� */
extern void GPTIMx_SMCR_MSM_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_SMCR_MSM_Get(GPTIM_Type* GPTIMx);

/* ����ѡ������ѡ��ͬ���������Ĵ���Դ (Trigger Source) ��غ��� */
extern void GPTIMx_SMCR_TS_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_SMCR_TS_Get(GPTIM_Type* GPTIMx);

/* �ӻ�ģʽѡ�� (Slave Mode Selection) ��غ��� */
extern void GPTIMx_SMCR_SMS_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_SMCR_SMS_Get(GPTIM_Type* GPTIMx);

/* ��׽�Ƚ�ͨ��4��DMAģʽ���� (CC4 Burst Enable) ��غ��� */
extern void GPTIMx_DIER_CC4BURSTEN_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_DIER_CC4BURSTEN_Get(GPTIM_Type* GPTIMx);

/* ��׽�Ƚ�ͨ��3��DMAģʽ���� (CC3 Burst Enable) ��غ��� */
extern void GPTIMx_DIER_CC3BURSTEN_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_DIER_CC3BURSTEN_Get(GPTIM_Type* GPTIMx);

/* ��׽�Ƚ�ͨ��2��DMAģʽ���� (CC2 Burst Enable) ��غ��� */
extern void GPTIMx_DIER_CC2BURSTEN_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_DIER_CC2BURSTEN_Get(GPTIM_Type* GPTIMx);

/* ��׽�Ƚ�ͨ��1��DMAģʽ���� (CC1 Burst Enable) ��غ��� */
extern void GPTIMx_DIER_CC1BURSTEN_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_DIER_CC1BURSTEN_Get(GPTIM_Type* GPTIMx);

/* �ⲿ����DMA����ʹ�� (Triggered DMA Enable) ��غ��� */
extern void GPTIMx_DIER_TDE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_DIER_TDE_Getable(GPTIM_Type* GPTIMx);

/* ��׽�Ƚ�ͨ��4��DMA����ʹ�� (CC4 DMA Enable) ��غ��� */
extern void GPTIMx_DIER_CC4DE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_DIER_CC4DE_Getable(GPTIM_Type* GPTIMx);

/* ��׽�Ƚ�ͨ��3��DMA����ʹ�� (CC3 DMA Enable) ��غ��� */
extern void GPTIMx_DIER_CC3DE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_DIER_CC3DE_Getable(GPTIM_Type* GPTIMx);

/* ��׽�Ƚ�ͨ��2��DMA����ʹ�� (CC2 DMA Enable) ��غ��� */
extern void GPTIMx_DIER_CC2DE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_DIER_CC2DE_Getable(GPTIM_Type* GPTIMx);

/* ��׽�Ƚ�ͨ��1��DMA����ʹ�� (CC1 DMA Enable) ��غ��� */
extern void GPTIMx_DIER_CC1DE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_DIER_CC1DE_Getable(GPTIM_Type* GPTIMx);

/* Update Event DMA����ʹ�� (Update event DMA Enable) ��غ��� */
extern void GPTIMx_DIER_UDE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_DIER_UDE_Getable(GPTIM_Type* GPTIMx);

/* �����¼��ж�ʹ�� (Trigger event Interrupt Enable) ��غ��� */
extern void GPTIMx_DIER_TIE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_DIER_TIE_Getable(GPTIM_Type* GPTIMx);

/* ��׽/�Ƚ�ͨ��4�ж�ʹ�� (CC4 Interrupt Enable) ��غ��� */
extern void GPTIMx_DIER_CC4IE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_DIER_CC4IE_Getable(GPTIM_Type* GPTIMx);

/* ��׽/�Ƚ�ͨ��3�ж�ʹ�� (CC3 Interrupt Enable) ��غ��� */
extern void GPTIMx_DIER_CC3IE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_DIER_CC3IE_Getable(GPTIM_Type* GPTIMx);

/* ��׽/�Ƚ�ͨ��2�ж�ʹ�� (CC2 Interrupt Enable) ��غ��� */
extern void GPTIMx_DIER_CC2IE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_DIER_CC2IE_Getable(GPTIM_Type* GPTIMx);

/* ��׽/�Ƚ�ͨ��1�ж�ʹ�� (CC1 Interrupt Enable) ��غ��� */
extern void GPTIMx_DIER_CC1IE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_DIER_CC1IE_Getable(GPTIM_Type* GPTIMx);

/* Update�¼��ж�ʹ�� (Update event Interrupt Enable) ��غ��� */
extern void GPTIMx_DIER_UIE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_DIER_UIE_Getable(GPTIM_Type* GPTIMx);

/* ��׽/�Ƚ�ͨ��4��Overcapture�ж� (Over-Capture Interrupt Flag for CC4) ��غ��� */
extern void GPTIMx_ISR_CC4OF_Clr(GPTIM_Type* GPTIMx);
extern FlagStatus GPTIMx_ISR_CC4OF_Chk(GPTIM_Type* GPTIMx);

/* ��׽/�Ƚ�ͨ��3��Overcapture�ж� (Over-Capture Interrupt Flag for CC3) ��غ��� */
extern void GPTIMx_ISR_CC3OF_Clr(GPTIM_Type* GPTIMx);
extern FlagStatus GPTIMx_ISR_CC3OF_Chk(GPTIM_Type* GPTIMx);

/* ��׽/�Ƚ�ͨ��2��Overcapture�ж� (Over-Capture Interrupt Flag for CC2) ��غ��� */
extern void GPTIMx_ISR_CC2OF_Clr(GPTIM_Type* GPTIMx);
extern FlagStatus GPTIMx_ISR_CC2OF_Chk(GPTIM_Type* GPTIMx);

/* ��׽/�Ƚ�ͨ��1��Overcapture�ж� (Over-Capture Interrupt Flag for CC1) ��غ��� */
extern void GPTIMx_ISR_CC1OF_Clr(GPTIM_Type* GPTIMx);
extern FlagStatus GPTIMx_ISR_CC1OF_Chk(GPTIM_Type* GPTIMx);

/* �����¼��жϱ�־ ��غ��� */
extern void GPTIMx_ISR_TIF_Clr(GPTIM_Type* GPTIMx);
extern FlagStatus GPTIMx_ISR_TIF_Chk(GPTIM_Type* GPTIMx);

/* ��׽/�Ƚ�ͨ��4�жϱ�־ (CC4 Interrupt Flag) ��غ��� */
extern void GPTIMx_ISR_CC4IF_Clr(GPTIM_Type* GPTIMx);
extern FlagStatus GPTIMx_ISR_CC4IF_Chk(GPTIM_Type* GPTIMx);

/* ��׽/�Ƚ�ͨ��3�жϱ�־ (CC3 Interrupt Flag) ��غ��� */
extern void GPTIMx_ISR_CC3IF_Clr(GPTIM_Type* GPTIMx);
extern FlagStatus GPTIMx_ISR_CC3IF_Chk(GPTIM_Type* GPTIMx);

/* ��׽/�Ƚ�ͨ��2�жϱ�־ (CC2 Interrupt Flag) ��غ��� */
extern void GPTIMx_ISR_CC2IF_Clr(GPTIM_Type* GPTIMx);
extern FlagStatus GPTIMx_ISR_CC2IF_Chk(GPTIM_Type* GPTIMx);

/* ��׽/�Ƚ�ͨ��1�жϱ�־ (CC1 Interrupt Flag) ��غ��� */
extern void GPTIMx_ISR_CC1IF_Clr(GPTIM_Type* GPTIMx);
extern FlagStatus GPTIMx_ISR_CC1IF_Chk(GPTIM_Type* GPTIMx);

/* Update�¼��жϱ�־��Ӳ����λ�����д1���㡣(Update event Interrupt Flag) ��غ��� */
extern void GPTIMx_ISR_UIF_Clr(GPTIM_Type* GPTIMx);
extern FlagStatus GPTIMx_ISR_UIF_Chk(GPTIM_Type* GPTIMx);

/* ��������������λ�˼Ĵ������������¼���Ӳ���Զ����� (Trigger Generate) ��غ��� */
extern void GPTIMx_EGR_TG_Setable(GPTIM_Type* GPTIMx, FunState NewState);

/* ��׽/�Ƚ�ͨ��4������� (CC4 Generate) ��غ��� */
extern void GPTIMx_EGR_CC4G_Setable(GPTIM_Type* GPTIMx, FunState NewState);

/* ��׽/�Ƚ�ͨ��3������� (CC3 Generate) ��غ��� */
extern void GPTIMx_EGR_CC3G_Setable(GPTIM_Type* GPTIMx, FunState NewState);

/* ��׽/�Ƚ�ͨ��2������� (CC2 Generate) ��غ��� */
extern void GPTIMx_EGR_CC2G_Setable(GPTIM_Type* GPTIMx, FunState NewState);

/* ��׽/�Ƚ�ͨ��1������� (CC1 Generate) ��غ��� */
extern void GPTIMx_EGR_CC1G_Setable(GPTIM_Type* GPTIMx, FunState NewState);

/* ���Update�¼��������λ�˼Ĵ�������Update�¼���Ӳ���Զ����� (User Generate) ��غ��� */
extern void GPTIMx_EGR_UG_Setable(GPTIM_Type* GPTIMx, FunState NewState);

/* ����Ƚ�2����ʹ�� (OC2 Clear Enable) ��غ��� */
extern void GPTIMx_CCMR1_OC2CE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CCMR1_OC2CE_Getable(GPTIM_Type* GPTIMx);

/* ����Ƚ�2ģʽ���ã��˼Ĵ�������OC2REF�źŵ���Ϊ (OC2 Mode) ��غ��� */
extern void GPTIMx_CCMR1_OC2M_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCMR1_OC2M_Get(GPTIM_Type* GPTIMx);

/* ����Ƚ�2Ԥװ��ʹ�� (OC2 Preload Enable) ��غ��� */
extern void GPTIMx_CCMR1_OC2PE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CCMR1_OC2PE_Getable(GPTIM_Type* GPTIMx);

/* ����Ƚ�2����ʹ�� (OC2 Fast Enable) ��غ��� */
extern void GPTIMx_CCMR1_OC2FE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CCMR1_OC2FE_Getable(GPTIM_Type* GPTIMx);

/* ��׽/�Ƚ�2ͨ��ѡ�� (CC2 channel Selection) ��غ��� */
extern void GPTIMx_CCMR1_CC2S_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCMR1_CC2S_Get(GPTIM_Type* GPTIMx);

/* ����Ƚ�1����ʹ�� (OC2 Clear Enable) ��غ��� */
extern void GPTIMx_CCMR1_OC1CE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CCMR1_OC1CE_Getable(GPTIM_Type* GPTIMx);

/* ����Ƚ�1ģʽ���ã��˼Ĵ�������OC1REF�źŵ���Ϊ (OC1 Mode) ��غ��� */
extern void GPTIMx_CCMR1_OC1M_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCMR1_OC1M_Get(GPTIM_Type* GPTIMx);

/* ����Ƚ�1Ԥװ��ʹ�� (OC1 Preload Enable) ��غ��� */
extern void GPTIMx_CCMR1_OC1PE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CCMR1_OC1PE_Getable(GPTIM_Type* GPTIMx);

/* ����Ƚ�1����ʹ�� (OC1 Fast Enable) ��غ��� */
extern void GPTIMx_CCMR1_OC1FE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CCMR1_OC1FE_Getable(GPTIM_Type* GPTIMx);

/* ��׽/�Ƚ�1ͨ��ѡ�� (CC1 channel Selection) ��غ��� */
extern void GPTIMx_CCMR1_CC1S_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCMR1_CC1S_Get(GPTIM_Type* GPTIMx);

/* ���벶׽2�˲� (IC2 Filter) ��غ��� */
extern void GPTIMx_CCMR1_IC2F_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCMR1_IC2F_Get(GPTIM_Type* GPTIMx);

/* ���벶׽2Ԥ��Ƶ (IC2 Prescaler) ��غ��� */
extern void GPTIMx_CCMR1_IC2PSC_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCMR1_IC2PSC_Get(GPTIM_Type* GPTIMx);

/* ���벶׽1�˲� (IC1 Filter) ��غ��� */
extern void GPTIMx_CCMR1_IC1F_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCMR1_IC1F_Get(GPTIM_Type* GPTIMx);

/* ���벶׽1Ԥ��Ƶ (IC1 Prescaler) ��غ��� */
extern void GPTIMx_CCMR1_IC1PSC_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCMR1_IC1PSC_Get(GPTIM_Type* GPTIMx);

/* ����Ƚ�4����ʹ�� (OC4 Clear Enable) ��غ��� */
extern void GPTIMx_CCMR2_OC4CE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CCMR2_OC4CE_Getable(GPTIM_Type* GPTIMx);

/* ����Ƚ�4ģʽ���ã��˼Ĵ�������OC4REF�źŵ���Ϊ (OC4 Mode) ��غ��� */
extern void GPTIMx_CCMR2_OC4M_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCMR2_OC4M_Get(GPTIM_Type* GPTIMx);

/* ����Ƚ�4Ԥװ��ʹ�� (OC4 Preload Enable) ��غ��� */
extern void GPTIMx_CCMR2_OC4PE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CCMR2_OC4PE_Getable(GPTIM_Type* GPTIMx);

/* ����Ƚ�4����ʹ�� (OC4 Fast Enable) ��غ��� */
extern void GPTIMx_CCMR2_OC4FE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CCMR2_OC4FE_Getable(GPTIM_Type* GPTIMx);

/* ��׽/�Ƚ�4ͨ��ѡ�� (CC4 channel Selection) ��غ��� */
extern void GPTIMx_CCMR2_CC4S_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCMR2_CC4S_Get(GPTIM_Type* GPTIMx);

/* ����Ƚ�3����ʹ�� (OC3 Clear Enable) ��غ��� */
extern void GPTIMx_CCMR2_OC3CE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CCMR2_OC3CE_Getable(GPTIM_Type* GPTIMx);

/* ����Ƚ�3ģʽ���ã��˼Ĵ�������OC3REF�źŵ���Ϊ (OC3 Mode) ��غ��� */
extern void GPTIMx_CCMR2_OC3M_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCMR2_OC3M_Get(GPTIM_Type* GPTIMx);

/* ����Ƚ�3Ԥװ��ʹ�� (OC3 Preload Enable) ��غ��� */
extern void GPTIMx_CCMR2_OC3PE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CCMR2_OC3PE_Getable(GPTIM_Type* GPTIMx);

/* ����Ƚ�3����ʹ�� (OC3 Fast Enable) ��غ��� */
extern void GPTIMx_CCMR2_OC3FE_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CCMR2_OC3FE_Getable(GPTIM_Type* GPTIMx);

/* ��׽/�Ƚ�3ͨ��ѡ�� (CC3 channel Selection) ��غ��� */
extern void GPTIMx_CCMR2_CC3S_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCMR2_CC3S_Get(GPTIM_Type* GPTIMx);

/* ���벶׽4�˲� (IC4 Filter) ��غ��� */
extern void GPTIMx_CCMR2_IC4F_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCMR2_IC4F_Get(GPTIM_Type* GPTIMx);

/* ���벶׽4Ԥ��Ƶ (IC4 Prescaler) ��غ��� */
extern void GPTIMx_CCMR2_IC4PSC_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCMR2_IC4PSC_Get(GPTIM_Type* GPTIMx);

/* ���벶׽3�˲� (IC3 Filter) ��غ��� */
extern void GPTIMx_CCMR2_IC3F_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCMR2_IC3F_Get(GPTIM_Type* GPTIMx);

/* ���벶׽3Ԥ��Ƶ (IC3 Prescaler) ��غ��� */
extern void GPTIMx_CCMR2_IC3PSC_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCMR2_IC3PSC_Get(GPTIM_Type* GPTIMx);

/* ��׽/�Ƚ�4������� (CC4 Polarity) ��غ��� */
extern void GPTIMx_CCER_CC4P_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCER_CC4P_Get(GPTIM_Type* GPTIMx);

/* ��׽/�Ƚ�4���ʹ�� (CC4 output Enable) ��غ��� */
extern void GPTIMx_CCER_CC4E_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CCER_CC4E_Getable(GPTIM_Type* GPTIMx);

/* ��׽/�Ƚ�3������� (CC3 Polarity) ��غ��� */
extern void GPTIMx_CCER_CC3P_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCER_CC3P_Get(GPTIM_Type* GPTIMx);

/* ��׽/�Ƚ�3���ʹ�� (CC3 output Enable) ��غ��� */
extern void GPTIMx_CCER_CC3E_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CCER_CC3E_Getable(GPTIM_Type* GPTIMx);

/* ��׽/�Ƚ�2������� (CC2 Polarity) ��غ��� */
extern void GPTIMx_CCER_CC2P_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCER_CC2P_Get(GPTIM_Type* GPTIMx);

/* ��׽/�Ƚ�2���ʹ�� (CC2 output Enable) ��غ��� */
extern void GPTIMx_CCER_CC2E_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CCER_CC2E_Getable(GPTIM_Type* GPTIMx);

/* ��׽/�Ƚ�1������� (CC1 Polarity) ��غ��� */
extern void GPTIMx_CCER_CC1P_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCER_CC1P_Get(GPTIM_Type* GPTIMx);

/* ��׽/�Ƚ�1���ʹ�� (CC1 output Enable) ��غ��� */
extern void GPTIMx_CCER_CC1E_Setable(GPTIM_Type* GPTIMx, FunState NewState);
extern FunState GPTIMx_CCER_CC1E_Getable(GPTIM_Type* GPTIMx);

/* ������ֵ (Counter) ��غ��� */
extern void GPTIMx_CNT_Write(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CNT_Read(GPTIM_Type* GPTIMx);

/* ������ʱ�ӣ�CK_CNT��Ԥ��Ƶֵ (Counter Clock Prescaler) ��غ��� */
extern void GPTIMx_PSC_Write(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_PSC_Read(GPTIM_Type* GPTIMx);

/* �������ʱ���Զ�����ֵ (Auto-Reload Register) ��غ��� */
extern void GPTIMx_ARR_Write(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_ARR_Read(GPTIM_Type* GPTIMx);

/* ��׽/�Ƚ�ͨ��1�Ĵ��� (Capture/Compare channel 1 Register) ��غ��� */
extern void GPTIMx_CCR1_Write(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCR1_Read(GPTIM_Type* GPTIMx);

/* ��׽/�Ƚ�ͨ��2�Ĵ��� (Capture/Compare channel 2 Register) ��غ��� */
extern void GPTIMx_CCR2_Write(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCR2_Read(GPTIM_Type* GPTIMx);

/* ��׽/�Ƚ�ͨ��3�Ĵ��� (Capture/Compare channel 3 Register) ��غ��� */
extern void GPTIMx_CCR3_Write(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCR3_Read(GPTIM_Type* GPTIMx);

/* ��׽/�Ƚ�ͨ��4�Ĵ��� (Capture/Compare channel 4 Register) ��غ��� */
extern void GPTIMx_CCR4_Write(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_CCR4_Read(GPTIM_Type* GPTIMx);

/* DMA Burst���� (DMA Burst Length) ��غ��� */
extern void GPTIMx_DCR_DBL_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_DCR_DBL_Get(GPTIM_Type* GPTIMx);

/* DMA����ַ������ָ��Ĵ�����ƫ�Ƶ�ַ (DMA Burst offset Address) ��غ��� */
extern void GPTIMx_DCR_DBA_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_DCR_DBA_Get(GPTIM_Type* GPTIMx);

/* DMA burst���ʼĴ��� (DMA Burst Access Register) ��غ��� */
extern void GPTIMx_DMAR_Write(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_DMAR_Read(GPTIM_Type* GPTIMx);

/* ITR�����ź�ѡ�� (Internal Trigger Source Selection) ��غ��� */
extern void GPTIMx_ITRSEL_ITR3SEL_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_ITRSEL_ITR3SEL_Get(GPTIM_Type* GPTIMx);

/* ITR�����ź�ѡ�� (Internal Trigger Source Selection) ��غ��� */
extern void GPTIMx_ITRSEL_ITR2SEL_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_ITRSEL_ITR2SEL_Get(GPTIM_Type* GPTIMx);

/* ITR�����ź�ѡ�� (Internal Trigger Source Selection) ��غ��� */
extern void GPTIMx_ITRSEL_ITR1SEL_Set(GPTIM_Type* GPTIMx, uint32_t SetValue);
extern uint32_t GPTIMx_ITRSEL_ITR1SEL_Get(GPTIM_Type* GPTIMx);

/* ITR�����ź�ѡ�� (Internal Trigger Source Selection) ��غ��� */
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
