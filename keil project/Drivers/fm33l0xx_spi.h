/**
  ******************************************************************************
  * @file    fm33l0xx_spi.h
  * @author  FM33L0xx Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file contains all the functions prototypes for the SPI firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33L0XX_SPI_H
#define __FM33L0XX_SPI_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33L0XX.h"

//------------------------------------------------------------------------------
typedef struct
{
	uint32_t LSBF;             	//�ȷ��͸�λbit���ǵ�λbit/* SETTING 1 FOR LSB */		
  uint32_t CPHOL;			    //ʱ�Ӽ���ѡ��/* SETTING 1 FOR CLK STOP AT HIGH*/	
	uint32_t CPHA;				//ʱ����λѡ��/* SETTING 1 FOR START AT SECOND CLK EDGE AND 0 FOR FIRST */
}SPI_Slave_SInitTypeDef;

typedef struct
{
	uint32_t SSPA;				//slaveģʽ�¶Է���ʱ������е�������ǰ��
	FunState FLTEN;             //slaveģʽ��ʹ��4ns�˲�/
	uint32_t LSBF;             	//�ȷ��͸�λbit���ǵ�λbit/* SETTING 1 FOR LSB */		
  uint32_t CPHOL;			    //ʱ�Ӽ���ѡ��/* SETTING 1 FOR CLK STOP AT HIGH*/	
	uint32_t CPHA;				//ʱ����λѡ��/* SETTING 1 FOR START AT SECOND CLK EDGE AND 0 FOR FIRST */
	FunState TXO;               //TXONLYģʽ
	uint32_t TXO_AC;            //TXONLYӲ���Զ��������

	FunState SPIEN;             //SPIʹ�ܣ���ʼ��ʱ����дΪDISABLE
	FunState ERRIE;             //SPI�����ж�ʹ�ܣ���ʼ��ʱ����дΪDISABLE
	FunState TXIE;              //SPI��������ж�ʹ�ܣ���ʼ��ʱ����дΪDISABLE
	FunState RXIE;              //SPI��������ж�ʹ�ܣ���ʼ��ʱ����дΪDISABLE
}SPI_Slave_InitTypeDef;

typedef struct
{
    uint32_t BAUD_RATE;         //������/* SETTING BAUD_RATE */	
    uint32_t LSBF;             	//�ȷ��͸�λbit���ǵ�λbit/* SETTING 1 FOR LSB */		
    uint32_t CPHOL;			    //ʱ�Ӽ���ѡ��/* SETTING 1 FOR CLK STOP AT HIGH*/	
	uint32_t CPHA;				//ʱ����λѡ��/* SETTING 1 FOR START AT SECOND CLK EDGE AND 0 FOR FIRST */
	uint32_t SSNM;				//ÿ�η���8bit�󱣳�SSNΪ�ͻ������ߣ�SSNӲ��ģʽ��Ч/* SETTING SSN AFTER SENDING */	
	uint32_t SSNSEN;			//SSN��Ӳ�����ƻ������������/* SETTING 1 FOR CONTROL SSN BY SOFTWARE */
}SPI_Master_SInitTypeDef;

