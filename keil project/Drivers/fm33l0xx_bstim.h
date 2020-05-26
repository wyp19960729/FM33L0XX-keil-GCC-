/**
  ******************************************************************************
  * @file    fm33l0xx_bstim.h
  * @author  FM33L0xx Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file contains all the functions prototypes for the BSTIM firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33L0XX_BSTIM_H
#define __FM33L0XX_BSTIM_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33L0XX.h" 
   
//------------------------------------------------------------------------------
#define	BSTIM_CR1_ARPE_Pos	7	/* Auto-reload预装载使能 */
#define	BSTIM_CR1_ARPE_Msk	(0x1U << BSTIM_CR1_ARPE_Pos)
	/* 0：ARR寄存器不使能preload */
	/* 1：ARR寄存器使能preload */

#define	BSTIM_CR1_OPM_Pos	3	/* 单脉冲输出模式 (One Pulse Mode) */
#define	BSTIM_CR1_OPM_Msk	(0x1U << BSTIM_CR1_OPM_Pos)
#define	BSTIM_CR1_OPM_CONTINUE	(0x0U << BSTIM_CR1_OPM_Pos)	/* 0：Update Event发生时计数器不停止 */
#define	BSTIM_CR1_OPM_STOP	(0x1U << BSTIM_CR1_OPM_Pos)	/* 1：Update Event发生时计数器停止（自动清零CEN) */

#define	BSTIM_CR1_URS_Pos	2	/* 更新请求选择 (Update Request Select) */
#define	BSTIM_CR1_URS_Msk	(0x1U << BSTIM_CR1_URS_Pos)
#define	BSTIM_CR1_URS_ALL	(0x0U << BSTIM_CR1_URS_Pos)	/* 0：以下事件能够产生update中断 -计数器上溢出或下溢出 -软件置位UG寄存器 -从机控制器产生update */
#define	BSTIM_CR1_URS_COUNT	(0x1U << BSTIM_CR1_URS_Pos)	/* 1：仅计数器上溢出或下溢出会产生update中断或DMA请求 */

#define	BSTIM_CR1_UDIS_Pos	1	/* 禁止update (Update Disable) */
#define	BSTIM_CR1_UDIS_Msk	(0x1U << BSTIM_CR1_UDIS_Pos)
	/* 0：使能update事件；以下事件发生时产生update事件
-计数器上溢出或下溢出
-软件置位UG寄存器
-从机控制器产生update */
	/* 1：禁止update事件，不更新shadow寄存器。当UG置位或从机控制器收到硬件reset时重新初始化计数器和预分频器。 */

#define	BSTIM_CR1_CEN_Pos	0	/* 计数器使能 (Counter Enable) */
#define	BSTIM_CR1_CEN_Msk	(0x1U << BSTIM_CR1_CEN_Pos)
	/* 0：计数器关闭 */
	/* 1：计数器使能 */

#define	BSTIM_CR2_MMS_Pos	4	/* 主机模式选择，用于配置主机模式下向从机发送的同步触发信号（TRGO）源 (Master Mode Select) */
#define	BSTIM_CR2_MMS_Msk	(0x7U << BSTIM_CR2_MMS_Pos)
#define	BSTIM_CR2_MMS_EGR	(0x0U << BSTIM_CR2_MMS_Pos)	/* 000：BSTIM_EGR的UG寄存器被用作TRGO */
#define	BSTIM_CR2_MMS_CNT_EN	(0x1U << BSTIM_CR2_MMS_Pos)	/* 001：计数器使能信号CNT_EN被用作TRGO，可用于同时启动多个定时器 */
#define	BSTIM_CR2_MMS_UE_GO	(0x2U << BSTIM_CR2_MMS_Pos)	/* 010：UE（update event）信号被用作TRGO */

#define	BSTIM_IER_UIE_Pos	0	/* Update事件中断使能 (Update event Interrupt Enable) */
#define	BSTIM_IER_UIE_Msk	(0x1U << BSTIM_IER_UIE_Pos)
	/* 0：禁止Update事件中断 */
	/* 1：允许Update事件中断 */

