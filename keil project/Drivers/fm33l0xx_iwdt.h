/**
  ******************************************************************************
  * @file    fm33l0xx_iwdt.h
  * @author  FM33L0xx Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file contains all the functions prototypes for the IWDT firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33L0XX_IWDT_H
#define __FM33L0XX_IWDT_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33L0XX.h" 
   
//------------------------------------------------------------------------------

#define WDTSERV_key	((uint32_t)0x12345A5A)
   
#define	IWDT_SERV_SERV_Pos	0	/* IWDT清除寄存器 */
#define	IWDT_SERV_SERV_Msk	(0xffffffffU << IWDT_SERV_SERV_Pos)

#define	IWDT_CR_CFG_Pos	0	/* 配置IWDT看门狗溢出时间 */
#define	IWDT_CR_CFG_Msk	(0x7U << IWDT_CR_CFG_Pos)
#define	IWDT_CR_CFG_0P125S	(0x0U << IWDT_CR_CFG_Pos)
#define	IWDT_CR_CFG_0P250S	(0x1U << IWDT_CR_CFG_Pos)
#define	IWDT_CR_CFG_0P500S  (0x2U << IWDT_CR_CFG_Pos)
#define	IWDT_CR_CFG_1S    	(0x3U << IWDT_CR_CFG_Pos)
#define	IWDT_CR_CFG_2S	    (0x4U << IWDT_CR_CFG_Pos)
#define	IWDT_CR_CFG_4S	    (0x5U << IWDT_CR_CFG_Pos)
#define	IWDT_CR_CFG_8S	    (0x6U << IWDT_CR_CFG_Pos)
#define	IWDT_CR_CFG_16S	    (0x7U << IWDT_CR_CFG_Pos)

#define	IWDT_CNT_CNT_Pos	0	/* IWDT当前计数值 */
#define	IWDT_CNT_CNT_Msk	(0xfffU << IWDT_CNT_CNT_Pos)

#define	IWDT_WIN_WIN_Pos	0	/* IWDT窗口寄存器 */
#define	IWDT_WIN_WIN_Msk	(0xfffU << IWDT_WIN_WIN_Pos)

#define	IWDT_SR_BUSY_Pos	0	/* IWDT清狗状态标志 */
#define	IWDT_SR_BUSY_Msk	(0x1U << IWDT_SR_BUSY_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void IWDT_Deinit(void);

/* IWDT清除寄存器 相关函数 */
extern void IWDT_SERV_Write(uint32_t SetValue);

/* 配置IWDT看门狗溢出时间 相关函数 */
extern void IWDT_CR_CFG_Set(uint32_t SetValue);
extern uint32_t IWDT_CR_CFG_Get(void);

/* IWDT当前计数值 相关函数 */
extern uint32_t IWDT_CNT_Read(void);

/* IWDT窗口寄存器 相关函数 */
extern void IWDT_WIN_Write(uint32_t SetValue);
extern uint32_t IWDT_WIN_Read(void);

/* IWDT清狗状态标志 相关函数 */
extern FlagStatus IWDT_SR_BUSY_Chk(void);   

extern void IWDT_Clr(void);

#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_IWDT_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
