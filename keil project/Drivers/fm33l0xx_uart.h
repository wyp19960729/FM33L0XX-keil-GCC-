/**
  ******************************************************************************
  * @file    fm33l0xx_uart.h
  * @author  FM33L0xx Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file contains all the functions prototypes for the UART firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33L0XX_UART_H
#define __FM33L0XX_UART_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33L0XX.h"

typedef enum
{
	RxInt,
	TxInt
	
}UART_IntTypeDef;

typedef enum
{
	Seven7Bit,		
	Eight8Bit,
	Nine9Bit,
	Six6Bit	
}UART_DataBitTypeDef;

typedef enum
{
	NONE,
	EVEN,
	ODD
	
}UART_ParityBitTypeDef;

typedef enum
{
	OneBit,
	TwoBit
}UART_StopBitTypeDef;

typedef struct
{
	uint32_t				BaudRate;		//������
	UART_DataBitTypeDef		DataBit;		//����λ��
	UART_ParityBitTypeDef	ParityBit; 		//У��λ
	UART_StopBitTypeDef		StopBit;		//ֹͣλ
	
}UART_SInitTypeDef;	

typedef struct
{
	FunState				RXIE;		//�����ж�
	FunState				TXBE_IE;		//���ͻ�����ж�
	FunState				TXSE_IE;		//���ͻ�����ҷ��ͼĴ������ж�
	
	uint32_t				SPBRG;		//�����ʲ������Ĵ���
	
	uint32_t				PDSEL;		//���ݳ���ѡ��
	uint32_t				PARITY;		//У��λ����
	
	FunState				ERRIE;		//�����ж�ʹ�ܿ���
	FunState				RXEN;		//����ģ��ʹ�ܿ���
	uint32_t				STOPSEL;	//ֹͣλѡ��

	FunState				TXEN;		//����ģ��ʹ�ܿ���
	FunState				IREN;		//���ͺ������ʹ��λ


	FunState				RXDFLAG;	//��������ȡ������λ
	FunState				TXDFLAG;	//��������ȡ������λ
	
}UART_InitTypeDef;		 
	 
//------------------------------------------------------------------------------
#define	UART_IRCR_IRFLAG_Pos	15	/* ���ƺ�����Ʒ�������ʱ��Ĭ��������� */
#define	UART_IRCR_IRFLAG_Msk	(0x1U << UART_IRCR_IRFLAG_Pos)
	/* 0�������� */
	/* 1�������� */

#define	UART_IRCR_TH_Pos	11	/* ����ռ�ձȵ��Ʋ��� */
#define	UART_IRCR_TH_Msk	(0xfU << UART_IRCR_TH_Pos)

#define	UART_IRCR_TZBRG_Pos	0	/* �������Ƶ�� */
#define	UART_IRCR_TZBRG_Msk	(0x7ffU << UART_IRCR_TZBRG_Pos)

#define	UARTx_CSR_BUSY_Pos	24	/* UARTͨ�ű�־ */
#define	UARTx_CSR_BUSY_Msk	(0x1U << UARTx_CSR_BUSY_Pos)

#define	UARTx_CSR_TXIREN_Pos	17	/* ���ͺ������ʹ��λ */
#define	UARTx_CSR_TXIREN_Msk	(0x1U << UARTx_CSR_TXIREN_Pos)
	/* 0���رպ�����Ʒ��� */
	/* 1��ʹ�ܺ�����Ʒ��� */

#define	UARTx_CSR_RXTOEN_Pos	16	/* ���ճ�ʱʹ�� */
#define	UARTx_CSR_RXTOEN_Msk	(0x1U << UARTx_CSR_RXTOEN_Pos)
	/* 0���رս��ճ�ʱ���� */
	/* 1��ʹ�ܽ��ճ�ʱ���� */

#define	UARTx_CSR_NEWUP_Pos	11	/* UART RX�½��ػ��ѹ���ʹ�ܼĴ��� */
#define	UARTx_CSR_NEWUP_Msk	(0x1U << UARTx_CSR_NEWUP_Pos)
	/* 0����ֹRX�½��ػ��� */
	/* 1��ʹ��RX�½��ػ��� */

