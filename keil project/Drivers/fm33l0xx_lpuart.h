/**
  ******************************************************************************
  * @file    fm33l0xx_lpuart.h
  * @author  FM33L0xx Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file contains all the functions prototypes for the LPUART firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33L0XX_LPUART_H
#define __FM33L0XX_LPUART_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33L0XX.h" 
#include "fm33l0xx_uart.h" 
   
//-----------------------------------------------------------------------------------------------------------------------------
typedef struct
{
	uint32_t				BaudRate;		//������
	UART_DataBitTypeDef		DataBit;		//����λ��
	UART_ParityBitTypeDef	ParityBit; 		//У��λ
	UART_StopBitTypeDef		StopBit;		//ֹͣλ
	
}LPUART_SInitTypeDef;	

typedef struct
{
	uint32_t				BAUD;	//�����ʿ���
	FunState				TXEN;		//����ʹ��
	FunState				RXEN;		//����ʹ��
	uint32_t				MATD;	//����ƥ��Ĵ���
	uint32_t				MCTL;		//���ƿ��ƼĴ���
	
	uint32_t				STOPCFG;			//ֹͣλ����
	uint32_t				PDSEL;			//���ݳ���
	uint32_t				PARITY;		//У��λ����
	
	uint32_t				RXEV;		//�����ж��¼�����
  
  FunState				RXEVIE;		//���ջ����¼��ж�
	FunState				TXSEIE;		//���ͻ�������λ�Ĵ������ж�
	FunState				TXBEIE;		//����buffer���ж�
	FunState				RXBFIE;		//���ջ������ж�
	FunState				TXPOL;		//���ݷ��ͼ���ȡ��ʹ��
	FunState				RXPOL;		//���ݽ��ռ���ȡ������
	FunState				WKBYTECFG;	//���ݻ�����������
	FunState				RXERRIE;		//���մ����ж�ʹ��
	
}LPUART_InitTypeDef;

#define LPU_LSCLK    RCC_OPC_CR1_LPUART1CKS_LSCLK
#define LPU_RCHFDIV  RCC_OPC_CR1_LPUART1CKS_RCHFDIV
#define LPU_RC4MDIV  RCC_OPC_CR1_LPUART1CKS_RC4MDIV

#define LPUARTx_MCTL_FOR9600 (0x00000552<<16)
#define LPUARTx_MCTL_FOR4800 (0x00001EFB<<16)
#define LPUARTx_MCTL_FOR2400 (0x000016DB<<16)
#define LPUARTx_MCTL_FOR1200 (0x00000492<<16)
#define LPUARTx_MCTL_FOR600  (0x000016D6<<16)
#define LPUARTx_MCTL_FOR300  (0x00000842<<16)


#define	LPUARTx_CSR_BUSY_Pos	24	/* ͨ��״̬ */
#define	LPUARTx_CSR_BUSY_Msk	(0x1U << LPUARTx_CSR_BUSY_Pos)

#define	LPUARTx_CSR_WKBYTECFG_Pos	19	/* ���ݽ��ջ����������� */
#define	LPUARTx_CSR_WKBYTECFG_Msk	(0x1U << LPUARTx_CSR_WKBYTECFG_Pos)
	/* 0 = ����ʱ����1�ֽھͻỽ�ѣ���У����ż��ֹͣλ */
	/* 1 = ����ʱ����1�ֽڣ�����У����ż��ֹͣλ��ȷ�Ż��� */

