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
#define	RNG_CR_EN_Pos	0	/* RNGʹ�ܼĴ��������д1ʹ�� */
#define	RNG_CR_EN_Msk	(0x1U << RNG_CR_EN_Pos)
	/* 0���ر�RNG */
	/* 1��ʹ��RNG */

#define	RNG_DOR_OUT_Pos	0	/* ��������ɽ����CRC�������Ĵ��� */
#define	RNG_DOR_OUT_Msk	(0xffffffffU << RNG_DOR_OUT_Pos)

#define	RNG_SR_LFSREN_Pos	1	/* LFSRʹ�ܱ�־,���Ĵ�����������ģ���жϣ�������ѯ */
#define	RNG_SR_LFSREN_Msk	(0x1U << RNG_SR_LFSREN_Pos)

#define	RNG_SR_RNF_Pos	0	/* ���������ʧ�ܱ�־�����д1��0 */
#define	RNG_SR_RNF_Msk	(0x1U << RNG_SR_RNF_Pos)

#define	RNG_CRC_CR_CRCEN_Pos	0	/* CRC���ƼĴ��� */
#define	RNG_CRC_CR_CRCEN_Msk	(0x1U << RNG_CRC_CR_CRCEN_Pos)
	/* 0��CRC�ر� */
	/* 1��CRCʹ�� */

#define	RNG_CRC_DIR_CRCIN_Pos	0	/* CRC������������Ĵ��� */
#define	RNG_CRC_DIR_CRCIN_Msk	(0xffffffffU << RNG_CRC_DIR_CRCIN_Pos)

#define	RNG_CRC_SR_CRCDONE_Pos	0	/* CRC������ɱ�־�����д0���� */
#define	RNG_CRC_SR_CRCDONE_Msk	(0x1U << RNG_CRC_SR_CRCDONE_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void RNG_Deinit(void);

/* RNGʹ�ܼĴ��������д1ʹ�� ��غ��� */
extern void RNG_CR_EN_Setable(FunState NewState);
extern FunState RNG_CR_EN_Getable(void);

/* ��������ɽ����CRC�������Ĵ��� ��غ��� */
extern uint32_t RNG_DOR_Read(void);

/* LFSRʹ�ܱ�־,���Ĵ�����������ģ���жϣ�������ѯ ��غ��� */
extern FlagStatus RNG_SR_LFSREN_Chk(void);

/* ���������ʧ�ܱ�־�����д1��0 ��غ��� */
extern void RNG_SR_RNF_Clr(void);
extern FlagStatus RNG_SR_RNF_Chk(void);

/* CRC���ƼĴ��� ��غ��� */
extern void RNG_CRC_CR_CRCEN_Setable(FunState NewState);
extern FunState RNG_CRC_CR_CRCEN_Getable(void);

/* CRC������������Ĵ��� ��غ��� */
extern void RNG_CRC_DIR_Write(uint32_t SetValue);
extern uint32_t RNG_CRC_DIR_Read(void);

/* CRC������ɱ�־�����д0���� ��غ��� */
extern void RNG_CRC_SR_CRCDONE_Clr(void);
extern FlagStatus RNG_CRC_SR_CRCDONE_Chk(void);


                
#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_RNG_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
