/**
  ******************************************************************************
  * @file    fm33l0xx_dma.c
  * @author  FM33l0 Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33l0xx_dma.h" 
#include "fm33l0xx_rcc.h" 

/** @addtogroup fm33l0_StdPeriph_Driver
  * @{
  */

/** @defgroup DMA 
  * @brief DMA driver modules
  * @{
  */ 
  

/* DMAȫ��ʹ�� ��غ��� */
void DMA_GCR_DMAEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		DMA->GCR |= (DMA_GCR_DMAEN_Msk);
	}
	else
	{
		DMA->GCR &= ~(DMA_GCR_DMAEN_Msk);
	}
}

FunState DMA_GCR_DMAEN_Getable(void)
{
	if (DMA->GCR & (DMA_GCR_DMAEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* DMAͨ���������ݳ��ȿ��� ��غ��� */
void DMA_CHx_CR_TSIZE_Set(DMA_CH_Type CHx, uint32_t SetValue)
{
    uint32_t *pREG;
	uint32_t tmpreg;
    
    pREG = (uint32_t *)(DMA_BASE + 4 + CHx * 8);
    
    SetValue <<= DMA_CHx_CR_TSIZE_Pos;
	tmpreg = *pREG;
	tmpreg &= ~(DMA_CHx_CR_TSIZE_Msk);
	tmpreg |= (SetValue & DMA_CHx_CR_TSIZE_Msk);
	*pREG = tmpreg;
}

uint32_t DMA_CHx_CR_TSIZE_Get(DMA_CH_Type CHx)
{
    uint32_t *pREG;
    uint32_t tmpsize;
    
    pREG = (uint32_t *)(DMA_BASE + 4 + CHx * 8);
    tmpsize = (*pREG & DMA_CHx_CR_TSIZE_Msk);
    tmpsize >>= DMA_CHx_CR_TSIZE_Pos;
    
	return tmpsize;
}

/* ͨ�����ȼ� ��غ��� */
void DMA_CHx_CR_PRI_Set(DMA_CH_Type CHx, uint32_t SetValue)
{
	uint32_t *pREG;
	uint32_t tmpreg;
    
    pREG = (uint32_t *)(DMA_BASE + 4 + CHx * 8);
	tmpreg = *pREG;
	tmpreg &= ~(DMA_CHx_CR_PRI_Msk);
	tmpreg |= (SetValue & DMA_CHx_CR_PRI_Msk);
	*pREG = tmpreg;
}

uint32_t DMA_CHx_CR_PRI_Get(DMA_CH_Type CHx)
{
    uint32_t *pREG;
    
    pREG = (uint32_t *)(DMA_BASE + 4 + CHx * 8);
	return (*pREG & DMA_CHx_CR_PRI_Msk);
}

/* RAM��ַ������� ��غ��� */
void DMA_CHx_CR_INC_Set(DMA_CH_Type CHx, uint32_t SetValue)
{
	uint32_t *pREG;
	uint32_t tmpreg;
    
    pREG = (uint32_t *)(DMA_BASE + 4 + CHx * 8);
	tmpreg = *pREG;
	tmpreg &= ~(DMA_CHx_CR_INC_Msk);
	tmpreg |= (SetValue & DMA_CHx_CR_INC_Msk);
	*pREG = tmpreg;
}

uint32_t DMA_CHx_CR_INC_Get(DMA_CH_Type CHx)
{
    uint32_t *pREG;
    
    pREG = (uint32_t *)(DMA_BASE + 4 + CHx * 8);
	return (*pREG & DMA_CHx_CR_INC_Msk);
}

/* ͨ���������� ��غ��� */
void DMA_CHx_CR_SSEL_Set(DMA_CH_Type CHx, uint32_t SetValue)
{
    uint32_t *pREG;
	uint32_t tmpreg;
    
    pREG = (uint32_t *)(DMA_BASE + 4 + CHx * 8);
    
	tmpreg = *pREG;
	tmpreg &= ~(DMA_CHx_CR_SSEL_Msk);
	tmpreg |= (SetValue & DMA_CHx_CR_SSEL_Msk);
	*pREG = tmpreg;
}

uint32_t DMA_CHx_CR_SSEL_Get(DMA_CH_Type CHx)
{
    uint32_t *pREG;
    
    pREG = (uint32_t *)(DMA_BASE + 4 + CHx * 8);
	return (*pREG & DMA_CHx_CR_SSEL_Msk);
}

/* ͨ�����䷽�� ��غ��� */
void DMA_CHx_CR_DIR_Set(DMA_CH_Type CHx, uint32_t SetValue)
{
    uint32_t *pREG;
	uint32_t tmpreg;
    
    pREG = (uint32_t *)(DMA_BASE + 4 + CHx * 8);
	tmpreg = *pREG;
	tmpreg &= ~(DMA_CHx_CR_DIR_Msk);
	tmpreg |= (SetValue & DMA_CHx_CR_DIR_Msk);
	*pREG = tmpreg;
}

uint32_t DMA_CHx_CR_DIR_Get(DMA_CH_Type CHx)
{
    uint32_t *pREG;
    
    pREG = (uint32_t *)(DMA_BASE + 4 + CHx * 8);
	return (*pREG & DMA_CHx_CR_DIR_Msk);
}

/* ����������� ��غ��� */
void DMA_CHx_CR_BDW_Set(DMA_CH_Type CHx, uint32_t SetValue)
{
    uint32_t *pREG;
    uint32_t tmpreg;
    
    pREG = (uint32_t *)(DMA_BASE + 4 + CHx * 8);
	tmpreg = *pREG;
	tmpreg &= ~(DMA_CHx_CR_BDW_Msk);
	tmpreg |= (SetValue & DMA_CHx_CR_BDW_Msk);
	*pREG = tmpreg;
}

uint32_t DMA_CHx_CR_BDW_Get(DMA_CH_Type CHx)
{
    uint32_t *pREG;
    pREG = (uint32_t *)(DMA_BASE + 4 + CHx * 8);
    
    return (*pREG & DMA_CHx_CR_BDW_Msk);
}

/* ѭ������ģʽ ��غ��� */
void DMA_CHx_CR_CIRC_Setable(DMA_CH_Type CHx, FunState NewState)
{
    uint32_t *pREG;
    pREG = (uint32_t *)(DMA_BASE + 4 + CHx * 8);
    
	if (NewState == ENABLE)
	{
        *pREG |= (DMA_CHx_CR_CIRC_Msk);
	}
	else
	{
		*pREG &= ~(DMA_CHx_CR_CIRC_Msk);
	}
}

FunState DMAx_CHx_CR_CIRC_Getable(DMA_CH_Type CHx)
{
    uint32_t *pREG;
    pREG = (uint32_t *)(DMA_BASE + 4 + CHx * 8);
    
	if (*pREG & (DMA_CHx_CR_CIRC_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��������ж� ��غ��� */
void DMA_CHx_CR_FTIE_Setable(DMA_CH_Type CHx, FunState NewState)
{
    uint32_t *pREG;
    pREG = (uint32_t *)(DMA_BASE + 4 + CHx * 8);
    
	if (NewState == ENABLE)
	{
		*pREG |= (DMA_CHx_CR_FTIE_Msk);
	}
	else
	{
		*pREG &= ~(DMA_CHx_CR_FTIE_Msk);
	}
}

FunState DMA_CHx_CR_FTIE_Getable(DMA_CH_Type CHx)
{
    uint32_t *pREG;
    pREG = (uint32_t *)(DMA_BASE + 4 + CHx * 8);
    
	if (*pREG & (DMA_CHx_CR_FTIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��̴����ж� ��غ��� */
void DMA_CHx_CR_HTIE_Setable(DMA_CH_Type CHx, FunState NewState)
{
    uint32_t *pREG;
    pREG = (uint32_t *)(DMA_BASE + 4 + CHx * 8);
    
	if (NewState == ENABLE)
	{
		*pREG |= (DMA_CHx_CR_HTIE_Msk);
	}
	else
	{
		*pREG &= ~(DMA_CHx_CR_HTIE_Msk);
	}
}

FunState DMA_CHx_CR_HTIE_Getable(DMA_CH_Type CHx)
{
    uint32_t *pREG;
    pREG = (uint32_t *)(DMA_BASE + 4 + CHx * 8);
    
	if (*pREG & (DMA_CHx_CR_HTIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ͨ������ ��غ��� */
void DMA_CHx_CR_EN_Setable(DMA_CH_Type CHx, FunState NewState)
{
    uint32_t *pREG;
    pREG = (uint32_t *)(DMA_BASE + 4 + CHx * 8);
    
	if (NewState == ENABLE)
	{
		*pREG |= (DMA_CHx_CR_EN_Msk);
	}
	else
	{
		*pREG &= ~(DMA_CHx_CR_EN_Msk);
	}
}

FunState DMA_CHx_CR_EN_Getable(DMA_CH_Type CHx)
{
    uint32_t *pREG;
    pREG = (uint32_t *)(DMA_BASE + 4 + CHx * 8);
    
	if (*pREG & (DMA_CHx_CR_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �������ݳ��� ��غ��� */
void DMA_CH7_CR_TSIZE_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
    
    SetValue <<= DMA_CH7_CR_TSIZE_Pos;
	tmpreg = DMA->CH7_CR;
	tmpreg &= ~(DMA_CH7_CR_TSIZE_Msk);
	tmpreg |= (SetValue & DMA_CH7_CR_TSIZE_Msk);
	DMA->CH7_CR = tmpreg;
}

uint32_t DMA_CH7_CR_TSIZE_Get(void)
{
    uint32_t tmpsize;
    
    tmpsize = DMA->CH7_CR & DMA_CH7_CR_TSIZE_Msk;
    tmpsize >>= DMA_CH7_CR_TSIZE_Pos;
	return tmpsize;
}

/* ���ȼ����� ��غ��� */
void DMA_CH7_CR_PRI_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
    
	tmpreg = DMA->CH7_CR;
	tmpreg &= ~(DMA_CH7_CR_PRI_Msk);
	tmpreg |= (SetValue & DMA_CH7_CR_PRI_Msk);
	DMA->CH7_CR = tmpreg;
}

uint32_t DMA_CH7_CR_PRI_Get(void)
{
	return (DMA->CH7_CR & DMA_CH7_CR_PRI_Msk);
}

/* ͨ���������� ��غ��� */
void DMA_CH7_CR_SSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
    
	tmpreg = DMA->CH7_CR;
	tmpreg &= ~(DMA_CH7_CR_SSEL_Msk);
	tmpreg |= (SetValue & DMA_CH7_CR_SSEL_Msk);
	DMA->CH7_CR = tmpreg;
}

uint32_t DMA_CH7_CR_SSEL_Get(void)
{
	return (DMA->CH7_CR & DMA_CH7_CR_SSEL_Msk);
}

/* ��������ж� ��غ��� */
void DMA_CH7_CR_FTIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		DMA->CH7_CR |= (DMA_CH7_CR_FTIE_Msk);
	}
	else
	{
		DMA->CH7_CR &= ~(DMA_CH7_CR_FTIE_Msk);
	}
}

FunState DMA_CH7_CR_FTIE_Getable(void)
{
	if (DMA->CH7_CR & (DMA_CH7_CR_FTIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��̴����ж� ��غ��� */
void DMA_CH7_CR_HTIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		DMA->CH7_CR |= (DMA_CH7_CR_HTIE_Msk);
	}
	else
	{
		DMA->CH7_CR &= ~(DMA_CH7_CR_HTIE_Msk);
	}
}

FunState DMA_CH7_CR_HTIE_Getable(void)
{
	if (DMA->CH7_CR & (DMA_CH7_CR_HTIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ͨ������ ��غ��� */
void DMA_CH7_CR_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		DMA->CH7_CR |= (DMA_CH7_CR_EN_Msk);
	}
	else
	{
		DMA->CH7_CR &= ~(DMA_CH7_CR_EN_Msk);
	}
}

FunState DMA_CH7_CR_EN_Getable(void)
{
	if (DMA->CH7_CR & (DMA_CH7_CR_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ͨ��0-6�洢��ָ���ַ ��غ��� */
void DMA_CHx_MAD_MEMAD_Write(DMA_CH_Type CHx, uint32_t SetValue)
{
    uint32_t *pREG;
    
    pREG = (uint32_t *)(DMA_BASE + 8 + CHx * 8);
	*pREG = SetValue & DMA_CHx_MAD_MEMAD_Msk;
}

/* ͨ��7 FLASHָ���ַ ��غ��� */
void DMA_CH7_FLSAD_Write(uint32_t SetValue)
{
	DMA->CH7_FLSAD = (SetValue & DMAx_CH7_FLSAD_FLSAD_Msk) >> 2; //CH7��flash��ַ���ֵ�ַ���˴���������2bit�����Ա�ʹ��ʱ����ʹ����ͨ��ַ
}

/* ͨ��7 RAMָ���ַ ��غ��� */
void DMA_CH7_RAMAD_Write(uint32_t SetValue)
{
	DMA->CH7_RAMAD = (SetValue & DMAx_CH7_RAMAD_RAMAD_Msk) >> 2; //CH7��RAM��ַ���ֵ�ַ���˴���������2bit�����Ա�ʹ��ʱ����ʹ����ͨ��ַ
}

/* ��������ж� ��غ��� */
void DMA_ISR_CHFT_Clr(DMA_CH_Type CHx)
{
	DMA->ISR = (0x100U << CHx);
}

FlagStatus DMA_ISR_CHFT_Chk(DMA_CH_Type CHx)
{
	if (DMA->ISR & (0x100U << CHx))
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �������ж� ��غ��� */
void DMA_ISR_CHHT_Clr(DMA_CH_Type CHx)
{
	DMA->ISR = (0x1U << CHx);
}

FlagStatus DMA_ISR_CHHT_Chk(DMA_CH_Type CHx)
{
	if (DMA->ISR & (0x1U << CHx))
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void DMA_Deinit(void)
{    
    RCC_PRST_EN_Write(RSTKEY0);
    RCC_AHBRST_CR_DMARST_Setable(ENABLE);  
    RCC_AHBRST_CR_DMARST_Setable(DISABLE);   
    RCC_PRST_EN_Write(RSTKEY1);
}

void DMA_Init(DMA_InitTypeDef* para)
{
    if( DMA_CH7 == para->CHx )
	{
        DMA_CH7_FLSAD_Write(para->CH7FLSAD);    //ͨ��FLASHָ���ַ�������ͨ��7������
		DMA_CH7_RAMAD_Write(para->CHxRAMAD);    //CH0~CH7ͨ��RAMָ���ַ
        DMA_CH7_CR_TSIZE_Set(para->CHxTSIZE);	//ͨ�����䳤��
        DMA_CH7_CR_PRI_Set(para->CHxPRI);		//ͨ�����ȼ�
        DMA_CH7_CR_SSEL_Set(para->CHxSSEL);     //CH7���䷽ʽѡ��
        DMA_CH7_CR_FTIE_Setable(para->CHxFTIE);	//ͨ����������ж�ʹ��
        DMA_CH7_CR_HTIE_Setable(para->CHxHTIE);	//ͨ���������ж�ʹ��
        DMA_CH7_CR_EN_Setable(para->CHxEN);		//ͨ��ʹ��
	}
	else
	{
		DMA_CHx_MAD_MEMAD_Write(para->CHx, para->CHxRAMAD);//CH0~CH7ͨ��RAMָ���ַ
        DMA_CHx_CR_TSIZE_Set(para->CHx, para->CHxTSIZE);	//ͨ�����䳤��
        DMA_CHx_CR_PRI_Set(para->CHx, para->CHxPRI);		//ͨ�����ȼ�
        DMA_CHx_CR_INC_Set(para->CHx, para->CHxINC);		//ͨ����ַ��������
        DMA_CHx_CR_SSEL_Set(para->CHx, para->CHxSSEL);		//CH0~CH6����ͨ��ѡ��,CH7���䷽ʽѡ��
        DMA_CHx_CR_DIR_Set(para->CHx, para->CHxDIR);        //CH0~CH6����ͨ�������ݴ��䷽������
        DMA_CHx_CR_FTIE_Setable(para->CHx, para->CHxFTIE);	//ͨ����������ж�ʹ��
        DMA_CHx_CR_HTIE_Setable(para->CHx, para->CHxHTIE);	//ͨ���������ж�ʹ��
        DMA_CHx_CR_EN_Setable(para->CHx, para->CHxEN);		//ͨ��ʹ��
	}
}
  
/******END OF FILE****/
