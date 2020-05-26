/**
  ******************************************************************************
  * @file    fm33l0xx_i2c.h
  * @author  FM33L0xx Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file contains all the functions prototypes for the I2C firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33L0XX_I2C_H
#define __FM33L0XX_I2C_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33L0XX.h" 

//-----------------------------------------------------------------------------------------------------------------------------
#define I2C_SEND_STARTBIT()			I2C_MSP_CR_SEN_Setable(ENABLE)
#define I2C_SEND_RESTARTBIT()		I2C_MSP_CR_RSEN_Setable(ENABLE)
#define I2C_SEND_STOPBIT()			I2C_MSP_CR_PEN_Setable(ENABLE)
	 
#define I2C_SEND_ACK_0()				I2C_MSP_SR_ACKMO_Set(I2C_MSP_SR_ACKMO_RESET)
#define I2C_SEND_ACK_1()				I2C_MSP_SR_ACKMO_Set(I2C_MSP_SR_ACKMO_SET)
	 
	 
#define	I2C_MSP_CFGR_AUTOEND_Pos	17	/* ����DMA�Զ���ֹ */
#define	I2C_MSP_CFGR_AUTOEND_Msk	(0x1U << I2C_MSP_CFGR_AUTOEND_Pos)
#define	I2C_MSP_CFGR_AUTOEND_WAIT	(0x0U << I2C_MSP_CFGR_AUTOEND_Pos)	/* 1��DMAָ�����ȴ�����ɺ��Զ�����STOPʱ�� */
#define	I2C_MSP_CFGR_AUTOEND_AUTOEND	(0x1U << I2C_MSP_CFGR_AUTOEND_Pos)	/* 0��DMAָ�����ȴ�����ɺ󣬵ȴ�����ӹ� */

#define	I2C_MSP_CFGR_MSP_DMAEN_Pos	16	/* ����DMAʹ�� */
#define	I2C_MSP_CFGR_MSP_DMAEN_Msk	(0x1U << I2C_MSP_CFGR_MSP_DMAEN_Pos)
	/* 0���ر�DMA���� */
	/* 1��ʹ��DMA���� */

#define	I2C_MSP_CFGR_TOEN_Pos	1	/* SCL���ͳ�ʱʹ�� */
#define	I2C_MSP_CFGR_TOEN_Msk	(0x1U << I2C_MSP_CFGR_TOEN_Pos)
	/* 0���رճ�ʱ���� */
	/* 1��ʹ�ܳ�ʱ���� */

#define	I2C_MSP_CFGR_MSPEN_Pos	0	/* I2C����ģ��ʹ�ܿ���λ */
#define	I2C_MSP_CFGR_MSPEN_Msk	(0x1U << I2C_MSP_CFGR_MSPEN_Pos)
	/* 0 = I2C������ֹ */
	/* 1 = I2C����ʹ�� */

#define	I2C_MSP_CR_RCEN_Pos	3	/* ��������ģʽ�£�����ʹ��λ */
#define	I2C_MSP_CR_RCEN_Msk	(0x1U << I2C_MSP_CR_RCEN_Pos)
	/* 0�����ս�ֹ */
	/* 1����������ʹ�� */

#define	I2C_MSP_CR_PEN_Pos	2	/* STOPʱ�����ʹ�ܿ���λ */
#define	I2C_MSP_CR_PEN_Msk	(0x1U << I2C_MSP_CR_PEN_Pos)
	/* 0��ʹ�ܽ�ֹ */
	/* 1:����STOPʱ��ʹ�� */

#define	I2C_MSP_CR_RSEN_Pos	1	/* Repeated STARTʱ�����ʹ�ܿ���λ */
#define	I2C_MSP_CR_RSEN_Msk	(0x1U << I2C_MSP_CR_RSEN_Pos)
	/* 0��ʹ�ܽ�ֹ */
	/* 1:�����ظ�STARTʱ��ʹ�� */

