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
RTC写使能寄存器 相关函数 
功能:是否允许CPU向RTC的BCD时间寄存器写入初值
输入:写入0xACACACAC  , 允许CPU向RTC的BCD时间寄存器写入初值, RTCWE置1
	     写入不为0xACACACAC任意值,   恢复写保护,RTCWE清0

**************************************************************************************/
void RTC_WER_Write(uint32_t SetValue)
{
	RTC->WER = (SetValue);
}

/* BCD时间秒寄存器 相关函数 */
void RTC_BCDSEC_Write(uint32_t SetValue)
{
	RTC->BCDSEC = (SetValue & RTC_BCDSEC_SEC_Msk);
}

uint32_t RTC_BCDSEC_Read(void)
{
	return (RTC->BCDSEC & RTC_BCDSEC_SEC_Msk);
}

/* BCD时间分钟寄存器 相关函数 */
void RTC_BCDMIN_Write(uint32_t SetValue)
{
	RTC->BCDMIN = (SetValue & RTC_BCDMIN_MIN_Msk);
}

uint32_t RTC_BCDMIN_Read(void)
{
	return (RTC->BCDMIN & RTC_BCDMIN_MIN_Msk);
}

/* BCD时间小时寄存器 相关函数 */
void RTC_BCDHOUR_Write(uint32_t SetValue)
{
	RTC->BCDHOUR = (SetValue & RTC_BCDHOUR_HOUR_Msk);
}

uint32_t RTC_BCDHOUR_Read(void)
{
	return (RTC->BCDHOUR & RTC_BCDHOUR_HOUR_Msk);
}

/* BCD时间天寄存器 相关函数 */
void RTC_BCDDAY_Write(uint32_t SetValue)
{
	RTC->BCDDAY = (SetValue & RTC_BCDDAY_DAY_Msk);
}

uint32_t RTC_BCDDAY_Read(void)
{
	return (RTC->BCDDAY & RTC_BCDDAY_DAY_Msk);
}

/* BCD时间星期寄存器 相关函数 */
void RTC_BCDWEEK_Write(uint32_t SetValue)
{
	RTC->BCDWEEK = (SetValue & RTC_BCDWEEK_WEEK_Msk);
}

uint32_t RTC_BCDWEEK_Read(void)
{
	return (RTC->BCDWEEK & RTC_BCDWEEK_WEEK_Msk);
}

/* BCD时间月寄存器 相关函数 */
void RTC_BCDMONTH_Write(uint32_t SetValue)
{
	RTC->BCDMONTH = (SetValue & RTC_BCDMONTH_MONTH_Msk);
}

uint32_t RTC_BCDMONTH_Read(void)
{
	return (RTC->BCDMONTH & RTC_BCDMONTH_MONTH_Msk);
}

/* BCD时间年寄存器 相关函数 */
void RTC_BCDYEAR_Write(uint32_t SetValue)
{
	RTC->BCDYEAR = (SetValue & RTC_BCDYEAR_YEAR_Msk);
}

uint32_t RTC_BCDYEAR_Read(void)
{
	return (RTC->BCDYEAR & RTC_BCDYEAR_YEAR_Msk);
}

/* 闹钟的小时数值 相关函数 */
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

/* 闹钟的分数值 相关函数 */
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

/* 闹钟的秒数值 相关函数 */
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

/* 频率输出选择信号 相关函数 */
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

/* LTBC补偿调整数值 相关函数 */
void RTC_ADJUST_Write(uint32_t SetValue)
{
	RTC->ADJUST = (SetValue & RTC_ADJUST_ADJUST_Msk);
}

uint32_t RTC_ADJUST_Read(void)
{
	return (RTC->ADJUST & RTC_ADJUST_ADJUST_Msk);
}

/* LTBC补偿方向 相关函数 */
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

/* 毫秒计数器值，有效位8bit，精度3.9ms 相关函数 */
void RTC_SBSCNT_Write(uint32_t SetValue)
{
	RTC->SBSCNT = (SetValue & RTC_SBSCNT_MSCNT_Msk);
}

uint32_t RTC_SBSCNT_Read(void)
{
	return (RTC->SBSCNT & RTC_SBSCNT_MSCNT_Msk);
}

/* 备份寄存器0，可读写，无复位值 相关函数 */
void RTC_BKR0_Write(uint32_t SetValue)
{
	RTC->BKR0 = (SetValue);
}

