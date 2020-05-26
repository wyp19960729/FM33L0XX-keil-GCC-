/**
  ******************************************************************************
  * @file    fm33l0xx_rtc.h
  * @author  FM33L0xx Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file contains all the functions prototypes for the RTC firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33L0XX_RTC_H
#define __FM33L0XX_RTC_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33L0XX.h"

//------------------------------------------------------------------------------

/* Exported constants --------------------------------------------------------*/
#define RTC_WRITE_DISABLE					((uint32_t)0x53535353)
#define RTC_WRITE_ENABLE					((uint32_t)0xACACACAC)
/* Exported types ------------------------------------------------------------*/	 
typedef struct
{       
	uint8_t			Year;		/*!<RTC ��*/
	uint8_t			Month;		/*!<RTC ��*/
	uint8_t			Day;		/*!<RTC ��*/	
	uint8_t			Hour;		/*!<RTC ʱ*/
	uint8_t			Minute;		/*!<RTC ��*/	
	uint8_t			Second;		/*!<RTC ��*/			
	uint8_t			Week;		/*!<RTC ��*/	

}RTC_TimeDateTypeDef,RTC_StampTimeTypeDef;

typedef struct
{     
	uint8_t			Hour;		/*!<RTC���� ʱ*/		
	uint8_t			Minute;		/*!<RTC���� ��*/
	uint8_t			Second;		/*!<RTC���� ��*/

}RTC_AlarmTimeTypeDef;


/* Exported macro ------------------------------------------------------------*/



//��0x811800��ʼ�ᱣ��������Ϣ
#define const_tx_flag  		(*((uint16_t *)(0x1ffffa20))) //��У��־(0x3cc3Ϊ��̵�У)
#define const_rtc_adj_top 	(*((int16_t *)(0x1ffffa36))) //�������ppm,0.01ppm
#define const_rtc_backup 	0x1FFFF800  //RTC���ݼĴ����׵�ַ
#define	RTC_WER_WE_Pos	0	/* RTCдʹ�ܼĴ��� */
#define	RTC_WER_WE_Msk	(0xffffffffU << RTC_WER_WE_Pos)

#define	RTC_IER_ADJ_IE_Pos	12	/* ��У�����ж�ʹ�� */
#define	RTC_IER_ADJ_IE_Msk	(0x1U << RTC_IER_ADJ_IE_Pos)

#define	RTC_IER_ALARM_IE_Pos	11	/* �����ж�ʹ�� */
#define	RTC_IER_ALARM_IE_Msk	(0x1U << RTC_IER_ALARM_IE_Pos)

#define	RTC_IER_1KHZ_IE_Pos	10	/* 1khz�ж�ʹ�� */
#define	RTC_IER_1KHZ_IE_Msk	(0x1U << RTC_IER_1KHZ_IE_Pos)

#define	RTC_IER_256HZ_IE_Pos	9	/* 256hz�ж�ʹ�� */
#define	RTC_IER_256HZ_IE_Msk	(0x1U << RTC_IER_256HZ_IE_Pos)

#define	RTC_IER_64HZ_IE_Pos	8	/* 64hz�ж�ʹ�� */
#define	RTC_IER_64HZ_IE_Msk	(0x1U << RTC_IER_64HZ_IE_Pos)

#define	RTC_IER_16HZ_IE_Pos	7	/* 16hz�ж�ʹ�� */
#define	RTC_IER_16HZ_IE_Msk	(0x1U << RTC_IER_16HZ_IE_Pos)

#define	RTC_IER_8HZ_IE_Pos	6	/* 8hz�ж�ʹ�� */
#define	RTC_IER_8HZ_IE_Msk	(0x1U << RTC_IER_8HZ_IE_Pos)

#define	RTC_IER_4HZ_IE_Pos	5	/* 4hz�ж�ʹ�� */
#define	RTC_IER_4HZ_IE_Msk	(0x1U << RTC_IER_4HZ_IE_Pos)

#define	RTC_IER_2HZ_IE_Pos	4	/* 2hz�ж�ʹ�� */
#define	RTC_IER_2HZ_IE_Msk	(0x1U << RTC_IER_2HZ_IE_Pos)

#define	RTC_IER_SEC_IE_Pos	3	/* ���ж�ʹ�� */
#define	RTC_IER_SEC_IE_Msk	(0x1U << RTC_IER_SEC_IE_Pos)

