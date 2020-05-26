/**
  ******************************************************************************
  * @file    fm33l0xx_dbg.c
  * @author  FM33L0 Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33l0xx_dbg.h" 


/** @addtogroup fm33l0_StdPeriph_Driver
  * @{
  */

/** @defgroup DBG 
  * @brief DBG driver modules
  * @{
  */ 
  
  /* Debug状态下ATIM使能控制 相关函数 */
void DBG_CR_AT_STOP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		DBG->CR |= (DBG_CR_AT_STOP_Msk);
	}
	else
	{
		DBG->CR &= ~(DBG_CR_AT_STOP_Msk);
	}
}

FunState DBG_CR_AT_STOP_Getable(void)
{
	if (DBG->CR & (DBG_CR_AT_STOP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Debug状态下GPTIM1使能控制 相关函数 */
void DBG_CR_GT1_STOP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		DBG->CR |= (DBG_CR_GT1_STOP_Msk);
	}
	else
	{
		DBG->CR &= ~(DBG_CR_GT1_STOP_Msk);
	}
}

FunState DBG_CR_GT1_STOP_Getable(void)
{
	if (DBG->CR & (DBG_CR_GT1_STOP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Debug状态下GPTIM0使能控制 相关函数 */
void DBG_CR_GT0_STOP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		DBG->CR |= (DBG_CR_GT0_STOP_Msk);
	}
	else
	{
		DBG->CR &= ~(DBG_CR_GT0_STOP_Msk);
	}
}

FunState DBG_CR_GT0_STOP_Getable(void)
{
	if (DBG->CR & (DBG_CR_GT0_STOP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Debug状态下BSTIM使能控制 相关函数 */
void DBG_CR_BT_STOP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		DBG->CR |= (DBG_CR_BT_STOP_Msk);
	}
	else
	{
		DBG->CR &= ~(DBG_CR_BT_STOP_Msk);
	}
}

FunState DBG_CR_BT_STOP_Getable(void)
{
	if (DBG->CR & (DBG_CR_BT_STOP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Debug状态下WWDT使能控制 相关函数 */
void DBG_CR_WWDT_STOP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		DBG->CR |= (DBG_CR_WWDT_STOP_Msk);
	}
	else
	{
		DBG->CR &= ~(DBG_CR_WWDT_STOP_Msk);
	}
}

FunState DBG_CR_WWDT_STOP_Getable(void)
{
	if (DBG->CR & (DBG_CR_WWDT_STOP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Debug状态下IWDT使能控制 相关函数 */
void DBG_CR_IWDT_STOP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		DBG->CR |= (DBG_CR_IWDT_STOP_Msk);
	}
	else
	{
		DBG->CR &= ~(DBG_CR_IWDT_STOP_Msk);
	}
}

FunState DBG_CR_IWDT_STOP_Getable(void)
{
	if (DBG->CR & (DBG_CR_IWDT_STOP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 地址非对齐访问错误标志 相关函数 */
void DBG_HDFR_DABORT_ADDR_FLAG_Clr(void)
{
	DBG->HDFR = DBG_HDFR_DABORT_ADDR_FLAG_Msk;
}

FlagStatus DBG_HDFR_DABORT_ADDR_FLAG_Chk(void)
{
	if (DBG->HDFR & DBG_HDFR_DABORT_ADDR_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 非法地址访问错误标志 相关函数 */
void DBG_HDFR_DABORT_RESP_FLAG_Clr(void)
{
	DBG->HDFR = DBG_HDFR_DABORT_RESP_FLAG_Msk;
}

FlagStatus DBG_HDFR_DABORT_RESP_FLAG_Chk(void)
{
	if (DBG->HDFR & DBG_HDFR_DABORT_RESP_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* SVC instructions未定义标志 相关函数 */
void DBG_HDFR_SVCUNDEF_FLAG_Clr(void)
{
	DBG->HDFR = DBG_HDFR_SVCUNDEF_FLAG_Msk;
}

FlagStatus DBG_HDFR_SVCUNDEF_FLAG_Chk(void)
{
	if (DBG->HDFR & DBG_HDFR_SVCUNDEF_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 执行BKPT指令标志 相关函数 */
void DBG_HDFR_BKPT_FLAG_Clr(void)
{
	DBG->HDFR = DBG_HDFR_BKPT_FLAG_Msk;
}

FlagStatus DBG_HDFR_BKPT_FLAG_Chk(void)
{
	if (DBG->HDFR & DBG_HDFR_BKPT_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* Thumb-State标志 相关函数 */
void DBG_HDFR_TBIT_FLAG_Clr(void)
{
	DBG->HDFR = DBG_HDFR_TBIT_FLAG_Msk;
}

FlagStatus DBG_HDFR_TBIT_FLAG_Chk(void)
{
	if (DBG->HDFR & DBG_HDFR_TBIT_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 特殊指令标志 相关函数 */
void DBG_HDFR_SPECIAL_OP_FLAG_Clr(void)
{
	DBG->HDFR = DBG_HDFR_SPECIAL_OP_FLAG_Msk;
}

FlagStatus DBG_HDFR_SPECIAL_OP_FLAG_Chk(void)
{
	if (DBG->HDFR & DBG_HDFR_SPECIAL_OP_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* hardfault标志位 相关函数 */
void DBG_HDFR_HDF_REQUEST_FLAG_Clr(void)
{
	DBG->HDFR = DBG_HDFR_HDF_REQUEST_FLAG_Msk;
}

FlagStatus DBG_HDFR_HDF_REQUEST_FLAG_Chk(void)
{
	if (DBG->HDFR & DBG_HDFR_HDF_REQUEST_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}
//Code_End

  
/******END OF FILE****/
