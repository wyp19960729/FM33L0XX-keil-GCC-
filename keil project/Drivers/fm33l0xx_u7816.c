/**
  ******************************************************************************
  * @file    fm33l0xx_u7816.c
  * @author  FM33L0 Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33l0xx_u7816.h" 
#include "fm33l0xx_rcc.h" 


/** @addtogroup fm33l0_StdPeriph_Driver
  * @{
  */

/** @defgroup U7816 
  * @brief U7816 driver modules
  * @{
  */ 
  
/* U7816ͨ������ʹ�ܿ��� ��غ��� */
void U7816_CR_TXEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816->CR |= (U7816_CR_TXEN_Msk);
	}
	else
	{
		U7816->CR &= ~(U7816_CR_TXEN_Msk);
	}
}

FunState U7816_CR_TXEN_Getable(void)
{
	if (U7816->CR & (U7816_CR_TXEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* U7816ͨ������ʹ�ܿ��� ��غ��� */
void U7816_CR_RXEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816->CR |= (U7816_CR_RXEN_Msk);
	}
	else
	{
		U7816->CR &= ~(U7816_CR_RXEN_Msk);
	}
}

FunState U7816_CR_RXEN_Getable(void)
{
	if (U7816->CR & (U7816_CR_RXEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* U7816ʱ��CLK���ʹ�ܿ��� ��غ��� */
void U7816_CR_CKOEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816->CR |= (U7816_CR_CKOEN_Msk);
	}
	else
	{
		U7816->CR &= ~(U7816_CR_CKOEN_Msk);
	}
}

FunState U7816_CR_CKOEN_Getable(void)
{
	if (U7816->CR & (U7816_CR_CKOEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* U7816ͨ�����ݷ���ǿ���������Զ���Ч���� ��غ��� */
void U7816_CR_HPUAT_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816->CR |= (U7816_CR_HPUAT_Msk);
	}
	else
	{
		U7816->CR &= ~(U7816_CR_HPUAT_Msk);
	}
}

FunState U7816_CR_HPUAT_Getable(void)
{
	if (U7816->CR & (U7816_CR_HPUAT_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* U7816ͨ��ǿ����ʹ�ܿ��� ��غ��� */
void U7816_CR_HPUEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816->CR |= (U7816_CR_HPUEN_Msk);
	}
	else
	{
		U7816->CR &= ~(U7816_CR_HPUEN_Msk);
	}
}

FunState U7816_CR_HPUEN_Getable(void)
{
	if (U7816->CR & (U7816_CR_HPUEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* GUARD TIME ���ͳ��ȿ��� ��غ��� */
void U7816_FFR_SFREN_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = U7816->FFR;
	tmpreg &= ~(U7816_FFR_SFREN_Msk);
	tmpreg |= (SetValue & U7816_FFR_SFREN_Msk);
	U7816->FFR = tmpreg;
}

uint32_t U7816_FFR_SFREN_Get(void)
{
	return (U7816->FFR & U7816_FFR_SFREN_Msk);
}

/* ERROR SIGNAL���ѡ�� ��غ��� */
void U7816_FFR_ERSW_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = U7816->FFR;
	tmpreg &= ~(U7816_FFR_ERSW_Msk);
	tmpreg |= (SetValue & U7816_FFR_ERSW_Msk);
	U7816->FFR = tmpreg;
}

uint32_t U7816_FFR_ERSW_Get(void)
{
	return (U7816->FFR & U7816_FFR_ERSW_Msk);
}

/* ERROR SIGNAL��GUARDTIME���ѡ�񣨽��ڷ���ʱ��Ч�� ��غ��� */
void U7816_FFR_ERSGD_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = U7816->FFR;
	tmpreg &= ~(U7816_FFR_ERSGD_Msk);
	tmpreg |= (SetValue & U7816_FFR_ERSGD_Msk);
	U7816->FFR = tmpreg;
}

uint32_t U7816_FFR_ERSGD_Get(void)
{
	return (U7816->FFR & U7816_FFR_ERSGD_Msk);
}

/* BGT��block guard time������ ��غ��� */
void U7816_FFR_BGTEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816->FFR |= (U7816_FFR_BGTEN_Msk);
	}
	else
	{
		U7816->FFR &= ~(U7816_FFR_BGTEN_Msk);
	}
}

FunState U7816_FFR_BGTEN_Getable(void)
{
	if (U7816->FFR & (U7816_FFR_BGTEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���ƽ���������żУ�����ʱ�Զ��ط����� ��غ��� */
void U7816_FFR_REP_T_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = U7816->FFR;
	tmpreg &= ~(U7816_FFR_REP_T_Msk);
	tmpreg |= (SetValue & U7816_FFR_REP_T_Msk);
	U7816->FFR = tmpreg;
}

uint32_t U7816_FFR_REP_T_Get(void)
{
	return (U7816->FFR & U7816_FFR_REP_T_Msk);
}

/* ��żУ������ѡ�� ��غ��� */
void U7816_FFR_PAR_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = U7816->FFR;
	tmpreg &= ~(U7816_FFR_PAR_Msk);
	tmpreg |= (SetValue & U7816_FFR_PAR_Msk);
	U7816->FFR = tmpreg;
}

uint32_t U7816_FFR_PAR_Get(void)
{
	return (U7816->FFR & U7816_FFR_PAR_Msk);
}

/* Guard Time���ȿ���λ������ʱ�ϸ���Э��2etu�� ��غ��� */
void U7816_FFR_RFREN_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = U7816->FFR;
	tmpreg &= ~(U7816_FFR_RFREN_Msk);
	tmpreg |= (SetValue & U7816_FFR_RFREN_Msk);
	U7816->FFR = tmpreg;
}

uint32_t U7816_FFR_RFREN_Get(void)
{
	return (U7816->FFR & U7816_FFR_RFREN_Msk);
}

/* ������������żУ���Ĵ���ʽѡ�� ��غ��� */
void U7816_FFR_TREPEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816->FFR |= (U7816_FFR_TREPEN_Msk);
	}
	else
	{
		U7816->FFR &= ~(U7816_FFR_TREPEN_Msk);
	}
}

