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
    GPIO_FCR_IN		= 0x00, /*!< GPIO ���� */
    GPIO_FCR_OUT	= 0x01, /*!< GPIO ��� */
    GPIO_FCR_DIG	= 0x02, /*!< GPIO �������⹦�� */
    GPIO_FCR_ANA	= 0x03  /*!< GPIO ģ�⹦�� */
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
    uint32_t					Pin;     	//PINѡ��
    GPIO_FCR_TypeDef			PxFCR;		//IO����ѡ��
    GPIO_ODEN_TypeDef			PxODEN;		//��©���ʹ�ܿ���
    GPIO_PUEN_TypeDef			PxPUEN;		//��������ʹ�ܿ���
    GPIO_INEN_TypeDef			PxINEN;		//����ʹ�ܿ���
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


/* WKUP����ʹ��PIN�궨�� */
#define		PINWKEN_PD6		BIT7
#define		PINWKEN_PD11	BIT6
#define		PINWKEN_PC10	BIT5
#define		PINWKEN_PC6 	BIT4
#define		PINWKEN_PB12	BIT3
#define		PINWKEN_PB2		BIT2
#define		PINWKEN_PA10	BIT1
#define		PINWKEN_PA15	BIT0

// 1. PortX����ʹ�ܼĴ���
#define	GPIOx_INEN_INEN_Pos	0	//R/W: rw	ResetValue: 0x0
#define	GPIOx_INEN_INEN_Msk	(0xffffU << GPIOx_INEN_INEN_Pos)
								//GPIO����ʹ�ܿ���
								//0���ر�����ʹ��
								//1��������ʹ��

// 2. PortX����ʹ�ܼĴ���
#define	GPIOx_PUEN_PUEN_Pos	0	//R/W: rw	ResetValue: 0x0
#define	GPIOx_PUEN_PUEN_Msk	(0xffffU << GPIOx_PUEN_PUEN_Pos)								
								//GPIO��������
								//0���ر�����
								//1��ʹ������	

// 3. PortX��©ʹ�ܼĴ���								
#define	GPIOx_ODEN_ODEN_Pos	0	//R/W: rw	ResetValue: 0x0
#define	GPIOx_ODEN_ODEN_Msk	(0xffffU << GPIOx_ODEN_ODEN_Pos)
								//GPIO��©���ʹ��
								//0���رտ�©���
								//1��ʹ�ܿ�©���

// 4. PortX����ѡ��Ĵ���								
#define	GPIOx_FCR_Px15FCR_Pos	30	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px15FCR_Msk	(0x03U << GPIOx_FCR_Px15FCR_Pos)
								//Px[15]���Ź���ѡ��
								//00��GPIO����
								//01��GPIO���
								//10��Digital function
								//11��Analog function								
#define	GPIOx_FCR_Px14FCR_Pos	28	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px14FCR_Msk	(0x03U << GPIOx_FCR_Px14FCR_Pos)
								//Px[14]���Ź���ѡ��
								//00��GPIO����
								//01��GPIO���
								//10��Digital function
								//11��Analog function
#define	GPIOx_FCR_Px13FCR_Pos	26	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px13FCR_Msk	(0x03U << GPIOx_FCR_Px13FCR_Pos)
								//Px[13]���Ź���ѡ��
								//00��GPIO����
								//01��GPIO���
								//10��Digital function
								//11��Analog function
#define	GPIOx_FCR_Px12FCR_Pos	24	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px12FCR_Msk	(0x03U << GPIOx_FCR_Px12FCR_Pos)
								//Px[12]���Ź���ѡ��
								//00��GPIO����
								//01��GPIO���
								//10��Digital function
								//11��Analog function
#define	GPIOx_FCR_Px11FCR_Pos	22	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px11FCR_Msk	(0x03U << GPIOx_FCR_Px11FCR_Pos)
								//Px[11]���Ź���ѡ��
								//00��GPIO����
								//01��GPIO���
								//10��Digital function
								//11��Analog function
