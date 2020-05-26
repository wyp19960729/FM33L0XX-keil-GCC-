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
	uint32_t			LMUX;		/*!<COM����ѡ��*/	
	uint32_t			ENMODE;		/*!<����ģʽѡ��*/
	uint32_t			WFT;		/*!<��������ѡ��*/
	uint32_t			DF;			/*!<��ʾƵ�ʿ��ƼĴ���*/
	uint32_t			BIASMD;		/*!<ƫ�����Ϳ���*/
	uint32_t			SCFSEL;		/*!<SCƵ��ѡ��*/  //����Ƭ�����ģʽ����Ч
	uint32_t			SC_CTRL;	/*!<Ƭ���������ģʽ�£�������ʽ����*/
	uint32_t			IC_CTRL;	/*!<Ƭ�ڵ���ģʽ�£�����������С*/
	uint32_t			LCDBIAS;	/*!<��ʾ�Ҷ�����*/
	FunState			ANTIPOLAR;	/*!<������ʹ�ܿ���*/
	
	uint32_t			LCCTRL;		/*!<����Ϊ0*/
	FunState			TESTEN;		/*!<���ֹر�*/
	
	FunState			FLICK;		/*!<��ʾ��˸ʹ��λ*/
	uint32_t			TON;		/*!<��˸��ʾʱ�ĵ���ʱ�䣽TON��0.25��*/
	uint32_t			TOFF;		/*!<��˸��ʾʱ��Ϩ��ʱ�䣽TOFF��0.25��*/
	FunState			DONIE;		/*!<��ʾ�����ж�ʹ�ܿ���*/
	FunState			DOFFIE;		/*!<��ʾϨ���ж�ʹ�ܿ���*/
	
	FunState			LCDEN;		/*!<LCD��ʾʹ�ܿ���*/
}LCD_InitTypeDef;
     
#define	LCD_CR_SCFSEL_Pos	20	/* ��������Ƶ��ѡ�� */
#define	LCD_CR_SCFSEL_Msk	(0x7U << LCD_CR_SCFSEL_Pos)
#define	LCD_CR_SCFSEL_X1	(0x0U << LCD_CR_SCFSEL_Pos)	/* ֡Ƶ*COM�� */
#define	LCD_CR_SCFSEL_X8	(0x1U << LCD_CR_SCFSEL_Pos)	/* LSCLK/8 */
#define	LCD_CR_SCFSEL_X16	(0x2U << LCD_CR_SCFSEL_Pos)	/* LSCLK/16 */
#define	LCD_CR_SCFSEL_X32	(0x3U << LCD_CR_SCFSEL_Pos)	/* LSCLK/32 */
#define	LCD_CR_SCFSEL_X64	(0x4U << LCD_CR_SCFSEL_Pos)	/* LSCLK/64 */
#define	LCD_CR_SCFSEL_X128	(0x5U << LCD_CR_SCFSEL_Pos)	/* LSCLK/128 */
#define	LCD_CR_SCFSEL_X256	(0x6U << LCD_CR_SCFSEL_Pos)	/* LSCLK/256 */
#define	LCD_CR_SCFSEL_X512	(0x7U << LCD_CR_SCFSEL_Pos)	/* LSCLK/512 */

#define	LCD_CR_SC_CTRL_Pos	18	/* Ƭ�����������ʽ���� */
#define	LCD_CR_SC_CTRL_Msk	(0x3U << LCD_CR_SC_CTRL_Pos)
#define	LCD_CR_SC_CTRL_ONE	(0x0U << LCD_CR_SC_CTRL_Pos)	/* �������� */
#define	LCD_CR_SC_CTRL_TWO	(0x1U << LCD_CR_SC_CTRL_Pos)	/* ������������ */
#define	LCD_CR_SC_CTRL_FOUR	(0x2U << LCD_CR_SC_CTRL_Pos)	/* ���������Ĵ� */
#define	LCD_CR_SC_CTRL_CONTINUE	(0x3U << LCD_CR_SC_CTRL_Pos)	/* ������� */

