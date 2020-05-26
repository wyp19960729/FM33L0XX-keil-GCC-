/**
  ******************************************************************************
  * @file    fm33l0xx_i2c.h
  * @author  FM33L0xx Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file contains all the functions prototypes for the I2C firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33L0XX_I2C_H
#define __FM33L0XX_I2C_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33L0XX.h" 

//-----------------------------------------------------------------------------------------------------------------------------
#define I2C_SEND_STARTBIT()			I2C_MSP_CR_SEN_Setable(ENABLE)
#define I2C_SEND_RESTARTBIT()		I2C_MSP_CR_RSEN_Setable(ENABLE)
#define I2C_SEND_STOPBIT()			I2C_MSP_CR_PEN_Setable(ENABLE)
	 
#define I2C_SEND_ACK_0()				I2C_MSP_SR_ACKMO_Set(I2C_MSP_SR_ACKMO_RESET)
#define I2C_SEND_ACK_1()				I2C_MSP_SR_ACKMO_Set(I2C_MSP_SR_ACKMO_SET)
	 
	 
#define	I2C_MSP_CFGR_AUTOEND_Pos	17	/* 主机DMA自动终止 */
#define	I2C_MSP_CFGR_AUTOEND_Msk	(0x1U << I2C_MSP_CFGR_AUTOEND_Pos)
#define	I2C_MSP_CFGR_AUTOEND_WAIT	(0x0U << I2C_MSP_CFGR_AUTOEND_Pos)	/* 1：DMA指定长度传输完成后，自动发送STOP时序 */
#define	I2C_MSP_CFGR_AUTOEND_AUTOEND	(0x1U << I2C_MSP_CFGR_AUTOEND_Pos)	/* 0：DMA指定长度传输完成后，等待软件接管 */

#define	I2C_MSP_CFGR_MSP_DMAEN_Pos	16	/* 主机DMA使能 */
#define	I2C_MSP_CFGR_MSP_DMAEN_Msk	(0x1U << I2C_MSP_CFGR_MSP_DMAEN_Pos)
	/* 0：关闭DMA功能 */
	/* 1：使能DMA功能 */

#define	I2C_MSP_CFGR_TOEN_Pos	1	/* SCL拉低超时使能 */
#define	I2C_MSP_CFGR_TOEN_Msk	(0x1U << I2C_MSP_CFGR_TOEN_Pos)
	/* 0：关闭超时功能 */
	/* 1：使能超时功能 */

#define	I2C_MSP_CFGR_MSPEN_Pos	0	/* I2C主机模块使能控制位 */
#define	I2C_MSP_CFGR_MSPEN_Msk	(0x1U << I2C_MSP_CFGR_MSPEN_Pos)
	/* 0 = I2C主机禁止 */
	/* 1 = I2C主机使能 */

#define	I2C_MSP_CR_RCEN_Pos	3	/* 主机接收模式下，接收使能位 */
#define	I2C_MSP_CR_RCEN_Msk	(0x1U << I2C_MSP_CR_RCEN_Pos)
	/* 0：接收禁止 */
	/* 1：主机接收使能 */

#define	I2C_MSP_CR_PEN_Pos	2	/* STOP时序产生使能控制位 */
#define	I2C_MSP_CR_PEN_Msk	(0x1U << I2C_MSP_CR_PEN_Pos)
	/* 0：使能禁止 */
	/* 1:发送STOP时序使能 */

#define	I2C_MSP_CR_RSEN_Pos	1	/* Repeated START时序产生使能控制位 */
#define	I2C_MSP_CR_RSEN_Msk	(0x1U << I2C_MSP_CR_RSEN_Pos)
	/* 0：使能禁止 */
	/* 1:发送重复START时序使能 */

#define	I2C_MSP_CR_SEN_Pos	0	/* START时序产生使能控制位 */
#define	I2C_MSP_CR_SEN_Msk	(0x1U << I2C_MSP_CR_SEN_Pos)
	/* 0：使能禁止 */
	/* 1:发送START时序使能 */

#define	I2C_MSP_IER_WCOLE_Pos	6	/* WCOL中断使能寄存器 */
#define	I2C_MSP_IER_WCOLE_Msk	(0x1U << I2C_MSP_IER_WCOLE_Pos)
	/* 0：禁止写冲突中断 */
	/* 1：允许写冲突中断 */

