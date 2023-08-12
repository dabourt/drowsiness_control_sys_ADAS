/*
 * dc_motor_driver_gpio.c
 *
 *  Created on: Apr 28, 2023
 *      Author: DABOUR
 */
#include "../../ECU_Layer/dc_motor_driver/dc_gpio.h"


void DC_Driver_GPIO_In_Pin_init(GPIO_TypeDef * DC_DRIVER_IN_x_PORT , uint16_t DC_DRIVER_IN_x_PIN)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	/* GPIO Ports Clock Enable */
	if(DC_DRIVER_IN_x_PORT == GPIOA)
	{
		__HAL_RCC_GPIOA_CLK_ENABLE();
	}
	else if(DC_DRIVER_IN_x_PORT == GPIOB)
	{
		__HAL_RCC_GPIOB_CLK_ENABLE();
	}
	else if(DC_DRIVER_IN_x_PORT == GPIOC)
	{
		__HAL_RCC_GPIOC_CLK_ENABLE();
	}
	else if(DC_DRIVER_IN_x_PORT == GPIOH)
	{
		__HAL_RCC_GPIOH_CLK_ENABLE();
	}
	else
	{

	}

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(DC_DRIVER_IN_x_PORT, DC_DRIVER_IN_x_PIN, GPIO_PIN_RESET);

	/*Configure GPIO pins : PA3 PA4 */
	GPIO_InitStruct.Pin = DC_DRIVER_IN_x_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(DC_DRIVER_IN_x_PORT, &GPIO_InitStruct);
}