typedef struct
{
	uint32_t MSPA;              //masterģʽ�¶Բ�������е���(�ͺ�)�����ڸ���ͨ��ʱ����PCB�����ӳ�
	uint32_t WAIT;              //masterģʽ�£�ÿ�η�����8bit���ټ��뼸��sck���ڵĵȴ�ʱ��
	uint32_t BAUD_RATE; 		//������/* SETTING BAUD_RATE */	
	uint32_t LSBF;				//�ȷ��͸�λbit���ǵ�λbit/* SETTING 1 FOR LSB */		
	uint32_t CPHOL; 			//ʱ�Ӽ���ѡ��/* SETTING 1 FOR CLK STOP AT HIGH*/ 
	uint32_t CPHA;				//ʱ����λѡ��/* SETTING 1 FOR START AT SECOND CLK EDGE AND 0 FOR FIRST */
    FunState DUMMY_EN;          //��˫��Э���¶��������Ƿ����dummy cycle
    FunState RXO;               //������ģʽ
    uint32_t DATA_LEN;          //ͨ�����ݳ���
    uint32_t HALFDUPLEX;        //ͨ��ģʽѡ��
    uint32_t HD_RW;             //4�߰�˫��Э����������д��������
    uint32_t CMD8b;             //4�߰�˫��Э����command֡����
    uint32_t SSNM;				//ÿ�η���8bit�󱣳�SSNΪ�ͻ������ߣ�SSNӲ��ģʽ��Ч/* SETTING SSN AFTER SENDING */ 
	uint32_t TXO_AC;            //TXONLYӲ���Զ��������
	FunState TXO;               //TXONLYģʽ
	uint32_t SSNSEN;			//SSN��Ӳ�����ƻ������������/* SETTING 1 FOR CONTROL SSN BY SOFTWARE */

	FunState SPIEN;             //SPIʹ�ܣ���ʼ��ʱ����дΪDISABLE
	FunState ERRIE;             //SPI�����ж�ʹ�ܣ���ʼ��ʱ����дΪDISABLE
	FunState TXIE;              //SPI��������ж�ʹ�ܣ���ʼ��ʱ����дΪDISABLE
	FunState RXIE;              //SPI��������ж�ʹ�ܣ���ʼ��ʱ����дΪDISABLE
}SPI_Master_InitTypeDef;


#define	SPIx_CR1_MSPA_Pos	10	/* Master��MISO�źŵĲ���λ�õ��������ڸ���ͨ��ʱ����PCB�����ӳ� */
#define	SPIx_CR1_MSPA_Msk	(0x1U << SPIx_CR1_MSPA_Pos)
#define	SPIx_CR1_MSPA_NORMAL	(0x0U << SPIx_CR1_MSPA_Pos)	/* �����㲻���� */
#define	SPIx_CR1_MSPA_HALF_DELAY	(0x1U << SPIx_CR1_MSPA_Pos)	/* �������ӳٰ��SCK���� */

#define	SPIx_CR1_SSPA_Pos	9	/* Slave MISO����λ�õ��� */
#define	SPIx_CR1_SSPA_Msk	(0x1U << SPIx_CR1_SSPA_Pos)
#define	SPIx_CR1_SSPA_NORMAL	(0x0U << SPIx_CR1_SSPA_Pos)	/* ���Ͳ���ǰ */
#define	SPIx_CR1_SSPA_HALF_DELAY	(0x1U << SPIx_CR1_SSPA_Pos)	/* ��ǰ���SCK���ڷ��� */

#define	SPIx_CR1_MM_Pos	8	/* Master/Slaveģʽѡ�� */
#define	SPIx_CR1_MM_Msk	(0x1U << SPIx_CR1_MM_Pos)
#define	SPIx_CR1_MM_SLAVE	(0x0U << SPIx_CR1_MM_Pos)	/* Slaveģʽ */
#define	SPIx_CR1_MM_MASTER	(0x1U << SPIx_CR1_MM_Pos)	/* Masterģʽ */

#define	SPIx_CR1_WAIT_Pos	6	/* ������ɺ�ȴ� */
#define	SPIx_CR1_WAIT_Msk	(0x3U << SPIx_CR1_WAIT_Pos)
#define	SPIx_CR1_WAIT_WAIT_1	(0x0U << SPIx_CR1_WAIT_Pos)	/* 1��SCK���� */
#define	SPIx_CR1_WAIT_WAIT_2	(0x1U << SPIx_CR1_WAIT_Pos)	/* 2��SCK���� */
#define	SPIx_CR1_WAIT_WAIT_3	(0x2U << SPIx_CR1_WAIT_Pos)	/* 3��SCK���� */
#define	SPIx_CR1_WAIT_WAIT_4	(0x3U << SPIx_CR1_WAIT_Pos)	/* 4��SCK���� */

