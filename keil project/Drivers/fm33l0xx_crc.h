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
	uint32_t			CRCSEL;		/*!<CRC校验多项式位宽选择*/
	FunState 			OPWD;			/*!<WORD操作使能*/
	FunState      		PARA;			/*!<CRC快速计算使能*/
	uint32_t			RFLTIN;		/*!<CRC输入反转控制*/
	FunState			RFLTO;		/*!<CRC输出反转控制*/
	FunState			XOR;		/*!<输出异或使能*/
	uint32_t			CRC_XOR;	/*!<运算结果异或寄存器*/
	uint32_t 			CRCPOLY;	/*!<CRC多项式寄存器*/

}CRC_InitTypeDef;
#define	CRC_DR_DR_Pos	0	/* CRC数据寄存器 */
#define	CRC_DR_DR_Msk	(0xffffffffU << CRC_DR_DR_Pos)

#define	CRC_CR_OPWD_Pos	9	/* WORD操作使能 */
#define	CRC_CR_OPWD_Msk	(0x1U << CRC_CR_OPWD_Pos)
	/* 0：字节操作，CRC计算仅针对CRC_DR最低字节进行 */
	/* 1：字操作，CRC计算针对CRC_DR全部4字节进行 */

#define	CRC_CR_PARA_Pos	8	/* CRC快速计算使能 */
#define	CRC_CR_PARA_Msk	(0x1U << CRC_CR_PARA_Pos)
	/* 0：串行运算，计算1个字节需要8个时钟周期 */
	/* 1：并行计算，计算1个字节需要1个时钟周期 */

#define	CRC_CR_RFLTIN_Pos	6	/* CRC输入反转控制 */
#define	CRC_CR_RFLTIN_Msk	(0x3U << CRC_CR_RFLTIN_Pos)
#define	CRC_CR_RFLTIN_NONE	(0x0U << CRC_CR_RFLTIN_Pos)	/* 00：输入不反转 */
#define	CRC_CR_RFLTIN_BYTE	(0x1U << CRC_CR_RFLTIN_Pos)	/* 01：输入按字节反转 */
#define	CRC_CR_RFLTIN_HALFWORD	(0x2U << CRC_CR_RFLTIN_Pos)	/* 10：输入按半字反转 */
#define	CRC_CR_RFLTIN_WORD	(0x3U << CRC_CR_RFLTIN_Pos)	/* 11：输入按字反转 */

#define	CRC_CR_RFLTO_Pos	5	/* CRC输出反转控制 */
#define	CRC_CR_RFLTO_Msk	(0x1U << CRC_CR_RFLTO_Pos)
	/* 0：输入不反转 */
	/* 1：输入按字节反转 */

#define	CRC_CR_RES_Pos	4	/* CRC结果标志位，只读 */
#define	CRC_CR_RES_Msk	(0x1U << CRC_CR_RES_Pos)

#define	CRC_CR_BUSY_Pos	3	/* CRC运算标志位，只读 */
#define	CRC_CR_BUSY_Msk	(0x1U << CRC_CR_BUSY_Pos)

#define	CRC_CR_XOR_Pos	2	/* 输出异或使能 */
#define	CRC_CR_XOR_Msk	(0x1U << CRC_CR_XOR_Pos)
	/* 0：输出不异或CRC_XOR寄存器 */
	/* 1：输出异或CRC_XOR寄存器 */

#define	CRC_CR_SEL_Pos	0	/* CRC校验多项式选择 */
#define	CRC_CR_SEL_Msk	(0x3U << CRC_CR_SEL_Pos)
#define	CRC_CR_SEL_CRC32	(0x0U << CRC_CR_SEL_Pos)	/* 00：CRC32 */
#define	CRC_CR_SEL_CRC16	(0x1U << CRC_CR_SEL_Pos)	/* 01：CRC16 */
#define	CRC_CR_SEL_CRC8	(0x2U << CRC_CR_SEL_Pos)	/* 10：CRC8 */
#define	CRC_CR_SEL_CRC7	(0x3U << CRC_CR_SEL_Pos)	/* 11：CRC7 */