#define	I2C_MSP_IER_OVTE_Pos	5	/* SCL超时中断使能寄存器 */
#define	I2C_MSP_IER_OVTE_Msk	(0x1U << I2C_MSP_IER_OVTE_Pos)
	/* 0：禁止超时中断 */
	/* 1：允许超时中断 */

#define	I2C_MSP_IER_SE_Pos	4	/* START时序中断使能寄存器 */
#define	I2C_MSP_IER_SE_Msk	(0x1U << I2C_MSP_IER_SE_Pos)
	/* 0：禁止START时序中断 */
	/* 1：允许START时序中断 */

#define	I2C_MSP_IER_PE_Pos	3	/* STOP时序中断使能寄存器 */
#define	I2C_MSP_IER_PE_Msk	(0x1U << I2C_MSP_IER_PE_Pos)
	/* 0：禁止STOP时序中断 */
	/* 1：允许STOP时序中断 */

#define	I2C_MSP_IER_NACKE_Pos	2	/* 主机发送模式下NACK中断使能寄存器 */
#define	I2C_MSP_IER_NACKE_Msk	(0x1U << I2C_MSP_IER_NACKE_Pos)
	/* 0：禁止产生NACK中断 */
	/* 1：允许收到NACK产生中断 */

#define	I2C_MSP_IER_TXIE_Pos	1	/* I2C主机发送完成中断使能 */
#define	I2C_MSP_IER_TXIE_Msk	(0x1U << I2C_MSP_IER_TXIE_Pos)
	/* 0：禁止发送完成中断 */
	/* 1：允许发送完成中断 */

#define	I2C_MSP_IER_RXIE_Pos	0	/* I2C主机接收完成中断使能 */
#define	I2C_MSP_IER_RXIE_Msk	(0x1U << I2C_MSP_IER_RXIE_Pos)
	/* 0：禁止接收完成中断 */
	/* 1：允许接收完成中断 */

#define	I2C_MSP_ISR_WCOL_Pos	6	/* 写冲突检测位 */
#define	I2C_MSP_ISR_WCOL_Msk	(0x1U << I2C_MSP_ISR_WCOL_Pos)

#define	I2C_MSP_ISR_OVT_Pos	5	/* SCL超时中断标志 */
#define	I2C_MSP_ISR_OVT_Msk	(0x1U << I2C_MSP_ISR_OVT_Pos)

#define	I2C_MSP_ISR_S_Pos	4	/* START时序发送完成中断标志 */
#define	I2C_MSP_ISR_S_Msk	(0x1U << I2C_MSP_ISR_S_Pos)

#define	I2C_MSP_ISR_P_Pos	3	/* STOP时序发送完成中断标志 */
#define	I2C_MSP_ISR_P_Msk	(0x1U << I2C_MSP_ISR_P_Pos)

#define	I2C_MSP_ISR_ACKSTA_Pos	2	/* 主控发送模式下，来自从机的回应信号 */
#define	I2C_MSP_ISR_ACKSTA_Msk	(0x1U << I2C_MSP_ISR_ACKSTA_Pos)

#define	I2C_MSP_ISR_TXIF_Pos	1	/* I2C主机发送完成中断标志 */
#define	I2C_MSP_ISR_TXIF_Msk	(0x1U << I2C_MSP_ISR_TXIF_Pos)

#define	I2C_MSP_ISR_RXIF_Pos	0	/* I2C主机接收完成中断标志 */
#define	I2C_MSP_ISR_RXIF_Msk	(0x1U << I2C_MSP_ISR_RXIF_Pos)

#define	I2C_MSP_SR_BUSY_Pos	5	/* I2C通信状态位 */
#define	I2C_MSP_SR_BUSY_Msk	(0x1U << I2C_MSP_SR_BUSY_Pos)

#define	I2C_MSP_SR_RW_Pos	4	/* I2C传输方向状态位 */
#define	I2C_MSP_SR_RW_Msk	(0x1U << I2C_MSP_SR_RW_Pos)

#define	I2C_MSP_SR_BF_Pos	2	/* 缓冲器满状态位 */
#define	I2C_MSP_SR_BF_Msk	(0x1U << I2C_MSP_SR_BF_Pos)

