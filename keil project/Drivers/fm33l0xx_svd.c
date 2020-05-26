/**
  ******************************************************************************
  * @file    fm33l0xx_svd.c
  * @author  FM33L0 Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33l0xx_svd.h" 


/** @addtogroup fm33l0_StdPeriph_Driver
  * @{
  */

/** @defgroup SVD
  * @brief SVD driver modules
  * @{
  */ 
  
 /* SVD������ֵ����(SVD threshold level)
 ��غ��� */
void SVD_CFGR_LVL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SVD->CFGR;
	tmpreg &= ~(SVD_CFGR_LVL_Msk);
	tmpreg |= (SetValue & SVD_CFGR_LVL_Msk);
	SVD->CFGR = tmpreg;
}

uint32_t SVD_CFGR_LVL_Get(void)
{
	return (SVD->CFGR & SVD_CFGR_LVL_Msk);
}

/* �����˲�ʹ�ܣ�SVDMODE=1ʱ������1��(Digital Filter Enable) ��غ��� */
void SVD_CFGR_DFEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SVD->CFGR |= (SVD_CFGR_DFEN_Msk);
	}
	else
	{
		SVD->CFGR &= ~(SVD_CFGR_DFEN_Msk);
	}
}

FunState SVD_CFGR_DFEN_Getable(void)
{
	if (SVD->CFGR & (SVD_CFGR_DFEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SVD����ģʽѡ������ģʽ��Ҫ��λSVDEN�Ż�����SVD ��غ��� */
void SVD_CFGR_MOD_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SVD->CFGR;
	tmpreg &= ~(SVD_CFGR_MOD_Msk);
	tmpreg |= (SetValue & SVD_CFGR_MOD_Msk);
	SVD->CFGR = tmpreg;
}

uint32_t SVD_CFGR_MOD_Get(void)
{
	return (SVD->CFGR & SVD_CFGR_MOD_Msk);
}

/* SVD��Ъʹ�ܼ��(SVD Interval) ��غ��� */
void SVD_CFGR_ITVL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SVD->CFGR;
	tmpreg &= ~(SVD_CFGR_ITVL_Msk);
	tmpreg |= (SetValue & SVD_CFGR_ITVL_Msk);
	SVD->CFGR = tmpreg;
}

uint32_t SVD_CFGR_ITVL_Get(void)
{
	return (SVD->CFGR & SVD_CFGR_ITVL_Msk);
}

/* SVD����ʹ�ܣ�����д1 (SVD test enable) ��غ��� */
void SVD_CR_TE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SVD->CR |= (SVD_CR_TE_Msk);
	}
	else
	{
		SVD->CR &= ~(SVD_CR_TE_Msk);
	}
}

