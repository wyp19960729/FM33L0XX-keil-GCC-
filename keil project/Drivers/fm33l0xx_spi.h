/**
  ******************************************************************************
  * @file    fm33l0xx_spi.h
  * @author  FM33L0xx Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file contains all the functions prototypes for the SPI firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33L0XX_SPI_H
#define __FM33L0XX_SPI_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33L0XX.h"

//------------------------------------------------------------------------------
typedef struct
{
	uint32_t LSBF;             	//先发送高位bit还是低位bit/* SETTING 1 FOR LSB */		
  uint32_t CPHOL;			    //时钟极性选择/* SETTING 1 FOR CLK STOP AT HIGH*/	
	uint32_t CPHA;				//时钟相位选择/* SETTING 1 FOR START AT SECOND CLK EDGE AND 0 FOR FIRST */
}SPI_Slave_SInitTypeDef;

typedef struct
{
	uint32_t SSPA;				//slave模式下对发送时机点进行调整（提前）
	FunState FLTEN;             //slave模式下使能4ns滤波/
	uint32_t LSBF;             	//先发送高位bit还是低位bit/* SETTING 1 FOR LSB */		
  uint32_t CPHOL;			    //时钟极性选择/* SETTING 1 FOR CLK STOP AT HIGH*/	
	uint32_t CPHA;				//时钟相位选择/* SETTING 1 FOR START AT SECOND CLK EDGE AND 0 FOR FIRST */
	FunState TXO;               //TXONLY模式
	uint32_t TXO_AC;            //TXONLY硬件自动清除配置

	FunState SPIEN;             //SPI使能，初始化时建议写为DISABLE
	FunState ERRIE;             //SPI错误中断使能，初始化时建议写为DISABLE
	FunState TXIE;              //SPI发送完成中断使能，初始化时建议写为DISABLE
	FunState RXIE;              //SPI接收完成中断使能，初始化时建议写为DISABLE
}SPI_Slave_InitTypeDef;

typedef struct
{
    uint32_t BAUD_RATE;         //波特率/* SETTING BAUD_RATE */	
    uint32_t LSBF;             	//先发送高位bit还是低位bit/* SETTING 1 FOR LSB */		
    uint32_t CPHOL;			    //时钟极性选择/* SETTING 1 FOR CLK STOP AT HIGH*/	
	uint32_t CPHA;				//时钟相位选择/* SETTING 1 FOR START AT SECOND CLK EDGE AND 0 FOR FIRST */
	uint32_t SSNM;				//每次发完8bit后保持SSN为低还是拉高，SSN硬件模式有效/* SETTING SSN AFTER SENDING */	
	uint32_t SSNSEN;			//SSN由硬件控制还是由软件控制/* SETTING 1 FOR CONTROL SSN BY SOFTWARE */
}SPI_Master_SInitTypeDef;

typedef struct
{
	uint32_t MSPA;              //master模式下对采样点进行调整(滞后)，用于高速通信时补偿PCB走线延迟
	uint32_t WAIT;              //master模式下，每次发送完8bit至少加入几个sck周期的等待时间
	uint32_t BAUD_RATE; 		//波特率/* SETTING BAUD_RATE */	
	uint32_t LSBF;				//先发送高位bit还是低位bit/* SETTING 1 FOR LSB */		
	uint32_t CPHOL; 			//时钟极性选择/* SETTING 1 FOR CLK STOP AT HIGH*/ 
	uint32_t CPHA;				//时钟相位选择/* SETTING 1 FOR START AT SECOND CLK EDGE AND 0 FOR FIRST */
    FunState DUMMY_EN;          //半双工协议下读操作后是否插入dummy cycle
    FunState RXO;               //单接收模式
    uint32_t DATA_LEN;          //通信数据长度
    uint32_t HALFDUPLEX;        //通信模式选择
    uint32_t HD_RW;             //4线半双工协议下主机读写操作配置
    uint32_t CMD8b;             //4线半双工协议下command帧长度
    uint32_t SSNM;				//每次发完8bit后保持SSN为低还是拉高，SSN硬件模式有效/* SETTING SSN AFTER SENDING */ 
	uint32_t TXO_AC;            //TXONLY硬件自动清除配置
	FunState TXO;               //TXONLY模式
	uint32_t SSNSEN;			//SSN由硬件控制还是由软件控制/* SETTING 1 FOR CONTROL SSN BY SOFTWARE */

	FunState SPIEN;             //SPI使能，初始化时建议写为DISABLE
	FunState ERRIE;             //SPI错误中断使能，初始化时建议写为DISABLE
	FunState TXIE;              //SPI发送完成中断使能，初始化时建议写为DISABLE
	FunState RXIE;              //SPI接收完成中断使能，初始化时建议写为DISABLE
}SPI_Master_InitTypeDef;


