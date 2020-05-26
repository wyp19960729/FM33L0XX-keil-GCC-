/**
  ******************************************************************************
  * @file    fm33l0xx_gpio.h
  * @author  FM33L0xx Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file contains all the functions prototypes for the GPIO firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33L0XX_GPIO_H
#define __FM33L0XX_GPIO_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33L0XX.h" 

//------------------------------------------------------------------------------
typedef enum
{ 
    GPIO_FCR_IN		= 0x00, /*!< GPIO 输入 */
    GPIO_FCR_OUT	= 0x01, /*!< GPIO 输出 */
    GPIO_FCR_DIG	= 0x02, /*!< GPIO 数字特殊功能 */
    GPIO_FCR_ANA	= 0x03  /*!< GPIO 模拟功能 */
}GPIO_FCR_TypeDef;

/** 
  * @brief  GPIO Output type enumeration 
  */  
typedef enum
{ 
    GPIO_OD_Dis = 0x00,
    GPIO_OD_En = 0x01
}GPIO_ODEN_TypeDef;

/** 
  * @brief  GPIO Configuration PullUp enumeration 
  */ 
typedef enum
{ 
    GPIO_PU_Dis = 0x00,
    GPIO_PU_En  = 0x01 
}GPIO_PUEN_TypeDef;

/** 
  * @brief  GPIO Configuration InEn enumeration 
  */ 
typedef enum
{ 
    GPIO_IN_Dis		= 0x00,
    GPIO_IN_En		= 0x01 
}GPIO_INEN_TypeDef;

/** 
  * @brief  GPIO Configuration HighDrive enumeration 
  */ 
typedef enum
{ 
    GPIO_HD_Dis		= 0x00,
    GPIO_HD_En		= 0x01 
}GPIO_HD_TypeDef;

/** 
  * @brief  GPIO Configuration AnalogChannel enumeration 
  */ 
typedef enum
{ 
    GPIO_ANEN_Dis		= 0x00,
    GPIO_ANEN_En		= 0x01 
}GPIO_ANEN_TypeDef;

/** 
  * @brief   GPIO Init structure definition  
  */ 
typedef struct
{
    uint32_t					Pin;     	//PIN选择
    GPIO_FCR_TypeDef			PxFCR;		//IO功能选择
    GPIO_ODEN_TypeDef			PxODEN;		//开漏输出使能控制
    GPIO_PUEN_TypeDef			PxPUEN;		//上拉电阻使能控制
    GPIO_INEN_TypeDef			PxINEN;		//输入使能控制
}GPIO_InitTypeDef;

/** 
  * @brief  GPIO Bit SET and Bit RESET enumeration 
  */ 
typedef enum
{ 
    Bit_RESET = 0,
    Bit_SET
}BitAction;
#define IS_GPIO_BIT_ACTION(ACTION) (((ACTION) == Bit_RESET) || ((ACTION) == Bit_SET))

typedef enum
{ 
    EXTI_RISING,
    EXTI_FALLING,
    EXTI_BOTH,
    EXTI_DISABLE,
	
}GPIOExtiEdge;
#define IS_GPIO_INTERRUPT_TRIGER_EDGE(EDGE) (((EDGE) == GPIO_RISING) || ((EDGE) == GPIO_FALLING)|| ((EDGE) == GPIO_BOTH)|| ((EDGE) == GPIO_DISABLE))


/* Exported constants --------------------------------------------------------*/

/** @defgroup GPIO_Exported_Constants
  * @{
  */
	 
/**
* @}
*/ 

/** @defgroup GPIO_Exported_Types
  * @{
  */

#define IS_GPIO_ALL_PERIPH(PERIPH) (((PERIPH) == GPIOA) || \
                                    ((PERIPH) == GPIOB) || \
                                    ((PERIPH) == GPIOC) || \
                                    ((PERIPH) == GPIOD))
                                     
/** @defgroup GPIO_pins_define 
  * @{
  */ 
#define GPIO_Pin_0                 ((uint32_t)0x00000001)  /* Pin 0 selected */
#define GPIO_Pin_1                 ((uint32_t)0x00000002)  /* Pin 1 selected */
#define GPIO_Pin_2                 ((uint32_t)0x00000004)  /* Pin 2 selected */
#define GPIO_Pin_3                 ((uint32_t)0x00000008)  /* Pin 3 selected */
#define GPIO_Pin_4                 ((uint32_t)0x00000010)  /* Pin 4 selected */
#define GPIO_Pin_5                 ((uint32_t)0x00000020)  /* Pin 5 selected */
#define GPIO_Pin_6                 ((uint32_t)0x00000040)  /* Pin 6 selected */
#define GPIO_Pin_7                 ((uint32_t)0x00000080)  /* Pin 7 selected */
#define GPIO_Pin_8                 ((uint32_t)0x00000100)  /* Pin 8 selected */
#define GPIO_Pin_9                 ((uint32_t)0x00000200)  /* Pin 9 selected */
#define GPIO_Pin_10                ((uint32_t)0x00000400)  /* Pin 10 selected */
#define GPIO_Pin_11                ((uint32_t)0x00000800)  /* Pin 11 selected */
#define GPIO_Pin_12                ((uint32_t)0x00001000)  /* Pin 12 selected */
#define GPIO_Pin_13                ((uint32_t)0x00002000)  /* Pin 13 selected */
#define GPIO_Pin_14                ((uint32_t)0x00004000)  /* Pin 14 selected */
#define GPIO_Pin_15                ((uint32_t)0x00008000)  /* Pin 15 selected */
#define GPIO_Pin_All               ((uint16_t)0xFFFF)  /*!< All pins selected */

