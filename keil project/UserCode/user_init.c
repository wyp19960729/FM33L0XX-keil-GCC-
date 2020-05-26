#include "define_all.h"  

//cpu滴答定时器配置(软件延时用)
void Init_SysTick(void)
{
    SysTick_Config(0x1000000UL);
    SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |//关闭中断
                    //SysTick_CTRL_TICKINT_Msk |
                    SysTick_CTRL_ENABLE_Msk;
}
//调用软件延时前必须先配置SysTick
void TicksDelay(uint32_t ClkNum)
{
    uint32_t last = SysTick->VAL;
    
    ClkNum = ClkNum*clkmode;//适应不同主频，8M时最大定时2ms，32M时最大定时0.5ms
    if(ClkNum>0xF00000)
    {
        ClkNum = 0xF00000;
    }
    while(((last - SysTick->VAL)&0xFFFFFFUL ) < ClkNum);
}
//ms软件延时
void TicksDelayMs(uint32_t ms , ConditionHook Hook)
{
    uint32_t ClkNum;
    
    ClkNum = (__SYSTEM_CLOCK/1000) ;
    for(;ms>0;ms--)
    {
        if(Hook!=NULL)
        {
            if(Hook()) return ;
        }
        TicksDelay(ClkNum);
    }
}
//us软件延时
void TicksDelayUs(uint32_t us)
{
    uint32_t ClkNum;
    
    if(us>100000)//不大于100ms
    {
        us = 100000;
    }
    ClkNum = us*(__SYSTEM_CLOCK/1000000) ;
    TicksDelay(ClkNum);
}

//校验寄存器
unsigned char CheckSysReg( __IO uint32_t *RegAddr, uint32_t Value )
{
	if( *RegAddr != Value ) 
	{
		*RegAddr = Value;
		return 1;
	}
	else
	{
		return 0;
	}
}

//查询NVIC寄存器对应向量号中断是否打开
//1 打开
//0 关闭
unsigned char CheckNvicIrqEn( IRQn_Type IRQn )
{
	if( 0 == ( NVIC->ISER[0U] & ((uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL)))) )
		return 0;
	else
		return 1;
}

//IO模拟功能配置:LCD/ADC
void AnalogIO( GPIO_Type* GPIOx, uint32_t PinNum )
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	GPIO_InitTypeDef  GPIO_InitStructureRun;
	
	GPIO_Get_InitPara(GPIOx, PinNum, &GPIO_InitStructureRun);
	
	if( (GPIO_InitStructureRun.Pin		!= PinNum) ||
		(GPIO_InitStructureRun.PxINEN	!= GPIO_IN_Dis) ||
		(GPIO_InitStructureRun.PxODEN	!= GPIO_OD_En) ||
		(GPIO_InitStructureRun.PxPUEN	!= GPIO_PU_Dis) ||
		(GPIO_InitStructureRun.PxFCR	!= GPIO_FCR_ANA) )
	{
		GPIO_InitStructure.Pin = PinNum;
		GPIO_InitStructure.PxINEN = GPIO_IN_Dis;
		GPIO_InitStructure.PxODEN = GPIO_OD_En;
		GPIO_InitStructure.PxPUEN = GPIO_PU_Dis;
		GPIO_InitStructure.PxFCR = GPIO_FCR_ANA;
		
		GPIO_Init(GPIOx, &GPIO_InitStructure);		
	}	
}

//IO输入口配置 
//type 0 = 普通 
//type 1 = 上拉
//#define IN_NORMAL	0
//#define IN_PULLUP	1
void InputtIO( GPIO_Type* GPIOx, uint32_t PinNum, uint8_t Type )
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	GPIO_InitTypeDef  GPIO_InitStructureRun;
	
	GPIO_Get_InitPara(GPIOx, PinNum, &GPIO_InitStructureRun);
		
	if( (GPIO_InitStructureRun.Pin		!= PinNum) ||
		(GPIO_InitStructureRun.PxINEN	!= GPIO_IN_En) ||
		(GPIO_InitStructureRun.PxODEN	!= GPIO_OD_En) ||
		((Type == IN_NORMAL)&&(GPIO_InitStructureRun.PxPUEN != GPIO_PU_Dis)) ||
		((Type == IN_PULLUP)&&(GPIO_InitStructureRun.PxPUEN != GPIO_PU_En)) ||
		(GPIO_InitStructureRun.PxFCR	!= GPIO_FCR_IN) )
	{
		GPIO_InitStructure.Pin = PinNum;	
		GPIO_InitStructure.PxINEN = GPIO_IN_En;
		GPIO_InitStructure.PxODEN = GPIO_OD_En;
		if(Type == IN_NORMAL)		GPIO_InitStructure.PxPUEN = GPIO_PU_Dis;
		else						GPIO_InitStructure.PxPUEN = GPIO_PU_En;	
		GPIO_InitStructure.PxFCR = GPIO_FCR_IN;
		
		GPIO_Init(GPIOx, &GPIO_InitStructure);	
	}
}

