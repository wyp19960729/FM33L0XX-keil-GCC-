/**
  ******************************************************************************
  * @file    fm33l0xx_tim.h
  * @author  FM33L0xx Application Team
  * @version V1.0.0
  * @date    20-SETP-2018
  * @brief   This file contains all the functions prototypes for the TIM firmware library.  
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __FM33L0XX_TIM_H
#define __FM33L0XX_TIM_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "FM33L0XX.h"
/** @addtogroup FM33L0xx_StdPeriph_Driver
  * @{
  */

/** @addtogroup TIM
  * @{
  */
	 
/* Exported types ------------------------------------------------------------*/

#define TIM_Channel_1                      ((uint16_t)0x0000)
#define TIM_Channel_2                      ((uint16_t)0x0001)
#define TIM_Channel_3                      ((uint16_t)0x0002)
#define TIM_Channel_4                      ((uint16_t)0x0003)

#define TIM_CCx_Enable                      ((uint16_t)0x0001)
#define TIM_CCx_Disable                     ((uint16_t)0x0000)

#define TIM_CCxN_Enable                     ((uint16_t)0x0004)
#define TIM_CCxN_Disable                    ((uint16_t)0x0000)

#define CCER_CCE_Set                        ((uint16_t)0x0001)  
#define	CCER_CCNE_Set                       ((uint16_t)0x0004) 

#define TIM_IT_Update                      ((uint16_t)0x0001)
#define TIM_IT_CC1                         ((uint16_t)0x0002)
#define TIM_IT_CC2                         ((uint16_t)0x0004)
#define TIM_IT_CC3                         ((uint16_t)0x0008)
#define TIM_IT_CC4                         ((uint16_t)0x0010)
#define TIM_IT_COM                         ((uint16_t)0x0020)
#define TIM_IT_Trigger                     ((uint16_t)0x0040)
#define TIM_IT_Break                       ((uint16_t)0x0080)

typedef struct
{
  uint32_t TIM_Prescaler;         	//TIM_PSC
  uint32_t TIM_CounterMode;     		//TIM_CR1_DIR| TIM_CR1_CMS
  uint32_t TIM_Period;   						//TIM_ARR         
  uint32_t TIM_ClockDivision;    		//TIM_CR1_CKD
  uint32_t TIM_RepetitionCounter; 	//TIM_RCR
} TIM_TimeBaseInitTypeDef; 

typedef struct
{
  uint32_t TIM_OCMode;        /*!< Specifies the TIM mode.
                                   This parameter can be a value of @ref TIM_Output_Compare_and_PWM_modes */

  uint32_t TIM_OutputState;   /*!< Specifies the TIM Output Compare state.
                                   This parameter can be a value of @ref TIM_Output_Compare_state */

  uint32_t TIM_OutputNState;  /*!< Specifies the TIM complementary Output Compare state.
                                   This parameter can be a value of @ref TIM_Output_Compare_N_state
                                   @note This parameter is valid only for TIM1 and TIM8. */

  uint32_t TIM_Pulse;         /*!< Specifies the pulse value to be loaded into the Capture Compare Register. 
                                   This parameter can be a number between 0x0000 and 0xFFFF */

  uint32_t TIM_OCPolarity;    /*!< Specifies the output polarity.
                                   This parameter can be a value of @ref TIM_Output_Compare_Polarity */

  uint32_t TIM_OCNPolarity;   /*!< Specifies the complementary output polarity.
                                   This parameter can be a value of @ref TIM_Output_Compare_N_Polarity
                                   @note This parameter is valid only for TIM1 and TIM8. */

  uint32_t TIM_OCIdleState;   /*!< Specifies the TIM Output Compare pin state during Idle state.
                                   This parameter can be a value of @ref TIM_Output_Compare_Idle_State
                                   @note This parameter is valid only for TIM1 and TIM8. */

  uint32_t TIM_OCNIdleState;  /*!< Specifies the TIM Output Compare pin state during Idle state.
                                   This parameter can be a value of @ref TIM_Output_Compare_N_Idle_State
                                   @note This parameter is valid only for TIM1 and TIM8. */
} TIM_OCInitTypeDef;

typedef struct
{

  uint32_t TIM_OSSRState;        /*!< Specifies the Off-State selection used in Run mode.
                                      This parameter can be a value of @ref OSSR_Off_State_Selection_for_Run_mode_state */

  uint32_t TIM_OSSIState;        /*!< Specifies the Off-State used in Idle state.
                                      This parameter can be a value of @ref OSSI_Off_State_Selection_for_Idle_mode_state */

  uint32_t TIM_LOCKLevel;        /*!< Specifies the LOCK level parameters.
                                      This parameter can be a value of @ref Lock_level */ 

  uint32_t TIM_DeadTime;         /*!< Specifies the delay time between the switching-off and the
                                      switching-on of the outputs.
                                      This parameter can be a number between 0x00 and 0xFF  */

  uint32_t TIM_Break;            /*!< Specifies whether the TIM Break input is enabled or not. 
                                      This parameter can be a value of @ref Break_Input_enable_disable */

  uint32_t TIM_BreakPolarity;    /*!< Specifies the TIM Break Input pin polarity.
                                      This parameter can be a value of @ref Break_Polarity */

  uint32_t TIM_AutomaticOutput;  /*!< Specifies whether the TIM Automatic Output feature is enabled or not. 
                                      This parameter can be a value of @ref TIM_AOE_Bit_Set_Reset */
} TIM_BDTRInitTypeDef;

typedef struct
{

  uint32_t TIM_Channel;      /*!< Specifies the TIM channel.
                                  This parameter can be a value of @ref TIM_Channel */

  uint32_t TIM_ICPolarity;   /*!< Specifies the active edge of the input signal.
                                  This parameter can be a value of @ref TIM_Input_Capture_Polarity */

  uint32_t TIM_ICSelection;  /*!< Specifies the input.
                                  This parameter can be a value of @ref TIM_Input_Capture_Selection */

  uint32_t TIM_ICPrescaler;  /*!< Specifies the Input Capture Prescaler.
                                  This parameter can be a value of @ref TIM_Input_Capture_Prescaler */

  uint32_t TIM_ICFilter;     /*!< Specifies the input capture filter.
                                  This parameter can be a number between 0x0 and 0xF */
} TIM_ICInitTypeDef;
/**
* @}TIM_CR1
*/ 
  

/** @defgroup TIM_CR1_CEN
  * @{
  */
#define TIM_CR1_CEN_Pos		               						0                                             
#define TIM_CR1_CEN_Msk               				  			(0x01UL << TIM_CR1_CEN_Pos)  
#define TIM_CR1_CEN_ENABLE     				        			((uint32_t)0x00000001)
#define TIM_CR1_CEN_DISABLE    				        			((uint32_t)0x00000000) 

/** @defgroup TIM_CR1_UDIS
  * @{
  */
#define TIM_CR1_UDIS_Pos		               						1                                             
#define TIM_CR1_UDIS_Msk               				  		(0x01UL << TIM_CR1_UDIS_Pos)  
#define TIM_CR1_UDIS_DIS_UPDATE  			        			((uint32_t)0x00000002)
#define TIM_CR1_UDIS_EN_UPDATE  			        			((uint32_t)0x00000000) 

/** @defgroup TIM_CR1_URS
  * @{
  */
#define TIM_CR1_URS_Pos		       	       						2                                             
#define TIM_CR1_URS_Msk              				  			(0x01UL << TIM_CR1_URS_Pos)  
#define TIM_CR1_URS_OVER     				        				((uint32_t)0x00000004)
#define TIM_CR1_URS_ALL	    				        				((uint32_t)0x00000000) 

