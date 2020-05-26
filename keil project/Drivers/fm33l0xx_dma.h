/**
  ******************************************************************************
  * @file    fm33l0xx_dma.h
  * @author  FM33l0xx Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file contains all the functions prototypes for the DMA firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __FM33L0XX_DMA_H
#define __FM33L0XX_DMA_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33L0XX.h" 

typedef enum {
    DMA_CH0 = 0, 
    DMA_CH1 = 1, 
    DMA_CH2 = 2, 
    DMA_CH3 = 3, 
    DMA_CH4 = 4, 
    DMA_CH5 = 5, 
    DMA_CH6 = 6, 
    DMA_CH7 = 7	
}DMA_CH_Type;


typedef struct
{
	DMA_CH_Type CHx;			//DMA通道号
    
	uint32_t CHxTSIZE;          //通道传输长度
	uint32_t CHxPRI;            //通道优先级
	uint32_t CHxINC;            //CH0~CH6通道地址增长方向,CH7无意义
	uint32_t CHxSSEL;           //CH0~CH6外设通道选择,CH7传输方式选择
    uint32_t CHxDIR;            //CH0~CH6通道传输方向选择
	FunState CHxFTIE;           //通道传输完成中断使能
	FunState CHxHTIE;           //通道传输半程中断使能
	FunState CHxEN;             //通道使能
    
	uint32_t CHxRAMAD;          //CH0~CH7通道RAM指针地址,注意CH7使用的是word地址，驱动里已处理过了，
	uint32_t CH7FLSAD;			//通道FLASH指针地址，仅针对通道7有意义	
}DMA_InitTypeDef;
     
#define	DMA_GCR_DMAEN_Pos	0	/* DMA全局使能 */
#define	DMA_GCR_DMAEN_Msk	(0x1U << DMA_GCR_DMAEN_Pos)
	/* 关闭 */
	/* 使能 */

#define	DMA_CHx_CR_TSIZE_Pos	16	/* DMA通道传输数据长度控制 */
#define	DMA_CHx_CR_TSIZE_Msk	(0xffffU << DMA_CHx_CR_TSIZE_Pos)

#define	DMA_CHx_CR_PRI_Pos	12	/* 通道优先级 */
#define	DMA_CHx_CR_PRI_Msk	(0x3U << DMA_CHx_CR_PRI_Pos)
#define	DMA_CHx_CR_PRI_LOW	(0x0U << DMA_CHx_CR_PRI_Pos)	/* 低 */
#define	DMA_CHx_CR_PRI_MEDIUM	(0x1U << DMA_CHx_CR_PRI_Pos)	/* 中 */
#define	DMA_CHx_CR_PRI_HIGH	(0x2U << DMA_CHx_CR_PRI_Pos)	/* 高 */
#define	DMA_CHx_CR_PRI_VERYHIGH	(0x3U << DMA_CHx_CR_PRI_Pos)	/* 非常高 */

#define	DMA_CHx_CR_INC_Pos	11	/* RAM地址方向控制 */
#define	DMA_CHx_CR_INC_Msk	(0x1U << DMA_CHx_CR_INC_Pos)
#define	DMA_CHx_CR_INC_DEC	(0x0U << DMA_CHx_CR_INC_Pos)	/* 递减 */
#define	DMA_CHx_CR_INC_INC	(0x1U << DMA_CHx_CR_INC_Pos)	/* 递增 */

#define	DMA_CHx_CR_SSEL_Pos	8	/* 通道外设请求 */
#define	DMA_CHx_CR_SSEL_Msk	(0x7U << DMA_CHx_CR_SSEL_Pos)

#define	DMA_CH0_CR_SSEL_ADC_OUT	    (0x0U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH0_CR_SSEL_LPUART0_RX	(0x1U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH0_CR_SSEL_LPUART1_TX	(0x2U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH0_CR_SSEL_AES_IN	    (0x3U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH0_CR_SSEL_CRC_OUT	    (0x4U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH0_CR_SSEL_ATIM_CH1	(0x5U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH0_CR_SSEL_GTIM0_CH1	(0x6U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH0_CR_SSEL_GTIM1_CH1	(0x7U << DMA_CHx_CR_SSEL_Pos)