#define	LPUARTx_CSR_RXEV_Pos	16	/* �����ж��¼����� */
#define	LPUARTx_CSR_RXEV_Msk	(0x3U << LPUARTx_CSR_RXEV_Pos)
#define	LPUARTx_CSR_RXEV_FALLING	(0x3U << LPUARTx_CSR_RXEV_Pos)	/* 11 = RXD�½��ؼ�⻽�� */
#define	LPUARTx_CSR_RXEV_MATCH	(0x2U << LPUARTx_CSR_RXEV_Pos)	/* 10 = ��������ƥ��ɹ����� */
#define	LPUARTx_CSR_RXEV_1BYTE	(0x1U << LPUARTx_CSR_RXEV_Pos)	/* 01 = 1 BYTE���ݽ�����ɻ��� */
#define	LPUARTx_CSR_RXEV_START	(0x0U << LPUARTx_CSR_RXEV_Pos)	/* 00 = STARTλ��⻽�� */

#define	LPUARTx_CSR_DMATXIFCFG_Pos	10	/* DMA��������ж�ʹ�� */
#define	LPUARTx_CSR_DMATXIFCFG_Msk	(0x1U << LPUARTx_CSR_DMATXIFCFG_Pos)
	/* 0 = �Ƿ������ж��ź��������IE���� */
	/* 1 = IEΪ1ʱ��DMA���������һ֡�����ж��ź���� */

#define	LPUARTx_CSR_BITORD_Pos	9	/* ���ݷ��ͺͽ��յ�λ˳�� */
#define	LPUARTx_CSR_BITORD_Msk	(0x1U << LPUARTx_CSR_BITORD_Pos)
#define	LPUARTx_CSR_BITORD_LSB	(0x0U << LPUARTx_CSR_BITORD_Pos)	/* 0 = LSB first */
#define	LPUARTx_CSR_BITORD_MSB	(0x1U << LPUARTx_CSR_BITORD_Pos)	/* 1 = MSB first */

#define	LPUARTx_CSR_STOPCFG_Pos	8	/* ����ʱֹͣλ���� */
#define	LPUARTx_CSR_STOPCFG_Msk	(0x1U << LPUARTx_CSR_STOPCFG_Pos)
#define	LPUARTx_CSR_STOPCFG_1BIT	(0x0U << LPUARTx_CSR_STOPCFG_Pos)	/* 0 = 1bitֹͣλ */
#define	LPUARTx_CSR_STOPCFG_2BIT	(0x1U << LPUARTx_CSR_STOPCFG_Pos)	/* 1 = 2bitֹͣλ */

#define	LPUARTx_CSR_PDSEL_Pos	6	/* ÿ֡���ݳ��� */
#define	LPUARTx_CSR_PDSEL_Msk	(0x3U << LPUARTx_CSR_PDSEL_Pos)
#define	LPUARTx_CSR_PDSEL_6BIT	(0x3U << LPUARTx_CSR_PDSEL_Pos)	/* 11 = 6bitֹͣλ */
#define	LPUARTx_CSR_PDSEL_9BIT	(0x2U << LPUARTx_CSR_PDSEL_Pos)	/* 10 = 9bitֹͣλ */
#define	LPUARTx_CSR_PDSEL_8BIT	(0x1U << LPUARTx_CSR_PDSEL_Pos)	/* 01 = 8bitֹͣλ */
#define	LPUARTx_CSR_PDSEL_7BIT	(0x0U << LPUARTx_CSR_PDSEL_Pos)	/* 00 = 7bitֹͣλ */

#define	LPUARTx_CSR_PARITY_Pos	4	/* У��λ���� */
#define	LPUARTx_CSR_PARITY_Msk	(0x3U << LPUARTx_CSR_PARITY_Pos)
#define	LPUARTx_CSR_PARITY_ODD	(0x2U << LPUARTx_CSR_PARITY_Pos)	/* 10 = ��У�� */
#define	LPUARTx_CSR_PARITY_EVEN	(0x1U << LPUARTx_CSR_PARITY_Pos)	/* 01 = żУ�� */
#define	LPUARTx_CSR_PARITY_NONE	(0x0U << LPUARTx_CSR_PARITY_Pos)	/* 00 = ��У�� */