#define	RTC_IER_MIN_IE_Pos	2	/* ���ж�ʹ�� */
#define	RTC_IER_MIN_IE_Msk	(0x1U << RTC_IER_MIN_IE_Pos)

#define	RTC_IER_HOUR_IE_Pos	1	/* Сʱ�ж�ʹ�� */
#define	RTC_IER_HOUR_IE_Msk	(0x1U << RTC_IER_HOUR_IE_Pos)

#define	RTC_IER_DAY_IE_Pos	0	/* ���ж�ʹ�� */
#define	RTC_IER_DAY_IE_Msk	(0x1U << RTC_IER_DAY_IE_Pos)

#define	RTC_ISR_ADJ_IF_Pos	12	/* ��У�����жϱ�־ */
#define	RTC_ISR_ADJ_IF_Msk	(0x1U << RTC_ISR_ADJ_IF_Pos)

#define	RTC_ISR_ALARM_IF_Pos	11	/* �����жϱ�־ */
#define	RTC_ISR_ALARM_IF_Msk	(0x1U << RTC_ISR_ALARM_IF_Pos)

#define	RTC_ISR_1KHZ_IF_Pos	10	/* 1khz�жϱ�־ */
#define	RTC_ISR_1KHZ_IF_Msk	(0x1U << RTC_ISR_1KHZ_IF_Pos)

#define	RTC_ISR_256HZ_IF_Pos	9	/* 256hz�жϱ�־ */
#define	RTC_ISR_256HZ_IF_Msk	(0x1U << RTC_ISR_256HZ_IF_Pos)

#define	RTC_ISR_64HZ_IF_Pos	8	/* 64hz�жϱ�־ */
#define	RTC_ISR_64HZ_IF_Msk	(0x1U << RTC_ISR_64HZ_IF_Pos)

#define	RTC_ISR_16HZ_IF_Pos	7	/* 16hz�жϱ�־ */
#define	RTC_ISR_16HZ_IF_Msk	(0x1U << RTC_ISR_16HZ_IF_Pos)

#define	RTC_ISR_8HZ_IF_Pos	6	/* 8hz�жϱ�־ */
#define	RTC_ISR_8HZ_IF_Msk	(0x1U << RTC_ISR_8HZ_IF_Pos)

#define	RTC_ISR_4HZ_IF_Pos	5	/* 4hz�жϱ�־ */
#define	RTC_ISR_4HZ_IF_Msk	(0x1U << RTC_ISR_4HZ_IF_Pos)

#define	RTC_ISR_2HZ_IF_Pos	4	/* 2hz�жϱ�־ */
#define	RTC_ISR_2HZ_IF_Msk	(0x1U << RTC_ISR_2HZ_IF_Pos)

#define	RTC_ISR_SEC_IF_Pos	3	/* ���жϱ�־ */
#define	RTC_ISR_SEC_IF_Msk	(0x1U << RTC_ISR_SEC_IF_Pos)

#define	RTC_ISR_MIN_IF_Pos	2	/* ���жϱ�־ */
#define	RTC_ISR_MIN_IF_Msk	(0x1U << RTC_ISR_MIN_IF_Pos)

#define	RTC_ISR_HOUR_IF_Pos	1	/* Сʱ�жϱ�־ */
#define	RTC_ISR_HOUR_IF_Msk	(0x1U << RTC_ISR_HOUR_IF_Pos)

#define	RTC_ISR_DAY_IF_Pos	0	/* ���жϱ�־ */
#define	RTC_ISR_DAY_IF_Msk	(0x1U << RTC_ISR_DAY_IF_Pos)

#define	RTC_BCDSEC_SEC_Pos	0	/* BCDʱ����Ĵ��� */
#define	RTC_BCDSEC_SEC_Msk	(0x7fU << RTC_BCDSEC_SEC_Pos)

#define	RTC_BCDMIN_MIN_Pos	0	/* BCDʱ����ӼĴ��� */
#define	RTC_BCDMIN_MIN_Msk	(0x7fU << RTC_BCDMIN_MIN_Pos)

#define	RTC_BCDHOUR_HOUR_Pos	0	/* BCDʱ��Сʱ�Ĵ��� */
#define	RTC_BCDHOUR_HOUR_Msk	(0x3fU << RTC_BCDHOUR_HOUR_Pos)

#define	RTC_BCDDAY_DAY_Pos	0	/* BCDʱ����Ĵ��� */
#define	RTC_BCDDAY_DAY_Msk	(0x3fU << RTC_BCDDAY_DAY_Pos)