//IO输出口配置 
//type 0 = 普通 
//type 1 = OD
//#define OUT_PUSHPULL	0
//#define OUT_OPENDRAIN	1
void OutputIO( GPIO_Type* GPIOx, uint32_t PinNum, uint8_t Type )
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	GPIO_InitTypeDef  GPIO_InitStructureRun;
	
	GPIO_Get_InitPara(GPIOx, PinNum, &GPIO_InitStructureRun);
	
	if( (GPIO_InitStructureRun.Pin		!= PinNum) ||
		(GPIO_InitStructureRun.PxINEN	!= GPIO_IN_Dis) ||
		((Type == OUT_PUSHPULL)&&(GPIO_InitStructureRun.PxODEN	!= GPIO_OD_Dis)) ||
		((Type == OUT_OPENDRAIN)&&(GPIO_InitStructureRun.PxODEN	!= GPIO_OD_En)) ||
		(GPIO_InitStructureRun.PxPUEN	!= GPIO_PU_Dis) ||
		(GPIO_InitStructureRun.PxFCR	!= GPIO_FCR_OUT) )
	{
		GPIO_InitStructure.Pin = PinNum;
		GPIO_InitStructure.PxINEN = GPIO_IN_Dis;
		if(Type == OUT_PUSHPULL)	GPIO_InitStructure.PxODEN = GPIO_OD_Dis;
		else						GPIO_InitStructure.PxODEN = GPIO_OD_En;
		GPIO_InitStructure.PxPUEN = GPIO_PU_Dis;
		GPIO_InitStructure.PxFCR = GPIO_FCR_OUT;
		 
		GPIO_Init(GPIOx, &GPIO_InitStructure);		
	}
}
//IO数字特殊功能口 
//type 0 = 普通 
//type 1 = OD (OD功能仅部分特殊功能支持)
//type 2 = 普通+上拉 
//type 3 = OD+上拉
//#define ALTFUN_NORMAL				0
//#define ALTFUN_OPENDRAIN			1
//#define ALTFUN_PULLUP				2
//#define ALTFUN_OPENDRAIN_PULLUP	3
void AltFunIO( GPIO_Type* GPIOx, uint32_t PinNum, uint8_t Type  )
{																
	GPIO_InitTypeDef  GPIO_InitStructure;
	GPIO_InitTypeDef  GPIO_InitStructureRun;
	
	GPIO_Get_InitPara(GPIOx, PinNum, &GPIO_InitStructureRun);
	
	if( (GPIO_InitStructureRun.Pin		!= PinNum) ||
		(GPIO_InitStructureRun.PxINEN	!= GPIO_IN_Dis) ||
		(((Type & 0x01) == 0)&&(GPIO_InitStructureRun.PxODEN	!= GPIO_OD_Dis)) ||
		(((Type & 0x01) != 0)&&(GPIO_InitStructureRun.PxODEN	!= GPIO_OD_En)) ||
		(((Type & 0x02) == 0)&&(GPIO_InitStructureRun.PxPUEN	!= GPIO_PU_Dis)) ||
		(((Type & 0x02) != 0)&&(GPIO_InitStructureRun.PxPUEN	!= GPIO_PU_En)) ||
		(GPIO_InitStructureRun.PxFCR	!= GPIO_FCR_DIG) )
	{
		GPIO_InitStructure.Pin = PinNum;
		GPIO_InitStructure.PxINEN = GPIO_IN_Dis;
		if( (Type & 0x01) == 0 )	GPIO_InitStructure.PxODEN = GPIO_OD_Dis;
		else						GPIO_InitStructure.PxODEN = GPIO_OD_En;
		if( (Type & 0x02) == 0 )	GPIO_InitStructure.PxPUEN = GPIO_PU_Dis;
		else						GPIO_InitStructure.PxPUEN = GPIO_PU_En;	
		GPIO_InitStructure.PxFCR = GPIO_FCR_DIG;
		 
		GPIO_Init(GPIOx, &GPIO_InitStructure);		
	}
}

