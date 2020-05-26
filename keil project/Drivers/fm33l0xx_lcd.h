/**
  ******************************************************************************
  * @file    fm33l0xx_lcd.h
  * @author  FM33l0xx Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file contains all the functions prototypes for the LCD firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __FM33L0XX_LCD_H
#define __FM33L0XX_LCD_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33L0XX.h" 
   
typedef struct
{       
	uint32_t			LMUX;		/*!<COM数量选择*/	
	uint32_t			ENMODE;		/*!<驱动模式选择*/
	uint32_t			WFT;		/*!<驱动波形选择*/
	uint32_t			DF;			/*!<显示频率控制寄存器*/
	uint32_t			BIASMD;		/*!<偏置类型控制*/
	uint32_t			SCFSEL;		/*!<SC频率选择*/  //仅在片外电容模式下有效
	uint32_t			SC_CTRL;	/*!<片外电容驱动模式下，驱动方式控制*/
	uint32_t			IC_CTRL;	/*!<片内电阻模式下，驱动电流大小*/
	uint32_t			LCDBIAS;	/*!<显示灰度设置*/
	FunState			ANTIPOLAR;	/*!<防极化使能控制*/
	
	uint32_t			LCCTRL;		/*!<保持为0*/
	FunState			TESTEN;		/*!<保持关闭*/
	
	FunState			FLICK;		/*!<显示闪烁使能位*/
	uint32_t			TON;		/*!<闪烁显示时的点亮时间＝TON×0.25秒*/
	uint32_t			TOFF;		/*!<闪烁显示时的熄灭时间＝TOFF×0.25秒*/
	FunState			DONIE;		/*!<显示点亮中断使能控制*/
	FunState			DOFFIE;		/*!<显示熄灭中断使能控制*/
	
	FunState			LCDEN;		/*!<LCD显示使能控制*/
}LCD_InitTypeDef;
     
#define	LCD_CR_SCFSEL_Pos	20	/* 电容驱动频率选择 */
#define	LCD_CR_SCFSEL_Msk	(0x7U << LCD_CR_SCFSEL_Pos)
#define	LCD_CR_SCFSEL_X1	(0x0U << LCD_CR_SCFSEL_Pos)	/* 帧频*COM数 */
#define	LCD_CR_SCFSEL_X8	(0x1U << LCD_CR_SCFSEL_Pos)	/* LSCLK/8 */
#define	LCD_CR_SCFSEL_X16	(0x2U << LCD_CR_SCFSEL_Pos)	/* LSCLK/16 */
#define	LCD_CR_SCFSEL_X32	(0x3U << LCD_CR_SCFSEL_Pos)	/* LSCLK/32 */
#define	LCD_CR_SCFSEL_X64	(0x4U << LCD_CR_SCFSEL_Pos)	/* LSCLK/64 */
#define	LCD_CR_SCFSEL_X128	(0x5U << LCD_CR_SCFSEL_Pos)	/* LSCLK/128 */
#define	LCD_CR_SCFSEL_X256	(0x6U << LCD_CR_SCFSEL_Pos)	/* LSCLK/256 */
#define	LCD_CR_SCFSEL_X512	(0x7U << LCD_CR_SCFSEL_Pos)	/* LSCLK/512 */

#define	LCD_CR_SC_CTRL_Pos	18	/* 片外电容驱动方式控制 */
#define	LCD_CR_SC_CTRL_Msk	(0x3U << LCD_CR_SC_CTRL_Pos)
#define	LCD_CR_SC_CTRL_ONE	(0x0U << LCD_CR_SC_CTRL_Pos)	/* 单次驱动 */
#define	LCD_CR_SC_CTRL_TWO	(0x1U << LCD_CR_SC_CTRL_Pos)	/* 连续驱动两次 */
#define	LCD_CR_SC_CTRL_FOUR	(0x2U << LCD_CR_SC_CTRL_Pos)	/* 连续驱动四次 */
#define	LCD_CR_SC_CTRL_CONTINUE	(0x3U << LCD_CR_SC_CTRL_Pos)	/* 多次驱动 */