#define	SPIx_CR1_MSPA_Pos	10	/* Master对MISO信号的采样位置调整，用于高速通信时补偿PCB走线延迟 */
#define	SPIx_CR1_MSPA_Msk	(0x1U << SPIx_CR1_MSPA_Pos)
#define	SPIx_CR1_MSPA_NORMAL	(0x0U << SPIx_CR1_MSPA_Pos)	/* 采样点不调整 */
#define	SPIx_CR1_MSPA_HALF_DELAY	(0x1U << SPIx_CR1_MSPA_Pos)	/* 采样点延迟半个SCK周期 */

#define	SPIx_CR1_SSPA_Pos	9	/* Slave MISO发送位置调整 */
#define	SPIx_CR1_SSPA_Msk	(0x1U << SPIx_CR1_SSPA_Pos)
#define	SPIx_CR1_SSPA_NORMAL	(0x0U << SPIx_CR1_SSPA_Pos)	/* 发送不提前 */
#define	SPIx_CR1_SSPA_HALF_DELAY	(0x1U << SPIx_CR1_SSPA_Pos)	/* 提前半个SCK周期发送 */

#define	SPIx_CR1_MM_Pos	8	/* Master/Slave模式选择 */
#define	SPIx_CR1_MM_Msk	(0x1U << SPIx_CR1_MM_Pos)
#define	SPIx_CR1_MM_SLAVE	(0x0U << SPIx_CR1_MM_Pos)	/* Slave模式 */
#define	SPIx_CR1_MM_MASTER	(0x1U << SPIx_CR1_MM_Pos)	/* Master模式 */

#define	SPIx_CR1_WAIT_Pos	6	/* 发送完成后等待 */
#define	SPIx_CR1_WAIT_Msk	(0x3U << SPIx_CR1_WAIT_Pos)
#define	SPIx_CR1_WAIT_WAIT_1	(0x0U << SPIx_CR1_WAIT_Pos)	/* 1个SCK周期 */
#define	SPIx_CR1_WAIT_WAIT_2	(0x1U << SPIx_CR1_WAIT_Pos)	/* 2个SCK周期 */
#define	SPIx_CR1_WAIT_WAIT_3	(0x2U << SPIx_CR1_WAIT_Pos)	/* 3个SCK周期 */
#define	SPIx_CR1_WAIT_WAIT_4	(0x3U << SPIx_CR1_WAIT_Pos)	/* 4个SCK周期 */

#define	SPIx_CR1_BAUD_Pos	3	/* Master模式下波特率设置 */
#define	SPIx_CR1_BAUD_Msk	(0x7U << SPIx_CR1_BAUD_Pos)
#define	SPIx_CR1_BAUD_PLCK_2	(0x0U << SPIx_CR1_BAUD_Pos)	/* 外设时钟2分频 */
#define	SPIx_CR1_BAUD_PLCK_4	(0x1U << SPIx_CR1_BAUD_Pos)	/* 外设时钟4分频 */
#define	SPIx_CR1_BAUD_PLCK_8	(0x2U << SPIx_CR1_BAUD_Pos)	/* 外设时钟8分频 */
#define	SPIx_CR1_BAUD_PLCK_16	(0x3U << SPIx_CR1_BAUD_Pos)	/* 外设时钟16分频 */
#define	SPIx_CR1_BAUD_PLCK_32	(0x4U << SPIx_CR1_BAUD_Pos)	/* 外设时钟32分频 */
#define	SPIx_CR1_BAUD_PLCK_64	(0x5U << SPIx_CR1_BAUD_Pos)	/* 外设时钟64分频 */
#define	SPIx_CR1_BAUD_PLCK_128	(0x6U << SPIx_CR1_BAUD_Pos)	/* 外设时钟128分频 */
#define	SPIx_CR1_BAUD_PLCK_256	(0x7U << SPIx_CR1_BAUD_Pos)	/* 外设时钟256分频 */