#define	I2C_MSP_CR_SEN_Pos	0	/* STARTʱ�����ʹ�ܿ���λ */
#define	I2C_MSP_CR_SEN_Msk	(0x1U << I2C_MSP_CR_SEN_Pos)
	/* 0��ʹ�ܽ�ֹ */
	/* 1:����STARTʱ��ʹ�� */

#define	I2C_MSP_IER_WCOLE_Pos	6	/* WCOL�ж�ʹ�ܼĴ��� */
#define	I2C_MSP_IER_WCOLE_Msk	(0x1U << I2C_MSP_IER_WCOLE_Pos)
	/* 0����ֹд��ͻ�ж� */
	/* 1������д��ͻ�ж� */

#define	I2C_MSP_IER_OVTE_Pos	5	/* SCL��ʱ�ж�ʹ�ܼĴ��� */
#define	I2C_MSP_IER_OVTE_Msk	(0x1U << I2C_MSP_IER_OVTE_Pos)
	/* 0����ֹ��ʱ�ж� */
	/* 1������ʱ�ж� */

#define	I2C_MSP_IER_SE_Pos	4	/* STARTʱ���ж�ʹ�ܼĴ��� */
#define	I2C_MSP_IER_SE_Msk	(0x1U << I2C_MSP_IER_SE_Pos)
	/* 0����ֹSTARTʱ���ж� */
	/* 1������STARTʱ���ж� */

#define	I2C_MSP_IER_PE_Pos	3	/* STOPʱ���ж�ʹ�ܼĴ��� */
#define	I2C_MSP_IER_PE_Msk	(0x1U << I2C_MSP_IER_PE_Pos)
	/* 0����ֹSTOPʱ���ж� */
	/* 1������STOPʱ���ж� */

#define	I2C_MSP_IER_NACKE_Pos	2	/* ��������ģʽ��NACK�ж�ʹ�ܼĴ��� */
#define	I2C_MSP_IER_NACKE_Msk	(0x1U << I2C_MSP_IER_NACKE_Pos)
	/* 0����ֹ����NACK�ж� */
	/* 1�������յ�NACK�����ж� */

#define	I2C_MSP_IER_TXIE_Pos	1	/* I2C������������ж�ʹ�� */
#define	I2C_MSP_IER_TXIE_Msk	(0x1U << I2C_MSP_IER_TXIE_Pos)
	/* 0����ֹ��������ж� */
	/* 1������������ж� */

#define	I2C_MSP_IER_RXIE_Pos	0	/* I2C������������ж�ʹ�� */
#define	I2C_MSP_IER_RXIE_Msk	(0x1U << I2C_MSP_IER_RXIE_Pos)
	/* 0����ֹ��������ж� */
	/* 1�������������ж� */

#define	I2C_MSP_ISR_WCOL_Pos	6	/* д��ͻ���λ */
#define	I2C_MSP_ISR_WCOL_Msk	(0x1U << I2C_MSP_ISR_WCOL_Pos)

#define	I2C_MSP_ISR_OVT_Pos	5	/* SCL��ʱ�жϱ�־ */
#define	I2C_MSP_ISR_OVT_Msk	(0x1U << I2C_MSP_ISR_OVT_Pos)

#define	I2C_MSP_ISR_S_Pos	4	/* STARTʱ��������жϱ�־ */
#define	I2C_MSP_ISR_S_Msk	(0x1U << I2C_MSP_ISR_S_Pos)

#define	I2C_MSP_ISR_P_Pos	3	/* STOPʱ��������жϱ�־ */
#define	I2C_MSP_ISR_P_Msk	(0x1U << I2C_MSP_ISR_P_Pos)

#define	I2C_MSP_ISR_ACKSTA_Pos	2	/* ���ط���ģʽ�£����Դӻ��Ļ�Ӧ�ź� */
#define	I2C_MSP_ISR_ACKSTA_Msk	(0x1U << I2C_MSP_ISR_ACKSTA_Pos)