#define IS_GPIO_PIN(PIN) ((((PIN) & (uint16_t)0x00) == 0x00) && ((PIN) != (uint16_t)0x00))
#define IS_GET_GPIO_PIN(PIN) (((PIN) == GPIO_Pin_0) || \
                              ((PIN) == GPIO_Pin_1) || \
                              ((PIN) == GPIO_Pin_2) || \
                              ((PIN) == GPIO_Pin_3) || \
                              ((PIN) == GPIO_Pin_4) || \
                              ((PIN) == GPIO_Pin_5) || \
                              ((PIN) == GPIO_Pin_6) || \
                              ((PIN) == GPIO_Pin_7) || \
                              ((PIN) == GPIO_Pin_8) || \
                              ((PIN) == GPIO_Pin_9) || \
                              ((PIN) == GPIO_Pin_10) || \
                              ((PIN) == GPIO_Pin_11) || \
                              ((PIN) == GPIO_Pin_12) || \
                              ((PIN) == GPIO_Pin_13) || \
                              ((PIN) == GPIO_Pin_14) || \
                              ((PIN) == GPIO_Pin_15))



/* Exported macro ------------------------------------------------------------*/


/* WKUP引脚使能PIN宏定义 */
#define		PINWKEN_PD6		BIT7
#define		PINWKEN_PD11	BIT6
#define		PINWKEN_PC10	BIT5
#define		PINWKEN_PC6 	BIT4
#define		PINWKEN_PB12	BIT3
#define		PINWKEN_PB2		BIT2
#define		PINWKEN_PA10	BIT1
#define		PINWKEN_PA15	BIT0

// 1. PortX输入使能寄存器
#define	GPIOx_INEN_INEN_Pos	0	//R/W: rw	ResetValue: 0x0
#define	GPIOx_INEN_INEN_Msk	(0xffffU << GPIOx_INEN_INEN_Pos)
								//GPIO输入使能控制
								//0：关闭输入使能
								//1：打开输入使能

// 2. PortX上拉使能寄存器
#define	GPIOx_PUEN_PUEN_Pos	0	//R/W: rw	ResetValue: 0x0
#define	GPIOx_PUEN_PUEN_Msk	(0xffffU << GPIOx_PUEN_PUEN_Pos)								
								//GPIO上拉控制
								//0：关闭上拉
								//1：使能上拉	

// 3. PortX开漏使能寄存器								
#define	GPIOx_ODEN_ODEN_Pos	0	//R/W: rw	ResetValue: 0x0
#define	GPIOx_ODEN_ODEN_Msk	(0xffffU << GPIOx_ODEN_ODEN_Pos)
								//GPIO开漏输出使能
								//0：关闭开漏输出
								//1：使能开漏输出

// 4. PortX功能选择寄存器								
#define	GPIOx_FCR_Px15FCR_Pos	30	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px15FCR_Msk	(0x03U << GPIOx_FCR_Px15FCR_Pos)
								//Px[15]引脚功能选择
								//00：GPIO输入
								//01：GPIO输出
								//10：Digital function
								//11：Analog function								
#define	GPIOx_FCR_Px14FCR_Pos	28	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px14FCR_Msk	(0x03U << GPIOx_FCR_Px14FCR_Pos)
								//Px[14]引脚功能选择
								//00：GPIO输入
								//01：GPIO输出
								//10：Digital function
								//11：Analog function
#define	GPIOx_FCR_Px13FCR_Pos	26	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px13FCR_Msk	(0x03U << GPIOx_FCR_Px13FCR_Pos)
								//Px[13]引脚功能选择
								//00：GPIO输入
								//01：GPIO输出
								//10：Digital function
								//11：Analog function
#define	GPIOx_FCR_Px12FCR_Pos	24	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px12FCR_Msk	(0x03U << GPIOx_FCR_Px12FCR_Pos)
								//Px[12]引脚功能选择
								//00：GPIO输入
								//01：GPIO输出
								//10：Digital function
								//11：Analog function
#define	GPIOx_FCR_Px11FCR_Pos	22	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px11FCR_Msk	(0x03U << GPIOx_FCR_Px11FCR_Pos)
								//Px[11]引脚功能选择
								//00：GPIO输入
								//01：GPIO输出
								//10：Digital function
								//11：Analog function
#define	GPIOx_FCR_Px10FCR_Pos	20	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px10FCR_Msk	(0x03U << GPIOx_FCR_Px10FCR_Pos)
								//Px[10]引脚功能选择
								//00：GPIO输入
								//01：GPIO输出
								//10：Digital function
								//10：Analog function
#define	GPIOx_FCR_Px9FCR_Pos	18	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px9FCR_Msk	(0x03U << GPIOx_FCR_Px9FCR_Pos)
								//Px[9]引脚功能选择
								//00：GPIO输入
								//01：GPIO输出
								//10：Digital function
								//11：Analog function	