#define	UARTx_CSR_DMATXIFCFG_Pos	10	/* DMA��������ж�ʹ�ܣ�����UARTͨ��DMA���з���ʱ��Ч */
#define	UARTx_CSR_DMATXIFCFG_Msk	(0x1U << UARTx_CSR_DMATXIFCFG_Pos)
	/* 0���Ƿ������ж��ź��������IE���� */
	/* 1��IE=1������£�DMAģʽ�·��������һ֡�������ж��ź���������һ֮֡ǰ������֡������ɺ������ж��ź���� */

#define	UARTx_CSR_BITORD_Pos	9	/* ���ݷ���/����ʱ��λ˳�� */
#define	UARTx_CSR_BITORD_Msk	(0x1U << UARTx_CSR_BITORD_Pos)
#define	UARTx_CSR_BITORD_LSB	(0x0U << UARTx_CSR_BITORD_Pos)	/* 0��LSB first */
#define	UARTx_CSR_BITORD_MSB	(0x1U << UARTx_CSR_BITORD_Pos)	/* 1��MSB first */

#define	UARTx_CSR_STOPCFG_Pos	8	/* ֹͣλ������ã����Է���֡��ʽ��Ч������ʱ���ж�ֹͣλ���� */
#define	UARTx_CSR_STOPCFG_Msk	(0x1U << UARTx_CSR_STOPCFG_Pos)
#define	UARTx_CSR_STOPCFG_1STOPBIT	(0x0U << UARTx_CSR_STOPCFG_Pos)	/* 0��1λֹͣλ */
#define	UARTx_CSR_STOPCFG_2STOPBIT	(0x1U << UARTx_CSR_STOPCFG_Pos)	/* 1��2λֹͣλ */

#define	UARTx_CSR_PDSEL_Pos	6	/* ÿ֡�����ݳ���ѡ�񣻴˼Ĵ��������ݷ��ͺͽ���ͬʱ��Ч */
#define	UARTx_CSR_PDSEL_Msk	(0x3U << UARTx_CSR_PDSEL_Pos)
#define	UARTx_CSR_PDSEL_7BIT	(0x0U << UARTx_CSR_PDSEL_Pos)	/* 00��7λ���� */
#define	UARTx_CSR_PDSEL_8BIT	(0x1U << UARTx_CSR_PDSEL_Pos)	/* 01��8λ���� */
#define	UARTx_CSR_PDSEL_9BIT	(0x2U << UARTx_CSR_PDSEL_Pos)	/* 10��9λ���� */
#define	UARTx_CSR_PDSEL_6BIT	(0x3U << UARTx_CSR_PDSEL_Pos)	/* 11��6λ���� */

#define	UARTx_CSR_PARITY_Pos	4	/* У��λ���ã��˼Ĵ��������ݷ��ͺͽ���ͬʱ��Ч */
#define	UARTx_CSR_PARITY_Msk	(0x3U << UARTx_CSR_PARITY_Pos)
#define	UARTx_CSR_PARITY_NONE	(0x0U << UARTx_CSR_PARITY_Pos)	/* 00����У��λ */
#define	UARTx_CSR_PARITY_EVEN	(0x1U << UARTx_CSR_PARITY_Pos)	/* 01��żУ�� */
#define	UARTx_CSR_PARITY_ODD	(0x2U << UARTx_CSR_PARITY_Pos)	/* 10����У�� */

#define	UARTx_CSR_RXPOL_Pos	3	/* �������ݼ������� */
#define	UARTx_CSR_RXPOL_Msk	(0x1U << UARTx_CSR_RXPOL_Pos)
	/* 0������ */
	/* 1��ȡ�� */

#define	UARTx_CSR_TXPOL_Pos	2	/* �������ݼ������� */
#define	UARTx_CSR_TXPOL_Msk	(0x1U << UARTx_CSR_TXPOL_Pos)
	/* 0������ */
	/* 1��ȡ�� */

#define	UARTx_CSR_RXEN_Pos	1	/* ����ʹ�ܣ�1��Ч */
#define	UARTx_CSR_RXEN_Msk	(0x1U << UARTx_CSR_RXEN_Pos)
	/* 0����ֹ����ģ�� */
	/* 1��ʹ�ܽ���ģ�� */

