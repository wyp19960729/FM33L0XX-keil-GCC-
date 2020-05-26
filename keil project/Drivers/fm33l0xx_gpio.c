/**
  ******************************************************************************
  * @file    fm33l0xx_gpio.c
  * @author  FM33L0 Application Team
  * @version V0.1.0
  * @date    12-Jun-2019
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33l0xx_gpio.h" 


/** @addtogroup fm33l0_StdPeriph_Driver
  * @{
  */

/** @defgroup GPIO 
  * @brief GPIO driver modules
  * @{
  */ 
	
#ifdef  USE_FULL_ASSERT

/**
  * @brief  The assert_param macro is used for function's parameters check.
  * @param  expr: If expr is false, it calls assert_failed function
  *   which reports the name of the source file and the source
  *   line number of the call that failed. 
  *   If expr is true, it returns no value.
  * @retval None
  */
  #define assert_param(expr) ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))
/* Exported functions ------------------------------------------------------- */
  void assert_failed(uint8_t* file, uint32_t line);
#else
  #define assert_param(expr) ((void)0)
#endif /* USE_FULL_ASSERT */

/********************************
 PortX������ݼĴ������ú���
����: ����PortX�������
���룺GPIO_Type* GPIOx���ܽźţ�,  uint32_t SetValue�����ֵ��
���:��
********************************/
void GPIOx_DO_Write(GPIO_Type* GPIOx, uint32_t SetValue)
{
	GPIOx->DO = (SetValue & GPIOx_DO_DO_Msk);
}
/********************************
��PortX�������״̬����
����:��PortX�������״̬
���룺��
���:PortX���ֵ
********************************/
uint32_t GPIOx_DO_Read(GPIO_Type* GPIOx)
{
	return (GPIOx->DO & GPIOx_DO_DO_Msk);
}

/********************************
PortX���������λ�Ĵ�������
����:PortX���������λ������PADSETд0x0000_8000����PADO[15]��λ������λ���ֲ��䡣
���룺GPIO_Type* GPIOx���ܽźţ�,  uint32_t SetValue�����ֵ��
���:��
********************************/
void GPIOx_DSET_Write(GPIO_Type* GPIOx, uint32_t SetValue)
{
	GPIOx->DSET = (SetValue & GPIOx_DSET_DSET_Msk);
}

/********************************
PortX������ݸ�λ�Ĵ�������
����:PortX������ݸ�λ������PADRSTд0x0000_8000����PADO[15]���㣬����λ���ֲ��䡣
���룺GPIO_Type* GPIOx���ܽźţ�,  uint32_t SetValue�����ֵ��
���:��
********************************/
void GPIOx_DRST_Write(GPIO_Type* GPIOx, uint32_t SetValue)
{
	GPIOx->DRST = (SetValue & GPIOx_DRST_DRESET_Msk);
}

/********************************
PortX�������ݼĴ�������
����:PortX�������ݣ��˼Ĵ�����ռ�õ�ַ�ռ䣬������ʵ�֡�������˼Ĵ���ֱ�ӷ������������źţ�оƬ���������������������
���룺GPIO_Type* GPIOx���ܽźţ�,  uint32_t SetValue������ֵ��
���:��
********************************/
uint32_t GPIOx_DIN_Read(GPIO_Type* GPIOx)
{
	return (GPIOx->DIN & GPIOx_DIN_DIN_Msk);
}

/* PortX�������ֹ��ܼĴ��� ��غ��� */
extern void GPIOx_DFS_Setable(GPIO_Type* GPIOx, uint32_t GPIO_Pin, FunState NewState)
{
	uint32_t tmpreg;
	
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GET_GPIO_PIN(GPIO_Pin));
	
	tmpreg = GPIOx->DFS;
	if (NewState == ENABLE)
	{
		tmpreg |= (GPIO_Pin);
	}
	else
	{
		tmpreg &= ~(GPIO_Pin);
	}
	GPIOx->DFS = tmpreg;
}

extern FunState GPIOx_DFS_Getable(GPIO_Type* GPIOx, uint32_t GPIO_Pin)
{
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GET_GPIO_PIN(GPIO_Pin));
	
	if (GPIOx->DFS & GPIO_Pin)
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* PortXǿ����ʹ�ܼĴ��� ��غ��� */
extern void GPIOx_HD_Setable(GPIO_Type* GPIOx, uint32_t GPIO_Pin, FunState NewState)
{
	uint32_t tmpreg;
	
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GET_GPIO_PIN(GPIO_Pin));
	
	tmpreg = GPIOx->HD;
	if (NewState == ENABLE)
	{
		tmpreg |= (GPIO_Pin);
	}
	else
	{
		tmpreg &= ~(GPIO_Pin);
	}
	GPIOx->HD = tmpreg;
}