#define	GPIOx_FCR_Px8FCR_Pos	16	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px8FCR_Msk	(0x03U << GPIOx_FCR_Px8FCR_Pos)
								//Px[8]引脚功能选择
								//00：GPIO输入
								//01：GPIO输出
								//10：Digital function
								//11：Analog function
#define	GPIOx_FCR_Px7FCR_Pos	14	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px7FCR_Msk	(0x03U << GPIOx_FCR_Px7FCR_Pos)
								//Px[7]引脚功能选择
								//00：GPIO输入
								//01：GPIO输出
								//10：Digital function
								//11：Analog function
#define	GPIOx_FCR_Px6FCR_Pos	12	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px6FCR_Msk	(0x03U << GPIOx_FCR_Px6FCR_Pos)
								//Px[6]引脚功能选择
								//00：GPIO输入
								//01：GPIO输出
								//10：Digital function
								//11：Analog function
#define	GPIOx_FCR_Px5FCR_Pos	10	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px5FCR_Msk	(0x03U << GPIOx_FCR_Px5FCR_Pos)
								//Px[5]引脚功能选择
								//00：GPIO输入
								//01：GPIO输出
								//10：Digital function
								//11：Analog function
#define	GPIOx_FCR_Px4FCR_Pos	8	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px4FCR_Msk	(0x03U << GPIOx_FCR_Px4FCR_Pos)
								//Px[4]引脚功能选择
								//00：GPIO输入
								//01：GPIO输出
								//10：Digital function
								//11：Analog function
#define	GPIOx_FCR_Px3FCR_Pos	6	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px3FCR_Msk	(0x03U << GPIOx_FCR_Px3FCR_Pos)
								//Px[3]引脚功能选择
								//00：GPIO输入
								//01：GPIO输出
								//10：Digital function
								//11：Analog function
#define	GPIOx_FCR_Px2FCR_Pos	4	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px2FCR_Msk	(0x03U << GPIOx_FCR_Px2FCR_Pos)
								//Px[2]引脚功能选择
								//00：GPIO输入
								//01：GPIO输出
								//10：Digital function
								//11：Analog function
#define	GPIOx_FCR_Px1FCR_Pos	2	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px1FCR_Msk	(0x03U << GPIOx_FCR_Px1FCR_Pos)
								//Px[1]引脚功能选择
								//00：GPIO输入
								//01：GPIO输出
								//10：Digital function
								//11：Analog function
#define	GPIOx_FCR_Px0FCR_Pos	0	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px0FCR_Msk	(0x03U << GPIOx_FCR_Px0FCR_Pos)
								//Px[0]引脚功能选择
								//00：GPIO输入
								//01：GPIO输出
								//10：Digital function
								//11：Analog function	

// 5. PortX输出数据寄存器																						
#define	GPIOx_DO_DO_Pos	0	//R/W: rw	ResetValue: 0x0
#define	GPIOx_DO_DO_Msk	(0xffffU << GPIOx_DO_DO_Pos)
								//GPIO output data register

// 6. PortX输出数据置位寄存器								
#define	GPIOx_DSET_DSET_Pos	0	//R/W: rw	ResetValue: 0x0
#define	GPIOx_DSET_DSET_Msk	(0xffffU << GPIOx_DSET_DSET_Pos)
								//GPIO output data set register
								//举例：向PADSET写0x0000_8000，则PADOR[15]置位，其余位保持不变。
								//PASET/PBSET为16位；PCSET/PDSET为13位

// 7. PortX输出数据复位寄存器								
#define	GPIOx_DRST_DRESET_Pos	0	//R/W: rw	ResetValue: 0x0
#define	GPIOx_DRST_DRESET_Msk	(0xffffU << GPIOx_DRST_DRESET_Pos)
								//GPIO output data reset register
								//举例：向PADRST写0x0000_8000，则PADOR[15]清零，其余位保持不变
								//PASET/PBSET为16位；PCSET/PDSET为13位

// 8. PortX输入数据寄存器																																															
#define	GPIOx_DIN_DIN_Pos	0	//R/W: rw	ResetValue: 0x0
#define	GPIOx_DIN_DIN_Msk	(0xffffU << GPIOx_DIN_DIN_Pos)
								//Portx input data register
								//此寄存器仅占用地址空间，无物理实现。
								//软件读此寄存器直接返回引脚输入信号，芯片并不对引脚输入进行锁存

// 9. PortX额外数字功能寄存器								
#define	GPIOx_DFS_DFS_Pos	0	//R/W: rw	ResetValue: 0x0
#define	GPIOx_DFS_DFS_Msk	(0xffffU << GPIOx_DFS_DFS_Pos)
								//Portx Digital Function Select
								//对于具有多个数字外设功能的引脚，通过PxDFS寄存器可以选择使用哪个外设功能。
								//注意，对于不同的IO分组，有效的寄存器位置是不一样的

// 10. PortX强驱动使能寄存器								
#define	GPIOx_HD_HD_Pos	0	//R/W: rw	ResetValue: 0x0
#define	GPIOx_HD_HD_Msk	(0xffffU << GPIOx_HD_HD_Pos)
								//PortX High Drive Enable
								//1：使能IO强驱动
								//0：关闭IO强驱动
								//注：支持强驱动的IO有PA11/12、PD0/1/11；有效的物理寄存器有PAHD[11], PAHD[12], PDHD[0], PDHD[1], PDHD[11]；其余寄存器无意义。								