#define	GPIOx_FCR_Px10FCR_Pos	20	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px10FCR_Msk	(0x03U << GPIOx_FCR_Px10FCR_Pos)
								//Px[10]���Ź���ѡ��
								//00��GPIO����
								//01��GPIO���
								//10��Digital function
								//10��Analog function
#define	GPIOx_FCR_Px9FCR_Pos	18	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px9FCR_Msk	(0x03U << GPIOx_FCR_Px9FCR_Pos)
								//Px[9]���Ź���ѡ��
								//00��GPIO����
								//01��GPIO���
								//10��Digital function
								//11��Analog function	
#define	GPIOx_FCR_Px8FCR_Pos	16	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px8FCR_Msk	(0x03U << GPIOx_FCR_Px8FCR_Pos)
								//Px[8]���Ź���ѡ��
								//00��GPIO����
								//01��GPIO���
								//10��Digital function
								//11��Analog function
#define	GPIOx_FCR_Px7FCR_Pos	14	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px7FCR_Msk	(0x03U << GPIOx_FCR_Px7FCR_Pos)
								//Px[7]���Ź���ѡ��
								//00��GPIO����
								//01��GPIO���
								//10��Digital function
								//11��Analog function
#define	GPIOx_FCR_Px6FCR_Pos	12	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px6FCR_Msk	(0x03U << GPIOx_FCR_Px6FCR_Pos)
								//Px[6]���Ź���ѡ��
								//00��GPIO����
								//01��GPIO���
								//10��Digital function
								//11��Analog function
#define	GPIOx_FCR_Px5FCR_Pos	10	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px5FCR_Msk	(0x03U << GPIOx_FCR_Px5FCR_Pos)
								//Px[5]���Ź���ѡ��
								//00��GPIO����
								//01��GPIO���
								//10��Digital function
								//11��Analog function
#define	GPIOx_FCR_Px4FCR_Pos	8	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px4FCR_Msk	(0x03U << GPIOx_FCR_Px4FCR_Pos)
								//Px[4]���Ź���ѡ��
								//00��GPIO����
								//01��GPIO���
								//10��Digital function
								//11��Analog function
#define	GPIOx_FCR_Px3FCR_Pos	6	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px3FCR_Msk	(0x03U << GPIOx_FCR_Px3FCR_Pos)
								//Px[3]���Ź���ѡ��
								//00��GPIO����
								//01��GPIO���
								//10��Digital function
								//11��Analog function
#define	GPIOx_FCR_Px2FCR_Pos	4	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px2FCR_Msk	(0x03U << GPIOx_FCR_Px2FCR_Pos)
								//Px[2]���Ź���ѡ��
								//00��GPIO����
								//01��GPIO���
								//10��Digital function
								//11��Analog function
#define	GPIOx_FCR_Px1FCR_Pos	2	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px1FCR_Msk	(0x03U << GPIOx_FCR_Px1FCR_Pos)
								//Px[1]���Ź���ѡ��
								//00��GPIO����
								//01��GPIO���
								//10��Digital function
								//11��Analog function
#define	GPIOx_FCR_Px0FCR_Pos	0	//R/W: rw	ResetValue: 0x0
#define	GPIOx_FCR_Px0FCR_Msk	(0x03U << GPIOx_FCR_Px0FCR_Pos)
								//Px[0]���Ź���ѡ��
								//00��GPIO����
								//01��GPIO���
								//10��Digital function
								//11��Analog function	

// 5. PortX������ݼĴ���																						
#define	GPIOx_DO_DO_Pos	0	//R/W: rw	ResetValue: 0x0
#define	GPIOx_DO_DO_Msk	(0xffffU << GPIOx_DO_DO_Pos)
								//GPIO output data register