#define	LCD_CR_IC_CTRL_Pos	16	/* ƫ�õ�·�������Դ��С���� */
#define	LCD_CR_IC_CTRL_Msk	(0x3U << LCD_CR_IC_CTRL_Pos)
#define	LCD_CR_IC_CTRL_L3	(0x0U << LCD_CR_IC_CTRL_Pos)	/* ������� */
#define	LCD_CR_IC_CTRL_L2	(0x1U << LCD_CR_IC_CTRL_Pos)	/* �����δ� */
#define	LCD_CR_IC_CTRL_L1	(0x2U << LCD_CR_IC_CTRL_Pos)	/* ������С */
#define	LCD_CR_IC_CTRL_L0	(0x3U << LCD_CR_IC_CTRL_Pos)	/* ������С */

#define	LCD_CR_ENMODE_Pos	15	/* ����ģʽѡ�� */
#define	LCD_CR_ENMODE_Msk	(0x1U << LCD_CR_ENMODE_Pos)
#define	LCD_CR_ENMODE_EXTERNALCAP	(0x0U << LCD_CR_ENMODE_Pos)	/* Ƭ��������� */
#define	LCD_CR_ENMODE_INNERRESISTER	(0x1U << LCD_CR_ENMODE_Pos)	/* Ƭ�ڵ������� */

#define	LCD_CR_FLICK_Pos	14	/* ��ʾ��˸���� */
#define	LCD_CR_FLICK_Msk	(0x1U << LCD_CR_FLICK_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_CR_BIAS_Pos	8	/* ��ʾ�Ҷ����� */
#define	LCD_CR_BIAS_Msk	(0xfU << LCD_CR_BIAS_Pos)

#define	LCD_CR_BIASMD_Pos	5	/* ƫ�����Ϳ��� */
#define	LCD_CR_BIASMD_Msk	(0x1U << LCD_CR_BIASMD_Pos)
#define	LCD_CR_BIASMD_4BIAS	(0x0U << LCD_CR_BIASMD_Pos)	/* 1/4 Bias */
#define	LCD_CR_BIASMD_3BIAS	(0x1U << LCD_CR_BIASMD_Pos)	/* 1/3 Bias */

#define	LCD_CR_ANTIPOLAR_Pos	4	/* ������ */
#define	LCD_CR_ANTIPOLAR_Msk	(0x1U << LCD_CR_ANTIPOLAR_Pos)
	/* COM��SEG��LCD�ر�����¸��� */
	/* COM��SEG��LCD�ر�����½ӵ� */

#define	LCD_CR_WFT_Pos	3	/* ��������ѡ�� */
#define	LCD_CR_WFT_Msk	(0x1U << LCD_CR_WFT_Pos)
#define	LCD_CR_WFT_ATYPE	(0x0U << LCD_CR_WFT_Pos)	/* A�ನ�� */
#define	LCD_CR_WFT_BTYPE	(0x1U << LCD_CR_WFT_Pos)	/* B�ನ�� */

#define	LCD_CR_LMUX_Pos	1	/* COM������ѡ�� */
#define	LCD_CR_LMUX_Msk	(0x3U << LCD_CR_LMUX_Pos)
#define	LCD_CR_LMUX_4COM	(0x0U << LCD_CR_LMUX_Pos)	/* 4COM */
#define	LCD_CR_LMUX_6COM	(0x1U << LCD_CR_LMUX_Pos)	/* 6COM */
#define	LCD_CR_LMUX_8COM	(0x2U << LCD_CR_LMUX_Pos)	/* 8COM */

#define	LCD_CR_EN_Pos	0	/* LCD���� */
#define	LCD_CR_EN_Msk	(0x1U << LCD_CR_EN_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_TEST_LCCTRL_Pos	7	/* LCD���Կ���λ����DISPDATA���ʹ�� */
#define	LCD_TEST_LCCTRL_Msk	(0x1U << LCD_TEST_LCCTRL_Pos)
#define	LCD_TEST_LCCTRL_LOW	(0x0U << LCD_TEST_LCCTRL_Pos)
#define	LCD_TEST_LCCTRL_HIGH	(0x1U << LCD_TEST_LCCTRL_Pos)

