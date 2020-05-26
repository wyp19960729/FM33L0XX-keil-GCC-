/**
  ******************************************************************************
  * @file    fm33l0xx_u7816.h
  * @author  FM33L0xx Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file contains all the functions prototypes for the U7816 firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33L0XX_U7816_H
#define __FM33L0XX_U7816_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33L0XX.h"

//------------------------------------------------------------------------------
typedef struct
{
	FunState				TXEN;		//发送使能
	FunState				RXEN;		//接受使能
	FunState				CKOEN;		//U7816时钟CLK输出使能控制
	FunState				HPUAT;		//U7816通道数据发送强上拉电阻自动有效控制
	FunState				HPUEN;		//U7816通道强上拉使能控制
	
	uint32_t				ERSW;		//ERROR SIGNAL宽度选择
	uint32_t				ERSGD;		//ERROR SIGNAL后GUARDTIME宽度选择（仅在发送时有效）
	FunState				BGTEN;		//BGT（block guard time）控制
	uint32_t				REP_T;		//控制接收数据奇偶校验出错时自动重发次数
	uint32_t				PAR;		//奇偶校验类型选择
	uint32_t				RFREN;		//Guard Time长度控制位（发送时严格按照协议2etu）
  uint32_t				SFREN;		//Guard Time长度控制位（发送时严格按照协议2etu）
	FunState				TREPEN;		//缓发送数据奇偶校验错的处理方式选择
	FunState				RREPEN;		//接收数据奇偶校验错的处理方式选择
	FunState				DICONV;		//传输次序反向编码使能
	
	uint32_t				TXEGT;		//发送时插入的EGT时间（以ETU为单位）
	uint32_t				CLKDIV;		//U7816时钟输出分频控制寄存器
	uint32_t				PDIV;		//U7816预分频控制寄存器，控制7816通信分频比（波特率）
	
	FunState				RXIE;		//数据接收中断使能位。对应RX_FLAG中断标志位
	FunState				TXIE;		//数据发送中断使能位。对应TX_FLAG中断标志位
	FunState				LSIE;		//线路状态中断使能位。对应ERROR_FLAG中断标志位
	
}U7816_InitTypeDef;

#define	U7816_CR_TXEN_Pos	5	/* U7816通道发送使能控制 */
#define	U7816_CR_TXEN_Msk	(0x1U << U7816_CR_TXEN_Pos)
	/* 0 = 通道发送禁止，不可发送数据，并关断输出端口 */
	/* 1 = 通道发送使能，可发送数据 */

#define	U7816_CR_RXEN_Pos	4	/* U7816通道接收使能控制 */
#define	U7816_CR_RXEN_Msk	(0x1U << U7816_CR_RXEN_Pos)
	/* 0 = 通道接收禁止，不可接收数据，并关断输入端口 */
	/* 1 = 通道接收使能，可接收数据 */

#define	U7816_CR_CKOEN_Pos	3	/* U7816时钟CLK输出使能控制 */
#define	U7816_CR_CKOEN_Msk	(0x1U << U7816_CR_CKOEN_Pos)
	/* 0 = 7816时钟输出禁止 */
	/* 1 = 7816时钟输出使能 */

#define	U7816_CR_HPUAT_Pos	2	/* U7816通道数据发送强上拉电阻自动有效控制 */
#define	U7816_CR_HPUAT_Msk	(0x1U << U7816_CR_HPUAT_Pos)
	/* 0 = 数据发送时上拉电阻自动有效功能禁止，上拉电阻由HPUEN，LPUEN控制 */
	/* 1 = 数据发送时上拉电阻自动有效，接收态上拉电阻无效 */

#define	U7816_CR_HPUEN_Pos	1	/* U7816通道强上拉使能控制 */
#define	U7816_CR_HPUEN_Msk	(0x1U << U7816_CR_HPUEN_Pos)
	/* 0 = 强上拉无效 */
	/* 1 = 强上拉有效 */