// 6. PortX���������λ�Ĵ���								
#define	GPIOx_DSET_DSET_Pos	0	//R/W: rw	ResetValue: 0x0
#define	GPIOx_DSET_DSET_Msk	(0xffffU << GPIOx_DSET_DSET_Pos)
								//GPIO output data set register
								//��������PADSETд0x0000_8000����PADOR[15]��λ������λ���ֲ��䡣
								//PASET/PBSETΪ16λ��PCSET/PDSETΪ13λ

// 7. PortX������ݸ�λ�Ĵ���								
#define	GPIOx_DRST_DRESET_Pos	0	//R/W: rw	ResetValue: 0x0
#define	GPIOx_DRST_DRESET_Msk	(0xffffU << GPIOx_DRST_DRESET_Pos)
								//GPIO output data reset register
								//��������PADRSTд0x0000_8000����PADOR[15]���㣬����λ���ֲ���
								//PASET/PBSETΪ16λ��PCSET/PDSETΪ13λ

// 8. PortX�������ݼĴ���																																															
#define	GPIOx_DIN_DIN_Pos	0	//R/W: rw	ResetValue: 0x0
#define	GPIOx_DIN_DIN_Msk	(0xffffU << GPIOx_DIN_DIN_Pos)
								//Portx input data register
								//�˼Ĵ�����ռ�õ�ַ�ռ䣬������ʵ�֡�
								//������˼Ĵ���ֱ�ӷ������������źţ�оƬ���������������������

// 9. PortX�������ֹ��ܼĴ���								
#define	GPIOx_DFS_DFS_Pos	0	//R/W: rw	ResetValue: 0x0
#define	GPIOx_DFS_DFS_Msk	(0xffffU << GPIOx_DFS_DFS_Pos)
								//Portx Digital Function Select
								//���ھ��ж���������蹦�ܵ����ţ�ͨ��PxDFS�Ĵ�������ѡ��ʹ���ĸ����蹦�ܡ�
								//ע�⣬���ڲ�ͬ��IO���飬��Ч�ļĴ���λ���ǲ�һ����

// 10. PortXǿ����ʹ�ܼĴ���								
#define	GPIOx_HD_HD_Pos	0	//R/W: rw	ResetValue: 0x0
#define	GPIOx_HD_HD_Msk	(0xffffU << GPIOx_HD_HD_Pos)
								//PortX High Drive Enable
								//1��ʹ��IOǿ����
								//0���ر�IOǿ����
								//ע��֧��ǿ������IO��PA11/12��PD0/1/11����Ч������Ĵ�����PAHD[11], PAHD[12], PDHD[0], PDHD[1], PDHD[11]������Ĵ��������塣								

// 11. PortXģ�⿪��ʹ�ܼĴ���								
#define	GPIOx_ANEN_ANEN_Pos	0	//R/W: rw	ResetValue: 0x0
#define	GPIOx_ANEN_ANEN_Msk	(0xffffU << GPIOx_ANEN_ANEN_Pos)
								//PortX ģ�⿪��ʹ��
								//1��ʹ��IOģ�⿪��
								//0���ر�IOģ�⿪��
								//ע��֧��ģ�⿪�ص�IO��
								//PA6/PA7/PA13/PA14/PA15
								//PB0/PB1/PB13/PB14/PB15
								//PC0/PC1/PC6/PC7/PC8/PC9/PC10
								//PD0/PD1/PD2/PD11/PD12
								//��Ӧ����IO��PxANEN�Ĵ�����Ч������Ĵ��������塣

