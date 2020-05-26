/**
  ******************************************************************************
  * @file    fm33l0xx_spi.c
  * @author  FM33L0 Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33l0xx_spi.h" 
#include "fm33l0xx_rcc.h" 

/** @addtogroup fm33l0_StdPeriph_Driver
  * @{
  */

/** @defgroup SPI 
  * @brief SPI driver modules
  * @{
  */ 
#include "fm33l0xx_spi.h"

/* Master��MISO�źŵĲ���λ�õ��������ڸ���ͨ��ʱ����PCB�����ӳ� ��غ��� */
void SPIx_CR1_MSPA_Set(SPI_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->CR1;
	tmpreg &= ~(SPIx_CR1_MSPA_Msk);
	tmpreg |= (SetValue & SPIx_CR1_MSPA_Msk);
	SPIx->CR1 = tmpreg;
}

uint32_t SPIx_CR1_MSPA_Get(SPI_Type* SPIx)
{
	return (SPIx->CR1 & SPIx_CR1_MSPA_Msk);
}

/* Slave MISO����λ�õ��� ��غ��� */
void SPIx_CR1_SSPA_Set(SPI_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->CR1;
	tmpreg &= ~(SPIx_CR1_SSPA_Msk);
	tmpreg |= (SetValue & SPIx_CR1_SSPA_Msk);
	SPIx->CR1 = tmpreg;
}

uint32_t SPIx_CR1_SSPA_Get(SPI_Type* SPIx)
{
	return (SPIx->CR1 & SPIx_CR1_SSPA_Msk);
}

/* Master/Slaveģʽѡ�� ��غ��� */
void SPIx_CR1_MM_Set(SPI_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->CR1;
	tmpreg &= ~(SPIx_CR1_MM_Msk);
	tmpreg |= (SetValue & SPIx_CR1_MM_Msk);
	SPIx->CR1 = tmpreg;
}

uint32_t SPIx_CR1_MM_Get(SPI_Type* SPIx)
{
	return (SPIx->CR1 & SPIx_CR1_MM_Msk);
}

/* ������ɺ�ȴ� ��غ��� */
void SPIx_CR1_WAIT_Set(SPI_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->CR1;
	tmpreg &= ~(SPIx_CR1_WAIT_Msk);
	tmpreg |= (SetValue & SPIx_CR1_WAIT_Msk);
	SPIx->CR1 = tmpreg;
}

uint32_t SPIx_CR1_WAIT_Get(SPI_Type* SPIx)
{
	return (SPIx->CR1 & SPIx_CR1_WAIT_Msk);
}

/* Masterģʽ�²��������� ��غ��� */
void SPIx_CR1_BAUD_Set(SPI_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->CR1;
	tmpreg &= ~(SPIx_CR1_BAUD_Msk);
	tmpreg |= (SetValue & SPIx_CR1_BAUD_Msk);
	SPIx->CR1 = tmpreg;
}

uint32_t SPIx_CR1_BAUD_Get(SPI_Type* SPIx)
{
	return (SPIx->CR1 & SPIx_CR1_BAUD_Msk);
}

/* ֡��ʽ ��غ��� */
void SPIx_CR1_LSBF_Set(SPI_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->CR1;
	tmpreg &= ~(SPIx_CR1_LSBF_Msk);
	tmpreg |= (SetValue & SPIx_CR1_LSBF_Msk);
	SPIx->CR1 = tmpreg;
}

uint32_t SPIx_CR1_LSBF_Get(SPI_Type* SPIx)
{
	return (SPIx->CR1 & SPIx_CR1_LSBF_Msk);
}

/* ʱ�Ӽ���ѡ�� ��غ��� */
void SPIx_CR1_CPOL_Set(SPI_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->CR1;
	tmpreg &= ~(SPIx_CR1_CPOL_Msk);
	tmpreg |= (SetValue & SPIx_CR1_CPOL_Msk);
	SPIx->CR1 = tmpreg;
}

uint32_t SPIx_CR1_CPOL_Get(SPI_Type* SPIx)
{
	return (SPIx->CR1 & SPIx_CR1_CPOL_Msk);
}

/* ʱ����λѡ�� ��غ��� */
void SPIx_CR1_CPHA_Set(SPI_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->CR1;
	tmpreg &= ~(SPIx_CR1_CPHA_Msk);
	tmpreg |= (SetValue & SPIx_CR1_CPHA_Msk);
	SPIx->CR1 = tmpreg;
}

