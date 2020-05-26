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
  
/* 通信状态 相关函数 */
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

/* 数据接收唤醒条件配置 相关函数 */
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

/* 唤醒中断事件配置 相关函数 */
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

/* DMA发送完成中断使能 相关函数 */
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

/* 数据发送和接收的位顺序 相关函数 */
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

/* 发送时停止位设置 相关函数 */
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

/* 每帧数据长度 相关函数 */
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

/* 校验位配置 相关函数 */
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

/* 接收数据极性 相关函数 */
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

/* 发送数据极性 相关函数 */
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

/* 接收使能控制 相关函数 */
void LPUARTx_CSR_RXEN_Setable(LPUART_Type* LPUARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPUARTx->CSR |= (LPUARTx_CSR_RXEN_Msk);
    while(((LPUARTx->CSR)&LPUARTx_CSR_RXEN_Msk)==0);//寄存器与模块不同步，必须确认已经写进寄存器，防止写其他bit时覆盖掉
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

/* 发送使能控制 相关函数 */
void LPUARTx_CSR_TXEN_Setable(LPUART_Type* LPUARTx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		LPUARTx->CSR |= (LPUARTx_CSR_TXEN_Msk);
    while(((LPUARTx->CSR)&LPUARTx_CSR_TXEN_Msk)==0); //寄存器与模块不同步，必须确认已经写进寄存器，防止写其他bit时覆盖掉
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

/* 接收唤醒事件中断使能 相关函数 */
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

/* 接收错误中断使能 相关函数 */
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

/* 接收缓存满中断使能 相关函数 */
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

/* 发送缓存空中断使能 相关函数 */
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

/* 发送缓存空且发送移位寄存器空中断使能 相关函数 */
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

/* 接收唤醒事件中断标志 相关函数 */
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

/* 发送缓存溢出错误标志 相关函数 */
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

/* 奇偶校验错误中断标志 相关函数 */
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

/* 帧格式错误中断标志 相关函数 */
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

/* 接收缓存溢出错误中断标志 相关函数 */
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

/* 接收缓存满中断标志 相关函数 */
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

/* 发送缓存空中断标志 相关函数 */
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

/* 发送缓存空且发送移位寄存器空中断标志 相关函数 */
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

/* 每个bit的位宽调制控制信号 相关函数 */
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

/* 波特率控制 相关函数 */
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

/* 接收数据缓冲 相关函数 */
uint32_t LPUARTx_RXBUF_Read(LPUART_Type* LPUARTx)
{
	return (LPUARTx->RXBUF & LPUARTx_RXBUF_RXBUF_Msk);
}

/* 发送数据缓冲 相关函数 */
void LPUARTx_TXBUF_Write(LPUART_Type* LPUARTx, uint32_t SetValue)
{
	LPUARTx->TXBUF = (SetValue & LPUARTx_TXBUF_TXBUF_Msk);
}

/* 数据匹配寄存器 相关函数 */
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

/*LPUART  完整参数初始化函数 */
void LPUART_Init(LPUART_Type* LPUARTx,LPUART_InitTypeDef* para)
{
	LPUARTx_BMR_BAUD_Set(LPUARTx,para->BAUD);		//波特率控制
	LPUARTx_CSR_TXEN_Setable(LPUARTx,para->TXEN);		//发送使能
	LPUARTx_CSR_RXEN_Setable(LPUARTx,para->RXEN);		//接收使能
	LPUARTx_DMR_Write(LPUARTx,para->MATD);		//数据匹配寄存器
	LPUARTx_BMR_MCTL_Set(LPUARTx,para->MCTL);				//调制控制寄存器
	
	LPUARTx_CSR_STOPCFG_Set(LPUARTx,para->STOPCFG);				//停止位长度
	LPUARTx_CSR_PDSEL_Set(LPUARTx,para->PDSEL);				//数据长度
	LPUARTx_CSR_PARITY_Set(LPUARTx,para->PARITY);			//校验位类型
  
	LPUARTx_CSR_WKBYTECFG_Setable(LPUARTx,para->WKBYTECFG);//接收唤醒条件配置
	LPUARTx_CSR_RXEV_Set(LPUARTx,para->RXEV);		//接收中断事件配置
  LPUARTx_IER_RXEV_IE_Setable(LPUARTx,para->RXEVIE);//接收事件唤醒中断
	LPUARTx_IER_TXSE_IE_Setable(LPUARTx,para->TXSEIE);		//发送完成中断使能
	LPUARTx_IER_TXBE_IE_Setable(LPUARTx,para->TXBEIE);		//发送buffer空中断使能
	LPUARTx_IER_RXBF_IE_Setable(LPUARTx,para->RXBFIE);		//接收中断使能
  LPUARTx_IER_RXERR_IE_Setable(LPUARTx,para->RXERRIE);		//错误中断使能
	LPUARTx_CSR_TXPOL_Set(LPUARTx,para->TXPOL);		//数据发送极性取反使能
	LPUARTx_CSR_RXPOL_Set(LPUARTx,para->RXPOL);		//数据接收极性取反控制	
}

/*LPUART 简单参数初始化函数 */
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
	
	//停止位长度
	if(OneBit == para->StopBit)
	{
		para2.STOPCFG = LPUARTx_CSR_STOPCFG_1BIT;
	}
	else
	{
		para2.STOPCFG = LPUARTx_CSR_STOPCFG_2BIT;
	}
	//数据位长度
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
	
	//校验位
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
	
	para2.RXEV =LPUARTx_CSR_RXEV_1BYTE;		//接收中断事件配置
  para2.WKBYTECFG = ENABLE;		//数据唤醒条件配置
	para2.TXSEIE = DISABLE;		//发送完成中断使能
	para2.TXBEIE = DISABLE;		//发送buffer空中断使能
	para2.RXBFIE = DISABLE;		//接收中断使能
	para2.TXPOL = DISABLE;		//数据发送极性取反使能
	para2.RXPOL = DISABLE;		//数据接收极性取反控制
	para2.RXERRIE = DISABLE;		//错误中断使能	
	LPUART_Init(LPUARTx,&para2);
}
/******END OF FILE****/