#define	U7816_FFR_SFREN_Pos	11	/* GUARD TIME 发送长度控制 */
#define	U7816_FFR_SFREN_Msk	(0x1U << U7816_FFR_SFREN_Pos)
#define	U7816_FFR_SFREN_2ETU	(0x0U << U7816_FFR_SFREN_Pos)	/* 0 = Guard time为2 etu */
#define	U7816_FFR_SFREN_3ETU	(0x1U << U7816_FFR_SFREN_Pos)	/* 1 = Guard time为3 etu */

#define	U7816_FFR_ERSW_Pos	9	/* ERROR SIGNAL宽度选择 */
#define	U7816_FFR_ERSW_Msk	(0x3U << U7816_FFR_ERSW_Pos)
#define	U7816_FFR_ERSW_1ETU	(0x3U << U7816_FFR_ERSW_Pos)	/* 11 = ERROR SIGNAL宽度为1ETU; */
#define	U7816_FFR_ERSW_1P5ETU	(0x2U << U7816_FFR_ERSW_Pos)	/* 10 = ERROR SIGNAL宽度为1.5ETU; */
#define	U7816_FFR_ERSW_2ETU	(0x0U << U7816_FFR_ERSW_Pos)	/* 01/00 = ERROR SIGNAL宽度为2ETU; */

#define	U7816_FFR_ERSGD_Pos	8	/* ERROR SIGNAL后GUARDTIME宽度选择（仅在发送时有效） */
#define	U7816_FFR_ERSGD_Msk	(0x1U << U7816_FFR_ERSGD_Pos)
#define	U7816_FFR_ERSGD_1PETU	(0x1U << U7816_FFR_ERSGD_Pos)	/* 1 = ERROR SIGNAL后GUARDTIME为1~1.5ETU。 */
#define	U7816_FFR_ERSGD_2PETU	(0x0U << U7816_FFR_ERSGD_Pos)	/* 0 = ERROR SIGNAL后GUARDTIME为2~2.5ETU。 */

#define	U7816_FFR_BGTEN_Pos	7	/* BGT（block guard time）控制 */
#define	U7816_FFR_BGTEN_Msk	(0x1U << U7816_FFR_BGTEN_Pos)
	/* 0 = BGT禁止，不插入Block guard time(22 etu); */
	/* 1 = BGT使能，插入Block guard time(22 etu); */

#define	U7816_FFR_REP_T_Pos	6	/* 控制接收数据奇偶校验出错时自动重发次数 */
#define	U7816_FFR_REP_T_Msk	(0x1U << U7816_FFR_REP_T_Pos)
#define	U7816_FFR_REP_T_1TIME	(0x0U << U7816_FFR_REP_T_Pos)	/* 0 = 1次 */
#define	U7816_FFR_REP_T_3TIME	(0x1U << U7816_FFR_REP_T_Pos)	/* 1 = 3次 */

#define	U7816_FFR_PAR_Pos	4	/* 奇偶校验类型选择 */
#define	U7816_FFR_PAR_Msk	(0x3U << U7816_FFR_PAR_Pos)
#define	U7816_FFR_PAR_EVEN	(0x0U << U7816_FFR_PAR_Pos)	/* 00：Even */
#define	U7816_FFR_PAR_ODD	(0x1U << U7816_FFR_PAR_Pos)	/* 01：Odd */
#define	U7816_FFR_PAR_ALWAYS1	(0x2U << U7816_FFR_PAR_Pos)	/* 10：Always 1 */
#define	U7816_FFR_PAR_NONE	(0x3U << U7816_FFR_PAR_Pos)	/* 11：不校验，处理 */

#define	U7816_FFR_RFREN_Pos	3	/* Guard Time长度控制位（发送时严格按照协议2etu） */
#define	U7816_FFR_RFREN_Msk	(0x1U << U7816_FFR_RFREN_Pos)
#define	U7816_FFR_RFREN_2ETU	(0x0U << U7816_FFR_RFREN_Pos)	/* 0 = Guard time为2 etu */
#define	U7816_FFR_RFREN_1ETU	(0x1U << U7816_FFR_RFREN_Pos)	/* 1 = Guard time为1 etu */

