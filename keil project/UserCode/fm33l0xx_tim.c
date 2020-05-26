/**
  ******************************************************************************
  * @file    fm33l0xx_TIM.c
  * @author  
  * @version V0.0.1
  * @date    04-NEV-2018
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of the Advanced timer (TIM):           
  *           
  ******************************************************************************  
  */ 

/* Includes ------------------------------------------------------------------*/
#include "fm33l0xx_tim.h" 

void TIM_TimeBaseInit(ATIM_Type* TIMx, TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct)
{
  uint32_t tmpcr1 = 0;

  tmpcr1 = TIMx->CR1;  

  /* Select the Counter Mode */
  tmpcr1 &= ~(TIM_CR1_DIR_Msk | TIM_CR1_CMS_Msk);
  tmpcr1 |= TIM_TimeBaseInitStruct->TIM_CounterMode;
 
  tmpcr1 &=  ~TIM_CR1_CKD_Msk;
  tmpcr1 |= TIM_TimeBaseInitStruct->TIM_ClockDivision;

  TIMx->CR1 = tmpcr1;

  /* Set the Autoreload value */
  TIMx->ARR = TIM_TimeBaseInitStruct->TIM_Period ;
 
  /* Set the Prescaler value */
  TIMx->PSC = TIM_TimeBaseInitStruct->TIM_Prescaler;    

  /* Set the Repetition Counter value */
  TIMx->RCR = TIM_TimeBaseInitStruct->TIM_RepetitionCounter;

  /* Generate an update event to reload the Prescaler 
     and the repetition counter value immediatly */
 // TIMx->EGR = TIM_EGR_UG;          
}

void TIM_OC1Init(ATIM_Type* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct)
{
  uint32_t tmpccmrx = 0, tmpccer = 0, tmpcr2 = 0;
   
 /* Disable the Channel 1: Reset the CC1E Bit */
  TIMx->CCER &= (~TIM_CCER_CC1E_ENABLE);
  /* Get the TIMx CCER register value */
  tmpccer = TIMx->CCER;
  /* Get the TIMx CR2 register value */
  tmpcr2 =  TIMx->CR2;
  
  /* Get the TIMx CCMR1 register value */
  tmpccmrx = TIMx->CCMR1;
    
  /* Reset the Output Compare Mode Bits */
  tmpccmrx &= (uint16_t)(~((uint16_t)TIM_CCMR1_OC1M_Msk));
  tmpccmrx &= (uint16_t)(~((uint16_t)TIM_CCMR1_CC1S_Msk));

  /* Select the Output Compare Mode */
  tmpccmrx |= TIM_OCInitStruct->TIM_OCMode;
  
  /* Reset the Output Polarity level */
  tmpccer &= (~TIM_CCER_CC1P_Msk);
  /* Set the Output Compare Polarity */
  tmpccer |= TIM_OCInitStruct->TIM_OCPolarity;
  
  /* Set the Output State */
  tmpccer |= TIM_OCInitStruct->TIM_OutputState;
 
  /* Reset the Output N Polarity level */
  tmpccer &= (~TIM_CCER_CC1NP_Msk);
  /* Set the Output N Polarity */
  tmpccer |= TIM_OCInitStruct->TIM_OCNPolarity;
  
  /* Reset the Output N State */
  tmpccer &= (~TIM_CCER_CC1NE_Msk);    
  /* Set the Output N State */
  tmpccer |= TIM_OCInitStruct->TIM_OutputNState;
  
  /* Reset the Output Compare and Output Compare N IDLE State */
  tmpcr2 &= (~TIM_CR2_OIS1_Msk);
  tmpcr2 &= (~TIM_CR2_OIS1N_Msk);
  
  /* Set the Output Idle state */
  tmpcr2 |= TIM_OCInitStruct->TIM_OCIdleState;
  /* Set the Output N Idle state */
  tmpcr2 |= TIM_OCInitStruct->TIM_OCNIdleState;
    
  /* Write to TIMx CR2 */
  TIMx->CR2 = tmpcr2;
  
  /* Write to TIMx CCMR1 */
  TIMx->CCMR1 = tmpccmrx;

  /* Set the Capture Compare Register value */
  TIMx->CCR1 = TIM_OCInitStruct->TIM_Pulse; 
 
  /* Write to TIMx CCER */
  TIMx->CCER = tmpccer;
}