#define	SPIx_CR1_BAUD_Pos	3	/* Masterģʽ�²��������� */
#define	SPIx_CR1_BAUD_Msk	(0x7U << SPIx_CR1_BAUD_Pos)
#define	SPIx_CR1_BAUD_PLCK_2	(0x0U << SPIx_CR1_BAUD_Pos)	/* ����ʱ��2��Ƶ */
#define	SPIx_CR1_BAUD_PLCK_4	(0x1U << SPIx_CR1_BAUD_Pos)	/* ����ʱ��4��Ƶ */
#define	SPIx_CR1_BAUD_PLCK_8	(0x2U << SPIx_CR1_BAUD_Pos)	/* ����ʱ��8��Ƶ */
#define	SPIx_CR1_BAUD_PLCK_16	(0x3U << SPIx_CR1_BAUD_Pos)	/* ����ʱ��16��Ƶ */
#define	SPIx_CR1_BAUD_PLCK_32	(0x4U << SPIx_CR1_BAUD_Pos)	/* ����ʱ��32��Ƶ */
#define	SPIx_CR1_BAUD_PLCK_64	(0x5U << SPIx_CR1_BAUD_Pos)	/* ����ʱ��64��Ƶ */
#define	SPIx_CR1_BAUD_PLCK_128	(0x6U << SPIx_CR1_BAUD_Pos)	/* ����ʱ��128��Ƶ */
#define	SPIx_CR1_BAUD_PLCK_256	(0x7U << SPIx_CR1_BAUD_Pos)	/* ����ʱ��256��Ƶ */

#define	SPIx_CR1_LSBF_Pos	2	/* ֡��ʽ */
#define	SPIx_CR1_LSBF_Msk	(0x1U << SPIx_CR1_LSBF_Pos)
#define	SPIx_CR1_LSBF_MSB	(0x0U << SPIx_CR1_LSBF_Pos)	/* �ȷ��͸�bit */
#define	SPIx_CR1_LSBF_LSB	(0x1U << SPIx_CR1_LSBF_Pos)	/* �ȷ��͵�bit */

#define	SPIx_CR1_CPOL_Pos	1	/* ʱ�Ӽ���ѡ�� */
#define	SPIx_CR1_CPOL_Msk	(0x1U << SPIx_CR1_CPOL_Pos)
#define	SPIx_CR1_CPOL_LOW	(0x0U << SPIx_CR1_CPOL_Pos)	/* ����ʱ��ֹͣʱ�ڵ͵�ƽ */
#define	SPIx_CR1_CPOL_HIGH	(0x1U << SPIx_CR1_CPOL_Pos)	/* ����ʱ��ֹͣʱ�ڸߵ�ƽ */

#define	SPIx_CR1_CPHA_Pos	0	/* ʱ����λѡ�� */
#define	SPIx_CR1_CPHA_Msk	(0x1U << SPIx_CR1_CPHA_Pos)
#define	SPIx_CR1_CPHA_FIRST	(0x0U << SPIx_CR1_CPHA_Pos)	/* ��һ��ʱ�ӱ��ز��� */
#define	SPIx_CR1_CPHA_SECOND	(0x1U << SPIx_CR1_CPHA_Pos)	/* �ڶ���ʱ�ӱ��ز��� */

#define	SPIx_CR2_DUMMY_EN_Pos	15	/* ���߰�˫��Э���ڶ������Ƿ����dummy cycle */
#define	SPIx_CR2_DUMMY_EN_Msk	(0x1U << SPIx_CR2_DUMMY_EN_Pos)
	/* ������ */
	/* ���� */

#define	SPIx_CR2_RXO_Pos	11	/* Master RXONLY����λ */
#define	SPIx_CR2_RXO_Msk	(0x1U << SPIx_CR2_RXO_Pos)
	/* �շ�ģʽ */
	/* ������ģʽ */

#define	SPIx_CR2_DLEN_Pos	9	/* ͨ�������ֳ����� */
#define	SPIx_CR2_DLEN_Msk	(0x3U << SPIx_CR2_DLEN_Pos)
#define	SPIx_CR2_DLEN_8BIT	(0x0U << SPIx_CR2_DLEN_Pos)	/* 8bit���� */
#define	SPIx_CR2_DLEN_16BIT	(0x1U << SPIx_CR2_DLEN_Pos)	/* 16bit���� */
#define	SPIx_CR2_DLEN_24BIT	(0x2U << SPIx_CR2_DLEN_Pos)	/* 24bit���� */
#define	SPIx_CR2_DLEN_32BIT	(0x3U << SPIx_CR2_DLEN_Pos)	/* 32bit���� */

