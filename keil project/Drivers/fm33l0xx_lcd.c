/**
  ******************************************************************************
  * @file    fm33l0xx_lcd.c
  * @author  FM33l0 Application Team
  * @version V0.0.1
  * @date    23-APRIL-2019
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33l0xx_lcd.h" 
#include "fm33l0xx_rcc.h" 

/** @addtogroup fm33l0_StdPeriph_Driver
  * @{
  */

/** @defgroup LCD 
  * @brief LCD driver modules
  * @{
  */ 
  
/* ��������Ƶ��ѡ�� ��غ��� */
void LCD_CR_SCFSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LCD->CR;
	tmpreg &= ~(LCD_CR_SCFSEL_Msk);
	tmpreg |= (SetValue & LCD_CR_SCFSEL_Msk);
	LCD->CR = tmpreg;
}

uint32_t LCD_CR_SCFSEL_Get(void)
{
	return (LCD->CR & LCD_CR_SCFSEL_Msk);
}

/* Ƭ�����������ʽ���� ��غ��� */
void LCD_CR_SC_CTRL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LCD->CR;
	tmpreg &= ~(LCD_CR_SC_CTRL_Msk);
	tmpreg |= (SetValue & LCD_CR_SC_CTRL_Msk);
	LCD->CR = tmpreg;
}

uint32_t LCD_CR_SC_CTRL_Get(void)
{
	return (LCD->CR & LCD_CR_SC_CTRL_Msk);
}

/* ƫ�õ�·�������Դ��С���� ��غ��� */
void LCD_CR_IC_CTRL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LCD->CR;
	tmpreg &= ~(LCD_CR_IC_CTRL_Msk);
	tmpreg |= (SetValue & LCD_CR_IC_CTRL_Msk);
	LCD->CR = tmpreg;
}

uint32_t LCD_CR_IC_CTRL_Get(void)
{
	return (LCD->CR & LCD_CR_IC_CTRL_Msk);
}

/* ����ģʽѡ�� ��غ��� */
void LCD_CR_ENMODE_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LCD->CR;
	tmpreg &= ~(LCD_CR_ENMODE_Msk);
	tmpreg |= (SetValue & LCD_CR_ENMODE_Msk);
	LCD->CR = tmpreg;
}

uint32_t LCD_CR_ENMODE_Get(void)
{
	return (LCD->CR & LCD_CR_ENMODE_Msk);
}

/* ��ʾ��˸���� ��غ��� */
void LCD_CR_FLICK_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LCD->CR |= (LCD_CR_FLICK_Msk);
	}
	else
	{
		LCD->CR &= ~(LCD_CR_FLICK_Msk);
	}
}

FunState LCD_CR_FLICK_Getable(void)
{
	if (LCD->CR & (LCD_CR_FLICK_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��ʾ�Ҷ����� ��غ��� */
void LCD_CR_BIAS_Write(uint32_t SetValue)
{
    uint32_t tmpreg;
    
    SetValue <<= LCD_CR_BIAS_Pos;
    tmpreg = LCD->CR;
    tmpreg &= ~(LCD_CR_BIAS_Msk);
	tmpreg |= (SetValue & LCD_CR_BIAS_Msk);
	LCD->CR = tmpreg;
}

uint32_t LCD_CR_BIAS_Read(void)
{
    uint32_t tmpsize;
    
    tmpsize = LCD->CR & LCD_CR_BIAS_Msk;
    tmpsize >>= LCD_CR_BIAS_Pos;
	return tmpsize;
}

/* ƫ�����Ϳ��� ��غ��� */
void LCD_CR_BIASMD_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LCD->CR;
	tmpreg &= ~(LCD_CR_BIASMD_Msk);
	tmpreg |= (SetValue & LCD_CR_BIASMD_Msk);
	LCD->CR = tmpreg;
}

uint32_t LCD_CR_BIASMD_Get(void)
{
	return (LCD->CR & LCD_CR_BIASMD_Msk);
}

/* ������ ��غ��� */
void LCD_CR_ANTIPOLAR_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LCD->CR |= (LCD_CR_ANTIPOLAR_Msk);
	}
	else
	{
		LCD->CR &= ~(LCD_CR_ANTIPOLAR_Msk);
	}
}

