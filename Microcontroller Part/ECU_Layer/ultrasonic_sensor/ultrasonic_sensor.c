/*
 * ultrasonic_sensor.c
 *
 *  Created on: Jun 18, 2023
 *      Author: DABOUR
 */
#include "../../ECU_Layer/ultrasonic_sensor/ultrasonic_sensor.h"
#include "../../RTE_Layer/Inc/rte_time.h"

TIM_HandleTypeDef ul_tim;
volatile uint8_t Distance  = 0;

static void ultrasonic_sensor_timer_init(void);
static void ultrasonic_sensor_gpio_init(void);
static void ultrasonic_TIM_Base_MspInit(TIM_HandleTypeDef* tim_baseHandle);

void delay(uint32_t time);

void ultrasonic_sensor_init(void)
{
#if DISTANCE_FROM_MCU==0
	ultrasonic_sensor_timer_init();
	ultrasonic_sensor_gpio_init();
	HAL_TIM_IC_Start_IT(&ul_tim, ULTRASONIC_TIMER_CHANNEL);
	ul_tim.IC_CaptureCallback = ultrasonic_sensor_ic_handler;
#endif
}

static void ultrasonic_sensor_timer_init(void)
{
	/* USER CODE BEGIN TIM4_Init 0 */

	  /* USER CODE END TIM4_Init 0 */

	  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
	  TIM_MasterConfigTypeDef sMasterConfig = {0};
	  TIM_IC_InitTypeDef sConfigIC = {0};

	  /* USER CODE BEGIN TIM4_Init 1 */

	  /* USER CODE END TIM4_Init 1 */
	  ul_tim.Instance = TIM4;
	  ul_tim.Init.Prescaler = 84-1;
	  ul_tim.Init.CounterMode = TIM_COUNTERMODE_UP;
	  ul_tim.Init.Period = 0xffff-1;
	  ul_tim.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	  ul_tim.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	  if (HAL_TIM_Base_Init(&ul_tim) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	  if (HAL_TIM_ConfigClockSource(&ul_tim, &sClockSourceConfig) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  if (HAL_TIM_IC_Init(&ul_tim) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	  if (HAL_TIMEx_MasterConfigSynchronization(&ul_tim, &sMasterConfig) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  sConfigIC.ICPolarity = TIM_INPUTCHANNELPOLARITY_RISING;
	  sConfigIC.ICSelection = TIM_ICSELECTION_DIRECTTI;
	  sConfigIC.ICPrescaler = TIM_ICPSC_DIV1;
	  sConfigIC.ICFilter = 0xF;
	  if (HAL_TIM_IC_ConfigChannel(&ul_tim, &sConfigIC, TIM_CHANNEL_1) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  /* USER CODE BEGIN TIM4_Init 2 */
	  ultrasonic_TIM_Base_MspInit(&ul_tim);
	  /* USER CODE END TIM4_Init 2 */

}

void ultrasonic_TIM_Base_MspInit(TIM_HandleTypeDef* tim_baseHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(tim_baseHandle->Instance==TIM4)
  {
  /* USER CODE BEGIN TIM4_MspInit 0 */

  /* USER CODE END TIM4_MspInit 0 */
    /* TIM4 clock enable */
    __HAL_RCC_TIM4_CLK_ENABLE();

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**TIM4 GPIO Configuration
    PB6     ------> TIM4_CH1
    */
    GPIO_InitStruct.Pin = GPIO_PIN_6;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF2_TIM4;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* TIM4 interrupt Init */
    HAL_NVIC_SetPriority(TIM4_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(TIM4_IRQn);
  /* USER CODE BEGIN TIM4_MspInit 1 */

    TIM4->ARR = 0xfffe;
    TIM4->CCMR1 = 0x1;
    TIM4->CCER = 0x3;
    TIM4->PSC = 0x53;



  /* USER CODE END TIM4_MspInit 1 */
  }
}

static void ultrasonic_sensor_gpio_init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	/* GPIO Ports Clock Enable */
	if(GPIO_TRIG_Pin_GPIO_Port == GPIOA)
	{
		__HAL_RCC_GPIOA_CLK_ENABLE();
	}
	else if(GPIO_TRIG_Pin_GPIO_Port == GPIOB)
	{
		__HAL_RCC_GPIOB_CLK_ENABLE();
	}
	else if(GPIO_TRIG_Pin_GPIO_Port == GPIOC)
	{
		__HAL_RCC_GPIOC_CLK_ENABLE();
	}
	else if(GPIO_TRIG_Pin_GPIO_Port == GPIOH)
	{
		__HAL_RCC_GPIOH_CLK_ENABLE();
	}
	else
	{

	}

	HAL_GPIO_WritePin(GPIO_TRIG_Pin_GPIO_Port, GPIO_TRIG_Pin_Pin, GPIO_PIN_RESET);

	GPIO_InitStruct.Pin = GPIO_TRIG_Pin_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIO_TRIG_Pin_GPIO_Port, &GPIO_InitStruct);


}
void delay(uint32_t time)
{
	__HAL_TIM_SET_COUNTER(&ul_tim, 0);
	while(__HAL_TIM_GET_COUNTER(&ul_tim) < time);
}

void ultrasonic_sensor_start_distance_measurment(void)
{
#if DISTANCE_FROM_MCU == 0
	  HAL_TIM_IC_Start_IT(&ul_tim, TIM_CHANNEL_1);

	HAL_GPIO_WritePin(GPIO_TRIG_Pin_GPIO_Port, GPIO_TRIG_Pin_Pin, GPIO_PIN_SET);  // pull the TRIG pin HIGH


	delay(10);  // wait for 10 us
	//first_time = 0;
	HAL_GPIO_WritePin(GPIO_TRIG_Pin_GPIO_Port, GPIO_TRIG_Pin_Pin, GPIO_PIN_RESET);  // pull the TRIG pin low
	__HAL_TIM_ENABLE_IT(&ul_tim, TIM_IT_CC1);
#endif


}


void ultrasonic_sensor_ic_handler(TIM_HandleTypeDef *ul_tim)
{
	static uint32_t IC_Val1 = 0;
	static uint32_t IC_Val2 = 0;
	static uint8_t Distance_temp[3] = {0};
	uint32_t Difference = 0;
	static uint8_t Is_First_Captured = 0;  // is the first value captured ?
	static uint8_t ultrasonic_iteration = 0;

	if (ul_tim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)  // if the interrupt source is channel1
	{
		if (Is_First_Captured==0) // if the first value is not captured
		{
			IC_Val1 = HAL_TIM_ReadCapturedValue(ul_tim, ULTRASONIC_TIMER_CHANNEL); // read the first value
			Is_First_Captured = 1;  // set the first captured as true
			// Now change the polarity to falling edge
			__HAL_TIM_SET_CAPTUREPOLARITY(ul_tim, ULTRASONIC_TIMER_CHANNEL, TIM_INPUTCHANNELPOLARITY_FALLING);
		}

		else if (Is_First_Captured==1)   // if the first is already captured
		{
			IC_Val2 = HAL_TIM_ReadCapturedValue(ul_tim, ULTRASONIC_TIMER_CHANNEL);  // read second value
			__HAL_TIM_SET_COUNTER(ul_tim, 0);  // reset the counter

			if (IC_Val2 > IC_Val1)
			{
				Difference = IC_Val2-IC_Val1;
			}

			else if (IC_Val1 > IC_Val2)
			{
				Difference = (0xffff - IC_Val1) + IC_Val2;
			}
			//Distance = Difference * .034/2;
			Distance_temp[ultrasonic_iteration] = Difference * .034/2;
			/*** sensor value validation ***/

			if(ultrasonic_iteration > 0)
			{
				if((Distance_temp[ultrasonic_iteration] - Distance_temp[ultrasonic_iteration -1]) < 6)
				{
					if(ultrasonic_iteration >= 2)
					{

						Distance = Distance_temp[2];
						ultrasonic_iteration = 0;
					}
					else
					{
						ultrasonic_iteration++;
					}
				}
				else
				{
						Distance_temp[0] = Distance_temp[ultrasonic_iteration];
						ultrasonic_iteration = 1;
				}
			}
			else
			{
				ultrasonic_iteration++;
			}

			Is_First_Captured = 0; // set it back to false

			// set polarity to rising edge
			__HAL_TIM_SET_CAPTUREPOLARITY(ul_tim, ULTRASONIC_TIMER_CHANNEL, TIM_INPUTCHANNELPOLARITY_RISING);
			__HAL_TIM_DISABLE_IT(ul_tim, TIM_IT_CC1);
		}
	}
}