#define	I2C_MSP_SR_ACKMO_Pos	0	/* 主控接收模式下，主机回应信号的状态 */
#define	I2C_MSP_SR_ACKMO_Msk	(0x1U << I2C_MSP_SR_ACKMO_Pos)
#define	I2C_MSP_SR_ACKMO_RESET	(0x0U << I2C_MSP_SR_ACKMO_Pos)	/* 0：主机回发ACK */
#define	I2C_MSP_SR_ACKMO_SET	(0x1U << I2C_MSP_SR_ACKMO_Pos)	/* 1：主机回发NACK */

#define	I2C_MSP_BGR_MSPBRGH_Pos	16	/* 主机发送的SCL时钟高电平宽度 */
#define	I2C_MSP_BGR_MSPBRGH_Msk	(0x1ffU << I2C_MSP_BGR_MSPBRGH_Pos)

#define	I2C_MSP_BGR_MSPBRGL_Pos	0	/* 主机发送的SCL时钟低电平宽度 */
#define	I2C_MSP_BGR_MSPBRGL_Msk	(0x1ffU << I2C_MSP_BGR_MSPBRGL_Pos)

#define	I2C_MSP_BUF_MSPBUF_Pos	0	/* I2C主机收发缓存寄存器 */
#define	I2C_MSP_BUF_MSPBUF_Msk	(0xffU << I2C_MSP_BUF_MSPBUF_Pos)

#define	I2C_MSP_TCR_SDAHD_Pos	0	/* I2C主机时序控制寄存器 */
#define	I2C_MSP_TCR_SDAHD_Msk	(0x1ffU << I2C_MSP_TCR_SDAHD_Pos)

#define	I2C_MSP_TOR_TIMEOUT_Pos	0	/* I2C主机超时寄存器 */
#define	I2C_MSP_TOR_TIMEOUT_Msk	(0xfffU << I2C_MSP_TOR_TIMEOUT_Pos)

#define	I2C_SSP_CR_SCLSEN_Pos	9	/* I2C从机时钟延展使能 */
#define	I2C_SSP_CR_SCLSEN_Msk	(0x1U << I2C_SSP_CR_SCLSEN_Pos)
	/* 0：禁止 */
	/* 1：使能 */

#define	I2C_SSP_CR_SSP_DMAEN_Pos	8	/* I2C从机DMA使能 */
#define	I2C_SSP_CR_SSP_DMAEN_Msk	(0x1U << I2C_SSP_CR_SSP_DMAEN_Pos)
	/* 0：关闭DMA功能 */
	/* 1：使能DMA功能 */

#define	I2C_SSP_CR_ACKEN_Pos	4	/* ACK使能位 */
#define	I2C_SSP_CR_ACKEN_Msk	(0x1U << I2C_SSP_CR_ACKEN_Pos)
	/* 0:slave不回发ACK */
	/* 1:slave接收完成后将回发ACK */

#define	I2C_SSP_CR_SDAO_DLYEN_Pos	3	/* SDA从机输出延迟使能 */
#define	I2C_SSP_CR_SDAO_DLYEN_Msk	(0x1U << I2C_SSP_CR_SDAO_DLYEN_Pos)
	/* 0：bypass从机SDA输出延迟 */
	/* 1：使能从机SDA输出延迟 */

#define	I2C_SSP_CR_SCLI_ANFEN_Pos	2	/* SCL从机输入模拟滤波使能 */
#define	I2C_SSP_CR_SCLI_ANFEN_Msk	(0x1U << I2C_SSP_CR_SCLI_ANFEN_Pos)
	/* 0：bypass模拟滤波 */
	/* 1：使能模拟滤波 */

#define	I2C_SSP_CR_A10EN_Pos	1	/* 10位地址使能 */
#define	I2C_SSP_CR_A10EN_Msk	(0x1U << I2C_SSP_CR_A10EN_Pos)
	/* 0:slave使用7bit address */
	/* 1:slave使用10bit address */

#define	I2C_SSP_CR_SSPEN_Pos	0	/* I2C从机使能位 */
#define	I2C_SSP_CR_SSPEN_Msk	(0x1U << I2C_SSP_CR_SSPEN_Pos)
	/* 0：关闭I2C从机 */
	/* 1：使能I2C从机 */

