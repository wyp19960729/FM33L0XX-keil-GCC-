/**
  ******************************************************************************
  * @file    fm33l0xx_aes.c
  * @author  FM33L0 Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33l0xx_aes.h" 


/** @addtogroup fm33l0_StdPeriph_Driver
  * @{
  */

/** @defgroup AES 
  * @brief AES driver modules
  * @{
  */ 
  
 //Code_Start
//2019-06-13-09-37-09
//FM33A0XX_Driver_Gen_V1.4

/* AES������Կ���ȣ�AESEN=1ʱ�����޸� ��غ��� */
void AES_CR_KEYLEN_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = AES->CR;
	tmpreg &= ~(AES_CR_KEYLEN_Msk);
	tmpreg |= (SetValue & AES_CR_KEYLEN_Msk);
	AES->CR = tmpreg;
}

uint32_t AES_CR_KEYLEN_Get(void)
{
	return (AES->CR & AES_CR_KEYLEN_Msk);
}

/* DMA�����Զ�����ʹ�� ��غ��� */
void AES_CR_DMAOEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		AES->CR |= (AES_CR_DMAOEN_Msk);
	}
	else
	{
		AES->CR &= ~(AES_CR_DMAOEN_Msk);
	}
}

FunState AES_CR_DMAOEN_Getable(void)
{
	if (AES->CR & (AES_CR_DMAOEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* DMA�����Զ�д��ʹ�� ��غ��� */
void AES_CR_DMAIEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		AES->CR |= (AES_CR_DMAIEN_Msk);
	}
	else
	{
		AES->CR &= ~(AES_CR_DMAIEN_Msk);
	}
}

FunState AES_CR_DMAIEN_Getable(void)
{
	if (AES->CR & (AES_CR_DMAIEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* AES����������ģʽ��AESEN=1ʱ�����޸� ��غ��� */
void AES_CR_CHMOD_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = AES->CR;
	tmpreg &= ~(AES_CR_CHMOD_Msk);
	tmpreg |= (SetValue & AES_CR_CHMOD_Msk);
	AES->CR = tmpreg;
}

uint32_t AES_CR_CHMOD_Get(void)
{
	return (AES->CR & AES_CR_CHMOD_Msk);
}

/* AES����ģʽ��AESEN=1ʱ�����޸� ��غ��� */
void AES_CR_MODE_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = AES->CR;
	tmpreg &= ~(AES_CR_MODE_Msk);
	tmpreg |= (SetValue & AES_CR_MODE_Msk);
	AES->CR = tmpreg;
}

uint32_t AES_CR_MODE_Get(void)
{
	return (AES->CR & AES_CR_MODE_Msk);
}

/* ѡ���������ͣ�AESEN=1ʱ�����޸� ��غ��� */
void AES_CR_DATATYP_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = AES->CR;
	tmpreg &= ~(AES_CR_DATATYP_Msk);
	tmpreg |= (SetValue & AES_CR_DATATYP_Msk);
	AES->CR = tmpreg;
}

uint32_t AES_CR_DATATYP_Get(void)
{
	return (AES->CR & AES_CR_DATATYP_Msk);
}

/* AESʹ��,���κ�ʱ�����AESENλ���ܹ���λAESģ�� ��غ��� */
void AES_CR_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		AES->CR |= (AES_CR_EN_Msk);
	}
	else
	{
		AES->CR &= ~(AES_CR_EN_Msk);
	}
}

FunState AES_CR_EN_Getable(void)
{
	if (AES->CR & (AES_CR_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* д�����ж�ʹ�ܣ�1��Ч ��غ��� */
void AES_IER_WRERR_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		AES->IER &= ~(AES_IER_WRERR_IE_Msk);
	}
	else
	{
		AES->IER |= (AES_IER_WRERR_IE_Msk);
	}
}

FunState AES_IER_WRERR_IE_Getable(void)
{
	if (AES->IER & (AES_IER_WRERR_IE_Msk))
	{
		return DISABLE;
	}
	else
	{
		return ENABLE;
	}
}

/* �������ж�ʹ�ܣ�1��Ч ��غ��� */
void AES_IER_RDERR_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		AES->IER &= ~(AES_IER_RDERR_IE_Msk);
	}
	else
	{
		AES->IER |= (AES_IER_RDERR_IE_Msk);
	}
}