//IO关闭（od输出高）
//当输入使能有效时，如果外部信号浮空，也可能导致FM385管脚漏电；
//可以将FCR配置为01（GPIO输出），ODEN配置为1，即伪开漏输出，关闭上拉使能，并将输出数据设为1
//注意SWD接口的PG8,9如果程序改变它们的配置将无法仿真
void CloseeIO( GPIO_Type* GPIOx, uint32_t PinNum )
{
	GPIO_InitTypeDef  GPIO_InitStructureRun;
	
	GPIO_Get_InitPara(GPIOx, PinNum, &GPIO_InitStructureRun);
		
	if((GPIO_InitStructureRun.PxFCR	!= GPIO_FCR_OUT))
	{
		GPIO_SetBits(GPIOx, PinNum);
		OutputIO( GPIOx, PinNum, OUT_OPENDRAIN );
	}
	else
	{
		OutputIO( GPIOx, PinNum, OUT_OPENDRAIN );
		GPIO_SetBits(GPIOx, PinNum);		
	}
}

//IO口初始输出状态配置
void Init_Pad_Io(void)
{	
	GPIOx_DO_Write(GPIOA, 0x0000);	
	GPIOx_DO_Write(GPIOB, 0x0000);	
	GPIOx_DO_Write(GPIOC, 0x0000);	
	GPIOx_DO_Write(GPIOD, 0x0000);	
}

void Close_AllIOEXTI(void)
{
  GPIO_COMMON->EXTI_EDS =0xFFFFFFFF;
}



//关闭64脚芯片可使用的全部IO(SWD口除外，关闭后不能仿真)
void Close_AllIO_GPIO_64pin( void )
{		
  Close_AllIOEXTI();
  
	CloseeIO( GPIOA, GPIO_Pin_0 );	//PA0; //
	CloseeIO( GPIOA, GPIO_Pin_1 );	//PA1; //
	CloseeIO( GPIOA, GPIO_Pin_2 );	//PA2; //
	CloseeIO( GPIOA, GPIO_Pin_3 );	//PA3; //
	CloseeIO( GPIOA, GPIO_Pin_4 );	//PA4; //
	CloseeIO( GPIOA, GPIO_Pin_5 );	//PA5; //
	CloseeIO( GPIOA, GPIO_Pin_6 );	//PA6; //
	CloseeIO( GPIOA, GPIO_Pin_7 );	//PA7; //
	CloseeIO( GPIOA, GPIO_Pin_8 );	//PA8; //
	CloseeIO( GPIOA, GPIO_Pin_9 );	//PA9; //
	CloseeIO( GPIOA, GPIO_Pin_10 );	//PA10;//
	CloseeIO( GPIOA, GPIO_Pin_11 );	//PA11;//
	CloseeIO( GPIOA, GPIO_Pin_12 );	//PA12;//
	CloseeIO( GPIOA, GPIO_Pin_13 );	//PA13;//
	CloseeIO( GPIOA, GPIO_Pin_14 );	//PA14;//
	CloseeIO( GPIOA, GPIO_Pin_15 );	//PA15;//

	CloseeIO( GPIOB, GPIO_Pin_0 );	//PB0; //
	CloseeIO( GPIOB, GPIO_Pin_1 );	//PB1; //
	CloseeIO( GPIOB, GPIO_Pin_2 );	//PB2; //
	CloseeIO( GPIOB, GPIO_Pin_3 );	//PB3; //
	CloseeIO( GPIOB, GPIO_Pin_4 );	//PB4; //
	CloseeIO( GPIOB, GPIO_Pin_5 );	//PB5; //
	CloseeIO( GPIOB, GPIO_Pin_6 );	//PB6; //
	CloseeIO( GPIOB, GPIO_Pin_7 );	//PB7; //
	CloseeIO( GPIOB, GPIO_Pin_8 );	//PB8; //
	CloseeIO( GPIOB, GPIO_Pin_9 );	//PB9; //
	CloseeIO( GPIOB, GPIO_Pin_10 );	//PB10;//
	CloseeIO( GPIOB, GPIO_Pin_11 );	//PB11;//
	CloseeIO( GPIOB, GPIO_Pin_12 );	//PB12;//
	CloseeIO( GPIOB, GPIO_Pin_13 );	//PB13;//
	CloseeIO( GPIOB, GPIO_Pin_14 );	//PB14;//
	CloseeIO( GPIOB, GPIO_Pin_15 );	//PB15;//
	
	CloseeIO( GPIOC, GPIO_Pin_2 );	//PC2; //
	CloseeIO( GPIOC, GPIO_Pin_3 );	//PC3; //
	CloseeIO( GPIOC, GPIO_Pin_4 );	//PC4; //
	CloseeIO( GPIOC, GPIO_Pin_5 );	//PC5; //
	CloseeIO( GPIOC, GPIO_Pin_6 );	//PC6; //
	CloseeIO( GPIOC, GPIO_Pin_7 );	//PC7; //
	CloseeIO( GPIOC, GPIO_Pin_8 );	//PC8; //
	CloseeIO( GPIOC, GPIO_Pin_9 );	//PC9; //
	CloseeIO( GPIOC, GPIO_Pin_10 );	//PC10;//
	CloseeIO( GPIOC, GPIO_Pin_11 );	//PC11;//
	CloseeIO( GPIOC, GPIO_Pin_12 );	//PC12;//

	
	CloseeIO( GPIOD, GPIO_Pin_0 );	//PD0;//
	CloseeIO( GPIOD, GPIO_Pin_1 );	//PD1;//
	CloseeIO( GPIOD, GPIO_Pin_2 );	//PD2;//
	CloseeIO( GPIOD, GPIO_Pin_3 );	//PD3;//
	CloseeIO( GPIOD, GPIO_Pin_4 );	//PD4;//
	CloseeIO( GPIOD, GPIO_Pin_5 );	//PD5;//
	CloseeIO( GPIOD, GPIO_Pin_6 );	//PD6;//
//  CloseeIO( GPIOD, GPIO_Pin_6 );	//PD7;//SWD
//  CloseeIO( GPIOD, GPIO_Pin_6 );	//PD8;//SWD
//  CloseeIO( GPIOD, GPIO_Pin_9 );	//PD9;//XTLF
//  CloseeIO( GPIOD, GPIO_Pin_10);	//PD10;//XTLF
  CloseeIO( GPIOD, GPIO_Pin_11);	//PD11;//
  CloseeIO( GPIOD, GPIO_Pin_12);	//PD12;//
}

