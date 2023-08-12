/*
 * optical_encoder.h
 *
 *  Created on: Jul 5, 2023
 *      Author: DABOUR
 */

#ifndef OPTICAL_ENCODER_OPTICAL_ENCODER_H_
#define OPTICAL_ENCODER_OPTICAL_ENCODER_H_

#include "stm32f4xx_hal.h"
#include "../../Core/Inc/main.h"
#include "../../Core/Inc/stm32f4xx_it.h"

#define ENCODER_MOTOR_2_Pin 		GPIO_PIN_12
#define ENCODER_MOTOR_2_GPIO_Port   GPIOA
#define ENCODER_MOTOR_1_Pin 		GPIO_PIN_15
#define ENCODER_MOTOR_1_GPIO_Port   GPIOA


extern TIM_HandleTypeDef htim1;

extern TIM_HandleTypeDef htim2;

extern TIM_HandleTypeDef htim9;

void Optical_Encoder_Init(void);
void Optical_Encoder_Read_data_IT(void);
void Optical_Encoder_Read_data_Handler();

void Encoder_Motor1_TIM_Init(void);
void Encoder_Motor2_TIM_Init(void);
void Encoder_TIM_IT_Init(void);


#endif /* OPTICAL_ENCODER_OPTICAL_ENCODER_H_ */