void TIM_OC2Init(ATIM_Type* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct)
{
  uint32_t tmpccmrx = 0, tmpccer = 0, tmpcr2 = 0;
     
   /* Disable the Channel 2: Reset the CC2E Bit */
  TIMx->CCER &= (~TIM_CCER_CC2E_Msk);
  
  /* Get the TIMx CCER register value */  
  tmpccer = TIMx->CCER;
  /* Get the TIMx CR2 register value */
  tmpcr2 =  TIMx->CR2;
  
  /* Get the TIMx CCMR1 register value */
  tmpccmrx = TIMx->CCMR1;
    
  /* Reset the Output Compare mode and Capture/Compare selection Bits */
  tmpccmrx &= (~TIM_CCMR1_OC2M_Msk);
  tmpccmrx &= (~TIM_CCMR1_CC2S_Msk);
  
  /* Select the Output Compare Mode */
  tmpccmrx |= (TIM_OCInitStruct->TIM_OCMode << 8);
  
  /* Reset the Output Polarity level */
  tmpccer &= (~TIM_CCER_CC2P_Msk);
  /* Set the Output Compare Polarity */
  tmpccer |= (TIM_OCInitStruct->TIM_OCPolarity << 4);
  
  /* Set the Output State */
  tmpccer |= (TIM_OCInitStruct->TIM_OutputState << 4);
   
   /* Reset the Output N Polarity level */
  tmpccer &= (~TIM_CCER_CC2NP_Msk);
  /* Set the Output N Polarity */
  tmpccer |= (TIM_OCInitStruct->TIM_OCNPolarity << 4);
  
  /* Reset the Output N State */
  tmpccer &= (~TIM_CCER_CC2NE_Msk);    
  /* Set the Output N State */
  tmpccer |= (TIM_OCInitStruct->TIM_OutputNState << 4);
  
  /* Reset the Output Compare and Output Compare N IDLE State */
  tmpcr2 &= (~TIM_CR2_OIS2_Msk);
  tmpcr2 &= (~TIM_CR2_OIS2N_Msk);
  
  /* Set the Output Idle state */
  tmpcr2 |= (TIM_OCInitStruct->TIM_OCIdleState << 2);
  /* Set the Output N Idle state */
  tmpcr2 |= (TIM_OCInitStruct->TIM_OCNIdleState << 2);
     
  
  /* Write to TIMx CR2 */
  TIMx->CR2 = tmpcr2;
  
  /* Write to TIMx CCMR1 */
  TIMx->CCMR1 = tmpccmrx;

  /* Set the Capture Compare Register value */
  TIMx->CCR2 = TIM_OCInitStruct->TIM_Pulse;
  
  /* Write to TIMx CCER */
  TIMx->CCER = tmpccer;
}