extern FunState GPIOx_HD_Getable(GPIO_Type* GPIOx, uint32_t GPIO_Pin)
{
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GET_GPIO_PIN(GPIO_Pin));
	
	if (GPIOx->HD & GPIO_Pin)
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* PortXģ�⿪��ʹ�ܼĴ��� ��غ��� */
extern void GPIOx_ANEN_Setable(GPIO_Type* GPIOx, uint32_t GPIO_Pin, FunState NewState)
{
	uint32_t tmpreg;
	
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GET_GPIO_PIN(GPIO_Pin));
	
	tmpreg = GPIOx->ANEN;
	if (NewState == ENABLE)
	{
		tmpreg |= (GPIO_Pin);
	}
	else
	{
		tmpreg &= ~(GPIO_Pin);
	}
	GPIOx->ANEN = tmpreg;
}

extern FunState GPIOx_ANEN_Getable(GPIO_Type* GPIOx, uint32_t GPIO_Pin)
{
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GET_GPIO_PIN(GPIO_Pin));
	
	if (GPIOx->ANEN & GPIO_Pin)
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
 FOUT������ú���
����: ����FOUT���
���룺���Ƶ��ѡ���ź�
���:��
********************************/
void GPIO_FOUT1SEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPIO_COMMON->FOUT_SEL;
	tmpreg &= ~(GPIO_FOUT_SEL_FOUT1SEL_Msk);
	tmpreg |= (SetValue & GPIO_FOUT_SEL_FOUT1SEL_Msk);
	GPIO_COMMON->FOUT_SEL = tmpreg;
}
/********************************
��FOUT���״̬����
����:��FOUT���״̬
���룺��
���:FOUT���ѡ��ֵ
********************************/
uint32_t GPIO_FOUT1SEL_Get(void)
{
	return (GPIO_COMMON->FOUT_SEL & GPIO_FOUT_SEL_FOUT1SEL_Msk);
}

/********************************
 FOUT������ú���
����: ����FOUT���
���룺���Ƶ��ѡ���ź�
���:��
********************************/
void GPIO_FOUT0SEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPIO_COMMON->FOUT_SEL;
	tmpreg &= ~(GPIO_FOUT_SEL_FOUT0SEL_Msk);
	tmpreg |= (SetValue & GPIO_FOUT_SEL_FOUT0SEL_Msk);
	GPIO_COMMON->FOUT_SEL = tmpreg;
}
/********************************
��FOUT���״̬����
����:��FOUT���״̬
���룺��
���:FOUT���ѡ��ֵ
********************************/
uint32_t GPIO_FOUT0SEL_Get(void)
{
	return (GPIO_COMMON->FOUT_SEL & GPIO_FOUT_SEL_FOUT0SEL_Msk);
}


void GPIOx_Deinit(GPIO_Type* GPIOx)
{
	GPIOx->INEN = 0x00000000;
	GPIOx->PUEN = 0x00000000;
	GPIOx->ODEN = 0x00000000;
	GPIOx->FCR = 0x00000000;
	GPIOx->DO = 0x00000000;
	//GPIOx->DSET = ;
	//GPIOx->DRST = ;
	//GPIOx->DIN = ;
	//GPIOx->DFS = 0x00000000;
	//GPIOx->HD = 0x00000000;
	//GPIOx->ANEN = 0x00000000;
}

void GPIO_Deinit(void)
{
	GPIO_COMMON->EXTI_SEL = 0xFFFF0000;
	GPIO_COMMON->EXTI_EDS = 0xFFFF0000;
	GPIO_COMMON->EXTI_DF = 0xFFFF0000;
//	GPIO_COMMON->EXTI_ISR = 0xFFFF0000;
	GPIO_COMMON->EXTI_DI = 0xFFFF0000;
	GPIO_COMMON->FOUT_SEL = 0xFFFF0000;
	GPIO_COMMON->PINWKEN = 0xFFFF0000;
}
//Code_End