#define	LCD_TEST_TESTEN_Pos	0	/* ����ģʽ���� */
#define	LCD_TEST_TESTEN_Msk	(0x1U << LCD_TEST_TESTEN_Pos)
	/* ����ģʽ */
	/* ����ģʽ */

#define	LCD_FCR_DF_Pos	0	/* ��ʾƵ�ʿ��ƼĴ��� */
#define	LCD_FCR_DF_Msk	(0xffU << LCD_FCR_DF_Pos)

#define	LCD_FLKT_TOFF_Pos	8	/* ��˸��ʾϨ��ʱ��Ĵ��� */
#define	LCD_FLKT_TOFF_Msk	(0xffU << LCD_FLKT_TOFF_Pos)

#define	LCD_FLKT_TON_Pos	0	/* ��˸��ʾ����ʱ��Ĵ��� */
#define	LCD_FLKT_TON_Msk	(0xffU << LCD_FLKT_TON_Pos)

#define	LCD_IER_DONIE_Pos	1	/* ��ʾ�����жϿ���λ */
#define	LCD_IER_DONIE_Msk	(0x1U << LCD_IER_DONIE_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_IER_DOFFIE_Pos	0	/* ��ʾϨ���жϿ���λ */
#define	LCD_IER_DOFFIE_Msk	(0x1U << LCD_IER_DOFFIE_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_ISR_DONIF_Pos	1	/* ��ʾ�����жϱ�־ */
#define	LCD_ISR_DONIF_Msk	(0x1U << LCD_ISR_DONIF_Pos)

#define	LCD_ISR_DOFFIF_Pos	0	/* ��ʾϨ���жϱ�־ */
#define	LCD_ISR_DOFFIF_Msk	(0x1U << LCD_ISR_DOFFIF_Pos)

#define	LCD_COM_EN_Pos	0	/* LCD COM0~3���ʹ�ܿ��� */
#define	LCD_COM_EN_Msk	(0xfU << LCD_COM_EN_Pos)

#define	LCD_SEG_EN_Pos	0	/* LCD SEG0~31���ʹ�ܿ���,COM4~7���ʹ�ܿ��� */
#define	LCD_SEG_EN_Msk	(0xffffffffU << LCD_SEG_EN_Pos)

#define	LCD_COM_EN_COMEN3_Pos	3	/* LCD COM������� */
#define	LCD_COM_EN_COMEN3_Msk	(0x1U << LCD_COM_EN_COMEN3_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_COM_EN_COMEN2_Pos	2	/* LCD COM������� */
#define	LCD_COM_EN_COMEN2_Msk	(0x1U << LCD_COM_EN_COMEN2_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_COM_EN_COMEN1_Pos	1	/* LCD COM������� */
#define	LCD_COM_EN_COMEN1_Msk	(0x1U << LCD_COM_EN_COMEN1_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_COM_EN_COMEN0_Pos	0	/* LCD COM������� */
#define	LCD_COM_EN_COMEN0_Msk	(0x1U << LCD_COM_EN_COMEN0_Pos)
	/* �ر� */
	/* ʹ�� */
    
#define	LCD_SEG_EN0_COMEN7_Pos	31	/* LCD COM������� */
#define	LCD_SEG_EN0_COMEN7_Msk	(0x1U << LCD_SEG_EN0_COMEN7_Pos)
	/* �ر� */
	/* ʹ�� */
    
#define	LCD_SEG_EN0_COMEN6_Pos	30	/* LCD COM������� */
#define	LCD_SEG_EN0_COMEN6_Msk	(0x1U << LCD_SEG_EN0_COMEN6_Pos)
	/* �ر� */
	/* ʹ�� */
    
#define	LCD_SEG_EN0_COMEN5_Pos	29	/* LCD COM������� */
#define	LCD_SEG_EN0_COMEN5_Msk	(0x1U << LCD_SEG_EN0_COMEN5_Pos)
	/* �ر� */
	/* ʹ�� */
    