uint32_t SPIx_CR1_CPHA_Get(SPI_Type* SPIx)
{
	return (SPIx->CR1 & SPIx_CR1_CPHA_Msk);
}

/* ���߰�˫��Э���ڶ������Ƿ����dummy cycle ��غ��� */
void SPIx_CR2_DUMMY_EN_Setable(SPI_Type* SPIx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		SPIx->CR2 |= (SPIx_CR2_DUMMY_EN_Msk);
	}
	else
	{
		SPIx->CR2 &= ~(SPIx_CR2_DUMMY_EN_Msk);
	}
}

FunState SPIx_CR2_DUMMY_EN_Getable(SPI_Type* SPIx)
{
	if (SPIx->CR2 & (SPIx_CR2_DUMMY_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Master RXONLY����λ ��غ��� */
void SPIx_CR2_RXO_Setable(SPI_Type* SPIx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		SPIx->CR2 |= (SPIx_CR2_RXO_Msk);
	}
	else
	{
		SPIx->CR2 &= ~(SPIx_CR2_RXO_Msk);
	}
}

FunState SPIx_CR2_RXO_Getable(SPI_Type* SPIx)
{
	if (SPIx->CR2 & (SPIx_CR2_RXO_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ͨ�������ֳ����� ��غ��� */
void SPIx_CR2_DLEN_Set(SPI_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->CR2;
	tmpreg &= ~(SPIx_CR2_DLEN_Msk);
	tmpreg |= (SetValue & SPIx_CR2_DLEN_Msk);
	SPIx->CR2 = tmpreg;
}

uint32_t SPIx_CR2_DLEN_Get(SPI_Type* SPIx)
{
	return (SPIx->CR2 & SPIx_CR2_DLEN_Msk);
}

/* ͨ��ģʽѡ�� ��غ��� */
void SPIx_CR2_HALFDUPLEX_Set(SPI_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->CR2;
	tmpreg &= ~(SPIx_CR2_HALFDUPLEX_Msk);
	tmpreg |= (SetValue & SPIx_CR2_HALFDUPLEX_Msk);
	SPIx->CR2 = tmpreg;
}

uint32_t SPIx_CR2_HALFDUPLEX_Get(SPI_Type* SPIx)
{
	return (SPIx->CR2 & SPIx_CR2_HALFDUPLEX_Msk);
}

/* ��˫��ģʽ�¶�д���� ��غ��� */
void SPIx_CR2_HD_RW_Set(SPI_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->CR2;
	tmpreg &= ~(SPIx_CR2_HD_RW_Msk);
	tmpreg |= (SetValue & SPIx_CR2_HD_RW_Msk);
	SPIx->CR2 = tmpreg;
}

uint32_t SPIx_CR2_HD_RW_Get(SPI_Type* SPIx)
{
	return (SPIx->CR2 & SPIx_CR2_HD_RW_Msk);
}

/* ��˫��ģʽ��commmand֡���� ��غ��� */
void SPIx_CR2_CMD8b_Set(SPI_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->CR2;
	tmpreg &= ~(SPIx_CR2_CMD8b_Msk);
	tmpreg |= (SetValue & SPIx_CR2_CMD8b_Msk);
	SPIx->CR2 = tmpreg;
}

uint32_t SPIx_CR2_CMD8b_Get(SPI_Type* SPIx)
{
	return (SPIx->CR2 & SPIx_CR2_CMD8b_Msk);
}

/* Masterģʽ��SSN����ģʽѡ�� ��غ��� */
void SPIx_CR2_SSNM_Set(SPI_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->CR2;
	tmpreg &= ~(SPIx_CR2_SSNM_Msk);
	tmpreg |= (SetValue & SPIx_CR2_SSNM_Msk);
	SPIx->CR2 = tmpreg;
}

uint32_t SPIx_CR2_SSNM_Get(SPI_Type* SPIx)
{
	return (SPIx->CR2 & SPIx_CR2_SSNM_Msk);
}

/* TXONLYӲ���Զ���տ��� ��غ��� */
void SPIx_CR2_TXO_AC_Set(SPI_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->CR2;
	tmpreg &= ~(SPIx_CR2_TXO_AC_Msk);
	tmpreg |= (SetValue & SPIx_CR2_TXO_AC_Msk);
	SPIx->CR2 = tmpreg;
}

uint32_t SPIx_CR2_TXO_AC_Get(SPI_Type* SPIx)
{
	return (SPIx->CR2 & SPIx_CR2_TXO_AC_Msk);
}

/* TXONLYģʽ���� ��غ��� */
void SPIx_CR2_TXO_Setable(SPI_Type* SPIx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		SPIx->CR2 |= (SPIx_CR2_TXO_Msk);
	}
	else
	{
		SPIx->CR2 &= ~(SPIx_CR2_TXO_Msk);
	}
}

FunState SPIx_CR2_TXO_Getable(SPI_Type* SPIx)
{
	if (SPIx->CR2 & (SPIx_CR2_TXO_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SSN�����ƽ ��غ��� */
void SPIx_CR2_SSN_Set(SPI_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->CR2;
	tmpreg &= ~(SPIx_CR2_SSN_Msk);
	tmpreg |= (SetValue & SPIx_CR2_SSN_Msk);
	SPIx->CR2 = tmpreg;
}

uint32_t SPIx_CR2_SSN_Get(SPI_Type* SPIx)
{
	return (SPIx->CR2 & SPIx_CR2_SSN_Msk);
}

/* �������SSN ��غ��� */
void SPIx_CR2_SSNSEN_Set(SPI_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->CR2;
	tmpreg &= ~(SPIx_CR2_SSNSEN_Msk);
	tmpreg |= (SetValue & SPIx_CR2_SSNSEN_Msk);
	SPIx->CR2 = tmpreg;
}

uint32_t SPIx_CR2_SSNSEN_Get(SPI_Type* SPIx)
{
	return (SPIx->CR2 & SPIx_CR2_SSNSEN_Msk);
}

/* SPIģ����� ��غ��� */
void SPIx_CR2_SPIEN_Setable(SPI_Type* SPIx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		SPIx->CR2 |= (SPIx_CR2_SPIEN_Msk);
	}
	else
	{
		SPIx->CR2 &= ~(SPIx_CR2_SPIEN_Msk);
	}
}

FunState SPIx_CR2_SPIEN_Getable(SPI_Type* SPIx)
{
	if (SPIx->CR2 & (SPIx_CR2_SPIEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SPIģ�� ���ƼĴ���3 */
void SPIx_CR3_TXBFC_Clr(SPI_Type* SPIx)
{
	SPIx->CR3 = SPIx_CR3_TXBFC_Msk;
}

void SPIx_CR3_RXBFC_Clr(SPI_Type* SPIx)
{
	SPIx->CR3 = SPIx_CR3_RXBFC_Msk;
}

void SPIx_CR3_MERRC_Clr(SPI_Type* SPIx)
{
	SPIx->CR3 = SPIx_CR3_MERRC_Msk;
}

void SPIx_CR3_SERRC_Clr(SPI_Type* SPIx)
{
	SPIx->CR3 = SPIx_CR3_SERRC_Msk;
}

/* SPI�����жϿ��� ��غ��� */
void SPIx_IER_ERRIE_Setable(SPI_Type* SPIx, FunState NewState)
{
    if (NewState == ENABLE)
	{
		SPIx->IER |= (SPIx_IER_ERRIE_Msk);
	}
	else
	{
		SPIx->IER &= ~(SPIx_IER_ERRIE_Msk);
	}
}

FunState SPIx_IER_ERRIE_Getable(SPI_Type* SPIx)
{
	if (SPIx->IER & (SPIx_IER_ERRIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��������жϿ��� ��غ��� */
void SPIx_IER_TXIE_Setable(SPI_Type* SPIx, FunState NewState)
{
    if (NewState == ENABLE)
	{
		SPIx->IER |= (SPIx_IER_TXIE_Msk);
	}
	else
	{
		SPIx->IER &= ~(SPIx_IER_TXIE_Msk);
	}
}

FunState SPIx_IER_TXIE_Getable(SPI_Type* SPIx)
{
    if (SPIx->IER & (SPIx_IER_TXIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��������жϿ��� ��غ��� */
void SPIx_IER_RXIE_Setable(SPI_Type* SPIx, FunState NewState)
{
    if (NewState == ENABLE)
	{
		SPIx->IER |= (SPIx_IER_RXIE_Msk);
	}
	else
	{
		SPIx->IER &= ~(SPIx_IER_RXIE_Msk);
	}
}

FunState SPIx_IER_RXIE_Getable(SPI_Type* SPIx)
{
    if (SPIx->IER & (SPIx_IER_RXIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��˫��ģʽ�£�ÿ֡���ݵ�֡ģʽ ��غ��� */
void SPIx_ISR_DCN_TX_Set(SPI_Type* SPIx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = SPIx->ISR;
	tmpreg &= ~(SPIx_ISR_DCN_TX_Msk);
	tmpreg |= (SetValue & SPIx_ISR_DCN_TX_Msk);
	SPIx->ISR = tmpreg;
}

uint32_t SPIx_ISR_DCN_TX_Get(SPI_Type* SPIx)
{
	return (SPIx->ISR & SPIx_ISR_DCN_TX_Msk);
}

/* ���ջ�������������д1��0 ��غ��� */
void SPIx_ISR_RXCOL_Clr(SPI_Type* SPIx)
{
	SPIx->ISR = SPIx_ISR_RXCOL_Msk;
}

FlagStatus SPIx_ISR_RXCOL_Chk(SPI_Type* SPIx)
{
	if (SPIx->ISR & SPIx_ISR_RXCOL_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���ͻ�������������д1��0 ��غ��� */
void SPIx_ISR_TXCOL_Clr(SPI_Type* SPIx)
{
	SPIx->ISR = SPIx_ISR_TXCOL_Msk;
}

FlagStatus SPIx_ISR_TXCOL_Chk(SPI_Type* SPIx)
{
	if (SPIx->ISR & SPIx_ISR_TXCOL_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* SPI״̬��־��ֻ�� ��غ��� */
FlagStatus SPIx_ISR_BUSY_Chk(SPI_Type* SPIx)
{
	if (SPIx->ISR & SPIx_ISR_BUSY_Msk)
    {
        return SET;
    }
    else
    {
        return RESET;
    }
}

/* ���������־�����д1��0 ��غ��� */
void SPIx_ISR_MERR_Clr(SPI_Type* SPIx)
{
	SPIx->ISR = SPIx_ISR_MERR_Msk;
}

FlagStatus SPIx_ISR_MERR_Chk(SPI_Type* SPIx)
{
	if (SPIx->ISR & SPIx_ISR_MERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �ӻ������־�����д1��0 ��غ��� */
void SPIx_ISR_SERR_Clr(SPI_Type* SPIx)
{
	SPIx->ISR = SPIx_ISR_SERR_Msk;
}

FlagStatus SPIx_ISR_SERR_Chk(SPI_Type* SPIx)
{
	if (SPIx->ISR & SPIx_ISR_SERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ����bufferΪ�ձ�־ ��غ��� */
void SPIx_ISR_TXBE_Clr(SPI_Type* SPIx)
{
	SPIx->ISR = SPIx_ISR_TXBE_Msk;
}

FlagStatus SPIx_ISR_TXBE_Chk(SPI_Type* SPIx)
{
	if (SPIx->ISR & SPIx_ISR_TXBE_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ����buffer�ǿձ�־ ��غ��� */
void SPIx_ISR_RXBF_Clr(SPI_Type* SPIx)
{
	SPIx->ISR = SPIx_ISR_RXBF_Msk;
}

FlagStatus SPIx_ISR_RXBF_Chk(SPI_Type* SPIx)
{
	if (SPIx->ISR & SPIx_ISR_RXBF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* SPI���ͻ��� ��غ��� */
void SPIx_TXBUF_Write(SPI_Type* SPIx, uint32_t SetValue)
{
	SPIx->TXBUF = SetValue;
}

uint32_t SPIx_RXBUF_Read(SPI_Type* SPIx)
{
	return (SPIx->RXBUF);
}


void SPIx_Deinit(SPI_Type* SPIx)
{    
  if(SPIx==SPI1)
  {
    RCC_PRST_EN_Write(RSTKEY0);
    RCC_APBRST_CR2_SPI1RST_Setable(ENABLE);  
    RCC_APBRST_CR2_SPI1RST_Setable(DISABLE);
    RCC_PRST_EN_Write(RSTKEY1);
  }
  if(SPIx==SPI2)
  {
    RCC_PRST_EN_Write(RSTKEY0);
    RCC_APBRST_CR1_SPI2RST_Setable(ENABLE);  
    RCC_APBRST_CR1_SPI2RST_Setable(DISABLE);
    RCC_PRST_EN_Write(RSTKEY1);
  }
}


/********************************
 SPI��ģʽ��ʼ������
����:  SPI��ģʽ��ʼ��
���룺 SPI��ģʽ�ĳ�ʼ������
********************************/
void SPI_Master_Init(SPI_Type* SPIx, SPI_Master_SInitTypeDef* para)
{
	SPIx_Deinit(SPIx);
	
	SPIx_CR1_MSPA_Set(SPIx, SPIx_CR1_MSPA_NORMAL);
	SPIx_CR1_WAIT_Set(SPIx, SPIx_CR1_WAIT_WAIT_1);
	SPIx_CR1_BAUD_Set(SPIx, para->BAUD_RATE);
	SPIx_CR1_LSBF_Set(SPIx, para->LSBF);
	SPIx_CR1_CPOL_Set(SPIx, para->CPHOL);
	SPIx_CR1_CPHA_Set(SPIx, para->CPHA);
	SPIx_CR2_SSNM_Set(SPIx, para->SSNM);
	SPIx_CR2_TXO_Setable(SPIx, DISABLE);
	SPIx_CR2_SSNSEN_Set(SPIx, para->SSNSEN);

	SPIx_CR1_MM_Set(SPIx, SPIx_CR1_MM_MASTER);//���ó���ģʽ
}

/********************************
 SPI��ģʽ��ʼ������
����:  SPI��ģʽ��ʼ��
���룺 SPI��ģʽ�ĳ�ʼ������
********************************/
void SPI_Slave_Init(SPI_Type* SPIx, SPI_Slave_SInitTypeDef* para)
{
	SPIx_Deinit(SPIx);
	
	SPIx_CR1_SSPA_Set(SPIx, SPIx_CR1_SSPA_NORMAL);
	SPIx_CR1_LSBF_Set(SPIx, para->LSBF);
	SPIx_CR1_CPOL_Set(SPIx, para->CPHOL);
	SPIx_CR1_CPHA_Set(SPIx, para->CPHA);
	SPIx_CR2_TXO_Setable(SPIx, DISABLE);

	SPIx_CR1_MM_Set(SPIx, SPIx_CR1_MM_SLAVE);//���óɴ�ģʽ
}


/********************************
 SPI��SSN���õ�ƽ�͵ĺ���
********************************/
void SPI_SSN_Set_Low(SPI_Type* SPIx)//������
{
	SPIx_CR2_SSN_Set(SPIx, SPIx_CR2_SSN_LOW);//����SSN�ź�
}
/********************************
 SPI��SSN���õ�ƽ�ߵĺ���
********************************/
void SPI_SSN_Set_High(SPI_Type* SPIx)//������
{
	SPIx_CR2_SSN_Set(SPIx, SPIx_CR2_SSN_HIGH);//����SSN�ź�
}
/********************************
 SPI����һ���ֽڵĺ���
���ܣ�SPI����һ���ֽ�
�����SPI�����ֽ�
********************************/
uint8_t SPI_Recv_Byte(SPI_Type* SPIx)//SPI����һ�ֽ�
{
	return SPIx_RXBUF_Read(SPIx);
}
/********************************
 SPI����һ���ֽڵĺ���
���ܣ�SPI����һ���ֽ�
���룺SPIҪ���͵��ֽ�
********************************/
void SPI_Send_Byte(SPI_Type* SPIx, uint8_t data)//SPI����һ�ֽ�
{
	SPIx_TXBUF_Write(SPIx, data);
}
/********************************
 SPI���Ͳ�����һ���ֽڵĺ���
���ܣ�SPI���ͺͽ���һ���ֽ�
���룺SPIҪ���͵��ֽڣ������SPI�����ֽ�
********************************/
uint8_t SPI_RW_Byte(SPI_Type* SPIx, uint8_t data)//SPI���Ͳ�����һ�ֽ�
{
  unsigned char rx_data;
	uint32_t Temp32;
	uint32_t i;
	
	Temp32 = SPIx_CR1_BAUD_Get(SPIx);
	Temp32 = Temp32>>SPIx_CR1_BAUD_Pos;
	Temp32 = 0x1U<<(Temp32+1);
	Temp32 = Temp32*8;
	
    for(i=0; i<Temp32; i++)
    {
    	if (SPIx_ISR_TXBE_Chk(SPIx) == SET)
		{
			break;
		}		
    }
    SPI_Send_Byte(SPIx, data);

    for(i=0; i<Temp32; i++)
    {
    	if (SPIx_ISR_RXBF_Chk(SPIx) == SET)
        {
            break;
        }
    }
    rx_data = SPI_Recv_Byte(SPIx);
    return rx_data;
}

/******END OF FILE****/