#define	BSTIM_ISR_UIF_Pos	0	/* Update事件中断标志，硬件置位，软件写1清零。(Update event Interrupt Flag)当以下事件发生时，UIF置位，并更新shadow寄存器 */
#define	BSTIM_ISR_UIF_Msk	(0x1U << BSTIM_ISR_UIF_Pos)

#define	BSTIM_EGR_UG_Pos	0	/* 软件Update事件，软件置位此寄存器产生Update事件，硬件自动清零 (User Generate) */
#define	BSTIM_EGR_UG_Msk	(0x1U << BSTIM_EGR_UG_Pos)

#define	BSTIM_CNT_CNT_Pos	0	/* 计数器值 (Counter) */
#define	BSTIM_CNT_CNT_Msk	(0xffffffffU << BSTIM_CNT_CNT_Pos)

#define	BSTIM_PSC_PSC_Pos	0	/* 计数器时钟（CK_CNT）预分频值 (Counter Clock Prescaler) */
#define	BSTIM_PSC_PSC_Msk	(0xffffffffU << BSTIM_PSC_PSC_Pos)

#define	BSTIM_ARR_ARR_Pos	0	/* 计数溢出时的自动重载值 (Auto-Reload Register) */
#define	BSTIM_ARR_ARR_Msk	(0xffffffffU << BSTIM_ARR_ARR_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void BSTIM_Deinit(void);

/* Auto-reload预装载使能 相关函数 */
extern void BSTIM_CR1_ARPE_Setable(FunState NewState);
extern FunState BSTIM_CR1_ARPE_Getable(void);

/* 单脉冲输出模式 (One Pulse Mode) 相关函数 */
extern void BSTIM_CR1_OPM_Set(uint32_t SetValue);
extern uint32_t BSTIM_CR1_OPM_Get(void);

/* 更新请求选择 (Update Request Select) 相关函数 */
extern void BSTIM_CR1_URS_Set(uint32_t SetValue);
extern uint32_t BSTIM_CR1_URS_Get(void);

/* 禁止update (Update Disable) 相关函数 */
extern void BSTIM_CR1_UDIS_Setable(FunState NewState);
extern FunState BSTIM_CR1_UDIS_Getable(void);

/* 计数器使能 (Counter Enable) 相关函数 */
extern void BSTIM_CR1_CEN_Setable(FunState NewState);
extern FunState BSTIM_CR1_CEN_Getable(void);

/* 主机模式选择，用于配置主机模式下向从机发送的同步触发信号（TRGO）源 (Master Mode Select) 相关函数 */
extern void BSTIM_CR2_MMS_Set(uint32_t SetValue);
extern uint32_t BSTIM_CR2_MMS_Get(void);

/* Update事件中断使能 (Update event Interrupt Enable) 相关函数 */
extern void BSTIM_IER_UIE_Setable(FunState NewState);
extern FunState BSTIM_IER_UIE_Getable(void);

/* Update事件中断标志，硬件置位，软件写1清零。(Update event Interrupt Flag)
当以下事件发生时，UIF置位，并更新shadow寄存器 相关函数 */
extern void BSTIM_ISR_UIF_Clr(void);
extern FlagStatus BSTIM_ISR_UIF_Chk(void);

/* 软件Update事件，软件置位此寄存器产生Update事件，硬件自动清零 (User Generate) 相关函数 */
extern void BSTIM_EGR_UG_Clr(void);

/* 计数器值 (Counter) 相关函数 */
extern void BSTIM_CNT_Write(uint32_t SetValue);
extern uint32_t BSTIM_CNT_Read(void);

/* 计数器时钟（CK_CNT）预分频值 (Counter Clock Prescaler) 相关函数 */
extern void BSTIM_PSC_Write(uint32_t SetValue);
extern uint32_t BSTIM_PSC_Read(void);

/* 计数溢出时的自动重载值 (Auto-Reload Register) 相关函数 */
extern void BSTIM_ARR_Write(uint32_t SetValue);
extern uint32_t BSTIM_ARR_Read(void);
                
#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_BSTIM_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
