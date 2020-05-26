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
	uint8_t			Year;		/*!<RTC 年*/
	uint8_t			Month;		/*!<RTC 月*/
	uint8_t			Day;		/*!<RTC 日*/	
	uint8_t			Hour;		/*!<RTC 时*/
	uint8_t			Minute;		/*!<RTC 分*/	
	uint8_t			Second;		/*!<RTC 秒*/			
	uint8_t			Week;		/*!<RTC 周*/	

}RTC_TimeDateTypeDef,RTC_StampTimeTypeDef;

typedef struct
{     
	uint8_t			Hour;		/*!<RTC闹钟 时*/		
	uint8_t			Minute;		/*!<RTC闹钟 分*/
	uint8_t			Second;		/*!<RTC闹钟 秒*/

}RTC_AlarmTimeTypeDef;


/* Exported macro ------------------------------------------------------------*/



//从0x811800开始会保存如下信息
#define const_tx_flag  		(*((uint16_t *)(0x1ffffa20))) //调校标志(0x3cc3为编程调校)
#define const_rtc_adj_top 	(*((int16_t *)(0x1ffffa36))) //顶点误差ppm,0.01ppm
#define const_rtc_backup 	0x1FFFF800  //RTC备份寄存器首地址
#define	RTC_WER_WE_Pos	0	/* RTC写使能寄存器 */
#define	RTC_WER_WE_Msk	(0xffffffffU << RTC_WER_WE_Pos)

#define	RTC_IER_ADJ_IE_Pos	12	/* 调校周期中断使能 */
#define	RTC_IER_ADJ_IE_Msk	(0x1U << RTC_IER_ADJ_IE_Pos)

#define	RTC_IER_ALARM_IE_Pos	11	/* 闹钟中断使能 */
#define	RTC_IER_ALARM_IE_Msk	(0x1U << RTC_IER_ALARM_IE_Pos)

#define	RTC_IER_1KHZ_IE_Pos	10	/* 1khz中断使能 */
#define	RTC_IER_1KHZ_IE_Msk	(0x1U << RTC_IER_1KHZ_IE_Pos)

#define	RTC_IER_256HZ_IE_Pos	9	/* 256hz中断使能 */
#define	RTC_IER_256HZ_IE_Msk	(0x1U << RTC_IER_256HZ_IE_Pos)

#define	RTC_IER_64HZ_IE_Pos	8	/* 64hz中断使能 */
#define	RTC_IER_64HZ_IE_Msk	(0x1U << RTC_IER_64HZ_IE_Pos)

#define	RTC_IER_16HZ_IE_Pos	7	/* 16hz中断使能 */
#define	RTC_IER_16HZ_IE_Msk	(0x1U << RTC_IER_16HZ_IE_Pos)

#define	RTC_IER_8HZ_IE_Pos	6	/* 8hz中断使能 */
#define	RTC_IER_8HZ_IE_Msk	(0x1U << RTC_IER_8HZ_IE_Pos)

#define	RTC_IER_4HZ_IE_Pos	5	/* 4hz中断使能 */
#define	RTC_IER_4HZ_IE_Msk	(0x1U << RTC_IER_4HZ_IE_Pos)

#define	RTC_IER_2HZ_IE_Pos	4	/* 2hz中断使能 */
#define	RTC_IER_2HZ_IE_Msk	(0x1U << RTC_IER_2HZ_IE_Pos)

#define	RTC_IER_SEC_IE_Pos	3	/* 秒中断使能 */
#define	RTC_IER_SEC_IE_Msk	(0x1U << RTC_IER_SEC_IE_Pos)

#define	RTC_IER_MIN_IE_Pos	2	/* 分中断使能 */
#define	RTC_IER_MIN_IE_Msk	(0x1U << RTC_IER_MIN_IE_Pos)

#define	RTC_IER_HOUR_IE_Pos	1	/* 小时中断使能 */
#define	RTC_IER_HOUR_IE_Msk	(0x1U << RTC_IER_HOUR_IE_Pos)

#define	RTC_IER_DAY_IE_Pos	0	/* 天中断使能 */
#define	RTC_IER_DAY_IE_Msk	(0x1U << RTC_IER_DAY_IE_Pos)