#define	LCD_CR_IC_CTRL_Pos	16	/* 偏置电路输入电流源大小控制 */
#define	LCD_CR_IC_CTRL_Msk	(0x3U << LCD_CR_IC_CTRL_Pos)
#define	LCD_CR_IC_CTRL_L3	(0x0U << LCD_CR_IC_CTRL_Pos)	/* 电流最大 */
#define	LCD_CR_IC_CTRL_L2	(0x1U << LCD_CR_IC_CTRL_Pos)	/* 电流次大 */
#define	LCD_CR_IC_CTRL_L1	(0x2U << LCD_CR_IC_CTRL_Pos)	/* 电流次小 */
#define	LCD_CR_IC_CTRL_L0	(0x3U << LCD_CR_IC_CTRL_Pos)	/* 电流最小 */

#define	LCD_CR_ENMODE_Pos	15	/* 驱动模式选择 */
#define	LCD_CR_ENMODE_Msk	(0x1U << LCD_CR_ENMODE_Pos)
#define	LCD_CR_ENMODE_EXTERNALCAP	(0x0U << LCD_CR_ENMODE_Pos)	/* 片外电容驱动 */
#define	LCD_CR_ENMODE_INNERRESISTER	(0x1U << LCD_CR_ENMODE_Pos)	/* 片内电阻驱动 */

#define	LCD_CR_FLICK_Pos	14	/* 显示闪烁控制 */
#define	LCD_CR_FLICK_Msk	(0x1U << LCD_CR_FLICK_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_CR_BIAS_Pos	8	/* 显示灰度设置 */
#define	LCD_CR_BIAS_Msk	(0xfU << LCD_CR_BIAS_Pos)

#define	LCD_CR_BIASMD_Pos	5	/* 偏置类型控制 */
#define	LCD_CR_BIASMD_Msk	(0x1U << LCD_CR_BIASMD_Pos)
#define	LCD_CR_BIASMD_4BIAS	(0x0U << LCD_CR_BIASMD_Pos)	/* 1/4 Bias */
#define	LCD_CR_BIASMD_3BIAS	(0x1U << LCD_CR_BIASMD_Pos)	/* 1/3 Bias */

#define	LCD_CR_ANTIPOLAR_Pos	4	/* 防极化 */
#define	LCD_CR_ANTIPOLAR_Msk	(0x1U << LCD_CR_ANTIPOLAR_Pos)
	/* COM和SEG在LCD关闭情况下浮空 */
	/* COM和SEG在LCD关闭情况下接地 */

#define	LCD_CR_WFT_Pos	3	/* 驱动波形选择 */
#define	LCD_CR_WFT_Msk	(0x1U << LCD_CR_WFT_Pos)
#define	LCD_CR_WFT_ATYPE	(0x0U << LCD_CR_WFT_Pos)	/* A类波形 */
#define	LCD_CR_WFT_BTYPE	(0x1U << LCD_CR_WFT_Pos)	/* B类波形 */

#define	LCD_CR_LMUX_Pos	1	/* COM口数量选择 */
#define	LCD_CR_LMUX_Msk	(0x3U << LCD_CR_LMUX_Pos)
#define	LCD_CR_LMUX_4COM	(0x0U << LCD_CR_LMUX_Pos)	/* 4COM */
#define	LCD_CR_LMUX_6COM	(0x1U << LCD_CR_LMUX_Pos)	/* 6COM */
#define	LCD_CR_LMUX_8COM	(0x2U << LCD_CR_LMUX_Pos)	/* 8COM */

#define	LCD_CR_EN_Pos	0	/* LCD控制 */
#define	LCD_CR_EN_Msk	(0x1U << LCD_CR_EN_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_TEST_LCCTRL_Pos	7	/* LCD测试控制位，与DISPDATA组合使用 */
#define	LCD_TEST_LCCTRL_Msk	(0x1U << LCD_TEST_LCCTRL_Pos)
#define	LCD_TEST_LCCTRL_LOW	(0x0U << LCD_TEST_LCCTRL_Pos)
#define	LCD_TEST_LCCTRL_HIGH	(0x1U << LCD_TEST_LCCTRL_Pos)