#define	UARTx_CSR_TXEN_Pos	0	/* ����ʹ�ܣ�1��Ч */
#define	UARTx_CSR_TXEN_Msk	(0x1U << UARTx_CSR_TXEN_Pos)
	/* 0����ֹ����ģ�� */
	/* 1��ʹ�ܷ���ģ�� */

#define	UARTx_IER_RXTO_IE_Pos	11	/* ���ճ�ʱ�ж�ʹ�ܣ�1��Ч */
#define	UARTx_IER_RXTO_IE_Msk	(0x1U << UARTx_IER_RXTO_IE_Pos)
	/* 0����ֹ���ճ�ʱ�ж� */
	/* 1��ʹ�ܽ��ճ�ʱ�ж� */

#define	UARTx_IER_RXERR_IE_Pos	10	/* ���մ����ж�ʹ�ܣ�1��Ч */
#define	UARTx_IER_RXERR_IE_Msk	(0x1U << UARTx_IER_RXERR_IE_Pos)
	/* 0����ֹ���մ����ж� */
	/* 1��ʹ�ܽ��մ����ж� */

#define	UARTx_IER_RXBF_IE_Pos	8	/* ���ջ������ж�ʹ�ܣ�1��Ч */
#define	UARTx_IER_RXBF_IE_Msk	(0x1U << UARTx_IER_RXBF_IE_Pos)
	/* 0����ֹ���ջ������ж� */
	/* 1��ʹ�ܽ��ջ������ж� */

#define	UARTx_IER_NEWUP_IE_Pos	7	/* RX�½����첽����ж�ʹ�ܣ�1��Ч */
#define	UARTx_IER_NEWUP_IE_Msk	(0x1U << UARTx_IER_NEWUP_IE_Pos)
	/* 0����ֹRX�½����첽����ж� */
	/* 1��ʹ��RX�½����첽����ж� */

#define	UARTx_IER_TXBE_IE_Pos	1	/* ���ͻ�����ж�ʹ�ܣ�1��Ч */
#define	UARTx_IER_TXBE_IE_Msk	(0x1U << UARTx_IER_TXBE_IE_Pos)
	/* 0����ֹ���ͻ�����ж� */
	/* 1��ʹ�ܷ��ͻ�����ж� */

#define	UARTx_IER_TXSE_IE_Pos	0	/* ���ͻ�����ҷ�����λ�Ĵ������ж�ʹ�ܣ�1��Ч */
#define	UARTx_IER_TXSE_IE_Msk	(0x1U << UARTx_IER_TXSE_IE_Pos)
	/* 0����ֹ���ͻ�����ҷ�����λ�Ĵ������ж� */
	/* 1��ʹ�ܷ��ͻ�����ҷ�����λ�Ĵ������ж� */

#define	UARTx_ISR_PERR_Pos	18	/* ��żУ������жϱ�־��Ӳ����λ�����д1���� */
#define	UARTx_ISR_PERR_Msk	(0x1U << UARTx_ISR_PERR_Pos)

#define	UARTx_ISR_FERR_Pos	17	/* ֡��ʽ�����жϱ�־��Ӳ����λ�����д1���� */
#define	UARTx_ISR_FERR_Msk	(0x1U << UARTx_ISR_FERR_Pos)

#define	UARTx_ISR_OERR_Pos	16	/* ���ջ�����������жϱ�־�������ջ�����������£��յ��µ�����ʱ��λ��Ӳ����λ�����д1���߶�ȡRXBUFʱ����
�������ʱ�����ջ�������ԭ�е����ݱ������ݸ��� */
#define	UARTx_ISR_OERR_Msk	(0x1U << UARTx_ISR_OERR_Pos)

#define	UARTx_ISR_RXTO_Pos	11	/* ���ճ�ʱ�жϱ�־��Ӳ����λ�����д1���㣨��UART0��UART1��Ч�� */
#define	UARTx_ISR_RXTO_Msk	(0x1U << UARTx_ISR_RXTO_Pos)