FunState AES_IER_RDERR_IE_Getable(void)
{
	if (AES->IER & (AES_IER_RDERR_IE_Msk))
	{
		return DISABLE;
	}
	else
	{
		return ENABLE;
	}
}

/* AES��������ж�ʹ�ܣ�1��Ч ��غ��� */
void AES_IER_CCF_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		AES->IER &= ~(AES_IER_CCF_IE_Msk);
	}
	else
	{
		AES->IER |= (AES_IER_CCF_IE_Msk);
	}
}

FunState AES_IER_CCF_IE_Getable(void)
{
	if (AES->IER & (AES_IER_CCF_IE_Msk))
	{
		return DISABLE;
	}
	else
	{
		return ENABLE;
	}
}

/* д�����־���ڼ��������׶η���д����ʱ��λ�����д1����  ��غ��� */
void AES_ISR_WRERR_Clr(void)
{
	AES->ISR = AES_ISR_WRERR_Msk;
}

FlagStatus AES_ISR_WRERR_Chk(void)
{
	if (AES->ISR & AES_ISR_WRERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �������־���ڼ��������׶η���������ʱ��λ�����д1���� ��غ��� */
void AES_ISR_RDERR_Clr(void)
{
	AES->ISR = AES_ISR_RDERR_Msk;
}

FlagStatus AES_ISR_RDERR_Chk(void)
{
	if (AES->ISR & AES_ISR_RDERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* AES������ɱ�־�����д1���� ��غ��� */
void AES_ISR_CCF_Clr(void)
{
	AES->ISR = AES_ISR_CCF_Msk;
}

FlagStatus AES_ISR_CCF_Chk(void)
{
	if (AES->ISR & AES_ISR_CCF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��������Ĵ�������AES��Ҫ����ӽ�������ʱ��Ӧ�����üĴ�������д4�� ��غ��� */
void AES_DIR_Write(uint32_t SetValue)
{
	AES->DIR = (SetValue);
}

uint32_t AES_DIR_Read(void)
{
	return (AES->DIR);
}

/* ��������Ĵ�������AES������ɺ󣬿��Է��Ĵζ����ӽ��ܵĽ�� ��غ��� */
void AES_DOR_Write(uint32_t SetValue)
{
	AES->DOR = (SetValue);
}

uint32_t AES_DOR_Read(void)
{
	return (AES->DOR);
}

/* AES������Կ���256bit,AESKEY0�����Կ���32bit��AESLKEY7�����Կ���32bit��AESKEY0~3��MultHģʽ�´��H[127:0]
 ��غ��� */
void AES_KEY0_Write(uint32_t SetValue)
{
	AES->KEY0 = (SetValue);
}

uint32_t AES_KEY0_Read(void)
{
	return (AES->KEY0);
}

void AES_KEY1_Write(uint32_t SetValue)
{
	AES->KEY1 = (SetValue);
}

uint32_t AES_KEY1_Read(void)
{
	return (AES->KEY1);
}

void AES_KEY2_Write(uint32_t SetValue)
{
	AES->KEY2 = (SetValue);
}

uint32_t AES_KEY2_Read(void)
{
	return (AES->KEY2);
}

void AES_KEY3_Write(uint32_t SetValue)
{
	AES->KEY3 = (SetValue);
}

uint32_t AES_KEY3_Read(void)
{
	return (AES->KEY3);
}

void AES_KEY4_Write(uint32_t SetValue)
{
	AES->KEY4 = (SetValue);
}

uint32_t AES_KEY4_Read(void)
{
	return (AES->KEY4);
}

void AES_KEY5_Write(uint32_t SetValue)
{
	AES->KEY5 = (SetValue);
}

uint32_t AES_KEY5_Read(void)
{
	return (AES->KEY5);
}

void AES_KEY6_Write(uint32_t SetValue)
{
	AES->KEY6 = (SetValue);
}

uint32_t AES_KEY6_Read(void)
{
	return (AES->KEY6);
}

void AES_KEY7_Write(uint32_t SetValue)
{
	AES->KEY7 = (SetValue);
}

uint32_t AES_KEY7_Read(void)
{
	return (AES->KEY7);
}

/* AES����128bit��ʼ��������MultHģʽ�±��������� ��غ��� */
void AES_IVR0_Write(uint32_t SetValue)
{
	AES->IVR0 = (SetValue);
}

uint32_t AES_IVR0_Read(void)
{
	return (AES->IVR0);
}

void AES_IVR1_Write(uint32_t SetValue)
{
	AES->IVR1 = (SetValue);
}

uint32_t AES_IVR1_Read(void)
{
	return (AES->IVR1);
}

void AES_IVR2_Write(uint32_t SetValue)
{
	AES->IVR2 = (SetValue);
}

uint32_t AES_IVR2_Read(void)
{
	return (AES->IVR2);
}

void AES_IVR3_Write(uint32_t SetValue)
{
	AES->IVR3 = (SetValue);
}

uint32_t AES_IVR3_Read(void)
{
	return (AES->IVR3);
}


void AES_Deinit(void)
{
	//AES->CR = 0x00000000;
	//AES->IER = 0x00000000;
	//AES->ISR = 0x00000000;
	//AES->DIR = 0x00000000;
	//AES->DOR = 0x00000000;
	//AES->KEY0 = 0x00000000;
	//AES->KEY1 = 0x00000000;
	//AES->KEY2 = 0x00000000;
	//AES->KEY3 = 0x00000000;
	//AES->KEY4 = 0x00000000;
	//AES->KEY5 = 0x00000000;
	//AES->KEY6 = 0x00000000;
	//AES->KEY7 = 0x00000000;
	//AES->IVR0 = 0x00000000;
	//AES->IVR1 = 0x00000000;
	//AES->IVR2 = 0x00000000;
	//AES->IVR3 = 0x00000000;
}
//Code_End


/********************************
AES ���ܿ��ƺ���
����: �ӽ�����Կ����(key0�����Կ���32bit)
���룺��Կ	16/24/32�ֽڳ��ȵ���Կ
			����	16/24/32
���: ��
********************************/
void AES_KEYx_WriteEx(uint8_t *KeyIn, uint8_t Len)
{
	uint8_t i;
	__IO uint32_t *PointKeyReg;
	__IO uint32_t Temp32;
	
	if( (Len != 16) && (Len != 24) && (Len != 32) ) return;
	
	PointKeyReg = (&AES->KEY0);
	for(i=0; i<Len; i=i+4)
	{
		Temp32 = (KeyIn[0+i]<<24)|(KeyIn[1+i]<<16)|(KeyIn[2+i]<<8)|(KeyIn[3+i]<<0);
		PointKeyReg[(Len-i)/4-1] = Temp32;
	}
}

/*�ӽ�����Կ�������һ���ִ����Կ���32bit  */
void AES_KEYx_ReadEx(uint8_t *KeyOut, uint8_t Len)
{
	uint8_t i;
	__IO uint32_t *PointKeyReg;
	__IO uint32_t Temp32;
	
	if( (Len != 16) && (Len != 24) && (Len != 32) ) return;
	
	PointKeyReg = (&AES->KEY0);
	for(i=0; i<Len; i=i+4)
	{
		Temp32 = PointKeyReg[(Len-i)/4-1];
		KeyOut[0+i] = Temp32>>24;
		KeyOut[1+i] = Temp32>>16;
		KeyOut[2+i] = Temp32>>8;
		KeyOut[3+i] = Temp32>>0;
	}
}

/*��ʼ�������� */
void AES_IVRx_WriteEx(uint8_t *IVRIn)
{
	uint8_t i;
	__IO uint32_t *PointIvrReg;
	__IO uint32_t Temp32;
	
	PointIvrReg = (&AES->IVR0);
	for(i=0; i<4*4; i=i+4)
	{
		Temp32 = (IVRIn[0+i]<<24)|(IVRIn[1+i]<<16)|(IVRIn[2+i]<<8)|(IVRIn[3+i]<<0);
		PointIvrReg[(16-i)/4-1] = Temp32;
	}
}
/*�ӽ����������룬16�ֽڣ�128bit��������������  */
void AES_DIR_GroupWrite_128BIT(uint8_t *DataIn)
{
	uint8_t i;
	__IO uint32_t Temp32;

	for(i=0; i<16; i=i+4)
	{
		Temp32 = (DataIn[0+i]<<24)|(DataIn[1+i]<<16)|(DataIn[2+i]<<8)|(DataIn[3+i]<<0);
		AES->DIR = Temp32;
	}
}
        						
/*�ӽ������������16�ֽڣ�128bit�������������  */
void AES_DOR_GroupRead_128BIT(uint8_t *DataOut)
{
	uint8_t i;
	__IO uint32_t Temp32;
	uint8_t Buf[16];
	
	for(i=0; i<16; i=i+4)
	{
		Temp32 = AES->DOR;
		Buf[0+i] = Temp32>>24;
		Buf[1+i] = Temp32>>16;
		Buf[2+i] = Temp32>>8;
		Buf[3+i] = Temp32>>0;
	}
	if( RCC->SYSCLK_CR & (0x07UL << 16))//APBʱ���з�Ƶ
	{
		for(i=0; i<12; i++)
		{
			DataOut[4+i] = Buf[i];
		}
		for(i=0; i<4; i++)
		{
			DataOut[i] = Buf[12+i];
		}	
	}
	else
	{
		for(i=0; i<16; i++)
		{
			DataOut[i] = Buf[i];
		}
	}
}

uint8_t AES_GroupWriteAndRead_128BIT(uint8_t *DataIn, uint8_t *DataOut)
{	
	uint16_t i;
	
	//����ӽ�������
	AES_DIR_GroupWrite_128BIT(DataIn);
	
	//�ȴ�CCF��־����,��ɼ����Լ��Ҫ100��ʱ������
	for(i=0;i<500;i++)
	{
		if(SET == AES_ISR_CCF_Chk() ) break;
	}
	//��CCF��־
	//��ȡǰ�������
	AES_ISR_CCF_Chk();
	
	//��ȡ���
	AES_DOR_GroupRead_128BIT(DataOut);
	
	if(i==500) return 1;
	else return 0;
}

/* AESģ���ʼ������ */
void AES_Init(AES_InitTypeDef* para)
{
	AES_CR_KEYLEN_Set(para->KEYLEN);				//AES������Կ���ȣ�AESEN=1ʱ�����޸�
	AES_CR_CHMOD_Set(para->CHMOD);					//AES����������ģʽ��AESEN=1ʱ�����޸�
	AES_CR_MODE_Set(para->MODE);						//AES����ģʽ��AESEN=1ʱ�����޸�
	AES_CR_DATATYP_Set(para->DATATYP);			//ѡ���������ͣ�AESEN=1ʱ�����޸ġ����彻������ɲο�AES���������½�	
	AES_CR_DMAOEN_Setable(para->DMAOEN);		//DMA�����Զ�����ʹ��
	AES_CR_DMAIEN_Setable(para->DMAIEN);		//DMA�����Զ�д��ʹ��
	AES_IER_WRERR_IE_Setable(para->WERRIE);	//�����־��WRERR���ж�ʹ��
	AES_IER_RDERR_IE_Setable(para->RERRIE);	//�����־��RDERR���ж�ʹ��
	AES_IER_CCF_IE_Setable(para->CCFIE);		//CCF��־�ж�ʹ��
	AES_CR_EN_Setable(para->AESEN);					//AESʹ�� 
}


/******END OF FILE****/
