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
#define	BSTIM_CR1_ARPE_Pos	7	/* Auto-reloadԤװ��ʹ�� */
#define	BSTIM_CR1_ARPE_Msk	(0x1U << BSTIM_CR1_ARPE_Pos)
	/* 0��ARR�Ĵ�����ʹ��preload */
	/* 1��ARR�Ĵ���ʹ��preload */

#define	BSTIM_CR1_OPM_Pos	3	/* ���������ģʽ (One Pulse Mode) */
#define	BSTIM_CR1_OPM_Msk	(0x1U << BSTIM_CR1_OPM_Pos)
#define	BSTIM_CR1_OPM_CONTINUE	(0x0U << BSTIM_CR1_OPM_Pos)	/* 0��Update Event����ʱ��������ֹͣ */
#define	BSTIM_CR1_OPM_STOP	(0x1U << BSTIM_CR1_OPM_Pos)	/* 1��Update Event����ʱ������ֹͣ���Զ�����CEN) */

#define	BSTIM_CR1_URS_Pos	2	/* ��������ѡ�� (Update Request Select) */
#define	BSTIM_CR1_URS_Msk	(0x1U << BSTIM_CR1_URS_Pos)
#define	BSTIM_CR1_URS_ALL	(0x0U << BSTIM_CR1_URS_Pos)	/* 0�������¼��ܹ�����update�ж� -������������������ -�����λUG�Ĵ��� -�ӻ�����������update */
#define	BSTIM_CR1_URS_COUNT	(0x1U << BSTIM_CR1_URS_Pos)	/* 1���������������������������update�жϻ�DMA���� */

#define	BSTIM_CR1_UDIS_Pos	1	/* ��ֹupdate (Update Disable) */
#define	BSTIM_CR1_UDIS_Msk	(0x1U << BSTIM_CR1_UDIS_Pos)
	/* 0��ʹ��update�¼��������¼�����ʱ����update�¼�
-������������������
-�����λUG�Ĵ���
-�ӻ�����������update */
	/* 1����ֹupdate�¼���������shadow�Ĵ�������UG��λ��ӻ��������յ�Ӳ��resetʱ���³�ʼ����������Ԥ��Ƶ���� */

#define	BSTIM_CR1_CEN_Pos	0	/* ������ʹ�� (Counter Enable) */
#define	BSTIM_CR1_CEN_Msk	(0x1U << BSTIM_CR1_CEN_Pos)
	/* 0���������ر� */
	/* 1��������ʹ�� */

#define	BSTIM_CR2_MMS_Pos	4	/* ����ģʽѡ��������������ģʽ����ӻ����͵�ͬ�������źţ�TRGO��Դ (Master Mode Select) */
#define	BSTIM_CR2_MMS_Msk	(0x7U << BSTIM_CR2_MMS_Pos)
#define	BSTIM_CR2_MMS_EGR	(0x0U << BSTIM_CR2_MMS_Pos)	/* 000��BSTIM_EGR��UG�Ĵ���������TRGO */
#define	BSTIM_CR2_MMS_CNT_EN	(0x1U << BSTIM_CR2_MMS_Pos)	/* 001��������ʹ���ź�CNT_EN������TRGO��������ͬʱ���������ʱ�� */
#define	BSTIM_CR2_MMS_UE_GO	(0x2U << BSTIM_CR2_MMS_Pos)	/* 010��UE��update event���źű�����TRGO */

#define	BSTIM_IER_UIE_Pos	0	/* Update�¼��ж�ʹ�� (Update event Interrupt Enable) */
#define	BSTIM_IER_UIE_Msk	(0x1U << BSTIM_IER_UIE_Pos)
	/* 0����ֹUpdate�¼��ж� */
	/* 1������Update�¼��ж� */

#define	BSTIM_ISR_UIF_Pos	0	/* Update�¼��жϱ�־��Ӳ����λ�����д1���㡣(Update event Interrupt Flag)�������¼�����ʱ��UIF��λ��������shadow�Ĵ��� */
#define	BSTIM_ISR_UIF_Msk	(0x1U << BSTIM_ISR_UIF_Pos)

