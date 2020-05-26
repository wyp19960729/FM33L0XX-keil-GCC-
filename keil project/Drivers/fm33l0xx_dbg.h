/**
  ******************************************************************************
  * @file    fm33l0xx_dbg.h
  * @author  FM33L0xx Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file contains all the functions prototypes for the DBG firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33L0XX_DBG_H
#define __FM33L0XX_DBG_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33L0XX.h"

//------------------------------------------------------------------------------
#define	DBG_CR_AT_STOP_Pos	13	/* Debug状态下ATIM使能控制 */
#define	DBG_CR_AT_STOP_Msk	(0x1U << DBG_CR_AT_STOP_Pos)
	/* 0：Debug时保持ATIM原来状态 */
	/* 1：Debug时保持ATIM原来状态 */

#define	DBG_CR_GT1_STOP_Pos	11	/* Debug状态下GPTIM1使能控制 */
#define	DBG_CR_GT1_STOP_Msk	(0x1U << DBG_CR_GT1_STOP_Pos)
	/* 0：Debug时保持GPTIM2原来状态 */
	/* 1：Debug时关闭GPTIM2 */

#define	DBG_CR_GT0_STOP_Pos	10	/* Debug状态下GPTIM0使能控制 */
#define	DBG_CR_GT0_STOP_Msk	(0x1U << DBG_CR_GT0_STOP_Pos)
	/* 0：Debug时保持GPTIM1原来状态 */
	/* 1：Debug时关闭GPTIM1 */

#define	DBG_CR_BT_STOP_Pos	8	/* Debug状态下BSTIM使能控制 */
#define	DBG_CR_BT_STOP_Msk	(0x1U << DBG_CR_BT_STOP_Pos)
	/* 0：Debug时保持BSTIM原来状态 */
	/* 1：Debug时关闭BSTIM */

#define	DBG_CR_WWDT_STOP_Pos	1	/* Debug状态下WWDT使能控制 */
#define	DBG_CR_WWDT_STOP_Msk	(0x1U << DBG_CR_WWDT_STOP_Pos)
	/* 0：Debug时保持WWDT原来状态 */
	/* 1：Debug时关闭WWDT */

#define	DBG_CR_IWDT_STOP_Pos	0	/* Debug状态下IWDT使能控制 */
#define	DBG_CR_IWDT_STOP_Msk	(0x1U << DBG_CR_IWDT_STOP_Pos)
	/* 0：Debug时保持IWDT开启 */
	/* 1：Debug时关闭IWDT */

#define	DBG_HDFR_DABORT_ADDR_FLAG_Pos	6	/* 地址非对齐访问错误标志 */
#define	DBG_HDFR_DABORT_ADDR_FLAG_Msk	(0x1U << DBG_HDFR_DABORT_ADDR_FLAG_Pos)

#define	DBG_HDFR_DABORT_RESP_FLAG_Pos	5	/* 非法地址访问错误标志 */
#define	DBG_HDFR_DABORT_RESP_FLAG_Msk	(0x1U << DBG_HDFR_DABORT_RESP_FLAG_Pos)

#define	DBG_HDFR_SVCUNDEF_FLAG_Pos	4	/* SVC instructions未定义标志 */
#define	DBG_HDFR_SVCUNDEF_FLAG_Msk	(0x1U << DBG_HDFR_SVCUNDEF_FLAG_Pos)

#define	DBG_HDFR_BKPT_FLAG_Pos	3	/* 执行BKPT指令标志 */
#define	DBG_HDFR_BKPT_FLAG_Msk	(0x1U << DBG_HDFR_BKPT_FLAG_Pos)

#define	DBG_HDFR_TBIT_FLAG_Pos	2	/* Thumb-State标志 */
#define	DBG_HDFR_TBIT_FLAG_Msk	(0x1U << DBG_HDFR_TBIT_FLAG_Pos)

#define	DBG_HDFR_SPECIAL_OP_FLAG_Pos	1	/* 特殊指令标志 */
#define	DBG_HDFR_SPECIAL_OP_FLAG_Msk	(0x1U << DBG_HDFR_SPECIAL_OP_FLAG_Pos)

#define	DBG_HDFR_HDF_REQUEST_FLAG_Pos	0	/* hardfault标志位 */
#define	DBG_HDFR_HDF_REQUEST_FLAG_Msk	(0x1U << DBG_HDFR_HDF_REQUEST_FLAG_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void DBG_Deinit(void);

/* Debug状态下ATIM使能控制 相关函数 */
extern void DBG_CR_AT_STOP_Setable(FunState NewState);
extern FunState DBG_CR_AT_STOP_Getable(void);

/* Debug状态下GPTIM2使能控制 相关函数 */
extern void DBG_CR_GT1_STOP_Setable(FunState NewState);
extern FunState DBG_CR_GT1_STOP_Getable(void);

/* Debug状态下GPTIM1使能控制 相关函数 */
extern void DBG_CR_GT0_STOP_Setable(FunState NewState);
extern FunState DBG_CR_GT0_STOP_Getable(void);

/* Debug状态下BSTIM使能控制 相关函数 */
extern void DBG_CR_BT_STOP_Setable(FunState NewState);
extern FunState DBG_CR_BT_STOP_Getable(void);

/* Debug状态下WWDT使能控制 相关函数 */
extern void DBG_CR_WWDT_STOP_Setable(FunState NewState);
extern FunState DBG_CR_WWDT_STOP_Getable(void);

/* Debug状态下IWDT使能控制 相关函数 */
extern void DBG_CR_IWDT_STOP_Setable(FunState NewState);
extern FunState DBG_CR_IWDT_STOP_Getable(void);

/* 地址非对齐访问错误标志 相关函数 */
extern void DBG_HDFR_DABORT_ADDR_FLAG_Clr(void);
extern FlagStatus DBG_HDFR_DABORT_ADDR_FLAG_Chk(void);

/* 非法地址访问错误标志 相关函数 */
extern void DBG_HDFR_DABORT_RESP_FLAG_Clr(void);
extern FlagStatus DBG_HDFR_DABORT_RESP_FLAG_Chk(void);

/* SVC instructions未定义标志 相关函数 */
extern void DBG_HDFR_SVCUNDEF_FLAG_Clr(void);
extern FlagStatus DBG_HDFR_SVCUNDEF_FLAG_Chk(void);

/* 执行BKPT指令标志 相关函数 */
extern void DBG_HDFR_BKPT_FLAG_Clr(void);
extern FlagStatus DBG_HDFR_BKPT_FLAG_Chk(void);

/* Thumb-State标志 相关函数 */
extern void DBG_HDFR_TBIT_FLAG_Clr(void);
extern FlagStatus DBG_HDFR_TBIT_FLAG_Chk(void);

/* 特殊指令标志 相关函数 */
extern void DBG_HDFR_SPECIAL_OP_FLAG_Clr(void);
extern FlagStatus DBG_HDFR_SPECIAL_OP_FLAG_Chk(void);

/* hardfault标志位 相关函数 */
extern void DBG_HDFR_HDF_REQUEST_FLAG_Clr(void);
extern FlagStatus DBG_HDFR_HDF_REQUEST_FLAG_Chk(void);
//Announce_End
                
#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_DBG_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
