/**
  ******************************************************************************
  * @file    fm33l0xx_svd.h
  * @author  FM33L0xx Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file contains all the functions prototypes for the SPI firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33L0XX_SVD_H
#define __FM33L0XX_SVD_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33L0XX.h"

//------------------------------------------------------------------------------
typedef struct
{
	uint32_t	SVDMOD;		/*!<SVD工作模式选择  */
	uint32_t	SVDITVL;	/*!<SVD间歇使能间隔  */
	uint32_t	SVDLVL;		/*!<SVD报警阈值设置  */
	FunState	DFEN;		/*!<SVD数字滤波（SVDMODE=1时必须置1）  */
	FunState	PFIE;		/*!<SVD电源跌落中断  */
	FunState	PRIE;		/*!<SVD电源恢复中断  */
	FunState	SVDEN;		/*!<SVD使能  */
	
}ANAC_SVD_InitTypeDef;

#define	SVD_CFGR_LVL_Pos	4	/* SVD报警阈值设置(SVD threshold level)
 */
#define	SVD_CFGR_LVL_Msk	(0xfU << SVD_CFGR_LVL_Pos)
#define	SVD_CFGR_LVL_1P800V	(0x0U << SVD_CFGR_LVL_Pos)	/* 0000_1.913V_2.019V（SVDLVL_下降阈值_上升阈值） */
#define	SVD_CFGR_LVL_2P014V	(0x1U << SVD_CFGR_LVL_Pos)	/* 0001_2.014V_2.114V */
#define	SVD_CFGR_LVL_2P229V	(0x2U << SVD_CFGR_LVL_Pos)	/* 0010_2.229V_2.329V */
#define	SVD_CFGR_LVL_2P443V	(0x3U << SVD_CFGR_LVL_Pos)	/* 0011_2.443V_2.543V */
#define	SVD_CFGR_LVL_2P657V	(0x4U << SVD_CFGR_LVL_Pos)	/* 0100_2.657V_2.757V */
#define	SVD_CFGR_LVL_2P871V	(0x5U << SVD_CFGR_LVL_Pos)	/* 0101_2.871V_2.971V */
#define	SVD_CFGR_LVL_3P086V	(0x6U << SVD_CFGR_LVL_Pos)	/* 0110_3.086V_3.186V */
#define	SVD_CFGR_LVL_3P300V	(0x7U << SVD_CFGR_LVL_Pos)	/* 0111_3.300V_3.400V */
#define	SVD_CFGR_LVL_3P514V	(0x8U << SVD_CFGR_LVL_Pos)	/* 1000_3.514V_3.614V */
#define	SVD_CFGR_LVL_3P729V	(0x9U << SVD_CFGR_LVL_Pos)	/* 1001_3.729V_3.829V */
#define	SVD_CFGR_LVL_3P943V	(0xaU << SVD_CFGR_LVL_Pos)	/* 1010_3.943V_4.043V */
#define	SVD_CFGR_LVL_4P157V	(0xbU << SVD_CFGR_LVL_Pos)	/* 1011_4.157V_4.257V */
#define	SVD_CFGR_LVL_4P371V	(0xcU << SVD_CFGR_LVL_Pos)	/* 1100_4.371V_4.471V */
#define	SVD_CFGR_LVL_4P586V	(0xdU << SVD_CFGR_LVL_Pos)	/* 1101_4.586V_4.686V */
#define	SVD_CFGR_LVL_4P800V	(0xeU << SVD_CFGR_LVL_Pos)	/* 1110_4.800V_4.900V */
#define	SVD_CFGR_LVL_SVS	(0xfU << SVD_CFGR_LVL_Pos)	/* 1111_SVS_SVS  固定检测0.8V  */

#define	SVD_CFGR_DFEN_Pos	3	/* 数字滤波使能（SVDMODE=1时必须置1）(Digital Filter Enable) */
#define	SVD_CFGR_DFEN_Msk	(0x1U << SVD_CFGR_DFEN_Pos)
	/* 0：关闭SVD输出的数字滤波 */
	/* 1：启动SVD输出的数字滤波 */