#define	SPIx_CR2_HALFDUPLEX_Pos	8	/* ͨ��ģʽѡ�� */
#define	SPIx_CR2_HALFDUPLEX_Msk	(0x1U << SPIx_CR2_HALFDUPLEX_Pos)
#define	SPIx_CR2_HALFDUPLEX_STAND	(0x0U << SPIx_CR2_HALFDUPLEX_Pos)	/* ��׼SPIģʽ��4��ȫ˫�� */
#define	SPIx_CR2_HALFDUPLEX_DCN	(0x1U << SPIx_CR2_HALFDUPLEX_Pos)	/* DCNģʽ��4�߰�˫�� */

#define	SPIx_CR2_HD_RW_Pos	7	/* ��˫��ģʽ�¶�д���� */
#define	SPIx_CR2_HD_RW_Msk	(0x1U << SPIx_CR2_HD_RW_Pos)
#define	SPIx_CR2_HD_RW_WRITE	(0x0U << SPIx_CR2_HD_RW_Pos)	/* ����д��ӻ� */
#define	SPIx_CR2_HD_RW_READ	(0x1U << SPIx_CR2_HD_RW_Pos)	/* ������ȡ�ӻ� */

#define	SPIx_CR2_CMD8b_Pos	6	/* ��˫��ģʽ��commmand֡���� */
#define	SPIx_CR2_CMD8b_Msk	(0x1U << SPIx_CR2_CMD8b_Pos)
#define	SPIx_CR2_CMD8b_VARIABLE	(0x0U << SPIx_CR2_CMD8b_Pos)	/* ��DLEN���� */
#define	SPIx_CR2_CMD8b_FIXED	(0x1U << SPIx_CR2_CMD8b_Pos)	/* �̶�Ϊ8bit */

#define	SPIx_CR2_SSNM_Pos	5	/* Masterģʽ��SSN����ģʽѡ�� */
#define	SPIx_CR2_SSNM_Msk	(0x1U << SPIx_CR2_SSNM_Pos)
#define	SPIx_CR2_SSNM_LOW	(0x0U << SPIx_CR2_SSNM_Pos)	/* ����һ֡�󱣳�SSNΪ�� */
#define	SPIx_CR2_SSNM_HIGH	(0x1U << SPIx_CR2_SSNM_Pos)	/* ����һ֡������SSN */

#define	SPIx_CR2_TXO_AC_Pos	4	/* TXONLYӲ���Զ���տ��� */
#define	SPIx_CR2_TXO_AC_Msk	(0x1U << SPIx_CR2_TXO_AC_Pos)
#define	SPIx_CR2_TXO_AC_DISABLE	(0x0U << SPIx_CR2_TXO_AC_Pos)	/* �ر�TXONLYӲ���Զ���� */
#define	SPIx_CR2_TXO_AC_ENABLE	(0x1U << SPIx_CR2_TXO_AC_Pos)	/* TXONLYӲ���Զ������Ч */

#define	SPIx_CR2_TXO_Pos	3	/* TXONLYģʽ���� */
#define	SPIx_CR2_TXO_Msk	(0x1U << SPIx_CR2_TXO_Pos)
	/* �ر�TXONLYģʽ */
	/* ����TXONLYģʽ */

#define	SPIx_CR2_SSN_Pos	2	/* SSN�����ƽ */
#define	SPIx_CR2_SSN_Msk	(0x1U << SPIx_CR2_SSN_Pos)
#define	SPIx_CR2_SSN_LOW	(0x0U << SPIx_CR2_SSN_Pos)	/* �ߵ�ƽ */
#define	SPIx_CR2_SSN_HIGH	(0x1U << SPIx_CR2_SSN_Pos)	/* �͵�ƽ */

#define	SPIx_CR2_SSNSEN_Pos	1	/* �������SSN */
#define	SPIx_CR2_SSNSEN_Msk	(0x1U << SPIx_CR2_SSNSEN_Pos)
#define	SPIx_CR2_SSNSEN_DISABLE	(0x0U << SPIx_CR2_SSNSEN_Pos)	/* �ر� */
#define	SPIx_CR2_SSNSEN_ENABLE	(0x1U << SPIx_CR2_SSNSEN_Pos)	/* ʹ�� */