/** @defgroup TIM_CR1_OPM
  * @{
  */
#define TIM_CR1_OPM_Pos		       		       						3                                             
#define TIM_CR1_OPM_Msk               				  			(0x01UL << TIM_CR1_OPM_Pos)  
#define TIM_CR1_OPM_ENABLE     				        				((uint32_t)0x00000008)
#define TIM_CR1_OPM_DISABLE	   				        				((uint32_t)0x00000000) 

/** @defgroup TIM_CR1_DIR
  * @{
  */
#define TIM_CR1_DIR_Pos		               						4                                             
#define TIM_CR1_DIR_Msk               				  			(0x01UL << TIM_CR1_DIR_Pos)  
#define TIM_CR1_DIR_DOWN     				        				((uint32_t)0x00000010)
#define TIM_CR1_DIR_UP	    				        					((uint32_t)0x00000000) 

/** @defgroup TIM_CR1_CMS
  * @{
  */
#define TIM_CR1_CMS_Pos		               						5                                             
#define TIM_CR1_CMS_Msk               				  			(0x03UL << TIM_CR1_CMS_Pos)  
#define TIM_CR1_CMS_SINGLE     			        				((uint32_t)0x00000000)
#define TIM_CR1_CMS_CENTERALIGNED_DOWN 							((uint32_t)0x00000020) 
#define TIM_CR1_CMS_CENTERALIGNED_UP	       					((uint32_t)0x00000040) 
#define TIM_CR1_CMS_CENTERALIGNED_BOTH		   					((uint32_t)0x00000060) 

/** @defgroup TIM_CR1_ARPE
  * @{
  */
#define TIM_CR1_ARPE_Pos		               						7                                             
#define TIM_CR1_ARPE_Msk               				  		(0x01UL << TIM_CR1_ARPE_Pos)  
#define TIM_CR1_ARPE_PRELOAD 			        					((uint32_t)0x00000080)

/** @defgroup TIM_CR1_CKD
  * @{
  */
#define TIM_CR1_CKD_Pos		               						8                                             
#define TIM_CR1_CKD_Msk               				  			(0x03UL << TIM_CR1_CKD_Pos)  
#define TIM_CR1_CKD_1TINT     			     							((uint32_t)0x00000000)
#define TIM_CR1_CKD_2TINT		     										((uint32_t)0x00000100) 
#define TIM_CR1_CKD_4TINT	 		     									((uint32_t)0x00000200) 



/**
* @}TIM_CR2
*/ 
/** @defgroup TIM_CR2_CCPC
  * @{
  */
#define TIM_CR2_CCPC_Pos		               					0                                             
#define TIM_CR2_CCPC_Msk               							(0x01UL << TIM_CR2_CCPC_Pos)  
#define TIM_CR2_CCPC_ENABLE     				        		((uint32_t)0x00000001)
//#define TIM_CR2_CCPC_DISABLE    				        		((uint32_t)0x00000000)   
	
/** @defgroup TIM_CR2_CCUS
  * @{
  */
#define TIM_CR2_CCUS_Pos		               					2                                             
#define TIM_CR2_CCUS_Msk               							(0x01UL << TIM_CR2_CCUS_Pos)  
#define TIM_CR2_CCUS_COMNTRI     				        		((uint32_t)0x00000004)
#define TIM_CR2_CCUS_COM    				     			   		((uint32_t)0x00000000)   

/** @defgroup TIM_CR2_CCDS
  * @{
  */
#define TIM_CR2_CCDS_Pos		               					3                                             
#define TIM_CR2_CCDS_Msk               							(0x01UL << TIM_CR2_CCDS_Pos)  
#define TIM_CR2_CCDS_CCX		    				        		((uint32_t)0x00000008)
#define TIM_CR2_CCDS_UEV    				     			   		((uint32_t)0x00000000)   

/** @defgroup TIM_CR2_MMS
  * @{
  */
#define TIM_CR2_MMS_Pos		               						4                                             
#define TIM_CR2_MMS_Msk               							(0x07UL << TIM_CR2_MMS_Pos)  
#define TIM_CR2_MMS_UG		   		 				        		((uint32_t)0x00000000)
#define TIM_CR2_MMS_CEN    				     			   			((uint32_t)0x00000010)   
#define TIM_CR2_MMS_UEV    				     			   			((uint32_t)0x00000020)
#define TIM_CR2_MMS_COMP   				     			   			((uint32_t)0x00000030)
#define TIM_CR2_MMS_OC1REF  			     			   			((uint32_t)0x00000040)
#define TIM_CR2_MMS_OC2REF 				     			   			((uint32_t)0x00000050)
#define TIM_CR2_MMS_OC3REF    			   			   			((uint32_t)0x00000060)
#define TIM_CR2_MMS_OC4REF  			     			   			((uint32_t)0x00000070)

/** @defgroup TIM_CR2_T1S
  * @{
  */
#define TIM_CR2_T1S_Pos		               						7                                             
#define TIM_CR2_T1S_Msk               							(0x01UL << TIM_CR2_T1S_Pos)  
#define TIM_CR2_T1S_T123XOR    				        			((uint32_t)0x00000080)
#define TIM_CR2_T1S_T1    				     			   			((uint32_t)0x00000000) 

/** @defgroup TIM_CR2_OIS1
  * @{
  */
#define TIM_CR2_OIS1_Pos		               					8                                             
#define TIM_CR2_OIS1_Msk               							(0x01UL << TIM_CR2_OIS1_Pos)  
#define TIM_CR2_OIS1_RESET    				     					((uint32_t)0x00000000)
#define TIM_CR2_OIS1_SET   				     			   			((uint32_t)0x00000100) 

/** @defgroup TIM_CR2_OIS1N
  * @{
  */
#define TIM_CR2_OIS1N_Pos		               					9                                             
#define TIM_CR2_OIS1N_Msk               						(0x01UL << TIM_CR2_OIS1N_Pos)  
#define TIM_CR2_OIS1N_RESET  				        				((uint32_t)0x00000000)
#define TIM_CR2_OIS1N_SET   				   			   			((uint32_t)0x00000200) 

/** @defgroup TIM_CR2_OIS2
  * @{
  */
#define TIM_CR2_OIS2_Pos		               					10                                             
#define TIM_CR2_OIS2_Msk               							(0x01UL << TIM_CR2_OIS2_Pos)  
#define TIM_CR2_OIS2_RESET 				        					((uint32_t)0x00000000)
#define TIM_CR2_OIS2_SET   				     			   			((uint32_t)0x00000400) 

/** @defgroup TIM_CR2_OIS2N
  * @{
  */
#define TIM_CR2_OIS2N_Pos		               					11                                             
#define TIM_CR2_OIS2N_Msk               						(0x01UL << TIM_CR2_OIS2N_Pos)  
#define TIM_CR2_OIS2N_RESET  				        				((uint32_t)0x00000000)
#define TIM_CR2_OIS2N_SET  				     			   			((uint32_t)0x00000800) 

/** @defgroup TIM_CR2_OIS3
  * @{
  */
#define TIM_CR2_OIS3_Pos		               					12                                             
#define TIM_CR2_OIS3_Msk               							(0x01UL << TIM_CR2_OIS3_Pos)  
#define TIM_CR2_OIS3_RESET 				        					((uint32_t)0x00000000)
#define TIM_CR2_OIS3_SET   				     			   			((uint32_t)0x00001000) 

/** @defgroup TIM_CR2_OIS3N
  * @{
  */
