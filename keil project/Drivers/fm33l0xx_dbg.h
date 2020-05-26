/**
  ******************************************************************************
  * @file    fm33l0xx_dbg.h
  * @author  FM33L0xx Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file contains all the functions prototypes for the DBG firmware library.  
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __FM33L0XX_DBG_H
#define __FM33L0XX_DBG_H


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "FM33L0XX.h"

//------------------------------------------------------------------------------
#define	DBG_CR_AT_STOP_Pos	13	/* Debug״̬��ATIMʹ�ܿ��� */
#define	DBG_CR_AT_STOP_Msk	(0x1U << DBG_CR_AT_STOP_Pos)
	/* 0��Debugʱ����ATIMԭ��״̬ */
	/* 1��Debugʱ����ATIMԭ��״̬ */

#define	DBG_CR_GT1_STOP_Pos	11	/* Debug״̬��GPTIM1ʹ�ܿ��� */
#define	DBG_CR_GT1_STOP_Msk	(0x1U << DBG_CR_GT1_STOP_Pos)
	/* 0��Debugʱ����GPTIM2ԭ��״̬ */
	/* 1��Debugʱ�ر�GPTIM2 */

#define	DBG_CR_GT0_STOP_Pos	10	/* Debug״̬��GPTIM0ʹ�ܿ��� */
#define	DBG_CR_GT0_STOP_Msk	(0x1U << DBG_CR_GT0_STOP_Pos)
	/* 0��Debugʱ����GPTIM1ԭ��״̬ */
	/* 1��Debugʱ�ر�GPTIM1 */

#define	DBG_CR_BT_STOP_Pos	8	/* Debug״̬��BSTIMʹ�ܿ��� */
#define	DBG_CR_BT_STOP_Msk	(0x1U << DBG_CR_BT_STOP_Pos)
	/* 0��Debugʱ����BSTIMԭ��״̬ */
	/* 1��Debugʱ�ر�BSTIM */

#define	DBG_CR_WWDT_STOP_Pos	1	/* Debug״̬��WWDTʹ�ܿ��� */
#define	DBG_CR_WWDT_STOP_Msk	(0x1U << DBG_CR_WWDT_STOP_Pos)
	/* 0��Debugʱ����WWDTԭ��״̬ */
	/* 1��Debugʱ�ر�WWDT */

#define	DBG_CR_IWDT_STOP_Pos	0	/* Debug״̬��IWDTʹ�ܿ��� */
#define	DBG_CR_IWDT_STOP_Msk	(0x1U << DBG_CR_IWDT_STOP_Pos)
	/* 0��Debugʱ����IWDT���� */
	/* 1��Debugʱ�ر�IWDT */

#define	DBG_HDFR_DABORT_ADDR_FLAG_Pos	6	/* ��ַ�Ƕ�����ʴ����־ */
#define	DBG_HDFR_DABORT_ADDR_FLAG_Msk	(0x1U << DBG_HDFR_DABORT_ADDR_FLAG_Pos)

#define	DBG_HDFR_DABORT_RESP_FLAG_Pos	5	/* �Ƿ���ַ���ʴ����־ */
#define	DBG_HDFR_DABORT_RESP_FLAG_Msk	(0x1U << DBG_HDFR_DABORT_RESP_FLAG_Pos)

#define	DBG_HDFR_SVCUNDEF_FLAG_Pos	4	/* SVC instructionsδ�����־ */
#define	DBG_HDFR_SVCUNDEF_FLAG_Msk	(0x1U << DBG_HDFR_SVCUNDEF_FLAG_Pos)

#define	DBG_HDFR_BKPT_FLAG_Pos	3	/* ִ��BKPTָ���־ */
#define	DBG_HDFR_BKPT_FLAG_Msk	(0x1U << DBG_HDFR_BKPT_FLAG_Pos)

#define	DBG_HDFR_TBIT_FLAG_Pos	2	/* Thumb-State��־ */
#define	DBG_HDFR_TBIT_FLAG_Msk	(0x1U << DBG_HDFR_TBIT_FLAG_Pos)