#define	I2C_SSP_IER_ADEE_Pos	7	/* 从机地址错误中断使能 */
#define	I2C_SSP_IER_ADEE_Msk	(0x1U << I2C_SSP_IER_ADEE_Pos)

#define	I2C_SSP_IER_SE_Pos	6	/* Start中断使能 */
#define	I2C_SSP_IER_SE_Msk	(0x1U << I2C_SSP_IER_SE_Pos)

#define	I2C_SSP_IER_PE_Pos	5	/* Stop中断使能 */
#define	I2C_SSP_IER_PE_Msk	(0x1U << I2C_SSP_IER_PE_Pos)

#define	I2C_SSP_IER_WCOLE_Pos	4	/* WCOL中断使能 */
#define	I2C_SSP_IER_WCOLE_Msk	(0x1U << I2C_SSP_IER_WCOLE_Pos)

#define	I2C_SSP_IER_SSPOVE_Pos	3	/* SSPOV中断使能 */
#define	I2C_SSP_IER_SSPOVE_Msk	(0x1U << I2C_SSP_IER_SSPOVE_Pos)

#define	I2C_SSP_IER_ADME_Pos	2	/* 从机地址匹配中断使能 */
#define	I2C_SSP_IER_ADME_Msk	(0x1U << I2C_SSP_IER_ADME_Pos)

#define	I2C_SSP_IER_TXIE_Pos	1	/* 发送完成中断使能 */
#define	I2C_SSP_IER_TXIE_Msk	(0x1U << I2C_SSP_IER_TXIE_Pos)

#define	I2C_SSP_IER_RXIE_Pos	0	/* 接收完成中断使能 */
#define	I2C_SSP_IER_RXIE_Msk	(0x1U << I2C_SSP_IER_RXIE_Pos)

#define	I2C_SSP_ISR_ADE_Pos	7	/* 从机地址格式错误 */
#define	I2C_SSP_ISR_ADE_Msk	(0x1U << I2C_SSP_ISR_ADE_Pos)

#define	I2C_SSP_ISR_S_Pos	6	/* 检测到start时序 */
#define	I2C_SSP_ISR_S_Msk	(0x1U << I2C_SSP_ISR_S_Pos)

#define	I2C_SSP_ISR_P_Pos	5	/* 检测到stop时序 */
#define	I2C_SSP_ISR_P_Msk	(0x1U << I2C_SSP_ISR_P_Pos)

#define	I2C_SSP_ISR_WCOL_Pos	4	/* 写冲突标志 */
#define	I2C_SSP_ISR_WCOL_Msk	(0x1U << I2C_SSP_ISR_WCOL_Pos)

#define	I2C_SSP_ISR_SSPOV_Pos	3	/* SSPBUF溢出标志 */
#define	I2C_SSP_ISR_SSPOV_Msk	(0x1U << I2C_SSP_ISR_SSPOV_Pos)

#define	I2C_SSP_ISR_ADM_Pos	2	/* 从机地址匹配标志 */
#define	I2C_SSP_ISR_ADM_Msk	(0x1U << I2C_SSP_ISR_ADM_Pos)

#define	I2C_SSP_ISR_TXIF_Pos	1	/* I2C从机发送完成标志 */
#define	I2C_SSP_ISR_TXIF_Msk	(0x1U << I2C_SSP_ISR_TXIF_Pos)

#define	I2C_SSP_ISR_RXIF_Pos	0	/* I2C从机接收完成标志 */
#define	I2C_SSP_ISR_RXIF_Msk	(0x1U << I2C_SSP_ISR_RXIF_Pos)

#define	I2C_SSP_SR_BUSY_Pos	3	/* 从机通信标志 */
#define	I2C_SSP_SR_BUSY_Msk	(0x1U << I2C_SSP_SR_BUSY_Pos)

#define	I2C_SSP_SR_RW_Pos	2	/* 读写方向状态寄存器 */
#define	I2C_SSP_SR_RW_Msk	(0x1U << I2C_SSP_SR_RW_Pos)