#define TIM_CR2_OIS3N_Pos		               					13                                             
#define TIM_CR2_OIS3N_Msk               						(0x01UL << TIM_CR2_OIS3N_Pos)  
#define TIM_CR2_OIS3N_RESET  				        				((uint32_t)0x00000000)
#define TIM_CR2_OIS3N_SET  				     			   			((uint32_t)0x00002000) 

/** @defgroup TIM_CR2_OIS4
  * @{
  */
#define TIM_CR2_OIS4_Pos		               					14                                             
#define TIM_CR2_OIS4_Msk               							(0x01UL << TIM_CR2_OIS4_Pos)  
#define TIM_CR2_OIS4_RESET 				        					((uint32_t)0x00000000)
#define TIM_CR2_OIS4_SET   				     			   			((uint32_t)0x00004000) 


/**
* @}TIM_SMCR
*/ 	

/** @defgroup TIM_SMCR_SMS
  * @{
  */
#define TIM_SMCR_SMS_Pos		               				0                                             
#define TIM_SMCR_SMS_Msk               						(0x07UL << TIM_SMCR_SMS_Pos)  
#define TIM_SMCR_SMS_INTERNAL     				        ((uint32_t)0x00000000)
#define TIM_SMCR_SMS_ENCODER1    				        	((uint32_t)0x00000001) 
#define TIM_SMCR_SMS_ENCODER2    				        	((uint32_t)0x00000002) 	
#define TIM_SMCR_SMS_ENCODER3    				        	((uint32_t)0x00000003) 	
#define TIM_SMCR_SMS_RESET	    				        	((uint32_t)0x00000004) 	
#define TIM_SMCR_SMS_GATE		    				        	((uint32_t)0x00000005) 	
#define TIM_SMCR_SMS_TRGI		    				        	((uint32_t)0x00000006) 	
#define TIM_SMCR_SMS_EXCLK1	    				        	((uint32_t)0x00000007) 	

/** @defgroup TIM_SMCR_TS
  * @{
  */
#define TIM_SMCR_TS_Pos		               					4                                             
#define TIM_SMCR_TS_Msk               						(0x07UL << TIM_SMCR_TS_Pos)  
#define TIM_SMCR_TS_ITR0     				        			((uint32_t)0x00000000)
#define TIM_SMCR_TS_ITR1    				        			((uint32_t)0x00000010) 
#define TIM_SMCR_TS_ITR2    				     			   	((uint32_t)0x00000020) 	
#define TIM_SMCR_TS_ITR3    				    		    	((uint32_t)0x00000030) 	
#define TIM_SMCR_TS_TI1F_ED	    				        	((uint32_t)0x00000040) 	
#define TIM_SMCR_TS_TI1FP1		    				       	((uint32_t)0x00000050) 	
#define TIM_SMCR_TS_TI2FP2		    			        	((uint32_t)0x00000060) 	
#define TIM_SMCR_TS_ETRF		    				        	((uint32_t)0x00000070) 	

/** @defgroup TIM_SMCR_MSM
  * @{
  */
#define TIM_SMCR_MSM_Pos		               					7                                             
#define TIM_SMCR_MSM_Msk               						(0x01UL << TIM_SMCR_MSM_Pos)  
#define TIM_SMCR_MSM_N0NE     				        		((uint32_t)0x00000000)
#define TIM_SMCR_MSM_MSMODE  				        			((uint32_t)0x00000080) 

/** @defgroup TIM_SMCR_ETF
  * @{
  */
#define TIM_SMCR_ETF_Pos		               					8                           	
#define TIM_SMCR_ETF_Msk               							(0x0FUL << TIM_SMCR_ETF_Pos)  
#define TIM_SMCR_ETF_NONE      						        	((uint32_t)0x00000000) 
#define TIM_SMCR_ETF_FCLK_N2      				        	((uint32_t)0x00000100) 
#define TIM_SMCR_ETF_FCLK_N4     				        		((uint32_t)0x00000200) 
#define TIM_SMCR_ETF_FCLK_N8      				        	((uint32_t)0x00000300) 
#define TIM_SMCR_ETF_FDTS_DIV2N6   				        	((uint32_t)0x00000400)
#define TIM_SMCR_ETF_FDTS_DIV2N8 				        		((uint32_t)0x00000500) 
#define TIM_SMCR_ETF_FDTS_DIV4N6     		        		((uint32_t)0x00000600) 
#define TIM_SMCR_ETF_FDTS_DIV4N8 				        		((uint32_t)0x00000700) 
#define TIM_SMCR_ETF_FDTS_DIV8N6   				        	((uint32_t)0x00000800)
#define TIM_SMCR_ETF_FDTS_DIV8N8 				        		((uint32_t)0x00000900) 
#define TIM_SMCR_ETF_FDTS_DIV16N5     		        	((uint32_t)0x00000A00) 
#define TIM_SMCR_ETF_FDTS_DIV16N6 				        	((uint32_t)0x00000B00) 
#define TIM_SMCR_ETF_FDTS_DIV16N8   				       	((uint32_t)0x00000C00)
#define TIM_SMCR_ETF_FDTS_DIV32N5 				        	((uint32_t)0x00000D00) 
#define TIM_SMCR_ETF_FDTS_DIV32N6     		        	((uint32_t)0x00000E00) 
#define TIM_SMCR_ETF_FDTS_DIV32N8 				        	((uint32_t)0x00000F00) 

/** @defgroup TIM_SMCR_ETPS
  * @{
  */
#define TIM_SMCR_ETPS_Pos		               					12                                             
#define TIM_SMCR_ETPS_Msk               						(0x03UL << TIM_SMCR_ETPS_Pos)  
#define TIM_SMCR_ETPS_NONE			     				        ((uint32_t)0x00000000)
#define TIM_SMCR_ETPS_PER2      				        		((uint32_t)0x00001000) 
#define TIM_SMCR_ETPS_PER4      				        		((uint32_t)0x00002000) 
#define TIM_SMCR_ETPS_PER8      				        		((uint32_t)0x00003000)
	
/** @defgroup TIM_SMCR_ECE
  * @{
  */
#define TIM_SMCR_ECE_Pos		               					14                                             
#define TIM_SMCR_ECE_Msk               							(0x01UL << TIM_SMCR_ECE_Pos)  
#define TIM_SMCR_ECE_EXC2_DISABLE					     		  ((uint32_t)0x00000000)
#define TIM_SMCR_ECE_EXC2_ENABLE    		     		 		((uint32_t)0x00004000) 

/** @defgroup TIM_SMCR_ETP
  * @{
  */
#define TIM_SMCR_ETP_Pos		               					15                                             
#define TIM_SMCR_ETP_Msk               							(0x01UL << TIM_SMCR_ETP_Pos)  
#define TIM_SMCR_ETP_HIGH			     				   		    ((uint32_t)0x00000000)
#define TIM_SMCR_ETP_LOW      				       		 		((uint32_t)0x00008000) 

	
/**
* @}TIM_DIER
*/ 	

/** @defgroup TIM_DIER_UIE
  * @{
  */
#define TIM_DIER_UIE_Pos		               					0                                             
#define TIM_DIER_UIE_Msk               							(0x01UL << TIM_DIER_UIE_Pos)  
#define TIM_DIER_UIE     				        						((uint32_t)0x00000001)

/** @defgroup TIM_DIER_CC1IE
  * @{
  */
#define TIM_DIER_CC1IE_Pos		               				1                                             
#define TIM_DIER_CC1IE_Msk               						(0x01UL << TIM_DIER_CC1IE_Pos)  
#define TIM_DIER_CC1IE     				        					((uint32_t)0x00000002)