#define	SPIx_CR2_SPIEN_Pos	0	/* SPIģ����� */
#define	SPIx_CR2_SPIEN_Msk	(0x1U << SPIx_CR2_SPIEN_Pos)
	/* �ر� */
	/* ʹ�� */

#define	SPIx_CR3_TXBFC_Pos	3
#define	SPIx_CR3_TXBFC_Msk	(0x1U << SPIx_CR3_TXBFC_Pos)

#define	SPIx_CR3_RXBFC_Pos	2
#define	SPIx_CR3_RXBFC_Msk	(0x1U << SPIx_CR3_RXBFC_Pos)

#define	SPIx_CR3_MERRC_Pos	1
#define	SPIx_CR3_MERRC_Msk	(0x1U << SPIx_CR3_MERRC_Pos)

#define	SPIx_CR3_SERRC_Pos	0
#define	SPIx_CR3_SERRC_Msk	(0x1U << SPIx_CR3_SERRC_Pos)

#define	SPIx_IER_ERRIE_Pos	2	/* SPI�����жϿ��� */
#define	SPIx_IER_ERRIE_Msk	(0x1U << SPIx_IER_ERRIE_Pos)
/* ʧ�� */
/* ʹ�� */

#define	SPIx_IER_TXIE_Pos	1	/* ��������жϿ��� */
#define	SPIx_IER_TXIE_Msk	(0x1U << SPIx_IER_TXIE_Pos)
/* ʧ�� */
/* ʹ�� */

#define	SPIx_IER_RXIE_Pos	0	/* ��������жϿ��� */
#define	SPIx_IER_RXIE_Msk	(0x1U << SPIx_IER_RXIE_Pos)
/* ʧ�� */
/* ʹ�� */

#define	SPIx_ISR_DCN_TX_Pos	12	/* ��˫��ģʽ�£�ÿ֡���ݵ�֡ģʽ */
#define	SPIx_ISR_DCN_TX_Msk	(0x1U << SPIx_ISR_DCN_TX_Pos)
#define	SPIx_ISR_DCN_TX_CMD	(0x0U << SPIx_ISR_DCN_TX_Pos)	/* ����֡ */
#define	SPIx_ISR_DCN_TX_DATA	(0x1U << SPIx_ISR_DCN_TX_Pos)	/* ����֡ */

#define	SPIx_ISR_RXCOL_Pos	10	/* ���ջ�������������д1��0 */
#define	SPIx_ISR_RXCOL_Msk	(0x1U << SPIx_ISR_RXCOL_Pos)

#define	SPIx_ISR_TXCOL_Pos	9	/* ���ͻ�������������д1��0 */
#define	SPIx_ISR_TXCOL_Msk	(0x1U << SPIx_ISR_TXCOL_Pos)

#define	SPIx_ISR_BUSY_Pos	8	/* SPI״̬��־��ֻ�� */
#define	SPIx_ISR_BUSY_Msk	(0x1U << SPIx_ISR_BUSY_Pos)
#define	SPIx_ISR_BUSY_RESET	(0x0U << SPIx_ISR_BUSY_Pos)	/* ������� */
#define	SPIx_ISR_BUSY_SET	(0x1U << SPIx_ISR_BUSY_Pos)	/* ������ */

#define	SPIx_ISR_MERR_Pos	6	/* ���������־�����д1��0 */
#define	SPIx_ISR_MERR_Msk	(0x1U << SPIx_ISR_MERR_Pos)

#define	SPIx_ISR_SERR_Pos	5	/* �ӻ������־�����д1��0 */
#define	SPIx_ISR_SERR_Msk	(0x1U << SPIx_ISR_SERR_Pos)

#define	SPIx_ISR_TXBE_Pos	1	/* ����bufferΪ�ձ�־ */
#define	SPIx_ISR_TXBE_Msk	(0x1U << SPIx_ISR_TXBE_Pos)

#define	SPIx_ISR_RXBF_Pos	0	/* ����buffer�ǿձ�־ */
#define	SPIx_ISR_RXBF_Msk	(0x1U << SPIx_ISR_RXBF_Pos)