#define	LCD_TEST_TESTEN_Pos	0	/* 测试模式控制 */
#define	LCD_TEST_TESTEN_Msk	(0x1U << LCD_TEST_TESTEN_Pos)
	/* 正常模式 */
	/* 测试模式 */

#define	LCD_FCR_DF_Pos	0	/* 显示频率控制寄存器 */
#define	LCD_FCR_DF_Msk	(0xffU << LCD_FCR_DF_Pos)

#define	LCD_FLKT_TOFF_Pos	8	/* 闪烁显示熄灭时间寄存器 */
#define	LCD_FLKT_TOFF_Msk	(0xffU << LCD_FLKT_TOFF_Pos)

#define	LCD_FLKT_TON_Pos	0	/* 闪烁显示点亮时间寄存器 */
#define	LCD_FLKT_TON_Msk	(0xffU << LCD_FLKT_TON_Pos)

#define	LCD_IER_DONIE_Pos	1	/* 显示点亮中断控制位 */
#define	LCD_IER_DONIE_Msk	(0x1U << LCD_IER_DONIE_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_IER_DOFFIE_Pos	0	/* 显示熄灭中断控制位 */
#define	LCD_IER_DOFFIE_Msk	(0x1U << LCD_IER_DOFFIE_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_ISR_DONIF_Pos	1	/* 显示点亮中断标志 */
#define	LCD_ISR_DONIF_Msk	(0x1U << LCD_ISR_DONIF_Pos)

#define	LCD_ISR_DOFFIF_Pos	0	/* 显示熄灭中断标志 */
#define	LCD_ISR_DOFFIF_Msk	(0x1U << LCD_ISR_DOFFIF_Pos)

#define	LCD_COM_EN_Pos	0	/* LCD COM0~3输出使能控制 */
#define	LCD_COM_EN_Msk	(0xfU << LCD_COM_EN_Pos)

#define	LCD_SEG_EN_Pos	0	/* LCD SEG0~31输出使能控制,COM4~7输出使能控制 */
#define	LCD_SEG_EN_Msk	(0xffffffffU << LCD_SEG_EN_Pos)

#define	LCD_COM_EN_COMEN3_Pos	3	/* LCD COM输出控制 */
#define	LCD_COM_EN_COMEN3_Msk	(0x1U << LCD_COM_EN_COMEN3_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_COM_EN_COMEN2_Pos	2	/* LCD COM输出控制 */
#define	LCD_COM_EN_COMEN2_Msk	(0x1U << LCD_COM_EN_COMEN2_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_COM_EN_COMEN1_Pos	1	/* LCD COM输出控制 */
#define	LCD_COM_EN_COMEN1_Msk	(0x1U << LCD_COM_EN_COMEN1_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_COM_EN_COMEN0_Pos	0	/* LCD COM输出控制 */
#define	LCD_COM_EN_COMEN0_Msk	(0x1U << LCD_COM_EN_COMEN0_Pos)
	/* 关闭 */
	/* 使能 */
    
#define	LCD_SEG_EN0_COMEN7_Pos	31	/* LCD COM输出控制 */
#define	LCD_SEG_EN0_COMEN7_Msk	(0x1U << LCD_SEG_EN0_COMEN7_Pos)
	/* 关闭 */
	/* 使能 */
    
#define	LCD_SEG_EN0_COMEN6_Pos	30	/* LCD COM输出控制 */
#define	LCD_SEG_EN0_COMEN6_Msk	(0x1U << LCD_SEG_EN0_COMEN6_Pos)
	/* 关闭 */
	/* 使能 */
    
#define	LCD_SEG_EN0_COMEN5_Pos	29	/* LCD COM输出控制 */
#define	LCD_SEG_EN0_COMEN5_Msk	(0x1U << LCD_SEG_EN0_COMEN5_Pos)
	/* 关闭 */
	/* 使能 */
    