//默认开启大部分外设时钟，用户可按需求关闭不需要的时钟
//时钟开启关闭对功耗影响不大
void Init_RCC_PERIPH_clk(void)
{
	//PERCLK1
	RCC_PERCLK_SetableEx( DCUCLK, 		ENABLE );		//DCU APB bus clock enable
	RCC_PERCLK_SetableEx( BEEPCLK, 	ENABLE );		//Beep APB bus clock enable
	RCC_PERCLK_SetableEx( PADCLK, 	ENABLE );		//GPIO controller APB bus clock enable
	RCC_PERCLK_SetableEx( ANACCLK, 	ENABLE );		//Analog controller APB bus clock enable
	RCC_PERCLK_SetableEx( IWDTCLK, 		ENABLE );		//IWDT APB bus clock enable
	RCC_PERCLK_SetableEx( SCUCLK, 		ENABLE );		//System controller APB bus clock enable
	//RCC_PERCLK_SetableEx( PMUCLK, 		ENABLE );		//PMU APB bus clock enable
	RCC_PERCLK_SetableEx( RTCCLK, 		ENABLE );		//RTC APB bus clock enable
	RCC_PERCLK_SetableEx( LPTCLK, 		ENABLE );		//LPTIM APB bus clock enable
				
  //PERCLK2 
	RCC_PERCLK_SetableEx( ADCCLK, 		ENABLE );		//ADC controller APB bus clock enable
	RCC_PERCLK_SetableEx( WWDTCLK, 		ENABLE );		//WWDT APB bus clock enable
	RCC_PERCLK_SetableEx( RAMBISTCLK, 	DISABLE );		//RAMBIST APB bus clock enable
	RCC_PERCLK_SetableEx( FLSCLK, 	 DISABLE );		//Flash interface APB bus clock enable
	RCC_PERCLK_SetableEx( DMACLK, 		ENABLE );		//DMA APB bus clock enable
	RCC_PERCLK_SetableEx( LCDCLK, 		ENABLE );		//LCD APB bus clock enable
	RCC_PERCLK_SetableEx( AESCLK, 		ENABLE );		//AES APB bus clock enable
	RCC_PERCLK_SetableEx( RNGCLK, 		ENABLE );		//RNG APB bus clock enable
	RCC_PERCLK_SetableEx( CRCCLK, 		ENABLE );		//CRC APB bus clock enable

  //PERCLK3 
	RCC_PERCLK_SetableEx( I2CCLK, 		ENABLE );		//I2C APB bus clock enable
	RCC_PERCLK_SetableEx( LPUART1CLK, 	ENABLE );		//LPUART1 APB bus clock enable
	RCC_PERCLK_SetableEx( U7816CLK, 	ENABLE );		//U7816 APB bus clock enable
	RCC_PERCLK_SetableEx( LPUART0CLK, 	ENABLE );		//LPUART0 APB bus clock enable
	RCC_PERCLK_SetableEx( UCIRCLK, 	ENABLE );		//UART infra-red APB bus clock enable
	RCC_PERCLK_SetableEx( UART5CLK, 	ENABLE );		//UART5 APB bus clock enable
	RCC_PERCLK_SetableEx( UART4CLK, 	ENABLE );		//UART4 APB bus clock enable
	RCC_PERCLK_SetableEx( UART1CLK, 	ENABLE );		//UART1 APB bus clock enable
	RCC_PERCLK_SetableEx( UART0CLK, 		ENABLE );		//UART0 APB bus clock enable
	RCC_PERCLK_SetableEx( SPI2CLK, 		ENABLE );		//SPI2 APB bus clock enable
	RCC_PERCLK_SetableEx( SPI1CLK, 		ENABLE );		//SPI1 APB bus clock enable

  //PERCLK4 
	RCC_PERCLK_SetableEx( ATCLK, 		ENABLE );		//ATIM APB bus clock enable
	RCC_PERCLK_SetableEx( GT1CLK, 		ENABLE );		//GPTIM1 APB bus clock enable
	RCC_PERCLK_SetableEx( GT0CLK, 		ENABLE );		//GPTIM0 APB bus clock enable
	RCC_PERCLK_SetableEx( BTCLK, 		ENABLE );		//BSTIM APB bus clock enable
}