// 11. PortX模拟开关使能寄存器								
#define	GPIOx_ANEN_ANEN_Pos	0	//R/W: rw	ResetValue: 0x0
#define	GPIOx_ANEN_ANEN_Msk	(0xffffU << GPIOx_ANEN_ANEN_Pos)
								//PortX 模拟开关使能
								//1：使能IO模拟开关
								//0：关闭IO模拟开关
								//注：支持模拟开关的IO有
								//PA6/PA7/PA13/PA14/PA15
								//PB0/PB1/PB13/PB14/PB15
								//PC0/PC1/PC6/PC7/PC8/PC9/PC10
								//PD0/PD1/PD2/PD11/PD12
								//对应以上IO的PxANEN寄存器有效；其余寄存器无意义。

// 12. EXTI输入选择寄存器								
#define	GPIO_EXTI_SEL_DSEL_Pos			24	//R/W: rw	ResetValue: 0x0
#define	GPIO_EXTI_SEL_DSEL_Msk			0x3FU << GPIO_EXTI_SEL_DSEL_Pos
								//PortD EXTI中断输入选择
								//EXTI_DSEL[5:4] 
								//00：PD8
								//01：PD9
								//10：PD10
								//11：PD11
								//EXTI_DSEL[3:2] 
								//00：PD4
								//01：PD5
								//10：PD6
								//11：PD7
								//EXTI_DSEL[1:0] 
								//00：PD0
								//01：PD1
								//10：PD2
								//11：PD3
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_SEL_CSEL_Pos			16	//R/W: rw	ResetValue: 0x0
#define	GPIO_EXTI_SEL_CSEL_Msk			0x3FU << GPIO_EXTI_SEL_CSEL_Pos
								//PortC EXTI中断输入选择
								//EXTI_CSEL[5:4] 
								//00：PC8
								//01：PC9
								//10：PC10
								//11：PC11
								//EXTI_CSEL[3:2] 
								//00：PC4
								//01：PC5
								//10：PC6
								//11：PC7
								//EXTI_CSEL[1:0]  
								//00：PC0
								//01：PC1
								//10：PC2
								//11：PC3
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_SEL_BSEL_Pos			8	//R/W: rw	ResetValue: 0x0
#define	GPIO_EXTI_SEL_BSEL_Msk			0xFFU << GPIO_EXTI_SEL_BSEL_Pos
								//PortB EXTI中断输入选择
								//EXTI_BSEL[7:6] 
								//00：PB12
								//01：PB13
								//10：PB14
								//11：PB15
								//EXTI_BSEL[5:4] 
								//00：PB8
								//01：PB9
								//10：PB10
								//11：PB11
								//EXTI_BSEL[3:2] 
								//00：PB4
								//01：PB5
								//10：PB6
								//11：PB7
								//EXTI_BSEL[1:0]  
								//00：PB0
								//01：PB1
								//10：PB2
								//11：PB3
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_SEL_ASEL_Pos			0	//R/W: rw	ResetValue: 0x0
#define	GPIO_EXTI_SEL_ASEL_Msk			0xFFU << GPIO_EXTI_SEL_ASEL_Pos
								//PortA EXTI中断输入选择
								//EXTI_ASEL[7:6] 
								//00：PA12
								//01：PA13
								//10：PA14
								//11：PA15
								//EXTI_ASEL[5:4] 
								//00：PA8
								//01：PA9
								//10：PA10
								//11：PA11
								//EXTI_ASEL[3:2] 
								//00：PA4
								//01：PA5
								//10：PA6
								//11：PA7
								//EXTI_ASEL[1:0]  
								//00：PA0
								//01：PA1
								//10：PA2
								//11：PA3
								//