#define	LCD_SEG_EN0_COMEN4_Pos	28	/* LCD COM输出控制 */
#define	LCD_SEG_EN0_COMEN4_Msk	(0x1U << LCD_SEG_EN0_COMEN4_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_SEG_EN0_SEGEN31_Pos	31	/* LCD SEG输出控制 */
#define	LCD_SEG_EN0_SEGEN31_Msk	(0x1U << LCD_SEG_EN0_SEGEN31_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_SEG_EN0_SEGEN30_Pos	30	/* LCD SEG输出控制 */
#define	LCD_SEG_EN0_SEGEN30_Msk	(0x1U << LCD_SEG_EN0_SEGEN30_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_SEG_EN0_SEGEN29_Pos	29	/* LCD SEG输出控制 */
#define	LCD_SEG_EN0_SEGEN29_Msk	(0x1U << LCD_SEG_EN0_SEGEN29_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_SEG_EN0_SEGEN28_Pos	28	/* LCD SEG输出控制 */
#define	LCD_SEG_EN0_SEGEN28_Msk	(0x1U << LCD_SEG_EN0_SEGEN28_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_SEG_EN0_SEGEN27_Pos	27	/* LCD SEG输出控制 */
#define	LCD_SEG_EN0_SEGEN27_Msk	(0x1U << LCD_SEG_EN0_SEGEN27_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_SEG_EN0_SEGEN26_Pos	26	/* LCD SEG输出控制 */
#define	LCD_SEG_EN0_SEGEN26_Msk	(0x1U << LCD_SEG_EN0_SEGEN26_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_SEG_EN0_SEGEN25_Pos	25	/* LCD SEG输出控制 */
#define	LCD_SEG_EN0_SEGEN25_Msk	(0x1U << LCD_SEG_EN0_SEGEN25_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_SEG_EN0_SEGEN24_Pos	24	/* LCD SEG输出控制 */
#define	LCD_SEG_EN0_SEGEN24_Msk	(0x1U << LCD_SEG_EN0_SEGEN24_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_SEG_EN0_SEGEN23_Pos	23	/* LCD SEG输出控制 */
#define	LCD_SEG_EN0_SEGEN23_Msk	(0x1U << LCD_SEG_EN0_SEGEN23_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_SEG_EN0_SEGEN22_Pos	22	/* LCD SEG输出控制 */
#define	LCD_SEG_EN0_SEGEN22_Msk	(0x1U << LCD_SEG_EN0_SEGEN22_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_SEG_EN0_SEGEN21_Pos	21	/* LCD SEG输出控制 */
#define	LCD_SEG_EN0_SEGEN21_Msk	(0x1U << LCD_SEG_EN0_SEGEN21_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_SEG_EN0_SEGEN20_Pos	20	/* LCD SEG输出控制 */
#define	LCD_SEG_EN0_SEGEN20_Msk	(0x1U << LCD_SEG_EN0_SEGEN20_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_SEG_EN0_SEGEN19_Pos	19	/* LCD SEG输出控制 */
#define	LCD_SEG_EN0_SEGEN19_Msk	(0x1U << LCD_SEG_EN0_SEGEN19_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_SEG_EN0_SEGEN18_Pos	18	/* LCD SEG输出控制 */
#define	LCD_SEG_EN0_SEGEN18_Msk	(0x1U << LCD_SEG_EN0_SEGEN18_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_SEG_EN0_SEGEN17_Pos	17	/* LCD SEG输出控制 */
#define	LCD_SEG_EN0_SEGEN17_Msk	(0x1U << LCD_SEG_EN0_SEGEN17_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_SEG_EN0_SEGEN16_Pos	16	/* LCD SEG输出控制 */
#define	LCD_SEG_EN0_SEGEN16_Msk	(0x1U << LCD_SEG_EN0_SEGEN16_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_SEG_EN0_SEGEN15_Pos	15	/* LCD SEG输出控制 */
#define	LCD_SEG_EN0_SEGEN15_Msk	(0x1U << LCD_SEG_EN0_SEGEN15_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_SEG_EN0_SEGEN14_Pos	14	/* LCD SEG输出控制 */
#define	LCD_SEG_EN0_SEGEN14_Msk	(0x1U << LCD_SEG_EN0_SEGEN14_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_SEG_EN0_SEGEN13_Pos	13	/* LCD SEG输出控制 */
#define	LCD_SEG_EN0_SEGEN13_Msk	(0x1U << LCD_SEG_EN0_SEGEN13_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_SEG_EN0_SEGEN12_Pos	12	/* LCD SEG输出控制 */
#define	LCD_SEG_EN0_SEGEN12_Msk	(0x1U << LCD_SEG_EN0_SEGEN12_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_SEG_EN0_SEGEN11_Pos	11	/* LCD SEG输出控制 */
#define	LCD_SEG_EN0_SEGEN11_Msk	(0x1U << LCD_SEG_EN0_SEGEN11_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_SEG_EN0_SEGEN10_Pos	10	/* LCD SEG输出控制 */
#define	LCD_SEG_EN0_SEGEN10_Msk	(0x1U << LCD_SEG_EN0_SEGEN10_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_SEG_EN0_SEGEN9_Pos	9	/* LCD SEG输出控制 */
#define	LCD_SEG_EN0_SEGEN9_Msk	(0x1U << LCD_SEG_EN0_SEGEN9_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_SEG_EN0_SEGEN8_Pos	8	/* LCD SEG输出控制 */
#define	LCD_SEG_EN0_SEGEN8_Msk	(0x1U << LCD_SEG_EN0_SEGEN8_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_SEG_EN0_SEGEN7_Pos	7	/* LCD SEG输出控制 */
#define	LCD_SEG_EN0_SEGEN7_Msk	(0x1U << LCD_SEG_EN0_SEGEN7_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_SEG_EN0_SEGEN6_Pos	6	/* LCD SEG输出控制 */
#define	LCD_SEG_EN0_SEGEN6_Msk	(0x1U << LCD_SEG_EN0_SEGEN6_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_SEG_EN0_SEGEN5_Pos	5	/* LCD SEG输出控制 */
#define	LCD_SEG_EN0_SEGEN5_Msk	(0x1U << LCD_SEG_EN0_SEGEN5_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_SEG_EN0_SEGEN4_Pos	4	/* LCD SEG输出控制 */
#define	LCD_SEG_EN0_SEGEN4_Msk	(0x1U << LCD_SEG_EN0_SEGEN4_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_SEG_EN0_SEGEN3_Pos	3	/* LCD SEG输出控制 */
#define	LCD_SEG_EN0_SEGEN3_Msk	(0x1U << LCD_SEG_EN0_SEGEN3_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_SEG_EN0_SEGEN2_Pos	2	/* LCD SEG输出控制 */
#define	LCD_SEG_EN0_SEGEN2_Msk	(0x1U << LCD_SEG_EN0_SEGEN2_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_SEG_EN0_SEGEN1_Pos	1	/* LCD SEG输出控制 */
#define	LCD_SEG_EN0_SEGEN1_Msk	(0x1U << LCD_SEG_EN0_SEGEN1_Pos)
	/* 关闭 */
	/* 使能 */