// 12. EXTI����ѡ��Ĵ���								
#define	GPIO_EXTI_SEL_DSEL_Pos			24	//R/W: rw	ResetValue: 0x0
#define	GPIO_EXTI_SEL_DSEL_Msk			0x3FU << GPIO_EXTI_SEL_DSEL_Pos
								//PortD EXTI�ж�����ѡ��
								//EXTI_DSEL[5:4] 
								//00��PD8
								//01��PD9
								//10��PD10
								//11��PD11
								//EXTI_DSEL[3:2] 
								//00��PD4
								//01��PD5
								//10��PD6
								//11��PD7
								//EXTI_DSEL[1:0] 
								//00��PD0
								//01��PD1
								//10��PD2
								//11��PD3
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_SEL_CSEL_Pos			16	//R/W: rw	ResetValue: 0x0
#define	GPIO_EXTI_SEL_CSEL_Msk			0x3FU << GPIO_EXTI_SEL_CSEL_Pos
								//PortC EXTI�ж�����ѡ��
								//EXTI_CSEL[5:4] 
								//00��PC8
								//01��PC9
								//10��PC10
								//11��PC11
								//EXTI_CSEL[3:2] 
								//00��PC4
								//01��PC5
								//10��PC6
								//11��PC7
								//EXTI_CSEL[1:0]  
								//00��PC0
								//01��PC1
								//10��PC2
								//11��PC3
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_SEL_BSEL_Pos			8	//R/W: rw	ResetValue: 0x0
#define	GPIO_EXTI_SEL_BSEL_Msk			0xFFU << GPIO_EXTI_SEL_BSEL_Pos
								//PortB EXTI�ж�����ѡ��
								//EXTI_BSEL[7:6] 
								//00��PB12
								//01��PB13
								//10��PB14
								//11��PB15
								//EXTI_BSEL[5:4] 
								//00��PB8
								//01��PB9
								//10��PB10
								//11��PB11
								//EXTI_BSEL[3:2] 
								//00��PB4
								//01��PB5
								//10��PB6
								//11��PB7
								//EXTI_BSEL[1:0]  
								//00��PB0
								//01��PB1
								//10��PB2
								//11��PB3
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_SEL_ASEL_Pos			0	//R/W: rw	ResetValue: 0x0
#define	GPIO_EXTI_SEL_ASEL_Msk			0xFFU << GPIO_EXTI_SEL_ASEL_Pos
								//PortA EXTI�ж�����ѡ��
								//EXTI_ASEL[7:6] 
								//00��PA12
								//01��PA13
								//10��PA14
								//11��PA15
								//EXTI_ASEL[5:4] 
								//00��PA8
								//01��PA9
								//10��PA10
								//11��PA11
								//EXTI_ASEL[3:2] 
								//00��PA4
								//01��PA5
								//10��PA6
								//11��PA7
								//EXTI_ASEL[1:0]  
								//00��PA0
								//01��PA1
								//10��PA2
								//11��PA3
								//

