#include "define_all.h"  

//cpu�δ�ʱ������(�����ʱ��)
void Init_SysTick(void)
{
    SysTick_Config(0x1000000UL);
    SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |//�ر��ж�
                    //SysTick_CTRL_TICKINT_Msk |
                    SysTick_CTRL_ENABLE_Msk;
}
//���������ʱǰ����������SysTick
void TicksDelay(uint32_t ClkNum)
{
    uint32_t last = SysTick->VAL;
    
    ClkNum = ClkNum*clkmode;//��Ӧ��ͬ��Ƶ��8Mʱ���ʱ2ms��32Mʱ���ʱ0.5ms
    if(ClkNum>0xF00000)
    {
        ClkNum = 0xF00000;
    }
    while(((last - SysTick->VAL)&0xFFFFFFUL ) < ClkNum);
}
//ms�����ʱ
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
//us�����ʱ
void TicksDelayUs(uint32_t us)
{
    uint32_t ClkNum;
    
    if(us>100000)//������100ms
    {
        us = 100000;
    }
    ClkNum = us*(__SYSTEM_CLOCK/1000000) ;
    TicksDelay(ClkNum);
}

//У��Ĵ���
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

//��ѯNVIC�Ĵ�����Ӧ�������ж��Ƿ��
//1 ��
//0 �ر�
unsigned char CheckNvicIrqEn( IRQn_Type IRQn )
{
	if( 0 == ( NVIC->ISER[0U] & ((uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL)))) )
		return 0;
	else
		return 1;
}

//IOģ�⹦������:LCD/ADC
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

//IO��������� 
//type 0 = ��ͨ 
//type 1 = ����
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

//IO��������� 
//type 0 = ��ͨ 
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
//IO�������⹦�ܿ� 
//type 0 = ��ͨ 
//type 1 = OD (OD���ܽ��������⹦��֧��)
//type 2 = ��ͨ+���� 
//type 3 = OD+����
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

//IO�رգ�od����ߣ�
//������ʹ����Чʱ������ⲿ�źŸ��գ�Ҳ���ܵ���FM385�ܽ�©�磻
//���Խ�FCR����Ϊ01��GPIO�������ODEN����Ϊ1����α��©������ر�����ʹ�ܣ��������������Ϊ1
//ע��SWD�ӿڵ�PG8,9�������ı����ǵ����ý��޷�����
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

//IO�ڳ�ʼ���״̬����
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



//�ر�64��оƬ��ʹ�õ�ȫ��IO(SWD�ڳ��⣬�رպ��ܷ���)
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

//Ĭ�Ͽ����󲿷�����ʱ�ӣ��û��ɰ�����رղ���Ҫ��ʱ��
//ʱ�ӿ����رնԹ���Ӱ�첻��
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
    
	PLL_InitStruct.PLLDB = 31;	//pll��Ƶ�� = PLLDB + 1
  PLL_InitStruct.REFPRSC= RCC_PLL_CR_REFPRSC_DIV8; //ʱ��Դ8��Ƶ
	PLL_InitStruct.PLLINSEL = RCC_PLL_CR_INSEL_RCHF;	//PLLʱ��Դѡ��RCHF
	PLL_InitStruct.PLLOSEL = RCC_PLL_CR_OSEL_MUL1;	//Ĭ��ѡ��1�����
	PLL_InitStruct.PLLEN = DISABLE;	//Ĭ�Ϲر�PLL
	
	RCC_PLL_Init(&PLL_InitStruct);
	RCC_PLL_CR_EN_Setable(DISABLE);//�ر�PLL
}

//ϵͳʱ������
//ʹ��RCHF����ʱ��,define_all.h ��SYSCLKdef�����ϵͳʱ��Ƶ��
void Init_SysClk(void)
{
	RCC_RCHF_InitTypeDef RCHF_InitStruct;
	RCC_SYSCLK_InitTypeDef SYSCLK_InitStruct;
	
	RCHF_InitStruct.FSEL = SYSCLKdef;//define_all.h ��SYSCLKdef�����ϵͳʱ��Ƶ��
	RCHF_InitStruct.RCHFEN = ENABLE;//��RCHF
	
	RCC_RCHF_Init(&RCHF_InitStruct);
	
	SYSCLK_InitStruct.SYSCLKSEL = RCC_SYSCLK_CR_SYSCLKSEL_RCHF;	//ѡ��RCHF����ʱ��
	SYSCLK_InitStruct.STCLKSEL =  RCC_SYSCLK_CR_STCLKSEL_SCLK; //SCLK���ں�systick����ʱ��ѡ��
	SYSCLK_InitStruct.AHBPRES =  RCC_SYSCLK_CR_AHBPRES_DIV1;		//AHB����Ƶ
	SYSCLK_InitStruct.APBPRES =  RCC_SYSCLK_CR_APBPRES_DIV1;		//APB����Ƶ
	SYSCLK_InitStruct.SLP_ENEXTI = ENABLE;//����ģʽʹ���ⲿ�жϲ���
	SYSCLK_InitStruct.LSCATS = ENABLE;//LSCLK�Զ��л�ʹ��	
	
	RCC_SysClk_Init(&SYSCLK_InitStruct);
}

