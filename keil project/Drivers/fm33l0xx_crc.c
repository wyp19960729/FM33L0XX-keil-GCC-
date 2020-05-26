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
CRC 功能控制函数
功能: 填充CRC数据输入(仅低16位有效)
输入：CRC输入
输出: 无
********************************/
void CRC_DR_Write(uint32_t SetValue)
{
	CRC->DR = (SetValue);
}

uint32_t CRC_DR_Read(void)
{
	return (CRC->DR);
}

/* WORD操作使能 相关函数 */
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

/* CRC快速计算使能 相关函数 */
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

/* CRC输入反转控制 相关函数 */
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

/* CRC输出反转控制 相关函数 */
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

/* CRC结果标志位，只读 相关函数 */
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

/* CRC运算标志位，只读 相关函数 */
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

/* 输出异或使能 相关函数 */
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

/* CRC校验多项式选择 相关函数 */
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

/* CRC线性反馈移位寄存器 相关函数 */
void CRC_LFSR_Write(uint32_t SetValue)
{
	CRC->LFSR = (SetValue);
}

uint32_t CRC_LFSR_Read(void)
{
	return (CRC->LFSR);
}

/* CRC运算结果异或寄存器 相关函数 */
void CRC_XOR_Write(uint32_t SetValue)
{
	CRC->XOR = (SetValue);
}

uint32_t CRC_XOR_Read(void)
{
	return (CRC->XOR);
}

/* Flash内容CRC校验使能 相关函数 */
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

/* Flash校验起始地址（Word地址） 相关函数 */
void CRC_FLS_AD_Write(uint32_t SetValue)
{
	CRC->FLS_AD = (SetValue & CRC_FLS_AD_FLSAD_Msk);
}

uint32_t CRC_FLS_AD_Read(void)
{
	return (CRC->FLS_AD & CRC_FLS_AD_FLSAD_Msk);
}

/* CRC Flash校验数据长度（Word长度） 相关函数 */
void CRC_FLS_SIZE_Write(uint32_t SetValue)
{
	CRC->FLS_SIZE = (SetValue & CRC_FLS_SIZE_FLSS_Msk);
}

uint32_t CRC_FLS_SIZE_Read(void)
{
	return (CRC->FLS_SIZE & CRC_FLS_SIZE_FLSS_Msk);
}

/* CRC运算多项式系数 相关函数 */
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

/* CRC初始化配置函数*/
void CRC_Init(CRC_InitTypeDef* para)
{
	CRC_CR_SEL_Set(para->CRCSEL);			/*!<CRC校验多项式位宽选择*/
	CRC_CR_OPWD_Setable(para->OPWD);			/*!<WORD操作使能*/
	CRC_CR_PARA_Setable(para->PARA);			/*!<CRC快速计算使能*/
	CRC_CR_RFLTIN_Set(para->RFLTIN);		/*!<CRC输入反转控制*/
	CRC_CR_RFLTO_Setable(para->RFLTO);		/*!<CRC输出反转控制*/
	CRC_CR_XOR_Setable(para->XOR);			/*!<输出异或使能*/
	CRC_XOR_Write(para->CRC_XOR);			/*!<运算结果异或寄存器*/
	CRC_POLY_Write(para->CRCPOLY);			/*!<CRC多项式寄存器*/
}

/******END OF FILE****/
