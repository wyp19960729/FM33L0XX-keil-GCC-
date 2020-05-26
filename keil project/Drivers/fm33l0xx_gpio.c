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
 PortX输出数据寄存器配置函数
功能: 配置PortX输出数据
输入：GPIO_Type* GPIOx（管脚号）,  uint32_t SetValue（输出值）
输出:无
********************************/
void GPIOx_DO_Write(GPIO_Type* GPIOx, uint32_t SetValue)
{
	GPIOx->DO = (SetValue & GPIOx_DO_DO_Msk);
}
/********************************
读PortX输出数据状态函数
功能:读PortX输出数据状态
输入：无
输出:PortX输出值
********************************/
uint32_t GPIOx_DO_Read(GPIO_Type* GPIOx)
{
	return (GPIOx->DO & GPIOx_DO_DO_Msk);
}

/********************************
PortX输出数据置位寄存器函数
功能:PortX输出数据置位，如向PADSET写0x0000_8000，则PADO[15]置位，其余位保持不变。
输入：GPIO_Type* GPIOx（管脚号）,  uint32_t SetValue（输出值）
输出:无
********************************/
void GPIOx_DSET_Write(GPIO_Type* GPIOx, uint32_t SetValue)
{
	GPIOx->DSET = (SetValue & GPIOx_DSET_DSET_Msk);
}

/********************************
PortX输出数据复位寄存器函数
功能:PortX输出数据复位，如向PADRST写0x0000_8000，则PADO[15]清零，其余位保持不变。
输入：GPIO_Type* GPIOx（管脚号）,  uint32_t SetValue（输出值）
输出:无
********************************/
void GPIOx_DRST_Write(GPIO_Type* GPIOx, uint32_t SetValue)
{
	GPIOx->DRST = (SetValue & GPIOx_DRST_DRESET_Msk);
}

/********************************
PortX输入数据寄存器函数
功能:PortX输入数据，此寄存器仅占用地址空间，无物理实现。软件读此寄存器直接返回引脚输入信号，芯片并不对引脚输入进行锁存
输入：GPIO_Type* GPIOx（管脚号）,  uint32_t SetValue（输入值）
输出:无
********************************/
uint32_t GPIOx_DIN_Read(GPIO_Type* GPIOx)
{
	return (GPIOx->DIN & GPIOx_DIN_DIN_Msk);
}

/* PortX额外数字功能寄存器 相关函数 */
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

/* PortX强驱动使能寄存器 相关函数 */
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

/* PortX模拟开关使能寄存器 相关函数 */
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
 FOUT输出配置函数
功能: 配置FOUT输出
输入：输出频率选择信号
输出:无
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
读FOUT输出状态函数
功能:读FOUT输出状态
输入：无
输出:FOUT输出选择值
********************************/
uint32_t GPIO_FOUT1SEL_Get(void)
{
	return (GPIO_COMMON->FOUT_SEL & GPIO_FOUT_SEL_FOUT1SEL_Msk);
}

/********************************
 FOUT输出配置函数
功能: 配置FOUT输出
输入：输出频率选择信号
输出:无
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
读FOUT输出状态函数
功能:读FOUT输出状态
输入：无
输出:FOUT输出选择值
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
GPIO初始化配置函数
功能:GPIO初始化配置
输入：GPIO端口  GPIO_PIN引脚
输出: 无
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

/* 获取一个IO口的配置参数结构体 
	注意一次只能读取一个IO的配置
*/
/********************************
获取一个IO配置参数结构体函数
功能:获取一个IO配置参数结构体
输入：GPIO端口  GPIO_PIN引脚 引脚类型
输出: 无
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
读取GPIOx输入数据寄存器函数
功能:读取GPIOx输入数据寄存器
输入：GPIOx_PIN引脚 
输出: 数据寄存器值
********************************/
uint32_t GPIO_ReadInputData(GPIO_Type* GPIOx)
{
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	
//	return(GPIOx_DIN_Read(GPIOx));
	return (GPIOx->DIN);
}

/********************************
读取GPIOx输入数据寄存器bit函数
功能:GPIOx输入数据寄存器bit
输入：GPIO端口  GPIO_PIN引脚 
输出: bit状态
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
GPIOx输出置1函数
功能: GPIOx输出置1
输入：GPIO端口  GPIO_PIN引脚 
输出: 无
********************************/
void GPIO_SetBits(GPIO_Type* GPIOx, uint32_t GPIO_Pin)
{
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(GPIO_Pin));

//	GPIOx_DSET_Write(GPIOx, Pin);
    GPIOx->DSET = GPIO_Pin;
}

/********************************
GPIOx输出置0函数
功能: GPIOx输出置0
输入：GPIO端口  GPIO_PIN引脚 
输出: 无
********************************/
void GPIO_ResetBits(GPIO_Type* GPIOx, uint32_t GPIO_Pin)
{
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(GPIO_Pin));
	
//	GPIOx_DRESET_Write(GPIOx, Pin);
    GPIOx->DRST = GPIO_Pin;
}

