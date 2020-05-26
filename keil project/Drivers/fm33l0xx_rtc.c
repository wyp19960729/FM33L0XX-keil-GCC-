/**
  ******************************************************************************
  * @file    fm33l0xx_rtc.c
  * @author  FM33L0 Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33l0xx_rtc.h" 


/** @addtogroup fm33l0_StdPeriph_Driver
  * @{
  */

/** @defgroup RTC 
  * @brief RTC driver modules
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/************************************************************************************
RTCдʹ�ܼĴ��� ��غ��� 
����:�Ƿ�����CPU��RTC��BCDʱ��Ĵ���д���ֵ
����:д��0xACACACAC  , ����CPU��RTC��BCDʱ��Ĵ���д���ֵ, RTCWE��1
	     д�벻Ϊ0xACACACAC����ֵ,   �ָ�д����,RTCWE��0

**************************************************************************************/
void RTC_WER_Write(uint32_t SetValue)
{
	RTC->WER = (SetValue);
}

/* BCDʱ����Ĵ��� ��غ��� */
void RTC_BCDSEC_Write(uint32_t SetValue)
{
	RTC->BCDSEC = (SetValue & RTC_BCDSEC_SEC_Msk);
}

uint32_t RTC_BCDSEC_Read(void)
{
	return (RTC->BCDSEC & RTC_BCDSEC_SEC_Msk);
}

/* BCDʱ����ӼĴ��� ��غ��� */
void RTC_BCDMIN_Write(uint32_t SetValue)
{
	RTC->BCDMIN = (SetValue & RTC_BCDMIN_MIN_Msk);
}

uint32_t RTC_BCDMIN_Read(void)
{
	return (RTC->BCDMIN & RTC_BCDMIN_MIN_Msk);
}

/* BCDʱ��Сʱ�Ĵ��� ��غ��� */
void RTC_BCDHOUR_Write(uint32_t SetValue)
{
	RTC->BCDHOUR = (SetValue & RTC_BCDHOUR_HOUR_Msk);
}

uint32_t RTC_BCDHOUR_Read(void)
{
	return (RTC->BCDHOUR & RTC_BCDHOUR_HOUR_Msk);
}

/* BCDʱ����Ĵ��� ��غ��� */
void RTC_BCDDAY_Write(uint32_t SetValue)
{
	RTC->BCDDAY = (SetValue & RTC_BCDDAY_DAY_Msk);
}

uint32_t RTC_BCDDAY_Read(void)
{
	return (RTC->BCDDAY & RTC_BCDDAY_DAY_Msk);
}

/* BCDʱ�����ڼĴ��� ��غ��� */
void RTC_BCDWEEK_Write(uint32_t SetValue)
{
	RTC->BCDWEEK = (SetValue & RTC_BCDWEEK_WEEK_Msk);
}

uint32_t RTC_BCDWEEK_Read(void)
{
	return (RTC->BCDWEEK & RTC_BCDWEEK_WEEK_Msk);
}

/* BCDʱ���¼Ĵ��� ��غ��� */
void RTC_BCDMONTH_Write(uint32_t SetValue)
{
	RTC->BCDMONTH = (SetValue & RTC_BCDMONTH_MONTH_Msk);
}

uint32_t RTC_BCDMONTH_Read(void)
{
	return (RTC->BCDMONTH & RTC_BCDMONTH_MONTH_Msk);
}

/* BCDʱ����Ĵ��� ��غ��� */
void RTC_BCDYEAR_Write(uint32_t SetValue)
{
	RTC->BCDYEAR = (SetValue & RTC_BCDYEAR_YEAR_Msk);
}

uint32_t RTC_BCDYEAR_Read(void)
{
	return (RTC->BCDYEAR & RTC_BCDYEAR_YEAR_Msk);
}

/* ���ӵ�Сʱ��ֵ ��غ��� */
void RTC_ALARM_HOUR_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RTC->ALARM;
	tmpreg &= ~(RTC_ALARM_HOUR_Msk);
	tmpreg |= (SetValue & RTC_ALARM_HOUR_Msk);
	RTC->ALARM = tmpreg;
}