#define	RTC_ISR_ADJ_IF_Pos	12	/* 调校周期中断标志 */
#define	RTC_ISR_ADJ_IF_Msk	(0x1U << RTC_ISR_ADJ_IF_Pos)

#define	RTC_ISR_ALARM_IF_Pos	11	/* 闹钟中断标志 */
#define	RTC_ISR_ALARM_IF_Msk	(0x1U << RTC_ISR_ALARM_IF_Pos)

#define	RTC_ISR_1KHZ_IF_Pos	10	/* 1khz中断标志 */
#define	RTC_ISR_1KHZ_IF_Msk	(0x1U << RTC_ISR_1KHZ_IF_Pos)

#define	RTC_ISR_256HZ_IF_Pos	9	/* 256hz中断标志 */
#define	RTC_ISR_256HZ_IF_Msk	(0x1U << RTC_ISR_256HZ_IF_Pos)

#define	RTC_ISR_64HZ_IF_Pos	8	/* 64hz中断标志 */
#define	RTC_ISR_64HZ_IF_Msk	(0x1U << RTC_ISR_64HZ_IF_Pos)

#define	RTC_ISR_16HZ_IF_Pos	7	/* 16hz中断标志 */
#define	RTC_ISR_16HZ_IF_Msk	(0x1U << RTC_ISR_16HZ_IF_Pos)

#define	RTC_ISR_8HZ_IF_Pos	6	/* 8hz中断标志 */
#define	RTC_ISR_8HZ_IF_Msk	(0x1U << RTC_ISR_8HZ_IF_Pos)

#define	RTC_ISR_4HZ_IF_Pos	5	/* 4hz中断标志 */
#define	RTC_ISR_4HZ_IF_Msk	(0x1U << RTC_ISR_4HZ_IF_Pos)

#define	RTC_ISR_2HZ_IF_Pos	4	/* 2hz中断标志 */
#define	RTC_ISR_2HZ_IF_Msk	(0x1U << RTC_ISR_2HZ_IF_Pos)

#define	RTC_ISR_SEC_IF_Pos	3	/* 秒中断标志 */
#define	RTC_ISR_SEC_IF_Msk	(0x1U << RTC_ISR_SEC_IF_Pos)

#define	RTC_ISR_MIN_IF_Pos	2	/* 分中断标志 */
#define	RTC_ISR_MIN_IF_Msk	(0x1U << RTC_ISR_MIN_IF_Pos)

#define	RTC_ISR_HOUR_IF_Pos	1	/* 小时中断标志 */
#define	RTC_ISR_HOUR_IF_Msk	(0x1U << RTC_ISR_HOUR_IF_Pos)

#define	RTC_ISR_DAY_IF_Pos	0	/* 天中断标志 */
#define	RTC_ISR_DAY_IF_Msk	(0x1U << RTC_ISR_DAY_IF_Pos)

#define	RTC_BCDSEC_SEC_Pos	0	/* BCD时间秒寄存器 */
#define	RTC_BCDSEC_SEC_Msk	(0x7fU << RTC_BCDSEC_SEC_Pos)

#define	RTC_BCDMIN_MIN_Pos	0	/* BCD时间分钟寄存器 */
#define	RTC_BCDMIN_MIN_Msk	(0x7fU << RTC_BCDMIN_MIN_Pos)

#define	RTC_BCDHOUR_HOUR_Pos	0	/* BCD时间小时寄存器 */
#define	RTC_BCDHOUR_HOUR_Msk	(0x3fU << RTC_BCDHOUR_HOUR_Pos)

#define	RTC_BCDDAY_DAY_Pos	0	/* BCD时间天寄存器 */
#define	RTC_BCDDAY_DAY_Msk	(0x3fU << RTC_BCDDAY_DAY_Pos)

#define	RTC_BCDWEEK_WEEK_Pos	0	/* BCD时间星期寄存器 */
#define	RTC_BCDWEEK_WEEK_Msk	(0x7U << RTC_BCDWEEK_WEEK_Pos)