#define	I2C_MSP_ISR_TXIF_Pos	1	/* I2C������������жϱ�־ */
#define	I2C_MSP_ISR_TXIF_Msk	(0x1U << I2C_MSP_ISR_TXIF_Pos)

#define	I2C_MSP_ISR_RXIF_Pos	0	/* I2C������������жϱ�־ */
#define	I2C_MSP_ISR_RXIF_Msk	(0x1U << I2C_MSP_ISR_RXIF_Pos)

#define	I2C_MSP_SR_BUSY_Pos	5	/* I2Cͨ��״̬λ */
#define	I2C_MSP_SR_BUSY_Msk	(0x1U << I2C_MSP_SR_BUSY_Pos)

#define	I2C_MSP_SR_RW_Pos	4	/* I2C���䷽��״̬λ */
#define	I2C_MSP_SR_RW_Msk	(0x1U << I2C_MSP_SR_RW_Pos)

#define	I2C_MSP_SR_BF_Pos	2	/* ��������״̬λ */
#define	I2C_MSP_SR_BF_Msk	(0x1U << I2C_MSP_SR_BF_Pos)

#define	I2C_MSP_SR_ACKMO_Pos	0	/* ���ؽ���ģʽ�£�������Ӧ�źŵ�״̬ */
#define	I2C_MSP_SR_ACKMO_Msk	(0x1U << I2C_MSP_SR_ACKMO_Pos)
#define	I2C_MSP_SR_ACKMO_RESET	(0x0U << I2C_MSP_SR_ACKMO_Pos)	/* 0�������ط�ACK */
#define	I2C_MSP_SR_ACKMO_SET	(0x1U << I2C_MSP_SR_ACKMO_Pos)	/* 1�������ط�NACK */

#define	I2C_MSP_BGR_MSPBRGH_Pos	16	/* �������͵�SCLʱ�Ӹߵ�ƽ��� */
#define	I2C_MSP_BGR_MSPBRGH_Msk	(0x1ffU << I2C_MSP_BGR_MSPBRGH_Pos)

#define	I2C_MSP_BGR_MSPBRGL_Pos	0	/* �������͵�SCLʱ�ӵ͵�ƽ��� */
#define	I2C_MSP_BGR_MSPBRGL_Msk	(0x1ffU << I2C_MSP_BGR_MSPBRGL_Pos)

#define	I2C_MSP_BUF_MSPBUF_Pos	0	/* I2C�����շ�����Ĵ��� */
#define	I2C_MSP_BUF_MSPBUF_Msk	(0xffU << I2C_MSP_BUF_MSPBUF_Pos)

#define	I2C_MSP_TCR_SDAHD_Pos	0	/* I2C����ʱ����ƼĴ��� */
#define	I2C_MSP_TCR_SDAHD_Msk	(0x1ffU << I2C_MSP_TCR_SDAHD_Pos)

#define	I2C_MSP_TOR_TIMEOUT_Pos	0	/* I2C������ʱ�Ĵ��� */
#define	I2C_MSP_TOR_TIMEOUT_Msk	(0xfffU << I2C_MSP_TOR_TIMEOUT_Pos)

#define	I2C_SSP_CR_SCLSEN_Pos	9	/* I2C�ӻ�ʱ����չʹ�� */
#define	I2C_SSP_CR_SCLSEN_Msk	(0x1U << I2C_SSP_CR_SCLSEN_Pos)
	/* 0����ֹ */
	/* 1��ʹ�� */

#define	I2C_SSP_CR_SSP_DMAEN_Pos	8	/* I2C�ӻ�DMAʹ�� */
#define	I2C_SSP_CR_SSP_DMAEN_Msk	(0x1U << I2C_SSP_CR_SSP_DMAEN_Pos)
	/* 0���ر�DMA���� */
	/* 1��ʹ��DMA���� */