FunState U7816_FFR_TREPEN_Getable(void)
{
	if (U7816->FFR & (U7816_FFR_TREPEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����������żУ���Ĵ���ʽѡ�� ��غ��� */
void U7816_FFR_RREPEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816->FFR |= (U7816_FFR_RREPEN_Msk);
	}
	else
	{
		U7816->FFR &= ~(U7816_FFR_RREPEN_Msk);
	}
}

FunState U7816_FFR_RREPEN_Getable(void)
{
	if (U7816->FFR & (U7816_FFR_RREPEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ������������ʹ�� ��غ��� */
void U7816_FFR_DICONV_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816->FFR |= (U7816_FFR_DICONV_Msk);
	}
	else
	{
		U7816->FFR &= ~(U7816_FFR_DICONV_Msk);
	}
}

FunState U7816_FFR_DICONV_Getable(void)
{
	if (U7816->FFR & (U7816_FFR_DICONV_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����ʱ�����EGTʱ�䣨��ETUΪ��λ�� ��غ��� */
void U7816_EGTR_Write(uint32_t SetValue)
{
	U7816->EGTR = (SetValue & U7816_EGTR_TXEGT_Msk);
}

uint32_t U7816_EGTR_Read(void)
{
	return (U7816->EGTR & U7816_EGTR_TXEGT_Msk);
}

/* U7816ʱ�������Ƶ���ƼĴ��� ��غ��� */
void U7816_PSC_Write(uint32_t SetValue)
{
	U7816->PSC = (SetValue & U7816_PSC_CLKDIV_Msk);
}

uint32_t U7816_PSC_Read(void)
{
	return (U7816->PSC & U7816_PSC_CLKDIV_Msk);
}

/* U7816Ԥ��Ƶ���ƼĴ���������7816ͨ�ŷ�Ƶ�ȣ������ʣ� ��غ��� */
void U7816_BGR_Write(uint32_t SetValue)
{
	U7816->BGR = (SetValue & U7816_BGR_PDIV_Msk);
}

uint32_t U7816_BGR_Read(void)
{
	return (U7816->BGR & U7816_BGR_PDIV_Msk);
}

/* U7816���ݽ��ջ���Ĵ��� ��غ��� */
uint32_t U7816_RXBUF_Read(void)
{
	return (U7816->RXBUF & U7816_RXBUF_RXBUF_Msk);
}

/* U7816���ݷ��ͻ���Ĵ��� ��غ��� */
void U7816_TXBUF_Write(uint32_t SetValue)
{
	U7816->TXBUF = (SetValue & U7816_TXBUF_TXBUF_Msk);
}

/* ���ݽ����ж�ʹ��λ����ӦRX_FLAG�жϱ�־λ ��غ��� */
void U7816_IER_RXIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816->IER |= (U7816_IER_RXIE_Msk);
	}
	else
	{
		U7816->IER &= ~(U7816_IER_RXIE_Msk);
	}
}

FunState U7816_IER_RXIE_Getable(void)
{
	if (U7816->IER & (U7816_IER_RXIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���ݷ����ж�ʹ��λ����ӦTX_FLAG�жϱ�־λ ��غ��� */
void U7816_IER_TXIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816->IER |= (U7816_IER_TXIE_Msk);
	}
	else
	{
		U7816->IER &= ~(U7816_IER_TXIE_Msk);
	}
}

FunState U7816_IER_TXIE_Getable(void)
{
	if (U7816->IER & (U7816_IER_TXIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��·״̬�ж�ʹ��λ����ӦERROR_FLAG�жϱ�־λ ��غ��� */
void U7816_IER_LSIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816->IER |= (U7816_IER_LSIE_Msk);
	}
	else
	{
		U7816->IER &= ~(U7816_IER_LSIE_Msk);
	}
}

FunState U7816_IER_LSIE_Getable(void)
{
	if (U7816->IER & (U7816_IER_LSIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* U7816�ӿڷ����˴����źţ����ڵȴ��Է��ط�����.״̬�����뷢�ʹ����ź�״̬ʱ��λ���յ�������ʼλ���߽��뷢��״̬ʱӲ������;
 ��غ��� */
FlagStatus U7816_ISR_WAIT_RPT_Chk(void)
{
	if (U7816->ISR & U7816_ISR_WAIT_RPT_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��������æ��־ ��غ��� */
FlagStatus U7816_ISR_TXBUSY_Chk(void)
{
	if (U7816->ISR & U7816_ISR_TXBUSY_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��������æ��־ ��غ��� */
FlagStatus U7816_ISR_RXBUSY_Chk(void)
{
	if (U7816->ISR & U7816_ISR_RXBUSY_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ����������żУ������־λ ��غ��� */
void U7816_ISR_TPARERR_Clr(void)
{
	U7816->ISR = U7816_ISR_TPARERR_Msk;
}

FlagStatus U7816_ISR_TPARERR_Chk(void)
{
	if (U7816->ISR & U7816_ISR_TPARERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ����������żУ������־λ ��غ��� */
void U7816_ISR_RPARERR_Clr(void)
{
	U7816->ISR = U7816_ISR_RPARERR_Msk;
}

FlagStatus U7816_ISR_RPARERR_Chk(void)
{
	if (U7816->ISR & U7816_ISR_RPARERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ����֡��ʽ�����־λ ��غ��� */
void U7816_ISR_FRERR_Clr(void)
{
	U7816->ISR = U7816_ISR_FRERR_Msk;
}

FlagStatus U7816_ISR_FRERR_Chk(void)
{
	if (U7816->ISR & U7816_ISR_FRERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ������������־λ ��غ��� */
void U7816_ISR_OVERR_Clr(void)
{
	U7816->ISR = U7816_ISR_OVERR_Msk;
}

FlagStatus U7816_ISR_OVERR_Chk(void)
{
	if (U7816->ISR & U7816_ISR_OVERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ������ɱ�־ ��غ��� */
FlagStatus U7816_ISR_RXIF_Chk(void)
{
	if (U7816->ISR & U7816_ISR_RXIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���ͻ������ձ�־ ��غ��� */
FlagStatus U7816_ISR_TXIF_Chk(void)
{
	if (U7816->ISR & U7816_ISR_TXIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �����־���Ĵ������ó����������г���Ӳ����λ����U7816ERR����Ӧ���� ��غ��� */
FlagStatus U7816_ISR_ERRIF_Chk(void)
{
	if (U7816->ISR & U7816_ISR_ERRIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}


void U7816_Deinit(void)
{
  RCC_PRST_EN_Write(RSTKEY0);
  RCC_APBRST_CR1_U7816RST_Setable(ENABLE); 
  RCC_APBRST_CR1_U7816RST_Setable(DISABLE);
  RCC_PRST_EN_Write(RSTKEY1);
}

/* U7816����������ʼ������ */
void U7816_Init(U7816_InitTypeDef* para)
{
	U7816_CR_TXEN_Setable(para->TXEN);		//����ʹ��
	U7816_CR_RXEN_Setable(para->RXEN);		//����ʹ��
	U7816_CR_CKOEN_Setable(para->CKOEN);		//U7816ʱ��CLK���ʹ�ܿ���
	U7816_CR_HPUAT_Setable(para->HPUAT);		//U7816ͨ�����ݷ���ǿ���������Զ���Ч����
	U7816_CR_HPUEN_Setable(para->HPUEN);		//U7816ͨ��ǿ����ʹ�ܿ���
	
	U7816_FFR_ERSW_Set(para->ERSW);		//ERROR SIGNAL���ѡ��
	U7816_FFR_ERSGD_Set(para->ERSGD);		//ERROR SIGNAL��GUARDTIME���ѡ�񣨽��ڷ���ʱ��Ч��
	U7816_FFR_BGTEN_Setable(para->BGTEN);		//BGT��block guard time������
	U7816_FFR_REP_T_Set(para->REP_T);		//���ƽ���������żУ�����ʱ�Զ��ط�����
	U7816_FFR_PAR_Set(para->PAR);		//��żУ������ѡ��
	U7816_FFR_RFREN_Set(para->RFREN);		//����ʱGuard Time���ȿ���λ������ʱ�ϸ���Э��2etu��
	U7816_FFR_SFREN_Set(para->RFREN);		//����ʱGuard Time���ȿ���λ������ʱ�ϸ���Э��2etu��
  U7816_FFR_TREPEN_Setable(para->TREPEN);		//������������żУ���Ĵ���ʽѡ��
	U7816_FFR_RREPEN_Setable(para->RREPEN);		//����������żУ���Ĵ���ʽѡ��
	U7816_FFR_DICONV_Setable(para->DICONV);		//������������ʹ��
	
	U7816_EGTR_Write(para->TXEGT);		//����ʱ�����EGTʱ�䣨��ETUΪ��λ��
	U7816_PSC_Write(para->CLKDIV);		//U7816ʱ�������Ƶ���ƼĴ���
	U7816_BGR_Write( para->PDIV);		//U7816Ԥ��Ƶ���ƼĴ���������7816ͨ�ŷ�Ƶ�ȣ������ʣ�
	
	U7816_IER_RXIE_Setable(para->RXIE);		//���ݽ����ж�ʹ��λ����ӦRX_FLAG�жϱ�־λ
	U7816_IER_TXIE_Setable(para->TXIE);		//���ݷ����ж�ʹ��λ����ӦTX_FLAG�жϱ�־λ
	U7816_IER_LSIE_Setable(para->LSIE);		//��·״̬�ж�ʹ��λ����ӦERROR_FLAG�жϱ�־λ
}

/******END OF FILE****/