void Init_PLL(void)
{
	RCC_PLL_InitTypeDef PLL_InitStruct;
    
	PLL_InitStruct.PLLDB = 31;	//pll倍频数 = PLLDB + 1
  PLL_InitStruct.REFPRSC= RCC_PLL_CR_REFPRSC_DIV8; //时钟源8分频
	PLL_InitStruct.PLLINSEL = RCC_PLL_CR_INSEL_RCHF;	//PLL时钟源选择RCHF
	PLL_InitStruct.PLLOSEL = RCC_PLL_CR_OSEL_MUL1;	//默认选择1倍输出
	PLL_InitStruct.PLLEN = DISABLE;	//默认关闭PLL
	
	RCC_PLL_Init(&PLL_InitStruct);
	RCC_PLL_CR_EN_Setable(DISABLE);//关闭PLL
}

//系统时钟配置
//使用RCHF做主时钟,define_all.h 中SYSCLKdef宏控制系统时钟频率
void Init_SysClk(void)
{
	RCC_RCHF_InitTypeDef RCHF_InitStruct;
	RCC_SYSCLK_InitTypeDef SYSCLK_InitStruct;
	
	RCHF_InitStruct.FSEL = SYSCLKdef;//define_all.h 中SYSCLKdef宏控制系统时钟频率
	RCHF_InitStruct.RCHFEN = ENABLE;//打开RCHF
	
	RCC_RCHF_Init(&RCHF_InitStruct);
	
	SYSCLK_InitStruct.SYSCLKSEL = RCC_SYSCLK_CR_SYSCLKSEL_RCHF;	//选择RCHF做主时钟
	SYSCLK_InitStruct.STCLKSEL =  RCC_SYSCLK_CR_STCLKSEL_SCLK; //SCLK做内核systick工作时钟选择
	SYSCLK_InitStruct.AHBPRES =  RCC_SYSCLK_CR_AHBPRES_DIV1;		//AHB不分频
	SYSCLK_InitStruct.APBPRES =  RCC_SYSCLK_CR_APBPRES_DIV1;		//APB不分频
	SYSCLK_InitStruct.SLP_ENEXTI = ENABLE;//休眠模式使能外部中断采样
	SYSCLK_InitStruct.LSCATS = ENABLE;//LSCLK自动切换使能	
	
	RCC_SysClk_Init(&SYSCLK_InitStruct);
}

