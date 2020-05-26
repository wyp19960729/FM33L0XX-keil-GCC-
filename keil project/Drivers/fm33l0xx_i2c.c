/**
  ******************************************************************************
  * @file    fm33l0xx_i2c.c
  * @author  FM33L0 Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33l0xx_i2c.h" 
#include "fm33l0xx_rcc.h" 

/** @addtogroup fm33l0_StdPeriph_Driver
  * @{
  */

/** @defgroup I2C 
  * @brief I2C driver modules
  * @{
  */ 
/* 主机DMA自动终止 相关函数 */
void I2C_MSP_CFGR_AUTOEND_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = I2C->MSP_CFGR;
	tmpreg &= ~(I2C_MSP_CFGR_AUTOEND_Msk);
	tmpreg |= (SetValue & I2C_MSP_CFGR_AUTOEND_Msk);
	I2C->MSP_CFGR = tmpreg;
}

uint32_t I2C_MSP_CFGR_AUTOEND_Get(void)
{
	return (I2C->MSP_CFGR & I2C_MSP_CFGR_AUTOEND_Msk);
}

/* 主机DMA使能 相关函数 */
void I2C_MSP_CFGR_MSP_DMAEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->MSP_CFGR |= (I2C_MSP_CFGR_MSP_DMAEN_Msk);
	}
	else
	{
		I2C->MSP_CFGR &= ~(I2C_MSP_CFGR_MSP_DMAEN_Msk);
	}
}