#define	LCD_SEG_EN0_COMEN4_Pos	28	/* LCD COM������� */
#define	LCD_SEG_EN0_COMEN4_Msk	(0x1U << LCD_SEG_EN0_COMEN4_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_SEG_EN0_SEGEN31_Pos	31	/* LCD SEG������� */
#define	LCD_SEG_EN0_SEGEN31_Msk	(0x1U << LCD_SEG_EN0_SEGEN31_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_SEG_EN0_SEGEN30_Pos	30	/* LCD SEG������� */
#define	LCD_SEG_EN0_SEGEN30_Msk	(0x1U << LCD_SEG_EN0_SEGEN30_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_SEG_EN0_SEGEN29_Pos	29	/* LCD SEG������� */
#define	LCD_SEG_EN0_SEGEN29_Msk	(0x1U << LCD_SEG_EN0_SEGEN29_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_SEG_EN0_SEGEN28_Pos	28	/* LCD SEG������� */
#define	LCD_SEG_EN0_SEGEN28_Msk	(0x1U << LCD_SEG_EN0_SEGEN28_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_SEG_EN0_SEGEN27_Pos	27	/* LCD SEG������� */
#define	LCD_SEG_EN0_SEGEN27_Msk	(0x1U << LCD_SEG_EN0_SEGEN27_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_SEG_EN0_SEGEN26_Pos	26	/* LCD SEG������� */
#define	LCD_SEG_EN0_SEGEN26_Msk	(0x1U << LCD_SEG_EN0_SEGEN26_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_SEG_EN0_SEGEN25_Pos	25	/* LCD SEG������� */
#define	LCD_SEG_EN0_SEGEN25_Msk	(0x1U << LCD_SEG_EN0_SEGEN25_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_SEG_EN0_SEGEN24_Pos	24	/* LCD SEG������� */
#define	LCD_SEG_EN0_SEGEN24_Msk	(0x1U << LCD_SEG_EN0_SEGEN24_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_SEG_EN0_SEGEN23_Pos	23	/* LCD SEG������� */
#define	LCD_SEG_EN0_SEGEN23_Msk	(0x1U << LCD_SEG_EN0_SEGEN23_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_SEG_EN0_SEGEN22_Pos	22	/* LCD SEG������� */
#define	LCD_SEG_EN0_SEGEN22_Msk	(0x1U << LCD_SEG_EN0_SEGEN22_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_SEG_EN0_SEGEN21_Pos	21	/* LCD SEG������� */
#define	LCD_SEG_EN0_SEGEN21_Msk	(0x1U << LCD_SEG_EN0_SEGEN21_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_SEG_EN0_SEGEN20_Pos	20	/* LCD SEG������� */
#define	LCD_SEG_EN0_SEGEN20_Msk	(0x1U << LCD_SEG_EN0_SEGEN20_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_SEG_EN0_SEGEN19_Pos	19	/* LCD SEG������� */
#define	LCD_SEG_EN0_SEGEN19_Msk	(0x1U << LCD_SEG_EN0_SEGEN19_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_SEG_EN0_SEGEN18_Pos	18	/* LCD SEG������� */
#define	LCD_SEG_EN0_SEGEN18_Msk	(0x1U << LCD_SEG_EN0_SEGEN18_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_SEG_EN0_SEGEN17_Pos	17	/* LCD SEG������� */
#define	LCD_SEG_EN0_SEGEN17_Msk	(0x1U << LCD_SEG_EN0_SEGEN17_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_SEG_EN0_SEGEN16_Pos	16	/* LCD SEG������� */
#define	LCD_SEG_EN0_SEGEN16_Msk	(0x1U << LCD_SEG_EN0_SEGEN16_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_SEG_EN0_SEGEN15_Pos	15	/* LCD SEG������� */
#define	LCD_SEG_EN0_SEGEN15_Msk	(0x1U << LCD_SEG_EN0_SEGEN15_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_SEG_EN0_SEGEN14_Pos	14	/* LCD SEG������� */
#define	LCD_SEG_EN0_SEGEN14_Msk	(0x1U << LCD_SEG_EN0_SEGEN14_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_SEG_EN0_SEGEN13_Pos	13	/* LCD SEG������� */
#define	LCD_SEG_EN0_SEGEN13_Msk	(0x1U << LCD_SEG_EN0_SEGEN13_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_SEG_EN0_SEGEN12_Pos	12	/* LCD SEG������� */
#define	LCD_SEG_EN0_SEGEN12_Msk	(0x1U << LCD_SEG_EN0_SEGEN12_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_SEG_EN0_SEGEN11_Pos	11	/* LCD SEG������� */
#define	LCD_SEG_EN0_SEGEN11_Msk	(0x1U << LCD_SEG_EN0_SEGEN11_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_SEG_EN0_SEGEN10_Pos	10	/* LCD SEG������� */
#define	LCD_SEG_EN0_SEGEN10_Msk	(0x1U << LCD_SEG_EN0_SEGEN10_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_SEG_EN0_SEGEN9_Pos	9	/* LCD SEG������� */
#define	LCD_SEG_EN0_SEGEN9_Msk	(0x1U << LCD_SEG_EN0_SEGEN9_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_SEG_EN0_SEGEN8_Pos	8	/* LCD SEG������� */
#define	LCD_SEG_EN0_SEGEN8_Msk	(0x1U << LCD_SEG_EN0_SEGEN8_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_SEG_EN0_SEGEN7_Pos	7	/* LCD SEG������� */
#define	LCD_SEG_EN0_SEGEN7_Msk	(0x1U << LCD_SEG_EN0_SEGEN7_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_SEG_EN0_SEGEN6_Pos	6	/* LCD SEG������� */
#define	LCD_SEG_EN0_SEGEN6_Msk	(0x1U << LCD_SEG_EN0_SEGEN6_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_SEG_EN0_SEGEN5_Pos	5	/* LCD SEG������� */
#define	LCD_SEG_EN0_SEGEN5_Msk	(0x1U << LCD_SEG_EN0_SEGEN5_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_SEG_EN0_SEGEN4_Pos	4	/* LCD SEG������� */
#define	LCD_SEG_EN0_SEGEN4_Msk	(0x1U << LCD_SEG_EN0_SEGEN4_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_SEG_EN0_SEGEN3_Pos	3	/* LCD SEG������� */
#define	LCD_SEG_EN0_SEGEN3_Msk	(0x1U << LCD_SEG_EN0_SEGEN3_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_SEG_EN0_SEGEN2_Pos	2	/* LCD SEG������� */
#define	LCD_SEG_EN0_SEGEN2_Msk	(0x1U << LCD_SEG_EN0_SEGEN2_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_SEG_EN0_SEGEN1_Pos	1	/* LCD SEG������� */
#define	LCD_SEG_EN0_SEGEN1_Msk	(0x1U << LCD_SEG_EN0_SEGEN1_Pos)
	/* �ر� */
	/* ʹ�� */