void GPIO_ALL_Deinit(void)
{
	GPIO_Deinit();
	GPIOx_Deinit(GPIOA);
	GPIOx_Deinit(GPIOB);
	GPIOx_Deinit(GPIOC);
	GPIOx_Deinit(GPIOD);
}


/********************************
GPIO��ʼ�����ú���
����:GPIO��ʼ������
���룺GPIO�˿�  GPIO_PIN����
���: ��
********************************/
void GPIO_Init(GPIO_Type* GPIOx, GPIO_InitTypeDef* para)
{
    uint32_t pinpos = 0x00,pinbit = 0x00,currentpin =0x00;
		uint32_t tmpreg; 

    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));	
	
    for (pinpos = 0; pinpos < 16; pinpos++)
    {
        pinbit = ((uint32_t)0x01) <<pinpos;
        currentpin = (para->Pin) & pinbit;
			
        if (currentpin == pinbit)
        {
					tmpreg = GPIOx->INEN;
					tmpreg &= ~pinbit;
					tmpreg |= (para->PxINEN)<<pinpos;	
					GPIOx->INEN = tmpreg;
					
					tmpreg = GPIOx->PUEN;
					tmpreg &= ~pinbit;
					tmpreg |= (para->PxPUEN)<<pinpos;
					GPIOx->PUEN = tmpreg;
					
					tmpreg = GPIOx->ODEN;
					tmpreg &= ~pinbit;
					tmpreg |= (para->PxODEN)<<pinpos;
					GPIOx->ODEN = tmpreg;

					pinbit = (((uint32_t)0x00000003)) <<(pinpos*2);
					tmpreg = GPIOx->FCR;
					tmpreg &= ~pinbit;
					tmpreg |= (para->PxFCR)<<(pinpos*2);
					GPIOx->FCR = tmpreg;
        }
    }
}

/* ��ȡһ��IO�ڵ����ò����ṹ�� 
	ע��һ��ֻ�ܶ�ȡһ��IO������
*/
/********************************
��ȡһ��IO���ò����ṹ�庯��
����:��ȡһ��IO���ò����ṹ��
���룺GPIO�˿�  GPIO_PIN���� ��������
���: ��
********************************/
void GPIO_Get_InitPara(GPIO_Type* GPIOx, uint32_t GPIO_Pin, GPIO_InitTypeDef* para)
{
  uint32_t pinbit = 0x00;
  uint32_t i,temp;

	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));	
	
	for (i = 0; i < 16; i++)
	{
		pinbit = GPIO_Pin & (1<<i);
		if(pinbit > 0) break;
	}
	
	if(i < 16)
	{
		pinbit = i;
		para->Pin = GPIO_Pin;
		
		temp = (GPIOx->INEN&GPIO_Pin)>>pinbit;
		if(temp == (uint32_t)GPIO_IN_En)
		{                                         
			para->PxINEN = GPIO_IN_En;
		}
		else
		{
			para->PxINEN = GPIO_IN_Dis;
		}   
		
		temp = (GPIOx->PUEN&GPIO_Pin)>>pinbit;                                    
		if(temp == (uint32_t)GPIO_PU_En)
		{                                         
			para->PxPUEN = GPIO_PU_En;
		}
		else
		{
			para->PxPUEN = GPIO_PU_Dis;
		}   
		
		temp = (GPIOx->ODEN&GPIO_Pin)>>pinbit;                                   
		if(temp == (uint32_t)GPIO_OD_En)
		{                                         
			para->PxODEN = GPIO_OD_En;
		}
		else
		{
			para->PxODEN = GPIO_OD_Dis;
		}  
		
		temp = (GPIOx->FCR>>(pinbit*2))&0x00000003;                                    
		if(temp == (uint32_t)GPIO_FCR_IN)
		{                                         
			para->PxFCR = GPIO_FCR_IN;
		}
		else if(temp == (uint32_t)GPIO_FCR_OUT)
		{
			para->PxFCR = GPIO_FCR_OUT;
		}
		else if(temp == (uint32_t)GPIO_FCR_DIG)
		{                                         
			para->PxFCR = GPIO_FCR_DIG;
		}
		else
		{
			para->PxFCR = GPIO_FCR_ANA;
		}
	}  
}

/********************************
��ȡGPIOx�������ݼĴ�������
����:��ȡGPIOx�������ݼĴ���
���룺GPIOx_PIN���� 
���: ���ݼĴ���ֵ
********************************/
uint32_t GPIO_ReadInputData(GPIO_Type* GPIOx)
{
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	
//	return(GPIOx_DIN_Read(GPIOx));
	return (GPIOx->DIN);
}

