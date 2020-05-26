/**
  ******************************************************************************
  * @file    fm33l0xx_aes.h
  * @author  FM33L0xx Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file contains all the functions prototypes for the AES firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33L0XX_AES_H
#define __FM33L0XX_AES_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33L0XX.h" 

//------------------------------------------------------------------------------
//Macro_START
//2019-06-13-09-37-09
//FM33A0XX_Driver_Gen_V1.4

#define	AES_CR_KEYLEN_Pos	13	/* AES������Կ���ȣ�AESEN=1ʱ�����޸� */
#define	AES_CR_KEYLEN_Msk	(0x3U << AES_CR_KEYLEN_Pos)
#define	AES_CR_KEYLEN_128BIT	(0x0U << AES_CR_KEYLEN_Pos)	/* 00��128bit */
#define	AES_CR_KEYLEN_192BIT	(0x1U << AES_CR_KEYLEN_Pos)	/* 01��192bit */
#define	AES_CR_KEYLEN_256BIT	(0x2U << AES_CR_KEYLEN_Pos)	/* 10��256bit */

#define	AES_CR_DMAOEN_Pos	12	/* DMA�����Զ�����ʹ�� */
#define	AES_CR_DMAOEN_Msk	(0x1U << AES_CR_DMAOEN_Pos)
	/* 0�������� */
	/* 1������ */

#define	AES_CR_DMAIEN_Pos	11	/* DMA�����Զ�д��ʹ�� */
#define	AES_CR_DMAIEN_Msk	(0x1U << AES_CR_DMAIEN_Pos)
	/* 0�������� */
	/* 1������ */

#define	AES_CR_CHMOD_Pos	5	/* AES����������ģʽ��AESEN=1ʱ�����޸� */
#define	AES_CR_CHMOD_Msk	(0x3U << AES_CR_CHMOD_Pos)
#define	AES_CR_CHMOD_ECB	(0x0U << AES_CR_CHMOD_Pos)	/* 00��ECB */
#define	AES_CR_CHMOD_CBC	(0x1U << AES_CR_CHMOD_Pos)	/* 01��CBC */
#define	AES_CR_CHMOD_CTR	(0x2U << AES_CR_CHMOD_Pos)	/* 10��CTR */
#define	AES_CR_CHMOD_MULTH	(0x3U << AES_CR_CHMOD_Pos)	/* 11��ʹ��MultHģ�� */

#define	AES_CR_MODE_Pos	3	/* AES����ģʽ��AESEN=1ʱ�����޸� */
#define	AES_CR_MODE_Msk	(0x3U << AES_CR_MODE_Pos)
#define	AES_CR_MODE_ENCRYPT	(0x0U << AES_CR_MODE_Pos)	/* 00��ģʽ1������ */
#define	AES_CR_MODE_KEYEXP	(0x1U << AES_CR_MODE_Pos)	/* 01��ģʽ2����Կ��չ */
#define	AES_CR_MODE_DECRYPT	(0x2U << AES_CR_MODE_Pos)	/* 10��ģʽ3������ */
#define	AES_CR_MODE_KEYEXPDECRYPT	(0x3U << AES_CR_MODE_Pos)	/* 11��ģʽ4����Կ��չ+���� */

#define	AES_CR_DATATYP_Pos	1	/* ѡ���������ͣ�AESEN=1ʱ�����޸� */
#define	AES_CR_DATATYP_Msk	(0x3U << AES_CR_DATATYP_Pos)
#define	AES_CR_DATATYP_32BITNOEX	(0x0U << AES_CR_DATATYP_Pos)	/* 00��32bit���ݲ����� */
#define	AES_CR_DATATYP_16BITEX	(0x1U << AES_CR_DATATYP_Pos)	/* 01��16bit���ݰ��ֽ��� */
#define	AES_CR_DATATYP_8BITEX	(0x2U << AES_CR_DATATYP_Pos)	/* 10��8bit�����ֽڽ��� */
#define	AES_CR_DATATYP_1BITEX	(0x3U << AES_CR_DATATYP_Pos)	/* 11��1bit���ݱ��ؽ��� */