#define	UARTx_ISR_RXBF_Pos	8	/* ���ջ������жϱ�־��Ӳ����λ�����д1���߶�ȡRXBUFʱ���� */
#define	UARTx_ISR_RXBF_Msk	(0x1U << UARTx_ISR_RXBF_Pos)

#define	UARTx_ISR_NEWKF_Pos	7	/* RX�½����첽����жϱ�־��Ӳ����λ�����д1���� */
#define	UARTx_ISR_NEWKF_Msk	(0x1U << UARTx_ISR_NEWKF_Pos)

#define	UARTx_ISR_TXBE_Pos	1	/* ���ͻ�����жϱ�־��Ӳ����λ�����д��TXBUFʱ���� */
#define	UARTx_ISR_TXBE_Msk	(0x1U << UARTx_ISR_TXBE_Pos)

#define	UARTx_ISR_TXSE_Pos	0	/* ���ͻ��������λ�Ĵ�����������жϱ�־��Ӳ����λ�����д1�������д���ͻ���ʱ���� */
#define	UARTx_ISR_TXSE_Msk	(0x1U << UARTx_ISR_TXSE_Pos)

#define	UARTx_TODR_TXDLY_LEN_Pos	8	/* �����ӳ٣����255baud */
#define	UARTx_TODR_TXDLY_LEN_Msk	(0xffU << UARTx_TODR_TXDLY_LEN_Pos)

#define	UARTx_TODR_RXTO_LEN_Pos	0
#define	UARTx_TODR_RXTO_LEN_Msk	(0xffU << UARTx_TODR_RXTO_LEN_Pos)

#define	UARTx_RXBUF_RXBUF_Pos	0	/* �������ݻ���Ĵ������� */
#define	UARTx_RXBUF_RXBUF_Msk	(0x1ffU << UARTx_RXBUF_RXBUF_Pos)

#define	UARTx_TXBUF_TXBUF_Pos	0	/* �������ݻ���Ĵ������� */
#define	UARTx_TXBUF_TXBUF_Msk	(0x1ffU << UARTx_TXBUF_TXBUF_Pos)

#define	UARTx_BGR_SPBRG_Pos	0	/* �����ʲ������Ĵ���ֵ */
#define	UARTx_BGR_SPBRG_Msk	(0xffffU << UARTx_BGR_SPBRG_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void UART_Deinit(void);

/* ���ƺ�����Ʒ�������ʱ��Ĭ��������� ��غ��� */
extern void UART_IRCR_IRFLAG_Setable(FunState NewState);
extern FunState UART_IRCR_IRFLAG_Getable(void);

/* ����ռ�ձȵ��Ʋ��� ��غ��� */
extern void UART_IRCR_TH_Set(uint32_t SetValue);
extern uint32_t UART_IRCR_TH_Get(void);

/* �������Ƶ�� ��غ��� */
extern void UART_IRCR_TZBRG_Set(uint32_t SetValue);
extern uint32_t UART_IRCR_TZBRG_Get(void);
extern void UARTx_Deinit(UART_Type* UARTx);

/* UARTͨ�ű�־ ��غ��� */
extern FlagStatus UARTx_CSR_BUSY_Chk(UART_Type* UARTx);

/* ���ͺ������ʹ��λ ��غ��� */
extern void UARTx_CSR_TXIREN_Setable(UART_Type* UARTx, FunState NewState);
extern FunState UARTx_CSR_TXIREN_Getable(UART_Type* UARTx);

/* ���ճ�ʱʹ�� ��غ��� */
extern void UARTx_CSR_RXTOEN_Setable(UART_Type* UARTx, FunState NewState);
extern FunState UARTx_CSR_RXTOEN_Getable(UART_Type* UARTx);

/* UART RX�½��ػ��ѹ���ʹ�ܼĴ��� ��غ��� */
extern void UARTx_CSR_NEWUP_Setable(UART_Type* UARTx, FunState NewState);
extern FunState UARTx_CSR_NEWUP_Getable(UART_Type* UARTx);

/* DMA��������ж�ʹ�ܣ�����UARTͨ��DMA���з���ʱ��Ч ��غ��� */
extern void UARTx_CSR_DMATXIFCFG_Setable(UART_Type* UARTx, FunState NewState);
extern FunState UARTx_CSR_DMATXIFCFG_Getable(UART_Type* UARTx);