FunState I2C_MSP_CFGR_MSP_DMAEN_Getable(void)
{
	if (I2C->MSP_CFGR & (I2C_MSP_CFGR_MSP_DMAEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SCL拉低超时使能 相关函数 */
void I2C_MSP_CFGR_TOEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->MSP_CFGR |= (I2C_MSP_CFGR_TOEN_Msk);
	}
	else
	{
		I2C->MSP_CFGR &= ~(I2C_MSP_CFGR_TOEN_Msk);
	}
}

FunState I2C_MSP_CFGR_TOEN_Getable(void)
{
	if (I2C->MSP_CFGR & (I2C_MSP_CFGR_TOEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* I2C主机模块使能控制位 相关函数 */
void I2C_MSP_CFGR_MSPEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->MSP_CFGR |= (I2C_MSP_CFGR_MSPEN_Msk);
	}
	else
	{
		I2C->MSP_CFGR &= ~(I2C_MSP_CFGR_MSPEN_Msk);
	}
}

FunState I2C_MSP_CFGR_MSPEN_Getable(void)
{
	if (I2C->MSP_CFGR & (I2C_MSP_CFGR_MSPEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 主机接收模式下，接收使能位 相关函数 */
void I2C_MSP_CR_RCEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->MSP_CR |= (I2C_MSP_CR_RCEN_Msk);
	}
	else
	{
		I2C->MSP_CR &= ~(I2C_MSP_CR_RCEN_Msk);
	}
}

FunState I2C_MSP_CR_RCEN_Getable(void)
{
	if (I2C->MSP_CR & (I2C_MSP_CR_RCEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* STOP时序产生使能控制位 相关函数 */
void I2C_MSP_CR_PEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->MSP_CR |= (I2C_MSP_CR_PEN_Msk);
	}
	else
	{
		I2C->MSP_CR &= ~(I2C_MSP_CR_PEN_Msk);
	}
}

FunState I2C_MSP_CR_PEN_Getable(void)
{
	if (I2C->MSP_CR & (I2C_MSP_CR_PEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Repeated START时序产生使能控制位 相关函数 */
void I2C_MSP_CR_RSEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->MSP_CR |= (I2C_MSP_CR_RSEN_Msk);
	}
	else
	{
		I2C->MSP_CR &= ~(I2C_MSP_CR_RSEN_Msk);
	}
}

FunState I2C_MSP_CR_RSEN_Getable(void)
{
	if (I2C->MSP_CR & (I2C_MSP_CR_RSEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* START时序产生使能控制位 相关函数 */
void I2C_MSP_CR_SEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->MSP_CR |= (I2C_MSP_CR_SEN_Msk);
	}
	else
	{
		I2C->MSP_CR &= ~(I2C_MSP_CR_SEN_Msk);
	}
}

FunState I2C_MSP_CR_SEN_Getable(void)
{
	if (I2C->MSP_CR & (I2C_MSP_CR_SEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* WCOL中断使能寄存器 相关函数 */
void I2C_MSP_IER_WCOLE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->MSP_IER |= (I2C_MSP_IER_WCOLE_Msk);
	}
	else
	{
		I2C->MSP_IER &= ~(I2C_MSP_IER_WCOLE_Msk);
	}
}

FunState I2C_MSP_IER_WCOLE_Getable(void)
{
	if (I2C->MSP_IER & (I2C_MSP_IER_WCOLE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SCL超时中断使能寄存器 相关函数 */
void I2C_MSP_IER_OVTE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->MSP_IER |= (I2C_MSP_IER_OVTE_Msk);
	}
	else
	{
		I2C->MSP_IER &= ~(I2C_MSP_IER_OVTE_Msk);
	}
}

FunState I2C_MSP_IER_OVTE_Getable(void)
{
	if (I2C->MSP_IER & (I2C_MSP_IER_OVTE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* START时序中断使能寄存器 相关函数 */
void I2C_MSP_IER_SE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->MSP_IER |= (I2C_MSP_IER_SE_Msk);
	}
	else
	{
		I2C->MSP_IER &= ~(I2C_MSP_IER_SE_Msk);
	}
}

FunState I2C_MSP_IER_SE_Getable(void)
{
	if (I2C->MSP_IER & (I2C_MSP_IER_SE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* STOP时序中断使能寄存器 相关函数 */
void I2C_MSP_IER_PE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->MSP_IER |= (I2C_MSP_IER_PE_Msk);
	}
	else
	{
		I2C->MSP_IER &= ~(I2C_MSP_IER_PE_Msk);
	}
}

FunState I2C_MSP_IER_PE_Getable(void)
{
	if (I2C->MSP_IER & (I2C_MSP_IER_PE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 主机发送模式下NACK中断使能寄存器 相关函数 */
void I2C_MSP_IER_NACKE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->MSP_IER |= (I2C_MSP_IER_NACKE_Msk);
	}
	else
	{
		I2C->MSP_IER &= ~(I2C_MSP_IER_NACKE_Msk);
	}
}

FunState I2C_MSP_IER_NACKE_Getable(void)
{
	if (I2C->MSP_IER & (I2C_MSP_IER_NACKE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* I2C主机发送完成中断使能 相关函数 */
void I2C_MSP_IER_TXIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->MSP_IER |= (I2C_MSP_IER_TXIE_Msk);
	}
	else
	{
		I2C->MSP_IER &= ~(I2C_MSP_IER_TXIE_Msk);
	}
}

FunState I2C_MSP_IER_TXIE_Getable(void)
{
	if (I2C->MSP_IER & (I2C_MSP_IER_TXIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* I2C主机接收完成中断使能 相关函数 */
void I2C_MSP_IER_RXIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->MSP_IER |= (I2C_MSP_IER_RXIE_Msk);
	}
	else
	{
		I2C->MSP_IER &= ~(I2C_MSP_IER_RXIE_Msk);
	}
}

FunState I2C_MSP_IER_RXIE_Getable(void)
{
	if (I2C->MSP_IER & (I2C_MSP_IER_RXIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 写冲突检测位 相关函数 */
void I2C_MSP_ISR_WCOL_Clr(void)
{
	I2C->MSP_ISR = I2C_MSP_ISR_WCOL_Msk;
}

FlagStatus I2C_MSP_ISR_WCOL_Chk(void)
{
	if (I2C->MSP_ISR & I2C_MSP_ISR_WCOL_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* SCL超时中断标志 相关函数 */
void I2C_MSP_ISR_OVT_Clr(void)
{
	I2C->MSP_ISR = I2C_MSP_ISR_OVT_Msk;
}

FlagStatus I2C_MSP_ISR_OVT_Chk(void)
{
	if (I2C->MSP_ISR & I2C_MSP_ISR_OVT_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* START时序发送完成中断标志 相关函数 */
void I2C_MSP_ISR_S_Clr(void)
{
	I2C->MSP_ISR |= 0x0;
}

FlagStatus I2C_MSP_ISR_S_Chk(void)
{
	if (I2C->MSP_ISR & I2C_MSP_ISR_S_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* STOP时序发送完成中断标志 相关函数 */
void I2C_MSP_ISR_P_Clr(void)
{
	I2C->MSP_ISR |= 0x0;
}

FlagStatus I2C_MSP_ISR_P_Chk(void)
{
	if (I2C->MSP_ISR & I2C_MSP_ISR_P_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 主控发送模式下，来自从机的回应信号 相关函数 */
void I2C_MSP_ISR_ACKSTA_Clr(void)
{
	I2C->MSP_ISR = I2C_MSP_ISR_ACKSTA_Msk;
}

FlagStatus I2C_MSP_ISR_ACKSTA_Chk(void)
{
	if (I2C->MSP_ISR & I2C_MSP_ISR_ACKSTA_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* I2C主机发送完成中断标志 相关函数 */
void I2C_MSP_ISR_TXIF_Clr(void)
{
	I2C->MSP_ISR = I2C_MSP_ISR_TXIF_Msk;
}

FlagStatus I2C_MSP_ISR_TXIF_Chk(void)
{
	if (I2C->MSP_ISR & I2C_MSP_ISR_TXIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* I2C主机接收完成中断标志 相关函数 */
void I2C_MSP_ISR_RXIF_Clr(void)
{
	I2C->MSP_ISR = I2C_MSP_ISR_RXIF_Msk;
}

FlagStatus I2C_MSP_ISR_RXIF_Chk(void)
{
	if (I2C->MSP_ISR & I2C_MSP_ISR_RXIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* I2C通信状态位 相关函数 */
FlagStatus I2C_MSP_SR_BUSY_Chk(void)
{
	if (I2C->MSP_SR & I2C_MSP_SR_BUSY_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* I2C传输方向状态位 相关函数 */
FlagStatus I2C_MSP_SR_RW_Chk(void)
{
	if (I2C->MSP_SR & I2C_MSP_SR_RW_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 缓冲器满状态位 相关函数 */
FlagStatus I2C_MSP_SR_BF_Chk(void)
{
	if (I2C->MSP_SR & I2C_MSP_SR_BF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 主控接收模式下，主机回应信号的状态 相关函数 */
void I2C_MSP_SR_ACKMO_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = I2C->MSP_SR;
	tmpreg &= ~(I2C_MSP_SR_ACKMO_Msk);
	tmpreg |= (SetValue & I2C_MSP_SR_ACKMO_Msk);
	I2C->MSP_SR = tmpreg;
}

uint32_t I2C_MSP_SR_ACKMO_Get(void)
{
	return (I2C->MSP_SR & I2C_MSP_SR_ACKMO_Msk);
}

/* 主机发送的SCL时钟高电平宽度 相关函数 */
void I2C_MSP_BGR_MSPBRGH_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = I2C->MSP_BGR;
	tmpreg &= ~(I2C_MSP_BGR_MSPBRGH_Msk);
	tmpreg |= (SetValue & I2C_MSP_BGR_MSPBRGH_Msk);
	I2C->MSP_BGR = tmpreg;
}

uint32_t I2C_MSP_BGR_MSPBRGH_Get(void)
{
	return (I2C->MSP_BGR & I2C_MSP_BGR_MSPBRGH_Msk);
}

/* 主机发送的SCL时钟低电平宽度 相关函数 */
void I2C_MSP_BGR_MSPBRGL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = I2C->MSP_BGR;
	tmpreg &= ~(I2C_MSP_BGR_MSPBRGL_Msk);
	tmpreg |= (SetValue & I2C_MSP_BGR_MSPBRGL_Msk);
	I2C->MSP_BGR = tmpreg;
}

uint32_t I2C_MSP_BGR_MSPBRGL_Get(void)
{
	return (I2C->MSP_BGR & I2C_MSP_BGR_MSPBRGL_Msk);
}

/* I2C主机收发缓存寄存器 相关函数 */
void I2C_MSP_BUF_Write(uint32_t SetValue)
{
	I2C->MSP_BUF = (SetValue & I2C_MSP_BUF_MSPBUF_Msk);
}

uint32_t I2C_MSP_BUF_Read(void)
{
	return (I2C->MSP_BUF & I2C_MSP_BUF_MSPBUF_Msk);
}

/* I2C主机时序控制寄存器 相关函数 */
void I2C_MSP_TCR_SDAHD_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = I2C->MSP_TCR;
	tmpreg &= ~(I2C_MSP_TCR_SDAHD_Msk);
	tmpreg |= (SetValue & I2C_MSP_TCR_SDAHD_Msk);
	I2C->MSP_TCR = tmpreg;
}

uint32_t I2C_MSP_TCR_SDAHD_Get(void)
{
	return (I2C->MSP_TCR & I2C_MSP_TCR_SDAHD_Msk);
}

/* I2C主机超时寄存器 相关函数 */
void I2C_MSP_TOR_TIMEOUT_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = I2C->MSP_TOR;
	tmpreg &= ~(I2C_MSP_TOR_TIMEOUT_Msk);
	tmpreg |= (SetValue & I2C_MSP_TOR_TIMEOUT_Msk);
	I2C->MSP_TOR = tmpreg;
}

uint32_t I2C_MSP_TOR_TIMEOUT_Get(void)
{
	return (I2C->MSP_TOR & I2C_MSP_TOR_TIMEOUT_Msk);
}

/* I2C从机时钟延展使能 相关函数 */
void I2C_SSP_CR_SCLSEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->SSP_CR |= (I2C_SSP_CR_SCLSEN_Msk);
	}
	else
	{
		I2C->SSP_CR &= ~(I2C_SSP_CR_SCLSEN_Msk);
	}
}

FunState I2C_SSP_CR_SCLSEN_Getable(void)
{
	if (I2C->SSP_CR & (I2C_SSP_CR_SCLSEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* I2C从机DMA使能 相关函数 */
void I2C_SSP_CR_SSP_DMAEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->SSP_CR |= (I2C_SSP_CR_SSP_DMAEN_Msk);
	}
	else
	{
		I2C->SSP_CR &= ~(I2C_SSP_CR_SSP_DMAEN_Msk);
	}
}

FunState I2C_SSP_CR_SSP_DMAEN_Getable(void)
{
	if (I2C->SSP_CR & (I2C_SSP_CR_SSP_DMAEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ACK使能位 相关函数 */
void I2C_SSP_CR_ACKEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->SSP_CR |= (I2C_SSP_CR_ACKEN_Msk);
	}
	else
	{
		I2C->SSP_CR &= ~(I2C_SSP_CR_ACKEN_Msk);
	}
}

FunState I2C_SSP_CR_ACKEN_Getable(void)
{
	if (I2C->SSP_CR & (I2C_SSP_CR_ACKEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SDA从机输出延迟使能 相关函数 */
void I2C_SSP_CR_SDAO_DLYEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->SSP_CR |= (I2C_SSP_CR_SDAO_DLYEN_Msk);
	}
	else
	{
		I2C->SSP_CR &= ~(I2C_SSP_CR_SDAO_DLYEN_Msk);
	}
}

FunState I2C_SSP_CR_SDAO_DLYEN_Getable(void)
{
	if (I2C->SSP_CR & (I2C_SSP_CR_SDAO_DLYEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SCL从机输入模拟滤波使能 相关函数 */
void I2C_SSP_CR_SCLI_ANFEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->SSP_CR |= (I2C_SSP_CR_SCLI_ANFEN_Msk);
	}
	else
	{
		I2C->SSP_CR &= ~(I2C_SSP_CR_SCLI_ANFEN_Msk);
	}
}

FunState I2C_SSP_CR_SCLI_ANFEN_Getable(void)
{
	if (I2C->SSP_CR & (I2C_SSP_CR_SCLI_ANFEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 10位地址使能 相关函数 */
void I2C_SSP_CR_A10EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->SSP_CR |= (I2C_SSP_CR_A10EN_Msk);
	}
	else
	{
		I2C->SSP_CR &= ~(I2C_SSP_CR_A10EN_Msk);
	}
}

FunState I2C_SSP_CR_A10EN_Getable(void)
{
	if (I2C->SSP_CR & (I2C_SSP_CR_A10EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* I2C从机使能位 相关函数 */
void I2C_SSP_CR_SSPEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->SSP_CR |= (I2C_SSP_CR_SSPEN_Msk);
	}
	else
	{
		I2C->SSP_CR &= ~(I2C_SSP_CR_SSPEN_Msk);
	}
}

FunState I2C_SSP_CR_SSPEN_Getable(void)
{
	if (I2C->SSP_CR & (I2C_SSP_CR_SSPEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 从机地址错误中断使能 相关函数 */
void I2C_SSP_IER_ADEE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->SSP_IER |= (I2C_SSP_IER_ADEE_Msk);
	}
	else
	{
		I2C->SSP_IER &= ~(I2C_SSP_IER_ADEE_Msk);
	}
}

FunState I2C_SSP_IER_ADEE_Getable(void)
{
	if (I2C->SSP_IER & (I2C_SSP_IER_ADEE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Start中断使能 相关函数 */
void I2C_SSP_IER_SE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->SSP_IER |= (I2C_SSP_IER_SE_Msk);
	}
	else
	{
		I2C->SSP_IER &= ~(I2C_SSP_IER_SE_Msk);
	}
}

FunState I2C_SSP_IER_SE_Getable(void)
{
	if (I2C->SSP_IER & (I2C_SSP_IER_SE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Stop中断使能 相关函数 */
void I2C_SSP_IER_PE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->SSP_IER |= (I2C_SSP_IER_PE_Msk);
	}
	else
	{
		I2C->SSP_IER &= ~(I2C_SSP_IER_PE_Msk);
	}
}

FunState I2C_SSP_IER_PE_Getable(void)
{
	if (I2C->SSP_IER & (I2C_SSP_IER_PE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* WCOL中断使能 相关函数 */
void I2C_SSP_IER_WCOLE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->SSP_IER |= (I2C_SSP_IER_WCOLE_Msk);
	}
	else
	{
		I2C->SSP_IER &= ~(I2C_SSP_IER_WCOLE_Msk);
	}
}

FunState I2C_SSP_IER_WCOLE_Getable(void)
{
	if (I2C->SSP_IER & (I2C_SSP_IER_WCOLE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SSPOV中断使能 相关函数 */
void I2C_SSP_IER_SSPOVE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->SSP_IER |= (I2C_SSP_IER_SSPOVE_Msk);
	}
	else
	{
		I2C->SSP_IER &= ~(I2C_SSP_IER_SSPOVE_Msk);
	}
}

FunState I2C_SSP_IER_SSPOVE_Getable(void)
{
	if (I2C->SSP_IER & (I2C_SSP_IER_SSPOVE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 从机地址匹配中断使能 相关函数 */
void I2C_SSP_IER_ADME_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->SSP_IER |= (I2C_SSP_IER_ADME_Msk);
	}
	else
	{
		I2C->SSP_IER &= ~(I2C_SSP_IER_ADME_Msk);
	}
}

FunState I2C_SSP_IER_ADME_Getable(void)
{
	if (I2C->SSP_IER & (I2C_SSP_IER_ADME_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 发送完成中断使能 相关函数 */
void I2C_SSP_IER_TXIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->SSP_IER |= (I2C_SSP_IER_TXIE_Msk);
	}
	else
	{
		I2C->SSP_IER &= ~(I2C_SSP_IER_TXIE_Msk);
	}
}

FunState I2C_SSP_IER_TXIE_Getable(void)
{
	if (I2C->SSP_IER & (I2C_SSP_IER_TXIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 接收完成中断使能 相关函数 */
void I2C_SSP_IER_RXIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		I2C->SSP_IER |= (I2C_SSP_IER_RXIE_Msk);
	}
	else
	{
		I2C->SSP_IER &= ~(I2C_SSP_IER_RXIE_Msk);
	}
}

FunState I2C_SSP_IER_RXIE_Getable(void)
{
	if (I2C->SSP_IER & (I2C_SSP_IER_RXIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 从机地址格式错误 相关函数 */
void I2C_SSP_ISR_ADE_Clr(void)
{
	I2C->SSP_ISR = I2C_SSP_ISR_ADE_Msk;
}

FlagStatus I2C_SSP_ISR_ADE_Chk(void)
{
	if (I2C->SSP_ISR & I2C_SSP_ISR_ADE_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 检测到start时序 相关函数 */
FlagStatus I2C_SSP_ISR_S_Chk(void)
{
	if (I2C->SSP_ISR & I2C_SSP_ISR_S_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 检测到stop时序 相关函数 */
FlagStatus I2C_SSP_ISR_P_Chk(void)
{
	if (I2C->SSP_ISR & I2C_SSP_ISR_P_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 写冲突标志 相关函数 */
void I2C_SSP_ISR_WCOL_Clr(void)
{
	I2C->SSP_ISR = I2C_SSP_ISR_WCOL_Msk;
}

FlagStatus I2C_SSP_ISR_WCOL_Chk(void)
{
	if (I2C->SSP_ISR & I2C_SSP_ISR_WCOL_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* SSPBUF溢出标志 相关函数 */
void I2C_SSP_ISR_SSPOV_Clr(void)
{
	I2C->SSP_ISR = I2C_SSP_ISR_SSPOV_Msk;
}

FlagStatus I2C_SSP_ISR_SSPOV_Chk(void)
{
	if (I2C->SSP_ISR & I2C_SSP_ISR_SSPOV_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 从机地址匹配标志 相关函数 */
void I2C_SSP_ISR_ADM_Clr(void)
{
	I2C->SSP_ISR = I2C_SSP_ISR_ADM_Msk;
}

FlagStatus I2C_SSP_ISR_ADM_Chk(void)
{
	if (I2C->SSP_ISR & I2C_SSP_ISR_ADM_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* I2C从机发送完成标志 相关函数 */
void I2C_SSP_ISR_TXIF_Clr(void)
{
	I2C->SSP_ISR = I2C_SSP_ISR_TXIF_Msk;
}

FlagStatus I2C_SSP_ISR_TXIF_Chk(void)
{
	if (I2C->SSP_ISR & I2C_SSP_ISR_TXIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* I2C从机接收完成标志 相关函数 */
void I2C_SSP_ISR_RXIF_Clr(void)
{
	I2C->SSP_ISR = I2C_SSP_ISR_RXIF_Msk;
}

FlagStatus I2C_SSP_ISR_RXIF_Chk(void)
{
	if (I2C->SSP_ISR & I2C_SSP_ISR_RXIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 从机通信标志 相关函数 */
FlagStatus I2C_SSP_SR_BUSY_Chk(void)
{
	if (I2C->SSP_SR & I2C_SSP_SR_BUSY_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 读写方向状态寄存器 相关函数 */
FlagStatus I2C_SSP_SR_RW_Chk(void)
{
	if (I2C->SSP_SR & I2C_SSP_SR_RW_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* data/address帧指示 相关函数 */
FlagStatus I2C_SSP_SR_DA_Chk(void)
{
	if (I2C->SSP_SR & I2C_SSP_SR_DA_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 从机数据缓冲区满标志 相关函数 */
FlagStatus I2C_SSP_SR_BF_Chk(void)
{
	if (I2C->SSP_SR & I2C_SSP_SR_BF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* I2C从机收发缓存寄存器 相关函数 */
void I2C_SSP_BUF_Write(uint32_t SetValue)
{
	I2C->SSP_BUF = (SetValue & I2C_SSP_BUF_SSPBUF_Msk);
}

uint32_t I2C_SSP_BUF_Read(void)
{
	return (I2C->SSP_BUF & I2C_SSP_BUF_SSPBUF_Msk);
}

/* I2C从机地址寄存器 相关函数 */
void I2C_SSP_ADR_SSPADDR_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = I2C->SSP_ADR;
	tmpreg &= ~(I2C_SSP_ADR_SSPADDR_Msk);
	tmpreg |= (SetValue & I2C_SSP_ADR_SSPADDR_Msk);
	I2C->SSP_ADR = tmpreg;
}

uint32_t I2C_SSP_ADR_SSPADDR_Get(void)
{
	return (I2C->SSP_ADR & I2C_SSP_ADR_SSPADDR_Msk);
}


void I2C_Deinit(void)
{
	RCC_PRST_EN_Write(RSTKEY0);
  RCC_APBRST_CR1_I2CRST_Setable(ENABLE);  
  RCC_APBRST_CR1_I2CRST_Setable(DISABLE);
  RCC_PRST_EN_Write(RSTKEY1);
}
 /********************************
 I2C波特率寄存器值计算函数
功能：I2C波特率寄存器值计算
输入：期望波特率@Hz， APBClk @Hz
输出：I2CBRG对应期望波特率的配置值
********************************/
uint32_t I2C_BaudREG_Calc(uint32_t I2CClk, uint32_t APBClk)
{
	uint32_t TempREG;
	
	TempREG = APBClk/(2*I2CClk);
	if( TempREG >= 1 ) TempREG = TempREG - 1;
	
	return TempREG;
}
/******END OF FILE****/  
