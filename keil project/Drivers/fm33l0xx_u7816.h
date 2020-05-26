/**
  ******************************************************************************
  * @file    fm33l0xx_u7816.h
  * @author  FM33L0xx Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file contains all the functions prototypes for the U7816 firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33L0XX_U7816_H
#define __FM33L0XX_U7816_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33L0XX.h"

//------------------------------------------------------------------------------
typedef struct
{
	FunState				TXEN;		//����ʹ��
	FunState				RXEN;		//����ʹ��
	FunState				CKOEN;		//U7816ʱ��CLK���ʹ�ܿ���
	FunState				HPUAT;		//U7816ͨ�����ݷ���ǿ���������Զ���Ч����
	FunState				HPUEN;		//U7816ͨ��ǿ����ʹ�ܿ���
	
	uint32_t				ERSW;		//ERROR SIGNAL���ѡ��
	uint32_t				ERSGD;		//ERROR SIGNAL��GUARDTIME���ѡ�񣨽��ڷ���ʱ��Ч��
	FunState				BGTEN;		//BGT��block guard time������
	uint32_t				REP_T;		//���ƽ���������żУ�����ʱ�Զ��ط�����
	uint32_t				PAR;		//��żУ������ѡ��
	uint32_t				RFREN;		//Guard Time���ȿ���λ������ʱ�ϸ���Э��2etu��
  uint32_t				SFREN;		//Guard Time���ȿ���λ������ʱ�ϸ���Э��2etu��
	FunState				TREPEN;		//������������żУ���Ĵ���ʽѡ��
	FunState				RREPEN;		//����������żУ���Ĵ���ʽѡ��
	FunState				DICONV;		//������������ʹ��
	
	uint32_t				TXEGT;		//����ʱ�����EGTʱ�䣨��ETUΪ��λ��
	uint32_t				CLKDIV;		//U7816ʱ�������Ƶ���ƼĴ���
	uint32_t				PDIV;		//U7816Ԥ��Ƶ���ƼĴ���������7816ͨ�ŷ�Ƶ�ȣ������ʣ�
	
	FunState				RXIE;		//���ݽ����ж�ʹ��λ����ӦRX_FLAG�жϱ�־λ
	FunState				TXIE;		//���ݷ����ж�ʹ��λ����ӦTX_FLAG�жϱ�־λ
	FunState				LSIE;		//��·״̬�ж�ʹ��λ����ӦERROR_FLAG�жϱ�־λ
	
}U7816_InitTypeDef;

#define	U7816_CR_TXEN_Pos	5	/* U7816ͨ������ʹ�ܿ��� */
#define	U7816_CR_TXEN_Msk	(0x1U << U7816_CR_TXEN_Pos)
	/* 0 = ͨ�����ͽ�ֹ�����ɷ������ݣ����ض�����˿� */
	/* 1 = ͨ������ʹ�ܣ��ɷ������� */

#define	U7816_CR_RXEN_Pos	4	/* U7816ͨ������ʹ�ܿ��� */
#define	U7816_CR_RXEN_Msk	(0x1U << U7816_CR_RXEN_Pos)
	/* 0 = ͨ�����ս�ֹ�����ɽ������ݣ����ض�����˿� */
	/* 1 = ͨ������ʹ�ܣ��ɽ������� */

#define	U7816_CR_CKOEN_Pos	3	/* U7816ʱ��CLK���ʹ�ܿ��� */
#define	U7816_CR_CKOEN_Msk	(0x1U << U7816_CR_CKOEN_Pos)
	/* 0 = 7816ʱ�������ֹ */
	/* 1 = 7816ʱ�����ʹ�� */

#define	U7816_CR_HPUAT_Pos	2	/* U7816ͨ�����ݷ���ǿ���������Զ���Ч���� */
#define	U7816_CR_HPUAT_Msk	(0x1U << U7816_CR_HPUAT_Pos)
	/* 0 = ���ݷ���ʱ���������Զ���Ч���ܽ�ֹ������������HPUEN��LPUEN���� */
	/* 1 = ���ݷ���ʱ���������Զ���Ч������̬����������Ч */

#define	U7816_CR_HPUEN_Pos	1	/* U7816ͨ��ǿ����ʹ�ܿ��� */
#define	U7816_CR_HPUEN_Msk	(0x1U << U7816_CR_HPUEN_Pos)
	/* 0 = ǿ������Ч */
	/* 1 = ǿ������Ч */