//Mode:0 仿真模式下运行看门狗，运行所有定时器
//Mode:1 仿真模式关闭看门狗，运行所有定时器
void DBG_Init(uint08 Mode)
{
	if(Mode == 1)//debug
	{
		DBG_CR_IWDT_STOP_Setable(ENABLE);//仿真模式下关闭IWDT
		DBG_CR_WWDT_STOP_Setable(ENABLE);//仿真模式下关闭WWDT
	}
	else//release
	{
		DBG_CR_IWDT_STOP_Setable(DISABLE);//仿真模式下运行IWDT
		DBG_CR_WWDT_STOP_Setable(DISABLE);//仿真模式下运行WWDT
	}
	
	DBG_CR_BT_STOP_Setable(DISABLE);//仿真模式下运行BSTIM
	DBG_CR_GT0_STOP_Setable(DISABLE);//仿真模式下运行GPTIM0
	DBG_CR_GT1_STOP_Setable(DISABLE);//仿真模式下运行GPTIM1
	DBG_CR_AT_STOP_Setable(DISABLE);//仿真模式下运行ATIM
}

void Init_SysClk_Gen( void )				//时钟选择相关
{	
	/*PLL配置*/
	Init_PLL();	//默认关闭PLL
	
	/*系统时钟配置*/
	Init_SysClk();	//默认使用RCHF做主时钟
	
	/*外设时钟使能配置*/	
	Init_RCC_PERIPH_clk();	//默认开启大部分外设时钟
	
	/*DMA访问RAM优先级配置*/
	RCC_AHBM_CR_MPRIL_Set(0);	//默认AHB Master优先级配置DMA优先
	
	/*下电复位配置*/
	//pdr和bor两个下电复位至少要打开一个
	//当电源电压低于下电复位电压时，芯片会被复位住		
	//pdr电压档位不准但是功耗极低（几乎无法测量）
	//bor电压档位准确但是需要增加功耗

  RCC_PDR_CR_EN_Setable(ENABLE);//打开PDR 
  RCC_BOR_CR_OFF_BOR_Setable(DISABLE);//打开BOR

	
	/*仿真控制寄存器配置*/
	#ifdef __DEBUG
	DBG_Init(1);//仿真时运行定时器,关闭看门狗
	#else
	DBG_Init(0);
	#endif
}

void IWDT_Init(void)
{
   	RCC_PERCLK_SetableEx(IWDTCLK, ENABLE);		//IWDT总线时钟使能
   	IWDT_Clr();									//清IWDT
	  IWDT_CR_CFG_Set(IWDT_CR_CFG_2S);//配置IWDT溢出周期
}

void Init_IO(void)
{
	LED0_OFF;
	LED1_OFF;
  
	OutputIO( LED0_GPIO, LED0_PIN, 0 );	 //led0
	OutputIO( LED1_GPIO, LED1_PIN, 0 );	 //led1
	OutputIO( GPIOA, GPIO_Pin_0, 0 );	 
	
	//fout 输出系统时钟64分频
//	GPIO_FOUTSEL_FOUTSEL_Set(GPIO_FOUTSEL_FOUTSEL_AHBCLKD64);
//	AltFunIO( GPIOB, GPIO_Pin_6, ALTFUN_NORMAL );
}

void LED0_Flash(uint08 Times)
{
	uint08 i;
	
	for( i=0; i<Times; i++ )
	{
        LED0_ON;
		TicksDelayMs( 100, NULL );		
		LED0_OFF;
		TicksDelayMs( 100, NULL );	
	}
}