/********************************
��ȡGPIOx�������ݼĴ���bit����
����:GPIOx�������ݼĴ���bit
���룺GPIO�˿�  GPIO_PIN���� 
���: bit״̬
********************************/
uint8_t GPIO_ReadInputDataBit(GPIO_Type* GPIOx, uint32_t GPIO_Pin)
{
	uint8_t bitstatus = 0x00;

	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_GET_GPIO_PIN(GPIO_Pin));

	if ((GPIOx->DIN & GPIO_Pin) != (uint32_t)Bit_RESET)
	{
			bitstatus = (uint8_t)Bit_SET;
	}
	else
	{
			bitstatus = (uint8_t)Bit_RESET;
	}
	return bitstatus;
}

/********************************
GPIOx�����1����
����: GPIOx�����1
���룺GPIO�˿�  GPIO_PIN���� 
���: ��
********************************/
void GPIO_SetBits(GPIO_Type* GPIOx, uint32_t GPIO_Pin)
{
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(GPIO_Pin));

//	GPIOx_DSET_Write(GPIOx, Pin);
    GPIOx->DSET = GPIO_Pin;
}

/********************************
GPIOx�����0����
����: GPIOx�����0
���룺GPIO�˿�  GPIO_PIN���� 
���: ��
********************************/
void GPIO_ResetBits(GPIO_Type* GPIOx, uint32_t GPIO_Pin)
{
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(GPIO_Pin));
	
//	GPIOx_DRESET_Write(GPIOx, Pin);
    GPIOx->DRST = GPIO_Pin;
}

/********************************
GPIOx�����ת����
����: GPIOx�����0
���룺GPIO�˿�  GPIO_PIN���� 
���: ��
********************************/
void GPIO_ToggleBits(GPIO_Type* GPIOx, uint32_t GPIO_Pin)
{
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(GPIO_Pin));
	
	if(GPIO_Pin&GPIOx->DO)
	{
		//GPIO_ResetBits(GPIOx, GPIO_Pin);
		GPIOx->DRST = GPIO_Pin;	
	}
	else
	{
		//GPIO_SetBits(GPIOx, GPIO_Pin);	
		GPIOx->DSET = GPIO_Pin;
	}
}

/********************************
��ȡGPIOx������ݼĴ�������
����:��ȡGPIOx������ݼĴ���
���룺GPIOx_PIN���� 
���: ���ݼĴ���ֵ
********************************/
uint32_t GPIO_ReadOutputData(GPIO_Type* GPIOx)
{
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	
//	return(GPIOx_DO_Read(GPIOx));
	return (GPIOx->DO);
}


/********************************
��ȡGPIOx������ݼĴ���bit����
����:GPIOx������ݼĴ���bit
���룺GPIO�˿�  GPIO_PIN���� 
���: bit״̬
********************************/
uint8_t GPIO_ReadOutputDataBit(GPIO_Type* GPIOx, uint32_t GPIO_Pin)
{
    uint8_t bitstatus = 0x00;
	
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GET_GPIO_PIN(GPIO_Pin));
	
    if (((GPIOx->DO) & GPIO_Pin) != (uint32_t)Bit_RESET)
    {
        bitstatus = (uint8_t)Bit_SET;
    }
    else
    {
        bitstatus = (uint8_t)Bit_RESET;
    }
    return bitstatus;
}

/********************************
WKUP�������ú���
���ܣ�WKUP��������
���룺WKUP GPIO_PIN����        
      ENABLE ʹ��WKUP����
      DISABLE �ر�WKUP����
���: ��
********************************/
void GPIO_PINWKEN_SetableEx(uint32_t NWKPinDef, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPIO_COMMON->PINWKEN |= NWKPinDef;
	}
	else
	{
		GPIO_COMMON->PINWKEN &= ~ NWKPinDef;
	}
}

/********************************
WKUP����ѡ����
���ܣWWKUP����ѡ��
���룺WKUP GPIO_PIN����        
      ENABLE ������
      DISABLE �½���
���: ��
********************************/
void GPIO_PINWKSEL_SetableEx(uint32_t NWKPinDef, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPIO_COMMON->PINWKEN |= (NWKPinDef<<8);
	}
	else
	{
		GPIO_COMMON->PINWKEN &= ~ (NWKPinDef<<8);
	}
}

