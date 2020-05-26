/**
  ******************************************************************************
  * @file    fm33l0xx_flash.h
  * @author  FM33L0xx Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file contains all the functions prototypes for the FLASH firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33L0XX_FLASH_H
#define __FM33L0XX_FLASH_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33L0XX.h" 

#define FLS_SECTOR_ERASE_KEY0 	((uint32_t)0x96969696)
#define FLS_SECTOR_ERASE_KEY1 	((uint32_t)0xEAEAEAEA)
	 
#define FLS_ERASE_DATA 			((uint32_t)0x1234ABCD)

#define FLS_PROG_KEY0 			((uint32_t)0xA5A5A5A5)
#define FLS_PROG_KEY1 			((uint32_t)0xF1F1F1F1)
     
//------------------------------------------------------------------------------

#define	FLS_RDCR_WAIT_Pos	0	/* Flash读等待周期配置(CPU时钟超过24M后需开wait1) */
#define	FLS_RDCR_WAIT_Msk	(0x3U << FLS_RDCR_WAIT_Pos)
#define	FLS_RDCR_WAIT_0CYCLE	(0x0U << FLS_RDCR_WAIT_Pos)	/* 00/11：0 wait cycle */
#define	FLS_RDCR_WAIT_1CYCLE	(0x1U << FLS_RDCR_WAIT_Pos)	/* 01：1 wait cycle */
#define	FLS_RDCR_WAIT_2CYCLE	(0x2U << FLS_RDCR_WAIT_Pos)	/* 10：2 wait cycles */

#define	FLS_OPTBR_DBGOFF_EN_Pos	31	/* 用户配置字寄存器 */
#define	FLS_OPTBR_DBGOFF_EN_Msk	(0x1U << FLS_OPTBR_DBGOFF_EN_Pos)
	/* 0：MCUDBGCR寄存器使能 */
	/* 1：屏蔽MCUDBGCR寄存器功能 */

#define	FLS_OPTBR_BTSEN_Pos	8
#define	FLS_OPTBR_BTSEN_Msk	(0x3U << FLS_OPTBR_BTSEN_Pos)
	/* 00/01/11：禁止BootSwap功能 */
	/* 10：允许BootSwap */

#define	FLS_OPTBR_ACLOCKEN_Pos	2
#define	FLS_OPTBR_ACLOCKEN_Msk	(0x3U << FLS_OPTBR_ACLOCKEN_Pos)
	/* 00/01/11：ACLOCK不使能 */
	/* 10：ACLOCK使能 */

#define	FLS_OPTBR_DBRDPEN_Pos	0
#define	FLS_OPTBR_DBRDPEN_Msk	(0x3U << FLS_OPTBR_DBRDPEN_Pos)
	/* 00/01/11：DBRDP不使能 */
	/* 10：DBRDP使能 */

#define	FLS_ACLOCK_LOCK_Pos	0	/* ACLOCK配置寄存器 */
#define	FLS_ACLOCK_LOCK_Msk	(0xffffffffU << FLS_ACLOCK_LOCK_Pos)

#define	FLS_EPCR_ERTYPE_Pos	8	/* 扇区擦 */
#define	FLS_EPCR_ERTYPE_Msk	(0x3U << FLS_EPCR_ERTYPE_Pos)
#define	FLS_EPCR_ERTYPE_SECTOR	(0x0U << FLS_EPCR_ERTYPE_Pos)	/* 00/11：Sector Erase */
#define	FLS_EPCR_ERTYPE_CHIP_ERASE	(0x2U << FLS_EPCR_ERTYPE_Pos)	/* 10：Chip Erase (SWD only) */

#define	FLS_EPCR_PREQ_Pos	1
#define	FLS_EPCR_PREQ_Msk	(0x1U << FLS_EPCR_PREQ_Pos)
#define	FLS_EPCR_PREQ_NONE	(0x0U << FLS_EPCR_PREQ_Pos)
#define	FLS_EPCR_PREQ_PROG	(0x1U << FLS_EPCR_PREQ_Pos)	/* Program Request软件置位，硬件完成编程后自动清零 */