#define	U7816_FFR_TREPEN_Pos	2	/* 缓发送数据奇偶校验错的处理方式选择 */
#define	U7816_FFR_TREPEN_Msk	(0x1U << U7816_FFR_TREPEN_Pos)
	/* 0 = 收到Error signal时不进行自动回发，置tx_parity_err标志，直接中断 */
	/* 1 = 收到奇偶校验出错标志（error signal），根据T＝0协议自动进行回发。在单一byte重复发送次数超过REP_T后，置tx_parity_err标志，进行中断 */

#define	U7816_FFR_RREPEN_Pos	1	/* 接收数据奇偶校验错的处理方式选择 */
#define	U7816_FFR_RREPEN_Msk	(0x1U << U7816_FFR_RREPEN_Pos)
	/* 0 = 奇偶校验错，不自动发送ERROR SIGNAL，置RX_PARITY_ERR标志，进行中断 */
	/* 1 = 奇偶校验错，根据T=0协议自动回发ERROR SIGNAL。单一BYTE连续接收次数超过REP_T后，置RX_PARITY_ERR标志，进行中断 */

#define	U7816_FFR_DICONV_Pos	0	/* 传输次序反向编码使能 */
#define	U7816_FFR_DICONV_Msk	(0x1U << U7816_FFR_DICONV_Pos)
	/* 0 = 正向编码，先收发LSB ； (收发数据+校验位)正逻辑电平 */
	/* 1 = 反向编码，先收发MSB；(收发数据+校验位)反逻辑电平 */

#define	U7816_EGTR_TXEGT_Pos	0	/* 发送时插入的EGT时间（以ETU为单位） */
#define	U7816_EGTR_TXEGT_Msk	(0xffU << U7816_EGTR_TXEGT_Pos)

#define	U7816_PSC_CLKDIV_Pos	0	/* U7816时钟输出分频控制寄存器 */
#define	U7816_PSC_CLKDIV_Msk	(0x1fU << U7816_PSC_CLKDIV_Pos)

#define	U7816_BGR_PDIV_Pos	0	/* U7816预分频控制寄存器，控制7816通信分频比（波特率） */
#define	U7816_BGR_PDIV_Msk	(0xfffU << U7816_BGR_PDIV_Pos)

#define	U7816_RXBUF_RXBUF_Pos	0	/* U7816数据接收缓存寄存器 */
#define	U7816_RXBUF_RXBUF_Msk	(0xffU << U7816_RXBUF_RXBUF_Pos)

#define	U7816_TXBUF_TXBUF_Pos	0	/* U7816数据发送缓存寄存器 */
#define	U7816_TXBUF_TXBUF_Msk	(0xffU << U7816_TXBUF_TXBUF_Pos)

#define	U7816_IER_RXIE_Pos	2	/* 数据接收中断使能位。对应RX_FLAG中断标志位 */
#define	U7816_IER_RXIE_Msk	(0x1U << U7816_IER_RXIE_Pos)
	/* 0 = 数据接收中断使能位 */
	/* 1 = 数据接收中断使能位 */

#define	U7816_IER_TXIE_Pos	1	/* 数据发送中断使能位。对应TX_FLAG中断标志位 */
#define	U7816_IER_TXIE_Msk	(0x1U << U7816_IER_TXIE_Pos)
	/* 0 = 数据发送中断禁止 */
	/* 1 = 数据发送中断使能 */

#define	U7816_IER_LSIE_Pos	0	/* 线路状态中断使能位。对应ERROR_FLAG中断标志位 */
#define	U7816_IER_LSIE_Msk	(0x1U << U7816_IER_LSIE_Pos)
	/* 0 = 线路状态中断禁止 */
	/* 1 = 线路状态中断使能 */

#define	U7816_ISR_WAIT_RPT_Pos	18	/* U7816接口发送了错误信号，正在等待对方重发数据.状态机进入发送错误信号状态时置位，收到数据起始位或者进入发送状态时硬件清零;
 */
#define	U7816_ISR_WAIT_RPT_Msk	(0x1U << U7816_ISR_WAIT_RPT_Pos)

#define	U7816_ISR_TXBUSY_Pos	17	/* 发送数据忙标志 */
#define	U7816_ISR_TXBUSY_Msk	(0x1U << U7816_ISR_TXBUSY_Pos)