#define	LCD_SEG_EN0_SEGEN0_Pos	0	/* LCD SEG������� */
#define	LCD_SEG_EN0_SEGEN0_Msk	(0x1U << LCD_SEG_EN0_SEGEN0_Pos)
	/* �ر� */
	/* ʹ�� */
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void LCD_Deinit(void);

/* ��������Ƶ��ѡ�� ��غ��� */
extern void LCD_CR_SCFSEL_Set(uint32_t SetValue);
extern uint32_t LCD_CR_SCFSEL_Get(void);

/* Ƭ�����������ʽ���� ��غ��� */
extern void LCD_CR_SC_CTRL_Set(uint32_t SetValue);
extern uint32_t LCD_CR_SC_CTRL_Get(void);

/* ƫ�õ�·�������Դ��С���� ��غ��� */
extern void LCD_CR_IC_CTRL_Set(uint32_t SetValue);
extern uint32_t LCD_CR_IC_CTRL_Get(void);

/* ����ģʽѡ�� ��غ��� */
extern void LCD_CR_ENMODE_Set(uint32_t SetValue);
extern uint32_t LCD_CR_ENMODE_Get(void);

/* ��ʾ��˸���� ��غ��� */
extern void LCD_CR_FLICK_Setable(FunState NewState);
extern FunState LCD_CR_FLICK_Getable(void);