#define	FLS_EPCR_EREQ_Pos	0
#define	FLS_EPCR_EREQ_Msk	(0x1U << FLS_EPCR_EREQ_Pos)
#define	FLS_EPCR_EREQ_NONE	(0x0U << FLS_EPCR_EREQ_Pos)
#define	FLS_EPCR_EREQ_ERASE	(0x1U << FLS_EPCR_EREQ_Pos)	/* Erase Request软件置位，硬件完成擦除后自动清零 */

#define	FLS_KEY_FLSKEY_Pos	0	/* Flash擦写Key输入寄存器，软件或者SWD在启动擦写前必须正确地向此地址写入合法KEY序列。空地址，物理上无寄存器实现。 */
#define	FLS_KEY_FLSKEY_Msk	(0xffffffffU << FLS_KEY_FLSKEY_Pos)

#define	FLS_IER_AUTHIE_Pos	10	/* Flash读写权限错误中断使能 (Flash Authentication Error Interrupt Enable) */
#define	FLS_IER_AUTHIE_Msk	(0x1U << FLS_IER_AUTHIE_Pos)

#define	FLS_IER_KEYIE_Pos	9	/* Flash KEY错误中断使能 (Flash Key Error Interrupt Enable) */
#define	FLS_IER_KEYIE_Msk	(0x1U << FLS_IER_KEYIE_Pos)

#define	FLS_IER_CKIE_Pos	8	/* 擦写定时时钟错误中断使能 (Erase/Program Clock Error Interrupt Enable) */
#define	FLS_IER_CKIE_Msk	(0x1U << FLS_IER_CKIE_Pos)

#define	FLS_IER_PRDIE_Pos	1	/* 编程完成标志中断使能 (Program Done Interrupt Enable) */
#define	FLS_IER_PRDIE_Msk	(0x1U << FLS_IER_PRDIE_Pos)

#define	FLS_IER_ERDIE_Pos	0	/* 擦写完成标志中断使能 (Erase Done Interrupt Enable) */
#define	FLS_IER_ERDIE_Msk	(0x1U << FLS_IER_ERDIE_Pos)

#define	FLS_ISR_KEYSTA_Pos	17	/* Flash标志寄存器 */
#define	FLS_ISR_KEYSTA_Msk	(0x7U << FLS_ISR_KEYSTA_Pos)
#define	FLS_ISR_KEYSTA_KEY_NONE_PROTECT	(0x0U << FLS_ISR_KEYSTA_Pos)	/* 000：Flash写保护状态，未输入KEY */
#define	FLS_ISR_KEYSTA_CHIP_ERASE	(0x1U << FLS_ISR_KEYSTA_Pos)	/* 001：全擦解锁状态 */
#define	FLS_ISR_KEYSTA_SECTOR_ERASE	(0x2U << FLS_ISR_KEYSTA_Pos)	/* 010：扇区擦解锁状态 */
#define	FLS_ISR_KEYSTA_PROGRAM	(0x3U << FLS_ISR_KEYSTA_Pos)	/* 011：编程解锁状态 */
#define	FLS_ISR_KEYSTA_KEY_ERR_PROTECT	(0x4U << FLS_ISR_KEYSTA_Pos)	/* 100：KEY错误锁定状态，需要复位才能解锁 */

#define	FLS_ISR_BTSF_Pos	16
#define	FLS_ISR_BTSF_Msk	(0x1U << FLS_ISR_BTSF_Pos)
#define	FLS_ISR_BTSF_START_0000H	(0x0U << FLS_ISR_BTSF_Pos)	/* 0：启动程序区为Flash物理地址0000H~1FFFH */
#define	FLS_ISR_BTSF_START_2000H	(0x1U << FLS_ISR_BTSF_Pos)	/* 1：启动程序区为Flash物理地址2000H~3FFFH */

#define	FLS_ISR_AUTHERR_Pos	10
#define	FLS_ISR_AUTHERR_Msk	(0x1U << FLS_ISR_AUTHERR_Pos)

#define	FLS_ISR_KEYERR_Pos	9
#define	FLS_ISR_KEYERR_Msk	(0x1U << FLS_ISR_KEYERR_Pos)

#define	FLS_ISR_CKERR_Pos	8
#define	FLS_ISR_CKERR_Msk	(0x1U << FLS_ISR_CKERR_Pos)