#define	RTC_BCDWEEK_WEEK_Pos	0	/* BCDʱ�����ڼĴ��� */
#define	RTC_BCDWEEK_WEEK_Msk	(0x7U << RTC_BCDWEEK_WEEK_Pos)

#define	RTC_BCDMONTH_MONTH_Pos	0	/* BCDʱ���¼Ĵ��� */
#define	RTC_BCDMONTH_MONTH_Msk	(0x1fU << RTC_BCDMONTH_MONTH_Pos)

#define	RTC_BCDYEAR_YEAR_Pos	0	/* BCDʱ����Ĵ��� */
#define	RTC_BCDYEAR_YEAR_Msk	(0xffU << RTC_BCDYEAR_YEAR_Pos)

#define	RTC_ALARM_HOUR_Pos	16	/* ���ӵ�Сʱ��ֵ */
#define	RTC_ALARM_HOUR_Msk	(0x3fU << RTC_ALARM_HOUR_Pos)

#define	RTC_ALARM_MIN_Pos	8	/* ���ӵķ���ֵ */
#define	RTC_ALARM_MIN_Msk	(0x7fU << RTC_ALARM_MIN_Pos)

#define	RTC_ALARM_SEC_Pos	0	/* ���ӵ�����ֵ */
#define	RTC_ALARM_SEC_Msk	(0x7fU << RTC_ALARM_SEC_Pos)

#define	RTC_TMSEL_TMSEL_Pos	0	/* Ƶ�����ѡ���ź� */
#define	RTC_TMSEL_TMSEL_Msk	(0xfU << RTC_TMSEL_TMSEL_Pos)
#define	RTC_TMSEL_TMSEL_SECOND	(0x2U << RTC_TMSEL_TMSEL_Pos)	/* 4��b0010��������������λ�źţ��ߵ�ƽ���1s */
#define	RTC_TMSEL_TMSEL_MINUTE	(0x3U << RTC_TMSEL_TMSEL_Pos)	/* 4��b0011������ּ�������λ�źţ��ߵ�ƽ���1s */
#define	RTC_TMSEL_TMSEL_HOUR	(0x4U << RTC_TMSEL_TMSEL_Pos)	/* 4��b0100�����Сʱ��������λ�źţ��ߵ�ƽ���1s */
#define	RTC_TMSEL_TMSEL_DAY	(0x5U << RTC_TMSEL_TMSEL_Pos)	/* 4��b0101��������������λ�źţ��ߵ�ƽ���1s */
#define	RTC_TMSEL_TMSEL_ALARM	(0x6U << RTC_TMSEL_TMSEL_Pos)	/* 4��b0110���������ƥ���ź� */
#define	RTC_TMSEL_TMSEL_32S	(0x7U << RTC_TMSEL_TMSEL_Pos)	/* 4��b0111�����32�뷽���ź� */
#define	RTC_TMSEL_TMSEL_SECONDREV	(0x9U << RTC_TMSEL_TMSEL_Pos)	/* 4��b1001������������������λ�ź� */
#define	RTC_TMSEL_TMSEL_MINUTEREV	(0xaU << RTC_TMSEL_TMSEL_Pos)	/* 4��b1010����������ּ�������λ�ź� */
#define	RTC_TMSEL_TMSEL_HOURREV	(0xbU << RTC_TMSEL_TMSEL_Pos)	/* 4��b1011���������Сʱ��������λ�ź� */
#define	RTC_TMSEL_TMSEL_DAYREV	(0xcU << RTC_TMSEL_TMSEL_Pos)	/* 4��b1100������������������λ�ź� */
#define	RTC_TMSEL_TMSEL_ALARMREV	(0xdU << RTC_TMSEL_TMSEL_Pos)	/* 4��b1101�������������ƥ���ź� */
#define	RTC_TMSEL_TMSEL_SECONDRUN	(0xfU << RTC_TMSEL_TMSEL_Pos)	/* 4��b1111�����RTC�ڲ���ʱ�귽�� */

#define	RTC_ADJUST_ADJUST_Pos	0	/* LTBC����������ֵ */
#define	RTC_ADJUST_ADJUST_Msk	(0x1ffU << RTC_ADJUST_ADJUST_Pos)

