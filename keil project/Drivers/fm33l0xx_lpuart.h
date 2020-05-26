/**
  ******************************************************************************
  * @file    fm33l0xx_lpuart.h
  * @author  FM33L0xx Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file contains all the functions prototypes for the LPUART firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33L0XX_LPUART_H
#define __FM33L0XX_LPUART_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33L0XX.h" 
#include "fm33l0xx_uart.h" 
   
//-----------------------------------------------------------------------------------------------------------------------------
typedef struct
{
	uint32_t				BaudRate;		//波特率
	UART_DataBitTypeDef		DataBit;		//数据位数
	UART_ParityBitTypeDef	ParityBit; 		//校验位
	UART_StopBitTypeDef		StopBit;		//停止位
	
}LPUART_SInitTypeDef;	

typedef struct
{
	uint32_t				BAUD;	//波特率控制
	FunState				TXEN;		//发送使能
	FunState				RXEN;		//接收使能
	uint32_t				MATD;	//数据匹配寄存器
	uint32_t				MCTL;		//调制控制寄存器
	
	uint32_t				STOPCFG;			//停止位长度
	uint32_t				PDSEL;			//数据长度
	uint32_t				PARITY;		//校验位类型
	
	uint32_t				RXEV;		//接收中断事件配置
  
  FunState				RXEVIE;		//接收唤醒事件中断
	FunState				TXSEIE;		//发送缓存且移位寄存器空中断
	FunState				TXBEIE;		//发送buffer空中断
	FunState				RXBFIE;		//接收缓存满中断
	FunState				TXPOL;		//数据发送极性取反使能
	FunState				RXPOL;		//数据接收极性取反控制
	FunState				WKBYTECFG;	//数据唤醒条件配置
	FunState				RXERRIE;		//接收错误中断使能
	
}LPUART_InitTypeDef;

#define LPU_LSCLK    RCC_OPC_CR1_LPUART1CKS_LSCLK
#define LPU_RCHFDIV  RCC_OPC_CR1_LPUART1CKS_RCHFDIV
#define LPU_RC4MDIV  RCC_OPC_CR1_LPUART1CKS_RC4MDIV

#define LPUARTx_MCTL_FOR9600 (0x00000552<<16)
#define LPUARTx_MCTL_FOR4800 (0x00001EFB<<16)
#define LPUARTx_MCTL_FOR2400 (0x000016DB<<16)
#define LPUARTx_MCTL_FOR1200 (0x00000492<<16)
#define LPUARTx_MCTL_FOR600  (0x000016D6<<16)
#define LPUARTx_MCTL_FOR300  (0x00000842<<16)


#define	LPUARTx_CSR_BUSY_Pos	24	/* 通信状态 */
#define	LPUARTx_CSR_BUSY_Msk	(0x1U << LPUARTx_CSR_BUSY_Pos)

#define	LPUARTx_CSR_WKBYTECFG_Pos	19	/* 数据接收唤醒条件配置 */
#define	LPUARTx_CSR_WKBYTECFG_Msk	(0x1U << LPUARTx_CSR_WKBYTECFG_Pos)
	/* 0 = 休眠时接收1字节就会唤醒，不校验奇偶和停止位 */
	/* 1 = 休眠时接收1字节，并且校验奇偶和停止位正确才唤醒 */

#define	LPUARTx_CSR_RXEV_Pos	16	/* 唤醒中断事件配置 */
#define	LPUARTx_CSR_RXEV_Msk	(0x3U << LPUARTx_CSR_RXEV_Pos)
#define	LPUARTx_CSR_RXEV_FALLING	(0x3U << LPUARTx_CSR_RXEV_Pos)	/* 11 = RXD下降沿检测唤醒 */
#define	LPUARTx_CSR_RXEV_MATCH	(0x2U << LPUARTx_CSR_RXEV_Pos)	/* 10 = 接收数据匹配成功唤醒 */
#define	LPUARTx_CSR_RXEV_1BYTE	(0x1U << LPUARTx_CSR_RXEV_Pos)	/* 01 = 1 BYTE数据接收完成唤醒 */
#define	LPUARTx_CSR_RXEV_START	(0x0U << LPUARTx_CSR_RXEV_Pos)	/* 00 = START位检测唤醒 */

#define	LPUARTx_CSR_DMATXIFCFG_Pos	10	/* DMA发送完成中断使能 */
#define	LPUARTx_CSR_DMATXIFCFG_Msk	(0x1U << LPUARTx_CSR_DMATXIFCFG_Pos)
	/* 0 = 是否允许中断信号输出仅由IE决定 */
	/* 1 = IE为1时，DMA发送完最后一帧允许中断信号输出 */

