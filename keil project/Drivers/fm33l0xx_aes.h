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

#define	AES_CR_KEYLEN_Pos	13	/* AES加密密钥长度，AESEN=1时不可修改 */
#define	AES_CR_KEYLEN_Msk	(0x3U << AES_CR_KEYLEN_Pos)
#define	AES_CR_KEYLEN_128BIT	(0x0U << AES_CR_KEYLEN_Pos)	/* 00：128bit */
#define	AES_CR_KEYLEN_192BIT	(0x1U << AES_CR_KEYLEN_Pos)	/* 01：192bit */
#define	AES_CR_KEYLEN_256BIT	(0x2U << AES_CR_KEYLEN_Pos)	/* 10：256bit */

#define	AES_CR_DMAOEN_Pos	12	/* DMA数据自动读出使能 */
#define	AES_CR_DMAOEN_Msk	(0x1U << AES_CR_DMAOEN_Pos)
	/* 0：不开启 */
	/* 1：开启 */

#define	AES_CR_DMAIEN_Pos	11	/* DMA数据自动写入使能 */
#define	AES_CR_DMAIEN_Msk	(0x1U << AES_CR_DMAIEN_Pos)
	/* 0：不开启 */
	/* 1：开启 */

#define	AES_CR_CHMOD_Pos	5	/* AES数据流处理模式，AESEN=1时不可修改 */
#define	AES_CR_CHMOD_Msk	(0x3U << AES_CR_CHMOD_Pos)
#define	AES_CR_CHMOD_ECB	(0x0U << AES_CR_CHMOD_Pos)	/* 00：ECB */
#define	AES_CR_CHMOD_CBC	(0x1U << AES_CR_CHMOD_Pos)	/* 01：CBC */
#define	AES_CR_CHMOD_CTR	(0x2U << AES_CR_CHMOD_Pos)	/* 10：CTR */
#define	AES_CR_CHMOD_MULTH	(0x3U << AES_CR_CHMOD_Pos)	/* 11：使用MultH模块 */

#define	AES_CR_MODE_Pos	3	/* AES工作模式，AESEN=1时不可修改 */
#define	AES_CR_MODE_Msk	(0x3U << AES_CR_MODE_Pos)
#define	AES_CR_MODE_ENCRYPT	(0x0U << AES_CR_MODE_Pos)	/* 00：模式1：加密 */
#define	AES_CR_MODE_KEYEXP	(0x1U << AES_CR_MODE_Pos)	/* 01：模式2：密钥扩展 */
#define	AES_CR_MODE_DECRYPT	(0x2U << AES_CR_MODE_Pos)	/* 10：模式3：解密 */
#define	AES_CR_MODE_KEYEXPDECRYPT	(0x3U << AES_CR_MODE_Pos)	/* 11：模式4：密钥扩展+解密 */

#define	AES_CR_DATATYP_Pos	1	/* 选择数据类型，AESEN=1时不可修改 */
#define	AES_CR_DATATYP_Msk	(0x3U << AES_CR_DATATYP_Pos)
#define	AES_CR_DATATYP_32BITNOEX	(0x0U << AES_CR_DATATYP_Pos)	/* 00：32bit数据不交换 */
#define	AES_CR_DATATYP_16BITEX	(0x1U << AES_CR_DATATYP_Pos)	/* 01：16bit数据半字交换 */
#define	AES_CR_DATATYP_8BITEX	(0x2U << AES_CR_DATATYP_Pos)	/* 10：8bit数据字节交换 */
#define	AES_CR_DATATYP_1BITEX	(0x3U << AES_CR_DATATYP_Pos)	/* 11：1bit数据比特交换 */

#define	AES_CR_EN_Pos	0	/* AES使能,在任何时候清除AESEN位都能够复位AES模块 */
#define	AES_CR_EN_Msk	(0x1U << AES_CR_EN_Pos)
	/* 0：不使能 */
	/* 1：使能 */

#define	AES_IER_WRERR_IE_Pos	2	/* 写错误中断使能，1有效 */
#define	AES_IER_WRERR_IE_Msk	(0x1U << AES_IER_WRERR_IE_Pos)

#define	AES_IER_RDERR_IE_Pos	1	/* 读错误中断使能，1有效 */
#define	AES_IER_RDERR_IE_Msk	(0x1U << AES_IER_RDERR_IE_Pos)

#define	AES_IER_CCF_IE_Pos	0	/* AES计算完成中断使能，1有效 */
#define	AES_IER_CCF_IE_Msk	(0x1U << AES_IER_CCF_IE_Pos)

#define	AES_ISR_WRERR_Pos	2	/* 写错误标志：在计算或输出阶段发生写操作时置位，软件写1清零  */
#define	AES_ISR_WRERR_Msk	(0x1U << AES_ISR_WRERR_Pos)

#define	AES_ISR_RDERR_Pos	1	/* 读错误标志：在计算或输入阶段发生读操作时置位，软件写1清零 */
#define	AES_ISR_RDERR_Msk	(0x1U << AES_ISR_RDERR_Pos)

#define	AES_ISR_CCF_Pos	0	/* AES计算完成标志，软件写1清零 */
#define	AES_ISR_CCF_Msk	(0x1U << AES_ISR_CCF_Pos)

