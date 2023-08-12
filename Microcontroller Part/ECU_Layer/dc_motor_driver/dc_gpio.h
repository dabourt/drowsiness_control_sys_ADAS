/*
 * dc_motor_driver_gpio.h
 *
 *  Created on: Apr 28, 2023
 *      Author: DABOUR
 */

#ifndef DC_MOTOR_DRIVER_DC_GPIO_H_
#define DC_MOTOR_DRIVER_DC_GPIO_H_

#include "stm32f4xx_hal.h"

#include "../../ECU_Layer/dc_motor_driver/dc_motor.h"

#define DC_DRIVER_IN_1_PIN 			GPIO_PIN_1
#define DC_DRIVER_IN_2_PIN 			GPIO_PIN_2
#if (DUAL_CHANNEL==ENABLE)
#define DC_DRIVER_IN_3_PIN 			GPIO_PIN_5
#define DC_DRIVER_IN_4_PIN 			GPIO_PIN_6
#endif


#define DC_DRIVER_IN_1_PORT 		((GPIO_TypeDef *)GPIOB)
#define DC_DRIVER_IN_2_PORT 		((GPIO_TypeDef *)GPIOB)
#if (DUAL_CHANNEL==ENABLE)
#define DC_DRIVER_IN_3_PORT 		((GPIO_TypeDef *)GPIOA)
#define DC_DRIVER_IN_4_PORT 		((GPIO_TypeDef *)GPIOA)
#endif

void DC_Driver_GPIO_In_Pin_init(GPIO_TypeDef * DC_DRIVER_IN_x_PORT , uint16_t DC_DRIVER_IN_x_PIN);

#endif /* DC_MOTOR_DRIVER_DC_GPIO_H_ */