#define	DBG_HDFR_SPECIAL_OP_FLAG_Pos	1	/* ����ָ���־ */
#define	DBG_HDFR_SPECIAL_OP_FLAG_Msk	(0x1U << DBG_HDFR_SPECIAL_OP_FLAG_Pos)

#define	DBG_HDFR_HDF_REQUEST_FLAG_Pos	0	/* hardfault��־λ */
#define	DBG_HDFR_HDF_REQUEST_FLAG_Msk	(0x1U << DBG_HDFR_HDF_REQUEST_FLAG_Pos)
//Macro_End

/* Exported functions --------------------------------------------------------*/ 
extern void DBG_Deinit(void);

/* Debug״̬��ATIMʹ�ܿ��� ��غ��� */
extern void DBG_CR_AT_STOP_Setable(FunState NewState);
extern FunState DBG_CR_AT_STOP_Getable(void);

/* Debug״̬��GPTIM2ʹ�ܿ��� ��غ��� */
extern void DBG_CR_GT1_STOP_Setable(FunState NewState);
extern FunState DBG_CR_GT1_STOP_Getable(void);

/* Debug״̬��GPTIM1ʹ�ܿ��� ��غ��� */
extern void DBG_CR_GT0_STOP_Setable(FunState NewState);
extern FunState DBG_CR_GT0_STOP_Getable(void);

/* Debug״̬��BSTIMʹ�ܿ��� ��غ��� */
extern void DBG_CR_BT_STOP_Setable(FunState NewState);
extern FunState DBG_CR_BT_STOP_Getable(void);

/* Debug״̬��WWDTʹ�ܿ��� ��غ��� */
extern void DBG_CR_WWDT_STOP_Setable(FunState NewState);
extern FunState DBG_CR_WWDT_STOP_Getable(void);

/* Debug״̬��IWDTʹ�ܿ��� ��غ��� */
extern void DBG_CR_IWDT_STOP_Setable(FunState NewState);
extern FunState DBG_CR_IWDT_STOP_Getable(void);

/* ��ַ�Ƕ�����ʴ����־ ��غ��� */
extern void DBG_HDFR_DABORT_ADDR_FLAG_Clr(void);
extern FlagStatus DBG_HDFR_DABORT_ADDR_FLAG_Chk(void);

/* �Ƿ���ַ���ʴ����־ ��غ��� */
extern void DBG_HDFR_DABORT_RESP_FLAG_Clr(void);
extern FlagStatus DBG_HDFR_DABORT_RESP_FLAG_Chk(void);

/* SVC instructionsδ�����־ ��غ��� */
extern void DBG_HDFR_SVCUNDEF_FLAG_Clr(void);
extern FlagStatus DBG_HDFR_SVCUNDEF_FLAG_Chk(void);

/* ִ��BKPTָ���־ ��غ��� */
extern void DBG_HDFR_BKPT_FLAG_Clr(void);
extern FlagStatus DBG_HDFR_BKPT_FLAG_Chk(void);

/* Thumb-State��־ ��غ��� */
extern void DBG_HDFR_TBIT_FLAG_Clr(void);
extern FlagStatus DBG_HDFR_TBIT_FLAG_Chk(void);

/* ����ָ���־ ��غ��� */
extern void DBG_HDFR_SPECIAL_OP_FLAG_Clr(void);
extern FlagStatus DBG_HDFR_SPECIAL_OP_FLAG_Chk(void);

/* hardfault��־λ ��غ��� */
extern void DBG_HDFR_HDF_REQUEST_FLAG_Clr(void);
extern FlagStatus DBG_HDFR_HDF_REQUEST_FLAG_Chk(void);
//Announce_End
                
#ifdef __cplusplus
}
#endif

#endif /* __FM33L0XX_DBG_H */



/************************ (C) COPYRIGHT FMSHelectronics *****END OF FILE****/