#define	SVD_CFGR_MOD_Pos	2	/* SVD工作模式选择，配置模式后还要置位SVDEN才会启动SVD */
#define	SVD_CFGR_MOD_Msk	(0x1U << SVD_CFGR_MOD_Pos)
#define	SVD_CFGR_MOD_ALWAYSON	(0x0U << SVD_CFGR_MOD_Pos)	/* 0：常使能模式 */
#define	SVD_CFGR_MOD_INTERVAL	(0x1U << SVD_CFGR_MOD_Pos)	/* 1：间歇使能模式 */

#define	SVD_CFGR_ITVL_Pos	0	/* SVD间歇使能间隔(SVD Interval) */
#define	SVD_CFGR_ITVL_Msk	(0x3U << SVD_CFGR_ITVL_Pos)
#define	SVD_CFGR_ITVL_62P5MS	(0x0U << SVD_CFGR_ITVL_Pos)	/* 00：62.5ms */
#define	SVD_CFGR_ITVL_256MS	(0x1U << SVD_CFGR_ITVL_Pos)	/* 01：256s */
#define	SVD_CFGR_ITVL_1S	(0x2U << SVD_CFGR_ITVL_Pos)	/* 10：1s */
#define	SVD_CFGR_ITVL_4S	(0x3U << SVD_CFGR_ITVL_Pos)	/* 11：4s */

#define	SVD_CR_TE_Pos	8	/* SVD测试使能，避免写1 (SVD test enable) */
#define	SVD_CR_TE_Msk	(0x1U << SVD_CR_TE_Pos)
	/* 0:SVD测试使能 */
	/* 1：SVD测试禁止 */

#define	SVD_CR_SVSEN_Pos	1	/* SVS外部电源检测通道控制信号(SVS external monitor channel enable) */
#define	SVD_CR_SVSEN_Msk	(0x1U << SVD_CR_SVSEN_Pos)
	/* 0：SVS通道关闭 */
	/* 1：SVS通道使能 */

#define	SVD_CR_EN_Pos	0	/* SVD使能 (SVD enable) */
#define	SVD_CR_EN_Msk	(0x1U << SVD_CR_EN_Pos)
	/* 0：关闭SVD */
	/* 1：启动SVD */

#define	SVD_IER_PFIE_Pos	1	/* 电源跌落中断使能(Power Fall interrupt enable) */
#define	SVD_IER_PFIE_Msk	(0x1U << SVD_IER_PFIE_Pos)
	/* 0：SVD电源跌落中断使能 */
	/* 1：SVD电源跌落中断禁止 */

#define	SVD_IER_PRIE_Pos	0	/* 电源恢复中断使能(Power Rise interrupt enable) */
#define	SVD_IER_PRIE_Msk	(0x1U << SVD_IER_PRIE_Pos)
	/* 0：SVD电源恢复中断使能 */
	/* 1：SVD电源恢复中断禁止 */

#define	SVD_ISR_SVDO_Pos	8	/* SVD电源检测输出 (SVD output) */
#define	SVD_ISR_SVDO_Msk	(0x1U << SVD_ISR_SVDO_Pos)

#define	SVD_ISR_SVDR_Pos	7	/* SVD输出锁存信号，数字电路锁存的SVD状态 */
#define	SVD_ISR_SVDR_Msk	(0x1U << SVD_ISR_SVDR_Pos)

#define	SVD_ISR_PFF_Pos	1	/* 电源跌落中断标志 */
#define	SVD_ISR_PFF_Msk	(0x1U << SVD_ISR_PFF_Pos)

#define	SVD_ISR_PRF_Pos	0	/* 电源恢复中断标志 */
#define	SVD_ISR_PRF_Msk	(0x1U << SVD_ISR_PRF_Pos)

#define	SVD_VSR_V0P85EN_Pos	2	/* 0.85V基准输入使能信号 (0.85V reference enable) */
#define	SVD_VSR_V0P85EN_Msk	(0x1U << SVD_VSR_V0P85EN_Pos)
	/* 0：关闭0.85V基准输入 */
	/* 1：使能0.85V基准输入 */

