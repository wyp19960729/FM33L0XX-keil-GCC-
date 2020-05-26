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
	DMA_CH_Type CHx;			//DMAͨ����
    
	uint32_t CHxTSIZE;          //ͨ�����䳤��
	uint32_t CHxPRI;            //ͨ�����ȼ�
	uint32_t CHxINC;            //CH0~CH6ͨ����ַ��������,CH7������
	uint32_t CHxSSEL;           //CH0~CH6����ͨ��ѡ��,CH7���䷽ʽѡ��
    uint32_t CHxDIR;            //CH0~CH6ͨ�����䷽��ѡ��
	FunState CHxFTIE;           //ͨ����������ж�ʹ��
	FunState CHxHTIE;           //ͨ���������ж�ʹ��
	FunState CHxEN;             //ͨ��ʹ��
    
	uint32_t CHxRAMAD;          //CH0~CH7ͨ��RAMָ���ַ,ע��CH7ʹ�õ���word��ַ���������Ѵ�����ˣ�
	uint32_t CH7FLSAD;			//ͨ��FLASHָ���ַ�������ͨ��7������	
}DMA_InitTypeDef;
     
#define	DMA_GCR_DMAEN_Pos	0	/* DMAȫ��ʹ�� */
#define	DMA_GCR_DMAEN_Msk	(0x1U << DMA_GCR_DMAEN_Pos)
	/* �ر� */
	/* ʹ�� */

#define	DMA_CHx_CR_TSIZE_Pos	16	/* DMAͨ���������ݳ��ȿ��� */
#define	DMA_CHx_CR_TSIZE_Msk	(0xffffU << DMA_CHx_CR_TSIZE_Pos)

#define	DMA_CHx_CR_PRI_Pos	12	/* ͨ�����ȼ� */
#define	DMA_CHx_CR_PRI_Msk	(0x3U << DMA_CHx_CR_PRI_Pos)
#define	DMA_CHx_CR_PRI_LOW	(0x0U << DMA_CHx_CR_PRI_Pos)	/* �� */
#define	DMA_CHx_CR_PRI_MEDIUM	(0x1U << DMA_CHx_CR_PRI_Pos)	/* �� */
#define	DMA_CHx_CR_PRI_HIGH	(0x2U << DMA_CHx_CR_PRI_Pos)	/* �� */
#define	DMA_CHx_CR_PRI_VERYHIGH	(0x3U << DMA_CHx_CR_PRI_Pos)	/* �ǳ��� */

#define	DMA_CHx_CR_INC_Pos	11	/* RAM��ַ������� */
#define	DMA_CHx_CR_INC_Msk	(0x1U << DMA_CHx_CR_INC_Pos)
#define	DMA_CHx_CR_INC_DEC	(0x0U << DMA_CHx_CR_INC_Pos)	/* �ݼ� */
#define	DMA_CHx_CR_INC_INC	(0x1U << DMA_CHx_CR_INC_Pos)	/* ���� */

#define	DMA_CHx_CR_SSEL_Pos	8	/* ͨ���������� */
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

#define	DMA_CHx_CR_DIR_Pos	6	/* ͨ�����䷽�� */
#define	DMA_CHx_CR_DIR_Msk	(0x1U << DMA_CHx_CR_DIR_Pos)
#define	DMA_CHx_CR_DIR_PER_TO_RAM	(0x0U << DMA_CHx_CR_DIR_Pos)	/* �������ȡ����д��RAM */
#define	DMA_CHx_CR_DIR_RAM_TO_PER	(0x1U << DMA_CHx_CR_DIR_Pos)	/* ��RAM��ȡ����д������ */

#define	DMA_CHx_CR_BDW_Pos	4	/* ����������� */
#define	DMA_CHx_CR_BDW_Msk	(0x3U << DMA_CHx_CR_BDW_Pos)
#define	DMA_CHx_CR_BDW_8BIT	    (0x0U << DMA_CHx_CR_BDW_Pos)	/* �ֽڣ�8bit */
#define	DMA_CHx_CR_BDW_16BIT	(0x1U << DMA_CHx_CR_BDW_Pos)	/* ���֣�16bit */
#define	DMA_CHx_CR_BDW_32BIT	(0x2U << DMA_CHx_CR_BDW_Pos)	/* �֣�32bit */

