/*
 * dc_motor_driver.c
 *
 *  Created on: Apr 28, 2023
 *      Author: DABOUR
 */
#include "../../ECU_Layer/dc_motor_driver/dc_motor.h"


void dc_motor_driver_init(void)
{
/* Four DIO driver pins initialization */
#if (DUAL_CHANNEL == ENABLE || SELECTED_CHANNEL == MOTOR_DRIVER_CH_1)
	DC_Driver_GPIO_In_Pin_init(DC_DRIVER_IN_1_PORT, DC_DRIVER_IN_1_PIN);
	DC_Driver_GPIO_In_Pin_init(DC_DRIVER_IN_2_PORT, DC_DRIVER_IN_2_PIN);
#endif
#if (DUAL_CHANNEL == ENABLE || SELECTED_CHANNEL == MOTOR_DRIVER_CH_2)
	DC_Driver_GPIO_In_Pin_init(DC_DRIVER_IN_3_PORT, DC_DRIVER_IN_3_PIN);
	DC_Driver_GPIO_In_Pin_init(DC_DRIVER_IN_4_PORT, DC_DRIVER_IN_4_PIN);
#endif
/* End Pins initialization */

/* Two PWM Pins (EN_A, EN_B) initialization */
#if (DUAL_CHANNEL == ENABLE || SELECTED_CHANNEL == MOTOR_DRIVER_CH_1)
	dc_TIM3_Init();
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
#endif
#if (DUAL_CHANNEL == ENABLE || SELECTED_CHANNEL == MOTOR_DRIVER_CH_2)
	dc_TIM10_Init();
	HAL_TIM_PWM_Start(&htim10, TIM_CHANNEL_1);
#endif
/* End PWM initialization */
}
/*
 * speed
 * direction: the
 */
void dc_motor_driver_move(uint8_t motor_x, uint16_t motor_speed, int8_t motor_direction)
{
	if(MOTOR_ROT_REVERSE == motor_direction)
	{
		if(MOTOR_DRIVER_CH_1 == motor_x)
		{
#if (DUAL_CHANNEL == ENABLE || SELECTED_CHANNEL == MOTOR_DRIVER_CH_1)
		HAL_GPIO_WritePin(DC_DRIVER_IN_1_PORT, DC_DRIVER_IN_1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(DC_DRIVER_IN_2_PORT, DC_DRIVER_IN_2_PIN, GPIO_PIN_RESET);
		__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2, motor_speed);

#endif
		}
		else if(MOTOR_DRIVER_CH_2 == motor_x)
		{
#if (DUAL_CHANNEL == ENABLE || SELECTED_CHANNEL == MOTOR_DRIVER_CH_2)
		HAL_GPIO_WritePin(DC_DRIVER_IN_3_PORT, DC_DRIVER_IN_3_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(DC_DRIVER_IN_4_PORT, DC_DRIVER_IN_4_PIN, GPIO_PIN_RESET);
		__HAL_TIM_SET_COMPARE(&htim10,TIM_CHANNEL_1, motor_speed);
#endif
		}
		else{  }
	}
	else if(MOTOR_ROT_FORWARD == motor_direction)
	{
		if(MOTOR_DRIVER_CH_1 == motor_x)
		{
#if (DUAL_CHANNEL == ENABLE || SELECTED_CHANNEL == MOTOR_DRIVER_CH_1)
		HAL_GPIO_WritePin(DC_DRIVER_IN_1_PORT, DC_DRIVER_IN_1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(DC_DRIVER_IN_2_PORT, DC_DRIVER_IN_2_PIN, GPIO_PIN_SET);
		__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2, motor_speed);
#endif
		}
		else if(MOTOR_DRIVER_CH_2 == motor_x)
		{
#if (DUAL_CHANNEL == ENABLE || SELECTED_CHANNEL == MOTOR_DRIVER_CH_2)
		HAL_GPIO_WritePin(DC_DRIVER_IN_3_PORT, DC_DRIVER_IN_3_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(DC_DRIVER_IN_4_PORT, DC_DRIVER_IN_4_PIN, GPIO_PIN_SET);
		__HAL_TIM_SET_COMPARE(&htim10,TIM_CHANNEL_1, motor_speed);
#endif
		}
		else{  }
	}
	else{  }
}

void dc_motor_driver_stop(uint8_t motor_x)
{
	if(MOTOR_DRIVER_CH_1 == motor_x)
	{
#if (DUAL_CHANNEL == ENABLE || SELECTED_CHANNEL == MOTOR_DRIVER_CH_1)
		__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2, 0);
#endif
	}
	else if(MOTOR_DRIVER_CH_2 == motor_x)
	{
#if (DUAL_CHANNEL == ENABLE || SELECTED_CHANNEL == MOTOR_DRIVER_CH_2)
		__HAL_TIM_SET_COMPARE(&htim10,TIM_CHANNEL_1, 0);
#endif
	}
	else{   }
}

void dc_motor_driver_continue(uint8_t motor_x, uint16_t motor_speed)
{
	if(MOTOR_DRIVER_CH_1 == motor_x)
	{
#if (DUAL_CHANNEL == ENABLE || SELECTED_CHANNEL == MOTOR_DRIVER_CH_1)
		__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2, motor_speed);
#endif
	}
	else if(MOTOR_DRIVER_CH_2 == motor_x)
	{
#if (DUAL_CHANNEL == ENABLE || SELECTED_CHANNEL == MOTOR_DRIVER_CH_2)
		__HAL_TIM_SET_COMPARE(&htim10,TIM_CHANNEL_1, motor_speed);
#endif
	}
	else{   }
}




/*
void dc_motor_driver_move(uint8_t motor_x, uint16_t motor_speed, uint8_t motor_direction)
{

}*/