/** @defgroup TIM_DIER_CC2IE
  * @{
  */
#define TIM_DIER_CC2IE_Pos		               				2                                             
#define TIM_DIER_CC2IE_Msk               						(0x01UL << TIM_DIER_CC2IE_Pos)  
#define TIM_DIER_CC2IE     				        					((uint32_t)0x00000004)

/** @defgroup TIM_DIER_CC3IE
  * @{
  */
#define TIM_DIER_CC3IE_Pos		               				3                                             
#define TIM_DIER_CC3IE_Msk               						(0x01UL << TIM_DIER_CC3IE_Pos)  
#define TIM_DIER_CC3IE     				        					((uint32_t)0x00000008)

/** @defgroup TIM_DIER_CC4IE
  * @{
  */
#define TIM_DIER_CC4IE_Pos		               				4                                             
#define TIM_DIER_CC4IE_Msk               						(0x01UL << TIM_DIER_CC4IE_Pos)  
#define TIM_DIER_CC4IE     				        					((uint32_t)0x00000010)

/** @defgroup TIM_DIER_COMIE
  * @{
  */
#define TIM_DIER_COMIE_Pos		               				5                                             
#define TIM_DIER_COMIE_Msk               						(0x01UL << TIM_DIER_COMIE_Pos)  
#define TIM_DIER_COMIE     				        					((uint32_t)0x00000020)

/** @defgroup TIM_DIER_TIE
  * @{
  */
#define TIM_DIER_TIE_Pos		               					6                                             
#define TIM_DIER_TIE_Msk               							(0x01UL << TIM_DIER_TIE_Pos)  
#define TIM_DIER_TIE     				        						((uint32_t)0x00000040)

/** @defgroup TIM_DIER_BIE
  * @{
  */
#define TIM_DIER_BIE_Pos		               					7                                             
#define TIM_DIER_BIE_Msk               							(0x01UL << TIM_DIER_BIE_Pos)  
#define TIM_DIER_BIE     				        						((uint32_t)0x00000080)

/** @defgroup TIM_DIER_UDE
  * @{
  */
#define TIM_DIER_UDE_Pos		               					8                                             
#define TIM_DIER_UDE_Msk               							(0x01UL << TIM_DIER_UDE_Pos)  
#define TIM_DIER_UDE     				        						((uint32_t)0x00000100)

/** @defgroup TIM_DIER_CC1DE
  * @{
  */
#define TIM_DIER_CC1DE_Pos		               				9                                             
#define TIM_DIER_CC1DE_Msk               						(0x01UL << TIM_DIER_CC1DE_Pos)  
#define TIM_DIER_CC1DE     				        					((uint32_t)0x00000200)

/** @defgroup TIM_DIER_CC2DE
  * @{
  */
#define TIM_DIER_CC2DE_Pos		               				10                                             
#define TIM_DIER_CC2DE_Msk               						(0x01UL << TIM_DIER_CC2DE_Pos)  
#define TIM_DIER_CC2DE     				        					((uint32_t)0x00000400)

/** @defgroup TIM_DIER_CC3DE
  * @{
  */
#define TIM_DIER_CC3DE_Pos		               				11                                             
#define TIM_DIER_CC3DE_Msk               						(0x01UL << TIM_DIER_CC3DE_Pos)  
#define TIM_DIER_CC3DE     				        					((uint32_t)0x00000800)

/** @defgroup TIM_DIER_CC4DE
  * @{
  */
#define TIM_DIER_CC4DE_Pos		               				12                                             
#define TIM_DIER_CC4DE_Msk               						(0x01UL << TIM_DIER_CC4DE_Pos)  
#define TIM_DIER_CC4DE     				        					((uint32_t)0x00001000)

/** @defgroup TIM_DIER_COMDE
  * @{
  */
#define TIM_DIER_COMDE_Pos		               				13                                             
#define TIM_DIER_COMDE_Msk               						(0x01UL << TIM_DIER_COMDE_Pos)  
#define TIM_DIER_COMDE     				        					((uint32_t)0x00002000)

/** @defgroup TIM_DIER_TDE
  * @{
  */
#define TIM_DIER_TDE_Pos		               					14                                             
#define TIM_DIER_TDE_Msk               							(0x01UL << TIM_DIER_TDE_Pos)  
#define TIM_DIER_TDE     				        						((uint32_t)0x00004000)

/**
* @}TIM_SR
*/ 

#define TIM_SR_UIF				    				        			((uint32_t)0x00000001)
#define TIM_SR_CC1IF				    				        		((uint32_t)0x00000002)
#define TIM_SR_CC2IF				    				        		((uint32_t)0x00000004)
#define TIM_SR_CC3IF				    				        		((uint32_t)0x00000008)
#define TIM_SR_CC4IF				    				        		((uint32_t)0x00000010)
#define TIM_SR_COMIF				    				        		((uint32_t)0x00000020)
#define TIM_SR_TIF					    				        		((uint32_t)0x00000040)
#define TIM_SR_BIF				    				        			((uint32_t)0x00000080)

#define TIM_SR_CC1OF			    				        			((uint32_t)0x00000200)
#define TIM_SR_CC2OF			    				        			((uint32_t)0x00000400)
#define TIM_SR_CC3OF			    				        			((uint32_t)0x00000800)
#define TIM_SR_CC4OF			    				        			((uint32_t)0x00000100)

/**
* @}TIM_EGR
*/ 
	
#define TIM_EGR_UG     				        							((uint32_t)0x00000001)
#define TIM_EGR_CC1G   				        							((uint32_t)0x00000002)
#define TIM_EGR_CC2G     				       							((uint32_t)0x00000004)
#define TIM_EGR_CC3G   				        							((uint32_t)0x00000008)
#define TIM_EGR_CC4G   				        							((uint32_t)0x00000010)
#define TIM_EGR_COMG   				        							((uint32_t)0x00000020)
#define TIM_EGR_TG   				        								((uint32_t)0x00000040)
#define TIM_EGR_BG   				        								((uint32_t)0x00000080)





/**
* @}TIM_CCMR1
*/

/** @defgroup TIM_CCMR1_CC1S
  * @{
  */

#define TIM_CCMR1_CC1S_Pos		               					0                                             
#define TIM_CCMR1_CC1S_Msk               							(0x03UL << TIM_CCMR1_CC1S_Pos)  
#define TIM_CCMR1_CC1S_OUTPUT			     				        ((uint32_t)0x00000000)
#define TIM_CCMR1_CC1S_INPUT_TI1      				        ((uint32_t)0x00000001) 
#define TIM_CCMR1_CC1S_INPUT_TI2      				        ((uint32_t)0x00000002) 
#define TIM_CCMR1_CC1S_INPUT_TRC      				        ((uint32_t)0x00000003) 


/** @defgroup TIM_CCMR1_IC1PCS
  * @{
  */

#define TIM_CCMR1_IC1PCS_Pos		               				2                                             
#define TIM_CCMR1_IC1PCS_Msk               						(0x03UL << TIM_CCMR1_IC1PCS_Pos)  
#define TIM_CCMR1_IC1PCS_NONE			     				        ((uint32_t)0x00000000)
#define TIM_CCMR1_IC1PCS_PER2      				        		((uint32_t)0x00000004) 
#define TIM_CCMR1_IC1PCS_PER4      				        		((uint32_t)0x00000008) 
#define TIM_CCMR1_IC1PCS_PER8      				        		((uint32_t)0x0000000C) 

/** @defgroup TIM_CCMR1_IC1F
  * @{
  */