#define	DMA_CHx_CR_CIRC_Pos	3	/* ѭ������ģʽ */
#define	DMA_CHx_CR_CIRC_Msk	(0x1U << DMA_CHx_CR_CIRC_Pos)
#define	DMA_CHx_CR_CIRC_DISABLE	(0x0U << DMA_CHx_CR_CIRC_Pos)	/* �ر� */
#define	DMA_CHx_CR_CIRC_ENABLE	(0x1U << DMA_CHx_CR_CIRC_Pos)	/* ʹ�� */

#define	DMA_CHx_CR_FTIE_Pos	2	/* ��������ж� */
#define	DMA_CHx_CR_FTIE_Msk	(0x1U << DMA_CHx_CR_FTIE_Pos)
	/* �ر� */
	/* ʹ�� */

#define	DMA_CHx_CR_HTIE_Pos	1	/* ��̴����ж� */
#define	DMA_CHx_CR_HTIE_Msk	(0x1U << DMA_CHx_CR_HTIE_Pos)
	/* �ر� */
	/* ʹ�� */

#define	DMA_CHx_CR_EN_Pos	0	/* ͨ������ */
#define	DMA_CHx_CR_EN_Msk	(0x1U << DMA_CHx_CR_EN_Pos)
	/* �ر� */
	/* ʹ�� */

#define	DMA_CHx_MAD_MEMAD_Pos	0	/* �洢��ָ���ַ */
#define	DMA_CHx_MAD_MEMAD_Msk	(0xffffffffU << DMA_CHx_MAD_MEMAD_Pos)

#define	DMA_CH7_CR_TSIZE_Pos	16	/* �������ݳ��� */
#define	DMA_CH7_CR_TSIZE_Msk	(0xfffU << DMA_CH7_CR_TSIZE_Pos)

#define	DMA_CH7_CR_PRI_Pos	12	/* ���ȼ����� */
#define	DMA_CH7_CR_PRI_Msk	(0x3U << DMA_CH7_CR_PRI_Pos)
#define	DMA_CH7_CR_PRI_LOW	(0x0U << DMA_CH7_CR_PRI_Pos)	/* �� */
#define	DMA_CH7_CR_PRI_MEDIUM	(0x1U << DMA_CH7_CR_PRI_Pos)	/* �� */
#define	DMA_CH7_CR_PRI_HIGH	(0x2U << DMA_CH7_CR_PRI_Pos)	/* �� */
#define	DMA_CH7_CR_PRI_VERYHIGH	(0x3U << DMA_CH7_CR_PRI_Pos)	/* �ǳ��� */

//BIT10	CH7DIR	Channel7���䷽��
//1��Flash->RAM����
//0��RAM->Flash����
//BIT9	CH7RI	Channel7 RAM��ַ�������ã�����Flash->RAM��������Ч
//1��RAM��ַ����
//0��RAM��ַ�ݼ�
//BIT8	CH7FI	Channel7 Flash��ַ�������ã�����Flash->RAM��������Ч
//1��Flash��ַ����
//0��Flash��ַ�ݼ�
#define	DMA_CH7_CR_SSEL_Pos	8	/* Channel7����ͨ��ѡ�� */
#define	DMA_CH7_CR_SSEL_Msk	(0x7U << DMA_CH7_CR_SSEL_Pos)
#define	DMA_CH7_CR_SSEL_RFRMFM	(0x0U << DMA_CH7_CR_SSEL_Pos)	/* Channel7 RAM->FLASH���� RAM��ַ�ݼ� FLASH��ַ�ݼ� */
#define	DMA_CH7_CR_SSEL_RFRMFP	(0x1U << DMA_CH7_CR_SSEL_Pos)	/* Channel7 RAM->FLASH���� RAM��ַ�ݼ� FLASH��ַ���� */
#define	DMA_CH7_CR_SSEL_RFRPFM	(0x2U << DMA_CH7_CR_SSEL_Pos)	/* Channel7 RAM->FLASH���� RAM��ַ���� FLASH��ַ�ݼ� */
#define	DMA_CH7_CR_SSEL_RFRPFP	(0x3U << DMA_CH7_CR_SSEL_Pos)	/* Channel7 RAM->FLASH���� RAM��ַ���� FLASH��ַ���� */
#define	DMA_CH7_CR_SSEL_FRRMFM	(0x4U << DMA_CH7_CR_SSEL_Pos)	/* Channel7 FLASH->RAM���� RAM��ַ�ݼ� FLASH��ַ�ݼ� */
#define	DMA_CH7_CR_SSEL_FRRMFP	(0x5U << DMA_CH7_CR_SSEL_Pos)	/* Channel7 FLASH->RAM���� RAM��ַ�ݼ� FLASH��ַ���� */
#define	DMA_CH7_CR_SSEL_FRRPFM	(0x6U << DMA_CH7_CR_SSEL_Pos)	/* Channel7 FLASH->RAM���� RAM��ַ���� FLASH��ַ�ݼ� */
#define	DMA_CH7_CR_SSEL_FRRPFP	(0x7U << DMA_CH7_CR_SSEL_Pos)	/* Channel7 FLASH->RAM���� RAM��ַ���� FLASH��ַ���� */

