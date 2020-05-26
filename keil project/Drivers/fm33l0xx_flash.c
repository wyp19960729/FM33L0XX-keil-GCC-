/**
  ******************************************************************************
  * @file    fm33l0xx_flash.c
  * @author  FM33L0 Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33l0xx_flash.h" 


/** @addtogroup fm33l0_StdPeriph_Driver
  * @{
  */

/** @defgroup flash 
  * @brief flash driver modules
  * @{
  */ 
  
/* Flash读等待周期配置(CPU时钟超过24M后需开wait1) 相关函数 */
void FLS_RDCR_WAIT_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = FLS->RDCR;
	tmpreg &= ~(FLS_RDCR_WAIT_Msk);
	tmpreg |= (SetValue & FLS_RDCR_WAIT_Msk);
	FLS->RDCR = tmpreg;
}

uint32_t FLS_RDCR_WAIT_Get(void)
{
	return (FLS->RDCR & FLS_RDCR_WAIT_Msk);
}

/* 用户配置字寄存器 相关函数 */
FunState FLS_OPTBR_DBGOFF_EN_Getable(void)
{
	if (FLS->OPTBR & (FLS_OPTBR_DBGOFF_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

FunState FLS_OPTBR_BTSEN_Getable(void)
{
	if (FLS->OPTBR & (FLS_OPTBR_BTSEN_Msk))
	{
		return DISABLE;
	}
	else
	{
		return ENABLE;
	}
}

FunState FLS_OPTBR_ACLOCKEN_Getable(void)
{
	if (FLS->OPTBR & (FLS_OPTBR_ACLOCKEN_Msk))
	{
		return DISABLE;
	}
	else
	{
		return ENABLE;
	}
}

FunState FLS_OPTBR_DBRDPEN_Getable(void)
{
	if (FLS->OPTBR & (FLS_OPTBR_DBRDPEN_Msk))
	{
		return DISABLE;
	}
	else
	{
		return ENABLE;
	}
}

/* ACLOCK配置寄存器 相关函数 */
void FLS_ACLOCK_Write(uint32_t SetValue)
{
	FLS->ACLOCK = (SetValue);
}

uint32_t FLS_ACLOCK_Read(void)
{
	return (FLS->ACLOCK);
}

/* 扇区擦 相关函数 */
void FLS_EPCR_ERTYPE_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = FLS->EPCR;
	tmpreg &= ~(FLS_EPCR_ERTYPE_Msk);
	tmpreg |= (SetValue & FLS_EPCR_ERTYPE_Msk);
	FLS->EPCR = tmpreg;
}

uint32_t FLS_EPCR_ERTYPE_Get(void)
{
	return (FLS->EPCR & FLS_EPCR_ERTYPE_Msk);
}

void FLS_EPCR_PREQ_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = FLS->EPCR;
	tmpreg &= ~(FLS_EPCR_PREQ_Msk);
	tmpreg |= (SetValue & FLS_EPCR_PREQ_Msk);
	FLS->EPCR = tmpreg;
}

uint32_t FLS_EPCR_PREQ_Get(void)
{
	return (FLS->EPCR & FLS_EPCR_PREQ_Msk);
}

void FLS_EPCR_EREQ_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = FLS->EPCR;
	tmpreg &= ~(FLS_EPCR_EREQ_Msk);
	tmpreg |= (SetValue & FLS_EPCR_EREQ_Msk);
	FLS->EPCR = tmpreg;
}

uint32_t FLS_EPCR_EREQ_Get(void)
{
	return (FLS->EPCR & FLS_EPCR_EREQ_Msk);
}

/* Flash擦写Key输入寄存器，软件或者SWD在启动擦写前必须正确地向此地址写入合法KEY序列。空地址，物理上无寄存器实现。 相关函数 */
void FLS_KEY_Write(uint32_t SetValue)
{
	FLS->KEY = (SetValue);
}

/* Flash读写权限错误中断使能 (Flash Authentication Error Interrupt Enable) 相关函数 */
void FLS_IER_AUTHIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		FLS->IER |= (FLS_IER_AUTHIE_Msk);
	}
	else
	{
		FLS->IER &= ~(FLS_IER_AUTHIE_Msk);
	}
}