#define	RTC_BCDMONTH_MONTH_Pos	0	/* BCD时间月寄存器 */
#define	RTC_BCDMONTH_MONTH_Msk	(0x1fU << RTC_BCDMONTH_MONTH_Pos)

#define	RTC_BCDYEAR_YEAR_Pos	0	/* BCD时间年寄存器 */
#define	RTC_BCDYEAR_YEAR_Msk	(0xffU << RTC_BCDYEAR_YEAR_Pos)

#define	RTC_ALARM_HOUR_Pos	16	/* 闹钟的小时数值 */
#define	RTC_ALARM_HOUR_Msk	(0x3fU << RTC_ALARM_HOUR_Pos)

#define	RTC_ALARM_MIN_Pos	8	/* 闹钟的分数值 */
#define	RTC_ALARM_MIN_Msk	(0x7fU << RTC_ALARM_MIN_Pos)

#define	RTC_ALARM_SEC_Pos	0	/* 闹钟的秒数值 */
#define	RTC_ALARM_SEC_Msk	(0x7fU << RTC_ALARM_SEC_Pos)

#define	RTC_TMSEL_TMSEL_Pos	0	/* 频率输出选择信号 */
#define	RTC_TMSEL_TMSEL_Msk	(0xfU << RTC_TMSEL_TMSEL_Pos)
#define	RTC_TMSEL_TMSEL_SECOND	(0x2U << RTC_TMSEL_TMSEL_Pos)	/* 4’b0010：输出秒计数器进位信号，高电平宽度1s */
#define	RTC_TMSEL_TMSEL_MINUTE	(0x3U << RTC_TMSEL_TMSEL_Pos)	/* 4’b0011：输出分计数器进位信号，高电平宽度1s */
#define	RTC_TMSEL_TMSEL_HOUR	(0x4U << RTC_TMSEL_TMSEL_Pos)	/* 4’b0100：输出小时计数器进位信号，高电平宽度1s */
#define	RTC_TMSEL_TMSEL_DAY	(0x5U << RTC_TMSEL_TMSEL_Pos)	/* 4’b0101：输出天计数器进位信号，高电平宽度1s */
#define	RTC_TMSEL_TMSEL_ALARM	(0x6U << RTC_TMSEL_TMSEL_Pos)	/* 4’b0110：输出闹钟匹配信号 */
#define	RTC_TMSEL_TMSEL_32S	(0x7U << RTC_TMSEL_TMSEL_Pos)	/* 4’b0111：输出32秒方波信号 */
#define	RTC_TMSEL_TMSEL_SECONDREV	(0x9U << RTC_TMSEL_TMSEL_Pos)	/* 4’b1001：反向输出秒计数器进位信号 */
#define	RTC_TMSEL_TMSEL_MINUTEREV	(0xaU << RTC_TMSEL_TMSEL_Pos)	/* 4’b1010：反向输出分计数器进位信号 */
#define	RTC_TMSEL_TMSEL_HOURREV	(0xbU << RTC_TMSEL_TMSEL_Pos)	/* 4’b1011：反向输出小时计数器进位信号 */
#define	RTC_TMSEL_TMSEL_DAYREV	(0xcU << RTC_TMSEL_TMSEL_Pos)	/* 4’b1100：反向输出天计数器进位信号 */
#define	RTC_TMSEL_TMSEL_ALARMREV	(0xdU << RTC_TMSEL_TMSEL_Pos)	/* 4’b1101：反向输出闹钟匹配信号 */
#define	RTC_TMSEL_TMSEL_SECONDRUN	(0xfU << RTC_TMSEL_TMSEL_Pos)	/* 4’b1111：输出RTC内部秒时标方波 */

#define	RTC_ADJUST_ADJUST_Pos	0	/* LTBC补偿调整数值 */
#define	RTC_ADJUST_ADJUST_Msk	(0x1ffU << RTC_ADJUST_ADJUST_Pos)

