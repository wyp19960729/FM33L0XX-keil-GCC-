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
  
  /* Debug״̬��ATIMʹ�ܿ��� ��غ��� */
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

/* Debug״̬��GPTIM1ʹ�ܿ��� ��غ��� */
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

/* Debug״̬��GPTIM0ʹ�ܿ��� ��غ��� */
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

/* Debug״̬��BSTIMʹ�ܿ��� ��غ��� */
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

/* Debug״̬��WWDTʹ�ܿ��� ��غ��� */
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

/* Debug״̬��IWDTʹ�ܿ��� ��غ��� */
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

/* ��ַ�Ƕ�����ʴ����־ ��غ��� */
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

/* �Ƿ���ַ���ʴ����־ ��غ��� */
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

/* SVC instructionsδ�����־ ��غ��� */
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

/* ִ��BKPTָ���־ ��غ��� */
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

/* Thumb-State��־ ��غ��� */
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

/* ����ָ���־ ��غ��� */
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

/* hardfault��־λ ��غ��� */
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
