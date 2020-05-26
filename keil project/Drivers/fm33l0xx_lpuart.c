/**
  ******************************************************************************
  * @file    fm33l0xx_lpuart.c
  * @author  FM33L0 Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33l0xx_lpuart.h" 
#include "fm33l0xx_rcc.h" 

/** @addtogroup fm33l0_StdPeriph_Driver
  * @{
  */

/** @defgroup LPUART 
  * @brief LPUART driver modules
  * @{
  */ 
  
/* ͨ��״̬ ��غ��� */
FlagStatus LPUARTx_CSR_BUSY_Chk(LPUART_Type* LPUARTx)
{
	if (LPUARTx->CSR & LPUARTx_CSR_BUSY_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���ݽ��ջ����������� ��غ��� */
void LPUARTx_CSR_WKBYTECFG_Setable(LPUART_Type* LPUARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPUARTx->CSR |= (LPUARTx_CSR_WKBYTECFG_Msk);
	}
	else
	{
		LPUARTx->CSR &= ~(LPUARTx_CSR_WKBYTECFG_Msk);
	}
}

FunState LPUARTx_CSR_WKBYTECFG_Getable(LPUART_Type* LPUARTx)
{
	if (LPUARTx->CSR & (LPUARTx_CSR_WKBYTECFG_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �����ж��¼����� ��غ��� */
void LPUARTx_CSR_RXEV_Set(LPUART_Type* LPUARTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPUARTx->CSR;
	tmpreg &= ~(LPUARTx_CSR_RXEV_Msk);
	tmpreg |= (SetValue & LPUARTx_CSR_RXEV_Msk);
	LPUARTx->CSR = tmpreg;
}

uint32_t LPUARTx_CSR_RXEV_Get(LPUART_Type* LPUARTx)
{
	return (LPUARTx->CSR & LPUARTx_CSR_RXEV_Msk);
}

/* DMA��������ж�ʹ�� ��غ��� */
void LPUARTx_CSR_DMATXIFCFG_Setable(LPUART_Type* LPUARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPUARTx->CSR |= (LPUARTx_CSR_DMATXIFCFG_Msk);
	}
	else
	{
		LPUARTx->CSR &= ~(LPUARTx_CSR_DMATXIFCFG_Msk);
	}
}

FunState LPUARTx_CSR_DMATXIFCFG_Getable(LPUART_Type* LPUARTx)
{
	if (LPUARTx->CSR & (LPUARTx_CSR_DMATXIFCFG_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���ݷ��ͺͽ��յ�λ˳�� ��غ��� */
void LPUARTx_CSR_BITORD_Set(LPUART_Type* LPUARTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPUARTx->CSR;
	tmpreg &= ~(LPUARTx_CSR_BITORD_Msk);
	tmpreg |= (SetValue & LPUARTx_CSR_BITORD_Msk);
	LPUARTx->CSR = tmpreg;
}

uint32_t LPUARTx_CSR_BITORD_Get(LPUART_Type* LPUARTx)
{
	return (LPUARTx->CSR & LPUARTx_CSR_BITORD_Msk);
}

/* ����ʱֹͣλ���� ��غ��� */
void LPUARTx_CSR_STOPCFG_Set(LPUART_Type* LPUARTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPUARTx->CSR;
	tmpreg &= ~(LPUARTx_CSR_STOPCFG_Msk);
	tmpreg |= (SetValue & LPUARTx_CSR_STOPCFG_Msk);
	LPUARTx->CSR = tmpreg;
}

uint32_t LPUARTx_CSR_STOPCFG_Get(LPUART_Type* LPUARTx)
{
	return (LPUARTx->CSR & LPUARTx_CSR_STOPCFG_Msk);
}

/* ÿ֡���ݳ��� ��غ��� */
void LPUARTx_CSR_PDSEL_Set(LPUART_Type* LPUARTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPUARTx->CSR;
	tmpreg &= ~(LPUARTx_CSR_PDSEL_Msk);
	tmpreg |= (SetValue & LPUARTx_CSR_PDSEL_Msk);
	LPUARTx->CSR = tmpreg;
}

uint32_t LPUARTx_CSR_PDSEL_Get(LPUART_Type* LPUARTx)
{
	return (LPUARTx->CSR & LPUARTx_CSR_PDSEL_Msk);
}

/* У��λ���� ��غ��� */
void LPUARTx_CSR_PARITY_Set(LPUART_Type* LPUARTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPUARTx->CSR;
	tmpreg &= ~(LPUARTx_CSR_PARITY_Msk);
	tmpreg |= (SetValue & LPUARTx_CSR_PARITY_Msk);
	LPUARTx->CSR = tmpreg;
}

uint32_t LPUARTx_CSR_PARITY_Get(LPUART_Type* LPUARTx)
{
	return (LPUARTx->CSR & LPUARTx_CSR_PARITY_Msk);
}

/* �������ݼ��� ��غ��� */
void LPUARTx_CSR_RXPOL_Set(LPUART_Type* LPUARTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPUARTx->CSR;
	tmpreg &= ~(LPUARTx_CSR_RXPOL_Msk);
	tmpreg |= (SetValue & LPUARTx_CSR_RXPOL_Msk);
	LPUARTx->CSR = tmpreg;
}

uint32_t LPUARTx_CSR_RXPOL_Get(LPUART_Type* LPUARTx)
{
	return (LPUARTx->CSR & LPUARTx_CSR_RXPOL_Msk);
}

/* �������ݼ��� ��غ��� */
void LPUARTx_CSR_TXPOL_Set(LPUART_Type* LPUARTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPUARTx->CSR;
	tmpreg &= ~(LPUARTx_CSR_TXPOL_Msk);
	tmpreg |= (SetValue & LPUARTx_CSR_TXPOL_Msk);
	LPUARTx->CSR = tmpreg;
}

uint32_t LPUARTx_CSR_TXPOL_Get(LPUART_Type* LPUARTx)
{
	return (LPUARTx->CSR & LPUARTx_CSR_TXPOL_Msk);
}

/* ����ʹ�ܿ��� ��غ��� */
void LPUARTx_CSR_RXEN_Setable(LPUART_Type* LPUARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPUARTx->CSR |= (LPUARTx_CSR_RXEN_Msk);
    while(((LPUARTx->CSR)&LPUARTx_CSR_RXEN_Msk)==0);//�Ĵ�����ģ�鲻ͬ��������ȷ���Ѿ�д���Ĵ�������ֹд����bitʱ���ǵ�
	}
	else
	{
		LPUARTx->CSR &= ~(LPUARTx_CSR_RXEN_Msk);
    while(((LPUARTx->CSR)&LPUARTx_CSR_RXEN_Msk)!=0);
	}
}

FunState LPUARTx_CSR_RXEN_Getable(LPUART_Type* LPUARTx)
{
	if (LPUARTx->CSR & (LPUARTx_CSR_RXEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����ʹ�ܿ��� ��غ��� */
void LPUARTx_CSR_TXEN_Setable(LPUART_Type* LPUARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPUARTx->CSR |= (LPUARTx_CSR_TXEN_Msk);
    while(((LPUARTx->CSR)&LPUARTx_CSR_TXEN_Msk)==0); //�Ĵ�����ģ�鲻ͬ��������ȷ���Ѿ�д���Ĵ�������ֹд����bitʱ���ǵ�
	}
	else
	{
		LPUARTx->CSR &= ~(LPUARTx_CSR_TXEN_Msk);
    while(((LPUARTx->CSR)&LPUARTx_CSR_TXEN_Msk)!=0);
	}
}

FunState LPUARTx_CSR_TXEN_Getable(LPUART_Type* LPUARTx)
{
	if (LPUARTx->CSR & (LPUARTx_CSR_TXEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���ջ����¼��ж�ʹ�� ��غ��� */
void LPUARTx_IER_RXEV_IE_Setable(LPUART_Type* LPUARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPUARTx->IER |= (LPUARTx_IER_RXEV_IE_Msk);
	}
	else
	{
		LPUARTx->IER &= ~(LPUARTx_IER_RXEV_IE_Msk);
	}
}

FunState LPUARTx_IER_RXEV_IE_Getable(LPUART_Type* LPUARTx)
{
	if (LPUARTx->IER & (LPUARTx_IER_RXEV_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���մ����ж�ʹ�� ��غ��� */
void LPUARTx_IER_RXERR_IE_Setable(LPUART_Type* LPUARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPUARTx->IER |= (LPUARTx_IER_RXERR_IE_Msk);
	}
	else
	{
		LPUARTx->IER &= ~(LPUARTx_IER_RXERR_IE_Msk);
	}
}

FunState LPUARTx_IER_RXERR_IE_Getable(LPUART_Type* LPUARTx)
{
	if (LPUARTx->IER & (LPUARTx_IER_RXERR_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���ջ������ж�ʹ�� ��غ��� */
void LPUARTx_IER_RXBF_IE_Setable(LPUART_Type* LPUARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPUARTx->IER |= (LPUARTx_IER_RXBF_IE_Msk);
	}
	else
	{
		LPUARTx->IER &= ~(LPUARTx_IER_RXBF_IE_Msk);
	}
}

FunState LPUARTx_IER_RXBF_IE_Getable(LPUART_Type* LPUARTx)
{
	if (LPUARTx->IER & (LPUARTx_IER_RXBF_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���ͻ�����ж�ʹ�� ��غ��� */
void LPUARTx_IER_TXBE_IE_Setable(LPUART_Type* LPUARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPUARTx->IER |= (LPUARTx_IER_TXBE_IE_Msk);
	}
	else
	{
		LPUARTx->IER &= ~(LPUARTx_IER_TXBE_IE_Msk);
	}
}

FunState LPUARTx_IER_TXBE_IE_Getable(LPUART_Type* LPUARTx)
{
	if (LPUARTx->IER & (LPUARTx_IER_TXBE_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���ͻ�����ҷ�����λ�Ĵ������ж�ʹ�� ��غ��� */
void LPUARTx_IER_TXSE_IE_Setable(LPUART_Type* LPUARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPUARTx->IER |= (LPUARTx_IER_TXSE_IE_Msk);
	}
	else
	{
		LPUARTx->IER &= ~(LPUARTx_IER_TXSE_IE_Msk);
	}
}

FunState LPUARTx_IER_TXSE_IE_Getable(LPUART_Type* LPUARTx)
{
	if (LPUARTx->IER & (LPUARTx_IER_TXSE_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���ջ����¼��жϱ�־ ��غ��� */
void LPUARTx_ISR_RXEVF_Clr(LPUART_Type* LPUARTx)
{
	LPUARTx->ISR = LPUARTx_ISR_RXEVF_Msk;
}

FlagStatus LPUARTx_ISR_RXEVF_Chk(LPUART_Type* LPUARTx)
{
	if (LPUARTx->ISR & LPUARTx_ISR_RXEVF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���ͻ�����������־ ��غ��� */
void LPUARTx_ISR_TXOV_Clr(LPUART_Type* LPUARTx)
{
	LPUARTx->ISR = LPUARTx_ISR_TXOV_Msk;
}

FlagStatus LPUARTx_ISR_TXOV_Chk(LPUART_Type* LPUARTx)
{
	if (LPUARTx->ISR & LPUARTx_ISR_TXOV_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��żУ������жϱ�־ ��غ��� */
void LPUARTx_ISR_PERR_Clr(LPUART_Type* LPUARTx)
{
	LPUARTx->ISR = LPUARTx_ISR_PERR_Msk;
}

FlagStatus LPUARTx_ISR_PERR_Chk(LPUART_Type* LPUARTx)
{
	if (LPUARTx->ISR & LPUARTx_ISR_PERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ֡��ʽ�����жϱ�־ ��غ��� */
void LPUARTx_ISR_FERR_Clr(LPUART_Type* LPUARTx)
{
	LPUARTx->ISR = LPUARTx_ISR_FERR_Msk;
}

FlagStatus LPUARTx_ISR_FERR_Chk(LPUART_Type* LPUARTx)
{
	if (LPUARTx->ISR & LPUARTx_ISR_FERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���ջ�����������жϱ�־ ��غ��� */
void LPUARTx_ISR_OERR_Clr(LPUART_Type* LPUARTx)
{
	LPUARTx->ISR = LPUARTx_ISR_OERR_Msk;
}

FlagStatus LPUARTx_ISR_OERR_Chk(LPUART_Type* LPUARTx)
{
	if (LPUARTx->ISR & LPUARTx_ISR_OERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���ջ������жϱ�־ ��غ��� */
void LPUARTx_ISR_RXBF_Clr(LPUART_Type* LPUARTx)
{
	LPUARTx->ISR = LPUARTx_ISR_RXBF_Msk;
}

FlagStatus LPUARTx_ISR_RXBF_Chk(LPUART_Type* LPUARTx)
{
	if (LPUARTx->ISR & LPUARTx_ISR_RXBF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���ͻ�����жϱ�־ ��غ��� */
FlagStatus LPUARTx_ISR_TXBE_Chk(LPUART_Type* LPUARTx)
{
	if (LPUARTx->ISR & LPUARTx_ISR_TXBE_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���ͻ�����ҷ�����λ�Ĵ������жϱ�־ ��غ��� */
void LPUARTx_ISR_TXSE_Clr(LPUART_Type* LPUARTx)
{
	LPUARTx->ISR = LPUARTx_ISR_TXSE_Msk;
}

FlagStatus LPUARTx_ISR_TXSE_Chk(LPUART_Type* LPUARTx)
{
	if (LPUARTx->ISR & LPUARTx_ISR_TXSE_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ÿ��bit��λ����ƿ����ź� ��غ��� */
void LPUARTx_BMR_MCTL_Set(LPUART_Type* LPUARTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPUARTx->BMR;
	tmpreg &= ~(LPUARTx_BMR_MCTL_Msk);
	tmpreg |= (SetValue & LPUARTx_BMR_MCTL_Msk);
	LPUARTx->BMR = tmpreg;
}

uint32_t LPUARTx_BMR_MCTL_Get(LPUART_Type* LPUARTx)
{
	return (LPUARTx->BMR & LPUARTx_BMR_MCTL_Msk);
}

/* �����ʿ��� ��غ��� */
void LPUARTx_BMR_BAUD_Set(LPUART_Type* LPUARTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LPUARTx->BMR;
	tmpreg &= ~(LPUARTx_BMR_BAUD_Msk);
	tmpreg |= (SetValue & LPUARTx_BMR_BAUD_Msk);
	LPUARTx->BMR = tmpreg;
}

uint32_t LPUARTx_BMR_BAUD_Get(LPUART_Type* LPUARTx)
{
	return (LPUARTx->BMR & LPUARTx_BMR_BAUD_Msk);
}

/* �������ݻ��� ��غ��� */
uint32_t LPUARTx_RXBUF_Read(LPUART_Type* LPUARTx)
{
	return (LPUARTx->RXBUF & LPUARTx_RXBUF_RXBUF_Msk);
}

/* �������ݻ��� ��غ��� */
void LPUARTx_TXBUF_Write(LPUART_Type* LPUARTx, uint32_t SetValue)
{
	LPUARTx->TXBUF = (SetValue & LPUARTx_TXBUF_TXBUF_Msk);
}

/* ����ƥ��Ĵ��� ��غ��� */
void LPUARTx_DMR_Write(LPUART_Type* LPUARTx, uint32_t SetValue)
{
	LPUARTx->DMR = (SetValue & LPUARTx_DMR_MATD_Msk);
}

uint32_t LPUARTx_DMR_Read(LPUART_Type* LPUARTx)
{
	return (LPUARTx->DMR & LPUARTx_DMR_MATD_Msk);
}


void LPUARTx_Deinit(LPUART_Type* LPUARTx)
{
	if(LPUARTx==LPUART0)
  {
    RCC_PRST_EN_Write(RSTKEY0);
    RCC_APBRST_CR1_LPUART0RST_Setable(ENABLE);  
    RCC_APBRST_CR1_LPUART0RST_Setable(DISABLE);
    RCC_PRST_EN_Write(RSTKEY1);
  }
  if(LPUARTx==LPUART1)
  {
    RCC_PRST_EN_Write(RSTKEY0);
    RCC_APBRST_CR2_LPUART1RST_Setable(ENABLE);  
    RCC_APBRST_CR2_LPUART1RST_Setable(DISABLE);
    RCC_PRST_EN_Write(RSTKEY1);
  }
}

/*LPUART  ����������ʼ������ */
void LPUART_Init(LPUART_Type* LPUARTx,LPUART_InitTypeDef* para)
{
	LPUARTx_BMR_BAUD_Set(LPUARTx,para->BAUD);		//�����ʿ���
	LPUARTx_CSR_TXEN_Setable(LPUARTx,para->TXEN);		//����ʹ��
	LPUARTx_CSR_RXEN_Setable(LPUARTx,para->RXEN);		//����ʹ��
	LPUARTx_DMR_Write(LPUARTx,para->MATD);		//����ƥ��Ĵ���
	LPUARTx_BMR_MCTL_Set(LPUARTx,para->MCTL);				//���ƿ��ƼĴ���
	
	LPUARTx_CSR_STOPCFG_Set(LPUARTx,para->STOPCFG);				//ֹͣλ����
	LPUARTx_CSR_PDSEL_Set(LPUARTx,para->PDSEL);				//���ݳ���
	LPUARTx_CSR_PARITY_Set(LPUARTx,para->PARITY);			//У��λ����
  
	LPUARTx_CSR_WKBYTECFG_Setable(LPUARTx,para->WKBYTECFG);//���ջ�����������
	LPUARTx_CSR_RXEV_Set(LPUARTx,para->RXEV);		//�����ж��¼�����
  LPUARTx_IER_RXEV_IE_Setable(LPUARTx,para->RXEVIE);//�����¼������ж�
	LPUARTx_IER_TXSE_IE_Setable(LPUARTx,para->TXSEIE);		//��������ж�ʹ��
	LPUARTx_IER_TXBE_IE_Setable(LPUARTx,para->TXBEIE);		//����buffer���ж�ʹ��
	LPUARTx_IER_RXBF_IE_Setable(LPUARTx,para->RXBFIE);		//�����ж�ʹ��
  LPUARTx_IER_RXERR_IE_Setable(LPUARTx,para->RXERRIE);		//�����ж�ʹ��
	LPUARTx_CSR_TXPOL_Set(LPUARTx,para->TXPOL);		//���ݷ��ͼ���ȡ��ʹ��
	LPUARTx_CSR_RXPOL_Set(LPUARTx,para->RXPOL);		//���ݽ��ռ���ȡ������	
}

/*LPUART �򵥲�����ʼ������ */
void LPUART_SInit(LPUART_Type* LPUARTx,LPUART_SInitTypeDef* para)
{
	LPUART_InitTypeDef para2;	
		
	switch(para->BaudRate)
	{
		case 9600:
			para2.BAUD = LPUARTx_BMR_BAUD_9600;
			para2.MCTL = LPUARTx_MCTL_FOR9600;
			break;

		case 4800:
			para2.BAUD = LPUARTx_BMR_BAUD_4800;
			para2.MCTL = LPUARTx_MCTL_FOR4800;
			break;

		case 2400:
			para2.BAUD = LPUARTx_BMR_BAUD_2400;
			para2.MCTL = LPUARTx_MCTL_FOR2400;
			break;
		
		case 1200:
			para2.BAUD = LPUARTx_BMR_BAUD_1200;
			para2.MCTL = LPUARTx_MCTL_FOR1200;
			break;
		
		case 600:
			para2.BAUD = LPUARTx_BMR_BAUD_600;
			para2.MCTL = LPUARTx_MCTL_FOR600;
			break;
		
		case 300:
			para2.BAUD = LPUARTx_BMR_BAUD_300;
			para2.MCTL = LPUARTx_MCTL_FOR300;
			break;
		
		default:
			para2.BAUD = LPUARTx_BMR_BAUD_600;
			para2.MCTL = LPUARTx_MCTL_FOR9600;
			break;
	}

	para2.TXEN = DISABLE;
	para2.RXEN = DISABLE;
	para2.MATD = 0;
	
	//ֹͣλ����
	if(OneBit == para->StopBit)
	{
		para2.STOPCFG = LPUARTx_CSR_STOPCFG_1BIT;
	}
	else
	{
		para2.STOPCFG = LPUARTx_CSR_STOPCFG_2BIT;
	}
	//����λ����
	if(Eight8Bit == para->DataBit)
	{
		para2.PDSEL = LPUARTx_CSR_PDSEL_8BIT;
	}
  else if(Nine9Bit == para->DataBit)
	{
		para2.PDSEL = LPUARTx_CSR_PDSEL_9BIT;
	}
   else if(Seven7Bit == para->DataBit)
	{
		para2.PDSEL = LPUARTx_CSR_PDSEL_7BIT;
	}
	else
	{
		para2.PDSEL = LPUARTx_CSR_PDSEL_6BIT;
	}
	
	//У��λ
	if(NONE == para->ParityBit)
	{
		para2.PARITY = LPUARTx_CSR_PARITY_NONE;
	}
  else if( EVEN== para->ParityBit)
  {
    para2.PARITY = LPUARTx_CSR_PARITY_EVEN;
  }
	else
	{
    para2.PARITY = LPUARTx_CSR_PARITY_ODD;
	}
	
	para2.RXEV =LPUARTx_CSR_RXEV_1BYTE;		//�����ж��¼�����
  para2.WKBYTECFG = ENABLE;		//���ݻ�����������
	para2.TXSEIE = DISABLE;		//��������ж�ʹ��
	para2.TXBEIE = DISABLE;		//����buffer���ж�ʹ��
	para2.RXBFIE = DISABLE;		//�����ж�ʹ��
	para2.TXPOL = DISABLE;		//���ݷ��ͼ���ȡ��ʹ��
	para2.RXPOL = DISABLE;		//���ݽ��ռ���ȡ������
	para2.RXERRIE = DISABLE;		//�����ж�ʹ��	
	LPUART_Init(LPUARTx,&para2);
}
/******END OF FILE****/