#define	CRC_LFSR_LFSR_Pos	0	/* CRC线性反馈移位寄存器 */
#define	CRC_LFSR_LFSR_Msk	(0xffffffffU << CRC_LFSR_LFSR_Pos)

#define	CRC_XOR_XOR_Pos	0	/* CRC运算结果异或寄存器 */
#define	CRC_XOR_XOR_Msk	(0xffffffffU << CRC_XOR_XOR_Pos)

#define	CRC_FLS_CR_FLSCRCEN_Pos	0	/* Flash内容CRC校验使能 */
#define	CRC_FLS_CR_FLSCRCEN_Msk	(0x1U << CRC_FLS_CR_FLSCRCEN_Pos)
	/* 0：不使能Flash CRC校验 */
	/* 1：启动Flash CRC校验 */

#define	CRC_FLS_AD_FLSAD_Pos	0	/* Flash校验起始地址（Word地址） */
#define	CRC_FLS_AD_FLSAD_Msk	(0x7fffU << CRC_FLS_AD_FLSAD_Pos)

#define	CRC_FLS_SIZE_FLSS_Pos	0	/* CRC Flash校验数据长度（Word长度） */
#define	CRC_FLS_SIZE_FLSS_Msk	(0x7fffU << CRC_FLS_SIZE_FLSS_Pos)

#define	CRC_POLY_POLY_Pos	0	/* CRC运算多项式系数 */
#define	CRC_POLY_POLY_Msk	(0xffffffffU << CRC_POLY_POLY_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void CRC_Deinit(void);

/* CRC数据寄存器 相关函数 */
extern void CRC_DR_Write(uint32_t SetValue);
extern uint32_t CRC_DR_Read(void);

/* WORD操作使能 相关函数 */
extern void CRC_CR_OPWD_Setable(FunState NewState);
extern FunState CRC_CR_OPWD_Getable(void);

/* CRC快速计算使能 相关函数 */
extern void CRC_CR_PARA_Setable(FunState NewState);
extern FunState CRC_CR_PARA_Getable(void);

/* CRC输入反转控制 相关函数 */
extern void CRC_CR_RFLTIN_Set(uint32_t SetValue);
extern uint32_t CRC_CR_RFLTIN_Get(void);

/* CRC输出反转控制 相关函数 */
extern void CRC_CR_RFLTO_Setable(FunState NewState);
extern FunState CRC_CR_RFLTO_Getable(void);

/* CRC结果标志位，只读 相关函数 */
extern FlagStatus CRC_CR_RES_Chk(void);

/* CRC运算标志位，只读 相关函数 */
extern FlagStatus CRC_CR_BUSY_Chk(void);

/* 输出异或使能 相关函数 */
extern void CRC_CR_XOR_Setable(FunState NewState);
extern FunState CRC_CR_XOR_Getable(void);

/* CRC校验多项式选择 相关函数 */
extern void CRC_CR_SEL_Set(uint32_t SetValue);
extern uint32_t CRC_CR_SEL_Get(void);

/* CRC线性反馈移位寄存器 相关函数 */
extern void CRC_LFSR_Write(uint32_t SetValue);
extern uint32_t CRC_LFSR_Read(void);

/* CRC运算结果异或寄存器 相关函数 */
extern void CRC_XOR_Write(uint32_t SetValue);
extern uint32_t CRC_XOR_Read(void);

/* Flash内容CRC校验使能 相关函数 */
extern void CRC_FLS_CR_FLSCRCEN_Setable(FunState NewState);
extern FunState CRC_FLS_CR_FLSCRCEN_Getable(void);

/* Flash校验起始地址（Word地址） 相关函数 */
extern void CRC_FLS_AD_Write(uint32_t SetValue);
extern uint32_t CRC_FLS_AD_Read(void);

/* CRC Flash校验数据长度（Word长度） 相关函数 */
extern void CRC_FLS_SIZE_Write(uint32_t SetValue);
extern uint32_t CRC_FLS_SIZE_Read(void);

/* CRC运算多项式系数 相关函数 */
extern void CRC_POLY_Write(uint32_t SetValue);
extern uint32_t CRC_POLY_Read(void);
//Announce_End
/* CRC初始化配置函数*/
void CRC_Init(CRC_InitTypeDef* para);
#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_CRC_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