#define	I2C_SSP_CR_ACKEN_Pos	4	/* ACKʹ��λ */
#define	I2C_SSP_CR_ACKEN_Msk	(0x1U << I2C_SSP_CR_ACKEN_Pos)
	/* 0:slave���ط�ACK */
	/* 1:slave������ɺ󽫻ط�ACK */

#define	I2C_SSP_CR_SDAO_DLYEN_Pos	3	/* SDA�ӻ�����ӳ�ʹ�� */
#define	I2C_SSP_CR_SDAO_DLYEN_Msk	(0x1U << I2C_SSP_CR_SDAO_DLYEN_Pos)
	/* 0��bypass�ӻ�SDA����ӳ� */
	/* 1��ʹ�ܴӻ�SDA����ӳ� */

#define	I2C_SSP_CR_SCLI_ANFEN_Pos	2	/* SCL�ӻ�����ģ���˲�ʹ�� */
#define	I2C_SSP_CR_SCLI_ANFEN_Msk	(0x1U << I2C_SSP_CR_SCLI_ANFEN_Pos)
	/* 0��bypassģ���˲� */
	/* 1��ʹ��ģ���˲� */

#define	I2C_SSP_CR_A10EN_Pos	1	/* 10λ��ַʹ�� */
#define	I2C_SSP_CR_A10EN_Msk	(0x1U << I2C_SSP_CR_A10EN_Pos)
	/* 0:slaveʹ��7bit address */
	/* 1:slaveʹ��10bit address */

#define	I2C_SSP_CR_SSPEN_Pos	0	/* I2C�ӻ�ʹ��λ */
#define	I2C_SSP_CR_SSPEN_Msk	(0x1U << I2C_SSP_CR_SSPEN_Pos)
	/* 0���ر�I2C�ӻ� */
	/* 1��ʹ��I2C�ӻ� */

#define	I2C_SSP_IER_ADEE_Pos	7	/* �ӻ���ַ�����ж�ʹ�� */
#define	I2C_SSP_IER_ADEE_Msk	(0x1U << I2C_SSP_IER_ADEE_Pos)

#define	I2C_SSP_IER_SE_Pos	6	/* Start�ж�ʹ�� */
#define	I2C_SSP_IER_SE_Msk	(0x1U << I2C_SSP_IER_SE_Pos)

#define	I2C_SSP_IER_PE_Pos	5	/* Stop�ж�ʹ�� */
#define	I2C_SSP_IER_PE_Msk	(0x1U << I2C_SSP_IER_PE_Pos)

#define	I2C_SSP_IER_WCOLE_Pos	4	/* WCOL�ж�ʹ�� */
#define	I2C_SSP_IER_WCOLE_Msk	(0x1U << I2C_SSP_IER_WCOLE_Pos)

#define	I2C_SSP_IER_SSPOVE_Pos	3	/* SSPOV�ж�ʹ�� */
#define	I2C_SSP_IER_SSPOVE_Msk	(0x1U << I2C_SSP_IER_SSPOVE_Pos)

#define	I2C_SSP_IER_ADME_Pos	2	/* �ӻ���ַƥ���ж�ʹ�� */
#define	I2C_SSP_IER_ADME_Msk	(0x1U << I2C_SSP_IER_ADME_Pos)

#define	I2C_SSP_IER_TXIE_Pos	1	/* ��������ж�ʹ�� */
#define	I2C_SSP_IER_TXIE_Msk	(0x1U << I2C_SSP_IER_TXIE_Pos)

#define	I2C_SSP_IER_RXIE_Pos	0	/* ��������ж�ʹ�� */
#define	I2C_SSP_IER_RXIE_Msk	(0x1U << I2C_SSP_IER_RXIE_Pos)

#define	I2C_SSP_ISR_ADE_Pos	7	/* �ӻ���ַ��ʽ���� */
#define	I2C_SSP_ISR_ADE_Msk	(0x1U << I2C_SSP_ISR_ADE_Pos)