#define TIM_CCMR1_IC1F_Pos		               					4                                             
#define TIM_CCMR1_IC1F_Msk               							(0x0FUL << TIM_CCMR1_IC1F_Pos)  

#define TIM_CCMR1_IC2F_Pos		               					12                                             
#define TIM_CCMR1_IC2F_Msk               							(0x0FUL << TIM_CCMR1_IC2F_Pos)  

#define TIM_CCMR1_ICxF_NONE			     				        	((uint32_t)0x00000000)
#define TIM_CCMR1_ICxF_FCLK_N2      				        	((uint32_t)0x00000001) 
#define TIM_CCMR1_ICxF_FCLK_N4     				        		((uint32_t)0x00000002) 
#define TIM_CCMR1_ICxF_FCLK_N8      				        	((uint32_t)0x00000003) 
#define TIM_CCMR1_ICxF_FDTS_DIV2N6   				        	((uint32_t)0x00000004)
#define TIM_CCMR1_ICxF_FDTS_DIV2N8 				        		((uint32_t)0x00000005) 
#define TIM_CCMR1_ICxF_FDTS_DIV4N6     		        		((uint32_t)0x00000006) 
#define TIM_CCMR1_ICxF_FDTS_DIV4N8 				        		((uint32_t)0x00000007) 
#define TIM_CCMR1_ICxF_FDTS_DIV8N6   				        	((uint32_t)0x00000008)
#define TIM_CCMR1_ICxF_FDTS_DIV8N8 				        		((uint32_t)0x00000009) 
#define TIM_CCMR1_ICxF_FDTS_DIV16N5     		        	((uint32_t)0x0000000A) 
#define TIM_CCMR1_ICxF_FDTS_DIV16N6 				        	((uint32_t)0x0000000B) 
#define TIM_CCMR1_ICxF_FDTS_DIV16N8   				       	((uint32_t)0x0000000C)
#define TIM_CCMR1_ICxF_FDTS_DIV32N5 				        	((uint32_t)0x0000000D) 
#define TIM_CCMR1_ICxF_FDTS_DIV32N6     		        	((uint32_t)0x0000000E) 
#define TIM_CCMR1_ICxF_FDTS_DIV32N8 				        	((uint32_t)0x0000000F) 

/** @defgroup TIM_CCMR1_CC2S
  * @{
  */

#define TIM_CCMR1_CC2S_Pos		               					8                                             
#define TIM_CCMR1_CC2S_Msk               							(0x03UL << TIM_CCMR1_CC2S_Pos)  
#define TIM_CCMR1_CC2S_OUTPUT			     				        ((uint32_t)0x00000000)
#define TIM_CCMR1_CC2S_INPUT_TI2      				        ((uint32_t)0x00000100) 
#define TIM_CCMR1_CC2S_INPUT_TI1      				        ((uint32_t)0x00000200) 
#define TIM_CCMR1_CC2S_INPUT_TRC      				        ((uint32_t)0x00000300) 

/** @defgroup TIM_CCMR1_IC2PCS
  * @{
  */

#define TIM_CCMR1_IC2PCS_Pos		               				10                                             
#define TIM_CCMR1_IC2PCS_Msk               						(0x03UL << TIM_CCMR1_IC2PCS_Pos)  
#define TIM_CCMR1_IC2PCS_NONE			     				        ((uint32_t)0x00000000)
#define TIM_CCMR1_IC2PCS_PER2      				        		((uint32_t)0x00000400) 
#define TIM_CCMR1_IC2PCS_PER4      				        		((uint32_t)0x00000800) 
#define TIM_CCMR1_IC2PCS_PER8      				        		((uint32_t)0x00000C00) 

/** @defgroup TIM_CCMR1_OC1FE
  * @{
  */
#define TIM_CCMR1_OC1FE_Pos		               					2                                             
#define TIM_CCMR1_OC1FE_Msk               						(0x01UL << TIM_CCMR1_OC1FE_Pos)  
#define TIM_CCMR1_OC1FE_DISABLE			     				      ((uint32_t)0x00000000)
#define TIM_CCMR1_OC1FE_ENABLE      				       		((uint32_t)0x00000004) 

/** @defgroup TIM_CCMR1_OC1PE
  * @{
  */
#define TIM_CCMR1_OC1PE_Pos		               					3                                             
#define TIM_CCMR1_OC1PE_Msk               						(0x01UL << TIM_CCMR1_OC1PE_Pos)  
#define TIM_CCMR1_OC1PE_DISABLE			     				      ((uint32_t)0x00000000)
#define TIM_CCMR1_OC1PE_ENABLE      				       		((uint32_t)0x00000008) 

/** @defgroup TIM_CCMR1_OC1M
  * @{
  */

#define TIM_CCMR1_OC1M_Pos		               					4                                             
#define TIM_CCMR1_OC1M_Msk               							(0x07UL << TIM_CCMR1_OC1M_Pos)  
#define TIM_CCMR1_OC1M_NONE			     				       		((uint32_t)0x00000000)
#define TIM_CCMR1_OC1M_EQH			     				       		((uint32_t)0x00000010)
#define TIM_CCMR1_OC1M_EQL     				        				((uint32_t)0x00000020) 
#define TIM_CCMR1_OC1M_EQTOGGLE  				        			((uint32_t)0x00000030) 
#define TIM_CCMR1_OC1M_FL      			 	        				((uint32_t)0x00000040) 
#define TIM_CCMR1_OC1M_FH 			     				       		((uint32_t)0x00000050)
#define TIM_CCMR1_OC1M_PWM1    				        				((uint32_t)0x00000060) 
#define TIM_CCMR1_OC1M_PWM2		  				        			((uint32_t)0x00000070) 

/** @defgroup TIM_CCMR1_OC1CE
  * @{
  */
#define TIM_CCMR1_OC1CE_Pos		               					7                                             
#define TIM_CCMR1_OC1CE_Msk               						(0x01UL << TIM_CCMR1_OC1CE_Pos)  
#define TIM_CCMR1_OC1CE_DISABLE			     				      ((uint32_t)0x00000000)
#define TIM_CCMR1_OC1CE_ENABLE      				       		((uint32_t)0x00000080) 	
	
/** @defgroup TIM_CCMR1_OC2FE
  * @{
  */
#define TIM_CCMR1_OC2FE_Pos		               					10                                             
#define TIM_CCMR1_OC2FE_Msk               						(0x01UL << TIM_CCMR1_OC2FE_Pos)  
#define TIM_CCMR1_OC2FE_DISABLE			     				      ((uint32_t)0x00000000)
#define TIM_CCMR1_OC2FE_ENABLE      				       		((uint32_t)0x00000400) 

/** @defgroup TIM_CCMR1_OC2PE
  * @{
  */
#define TIM_CCMR1_OC2PE_Pos		               					11                                             
#define TIM_CCMR1_OC2PE_Msk               						(0x01UL << TIM_CCMR1_OC2PE_Pos)  
#define TIM_CCMR1_OC2PE_DISABLE			     				      ((uint32_t)0x00000000)
#define TIM_CCMR1_OC2PE_ENABLE      				       		((uint32_t)0x00000800) 

/** @defgroup TIM_CCMR1_OC2M
  * @{
  */