#define	RTC_ADSIGN_ADSIGN_Pos	0	/* LTBC补偿方向 */
#define	RTC_ADSIGN_ADSIGN_Msk	(0x1U << RTC_ADSIGN_ADSIGN_Pos)
#define	RTC_ADSIGN_ADSIGN_PLUS	(0x0U << RTC_ADSIGN_ADSIGN_Pos)	/* 0：表示增加计数初值 */
#define	RTC_ADSIGN_ADSIGN_MINUS	(0x1U << RTC_ADSIGN_ADSIGN_Pos)	/* 1：表示减少计数初值 */

#define	RTC_SBSCNT_MSCNT_Pos	0	/* 毫秒计数器值，有效位8bit，精度3.9ms */
#define	RTC_SBSCNT_MSCNT_Msk	(0xffU << RTC_SBSCNT_MSCNT_Pos)

#define	RTC_BKR0_BKP_Pos	0	/* 备份寄存器0，可读写，无复位值 */
#define	RTC_BKR0_BKP_Msk	(0xffffffffU << RTC_BKR0_BKP_Pos)

#define	RTC_BKR1_BKP_Pos	0	/* 备份寄存器1，可读写，无复位值 */
#define	RTC_BKR1_BKP_Msk	(0xffffffffU << RTC_BKR1_BKP_Pos)

#define	RTC_BKR2_BKP_Pos	0	/* 备份寄存器2，可读写，无复位值 */
#define	RTC_BKR2_BKP_Msk	(0xffffffffU << RTC_BKR2_BKP_Pos)

#define	RTC_BKR3_BKP_Pos	0	/* 备份寄存器3，可读写，无复位值 */
#define	RTC_BKR3_BKP_Msk	(0xffffffffU << RTC_BKR3_BKP_Pos)

#define	RTC_BKR4_BKP_Pos	0	/* 备份寄存器4，可读写，无复位值 */
#define	RTC_BKR4_BKP_Msk	(0xffffffffU << RTC_BKR4_BKP_Pos)

#define	RTC_BKR5_BKP_Pos	0	/* 备份寄存器5，可读写，无复位值 */
#define	RTC_BKR5_BKP_Msk	(0xffffffffU << RTC_BKR5_BKP_Pos)

#define	RTC_BKR6_BKP_Pos	0	/* 备份寄存器6，可读写，无复位值 */
#define	RTC_BKR6_BKP_Msk	(0xffffffffU << RTC_BKR6_BKP_Pos)

#define	RTC_BKR7_BKP_Pos	0	/* 备份寄存器7，可读写，无复位值 */
#define	RTC_BKR7_BKP_Msk	(0xffffffffU << RTC_BKR7_BKP_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void RTC_Deinit(void);

/* RTC写使能寄存器 相关函数 */
extern void RTC_WER_Write(uint32_t SetValue);

/* BCD时间秒寄存器 相关函数 */
extern void RTC_BCDSEC_Write(uint32_t SetValue);
extern uint32_t RTC_BCDSEC_Read(void);

/* BCD时间分钟寄存器 相关函数 */
extern void RTC_BCDMIN_Write(uint32_t SetValue);
extern uint32_t RTC_BCDMIN_Read(void);

/* BCD时间小时寄存器 相关函数 */
extern void RTC_BCDHOUR_Write(uint32_t SetValue);
extern uint32_t RTC_BCDHOUR_Read(void);

/* BCD时间天寄存器 相关函数 */
extern void RTC_BCDDAY_Write(uint32_t SetValue);
extern uint32_t RTC_BCDDAY_Read(void);

/* BCD时间星期寄存器 相关函数 */
extern void RTC_BCDWEEK_Write(uint32_t SetValue);
extern uint32_t RTC_BCDWEEK_Read(void);

/* BCD时间月寄存器 相关函数 */
extern void RTC_BCDMONTH_Write(uint32_t SetValue);
extern uint32_t RTC_BCDMONTH_Read(void);

/* BCD时间年寄存器 相关函数 */
extern void RTC_BCDYEAR_Write(uint32_t SetValue);
extern uint32_t RTC_BCDYEAR_Read(void);

/* 闹钟的小时数值 相关函数 */
extern void RTC_ALARM_HOUR_Set(uint32_t SetValue);
extern uint32_t RTC_ALARM_HOUR_Get(void);

