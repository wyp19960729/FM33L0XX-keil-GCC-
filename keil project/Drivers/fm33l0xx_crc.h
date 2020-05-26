/**
  ******************************************************************************
  * @file    fm33l0xx_crc.h
  * @author  FM33L0xx Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file contains all the functions prototypes for the CRC firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33L0XX_CRC_H
#define __FM33L0XX_CRC_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33L0XX.h" 

//------------------------------------------------------------------------------

/* Exported constants --------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
typedef struct
{       	
	uint32_t			CRCSEL;		/*!<CRCУ�����ʽλ��ѡ��*/
	FunState 			OPWD;			/*!<WORD����ʹ��*/
	FunState      		PARA;			/*!<CRC���ټ���ʹ��*/
	uint32_t			RFLTIN;		/*!<CRC���뷴ת����*/
	FunState			RFLTO;		/*!<CRC�����ת����*/
	FunState			XOR;		/*!<������ʹ��*/
	uint32_t			CRC_XOR;	/*!<���������Ĵ���*/
	uint32_t 			CRCPOLY;	/*!<CRC����ʽ�Ĵ���*/

}CRC_InitTypeDef;
#define	CRC_DR_DR_Pos	0	/* CRC���ݼĴ��� */
#define	CRC_DR_DR_Msk	(0xffffffffU << CRC_DR_DR_Pos)

#define	CRC_CR_OPWD_Pos	9	/* WORD����ʹ�� */
#define	CRC_CR_OPWD_Msk	(0x1U << CRC_CR_OPWD_Pos)
	/* 0���ֽڲ�����CRC��������CRC_DR����ֽڽ��� */
	/* 1���ֲ�����CRC�������CRC_DRȫ��4�ֽڽ��� */

#define	CRC_CR_PARA_Pos	8	/* CRC���ټ���ʹ�� */
#define	CRC_CR_PARA_Msk	(0x1U << CRC_CR_PARA_Pos)
	/* 0���������㣬����1���ֽ���Ҫ8��ʱ������ */
	/* 1�����м��㣬����1���ֽ���Ҫ1��ʱ������ */

#define	CRC_CR_RFLTIN_Pos	6	/* CRC���뷴ת���� */
#define	CRC_CR_RFLTIN_Msk	(0x3U << CRC_CR_RFLTIN_Pos)
#define	CRC_CR_RFLTIN_NONE	(0x0U << CRC_CR_RFLTIN_Pos)	/* 00�����벻��ת */
#define	CRC_CR_RFLTIN_BYTE	(0x1U << CRC_CR_RFLTIN_Pos)	/* 01�����밴�ֽڷ�ת */
#define	CRC_CR_RFLTIN_HALFWORD	(0x2U << CRC_CR_RFLTIN_Pos)	/* 10�����밴���ַ�ת */
#define	CRC_CR_RFLTIN_WORD	(0x3U << CRC_CR_RFLTIN_Pos)	/* 11�����밴�ַ�ת */

#define	CRC_CR_RFLTO_Pos	5	/* CRC�����ת���� */
#define	CRC_CR_RFLTO_Msk	(0x1U << CRC_CR_RFLTO_Pos)
	/* 0�����벻��ת */
	/* 1�����밴�ֽڷ�ת */

#define	CRC_CR_RES_Pos	4	/* CRC�����־λ��ֻ�� */
#define	CRC_CR_RES_Msk	(0x1U << CRC_CR_RES_Pos)

#define	CRC_CR_BUSY_Pos	3	/* CRC�����־λ��ֻ�� */
#define	CRC_CR_BUSY_Msk	(0x1U << CRC_CR_BUSY_Pos)

#define	CRC_CR_XOR_Pos	2	/* ������ʹ�� */
#define	CRC_CR_XOR_Msk	(0x1U << CRC_CR_XOR_Pos)
	/* 0����������CRC_XOR�Ĵ��� */
	/* 1��������CRC_XOR�Ĵ��� */

#define	CRC_CR_SEL_Pos	0	/* CRCУ�����ʽѡ�� */
#define	CRC_CR_SEL_Msk	(0x3U << CRC_CR_SEL_Pos)
#define	CRC_CR_SEL_CRC32	(0x0U << CRC_CR_SEL_Pos)	/* 00��CRC32 */
#define	CRC_CR_SEL_CRC16	(0x1U << CRC_CR_SEL_Pos)	/* 01��CRC16 */
#define	CRC_CR_SEL_CRC8	(0x2U << CRC_CR_SEL_Pos)	/* 10��CRC8 */
#define	CRC_CR_SEL_CRC7	(0x3U << CRC_CR_SEL_Pos)	/* 11��CRC7 */