#define TIM_CCMR1_OC2M_Pos		               					12                                             
#define TIM_CCMR1_OC2M_Msk               							(0x07UL << TIM_CCMR1_OC2M_Pos)  
#define TIM_CCMR1_OC2M_NONE			     				       		((uint32_t)0x00000000)
#define TIM_CCMR1_OC2M_EQH			     				       		((uint32_t)0x00001000)
#define TIM_CCMR1_OC2M_EQL     				        				((uint32_t)0x00002000) 
#define TIM_CCMR1_OC2M_EQTOGGLE  				        			((uint32_t)0x00003000) 
#define TIM_CCMR1_OC2M_FL      			 	        				((uint32_t)0x00004000) 
#define TIM_CCMR1_OC2M_FH 			     				       		((uint32_t)0x00005000)
#define TIM_CCMR1_OC2M_PWM1    				        				((uint32_t)0x00006000) 
#define TIM_CCMR1_OC2M_PWM2		  				        			((uint32_t)0x00007000) 

/** @defgroup TIM_CCMR1_OC2CE
  * @{
  */
#define TIM_CCMR1_OC2CE_Pos		               					15                                             
#define TIM_CCMR1_OC2CE_Msk               						(0x01UL << TIM_CCMR1_OC2CE_Pos)  
#define TIM_CCMR1_OC2CE_DISABLE			     				      ((uint32_t)0x00000000)
#define TIM_CCMR1_OC2CE_ENABLE      				       		((uint32_t)0x00008000) 		
	

/**
* @}TIM_CCMR2
*/

/** @defgroup TIM_CCMR2_CC3S
  * @{
  */

#define TIM_CCMR2_CC3S_Pos		               					0                                             
#define TIM_CCMR2_CC3S_Msk               							(0x03UL << TIM_CCMR2_CC3S_Pos)  
#define TIM_CCMR2_CC3S_OUTPUT			     				        ((uint32_t)0x00000000)
#define TIM_CCMR2_CC3S_INPUT_TI3      				        ((uint32_t)0x00000001) 
#define TIM_CCMR2_CC3S_INPUT_TI4      				        ((uint32_t)0x00000002) 
#define TIM_CCMR2_CC3S_INPUT_TRC      				        ((uint32_t)0x00000003) 


/** @defgroup TIM_CCMR2_IC3PCS
  * @{
  */

#define TIM_CCMR2_IC3PCS_Pos		               				2                                             
#define TIM_CCMR2_IC3PCS_Msk               						(0x03UL << TIM_CCMR2_IC3PCS_Pos)  
#define TIM_CCMR2_IC3PCS_NONE			     				        ((uint32_t)0x00000000)
#define TIM_CCMR2_IC3PCS_PER2      				        		((uint32_t)0x00000004) 
#define TIM_CCMR2_IC3PCS_PER4      				        		((uint32_t)0x00000008) 
#define TIM_CCMR2_IC3PCS_PER8      				        		((uint32_t)0x0000000C) 

/** @defgroup TIM_CCMR2_IC3F
  * @{
  */

#define TIM_CCMR2_IC3F_Pos		               					4                                             
#define TIM_CCMR2_IC3F_Msk               							(0x0FUL << TIM_CCMR2_IC3F_Pos)  

#define TIM_CCMR2_IC4F_Pos		               					12                                             
#define TIM_CCMR2_IC4F_Msk               							(0x0FUL << TIM_CCMR2_IC4F_Pos)  



/** @defgroup TIM_CCMR2_CC4S
  * @{
  */

#define TIM_CCMR2_CC4S_Pos		               					8                                             
#define TIM_CCMR2_CC4S_Msk               							(0x03UL << TIM_CCMR2_CC4S_Pos)  
#define TIM_CCMR2_CC4S_OUTPUT			     				        ((uint32_t)0x00000000)
#define TIM_CCMR2_CC4S_INPUT_TI4      				        ((uint32_t)0x00000100) 
#define TIM_CCMR2_CC4S_INPUT_TI3      				        ((uint32_t)0x00000200) 
#define TIM_CCMR2_CC4S_INPUT_TRC      				        ((uint32_t)0x00000300) 

/** @defgroup TIM_CCMR2_IC4PCS
  * @{
  */

#define TIM_CCMR2_IC4PCS_Pos		               				10                                             
#define TIM_CCMR2_IC4PCS_Msk               						(0x03UL << TIM_CCMR2_IC4PCS_Pos)  
#define TIM_CCMR2_IC4PCS_NONE			     				        ((uint32_t)0x00000000)
#define TIM_CCMR2_IC4PCS_PER2      				        		((uint32_t)0x00000400) 
#define TIM_CCMR2_IC4PCS_PER4      				        		((uint32_t)0x00000800) 
#define TIM_CCMR2_IC4PCS_PER8      				        		((uint32_t)0x00000C00) 


/** @defgroup TIM_CCMR2_OC3FE
  * @{
  */
#define TIM_CCMR2_OC3FE_Pos		               					2                                             
#define TIM_CCMR2_OC3FE_Msk               						(0x01UL << TIM_CCMR2_OC3FE_Pos)  
#define TIM_CCMR2_OC3FE_DISABLE			     				      ((uint32_t)0x00000000)
#define TIM_CCMR2_OC3FE_ENABLE      				       		((uint32_t)0x00000004) 

/** @defgroup TIM_CCMR2_OC3PE
  * @{
  */
#define TIM_CCMR2_OC3PE_Pos		               					3                                             
#define TIM_CCMR2_OC3PE_Msk               						(0x01UL << TIM_CCMR2_OC3PE_Pos)  
#define TIM_CCMR2_OC3PE_DISABLE			     				      ((uint32_t)0x00000000)
#define TIM_CCMR2_OC3PE_ENABLE      				       		((uint32_t)0x00000008) 

/** @defgroup TIM_CCMR2_OC3M
  * @{
  */

#define TIM_CCMR2_OC3M_Pos		               					4                                             
#define TIM_CCMR2_OC3M_Msk               							(0x07UL << TIM_CCMR2_OC3M_Pos)  
#define TIM_CCMR2_OC3M_NONE			     				       		((uint32_t)0x00000000)
#define TIM_CCMR2_OC3M_EQH			     				       		((uint32_t)0x00000010)
#define TIM_CCMR2_OC3M_EQL     				        				((uint32_t)0x00000020) 
#define TIM_CCMR2_OC3M_EQTOGGLE  				        			((uint32_t)0x00000030) 
#define TIM_CCMR2_OC3M_FL      			 	        				((uint32_t)0x00000040) 
#define TIM_CCMR2_OC3M_FH 			     				       		((uint32_t)0x00000050)
#define TIM_CCMR2_OC3M_PWM1    				        				((uint32_t)0x00000060) 
#define TIM_CCMR2_OC3M_PWM2		  				        			((uint32_t)0x00000070) 

/** @defgroup TIM_CCMR2_OC3CE
  * @{
  */
#define TIM_CCMR2_OC3CE_Pos		               					7                                             
#define TIM_CCMR2_OC3CE_Msk               						(0x01UL << TIM_CCMR2_OC3CE_Pos)  
#define TIM_CCMR2_OC3CE_DISABLE			     				      ((uint32_t)0x00000000)
#define TIM_CCMR2_OC3CE_ENABLE      				       		((uint32_t)0x00000080) 	
	
/** @defgroup TIM_CCMR2_OC4FE
  * @{
  */
#define TIM_CCMR2_OC4FE_Pos		               					10                                             
#define TIM_CCMR2_OC4FE_Msk               						(0x01UL << TIM_CCMR2_OC4FE_Pos)  
#define TIM_CCMR2_OC4FE_DISABLE			     				      ((uint32_t)0x00000000)
#define TIM_CCMR2_OC4FE_ENABLE      				       		((uint32_t)0x00000400) 

/** @defgroup TIM_CCMR2_OC4PE
  * @{
  */