#define	SPIx_TXBUF_TXBUF_Pos	0	/* SPI���ͻ��� */
#define	SPIx_TXBUF_TXBUF_Msk	(0xffffffffU << SPIx_TXBUF_TXBUF_Pos)

#define	SPIx_RXBUF_RXBUF_Pos	0	/* SPI���ջ��� */
#define	SPIx_RXBUF_RXBUF_Msk	(0xffffffffU << SPIx_RXBUF_RXBUF_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void SPIx_Deinit(SPI_Type* SPIx);

/* Master��MISO�źŵĲ���λ�õ��������ڸ���ͨ��ʱ����PCB�����ӳ� ��غ��� */
extern void SPIx_CR1_MSPA_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR1_MSPA_Get(SPI_Type* SPIx);

/* Slave MISO����λ�õ��� ��غ��� */
extern void SPIx_CR1_SSPA_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR1_SSPA_Get(SPI_Type* SPIx);

/* Master/Slaveģʽѡ�� ��غ��� */
extern void SPIx_CR1_MM_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR1_MM_Get(SPI_Type* SPIx);

/* ������ɺ�ȴ� ��غ��� */
extern void SPIx_CR1_WAIT_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR1_WAIT_Get(SPI_Type* SPIx);

/* Masterģʽ�²��������� ��غ��� */
extern void SPIx_CR1_BAUD_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR1_BAUD_Get(SPI_Type* SPIx);

/* ֡��ʽ ��غ��� */
extern void SPIx_CR1_LSBF_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR1_LSBF_Get(SPI_Type* SPIx);

/* ʱ�Ӽ���ѡ�� ��غ��� */
extern void SPIx_CR1_CPOL_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR1_CPOL_Get(SPI_Type* SPIx);

/* ʱ����λѡ�� ��غ��� */
extern void SPIx_CR1_CPHA_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR1_CPHA_Get(SPI_Type* SPIx);

/* ���߰�˫��Э���ڶ������Ƿ����dummy cycle ��غ��� */
extern void SPIx_CR2_DUMMY_EN_Setable(SPI_Type* SPIx, FunState NewState);
extern FunState SPIx_CR2_DUMMY_EN_Getable(SPI_Type* SPIx);

/* Master RXONLY����λ ��غ��� */
extern void SPIx_CR2_RXO_Setable(SPI_Type* SPIx, FunState NewState);
extern FunState SPIx_CR2_RXO_Getable(SPI_Type* SPIx);

/* ͨ�������ֳ����� ��غ��� */
extern void SPIx_CR2_DLEN_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR2_DLEN_Get(SPI_Type* SPIx);

/* ͨ��ģʽѡ�� ��غ��� */
extern void SPIx_CR2_HALFDUPLEX_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR2_HALFDUPLEX_Get(SPI_Type* SPIx);

/* ��˫��ģʽ�¶�д���� ��غ��� */
extern void SPIx_CR2_HD_RW_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR2_HD_RW_Get(SPI_Type* SPIx);

/* ��˫��ģʽ��commmand֡���� ��غ��� */
extern void SPIx_CR2_CMD8b_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR2_CMD8b_Get(SPI_Type* SPIx);

/* Masterģʽ��SSN����ģʽѡ�� ��غ��� */
extern void SPIx_CR2_SSNM_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR2_SSNM_Get(SPI_Type* SPIx);

/* TXONLYӲ���Զ���տ��� ��غ��� */
extern void SPIx_CR2_TXO_AC_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR2_TXO_AC_Get(SPI_Type* SPIx);

/* TXONLYģʽ���� ��غ��� */
extern void SPIx_CR2_TXO_Setable(SPI_Type* SPIx, FunState NewState);
extern FunState SPIx_CR2_TXO_Getable(SPI_Type* SPIx);

/* SSN�����ƽ ��غ��� */
extern void SPIx_CR2_SSN_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR2_SSN_Get(SPI_Type* SPIx);

/* �������SSN ��غ��� */
extern void SPIx_CR2_SSNSEN_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR2_SSNSEN_Get(SPI_Type* SPIx);

/* SPIģ����� ��غ��� */
extern void SPIx_CR2_SPIEN_Setable(SPI_Type* SPIx, FunState NewState);
extern FunState SPIx_CR2_SPIEN_Getable(SPI_Type* SPIx);

