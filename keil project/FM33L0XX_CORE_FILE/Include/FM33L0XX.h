
/****************************************************************************************************//**
 * @file     FM33L0XX.h
 *
 * @brief    CMSIS Cortex-M0 Peripheral Access Layer Header File for
 *           FM33L0XX from Keil.
 *
 * @version  V0.1.2
 * @date     20. jun 2019
 *
 * @note     Generated with SVDConv V2.87e 
 *           from CMSIS SVD File 'FM33L0XX.SVD' Version 1.0,
 *
 * @par      ARM Limited (ARM) is supplying this software for use with Cortex-M
 *           processor based microcontroller, but can be equally used for other
 *           suitable processor architectures. This file can be freely distributed.
 *           Modifications to this file shall be clearly marked.
 *           
 *           THIS SOFTWARE IS PROVIDED "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 *           OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 *           MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 *           ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 *           CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER. 
 *
 *******************************************************************************************************/



/** @addtogroup Keil
  * @{
  */

/** @addtogroup FM33L0XX
  * @{
  */

#ifndef FM33L0XX_H
#define FM33L0XX_H

#ifdef __cplusplus
extern "C" {
#endif


typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus;
typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunState;
typedef enum {FAIL = 0, PASS = !FAIL} ErrorStatus;

#define __RCHF_INITIAL_CLOCK    (8000000)		/* Value of the Internal RC HIGH oscillator in Hz */
#define __RC4M_CLOCK    				(4000000)		/* Value of the Internal RC 4M oscillator in Hz */
#define __RCLP_CLOCK    				(32000)			/* Value of the Internal RC LOW oscillator in Hz */
#define __XTHF_CLOCK    				(8000000)			/* Value of the EXTERNAL oscillator in Hz */
#define __XTLF_CLOCK    				(32768)			/* Value of the EXTERNAL oscillator in Hz */



/* -------------------------  Interrupt Number Definition  ------------------------ */

typedef enum {
/* -------------------  Cortex-M0 Processor Exceptions Numbers  ------------------- */
  Reset_IRQn                    = -15,              /*!<   1  Reset Vector, invoked on Power up and warm reset                 */
  NMI_IRQn                      = -14,              /*!<   2  Non maskable Interrupt, cannot be stopped or preempted           */
  HardFault_IRQn                = -13,              /*!<   3  Hard Fault, all classes of Fault                                 */
  SVCall_IRQn                   =  -5,              /*!<  11  System Service Call via SVC instruction                          */
  PendSV_IRQn                   =  -2,              /*!<  14  Pendable request for system service                              */
  SysTick_IRQn                  =  -1,              /*!<  15  System Tick Timer                                                */
/* ---------------------  FM33L0XX Specific Interrupt Numbers  -------------------- */
  WWDT_IRQn                   	=  0,               /*!<   0    WWDT             */
  SVD_IRQn               				=  1,               /*!<   1    SVD_IRQn         */
  RTC_IRQn               				=  2,               /*!<   2    RTC_IRQn         */
  FLASH_IRQn                  	=  3,               /*!<   3    FLASH_IRQn       */ 
  LFDET_IRQn                 		=  4,               /*!<   4    LFDET_IRQn       */
  ADC_IRQn                  		=  5,               /*!<   5    ADC_IRQn         */
  NULL1			                    =  6,               /*!<   6    NULL             */
  SPI1_IRQn                     =  7,               /*!<   7    SPI1_IRQn        */
  SPI2_IRQn                     =  8,               /*!<   8    SPI2_IRQn        */
  LCD_IRQn                 	    =  9,               /*!<   9    LCD_IRQn        */
  UART0_IRQn                    =  10,           		/*!<  10   UART0_IRQn       */
  UART1_IRQn                    =  11,           		/*!<  11   UART1_IRQn       */
  UART4_IRQn                    =  12,           		/*!<  12   UART4_IRQn	      */
  UART5_IRQn                    =  13,              /*!<  13   UART5_IRQn       */ 
  HFDET_IRQn           			    =  14,              /*!<  14   HFDET_IRQn       */
	U7816_IRQn	            			=  15,              /*!<  15   U7816_IRQn       */
  LPUART1_IRQn            		  =  16,              /*!<  16   LPUART1_IRQn     */
  I2C_IRQn                      =  17,              /*!<  17   I2C_IRQn         */
	NULL3			                    =  18,           		/*!<  18   NULL             */
  AES_IRQn                      =  19,              /*!<  19   AES_IRQn         */ 
  LPTIM_IRQn                    =  20,              /*!<  20   LPTIM_IRQn			  */
	DMA_IRQn                 		  =  21,              /*!<  21   DMA_IRQn         */
  WKUP_IRQn		                  =  22,              /*!<  22   WKUP_IRQn        */
  OPA1_IRQn 		                =  23,              /*!<  23   OPA1_IRQn        */
  BSTIM_IRQn                    =  24,              /*!<  24   BSTIM_IRQn       */
  OPA2_IRQn   		              =  25,              /*!<  25   OPA2_IRQn        */
  GPTIM0_IRQn                   =  26,              /*!<  26   GTIM0_IRQn      */
  GPTIM1_IRQn                   =  27,              /*!<  27   GTIM1_IRQn      */
  ATIM_IRQn                     =  28,              /*!<  28   ATIM_IRQn        */
  VREF_IRQn						          =  29,              /*!<  29   VREF_IRQn	      */
  GPIO_IRQn                  		=  30,              /*!<  30   GPIO_IRQn        */
	LPUART0_IRQn               		=  31,              /*!<  31   LPUART0_IRQn 	  */
} IRQn_Type;


/** @addtogroup Configuration_of_CMSIS
  * @{
  */


/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/* ----------------Configuration of the Cortex-M0 Processor and Core Peripherals---------------- */
#define __CM0_REV                 0x0100            /*!< Cortex-M0 Core Revision                                               */
#define __MPU_PRESENT                  0            /*!< MPU present or not                                                    */
#define __VTOR_PRESENT            		 1						/*!< VTOR present or not 																									 */
#define __NVIC_PRIO_BITS               2            /*!< Number of Bits used for Priority Levels                               */
#define __Vendor_SysTickConfig         0            /*!< Set to 1 if different SysTick Config is used                          */
/** @} */ /* End of group Configuration_of_CMSIS */

#include "core_cm0plus.h"                            /*!< Cortex-M0 processor and core peripherals                           */
#include "system_FM33L0XX.h"                        /*!< FM33L0XX System                                                        */

/* ================================================================================ */
/* ================       Device Specific Peripheral Section       ================ */
/* ================================================================================ */


/** @addtogroup Device_Peripheral_Registers
  * @{
  */


/* -------------------  Start of section using anonymous unions  ------------------ */
#if defined(__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined(__ICCARM__)
  #pragma language=extended
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
/* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning 586
#else
  #warning Not supported compiler type
#endif

/* ================================================================================ */
/* ================                       DBG                      ================ */
/* ================================================================================ */
typedef struct
{
  __IO uint32_t REV;
  __IO uint32_t CR; 							    /*!<  Debug Configuration Register */
	__IO uint32_t HDFR;   							/*!<  HardFault Flag Register*/
  __IO uint32_t WKFR;  							  /*!<  Debug Wakeup Flag Register*/
	
}DBG_Type;


/* ================================================================================ */
/* ================                       PMU                      ================ */
/* ================================================================================ */
typedef struct
{
	__IO uint32_t CR; 							  		    /*!< Power Management Control Register  */
	__IO uint32_t WKTR;   								    /*!<  Wakeup Time Register*/
	__IO uint32_t WKFR;  								      /*!<  Wakeup Source Flags Register*/
  __IO uint32_t IER;									      /*!<  PMU Interrupt Enable Register*/
  __IO uint32_t ISR;									      /*!<  PMU Interrupt and Status Register*/
}PMU_Type;

typedef struct
{
	__IO uint32_t CR; 							  		    /*!< VREF Control Register  */
	__IO uint32_t SR;   								      /*!<  VREF Status Register*/
	__IO uint32_t IER;  								      /*!<  VREF Interrupt Enable Register*/
}PMU_VREF_Type;

typedef struct
{
	__IO uint32_t CR; 							  		    /*!< Buffer Control Register  */
}PMU_BUF_Type;

/* ================================================================================ */
/* ================                       UART                     ================ */
/* ================================================================================ */

typedef struct 
{
	__IO 	uint32_t	IRCR;								/*!< Infrared modulation Control Register */  		
	
} UART_COMMON_Type;
	 
typedef struct 
{
  __IO  uint32_t CSR;               /*!< UART Control Status Register */
  __IO 	uint32_t IER;               /*!< UART  Interrupt Enable Register */
  __IO 	uint32_t ISR;               /*!< UART Interrupt Status Register*/
  __IO 	uint32_t TODR;              /*!< UART Time-Out and Delay Register*/
  __IO 	uint32_t RXBUF;             /*!< UART  Receive Buffer */
	__IO 	uint32_t TXBUF;             /*!< UART Transmit Buffer */
	__IO 	uint32_t BGR;								/*!< UART Baud rate Generator Register */
												
} UART_Type; 

/* ================================================================================ */
/* ================                      RCC                  ================ */
/* ================================================================================ */
typedef struct
{
	__IO uint32_t LKP_CR;							/*!< Lockup reset Control Register			         ,Address offset: 0x00*/
	__IO uint32_t SOFTRST;						/*!< Software Reset Register		                 ,Address offset: 0x04*/
	__IO uint32_t RSTFR;							/*!<  Reset Flag Register				                 ,Address offset: 0x08*/
  __IO uint32_t SYSCLK_CR; 					/*!<  System Clock Control Register						   ,Address offset: 0x0C*/
  __IO uint32_t RCHF_CR;   					/*!<  RCHF Control Register			                 ,Address offset: 0x10*/
  __IO uint32_t RC4M_TR;  					/*!<  RC4M Trim Register					               ,Address offset: 0x14*/
  __IO uint32_t PLL_CR;  						/*!<  PLL Control Register				               ,Address offset: 0x18*/
	__IO uint32_t RCLP_CR;  					/*!<  RCLP CONFIG REGISTER 			                 ,Address offset: 0x1C*/
	__IO uint32_t RCLP_TR;  					/*!<  RCLP TRIM  REGISTER					               ,Address offset: 0x20*/
	__IO uint32_t XTLF_CR;  					/*!<  XTLF CONFIG REGISTER			                 ,Address offset: 0x24*/
	__IO uint32_t PCLK_CR1;  					/*!<  Peripheral bus Clock Control Register1 		 ,Address offset: 0x28*/
	__IO uint32_t PCLK_CR2;  					/*!<  Peripheral bus Clock Control Register2 		 ,Address offset: 0x2C*/
	__IO uint32_t PCLK_CR3;  					/*!<  Peripheral bus Clock Control Register3 		 ,Address offset: 0x30*/
	__IO uint32_t PCLK_CR4;  					/*!<  Peripheral bus Clock Control Register4 		 ,Address offset: 0x34*/
	__IO uint32_t REV0;								/*!<  RESERVED REGISTER 0	 			                 ,Address offset: 0x38*/
	__IO uint32_t REV1;								/*!<  RESERVED REGISTER 1	 			                 ,Address offset: 0x3C*/
	__IO uint32_t REV2;								/*!<  RESERVED REGISTER 2	 			                 ,Address offset: 0x40*/
	__IO uint32_t AHBM_CR;  					/*!<  AHB Master Control Register                ,Address offset: 0x44*/
	__IO uint32_t REV3;  							/*!<  RESERVED REGISTER 3		                     ,Address offset: 0x48*/
	__IO uint32_t REV4;  							/*!<  RESERVED REGISTER 4		                     ,Address offset: 0x4C*/
	__IO uint32_t PRST_EN;   	        /*!<  Peripheral Reset Enable Register           ,Address offset: 0x50*/
  __IO uint32_t AHBRST_CR;   		    /*!<  AHB Peripherals Reset Control Register     ,Address offset: 0x54*/
  __IO uint32_t APBRST_CR1;  		    /*!<  APB Peripherals Reset Control Register1    ,Address offset: 0x58*/
	__IO uint32_t APBRST_CR2;  		    /*!<  APB Peripherals Reset Control Register2    ,Address offset: 0x5C*/
	__IO uint32_t XTHF_CR; 						/*!<  XTHF Control Register			                 ,Address offset: 0x60*/
	__IO uint32_t RC4M_CR; 					  /*!<  RC4M Control Register			                 ,Address offset: 0x64*/
	__IO uint32_t RCHF_TR; 						/*!<  RCHF Trim Register                         ,Address offset: 0x68*/	
	__IO uint32_t OPC_CR1; 						/*!<  Peripheral Operation Clock Control Register1	,Address offset: 0x6C*/	
	__IO uint32_t OPC_CR2; 						/*!<  Peripheral Operation Clock Control Register2  ,Address offset: 0x70*/
	
}RCC_Type;

typedef struct
{
  __IO uint32_t IER;						/*!< XTLF Oscillation Fail Detection Interrupt Enable Register,	        Address offset: 0x00 */
  __IO uint32_t ISR;						/*!< XTLF Oscillation Fail Detection Interrupt Status Register,		      Address offset: 0x04 */

}RCC_FDET_Type;
typedef struct
{
  __IO uint32_t CR;						/*!< PDR Control Register,	        Address offset: 0x00 */

}RCC_PDR_Type;

typedef struct
{
  __IO uint32_t CR;						/*!< BOR Control Register,	        Address offset: 0x00 */

}RCC_BOR_Type;

/* ================================================================================ */
/* ================                       DMA                      ================ */
/* ================================================================================ */
typedef struct
{
  __IO uint32_t GCR; 						/*!<  DMA Global Control Register 		    ,Address offset: 0x00*/
  __IO uint32_t CH0_CR;   			/*!<  Channel 0 Control Register		      ,Address offset: 0x04*/
  __IO uint32_t CH0_MAD;  			/*!<  Channel 0 Memory Address Register 	,Address offset: 0x08*/
  __IO uint32_t CH1_CR;  				/*!<  Channel 1 Control Register          ,Address offset: 0x0C*/
	__IO uint32_t CH1_MAD;  			/*!<  Channel 1 Memory Address Register   ,Address offset: 0x10*/	
	__IO uint32_t CH2_CR;  				/*!<  Channel 2 Control Register          ,Address offset: 0x14*/
	__IO uint32_t CH2_MAD;  			/*!<  Channel 2 Memory Address Register   ,Address offset: 0x18*/
	__IO uint32_t CH3_CR;  				/*!<  Channel 3 Control Register          ,Address offset: 0x1C*/
	__IO uint32_t CH3_MAD;  			/*!<  Channel 3 Memory Address Register   ,Address offset: 0x20*/
	__IO uint32_t CH4_CR;  				/*!<  Channel 4 Control Register          ,Address offset: 0x24*/
	__IO uint32_t CH4_MAD;  			/*!<  Channel 4 Memory Address Register   ,Address offset: 0x28*/
	__IO uint32_t CH5_CR;  				/*!<  Channel 5 Control Register          ,Address offset: 0x2C*/
	__IO uint32_t CH5_MAD;  			/*!<  Channel 5 Memory Address Register   ,Address offset: 0x30*/
	__IO uint32_t CH6_CR;  				/*!<  Channel 6 Control Register          ,Address offset: 0x34*/
	__IO uint32_t CH6_MAD;  			/*!<  Channel 6 Memory Address Register   ,Address offset: 0x38*/
	__IO uint32_t CH7_CR;  				/*!<  Channel 7 Control Register          ,Address offset: 0x3C*/
	__IO uint32_t CH7_FLSAD;  		/*!<  Channel 7 Flash Address Register    ,Address offset: 0x40*/
	__IO uint32_t CH7_RAMAD;  		/*!<  Channel 7 RAM Address Register      ,Address offset: 0x44*/
	__IO uint32_t ISR;  					/*!<  DMA Interrupt Status Register       ,Address offset: 0x48*/
  
}DMA_Type;


/* ================================================================================ */
/* ================                        SPI                     ================ */
/* ================================================================================ */
typedef struct
{
  __IO uint32_t CR1; 								/*!<  SPI1 Control Register1 */
  __IO uint32_t CR2;   							/*!<  SPI1 Control Register2 */
  __IO uint32_t CR3;  							/*!<  SPI1 Control Register3 */
  __IO uint32_t IER;  		  				/*!< SPI1 Interrupt Enable Register */
	__IO uint32_t ISR;  							/*!<  SPI1 Status Register */	
	__IO uint32_t TXBUF;  						/*!<  SPI1 Transmit Buffer */
	__IO uint32_t RXBUF;  						/*!<  SPI1 Receive Buffer */
  
}SPI_Type;


/* ================================================================================ */
/* ================                       GPIO                     ================ */
/* ================================================================================ */
typedef struct
{
  __IO uint32_t INEN; 									/*!<  Input Enable Register*/
  __IO uint32_t PUEN;   								/*!<  Pull-Up Enable Register*/
  __IO uint32_t ODEN;  									/*!<  Open-Drain Enable Register*/
  __IO uint32_t FCR;  									/*!<  Function Control Register*/
	__IO uint32_t DO;  									  /*!<  Data Output Register  */	
	__O uint32_t  DSET;  									/*!<  Data Set Register  */
	__O uint32_t  DRST;  								  /*!<  Data Reset Register */
	__I uint32_t  DIN;  									/*!<  Data Input RegisterR */
	__IO uint32_t DFS;							 		  /*!<  Digital Function Select*/
	__IO uint32_t HD;										  /*!<  High Driver Enable Register*/
  __IO uint32_t ANEN;                   /*!<  Analog channel Enable Register*/
  
}GPIO_Type;

typedef struct
{
  __IO uint32_t EXTI_SEL; 						  	/*!<  External Interrupt input Select Register			 */
  __IO uint32_t EXTI_EDS;   						  /*!<  External Interrupt Edge Select and Enable Register	 */
  __IO uint32_t EXTI_DF;  							  /*!<  External Interrupt Digital Filter Register	 */
  __IO uint32_t EXTI_ISR;  							  /*!<  External Interrupt and Status Register			 */
	__IO uint32_t EXTI_DI;  						/*!<  External Interrupt Data Input Register		 */	
  __IO uint32_t RSV0[59];                 /*!<  RESERVED REGISTER 	     */
  __IO uint32_t FOUT_SEL;                 /*!<  Frequency Output Select Register	   */
  __IO uint32_t RSV1[63];                 /*!<  RESERVED REGISTER 	 	   */
  __IO uint32_t PINWKEN;                  /*!<  Wakeup Enable Register */
}GPIO_COMMON_Type;


/* ================================================================================ */
/* ================                       IWDG                     ================ */
/* ================================================================================ */
typedef struct
{
  __IO uint32_t SERV;   	/*!< IWDT Service Register,          Address offset: 0x00 */
  __IO uint32_t CR;   		/*!< IWDT Config Register, 		       Address offset: 0x04 */
  __I uint32_t 	CNT;  		/*!< IWDT Counter Register,          Address offset: 0x08 */
  __IO uint32_t WIN;	    /*!< IWDT Window Register,           Address offset: 0x0C */
  __IO uint32_t SR;	      /*!< IWDT Status Register,           Address offset: 0x10 */
} IWDT_Type;


/* ================================================================================ */
/* ================                      FLASH                     ================ */
/* ================================================================================ */
typedef struct
{
  __IO uint32_t RDCR;        /*!< Flash Read Control Register,              Address offset: 0x00 */
  __IO uint32_t REV;   		   /*!< RESERVED REGISTER,		                    Address offset: 0x04 */
  __I uint32_t 	OPTBR;  		 /*!< Flash Option Bytes Register,              Address offset: 0x08 */
	__IO uint32_t ACLOCK;		   /*!< Flash Application Code Lock Register,     Address offset: 0x0C */
	__IO uint32_t RSV0;				 /*!< RESERVED REGISTER,                        Address offset: 0x10 */
	__IO uint32_t EPCR;			   /*!< Flash Erase/Program Control Register,     Address offset: 0x14 */
	__IO uint32_t KEY;			   /*!< Flash Key Register,                       Address offset: 0x18 */
	__IO uint32_t IER;			   /*!< Flash Interrupt Enable Register,          Address offset: 0x1C */
	__IO uint32_t ISR;			   /*!< Flash Interrupt Status Register,          Address offset: 0x20 */	
    
} FLS_Type;

/* ================================================================================ */
/* ================                     ATIM                       ================ */
/* ================================================================================ */
typedef struct
{
  __IO uint32_t CR1;   				/*!< ATIM Control Register1,       	            Address offset: 0x00 */
  __IO uint32_t CR2;          /*!< ATIM Control Register2,       	            Address offset: 0x04 */
  __IO uint32_t SMCR;         /*!< ATIM Slave Mode Control Register,          Address offset: 0x08 */
  __IO uint32_t DIER;         /*!< ATIM DMA and Interrupt Enable Register,    Address offset: 0x0C */
  __IO uint32_t ISR;          /*!< ATIM Interrupt Status Register,       	    Address offset: 0x10 */
  __IO uint32_t EGR;          /*!< ATIM Event Generation Register,            Address offset: 0x14 */
  __IO uint32_t CCMR1;        /*!< ATIM Capture/Compare Mode Register1,       Address offset: 0x18 */
  __IO uint32_t CCMR2;        /*!< ATIM Capture/Compare Mode Register2,       Address offset: 0x1C */
  __IO uint32_t CCER;         /*!< ATIM Capture/Compare Enable Register,      Address offset: 0x20 */
  __IO uint32_t CNT;          /*!< ATIM Counter Register,       	            Address offset: 0x24 */
  __IO uint32_t PSC;          /*!< ATIM Prescaler Register,       	          Address offset: 0x28 */
  __IO uint32_t ARR;          /*!< ATIM Auto-Reload Register,       	        Address offset: 0x2C */
  __IO uint32_t RCR;          /*!< ATIM Repetition Counter Register,          Address offset: 0x30 */
  __IO uint32_t CCR1;         /*!< ATIM Capture/Compare Register1,       	    Address offset: 0x34 */
  __IO uint32_t CCR2;         /*!< ATIM Capture/Compare Register2,       	    Address offset: 0x38 */
  __IO uint32_t CCR3;         /*!< ATIM Capture/Compare Register3,       	    Address offset: 0x3C */
  __IO uint32_t CCR4;         /*!< ATIM Capture/Compare Register4,       	    Address offset: 0x40 */
  __IO uint32_t BDTR;         /*!< ATIM Break and Deadtime Register,       	  Address offset: 0x44 */
  __IO uint32_t DCR;          /*!< ATIM DMA Control Register,       	        Address offset: 0x48 */
  __IO uint32_t DMAR;         /*!< ATIM DMA Access Register,       	          Address offset: 0x4C */
  __IO uint32_t RSV0;         /*!< RESERVED REGISTER0,       	                Address offset: 0x50 */
  __IO uint32_t RSV1;         /*!< RESERVED REGISTER1,        	              Address offset: 0x54 */
  __IO uint32_t RSV2;         /*!< RESERVED REGISTER2,       	                Address offset: 0x58 */
  __IO uint32_t RSV3;         /*!< RESERVED REGISTER3,       	                Address offset: 0x5C */
  __IO uint32_t BKCR;         /*!< ATIM Break Control Register,       	      Address offset: 0x60 */
  
} ATIM_Type;

/* ================================================================================ */
/* ================                     GPTIM                      ================ */
/* ================================================================================ */
typedef struct
{
  __IO uint32_t CR1;   				 /*!< GPTIM Control Register1,       	            Address offset: 0x00 */
  __IO uint32_t CR2;           /*!< GPTIM Control Register2,       	            Address offset: 0x04 */
  __IO uint32_t SMCR;          /*!< GPTIM Slave Mode Control Register,          Address offset: 0x08 */
  __IO uint32_t DIER;          /*!< GPTIM DMA and Interrupt Enable Register,    Address offset: 0x0C */
  __IO uint32_t ISR;           /*!< GPTIM Interrupt Status Register,       	    Address offset: 0x10 */
  __IO uint32_t EGR;           /*!< GPTIM EVENT GENERATE REGISTER,              Address offset: 0x14 */
  __IO uint32_t CCMR1;         /*!< GPTIM Capture/Compare Mode Register1,       Address offset: 0x18 */
  __IO uint32_t CCMR2;         /*!< GPTIM Capture/Compare Mode Register2,       Address offset: 0x1C */
  __IO uint32_t CCER;          /*!< GPTIM Capture/Compare Enable Register,      Address offset: 0x20 */
  __IO uint32_t CNT;           /*!< GPTIM Counter Register,       	            Address offset: 0x24 */
  __IO uint32_t PSC;           /*!< GPTIM Prescaler Register,       	          Address offset: 0x28 */
  __IO uint32_t ARR;           /*!< GPTIM Auto-Reload Register,       	        Address offset: 0x2C */
  __IO uint32_t RSV0;          /*!< RESERVED REGISTER0,       	                Address offset: 0x30 */
  __IO uint32_t CCR1;          /*!< GPTIM Capture/Compare Register1,       	    Address offset: 0x34 */
  __IO uint32_t CCR2;          /*!< GPTIM Capture/Compare Register2,       	    Address offset: 0x38 */
  __IO uint32_t CCR3;          /*!< GPTIM Capture/Compare Register3,       	    Address offset: 0x3C */
  __IO uint32_t CCR4;          /*!< GPTIM Capture/Compare Register4,       	    Address offset: 0x40 */
  __IO uint32_t RSV1;          /*!< RESERVED REGISTER1,       	                Address offset: 0x44 */
  __IO uint32_t DCR;           /*!< GPTIM DMA CONTROL REGISTER,       	        Address offset: 0x48 */
  __IO uint32_t DMAR;          /*!< GPTIM DMA access Register,       	          Address offset: 0x4C */
  __IO uint32_t RSV2;          /*!< RESERVED REGISTER2,       	                Address offset: 0x50 */
  __IO uint32_t RSV3;          /*!< RESERVED REGISTER3,       	                Address offset: 0x54 */
  __IO uint32_t RSV4;          /*!< RESERVED REGISTER4,       	                Address offset: 0x58 */
  __IO uint32_t RSV5;          /*!< RESERVED REGISTER5,       	                Address offset: 0x5C */
  __IO uint32_t ITRSEL;        /*!< GPTIM  Internal Trigger Select Register,    Address offset: 0x60 */
} GPTIM_Type;

/* ================================================================================ */
/* ================                      BSTIM                     ================ */
/* ================================================================================ */
typedef struct
{
  __IO uint32_t CR1;   				 /*!< BSTIM Control Register1,       	          Address offset: 0x00 */
  __IO uint32_t CR2;	         /*!< BSTIM Control Register2,       	          Address offset: 0x04 */
  __IO uint32_t RSV0;	         /*!< RESERVED REGISTER0,       	              Address offset: 0x08 */
  __IO uint32_t IER;           /*!< BSTIM Interrupt Enable Register,          Address offset: 0x0C */
  __IO uint32_t ISR;           /*!< BSTIM Interrupt Status Register,       	  Address offset: 0x10 */
  __IO uint32_t EGR;           /*!< BSTIM Event Generation Register,          Address offset: 0x14 */
  __IO uint32_t RSV1;          /*!< RESERVED REGISTER1,       	              Address offset: 0x18 */
  __IO uint32_t RSV2;          /*!< RESERVED REGISTER2,       	              Address offset: 0x1C */
  __IO uint32_t RSV3;          /*!< RESERVED REGISTER3,       	              Address offset: 0x20 */
  __IO uint32_t CNT;           /*!< BSTIM Counter Register,       	          Address offset: 0x24 */
  __IO uint32_t PSC;           /*!< BSTIM Prescaler Register,       	        Address offset: 0x28 */
  __IO uint32_t ARR;           /*!< BSTIM Auto-Reload Register,       	      Address offset: 0x2C */
} BSTIM_Type;

/* ================================================================================ */
/* ================                      I2C                       ================ */
/* ================================================================================ */
typedef struct
{
  __IO uint32_t MSP_CFGR;   			/*!< I2C Master Config Register,       			   Address offset: 0x00 */
  __IO uint32_t MSP_CR;   				/*!< I2C Master Control Register, 					   Address offset: 0x04 */
  __IO uint32_t MSP_IER;  				/*!< I2C Master Intterupt Enable Register,	   Address offset: 0x08 */
	__IO uint32_t MSP_ISR;					/*!< I2C Master Interrupt Status Register,     Address offset: 0x0C */
	__IO uint32_t MSP_SR;						/*!< I2C Master Status Register,			  		   Address offset: 0x10 */
	__IO uint32_t MSP_BGR;					/*!< I2C Master Baud rate Generator Register,	 Address offset: 0x14 */
	__IO uint32_t MSP_BUF;					/*!< I2C Master transfer Buffer,			    		 Address offset: 0x18 */
	__IO uint32_t MSP_TCR;				  /*!< I2C Master Timing Control Register,		   Address offset: 0x1C */	
	__IO uint32_t MSP_TOR;					/*!< I2C Master Time-Out Register,	           Address offset: 0x20 */	
	__IO uint32_t SSP_CR;						/*!< I2C Slave Control Register,						   Address offset: 0x24 */		
	__IO uint32_t SSP_IER;					/*!< I2C Slave Interrupt Enable Register,		   Address offset: 0x28 */		
	__IO uint32_t SSP_ISR;					/*!< I2C Slave Interrupt Status Register,			 Address offset: 0x2C */		
	__IO uint32_t SSP_SR;						/*!< I2C Slave Status Register,							   Address offset: 0x30 */	
	__IO uint32_t SSP_BUF;					/*!< I2C Slave transfer Buffer,							   Address offset: 0x34 */
	__IO uint32_t SSP_ADR;					/*!< I2C Slave Address Register,						   Address offset: 0x38 */		
  
} I2C_Type;

	
/* ================================================================================ */
/* ================                      SVD                      ================ */
/* ================================================================================ */
typedef struct
{
  __IO uint32_t CFGR;						/*!< SVD Config Register,	 					           Address offset: 0x24 */
	__IO uint32_t CR;						  /*!< SVD Control Register,			 			         Address offset: 0x28 */
	__IO uint32_t IER;						/*!< SVD Interrupt Enable Register,		         Address offset: 0x2C */
  __IO uint32_t ISR;	          /*!< SVD Interrupt Status Register,	           Address offset: 0x30 */
  __IO uint32_t VSR;	          /*!< SVD reference Voltage Select Register,		 Address offset: 0x34 */
} SVD_Type;

/* ================================================================================ */
/* ================                      OPA                      ================ */
/* ================================================================================ */
typedef struct
{
  __IO uint32_t CR;						  /*!< OPA Control Register 				   */
	__IO uint32_t CALR;						/*!< OPA Calibration Register			   */
	__IO uint32_t IER;						/*!< OPA Interrupt Enable Register   */
  __IO uint32_t ISR;	          /*!< OPA Interrupt Status Register   */
} OPA_Type;

/* ================================================================================ */
/* ================                     ADC                        ================ */
/* ================================================================================ */
typedef struct
{
  __IO uint32_t ISR;   				 /*!< ADC Interrupt and Status Register,       Address offset: 0x00 */
  __IO uint32_t IER;           /*!< ADC Interrupt Enable Register,       		 Address offset: 0x04 */
  __IO uint32_t CR;            /*!< ADC Control Register,       			       Address offset: 0x08 */
  __IO uint32_t CFGR;          /*!< ADC Config Register,       			         Address offset: 0x0C */
  __IO uint32_t SMTR;          /*!< ADC Sampling Time Register,       			 Address offset: 0x10 */
  __IO uint32_t CHER;          /*!< ADC Channel Enable Register,       			 Address offset: 0x14 */
  __IO uint32_t DR;            /*!< ADC Data Register,       			           Address offset: 0x18 */
  __IO uint32_t CAL;           /*!< ADC Calibration Register,       			    Address offset: 0x1C */
  __IO uint32_t HLTR;          /*!< ADC analog watchdog Threshold Register,   Address offset: 0x20 */
} ADC_Type;

/* ================================================================================ */
/* ================                      CRC                       ================ */
/* ================================================================================ */
typedef struct
{
  __IO uint32_t DR;   					 /*!< CRC Data Register,       					    Address offset: 0x00 */
  __IO uint32_t CR;   				   /*!< CRC Control Register, 			          Address offset: 0x04 */
  __IO uint32_t LFSR;  				   /*!< CRC Linear Feedback Shift Register,  	Address offset: 0x08 */
	__IO uint32_t XOR;					   /*!< CRC output XOR Register,      				Address offset: 0x0C */
	__IO uint32_t FLS_CR;					 /*!< CRC Flash checksum Control Register,	Address offset: 0x10 */
	__IO uint32_t FLS_AD;					 /*!< CRC Flash checksum Address Register,	Address offset: 0x14 */
	__IO uint32_t FLS_SIZE;				 /*!< CRC Flash checksum Size Register,			Address offset: 0x18 */
	__IO uint32_t POLY;					   /*!< CRC Polynominal Register,					    Address offset: 0x1C */
  
} CRC_Type;

/* ================================================================================ */
/* ================                      U7816                     ================ */
/* ================================================================================ */
typedef struct
{
  __IO uint32_t CR;   					/*!< U7816 Control Register,              Address offset: 0x00 */
  __IO uint32_t FFR;            /*!< U7816 Frame Format Register,         Address offset: 0x04 */
  __IO uint32_t EGTR;           /*!< U7816 Extra Guard Time Register,     Address offset: 0x08 */
  __IO uint32_t PSC;            /*!< U7816 Prescaler Register,            Address offset: 0x0C */
  __IO uint32_t BGR;            /*!< U7816 Baud rate Generator Register,  Address offset: 0x10 */
  __IO uint32_t RXBUF;          /*!< U7816 Receive Buffer,                Address offset: 0x14 */
  __IO uint32_t TXBUF;          /*!< U7816 Transmit Buffer,               Address offset: 0x18 */
  __IO uint32_t IER;            /*!< U7816 Interrupt Enable Register,     Address offset: 0x1C */
  __IO uint32_t ISR;            /*!< U7816 Interrupt Status Register,     Address offset: 0x20 */
  
} U7816_Type;

/* ================================================================================ */
/* ================                      LPTIM                     ================ */
/* ================================================================================ */
typedef struct
{
  __IO uint32_t CFGR;   					  /*!< LPTIM Config Register,   	                         Address offset: 0x00*/
  __IO uint32_t CNT;   					    /*!< LPTIM Counter Register, 	                           Address offset: 0x04*/
  __IO uint32_t CCSR;  				      /*!< LPTIM Capture/Compare Control and Status Register,  Address offset: 0x08*/
	__IO uint32_t ARR;					      /*!< LPTIM Auto-Reload Register,                         Address offset: 0x0C*/
	__IO uint32_t IER;					      /*!< LPTIM Interrupt Enable Register,                    Address offset: 0x10*/
	__IO uint32_t ISR;					      /*!< LPTIM Interrupt Status Register,	 		 	             Address offset: 0x14*/
	__IO uint32_t CR;				          /*!< LPTIM Control Register,			                       Address offset: 0x18*/	
  __IO uint32_t RSV;                /*!< RESERVED REGISTER,                                  Address offset: 0x1C*/
  __IO uint32_t CCR1;               /*!< LPTIM Capture/Compare Register1,   	               Address offset: 0x20*/
  __IO uint32_t CCR2;               /*!< LPTIM Capture/Compare Register2,   	               Address offset: 0x24*/
  
} LPTIM_Type;

/* ================================================================================ */
/* ================                      BEEP                      ================ */
/* ================================================================================ */
typedef struct
{
  __IO uint32_t CSR;   					  /*!< BEEP Control Status Register,   	Address offset: 0x00*/
  
} BEEP_Type;

/* ================================================================================ */
/* ================                      LPUART                    ================ */
/* ================================================================================ */
typedef struct
{
  __IO uint32_t CSR;   					 /*!< LPUART Control Status Register,   	      Address offset: 0x00*/
  __IO uint32_t IER;   					 /*!< LPUART Interrupt Enable Register, 	      Address offset: 0x04*/
  __IO uint32_t ISR;  				   /*!< LPUART Interrupt Status Register,  	      Address offset: 0x08*/
	__IO uint32_t BMR;					   /*!< LPUART Baud rate Modulation Register,     Address offset: 0x0C*/
	__IO uint32_t RXBUF;					 /*!< LPUART Receive Buffer Register,           Address offset: 0x10*/
	__IO uint32_t TXBUF;					 /*!< LPUART Transmit Buffer Register,	 		 	  Address offset: 0x14*/
	__IO uint32_t DMR;				     /*!< LPUART  data Matching Register,			      Address offset: 0x18*/	
  
} LPUART_Type;

/* ================================================================================ */
/* ================                      LCD                     ================ */
/* ================================================================================ */
typedef struct
{
  __IO uint32_t CR;   			      /*!< LCD Control Register,    					Address offset: 0x00 */
  __IO uint32_t TEST;   				  /*!< LCD test Register, 				        Address offset: 0x04 */
  __IO uint32_t FCR;  					  /*!< LCD Frequency Control Register,    Address offset: 0x08 */
	__IO uint32_t FLKT;						  /*!< LCD Flick Time Register,      		  Address offset: 0x0C */  
	__IO uint32_t REV1;							/*!< NULL,															Address offset: 0x10 */
	__IO uint32_t IER;						  /*!< LCD Interrupt Enable Register,	 	  Address offset: 0x14 */
	__IO uint32_t ISR;						  /*!< LCD Interrupt Status Register,			Address offset: 0x18 */
	__IO uint32_t REV2;						  /*!< NULL,                							Address offset: 0x1C */	
	__IO uint32_t REV3;						  /*!< NULL,															Address offset: 0x20 */	
	__IO uint32_t DATA0;				    /*!< LCD data buffer registers 0,				Address offset: 0x24 */	
	__IO uint32_t DATA1;				    /*!< LCD data buffer registers 1,				Address offset: 0x28 */
	__IO uint32_t DATA2;				    /*!< LCD data buffer registers 2,				Address offset: 0x2C */
	__IO uint32_t DATA3;				    /*!< LCD data buffer registers 3,			  Address offset: 0x30 */
	__IO uint32_t DATA4;				    /*!< LCD data buffer registers 4,				Address offset: 0x34 */
	__IO uint32_t DATA5;				    /*!< LCD data buffer registers 5,				Address offset: 0x38 */
	__IO uint32_t DATA6;				    /*!< LCD data buffer registers 6,			  Address offset: 0x3C */
	__IO uint32_t DATA7;				    /*!< LCD data buffer registers 7,				Address offset: 0x40 */
	__IO uint32_t REV4;				      /*!< NULL,															Address offset: 0x44 */
	__IO uint32_t REV5;				      /*!< NULL,															Address offset: 0x48 */
	__IO uint32_t REV6;					    /*!< NULL,															Address offset: 0x4C */
	__IO uint32_t COM_EN;						/*!< LCD COM Enable Register,					  Address offset: 0x50 */
	__IO uint32_t SEG_EN0;					/*!< LCD SEG Enable Register0,					Address offset: 0x54 */
	
} LCD_Type;

/* ================================================================================ */
/* ================                      RTC                       ================ */
/* ================================================================================ */
typedef struct
{
  __IO uint32_t WER;   					/*!< RTC Write Enable Register,    		Address offset: 0x00 */
  __IO uint32_t IER;   					/*!< RTC Interrupt Enable Register, 	Address offset: 0x04 */
  __IO uint32_t ISR;  					/*!< RTC Interrupt Status Register,  	Address offset: 0x08 */
	__IO uint32_t BCDSEC;					/*!< RTC SECOND IN BCD REGISTER,      Address offset: 0x0C */
	__IO uint32_t BCDMIN;					/*!< RTC MINITE IN BCD REGISTER,			Address offset: 0x10 */
	__IO uint32_t BCDHOUR;				/*!< RTC HOUR IN BCD REGISTER,	 			Address offset: 0x14 */
	__IO uint32_t BCDDAY;					/*!< RTC DAY IN BCD REGISTER,					Address offset: 0x18 */
	__IO uint32_t BCDWEEK;				/*!< RTC WEEK IN BCD REGISTER,				Address offset: 0x1C */	
	__IO uint32_t BCDMONTH;				/*!< RTC MONTH IN BCD REGISTER,				Address offset: 0x20 */	
	__IO uint32_t BCDYEAR;				/*!< RTC YEAR IN BCD REGISTER,				Address offset: 0x24 */	
	__IO uint32_t ALARM;					/*!< RTC Alarm Register,				      Address offset: 0x28 */
	__IO uint32_t TMSEL;					/*!< RTC Time Mark Select,				    Address offset: 0x2C */
	__IO uint32_t ADJUST;					/*!< RTC time Adjust Register,				Address offset: 0x30 */
	__IO uint32_t ADSIGN;					/*!< RTC time Adjust Sign Register,		Address offset: 0x34 */
	__IO uint32_t REV1;					  /*!< NULL,			 											Address offset: 0x38 */
	__IO uint32_t SBSCNT;					/*!< RTC Sub-Second Counter,					Address offset: 0x3C */
  __IO uint32_t RSV[12];        /*!< NULL,			 											Address offset: 0x40 */
  __IO uint32_t BKR0;           /*!< RTC BACKUP REGISTER0,						Address offset: 0x70 */
  __IO uint32_t BKR1;           /*!< RTC BACKUP REGISTER1,						Address offset: 0x74 */
  __IO uint32_t BKR2;           /*!< RTC BACKUP REGISTER2,						Address offset: 0x78 */
  __IO uint32_t BKR3;           /*!< RTC BACKUP REGISTER3,						Address offset: 0x7C */
  __IO uint32_t BKR4;           /*!< RTC BACKUP REGISTER4,						Address offset: 0x80 */
  __IO uint32_t BKR5;           /*!< RTC BACKUP REGISTER5,						Address offset: 0x84 */
  __IO uint32_t BKR6;           /*!< RTC BACKUP REGISTER6,						Address offset: 0x88 */
  __IO uint32_t BKR7;           /*!< RTC BACKUP REGISTER7,						Address offset: 0x8C */
  
} RTC_Type;

/* ================================================================================ */
/* ================                      AES                       ================ */
/* ================================================================================ */
typedef struct
{
  __IO uint32_t CR;   					/*!< AES Control Register,    					Address offset: 0x00 */
  __IO uint32_t IER;            /*!< AES Interrupt Enable Register,    	Address offset: 0x04 */
  __IO uint32_t ISR;   					/*!< AES Interrupt Status Register, 		Address offset: 0x08 */
  __IO uint32_t DIR;  					/*!< AES Data Input Register,  					Address offset: 0x0C */
	__IO uint32_t DOR;					  /*!< AES Data Output Register,      		Address offset: 0x10 */
	__IO uint32_t KEY0;					  /*!< AES Key Register 0,				        Address offset: 0x14 */
	__IO uint32_t KEY1;					  /*!< AES Key Register 1,	 							Address offset: 0x18 */
	__IO uint32_t KEY2;					  /*!< AES Key Register 2,								Address offset: 0x1C */
	__IO uint32_t KEY3;					  /*!< AES Key Register 3,								Address offset: 0x20 */	
	__IO uint32_t KEY4;					  /*!< AES Key Register 4,								Address offset: 0x24 */	
	__IO uint32_t KEY5;					  /*!< AES Key Register 5,								Address offset: 0x28 */	
	__IO uint32_t KEY6;					  /*!< AES Key Register 6,								Address offset: 0x2C */
	__IO uint32_t KEY7;					  /*!< AES Key Register 7,								Address offset: 0x30 */
	__IO uint32_t IVR0;					  /*!< AES Initial Vector Register 0,			Address offset: 0x34 */
	__IO uint32_t IVR1;					  /*!< AES Initial Vector Register 1,			Address offset: 0x38 */
	__IO uint32_t IVR2;					  /*!< AES Initial Vector Register 2,			Address offset: 0x3C */
	__IO uint32_t IVR3;					  /*!< AES Initial Vector Register 3,			Address offset: 0x40 */
  
} AES_Type;

/* ================================================================================ */
/* ================                      WWDT                      ================ */
/* ================================================================================ */
typedef struct
{
  __IO uint32_t CR;   				/*!< WWDT Control Register,    						Address offset: 0x00 */
  __IO uint32_t CFGR;   			/*!< WWDT Config Register, 								Address offset: 0x04 */
  __IO uint32_t CNT;  				/*!< WWDT Counter Register,  							Address offset: 0x08 */
	__IO uint32_t IER;					/*!<WWDT Interrupt Enable Register,       Address offset: 0x0C */
	__IO uint32_t ISR;					/*!< WWDT Interrupt Status Register,			Address offset: 0x10 */
	__IO uint32_t PSC;					/*!< WWDT Prescaler Register,             Address offset: 0x14 */	
  
} WWDT_Type;

/* ================================================================================ */
/* ================                      RNG                      ================ */
/* ================================================================================ */
typedef struct
{
__IO uint32_t CR;          /*!< RNG CONTROL REGISTER,    					 */
} RNG_CR_Type;

typedef struct
{
  __IO uint32_t RSV0;   				  /*!< RESERVED REGISTER,    				        Address offset: 0x00 */
  __IO uint32_t DOR;   				/*!< RNG OUTPUT REGISTER, 								Address offset: 0x04 */
  __IO uint32_t RSV1;  				    /*!< RESERVED REGISTER,  				          Address offset: 0x08 */
  __IO uint32_t RSV2;             /*!< RESERVED REGISTER,  				          Address offset: 0x0C */
	__IO uint32_t SR;						/*!< RNG FLAG REGISTER,                  Address offset: 0x10 */	
	__IO uint32_t CRC_CR;						/*!< RNG CRC CONTROL REGISTER,						Address offset: 0x14 */	
	__IO uint32_t CRC_DIR;						/*!< RNG CRC INPUT REGISTER,							Address offset: 0x18 */	
	__IO uint32_t CRC_SR;						/*!< RNG CRC FLAG REGISTER,							Address offset: 0x1C */		
} RNG_Type;

/* --------------------  End of section using anonymous unions  ------------------- */
#if defined(__CC_ARM)
  #pragma pop
#elif defined(__ICCARM__)
  /* leave anonymous unions enabled */
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning restore
#else
  #warning Not supported compiler type
#endif

/* ================================================================================ */
/* ================              CPU memory map                    ================ */
/* ================================================================================ */

/* Peripheral and SRAM base address */

#define FLASH_BASE            ((     uint32_t)0x00000000)
#define SRAM_BASE             ((     uint32_t)0x20000000)
#define PERIPH_BASE           ((     uint32_t)0x40000000)

/* ================================================================================ */
/* ================              Peripheral memory map             ================ */
/* ================================================================================ */

/* Peripheral memory map */

#define DBG_BASE						(PERIPH_BASE				+0x00000000)
#define PMU_BASE				    (PERIPH_BASE				+0x00000100)
#define RCC_BASE				    (PERIPH_BASE				+0x00000200)
#define DMA_BASE						(PERIPH_BASE				+0x00000400)
#define GPIOA_BASE  				(PERIPH_BASE				+0x00000C00)
#define GPIOB_BASE					(PERIPH_BASE				+0x00000C40)
#define GPIOC_BASE					(PERIPH_BASE				+0x00000C80)
#define GPIOD_BASE  				(PERIPH_BASE				+0x00000CC0)
#define GPIO_COMMON_BASE		(PERIPH_BASE				+0x00000D00)
#define FLS_BASE					  (PERIPH_BASE				+0x00001000)
#define CRC_BASE						(PERIPH_BASE				+0x00010000)	
#define LPUART0_BASE				(PERIPH_BASE				+0x00010400)
#define LPUART1_BASE				(PERIPH_BASE				+0x00010420)
#define SPI1_BASE						(PERIPH_BASE				+0x00010840)
#define SPI2_BASE						(PERIPH_BASE				+0x00010880)
#define LCD_BASE						(PERIPH_BASE				+0x00010C00)	
#define RTC_BASE						(PERIPH_BASE				+0x00011000)
#define IWDT_BASE						(PERIPH_BASE				+0x00011400)	
#define WWDT_BASE						(PERIPH_BASE				+0x00011800)
#define U7816_BASE					(PERIPH_BASE				+0x00011C00)
#define UART_COMMON_BASE		(PERIPH_BASE				+0x00012008)
#define UART0_BASE					(PERIPH_BASE				+0x0001200C)
#define UART1_BASE					(PERIPH_BASE				+0x0001202C)		
#define UART4_BASE					(PERIPH_BASE				+0x0001208C)	
#define UART5_BASE					(PERIPH_BASE				+0x000120AC)	
#define I2C_BASE						(PERIPH_BASE				+0x00012400)
#define RCC_PDR_BASE		    (PERIPH_BASE				+0x00012800)
#define RCC_BOR_BASE		    (PERIPH_BASE				+0x00012804)
#define PMU_VREF_BASE				(PERIPH_BASE				+0x0001280C)
#define PMU_BUF_BASE				(PERIPH_BASE				+0x00012818)
#define SVD_BASE						(PERIPH_BASE				+0x00012824)
#define RCC_FDET_BASE		    (PERIPH_BASE				+0x00012838)
#define OPA1_BASE						(PERIPH_BASE				+0x00012844)
#define OPA2_BASE						(PERIPH_BASE				+0x00012854)
#define RNG_CR_BASE			    (PERIPH_BASE				+0x00012864)
#define LPTIM_BASE					(PERIPH_BASE				+0x00013400)
#define AES_BASE						(PERIPH_BASE				+0x00013800)
#define RNG_BASE						(PERIPH_BASE				+0x00013C00)
#define ATIM_BASE				    (PERIPH_BASE				+0x00014000)
#define GPTIM0_BASE				  (PERIPH_BASE				+0x00014400)
#define GPTIM1_BASE				  (PERIPH_BASE				+0x00014800)
#define BSTIM_BASE				  (PERIPH_BASE				+0x00014C00)
#define ADC_BASE						(PERIPH_BASE				+0x00015000)
#define BEEP_BASE						(PERIPH_BASE				+0x00015400)

/* ================================================================================ */
/* ================             Peripheral declaration             ================ */
/* ================================================================================ */

#define DBG															((DBG_Type             		*) DBG_BASE					)
#define PMU															((PMU_Type             		*) PMU_BASE					)
#define PMU_VREF												((PMU_VREF_Type           *) PMU_VREF_BASE		)
#define PMU_BUF													((PMU_BUF_Type            *) PMU_BUF_BASE			)
#define RCC													    ((RCC_Type                *) RCC_BASE			    )
#define RCC_PDR											    ((RCC_PDR_Type            *) RCC_PDR_BASE	    )
#define RCC_BOR											    ((RCC_BOR_Type            *) RCC_BOR_BASE	    )
#define DMA															((DMA_Type             		*) DMA_BASE					)
#define GPIOA														((GPIO_Type         			*) GPIOA_BASE				)
#define GPIOB														((GPIO_Type         			*) GPIOB_BASE				)
#define GPIOC														((GPIO_Type         			*) GPIOC_BASE				)
#define GPIOD														((GPIO_Type         			*) GPIOD_BASE				)
#define GPIO_COMMON      								((GPIO_COMMON_Type   			*) GPIO_COMMON_BASE	)
#define FLS														  ((FLS_Type           		  *) FLS_BASE				)
#define CRC															((CRC_Type        				*) CRC_BASE					)
#define LPUART0                         ((LPUART_Type             *) LPUART0_BASE			)
#define LPUART1                         ((LPUART_Type             *) LPUART1_BASE			)
#define SPI1														((SPI_Type            		*) SPI1_BASE				)
#define SPI2														((SPI_Type            		*) SPI2_BASE				)
#define LCD														  ((LCD_Type        				*) LCD_BASE				)
#define RTC															((RTC_Type        				*) RTC_BASE					)
#define IWDT														((IWDT_Type               *) IWDT_BASE				)
#define WWDT														((WWDT_Type               *) WWDT_BASE				)
#define U7816													  ((U7816_Type        			*) U7816_BASE			  )
#define UART_COMMON                     ((UART_COMMON_Type        *) UART_COMMON_BASE	)
#define UART0                           ((UART_Type               *) UART0_BASE				)
#define UART1                           ((UART_Type               *) UART1_BASE				)
#define UART4                           ((UART_Type               *) UART4_BASE				)
#define UART5                           ((UART_Type               *) UART5_BASE				)
#define I2C															((I2C_Type         				*) I2C_BASE					)
#define RCC_FDET										    ((RCC_FDET_Type           *) RCC_FDET_BASE		)
#define SVD														  ((SVD_Type        				*) SVD_BASE				  )
#define OPA1														((OPA_Type        				*) OPA1_BASE				)
#define OPA2														((OPA_Type        				*) OPA2_BASE				)
#define LPTIM													  ((LPTIM_Type        			*) LPTIM_BASE			  )
#define AES                          	  ((AES_Type              	*) AES_BASE					)
#define RNG														  ((RNG_Type        				*) RNG_BASE				)
#define RNG_CR											    ((RNG_CR_Type        	    *) RNG_CR_BASE	)
#define ATIM													  ((ATIM_Type         		  *) ATIM_BASE			  )
#define GPTIM0													((GPTIM_Type         	    *) GPTIM0_BASE			  )
#define GPTIM1													((GPTIM_Type         		  *) GPTIM1_BASE			  )
#define BSTIM													  ((BSTIM_Type         		  *) BSTIM_BASE			  )
#define ADC														  ((ADC_Type        				*) ADC_BASE				  )
#define BEEP														((BEEP_Type        				*) BEEP_BASE				)

/* ================================================================================ */
/* ================             Peripheral include                 ================ */
/* ================================================================================ */

/** @} */ /* End of group Device_Peripheral_Registers */
/** @} */ /* End of group FM33L0XX */
/** @} */ /* End of group Keil */

#ifdef __cplusplus
}
#endif

#endif  /* FM33L0XX_H */