#define	LPUARTx_CSR_BITORD_Pos	9	/* 数据发送和接收的位顺序 */
#define	LPUARTx_CSR_BITORD_Msk	(0x1U << LPUARTx_CSR_BITORD_Pos)
#define	LPUARTx_CSR_BITORD_LSB	(0x0U << LPUARTx_CSR_BITORD_Pos)	/* 0 = LSB first */
#define	LPUARTx_CSR_BITORD_MSB	(0x1U << LPUARTx_CSR_BITORD_Pos)	/* 1 = MSB first */

#define	LPUARTx_CSR_STOPCFG_Pos	8	/* 发送时停止位设置 */
#define	LPUARTx_CSR_STOPCFG_Msk	(0x1U << LPUARTx_CSR_STOPCFG_Pos)
#define	LPUARTx_CSR_STOPCFG_1BIT	(0x0U << LPUARTx_CSR_STOPCFG_Pos)	/* 0 = 1bit停止位 */
#define	LPUARTx_CSR_STOPCFG_2BIT	(0x1U << LPUARTx_CSR_STOPCFG_Pos)	/* 1 = 2bit停止位 */

#define	LPUARTx_CSR_PDSEL_Pos	6	/* 每帧数据长度 */
#define	LPUARTx_CSR_PDSEL_Msk	(0x3U << LPUARTx_CSR_PDSEL_Pos)
#define	LPUARTx_CSR_PDSEL_6BIT	(0x3U << LPUARTx_CSR_PDSEL_Pos)	/* 11 = 6bit停止位 */
#define	LPUARTx_CSR_PDSEL_9BIT	(0x2U << LPUARTx_CSR_PDSEL_Pos)	/* 10 = 9bit停止位 */
#define	LPUARTx_CSR_PDSEL_8BIT	(0x1U << LPUARTx_CSR_PDSEL_Pos)	/* 01 = 8bit停止位 */
#define	LPUARTx_CSR_PDSEL_7BIT	(0x0U << LPUARTx_CSR_PDSEL_Pos)	/* 00 = 7bit停止位 */

#define	LPUARTx_CSR_PARITY_Pos	4	/* 校验位配置 */
#define	LPUARTx_CSR_PARITY_Msk	(0x3U << LPUARTx_CSR_PARITY_Pos)
#define	LPUARTx_CSR_PARITY_ODD	(0x2U << LPUARTx_CSR_PARITY_Pos)	/* 10 = 奇校验 */
#define	LPUARTx_CSR_PARITY_EVEN	(0x1U << LPUARTx_CSR_PARITY_Pos)	/* 01 = 偶校验 */
#define	LPUARTx_CSR_PARITY_NONE	(0x0U << LPUARTx_CSR_PARITY_Pos)	/* 00 = 无校验 */

#define	LPUARTx_CSR_RXPOL_Pos	3	/* 接收数据极性 */
#define	LPUARTx_CSR_RXPOL_Msk	(0x1U << LPUARTx_CSR_RXPOL_Pos)
#define	LPUARTx_CSR_RXPOL_POSITIVE	(0x0U << LPUARTx_CSR_RXPOL_Pos)	/* 0 = 正向 */
#define	LPUARTx_CSR_RXPOL_NEGATION	(0x1U << LPUARTx_CSR_RXPOL_Pos)	/* 1 = 取反 */

#define	LPUARTx_CSR_TXPOL_Pos	2	/* 发送数据极性 */
#define	LPUARTx_CSR_TXPOL_Msk	(0x1U << LPUARTx_CSR_TXPOL_Pos)
#define	LPUARTx_CSR_TXPOL_POSITIVE	(0x0U << LPUARTx_CSR_TXPOL_Pos)	/* 0 = 正向 */
#define	LPUARTx_CSR_TXPOL_NEGATION	(0x1U << LPUARTx_CSR_TXPOL_Pos)	/* 1 = 取反 */

#define	LPUARTx_CSR_RXEN_Pos	1	/* 接收使能控制 */
#define	LPUARTx_CSR_RXEN_Msk	(0x1U << LPUARTx_CSR_RXEN_Pos)
	/* 0 = 禁止 */
	/* 1 = 使能 */

#define	LPUARTx_CSR_TXEN_Pos	0	/* 发送使能控制 */
#define	LPUARTx_CSR_TXEN_Msk	(0x1U << LPUARTx_CSR_TXEN_Pos)
	/* 0 = 禁止 */
	/* 1 = 使能 */