#define	I2C_SSP_ISR_S_Pos	6	/* ��⵽startʱ�� */
#define	I2C_SSP_ISR_S_Msk	(0x1U << I2C_SSP_ISR_S_Pos)

#define	I2C_SSP_ISR_P_Pos	5	/* ��⵽stopʱ�� */
#define	I2C_SSP_ISR_P_Msk	(0x1U << I2C_SSP_ISR_P_Pos)

#define	I2C_SSP_ISR_WCOL_Pos	4	/* д��ͻ��־ */
#define	I2C_SSP_ISR_WCOL_Msk	(0x1U << I2C_SSP_ISR_WCOL_Pos)

#define	I2C_SSP_ISR_SSPOV_Pos	3	/* SSPBUF�����־ */
#define	I2C_SSP_ISR_SSPOV_Msk	(0x1U << I2C_SSP_ISR_SSPOV_Pos)

#define	I2C_SSP_ISR_ADM_Pos	2	/* �ӻ���ַƥ���־ */
#define	I2C_SSP_ISR_ADM_Msk	(0x1U << I2C_SSP_ISR_ADM_Pos)

#define	I2C_SSP_ISR_TXIF_Pos	1	/* I2C�ӻ�������ɱ�־ */
#define	I2C_SSP_ISR_TXIF_Msk	(0x1U << I2C_SSP_ISR_TXIF_Pos)

#define	I2C_SSP_ISR_RXIF_Pos	0	/* I2C�ӻ�������ɱ�־ */
#define	I2C_SSP_ISR_RXIF_Msk	(0x1U << I2C_SSP_ISR_RXIF_Pos)

#define	I2C_SSP_SR_BUSY_Pos	3	/* �ӻ�ͨ�ű�־ */
#define	I2C_SSP_SR_BUSY_Msk	(0x1U << I2C_SSP_SR_BUSY_Pos)

#define	I2C_SSP_SR_RW_Pos	2	/* ��д����״̬�Ĵ��� */
#define	I2C_SSP_SR_RW_Msk	(0x1U << I2C_SSP_SR_RW_Pos)

#define	I2C_SSP_SR_DA_Pos	1	/* data/addressָ֡ʾ */
#define	I2C_SSP_SR_DA_Msk	(0x1U << I2C_SSP_SR_DA_Pos)

#define	I2C_SSP_SR_BF_Pos	0	/* �ӻ����ݻ���������־ */
#define	I2C_SSP_SR_BF_Msk	(0x1U << I2C_SSP_SR_BF_Pos)

#define	I2C_SSP_BUF_SSPBUF_Pos	0	/* I2C�ӻ��շ�����Ĵ��� */
#define	I2C_SSP_BUF_SSPBUF_Msk	(0xffU << I2C_SSP_BUF_SSPBUF_Pos)

#define	I2C_SSP_ADR_SSPADDR_Pos	0	/* I2C�ӻ���ַ�Ĵ��� */
#define	I2C_SSP_ADR_SSPADDR_Msk	(0x3ffU << I2C_SSP_ADR_SSPADDR_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void I2C_Deinit(void);

/* ����DMA�Զ���ֹ ��غ��� */
extern void I2C_MSP_CFGR_AUTOEND_Set(uint32_t SetValue);
extern uint32_t I2C_MSP_CFGR_AUTOEND_Get(void);

/* ����DMAʹ�� ��غ��� */
extern void I2C_MSP_CFGR_MSP_DMAEN_Setable(FunState NewState);
extern FunState I2C_MSP_CFGR_MSP_DMAEN_Getable(void);

/* SCL���ͳ�ʱʹ�� ��غ��� */
extern void I2C_MSP_CFGR_TOEN_Setable(FunState NewState);
extern FunState I2C_MSP_CFGR_TOEN_Getable(void);

/* I2C����ģ��ʹ�ܿ���λ ��غ��� */
extern void I2C_MSP_CFGR_MSPEN_Setable(FunState NewState);
extern FunState I2C_MSP_CFGR_MSPEN_Getable(void);

