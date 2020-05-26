/**
  ******************************************************************************
  * @file    fm33l0xx_beeper.c
  * @author  FM33L0 Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33l0xx_beeper.h" 


/** @addtogroup fm33l0_StdPeriph_Driver
  * @{
  */

/** @defgroup BEEPER 
  * @brief BEEPER driver modules
  * @{
  */ 
  //Code_Start
//2019-06-13-13-14-50
//FM33A0XX_Driver_Gen_V1.4

/* BEEP波形分频系数,BEEP输出频率为BEEPCLK/(2*(BEEPDIV+1)) 相关函数 */
void BEEP_CSR_DIV_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BEEP->CSR;
	tmpreg &= ~(BEEP_CSR_DIV_Msk);
	tmpreg |= (SetValue & BEEP_CSR_DIV_Msk);
	BEEP->CSR = tmpreg;
}

uint32_t BEEP_CSR_DIV_Get(void)
{
	return (BEEP->CSR & BEEP_CSR_DIV_Msk);
}

/* BEEP使能 相关函数 */
void BEEP_CSR_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		BEEP->CSR |= (BEEP_CSR_EN_Msk);
	}
	else
	{
		BEEP->CSR &= ~(BEEP_CSR_EN_Msk);
	}
}

FunState BEEP_CSR_EN_Getable(void)
{
	if (BEEP->CSR & (BEEP_CSR_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}


void BEEP_Deinit(void)
{
	//BEEP->CSR = 0x00000000;
}
//Code_End

  
/******END OF FILE****/