FunState LCD_CR_ANTIPOLAR_Getable(void)
{
	if (LCD->CR & (LCD_CR_ANTIPOLAR_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��������ѡ�� ��غ��� */
void LCD_CR_WFT_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LCD->CR;
	tmpreg &= ~(LCD_CR_WFT_Msk);
	tmpreg |= (SetValue & LCD_CR_WFT_Msk);
	LCD->CR = tmpreg;
}

uint32_t LCD_CR_WFT_Get(void)
{
	return (LCD->CR & LCD_CR_WFT_Msk);
}

/* COM������ѡ�� ��غ��� */
void LCD_CR_LMUX_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LCD->CR;
	tmpreg &= ~(LCD_CR_LMUX_Msk);
	tmpreg |= (SetValue & LCD_CR_LMUX_Msk);
	LCD->CR = tmpreg;
}

uint32_t LCD_CR_LMUX_Get(void)
{
	return (LCD->CR & LCD_CR_LMUX_Msk);
}

/* LCD���� ��غ��� */
void LCD_CR_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LCD->CR |= (LCD_CR_EN_Msk);
	}
	else
	{
		LCD->CR &= ~(LCD_CR_EN_Msk);
	}
}

FunState LCD_CR_EN_Getable(void)
{
	if (LCD->CR & (LCD_CR_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* LCD���Կ���λ����DISPDATA���ʹ�� ��غ��� */
void LCD_TEST_LCCTRL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = LCD->TEST;
	tmpreg &= ~(LCD_TEST_LCCTRL_Msk);
	tmpreg |= (SetValue & LCD_TEST_LCCTRL_Msk);
	LCD->TEST = tmpreg;
}

uint32_t LCD_TEST_LCCTRL_Get(void)
{
	return (LCD->TEST & LCD_TEST_LCCTRL_Msk);
}

/* ����ģʽ���� ��غ��� */
void LCD_TEST_TESTEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LCD->TEST |= (LCD_TEST_TESTEN_Msk);
	}
	else
	{
		LCD->TEST &= ~(LCD_TEST_TESTEN_Msk);
	}
}