#define	I2C_SSP_SR_DA_Pos	1	/* data/address帧指示 */
#define	I2C_SSP_SR_DA_Msk	(0x1U << I2C_SSP_SR_DA_Pos)

#define	I2C_SSP_SR_BF_Pos	0	/* 从机数据缓冲区满标志 */
#define	I2C_SSP_SR_BF_Msk	(0x1U << I2C_SSP_SR_BF_Pos)

#define	I2C_SSP_BUF_SSPBUF_Pos	0	/* I2C从机收发缓存寄存器 */
#define	I2C_SSP_BUF_SSPBUF_Msk	(0xffU << I2C_SSP_BUF_SSPBUF_Pos)

#define	I2C_SSP_ADR_SSPADDR_Pos	0	/* I2C从机地址寄存器 */
#define	I2C_SSP_ADR_SSPADDR_Msk	(0x3ffU << I2C_SSP_ADR_SSPADDR_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void I2C_Deinit(void);

/* 主机DMA自动终止 相关函数 */
extern void I2C_MSP_CFGR_AUTOEND_Set(uint32_t SetValue);
extern uint32_t I2C_MSP_CFGR_AUTOEND_Get(void);

/* 主机DMA使能 相关函数 */
extern void I2C_MSP_CFGR_MSP_DMAEN_Setable(FunState NewState);
extern FunState I2C_MSP_CFGR_MSP_DMAEN_Getable(void);

/* SCL拉低超时使能 相关函数 */
extern void I2C_MSP_CFGR_TOEN_Setable(FunState NewState);
extern FunState I2C_MSP_CFGR_TOEN_Getable(void);

/* I2C主机模块使能控制位 相关函数 */
extern void I2C_MSP_CFGR_MSPEN_Setable(FunState NewState);
extern FunState I2C_MSP_CFGR_MSPEN_Getable(void);

/* 主机接收模式下，接收使能位 相关函数 */
extern void I2C_MSP_CR_RCEN_Setable(FunState NewState);
extern FunState I2C_MSP_CR_RCEN_Getable(void);

/* STOP时序产生使能控制位 相关函数 */
extern void I2C_MSP_CR_PEN_Setable(FunState NewState);
extern FunState I2C_MSP_CR_PEN_Getable(void);

/* Repeated START时序产生使能控制位 相关函数 */
extern void I2C_MSP_CR_RSEN_Setable(FunState NewState);
extern FunState I2C_MSP_CR_RSEN_Getable(void);

/* START时序产生使能控制位 相关函数 */
extern void I2C_MSP_CR_SEN_Setable(FunState NewState);
extern FunState I2C_MSP_CR_SEN_Getable(void);

/* WCOL中断使能寄存器 相关函数 */
extern void I2C_MSP_IER_WCOLE_Setable(FunState NewState);
extern FunState I2C_MSP_IER_WCOLE_Getable(void);

/* SCL超时中断使能寄存器 相关函数 */
extern void I2C_MSP_IER_OVTE_Setable(FunState NewState);
extern FunState I2C_MSP_IER_OVTE_Getable(void);

/* START时序中断使能寄存器 相关函数 */
extern void I2C_MSP_IER_SE_Setable(FunState NewState);
extern FunState I2C_MSP_IER_SE_Getable(void);

/* STOP时序中断使能寄存器 相关函数 */
extern void I2C_MSP_IER_PE_Setable(FunState NewState);
extern FunState I2C_MSP_IER_PE_Getable(void);

/* 主机发送模式下NACK中断使能寄存器 相关函数 */
extern void I2C_MSP_IER_NACKE_Setable(FunState NewState);
extern FunState I2C_MSP_IER_NACKE_Getable(void);

/* I2C主机发送完成中断使能 相关函数 */
extern void I2C_MSP_IER_TXIE_Setable(FunState NewState);
extern FunState I2C_MSP_IER_TXIE_Getable(void);

/* I2C主机接收完成中断使能 相关函数 */
extern void I2C_MSP_IER_RXIE_Setable(FunState NewState);
extern FunState I2C_MSP_IER_RXIE_Getable(void);

/* 写冲突检测位 相关函数 */
extern void I2C_MSP_ISR_WCOL_Clr(void);
extern FlagStatus I2C_MSP_ISR_WCOL_Chk(void);