// 13. EXTI边沿选择和使能寄存器								
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_EDS_EXTI15_EDS_Pos		30	//R/W: rw	ResetValue: 0x3
#define	GPIO_EXTI_EDS_EXTI15_EDS_Msk		0x3U << GPIO_EXTI_EDS_EXTI15_EDS_Pos
								//EXTI[15] 边缘触发选择
								//00: rising
								//01: falling
								//10: both
								//11: disable
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_EDS_EXTI14_EDS_Pos		28	//R/W: rw	ResetValue: 0x3
#define	GPIO_EXTI_EDS_EXTI14_EDS_Msk		0x3U << GPIO_EXTI_EDS_EXTI14_EDS_Pos
								//EXTI[14] 边缘触发选择
								//00: rising
								//01: falling
								//10: both
								//11: disable
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_EDS_EXTI13_EDS_Pos		26	//R/W: rw	ResetValue: 0x3
#define	GPIO_EXTI_EDS_EXTI13_EDS_Msk		0x3U << GPIO_EXTI_EDS_EXTI13_EDS_Pos
								//EXTI[13] 边缘触发选择
								//00: rising
								//01: falling
								//10: both
								//11: disable
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_EDS_EXTI12_EDS_Pos		24	//R/W: rw	ResetValue: 0x3
#define	GPIO_EXTI_EDS_EXTI12_EDS_Msk		0x3U << GPIO_EXTI_EDS_EXTI12_EDS_Pos
								//EXTI[12] 边缘触发选择
								//00: rising
								//01: falling
								//10: both
								//11: disable
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_EDS_EXTI11_EDS_Pos		22	//R/W: rw	ResetValue: 0x3
#define	GPIO_EXTI_EDS_EXTI11_EDS_Msk		0x3U << GPIO_EXTI_EDS_EXTI11_EDS_Pos
								//EXTI[11] 边缘触发选择
								//00: rising
								//01: falling
								//10: both
								//11: disable
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_EDS_EXTI10_EDS_Pos		20	//R/W: rw	ResetValue: 0x3
#define	GPIO_EXTI_EDS_EXTI10_EDS_Msk		0x3U << GPIO_EXTI_EDS_EXTI10_EDS_Pos
								//EXTI[10] 边缘触发选择
								//00: rising
								//01: falling
								//10: both
								//11: disable
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_EDS_EXTI9_EDS_Pos			18	//R/W: rw	ResetValue: 0x3
#define	GPIO_EXTI_EDS_EXTI9_EDS_Msk			0x3U << GPIO_EXTI_EDS_EXTI9_EDS_Pos
								//EXTI[9] 边缘触发选择
								//00: rising
								//01: falling
								//10: both
								//11: disable
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_EDS_EXTI8_EDS_Pos			16	//R/W: rw	ResetValue: 0x3
#define	GPIO_EXTI_EDS_EXTI8_EDS_Msk			0x3U << GPIO_EXTI_EDS_EXTI8_EDS_Pos
								//EXTI[8] 边缘触发选择
								//00: rising
								//01: falling
								//10: both
								//11: disable
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_EDS_EXTI7_EDS_Pos			14	//R/W: rw	ResetValue: 0x3
#define	GPIO_EXTI_EDS_EXTI7_EDS_Msk			0x3U << GPIO_EXTI_EDS_EXTI7_EDS_Pos
								//EXTI[7] 边缘触发选择
								//00: rising
								//01: falling
								//10: both
								//11: disable
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_EDS_EXTI6_EDS_Pos			12	//R/W: rw	ResetValue: 0x3
#define	GPIO_EXTI_EDS_EXTI6_EDS_Msk			0x3U << GPIO_EXTI_EDS_EXTI6_EDS_Pos
								//EXTI[6] 边缘触发选择
								//00: rising
								//01: falling
								//10: both
								//11: disable
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_EDS_EXTI5_EDS_Pos			10	//R/W: rw	ResetValue: 0x3
#define	GPIO_EXTI_EDS_EXTI5_EDS_Msk			0x3U << GPIO_EXTI_EDS_EXTI5_EDS_Pos
								//EXTI[5] 边缘触发选择
								//00: rising
								//01: falling
								//10: both
								//11: disable
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_EDS_EXTI4_EDS_Pos			8	//R/W: rw	ResetValue: 0x3
#define	GPIO_EXTI_EDS_EXTI4_EDS_Msk			0x3U << GPIO_EXTI_EDS_EXTI4_EDS_Pos
								//EXTI[4] 边缘触发选择
								//00: rising
								//01: falling
								//10: both
								//11: disable
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_EDS_EXTI3_EDS_Pos			6	//R/W: rw	ResetValue: 0x3
#define	GPIO_EXTI_EDS_EXTI3_EDS_Msk			0x3U << GPIO_EXTI_EDS_EXTI3_EDS_Pos
								//EXTI[3] 边缘触发选择
								//00: rising
								//01: falling
								//10: both
								//11: disable
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_EDS_EXTI2_EDS_Pos			4	//R/W: rw	ResetValue: 0x3
#define	GPIO_EXTI_EDS_EXTI2_EDS_Msk			0x3U << GPIO_EXTI_EDS_EXTI2_EDS_Pos
								//EXTI[2] 边缘触发选择
								//00: rising
								//01: falling
								//10: both
								//11: disable
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_EDS_EXTI1_EDS_Pos			2	//R/W: rw	ResetValue: 0x3
#define	GPIO_EXTI_EDS_EXTI1_EDS_Msk			0x3U << GPIO_EXTI_EDS_EXTI1_EDS_Pos
								//EXTI[1] 边缘触发选择
								//00: rising
								//01: falling
								//10: both
								//11: disable
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_EDS_EXTI0_EDS_Pos			0	//R/W: rw	ResetValue: 0x3
#define	GPIO_EXTI_EDS_EXTI0_EDS_Msk			0x3U << GPIO_EXTI_EDS_EXTI0_EDS_Pos
								//EXTI[0] 边缘触发选择
								//00: rising
								//01: falling
								//10: both
								//11: disable
								//
								
// 14. EXTI数字滤波控制寄存器								
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_DF_DF_Pos			0	//** R/W: rw	ResetValue: 0x0
#define	GPIO_EXTI_DF_DF_Msk			0xFFFFU << GPIO_EXTI_DF_DF_Pos
								//EXTI输入数字滤波功能使能
								//0：关闭EXTI数字滤波
								//1：使能EXTI数字滤波
								//
								
// 15. EXTI中断标志寄存器							
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_ISR_IF_Pos			0	//** R/W: rw	ResetValue: 0x0
#define	GPIO_EXTI_ISR_IF_Msk			0xFFFFU << GPIO_EXTI_ISR_IF_Pos
								//外部引脚中断标志寄存器，共可以产生16个引脚中断
								//硬件置位，软件写1清零
								//
								