#define	AES_CR_EN_Pos	0	/* AESʹ��,���κ�ʱ�����AESENλ���ܹ���λAESģ�� */
#define	AES_CR_EN_Msk	(0x1U << AES_CR_EN_Pos)
	/* 0����ʹ�� */
	/* 1��ʹ�� */

#define	AES_IER_WRERR_IE_Pos	2	/* д�����ж�ʹ�ܣ�1��Ч */
#define	AES_IER_WRERR_IE_Msk	(0x1U << AES_IER_WRERR_IE_Pos)

#define	AES_IER_RDERR_IE_Pos	1	/* �������ж�ʹ�ܣ�1��Ч */
#define	AES_IER_RDERR_IE_Msk	(0x1U << AES_IER_RDERR_IE_Pos)

#define	AES_IER_CCF_IE_Pos	0	/* AES��������ж�ʹ�ܣ�1��Ч */
#define	AES_IER_CCF_IE_Msk	(0x1U << AES_IER_CCF_IE_Pos)

#define	AES_ISR_WRERR_Pos	2	/* д�����־���ڼ��������׶η���д����ʱ��λ�����д1����  */
#define	AES_ISR_WRERR_Msk	(0x1U << AES_ISR_WRERR_Pos)

#define	AES_ISR_RDERR_Pos	1	/* �������־���ڼ��������׶η���������ʱ��λ�����д1���� */
#define	AES_ISR_RDERR_Msk	(0x1U << AES_ISR_RDERR_Pos)

#define	AES_ISR_CCF_Pos	0	/* AES������ɱ�־�����д1���� */
#define	AES_ISR_CCF_Msk	(0x1U << AES_ISR_CCF_Pos)

#define	AES_DIR_DIN_Pos	0	/* ��������Ĵ�������AES��Ҫ����ӽ�������ʱ��Ӧ�����üĴ�������д4�� */
#define	AES_DIR_DIN_Msk	(0xffffffffU << AES_DIR_DIN_Pos)

#define	AES_DOR_DOUT_Pos	0	/* ��������Ĵ�������AES������ɺ󣬿��Է��Ĵζ����ӽ��ܵĽ�� */
#define	AES_DOR_DOUT_Msk	(0xffffffffU << AES_DOR_DOUT_Pos)

#define	AES_KEY0_KEYx_Pos	0	/* AES������Կ���256bit,AESKEY0�����Կ���32bit��AESLKEY7�����Կ���32bit��AESKEY0~3��MultHģʽ�´��H[127:0]
 */
#define	AES_KEY0_KEYx_Msk	(0xffffffffU << AES_KEY0_KEYx_Pos)

#define	AES_KEY1_KEYx_Pos	0
#define	AES_KEY1_KEYx_Msk	(0xffffffffU << AES_KEY1_KEYx_Pos)

#define	AES_KEY2_KEYx_Pos	0
#define	AES_KEY2_KEYx_Msk	(0xffffffffU << AES_KEY2_KEYx_Pos)

#define	AES_KEY3_KEYx_Pos	0
#define	AES_KEY3_KEYx_Msk	(0xffffffffU << AES_KEY3_KEYx_Pos)

#define	AES_KEY4_KEYx_Pos	0
#define	AES_KEY4_KEYx_Msk	(0xffffffffU << AES_KEY4_KEYx_Pos)

#define	AES_KEY5_KEYx_Pos	0
#define	AES_KEY5_KEYx_Msk	(0xffffffffU << AES_KEY5_KEYx_Pos)

#define	AES_KEY6_KEYx_Pos	0
#define	AES_KEY6_KEYx_Msk	(0xffffffffU << AES_KEY6_KEYx_Pos)

