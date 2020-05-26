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

/* Master对MISO信号的采样位置调整，用于高速通信时补偿PCB走线延迟 相关函数 */
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

/* Slave MISO发送位置调整 相关函数 */
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

/* Master/Slave模式选择 相关函数 */
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

/* 发送完成后等待 相关函数 */
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

/* Master模式下波特率设置 相关函数 */
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

/* 帧格式 相关函数 */
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

/* 时钟极性选择 相关函数 */
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

/* 时钟相位选择 相关函数 */
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

/* 四线半双工协议在读操作是否插入dummy cycle 相关函数 */
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

/* Master RXONLY控制位 相关函数 */
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

/* 通信数据字长配置 相关函数 */
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

/* 通信模式选择 相关函数 */
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

/* 半双工模式下读写配置 相关函数 */
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

/* 半双工模式下commmand帧长度 相关函数 */
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

/* Master模式下SSN控制模式选择 相关函数 */
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

/* TXONLY硬件自动清空控制 相关函数 */
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

/* TXONLY模式控制 相关函数 */
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

/* SSN输出电平 相关函数 */
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

/* 软件控制SSN 相关函数 */
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

/* SPI模块控制 相关函数 */
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

/* SPI模块 控制寄存器3 */
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

/* SPI错误中断控制 相关函数 */
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

/* 发送完成中断控制 相关函数 */
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

/* 接收完成中断控制 相关函数 */
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

/* 半双工模式下，每帧数据的帧模式 相关函数 */
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

/* 接收缓存区溢出，软件写1清0 相关函数 */
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

/* 发送缓存区溢出，软件写1清0 相关函数 */
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

/* SPI状态标志，只读 相关函数 */
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

/* 主机错误标志，软件写1清0 相关函数 */
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

/* 从机错误标志，软件写1清0 相关函数 */
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

/* 发送buffer为空标志 相关函数 */
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

/* 接收buffer非空标志 相关函数 */
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

/* SPI发送缓存 相关函数 */
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
 SPI主模式初始化函数
功能:  SPI主模式初始化
输入： SPI主模式的初始化参数
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

	SPIx_CR1_MM_Set(SPIx, SPIx_CR1_MM_MASTER);//配置成主模式
}

/********************************
 SPI从模式初始化函数
功能:  SPI从模式初始化
输入： SPI从模式的初始化参数
********************************/
void SPI_Slave_Init(SPI_Type* SPIx, SPI_Slave_SInitTypeDef* para)
{
	SPIx_Deinit(SPIx);
	
	SPIx_CR1_SSPA_Set(SPIx, SPIx_CR1_SSPA_NORMAL);
	SPIx_CR1_LSBF_Set(SPIx, para->LSBF);
	SPIx_CR1_CPOL_Set(SPIx, para->CPHOL);
	SPIx_CR1_CPHA_Set(SPIx, para->CPHA);
	SPIx_CR2_TXO_Setable(SPIx, DISABLE);

	SPIx_CR1_MM_Set(SPIx, SPIx_CR1_MM_SLAVE);//配置成从模式
}


/********************************
 SPI的SSN设置电平低的函数
********************************/
void SPI_SSN_Set_Low(SPI_Type* SPIx)//驱动级
{
	SPIx_CR2_SSN_Set(SPIx, SPIx_CR2_SSN_LOW);//拉低SSN信号
}
/********************************
 SPI的SSN设置电平高的函数
********************************/
void SPI_SSN_Set_High(SPI_Type* SPIx)//驱动级
{
	SPIx_CR2_SSN_Set(SPIx, SPIx_CR2_SSN_HIGH);//拉高SSN信号
}
/********************************
 SPI接收一个字节的函数
功能：SPI接收一个字节
输出：SPI接收字节
********************************/
uint8_t SPI_Recv_Byte(SPI_Type* SPIx)//SPI接收一字节
{
	return SPIx_RXBUF_Read(SPIx);
}
/********************************
 SPI发送一个字节的函数
功能：SPI发送一个字节
输入：SPI要发送的字节
********************************/
void SPI_Send_Byte(SPI_Type* SPIx, uint8_t data)//SPI发送一字节
{
	SPIx_TXBUF_Write(SPIx, data);
}
/********************************
 SPI发送并接收一个字节的函数
功能：SPI发送和接收一个字节
输入：SPI要发送的字节，输出：SPI接收字节
********************************/
uint8_t SPI_RW_Byte(SPI_Type* SPIx, uint8_t data)//SPI发送并接收一字节
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