void TIM_OC3Init(ATIM_Type* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct)
{
  uint32_t tmpccmrx = 0, tmpccer = 0, tmpcr2 = 0;

  /* Disable the Channel 2: Reset the CC2E Bit */
  TIMx->CCER &= (~TIM_CCER_CC3E_Msk);
  
  /* Get the TIMx CCER register value */
  tmpccer = TIMx->CCER;
  /* Get the TIMx CR2 register value */
  tmpcr2 =  TIMx->CR2;
  
  /* Get the TIMx CCMR2 register value */
  tmpccmrx = TIMx->CCMR2;
    
  /* Reset the Output Compare mode and Capture/Compare selection Bits */
  tmpccmrx &= (~TIM_CCMR2_OC3M_Msk);
  tmpccmrx &= (~TIM_CCMR2_CC3S_Msk);  
  /* Select the Output Compare Mode */
  tmpccmrx |= TIM_OCInitStruct->TIM_OCMode;
  
  /* Reset the Output Polarity level */
  tmpccer &= (~TIM_CCER_CC3P_Msk);
  /* Set the Output Compare Polarity */
  tmpccer |= (TIM_OCInitStruct->TIM_OCPolarity << 8);
  
  /* Set the Output State */
  tmpccer |= (TIM_OCInitStruct->TIM_OutputState << 8);
  
  /* Reset the Output N Polarity level */
  tmpccer &= (~TIM_CCER_CC3NP_Msk);
  /* Set the Output N Polarity */
  tmpccer |= (TIM_OCInitStruct->TIM_OCNPolarity << 8);
  /* Reset the Output N State */
  tmpccer &= (~TIM_CCER_CC3NE_Msk);
  
  /* Set the Output N State */
  tmpccer |= (TIM_OCInitStruct->TIM_OutputNState << 8);
  /* Reset the Output Compare and Output Compare N IDLE State */
  tmpcr2 &= (~TIM_CR2_OIS3_Msk);
  tmpcr2 &= (~TIM_CR2_OIS3N_Msk);
  /* Set the Output Idle state */
  tmpcr2 |= (TIM_OCInitStruct->TIM_OCIdleState << 4);
  /* Set the Output N Idle state */
  tmpcr2 |= (TIM_OCInitStruct->TIM_OCNIdleState << 4);
    
  /* Write to TIMx CR2 */
  TIMx->CR2 = tmpcr2;
  
  /* Write to TIMx CCMR2 */
  TIMx->CCMR2 = tmpccmrx;

  /* Set the Capture Compare Register value */
  TIMx->CCR3 = TIM_OCInitStruct->TIM_Pulse;
  
  /* Write to TIMx CCER */
  TIMx->CCER = tmpccer;
}

void TIM_OC1PreloadConfig(ATIM_Type* TIMx, uint32_t TIM_OCPreload)
{
  uint32_t tmpccmr1 = 0;

  tmpccmr1 = TIMx->CCMR1;
  /* Reset the OC1PE Bit */
  tmpccmr1 &= ~(TIM_CCMR1_OC1PE_Msk);
  /* Enable or Disable the Output Compare Preload feature */
  tmpccmr1 |= TIM_OCPreload;
  /* Write to TIMx CCMR1 register */
  TIMx->CCMR1 = tmpccmr1;
}

void TIM_OC2PreloadConfig(ATIM_Type* TIMx, uint32_t TIM_OCPreload)
{
  uint32_t tmpccmr1 = 0;

  tmpccmr1 = TIMx->CCMR1;
  /* Reset the OC2PE Bit */
  tmpccmr1 &= ~(TIM_CCMR1_OC2PE_Msk);
  /* Enable or Disable the Output Compare Preload feature */
  tmpccmr1 |= (TIM_OCPreload << 8);
  /* Write to TIMx CCMR1 register */
  TIMx->CCMR1 = tmpccmr1;
}

void TIM_OC3PreloadConfig(ATIM_Type* TIMx, uint32_t TIM_OCPreload)
{
  uint32_t tmpccmr2 = 0;
  
  tmpccmr2 = TIMx->CCMR2;
  /* Reset the OC3PE Bit */
  tmpccmr2 &= ~(TIM_CCMR2_OC3PE_Msk);
  /* Enable or Disable the Output Compare Preload feature */
  tmpccmr2 |= TIM_OCPreload;
  /* Write to TIMx CCMR2 register */
  TIMx->CCMR2 = tmpccmr2;
}