#define	SPIx_CR1_LSBF_Pos	2	/* 帧格式 */
#define	SPIx_CR1_LSBF_Msk	(0x1U << SPIx_CR1_LSBF_Pos)
#define	SPIx_CR1_LSBF_MSB	(0x0U << SPIx_CR1_LSBF_Pos)	/* 先发送高bit */
#define	SPIx_CR1_LSBF_LSB	(0x1U << SPIx_CR1_LSBF_Pos)	/* 先发送低bit */

#define	SPIx_CR1_CPOL_Pos	1	/* 时钟极性选择 */
#define	SPIx_CR1_CPOL_Msk	(0x1U << SPIx_CR1_CPOL_Pos)
#define	SPIx_CR1_CPOL_LOW	(0x0U << SPIx_CR1_CPOL_Pos)	/* 串行时钟停止时在低电平 */
#define	SPIx_CR1_CPOL_HIGH	(0x1U << SPIx_CR1_CPOL_Pos)	/* 串行时钟停止时在高电平 */

#define	SPIx_CR1_CPHA_Pos	0	/* 时钟相位选择 */
#define	SPIx_CR1_CPHA_Msk	(0x1U << SPIx_CR1_CPHA_Pos)
#define	SPIx_CR1_CPHA_FIRST	(0x0U << SPIx_CR1_CPHA_Pos)	/* 第一个时钟边沿采样 */
#define	SPIx_CR1_CPHA_SECOND	(0x1U << SPIx_CR1_CPHA_Pos)	/* 第二个时钟边沿采样 */

#define	SPIx_CR2_DUMMY_EN_Pos	15	/* 四线半双工协议在读操作是否插入dummy cycle */
#define	SPIx_CR2_DUMMY_EN_Msk	(0x1U << SPIx_CR2_DUMMY_EN_Pos)
	/* 不插入 */
	/* 插入 */

#define	SPIx_CR2_RXO_Pos	11	/* Master RXONLY控制位 */
#define	SPIx_CR2_RXO_Msk	(0x1U << SPIx_CR2_RXO_Pos)
	/* 收发模式 */
	/* 单接收模式 */

#define	SPIx_CR2_DLEN_Pos	9	/* 通信数据字长配置 */
#define	SPIx_CR2_DLEN_Msk	(0x3U << SPIx_CR2_DLEN_Pos)
#define	SPIx_CR2_DLEN_8BIT	(0x0U << SPIx_CR2_DLEN_Pos)	/* 8bit数据 */
#define	SPIx_CR2_DLEN_16BIT	(0x1U << SPIx_CR2_DLEN_Pos)	/* 16bit数据 */
#define	SPIx_CR2_DLEN_24BIT	(0x2U << SPIx_CR2_DLEN_Pos)	/* 24bit数据 */
#define	SPIx_CR2_DLEN_32BIT	(0x3U << SPIx_CR2_DLEN_Pos)	/* 32bit数据 */

#define	SPIx_CR2_HALFDUPLEX_Pos	8	/* 通信模式选择 */
#define	SPIx_CR2_HALFDUPLEX_Msk	(0x1U << SPIx_CR2_HALFDUPLEX_Pos)
#define	SPIx_CR2_HALFDUPLEX_STAND	(0x0U << SPIx_CR2_HALFDUPLEX_Pos)	/* 标准SPI模式，4线全双工 */
#define	SPIx_CR2_HALFDUPLEX_DCN	(0x1U << SPIx_CR2_HALFDUPLEX_Pos)	/* DCN模式，4线半双工 */