// 16. EXTI输入信号寄存器							
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_DI_DI_Pos			0	//** R/W: ro	ResetValue: 0x0
#define	GPIO_EXTI_DI_DI_Msk			0xFFFFU << GPIO_EXTI_DI_DI_Pos
								//EXTI输入信号只读寄存器，软件读取此寄存器可以观察EXTI的16个输入信号的当前状态
								//注：当使能了数字滤波后，软件可以从这个寄存器读取到某个IO输入信号滤波后的状态。
								//
								
// 17. FOUT配置寄存器								
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_FOUT_SEL_FOUT1SEL_Pos			4	//R/W: rw	ResetValue: 0x0
#define	GPIO_FOUT_SEL_FOUT1SEL_Msk			0xFU << GPIO_FOUT_SEL_FOUT1SEL_Pos
#define	GPIO_FOUT_SEL_FOUT1SEL_XTLF			(0x0U << GPIO_FOUT_SEL_FOUT1SEL_Pos)
#define	GPIO_FOUT_SEL_FOUT1SEL_RCLP			(0x1U << GPIO_FOUT_SEL_FOUT1SEL_Pos)
#define	GPIO_FOUT_SEL_FOUT1SEL_RCHF_64			(0x2U << GPIO_FOUT_SEL_FOUT1SEL_Pos)
#define	GPIO_FOUT_SEL_FOUT1SEL_LSCLK			(0x3U << GPIO_FOUT_SEL_FOUT1SEL_Pos)
#define	GPIO_FOUT_SEL_FOUT1SEL_AHBCLK_64			(0x4U << GPIO_FOUT_SEL_FOUT1SEL_Pos)
#define	GPIO_FOUT_SEL_FOUT1SEL_RTCTM			(0x5U << GPIO_FOUT_SEL_FOUT1SEL_Pos)
#define	GPIO_FOUT_SEL_FOUT1SEL_PLLO_64			(0x6U << GPIO_FOUT_SEL_FOUT1SEL_Pos)
#define	GPIO_FOUT_SEL_FOUT1SEL_RTCCLK_64			(0x7U << GPIO_FOUT_SEL_FOUT1SEL_Pos)
#define	GPIO_FOUT_SEL_FOUT1SEL_APBCLK_64			(0x8U << GPIO_FOUT_SEL_FOUT1SEL_Pos)
#define	GPIO_FOUT_SEL_FOUT1SEL_PLLO			(0x9U << GPIO_FOUT_SEL_FOUT1SEL_Pos)
#define	GPIO_FOUT_SEL_FOUT1SEL_RC4MPSC			(0xAU << GPIO_FOUT_SEL_FOUT1SEL_Pos)
#define	GPIO_FOUT_SEL_FOUT1SEL_RCHF			(0xBU << GPIO_FOUT_SEL_FOUT1SEL_Pos)
#define	GPIO_FOUT_SEL_FOUT1SEL_XTHF_64			(0xCU << GPIO_FOUT_SEL_FOUT1SEL_Pos)
#define	GPIO_FOUT_SEL_FOUT1SEL_ADCCLK_64			(0xDU << GPIO_FOUT_SEL_FOUT1SEL_Pos)
#define	GPIO_FOUT_SEL_FOUT1SEL_CLK8K			(0xEU << GPIO_FOUT_SEL_FOUT1SEL_Pos)
								//PB12输出选择
								//0000: XTLF
								//0001: RCLP
								//0010: RCHF/64
								//0011: LSCLK
								//0100: AHBCLK/64
								//0101: RTCTM
								//0110: PLLO/64
								//0111: RTCCLK64Hz
								//1000: APBCLK/64
								//1001: PLLO
								//1010: RC4MPSC
								//1011: RCHF
								//1100: XTHF/64
								//1101: ADCCLK/64
								//1110: CLK8K
								//1111: RFU
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_FOUT_SEL_FOUT0SEL_Pos			0	//R/W: rw	ResetValue: 0x0
#define	GPIO_FOUT_SEL_FOUT0SEL_Msk			0xFU << GPIO_FOUT_SEL_FOUT0SEL_Pos
#define	GPIO_FOUT_SEL_FOUT0SEL_XTLF			(0x0U << GPIO_FOUT_SEL_FOUT0SEL_Pos)
#define	GPIO_FOUT_SEL_FOUT0SEL_RCLP			(0x1U << GPIO_FOUT_SEL_FOUT0SEL_Pos)
#define	GPIO_FOUT_SEL_FOUT0SEL_RCHF_64			(0x2U << GPIO_FOUT_SEL_FOUT0SEL_Pos)
#define	GPIO_FOUT_SEL_FOUT0SEL_LSCLK			(0x3U << GPIO_FOUT_SEL_FOUT0SEL_Pos)
#define	GPIO_FOUT_SEL_FOUT0SEL_AHBCLK_64			(0x4U << GPIO_FOUT_SEL_FOUT0SEL_Pos)
#define	GPIO_FOUT_SEL_FOUT0SEL_RTCTM			(0x5U << GPIO_FOUT_SEL_FOUT0SEL_Pos)
#define	GPIO_FOUT_SEL_FOUT0SEL_PLLO_64			(0x6U << GPIO_FOUT_SEL_FOUT0SEL_Pos)
#define	GPIO_FOUT_SEL_FOUT0SEL_RTCCLK_64			(0x7U << GPIO_FOUT_SEL_FOUT0SEL_Pos)
#define	GPIO_FOUT_SEL_FOUT0SEL_APBCLK_64			(0x8U << GPIO_FOUT_SEL_FOUT0SEL_Pos)
#define	GPIO_FOUT_SEL_FOUT0SEL_PLLO			(0x9U << GPIO_FOUT_SEL_FOUT0SEL_Pos)
#define	GPIO_FOUT_SEL_FOUT0SEL_RC4MPSC			(0xAU << GPIO_FOUT_SEL_FOUT0SEL_Pos)
#define	GPIO_FOUT_SEL_FOUT0SEL_RCHF			(0xBU << GPIO_FOUT_SEL_FOUT0SEL_Pos)
#define	GPIO_FOUT_SEL_FOUT0SEL_XTHF_64			(0xCU << GPIO_FOUT_SEL_FOUT0SEL_Pos)
#define	GPIO_FOUT_SEL_FOUT0SEL_ADCCLK_64			(0xDU << GPIO_FOUT_SEL_FOUT0SEL_Pos)
#define	GPIO_FOUT_SEL_FOUT0SEL_CLK8K			(0xEU << GPIO_FOUT_SEL_FOUT0SEL_Pos)
								//PD11输出选择
								//0000: XTLF
								//0001: RCLP
								//0010: RCHF/64
								//0011: LSCLK
								//0100: AHBCLK/64
								//0101: RTCTM
								//0110: PLLO/64
								//0111: RTCCLK64Hz
								//1000: APBCLK/64
								//1001: PLLO
								//1010: RC4MPSC
								//1011: RCHF
								//1100: XTHF/64
								//1101: ADCCLK/64
								//1110: CLK8K
								//1111: RFU
								//
								