/* ��ʾ�Ҷ����� ��غ��� */
extern void LCD_CR_Write(uint32_t SetValue);
extern uint32_t LCD_CR_Read(void);

/* ƫ�����Ϳ��� ��غ��� */
extern void LCD_CR_BIASMD_Set(uint32_t SetValue);
extern uint32_t LCD_CR_BIASMD_Get(void);

/* ������ ��غ��� */
extern void LCD_CR_ANTIPOLAR_Setable(FunState NewState);
extern FunState LCD_CR_ANTIPOLAR_Getable(void);

/* ��������ѡ�� ��غ��� */
extern void LCD_CR_WFT_Set(uint32_t SetValue);
extern uint32_t LCD_CR_WFT_Get(void);

/* COM������ѡ�� ��غ��� */
extern void LCD_CR_LMUX_Set(uint32_t SetValue);
extern uint32_t LCD_CR_LMUX_Get(void);

/* LCD���� ��غ��� */
extern void LCD_CR_EN_Setable(FunState NewState);
extern FunState LCD_CR_EN_Getable(void);

/* LCD���Կ���λ����DISPDATA���ʹ�� ��غ��� */
extern void LCD_TEST_LCCTRL_Set(uint32_t SetValue);
extern uint32_t LCD_TEST_LCCTRL_Get(void);

/* ����ģʽ���� ��غ��� */
extern void LCD_TEST_TESTEN_Setable(FunState NewState);
extern FunState LCD_TEST_TESTEN_Getable(void);

/* ��ʾƵ�ʿ��ƼĴ��� ��غ��� */
extern void LCD_FCR_Write(uint32_t SetValue);
extern uint32_t LCD_FCR_Read(void);

/* ��˸��ʾϨ��ʱ��Ĵ��� ��غ��� */
extern void LCD_FLKT_TOFF_Write(uint32_t SetValue);
extern uint32_t LCD_FLKT_TOFF_Read(void);

/* ��˸��ʾ����ʱ��Ĵ��� ��غ��� */
extern void LCD_FLKT_TON_Write(uint32_t SetValue);
extern uint32_t LCD_FLKT_TON_Read(void);

/* ��ʾ�����жϿ���λ ��غ��� */
extern void LCD_IER_DONIE_Setable(FunState NewState);
extern FunState LCD_IER_DONIE_Getable(void);

/* ��ʾϨ���жϿ���λ ��غ��� */
extern void LCD_IER_DOFFIE_Setable(FunState NewState);
extern FunState LCD_IER_DOFFIE_Getable(void);

/* ��ʾ�����жϱ�־ ��غ��� */
extern void LCD_ISR_DONIF_Clr(void);
extern FlagStatus LCD_ISR_DONIF_Chk(void);

/* ��ʾϨ���жϱ�־ ��غ��� */
extern void LCD_ISR_DOFFIF_Clr(void);
extern FlagStatus LCD_ISR_DOFFIF_Chk(void);

/* LCD COM������� ��غ��� */
void LCD_COM_EN_Write(uint32_t value);
uint32_t LCD_COM_EN_Read(void);

/* LCD SEG������� ��غ��� */
void LCD_SEG_EN_Write(uint32_t value);
uint32_t LCD_SEG_EN_Read(void);

//Announce_End

/*DISPDATAx��ʾ���ݼĴ���ˢ��*/
extern void LCD_DISPDATAx_Refresh(uint32_t* DispBuf);

/*LCD��ʾ��������*/
extern void LCD_Init(LCD_InitTypeDef* para);
                
#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_LCD_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