/********************************
WKUP�ж����ѡ����
���ܣWWKUP�ж����ѡ��
���룺GPIO_PINWKEN_WKISEL_NMI: NMI�ж�      
      GPIO_PINWKEN_WKISEL_38��#38�ж�
���: ��
********************************/
void GPIO_PINWKEN_WKISEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPIO_COMMON->PINWKEN;
	tmpreg &= ~(GPIO_PINWKEN_WKISEL_Msk);
	tmpreg |= (SetValue & GPIO_PINWKEN_WKISEL_Msk);
	GPIO_COMMON->PINWKEN = tmpreg;
}
/********************************
��ȡWKUP�ж����ѡ����
���ܣ���ȡWKUP�ж����ѡ��
���룺��     
���: GPIO_PINWKEN_WKISEL_NMI: NMI�ж� 
      GPIO_PINWKEN_WKISEL_38��#38�ж�
********************************/
uint32_t GPIO_PINWKEN_WKISEL_Get(void)
{
	return (GPIO_COMMON->PINWKEN & GPIO_PINWKEN_WKISEL_Msk);
}

/*************************************************************************
 �������ƣ�GPIO_EXTI_Select_Pin
 ����˵����GPIO EXTI �ⲿ����ѡ��
 ���������GPIOx �˿� GPIO_Pinpin �˿������� 
 �����������
 ���ز����w��
 *************************************************************************/
void GPIO_EXTI_Select_Pin(GPIO_Type* GPIOx,uint32_t GPIO_Pin)
{
	uint32_t pin_num = 0,i;	
	uint32_t pin_shift;
	uint32_t tmpreg;
	
	for(i= 0;i<16;i++)
	{
		if(GPIO_Pin&(1<<i))
		{
			pin_num = i;
			break;
		}
	}

	tmpreg = GPIO_COMMON->EXTI_SEL;
	
	switch((uint32_t)GPIOx)
	{
		case (uint32_t)GPIOA:
			pin_shift = (pin_num / 4) * 2;
			tmpreg &= (~(0x00000003 << pin_shift));
			tmpreg |= ((pin_num % 4) << pin_shift);
			GPIO_COMMON->EXTI_SEL = tmpreg;
			break;
		case (uint32_t)GPIOB:
			pin_shift = (pin_num / 4) * 2 + 8;
			tmpreg &= (~(0x00000003 << pin_shift));
			tmpreg |= ((pin_num % 4) << pin_shift);
			GPIO_COMMON->EXTI_SEL = tmpreg;
			break;
		case (uint32_t)GPIOC://0~12
			if(pin_num <= 12)
			{
				pin_shift = (pin_num / 4) * 2 + 16;
				tmpreg &= (~(0x00000003 << pin_shift));
				tmpreg |= ((pin_num % 4) << pin_shift);
				GPIO_COMMON->EXTI_SEL = tmpreg;
			}
			break;
		case (uint32_t)GPIOD://0~12
			if(pin_num <= 12)
			{
				pin_shift = (pin_num / 4) * 2 + 24;
				tmpreg &= (~(0x00000003 << pin_shift));
				tmpreg |= ((pin_num % 4) << pin_shift);
				GPIO_COMMON->EXTI_SEL = tmpreg;
			}
			break;
		
		default:
			break;
	}
}

/*************************************************************************
 �������ƣ�GPIO_EXTI_Select_Edge
 ����˵����GPIO EXTI_Select_Edge �ⲿ�жϱ���ѡ��
 ���������GPIOx �˿� ��GPIO_Pin �˿������� ,edge_select ������
 �����������
 ���ز����w��
 *************************************************************************/