#define	LPUARTx_CSR_RXPOL_Pos	3	/* �������ݼ��� */
#define	LPUARTx_CSR_RXPOL_Msk	(0x1U << LPUARTx_CSR_RXPOL_Pos)
#define	LPUARTx_CSR_RXPOL_POSITIVE	(0x0U << LPUARTx_CSR_RXPOL_Pos)	/* 0 = ���� */
#define	LPUARTx_CSR_RXPOL_NEGATION	(0x1U << LPUARTx_CSR_RXPOL_Pos)	/* 1 = ȡ�� */

#define	LPUARTx_CSR_TXPOL_Pos	2	/* �������ݼ��� */
#define	LPUARTx_CSR_TXPOL_Msk	(0x1U << LPUARTx_CSR_TXPOL_Pos)
#define	LPUARTx_CSR_TXPOL_POSITIVE	(0x0U << LPUARTx_CSR_TXPOL_Pos)	/* 0 = ���� */
#define	LPUARTx_CSR_TXPOL_NEGATION	(0x1U << LPUARTx_CSR_TXPOL_Pos)	/* 1 = ȡ�� */

#define	LPUARTx_CSR_RXEN_Pos	1	/* ����ʹ�ܿ��� */
#define	LPUARTx_CSR_RXEN_Msk	(0x1U << LPUARTx_CSR_RXEN_Pos)
	/* 0 = ��ֹ */
	/* 1 = ʹ�� */

#define	LPUARTx_CSR_TXEN_Pos	0	/* ����ʹ�ܿ��� */
#define	LPUARTx_CSR_TXEN_Msk	(0x1U << LPUARTx_CSR_TXEN_Pos)
	/* 0 = ��ֹ */
	/* 1 = ʹ�� */

#define	LPUARTx_IER_RXEV_IE_Pos	12	/* ���ջ����¼��ж�ʹ�� */
#define	LPUARTx_IER_RXEV_IE_Msk	(0x1U << LPUARTx_IER_RXEV_IE_Pos)
	/* 0 = ��ֹ */
	/* 1 = ʹ�� */

#define	LPUARTx_IER_RXERR_IE_Pos	10	/* ���մ����ж�ʹ�� */
#define	LPUARTx_IER_RXERR_IE_Msk	(0x1U << LPUARTx_IER_RXERR_IE_Pos)
	/* 0 = ��ֹ */
	/* 1 = ʹ�� */

#define	LPUARTx_IER_RXBF_IE_Pos	8	/* ���ջ������ж�ʹ�� */
#define	LPUARTx_IER_RXBF_IE_Msk	(0x1U << LPUARTx_IER_RXBF_IE_Pos)
	/* 0 = ��ֹ */
	/* 1 = ʹ�� */

#define	LPUARTx_IER_TXBE_IE_Pos	1	/* ���ͻ�����ж�ʹ�� */
#define	LPUARTx_IER_TXBE_IE_Msk	(0x1U << LPUARTx_IER_TXBE_IE_Pos)
	/* 0 = ��ֹ */
	/* 1 = ʹ�� */

#define	LPUARTx_IER_TXSE_IE_Pos	0	/* ���ͻ�����ҷ�����λ�Ĵ������ж�ʹ�� */
#define	LPUARTx_IER_TXSE_IE_Msk	(0x1U << LPUARTx_IER_TXSE_IE_Pos)
	/* 0 = ��ֹ */
	/* 1 = ʹ�� */

#define	LPUARTx_ISR_RXEVF_Pos	24	/* ���ջ����¼��жϱ�־ */
#define	LPUARTx_ISR_RXEVF_Msk	(0x1U << LPUARTx_ISR_RXEVF_Pos)

#define	LPUARTx_ISR_TXOV_Pos	19	/* ���ͻ�����������־ */
#define	LPUARTx_ISR_TXOV_Msk	(0x1U << LPUARTx_ISR_TXOV_Pos)

#define	LPUARTx_ISR_PERR_Pos	18	/* ��żУ������жϱ�־ */
#define	LPUARTx_ISR_PERR_Msk	(0x1U << LPUARTx_ISR_PERR_Pos)

