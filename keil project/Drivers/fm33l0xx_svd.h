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
	uint32_t	SVDMOD;		/*!<SVD����ģʽѡ��  */
	uint32_t	SVDITVL;	/*!<SVD��Ъʹ�ܼ��  */
	uint32_t	SVDLVL;		/*!<SVD������ֵ����  */
	FunState	DFEN;		/*!<SVD�����˲���SVDMODE=1ʱ������1��  */
	FunState	PFIE;		/*!<SVD��Դ�����ж�  */
	FunState	PRIE;		/*!<SVD��Դ�ָ��ж�  */
	FunState	SVDEN;		/*!<SVDʹ��  */
	
}ANAC_SVD_InitTypeDef;

#define	SVD_CFGR_LVL_Pos	4	/* SVD������ֵ����(SVD threshold level)
 */
#define	SVD_CFGR_LVL_Msk	(0xfU << SVD_CFGR_LVL_Pos)
#define	SVD_CFGR_LVL_1P800V	(0x0U << SVD_CFGR_LVL_Pos)	/* 0000_1.913V_2.019V��SVDLVL_�½���ֵ_������ֵ�� */
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
#define	SVD_CFGR_LVL_SVS	(0xfU << SVD_CFGR_LVL_Pos)	/* 1111_SVS_SVS  �̶����0.8V  */

#define	SVD_CFGR_DFEN_Pos	3	/* �����˲�ʹ�ܣ�SVDMODE=1ʱ������1��(Digital Filter Enable) */
#define	SVD_CFGR_DFEN_Msk	(0x1U << SVD_CFGR_DFEN_Pos)
	/* 0���ر�SVD����������˲� */
	/* 1������SVD����������˲� */

#define	SVD_CFGR_MOD_Pos	2	/* SVD����ģʽѡ������ģʽ��Ҫ��λSVDEN�Ż�����SVD */
#define	SVD_CFGR_MOD_Msk	(0x1U << SVD_CFGR_MOD_Pos)
#define	SVD_CFGR_MOD_ALWAYSON	(0x0U << SVD_CFGR_MOD_Pos)	/* 0����ʹ��ģʽ */
#define	SVD_CFGR_MOD_INTERVAL	(0x1U << SVD_CFGR_MOD_Pos)	/* 1����Ъʹ��ģʽ */

#define	SVD_CFGR_ITVL_Pos	0	/* SVD��Ъʹ�ܼ��(SVD Interval) */
#define	SVD_CFGR_ITVL_Msk	(0x3U << SVD_CFGR_ITVL_Pos)
#define	SVD_CFGR_ITVL_62P5MS	(0x0U << SVD_CFGR_ITVL_Pos)	/* 00��62.5ms */
#define	SVD_CFGR_ITVL_256MS	(0x1U << SVD_CFGR_ITVL_Pos)	/* 01��256s */
#define	SVD_CFGR_ITVL_1S	(0x2U << SVD_CFGR_ITVL_Pos)	/* 10��1s */
#define	SVD_CFGR_ITVL_4S	(0x3U << SVD_CFGR_ITVL_Pos)	/* 11��4s */

#define	SVD_CR_TE_Pos	8	/* SVD����ʹ�ܣ�����д1 (SVD test enable) */
#define	SVD_CR_TE_Msk	(0x1U << SVD_CR_TE_Pos)
	/* 0:SVD����ʹ�� */
	/* 1��SVD���Խ�ֹ */

#define	SVD_CR_SVSEN_Pos	1	/* SVS�ⲿ��Դ���ͨ�������ź�(SVS external monitor channel enable) */
#define	SVD_CR_SVSEN_Msk	(0x1U << SVD_CR_SVSEN_Pos)
	/* 0��SVSͨ���ر� */
	/* 1��SVSͨ��ʹ�� */

#define	SVD_CR_EN_Pos	0	/* SVDʹ�� (SVD enable) */
#define	SVD_CR_EN_Msk	(0x1U << SVD_CR_EN_Pos)
	/* 0���ر�SVD */
	/* 1������SVD */

#define	SVD_IER_PFIE_Pos	1	/* ��Դ�����ж�ʹ��(Power Fall interrupt enable) */
#define	SVD_IER_PFIE_Msk	(0x1U << SVD_IER_PFIE_Pos)
	/* 0��SVD��Դ�����ж�ʹ�� */
	/* 1��SVD��Դ�����жϽ�ֹ */

#define	SVD_IER_PRIE_Pos	0	/* ��Դ�ָ��ж�ʹ��(Power Rise interrupt enable) */
#define	SVD_IER_PRIE_Msk	(0x1U << SVD_IER_PRIE_Pos)
	/* 0��SVD��Դ�ָ��ж�ʹ�� */
	/* 1��SVD��Դ�ָ��жϽ�ֹ */

#define	SVD_ISR_SVDO_Pos	8	/* SVD��Դ������ (SVD output) */
#define	SVD_ISR_SVDO_Msk	(0x1U << SVD_ISR_SVDO_Pos)

#define	SVD_ISR_SVDR_Pos	7	/* SVD��������źţ����ֵ�·�����SVD״̬ */
#define	SVD_ISR_SVDR_Msk	(0x1U << SVD_ISR_SVDR_Pos)

