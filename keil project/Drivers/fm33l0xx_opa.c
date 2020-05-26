/**
  ******************************************************************************
  * @file    fm33l0xx_opa.c
  * @author  FM33L0 Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33l0xx_opa.h" 
#include "fm33l0xx_rcc.h" 

/** @addtogroup fm33l0_StdPeriph_Driver
  * @{
  */

/** @defgroup OPA 
  * @brief OPA driver modules
  * @{
  */ 

/* VREF BUFFERʹ���ź� (VREF buffer enable) ��غ��� */
void OPAx_CR_BUFOFF_EN_Setable(OPA_Type* OPAx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		OPAx->CR |= (OPAx_CR_BUFOFF_EN_Msk);
	}
	else
	{
		OPAx->CR &= ~(OPAx_CR_BUFOFF_EN_Msk);
	}
}

FunState OPAx_CR_BUFOFF_EN_Getable(OPA_Type* OPAx)
{
	if (OPAx->CR & (OPAx_CR_BUFOFF_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* VREF BUFFER��·���� (VREF buffer bypass) ��غ��� */
void OPAx_CR_BUFBYP_Setable(OPA_Type* OPAx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		OPAx->CR |= (OPAx_CR_BUFBYP_Msk);
	}
	else
	{
		OPAx->CR &= ~(OPAx_CR_BUFBYP_Msk);
	}
}

FunState OPAx_CR_BUFBYP_Getable(OPA_Type* OPAx)
{
	if (OPAx->CR & (OPAx_CR_BUFBYP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* OPA��������ѡ�� (OPA Negtive Input Select) ��غ��� */
void OPAx_CR_VNSEL_Set(OPA_Type* OPAx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = OPAx->CR;
	tmpreg &= ~(OPAx_CR_VNSEL_Msk);
	tmpreg |= (SetValue & OPAx_CR_VNSEL_Msk);
	OPAx->CR = tmpreg;
}

uint32_t OPAx_CR_VNSEL_Get(OPA_Type* OPAx)
{
	return (OPAx->CR & OPAx_CR_VNSEL_Msk);
}

/* OPA��������ѡ�� (OPA Positive Input Select) ��غ��� */
void OPAx_CR_VPSEL_Set(OPA_Type* OPAx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = OPAx->CR;
	tmpreg &= ~(OPAx_CR_VPSEL_Msk);
	tmpreg |= (SetValue & OPAx_CR_VPSEL_Msk);
	OPAx->CR = tmpreg;
}

uint32_t OPAx_CR_VPSEL_Get(OPA_Type* OPAx)
{
	return (OPAx->CR & OPAx_CR_VPSEL_Msk);
}

/* OPA�Ƚ���ģʽ��������˲�ʹ�ܣ���OPA����Ϊ�Ƚ���ģʽ����Ч�� (OPA Comparator mode digital filter) ��غ��� */
void OPAx_CR_DF_Setable(OPA_Type* OPAx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		OPAx->CR |= (OPAx_CR_DF_Msk);
	}
	else
	{
		OPAx->CR &= ~(OPAx_CR_DF_Msk);
	}
}

FunState OPAx_CR_DF_Getable(OPA_Type* OPAx)
{
	if (OPAx->CR & (OPAx_CR_DF_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* OPA��������GPIO����OPAxMOD=10ʱ��Ч
(OPA Negtive Input Connected to GPIO)
 ��غ��� */
void OPAx_CR_VN_EXC_Setable(OPA_Type* OPAx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		OPAx->CR |= (OPAx_CR_VN_EXC_Msk);
	}
	else
	{
		OPAx->CR &= ~(OPAx_CR_VN_EXC_Msk);
	}
}

FunState OPAx_CR_VN_EXC_Getable(OPA_Type* OPAx)
{
	if (OPAx->CR & (OPAx_CR_VN_EXC_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* PGA����ѡ�� (PGA gain select) ��غ��� */
void OPAx_CR_PGA_GAIN_Set(OPA_Type* OPAx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = OPAx->CR;
	tmpreg &= ~(OPAx_CR_PGA_GAIN_Msk);
	tmpreg |= (SetValue & OPAx_CR_PGA_GAIN_Msk);
	OPAx->CR = tmpreg;
}

uint32_t OPAx_CR_PGA_GAIN_Get(OPA_Type* OPAx)
{
	return (OPAx->CR & OPAx_CR_PGA_GAIN_Msk);
}

/* OPA����ģʽ (OPA mode) ��غ��� */
void OPAx_CR_MOD_Set(OPA_Type* OPAx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = OPAx->CR;
	tmpreg &= ~(OPAx_CR_MOD_Msk);
	tmpreg |= (SetValue & OPAx_CR_MOD_Msk);
	OPAx->CR = tmpreg;
}

uint32_t OPAx_CR_MOD_Get(OPA_Type* OPAx)
{
	return (OPAx->CR & OPAx_CR_MOD_Msk);
}

/* OPA�͹��Ŀ��ƼĴ��� (OPA low power mode) ��غ��� */
void OPAx_CR_LPM_Set(OPA_Type* OPAx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = OPAx->CR;
	tmpreg &= ~(OPAx_CR_LPM_Msk);
	tmpreg |= (SetValue & OPAx_CR_LPM_Msk);
	OPAx->CR = tmpreg;
}

uint32_t OPAx_CR_LPM_Get(OPA_Type* OPAx)
{
	return (OPAx->CR & OPAx_CR_LPM_Msk);
}

/* OPAʹ�ܼĴ��� (OPA enable) ��غ��� */
void OPAx_CR_EN_Setable(OPA_Type* OPAx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		OPAx->CR |= (OPAx_CR_EN_Msk);
	}
	else
	{
		OPAx->CR &= ~(OPAx_CR_EN_Msk);
	}
}

FunState OPAx_CR_EN_Getable(OPA_Type* OPAx)
{
	if (OPAx->CR & (OPAx_CR_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* OPA��������У׼ʹ�� ��غ��� */
void OPAx_CALR_NCAL_EN_Setable(OPA_Type* OPAx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		OPAx->CALR |= (OPAx_CALR_NCAL_EN_Msk);
	}
	else
	{
		OPAx->CALR &= ~(OPAx_CALR_NCAL_EN_Msk);
	}
}

FunState OPAx_CALR_NCAL_EN_Getable(OPA_Type* OPAx)
{
	if (OPAx->CALR & (OPAx_CALR_NCAL_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* OPA�������У׼trim�źţ����λΪ����λ ��غ��� */
void OPAx_CALR_NCAL_Set(OPA_Type* OPAx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = OPAx->CALR;
	tmpreg &= ~(OPAx_CALR_NCAL_Msk);
	tmpreg |= (SetValue & OPAx_CALR_NCAL_Msk);
	OPAx->CALR = tmpreg;
}

uint32_t OPAx_CALR_NCAL_Get(OPA_Type* OPAx)
{
	return (OPAx->CALR & OPAx_CALR_NCAL_Msk);
}

/* OPA��������У׼ʹ�� ��غ��� */
void OPAx_CALR_PCAL_EN_Setable(OPA_Type* OPAx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		OPAx->CALR |= (OPAx_CALR_PCAL_EN_Msk);
	}
	else
	{
		OPAx->CALR &= ~(OPAx_CALR_PCAL_EN_Msk);
	}
}

FunState OPAx_CALR_PCAL_EN_Getable(OPA_Type* OPAx)
{
	if (OPAx->CALR & (OPAx_CALR_PCAL_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* OPA�������У׼trim�źţ����λΪ����λ ��غ��� */
void OPAx_CALR_PCAL_Set(OPA_Type* OPAx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = OPAx->CALR;
	tmpreg &= ~(OPAx_CALR_PCAL_Msk);
	tmpreg |= (SetValue & OPAx_CALR_PCAL_Msk);
	OPAx->CALR = tmpreg;
}

uint32_t OPAx_CALR_PCAL_Get(OPA_Type* OPAx)
{
	return (OPAx->CALR & OPAx_CALR_PCAL_Msk);
}

/* OPA�Ƚ���ģʽ����½����ж�ʹ��
(OPA comparator mode fall interrupt enable)
 ��غ��� */
void OPAx_IER_FIE_Setable(OPA_Type* OPAx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		OPAx->IER |= (OPAx_IER_FIE_Msk);
	}
	else
	{
		OPAx->IER &= ~(OPAx_IER_FIE_Msk);
	}
}

FunState OPAx_IER_FIE_Getable(OPA_Type* OPAx)
{
	if (OPAx->IER & (OPAx_IER_FIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* OPA�Ƚ���ģʽ����������ж�ʹ��
(OPA comparator mode rise interrupt enable)
 ��غ��� */
void OPAx_IER_RIE_Setable(OPA_Type* OPAx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		OPAx->IER |= (OPAx_IER_RIE_Msk);
	}
	else
	{
		OPAx->IER &= ~(OPAx_IER_RIE_Msk);
	}
}

FunState OPAx_IER_RIE_Getable(OPA_Type* OPAx)
{
	if (OPAx->IER & (OPAx_IER_RIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* OPA�Ƚ���ģʽ�����ƽ��ֻ�� 
(OPA comparator mode output)
 ��غ��� */
FlagStatus OPAx_ISR_OUT_Chk(OPA_Type* OPAx)
{
	if (OPAx->ISR & OPAx_ISR_OUT_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* OPA�Ƚ���ģʽ����½����жϱ�־��Ӳ����λ�����д1���� (OPA comparator mode fall interrupt flag) ��غ��� */
void OPAx_ISR_FIF_Clr(OPA_Type* OPAx)
{
	OPAx->ISR = OPAx_ISR_FIF_Msk;
}

FlagStatus OPAx_ISR_FIF_Chk(OPA_Type* OPAx)
{
	if (OPAx->ISR & OPAx_ISR_FIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* OPA�Ƚ���ģʽ����������жϱ�־��Ӳ����λ�����д1���� (OPA comparator mode rise interrupt flag) ��غ��� */
void OPAx_ISR_RIF_Clr(OPA_Type* OPAx)
{
	OPAx->ISR = OPAx_ISR_RIF_Msk;
}

FlagStatus OPAx_ISR_RIF_Chk(OPA_Type* OPAx)
{
	if (OPAx->ISR & OPAx_ISR_RIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}


void OPAx_Deinit(void)
{
   RCC_PRST_EN_Write(RSTKEY0);
   RCC_APBRST_CR2_OPARST_Setable(ENABLE); 
   RCC_APBRST_CR2_OPARST_Setable(DISABLE);
   RCC_PRST_EN_Write(RSTKEY1);
}
/******END OF FILE****/