#define	FLS_ISR_PRD_Pos	1
#define	FLS_ISR_PRD_Msk	(0x1U << FLS_ISR_PRD_Pos)

#define	FLS_ISR_ERD_Pos	0
#define	FLS_ISR_ERD_Msk	(0x1U << FLS_ISR_ERD_Pos)

/* Exported functions --------------------------------------------------------*/ 
extern void FLS_Deinit(void);

/* Flash读等待周期配置(CPU时钟超过24M后需开wait1) 相关函数 */
extern void FLS_RDCR_WAIT_Set(uint32_t SetValue);
extern uint32_t FLS_RDCR_WAIT_Get(void);

/* 用户配置字寄存器 相关函数 */
extern FunState FLS_OPTBR_DBGOFF_EN_Getable(void);
extern FunState FLS_OPTBR_BTSEN_Getable(void);
extern FunState FLS_OPTBR_ACLOCKEN_Getable(void);
extern FunState FLS_OPTBR_DBRDPEN_Getable(void);

/* ACLOCK配置寄存器 相关函数 */
extern void FLS_ACLOCK_Write(uint32_t SetValue);
extern uint32_t FLS_ACLOCK_Read(void);

/* 扇区擦 相关函数 */
extern void FLS_EPCR_ERTYPE_Set(uint32_t SetValue);
extern uint32_t FLS_EPCR_ERTYPE_Get(void);
extern void FLS_EPCR_PREQ_Set(uint32_t SetValue);
extern uint32_t FLS_EPCR_PREQ_Get(void);
extern void FLS_EPCR_EREQ_Set(uint32_t SetValue);
extern uint32_t FLS_EPCR_EREQ_Get(void);

/* Flash擦写Key输入寄存器，软件或者SWD在启动擦写前必须正确地向此地址写入合法KEY序列。空地址，物理上无寄存器实现。 相关函数 */
extern void FLS_KEY_Write(uint32_t SetValue);

/* Flash读写权限错误中断使能 (Flash Authentication Error Interrupt Enable) 相关函数 */
extern void FLS_IER_AUTHIE_Setable(FunState NewState);
extern FunState FLS_IER_AUTHIE_Getable(void);

/* Flash KEY错误中断使能 (Flash Key Error Interrupt Enable) 相关函数 */
extern void FLS_IER_KEYIE_Setable(FunState NewState);
extern FunState FLS_IER_KEYIE_Getable(void);

/* 擦写定时时钟错误中断使能 (Erase/Program Clock Error Interrupt Enable) 相关函数 */
extern void FLS_IER_CKIE_Setable(FunState NewState);
extern FunState FLS_IER_CKIE_Getable(void);

/* 编程完成标志中断使能 (Program Done Interrupt Enable) 相关函数 */
extern void FLS_IER_PRDIE_Setable(FunState NewState);
extern FunState FLS_IER_PRDIE_Getable(void);

/* 擦写完成标志中断使能 (Erase Done Interrupt Enable) 相关函数 */
extern void FLS_IER_ERDIE_Setable(FunState NewState);
extern FunState FLS_IER_ERDIE_Getable(void);

/* Flash标志寄存器 相关函数 */
extern uint32_t FLS_ISR_KEYSTA_Get(void);
extern uint32_t FLS_ISR_BTSF_Get(void);
extern void FLS_ISR_AUTHERR_Clr(void);
extern FlagStatus FLS_ISR_AUTHERR_Chk(void);
extern void FLS_ISR_KEYERR_Clr(void);
extern FlagStatus FLS_ISR_KEYERR_Chk(void);
extern void FLS_ISR_CKERR_Clr(void);
extern FlagStatus FLS_ISR_CKERR_Chk(void);
extern void FLS_ISR_PRD_Clr(void);
extern FlagStatus FLS_ISR_PRD_Chk(void);
extern void FLS_ISR_ERD_Clr(void);
extern FlagStatus FLS_ISR_ERD_Chk(void);


extern void FLASH_Erase_Sector(uint32_t erase_addr);
extern void FLASH_Prog_SingleByte(uint32_t prog_addr,uint8_t prog_data);
extern void FLASH_Prog_ByteString(uint32_t prog_addr,uint8_t* prog_data, uint16_t Len);
     

#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_FLASH_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
