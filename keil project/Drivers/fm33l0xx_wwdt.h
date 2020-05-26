/**
  ******************************************************************************
  * @file    fm33l0xx_wwdt.h
  * @author  FM33L0xx Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file contains all the functions prototypes for the WWDT firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33L0XX_WWDT_H
#define __FM33L0XX_WWDT_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33L0XX.h"
   
//------------------------------------------------------------------------------
#define	WWDT_CR_CON_Pos	0	/* WWDT控制寄存器 */
#define	WWDT_CR_CON_Msk	(0xffU << WWDT_CR_CON_Pos)

#define	WWDT_CFGR_CFG_Pos	0	/* 配置看门狗溢出时间 */
#define	WWDT_CFGR_CFG_Msk	(0x7U << WWDT_CFGR_CFG_Pos)
#define	WWDT_CFGR_CFG_X1	(0x0U << WWDT_CFGR_CFG_Pos)	/* 000：TPCLK * 4096 * 1 */
#define	WWDT_CFGR_CFG_X4	(0x1U << WWDT_CFGR_CFG_Pos)	/* 001：TPCLK * 4096 * 4 */
#define	WWDT_CFGR_CFG_X16	(0x2U << WWDT_CFGR_CFG_Pos)	/* 010：TPCLK * 4096 * 16 */
#define	WWDT_CFGR_CFG_X64	(0x3U << WWDT_CFGR_CFG_Pos)	/* 011：TPCLK * 4096 * 64 */
#define	WWDT_CFGR_CFG_X128	(0x4U << WWDT_CFGR_CFG_Pos)	/* 100：TPCLK * 4096 * 128 */
#define	WWDT_CFGR_CFG_X256	(0x5U << WWDT_CFGR_CFG_Pos)	/* 101：TPCLK * 4096 * 256 */
#define	WWDT_CFGR_CFG_X512	(0x6U << WWDT_CFGR_CFG_Pos)	/* 110：TPCLK * 4096 * 512 */
#define	WWDT_CFGR_CFG_X1024	(0x7U << WWDT_CFGR_CFG_Pos)	/* 111：TPCLK * 4096 * 1024 */

#define	WWDT_CNT_CNT_Pos	0	/* WWDT计数寄存器值 */
#define	WWDT_CNT_CNT_Msk	(0x3ffU << WWDT_CNT_CNT_Pos)

#define	WWDT_IER_IE_Pos	0	/* WWDT中断使能 */
#define	WWDT_IER_IE_Msk	(0x1U << WWDT_IER_IE_Pos)
	/* 0：中断使能禁止 */
	/* 1：中断使能打开 */

#define	WWDT_ISR_IF_Pos	0	/* WWDT 75%计时中断标志，写1清零 */
#define	WWDT_ISR_IF_Msk	(0x1U << WWDT_ISR_IF_Pos)

#define	WWDT_PSC_DIV_CNT_Pos	0	/* WWDT的4096预分频计数器 */
#define	WWDT_PSC_DIV_CNT_Msk	(0xfffU << WWDT_PSC_DIV_CNT_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void WWDT_Deinit(void);

/* WWDT控制寄存器 相关函数 */
extern void WWDT_CR_Write(uint32_t SetValue);

/* 配置看门狗溢出时间 相关函数 */
extern void WWDT_CFGR_CFG_Set(uint32_t SetValue);
extern uint32_t WWDT_CFGR_CFG_Get(void);

/* WWDT计数寄存器值 相关函数 */
extern uint32_t WWDT_CNT_Read(void);

/* WWDT中断使能 相关函数 */
extern void WWDT_IER_IE_Setable(FunState NewState);
extern FunState WWDT_IER_IE_Getable(void);

/* WWDT 75%计时中断标志，写1清零 相关函数 */
extern void WWDT_ISR_IF_Clr(void);
extern FlagStatus WWDT_ISR_IF_Chk(void);

/* WWDT的4096预分频计数器 相关函数 */
extern uint32_t WWDT_PSC_Read(void);
extern uint32_t WWDT_PSC_Read(void);
#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_WWDT_H */

/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