#define	SPIx_CR2_HD_RW_Pos	7	/* 半双工模式下读写配置 */
#define	SPIx_CR2_HD_RW_Msk	(0x1U << SPIx_CR2_HD_RW_Pos)
#define	SPIx_CR2_HD_RW_WRITE	(0x0U << SPIx_CR2_HD_RW_Pos)	/* 主机写入从机 */
#define	SPIx_CR2_HD_RW_READ	(0x1U << SPIx_CR2_HD_RW_Pos)	/* 主机读取从机 */

#define	SPIx_CR2_CMD8b_Pos	6	/* 半双工模式下commmand帧长度 */
#define	SPIx_CR2_CMD8b_Msk	(0x1U << SPIx_CR2_CMD8b_Pos)
#define	SPIx_CR2_CMD8b_VARIABLE	(0x0U << SPIx_CR2_CMD8b_Pos)	/* 由DLEN定义 */
#define	SPIx_CR2_CMD8b_FIXED	(0x1U << SPIx_CR2_CMD8b_Pos)	/* 固定为8bit */

#define	SPIx_CR2_SSNM_Pos	5	/* Master模式下SSN控制模式选择 */
#define	SPIx_CR2_SSNM_Msk	(0x1U << SPIx_CR2_SSNM_Pos)
#define	SPIx_CR2_SSNM_LOW	(0x0U << SPIx_CR2_SSNM_Pos)	/* 发送一帧后保持SSN为低 */
#define	SPIx_CR2_SSNM_HIGH	(0x1U << SPIx_CR2_SSNM_Pos)	/* 发送一帧后拉高SSN */

#define	SPIx_CR2_TXO_AC_Pos	4	/* TXONLY硬件自动清空控制 */
#define	SPIx_CR2_TXO_AC_Msk	(0x1U << SPIx_CR2_TXO_AC_Pos)
#define	SPIx_CR2_TXO_AC_DISABLE	(0x0U << SPIx_CR2_TXO_AC_Pos)	/* 关闭TXONLY硬件自动清空 */
#define	SPIx_CR2_TXO_AC_ENABLE	(0x1U << SPIx_CR2_TXO_AC_Pos)	/* TXONLY硬件自动清空有效 */

#define	SPIx_CR2_TXO_Pos	3	/* TXONLY模式控制 */
#define	SPIx_CR2_TXO_Msk	(0x1U << SPIx_CR2_TXO_Pos)
	/* 关闭TXONLY模式 */
	/* 启动TXONLY模式 */

#define	SPIx_CR2_SSN_Pos	2	/* SSN输出电平 */
#define	SPIx_CR2_SSN_Msk	(0x1U << SPIx_CR2_SSN_Pos)
#define	SPIx_CR2_SSN_LOW	(0x0U << SPIx_CR2_SSN_Pos)	/* 高电平 */
#define	SPIx_CR2_SSN_HIGH	(0x1U << SPIx_CR2_SSN_Pos)	/* 低电平 */

#define	SPIx_CR2_SSNSEN_Pos	1	/* 软件控制SSN */
#define	SPIx_CR2_SSNSEN_Msk	(0x1U << SPIx_CR2_SSNSEN_Pos)
#define	SPIx_CR2_SSNSEN_DISABLE	(0x0U << SPIx_CR2_SSNSEN_Pos)	/* 关闭 */
#define	SPIx_CR2_SSNSEN_ENABLE	(0x1U << SPIx_CR2_SSNSEN_Pos)	/* 使能 */

#define	SPIx_CR2_SPIEN_Pos	0	/* SPI模块控制 */
#define	SPIx_CR2_SPIEN_Msk	(0x1U << SPIx_CR2_SPIEN_Pos)
	/* 关闭 */
	/* 使能 */