#define	U7816_FFR_SFREN_Pos	11	/* GUARD TIME ���ͳ��ȿ��� */
#define	U7816_FFR_SFREN_Msk	(0x1U << U7816_FFR_SFREN_Pos)
#define	U7816_FFR_SFREN_2ETU	(0x0U << U7816_FFR_SFREN_Pos)	/* 0 = Guard timeΪ2 etu */
#define	U7816_FFR_SFREN_3ETU	(0x1U << U7816_FFR_SFREN_Pos)	/* 1 = Guard timeΪ3 etu */

#define	U7816_FFR_ERSW_Pos	9	/* ERROR SIGNAL���ѡ�� */
#define	U7816_FFR_ERSW_Msk	(0x3U << U7816_FFR_ERSW_Pos)
#define	U7816_FFR_ERSW_1ETU	(0x3U << U7816_FFR_ERSW_Pos)	/* 11 = ERROR SIGNAL���Ϊ1ETU; */
#define	U7816_FFR_ERSW_1P5ETU	(0x2U << U7816_FFR_ERSW_Pos)	/* 10 = ERROR SIGNAL���Ϊ1.5ETU; */
#define	U7816_FFR_ERSW_2ETU	(0x0U << U7816_FFR_ERSW_Pos)	/* 01/00 = ERROR SIGNAL���Ϊ2ETU; */

#define	U7816_FFR_ERSGD_Pos	8	/* ERROR SIGNAL��GUARDTIME���ѡ�񣨽��ڷ���ʱ��Ч�� */
#define	U7816_FFR_ERSGD_Msk	(0x1U << U7816_FFR_ERSGD_Pos)
#define	U7816_FFR_ERSGD_1PETU	(0x1U << U7816_FFR_ERSGD_Pos)	/* 1 = ERROR SIGNAL��GUARDTIMEΪ1~1.5ETU�� */
#define	U7816_FFR_ERSGD_2PETU	(0x0U << U7816_FFR_ERSGD_Pos)	/* 0 = ERROR SIGNAL��GUARDTIMEΪ2~2.5ETU�� */

#define	U7816_FFR_BGTEN_Pos	7	/* BGT��block guard time������ */
#define	U7816_FFR_BGTEN_Msk	(0x1U << U7816_FFR_BGTEN_Pos)
	/* 0 = BGT��ֹ��������Block guard time(22 etu); */
	/* 1 = BGTʹ�ܣ�����Block guard time(22 etu); */

#define	U7816_FFR_REP_T_Pos	6	/* ���ƽ���������żУ�����ʱ�Զ��ط����� */
#define	U7816_FFR_REP_T_Msk	(0x1U << U7816_FFR_REP_T_Pos)
#define	U7816_FFR_REP_T_1TIME	(0x0U << U7816_FFR_REP_T_Pos)	/* 0 = 1�� */
#define	U7816_FFR_REP_T_3TIME	(0x1U << U7816_FFR_REP_T_Pos)	/* 1 = 3�� */

#define	U7816_FFR_PAR_Pos	4	/* ��żУ������ѡ�� */
#define	U7816_FFR_PAR_Msk	(0x3U << U7816_FFR_PAR_Pos)
#define	U7816_FFR_PAR_EVEN	(0x0U << U7816_FFR_PAR_Pos)	/* 00��Even */
#define	U7816_FFR_PAR_ODD	(0x1U << U7816_FFR_PAR_Pos)	/* 01��Odd */
#define	U7816_FFR_PAR_ALWAYS1	(0x2U << U7816_FFR_PAR_Pos)	/* 10��Always 1 */
#define	U7816_FFR_PAR_NONE	(0x3U << U7816_FFR_PAR_Pos)	/* 11����У�飬���� */

#define	U7816_FFR_RFREN_Pos	3	/* Guard Time���ȿ���λ������ʱ�ϸ���Э��2etu�� */
#define	U7816_FFR_RFREN_Msk	(0x1U << U7816_FFR_RFREN_Pos)
#define	U7816_FFR_RFREN_2ETU	(0x0U << U7816_FFR_RFREN_Pos)	/* 0 = Guard timeΪ2 etu */
#define	U7816_FFR_RFREN_1ETU	(0x1U << U7816_FFR_RFREN_Pos)	/* 1 = Guard timeΪ1 etu */