extern void SPIx_CR3_TXBFC_Clr(SPI_Type* SPIx);
extern void SPIx_CR3_RXBFC_Clr(SPI_Type* SPIx);
extern void SPIx_CR3_MERRC_Clr(SPI_Type* SPIx);
extern void SPIx_CR3_SERRC_Clr(SPI_Type* SPIx);

/* SPI�����жϿ��� ��غ��� */
extern void SPIx_IER_ERRIE_Setable(SPI_Type* SPIx, FunState NewState);
extern FunState SPIx_IER_ERRIE_Getable(SPI_Type* SPIx);

/* ��������жϿ��� ��غ��� */
extern void SPIx_IER_TXIE_Setable(SPI_Type* SPIx, FunState NewState);
extern FunState SPIx_IER_TXIE_Getable(SPI_Type* SPIx);

/* ��������жϿ��� ��غ��� */
extern void SPIx_IER_RXIE_Setable(SPI_Type* SPIx, FunState NewState);
extern FunState SPIx_IER_RXIE_Getable(SPI_Type* SPIx);

/* ��˫��ģʽ�£�ÿ֡���ݵ�֡ģʽ ��غ��� */
extern void SPIx_ISR_DCN_TX_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_ISR_DCN_TX_Get(SPI_Type* SPIx);

/* ���ջ�������������д1��0 ��غ��� */
extern void SPIx_ISR_RXCOL_Clr(SPI_Type* SPIx);
extern FlagStatus SPIx_ISR_RXCOL_Chk(SPI_Type* SPIx);

/* ���ͻ�������������д1��0 ��غ��� */
extern void SPIx_ISR_TXCOL_Clr(SPI_Type* SPIx);
extern FlagStatus SPIx_ISR_TXCOL_Chk(SPI_Type* SPIx);

/* SPI״̬��־��ֻ�� ��غ��� */
extern FlagStatus SPIx_ISR_BUSY_Chk(SPI_Type* SPIx);

/* ���������־�����д1��0 ��غ��� */
extern void SPIx_ISR_MERR_Clr(SPI_Type* SPIx);
extern FlagStatus SPIx_ISR_MERR_Chk(SPI_Type* SPIx);

/* �ӻ������־�����д1��0 ��غ��� */
extern void SPIx_ISR_SERR_Clr(SPI_Type* SPIx);
extern FlagStatus SPIx_ISR_SERR_Chk(SPI_Type* SPIx);

/* ����bufferΪ�ձ�־ ��غ��� */
extern void SPIx_ISR_TXBE_Clr(SPI_Type* SPIx);
extern FlagStatus SPIx_ISR_TXBE_Chk(SPI_Type* SPIx);

/* ����buffer�ǿձ�־ ��غ��� */
extern void SPIx_ISR_RXBF_Clr(SPI_Type* SPIx);
extern FlagStatus SPIx_ISR_RXBF_Chk(SPI_Type* SPIx);

/* SPI���ͻ��� ��غ��� */
extern void SPIx_TXBUF_Write(SPI_Type* SPIx, uint32_t SetValue);

/* SPI���ջ��� ��غ��� */
extern uint32_t SPIx_RXBUF_Read(SPI_Type* SPIx);

//Announce_End

//Announce_HandBy
extern void SPI_Master_Init(SPI_Type* SPIx, SPI_Master_SInitTypeDef* para);
extern void SPI_Slave_Init(SPI_Type* SPIx, SPI_Slave_SInitTypeDef* para);

extern void SPI_SSN_Set_Low(SPI_Type* SPIx);//SSN�õ�
extern void SPI_SSN_Set_High(SPI_Type* SPIx);//SSN�ø�

extern uint8_t SPI_Recv_Byte(SPI_Type* SPIx);//SPI����һ�ֽ�
extern void SPI_Send_Byte(SPI_Type* SPIx, uint8_t data);//SPI����һ�ֽ�

extern uint8_t SPI_RW_Byte(SPI_Type* SPIx, uint8_t data);//SPI���Ͳ�����һ�ֽ�
//Announce_End

#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_SPI_H */

/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
