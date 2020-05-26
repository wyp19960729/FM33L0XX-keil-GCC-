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
  
/* U7816通道发送使能控制 相关函数 */
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

/* U7816通道接收使能控制 相关函数 */
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

/* U7816时钟CLK输出使能控制 相关函数 */
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

/* U7816通道数据发送强上拉电阻自动有效控制 相关函数 */
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

/* U7816通道强上拉使能控制 相关函数 */
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

/* GUARD TIME 发送长度控制 相关函数 */
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

/* ERROR SIGNAL宽度选择 相关函数 */
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

/* ERROR SIGNAL后GUARDTIME宽度选择（仅在发送时有效） 相关函数 */
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

/* BGT（block guard time）控制 相关函数 */
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

/* 控制接收数据奇偶校验出错时自动重发次数 相关函数 */
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

/* 奇偶校验类型选择 相关函数 */
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

/* Guard Time长度控制位（发送时严格按照协议2etu） 相关函数 */
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

/* 缓发送数据奇偶校验错的处理方式选择 相关函数 */
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

/* 接收数据奇偶校验错的处理方式选择 相关函数 */
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

/* 传输次序反向编码使能 相关函数 */
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

/* 发送时插入的EGT时间（以ETU为单位） 相关函数 */
void U7816_EGTR_Write(uint32_t SetValue)
{
	U7816->EGTR = (SetValue & U7816_EGTR_TXEGT_Msk);
}

uint32_t U7816_EGTR_Read(void)
{
	return (U7816->EGTR & U7816_EGTR_TXEGT_Msk);
}

/* U7816时钟输出分频控制寄存器 相关函数 */
void U7816_PSC_Write(uint32_t SetValue)
{
	U7816->PSC = (SetValue & U7816_PSC_CLKDIV_Msk);
}

uint32_t U7816_PSC_Read(void)
{
	return (U7816->PSC & U7816_PSC_CLKDIV_Msk);
}

/* U7816预分频控制寄存器，控制7816通信分频比（波特率） 相关函数 */
void U7816_BGR_Write(uint32_t SetValue)
{
	U7816->BGR = (SetValue & U7816_BGR_PDIV_Msk);
}

uint32_t U7816_BGR_Read(void)
{
	return (U7816->BGR & U7816_BGR_PDIV_Msk);
}

/* U7816数据接收缓存寄存器 相关函数 */
uint32_t U7816_RXBUF_Read(void)
{
	return (U7816->RXBUF & U7816_RXBUF_RXBUF_Msk);
}

/* U7816数据发送缓存寄存器 相关函数 */
void U7816_TXBUF_Write(uint32_t SetValue)
{
	U7816->TXBUF = (SetValue & U7816_TXBUF_TXBUF_Msk);
}

/* 数据接收中断使能位。对应RX_FLAG中断标志位 相关函数 */
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

/* 数据发送中断使能位。对应TX_FLAG中断标志位 相关函数 */
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

/* 线路状态中断使能位。对应ERROR_FLAG中断标志位 相关函数 */
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

/* U7816接口发送了错误信号，正在等待对方重发数据.状态机进入发送错误信号状态时置位，收到数据起始位或者进入发送状态时硬件清零;
 相关函数 */
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

/* 发送数据忙标志 相关函数 */
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

/* 接收数据忙标志 相关函数 */
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

/* 发送数据奇偶校验错误标志位 相关函数 */
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

/* 接收数据奇偶校验错误标志位 相关函数 */
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

/* 接收帧格式错误标志位 相关函数 */
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

/* 接收溢出错误标志位 相关函数 */
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

/* 接收完成标志 相关函数 */
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

/* 发送缓冲区空标志 相关函数 */
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

/* 错误标志，寄存器配置出错或传输过程中出错。硬件置位，清U7816ERR中相应错误 相关函数 */
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

/* U7816完整参数初始化函数 */
void U7816_Init(U7816_InitTypeDef* para)
{
	U7816_CR_TXEN_Setable(para->TXEN);		//发送使能
	U7816_CR_RXEN_Setable(para->RXEN);		//接收使能
	U7816_CR_CKOEN_Setable(para->CKOEN);		//U7816时钟CLK输出使能控制
	U7816_CR_HPUAT_Setable(para->HPUAT);		//U7816通道数据发送强上拉电阻自动有效控制
	U7816_CR_HPUEN_Setable(para->HPUEN);		//U7816通道强上拉使能控制
	
	U7816_FFR_ERSW_Set(para->ERSW);		//ERROR SIGNAL宽度选择
	U7816_FFR_ERSGD_Set(para->ERSGD);		//ERROR SIGNAL后GUARDTIME宽度选择（仅在发送时有效）
	U7816_FFR_BGTEN_Setable(para->BGTEN);		//BGT（block guard time）控制
	U7816_FFR_REP_T_Set(para->REP_T);		//控制接收数据奇偶校验出错时自动重发次数
	U7816_FFR_PAR_Set(para->PAR);		//奇偶校验类型选择
	U7816_FFR_RFREN_Set(para->RFREN);		//接收时Guard Time长度控制位（发送时严格按照协议2etu）
	U7816_FFR_SFREN_Set(para->RFREN);		//接收时Guard Time长度控制位（发送时严格按照协议2etu）
  U7816_FFR_TREPEN_Setable(para->TREPEN);		//缓发送数据奇偶校验错的处理方式选择
	U7816_FFR_RREPEN_Setable(para->RREPEN);		//接收数据奇偶校验错的处理方式选择
	U7816_FFR_DICONV_Setable(para->DICONV);		//传输次序反向编码使能
	
	U7816_EGTR_Write(para->TXEGT);		//发送时插入的EGT时间（以ETU为单位）
	U7816_PSC_Write(para->CLKDIV);		//U7816时钟输出分频控制寄存器
	U7816_BGR_Write( para->PDIV);		//U7816预分频控制寄存器，控制7816通信分频比（波特率）
	
	U7816_IER_RXIE_Setable(para->RXIE);		//数据接收中断使能位。对应RX_FLAG中断标志位
	U7816_IER_TXIE_Setable(para->TXIE);		//数据发送中断使能位。对应TX_FLAG中断标志位
	U7816_IER_LSIE_Setable(para->LSIE);		//线路状态中断使能位。对应ERROR_FLAG中断标志位
}

/******END OF FILE****/