#define	RTC_ADSIGN_ADSIGN_Pos	0	/* LTBC�������� */
#define	RTC_ADSIGN_ADSIGN_Msk	(0x1U << RTC_ADSIGN_ADSIGN_Pos)
#define	RTC_ADSIGN_ADSIGN_PLUS	(0x0U << RTC_ADSIGN_ADSIGN_Pos)	/* 0����ʾ���Ӽ�����ֵ */
#define	RTC_ADSIGN_ADSIGN_MINUS	(0x1U << RTC_ADSIGN_ADSIGN_Pos)	/* 1����ʾ���ټ�����ֵ */

#define	RTC_SBSCNT_MSCNT_Pos	0	/* ���������ֵ����Чλ8bit������3.9ms */
#define	RTC_SBSCNT_MSCNT_Msk	(0xffU << RTC_SBSCNT_MSCNT_Pos)

#define	RTC_BKR0_BKP_Pos	0	/* ���ݼĴ���0���ɶ�д���޸�λֵ */
#define	RTC_BKR0_BKP_Msk	(0xffffffffU << RTC_BKR0_BKP_Pos)

#define	RTC_BKR1_BKP_Pos	0	/* ���ݼĴ���1���ɶ�д���޸�λֵ */
#define	RTC_BKR1_BKP_Msk	(0xffffffffU << RTC_BKR1_BKP_Pos)

#define	RTC_BKR2_BKP_Pos	0	/* ���ݼĴ���2���ɶ�д���޸�λֵ */
#define	RTC_BKR2_BKP_Msk	(0xffffffffU << RTC_BKR2_BKP_Pos)

#define	RTC_BKR3_BKP_Pos	0	/* ���ݼĴ���3���ɶ�д���޸�λֵ */
#define	RTC_BKR3_BKP_Msk	(0xffffffffU << RTC_BKR3_BKP_Pos)

#define	RTC_BKR4_BKP_Pos	0	/* ���ݼĴ���4���ɶ�д���޸�λֵ */
#define	RTC_BKR4_BKP_Msk	(0xffffffffU << RTC_BKR4_BKP_Pos)

#define	RTC_BKR5_BKP_Pos	0	/* ���ݼĴ���5���ɶ�д���޸�λֵ */
#define	RTC_BKR5_BKP_Msk	(0xffffffffU << RTC_BKR5_BKP_Pos)

#define	RTC_BKR6_BKP_Pos	0	/* ���ݼĴ���6���ɶ�д���޸�λֵ */
#define	RTC_BKR6_BKP_Msk	(0xffffffffU << RTC_BKR6_BKP_Pos)

#define	RTC_BKR7_BKP_Pos	0	/* ���ݼĴ���7���ɶ�д���޸�λֵ */
#define	RTC_BKR7_BKP_Msk	(0xffffffffU << RTC_BKR7_BKP_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void RTC_Deinit(void);

/* RTCдʹ�ܼĴ��� ��غ��� */
extern void RTC_WER_Write(uint32_t SetValue);

/* BCDʱ����Ĵ��� ��غ��� */
extern void RTC_BCDSEC_Write(uint32_t SetValue);
extern uint32_t RTC_BCDSEC_Read(void);

/* BCDʱ����ӼĴ��� ��غ��� */
extern void RTC_BCDMIN_Write(uint32_t SetValue);
extern uint32_t RTC_BCDMIN_Read(void);

/* BCDʱ��Сʱ�Ĵ��� ��غ��� */
extern void RTC_BCDHOUR_Write(uint32_t SetValue);
extern uint32_t RTC_BCDHOUR_Read(void);

/* BCDʱ����Ĵ��� ��غ��� */
extern void RTC_BCDDAY_Write(uint32_t SetValue);
extern uint32_t RTC_BCDDAY_Read(void);

/* BCDʱ�����ڼĴ��� ��غ��� */
extern void RTC_BCDWEEK_Write(uint32_t SetValue);
extern uint32_t RTC_BCDWEEK_Read(void);

/* BCDʱ���¼Ĵ��� ��غ��� */
extern void RTC_BCDMONTH_Write(uint32_t SetValue);
extern uint32_t RTC_BCDMONTH_Read(void);

/* BCDʱ����Ĵ��� ��غ��� */
extern void RTC_BCDYEAR_Write(uint32_t SetValue);
extern uint32_t RTC_BCDYEAR_Read(void);

/* ���ӵ�Сʱ��ֵ ��غ��� */
extern void RTC_ALARM_HOUR_Set(uint32_t SetValue);
extern uint32_t RTC_ALARM_HOUR_Get(void);