#define	DMA_CH1_CR_SSEL_UART0_RX	(0x0U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH1_CR_SSEL_LPUART0_TX	(0x1U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH1_CR_SSEL_I2C_RX	    (0x2U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH1_CR_SSEL_AES_OUT	    (0x3U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH1_CR_SSEL_ATIM_CH2	(0x4U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH1_CR_SSEL_GTIM0_CH2	(0x5U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH1_CR_SSEL_GTIM1_CH2	(0x6U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH1_CR_SSEL_LPT32_CH1	(0x7U << DMA_CHx_CR_SSEL_Pos)

#define	DMA_CH2_CR_SSEL_SPI2_RX	    (0x0U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH2_CR_SSEL_UART0_TX	(0x1U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH2_CR_SSEL_UART4_RX	(0x2U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH2_CR_SSEL_LPUART1_RX	(0x3U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH2_CR_SSEL_I2C_TX  	(0x4U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH2_CR_SSEL_ATIM_CH3	(0x5U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH2_CR_SSEL_GTIM0_CH3	(0x6U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH2_CR_SSEL_GTIM1_CH3	(0x7U << DMA_CHx_CR_SSEL_Pos)

#define	DMA_CH3_CR_SSEL_SPI1_RX	    (0x0U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH3_CR_SSEL_UART0_RX	(0x1U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH3_CR_SSEL_UART1_RX	(0x2U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH3_CR_SSEL_UART4_TX	(0x3U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH3_CR_SSEL_LPUART0_RX	(0x4U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH3_CR_SSEL_ATIM_CH4	(0x5U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH3_CR_SSEL_GTIM0_CH4	(0x6U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH3_CR_SSEL_GTIM1_CH4	(0x7U << DMA_CHx_CR_SSEL_Pos)

#define	DMA_CH4_CR_SSEL_ADC_OUT	    (0x0U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH4_CR_SSEL_SPI1_TX     (0x1U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH4_CR_SSEL_SPI2_TX	    (0x2U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH4_CR_SSEL_UART0_TX	(0x3U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH4_CR_SSEL_UART1_TX	(0x4U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH4_CR_SSEL_UART5_RX	(0x5U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH4_CR_SSEL_I2C_RX	    (0x6U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH4_CR_SSEL_ATIM_TRIG	(0x7U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH4_CR_SSEL_ATIM_COM	(0x7U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH4_CR_SSEL_ATIM_UEV	(0x7U << DMA_CHx_CR_SSEL_Pos)

#define	DMA_CH5_CR_SSEL_SPI1_RX	    (0x0U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH5_CR_SSEL_SPI2_RX	    (0x1U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH5_CR_SSEL_UART1_RX	(0x2U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH5_CR_SSEL_LPUART0_TX	(0x3U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH5_CR_SSEL_LPUART1_RX	(0x4U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH5_CR_SSEL_U7816_RX	(0x5U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH5_CR_SSEL_GTIM1_TRIG	(0x6U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH5_CR_SSEL_GTIM1_UEV	(0x6U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH5_CR_SSEL_LPT32_CH2	(0x7U << DMA_CHx_CR_SSEL_Pos)

#define	DMA_CH6_CR_SSEL_SPI1_TX	    (0x0U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH6_CR_SSEL_SPI2_TX	    (0x1U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH6_CR_SSEL_UART1_TX	(0x2U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH6_CR_SSEL_UART5_TX	(0x3U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH6_CR_SSEL_LPUART1_TX	(0x4U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH6_CR_SSEL_U7816_TX	(0x5U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH6_CR_SSEL_I2C_TX	    (0x6U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH6_CR_SSEL_GTIM0_TRIG	(0x7U << DMA_CHx_CR_SSEL_Pos)
#define	DMA_CH6_CR_SSEL_GTIM0_UEV	(0x7U << DMA_CHx_CR_SSEL_Pos)

#define	DMA_CHx_CR_DIR_Pos	6	/* 通道传输方向 */
#define	DMA_CHx_CR_DIR_Msk	(0x1U << DMA_CHx_CR_DIR_Pos)
#define	DMA_CHx_CR_DIR_PER_TO_RAM	(0x0U << DMA_CHx_CR_DIR_Pos)	/* 从外设读取数据写入RAM */
#define	DMA_CHx_CR_DIR_RAM_TO_PER	(0x1U << DMA_CHx_CR_DIR_Pos)	/* 从RAM读取数据写入外设 */