//#define	DMA_CH7_CR_DIR_Pos	10	/* ���䷽�� */
//#define	DMA_CH7_CR_DIR_Msk	(0x1U << DMA_CH7_CR_DIR_Pos)
//#define	DMA_CH7_CR_DIR_RAM_TO_FLASH	(0x0U << DMA_CH7_CR_DIR_Pos)	/* Ram��Flash */
//#define	DMA_CH7_CR_DIR_FLASH_TO_RAM	(0x1U << DMA_CH7_CR_DIR_Pos)	/* Flash��Ram */

//#define	DMA_CH7_CR_RI_Pos	9	/* RAM��ַ�������� */
//#define	DMA_CH7_CR_RI_Msk	(0x1U << DMA_CH7_CR_RI_Pos)
//#define	DMA_CH7_CR_RI_DEC	(0x0U << DMA_CH7_CR_RI_Pos)	/* �ݼ� */
//#define	DMA_CH7_CR_RI_INC	(0x1U << DMA_CH7_CR_RI_Pos)	/* ���� */

//#define	DMA_CH7_CR_FI_Pos	8	/* Flash��ַ�������� */
//#define	DMA_CH7_CR_FI_Msk	(0x1U << DMA_CH7_CR_FI_Pos)
//#define	DMA_CH7_CR_FI_DEC	(0x0U << DMA_CH7_CR_FI_Pos)	/* �ݼ� */
//#define	DMA_CH7_CR_FI_INC	(0x1U << DMA_CH7_CR_FI_Pos)	/* ���� */

#define	DMAx_CH7_FLSAD_FLSAD_Pos	0	/* ͨ��7 Flashָ���ַ */
#define	DMAx_CH7_FLSAD_FLSAD_Msk	(0x7fffU << DMAx_CH7_FLSAD_FLSAD_Pos)

#define	DMAx_CH7_RAMAD_RAMAD_Pos	0	/* ͨ��7 RAM��ָ���ַ */
#define	DMAx_CH7_RAMAD_RAMAD_Msk	(0xfffU << DMAx_CH7_RAMAD_RAMAD_Pos)

#define	DMA_CH7_CR_FTIE_Pos	2	/* ��������ж� */
#define	DMA_CH7_CR_FTIE_Msk	(0x1U << DMA_CH7_CR_FTIE_Pos)
	/* �ر� */
	/* ʹ�� */

#define	DMA_CH7_CR_HTIE_Pos	1	/* ��̴����ж� */
#define	DMA_CH7_CR_HTIE_Msk	(0x1U << DMA_CH7_CR_HTIE_Pos)
	/* �ر� */
	/* ʹ�� */

#define	DMA_CH7_CR_EN_Pos	0	/* ͨ������ */
#define	DMA_CH7_CR_EN_Msk	(0x1U << DMA_CH7_CR_EN_Pos)
	/* �ر� */
	/* ʹ�� */
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void DMA_Deinit(void);

/* DMAȫ��ʹ�� ��غ��� */
extern void DMA_GCR_DMAEN_Setable(FunState NewState);
extern FunState DMA_GCR_DMAEN_Getable(void);

/* DMAͨ���������ݳ��ȿ��� ��غ��� */
extern void DMA_CHx_CR_TSIZE_Set(DMA_CH_Type CHx, uint32_t SetValue);
extern uint32_t DMA_CHx_CR_TSIZE_Get(DMA_CH_Type CHx);