#define	LPUARTx_IER_RXEV_IE_Pos	12	/* 接收唤醒事件中断使能 */
#define	LPUARTx_IER_RXEV_IE_Msk	(0x1U << LPUARTx_IER_RXEV_IE_Pos)
	/* 0 = 禁止 */
	/* 1 = 使能 */

#define	LPUARTx_IER_RXERR_IE_Pos	10	/* 接收错误中断使能 */
#define	LPUARTx_IER_RXERR_IE_Msk	(0x1U << LPUARTx_IER_RXERR_IE_Pos)
	/* 0 = 禁止 */
	/* 1 = 使能 */

#define	LPUARTx_IER_RXBF_IE_Pos	8	/* 接收缓存满中断使能 */
#define	LPUARTx_IER_RXBF_IE_Msk	(0x1U << LPUARTx_IER_RXBF_IE_Pos)
	/* 0 = 禁止 */
	/* 1 = 使能 */

#define	LPUARTx_IER_TXBE_IE_Pos	1	/* 发送缓存空中断使能 */
#define	LPUARTx_IER_TXBE_IE_Msk	(0x1U << LPUARTx_IER_TXBE_IE_Pos)
	/* 0 = 禁止 */
	/* 1 = 使能 */

#define	LPUARTx_IER_TXSE_IE_Pos	0	/* 发送缓存空且发送移位寄存器空中断使能 */
#define	LPUARTx_IER_TXSE_IE_Msk	(0x1U << LPUARTx_IER_TXSE_IE_Pos)
	/* 0 = 禁止 */
	/* 1 = 使能 */

#define	LPUARTx_ISR_RXEVF_Pos	24	/* 接收唤醒事件中断标志 */
#define	LPUARTx_ISR_RXEVF_Msk	(0x1U << LPUARTx_ISR_RXEVF_Pos)

#define	LPUARTx_ISR_TXOV_Pos	19	/* 发送缓存溢出错误标志 */
#define	LPUARTx_ISR_TXOV_Msk	(0x1U << LPUARTx_ISR_TXOV_Pos)

#define	LPUARTx_ISR_PERR_Pos	18	/* 奇偶校验错误中断标志 */
#define	LPUARTx_ISR_PERR_Msk	(0x1U << LPUARTx_ISR_PERR_Pos)

#define	LPUARTx_ISR_FERR_Pos	17	/* 帧格式错误中断标志 */
#define	LPUARTx_ISR_FERR_Msk	(0x1U << LPUARTx_ISR_FERR_Pos)

#define	LPUARTx_ISR_OERR_Pos	16	/* 接收缓存溢出错误中断标志 */
#define	LPUARTx_ISR_OERR_Msk	(0x1U << LPUARTx_ISR_OERR_Pos)

#define	LPUARTx_ISR_RXBF_Pos	8	/* 接收缓存满中断标志 */
#define	LPUARTx_ISR_RXBF_Msk	(0x1U << LPUARTx_ISR_RXBF_Pos)

#define	LPUARTx_ISR_TXBE_Pos	1	/* 发送缓存空中断标志 */
#define	LPUARTx_ISR_TXBE_Msk	(0x1U << LPUARTx_ISR_TXBE_Pos)

#define	LPUARTx_ISR_TXSE_Pos	0	/* 发送缓存空且发送移位寄存器空中断标志 */
#define	LPUARTx_ISR_TXSE_Msk	(0x1U << LPUARTx_ISR_TXSE_Pos)

#define	LPUARTx_BMR_MCTL_Pos	16	/* 每个bit的位宽调制控制信号 */
#define	LPUARTx_BMR_MCTL_Msk	(0x1fffU << LPUARTx_BMR_MCTL_Pos)

#define	LPUARTx_BMR_BAUD_Pos	0	/* 波特率控制 */
#define	LPUARTx_BMR_BAUD_Msk	(0x7U << LPUARTx_BMR_BAUD_Pos)
#define	LPUARTx_BMR_BAUD_300	(0x5U << LPUARTx_BMR_BAUD_Pos)	/* 101\110\111 = 300bps */
#define	LPUARTx_BMR_BAUD_600	(0x4U << LPUARTx_BMR_BAUD_Pos)	/* 100=600bps */
#define	LPUARTx_BMR_BAUD_1200	(0x3U << LPUARTx_BMR_BAUD_Pos)	/* 011=1200bps */
#define	LPUARTx_BMR_BAUD_2400	(0x2U << LPUARTx_BMR_BAUD_Pos)	/* 010=2400bps */
#define	LPUARTx_BMR_BAUD_4800	(0x1U << LPUARTx_BMR_BAUD_Pos)	/* 001=4800bps */
#define	LPUARTx_BMR_BAUD_9600	(0x0U << LPUARTx_BMR_BAUD_Pos)	/* 000=9600bps */