FunState FLS_IER_AUTHIE_Getable(void)
{
	if (FLS->IER & (FLS_IER_AUTHIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Flash KEY错误中断使能 (Flash Key Error Interrupt Enable) 相关函数 */
void FLS_IER_KEYIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		FLS->IER |= (FLS_IER_KEYIE_Msk);
	}
	else
	{
		FLS->IER &= ~(FLS_IER_KEYIE_Msk);
	}
}

FunState FLS_IER_KEYIE_Getable(void)
{
	if (FLS->IER & (FLS_IER_KEYIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 擦写定时时钟错误中断使能 (Erase/Program Clock Error Interrupt Enable) 相关函数 */
void FLS_IER_CKIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		FLS->IER |= (FLS_IER_CKIE_Msk);
	}
	else
	{
		FLS->IER &= ~(FLS_IER_CKIE_Msk);
	}
}

FunState FLS_IER_CKIE_Getable(void)
{
	if (FLS->IER & (FLS_IER_CKIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 编程完成标志中断使能 (Program Done Interrupt Enable) 相关函数 */
void FLS_IER_PRDIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		FLS->IER |= (FLS_IER_PRDIE_Msk);
	}
	else
	{
		FLS->IER &= ~(FLS_IER_PRDIE_Msk);
	}
}

FunState FLS_IER_PRDIE_Getable(void)
{
	if (FLS->IER & (FLS_IER_PRDIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 擦写完成标志中断使能 (Erase Done Interrupt Enable) 相关函数 */
void FLS_IER_ERDIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		FLS->IER |= (FLS_IER_ERDIE_Msk);
	}
	else
	{
		FLS->IER &= ~(FLS_IER_ERDIE_Msk);
	}
}

FunState FLS_IER_ERDIE_Getable(void)
{
	if (FLS->IER & (FLS_IER_ERDIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Flash标志寄存器 相关函数 */
uint32_t FLS_ISR_KEYSTA_Get(void)
{
	return (FLS->ISR & FLS_ISR_KEYSTA_Msk);
}

uint32_t FLS_ISR_BTSF_Get(void)
{
	return (FLS->ISR & FLS_ISR_BTSF_Msk);
}

void FLS_ISR_AUTHERR_Clr(void)
{
	FLS->ISR = FLS_ISR_AUTHERR_Msk;
}

FlagStatus FLS_ISR_AUTHERR_Chk(void)
{
	if (FLS->ISR & FLS_ISR_AUTHERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void FLS_ISR_KEYERR_Clr(void)
{
	FLS->ISR = FLS_ISR_KEYERR_Msk;
}

FlagStatus FLS_ISR_KEYERR_Chk(void)
{
	if (FLS->ISR & FLS_ISR_KEYERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void FLS_ISR_CKERR_Clr(void)
{
	FLS->ISR = FLS_ISR_CKERR_Msk;
}

FlagStatus FLS_ISR_CKERR_Chk(void)
{
	if (FLS->ISR & FLS_ISR_CKERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void FLS_ISR_PRD_Clr(void)
{
	FLS->ISR = FLS_ISR_PRD_Msk;
}

FlagStatus FLS_ISR_PRD_Chk(void)
{
	if (FLS->ISR & FLS_ISR_PRD_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void FLS_ISR_ERD_Clr(void)
{
	FLS->ISR = FLS_ISR_ERD_Msk;
}

FlagStatus FLS_ISR_ERD_Chk(void)
{
	if (FLS->ISR & FLS_ISR_ERD_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}


void FLS_Deinit(void)
{

}

/********************************
扇区擦配置函数
功能:扇区擦配置
输入：擦除地址
输出: 无
********************************/
void FLASH_Erase_Sector(uint32_t erase_addr)
{
    //set to sector erase
    FLS_EPCR_ERTYPE_Set(FLS_EPCR_ERTYPE_SECTOR);
	
    //SET EREQ
    FLS_EPCR_EREQ_Set(FLS_EPCR_EREQ_ERASE);
	
    //write flash key
    FLS_KEY_Write(FLS_SECTOR_ERASE_KEY0);
    FLS_KEY_Write(FLS_SECTOR_ERASE_KEY1);
	
    //向需要擦除的扇区内任意地址写擦除请求0x1234_ABCD
    *(uint32_t*)erase_addr = FLS_ERASE_DATA;
	
	//wait for finish
	while (SET != FLS_ISR_ERD_Chk()) {__NOP();}
	FLS_ISR_ERD_Clr();
	
    FLS_KEY_Write(0x00000000);
}

/********************************
单字写flash函数
功能:单字写flash
输入：写入地址和写入数据
输出: 无
********************************/
void FLASH_Prog_SingleByte(uint32_t prog_addr,uint8_t prog_data)
{
	//set PREQ
    FLS_EPCR_PREQ_Set(FLS_EPCR_PREQ_PROG);
	
	//write flash key
    FLS_KEY_Write(FLS_PROG_KEY0);
    FLS_KEY_Write(FLS_PROG_KEY1);
	
    *(uint8_t*)prog_addr = prog_data;	

    while (RESET == FLS_ISR_PRD_Chk()){__NOP();}
	FLS_ISR_PRD_Clr();
	
    FLS_KEY_Write(0x00000000);
}

/********************************
连续写flash函数
功能:连续写flash
输入：写入地址、写入数据和长度
输出: 无
********************************/
void FLASH_Prog_ByteString(uint32_t prog_addr,uint8_t* prog_data, uint16_t Len)
{
	uint16_t i;
    
	//set PREQ
	FLS_EPCR_PREQ_Set(FLS_EPCR_PREQ_PROG);
	
	//write flash key
	FLS_KEY_Write(FLS_PROG_KEY0);
    FLS_KEY_Write(FLS_PROG_KEY1);
	
	for (i = 0; i < Len; i++)
	{
		FLS_EPCR_PREQ_Set(FLS_EPCR_PREQ_PROG);
		*(uint8_t*)prog_addr = prog_data[i];			// 写一个字节
		prog_addr++;
		while (RESET == FLS_ISR_PRD_Chk()){__NOP();}    // 等待写操作完成
		FLS_ISR_PRD_Clr();						        // 清除写完成中断标志
	}
	
    FLS_KEY_Write(0x00000000);
}
  
/******END OF FILE****/