#define	DMA_CHx_CR_BDW_Pos	4	/* 传输带宽设置 */
#define	DMA_CHx_CR_BDW_Msk	(0x3U << DMA_CHx_CR_BDW_Pos)
#define	DMA_CHx_CR_BDW_8BIT	    (0x0U << DMA_CHx_CR_BDW_Pos)	/* 字节，8bit */
#define	DMA_CHx_CR_BDW_16BIT	(0x1U << DMA_CHx_CR_BDW_Pos)	/* 半字，16bit */
#define	DMA_CHx_CR_BDW_32BIT	(0x2U << DMA_CHx_CR_BDW_Pos)	/* 字，32bit */

#define	DMA_CHx_CR_CIRC_Pos	3	/* 循环缓冲模式 */
#define	DMA_CHx_CR_CIRC_Msk	(0x1U << DMA_CHx_CR_CIRC_Pos)
#define	DMA_CHx_CR_CIRC_DISABLE	(0x0U << DMA_CHx_CR_CIRC_Pos)	/* 关闭 */
#define	DMA_CHx_CR_CIRC_ENABLE	(0x1U << DMA_CHx_CR_CIRC_Pos)	/* 使能 */

#define	DMA_CHx_CR_FTIE_Pos	2	/* 传输完成中断 */
#define	DMA_CHx_CR_FTIE_Msk	(0x1U << DMA_CHx_CR_FTIE_Pos)
	/* 关闭 */
	/* 使能 */

#define	DMA_CHx_CR_HTIE_Pos	1	/* 半程传输中断 */
#define	DMA_CHx_CR_HTIE_Msk	(0x1U << DMA_CHx_CR_HTIE_Pos)
	/* 关闭 */
	/* 使能 */

#define	DMA_CHx_CR_EN_Pos	0	/* 通道控制 */
#define	DMA_CHx_CR_EN_Msk	(0x1U << DMA_CHx_CR_EN_Pos)
	/* 关闭 */
	/* 使能 */

#define	DMA_CHx_MAD_MEMAD_Pos	0	/* 存储器指针地址 */
#define	DMA_CHx_MAD_MEMAD_Msk	(0xffffffffU << DMA_CHx_MAD_MEMAD_Pos)

#define	DMA_CH7_CR_TSIZE_Pos	16	/* 传输数据长度 */
#define	DMA_CH7_CR_TSIZE_Msk	(0xfffU << DMA_CH7_CR_TSIZE_Pos)

#define	DMA_CH7_CR_PRI_Pos	12	/* 优先级控制 */
#define	DMA_CH7_CR_PRI_Msk	(0x3U << DMA_CH7_CR_PRI_Pos)
#define	DMA_CH7_CR_PRI_LOW	(0x0U << DMA_CH7_CR_PRI_Pos)	/* 低 */
#define	DMA_CH7_CR_PRI_MEDIUM	(0x1U << DMA_CH7_CR_PRI_Pos)	/* 中 */
#define	DMA_CH7_CR_PRI_HIGH	(0x2U << DMA_CH7_CR_PRI_Pos)	/* 高 */
#define	DMA_CH7_CR_PRI_VERYHIGH	(0x3U << DMA_CH7_CR_PRI_Pos)	/* 非常高 */

//BIT10	CH7DIR	Channel7传输方向
//1：Flash->RAM传输
//0：RAM->Flash传输
//BIT9	CH7RI	Channel7 RAM地址增减设置，仅在Flash->RAM传输中有效
//1：RAM地址递增
//0：RAM地址递减
//BIT8	CH7FI	Channel7 Flash地址增减设置，仅在Flash->RAM传输中有效
//1：Flash地址递增
//0：Flash地址递减
#define	DMA_CH7_CR_SSEL_Pos	8	/* Channel7外设通道选择 */
#define	DMA_CH7_CR_SSEL_Msk	(0x7U << DMA_CH7_CR_SSEL_Pos)
#define	DMA_CH7_CR_SSEL_RFRMFM	(0x0U << DMA_CH7_CR_SSEL_Pos)	/* Channel7 RAM->FLASH传输 RAM地址递减 FLASH地址递减 */
#define	DMA_CH7_CR_SSEL_RFRMFP	(0x1U << DMA_CH7_CR_SSEL_Pos)	/* Channel7 RAM->FLASH传输 RAM地址递减 FLASH地址递增 */
#define	DMA_CH7_CR_SSEL_RFRPFM	(0x2U << DMA_CH7_CR_SSEL_Pos)	/* Channel7 RAM->FLASH传输 RAM地址递增 FLASH地址递减 */
#define	DMA_CH7_CR_SSEL_RFRPFP	(0x3U << DMA_CH7_CR_SSEL_Pos)	/* Channel7 RAM->FLASH传输 RAM地址递增 FLASH地址递增 */
#define	DMA_CH7_CR_SSEL_FRRMFM	(0x4U << DMA_CH7_CR_SSEL_Pos)	/* Channel7 FLASH->RAM传输 RAM地址递减 FLASH地址递减 */
#define	DMA_CH7_CR_SSEL_FRRMFP	(0x5U << DMA_CH7_CR_SSEL_Pos)	/* Channel7 FLASH->RAM传输 RAM地址递减 FLASH地址递增 */
#define	DMA_CH7_CR_SSEL_FRRPFM	(0x6U << DMA_CH7_CR_SSEL_Pos)	/* Channel7 FLASH->RAM传输 RAM地址递增 FLASH地址递减 */
#define	DMA_CH7_CR_SSEL_FRRPFP	(0x7U << DMA_CH7_CR_SSEL_Pos)	/* Channel7 FLASH->RAM传输 RAM地址递增 FLASH地址递增 */