#define	U7816_FFR_TREPEN_Pos	2	/* ������������żУ���Ĵ���ʽѡ�� */
#define	U7816_FFR_TREPEN_Msk	(0x1U << U7816_FFR_TREPEN_Pos)
	/* 0 = �յ�Error signalʱ�������Զ��ط�����tx_parity_err��־��ֱ���ж� */
	/* 1 = �յ���żУ������־��error signal��������T��0Э���Զ����лط����ڵ�һbyte�ظ����ʹ�������REP_T����tx_parity_err��־�������ж� */

#define	U7816_FFR_RREPEN_Pos	1	/* ����������żУ���Ĵ���ʽѡ�� */
#define	U7816_FFR_RREPEN_Msk	(0x1U << U7816_FFR_RREPEN_Pos)
	/* 0 = ��żУ������Զ�����ERROR SIGNAL����RX_PARITY_ERR��־�������ж� */
	/* 1 = ��żУ�������T=0Э���Զ��ط�ERROR SIGNAL����һBYTE�������մ�������REP_T����RX_PARITY_ERR��־�������ж� */

#define	U7816_FFR_DICONV_Pos	0	/* ������������ʹ�� */
#define	U7816_FFR_DICONV_Msk	(0x1U << U7816_FFR_DICONV_Pos)
	/* 0 = ������룬���շ�LSB �� (�շ�����+У��λ)���߼���ƽ */
	/* 1 = ������룬���շ�MSB��(�շ�����+У��λ)���߼���ƽ */

#define	U7816_EGTR_TXEGT_Pos	0	/* ����ʱ�����EGTʱ�䣨��ETUΪ��λ�� */
#define	U7816_EGTR_TXEGT_Msk	(0xffU << U7816_EGTR_TXEGT_Pos)

#define	U7816_PSC_CLKDIV_Pos	0	/* U7816ʱ�������Ƶ���ƼĴ��� */
#define	U7816_PSC_CLKDIV_Msk	(0x1fU << U7816_PSC_CLKDIV_Pos)

#define	U7816_BGR_PDIV_Pos	0	/* U7816Ԥ��Ƶ���ƼĴ���������7816ͨ�ŷ�Ƶ�ȣ������ʣ� */
#define	U7816_BGR_PDIV_Msk	(0xfffU << U7816_BGR_PDIV_Pos)

#define	U7816_RXBUF_RXBUF_Pos	0	/* U7816���ݽ��ջ���Ĵ��� */
#define	U7816_RXBUF_RXBUF_Msk	(0xffU << U7816_RXBUF_RXBUF_Pos)

#define	U7816_TXBUF_TXBUF_Pos	0	/* U7816���ݷ��ͻ���Ĵ��� */
#define	U7816_TXBUF_TXBUF_Msk	(0xffU << U7816_TXBUF_TXBUF_Pos)

#define	U7816_IER_RXIE_Pos	2	/* ���ݽ����ж�ʹ��λ����ӦRX_FLAG�жϱ�־λ */
#define	U7816_IER_RXIE_Msk	(0x1U << U7816_IER_RXIE_Pos)
	/* 0 = ���ݽ����ж�ʹ��λ */
	/* 1 = ���ݽ����ж�ʹ��λ */

#define	U7816_IER_TXIE_Pos	1	/* ���ݷ����ж�ʹ��λ����ӦTX_FLAG�жϱ�־λ */
#define	U7816_IER_TXIE_Msk	(0x1U << U7816_IER_TXIE_Pos)
	/* 0 = ���ݷ����жϽ�ֹ */
	/* 1 = ���ݷ����ж�ʹ�� */

#define	U7816_IER_LSIE_Pos	0	/* ��·״̬�ж�ʹ��λ����ӦERROR_FLAG�жϱ�־λ */
#define	U7816_IER_LSIE_Msk	(0x1U << U7816_IER_LSIE_Pos)
	/* 0 = ��·״̬�жϽ�ֹ */
	/* 1 = ��·״̬�ж�ʹ�� */

#define	U7816_ISR_WAIT_RPT_Pos	18	/* U7816�ӿڷ����˴����źţ����ڵȴ��Է��ط�����.״̬�����뷢�ʹ����ź�״̬ʱ��λ���յ�������ʼλ���߽��뷢��״̬ʱӲ������;
 */
#define	U7816_ISR_WAIT_RPT_Msk	(0x1U << U7816_ISR_WAIT_RPT_Pos)