#define	AES_KEY7_KEYx_Pos	0
#define	AES_KEY7_KEYx_Msk	(0xffffffffU << AES_KEY7_KEYx_Pos)

#define	AES_IVR0_IVRx_Pos	0	/* AES����128bit��ʼ��������MultHģʽ�±��������� */
#define	AES_IVR0_IVRx_Msk	(0xffffffffU << AES_IVR0_IVRx_Pos)

#define	AES_IVR1_IVRx_Pos	0
#define	AES_IVR1_IVRx_Msk	(0xffffffffU << AES_IVR1_IVRx_Pos)

#define	AES_IVR2_IVRx_Pos	0
#define	AES_IVR2_IVRx_Msk	(0xffffffffU << AES_IVR2_IVRx_Pos)

#define	AES_IVR3_IVRx_Pos	0
#define	AES_IVR3_IVRx_Msk	(0xffffffffU << AES_IVR3_IVRx_Pos)
//Macro_End


typedef struct
{
	uint32_t	KEYLEN;			//AES������Կ���ȣ�AESEN=1ʱ�����޸�
	uint32_t	CHMOD;			//AES����������ģʽ��AESEN=1ʱ�����޸�
	uint32_t	MODE;			//AES����ģʽ��AESEN=1ʱ�����޸�
	uint32_t	DATATYP;		//ѡ���������ͣ�AESEN=1ʱ�����޸ġ����彻������ɲο�AES���������½�	
	FunState	DMAOEN;			//DMA�����Զ�����ʹ��
	FunState	DMAIEN;			//DMA�����Զ�д��ʹ��
	FunState	WERRIE;			//�����־��WRERR���ж�ʹ��
	FunState	RERRIE;			//�����־��RDERR���ж�ʹ��
	FunState	CCFIE;			//CCF��־�ж�ʹ��
	FunState	AESEN;			//AESʹ�� 
	
}AES_InitTypeDef;

/* Exported functions --------------------------------------------------------*/ 
extern void AES_Deinit(void);

/* AES������Կ���ȣ�AESEN=1ʱ�����޸� ��غ��� */
extern void AES_CR_KEYLEN_Set(uint32_t SetValue);
extern uint32_t AES_CR_KEYLEN_Get(void);

/* DMA�����Զ�����ʹ�� ��غ��� */
extern void AES_CR_DMAOEN_Setable(FunState NewState);
extern FunState AES_CR_DMAOEN_Getable(void);

/* DMA�����Զ�д��ʹ�� ��غ��� */
extern void AES_CR_DMAIEN_Setable(FunState NewState);
extern FunState AES_CR_DMAIEN_Getable(void);

/* AES����������ģʽ��AESEN=1ʱ�����޸� ��غ��� */
extern void AES_CR_CHMOD_Set(uint32_t SetValue);
extern uint32_t AES_CR_CHMOD_Get(void);

/* AES����ģʽ��AESEN=1ʱ�����޸� ��غ��� */
extern void AES_CR_MODE_Set(uint32_t SetValue);
extern uint32_t AES_CR_MODE_Get(void);

/* ѡ���������ͣ�AESEN=1ʱ�����޸� ��غ��� */
extern void AES_CR_DATATYP_Set(uint32_t SetValue);
extern uint32_t AES_CR_DATATYP_Get(void);

/* AESʹ��,���κ�ʱ�����AESENλ���ܹ���λAESģ�� ��غ��� */
extern void AES_CR_EN_Setable(FunState NewState);
extern FunState AES_CR_EN_Getable(void);

/* д�����ж�ʹ�ܣ�1��Ч ��غ��� */
extern void AES_IER_WRERR_IE_Setable(FunState NewState);
extern FunState AES_IER_WRERR_IE_Getable(void);

/* �������ж�ʹ�ܣ�1��Ч ��غ��� */
extern void AES_IER_RDERR_IE_Setable(FunState NewState);
extern FunState AES_IER_RDERR_IE_Getable(void);