// 13. EXTI����ѡ���ʹ�ܼĴ���								
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_EDS_EXTI15_EDS_Pos		30	//R/W: rw	ResetValue: 0x3
#define	GPIO_EXTI_EDS_EXTI15_EDS_Msk		0x3U << GPIO_EXTI_EDS_EXTI15_EDS_Pos
								//EXTI[15] ��Ե����ѡ��
								//00: rising
								//01: falling
								//10: both
								//11: disable
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_EDS_EXTI14_EDS_Pos		28	//R/W: rw	ResetValue: 0x3
#define	GPIO_EXTI_EDS_EXTI14_EDS_Msk		0x3U << GPIO_EXTI_EDS_EXTI14_EDS_Pos
								//EXTI[14] ��Ե����ѡ��
								//00: rising
								//01: falling
								//10: both
								//11: disable
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_EDS_EXTI13_EDS_Pos		26	//R/W: rw	ResetValue: 0x3
#define	GPIO_EXTI_EDS_EXTI13_EDS_Msk		0x3U << GPIO_EXTI_EDS_EXTI13_EDS_Pos
								//EXTI[13] ��Ե����ѡ��
								//00: rising
								//01: falling
								//10: both
								//11: disable
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_EDS_EXTI12_EDS_Pos		24	//R/W: rw	ResetValue: 0x3
#define	GPIO_EXTI_EDS_EXTI12_EDS_Msk		0x3U << GPIO_EXTI_EDS_EXTI12_EDS_Pos
								//EXTI[12] ��Ե����ѡ��
								//00: rising
								//01: falling
								//10: both
								//11: disable
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_EDS_EXTI11_EDS_Pos		22	//R/W: rw	ResetValue: 0x3
#define	GPIO_EXTI_EDS_EXTI11_EDS_Msk		0x3U << GPIO_EXTI_EDS_EXTI11_EDS_Pos
								//EXTI[11] ��Ե����ѡ��
								//00: rising
								//01: falling
								//10: both
								//11: disable
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_EDS_EXTI10_EDS_Pos		20	//R/W: rw	ResetValue: 0x3
#define	GPIO_EXTI_EDS_EXTI10_EDS_Msk		0x3U << GPIO_EXTI_EDS_EXTI10_EDS_Pos
								//EXTI[10] ��Ե����ѡ��
								//00: rising
								//01: falling
								//10: both
								//11: disable
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_EDS_EXTI9_EDS_Pos			18	//R/W: rw	ResetValue: 0x3
#define	GPIO_EXTI_EDS_EXTI9_EDS_Msk			0x3U << GPIO_EXTI_EDS_EXTI9_EDS_Pos
								//EXTI[9] ��Ե����ѡ��
								//00: rising
								//01: falling
								//10: both
								//11: disable
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_EDS_EXTI8_EDS_Pos			16	//R/W: rw	ResetValue: 0x3
#define	GPIO_EXTI_EDS_EXTI8_EDS_Msk			0x3U << GPIO_EXTI_EDS_EXTI8_EDS_Pos
								//EXTI[8] ��Ե����ѡ��
								//00: rising
								//01: falling
								//10: both
								//11: disable
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_EDS_EXTI7_EDS_Pos			14	//R/W: rw	ResetValue: 0x3
#define	GPIO_EXTI_EDS_EXTI7_EDS_Msk			0x3U << GPIO_EXTI_EDS_EXTI7_EDS_Pos
								//EXTI[7] ��Ե����ѡ��
								//00: rising
								//01: falling
								//10: both
								//11: disable
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_EDS_EXTI6_EDS_Pos			12	//R/W: rw	ResetValue: 0x3
#define	GPIO_EXTI_EDS_EXTI6_EDS_Msk			0x3U << GPIO_EXTI_EDS_EXTI6_EDS_Pos
								//EXTI[6] ��Ե����ѡ��
								//00: rising
								//01: falling
								//10: both
								//11: disable
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_EDS_EXTI5_EDS_Pos			10	//R/W: rw	ResetValue: 0x3
#define	GPIO_EXTI_EDS_EXTI5_EDS_Msk			0x3U << GPIO_EXTI_EDS_EXTI5_EDS_Pos
								//EXTI[5] ��Ե����ѡ��
								//00: rising
								//01: falling
								//10: both
								//11: disable
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_EDS_EXTI4_EDS_Pos			8	//R/W: rw	ResetValue: 0x3
#define	GPIO_EXTI_EDS_EXTI4_EDS_Msk			0x3U << GPIO_EXTI_EDS_EXTI4_EDS_Pos
								//EXTI[4] ��Ե����ѡ��
								//00: rising
								//01: falling
								//10: both
								//11: disable
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_EDS_EXTI3_EDS_Pos			6	//R/W: rw	ResetValue: 0x3
#define	GPIO_EXTI_EDS_EXTI3_EDS_Msk			0x3U << GPIO_EXTI_EDS_EXTI3_EDS_Pos
								//EXTI[3] ��Ե����ѡ��
								//00: rising
								//01: falling
								//10: both
								//11: disable
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_EDS_EXTI2_EDS_Pos			4	//R/W: rw	ResetValue: 0x3
#define	GPIO_EXTI_EDS_EXTI2_EDS_Msk			0x3U << GPIO_EXTI_EDS_EXTI2_EDS_Pos
								//EXTI[2] ��Ե����ѡ��
								//00: rising
								//01: falling
								//10: both
								//11: disable
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_EDS_EXTI1_EDS_Pos			2	//R/W: rw	ResetValue: 0x3
#define	GPIO_EXTI_EDS_EXTI1_EDS_Msk			0x3U << GPIO_EXTI_EDS_EXTI1_EDS_Pos
								//EXTI[1] ��Ե����ѡ��
								//00: rising
								//01: falling
								//10: both
								//11: disable
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_EDS_EXTI0_EDS_Pos			0	//R/W: rw	ResetValue: 0x3
#define	GPIO_EXTI_EDS_EXTI0_EDS_Msk			0x3U << GPIO_EXTI_EDS_EXTI0_EDS_Pos
								//EXTI[0] ��Ե����ѡ��
								//00: rising
								//01: falling
								//10: both
								//11: disable
								//
								
