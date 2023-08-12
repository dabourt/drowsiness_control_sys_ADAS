/*
 * dc_timer.h
 *
 *  Created on: Apr 28, 2023
 *      Author: DABOUR
 */
#ifndef DC_MOTOR_DRIVER_DC_TIMER_H_
#define DC_MOTOR_DRIVER_DC_TIMER_H_

/******************************************* FILES INCLUDE START ************************************************/
#include "stm32f4xx_hal.h"
#include "../../Core/Inc/main.h"
/******************************************* FILES INCLUDE END **************************************************/

/******************************************* External Variable Start ********************************************/
extern TIM_HandleTypeDef htim10;
extern TIM_HandleTypeDef htim3;
/******************************************* External Variable End **********************************************/

/******************************************* Function Prototype Start *******************************************/
void dc_TIM10_Init(void);

void dc_TIM3_Init(void);

void dc_TIM_Base_MspInit(TIM_HandleTypeDef* tim_baseHandle);
void dc_TIM_MspPostInit(TIM_HandleTypeDef* timHandle);
/******************************************* Function Prototype End *********************************************/

#endif
