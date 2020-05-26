/**
  ******************************************************************************
  * @file    fm33l0xx_rng.c
  * @author  FM33L0 Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33l0xx_rng.h" 
#include "fm33l0xx_rcc.h" 

/** @addtogroup fm33l0_StdPeriph_Driver
  * @{
  */

/** @defgroup RNG 
  * @brief RNG driver modules
  * @{
  */ 
  
//Code_Start
//2019-06-13-12-59-53
//FM33A0XX_Driver_Gen_V1.4

/* RNGʹ�ܼĴ��������д1ʹ�� ��غ��� */
void RNG_CR_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RNG_CR->CR |= (RNG_CR_EN_Msk);
	}
	else
	{
		RNG_CR->CR &= ~(RNG_CR_EN_Msk);
	}
}

FunState RNG_CR_EN_Getable(void)
{
	if (RNG_CR->CR & (RNG_CR_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��������ɽ����CRC�������Ĵ��� ��غ��� */
uint32_t RNG_DOR_Read(void)
{
	return (RNG->DOR);
}

/* LFSRʹ�ܱ�־,���Ĵ�����������ģ���жϣ�������ѯ ��غ��� */
FlagStatus RNG_SR_LFSREN_Chk(void)
{
	if (RNG->SR & RNG_SR_LFSREN_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���������ʧ�ܱ�־�����д1��0 ��غ��� */
void RNG_SR_RNF_Clr(void)
{
	RNG->SR = RNG_SR_RNF_Msk;
}

FlagStatus RNG_SR_RNF_Chk(void)
{
	if (RNG->SR & RNG_SR_RNF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* CRC���ƼĴ��� ��غ��� */
void RNG_CRC_CR_CRCEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RNG->CRC_CR |= (RNG_CRC_CR_CRCEN_Msk);
	}
	else
	{
		RNG->CRC_CR &= ~(RNG_CRC_CR_CRCEN_Msk);
	}
}

FunState RNG_CRC_CR_CRCEN_Getable(void)
{
	if (RNG->CRC_CR & (RNG_CRC_CR_CRCEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* CRC������������Ĵ��� ��غ��� */
void RNG_CRC_DIR_Write(uint32_t SetValue)
{
	RNG->CRC_DIR = (SetValue);
}

uint32_t RNG_CRC_DIR_Read(void)
{
	return (RNG->CRC_DIR);
}

/* CRC������ɱ�־�����д0���� ��غ��� */
void RNG_CRC_SR_CRCDONE_Clr(void)
{
	RNG->CRC_SR &= ~(RNG_CRC_SR_CRCDONE_Msk);
}

FlagStatus RNG_CRC_SR_CRCDONE_Chk(void)
{
	if (RNG->CRC_SR & RNG_CRC_SR_CRCDONE_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void RNG_Deinit(void)
{
	 RCC_PRST_EN_Write(RSTKEY0);
   RCC_APBRST_CR2_RNGRST_Setable(ENABLE);  
   RCC_APBRST_CR2_RNGRST_Setable(DISABLE);
   RCC_PRST_EN_Write(RSTKEY1);
}

/******END OF FILE****/