// 14. EXTI�����˲����ƼĴ���								
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_DF_DF_Pos			0	//** R/W: rw	ResetValue: 0x0
#define	GPIO_EXTI_DF_DF_Msk			0xFFFFU << GPIO_EXTI_DF_DF_Pos
								//EXTI���������˲�����ʹ��
								//0���ر�EXTI�����˲�
								//1��ʹ��EXTI�����˲�
								//
								
// 15. EXTI�жϱ�־�Ĵ���							
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_ISR_IF_Pos			0	//** R/W: rw	ResetValue: 0x0
#define	GPIO_EXTI_ISR_IF_Msk			0xFFFFU << GPIO_EXTI_ISR_IF_Pos
								//�ⲿ�����жϱ�־�Ĵ����������Բ���16�������ж�
								//Ӳ����λ�����д1����
								//
								
// 16. EXTI�����źżĴ���							
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_EXTI_DI_DI_Pos			0	//** R/W: ro	ResetValue: 0x0
#define	GPIO_EXTI_DI_DI_Msk			0xFFFFU << GPIO_EXTI_DI_DI_Pos
								//EXTI�����ź�ֻ���Ĵ����������ȡ�˼Ĵ������Թ۲�EXTI��16�������źŵĵ�ǰ״̬
								//ע����ʹ���������˲���������Դ�����Ĵ�����ȡ��ĳ��IO�����ź��˲����״̬��
								//
								
// 17. FOUT���üĴ���								
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
								//PB12���ѡ��
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
								//PD11���ѡ��
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
								
// 18. WKUPʹ�ܼĴ���								
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_PINWKEN_WKISEL_Pos			31	//R/W: rw	ResetValue: 0x0
#define	GPIO_PINWKEN_WKISEL_Msk			0x1U << GPIO_PINWKEN_WKISEL_Pos
								//WKUPx�ж����ѡ��
								//0��NMI�жϣ�����FM385��
								//1��#39���
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_PINWKEN_SEL_Pos			8	//R/W: rw	ResetValue: 0x0
#define	GPIO_PINWKEN_SEL_Msk			0xFFU << GPIO_PINWKEN_SEL_Pos
								//WKUP����ѡ��
								//1����Ӧ��WKUP����Ϊ�����ػ���
								//0����Ӧ��WKUP����Ϊ�½��ػ���
								//
//-----------------------------------------------------------------------------------------------------------------------------
#define	GPIO_PINWKEN_EN_Pos			0	//R/W: rw	ResetValue: 0x0
#define	GPIO_PINWKEN_EN_Msk			0xFFU << GPIO_PINWKEN_EN_Pos
								//WKUP����ʹ���ź�
								//1����Ӧ��WKUP���Ź�����Ч
								//0����Ӧ��WKUP���Ź�����Ч
								//PINWKEN[x]����WKUPx���ŵ�ʹ��
								//
/* Exported functions --------------------------------------------------------*/ 
extern void GPIOx_Deinit(GPIO_Type* GPIOx);