#define	LCD_SEG_EN0_SEGEN0_Pos	0	/* LCD SEG输出控制 */
#define	LCD_SEG_EN0_SEGEN0_Msk	(0x1U << LCD_SEG_EN0_SEGEN0_Pos)
	/* 关闭 */
	/* 使能 */
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void LCD_Deinit(void);

/* 电容驱动频率选择 相关函数 */
extern void LCD_CR_SCFSEL_Set(uint32_t SetValue);
extern uint32_t LCD_CR_SCFSEL_Get(void);

/* 片外电容驱动方式控制 相关函数 */
extern void LCD_CR_SC_CTRL_Set(uint32_t SetValue);
extern uint32_t LCD_CR_SC_CTRL_Get(void);

/* 偏置电路输入电流源大小控制 相关函数 */
extern void LCD_CR_IC_CTRL_Set(uint32_t SetValue);
extern uint32_t LCD_CR_IC_CTRL_Get(void);

/* 驱动模式选择 相关函数 */
extern void LCD_CR_ENMODE_Set(uint32_t SetValue);
extern uint32_t LCD_CR_ENMODE_Get(void);

/* 显示闪烁控制 相关函数 */
extern void LCD_CR_FLICK_Setable(FunState NewState);
extern FunState LCD_CR_FLICK_Getable(void);