#define	LPUARTx_ISR_FERR_Pos	17	/* ֡��ʽ�����жϱ�־ */
#define	LPUARTx_ISR_FERR_Msk	(0x1U << LPUARTx_ISR_FERR_Pos)

#define	LPUARTx_ISR_OERR_Pos	16	/* ���ջ�����������жϱ�־ */
#define	LPUARTx_ISR_OERR_Msk	(0x1U << LPUARTx_ISR_OERR_Pos)

#define	LPUARTx_ISR_RXBF_Pos	8	/* ���ջ������жϱ�־ */
#define	LPUARTx_ISR_RXBF_Msk	(0x1U << LPUARTx_ISR_RXBF_Pos)

#define	LPUARTx_ISR_TXBE_Pos	1	/* ���ͻ�����жϱ�־ */
#define	LPUARTx_ISR_TXBE_Msk	(0x1U << LPUARTx_ISR_TXBE_Pos)

#define	LPUARTx_ISR_TXSE_Pos	0	/* ���ͻ�����ҷ�����λ�Ĵ������жϱ�־ */
#define	LPUARTx_ISR_TXSE_Msk	(0x1U << LPUARTx_ISR_TXSE_Pos)

#define	LPUARTx_BMR_MCTL_Pos	16	/* ÿ��bit��λ����ƿ����ź� */
#define	LPUARTx_BMR_MCTL_Msk	(0x1fffU << LPUARTx_BMR_MCTL_Pos)

#define	LPUARTx_BMR_BAUD_Pos	0	/* �����ʿ��� */
#define	LPUARTx_BMR_BAUD_Msk	(0x7U << LPUARTx_BMR_BAUD_Pos)
#define	LPUARTx_BMR_BAUD_300	(0x5U << LPUARTx_BMR_BAUD_Pos)	/* 101\110\111 = 300bps */
#define	LPUARTx_BMR_BAUD_600	(0x4U << LPUARTx_BMR_BAUD_Pos)	/* 100=600bps */
#define	LPUARTx_BMR_BAUD_1200	(0x3U << LPUARTx_BMR_BAUD_Pos)	/* 011=1200bps */
#define	LPUARTx_BMR_BAUD_2400	(0x2U << LPUARTx_BMR_BAUD_Pos)	/* 010=2400bps */
#define	LPUARTx_BMR_BAUD_4800	(0x1U << LPUARTx_BMR_BAUD_Pos)	/* 001=4800bps */
#define	LPUARTx_BMR_BAUD_9600	(0x0U << LPUARTx_BMR_BAUD_Pos)	/* 000=9600bps */

#define	LPUARTx_RXBUF_RXBUF_Pos	0	/* �������ݻ��� */
#define	LPUARTx_RXBUF_RXBUF_Msk	(0x1ffU << LPUARTx_RXBUF_RXBUF_Pos)

#define	LPUARTx_TXBUF_TXBUF_Pos	0	/* �������ݻ��� */
#define	LPUARTx_TXBUF_TXBUF_Msk	(0x1ffU << LPUARTx_TXBUF_TXBUF_Pos)

#define	LPUARTx_DMR_MATD_Pos	0	/* ����ƥ��Ĵ��� */
#define	LPUARTx_DMR_MATD_Msk	(0x1ffU << LPUARTx_DMR_MATD_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void LPUARTx_Deinit(LPUART_Type* LPUARTx);

/* ͨ��״̬ ��غ��� */
extern FlagStatus LPUARTx_CSR_BUSY_Chk(LPUART_Type* LPUARTx);

/* ���ݽ��ջ����������� ��غ��� */
extern void LPUARTx_CSR_WKBYTECFG_Setable(LPUART_Type* LPUARTx, FunState NewState);
extern FunState LPUARTx_CSR_WKBYTECFG_Getable(LPUART_Type* LPUARTx);