/* ���ݷ���/����ʱ��λ˳�� ��غ��� */
extern void UARTx_CSR_BITORD_Set(UART_Type* UARTx, uint32_t SetValue);
extern uint32_t UARTx_CSR_BITORD_Get(UART_Type* UARTx);

/* ֹͣλ������ã����Է���֡��ʽ��Ч������ʱ���ж�ֹͣλ���� ��غ��� */
extern void UARTx_CSR_STOPCFG_Set(UART_Type* UARTx, uint32_t SetValue);
extern uint32_t UARTx_CSR_STOPCFG_Get(UART_Type* UARTx);

/* ÿ֡�����ݳ���ѡ�񣻴˼Ĵ��������ݷ��ͺͽ���ͬʱ��Ч ��غ��� */
extern void UARTx_CSR_PDSEL_Set(UART_Type* UARTx, uint32_t SetValue);
extern uint32_t UARTx_CSR_PDSEL_Get(UART_Type* UARTx);

/* У��λ���ã��˼Ĵ��������ݷ��ͺͽ���ͬʱ��Ч ��غ��� */
extern void UARTx_CSR_PARITY_Set(UART_Type* UARTx, uint32_t SetValue);
extern uint32_t UARTx_CSR_PARITY_Get(UART_Type* UARTx);

/* �������ݼ������� ��غ��� */
extern void UARTx_CSR_RXPOL_Setable(UART_Type* UARTx, FunState NewState);
extern FunState UARTx_CSR_RXPOL_Getable(UART_Type* UARTx);

/* �������ݼ������� ��غ��� */
extern void UARTx_CSR_TXPOL_Setable(UART_Type* UARTx, FunState NewState);
extern FunState UARTx_CSR_TXPOL_Getable(UART_Type* UARTx);

/* ����ʹ�ܣ�1��Ч ��غ��� */
extern void UARTx_CSR_RXEN_Setable(UART_Type* UARTx, FunState NewState);
extern FunState UARTx_CSR_RXEN_Getable(UART_Type* UARTx);

/* ����ʹ�ܣ�1��Ч ��غ��� */
extern void UARTx_CSR_TXEN_Setable(UART_Type* UARTx, FunState NewState);
extern FunState UARTx_CSR_TXEN_Getable(UART_Type* UARTx);

/* ���ճ�ʱ�ж�ʹ�ܣ�1��Ч ��غ��� */
extern void UARTx_IER_RXTO_IE_Setable(UART_Type* UARTx, FunState NewState);
extern FunState UARTx_IER_RXTO_IE_Getable(UART_Type* UARTx);

/* ���մ����ж�ʹ�ܣ�1��Ч ��غ��� */
extern void UARTx_IER_RXERR_IE_Setable(UART_Type* UARTx, FunState NewState);
extern FunState UARTx_IER_RXERR_IE_Getable(UART_Type* UARTx);

/* ���ջ������ж�ʹ�ܣ�1��Ч ��غ��� */
extern void UARTx_IER_RXBF_IE_Setable(UART_Type* UARTx, FunState NewState);
extern FunState UARTx_IER_RXBF_IE_Getable(UART_Type* UARTx);

/* RX�½����첽����ж�ʹ�ܣ�1��Ч ��غ��� */
extern void UARTx_IER_NEWUP_IE_Setable(UART_Type* UARTx, FunState NewState);
extern FunState UARTx_IER_NEWUP_IE_Getable(UART_Type* UARTx);

/* ���ͻ�����ж�ʹ�ܣ�1��Ч ��غ��� */
extern void UARTx_IER_TXBE_IE_Setable(UART_Type* UARTx, FunState NewState);
extern FunState UARTx_IER_TXBE_IE_Getable(UART_Type* UARTx);

/* ���ͻ�����ҷ�����λ�Ĵ������ж�ʹ�ܣ�1��Ч ��غ��� */
extern void UARTx_IER_TXSE_IE_Setable(UART_Type* UARTx, FunState NewState);
extern FunState UARTx_IER_TXSE_IE_Getable(UART_Type* UARTx);