void GPIO_EXTI_Select_Edge(GPIO_Type* GPIOx,uint32_t GPIO_Pin,GPIOExtiEdge edge_select)
{
	uint32_t pin_num = 0,i;	
	uint32_t pin_shift;
	uint32_t tmpreg;

	for(i= 0;i<16;i++)
	{
		if(GPIO_Pin&(1<<i))
		{
			pin_num = i;
			break;
		}							
	}	
	
	tmpreg = GPIO_COMMON->EXTI_EDS;
	
	switch((uint32_t)GPIOx)
	{
		case (uint32_t)GPIOA:
			pin_shift = (pin_num / 4) * 2;
			tmpreg &= (~(0x00000003 << pin_shift));
			tmpreg |= (edge_select << pin_shift);
			GPIO_COMMON->EXTI_EDS = tmpreg;
			break;
		case (uint32_t)GPIOB:
			pin_shift = (pin_num / 4) * 2 + 8;
			tmpreg &= (~(0x00000003 << pin_shift));
			tmpreg |= (edge_select << pin_shift);
			GPIO_COMMON->EXTI_EDS = tmpreg;
			break;
		case (uint32_t)GPIOC://0~12
			if(pin_num <= 12)
			{
				pin_shift = (pin_num / 4) * 2 + 16;
				tmpreg &= (~(0x00000003 << pin_shift));
				tmpreg |= (edge_select << pin_shift);
				GPIO_COMMON->EXTI_EDS = tmpreg;
			}
			break;
		case (uint32_t)GPIOD://0~12
			if(pin_num <= 12)
			{
				pin_shift = (pin_num / 4) * 2 + 24;
				tmpreg &= (~(0x00000003 << pin_shift));
				tmpreg |= (edge_select << pin_shift);
				GPIO_COMMON->EXTI_EDS = tmpreg;
			}
			break;
		
		default:
			break;
	}
}

/*************************************************************************
 �������ƣ�GPIO_EXTI_DF_SetableEx
 ����˵����GPIO GPIO_EXTI_DF_SetableEx EXTI�����˲�����
 ���������GPIOx �˿� ��GPIO_Pin �˿������� ,NewState ʹ��/��ֹ
 �����������
 ���ز����w��
 *************************************************************************/
void GPIO_EXTI_DF_SetableEx(GPIO_Type* GPIOx,uint32_t GPIO_Pin, FunState NewState)
{
	uint32_t pin_num = 0,i;	
	uint32_t pin_shift;
	uint32_t tmpreg;

	for(i= 0;i<16;i++)
	{
		if(GPIO_Pin&(1<<i))
		{
			pin_num = i;
			break;
		}							
	}	
	
	tmpreg = GPIO_COMMON->EXTI_DF;
	
	switch((uint32_t)GPIOx)
	{
		case (uint32_t)GPIOA:
			pin_shift = (pin_num / 4);
			tmpreg &= (~(0x00000001 << pin_shift));
			tmpreg |= (NewState << pin_shift);
			GPIO_COMMON->EXTI_DF = tmpreg;
			break;
		case (uint32_t)GPIOB:
			pin_shift = (pin_num / 4) + 4;
			tmpreg &= (~(0x00000001 << pin_shift));
			tmpreg |= (NewState << pin_shift);
			GPIO_COMMON->EXTI_DF = tmpreg;
			break;
		case (uint32_t)GPIOC://0~12
			if(pin_num <= 12)
			{
				pin_shift = (pin_num / 4) + 8;
				tmpreg &= (~(0x00000001 << pin_shift));
				tmpreg |= (NewState << pin_shift);
				GPIO_COMMON->EXTI_DF = tmpreg;
			}
			break;
		case (uint32_t)GPIOD://0~12
			if(pin_num <= 12)
			{
				pin_shift = (pin_num / 4) + 12;
				tmpreg &= (~(0x00000001 << pin_shift));
				tmpreg |= (NewState << pin_shift);
				GPIO_COMMON->EXTI_DF = tmpreg;
			}
			break;
		
		default:
			break;
	}
}

/*************************************************************************
 �������ƣ�GPIO_EXTI_ISR_ClrEx
 ����˵����GPIO_EXTI_ISR_ClrEx ����жϱ�־
 ���������GPIOx �˿� ��GPIO_Pin �˿������� 
 �����������
 ���ز����w��
 *************************************************************************/
void GPIO_EXTI_ISR_ClrEx(GPIO_Type* GPIOx,uint32_t GPIO_Pin)
{
	uint32_t pin_num = 0,i;	
	uint32_t pin_shift;

	for(i= 0;i<16;i++)
	{
		if(GPIO_Pin&(1<<i))
		{
			pin_num = i;
			break;
		}							
	}	
	
	switch((uint32_t)GPIOx)
	{
		case (uint32_t)GPIOA:
			pin_shift = (pin_num / 4);
			GPIO_COMMON->EXTI_ISR = (1 << pin_shift);
			break;
		case (uint32_t)GPIOB:
			pin_shift = (pin_num / 4) + 4;
			GPIO_COMMON->EXTI_ISR = (1 << pin_shift);
			break;
		case (uint32_t)GPIOC://0~12
			if(pin_num <= 12)
			{
				pin_shift = (pin_num / 4) + 8;
				GPIO_COMMON->EXTI_ISR = (1 << pin_shift);
			}
			break;
		case (uint32_t)GPIOD://0~12
			if(pin_num <= 12)
			{
				pin_shift = (pin_num / 4) + 12;
				GPIO_COMMON->EXTI_ISR = (1 << pin_shift);
			}
			break;
		
		default:
			break;
	}
}