#define	SVD_VSR_V0P8EN_Pos	1	/* 0.8V基准输入使能信号 (0.8V reference enable) */
#define	SVD_VSR_V0P8EN_Msk	(0x1U << SVD_VSR_V0P8EN_Pos)
	/* 0：关闭0.8V基准输入 */
	/* 1：使能0.8V基准输入 */

#define	SVD_VSR_V0P75EN_Pos	0	/* 0.75V基准输入使能信号 (0.75V reference enable) */
#define	SVD_VSR_V0P75EN_Msk	(0x1U << SVD_VSR_V0P75EN_Pos)
	/* 0：关闭0.75V基准输入 */
	/* 1：使能0.75V基准输入 */
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void SVD_Deinit(void);

/* SVD报警阈值设置(SVD threshold level)
 相关函数 */
extern void SVD_CFGR_LVL_Set(uint32_t SetValue);
extern uint32_t SVD_CFGR_LVL_Get(void);

/* 数字滤波使能（SVDMODE=1时必须置1）(Digital Filter Enable) 相关函数 */
extern void SVD_CFGR_DFEN_Setable(FunState NewState);
extern FunState SVD_CFGR_DFEN_Getable(void);

/* SVD工作模式选择，配置模式后还要置位SVDEN才会启动SVD 相关函数 */
extern void SVD_CFGR_MOD_Set(uint32_t SetValue);
extern uint32_t SVD_CFGR_MOD_Get(void);

/* SVD间歇使能间隔(SVD Interval) 相关函数 */
extern void SVD_CFGR_ITVL_Set(uint32_t SetValue);
extern uint32_t SVD_CFGR_ITVL_Get(void);

/* SVD测试使能，避免写1 (SVD test enable) 相关函数 */
extern void SVD_CR_TE_Setable(FunState NewState);
extern FunState SVD_CR_TE_Getable(void);

/* SVS外部电源检测通道控制信号(SVS external monitor channel enable) 相关函数 */
extern void SVD_CR_SVSEN_Setable(FunState NewState);
extern FunState SVD_CR_SVSEN_Getable(void);

/* SVD使能 (SVD enable) 相关函数 */
extern void SVD_CR_EN_Setable(FunState NewState);
extern FunState SVD_CR_EN_Getable(void);

/* 电源跌落中断使能(Power Fall interrupt enable) 相关函数 */
extern void SVD_IER_PFIE_Setable(FunState NewState);
extern FunState SVD_IER_PFIE_Getable(void);

/* 电源恢复中断使能(Power Rise interrupt enable) 相关函数 */
extern void SVD_IER_PRIE_Setable(FunState NewState);
extern FunState SVD_IER_PRIE_Getable(void);

/* SVD电源检测输出 (SVD output) 相关函数 */
extern FlagStatus SVD_ISR_SVDO_Chk(void);

/* SVD输出锁存信号，数字电路锁存的SVD状态 相关函数 */
extern FlagStatus SVD_ISR_SVDR_Chk(void);

/* 电源跌落中断标志 相关函数 */
extern void SVD_ISR_PFF_Clr(void);
extern FlagStatus SVD_ISR_PFF_Chk(void);

/* 电源恢复中断标志 相关函数 */
extern void SVD_ISR_PRF_Clr(void);
extern FlagStatus SVD_ISR_PRF_Chk(void);

/* 0.85V基准输入使能信号 (0.85V reference enable) 相关函数 */
extern void SVD_VSR_V0P85EN_Setable(FunState NewState);
extern FunState SVD_VSR_V0P85EN_Getable(void);

/* 0.8V基准输入使能信号 (0.8V reference enable) 相关函数 */
extern void SVD_VSR_V0P8EN_Setable(FunState NewState);
extern FunState SVD_VSR_V0P8EN_Getable(void);

/* 0.75V基准输入使能信号 (0.75V reference enable) 相关函数 */
extern void SVD_VSR_V0P75EN_Setable(FunState NewState);
extern FunState SVD_VSR_V0P75EN_Getable(void); 

extern void SVD_Init(ANAC_SVD_InitTypeDef* para);
#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_SVD_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