uint32_t RTC_ALARM_HOUR_Get(void)
{
	return (RTC->ALARM & RTC_ALARM_HOUR_Msk);
}

/* ���ӵķ���ֵ ��غ��� */
void RTC_ALARM_MIN_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RTC->ALARM;
	tmpreg &= ~(RTC_ALARM_MIN_Msk);
	tmpreg |= (SetValue & RTC_ALARM_MIN_Msk);
	RTC->ALARM = tmpreg;
}

uint32_t RTC_ALARM_MIN_Get(void)
{
	return (RTC->ALARM & RTC_ALARM_MIN_Msk);
}

/* ���ӵ�����ֵ ��غ��� */
void RTC_ALARM_SEC_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RTC->ALARM;
	tmpreg &= ~(RTC_ALARM_SEC_Msk);
	tmpreg |= (SetValue & RTC_ALARM_SEC_Msk);
	RTC->ALARM = tmpreg;
}

uint32_t RTC_ALARM_SEC_Get(void)
{
	return (RTC->ALARM & RTC_ALARM_SEC_Msk);
}

/* Ƶ�����ѡ���ź� ��غ��� */
void RTC_TMSEL_TMSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RTC->TMSEL;
	tmpreg &= ~(RTC_TMSEL_TMSEL_Msk);
	tmpreg |= (SetValue & RTC_TMSEL_TMSEL_Msk);
	RTC->TMSEL = tmpreg;
}

uint32_t RTC_TMSEL_TMSEL_Get(void)
{
	return (RTC->TMSEL & RTC_TMSEL_TMSEL_Msk);
}

/* LTBC����������ֵ ��غ��� */
void RTC_ADJUST_Write(uint32_t SetValue)
{
	RTC->ADJUST = (SetValue & RTC_ADJUST_ADJUST_Msk);
}

uint32_t RTC_ADJUST_Read(void)
{
	return (RTC->ADJUST & RTC_ADJUST_ADJUST_Msk);
}

/* LTBC�������� ��غ��� */
void RTC_ADSIGN_ADSIGN_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RTC->ADSIGN;
	tmpreg &= ~(RTC_ADSIGN_ADSIGN_Msk);
	tmpreg |= (SetValue & RTC_ADSIGN_ADSIGN_Msk);
	RTC->ADSIGN = tmpreg;
}

uint32_t RTC_ADSIGN_ADSIGN_Get(void)
{
	return (RTC->ADSIGN & RTC_ADSIGN_ADSIGN_Msk);
}

/* ���������ֵ����Чλ8bit������3.9ms ��غ��� */
void RTC_SBSCNT_Write(uint32_t SetValue)
{
	RTC->SBSCNT = (SetValue & RTC_SBSCNT_MSCNT_Msk);
}

uint32_t RTC_SBSCNT_Read(void)
{
	return (RTC->SBSCNT & RTC_SBSCNT_MSCNT_Msk);
}

/* ���ݼĴ���0���ɶ�д���޸�λֵ ��غ��� */
void RTC_BKR0_Write(uint32_t SetValue)
{
	RTC->BKR0 = (SetValue);
}

uint32_t RTC_BKR0_Read(void)
{
	return (RTC->BKR0);
}

/* ���ݼĴ���1���ɶ�д���޸�λֵ ��غ��� */
void RTC_BKR1_Write(uint32_t SetValue)
{
	RTC->BKR1 = (SetValue);
}

uint32_t RTC_BKR1_Read(void)
{
	return (RTC->BKR1);
}

/* ���ݼĴ���2���ɶ�д���޸�λֵ ��غ��� */
void RTC_BKR2_Write(uint32_t SetValue)
{
	RTC->BKR2 = (SetValue);
}

uint32_t RTC_BKR2_Read(void)
{
	return (RTC->BKR2);
}

/* ���ݼĴ���3���ɶ�д���޸�λֵ ��غ��� */
void RTC_BKR3_Write(uint32_t SetValue)
{
	RTC->BKR3 = (SetValue);
}