/* PortX������ݼĴ��� ��غ��� */
extern void GPIOx_DO_Write(GPIO_Type* GPIOx, uint32_t SetValue);
extern uint32_t GPIOx_DO_Read(GPIO_Type* GPIOx);

/* PortX���������λ�Ĵ��� ��غ��� */
extern void GPIOx_DSET_Write(GPIO_Type* GPIOx, uint32_t SetValue);

/* PortX������ݸ�λ�Ĵ��� ��غ��� */
extern void GPIOx_DRST_Write(GPIO_Type* GPIOx, uint32_t SetValue);

/* PortX�������ݼĴ��� ��غ��� */
extern uint32_t GPIOx_DIN_Read(GPIO_Type* GPIOx);

/* PortX�������ֹ��ܼĴ��� ��غ��� */
extern void GPIOx_DFS_Setable(GPIO_Type* GPIOx, uint32_t GPIO_Pin, FunState NewState);
extern FunState GPIOx_DFS_Getable(GPIO_Type* GPIOx, uint32_t GPIO_Pin);

/* PortXǿ����ʹ�ܼĴ��� ��غ��� */
extern void GPIOx_HD_Setable(GPIO_Type* GPIOx, uint32_t GPIO_Pin, FunState NewState);
extern FunState GPIOx_HD_Getable(GPIO_Type* GPIOx, uint32_t GPIO_Pin);

/* PortXģ�⿪��ʹ�ܼĴ��� ��غ��� */
extern void GPIOx_ANEN_Setable(GPIO_Type* GPIOx, uint32_t GPIO_Pin, FunState NewState);
extern FunState GPIOx_ANEN_Getable(GPIO_Type* GPIOx, uint32_t GPIO_Pin);

extern void GPIO_Deinit(void);
//Announce_End

/* Exported functions --------------------------------------------------------*/ 

extern void GPIO_ALL_Deinit(void);

/* GPIO ��ʼ������ */
extern void GPIO_Init(GPIO_Type* GPIOx, GPIO_InitTypeDef* para);

/* ��ȡһ��IO�ڵ����ò����ṹ�� 
	ע��һ��ֻ�ܶ�ȡһ��IO������*/
extern void GPIO_Get_InitPara(GPIO_Type* GPIOx, uint32_t GPIO_Pin, GPIO_InitTypeDef* para);

/* ��ȡGPIOx�������ݼĴ��� */
extern uint32_t GPIO_ReadInputData(GPIO_Type* GPIOx);

/* ��ȡGPIOx�������ݼĴ���bit */
extern uint8_t GPIO_ReadInputDataBit(GPIO_Type* GPIOx, uint32_t GPIO_Pin);

/* GPIOx���������1 */
extern void GPIO_SetBits(GPIO_Type* GPIOx, uint32_t GPIO_Pin);

/* GPIOx���������0 */
extern void GPIO_ResetBits(GPIO_Type* GPIOx, uint32_t GPIO_Pin);

/* GPIOx��������÷�ת */
extern void GPIO_ToggleBits(GPIO_Type* GPIOx, uint32_t GPIO_Pin);

/* ��ȡGPIOx������ݼĴ��� */
extern uint32_t GPIO_ReadOutputData(GPIO_Type* GPIOx);

/* ��ȡGPIOx������ݼĴ���bit */
extern uint8_t GPIO_ReadOutputDataBit(GPIO_Type* GPIOx, uint32_t GPIO_Pin);

/* FOUT1���Ƶ��ѡ���ź� ��غ��� */
extern void GPIO_FOUT1SEL_Set(uint32_t SetValue);
extern uint32_t GPIO_FOUT1SEL_Get(void);

/* FOUT0���Ƶ��ѡ���ź� ��غ��� */
extern void GPIO_FOUT0SEL_Set(uint32_t SetValue);
extern uint32_t GPIO_FOUT0SEL_Get(void);