#define TIM_CCMR2_OC4PE_Pos		               					11                                             
#define TIM_CCMR2_OC4PE_Msk               						(0x01UL << TIM_CCMR2_OC4PE_Pos)  
#define TIM_CCMR2_OC4PE_DISABLE			     				      ((uint32_t)0x00000000)
#define TIM_CCMR2_OC4PE_ENABLE      				       		((uint32_t)0x00000800) 

/** @defgroup TIM_CCMR2_OC4M
  * @{
  */

#define TIM_CCMR2_OC4M_Pos		               					12                                             
#define TIM_CCMR2_OC4M_Msk               							(0x07UL << TIM_CCMR2_OC4M_Pos)  
#define TIM_CCMR2_OC4M_NONE			     				       		((uint32_t)0x00000000)
#define TIM_CCMR2_OC4M_EQH			     				       		((uint32_t)0x00001000)
#define TIM_CCMR2_OC4M_EQL     				        				((uint32_t)0x00002000) 
#define TIM_CCMR2_OC4M_EQTOGGLE  				        			((uint32_t)0x00003000) 
#define TIM_CCMR2_OC4M_FL      			 	        				((uint32_t)0x00004000) 
#define TIM_CCMR2_OC4M_FH 			     				       		((uint32_t)0x00005000)
#define TIM_CCMR2_OC4M_PWM1    				        				((uint32_t)0x00006000) 
#define TIM_CCMR2_OC4M_PWM2		  				        			((uint32_t)0x00007000) 

/** @defgroup TIM_CCMR2_OC4CE
  * @{
  */
#define TIM_CCMR2_OC4CE_Pos		               					15                                             
#define TIM_CCMR2_OC4CE_Msk               						(0x01UL << TIM_CCMR2_OC4CE_Pos)  
#define TIM_CCMR2_OC4CE_DISABLE			     				      ((uint32_t)0x00000000)
#define TIM_CCMR2_OC4CE_ENABLE      				       		((uint32_t)0x00008000) 		

/**
* @}TIM_CCER
*/

/** @defgroup TIM_CCER_CC1E
  * @{
  */
#define TIM_CCER_CC1E_Pos		               						0                                             
#define TIM_CCER_CC1E_Msk               							(0x01UL << TIM_CCER_CC1E_Pos)  
#define TIM_CCER_CC1E_DISABLE    				        			((uint32_t)0x00000000) 
#define TIM_CCER_CC1E_ENABLE     				        			((uint32_t)0x00000001)

/** @defgroup TIM_CCER_CC1P
  * @{
  */
#define TIM_CCER_CC1P_Pos		               						1                                             
#define TIM_CCER_CC1P_Msk               							(0x01UL << TIM_CCER_CC1P_Pos)  
#define TIM_CCER_CC1P_HIGH     				        				((uint32_t)0x00000000)
#define TIM_CCER_CC1P_LOW		    				        			((uint32_t)0x00000002) 

/** @defgroup TIM_CCER_CC1NE
  * @{
  */
#define TIM_CCER_CC1NE_Pos		               					2                                             
#define TIM_CCER_CC1NE_Msk               							(0x01UL << TIM_CCER_CC1NE_Pos)  
#define TIM_CCER_CC1NE_DISABLE    				        		((uint32_t)0x00000000) 
#define TIM_CCER_CC1NE_ENABLE     				        		((uint32_t)0x00000004)

/** @defgroup TIM_CCER_CC1NP
  * @{
  */
#define TIM_CCER_CC1NP_Pos		               					3                                             
#define TIM_CCER_CC1NP_Msk               							(0x01UL << TIM_CCER_CC1NP_Pos)  
#define TIM_CCER_CC1NP_HIGH     				        			((uint32_t)0x00000000)
#define TIM_CCER_CC1NP_LOW		    				        		((uint32_t)0x00000008) 

/** @defgroup TIM_CCER_CC2E
  * @{
  */
	
#define TIM_CCER_CC2E_Pos		               						4                                             
#define TIM_CCER_CC2E_Msk               							(0x01UL << TIM_CCER_CC2E_Pos)  
#define TIM_CCER_CC2E_DISABLE    				        			((uint32_t)0x00000000) 
#define TIM_CCER_CC2E_ENABLE     				        			((uint32_t)0x00000010)

/** @defgroup TIM_CCER_CC2P
  * @{
  */
#define TIM_CCER_CC2P_Pos		               						5                                             
#define TIM_CCER_CC2P_Msk               							(0x01UL << TIM_CCER_CC2P_Pos)  
#define TIM_CCER_CC2P_HIGH     				        				((uint32_t)0x00000000)
#define TIM_CCER_CC2P_LOW		    				        			((uint32_t)0x00000020) 

/** @defgroup TIM_CCER_CC2NE
  * @{
  */
#define TIM_CCER_CC2NE_Pos		               					6                                             
#define TIM_CCER_CC2NE_Msk               							(0x01UL << TIM_CCER_CC2NE_Pos)  
#define TIM_CCER_CC2NE_DISABLE    				        		((uint32_t)0x00000000) 
#define TIM_CCER_CC2NE_ENABLE     				        		((uint32_t)0x00000040)

/** @defgroup TIM_CCER_CC2NP
  * @{
  */
#define TIM_CCER_CC2NP_Pos		               					7                                             
#define TIM_CCER_CC2NP_Msk               							(0x01UL << TIM_CCER_CC2NP_Pos)  
#define TIM_CCER_CC2NP_HIGH     				        				((uint32_t)0x00000000)
#define TIM_CCER_CC2NP_LOW		    				        		((uint32_t)0x00000080) 
         
/** @defgroup TIM_CCER_CC3E
  * @{
  */         
          
#define TIM_CCER_CC3E_Pos		               						8                                             
#define TIM_CCER_CC3E_Msk               							(0x01UL << TIM_CCER_CC3E_Pos)  
#define TIM_CCER_CC3E_DISABLE    				        			((uint32_t)0x00000000) 
#define TIM_CCER_CC3E_ENABLE     				        			((uint32_t)0x00000100)

/** @defgroup TIM_CCER_CC3P
  * @{
  */
#define TIM_CCER_CC3P_Pos		               						9                                             
#define TIM_CCER_CC3P_Msk               							(0x01UL << TIM_CCER_CC3P_Pos)  
#define TIM_CCER_CC3P_HIGH     				        				((uint32_t)0x00000000)
#define TIM_CCER_CC3P_LOW		    				        			((uint32_t)0x00000200) 

/** @defgroup TIM_CCER_CC3NE
  * @{
  */
#define TIM_CCER_CC3NE_Pos		               					10                                             
#define TIM_CCER_CC3NE_Msk               							(0x01UL << TIM_CCER_CC3NE_Pos)  
#define TIM_CCER_CC3NE_DISABLE    				        		((uint32_t)0x00000000) 
#define TIM_CCER_CC3NE_ENABLE     				        		((uint32_t)0x00000400)

/** @defgroup TIM_CCER_CC3NP
  * @{
  */
#define TIM_CCER_CC3NP_Pos		               					11                                             
#define TIM_CCER_CC3NP_Msk               							(0x01UL << TIM_CCER_CC3NP_Pos)  
#define TIM_CCER_CC3NP_HIGH     				        				((uint32_t)0x00000000)
#define TIM_CCER_CC3NP_LOW		    				        		((uint32_t)0x00000800) 

/** @defgroup TIM_CCER_CC4E
  * @{
  */   
#define TIM_CCER_CC4E_Pos		               						12                                             
#define TIM_CCER_CC4E_Msk               							(0x01UL << TIM_CCER_CC4E_Pos)  
#define TIM_CCER_CC4E_DISABLE    				        			((uint32_t)0x00000000) 
#define TIM_CCER_CC4E_ENABLE     				        			((uint32_t)0x00001000)