#define	LPUARTx_RXBUF_RXBUF_Pos	0	/* 接收数据缓冲 */
#define	LPUARTx_RXBUF_RXBUF_Msk	(0x1ffU << LPUARTx_RXBUF_RXBUF_Pos)

#define	LPUARTx_TXBUF_TXBUF_Pos	0	/* 发送数据缓冲 */
#define	LPUARTx_TXBUF_TXBUF_Msk	(0x1ffU << LPUARTx_TXBUF_TXBUF_Pos)

#define	LPUARTx_DMR_MATD_Pos	0	/* 数据匹配寄存器 */
#define	LPUARTx_DMR_MATD_Msk	(0x1ffU << LPUARTx_DMR_MATD_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void LPUARTx_Deinit(LPUART_Type* LPUARTx);

/* 通信状态 相关函数 */
extern FlagStatus LPUARTx_CSR_BUSY_Chk(LPUART_Type* LPUARTx);

/* 数据接收唤醒条件配置 相关函数 */
extern void LPUARTx_CSR_WKBYTECFG_Setable(LPUART_Type* LPUARTx, FunState NewState);
extern FunState LPUARTx_CSR_WKBYTECFG_Getable(LPUART_Type* LPUARTx);

/* 唤醒中断事件配置 相关函数 */
extern void LPUARTx_CSR_RXEV_Set(LPUART_Type* LPUARTx, uint32_t SetValue);
extern uint32_t LPUARTx_CSR_RXEV_Get(LPUART_Type* LPUARTx);

/* DMA发送完成中断使能 相关函数 */
extern void LPUARTx_CSR_DMATXIFCFG_Setable(LPUART_Type* LPUARTx, FunState NewState);
extern FunState LPUARTx_CSR_DMATXIFCFG_Getable(LPUART_Type* LPUARTx);

/* 数据发送和接收的位顺序 相关函数 */
extern void LPUARTx_CSR_BITORD_Set(LPUART_Type* LPUARTx, uint32_t SetValue);
extern uint32_t LPUARTx_CSR_BITORD_Get(LPUART_Type* LPUARTx);

/* 发送时停止位设置 相关函数 */
extern void LPUARTx_CSR_STOPCFG_Set(LPUART_Type* LPUARTx, uint32_t SetValue);
extern uint32_t LPUARTx_CSR_STOPCFG_Get(LPUART_Type* LPUARTx);

/* 每帧数据长度 相关函数 */
extern void LPUARTx_CSR_PDSEL_Set(LPUART_Type* LPUARTx, uint32_t SetValue);
extern uint32_t LPUARTx_CSR_PDSEL_Get(LPUART_Type* LPUARTx);

/* 校验位配置 相关函数 */
extern void LPUARTx_CSR_PARITY_Set(LPUART_Type* LPUARTx, uint32_t SetValue);
extern uint32_t LPUARTx_CSR_PARITY_Get(LPUART_Type* LPUARTx);

/* 接收数据极性 相关函数 */
extern void LPUARTx_CSR_RXPOL_Set(LPUART_Type* LPUARTx, uint32_t SetValue);
extern uint32_t LPUARTx_CSR_RXPOL_Get(LPUART_Type* LPUARTx);

/* 发送数据极性 相关函数 */
extern void LPUARTx_CSR_TXPOL_Set(LPUART_Type* LPUARTx, uint32_t SetValue);
extern uint32_t LPUARTx_CSR_TXPOL_Get(LPUART_Type* LPUARTx);

/* 接收使能控制 相关函数 */
extern void LPUARTx_CSR_RXEN_Setable(LPUART_Type* LPUARTx, FunState NewState);
extern FunState LPUARTx_CSR_RXEN_Getable(LPUART_Type* LPUARTx);

/* 发送使能控制 相关函数 */
extern void LPUARTx_CSR_TXEN_Setable(LPUART_Type* LPUARTx, FunState NewState);
extern FunState LPUARTx_CSR_TXEN_Getable(LPUART_Type* LPUARTx);

/* 接收唤醒事件中断使能 相关函数 */
extern void LPUARTx_IER_RXEV_IE_Setable(LPUART_Type* LPUARTx, FunState NewState);
extern FunState LPUARTx_IER_RXEV_IE_Getable(LPUART_Type* LPUARTx);