void TIM_ARRPreloadConfig(ATIM_Type* TIMx, FunState NewState)
{
  if (NewState != DISABLE)
  {
    /* Set the ARR Preload Bit */
    TIMx->CR1 |= TIM_CR1_ARPE_Msk;
  }
  else
  {
    /* Reset the ARR Preload Bit */
    TIMx->CR1 &= ~(TIM_CR1_ARPE_Msk);
  }
}

void TIM_BDTRConfig(ATIM_Type* TIMx, TIM_BDTRInitTypeDef *TIM_BDTRInitStruct)
{
  /* Set the Lock level, the Break enable Bit and the Ploarity, the OSSR State,
     the OSSI State, the dead time value and the Automatic Output Enable Bit */
  TIMx->BDTR = (uint32_t)TIM_BDTRInitStruct->TIM_OSSRState | TIM_BDTRInitStruct->TIM_OSSIState |
             TIM_BDTRInitStruct->TIM_LOCKLevel | TIM_BDTRInitStruct->TIM_DeadTime |
             TIM_BDTRInitStruct->TIM_Break | TIM_BDTRInitStruct->TIM_BreakPolarity |
             TIM_BDTRInitStruct->TIM_AutomaticOutput;
}

void TIM_Cmd(ATIM_Type* TIMx, FunState NewState)
{
  
  if (NewState != DISABLE)
  {
    /* Enable the TIM Counter */
    TIMx->CR1 |= TIM_CR1_CEN_Msk;
  }
  else
  {
    /* Disable the TIM Counter */
    TIMx->CR1 &= ~TIM_CR1_CEN_Msk;
  }
}

void TIM_CtrlPWMOutputs(ATIM_Type* TIMx, FunState NewState)
{
  if (NewState != DISABLE)
  {
    /* Enable the TIM Main Output */
    TIMx->BDTR |= TIM_BDTR_MOE_Msk;
  }
  else
  {
    /* Disable the TIM Main Output */
    TIMx->BDTR &= (~TIM_BDTR_MOE_Msk);
  }  
}


void TIM_CCxCmd(ATIM_Type* TIMx, uint32_t TIM_Channel, uint32_t TIM_CCx)
{
  uint32_t tmp = 0;

  if(TIM_Channel==TIM_Channel_1)
  {
    tmp = CCER_CCE_Set << 0;

    /* Reset the CCxE Bit */
    TIMx->CCER &= ~ tmp;

    /* Set or reset the CCxE Bit */ 
   TIMx->CCER |= (TIM_CCx << 0);
  }
  
  if(TIM_Channel==TIM_Channel_2)
  {
    tmp = CCER_CCE_Set << 4;

    /* Reset the CCxE Bit */
    TIMx->CCER &= ~ tmp;

    /* Set or reset the CCxE Bit */ 
   TIMx->CCER |= (TIM_CCx << 4);
  }
  
   if(TIM_Channel==TIM_Channel_3)
   {
      tmp = CCER_CCE_Set << 8;

      /* Reset the CCxE Bit */
      TIMx->CCER &= ~ tmp;

      /* Set or reset the CCxE Bit */ 
     TIMx->CCER |= (TIM_CCx << 8);
   }
   
   if(TIM_Channel==TIM_Channel_4)
   {
      tmp = CCER_CCE_Set << 12;

      /* Reset the CCxE Bit */
      TIMx->CCER &= ~ tmp;

      /* Set or reset the CCxE Bit */ 
     TIMx->CCER |= (TIM_CCx << 12);
   }  
}


void TIM_CCxNCmd(ATIM_Type* TIMx, uint32_t TIM_Channel, uint32_t TIM_CCxN)
{
  uint32_t tmp = 0;
 if(TIM_Channel==TIM_Channel_1)
 {
   tmp = CCER_CCNE_Set << 0;

    /* Reset the CCxNE Bit */
    TIMx->CCER &=  ~tmp;

    /* Set or reset the CCxNE Bit */ 
    TIMx->CCER |=  (TIM_CCxN << 0);
 }
 
 if(TIM_Channel==TIM_Channel_2)
 {
   tmp = CCER_CCNE_Set << 4;

    /* Reset the CCxNE Bit */
    TIMx->CCER &=  ~tmp;

    /* Set or reset the CCxNE Bit */ 
    TIMx->CCER |=  (TIM_CCxN << 4);
 }
 
 if(TIM_Channel==TIM_Channel_3)
 {
   tmp = CCER_CCNE_Set << 8;

    /* Reset the CCxNE Bit */
    TIMx->CCER &=  ~tmp;

    /* Set or reset the CCxNE Bit */ 
    TIMx->CCER |=  (TIM_CCxN << 8);
 }
}

