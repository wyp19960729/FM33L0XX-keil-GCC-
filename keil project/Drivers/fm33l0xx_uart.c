/**
  ******************************************************************************
  * @file    fm33l0xx_uart.c
  * @author  FM33L0 Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33l0xx_uart.h" 
#include "fm33l0xx_rcc.h" 

/** @addtogroup fm33l0_StdPeriph_Driver
  * @{
  */

/** @defgroup UART 
  * @brief UART driver modules
  * @{
  */ 
  
/* 控制红外调制发送数据时的默认输出极性 相关函数 */
void UART_IRCR_IRFLAG_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		UART_COMMON->IRCR |= (UART_IRCR_IRFLAG_Msk);
	}
	else
	{
		UART_COMMON->IRCR &= ~(UART_IRCR_IRFLAG_Msk);
	}
}

FunState UART_IRCR_IRFLAG_Getable(void)
{
	if (UART_COMMON->IRCR & (UART_IRCR_IRFLAG_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 红外占空比调制参数 相关函数 */
void UART_IRCR_TH_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = UART_COMMON->IRCR;
	tmpreg &= ~(UART_IRCR_TH_Msk);
	tmpreg |= (SetValue & UART_IRCR_TH_Msk);
	UART_COMMON->IRCR = tmpreg;
}

uint32_t UART_IRCR_TH_Get(void)
{
	return (UART_COMMON->IRCR & UART_IRCR_TH_Msk);
}

/* 红外调制频率 相关函数 */
void UART_IRCR_TZBRG_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = UART_COMMON->IRCR;
	tmpreg &= ~(UART_IRCR_TZBRG_Msk);
	tmpreg |= (SetValue & UART_IRCR_TZBRG_Msk);
	UART_COMMON->IRCR = tmpreg;
}

uint32_t UART_IRCR_TZBRG_Get(void)
{
	return (UART_COMMON->IRCR & UART_IRCR_TZBRG_Msk);
}

/* UART通信标志 相关函数 */
FlagStatus UARTx_CSR_BUSY_Chk(UART_Type* UARTx)
{
	if (UARTx->CSR & UARTx_CSR_BUSY_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 发送红外调制使能位 相关函数 */
void UARTx_CSR_TXIREN_Setable(UART_Type* UARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		UARTx->CSR |= (UARTx_CSR_TXIREN_Msk);
	}
	else
	{
		UARTx->CSR &= ~(UARTx_CSR_TXIREN_Msk);
	}
}

FunState UARTx_CSR_TXIREN_Getable(UART_Type* UARTx)
{
	if (UARTx->CSR & (UARTx_CSR_TXIREN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 接收超时使能 相关函数 */
void UARTx_CSR_RXTOEN_Setable(UART_Type* UARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		UARTx->CSR |= (UARTx_CSR_RXTOEN_Msk);
	}
	else
	{
		UARTx->CSR &= ~(UARTx_CSR_RXTOEN_Msk);
	}
}

FunState UARTx_CSR_RXTOEN_Getable(UART_Type* UARTx)
{
	if (UARTx->CSR & (UARTx_CSR_RXTOEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* UART RX下降沿唤醒功能使能寄存器 相关函数 */
void UARTx_CSR_NEWUP_Setable(UART_Type* UARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		UARTx->CSR |= (UARTx_CSR_NEWUP_Msk);
	}
	else
	{
		UARTx->CSR &= ~(UARTx_CSR_NEWUP_Msk);
	}
}

FunState UARTx_CSR_NEWUP_Getable(UART_Type* UARTx)
{
	if (UARTx->CSR & (UARTx_CSR_NEWUP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* DMA发送完成中断使能，仅在UART通过DMA进行发送时有效 相关函数 */
void UARTx_CSR_DMATXIFCFG_Setable(UART_Type* UARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		UARTx->CSR |= (UARTx_CSR_DMATXIFCFG_Msk);
	}
	else
	{
		UARTx->CSR &= ~(UARTx_CSR_DMATXIFCFG_Msk);
	}
}

FunState UARTx_CSR_DMATXIFCFG_Getable(UART_Type* UARTx)
{
	if (UARTx->CSR & (UARTx_CSR_DMATXIFCFG_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 数据发送/接收时的位顺序 相关函数 */
void UARTx_CSR_BITORD_Set(UART_Type* UARTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = UARTx->CSR;
	tmpreg &= ~(UARTx_CSR_BITORD_Msk);
	tmpreg |= (SetValue & UARTx_CSR_BITORD_Msk);
	UARTx->CSR = tmpreg;
}

uint32_t UARTx_CSR_BITORD_Get(UART_Type* UARTx)
{
	return (UARTx->CSR & UARTx_CSR_BITORD_Msk);
}

/* 停止位宽度配置，仅对发送帧格式有效，接收时不判断停止位个数 相关函数 */
void UARTx_CSR_STOPCFG_Set(UART_Type* UARTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = UARTx->CSR;
	tmpreg &= ~(UARTx_CSR_STOPCFG_Msk);
	tmpreg |= (SetValue & UARTx_CSR_STOPCFG_Msk);
	UARTx->CSR = tmpreg;
}

uint32_t UARTx_CSR_STOPCFG_Get(UART_Type* UARTx)
{
	return (UARTx->CSR & UARTx_CSR_STOPCFG_Msk);
}

/* 每帧的数据长度选择；此寄存器对数据发送和接收同时有效 相关函数 */
void UARTx_CSR_PDSEL_Set(UART_Type* UARTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = UARTx->CSR;
	tmpreg &= ~(UARTx_CSR_PDSEL_Msk);
	tmpreg |= (SetValue & UARTx_CSR_PDSEL_Msk);
	UARTx->CSR = tmpreg;
}

uint32_t UARTx_CSR_PDSEL_Get(UART_Type* UARTx)
{
	return (UARTx->CSR & UARTx_CSR_PDSEL_Msk);
}

/* 校验位配置；此寄存器对数据发送和接收同时有效 相关函数 */
void UARTx_CSR_PARITY_Set(UART_Type* UARTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = UARTx->CSR;
	tmpreg &= ~(UARTx_CSR_PARITY_Msk);
	tmpreg |= (SetValue & UARTx_CSR_PARITY_Msk);
	UARTx->CSR = tmpreg;
}

uint32_t UARTx_CSR_PARITY_Get(UART_Type* UARTx)
{
	return (UARTx->CSR & UARTx_CSR_PARITY_Msk);
}

/* 接收数据极性配置 相关函数 */
void UARTx_CSR_RXPOL_Setable(UART_Type* UARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		UARTx->CSR |= (UARTx_CSR_RXPOL_Msk);
	}
	else
	{
		UARTx->CSR &= ~(UARTx_CSR_RXPOL_Msk);
	}
}

FunState UARTx_CSR_RXPOL_Getable(UART_Type* UARTx)
{
	if (UARTx->CSR & (UARTx_CSR_RXPOL_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 发送数据极性配置 相关函数 */
void UARTx_CSR_TXPOL_Setable(UART_Type* UARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		UARTx->CSR |= (UARTx_CSR_TXPOL_Msk);
	}
	else
	{
		UARTx->CSR &= ~(UARTx_CSR_TXPOL_Msk);
	}
}

FunState UARTx_CSR_TXPOL_Getable(UART_Type* UARTx)
{
	if (UARTx->CSR & (UARTx_CSR_TXPOL_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 接收使能，1有效 相关函数 */
void UARTx_CSR_RXEN_Setable(UART_Type* UARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		UARTx->CSR |= (UARTx_CSR_RXEN_Msk);
	}
	else
	{
		UARTx->CSR &= ~(UARTx_CSR_RXEN_Msk);
	}
}

FunState UARTx_CSR_RXEN_Getable(UART_Type* UARTx)
{
	if (UARTx->CSR & (UARTx_CSR_RXEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 发送使能，1有效 相关函数 */
void UARTx_CSR_TXEN_Setable(UART_Type* UARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		UARTx->CSR |= (UARTx_CSR_TXEN_Msk);
	}
	else
	{
		UARTx->CSR &= ~(UARTx_CSR_TXEN_Msk);
	}
}

FunState UARTx_CSR_TXEN_Getable(UART_Type* UARTx)
{
	if (UARTx->CSR & (UARTx_CSR_TXEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 接收超时中断使能，1有效 相关函数 */
void UARTx_IER_RXTO_IE_Setable(UART_Type* UARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		UARTx->IER |= (UARTx_IER_RXTO_IE_Msk);
	}
	else
	{
		UARTx->IER &= ~(UARTx_IER_RXTO_IE_Msk);
	}
}

FunState UARTx_IER_RXTO_IE_Getable(UART_Type* UARTx)
{
	if (UARTx->IER & (UARTx_IER_RXTO_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 接收错误中断使能，1有效 相关函数 */
void UARTx_IER_RXERR_IE_Setable(UART_Type* UARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		UARTx->IER |= (UARTx_IER_RXERR_IE_Msk);
	}
	else
	{
		UARTx->IER &= ~(UARTx_IER_RXERR_IE_Msk);
	}
}

FunState UARTx_IER_RXERR_IE_Getable(UART_Type* UARTx)
{
	if (UARTx->IER & (UARTx_IER_RXERR_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 接收缓存满中断使能，1有效 相关函数 */
void UARTx_IER_RXBF_IE_Setable(UART_Type* UARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		UARTx->IER |= (UARTx_IER_RXBF_IE_Msk);
	}
	else
	{
		UARTx->IER &= ~(UARTx_IER_RXBF_IE_Msk);
	}
}

FunState UARTx_IER_RXBF_IE_Getable(UART_Type* UARTx)
{
	if (UARTx->IER & (UARTx_IER_RXBF_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* RX下降沿异步检测中断使能，1有效 相关函数 */
void UARTx_IER_NEWUP_IE_Setable(UART_Type* UARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		UARTx->IER |= (UARTx_IER_NEWUP_IE_Msk);
	}
	else
	{
		UARTx->IER &= ~(UARTx_IER_NEWUP_IE_Msk);
	}
}

FunState UARTx_IER_NEWUP_IE_Getable(UART_Type* UARTx)
{
	if (UARTx->IER & (UARTx_IER_NEWUP_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 发送缓存空中断使能，1有效 相关函数 */
void UARTx_IER_TXBE_IE_Setable(UART_Type* UARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		UARTx->IER |= (UARTx_IER_TXBE_IE_Msk);
	}
	else
	{
		UARTx->IER &= ~(UARTx_IER_TXBE_IE_Msk);
	}
}

FunState UARTx_IER_TXBE_IE_Getable(UART_Type* UARTx)
{
	if (UARTx->IER & (UARTx_IER_TXBE_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 发送缓存空且发送移位寄存器空中断使能，1有效 相关函数 */
void UARTx_IER_TXSE_IE_Setable(UART_Type* UARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		UARTx->IER |= (UARTx_IER_TXSE_IE_Msk);
	}
	else
	{
		UARTx->IER &= ~(UARTx_IER_TXSE_IE_Msk);
	}
}

FunState UARTx_IER_TXSE_IE_Getable(UART_Type* UARTx)
{
	if (UARTx->IER & (UARTx_IER_TXSE_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* 奇偶校验错误中断标志，硬件置位，软件写1清零 相关函数 */
void UARTx_ISR_PERR_Clr(UART_Type* UARTx)
{
	UARTx->ISR = UARTx_ISR_PERR_Msk;
}

FlagStatus UARTx_ISR_PERR_Chk(UART_Type* UARTx)
{
	if (UARTx->ISR & UARTx_ISR_PERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 帧格式错误中断标志，硬件置位，软件写1清零 相关函数 */
void UARTx_ISR_FERR_Clr(UART_Type* UARTx)
{
	UARTx->ISR = UARTx_ISR_FERR_Msk;
}

FlagStatus UARTx_ISR_FERR_Chk(UART_Type* UARTx)
{
	if (UARTx->ISR & UARTx_ISR_FERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 接收缓存溢出错误中断标志，当接收缓存满的情况下，收到新的数据时置位；硬件置位，软件写1或者读取RXBUF时清零
接收溢出时，接收缓冲器中原有的数据被新数据覆盖 相关函数 */
void UARTx_ISR_OERR_Clr(UART_Type* UARTx)
{
	UARTx->ISR = UARTx_ISR_OERR_Msk;
}

FlagStatus UARTx_ISR_OERR_Chk(UART_Type* UARTx)
{
	if (UARTx->ISR & UARTx_ISR_OERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 接收超时中断标志，硬件置位，软件写1清零（仅UART0和UART1有效） 相关函数 */
void UARTx_ISR_RXTO_Clr(UART_Type* UARTx)
{
	UARTx->ISR = UARTx_ISR_RXTO_Msk;
}

FlagStatus UARTx_ISR_RXTO_Chk(UART_Type* UARTx)
{
	if (UARTx->ISR & UARTx_ISR_RXTO_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 接收缓存满中断标志，硬件置位，软件写1或者读取RXBUF时清零 相关函数 */
void UARTx_ISR_RXBF_Clr(UART_Type* UARTx)
{
	UARTx->ISR = UARTx_ISR_RXBF_Msk;
}

FlagStatus UARTx_ISR_RXBF_Chk(UART_Type* UARTx)
{
	if (UARTx->ISR & UARTx_ISR_RXBF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* RX下降沿异步检测中断标志，硬件置位，软件写1清零 相关函数 */
void UARTx_ISR_NEWKF_Clr(UART_Type* UARTx)
{
	UARTx->ISR = UARTx_ISR_NEWKF_Msk;
}

FlagStatus UARTx_ISR_NEWKF_Chk(UART_Type* UARTx)
{
	if (UARTx->ISR & UARTx_ISR_NEWKF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 发送缓存空中断标志，硬件置位，软件写入TXBUF时清零 相关函数 */
void UARTx_ISR_TXBE_Clr(UART_Type* UARTx)
{
	UARTx->ISR = UARTx_ISR_TXBE_Msk;
}

FlagStatus UARTx_ISR_TXBE_Chk(UART_Type* UARTx)
{
	if (UARTx->ISR & UARTx_ISR_TXBE_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 发送缓存空且移位寄存器发送完成中断标志，硬件置位，软件写1或者软件写发送缓存时清零 相关函数 */
void UARTx_ISR_TXSE_Clr(UART_Type* UARTx)
{
	UARTx->ISR = UARTx_ISR_TXSE_Msk;
}

FlagStatus UARTx_ISR_TXSE_Chk(UART_Type* UARTx)
{
	if (UARTx->ISR & UARTx_ISR_TXSE_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* 发送延迟，最大255baud 相关函数 */
void UARTx_TODR_TXDLY_LEN_Set(UART_Type* UARTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = UARTx->TODR;
	tmpreg &= ~(UARTx_TODR_TXDLY_LEN_Msk);
	tmpreg |= (SetValue & UARTx_TODR_TXDLY_LEN_Msk);
	UARTx->TODR = tmpreg;
}

uint32_t UARTx_TODR_TXDLY_LEN_Get(UART_Type* UARTx)
{
	return (UARTx->TODR & UARTx_TODR_TXDLY_LEN_Msk);
}

void UARTx_TODR_RXTO_LEN_Set(UART_Type* UARTx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = UARTx->TODR;
	tmpreg &= ~(UARTx_TODR_RXTO_LEN_Msk);
	tmpreg |= (SetValue & UARTx_TODR_RXTO_LEN_Msk);
	UARTx->TODR = tmpreg;
}

uint32_t UARTx_TODR_RXTO_LEN_Get(UART_Type* UARTx)
{
	return (UARTx->TODR & UARTx_TODR_RXTO_LEN_Msk);
}

/* 接收数据缓冲寄存器数据 相关函数 */
uint32_t UARTx_RXBUF_Read(UART_Type* UARTx)
{
	return (UARTx->RXBUF & UARTx_RXBUF_RXBUF_Msk);
}

/* 发送数据缓冲寄存器数据 相关函数 */
void UARTx_TXBUF_Write(UART_Type* UARTx, uint32_t SetValue)
{
	UARTx->TXBUF = (SetValue & UARTx_TXBUF_TXBUF_Msk);
}

/* 波特率产生器寄存器值 相关函数 */
void UARTx_BGR_Write(UART_Type* UARTx, uint32_t SetValue)
{
	UARTx->BGR = (SetValue & UARTx_BGR_SPBRG_Msk);
}

uint32_t UARTx_BGR_Read(UART_Type* UARTx)
{
	return (UARTx->BGR & UARTx_BGR_SPBRG_Msk);
}


void UART_Deinit(void)
{
	//UART->IRCR = 0x000000D2;
}
void UARTx_Deinit(UART_Type* UARTx)
{
	if(UARTx==UART0)
  {
    RCC_PRST_EN_Write(RSTKEY0);
    RCC_APBRST_CR2_UART0RST_Setable(ENABLE);  
    RCC_APBRST_CR2_UART0RST_Setable(DISABLE);
    RCC_PRST_EN_Write(RSTKEY1);
  }
  if(UARTx==UART1)
  {
    RCC_PRST_EN_Write(RSTKEY0);
    RCC_APBRST_CR2_UART1RST_Setable(ENABLE);  
    RCC_APBRST_CR2_UART1RST_Setable(DISABLE);
    RCC_PRST_EN_Write(RSTKEY1);
  }
  if(UARTx==UART4)
  {
    RCC_PRST_EN_Write(RSTKEY0);
    RCC_APBRST_CR1_UART4RST_Setable(ENABLE);  
    RCC_APBRST_CR1_UART4RST_Setable(DISABLE);
    RCC_PRST_EN_Write(RSTKEY1);
  }
  if(UARTx==UART5)
  {
    RCC_PRST_EN_Write(RSTKEY0);
    RCC_APBRST_CR1_UART5RST_Setable(ENABLE);  
    RCC_APBRST_CR1_UART5RST_Setable(DISABLE);
    RCC_PRST_EN_Write(RSTKEY1);
  }
}
/********************************
红外调制频率占空比配置函数
功能:红外调制频率占空比配置函数
输入：红外调制频率占空比配置
********************************/
void UART_IRModulation_Init( uint32_t ModuFreq, uint8_t ModuDutyCycle, uint32_t APBClk )
{
	uint32_t tempTZBRG, tempTH;
	
	if((ModuFreq > 0)&&(APBClk >= ModuFreq)&&(ModuDutyCycle < 100))
	{
		tempTZBRG = (uint32_t)((float)APBClk/(float)ModuFreq + 0.5) - 1;
		UART_IRCR_TZBRG_Set((tempTZBRG&UART_IRCR_TZBRG_Msk)<<UART_IRCR_TZBRG_Pos);//红外调制频率配置
		
		if((tempTZBRG>>4) != 0)
		{
			
			tempTH = (uint32_t)(((float)ModuDutyCycle/100.0)*((float)(tempTZBRG + 1)/(float)(tempTZBRG>>4)) + 0.5);
		}
		else
		{
			tempTH = (uint32_t)(((float)ModuDutyCycle/100.0)*(float)(tempTZBRG + 1) + 0.5);
			
		}
		UART_IRCR_TH_Set((tempTH<<UART_IRCR_TH_Pos)&UART_IRCR_TH_Msk);//红外调制占空比配置
	}
}

/********************************
UART完整参数初始化函数
功能:UART完整参数初始化
输入：串口号 参数
********************************/
void UART_Init(UART_Type* UARTx, UART_InitTypeDef* para)
{
	UARTx_BGR_Write(UARTx, para->SPBRG);		//波特率产生器寄存器

	UARTx_CSR_PDSEL_Set(UARTx, para->PDSEL);		// 数据长度选择
	UARTx_CSR_PARITY_Set(UARTx, para->PARITY);		// 校验位配置
	
	UARTx_CSR_STOPCFG_Set(UARTx, para->STOPSEL);	//停止位选择
	
	UARTx_IER_RXERR_IE_Setable(UARTx, para->ERRIE);		//错误中断使能控制


	UARTx_IER_RXBF_IE_Setable(UARTx, para->RXIE);		//接收中断
	UARTx_IER_TXBE_IE_Setable(UARTx, para->TXBE_IE);		//发送中断
	UARTx_IER_TXSE_IE_Setable(UARTx, para->TXSE_IE);		//发送中断
	
	UARTx_CSR_RXPOL_Setable(UARTx, para->RXDFLAG);	//接收数据取反控制位
	UARTx_CSR_TXPOL_Setable(UARTx, para->TXDFLAG);	//发送数据取反控制位

	UARTx_CSR_RXEN_Setable(UARTx, para->RXEN);		//接收模块使能控制
	UARTx_CSR_TXEN_Setable(UARTx, para->TXEN);		//发送模块使能控制
	UARTx_CSR_TXIREN_Setable(UARTx, para->IREN);		//发送红外调制使能位
}
/********************************
写入波特率产生器寄存器函数
功能:写入波特率
输入:要设置的波特率
********************************/
void UARTx_SPBRG_Write(UART_Type* UARTx, uint32_t SetValue)
{
	UARTx->BGR = (SetValue & UARTx_BGR_SPBRG_Msk);
}
uint32_t UART_BaudREGCalc(uint32_t BaudRate, uint32_t APBClk)
{
	uint32_t tmpSPBRG;
	float tmpfloat;
	
	tmpfloat = (float)APBClk/(float)BaudRate;
	
	if(tmpfloat > 1)
	{
		tmpSPBRG = (uint32_t)(tmpfloat - 1.0 + 0.5);
	}
	else
	{
		tmpSPBRG = 0;
	}
	
	return tmpSPBRG;
}


/********************************
UART简单参数初始化函数函数
功能:UART简单参数初始化
输入：串口号 参数
********************************/
void UART_SInit(UART_Type* UARTx, UART_SInitTypeDef* para, uint32_t APBClk)
{
	UART_InitTypeDef para2;
		
	para2.SPBRG = UART_BaudREGCalc(para->BaudRate, APBClk);
		
	if(Eight8Bit == para->DataBit)
	{
		  para2.PDSEL = UARTx_CSR_PDSEL_8BIT;
			if(EVEN == para->ParityBit)
			{
				para2.PARITY= UARTx_CSR_PARITY_EVEN;//8bit偶校验
			}
			else if(ODD == para->ParityBit)
			{
				para2.PARITY = UARTx_CSR_PARITY_ODD;//8bit奇校验
			}
			else
			{
				para2.PARITY = UARTx_CSR_PARITY_NONE;//8bit数据无校验
			}
	}
	else if(Nine9Bit == para->DataBit)
	{
		  para2.PDSEL = UARTx_CSR_PDSEL_9BIT;
			if(EVEN == para->ParityBit)
			{
				para2.PARITY = UARTx_CSR_PARITY_EVEN;//9bit偶校验
			}
			else if(ODD == para->ParityBit)
			{
				para2.PARITY = UARTx_CSR_PARITY_ODD;//9bit奇校验
			}
			else
			{
				para2.PARITY = UARTx_CSR_PARITY_NONE;//9bit数据无校验
			}
	}
		else if(Seven7Bit == para->DataBit)
	{
		  para2.PDSEL = UARTx_CSR_PDSEL_7BIT;
			if(EVEN == para->ParityBit)
			{
				para2.PARITY = UARTx_CSR_PARITY_EVEN;//7bit偶校验
			}
			else if(ODD == para->ParityBit)
			{
				para2.PARITY = UARTx_CSR_PARITY_ODD;//7bit奇校验
			}
			else
			{
				para2.PARITY = UARTx_CSR_PARITY_NONE;//7bit数据无校验
			}
	}
	else
	{
		  para2.PDSEL = UARTx_CSR_PDSEL_6BIT;
			if(EVEN == para->ParityBit)
			{
				para2.PARITY = UARTx_CSR_PARITY_EVEN;//8bit偶校验
			}
			else if(ODD == para->ParityBit)
			{
				para2.PARITY = UARTx_CSR_PARITY_ODD;//8bit奇校验
			}
			else
			{
				para2.PARITY = UARTx_CSR_PARITY_NONE;//8bit数据无校验
			}

	}
	
	if(OneBit == para->StopBit)
	{
		para2.STOPSEL = UARTx_CSR_STOPCFG_1STOPBIT;
	}
	else
	{
		para2.STOPSEL = UARTx_CSR_STOPCFG_2STOPBIT;
	}
	
	para2.RXIE = DISABLE;		//关闭接收中断
	para2.TXBE_IE = DISABLE;		//关闭发送中断
	para2.TXSE_IE = DISABLE;		//关闭发送中断
	para2.ERRIE = DISABLE;		//关闭错误中断

	para2.RXDFLAG = DISABLE;	//关闭接收数据取反控制位
	para2.TXDFLAG = DISABLE;	//关闭发送数据取反控制位

	para2.RXEN = DISABLE;		//关闭接收模块使能控制
	para2.TXEN = DISABLE;		//关闭发送模块使能控制
	para2.IREN = DISABLE;		//关闭发送红外调制使能位
	
	UART_Init(UARTx, &para2);
}
/******END OF FILE****/