/* ��żУ������жϱ�־��Ӳ����λ�����д1���� ��غ��� */
extern void UARTx_ISR_PERR_Clr(UART_Type* UARTx);
extern FlagStatus UARTx_ISR_PERR_Chk(UART_Type* UARTx);

/* ֡��ʽ�����жϱ�־��Ӳ����λ�����д1���� ��غ��� */
extern void UARTx_ISR_FERR_Clr(UART_Type* UARTx);
extern FlagStatus UARTx_ISR_FERR_Chk(UART_Type* UARTx);

/* ���ջ�����������жϱ�־�������ջ�����������£��յ��µ�����ʱ��λ��Ӳ����λ�����д1���߶�ȡRXBUFʱ����
�������ʱ�����ջ�������ԭ�е����ݱ������ݸ��� ��غ��� */
extern void UARTx_ISR_OERR_Clr(UART_Type* UARTx);
extern FlagStatus UARTx_ISR_OERR_Chk(UART_Type* UARTx);

/* ���ճ�ʱ�жϱ�־��Ӳ����λ�����д1���㣨��UART0��UART1��Ч�� ��غ��� */
extern void UARTx_ISR_RXTO_Clr(UART_Type* UARTx);
extern FlagStatus UARTx_ISR_RXTO_Chk(UART_Type* UARTx);

/* ���ջ������жϱ�־��Ӳ����λ�����д1���߶�ȡRXBUFʱ���� ��غ��� */
extern void UARTx_ISR_RXBF_Clr(UART_Type* UARTx);
extern FlagStatus UARTx_ISR_RXBF_Chk(UART_Type* UARTx);

/* RX�½����첽����жϱ�־��Ӳ����λ�����д1���� ��غ��� */
extern void UARTx_ISR_NEWKF_Clr(UART_Type* UARTx);
extern FlagStatus UARTx_ISR_NEWKF_Chk(UART_Type* UARTx);

/* ���ͻ�����жϱ�־��Ӳ����λ�����д��TXBUFʱ���� ��غ��� */
extern void UARTx_ISR_TXBE_Clr(UART_Type* UARTx);
extern FlagStatus UARTx_ISR_TXBE_Chk(UART_Type* UARTx);

/* ���ͻ��������λ�Ĵ�����������жϱ�־��Ӳ����λ�����д1�������д���ͻ���ʱ���� ��غ��� */
extern void UARTx_ISR_TXSE_Clr(UART_Type* UARTx);
extern FlagStatus UARTx_ISR_TXSE_Chk(UART_Type* UARTx);

/* �����ӳ٣����255baud ��غ��� */
extern void UARTx_TODR_TXDLY_LEN_Set(UART_Type* UARTx, uint32_t SetValue);
extern uint32_t UARTx_TODR_TXDLY_LEN_Get(UART_Type* UARTx);
extern void UARTx_TODR_RXTO_LEN_Set(UART_Type* UARTx, uint32_t SetValue);
extern uint32_t UARTx_TODR_RXTO_LEN_Get(UART_Type* UARTx);

/* �������ݻ���Ĵ������� ��غ��� */
extern uint32_t UARTx_RXBUF_Read(UART_Type* UARTx);

/* �������ݻ���Ĵ������� ��غ��� */
extern void UARTx_TXBUF_Write(UART_Type* UARTx, uint32_t SetValue);

/* �����ʲ������Ĵ���ֵ ��غ��� */
extern void UARTx_BGR_Write(UART_Type* UARTx, uint32_t SetValue);
extern uint32_t UARTx_BGR_Read(UART_Type* UARTx);

/* �������Ƶ�ʣ�ռ�ձ� ���� */
extern void UART_IRModulation_Init( uint32_t ModuFreq, uint8_t ModuDutyCycle, uint32_t APBClk );

/* UART����������ʼ������ */
extern void UART_Init(UART_Type* UARTx, UART_InitTypeDef* para);

/* uart�����ʼĴ���ֵ���㺯�� */
extern void UARTx_SPBRG_Write(UART_Type* UARTx, uint32_t SetValue);

/* UART�򵥲�����ʼ������ */
extern void UART_SInit(UART_Type* UARTx, UART_SInitTypeDef* para, uint32_t APBClk);
#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_UART_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