/* 显示灰度设置 相关函数 */
extern void LCD_CR_Write(uint32_t SetValue);
extern uint32_t LCD_CR_Read(void);

/* 偏置类型控制 相关函数 */
extern void LCD_CR_BIASMD_Set(uint32_t SetValue);
extern uint32_t LCD_CR_BIASMD_Get(void);

/* 防极化 相关函数 */
extern void LCD_CR_ANTIPOLAR_Setable(FunState NewState);
extern FunState LCD_CR_ANTIPOLAR_Getable(void);

/* 驱动波形选择 相关函数 */
extern void LCD_CR_WFT_Set(uint32_t SetValue);
extern uint32_t LCD_CR_WFT_Get(void);

/* COM口数量选择 相关函数 */
extern void LCD_CR_LMUX_Set(uint32_t SetValue);
extern uint32_t LCD_CR_LMUX_Get(void);

/* LCD控制 相关函数 */
extern void LCD_CR_EN_Setable(FunState NewState);
extern FunState LCD_CR_EN_Getable(void);

/* LCD测试控制位，与DISPDATA组合使用 相关函数 */
extern void LCD_TEST_LCCTRL_Set(uint32_t SetValue);
extern uint32_t LCD_TEST_LCCTRL_Get(void);

/* 测试模式控制 相关函数 */
extern void LCD_TEST_TESTEN_Setable(FunState NewState);
extern FunState LCD_TEST_TESTEN_Getable(void);

/* 显示频率控制寄存器 相关函数 */
extern void LCD_FCR_Write(uint32_t SetValue);
extern uint32_t LCD_FCR_Read(void);

/* 闪烁显示熄灭时间寄存器 相关函数 */
extern void LCD_FLKT_TOFF_Write(uint32_t SetValue);
extern uint32_t LCD_FLKT_TOFF_Read(void);

/* 闪烁显示点亮时间寄存器 相关函数 */
extern void LCD_FLKT_TON_Write(uint32_t SetValue);
extern uint32_t LCD_FLKT_TON_Read(void);

/* 显示点亮中断控制位 相关函数 */
extern void LCD_IER_DONIE_Setable(FunState NewState);
extern FunState LCD_IER_DONIE_Getable(void);

/* 显示熄灭中断控制位 相关函数 */
extern void LCD_IER_DOFFIE_Setable(FunState NewState);
extern FunState LCD_IER_DOFFIE_Getable(void);

/* 显示点亮中断标志 相关函数 */
extern void LCD_ISR_DONIF_Clr(void);
extern FlagStatus LCD_ISR_DONIF_Chk(void);

/* 显示熄灭中断标志 相关函数 */
extern void LCD_ISR_DOFFIF_Clr(void);
extern FlagStatus LCD_ISR_DOFFIF_Chk(void);

/* LCD COM输出控制 相关函数 */
void LCD_COM_EN_Write(uint32_t value);
uint32_t LCD_COM_EN_Read(void);

/* LCD SEG输出控制 相关函数 */
void LCD_SEG_EN_Write(uint32_t value);
uint32_t LCD_SEG_EN_Read(void);

//Announce_End

/*DISPDATAx显示数据寄存器刷新*/
extern void LCD_DISPDATAx_Refresh(uint32_t* DispBuf);

/*LCD显示功能配置*/
extern void LCD_Init(LCD_InitTypeDef* para);
                
#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_LCD_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
