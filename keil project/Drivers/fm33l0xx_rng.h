/**
  ******************************************************************************
  * @file    fm33l0xx_rng.h
  * @author  FM33L0xx Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file contains all the functions prototypes for the RNG firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33L0XX_RNG_H
#define __FM33L0XX_RNG_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33L0XX.h"

//------------------------------------------------------------------------------
#define	RNG_CR_EN_Pos	0	/* RNG使能寄存器，软件写1使能 */
#define	RNG_CR_EN_Msk	(0x1U << RNG_CR_EN_Pos)
	/* 0：关闭RNG */
	/* 1：使能RNG */

#define	RNG_DOR_OUT_Pos	0	/* 随机数生成结果或CRC运算结果寄存器 */
#define	RNG_DOR_OUT_Msk	(0xffffffffU << RNG_DOR_OUT_Pos)

#define	RNG_SR_LFSREN_Pos	1	/* LFSR使能标志,本寄存器不会引起模块中断，仅供查询 */
#define	RNG_SR_LFSREN_Msk	(0x1U << RNG_SR_LFSREN_Pos)

#define	RNG_SR_RNF_Pos	0	/* 随机数生成失败标志，软件写1清0 */
#define	RNG_SR_RNF_Msk	(0x1U << RNG_SR_RNF_Pos)

#define	RNG_CRC_CR_CRCEN_Pos	0	/* CRC控制寄存器 */
#define	RNG_CRC_CR_CRCEN_Msk	(0x1U << RNG_CRC_CR_CRCEN_Pos)
	/* 0：CRC关闭 */
	/* 1：CRC使能 */

#define	RNG_CRC_DIR_CRCIN_Pos	0	/* CRC运算数据输入寄存器 */
#define	RNG_CRC_DIR_CRCIN_Msk	(0xffffffffU << RNG_CRC_DIR_CRCIN_Pos)

#define	RNG_CRC_SR_CRCDONE_Pos	0	/* CRC计算完成标志，软件写0清零 */
#define	RNG_CRC_SR_CRCDONE_Msk	(0x1U << RNG_CRC_SR_CRCDONE_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void RNG_Deinit(void);

/* RNG使能寄存器，软件写1使能 相关函数 */
extern void RNG_CR_EN_Setable(FunState NewState);
extern FunState RNG_CR_EN_Getable(void);

/* 随机数生成结果或CRC运算结果寄存器 相关函数 */
extern uint32_t RNG_DOR_Read(void);

/* LFSR使能标志,本寄存器不会引起模块中断，仅供查询 相关函数 */
extern FlagStatus RNG_SR_LFSREN_Chk(void);

/* 随机数生成失败标志，软件写1清0 相关函数 */
extern void RNG_SR_RNF_Clr(void);
extern FlagStatus RNG_SR_RNF_Chk(void);

/* CRC控制寄存器 相关函数 */
extern void RNG_CRC_CR_CRCEN_Setable(FunState NewState);
extern FunState RNG_CRC_CR_CRCEN_Getable(void);

/* CRC运算数据输入寄存器 相关函数 */
extern void RNG_CRC_DIR_Write(uint32_t SetValue);
extern uint32_t RNG_CRC_DIR_Read(void);

/* CRC计算完成标志，软件写0清零 相关函数 */
extern void RNG_CRC_SR_CRCDONE_Clr(void);
extern FlagStatus RNG_CRC_SR_CRCDONE_Chk(void);


                
#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_RNG_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