void TIM_SetCompare2(ATIM_Type* TIMx, uint32_t Compare2)
{
  /* Set the Capture Compare2 Register value */
  TIMx->CCR2 = Compare2;
}

void TIM_SetCompare3(ATIM_Type* TIMx, uint32_t Compare3)
{
  /* Set the Capture Compare3 Register value */
  TIMx->CCR3 = Compare3;
}

void TIM_SetCompare1(ATIM_Type* TIMx, uint32_t Compare1)
{
  /* Set the Capture Compare1 Register value */
  TIMx->CCR1 = Compare1;
}


static void TI1_Config(ATIM_Type* TIMx, uint32_t TIM_ICPolarity, uint32_t TIM_ICSelection,
                       uint32_t TIM_ICFilter,uint32_t TIM_ICPrescaler)
{
  uint32_t tmpccmr1 = 0, tmpccer = 0;
  /* Disable the Channel 1: Reset the CC1E Bit */
  TIMx->CCER &= ~(TIM_CCER_CC1E_Msk);
  tmpccmr1 = TIMx->CCMR1;
  tmpccer = TIMx->CCER;
  /* Select the Input and set the filter */
  tmpccmr1 &= ((~TIM_CCMR1_CC1S_Msk) & (~TIM_CCMR1_IC1F_Msk));
  tmpccmr1 |= (TIM_ICSelection | (TIM_ICFilter << 4));
  
  /* Reset the IC1PSC Bits */
  tmpccmr1 &= ~(TIM_CCMR1_IC1PCS_Msk);
  /* Set the IC1PSC value */
  tmpccmr1 |= TIM_ICPrescaler;
 
  /* Select the Polarity and set the CC1E Bit */
  tmpccer &= ~(TIM_CCER_CC1P_Msk);
  tmpccer |= (TIM_ICPolarity | TIM_CCER_CC1E_Msk);

  /* Write to TIMx CCMR1 and CCER registers */
  TIMx->CCMR1 = tmpccmr1;
  TIMx->CCER = tmpccer;
}

static void TI2_Config(ATIM_Type* TIMx, uint32_t TIM_ICPolarity, uint32_t TIM_ICSelection,
                       uint32_t TIM_ICFilter,uint32_t TIM_ICPrescaler)
{
  uint32_t tmpccmr1 = 0, tmpccer = 0, tmp = 0;
  /* Disable the Channel 2: Reset the CC2E Bit */
  TIMx->CCER &= ~(TIM_CCER_CC2E_Msk);
  tmpccmr1 = TIMx->CCMR1;
  tmpccer = TIMx->CCER;
  tmp = (TIM_ICPolarity << 4);
  /* Select the Input and set the filter */
  tmpccmr1 &= ((~TIM_CCMR1_CC2S_Msk) & (~TIM_CCMR1_IC2F_Msk));
  tmpccmr1 |= (TIM_ICFilter << 12);
  tmpccmr1 |= (TIM_ICSelection << 8);
  
    /* Reset the IC1PSC Bits */
  tmpccmr1 &= ~(TIM_CCMR1_IC1PCS_Msk);
  /* Set the IC1PSC value */
  tmpccmr1 |= (TIM_ICPrescaler << 8);
  
  /* Select the Polarity and set the CC2E Bit */
  tmpccer &= ~(TIM_CCER_CC2P_Msk);
  tmpccer |=  (tmp | TIM_CCER_CC2E_Msk);
 
  
  /* Write to TIMx CCMR1 and CCER registers */
  TIMx->CCMR1 = tmpccmr1 ;
  TIMx->CCER = tmpccer;
}