uint32_t RTC_BKR0_Read(void)
{
	return (RTC->BKR0);
}

/* 备份寄存器1，可读写，无复位值 相关函数 */
void RTC_BKR1_Write(uint32_t SetValue)
{
	RTC->BKR1 = (SetValue);
}

uint32_t RTC_BKR1_Read(void)
{
	return (RTC->BKR1);
}

/* 备份寄存器2，可读写，无复位值 相关函数 */
void RTC_BKR2_Write(uint32_t SetValue)
{
	RTC->BKR2 = (SetValue);
}

uint32_t RTC_BKR2_Read(void)
{
	return (RTC->BKR2);
}

/* 备份寄存器3，可读写，无复位值 相关函数 */
void RTC_BKR3_Write(uint32_t SetValue)
{
	RTC->BKR3 = (SetValue);
}

uint32_t RTC_BKR3_Read(void)
{
	return (RTC->BKR3);
}

/* 备份寄存器4，可读写，无复位值 相关函数 */
void RTC_BKR4_Write(uint32_t SetValue)
{
	RTC->BKR4 = (SetValue);
}

uint32_t RTC_BKR4_Read(void)
{
	return (RTC->BKR4);
}

/* 备份寄存器5，可读写，无复位值 相关函数 */
void RTC_BKR5_Write(uint32_t SetValue)
{
	RTC->BKR5 = (SetValue);
}

uint32_t RTC_BKR5_Read(void)
{
	return (RTC->BKR5);
}

/* 备份寄存器6，可读写，无复位值 相关函数 */
void RTC_BKR6_Write(uint32_t SetValue)
{
	RTC->BKR6 = (SetValue);
}

uint32_t RTC_BKR6_Read(void)
{
	return (RTC->BKR6);
}

/* 备份寄存器7，可读写，无复位值 相关函数 */
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
RTC中断使能函数
功能:RTC中断使能
输入：有两个
      一个是使能状态
      另一个是RTC所需要的功能的中断使能
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
读取RTC所需要的功能的中断使能状态函数
功能:读取RTC所需要的功能的中断使能状态
输出：中断使能状态
		
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
清除RTC中断标志函数
功能:清除RTC中断标志
输入：要清除的所使用的RTC中断的中断标志
		
********************************/
void RTC_RTCIF_ClrEx(uint32_t if_def)
{
	RTC->ISR = (if_def);
}
/********************************
读取所使用的RTC中断标志状态函数
功能:读取RTC中断标志状态
输出：读取所使用的RTC中断标志状态
		
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
 RTC设置时间函数
功能:设置时间，秒，分，时，天，月，年，周，BCD格式
输入：要求设置的时间数组
		
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
 RTC读取时间函数
功能:读取时间，秒，分，时，天，月，年，周，BCD格式
输出：读取当前时间，保存为数组
		
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
 RTC设置时间函数
功能:设置时间，秒，分，时，天，月，年，周，BCD格式
输入：要求设置的时间数组
		
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
 RTC读取时间函数
功能:读取时间，秒，分，时，天，月，年，周，BCD格式
输出：读取当前时间，保存为数组
		
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
 RTC闹钟设置时间函数
功能:设置闹钟时间，秒，分，时
输入：要求设置的闹钟时间数组
		
********************************/
void RTC_AlarmTime_SetEx(RTC_AlarmTimeTypeDef* para)
{
	RTC_ALARM_SEC_Set(((uint32_t)para->Second<<RTC_ALARM_SEC_Pos));
	RTC_ALARM_MIN_Set(((uint32_t)para->Minute<<RTC_ALARM_MIN_Pos));
	RTC_ALARM_HOUR_Set(((uint32_t)para->Hour<<RTC_ALARM_HOUR_Pos));
}


/********************************
 读取RTC闹钟时间函数
功能:读取闹钟时间，秒，分，时
输出：读取闹钟时间，保存为数组
		
********************************/
void RTC_AlarmTime_GetEx(RTC_AlarmTimeTypeDef* para)
{
	para->Second = (RTC_ALARM_SEC_Get())>>RTC_ALARM_SEC_Pos;
	para->Minute = (RTC_ALARM_MIN_Get())>>RTC_ALARM_MIN_Pos;
	para->Hour = (RTC_ALARM_HOUR_Get())>>RTC_ALARM_HOUR_Pos;
}	

/******END OF FILE****/