/* ��������ģʽ�£�����ʹ��λ ��غ��� */
extern void I2C_MSP_CR_RCEN_Setable(FunState NewState);
extern FunState I2C_MSP_CR_RCEN_Getable(void);

/* STOPʱ�����ʹ�ܿ���λ ��غ��� */
extern void I2C_MSP_CR_PEN_Setable(FunState NewState);
extern FunState I2C_MSP_CR_PEN_Getable(void);

/* Repeated STARTʱ�����ʹ�ܿ���λ ��غ��� */
extern void I2C_MSP_CR_RSEN_Setable(FunState NewState);
extern FunState I2C_MSP_CR_RSEN_Getable(void);

/* STARTʱ�����ʹ�ܿ���λ ��غ��� */
extern void I2C_MSP_CR_SEN_Setable(FunState NewState);
extern FunState I2C_MSP_CR_SEN_Getable(void);

/* WCOL�ж�ʹ�ܼĴ��� ��غ��� */
extern void I2C_MSP_IER_WCOLE_Setable(FunState NewState);
extern FunState I2C_MSP_IER_WCOLE_Getable(void);

/* SCL��ʱ�ж�ʹ�ܼĴ��� ��غ��� */
extern void I2C_MSP_IER_OVTE_Setable(FunState NewState);
extern FunState I2C_MSP_IER_OVTE_Getable(void);

/* STARTʱ���ж�ʹ�ܼĴ��� ��غ��� */
extern void I2C_MSP_IER_SE_Setable(FunState NewState);
extern FunState I2C_MSP_IER_SE_Getable(void);

/* STOPʱ���ж�ʹ�ܼĴ��� ��غ��� */
extern void I2C_MSP_IER_PE_Setable(FunState NewState);
extern FunState I2C_MSP_IER_PE_Getable(void);

/* ��������ģʽ��NACK�ж�ʹ�ܼĴ��� ��غ��� */
extern void I2C_MSP_IER_NACKE_Setable(FunState NewState);
extern FunState I2C_MSP_IER_NACKE_Getable(void);

/* I2C������������ж�ʹ�� ��غ��� */
extern void I2C_MSP_IER_TXIE_Setable(FunState NewState);
extern FunState I2C_MSP_IER_TXIE_Getable(void);

/* I2C������������ж�ʹ�� ��غ��� */
extern void I2C_MSP_IER_RXIE_Setable(FunState NewState);
extern FunState I2C_MSP_IER_RXIE_Getable(void);

/* д��ͻ���λ ��غ��� */
extern void I2C_MSP_ISR_WCOL_Clr(void);
extern FlagStatus I2C_MSP_ISR_WCOL_Chk(void);

/* SCL��ʱ�жϱ�־ ��غ��� */
extern void I2C_MSP_ISR_OVT_Clr(void);
extern FlagStatus I2C_MSP_ISR_OVT_Chk(void);

/* STARTʱ��������жϱ�־ ��غ��� */
extern FlagStatus I2C_MSP_ISR_S_Chk(void);
extern void I2C_MSP_ISR_S_Clr(void);

/* STOPʱ��������жϱ�־ ��غ��� */
extern FlagStatus I2C_MSP_ISR_P_Chk(void);
extern void I2C_MSP_ISR_P_Clr(void);

/* ���ط���ģʽ�£����Դӻ��Ļ�Ӧ�ź� ��غ��� */
extern void I2C_MSP_ISR_ACKSTA_Clr(void);
extern FlagStatus I2C_MSP_ISR_ACKSTA_Chk(void);

/* I2C������������жϱ�־ ��غ��� */
extern void I2C_MSP_ISR_TXIF_Clr(void);
extern FlagStatus I2C_MSP_ISR_TXIF_Chk(void);

/* I2C������������жϱ�־ ��غ��� */
extern void I2C_MSP_ISR_RXIF_Clr(void);
extern FlagStatus I2C_MSP_ISR_RXIF_Chk(void);