/*************************************************************************
 �������ƣ�GPIO_EXTI_ISR_ChkEx
 ����˵����GPIO_EXTI_ISR_ChkEx ��ȡ�жϱ�־״̬
 ���������GPIOx �˿� ��GPIO_Pin �˿������� 
 �����������
 ���ز����wFlagStatus �жϱ�־״̬
 *************************************************************************/
FlagStatus GPIO_EXTI_ISR_ChkEx(GPIO_Type* GPIOx,uint32_t GPIO_Pin)
{
	uint32_t pin_num = 0,i;	
	uint32_t pin_shift;
	FlagStatus Result = RESET;

	for(i= 0;i<16;i++)
	{
		if(GPIO_Pin&(1<<i))
		{
			pin_num = i;
			break;
		}							
	}	
	
	Result = RESET;
	switch((uint32_t)GPIOx)
	{
		case (uint32_t)GPIOA:
			pin_shift = (pin_num / 4);
			if (GPIO_COMMON->EXTI_ISR & (1 << pin_shift))
			{
				Result = SET;
			}
			break;
		case (uint32_t)GPIOB:
			pin_shift = (pin_num / 4) + 4;
			if (GPIO_COMMON->EXTI_ISR & (1 << pin_shift))
			{
				Result = SET;
			}
			break;
		case (uint32_t)GPIOC://0~12
			if(pin_num <= 12)
			{
				pin_shift = (pin_num / 4) + 8;
				if (GPIO_COMMON->EXTI_ISR & (1 << pin_shift))
				{
					Result = SET;
				}
			}
			break;
		case (uint32_t)GPIOD://0~12
			if(pin_num <= 12)
			{
				pin_shift = (pin_num / 4) + 12;
				if (GPIO_COMMON->EXTI_ISR & (1 << pin_shift))
				{
					Result = SET;
				}
			}
			break;
		
		default:
			break;
	}
	
	return Result;
}

/* EXTI�����źżĴ��� ��غ��� */
uint32_t GPIO_EXTI_DI_Read(void)
{
	return GPIO_COMMON->EXTI_DI;
}

/*************************************************************************
 �������ƣ�GPIO_EXTI_Init
 ����˵����GPIO_EXTI_Init �ⲿ�жϳ�ʼ��
 ���������port �˿� ��pin �˿������� ,edge ������
 �����������
 ���ز����w��
 *************************************************************************/
//FM33L0XX ��4��GPIO��A~D�������Բ���16���ⲿ�����жϣ�����IO����ͬʱ�����жϹ���
void GPIO_EXTI_Init(GPIO_Type* GPIOx,uint32_t GPIO_Pin,GPIOExtiEdge edge_select, FunState DFState)
{
	GPIO_EXTI_Select_Edge(GPIOx, GPIO_Pin, EXTI_DISABLE);	//�رձ��ش���
	GPIO_EXTI_Select_Pin(GPIOx, GPIO_Pin);								//�ⲿ����ѡ��
	GPIO_EXTI_DF_SetableEx(GPIOx, GPIO_Pin, DFState);			//�޸�EXTI�����˲�����
	GPIO_EXTI_Select_Edge(GPIOx, GPIO_Pin, edge_select);	//�޸ı���ѡ��
	GPIO_EXTI_ISR_ClrEx(GPIOx, GPIO_Pin);							//����жϱ�־
}

/*************************************************************************
 �������ƣ�GPIO_EXTI_Close
 ����˵����GPIO_EXTI_Close �ⲿ�жϹر�
 ���������port �˿� ��pin �˿������� 
 �����������
 ���ز����w��
 *************************************************************************/
void GPIO_EXTI_Close(GPIO_Type* GPIOx,uint32_t GPIO_Pin)
{
	GPIO_EXTI_Select_Edge(GPIOx, GPIO_Pin, EXTI_DISABLE);//�رձ��ش���
}	
  
  
/******END OF FILE****/