/* AES��������ж�ʹ�ܣ�1��Ч ��غ��� */
extern void AES_IER_CCF_IE_Setable(FunState NewState);
extern FunState AES_IER_CCF_IE_Getable(void);

/* д�����־���ڼ��������׶η���д����ʱ��λ�����д1����  ��غ��� */
extern void AES_ISR_WRERR_Clr(void);
extern FlagStatus AES_ISR_WRERR_Chk(void);

/* �������־���ڼ��������׶η���������ʱ��λ�����д1���� ��غ��� */
extern void AES_ISR_RDERR_Clr(void);
extern FlagStatus AES_ISR_RDERR_Chk(void);

/* AES������ɱ�־�����д1���� ��غ��� */
extern void AES_ISR_CCF_Clr(void);
extern FlagStatus AES_ISR_CCF_Chk(void);

/* ��������Ĵ�������AES��Ҫ����ӽ�������ʱ��Ӧ�����üĴ�������д4�� ��غ��� */
extern void AES_DIR_Write(uint32_t SetValue);
extern uint32_t AES_DIR_Read(void);

/* ��������Ĵ�������AES������ɺ󣬿��Է��Ĵζ����ӽ��ܵĽ�� ��غ��� */
extern void AES_DOR_Write(uint32_t SetValue);
extern uint32_t AES_DOR_Read(void);

/* AES������Կ���256bit,AESKEY0�����Կ���32bit��AESLKEY7�����Կ���32bit��AESKEY0~3��MultHģʽ�´��H[127:0]
 ��غ��� */
extern void AES_KEY0_Write(uint32_t SetValue);
extern uint32_t AES_KEY0_Read(void);
extern void AES_KEY1_Write(uint32_t SetValue);
extern uint32_t AES_KEY1_Read(void);
extern void AES_KEY2_Write(uint32_t SetValue);
extern uint32_t AES_KEY2_Read(void);
extern void AES_KEY3_Write(uint32_t SetValue);
extern uint32_t AES_KEY3_Read(void);
extern void AES_KEY4_Write(uint32_t SetValue);
extern uint32_t AES_KEY4_Read(void);
extern void AES_KEY5_Write(uint32_t SetValue);
extern uint32_t AES_KEY5_Read(void);
extern void AES_KEY6_Write(uint32_t SetValue);
extern uint32_t AES_KEY6_Read(void);
extern void AES_KEY7_Write(uint32_t SetValue);
extern uint32_t AES_KEY7_Read(void);

/* AES����128bit��ʼ��������MultHģʽ�±��������� ��غ��� */
extern void AES_IVR0_Write(uint32_t SetValue);
extern uint32_t AES_IVR0_Read(void);
extern void AES_IVR1_Write(uint32_t SetValue);
extern uint32_t AES_IVR1_Read(void);
extern void AES_IVR2_Write(uint32_t SetValue);
extern uint32_t AES_IVR2_Read(void);
extern void AES_IVR3_Write(uint32_t SetValue);
extern uint32_t AES_IVR3_Read(void);
//Announce_End
extern void AES_Init(AES_InitTypeDef* para);
extern void AES_KEYx_WriteEx(uint8_t *KeyIn, uint8_t Len);			 
extern void AES_KEYx_ReadEx(uint8_t *KeyOut, uint8_t Len);
extern void AES_IVRx_WriteEx(uint8_t *IVRIn);
extern void AES_DIR_GroupWrite_128BIT(uint8_t *DataIn);
extern void AES_DOR_GroupRead_128BIT(uint8_t *DataOut);
extern uint8_t AES_GroupWriteAndRead_128BIT(uint8_t *DataIn, uint8_t *DataOut);
extern uint8_t AES_GroupWriteAndRead_128BIT(uint8_t *DataIn, uint8_t *DataOut);
#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_AES_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