#define	SPIx_CR3_TXBFC_Pos	3
#define	SPIx_CR3_TXBFC_Msk	(0x1U << SPIx_CR3_TXBFC_Pos)

#define	SPIx_CR3_RXBFC_Pos	2
#define	SPIx_CR3_RXBFC_Msk	(0x1U << SPIx_CR3_RXBFC_Pos)

#define	SPIx_CR3_MERRC_Pos	1
#define	SPIx_CR3_MERRC_Msk	(0x1U << SPIx_CR3_MERRC_Pos)

#define	SPIx_CR3_SERRC_Pos	0
#define	SPIx_CR3_SERRC_Msk	(0x1U << SPIx_CR3_SERRC_Pos)

#define	SPIx_IER_ERRIE_Pos	2	/* SPI错误中断控制 */
#define	SPIx_IER_ERRIE_Msk	(0x1U << SPIx_IER_ERRIE_Pos)
/* 失能 */
/* 使能 */

#define	SPIx_IER_TXIE_Pos	1	/* 发送完成中断控制 */
#define	SPIx_IER_TXIE_Msk	(0x1U << SPIx_IER_TXIE_Pos)
/* 失能 */
/* 使能 */

#define	SPIx_IER_RXIE_Pos	0	/* 接收完成中断控制 */
#define	SPIx_IER_RXIE_Msk	(0x1U << SPIx_IER_RXIE_Pos)
/* 失能 */
/* 使能 */

#define	SPIx_ISR_DCN_TX_Pos	12	/* 半双工模式下，每帧数据的帧模式 */
#define	SPIx_ISR_DCN_TX_Msk	(0x1U << SPIx_ISR_DCN_TX_Pos)
#define	SPIx_ISR_DCN_TX_CMD	(0x0U << SPIx_ISR_DCN_TX_Pos)	/* 命令帧 */
#define	SPIx_ISR_DCN_TX_DATA	(0x1U << SPIx_ISR_DCN_TX_Pos)	/* 数据帧 */

#define	SPIx_ISR_RXCOL_Pos	10	/* 接收缓存区溢出，软件写1清0 */
#define	SPIx_ISR_RXCOL_Msk	(0x1U << SPIx_ISR_RXCOL_Pos)

#define	SPIx_ISR_TXCOL_Pos	9	/* 发送缓存区溢出，软件写1清0 */
#define	SPIx_ISR_TXCOL_Msk	(0x1U << SPIx_ISR_TXCOL_Pos)

#define	SPIx_ISR_BUSY_Pos	8	/* SPI状态标志，只读 */
#define	SPIx_ISR_BUSY_Msk	(0x1U << SPIx_ISR_BUSY_Pos)
#define	SPIx_ISR_BUSY_RESET	(0x0U << SPIx_ISR_BUSY_Pos)	/* 传输空闲 */
#define	SPIx_ISR_BUSY_SET	(0x1U << SPIx_ISR_BUSY_Pos)	/* 传输中 */

#define	SPIx_ISR_MERR_Pos	6	/* 主机错误标志，软件写1清0 */
#define	SPIx_ISR_MERR_Msk	(0x1U << SPIx_ISR_MERR_Pos)

#define	SPIx_ISR_SERR_Pos	5	/* 从机错误标志，软件写1清0 */
#define	SPIx_ISR_SERR_Msk	(0x1U << SPIx_ISR_SERR_Pos)

#define	SPIx_ISR_TXBE_Pos	1	/* 发送buffer为空标志 */
#define	SPIx_ISR_TXBE_Msk	(0x1U << SPIx_ISR_TXBE_Pos)

#define	SPIx_ISR_RXBF_Pos	0	/* 接收buffer非空标志 */
#define	SPIx_ISR_RXBF_Msk	(0x1U << SPIx_ISR_RXBF_Pos)

#define	SPIx_TXBUF_TXBUF_Pos	0	/* SPI发送缓存 */
#define	SPIx_TXBUF_TXBUF_Msk	(0xffffffffU << SPIx_TXBUF_TXBUF_Pos)

