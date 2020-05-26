/**
  ******************************************************************************
  * @file    fm33l0xx_beeper.h
  * @author  FM33L0xx Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file contains all the functions prototypes for the BEEPER firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33L0XX_BEEPER_H
#define __FM33L0XX_BEEPER_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33L0XX.h" 
   
//------------------------------------------------------------------------------

#define	BEEP_CSR_DIV_Pos	1	/* BEEP波形分频系数,BEEP输出频率为BEEPCLK/(2*(BEEPDIV+1)) */
#define	BEEP_CSR_DIV_Msk	(0xfU << BEEP_CSR_DIV_Pos)
#define	BEEP_CSR_DIV_CLK_DIV2	(0x0U << BEEP_CSR_DIV_Pos)
#define	BEEP_CSR_DIV_CLK_DIV4	(0x1U << BEEP_CSR_DIV_Pos)
#define	BEEP_CSR_DIV_CLK_DIV6	(0x2U << BEEP_CSR_DIV_Pos)
#define	BEEP_CSR_DIV_CLK_DIV8	(0x3U << BEEP_CSR_DIV_Pos)
#define	BEEP_CSR_DIV_CLK_DIV10	(0x4U << BEEP_CSR_DIV_Pos)
#define	BEEP_CSR_DIV_CLK_DIV12	(0x5U << BEEP_CSR_DIV_Pos)
#define	BEEP_CSR_DIV_CLK_DIV14	(0x6U << BEEP_CSR_DIV_Pos)
#define	BEEP_CSR_DIV_CLK_DIV16	(0x7U << BEEP_CSR_DIV_Pos)
#define	BEEP_CSR_DIV_CLK_DIV18	(0x8U << BEEP_CSR_DIV_Pos)
#define	BEEP_CSR_DIV_CLK_DIV20	(0x9U << BEEP_CSR_DIV_Pos)
#define	BEEP_CSR_DIV_CLK_DIV22	(0xaU << BEEP_CSR_DIV_Pos)
#define	BEEP_CSR_DIV_CLK_DIV24	(0xbU << BEEP_CSR_DIV_Pos)
#define	BEEP_CSR_DIV_CLK_DIV26	(0xcU << BEEP_CSR_DIV_Pos)
#define	BEEP_CSR_DIV_CLK_DIV28	(0xdU << BEEP_CSR_DIV_Pos)
#define	BEEP_CSR_DIV_CLK_DIV30	(0xeU << BEEP_CSR_DIV_Pos)
#define	BEEP_CSR_DIV_CLK_DIV32	(0xfU << BEEP_CSR_DIV_Pos)

#define	BEEP_CSR_EN_Pos	0	/* BEEP使能 */
#define	BEEP_CSR_EN_Msk	(0x1U << BEEP_CSR_EN_Pos)
	/* 0：关闭BEEP波形输出 */
	/* 1：使能BEEP波形输出 */
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void BEEP_Deinit(void);

/* BEEP波形分频系数,BEEP输出频率为BEEPCLK/(2*(BEEPDIV+1)) 相关函数 */
extern void BEEP_CSR_DIV_Set(uint32_t SetValue);
extern uint32_t BEEP_CSR_DIV_Get(void);

/* BEEP使能 相关函数 */
extern void BEEP_CSR_EN_Setable(FunState NewState);
extern FunState BEEP_CSR_EN_Getable(void);
//Announce_End

   
#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_BEEPER_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