#define	U7816_ISR_RXBUSY_Pos	16	/* 接收数据忙标志 */
#define	U7816_ISR_RXBUSY_Msk	(0x1U << U7816_ISR_RXBUSY_Pos)

#define	U7816_ISR_TPARERR_Pos	11	/* 发送数据奇偶校验错误标志位 */
#define	U7816_ISR_TPARERR_Msk	(0x1U << U7816_ISR_TPARERR_Pos)

#define	U7816_ISR_RPARERR_Pos	10	/* 接收数据奇偶校验错误标志位 */
#define	U7816_ISR_RPARERR_Msk	(0x1U << U7816_ISR_RPARERR_Pos)

#define	U7816_ISR_FRERR_Pos	9	/* 接收帧格式错误标志位 */
#define	U7816_ISR_FRERR_Msk	(0x1U << U7816_ISR_FRERR_Pos)

#define	U7816_ISR_OVERR_Pos	8	/* 接收溢出错误标志位 */
#define	U7816_ISR_OVERR_Msk	(0x1U << U7816_ISR_OVERR_Pos)

#define	U7816_ISR_RXIF_Pos	2	/* 接收完成标志 */
#define	U7816_ISR_RXIF_Msk	(0x1U << U7816_ISR_RXIF_Pos)

#define	U7816_ISR_TXIF_Pos	1	/* 发送缓冲区空标志 */
#define	U7816_ISR_TXIF_Msk	(0x1U << U7816_ISR_TXIF_Pos)

#define	U7816_ISR_ERRIF_Pos	0	/* 错误标志，寄存器配置出错或传输过程中出错。硬件置位，清U7816ERR中相应错误 */
#define	U7816_ISR_ERRIF_Msk	(0x1U << U7816_ISR_ERRIF_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void U7816_Deinit(void);

/* U7816通道发送使能控制 相关函数 */
extern void U7816_CR_TXEN_Setable(FunState NewState);
extern FunState U7816_CR_TXEN_Getable(void);

/* U7816通道接收使能控制 相关函数 */
extern void U7816_CR_RXEN_Setable(FunState NewState);
extern FunState U7816_CR_RXEN_Getable(void);

/* U7816时钟CLK输出使能控制 相关函数 */
extern void U7816_CR_CKOEN_Setable(FunState NewState);
extern FunState U7816_CR_CKOEN_Getable(void);

/* U7816通道数据发送强上拉电阻自动有效控制 相关函数 */
extern void U7816_CR_HPUAT_Setable(FunState NewState);
extern FunState U7816_CR_HPUAT_Getable(void);

/* U7816通道强上拉使能控制 相关函数 */
extern void U7816_CR_HPUEN_Setable(FunState NewState);
extern FunState U7816_CR_HPUEN_Getable(void);

/* GUARD TIME 发送长度控制 相关函数 */
extern void U7816_FFR_SFREN_Set(uint32_t SetValue);
extern uint32_t U7816_FFR_SFREN_Get(void);

/* ERROR SIGNAL宽度选择 相关函数 */
extern void U7816_FFR_ERSW_Set(uint32_t SetValue);
extern uint32_t U7816_FFR_ERSW_Get(void);

/* ERROR SIGNAL后GUARDTIME宽度选择（仅在发送时有效） 相关函数 */
extern void U7816_FFR_ERSGD_Set(uint32_t SetValue);
extern uint32_t U7816_FFR_ERSGD_Get(void);

/* BGT（block guard time）控制 相关函数 */
extern void U7816_FFR_BGTEN_Setable(FunState NewState);
extern FunState U7816_FFR_BGTEN_Getable(void);

/* 控制接收数据奇偶校验出错时自动重发次数 相关函数 */
extern void U7816_FFR_REP_T_Set(uint32_t SetValue);
extern uint32_t U7816_FFR_REP_T_Get(void);

/* 奇偶校验类型选择 相关函数 */
extern void U7816_FFR_PAR_Set(uint32_t SetValue);
extern uint32_t U7816_FFR_PAR_Get(void);