/* ͨ�����ȼ� ��غ��� */
extern void DMA_CHx_CR_PRI_Set(DMA_CH_Type CHx, uint32_t SetValue);
extern uint32_t DMA_CHx_CR_PRI_Get(DMA_CH_Type CHx);

/* RAM��ַ������� ��غ��� */
extern void DMA_CHx_CR_INC_Set(DMA_CH_Type CHx, uint32_t SetValue);
extern uint32_t DMA_CHx_CR_INC_Get(DMA_CH_Type CHx);

/* ͨ���������� ��غ��� */
extern void DMA_CHx_CR_SSEL_Set(DMA_CH_Type CHx, uint32_t SetValue);
extern uint32_t DMA_CHx_CR_SSEL_Get(DMA_CH_Type CHx);

/* ͨ�����䷽�� ��غ��� */
extern void DMA_CHx_CR_DIR_Set(DMA_CH_Type CHx, uint32_t SetValue);
extern uint32_t DMA_CHx_CR_DIR_Get(DMA_CH_Type CHx);

/* ����������� ��غ��� */
extern void DMA_CHx_CR_BDW_Set(DMA_CH_Type CHx, uint32_t SetValue);
extern uint32_t DMA_CHx_CR_BDW_Get(DMA_CH_Type CHx);

/* ѭ������ģʽ ��غ��� */
extern void DMA_CHx_CR_CIRC_Setable(DMA_CH_Type CHx, FunState NewState);
extern FunState DMA_CHx_CR_CIRC_Getable(DMA_CH_Type CHx);

/* ��������ж� ��غ��� */
extern void DMA_CHx_CR_FTIE_Setable(DMA_CH_Type CHx, FunState NewState);
extern FunState DMA_CHx_CR_FTIE_Getable(DMA_CH_Type CHx);

/* ��̴����ж� ��غ��� */
extern void DMA_CHx_CR_HTIE_Setable(DMA_CH_Type CHx, FunState NewState);
extern FunState DMA_CHx_CR_HTIE_Getable(DMA_CH_Type CHx);

/* ͨ������ ��غ��� */
extern void DMA_CHx_CR_EN_Setable(DMA_CH_Type CHx, FunState NewState);
extern FunState DMA_CHx_CR_EN_Getable(DMA_CH_Type CHx);

/* �������ݳ��� ��غ��� */
extern void DMA_CH7_CR_TSIZE_Set(uint32_t SetValue);
extern uint32_t DMA_CH7_CR_TSIZE_Get(void);

/* ���ȼ����� ��غ��� */
extern void DMA_CH7_CR_PRI_Set(uint32_t SetValue);
extern uint32_t DMA_CH7_CR_PRI_Get(void);

/* ͨ���������� ��غ��� */
void DMA_CH7_CR_SSEL_Set(uint32_t SetValue);
uint32_t DMA_CH7_CR_SSEL_Get(void);

/* ��������ж� ��غ��� */
extern void DMA_CH7_CR_FTIE_Setable(FunState NewState);
extern FunState DMA_CH7_CR_FTIE_Getable(void);

/* ��̴����ж� ��غ��� */
extern void DMA_CH7_CR_HTIE_Setable(FunState NewState);
extern FunState DMA_CH7_CR_HTIE_Getable(void);

/* ͨ������ ��غ��� */
extern void DMA_CH7_CR_EN_Setable(FunState NewState);
extern FunState DMA_CH7_CR_EN_Getable(void);

/* �洢��ָ���ַ ��غ��� */
extern void DMA_CHx_MAD_MEMAD_Write(DMA_CH_Type CHx, uint32_t SetValue);

/* ͨ��7 FLASHָ���ַ ��غ��� */
extern void DMA_CH7_FLSAD_Write(uint32_t SetValue);

/* ͨ��7 RAMָ���ַ ��غ��� */
extern void DMA_CH7_RAMAD_Write(uint32_t SetValue);

/* ��������ж� ��غ��� */
extern void DMA_ISR_CHFT_Clr(DMA_CH_Type CHx);
extern FlagStatus DMA_ISR_CHFT_Chk(DMA_CH_Type CHx);

/* �������ж� ��غ��� */
extern void DMA_ISR_CHHT_Clr(DMA_CH_Type CHx);
extern FlagStatus DMA_ISR_CHHT_Chk(DMA_CH_Type CHx);

//Announce_End

extern void DMA_Init(DMA_InitTypeDef* para);

#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_DMA_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