//Mode:0 ����ģʽ�����п��Ź����������ж�ʱ��
//Mode:1 ����ģʽ�رտ��Ź����������ж�ʱ��
void DBG_Init(uint08 Mode)
{
	if(Mode == 1)//debug
	{
		DBG_CR_IWDT_STOP_Setable(ENABLE);//����ģʽ�¹ر�IWDT
		DBG_CR_WWDT_STOP_Setable(ENABLE);//����ģʽ�¹ر�WWDT
	}
	else//release
	{
		DBG_CR_IWDT_STOP_Setable(DISABLE);//����ģʽ������IWDT
		DBG_CR_WWDT_STOP_Setable(DISABLE);//����ģʽ������WWDT
	}
	
	DBG_CR_BT_STOP_Setable(DISABLE);//����ģʽ������BSTIM
	DBG_CR_GT0_STOP_Setable(DISABLE);//����ģʽ������GPTIM0
	DBG_CR_GT1_STOP_Setable(DISABLE);//����ģʽ������GPTIM1
	DBG_CR_AT_STOP_Setable(DISABLE);//����ģʽ������ATIM
}

void Init_SysClk_Gen( void )				//ʱ��ѡ�����
{	
	/*PLL����*/
	Init_PLL();	//Ĭ�Ϲر�PLL
	
	/*ϵͳʱ������*/
	Init_SysClk();	//Ĭ��ʹ��RCHF����ʱ��
	
	/*����ʱ��ʹ������*/	
	Init_RCC_PERIPH_clk();	//Ĭ�Ͽ����󲿷�����ʱ��
	
	/*DMA����RAM���ȼ�����*/
	RCC_AHBM_CR_MPRIL_Set(0);	//Ĭ��AHB Master���ȼ�����DMA����
	
	/*�µ縴λ����*/
	//pdr��bor�����µ縴λ����Ҫ��һ��
	//����Դ��ѹ�����µ縴λ��ѹʱ��оƬ�ᱻ��λס		
	//pdr��ѹ��λ��׼���ǹ��ļ��ͣ������޷�������
	//bor��ѹ��λ׼ȷ������Ҫ���ӹ���

  RCC_PDR_CR_EN_Setable(ENABLE);//��PDR 
  RCC_BOR_CR_OFF_BOR_Setable(DISABLE);//��BOR

	
	/*������ƼĴ�������*/
	#ifdef __DEBUG
	DBG_Init(1);//����ʱ���ж�ʱ��,�رտ��Ź�
	#else
	DBG_Init(0);
	#endif
}

void IWDT_Init(void)
{
   	RCC_PERCLK_SetableEx(IWDTCLK, ENABLE);		//IWDT����ʱ��ʹ��
   	IWDT_Clr();									//��IWDT
	  IWDT_CR_CFG_Set(IWDT_CR_CFG_2S);//����IWDT�������
}

void Init_IO(void)
{
	LED0_OFF;
	LED1_OFF;
  
	OutputIO( LED0_GPIO, LED0_PIN, 0 );	 //led0
	OutputIO( LED1_GPIO, LED1_PIN, 0 );	 //led1
	OutputIO( GPIOA, GPIO_Pin_0, 0 );	 
	
	//fout ���ϵͳʱ��64��Ƶ
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
    
    GPTIMx_SMCR_SMS_Set(GPTIMx, GPTIMx_SMCR_SMS_SLAVE_DIS); //��λģʽ
    GPTIMx_SMCR_TS_Set(GPTIMx, GPTIMx_SMCR_TS_ITR2); //���봥���ź�ITR2
    
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
    
    /* ʹ�ܶ�ʱ�����ؼĴ���ARR */
    GPTIMx_CR1_ARPE_Setable(GPTIMx, ENABLE);
    
    /* ��ʱ��������������*/
    TIM_TimeBaseStructure.TIM_Period = 65535;
    /* ����Ԥ��Ƶ����Ԥ��Ƶ����Ϊ8MHz */
    TIM_TimeBaseStructure.TIM_Prescaler = psc - 1;
    /* ʱ�ӷ�Ƶ���� ��û���õ������ù� */
    TIM_TimeBaseStructure.TIM_ClockDivision = GPTIMx_CR1_CKD_1TINT;
    /* ����������ģʽ*/
    TIM_TimeBaseStructure.TIM_CounterMode = GPTIMx_CR1_DIR_UP; 
    /* ��ʼ����ʱ*/
    GPTIMx_TimeBaseInit(GPTIMx, &TIM_TimeBaseStructure);

    /* CC1S=01 	ѡ�������IC1ӳ�䵽TRC�� */
    TIM_ICInitStructure.TIM_Channel     = TIM_Channel_1;
    /* �����ز��� */
    TIM_ICInitStructure.TIM_ICPolarity  = GPTIMx_CCER_CC1P_HIGH;	
    /* ӳ�䵽TRC�� */
    TIM_ICInitStructure.TIM_ICSelection = GPTIMx_CCMR1_CC1S_TRC;  
    /* ���������Ƶ,����Ƶ  */
    TIM_ICInitStructure.TIM_ICPrescaler = GPTIMx_CCMR1_IC1PSC_DIV8;	           
    /* IC1F=0000 ���������˲��� ���˲� */
    TIM_ICInitStructure.TIM_ICFilter    = 0x00;                         
	/* ��ʼ�����벶׽ */
    GPTIMx_ICInit(GPTIMx, &TIM_ICInitStructure);  
}