/* SCL超时中断标志 相关函数 */
extern void I2C_MSP_ISR_OVT_Clr(void);
extern FlagStatus I2C_MSP_ISR_OVT_Chk(void);

/* START时序发送完成中断标志 相关函数 */
extern FlagStatus I2C_MSP_ISR_S_Chk(void);
extern void I2C_MSP_ISR_S_Clr(void);

/* STOP时序发送完成中断标志 相关函数 */
extern FlagStatus I2C_MSP_ISR_P_Chk(void);
extern void I2C_MSP_ISR_P_Clr(void);

/* 主控发送模式下，来自从机的回应信号 相关函数 */
extern void I2C_MSP_ISR_ACKSTA_Clr(void);
extern FlagStatus I2C_MSP_ISR_ACKSTA_Chk(void);

/* I2C主机发送完成中断标志 相关函数 */
extern void I2C_MSP_ISR_TXIF_Clr(void);
extern FlagStatus I2C_MSP_ISR_TXIF_Chk(void);

/* I2C主机接收完成中断标志 相关函数 */
extern void I2C_MSP_ISR_RXIF_Clr(void);
extern FlagStatus I2C_MSP_ISR_RXIF_Chk(void);

/* I2C通信状态位 相关函数 */
extern FlagStatus I2C_MSP_SR_BUSY_Chk(void);

/* I2C传输方向状态位 相关函数 */
extern FlagStatus I2C_MSP_SR_RW_Chk(void);

/* 缓冲器满状态位 相关函数 */
extern FlagStatus I2C_MSP_SR_BF_Chk(void);

/* 主控接收模式下，主机回应信号的状态 相关函数 */
extern void I2C_MSP_SR_ACKMO_Set(uint32_t SetValue);
extern uint32_t I2C_MSP_SR_ACKMO_Get(void);

/* 主机发送的SCL时钟高电平宽度 相关函数 */
extern void I2C_MSP_BGR_MSPBRGH_Set(uint32_t SetValue);
extern uint32_t I2C_MSP_BGR_MSPBRGH_Get(void);

/* 主机发送的SCL时钟低电平宽度 相关函数 */
extern void I2C_MSP_BGR_MSPBRGL_Set(uint32_t SetValue);
extern uint32_t I2C_MSP_BGR_MSPBRGL_Get(void);

/* I2C主机收发缓存寄存器 相关函数 */
extern void I2C_MSP_BUF_Write(uint32_t SetValue);
extern uint32_t I2C_MSP_BUF_Read(void);

/* I2C主机时序控制寄存器 相关函数 */
extern void I2C_MSP_TCR_SDAHD_Set(uint32_t SetValue);
extern uint32_t I2C_MSP_TCR_SDAHD_Get(void);

/* I2C主机超时寄存器 相关函数 */
extern void I2C_MSP_TOR_TIMEOUT_Set(uint32_t SetValue);
extern uint32_t I2C_MSP_TOR_TIMEOUT_Get(void);

/* I2C从机时钟延展使能 相关函数 */
extern void I2C_SSP_CR_SCLSEN_Setable(FunState NewState);
extern FunState I2C_SSP_CR_SCLSEN_Getable(void);

/* I2C从机DMA使能 相关函数 */
extern void I2C_SSP_CR_SSP_DMAEN_Setable(FunState NewState);
extern FunState I2C_SSP_CR_SSP_DMAEN_Getable(void);

/* ACK使能位 相关函数 */
extern void I2C_SSP_CR_ACKEN_Setable(FunState NewState);
extern FunState I2C_SSP_CR_ACKEN_Getable(void);

/* SDA从机输出延迟使能 相关函数 */
extern void I2C_SSP_CR_SDAO_DLYEN_Setable(FunState NewState);
extern FunState I2C_SSP_CR_SDAO_DLYEN_Getable(void);

/* SCL从机输入模拟滤波使能 相关函数 */
extern void I2C_SSP_CR_SCLI_ANFEN_Setable(FunState NewState);
extern FunState I2C_SSP_CR_SCLI_ANFEN_Getable(void);

/* 10位地址使能 相关函数 */
extern void I2C_SSP_CR_A10EN_Setable(FunState NewState);
extern FunState I2C_SSP_CR_A10EN_Getable(void);

