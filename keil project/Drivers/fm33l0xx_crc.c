/**
  ******************************************************************************
  * @file    fm33l0xx_crc.c
  * @author  FM33L0 Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33l0xx_crc.h" 


/** @addtogroup fm33l0_StdPeriph_Driver
  * @{
  */

/** @defgroup CRC 
  * @brief CRC driver modules
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


/********************************
CRC ���ܿ��ƺ���
����: ���CRC��������(����16λ��Ч)
���룺CRC����
���: ��
********************************/
void CRC_DR_Write(uint32_t SetValue)
{
	CRC->DR = (SetValue);
}

uint32_t CRC_DR_Read(void)
{
	return (CRC->DR);
}

/* WORD����ʹ�� ��غ��� */
void CRC_CR_OPWD_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CRC->CR |= (CRC_CR_OPWD_Msk);
	}
	else
	{
		CRC->CR &= ~(CRC_CR_OPWD_Msk);
	}
}

FunState CRC_CR_OPWD_Getable(void)
{
	if (CRC->CR & (CRC_CR_OPWD_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* CRC���ټ���ʹ�� ��غ��� */
void CRC_CR_PARA_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CRC->CR |= (CRC_CR_PARA_Msk);
	}
	else
	{
		CRC->CR &= ~(CRC_CR_PARA_Msk);
	}
}

FunState CRC_CR_PARA_Getable(void)
{
	if (CRC->CR & (CRC_CR_PARA_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* CRC���뷴ת���� ��غ��� */
void CRC_CR_RFLTIN_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CRC->CR;
	tmpreg &= ~(CRC_CR_RFLTIN_Msk);
	tmpreg |= (SetValue & CRC_CR_RFLTIN_Msk);
	CRC->CR = tmpreg;
}

uint32_t CRC_CR_RFLTIN_Get(void)
{
	return (CRC->CR & CRC_CR_RFLTIN_Msk);
}

/* CRC�����ת���� ��غ��� */
void CRC_CR_RFLTO_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CRC->CR |= (CRC_CR_RFLTO_Msk);
	}
	else
	{
		CRC->CR &= ~(CRC_CR_RFLTO_Msk);
	}
}

FunState CRC_CR_RFLTO_Getable(void)
{
	if (CRC->CR & (CRC_CR_RFLTO_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* CRC�����־λ��ֻ�� ��غ��� */
FlagStatus CRC_CR_RES_Chk(void)
{
	if (CRC->CR & CRC_CR_RES_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* CRC�����־λ��ֻ�� ��غ��� */
FlagStatus CRC_CR_BUSY_Chk(void)
{
	if (CRC->CR & CRC_CR_BUSY_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ������ʹ�� ��غ��� */
void CRC_CR_XOR_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CRC->CR |= (CRC_CR_XOR_Msk);
	}
	else
	{
		CRC->CR &= ~(CRC_CR_XOR_Msk);
	}
}

FunState CRC_CR_XOR_Getable(void)
{
	if (CRC->CR & (CRC_CR_XOR_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* CRCУ�����ʽѡ�� ��غ��� */
void CRC_CR_SEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CRC->CR;
	tmpreg &= ~(CRC_CR_SEL_Msk);
	tmpreg |= (SetValue & CRC_CR_SEL_Msk);
	CRC->CR = tmpreg;
}

uint32_t CRC_CR_SEL_Get(void)
{
	return (CRC->CR & CRC_CR_SEL_Msk);
}

/* CRC���Է�����λ�Ĵ��� ��غ��� */
void CRC_LFSR_Write(uint32_t SetValue)
{
	CRC->LFSR = (SetValue);
}

uint32_t CRC_LFSR_Read(void)
{
	return (CRC->LFSR);
}

/* CRC���������Ĵ��� ��غ��� */
void CRC_XOR_Write(uint32_t SetValue)
{
	CRC->XOR = (SetValue);
}

uint32_t CRC_XOR_Read(void)
{
	return (CRC->XOR);
}

/* Flash����CRCУ��ʹ�� ��غ��� */
void CRC_FLS_CR_FLSCRCEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CRC->FLS_CR |= (CRC_FLS_CR_FLSCRCEN_Msk);
	}
	else
	{
		CRC->FLS_CR &= ~(CRC_FLS_CR_FLSCRCEN_Msk);
	}
}

FunState CRC_FLS_CR_FLSCRCEN_Getable(void)
{
	if (CRC->FLS_CR & (CRC_FLS_CR_FLSCRCEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* FlashУ����ʼ��ַ��Word��ַ�� ��غ��� */
void CRC_FLS_AD_Write(uint32_t SetValue)
{
	CRC->FLS_AD = (SetValue & CRC_FLS_AD_FLSAD_Msk);
}

uint32_t CRC_FLS_AD_Read(void)
{
	return (CRC->FLS_AD & CRC_FLS_AD_FLSAD_Msk);
}

/* CRC FlashУ�����ݳ��ȣ�Word���ȣ� ��غ��� */
void CRC_FLS_SIZE_Write(uint32_t SetValue)
{
	CRC->FLS_SIZE = (SetValue & CRC_FLS_SIZE_FLSS_Msk);
}

uint32_t CRC_FLS_SIZE_Read(void)
{
	return (CRC->FLS_SIZE & CRC_FLS_SIZE_FLSS_Msk);
}

/* CRC�������ʽϵ�� ��غ��� */
void CRC_POLY_Write(uint32_t SetValue)
{
	CRC->POLY = (SetValue);
}

uint32_t CRC_POLY_Read(void)
{
	return (CRC->POLY);
}


void CRC_Deinit(void)
{
	//CRC->DR = 0xFFFFFFFF;
	CRC->CR = 0x00000000;
	CRC->LFSR = 0xFFFFFFFF;
	CRC->XOR = 0x00000000;
	CRC->FLS_CR = 0x00000000;
	CRC->FLS_AD = 0x00000000;
	CRC->FLS_SIZE = 0x00000000;
	CRC->POLY = 0x00001021;
}
//Code_End

/* CRC��ʼ�����ú���*/
void CRC_Init(CRC_InitTypeDef* para)
{
	CRC_CR_SEL_Set(para->CRCSEL);			/*!<CRCУ�����ʽλ��ѡ��*/
	CRC_CR_OPWD_Setable(para->OPWD);			/*!<WORD����ʹ��*/
	CRC_CR_PARA_Setable(para->PARA);			/*!<CRC���ټ���ʹ��*/
	CRC_CR_RFLTIN_Set(para->RFLTIN);		/*!<CRC���뷴ת����*/
	CRC_CR_RFLTO_Setable(para->RFLTO);		/*!<CRC�����ת����*/
	CRC_CR_XOR_Setable(para->XOR);			/*!<������ʹ��*/
	CRC_XOR_Write(para->CRC_XOR);			/*!<���������Ĵ���*/
	CRC_POLY_Write(para->CRCPOLY);			/*!<CRC����ʽ�Ĵ���*/
}

/******END OF FILE****/