/* 闹钟的分数值 相关函数 */
extern void RTC_ALARM_MIN_Set(uint32_t SetValue);
extern uint32_t RTC_ALARM_MIN_Get(void);

/* 闹钟的秒数值 相关函数 */
extern void RTC_ALARM_SEC_Set(uint32_t SetValue);
extern uint32_t RTC_ALARM_SEC_Get(void);

/* 频率输出选择信号 相关函数 */
extern void RTC_TMSEL_TMSEL_Set(uint32_t SetValue);
extern uint32_t RTC_TMSEL_TMSEL_Get(void);

/* LTBC补偿调整数值 相关函数 */
extern void RTC_ADJUST_Write(uint32_t SetValue);
extern uint32_t RTC_ADJUST_Read(void);

/* LTBC补偿方向 相关函数 */
extern void RTC_ADSIGN_ADSIGN_Set(uint32_t SetValue);
extern uint32_t RTC_ADSIGN_ADSIGN_Get(void);

/* 毫秒计数器值，有效位8bit，精度3.9ms 相关函数 */
extern void RTC_SBSCNT_Write(uint32_t SetValue);
extern uint32_t RTC_SBSCNT_Read(void);

/* 备份寄存器0，可读写，无复位值 相关函数 */
extern void RTC_BKR0_Write(uint32_t SetValue);
extern uint32_t RTC_BKR0_Read(void);

/* 备份寄存器1，可读写，无复位值 相关函数 */
extern void RTC_BKR1_Write(uint32_t SetValue);
extern uint32_t RTC_BKR1_Read(void);

/* 备份寄存器2，可读写，无复位值 相关函数 */
extern void RTC_BKR2_Write(uint32_t SetValue);
extern uint32_t RTC_BKR2_Read(void);

/* 备份寄存器3，可读写，无复位值 相关函数 */
extern void RTC_BKR3_Write(uint32_t SetValue);
extern uint32_t RTC_BKR3_Read(void);

/* 备份寄存器4，可读写，无复位值 相关函数 */
extern void RTC_BKR4_Write(uint32_t SetValue);
extern uint32_t RTC_BKR4_Read(void);

/* 备份寄存器5，可读写，无复位值 相关函数 */
extern void RTC_BKR5_Write(uint32_t SetValue);
extern uint32_t RTC_BKR5_Read(void);

/* 备份寄存器6，可读写，无复位值 相关函数 */
extern void RTC_BKR6_Write(uint32_t SetValue);
extern uint32_t RTC_BKR6_Read(void);

/* 备份寄存器7，可读写，无复位值 相关函数 */
extern void RTC_BKR7_Write(uint32_t SetValue);
extern uint32_t RTC_BKR7_Read(void);
//Announce_End
/* RTC中断使能寄存器 相关函数 */
extern void RTC_RTCIE_SetableEx(FunState NewState, uint32_t ie_def);

extern FunState RTC_RTCIE_GetableEx(uint32_t ie_def);

/* RTC中断标志 相关函数 */
extern void RTC_RTCIF_ClrEx(uint32_t if_def);

extern FlagStatus RTC_RTCIF_ChkEx(uint32_t if_def);

/* RTC设置时间 *///注意要先打开写保护才能设置时间
extern void RTC_TimeDate_SetEx(RTC_TimeDateTypeDef* para);

/* RTC读取时间 */
extern void RTC_TimeDate_GetEx(RTC_TimeDateTypeDef* para);

/* 闹钟时间设置 */
extern void RTC_AlarmTime_SetEx(RTC_AlarmTimeTypeDef* para);

/* 闹钟时间读取 */
extern void RTC_AlarmTime_GetEx(RTC_AlarmTimeTypeDef* para);
	
/* 时间戳数据读取 */
extern void RTC_CLKSTAMPxx_GetEx(uint8_t StampType_def, RTC_StampTimeTypeDef* para);

extern void RTC_TimeDate_GetBkpEx(RTC_TimeDateTypeDef* para);
extern void RTC_TimeDate_SetBkpEx(RTC_TimeDateTypeDef* para);

#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_RTC_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