/* I2Cͨ��״̬λ ��غ��� */
extern FlagStatus I2C_MSP_SR_BUSY_Chk(void);

/* I2C���䷽��״̬λ ��غ��� */
extern FlagStatus I2C_MSP_SR_RW_Chk(void);

/* ��������״̬λ ��غ��� */
extern FlagStatus I2C_MSP_SR_BF_Chk(void);

/* ���ؽ���ģʽ�£�������Ӧ�źŵ�״̬ ��غ��� */
extern void I2C_MSP_SR_ACKMO_Set(uint32_t SetValue);
extern uint32_t I2C_MSP_SR_ACKMO_Get(void);

/* �������͵�SCLʱ�Ӹߵ�ƽ��� ��غ��� */
extern void I2C_MSP_BGR_MSPBRGH_Set(uint32_t SetValue);
extern uint32_t I2C_MSP_BGR_MSPBRGH_Get(void);

/* �������͵�SCLʱ�ӵ͵�ƽ��� ��غ��� */
extern void I2C_MSP_BGR_MSPBRGL_Set(uint32_t SetValue);
extern uint32_t I2C_MSP_BGR_MSPBRGL_Get(void);

/* I2C�����շ�����Ĵ��� ��غ��� */
extern void I2C_MSP_BUF_Write(uint32_t SetValue);
extern uint32_t I2C_MSP_BUF_Read(void);

/* I2C����ʱ����ƼĴ��� ��غ��� */
extern void I2C_MSP_TCR_SDAHD_Set(uint32_t SetValue);
extern uint32_t I2C_MSP_TCR_SDAHD_Get(void);

/* I2C������ʱ�Ĵ��� ��غ��� */
extern void I2C_MSP_TOR_TIMEOUT_Set(uint32_t SetValue);
extern uint32_t I2C_MSP_TOR_TIMEOUT_Get(void);

/* I2C�ӻ�ʱ����չʹ�� ��غ��� */
extern void I2C_SSP_CR_SCLSEN_Setable(FunState NewState);
extern FunState I2C_SSP_CR_SCLSEN_Getable(void);

/* I2C�ӻ�DMAʹ�� ��غ��� */
extern void I2C_SSP_CR_SSP_DMAEN_Setable(FunState NewState);
extern FunState I2C_SSP_CR_SSP_DMAEN_Getable(void);

/* ACKʹ��λ ��غ��� */
extern void I2C_SSP_CR_ACKEN_Setable(FunState NewState);
extern FunState I2C_SSP_CR_ACKEN_Getable(void);

/* SDA�ӻ�����ӳ�ʹ�� ��غ��� */
extern void I2C_SSP_CR_SDAO_DLYEN_Setable(FunState NewState);
extern FunState I2C_SSP_CR_SDAO_DLYEN_Getable(void);

/* SCL�ӻ�����ģ���˲�ʹ�� ��غ��� */
extern void I2C_SSP_CR_SCLI_ANFEN_Setable(FunState NewState);
extern FunState I2C_SSP_CR_SCLI_ANFEN_Getable(void);

/* 10λ��ַʹ�� ��غ��� */
extern void I2C_SSP_CR_A10EN_Setable(FunState NewState);
extern FunState I2C_SSP_CR_A10EN_Getable(void);

/* I2C�ӻ�ʹ��λ ��غ��� */
extern void I2C_SSP_CR_SSPEN_Setable(FunState NewState);
extern FunState I2C_SSP_CR_SSPEN_Getable(void);

/* �ӻ���ַ�����ж�ʹ�� ��غ��� */
extern void I2C_SSP_IER_ADEE_Setable(FunState NewState);
extern FunState I2C_SSP_IER_ADEE_Getable(void);

/* Start�ж�ʹ�� ��غ��� */
extern void I2C_SSP_IER_SE_Setable(FunState NewState);
extern FunState I2C_SSP_IER_SE_Getable(void);