/********************************
GPIOx输出翻转函数
功能: GPIOx输出置0
输入：GPIO端口  GPIO_PIN引脚 
输出: 无
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
读取GPIOx输出数据寄存器函数
功能:读取GPIOx输出数据寄存器
输入：GPIOx_PIN引脚 
输出: 数据寄存器值
********************************/
uint32_t GPIO_ReadOutputData(GPIO_Type* GPIOx)
{
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	
//	return(GPIOx_DO_Read(GPIOx));
	return (GPIOx->DO);
}


/********************************
读取GPIOx输出数据寄存器bit函数
功能:GPIOx输出数据寄存器bit
输入：GPIO端口  GPIO_PIN引脚 
输出: bit状态
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
WKUP引脚配置函数
功能：WKUP引脚配置
输入：WKUP GPIO_PIN引脚        
      ENABLE 使能WKUP功能
      DISABLE 关闭WKUP功能
输出: 无
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
WKUP边沿选择函数
功能WKUP边沿选择
输入：WKUP GPIO_PIN引脚        
      ENABLE 上升沿
      DISABLE 下降沿
输出: 无
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
WKUP中断入口选择函数
功能WKUP中断入口选择
输入：GPIO_PINWKEN_WKISEL_NMI: NMI中断      
      GPIO_PINWKEN_WKISEL_38：#38中断
输出: 无
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
读取WKUP中断入口选择函数
功能：读取WKUP中断入口选择
输入：无     
输出: GPIO_PINWKEN_WKISEL_NMI: NMI中断 
      GPIO_PINWKEN_WKISEL_38：#38中断
********************************/
uint32_t GPIO_PINWKEN_WKISEL_Get(void)
{
	return (GPIO_COMMON->PINWKEN & GPIO_PINWKEN_WKISEL_Msk);
}

/*************************************************************************
 函数名称：GPIO_EXTI_Select_Pin
 功能说明：GPIO EXTI 外部引脚选择
 输入参数：GPIOx 端口 GPIO_Pinpin 端口内引脚 
 输出参数：无
 返回参数无
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
 函数名称：GPIO_EXTI_Select_Edge
 功能说明：GPIO EXTI_Select_Edge 外部中断边沿选择
 输入参数：GPIOx 端口 ，GPIO_Pin 端口内引脚 ,edge_select 触发沿
 输出参数：无
 返回参数无
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
 函数名称：GPIO_EXTI_DF_SetableEx
 功能说明：GPIO GPIO_EXTI_DF_SetableEx EXTI数字滤波控制
 输入参数：GPIOx 端口 ，GPIO_Pin 端口内引脚 ,NewState 使能/禁止
 输出参数：无
 返回参数无
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
 函数名称：GPIO_EXTI_ISR_ClrEx
 功能说明：GPIO_EXTI_ISR_ClrEx 清除中断标志
 输入参数：GPIOx 端口 ，GPIO_Pin 端口内引脚 
 输出参数：无
 返回参数无
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
 函数名称：GPIO_EXTI_ISR_ChkEx
 功能说明：GPIO_EXTI_ISR_ChkEx 读取中断标志状态
 输入参数：GPIOx 端口 ，GPIO_Pin 端口内引脚 
 输出参数：无
 返回参数FlagStatus 中断标志状态
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

/* EXTI输入信号寄存器 相关函数 */
uint32_t GPIO_EXTI_DI_Read(void)
{
	return GPIO_COMMON->EXTI_DI;
}

/*************************************************************************
 函数名称：GPIO_EXTI_Init
 功能说明：GPIO_EXTI_Init 外部中断初始化
 输入参数：port 端口 ，pin 端口内引脚 ,edge 触发沿
 输出参数：无
 返回参数无
 *************************************************************************/
//FM33L0XX 的4组GPIO（A~D）最多可以产生16个外部引脚中断，部分IO不能同时开启中断功能
void GPIO_EXTI_Init(GPIO_Type* GPIOx,uint32_t GPIO_Pin,GPIOExtiEdge edge_select, FunState DFState)
{
	GPIO_EXTI_Select_Edge(GPIOx, GPIO_Pin, EXTI_DISABLE);	//关闭边沿触发
	GPIO_EXTI_Select_Pin(GPIOx, GPIO_Pin);								//外部引脚选择
	GPIO_EXTI_DF_SetableEx(GPIOx, GPIO_Pin, DFState);			//修改EXTI数字滤波功能
	GPIO_EXTI_Select_Edge(GPIOx, GPIO_Pin, edge_select);	//修改边沿选择
	GPIO_EXTI_ISR_ClrEx(GPIOx, GPIO_Pin);							//清除中断标志
}

/*************************************************************************
 函数名称：GPIO_EXTI_Close
 功能说明：GPIO_EXTI_Close 外部中断关闭
 输入参数：port 端口 ，pin 端口内引脚 
 输出参数：无
 返回参数无
 *************************************************************************/
void GPIO_EXTI_Close(GPIO_Type* GPIOx,uint32_t GPIO_Pin)
{
	GPIO_EXTI_Select_Edge(GPIOx, GPIO_Pin, EXTI_DISABLE);//关闭边沿触发
}	
  
  
/******END OF FILE****/