uint32_t RTC_BKR3_Read(void)
{
	return (RTC->BKR3);
}

/* ���ݼĴ���4���ɶ�д���޸�λֵ ��غ��� */
void RTC_BKR4_Write(uint32_t SetValue)
{
	RTC->BKR4 = (SetValue);
}

uint32_t RTC_BKR4_Read(void)
{
	return (RTC->BKR4);
}

/* ���ݼĴ���5���ɶ�д���޸�λֵ ��غ��� */
void RTC_BKR5_Write(uint32_t SetValue)
{
	RTC->BKR5 = (SetValue);
}

uint32_t RTC_BKR5_Read(void)
{
	return (RTC->BKR5);
}

/* ���ݼĴ���6���ɶ�д���޸�λֵ ��غ��� */
void RTC_BKR6_Write(uint32_t SetValue)
{
	RTC->BKR6 = (SetValue);
}

uint32_t RTC_BKR6_Read(void)
{
	return (RTC->BKR6);
}

/* ���ݼĴ���7���ɶ�д���޸�λֵ ��غ��� */
void RTC_BKR7_Write(uint32_t SetValue)
{
	RTC->BKR7 = (SetValue);
}

uint32_t RTC_BKR7_Read(void)
{
	return (RTC->BKR7);
}


void RTC_Deinit(void)
{
	//RTC->WER = 0x00000000;
	//RTC->IER = ;
	//RTC->ISR = ;
	//RTC->BCDSEC = ;
	//RTC->BCDMIN = ;
	//RTC->BCDHOUR = ;
	//RTC->BCDDAY = ;
	//RTC->BCDWEEK = ;
	//RTC->BCDMONTH = ;
	//RTC->BCDYEAR = ;
	//RTC->ALARM = 0x00000000;
	//RTC->TMSEL = 0x00000000;
	//RTC->ADJUST = ;
	//RTC->ADSIGN = ;
	//RTC->SBSCNT = ;
	//RTC->BKR0 = ;
	//RTC->BKR1 = ;
	//RTC->BKR2 = ;
	//RTC->BKR3 = ;
	//RTC->BKR4 = ;
	//RTC->BKR5 = ;
	//RTC->BKR6 = ;
	//RTC->BKR7 = ;
}
//Code_End


/********************************
RTC�ж�ʹ�ܺ���
����:RTC�ж�ʹ��
���룺������
      һ����ʹ��״̬
      ��һ����RTC����Ҫ�Ĺ��ܵ��ж�ʹ��
********************************/
void RTC_RTCIE_SetableEx(FunState NewState, uint32_t ie_def)
{
	if (NewState == ENABLE)
	{
		RTC->IER |= (ie_def);
	}
	else
	{
		RTC->IER &= ~(ie_def);
	}
}

/********************************
��ȡRTC����Ҫ�Ĺ��ܵ��ж�ʹ��״̬����
����:��ȡRTC����Ҫ�Ĺ��ܵ��ж�ʹ��״̬
������ж�ʹ��״̬
		
********************************/
FunState RTC_RTCIE_GetableEx(uint32_t ie_def)
{
	if (RTC->IER & (ie_def))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}