/* �����ж��¼����� ��غ��� */
extern void LPUARTx_CSR_RXEV_Set(LPUART_Type* LPUARTx, uint32_t SetValue);
extern uint32_t LPUARTx_CSR_RXEV_Get(LPUART_Type* LPUARTx);

/* DMA��������ж�ʹ�� ��غ��� */
extern void LPUARTx_CSR_DMATXIFCFG_Setable(LPUART_Type* LPUARTx, FunState NewState);
extern FunState LPUARTx_CSR_DMATXIFCFG_Getable(LPUART_Type* LPUARTx);

/* ���ݷ��ͺͽ��յ�λ˳�� ��غ��� */
extern void LPUARTx_CSR_BITORD_Set(LPUART_Type* LPUARTx, uint32_t SetValue);
extern uint32_t LPUARTx_CSR_BITORD_Get(LPUART_Type* LPUARTx);

/* ����ʱֹͣλ���� ��غ��� */
extern void LPUARTx_CSR_STOPCFG_Set(LPUART_Type* LPUARTx, uint32_t SetValue);
extern uint32_t LPUARTx_CSR_STOPCFG_Get(LPUART_Type* LPUARTx);

/* ÿ֡���ݳ��� ��غ��� */
extern void LPUARTx_CSR_PDSEL_Set(LPUART_Type* LPUARTx, uint32_t SetValue);
extern uint32_t LPUARTx_CSR_PDSEL_Get(LPUART_Type* LPUARTx);

/* У��λ���� ��غ��� */
extern void LPUARTx_CSR_PARITY_Set(LPUART_Type* LPUARTx, uint32_t SetValue);
extern uint32_t LPUARTx_CSR_PARITY_Get(LPUART_Type* LPUARTx);

/* �������ݼ��� ��غ��� */
extern void LPUARTx_CSR_RXPOL_Set(LPUART_Type* LPUARTx, uint32_t SetValue);
extern uint32_t LPUARTx_CSR_RXPOL_Get(LPUART_Type* LPUARTx);

/* �������ݼ��� ��غ��� */
extern void LPUARTx_CSR_TXPOL_Set(LPUART_Type* LPUARTx, uint32_t SetValue);
extern uint32_t LPUARTx_CSR_TXPOL_Get(LPUART_Type* LPUARTx);

/* ����ʹ�ܿ��� ��غ��� */
extern void LPUARTx_CSR_RXEN_Setable(LPUART_Type* LPUARTx, FunState NewState);
extern FunState LPUARTx_CSR_RXEN_Getable(LPUART_Type* LPUARTx);

/* ����ʹ�ܿ��� ��غ��� */
extern void LPUARTx_CSR_TXEN_Setable(LPUART_Type* LPUARTx, FunState NewState);
extern FunState LPUARTx_CSR_TXEN_Getable(LPUART_Type* LPUARTx);

/* ���ջ����¼��ж�ʹ�� ��غ��� */
extern void LPUARTx_IER_RXEV_IE_Setable(LPUART_Type* LPUARTx, FunState NewState);
extern FunState LPUARTx_IER_RXEV_IE_Getable(LPUART_Type* LPUARTx);

/* ���մ����ж�ʹ�� ��غ��� */
extern void LPUARTx_IER_RXERR_IE_Setable(LPUART_Type* LPUARTx, FunState NewState);
extern FunState LPUARTx_IER_RXERR_IE_Getable(LPUART_Type* LPUARTx);

/* ���ջ������ж�ʹ�� ��غ��� */
extern void LPUARTx_IER_RXBF_IE_Setable(LPUART_Type* LPUARTx, FunState NewState);
extern FunState LPUARTx_IER_RXBF_IE_Getable(LPUART_Type* LPUARTx);

/* ���ͻ�����ж�ʹ�� ��غ��� */
extern void LPUARTx_IER_TXBE_IE_Setable(LPUART_Type* LPUARTx, FunState NewState);
extern FunState LPUARTx_IER_TXBE_IE_Getable(LPUART_Type* LPUARTx);