/* 接收错误中断使能 相关函数 */
extern void LPUARTx_IER_RXERR_IE_Setable(LPUART_Type* LPUARTx, FunState NewState);
extern FunState LPUARTx_IER_RXERR_IE_Getable(LPUART_Type* LPUARTx);

/* 接收缓存满中断使能 相关函数 */
extern void LPUARTx_IER_RXBF_IE_Setable(LPUART_Type* LPUARTx, FunState NewState);
extern FunState LPUARTx_IER_RXBF_IE_Getable(LPUART_Type* LPUARTx);

/* 发送缓存空中断使能 相关函数 */
extern void LPUARTx_IER_TXBE_IE_Setable(LPUART_Type* LPUARTx, FunState NewState);
extern FunState LPUARTx_IER_TXBE_IE_Getable(LPUART_Type* LPUARTx);

/* 发送缓存空且发送移位寄存器空中断使能 相关函数 */
extern void LPUARTx_IER_TXSE_IE_Setable(LPUART_Type* LPUARTx, FunState NewState);
extern FunState LPUARTx_IER_TXSE_IE_Getable(LPUART_Type* LPUARTx);

/* 接收唤醒事件中断标志 相关函数 */
extern void LPUARTx_ISR_RXEVF_Clr(LPUART_Type* LPUARTx);
extern FlagStatus LPUARTx_ISR_RXEVF_Chk(LPUART_Type* LPUARTx);

/* 发送缓存溢出错误标志 相关函数 */
extern void LPUARTx_ISR_TXOV_Clr(LPUART_Type* LPUARTx);
extern FlagStatus LPUARTx_ISR_TXOV_Chk(LPUART_Type* LPUARTx);

/* 奇偶校验错误中断标志 相关函数 */
extern void LPUARTx_ISR_PERR_Clr(LPUART_Type* LPUARTx);
extern FlagStatus LPUARTx_ISR_PERR_Chk(LPUART_Type* LPUARTx);

/* 帧格式错误中断标志 相关函数 */
extern void LPUARTx_ISR_FERR_Clr(LPUART_Type* LPUARTx);
extern FlagStatus LPUARTx_ISR_FERR_Chk(LPUART_Type* LPUARTx);

/* 接收缓存溢出错误中断标志 相关函数 */
extern void LPUARTx_ISR_OERR_Clr(LPUART_Type* LPUARTx);
extern FlagStatus LPUARTx_ISR_OERR_Chk(LPUART_Type* LPUARTx);

/* 接收缓存满中断标志 相关函数 */
extern void LPUARTx_ISR_RXBF_Clr(LPUART_Type* LPUARTx);
extern FlagStatus LPUARTx_ISR_RXBF_Chk(LPUART_Type* LPUARTx);

/* 发送缓存空中断标志 相关函数 */
extern FlagStatus LPUARTx_ISR_TXBE_Chk(LPUART_Type* LPUARTx);

/* 发送缓存空且发送移位寄存器空中断标志 相关函数 */
extern void LPUARTx_ISR_TXSE_Clr(LPUART_Type* LPUARTx);
extern FlagStatus LPUARTx_ISR_TXSE_Chk(LPUART_Type* LPUARTx);

/* 每个bit的位宽调制控制信号 相关函数 */
extern void LPUARTx_BMR_MCTL_Set(LPUART_Type* LPUARTx, uint32_t SetValue);
extern uint32_t LPUARTx_BMR_MCTL_Get(LPUART_Type* LPUARTx);

/* 波特率控制 相关函数 */
extern void LPUARTx_BMR_BAUD_Set(LPUART_Type* LPUARTx, uint32_t SetValue);
extern uint32_t LPUARTx_BMR_BAUD_Get(LPUART_Type* LPUARTx);

/* 接收数据缓冲 相关函数 */
extern uint32_t LPUARTx_RXBUF_Read(LPUART_Type* LPUARTx);

/* 发送数据缓冲 相关函数 */
extern void LPUARTx_TXBUF_Write(LPUART_Type* LPUARTx, uint32_t SetValue);

/* 数据匹配寄存器 相关函数 */
extern void LPUARTx_DMR_Write(LPUART_Type* LPUARTx, uint32_t SetValue);
extern uint32_t LPUARTx_DMR_Read(LPUART_Type* LPUARTx);

extern void LPUART_SInit(LPUART_Type* LPUARTx,LPUART_SInitTypeDef* para);
extern void LPUART_Init(LPUART_Type* LPUARTx,LPUART_InitTypeDef* para);
#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_LPUART_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