static void RCHF_Adj_GPTimCfg(GPTIM_Type* GPTIMx, uint8_t psc)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    TIM_ICInitTypeDef        TIM_ICInitStructure;
    volatile uint32_t tmp08;
    
    GPTIMx_SMCR_SMS_Set(GPTIMx, GPTIMx_SMCR_SMS_SLAVE_DIS); //复位模式
    GPTIMx_SMCR_TS_Set(GPTIMx, GPTIMx_SMCR_TS_ITR2); //输入触发信号ITR2
    
    if (GPTIMx == GPTIM0)
    {
        RCC_PERCLK_SetableEx(GT0CLK,ENABLE);
        NVIC_DisableIRQ(GPTIM0_IRQn);
        
        GPTIMx_ITRSEL_ITR2SEL_Set(GPTIMx, GPTIM0_ITRSEL_ITR2SEL_XTLF);
    }
    else if (GPTIMx == GPTIM1)
    {
        RCC_PERCLK_SetableEx(GT1CLK,ENABLE);
        NVIC_DisableIRQ(GPTIM1_IRQn);
        
        GPTIMx_ITRSEL_ITR2SEL_Set(GPTIMx, GPTIM1_ITRSEL_ITR2SEL_XTLF);
    }
    else
    {
        // TODO: Error
        return;
    }
    
    /* 使能定时器重载寄存器ARR */
    GPTIMx_CR1_ARPE_Setable(GPTIMx, ENABLE);
    
    /* 定时器基本参数设置*/
    TIM_TimeBaseStructure.TIM_Period = 65535;
    /* 设置预分频：不预分频，即为8MHz */
    TIM_TimeBaseStructure.TIM_Prescaler = psc - 1;
    /* 时钟分频因子 ，没有用到，不用管 */
    TIM_TimeBaseStructure.TIM_ClockDivision = GPTIMx_CR1_CKD_1TINT;
    /* 计数器计数模式*/
    TIM_TimeBaseStructure.TIM_CounterMode = GPTIMx_CR1_DIR_UP; 
    /* 初始化定时*/
    GPTIMx_TimeBaseInit(GPTIMx, &TIM_TimeBaseStructure);

    /* CC1S=01 	选择输入端IC1映射到TRC上 */
    TIM_ICInitStructure.TIM_Channel     = TIM_Channel_1;
    /* 上升沿捕获 */
    TIM_ICInitStructure.TIM_ICPolarity  = GPTIMx_CCER_CC1P_HIGH;	
    /* 映射到TRC上 */
    TIM_ICInitStructure.TIM_ICSelection = GPTIMx_CCMR1_CC1S_TRC;  
    /* 配置输入分频,不分频  */
    TIM_ICInitStructure.TIM_ICPrescaler = GPTIMx_CCMR1_IC1PSC_DIV8;	           
    /* IC1F=0000 配置输入滤波器 不滤波 */
    TIM_ICInitStructure.TIM_ICFilter    = 0x00;                         
	/* 初始化输入捕捉 */
    GPTIMx_ICInit(GPTIMx, &TIM_ICInitStructure);  
}