/*WKUP�ж����ѡ����*/
extern void GPIO_PINWKEN_WKISEL_Set(uint32_t SetValue);
uint32_t GPIO_PINWKEN_WKISEL_Get(void);

/* WKUP����ʹ�� */
extern void GPIO_PINWKEN_SetableEx(uint32_t NWKPinDef, FunState NewState);

/* WKUP����ѡ�� */
extern void GPIO_PINWKSEL_SetableEx(uint32_t NWKPinDef, FunState NewState);

/*************************************************************************
 �������ƣ�GPIO_EXTI_Select_Pin
 ����˵����GPIO EXTI �ⲿ����ѡ��
 ���������GPIOx �˿� GPIO_Pinpin �˿������� 
 �����������
 ���ز����w��
 *************************************************************************/
extern void GPIO_EXTI_Select_Pin(GPIO_Type* GPIOx,uint32_t GPIO_Pin);

/*************************************************************************
 �������ƣ�GPIO_EXTI_Select_Edge
 ����˵����GPIO EXTI_Select_Edge �ⲿ�жϱ���ѡ��
 ���������GPIOx �˿� ��GPIO_Pin �˿������� ,edge_select ������
 �����������
 ���ز����w��
 *************************************************************************/
extern void GPIO_EXTI_Select_Edge(GPIO_Type* GPIOx,uint32_t GPIO_Pin,GPIOExtiEdge edge_select);

/*************************************************************************
 �������ƣ�GPIO_EXTI_DF_SetableEx
 ����˵����GPIO GPIO_EXTI_DF_SetableEx EXTI�����˲�����
 ���������GPIOx �˿� ��GPIO_Pin �˿������� ,NewState ʹ��/��ֹ
 �����������
 ���ز����w��
 *************************************************************************/
extern void GPIO_EXTI_DF_SetableEx(GPIO_Type* GPIOx,uint32_t GPIO_Pin, FunState NewState);

/*************************************************************************
 �������ƣ�GPIO_EXTI_ISR_ClrEx
 ����˵����GPIO_EXTI_ISR_ClrEx ����жϱ�־
 ���������GPIOx �˿� ��GPIO_Pin �˿������� 
 �����������
 ���ز����w��
 *************************************************************************/
extern void GPIO_EXTI_ISR_ClrEx(GPIO_Type* GPIOx,uint32_t GPIO_Pin);

/*************************************************************************
 �������ƣ�GPIO_EXTI_ISR_ChkEx
 ����˵����GPIO_EXTI_ISR_ChkEx ��ȡ�жϱ�־״̬
 ���������GPIOx �˿� ��GPIO_Pin �˿������� 
 �����������
 ���ز����wFlagStatus �жϱ�־״̬
 *************************************************************************/
extern FlagStatus GPIO_EXTI_ISR_ChkEx(GPIO_Type* GPIOx,uint32_t GPIO_Pin);

/* EXTI�����źżĴ��� ��غ��� */
extern uint32_t GPIO_EXTI_DI_Read(void);

/*************************************************************************
 �������ƣ�GPIO_EXTI_Init
 ����˵����GPIO_EXTI_Init �ⲿ�жϳ�ʼ��
 ���������port �˿� ��pin �˿������� ,edge ������
 �����������
 ���ز����w��
 *************************************************************************/
extern void GPIO_EXTI_Init(GPIO_Type* GPIOx,uint32_t GPIO_Pin,GPIOExtiEdge edge_select, FunState DFState);

/*************************************************************************
 �������ƣ�GPIO_EXTI_Close
 ����˵����GPIO_EXTI_Close �ⲿ�жϹر�
 ���������port �˿� ��pin �˿������� 
 �����������
 ���ز����w��
 *************************************************************************/
extern void GPIO_EXTI_Close(GPIO_Type* GPIOx,uint32_t GPIO_Pin);                
#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_GPIO_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