static void TI3_Config(ATIM_Type* TIMx, uint32_t TIM_ICPolarity, uint32_t TIM_ICSelection,
                       uint32_t TIM_ICFilter,uint32_t TIM_ICPrescaler)
{
  uint32_t tmpccmr2 = 0, tmpccer = 0, tmp = 0;
  /* Disable the Channel 3: Reset the CC3E Bit */
  TIMx->CCER &= ~(TIM_CCER_CC3E_Msk);
  tmpccmr2 = TIMx->CCMR2;
  tmpccer = TIMx->CCER;
  tmp = (TIM_ICPolarity << 8);
  /* Select the Input and set the filter */
  tmpccmr2 &= ((~(TIM_CCMR2_CC3S_Msk)) & (~(TIM_CCMR2_IC3F_Msk)));
  tmpccmr2 |= (TIM_ICSelection | (TIM_ICFilter << 4));
    
  /* Reset the IC1PSC Bits */
  tmpccmr2 &= ~(TIM_CCMR1_IC1PCS_Msk);
  /* Set the IC1PSC value */
  tmpccmr2 |= TIM_ICPrescaler ;
  
  /* Select the Polarity and set the CC3E Bit */
  tmpccer &= ~(TIM_CCER_CC3P_Msk);
  tmpccer |= (tmp | TIM_CCER_CC3E_Msk);
 
  
  /* Write to TIMx CCMR2 and CCER registers */
  TIMx->CCMR2 = tmpccmr2;
  TIMx->CCER = tmpccer;
}

static void TI4_Config(ATIM_Type* TIMx, uint32_t TIM_ICPolarity, uint32_t TIM_ICSelection,
                       uint32_t TIM_ICFilter,uint32_t TIM_ICPrescaler)
{
  uint32_t tmpccmr2 = 0, tmpccer = 0, tmp = 0;

   /* Disable the Channel 4: Reset the CC4E Bit */
  TIMx->CCER &= ~(TIM_CCER_CC4E_Msk);
  tmpccmr2 = TIMx->CCMR2;
  tmpccer = TIMx->CCER;
  tmp = (TIM_ICPolarity << 12);
  /* Select the Input and set the filter */
  tmpccmr2 &= ((~TIM_CCMR2_CC4S_Msk) & (~TIM_CCMR2_IC4F_Msk));
  tmpccmr2 |= (TIM_ICSelection << 8);
  tmpccmr2 |= (TIM_ICFilter << 12);
  
  /* Reset the IC1PSC Bits */
  tmpccmr2 &= ~(TIM_CCMR1_IC1PCS_Msk);
  /* Set the IC1PSC value */
  tmpccmr2 |= (TIM_ICPrescaler << 8) ;
  
  /* Select the Polarity and set the CC4E Bit */
  tmpccer &= ~(TIM_CCER_CC4P_Msk);
  tmpccer |= (tmp | TIM_CCER_CC4E_Msk);
 
  /* Write to TIMx CCMR2 and CCER registers */
  TIMx->CCMR2 = tmpccmr2;
  TIMx->CCER = tmpccer;
}