#define	AES_DIR_DIN_Pos	0	/* 数据输入寄存器，当AES需要输入加解密数据时，应该往该寄存器连续写4次 */
#define	AES_DIR_DIN_Msk	(0xffffffffU << AES_DIR_DIN_Pos)

#define	AES_DOR_DOUT_Pos	0	/* 数据输出寄存器，当AES计算完成后，可以分四次读出加解密的结果 */
#define	AES_DOR_DOUT_Msk	(0xffffffffU << AES_DOR_DOUT_Pos)

#define	AES_KEY0_KEYx_Pos	0	/* AES运算秘钥，最长256bit,AESKEY0存放秘钥最低32bit，AESLKEY7存放秘钥最高32bit。AESKEY0~3在MultH模式下存放H[127:0]
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

#define	AES_IVR0_IVRx_Pos	0	/* AES运算128bit初始向量，在MultH模式下保存运算结果 */
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
	uint32_t	KEYLEN;			//AES加密密钥长度，AESEN=1时不可修改
	uint32_t	CHMOD;			//AES数据流处理模式，AESEN=1时不可修改
	uint32_t	MODE;			//AES工作模式，AESEN=1时不可修改
	uint32_t	DATATYP;		//选择数据类型，AESEN=1时不可修改。具体交换规则可参考AES数据类型章节	
	FunState	DMAOEN;			//DMA数据自动读出使能
	FunState	DMAIEN;			//DMA数据自动写入使能
	FunState	WERRIE;			//错误标志（WRERR）中断使能
	FunState	RERRIE;			//错误标志（RDERR）中断使能
	FunState	CCFIE;			//CCF标志中断使能
	FunState	AESEN;			//AES使能 
	
}AES_InitTypeDef;

/* Exported functions --------------------------------------------------------*/ 
extern void AES_Deinit(void);

/* AES加密密钥长度，AESEN=1时不可修改 相关函数 */
extern void AES_CR_KEYLEN_Set(uint32_t SetValue);
extern uint32_t AES_CR_KEYLEN_Get(void);

/* DMA数据自动读出使能 相关函数 */
extern void AES_CR_DMAOEN_Setable(FunState NewState);
extern FunState AES_CR_DMAOEN_Getable(void);

/* DMA数据自动写入使能 相关函数 */
extern void AES_CR_DMAIEN_Setable(FunState NewState);
extern FunState AES_CR_DMAIEN_Getable(void);

/* AES数据流处理模式，AESEN=1时不可修改 相关函数 */
extern void AES_CR_CHMOD_Set(uint32_t SetValue);
extern uint32_t AES_CR_CHMOD_Get(void);

/* AES工作模式，AESEN=1时不可修改 相关函数 */
extern void AES_CR_MODE_Set(uint32_t SetValue);
extern uint32_t AES_CR_MODE_Get(void);

/* 选择数据类型，AESEN=1时不可修改 相关函数 */
extern void AES_CR_DATATYP_Set(uint32_t SetValue);
extern uint32_t AES_CR_DATATYP_Get(void);

/* AES使能,在任何时候清除AESEN位都能够复位AES模块 相关函数 */
extern void AES_CR_EN_Setable(FunState NewState);
extern FunState AES_CR_EN_Getable(void);

/* 写错误中断使能，1有效 相关函数 */
extern void AES_IER_WRERR_IE_Setable(FunState NewState);
extern FunState AES_IER_WRERR_IE_Getable(void);

/* 读错误中断使能，1有效 相关函数 */
extern void AES_IER_RDERR_IE_Setable(FunState NewState);
extern FunState AES_IER_RDERR_IE_Getable(void);

/* AES计算完成中断使能，1有效 相关函数 */
extern void AES_IER_CCF_IE_Setable(FunState NewState);
extern FunState AES_IER_CCF_IE_Getable(void);

/* 写错误标志：在计算或输出阶段发生写操作时置位，软件写1清零  相关函数 */
extern void AES_ISR_WRERR_Clr(void);
extern FlagStatus AES_ISR_WRERR_Chk(void);

/* 读错误标志：在计算或输入阶段发生读操作时置位，软件写1清零 相关函数 */
extern void AES_ISR_RDERR_Clr(void);
extern FlagStatus AES_ISR_RDERR_Chk(void);

/* AES计算完成标志，软件写1清零 相关函数 */
extern void AES_ISR_CCF_Clr(void);
extern FlagStatus AES_ISR_CCF_Chk(void);

/* 数据输入寄存器，当AES需要输入加解密数据时，应该往该寄存器连续写4次 相关函数 */
extern void AES_DIR_Write(uint32_t SetValue);
extern uint32_t AES_DIR_Read(void);

/* 数据输出寄存器，当AES计算完成后，可以分四次读出加解密的结果 相关函数 */
extern void AES_DOR_Write(uint32_t SetValue);
extern uint32_t AES_DOR_Read(void);

/* AES运算秘钥，最长256bit,AESKEY0存放秘钥最低32bit，AESLKEY7存放秘钥最高32bit。AESKEY0~3在MultH模式下存放H[127:0]
 相关函数 */
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

/* AES运算128bit初始向量，在MultH模式下保存运算结果 相关函数 */
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