/* ���ͻ�����ҷ�����λ�Ĵ������ж�ʹ�� ��غ��� */
extern void LPUARTx_IER_TXSE_IE_Setable(LPUART_Type* LPUARTx, FunState NewState);
extern FunState LPUARTx_IER_TXSE_IE_Getable(LPUART_Type* LPUARTx);

/* ���ջ����¼��жϱ�־ ��غ��� */
extern void LPUARTx_ISR_RXEVF_Clr(LPUART_Type* LPUARTx);
extern FlagStatus LPUARTx_ISR_RXEVF_Chk(LPUART_Type* LPUARTx);

/* ���ͻ�����������־ ��غ��� */
extern void LPUARTx_ISR_TXOV_Clr(LPUART_Type* LPUARTx);
extern FlagStatus LPUARTx_ISR_TXOV_Chk(LPUART_Type* LPUARTx);

/* ��żУ������жϱ�־ ��غ��� */
extern void LPUARTx_ISR_PERR_Clr(LPUART_Type* LPUARTx);
extern FlagStatus LPUARTx_ISR_PERR_Chk(LPUART_Type* LPUARTx);

/* ֡��ʽ�����жϱ�־ ��غ��� */
extern void LPUARTx_ISR_FERR_Clr(LPUART_Type* LPUARTx);
extern FlagStatus LPUARTx_ISR_FERR_Chk(LPUART_Type* LPUARTx);

/* ���ջ�����������жϱ�־ ��غ��� */
extern void LPUARTx_ISR_OERR_Clr(LPUART_Type* LPUARTx);
extern FlagStatus LPUARTx_ISR_OERR_Chk(LPUART_Type* LPUARTx);

/* ���ջ������жϱ�־ ��غ��� */
extern void LPUARTx_ISR_RXBF_Clr(LPUART_Type* LPUARTx);
extern FlagStatus LPUARTx_ISR_RXBF_Chk(LPUART_Type* LPUARTx);

/* ���ͻ�����жϱ�־ ��غ��� */
extern FlagStatus LPUARTx_ISR_TXBE_Chk(LPUART_Type* LPUARTx);

/* ���ͻ�����ҷ�����λ�Ĵ������жϱ�־ ��غ��� */
extern void LPUARTx_ISR_TXSE_Clr(LPUART_Type* LPUARTx);
extern FlagStatus LPUARTx_ISR_TXSE_Chk(LPUART_Type* LPUARTx);

/* ÿ��bit��λ����ƿ����ź� ��غ��� */
extern void LPUARTx_BMR_MCTL_Set(LPUART_Type* LPUARTx, uint32_t SetValue);
extern uint32_t LPUARTx_BMR_MCTL_Get(LPUART_Type* LPUARTx);

/* �����ʿ��� ��غ��� */
extern void LPUARTx_BMR_BAUD_Set(LPUART_Type* LPUARTx, uint32_t SetValue);
extern uint32_t LPUARTx_BMR_BAUD_Get(LPUART_Type* LPUARTx);

/* �������ݻ��� ��غ��� */
extern uint32_t LPUARTx_RXBUF_Read(LPUART_Type* LPUARTx);

/* �������ݻ��� ��غ��� */
extern void LPUARTx_TXBUF_Write(LPUART_Type* LPUARTx, uint32_t SetValue);

/* ����ƥ��Ĵ��� ��غ��� */
extern void LPUARTx_DMR_Write(LPUART_Type* LPUARTx, uint32_t SetValue);
extern uint32_t LPUARTx_DMR_Read(LPUART_Type* LPUARTx);

extern void LPUART_SInit(LPUART_Type* LPUARTx,LPUART_SInitTypeDef* para);
extern void LPUART_Init(LPUART_Type* LPUARTx,LPUART_InitTypeDef* para);
#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_LPUART_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