//#define	DMA_CH7_CR_DIR_Pos	10	/* 传输方向 */
//#define	DMA_CH7_CR_DIR_Msk	(0x1U << DMA_CH7_CR_DIR_Pos)
//#define	DMA_CH7_CR_DIR_RAM_TO_FLASH	(0x0U << DMA_CH7_CR_DIR_Pos)	/* Ram到Flash */
//#define	DMA_CH7_CR_DIR_FLASH_TO_RAM	(0x1U << DMA_CH7_CR_DIR_Pos)	/* Flash到Ram */

//#define	DMA_CH7_CR_RI_Pos	9	/* RAM地址增减设置 */
//#define	DMA_CH7_CR_RI_Msk	(0x1U << DMA_CH7_CR_RI_Pos)
//#define	DMA_CH7_CR_RI_DEC	(0x0U << DMA_CH7_CR_RI_Pos)	/* 递减 */
//#define	DMA_CH7_CR_RI_INC	(0x1U << DMA_CH7_CR_RI_Pos)	/* 递增 */

//#define	DMA_CH7_CR_FI_Pos	8	/* Flash地址增减设置 */
//#define	DMA_CH7_CR_FI_Msk	(0x1U << DMA_CH7_CR_FI_Pos)
//#define	DMA_CH7_CR_FI_DEC	(0x0U << DMA_CH7_CR_FI_Pos)	/* 递减 */
//#define	DMA_CH7_CR_FI_INC	(0x1U << DMA_CH7_CR_FI_Pos)	/* 递增 */

#define	DMAx_CH7_FLSAD_FLSAD_Pos	0	/* 通道7 Flash指针地址 */
#define	DMAx_CH7_FLSAD_FLSAD_Msk	(0x7fffU << DMAx_CH7_FLSAD_FLSAD_Pos)

#define	DMAx_CH7_RAMAD_RAMAD_Pos	0	/* 通道7 RAM字指针地址 */
#define	DMAx_CH7_RAMAD_RAMAD_Msk	(0xfffU << DMAx_CH7_RAMAD_RAMAD_Pos)

#define	DMA_CH7_CR_FTIE_Pos	2	/* 传输完成中断 */
#define	DMA_CH7_CR_FTIE_Msk	(0x1U << DMA_CH7_CR_FTIE_Pos)
	/* 关闭 */
	/* 使能 */

#define	DMA_CH7_CR_HTIE_Pos	1	/* 半程传输中断 */
#define	DMA_CH7_CR_HTIE_Msk	(0x1U << DMA_CH7_CR_HTIE_Pos)
	/* 关闭 */
	/* 使能 */

#define	DMA_CH7_CR_EN_Pos	0	/* 通道控制 */
#define	DMA_CH7_CR_EN_Msk	(0x1U << DMA_CH7_CR_EN_Pos)
	/* 关闭 */
	/* 使能 */
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void DMA_Deinit(void);

/* DMA全局使能 相关函数 */
extern void DMA_GCR_DMAEN_Setable(FunState NewState);
extern FunState DMA_GCR_DMAEN_Getable(void);

/* DMA通道传输数据长度控制 相关函数 */
extern void DMA_CHx_CR_TSIZE_Set(DMA_CH_Type CHx, uint32_t SetValue);
extern uint32_t DMA_CHx_CR_TSIZE_Get(DMA_CH_Type CHx);