//xtlf的32768Hz时钟作为参考源
//本函数仅适用于APB不分频的情况
//ClkMode 1 = 8M
//ClkMode 2 = 16M
//ClkMode 3 = 24M
void RCHF_Adj_Proc(GPTIM_Type* GPTIMx, uint8_t ClkMode)   
{
    volatile uint16_t Temp16;
    uint32_t capture[2];
    uint8_t n, m, tempbyte, TrimBuf;
    float DIVclkmode = 1.0;
    
    //FDETO	停振检测模块输出
	//1：XTLF未停振
	//0：XTLF停振
    if (RESET == RCC_FDET_ISR_HFDETO_Chk())
    {
        //使用测试参数		
		RCC_Init_RCHF_Trim(ClkMode);
		return;
    }
    
    switch(ClkMode)
	{
		case 1://8
			RCHF_Adj_GPTimCfg(GPTIMx, 1);//计数源1分频
			DIVclkmode		= 1.0;
			break;
		
		case 2://16/2
			RCHF_Adj_GPTimCfg(GPTIMx, 2);//计数源2分频
			DIVclkmode		= 1.0;
			break;
		
		case 3://24/4
			RCHF_Adj_GPTimCfg(GPTIMx, 4);//计数源4分频
			DIVclkmode		= 8.0/6.0;
			break;
		
		default://8
			RCHF_Adj_GPTimCfg(GPTIMx, 1);//计数源不分频
			DIVclkmode		= 1.0;
			break;	
	}	
    
    for (m = 0; m < 6; m++)
    {
        GPTIMx_CR1_CEN_Setable(GPTIMx, ENABLE);
        for (n = 0; n < 2; n++)
        {
            Temp16 = 0;
            Do_DelayStart();
            {
                if (SET == GPTIMx_ISR_CC1IF_Chk(GPTIMx))
                {
                    Temp16 = 1;
                    break;
                }
            }While_DelayMsEnd(7.5 * clkmode);
        }
        if (Temp16 == 0)
        {
            continue;
        }
        capture[0] = GPTIMx_CCR1_Read(GPTIMx);
        
        for (n = 0; n < 2; n++)
        {
            Temp16 = 0;
            Do_DelayStart();
            {
                if (SET == GPTIMx_ISR_CC1IF_Chk(GPTIMx))
                {
                    Temp16 = 1;
                    break;
                }
            }While_DelayMsEnd(7.5 * clkmode);
        }
        if (Temp16 == 0)
        {
            continue;
        }
        capture[1] = GPTIMx_CCR1_Read(GPTIMx);
        
        GPTIMx_CR1_CEN_Setable(GPTIMx, DISABLE);
        
        // 1952 = (1/(32768/8))/(1/8 000 000)
        // 7 = 1952 * (30KHz/8MHz) (0.385%的精度)
        // 9.76 = (40KHz/8MHz) * 1952
        Temp16 = (65536 + capture[1] - capture[0]) % 65536;
        if ((Temp16 > ((1952 - 7) / DIVclkmode)) &&
            (Temp16 < ((1952 + 7) / DIVclkmode)))
		{
			break;
		}
		else
		{
			TrimBuf = RCC_RCHF_TR_Read();	//读取RCHF校准值
			if (Temp16 > (1952 / DIVclkmode))
			{
				Temp16 = (uint16_t)(Temp16 - 1952 / DIVclkmode);
				tempbyte = (uint8_t)((float)Temp16 / (9.76 / DIVclkmode) + 0.5);
				
				if ( tempbyte > 0x20)
                {
                    tempbyte = 0x20;
				}
                
				if (TrimBuf >= tempbyte)
				{
					RCC_RCHF_TR_Write(TrimBuf - tempbyte); // 更新RCHF校准值
				}
				else
				{
					RCC_RCHF_TR_Write(0x00); // 更新RCHF校准值
				}			
			}
			else
			{
				Temp16 = (uint16_t)(1952 / DIVclkmode - Temp16);
				tempbyte =(uint8_t)( (float)Temp16 / (9.76 / DIVclkmode) + 0.5);
				
				if (tempbyte > 0x20)
                {
                    tempbyte = 0x20;
                }
				
				if ((TrimBuf + tempbyte) <= 0x7F)
				{
					RCC_RCHF_TR_Write(TrimBuf + tempbyte);//更新RCHF校准值
				}
				else
				{
					RCC_RCHF_TR_Write(0x7F);//更新RCHF校准值
				}
			}
			
			if (m == 5)	//未找到理想值,采用最后2次的值取平均
			{
				TrimBuf += RCC_RCHF_TR_Read();
				RCC_RCHF_TR_Write((uint32_t)(TrimBuf / 2.0 + 0.5));				
			}
		}
    }
}
void Init_System(void)
{		
	/*基础系统配置*/
  __disable_irq();			//关闭全局中断使能
  //IWDT_Init();				//系统看门狗设置 （函数需要完善）
  //IWDT_Clr();  				//清系统看门狗	
	Init_SysTick();				//cpu滴答定时器配置(软件延时用)	
	TicksDelayMs( 10, NULL );	//软件延时,系统上电后不要立刻将时钟切换为非RCHF8M，也不要立刻进休眠否则可能导致无法下载程序
	
	Init_SysClk_Gen();			//系统时钟配置
	RCC_Init_RCHF_Trim(clkmode);//RCHF振荡器校准值载入(芯片复位后自动载入8M的校准值)
	
	/*外设初始化配置*/
	Init_Pad_Io();				//IO口输出寄存器初始状态配置
	Close_AllIO_GPIO_64pin();   //关闭全部IO
	
   /*RTC数值调整寄存器*/
  RTC_ADJUST_Write(0);//RTC时钟温度补偿值写0，假如不操作调整寄存器，补偿值会是一个随机数，RTC时钟可能会偏差非常大
  
	/*用户初始化代码*/
	Init_IO();
	
	/*准备进入主循环*/
	TicksDelayMs( 100, NULL );	//软件延时
	
	LED0_Flash(5);				//软件延时，闪灯五次
	
	__enable_irq();				//打开全局中断使能
}