/********************************
���RTC�жϱ�־����
����:���RTC�жϱ�־
���룺Ҫ�������ʹ�õ�RTC�жϵ��жϱ�־
		
********************************/
void RTC_RTCIF_ClrEx(uint32_t if_def)
{
	RTC->ISR = (if_def);
}
/********************************
��ȡ��ʹ�õ�RTC�жϱ�־״̬����
����:��ȡRTC�жϱ�־״̬
�������ȡ��ʹ�õ�RTC�жϱ�־״̬
		
********************************/
FlagStatus RTC_RTCIF_ChkEx(uint32_t if_def)
{
	if (RTC->ISR & (if_def))
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
 RTC����ʱ�亯��
����:����ʱ�䣬�룬�֣�ʱ���죬�£��꣬�ܣ�BCD��ʽ
���룺Ҫ�����õ�ʱ������
		
********************************/
void RTC_TimeDate_SetEx(RTC_TimeDateTypeDef* para)
{
	RTC_BCDSEC_Write((uint32_t)para->Second);
	RTC_BCDMIN_Write((uint32_t)para->Minute);
	RTC_BCDHOUR_Write((uint32_t)para->Hour);
	RTC_BCDDAY_Write((uint32_t)para->Day);
	RTC_BCDMONTH_Write((uint32_t)para->Month);
	RTC_BCDYEAR_Write((uint32_t)para->Year);
	RTC_BCDWEEK_Write((uint32_t)para->Week);	
}

/********************************
 RTC��ȡʱ�亯��
����:��ȡʱ�䣬�룬�֣�ʱ���죬�£��꣬�ܣ�BCD��ʽ
�������ȡ��ǰʱ�䣬����Ϊ����
		
********************************/
void RTC_TimeDate_GetEx(RTC_TimeDateTypeDef* para)
{
	para->Second = RTC_BCDSEC_Read();
	para->Minute = RTC_BCDMIN_Read();
	para->Hour = RTC_BCDHOUR_Read();
	para->Day = RTC_BCDDAY_Read();
	para->Month = RTC_BCDMONTH_Read();
	para->Year = RTC_BCDYEAR_Read();
	para->Week = RTC_BCDWEEK_Read();	
}

/********************************
 RTC����ʱ�亯��
����:����ʱ�䣬�룬�֣�ʱ���죬�£��꣬�ܣ�BCD��ʽ
���룺Ҫ�����õ�ʱ������
		
********************************/
void RTC_TimeDate_SetBkpEx(RTC_TimeDateTypeDef* para)
{
	RTC_BKR0_Write((uint32_t)para->Second);
	RTC_BKR1_Write((uint32_t)para->Minute);
	RTC_BKR2_Write((uint32_t)para->Hour);
	RTC_BKR3_Write((uint32_t)para->Day);
	RTC_BKR4_Write((uint32_t)para->Month);
	RTC_BKR5_Write((uint32_t)para->Year);
	RTC_BKR7_Write((uint32_t)para->Week);	
}

/********************************
 RTC��ȡʱ�亯��
����:��ȡʱ�䣬�룬�֣�ʱ���죬�£��꣬�ܣ�BCD��ʽ
�������ȡ��ǰʱ�䣬����Ϊ����
		
********************************/
void RTC_TimeDate_GetBkpEx(RTC_TimeDateTypeDef* para)
{
	para->Second = RTC_BKR0_Read();
	para->Minute = RTC_BKR1_Read();
	para->Hour = RTC_BKR2_Read();
	para->Day = RTC_BKR3_Read();
	para->Month = RTC_BKR4_Read();
	para->Year = RTC_BKR5_Read();
	para->Week = RTC_BKR7_Read();	
}

/********************************
 RTC��������ʱ�亯��
����:��������ʱ�䣬�룬�֣�ʱ
���룺Ҫ�����õ�����ʱ������
		
********************************/
void RTC_AlarmTime_SetEx(RTC_AlarmTimeTypeDef* para)
{
	RTC_ALARM_SEC_Set(((uint32_t)para->Second<<RTC_ALARM_SEC_Pos));
	RTC_ALARM_MIN_Set(((uint32_t)para->Minute<<RTC_ALARM_MIN_Pos));
	RTC_ALARM_HOUR_Set(((uint32_t)para->Hour<<RTC_ALARM_HOUR_Pos));
}


/********************************
 ��ȡRTC����ʱ�亯��
����:��ȡ����ʱ�䣬�룬�֣�ʱ
�������ȡ����ʱ�䣬����Ϊ����
		
********************************/
void RTC_AlarmTime_GetEx(RTC_AlarmTimeTypeDef* para)
{
	para->Second = (RTC_ALARM_SEC_Get())>>RTC_ALARM_SEC_Pos;
	para->Minute = (RTC_ALARM_MIN_Get())>>RTC_ALARM_MIN_Pos;
	para->Hour = (RTC_ALARM_HOUR_Get())>>RTC_ALARM_HOUR_Pos;
}	

/******END OF FILE****/