/* Guard Time长度控制位（发送时严格按照协议2etu） 相关函数 */
extern void U7816_FFR_RFREN_Set(uint32_t SetValue);
extern uint32_t U7816_FFR_RFREN_Get(void);

/* 缓发送数据奇偶校验错的处理方式选择 相关函数 */
extern void U7816_FFR_TREPEN_Setable(FunState NewState);
extern FunState U7816_FFR_TREPEN_Getable(void);

/* 接收数据奇偶校验错的处理方式选择 相关函数 */
extern void U7816_FFR_RREPEN_Setable(FunState NewState);
extern FunState U7816_FFR_RREPEN_Getable(void);

/* 传输次序反向编码使能 相关函数 */
extern void U7816_FFR_DICONV_Setable(FunState NewState);
extern FunState U7816_FFR_DICONV_Getable(void);

/* 发送时插入的EGT时间（以ETU为单位） 相关函数 */
extern void U7816_EGTR_Write(uint32_t SetValue);
extern uint32_t U7816_EGTR_Read(void);

/* U7816时钟输出分频控制寄存器 相关函数 */
extern void U7816_PSC_Write(uint32_t SetValue);
extern uint32_t U7816_PSC_Read(void);

/* U7816预分频控制寄存器，控制7816通信分频比（波特率） 相关函数 */
extern void U7816_BGR_Write(uint32_t SetValue);
extern uint32_t U7816_BGR_Read(void);

/* U7816数据接收缓存寄存器 相关函数 */
extern uint32_t U7816_RXBUF_Read(void);

/* U7816数据发送缓存寄存器 相关函数 */
extern void U7816_TXBUF_Write(uint32_t SetValue);

/* 数据接收中断使能位。对应RX_FLAG中断标志位 相关函数 */
extern void U7816_IER_RXIE_Setable(FunState NewState);
extern FunState U7816_IER_RXIE_Getable(void);

/* 数据发送中断使能位。对应TX_FLAG中断标志位 相关函数 */
extern void U7816_IER_TXIE_Setable(FunState NewState);
extern FunState U7816_IER_TXIE_Getable(void);

/* 线路状态中断使能位。对应ERROR_FLAG中断标志位 相关函数 */
extern void U7816_IER_LSIE_Setable(FunState NewState);
extern FunState U7816_IER_LSIE_Getable(void);

/* U7816接口发送了错误信号，正在等待对方重发数据.状态机进入发送错误信号状态时置位，收到数据起始位或者进入发送状态时硬件清零;
 相关函数 */
extern FlagStatus U7816_ISR_WAIT_RPT_Chk(void);

/* 发送数据忙标志 相关函数 */
extern FlagStatus U7816_ISR_TXBUSY_Chk(void);

/* 接收数据忙标志 相关函数 */
extern FlagStatus U7816_ISR_RXBUSY_Chk(void);

/* 发送数据奇偶校验错误标志位 相关函数 */
extern void U7816_ISR_TPARERR_Clr(void);
extern FlagStatus U7816_ISR_TPARERR_Chk(void);

/* 接收数据奇偶校验错误标志位 相关函数 */
extern void U7816_ISR_RPARERR_Clr(void);
extern FlagStatus U7816_ISR_RPARERR_Chk(void);

/* 接收帧格式错误标志位 相关函数 */
extern void U7816_ISR_FRERR_Clr(void);
extern FlagStatus U7816_ISR_FRERR_Chk(void);

/* 接收溢出错误标志位 相关函数 */
extern void U7816_ISR_OVERR_Clr(void);
extern FlagStatus U7816_ISR_OVERR_Chk(void);

/* 接收完成标志 相关函数 */
extern FlagStatus U7816_ISR_RXIF_Chk(void);

/* 发送缓冲区空标志 相关函数 */
extern FlagStatus U7816_ISR_TXIF_Chk(void);

/* 错误标志，寄存器配置出错或传输过程中出错。硬件置位，清U7816ERR中相应错误 相关函数 */
extern FlagStatus U7816_ISR_ERRIF_Chk(void);

extern void U7816_Init(U7816_InitTypeDef* para);

#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_U7816_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