FunState SVD_CR_TE_Getable(void)
{
	if (SVD->CR & (SVD_CR_TE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SVS�ⲿ��Դ���ͨ�������ź�(SVS external monitor channel enable) ��غ��� */
void SVD_CR_SVSEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SVD->CR |= (SVD_CR_SVSEN_Msk);
	}
	else
	{
		SVD->CR &= ~(SVD_CR_SVSEN_Msk);
	}
}

FunState SVD_CR_SVSEN_Getable(void)
{
	if (SVD->CR & (SVD_CR_SVSEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SVDʹ�� (SVD enable) ��غ��� */
void SVD_CR_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SVD->CR |= (SVD_CR_EN_Msk);
	}
	else
	{
		SVD->CR &= ~(SVD_CR_EN_Msk);
	}
}

FunState SVD_CR_EN_Getable(void)
{
	if (SVD->CR & (SVD_CR_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��Դ�����ж�ʹ��(Power Fall interrupt enable) ��غ��� */
void SVD_IER_PFIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SVD->IER |= (SVD_IER_PFIE_Msk);
	}
	else
	{
		SVD->IER &= ~(SVD_IER_PFIE_Msk);
	}
}

FunState SVD_IER_PFIE_Getable(void)
{
	if (SVD->IER & (SVD_IER_PFIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��Դ�ָ��ж�ʹ��(Power Rise interrupt enable) ��غ��� */
void SVD_IER_PRIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SVD->IER |= (SVD_IER_PRIE_Msk);
	}
	else
	{
		SVD->IER &= ~(SVD_IER_PRIE_Msk);
	}
}

FunState SVD_IER_PRIE_Getable(void)
{
	if (SVD->IER & (SVD_IER_PRIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SVD��Դ������ (SVD output) ��غ��� */
FlagStatus SVD_ISR_SVDO_Chk(void)
{
	if (SVD->ISR & SVD_ISR_SVDO_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* SVD��������źţ����ֵ�·�����SVD״̬ ��غ��� */
FlagStatus SVD_ISR_SVDR_Chk(void)
{
	if (SVD->ISR & SVD_ISR_SVDR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��Դ�����жϱ�־ ��غ��� */
void SVD_ISR_PFF_Clr(void)
{
	SVD->ISR = SVD_ISR_PFF_Msk;
}

FlagStatus SVD_ISR_PFF_Chk(void)
{
	if (SVD->ISR & SVD_ISR_PFF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��Դ�ָ��жϱ�־ ��غ��� */
void SVD_ISR_PRF_Clr(void)
{
	SVD->ISR = SVD_ISR_PRF_Msk;
}

FlagStatus SVD_ISR_PRF_Chk(void)
{
	if (SVD->ISR & SVD_ISR_PRF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 0.85V��׼����ʹ���ź� (0.85V reference enable) ��غ��� */
void SVD_VSR_V0P85EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SVD->VSR |= (SVD_VSR_V0P85EN_Msk);
	}
	else
	{
		SVD->VSR &= ~(SVD_VSR_V0P85EN_Msk);
	}
}

FunState SVD_VSR_V0P85EN_Getable(void)
{
	if (SVD->VSR & (SVD_VSR_V0P85EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 0.8V��׼����ʹ���ź� (0.8V reference enable) ��غ��� */
void SVD_VSR_V0P8EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SVD->VSR |= (SVD_VSR_V0P8EN_Msk);
	}
	else
	{
		SVD->VSR &= ~(SVD_VSR_V0P8EN_Msk);
	}
}

FunState SVD_VSR_V0P8EN_Getable(void)
{
	if (SVD->VSR & (SVD_VSR_V0P8EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 0.75V��׼����ʹ���ź� (0.75V reference enable) ��غ��� */
void SVD_VSR_V0P75EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SVD->VSR |= (SVD_VSR_V0P75EN_Msk);
	}
	else
	{
		SVD->VSR &= ~(SVD_VSR_V0P75EN_Msk);
	}
}

FunState SVD_VSR_V0P75EN_Getable(void)
{
	if (SVD->VSR & (SVD_VSR_V0P75EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}


void SVD_Deinit(void)
{
	//SVD->CFGR = 0x00000008;
	//SVD->CR = 0x00000000;
	//SVD->IER = 0x00000000;
	//SVD->ISR = 0x00000000;
	//SVD->VSR = 0x00000004;
} 
/*********************************
SVD��ʼ�����ú��� 
���ܣ�SVD��ʼ������
����: ANAC_SVD_InitTypeDef* para���ṹ�庯�������ù���ģʽ����ֵ�������˲��ȹ���
���: ��
*********************************/
void SVD_Init(ANAC_SVD_InitTypeDef* para)
{
	SVD_CFGR_MOD_Set(para->SVDMOD);	//SVD����ģʽѡ��
	SVD_CFGR_ITVL_Set(para->SVDITVL);	//SVD��Ъʹ�ܼ������
	SVD_CFGR_LVL_Set(para->SVDLVL);	//SVD������ֵ����
	SVD_CFGR_DFEN_Setable(para->DFEN);	//SVD�����˲����ã�SVDMODE=1ʱ������1��
	SVD_IER_PFIE_Setable(para->PFIE);	//SVD��Դ�����ж�����
	SVD_IER_PRIE_Setable(para->PRIE);	//SVD��Դ�ָ��ж�����
	SVD_CR_TE_Setable(DISABLE);	//�رղ��Թ���
	SVD_CR_EN_Setable(para->SVDEN);	//SVDʹ������
}
/******END OF FILE****/