#define	CRC_LFSR_LFSR_Pos	0	/* CRC���Է�����λ�Ĵ��� */
#define	CRC_LFSR_LFSR_Msk	(0xffffffffU << CRC_LFSR_LFSR_Pos)

#define	CRC_XOR_XOR_Pos	0	/* CRC���������Ĵ��� */
#define	CRC_XOR_XOR_Msk	(0xffffffffU << CRC_XOR_XOR_Pos)

#define	CRC_FLS_CR_FLSCRCEN_Pos	0	/* Flash����CRCУ��ʹ�� */
#define	CRC_FLS_CR_FLSCRCEN_Msk	(0x1U << CRC_FLS_CR_FLSCRCEN_Pos)
	/* 0����ʹ��Flash CRCУ�� */
	/* 1������Flash CRCУ�� */

#define	CRC_FLS_AD_FLSAD_Pos	0	/* FlashУ����ʼ��ַ��Word��ַ�� */
#define	CRC_FLS_AD_FLSAD_Msk	(0x7fffU << CRC_FLS_AD_FLSAD_Pos)

#define	CRC_FLS_SIZE_FLSS_Pos	0	/* CRC FlashУ�����ݳ��ȣ�Word���ȣ� */
#define	CRC_FLS_SIZE_FLSS_Msk	(0x7fffU << CRC_FLS_SIZE_FLSS_Pos)

#define	CRC_POLY_POLY_Pos	0	/* CRC�������ʽϵ�� */
#define	CRC_POLY_POLY_Msk	(0xffffffffU << CRC_POLY_POLY_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void CRC_Deinit(void);

/* CRC���ݼĴ��� ��غ��� */
extern void CRC_DR_Write(uint32_t SetValue);
extern uint32_t CRC_DR_Read(void);

/* WORD����ʹ�� ��غ��� */
extern void CRC_CR_OPWD_Setable(FunState NewState);
extern FunState CRC_CR_OPWD_Getable(void);

/* CRC���ټ���ʹ�� ��غ��� */
extern void CRC_CR_PARA_Setable(FunState NewState);
extern FunState CRC_CR_PARA_Getable(void);

/* CRC���뷴ת���� ��غ��� */
extern void CRC_CR_RFLTIN_Set(uint32_t SetValue);
extern uint32_t CRC_CR_RFLTIN_Get(void);

/* CRC�����ת���� ��غ��� */
extern void CRC_CR_RFLTO_Setable(FunState NewState);
extern FunState CRC_CR_RFLTO_Getable(void);

/* CRC�����־λ��ֻ�� ��غ��� */
extern FlagStatus CRC_CR_RES_Chk(void);

/* CRC�����־λ��ֻ�� ��غ��� */
extern FlagStatus CRC_CR_BUSY_Chk(void);

/* ������ʹ�� ��غ��� */
extern void CRC_CR_XOR_Setable(FunState NewState);
extern FunState CRC_CR_XOR_Getable(void);

/* CRCУ�����ʽѡ�� ��غ��� */
extern void CRC_CR_SEL_Set(uint32_t SetValue);
extern uint32_t CRC_CR_SEL_Get(void);

/* CRC���Է�����λ�Ĵ��� ��غ��� */
extern void CRC_LFSR_Write(uint32_t SetValue);
extern uint32_t CRC_LFSR_Read(void);

/* CRC���������Ĵ��� ��غ��� */
extern void CRC_XOR_Write(uint32_t SetValue);
extern uint32_t CRC_XOR_Read(void);

/* Flash����CRCУ��ʹ�� ��غ��� */
extern void CRC_FLS_CR_FLSCRCEN_Setable(FunState NewState);
extern FunState CRC_FLS_CR_FLSCRCEN_Getable(void);

/* FlashУ����ʼ��ַ��Word��ַ�� ��غ��� */
extern void CRC_FLS_AD_Write(uint32_t SetValue);
extern uint32_t CRC_FLS_AD_Read(void);

/* CRC FlashУ�����ݳ��ȣ�Word���ȣ� ��غ��� */
extern void CRC_FLS_SIZE_Write(uint32_t SetValue);
extern uint32_t CRC_FLS_SIZE_Read(void);

/* CRC�������ʽϵ�� ��غ��� */
extern void CRC_POLY_Write(uint32_t SetValue);
extern uint32_t CRC_POLY_Read(void);
//Announce_End
/* CRC��ʼ�����ú���*/
void CRC_Init(CRC_InitTypeDef* para);
#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_CRC_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