/* 通道优先级 相关函数 */
extern void DMA_CHx_CR_PRI_Set(DMA_CH_Type CHx, uint32_t SetValue);
extern uint32_t DMA_CHx_CR_PRI_Get(DMA_CH_Type CHx);

/* RAM地址方向控制 相关函数 */
extern void DMA_CHx_CR_INC_Set(DMA_CH_Type CHx, uint32_t SetValue);
extern uint32_t DMA_CHx_CR_INC_Get(DMA_CH_Type CHx);

/* 通道外设请求 相关函数 */
extern void DMA_CHx_CR_SSEL_Set(DMA_CH_Type CHx, uint32_t SetValue);
extern uint32_t DMA_CHx_CR_SSEL_Get(DMA_CH_Type CHx);

/* 通道传输方向 相关函数 */
extern void DMA_CHx_CR_DIR_Set(DMA_CH_Type CHx, uint32_t SetValue);
extern uint32_t DMA_CHx_CR_DIR_Get(DMA_CH_Type CHx);

/* 传输带宽设置 相关函数 */
extern void DMA_CHx_CR_BDW_Set(DMA_CH_Type CHx, uint32_t SetValue);
extern uint32_t DMA_CHx_CR_BDW_Get(DMA_CH_Type CHx);

/* 循环缓冲模式 相关函数 */
extern void DMA_CHx_CR_CIRC_Setable(DMA_CH_Type CHx, FunState NewState);
extern FunState DMA_CHx_CR_CIRC_Getable(DMA_CH_Type CHx);

/* 传输完成中断 相关函数 */
extern void DMA_CHx_CR_FTIE_Setable(DMA_CH_Type CHx, FunState NewState);
extern FunState DMA_CHx_CR_FTIE_Getable(DMA_CH_Type CHx);

/* 半程传输中断 相关函数 */
extern void DMA_CHx_CR_HTIE_Setable(DMA_CH_Type CHx, FunState NewState);
extern FunState DMA_CHx_CR_HTIE_Getable(DMA_CH_Type CHx);

/* 通道控制 相关函数 */
extern void DMA_CHx_CR_EN_Setable(DMA_CH_Type CHx, FunState NewState);
extern FunState DMA_CHx_CR_EN_Getable(DMA_CH_Type CHx);

/* 传输数据长度 相关函数 */
extern void DMA_CH7_CR_TSIZE_Set(uint32_t SetValue);
extern uint32_t DMA_CH7_CR_TSIZE_Get(void);

/* 优先级控制 相关函数 */
extern void DMA_CH7_CR_PRI_Set(uint32_t SetValue);
extern uint32_t DMA_CH7_CR_PRI_Get(void);

/* 通道外设请求 相关函数 */
void DMA_CH7_CR_SSEL_Set(uint32_t SetValue);
uint32_t DMA_CH7_CR_SSEL_Get(void);

/* 传输完成中断 相关函数 */
extern void DMA_CH7_CR_FTIE_Setable(FunState NewState);
extern FunState DMA_CH7_CR_FTIE_Getable(void);

/* 半程传输中断 相关函数 */
extern void DMA_CH7_CR_HTIE_Setable(FunState NewState);
extern FunState DMA_CH7_CR_HTIE_Getable(void);

/* 通道控制 相关函数 */
extern void DMA_CH7_CR_EN_Setable(FunState NewState);
extern FunState DMA_CH7_CR_EN_Getable(void);

/* 存储器指针地址 相关函数 */
extern void DMA_CHx_MAD_MEMAD_Write(DMA_CH_Type CHx, uint32_t SetValue);

/* 通道7 FLASH指针地址 相关函数 */
extern void DMA_CH7_FLSAD_Write(uint32_t SetValue);

/* 通道7 RAM指针地址 相关函数 */
extern void DMA_CH7_RAMAD_Write(uint32_t SetValue);

/* 传输完成中断 相关函数 */
extern void DMA_ISR_CHFT_Clr(DMA_CH_Type CHx);
extern FlagStatus DMA_ISR_CHFT_Chk(DMA_CH_Type CHx);

/* 传输半程中断 相关函数 */
extern void DMA_ISR_CHHT_Clr(DMA_CH_Type CHx);
extern FlagStatus DMA_ISR_CHHT_Chk(DMA_CH_Type CHx);

//Announce_End

extern void DMA_Init(DMA_InitTypeDef* para);

#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_DMA_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