/** @defgroup TIM_CCER_CC4P
  * @{
  */
#define TIM_CCER_CC4P_Pos		               						13                                             
#define TIM_CCER_CC4P_Msk               							(0x01UL << TIM_CCER_CC4P_Pos)  
#define TIM_CCER_CC4P_HIGH     				        				((uint32_t)0x00000000)
#define TIM_CCER_CC4P_LOW		    				        			((uint32_t)0x00002000) 


/**
* @}TIM_BDTR
*/
/** @defgroup TIM_BDTR_DTG
  * @{
  */
#define TIM_BDTR_DTG_Pos		 			              			0                                             
#define TIM_BDTR_DTG_Msk         				      				(0xFFUL << TIM_BDTR_DTG_Pos)  

/** @defgroup TIM_BDTR_LOCK
  * @{
  */
#define TIM_BDTR_LOCK_Pos		 			              			8                                             
#define TIM_BDTR_LOCK_Msk         				      			(0x03UL << TIM_BDTR_LOCK_Pos)  
#define TIM_BDTR_LOCK_LEVEL0     				      			  ((uint32_t)0x00000000)
#define TIM_BDTR_LOCK_LEVEL1    				     				  ((uint32_t)0x00000100) 
#define TIM_BDTR_LOCK_LEVEL2    				     				  ((uint32_t)0x00000200) 
#define TIM_BDTR_LOCK_LEVEL3    				     				  ((uint32_t)0x00000300) 

/** @defgroup TIM_BDTR_OSSI
  * @{
  */
#define TIM_BDTR_OSSI_Pos		 			              			10                                             
#define TIM_BDTR_OSSI_Msk         				      			(0x01UL << TIM_BDTR_OSSI_Pos)  
#define TIM_BDTR_OSSI_ENABLE	     		      			  	((uint32_t)0x00000400)
#define TIM_BDTR_OSSI_DISABLE    				     				  ((uint32_t)0x00000000) 

/** @defgroup TIM_BDTR_OSSR
  * @{
  */
#define TIM_BDTR_OSSR_Pos		 			              			11                                             
#define TIM_BDTR_OSSR_Msk         				        		(0x01UL << TIM_BDTR_OSSR_Pos)  
#define TIM_BDTR_OSSR_ENABLE	     	 		      			 	((uint32_t)0x00000800)
#define TIM_BDTR_OSSR_DISABLE    				     				 	((uint32_t)0x00000000) 

/** @defgroup TIM_BDTR_BKE
  * @{
  */
#define TIM_BDTR_BKE_Pos		 			              			12                                             
#define TIM_BDTR_BKE_Msk         				      				(0x01UL << TIM_BDTR_BKE_Pos)  
#define TIM_BDTR_BKE_ENABLE     				      			  ((uint32_t)0x00001000)
#define TIM_BDTR_BKE_DISABLE    				     				  ((uint32_t)0x00000000) 

/** @defgroup TIM_BDTR_BKP
  * @{
  */
#define TIM_BDTR_BKP_Pos		 			              			13                                             
#define TIM_BDTR_BKP_Msk         				      				(0x01UL << TIM_BDTR_BKP_Pos)  
#define TIM_BDTR_BKP_HIGH     				      				  ((uint32_t)0x00002000)
#define TIM_BDTR_BKP_LOW    				     						  ((uint32_t)0x00000000) 

/** @defgroup TIM_BDTR_AOE
  * @{
  */
#define TIM_BDTR_AOE_Pos		 			              			14                                             
#define TIM_BDTR_AOE_Msk         				      				(0x01UL << TIM_BDTR_AOE_Pos)  
#define TIM_BDTR_AOE_SOFTAEVENT				      				  ((uint32_t)0x00004000)
#define TIM_BDTR_AOE_SOFT   				     						  ((uint32_t)0x00000000) 

/** @defgroup TIM_BDTR_MOE
  * @{
  */
#define TIM_BDTR_MOE_Pos		 			              			15                                             
#define TIM_BDTR_MOE_Msk         				      				(0x01UL << TIM_BDTR_MOE_Pos)  
#define TIM_BDTR_MOE_ENABLE     				      			  ((uint32_t)0x00008000)
#define TIM_BDTR_MOE_DISABLE    				     				  ((uint32_t)0x00000000) 

/**
* @}TIM_DCR
*/
/** @defgroup TIM_DCR_DBA
  * @{
  */
#define TIM_DCR_DBA_Pos		 			              			0                                             
#define TIM_DCR_DBA_Msk         				      			(0x1FUL << TIM_DCR_DBA_Pos)  

/** @defgroup TIM_DCR_DBL
  * @{
  */
#define TIM_DCR_DBL_Pos		 			              			8                                             
#define TIM_DCR_DBL_Msk         				      			(0x1FUL << TIM_DCR_DBL_Pos)  


/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/ 
extern void TIM_TimeBaseInit(ATIM_Type* TIMx, TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);
extern void TIM_Cmd(ATIM_Type* TIMx, FunState NewState);
extern void TIM_OC1Init(ATIM_Type* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
extern void TIM_OC2Init(ATIM_Type* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
extern void TIM_OC3Init(ATIM_Type* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
extern void TIM_OC1PreloadConfig(ATIM_Type* TIMx, uint32_t TIM_OCPreload);
extern void TIM_OC2PreloadConfig(ATIM_Type* TIMx, uint32_t TIM_OCPreload);
extern void TIM_OC3PreloadConfig(ATIM_Type* TIMx, uint32_t TIM_OCPreload);
extern void TIM_ARRPreloadConfig(ATIM_Type* TIMx, FunState NewState);
extern void TIM_BDTRConfig(ATIM_Type* TIMx, TIM_BDTRInitTypeDef *TIM_BDTRInitStruct);
extern void TIM_Cmd(ATIM_Type* TIMx, FunState NewState);
extern void TIM_CtrlPWMOutputs(ATIM_Type* TIMx, FunState NewState);
extern void TIM_CCxCmd(ATIM_Type* TIMx, uint32_t TIM_Channel, uint32_t TIM_CCx);
extern void TIM_CCxNCmd(ATIM_Type* TIMx, uint32_t TIM_Channel, uint32_t TIM_CCxN);
extern void BLDC_ATIM_PWM_Init(void);
extern void TIM_SetCompare1(ATIM_Type* TIMx, uint32_t Compare1);
extern void TIM_SetCompare2(ATIM_Type* TIMx, uint32_t Compare2);
extern void TIM_SetCompare3(ATIM_Type* TIMx, uint32_t Compare3);
extern void TIM_ICInit(ATIM_Type* TIMx, TIM_ICInitTypeDef* TIM_ICInitStruct);
extern void TIM_SelectHallSensor(ATIM_Type* TIMx, FunState NewState);
extern void TIM_SelectInputTrigger(ATIM_Type* TIMx, uint32_t TIM_InputTriggerSource);
extern void TIM_SelectSlaveMode(ATIM_Type* TIMx, uint32_t TIM_SlaveMode);
extern void TIM_SelectMasterSlaveMode(ATIM_Type* TIMx, uint32_t TIM_MasterSlaveMode);
extern void TIM_ITConfig(ATIM_Type* TIMx, uint32_t TIM_IT, FunState NewState);
extern void TIM_ClearITPendingBit(ATIM_Type* TIMx, uint32_t TIM_IT);
extern ITStatus TIM_GetITStatus(ATIM_Type* TIMx, uint32_t TIM_IT);
extern void HALL_TIMx_Init(void);


#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_TIM_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/