#define	SPIx_RXBUF_RXBUF_Pos	0	/* SPI接收缓存 */
#define	SPIx_RXBUF_RXBUF_Msk	(0xffffffffU << SPIx_RXBUF_RXBUF_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void SPIx_Deinit(SPI_Type* SPIx);

/* Master对MISO信号的采样位置调整，用于高速通信时补偿PCB走线延迟 相关函数 */
extern void SPIx_CR1_MSPA_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR1_MSPA_Get(SPI_Type* SPIx);

/* Slave MISO发送位置调整 相关函数 */
extern void SPIx_CR1_SSPA_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR1_SSPA_Get(SPI_Type* SPIx);

/* Master/Slave模式选择 相关函数 */
extern void SPIx_CR1_MM_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR1_MM_Get(SPI_Type* SPIx);

/* 发送完成后等待 相关函数 */
extern void SPIx_CR1_WAIT_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR1_WAIT_Get(SPI_Type* SPIx);

/* Master模式下波特率设置 相关函数 */
extern void SPIx_CR1_BAUD_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR1_BAUD_Get(SPI_Type* SPIx);

/* 帧格式 相关函数 */
extern void SPIx_CR1_LSBF_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR1_LSBF_Get(SPI_Type* SPIx);

/* 时钟极性选择 相关函数 */
extern void SPIx_CR1_CPOL_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR1_CPOL_Get(SPI_Type* SPIx);

/* 时钟相位选择 相关函数 */
extern void SPIx_CR1_CPHA_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR1_CPHA_Get(SPI_Type* SPIx);

/* 四线半双工协议在读操作是否插入dummy cycle 相关函数 */
extern void SPIx_CR2_DUMMY_EN_Setable(SPI_Type* SPIx, FunState NewState);
extern FunState SPIx_CR2_DUMMY_EN_Getable(SPI_Type* SPIx);

/* Master RXONLY控制位 相关函数 */
extern void SPIx_CR2_RXO_Setable(SPI_Type* SPIx, FunState NewState);
extern FunState SPIx_CR2_RXO_Getable(SPI_Type* SPIx);

/* 通信数据字长配置 相关函数 */
extern void SPIx_CR2_DLEN_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR2_DLEN_Get(SPI_Type* SPIx);

/* 通信模式选择 相关函数 */
extern void SPIx_CR2_HALFDUPLEX_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR2_HALFDUPLEX_Get(SPI_Type* SPIx);

/* 半双工模式下读写配置 相关函数 */
extern void SPIx_CR2_HD_RW_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR2_HD_RW_Get(SPI_Type* SPIx);

/* 半双工模式下commmand帧长度 相关函数 */
extern void SPIx_CR2_CMD8b_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR2_CMD8b_Get(SPI_Type* SPIx);

/* Master模式下SSN控制模式选择 相关函数 */
extern void SPIx_CR2_SSNM_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR2_SSNM_Get(SPI_Type* SPIx);

/* TXONLY硬件自动清空控制 相关函数 */
extern void SPIx_CR2_TXO_AC_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR2_TXO_AC_Get(SPI_Type* SPIx);

/* TXONLY模式控制 相关函数 */
extern void SPIx_CR2_TXO_Setable(SPI_Type* SPIx, FunState NewState);
extern FunState SPIx_CR2_TXO_Getable(SPI_Type* SPIx);

/* SSN输出电平 相关函数 */
extern void SPIx_CR2_SSN_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR2_SSN_Get(SPI_Type* SPIx);

/* 软件控制SSN 相关函数 */
extern void SPIx_CR2_SSNSEN_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_CR2_SSNSEN_Get(SPI_Type* SPIx);

/* SPI模块控制 相关函数 */
extern void SPIx_CR2_SPIEN_Setable(SPI_Type* SPIx, FunState NewState);
extern FunState SPIx_CR2_SPIEN_Getable(SPI_Type* SPIx);