// 18. WKUP使能寄存器								
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_PINWKEN_WKISEL_Pos			31	//R/W: rw	ResetValue: 0x0
#define	GPIO_PINWKEN_WKISEL_Msk			0x1U << GPIO_PINWKEN_WKISEL_Pos
								//WKUPx中断入口选择
								//0：NMI中断（兼容FM385）
								//1：#39入口
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_PINWKEN_SEL_Pos			8	//R/W: rw	ResetValue: 0x0
#define	GPIO_PINWKEN_SEL_Msk			0xFFU << GPIO_PINWKEN_SEL_Pos
								//WKUP边沿选择
								//1：对应的WKUP引脚为上升沿唤醒
								//0：对应的WKUP引脚为下降沿唤醒
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_PINWKEN_EN_Pos			0	//R/W: rw	ResetValue: 0x0
#define	GPIO_PINWKEN_EN_Msk			0xFFU << GPIO_PINWKEN_EN_Pos
								//WKUP引脚使能信号
								//1：对应的WKUP引脚功能有效
								//0：对应的WKUP引脚功能无效
								//PINWKEN[x]控制WKUPx引脚的使能
								//
/* Exported functions --------------------------------------------------------*/ 
extern void GPIOx_Deinit(GPIO_Type* GPIOx);

/* PortX输出数据寄存器 相关函数 */
extern void GPIOx_DO_Write(GPIO_Type* GPIOx, uint32_t SetValue);
extern uint32_t GPIOx_DO_Read(GPIO_Type* GPIOx);

/* PortX输出数据置位寄存器 相关函数 */
extern void GPIOx_DSET_Write(GPIO_Type* GPIOx, uint32_t SetValue);

/* PortX输出数据复位寄存器 相关函数 */
extern void GPIOx_DRST_Write(GPIO_Type* GPIOx, uint32_t SetValue);

/* PortX输入数据寄存器 相关函数 */
extern uint32_t GPIOx_DIN_Read(GPIO_Type* GPIOx);

/* PortX额外数字功能寄存器 相关函数 */
extern void GPIOx_DFS_Setable(GPIO_Type* GPIOx, uint32_t GPIO_Pin, FunState NewState);
extern FunState GPIOx_DFS_Getable(GPIO_Type* GPIOx, uint32_t GPIO_Pin);

/* PortX强驱动使能寄存器 相关函数 */
extern void GPIOx_HD_Setable(GPIO_Type* GPIOx, uint32_t GPIO_Pin, FunState NewState);
extern FunState GPIOx_HD_Getable(GPIO_Type* GPIOx, uint32_t GPIO_Pin);

/* PortX模拟开关使能寄存器 相关函数 */
extern void GPIOx_ANEN_Setable(GPIO_Type* GPIOx, uint32_t GPIO_Pin, FunState NewState);
extern FunState GPIOx_ANEN_Getable(GPIO_Type* GPIOx, uint32_t GPIO_Pin);

extern void GPIO_Deinit(void);
//Announce_End

/* Exported functions --------------------------------------------------------*/ 

extern void GPIO_ALL_Deinit(void);

/* GPIO 初始化配置 */
extern void GPIO_Init(GPIO_Type* GPIOx, GPIO_InitTypeDef* para);

/* 获取一个IO口的配置参数结构体 
	注意一次只能读取一个IO的配置*/
extern void GPIO_Get_InitPara(GPIO_Type* GPIOx, uint32_t GPIO_Pin, GPIO_InitTypeDef* para);