/* ���ӵķ���ֵ ��غ��� */
extern void RTC_ALARM_MIN_Set(uint32_t SetValue);
extern uint32_t RTC_ALARM_MIN_Get(void);

/* ���ӵ�����ֵ ��غ��� */
extern void RTC_ALARM_SEC_Set(uint32_t SetValue);
extern uint32_t RTC_ALARM_SEC_Get(void);

/* Ƶ�����ѡ���ź� ��غ��� */
extern void RTC_TMSEL_TMSEL_Set(uint32_t SetValue);
extern uint32_t RTC_TMSEL_TMSEL_Get(void);

/* LTBC����������ֵ ��غ��� */
extern void RTC_ADJUST_Write(uint32_t SetValue);
extern uint32_t RTC_ADJUST_Read(void);

/* LTBC�������� ��غ��� */
extern void RTC_ADSIGN_ADSIGN_Set(uint32_t SetValue);
extern uint32_t RTC_ADSIGN_ADSIGN_Get(void);

/* ���������ֵ����Чλ8bit������3.9ms ��غ��� */
extern void RTC_SBSCNT_Write(uint32_t SetValue);
extern uint32_t RTC_SBSCNT_Read(void);

/* ���ݼĴ���0���ɶ�д���޸�λֵ ��غ��� */
extern void RTC_BKR0_Write(uint32_t SetValue);
extern uint32_t RTC_BKR0_Read(void);

/* ���ݼĴ���1���ɶ�д���޸�λֵ ��غ��� */
extern void RTC_BKR1_Write(uint32_t SetValue);
extern uint32_t RTC_BKR1_Read(void);

/* ���ݼĴ���2���ɶ�д���޸�λֵ ��غ��� */
extern void RTC_BKR2_Write(uint32_t SetValue);
extern uint32_t RTC_BKR2_Read(void);

/* ���ݼĴ���3���ɶ�д���޸�λֵ ��غ��� */
extern void RTC_BKR3_Write(uint32_t SetValue);
extern uint32_t RTC_BKR3_Read(void);

/* ���ݼĴ���4���ɶ�д���޸�λֵ ��غ��� */
extern void RTC_BKR4_Write(uint32_t SetValue);
extern uint32_t RTC_BKR4_Read(void);

/* ���ݼĴ���5���ɶ�д���޸�λֵ ��غ��� */
extern void RTC_BKR5_Write(uint32_t SetValue);
extern uint32_t RTC_BKR5_Read(void);

/* ���ݼĴ���6���ɶ�д���޸�λֵ ��غ��� */
extern void RTC_BKR6_Write(uint32_t SetValue);
extern uint32_t RTC_BKR6_Read(void);

/* ���ݼĴ���7���ɶ�д���޸�λֵ ��غ��� */
extern void RTC_BKR7_Write(uint32_t SetValue);
extern uint32_t RTC_BKR7_Read(void);
//Announce_End
/* RTC�ж�ʹ�ܼĴ��� ��غ��� */
extern void RTC_RTCIE_SetableEx(FunState NewState, uint32_t ie_def);

extern FunState RTC_RTCIE_GetableEx(uint32_t ie_def);

/* RTC�жϱ�־ ��غ��� */
extern void RTC_RTCIF_ClrEx(uint32_t if_def);

extern FlagStatus RTC_RTCIF_ChkEx(uint32_t if_def);

/* RTC����ʱ�� *///ע��Ҫ�ȴ�д������������ʱ��
extern void RTC_TimeDate_SetEx(RTC_TimeDateTypeDef* para);

/* RTC��ȡʱ�� */
extern void RTC_TimeDate_GetEx(RTC_TimeDateTypeDef* para);

/* ����ʱ������ */
extern void RTC_AlarmTime_SetEx(RTC_AlarmTimeTypeDef* para);

/* ����ʱ���ȡ */
extern void RTC_AlarmTime_GetEx(RTC_AlarmTimeTypeDef* para);
	
/* ʱ������ݶ�ȡ */
extern void RTC_CLKSTAMPxx_GetEx(uint8_t StampType_def, RTC_StampTimeTypeDef* para);

extern void RTC_TimeDate_GetBkpEx(RTC_TimeDateTypeDef* para);
extern void RTC_TimeDate_SetBkpEx(RTC_TimeDateTypeDef* para);

#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_RTC_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