#define	BSTIM_EGR_UG_Pos	0	/* ���Update�¼��������λ�˼Ĵ�������Update�¼���Ӳ���Զ����� (User Generate) */
#define	BSTIM_EGR_UG_Msk	(0x1U << BSTIM_EGR_UG_Pos)

#define	BSTIM_CNT_CNT_Pos	0	/* ������ֵ (Counter) */
#define	BSTIM_CNT_CNT_Msk	(0xffffffffU << BSTIM_CNT_CNT_Pos)

#define	BSTIM_PSC_PSC_Pos	0	/* ������ʱ�ӣ�CK_CNT��Ԥ��Ƶֵ (Counter Clock Prescaler) */
#define	BSTIM_PSC_PSC_Msk	(0xffffffffU << BSTIM_PSC_PSC_Pos)

#define	BSTIM_ARR_ARR_Pos	0	/* �������ʱ���Զ�����ֵ (Auto-Reload Register) */
#define	BSTIM_ARR_ARR_Msk	(0xffffffffU << BSTIM_ARR_ARR_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void BSTIM_Deinit(void);

/* Auto-reloadԤװ��ʹ�� ��غ��� */
extern void BSTIM_CR1_ARPE_Setable(FunState NewState);
extern FunState BSTIM_CR1_ARPE_Getable(void);

/* ���������ģʽ (One Pulse Mode) ��غ��� */
extern void BSTIM_CR1_OPM_Set(uint32_t SetValue);
extern uint32_t BSTIM_CR1_OPM_Get(void);

/* ��������ѡ�� (Update Request Select) ��غ��� */
extern void BSTIM_CR1_URS_Set(uint32_t SetValue);
extern uint32_t BSTIM_CR1_URS_Get(void);

/* ��ֹupdate (Update Disable) ��غ��� */
extern void BSTIM_CR1_UDIS_Setable(FunState NewState);
extern FunState BSTIM_CR1_UDIS_Getable(void);

/* ������ʹ�� (Counter Enable) ��غ��� */
extern void BSTIM_CR1_CEN_Setable(FunState NewState);
extern FunState BSTIM_CR1_CEN_Getable(void);

/* ����ģʽѡ��������������ģʽ����ӻ����͵�ͬ�������źţ�TRGO��Դ (Master Mode Select) ��غ��� */
extern void BSTIM_CR2_MMS_Set(uint32_t SetValue);
extern uint32_t BSTIM_CR2_MMS_Get(void);

/* Update�¼��ж�ʹ�� (Update event Interrupt Enable) ��غ��� */
extern void BSTIM_IER_UIE_Setable(FunState NewState);
extern FunState BSTIM_IER_UIE_Getable(void);

/* Update�¼��жϱ�־��Ӳ����λ�����д1���㡣(Update event Interrupt Flag)
�������¼�����ʱ��UIF��λ��������shadow�Ĵ��� ��غ��� */
extern void BSTIM_ISR_UIF_Clr(void);
extern FlagStatus BSTIM_ISR_UIF_Chk(void);

/* ���Update�¼��������λ�˼Ĵ�������Update�¼���Ӳ���Զ����� (User Generate) ��غ��� */
extern void BSTIM_EGR_UG_Clr(void);

/* ������ֵ (Counter) ��غ��� */
extern void BSTIM_CNT_Write(uint32_t SetValue);
extern uint32_t BSTIM_CNT_Read(void);

/* ������ʱ�ӣ�CK_CNT��Ԥ��Ƶֵ (Counter Clock Prescaler) ��غ��� */
extern void BSTIM_PSC_Write(uint32_t SetValue);
extern uint32_t BSTIM_PSC_Read(void);

/* �������ʱ���Զ�����ֵ (Auto-Reload Register) ��غ��� */
extern void BSTIM_ARR_Write(uint32_t SetValue);
extern uint32_t BSTIM_ARR_Read(void);
                
#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_BSTIM_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