void TIM_ICInit(ATIM_Type* TIMx, TIM_ICInitTypeDef* TIM_ICInitStruct)
{
  if (TIM_ICInitStruct->TIM_Channel == TIM_Channel_1)
  {
    /* TI1 Configuration */
    TI1_Config(TIMx, TIM_ICInitStruct->TIM_ICPolarity,
               TIM_ICInitStruct->TIM_ICSelection,
               TIM_ICInitStruct->TIM_ICFilter,
               TIM_ICInitStruct->TIM_ICPrescaler);
  }
  else if (TIM_ICInitStruct->TIM_Channel == TIM_Channel_2)
  {
    /* TI2 Configuration */
    TI2_Config(TIMx, TIM_ICInitStruct->TIM_ICPolarity,
               TIM_ICInitStruct->TIM_ICSelection,
               TIM_ICInitStruct->TIM_ICFilter,
               TIM_ICInitStruct->TIM_ICPrescaler);
  }
  else if (TIM_ICInitStruct->TIM_Channel == TIM_Channel_3)
  {
    /* TI3 Configuration */
    TI3_Config(TIMx,  TIM_ICInitStruct->TIM_ICPolarity,
               TIM_ICInitStruct->TIM_ICSelection,
               TIM_ICInitStruct->TIM_ICFilter,
               TIM_ICInitStruct->TIM_ICPrescaler);
  }
  else
  {
    /* TI4 Configuration */
    TI4_Config(TIMx, TIM_ICInitStruct->TIM_ICPolarity,
               TIM_ICInitStruct->TIM_ICSelection,
               TIM_ICInitStruct->TIM_ICFilter,
               TIM_ICInitStruct->TIM_ICPrescaler);
  }
}

void TIM_SelectHallSensor(ATIM_Type* TIMx, FunState NewState)
{
  if (NewState != DISABLE)
  {
    /* Set the TI1S Bit */
    TIMx->CR2 |= TIM_CR2_T1S_Msk;
  }
  else
  {
    /* Reset the TI1S Bit */
    TIMx->CR2 &= ~(TIM_CR2_T1S_Msk);
  }
}

void TIM_SelectInputTrigger(ATIM_Type* TIMx, uint32_t TIM_InputTriggerSource)
{
  uint32_t tmpsmcr = 0;
 
  /* Get the TIMx SMCR register value */
  tmpsmcr = TIMx->SMCR;
  /* Reset the TS Bits */
  tmpsmcr &= (~TIM_SMCR_TS_Msk);
  /* Set the Input Trigger source */
  tmpsmcr |= TIM_InputTriggerSource;
  /* Write to TIMx SMCR */
  TIMx->SMCR = tmpsmcr;
}

void TIM_SelectSlaveMode(ATIM_Type* TIMx, uint32_t TIM_SlaveMode)
{
 /* Reset the SMS Bits */
  TIMx->SMCR &= ~(TIM_SMCR_SMS_Msk);
  /* Select the Slave Mode */
  TIMx->SMCR |= TIM_SlaveMode;
}

void TIM_SelectMasterSlaveMode(ATIM_Type* TIMx, uint32_t TIM_MasterSlaveMode)
{
  /* Reset the MSM Bit */
  TIMx->SMCR &= ~(TIM_SMCR_MSM_Msk);
  
  /* Set or Reset the MSM Bit */
  TIMx->SMCR |= TIM_MasterSlaveMode;
}

void TIM_ITConfig(ATIM_Type* TIMx, uint32_t TIM_IT, FunState NewState)
{  
  if (NewState != DISABLE)
  {
    /* Enable the Interrupt sources */
    TIMx->DIER |= TIM_IT;
  }
  else
  {
    /* Disable the Interrupt sources */
    TIMx->DIER &= ~TIM_IT;
  }
}

void TIM_ClearITPendingBit(ATIM_Type* TIMx, uint32_t TIM_IT)
{
  /* Clear the IT pending Bit */
  TIMx->ISR = TIM_IT;
}

ITStatus TIM_GetITStatus(ATIM_Type* TIMx, uint32_t TIM_IT)
{
  ITStatus bitstatus = RESET;  
  uint32_t itstatus = 0x0, itenable = 0x0;
   
  itstatus = TIMx->ISR & TIM_IT;
  
  itenable = TIMx->DIER & TIM_IT;
  
  if ((itstatus != RESET) && (itenable != RESET))
  {
    bitstatus = SET;
  }
  else
  {
    bitstatus = RESET;
  }
  return bitstatus;
}