#define	U7816_ISR_TXBUSY_Pos	17	/* ��������æ��־ */
#define	U7816_ISR_TXBUSY_Msk	(0x1U << U7816_ISR_TXBUSY_Pos)

#define	U7816_ISR_RXBUSY_Pos	16	/* ��������æ��־ */
#define	U7816_ISR_RXBUSY_Msk	(0x1U << U7816_ISR_RXBUSY_Pos)

#define	U7816_ISR_TPARERR_Pos	11	/* ����������żУ������־λ */
#define	U7816_ISR_TPARERR_Msk	(0x1U << U7816_ISR_TPARERR_Pos)

#define	U7816_ISR_RPARERR_Pos	10	/* ����������żУ������־λ */
#define	U7816_ISR_RPARERR_Msk	(0x1U << U7816_ISR_RPARERR_Pos)

#define	U7816_ISR_FRERR_Pos	9	/* ����֡��ʽ�����־λ */
#define	U7816_ISR_FRERR_Msk	(0x1U << U7816_ISR_FRERR_Pos)

#define	U7816_ISR_OVERR_Pos	8	/* ������������־λ */
#define	U7816_ISR_OVERR_Msk	(0x1U << U7816_ISR_OVERR_Pos)

#define	U7816_ISR_RXIF_Pos	2	/* ������ɱ�־ */
#define	U7816_ISR_RXIF_Msk	(0x1U << U7816_ISR_RXIF_Pos)

#define	U7816_ISR_TXIF_Pos	1	/* ���ͻ������ձ�־ */
#define	U7816_ISR_TXIF_Msk	(0x1U << U7816_ISR_TXIF_Pos)

#define	U7816_ISR_ERRIF_Pos	0	/* �����־���Ĵ������ó����������г���Ӳ����λ����U7816ERR����Ӧ���� */
#define	U7816_ISR_ERRIF_Msk	(0x1U << U7816_ISR_ERRIF_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void U7816_Deinit(void);

/* U7816ͨ������ʹ�ܿ��� ��غ��� */
extern void U7816_CR_TXEN_Setable(FunState NewState);
extern FunState U7816_CR_TXEN_Getable(void);

/* U7816ͨ������ʹ�ܿ��� ��غ��� */
extern void U7816_CR_RXEN_Setable(FunState NewState);
extern FunState U7816_CR_RXEN_Getable(void);

/* U7816ʱ��CLK���ʹ�ܿ��� ��غ��� */
extern void U7816_CR_CKOEN_Setable(FunState NewState);
extern FunState U7816_CR_CKOEN_Getable(void);

/* U7816ͨ�����ݷ���ǿ���������Զ���Ч���� ��غ��� */
extern void U7816_CR_HPUAT_Setable(FunState NewState);
extern FunState U7816_CR_HPUAT_Getable(void);

/* U7816ͨ��ǿ����ʹ�ܿ��� ��غ��� */
extern void U7816_CR_HPUEN_Setable(FunState NewState);
extern FunState U7816_CR_HPUEN_Getable(void);

/* GUARD TIME ���ͳ��ȿ��� ��غ��� */
extern void U7816_FFR_SFREN_Set(uint32_t SetValue);
extern uint32_t U7816_FFR_SFREN_Get(void);

/* ERROR SIGNAL���ѡ�� ��غ��� */
extern void U7816_FFR_ERSW_Set(uint32_t SetValue);
extern uint32_t U7816_FFR_ERSW_Get(void);

/* ERROR SIGNAL��GUARDTIME���ѡ�񣨽��ڷ���ʱ��Ч�� ��غ��� */
extern void U7816_FFR_ERSGD_Set(uint32_t SetValue);
extern uint32_t U7816_FFR_ERSGD_Get(void);

/* BGT��block guard time������ ��غ��� */
extern void U7816_FFR_BGTEN_Setable(FunState NewState);
extern FunState U7816_FFR_BGTEN_Getable(void);

/* ���ƽ���������żУ�����ʱ�Զ��ط����� ��غ��� */
extern void U7816_FFR_REP_T_Set(uint32_t SetValue);
extern uint32_t U7816_FFR_REP_T_Get(void);

/* ��żУ������ѡ�� ��غ��� */
extern void U7816_FFR_PAR_Set(uint32_t SetValue);
extern uint32_t U7816_FFR_PAR_Get(void);

