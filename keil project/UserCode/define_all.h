#ifndef	__DEFINEALL_H__
#define __DEFINEALL_H__

//���峣��, ����

//ϵͳʱ��Ĭ��ʹ��RCHF
#define RCHFCLKCFG	8	//8, 16, 24MHz

//define_all.h��RCHFCLKCFG����ϵͳʱ��
#if( RCHFCLKCFG == 8 )//8.0MHz
#define clkmode   1
#define SYSCLKdef RCC_RCHF_CR_FSEL_8MHZ//RCHF����Ƶ��8MHz
#elif( RCHFCLKCFG == 16 )//16.0MHz
#define clkmode   2
#define SYSCLKdef RCC_RCHF_CR_FSEL_16MHZ//RCHF����Ƶ��16MHz
#elif( RCHFCLKCFG == 24 )//24.0MHz
#define clkmode   3
#define SYSCLKdef RCC_RCHF_CR_FSEL_24MHZ//RCHF����Ƶ��24MHz
#endif

/*�������Ͷ���*/
typedef union
{
  unsigned char B08;
  struct
  {
    unsigned char bit0:1;
    unsigned char bit1:1;
    unsigned char bit2:1;
    unsigned char bit3:1;
    unsigned char bit4:1;
    unsigned char bit5:1;
    unsigned char bit6:1;
    unsigned char bit7:1;
  }Bit;
}B08_Bit;
#define	uint08 uint8_t
#define	uint16 uint16_t
#define uint32 uint32_t
#define	int08 int8_t		
#define	int16 int16_t
#define	int32 int32_t

/*����IO�궨��*/
#define LED0_GPIO		GPIOC
#define LED0_PIN		GPIO_Pin_0

#define KEY1_GPIO		GPIOA
#define KEY1_PIN		GPIO_Pin_10

#define KEY2_GPIO		GPIOB
#define KEY2_PIN		GPIO_Pin_12

#define KEY3_GPIO		GPIOD
#define KEY3_PIN		GPIO_Pin_11

#define KEY4_GPIO		GPIOC
#define KEY4_PIN		GPIO_Pin_6

/*�����궨��*/
#define LED0_ON			GPIO_ResetBits(LED0_GPIO, LED0_PIN)
#define LED0_OFF		GPIO_SetBits(LED0_GPIO, LED0_PIN)
#define LED0_TOG		GPIO_ToggleBits(LED0_GPIO, LED0_PIN)

/*����IO�궨��*/
#define LED1_GPIO		GPIOC
#define LED1_PIN		GPIO_Pin_1

/*�����궨��*/
#define LED1_ON			GPIO_ResetBits(LED1_GPIO, LED1_PIN)
#define LED1_OFF		GPIO_SetBits(LED1_GPIO, LED1_PIN)
#define LED1_TOG		GPIO_ToggleBits(LED1_GPIO, LED1_PIN)

#define KEY4_P 			(SET == GPIO_ReadInputDataBit(KEY4_GPIO, KEY4_PIN))
#define KEY4_N 			(RESET == GPIO_ReadInputDataBit(KEY4_GPIO, KEY4_PIN))

#define EA_OFF	((__get_PRIMASK()&0x00000001) == 0x00000001)
#define EA_ON	((__get_PRIMASK()&0x00000001) == 0x00000000)


/* GPIO���ú��������궨�� */
//IO��������� 
//type 0 = ��ͨ 
//type 1 = ����
#define IN_NORMAL	0
#define IN_PULLUP	1

//IO��������� 
//type 0 = ��ͨ 
//type 1 = OD
#define OUT_PUSHPULL	0
#define OUT_OPENDRAIN	1

//IO�������⹦�ܿ� 
//type 0 = ��ͨ 
//type 1 = OD (OD���ܽ��������⹦��֧��)
//type 2 = ��ͨ+���� 
//type 3 = OD+����
#define ALTFUN_NORMAL			0
#define ALTFUN_OPENDRAIN		1
#define ALTFUN_PULLUP			2
#define ALTFUN_OPENDRAIN_PULLUP	3


/*include*/
#include "FM33L0XX.h"
#include "fm33l0xx_include_all.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "bintohex.h"
#include "user_init.h"

#endif