FunState LCD_TEST_TESTEN_Getable(void)
{
	if (LCD->TEST & (LCD_TEST_TESTEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��ʾƵ�ʿ��ƼĴ��� ��غ��� */
void LCD_FCR_Write(uint32_t SetValue)
{
	LCD->FCR = (SetValue & LCD_FCR_DF_Msk);
}

uint32_t LCD_FCR_Read(void)
{
	return (LCD->FCR & LCD_FCR_DF_Msk);
}

/* ��˸��ʾϨ��ʱ��Ĵ��� ��غ��� */
void LCD_FLKT_TOFF_Write(uint32_t SetValue)
{
	LCD->FLKT = (SetValue & LCD_FLKT_TOFF_Msk);
}

uint32_t LCD_FLKT_TOFF_Read(void)
{
	return (LCD->FLKT & LCD_FLKT_TOFF_Msk);
}

/* ��˸��ʾ����ʱ��Ĵ��� ��غ��� */
void LCD_FLKT_TON_Write(uint32_t SetValue)
{
	LCD->FLKT = (SetValue & LCD_FLKT_TON_Msk);
}

uint32_t LCD_FLKT_TON_Read(void)
{
	return (LCD->FLKT & LCD_FLKT_TON_Msk);
}

/* ��ʾ�����жϿ���λ ��غ��� */
void LCD_IER_DONIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LCD->IER |= (LCD_IER_DONIE_Msk);
	}
	else
	{
		LCD->IER &= ~(LCD_IER_DONIE_Msk);
	}
}

FunState LCD_IER_DONIE_Getable(void)
{
	if (LCD->IER & (LCD_IER_DONIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��ʾϨ���жϿ���λ ��غ��� */
void LCD_IER_DOFFIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		LCD->IER |= (LCD_IER_DOFFIE_Msk);
	}
	else
	{
		LCD->IER &= ~(LCD_IER_DOFFIE_Msk);
	}
}

FunState LCD_IER_DOFFIE_Getable(void)
{
	if (LCD->IER & (LCD_IER_DOFFIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��ʾ�����жϱ�־ ��غ��� */
void LCD_ISR_DONIF_Clr(void)
{
	LCD->ISR = LCD_ISR_DONIF_Msk;
}

FlagStatus LCD_ISR_DONIF_Chk(void)
{
	if (LCD->ISR & LCD_ISR_DONIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��ʾϨ���жϱ�־ ��غ��� */
void LCD_ISR_DOFFIF_Clr(void)
{
	LCD->ISR = LCD_ISR_DOFFIF_Msk;
}

FlagStatus LCD_ISR_DOFFIF_Chk(void)
{
	if (LCD->ISR & LCD_ISR_DOFFIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* LCD COM������� ��غ��� */
void LCD_COM_EN_Write(uint32_t value)
{
    LCD->COM_EN = (value & LCD_COM_EN_Msk);
}

uint32_t LCD_COM_EN_Read(void)
{
    return (LCD->COM_EN & LCD_COM_EN_Msk);
}

/* LCD SEG������� ��غ��� */
void LCD_SEG_EN_Write(uint32_t value)
{
	LCD->SEG_EN0 = (value & LCD_SEG_EN_Msk);
}

uint32_t LCD_SEG_EN_Read(void)
{
	return (LCD->SEG_EN0 & LCD_SEG_EN_Msk);
}

void LCD_Deinit(void)
{   
   RCC_PRST_EN_Write(RSTKEY0);
   RCC_APBRST_CR1_LCDRST_Setable(ENABLE); 
   RCC_APBRST_CR1_LCDRST_Setable(DISABLE);
   RCC_PRST_EN_Write(RSTKEY1);
}

  
/*DISPDATAx��ʾ���ݼĴ���ˢ��*/
void LCD_DISPDATAx_Refresh(uint32_t* DispBuf)
{
    LCD->DATA0 = DispBuf[0];
    LCD->DATA1 = DispBuf[1];
    LCD->DATA2 = DispBuf[2];
    LCD->DATA3 = DispBuf[3];
    LCD->DATA4 = DispBuf[4];
    LCD->DATA5 = DispBuf[5];
    LCD->DATA6 = DispBuf[6];
    LCD->DATA7 = DispBuf[7];
}
 
/*LCD��ʾ��������*/
void LCD_Init(LCD_InitTypeDef* para)
{
	LCD_CR_LMUX_Set(para->LMUX);
	LCD_CR_ENMODE_Set(para->ENMODE);
	LCD_CR_WFT_Set(para->WFT);
	LCD_FCR_Write(para->DF);
	LCD_CR_BIASMD_Set(para->BIASMD);
	LCD_CR_SCFSEL_Set(para->SCFSEL);
	LCD_CR_SC_CTRL_Set(para->SC_CTRL);
	LCD_CR_IC_CTRL_Set(para->IC_CTRL);	
	LCD_CR_BIAS_Write(para->LCDBIAS);
	LCD_CR_ANTIPOLAR_Setable(para->ANTIPOLAR);
	
	LCD_TEST_LCCTRL_Set(para->LCCTRL);
	LCD_TEST_TESTEN_Setable(para->TESTEN);
	
	LCD_CR_FLICK_Setable(para->FLICK);	
	LCD_FLKT_TON_Write(para->TON);
	LCD_FLKT_TOFF_Write(para->TOFF);
	LCD_IER_DONIE_Setable(para->DONIE);
	LCD_IER_DOFFIE_Setable(para->DOFFIE);
	LCD_ISR_DONIF_Clr();
	LCD_ISR_DOFFIF_Clr();
	
	LCD_CR_EN_Setable(para->LCDEN);	
}

/******END OF FILE****/