/* I2C从机使能位 相关函数 */
extern void I2C_SSP_CR_SSPEN_Setable(FunState NewState);
extern FunState I2C_SSP_CR_SSPEN_Getable(void);

/* 从机地址错误中断使能 相关函数 */
extern void I2C_SSP_IER_ADEE_Setable(FunState NewState);
extern FunState I2C_SSP_IER_ADEE_Getable(void);

/* Start中断使能 相关函数 */
extern void I2C_SSP_IER_SE_Setable(FunState NewState);
extern FunState I2C_SSP_IER_SE_Getable(void);

/* Stop中断使能 相关函数 */
extern void I2C_SSP_IER_PE_Setable(FunState NewState);
extern FunState I2C_SSP_IER_PE_Getable(void);

/* WCOL中断使能 相关函数 */
extern void I2C_SSP_IER_WCOLE_Setable(FunState NewState);
extern FunState I2C_SSP_IER_WCOLE_Getable(void);

/* SSPOV中断使能 相关函数 */
extern void I2C_SSP_IER_SSPOVE_Setable(FunState NewState);
extern FunState I2C_SSP_IER_SSPOVE_Getable(void);

/* 从机地址匹配中断使能 相关函数 */
extern void I2C_SSP_IER_ADME_Setable(FunState NewState);
extern FunState I2C_SSP_IER_ADME_Getable(void);

/* 发送完成中断使能 相关函数 */
extern void I2C_SSP_IER_TXIE_Setable(FunState NewState);
extern FunState I2C_SSP_IER_TXIE_Getable(void);

/* 接收完成中断使能 相关函数 */
extern void I2C_SSP_IER_RXIE_Setable(FunState NewState);
extern FunState I2C_SSP_IER_RXIE_Getable(void);

/* 从机地址格式错误 相关函数 */
extern void I2C_SSP_ISR_ADE_Clr(void);
extern FlagStatus I2C_SSP_ISR_ADE_Chk(void);

/* 检测到start时序 相关函数 */
extern FlagStatus I2C_SSP_ISR_S_Chk(void);

/* 检测到stop时序 相关函数 */
extern FlagStatus I2C_SSP_ISR_P_Chk(void);

/* 写冲突标志 相关函数 */
extern void I2C_SSP_ISR_WCOL_Clr(void);
extern FlagStatus I2C_SSP_ISR_WCOL_Chk(void);

/* SSPBUF溢出标志 相关函数 */
extern void I2C_SSP_ISR_SSPOV_Clr(void);
extern FlagStatus I2C_SSP_ISR_SSPOV_Chk(void);

/* 从机地址匹配标志 相关函数 */
extern void I2C_SSP_ISR_ADM_Clr(void);
extern FlagStatus I2C_SSP_ISR_ADM_Chk(void);

/* I2C从机发送完成标志 相关函数 */
extern void I2C_SSP_ISR_TXIF_Clr(void);
extern FlagStatus I2C_SSP_ISR_TXIF_Chk(void);

/* I2C从机接收完成标志 相关函数 */
extern void I2C_SSP_ISR_RXIF_Clr(void);
extern FlagStatus I2C_SSP_ISR_RXIF_Chk(void);

/* 从机通信标志 相关函数 */
extern FlagStatus I2C_SSP_SR_BUSY_Chk(void);

/* 读写方向状态寄存器 相关函数 */
extern FlagStatus I2C_SSP_SR_RW_Chk(void);

/* data/address帧指示 相关函数 */
extern FlagStatus I2C_SSP_SR_DA_Chk(void);

/* 从机数据缓冲区满标志 相关函数 */
extern FlagStatus I2C_SSP_SR_BF_Chk(void);

/* I2C从机收发缓存寄存器 相关函数 */
extern void I2C_SSP_BUF_Write(uint32_t SetValue);
extern uint32_t I2C_SSP_BUF_Read(void);

/* I2C从机地址寄存器 相关函数 */
extern void I2C_SSP_ADR_SSPADDR_Set(uint32_t SetValue);
extern uint32_t I2C_SSP_ADR_SSPADDR_Get(void);

extern uint32_t I2C_BaudREG_Calc(uint32_t I2CClk, uint32_t APBClk);
#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_I2C_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