//xtlf��32768Hzʱ����Ϊ�ο�Դ
//��������������APB����Ƶ�����
//ClkMode 1 = 8M
//ClkMode 2 = 16M
//ClkMode 3 = 24M
void RCHF_Adj_Proc(GPTIM_Type* GPTIMx, uint8_t ClkMode)   
{
    volatile uint16_t Temp16;
    uint32_t capture[2];
    uint8_t n, m, tempbyte, TrimBuf;
    float DIVclkmode = 1.0;
    
    //FDETO	ͣ����ģ�����
	//1��XTLFδͣ��
	//0��XTLFͣ��
    if (RESET == RCC_FDET_ISR_HFDETO_Chk())
    {
        //ʹ�ò��Բ���		
		RCC_Init_RCHF_Trim(ClkMode);
		return;
    }
    
    switch(ClkMode)
	{
		case 1://8
			RCHF_Adj_GPTimCfg(GPTIMx, 1);//����Դ1��Ƶ
			DIVclkmode		= 1.0;
			break;
		
		case 2://16/2
			RCHF_Adj_GPTimCfg(GPTIMx, 2);//����Դ2��Ƶ
			DIVclkmode		= 1.0;
			break;
		
		case 3://24/4
			RCHF_Adj_GPTimCfg(GPTIMx, 4);//����Դ4��Ƶ
			DIVclkmode		= 8.0/6.0;
			break;
		
		default://8
			RCHF_Adj_GPTimCfg(GPTIMx, 1);//����Դ����Ƶ
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
        // 7 = 1952 * (30KHz/8MHz) (0.385%�ľ���)
        // 9.76 = (40KHz/8MHz) * 1952
        Temp16 = (65536 + capture[1] - capture[0]) % 65536;
        if ((Temp16 > ((1952 - 7) / DIVclkmode)) &&
            (Temp16 < ((1952 + 7) / DIVclkmode)))
		{
			break;
		}
		else
		{
			TrimBuf = RCC_RCHF_TR_Read();	//��ȡRCHFУ׼ֵ
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
					RCC_RCHF_TR_Write(TrimBuf - tempbyte); // ����RCHFУ׼ֵ
				}
				else
				{
					RCC_RCHF_TR_Write(0x00); // ����RCHFУ׼ֵ
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
					RCC_RCHF_TR_Write(TrimBuf + tempbyte);//����RCHFУ׼ֵ
				}
				else
				{
					RCC_RCHF_TR_Write(0x7F);//����RCHFУ׼ֵ
				}
			}
			
			if (m == 5)	//δ�ҵ�����ֵ,�������2�ε�ֵȡƽ��
			{
				TrimBuf += RCC_RCHF_TR_Read();
				RCC_RCHF_TR_Write((uint32_t)(TrimBuf / 2.0 + 0.5));				
			}
		}
    }
}
void Init_System(void)
{		
	/*����ϵͳ����*/
  __disable_irq();			//�ر�ȫ���ж�ʹ��
  //IWDT_Init();				//ϵͳ���Ź����� ��������Ҫ���ƣ�
  //IWDT_Clr();  				//��ϵͳ���Ź�	
	Init_SysTick();				//cpu�δ�ʱ������(�����ʱ��)	
	TicksDelayMs( 10, NULL );	//�����ʱ,ϵͳ�ϵ��Ҫ���̽�ʱ���л�Ϊ��RCHF8M��Ҳ��Ҫ���̽����߷�����ܵ����޷����س���
	
	Init_SysClk_Gen();			//ϵͳʱ������
	RCC_Init_RCHF_Trim(clkmode);//RCHF����У׼ֵ����(оƬ��λ���Զ�����8M��У׼ֵ)
	
	/*�����ʼ������*/
	Init_Pad_Io();				//IO������Ĵ�����ʼ״̬����
	Close_AllIO_GPIO_64pin();   //�ر�ȫ��IO
	
   /*RTC��ֵ�����Ĵ���*/
  RTC_ADJUST_Write(0);//RTCʱ���¶Ȳ���ֵд0�����粻���������Ĵ���������ֵ����һ���������RTCʱ�ӿ��ܻ�ƫ��ǳ���
  
	/*�û���ʼ������*/
	Init_IO();
	
	/*׼��������ѭ��*/
	TicksDelayMs( 100, NULL );	//�����ʱ
	
	LED0_Flash(5);				//�����ʱ���������
	
	__enable_irq();				//��ȫ���ж�ʹ��
}