extern void SPIx_CR3_TXBFC_Clr(SPI_Type* SPIx);
extern void SPIx_CR3_RXBFC_Clr(SPI_Type* SPIx);
extern void SPIx_CR3_MERRC_Clr(SPI_Type* SPIx);
extern void SPIx_CR3_SERRC_Clr(SPI_Type* SPIx);

/* SPI错误中断控制 相关函数 */
extern void SPIx_IER_ERRIE_Setable(SPI_Type* SPIx, FunState NewState);
extern FunState SPIx_IER_ERRIE_Getable(SPI_Type* SPIx);

/* 发送完成中断控制 相关函数 */
extern void SPIx_IER_TXIE_Setable(SPI_Type* SPIx, FunState NewState);
extern FunState SPIx_IER_TXIE_Getable(SPI_Type* SPIx);

/* 接收完成中断控制 相关函数 */
extern void SPIx_IER_RXIE_Setable(SPI_Type* SPIx, FunState NewState);
extern FunState SPIx_IER_RXIE_Getable(SPI_Type* SPIx);

/* 半双工模式下，每帧数据的帧模式 相关函数 */
extern void SPIx_ISR_DCN_TX_Set(SPI_Type* SPIx, uint32_t SetValue);
extern uint32_t SPIx_ISR_DCN_TX_Get(SPI_Type* SPIx);

/* 接收缓存区溢出，软件写1清0 相关函数 */
extern void SPIx_ISR_RXCOL_Clr(SPI_Type* SPIx);
extern FlagStatus SPIx_ISR_RXCOL_Chk(SPI_Type* SPIx);

/* 发送缓存区溢出，软件写1清0 相关函数 */
extern void SPIx_ISR_TXCOL_Clr(SPI_Type* SPIx);
extern FlagStatus SPIx_ISR_TXCOL_Chk(SPI_Type* SPIx);

/* SPI状态标志，只读 相关函数 */
extern FlagStatus SPIx_ISR_BUSY_Chk(SPI_Type* SPIx);

/* 主机错误标志，软件写1清0 相关函数 */
extern void SPIx_ISR_MERR_Clr(SPI_Type* SPIx);
extern FlagStatus SPIx_ISR_MERR_Chk(SPI_Type* SPIx);

/* 从机错误标志，软件写1清0 相关函数 */
extern void SPIx_ISR_SERR_Clr(SPI_Type* SPIx);
extern FlagStatus SPIx_ISR_SERR_Chk(SPI_Type* SPIx);

/* 发送buffer为空标志 相关函数 */
extern void SPIx_ISR_TXBE_Clr(SPI_Type* SPIx);
extern FlagStatus SPIx_ISR_TXBE_Chk(SPI_Type* SPIx);

/* 接收buffer非空标志 相关函数 */
extern void SPIx_ISR_RXBF_Clr(SPI_Type* SPIx);
extern FlagStatus SPIx_ISR_RXBF_Chk(SPI_Type* SPIx);

/* SPI发送缓存 相关函数 */
extern void SPIx_TXBUF_Write(SPI_Type* SPIx, uint32_t SetValue);

/* SPI接收缓存 相关函数 */
extern uint32_t SPIx_RXBUF_Read(SPI_Type* SPIx);

//Announce_End

//Announce_HandBy
extern void SPI_Master_Init(SPI_Type* SPIx, SPI_Master_SInitTypeDef* para);
extern void SPI_Slave_Init(SPI_Type* SPIx, SPI_Slave_SInitTypeDef* para);

extern void SPI_SSN_Set_Low(SPI_Type* SPIx);//SSN置低
extern void SPI_SSN_Set_High(SPI_Type* SPIx);//SSN置高

extern uint8_t SPI_Recv_Byte(SPI_Type* SPIx);//SPI接收一字节
extern void SPI_Send_Byte(SPI_Type* SPIx, uint8_t data);//SPI发送一字节

extern uint8_t SPI_RW_Byte(SPI_Type* SPIx, uint8_t data);//SPI发送并接收一字节
//Announce_End

#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_SPI_H */

/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