#define	SVD_ISR_PFF_Pos	1	/* ��Դ�����жϱ�־ */
#define	SVD_ISR_PFF_Msk	(0x1U << SVD_ISR_PFF_Pos)

#define	SVD_ISR_PRF_Pos	0	/* ��Դ�ָ��жϱ�־ */
#define	SVD_ISR_PRF_Msk	(0x1U << SVD_ISR_PRF_Pos)

#define	SVD_VSR_V0P85EN_Pos	2	/* 0.85V��׼����ʹ���ź� (0.85V reference enable) */
#define	SVD_VSR_V0P85EN_Msk	(0x1U << SVD_VSR_V0P85EN_Pos)
	/* 0���ر�0.85V��׼���� */
	/* 1��ʹ��0.85V��׼���� */

#define	SVD_VSR_V0P8EN_Pos	1	/* 0.8V��׼����ʹ���ź� (0.8V reference enable) */
#define	SVD_VSR_V0P8EN_Msk	(0x1U << SVD_VSR_V0P8EN_Pos)
	/* 0���ر�0.8V��׼���� */
	/* 1��ʹ��0.8V��׼���� */

#define	SVD_VSR_V0P75EN_Pos	0	/* 0.75V��׼����ʹ���ź� (0.75V reference enable) */
#define	SVD_VSR_V0P75EN_Msk	(0x1U << SVD_VSR_V0P75EN_Pos)
	/* 0���ر�0.75V��׼���� */
	/* 1��ʹ��0.75V��׼���� */
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void SVD_Deinit(void);

/* SVD������ֵ����(SVD threshold level)
 ��غ��� */
extern void SVD_CFGR_LVL_Set(uint32_t SetValue);
extern uint32_t SVD_CFGR_LVL_Get(void);

/* �����˲�ʹ�ܣ�SVDMODE=1ʱ������1��(Digital Filter Enable) ��غ��� */
extern void SVD_CFGR_DFEN_Setable(FunState NewState);
extern FunState SVD_CFGR_DFEN_Getable(void);

/* SVD����ģʽѡ������ģʽ��Ҫ��λSVDEN�Ż�����SVD ��غ��� */
extern void SVD_CFGR_MOD_Set(uint32_t SetValue);
extern uint32_t SVD_CFGR_MOD_Get(void);

/* SVD��Ъʹ�ܼ��(SVD Interval) ��غ��� */
extern void SVD_CFGR_ITVL_Set(uint32_t SetValue);
extern uint32_t SVD_CFGR_ITVL_Get(void);

/* SVD����ʹ�ܣ�����д1 (SVD test enable) ��غ��� */
extern void SVD_CR_TE_Setable(FunState NewState);
extern FunState SVD_CR_TE_Getable(void);

/* SVS�ⲿ��Դ���ͨ�������ź�(SVS external monitor channel enable) ��غ��� */
extern void SVD_CR_SVSEN_Setable(FunState NewState);
extern FunState SVD_CR_SVSEN_Getable(void);

/* SVDʹ�� (SVD enable) ��غ��� */
extern void SVD_CR_EN_Setable(FunState NewState);
extern FunState SVD_CR_EN_Getable(void);

/* ��Դ�����ж�ʹ��(Power Fall interrupt enable) ��غ��� */
extern void SVD_IER_PFIE_Setable(FunState NewState);
extern FunState SVD_IER_PFIE_Getable(void);

/* ��Դ�ָ��ж�ʹ��(Power Rise interrupt enable) ��غ��� */
extern void SVD_IER_PRIE_Setable(FunState NewState);
extern FunState SVD_IER_PRIE_Getable(void);

/* SVD��Դ������ (SVD output) ��غ��� */
extern FlagStatus SVD_ISR_SVDO_Chk(void);

/* SVD��������źţ����ֵ�·�����SVD״̬ ��غ��� */
extern FlagStatus SVD_ISR_SVDR_Chk(void);

/* ��Դ�����жϱ�־ ��غ��� */
extern void SVD_ISR_PFF_Clr(void);
extern FlagStatus SVD_ISR_PFF_Chk(void);

/* ��Դ�ָ��жϱ�־ ��غ��� */
extern void SVD_ISR_PRF_Clr(void);
extern FlagStatus SVD_ISR_PRF_Chk(void);

/* 0.85V��׼����ʹ���ź� (0.85V reference enable) ��غ��� */
extern void SVD_VSR_V0P85EN_Setable(FunState NewState);
extern FunState SVD_VSR_V0P85EN_Getable(void);

/* 0.8V��׼����ʹ���ź� (0.8V reference enable) ��غ��� */
extern void SVD_VSR_V0P8EN_Setable(FunState NewState);
extern FunState SVD_VSR_V0P8EN_Getable(void);

/* 0.75V��׼����ʹ���ź� (0.75V reference enable) ��غ��� */
extern void SVD_VSR_V0P75EN_Setable(FunState NewState);
extern FunState SVD_VSR_V0P75EN_Getable(void); 

extern void SVD_Init(ANAC_SVD_InitTypeDef* para);
#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_SVD_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