/* Stop�ж�ʹ�� ��غ��� */
extern void I2C_SSP_IER_PE_Setable(FunState NewState);
extern FunState I2C_SSP_IER_PE_Getable(void);

/* WCOL�ж�ʹ�� ��غ��� */
extern void I2C_SSP_IER_WCOLE_Setable(FunState NewState);
extern FunState I2C_SSP_IER_WCOLE_Getable(void);

/* SSPOV�ж�ʹ�� ��غ��� */
extern void I2C_SSP_IER_SSPOVE_Setable(FunState NewState);
extern FunState I2C_SSP_IER_SSPOVE_Getable(void);

/* �ӻ���ַƥ���ж�ʹ�� ��غ��� */
extern void I2C_SSP_IER_ADME_Setable(FunState NewState);
extern FunState I2C_SSP_IER_ADME_Getable(void);

/* ��������ж�ʹ�� ��غ��� */
extern void I2C_SSP_IER_TXIE_Setable(FunState NewState);
extern FunState I2C_SSP_IER_TXIE_Getable(void);

/* ��������ж�ʹ�� ��غ��� */
extern void I2C_SSP_IER_RXIE_Setable(FunState NewState);
extern FunState I2C_SSP_IER_RXIE_Getable(void);

/* �ӻ���ַ��ʽ���� ��غ��� */
extern void I2C_SSP_ISR_ADE_Clr(void);
extern FlagStatus I2C_SSP_ISR_ADE_Chk(void);

/* ��⵽startʱ�� ��غ��� */
extern FlagStatus I2C_SSP_ISR_S_Chk(void);

/* ��⵽stopʱ�� ��غ��� */
extern FlagStatus I2C_SSP_ISR_P_Chk(void);

/* д��ͻ��־ ��غ��� */
extern void I2C_SSP_ISR_WCOL_Clr(void);
extern FlagStatus I2C_SSP_ISR_WCOL_Chk(void);

/* SSPBUF�����־ ��غ��� */
extern void I2C_SSP_ISR_SSPOV_Clr(void);
extern FlagStatus I2C_SSP_ISR_SSPOV_Chk(void);

/* �ӻ���ַƥ���־ ��غ��� */
extern void I2C_SSP_ISR_ADM_Clr(void);
extern FlagStatus I2C_SSP_ISR_ADM_Chk(void);

/* I2C�ӻ�������ɱ�־ ��غ��� */
extern void I2C_SSP_ISR_TXIF_Clr(void);
extern FlagStatus I2C_SSP_ISR_TXIF_Chk(void);

/* I2C�ӻ�������ɱ�־ ��غ��� */
extern void I2C_SSP_ISR_RXIF_Clr(void);
extern FlagStatus I2C_SSP_ISR_RXIF_Chk(void);

/* �ӻ�ͨ�ű�־ ��غ��� */
extern FlagStatus I2C_SSP_SR_BUSY_Chk(void);

/* ��д����״̬�Ĵ��� ��غ��� */
extern FlagStatus I2C_SSP_SR_RW_Chk(void);

/* data/addressָ֡ʾ ��غ��� */
extern FlagStatus I2C_SSP_SR_DA_Chk(void);

/* �ӻ����ݻ���������־ ��غ��� */
extern FlagStatus I2C_SSP_SR_BF_Chk(void);

/* I2C�ӻ��շ�����Ĵ��� ��غ��� */
extern void I2C_SSP_BUF_Write(uint32_t SetValue);
extern uint32_t I2C_SSP_BUF_Read(void);

/* I2C�ӻ���ַ�Ĵ��� ��غ��� */
extern void I2C_SSP_ADR_SSPADDR_Set(uint32_t SetValue);
extern uint32_t I2C_SSP_ADR_SSPADDR_Get(void);

extern uint32_t I2C_BaudREG_Calc(uint32_t I2CClk, uint32_t APBClk);
#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_I2C_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