/* Guard Time���ȿ���λ������ʱ�ϸ���Э��2etu�� ��غ��� */
extern void U7816_FFR_RFREN_Set(uint32_t SetValue);
extern uint32_t U7816_FFR_RFREN_Get(void);

/* ������������żУ���Ĵ���ʽѡ�� ��غ��� */
extern void U7816_FFR_TREPEN_Setable(FunState NewState);
extern FunState U7816_FFR_TREPEN_Getable(void);

/* ����������żУ���Ĵ���ʽѡ�� ��غ��� */
extern void U7816_FFR_RREPEN_Setable(FunState NewState);
extern FunState U7816_FFR_RREPEN_Getable(void);

/* ������������ʹ�� ��غ��� */
extern void U7816_FFR_DICONV_Setable(FunState NewState);
extern FunState U7816_FFR_DICONV_Getable(void);

/* ����ʱ�����EGTʱ�䣨��ETUΪ��λ�� ��غ��� */
extern void U7816_EGTR_Write(uint32_t SetValue);
extern uint32_t U7816_EGTR_Read(void);

/* U7816ʱ�������Ƶ���ƼĴ��� ��غ��� */
extern void U7816_PSC_Write(uint32_t SetValue);
extern uint32_t U7816_PSC_Read(void);

/* U7816Ԥ��Ƶ���ƼĴ���������7816ͨ�ŷ�Ƶ�ȣ������ʣ� ��غ��� */
extern void U7816_BGR_Write(uint32_t SetValue);
extern uint32_t U7816_BGR_Read(void);

/* U7816���ݽ��ջ���Ĵ��� ��غ��� */
extern uint32_t U7816_RXBUF_Read(void);

/* U7816���ݷ��ͻ���Ĵ��� ��غ��� */
extern void U7816_TXBUF_Write(uint32_t SetValue);

/* ���ݽ����ж�ʹ��λ����ӦRX_FLAG�жϱ�־λ ��غ��� */
extern void U7816_IER_RXIE_Setable(FunState NewState);
extern FunState U7816_IER_RXIE_Getable(void);

/* ���ݷ����ж�ʹ��λ����ӦTX_FLAG�жϱ�־λ ��غ��� */
extern void U7816_IER_TXIE_Setable(FunState NewState);
extern FunState U7816_IER_TXIE_Getable(void);

/* ��·״̬�ж�ʹ��λ����ӦERROR_FLAG�жϱ�־λ ��غ��� */
extern void U7816_IER_LSIE_Setable(FunState NewState);
extern FunState U7816_IER_LSIE_Getable(void);

/* U7816�ӿڷ����˴����źţ����ڵȴ��Է��ط�����.״̬�����뷢�ʹ����ź�״̬ʱ��λ���յ�������ʼλ���߽��뷢��״̬ʱӲ������;
 ��غ��� */
extern FlagStatus U7816_ISR_WAIT_RPT_Chk(void);

/* ��������æ��־ ��غ��� */
extern FlagStatus U7816_ISR_TXBUSY_Chk(void);

/* ��������æ��־ ��غ��� */
extern FlagStatus U7816_ISR_RXBUSY_Chk(void);

/* ����������żУ������־λ ��غ��� */
extern void U7816_ISR_TPARERR_Clr(void);
extern FlagStatus U7816_ISR_TPARERR_Chk(void);

/* ����������żУ������־λ ��غ��� */
extern void U7816_ISR_RPARERR_Clr(void);
extern FlagStatus U7816_ISR_RPARERR_Chk(void);

/* ����֡��ʽ�����־λ ��غ��� */
extern void U7816_ISR_FRERR_Clr(void);
extern FlagStatus U7816_ISR_FRERR_Chk(void);

/* ������������־λ ��غ��� */
extern void U7816_ISR_OVERR_Clr(void);
extern FlagStatus U7816_ISR_OVERR_Chk(void);

/* ������ɱ�־ ��غ��� */
extern FlagStatus U7816_ISR_RXIF_Chk(void);

/* ���ͻ������ձ�־ ��غ��� */
extern FlagStatus U7816_ISR_TXIF_Chk(void);

/* �����־���Ĵ������ó����������г���Ӳ����λ����U7816ERR����Ӧ���� ��غ��� */
extern FlagStatus U7816_ISR_ERRIF_Chk(void);

extern void U7816_Init(U7816_InitTypeDef* para);

#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_U7816_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