/* 读取GPIOx输入数据寄存器 */
extern uint32_t GPIO_ReadInputData(GPIO_Type* GPIOx);

/* 读取GPIOx输入数据寄存器bit */
extern uint8_t GPIO_ReadInputDataBit(GPIO_Type* GPIOx, uint32_t GPIO_Pin);

/* GPIOx输出数据置1 */
extern void GPIO_SetBits(GPIO_Type* GPIOx, uint32_t GPIO_Pin);

/* GPIOx输出数据置0 */
extern void GPIO_ResetBits(GPIO_Type* GPIOx, uint32_t GPIO_Pin);

/* GPIOx输出数据置翻转 */
extern void GPIO_ToggleBits(GPIO_Type* GPIOx, uint32_t GPIO_Pin);

/* 读取GPIOx输出数据寄存器 */
extern uint32_t GPIO_ReadOutputData(GPIO_Type* GPIOx);

/* 读取GPIOx输出数据寄存器bit */
extern uint8_t GPIO_ReadOutputDataBit(GPIO_Type* GPIOx, uint32_t GPIO_Pin);

/* FOUT1输出频率选择信号 相关函数 */
extern void GPIO_FOUT1SEL_Set(uint32_t SetValue);
extern uint32_t GPIO_FOUT1SEL_Get(void);

/* FOUT0输出频率选择信号 相关函数 */
extern void GPIO_FOUT0SEL_Set(uint32_t SetValue);
extern uint32_t GPIO_FOUT0SEL_Get(void);

/*WKUP中断入口选择函数*/
extern void GPIO_PINWKEN_WKISEL_Set(uint32_t SetValue);
uint32_t GPIO_PINWKEN_WKISEL_Get(void);

/* WKUP引脚使能 */
extern void GPIO_PINWKEN_SetableEx(uint32_t NWKPinDef, FunState NewState);

/* WKUP边沿选择 */
extern void GPIO_PINWKSEL_SetableEx(uint32_t NWKPinDef, FunState NewState);

/*************************************************************************
 函数名称：GPIO_EXTI_Select_Pin
 功能说明：GPIO EXTI 外部引脚选择
 输入参数：GPIOx 端口 GPIO_Pinpin 端口内引脚 
 输出参数：无
 返回参数无
 *************************************************************************/
extern void GPIO_EXTI_Select_Pin(GPIO_Type* GPIOx,uint32_t GPIO_Pin);

/*************************************************************************
 函数名称：GPIO_EXTI_Select_Edge
 功能说明：GPIO EXTI_Select_Edge 外部中断边沿选择
 输入参数：GPIOx 端口 ，GPIO_Pin 端口内引脚 ,edge_select 触发沿
 输出参数：无
 返回参数无
 *************************************************************************/
extern void GPIO_EXTI_Select_Edge(GPIO_Type* GPIOx,uint32_t GPIO_Pin,GPIOExtiEdge edge_select);

/*************************************************************************
 函数名称：GPIO_EXTI_DF_SetableEx
 功能说明：GPIO GPIO_EXTI_DF_SetableEx EXTI数字滤波控制
 输入参数：GPIOx 端口 ，GPIO_Pin 端口内引脚 ,NewState 使能/禁止
 输出参数：无
 返回参数无
 *************************************************************************/
extern void GPIO_EXTI_DF_SetableEx(GPIO_Type* GPIOx,uint32_t GPIO_Pin, FunState NewState);

/*************************************************************************
 函数名称：GPIO_EXTI_ISR_ClrEx
 功能说明：GPIO_EXTI_ISR_ClrEx 清除中断标志
 输入参数：GPIOx 端口 ，GPIO_Pin 端口内引脚 
 输出参数：无
 返回参数无
 *************************************************************************/
extern void GPIO_EXTI_ISR_ClrEx(GPIO_Type* GPIOx,uint32_t GPIO_Pin);

/*************************************************************************
 函数名称：GPIO_EXTI_ISR_ChkEx
 功能说明：GPIO_EXTI_ISR_ChkEx 读取中断标志状态
 输入参数：GPIOx 端口 ，GPIO_Pin 端口内引脚 
 输出参数：无
 返回参数FlagStatus 中断标志状态
 *************************************************************************/
extern FlagStatus GPIO_EXTI_ISR_ChkEx(GPIO_Type* GPIOx,uint32_t GPIO_Pin);

/* EXTI输入信号寄存器 相关函数 */
extern uint32_t GPIO_EXTI_DI_Read(void);

/*************************************************************************
 函数名称：GPIO_EXTI_Init
 功能说明：GPIO_EXTI_Init 外部中断初始化
 输入参数：port 端口 ，pin 端口内引脚 ,edge 触发沿
 输出参数：无
 返回参数无
 *************************************************************************/
extern void GPIO_EXTI_Init(GPIO_Type* GPIOx,uint32_t GPIO_Pin,GPIOExtiEdge edge_select, FunState DFState);

/*************************************************************************
 函数名称：GPIO_EXTI_Close
 功能说明：GPIO_EXTI_Close 外部中断关闭
 输入参数：port 端口 ，pin 端口内引脚 
 输出参数：无
 返回参数无
 *************************************************************************/
extern void GPIO_EXTI_Close(GPIO_Type* GPIOx,uint32_t GPIO_Pin);                
#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_GPIO_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
