/*
 * ultrasonic_sensor.h
 *
 *  Created on: Jun 18, 2023
 *      Author: DABOUR
 *       Brief: Source code for ultrasonic-sensor (HC-SR04) driver to measure the distance.
 *
 * module modification : Select you wanted timer (make sure the selected timer and selected
 * 						 support Input Capture Mode)
 * 						 You need to enable the timer peripheral clk and his input pin from
 * 						 ultrasonic_sensor_timer_init() function.
 */

#ifndef ULTRASONIC_SENSOR_ULTRASONIC_SENSOR_H_
#define ULTRASONIC_SENSOR_ULTRASONIC_SENSOR_H_

/******************************************* FILES INCLUDE START ************************************************/
#include "stm32f4xx_hal.h"
#include "../../Core/Inc/main.h"
/******************************************* FILES INCLUDE END **************************************************/


/******************************************* MACRO Definition START *********************************************/
#define DISTANCE_FROM_MCU              1

#define ULTRASONIC_TIMER               TIM4
#define ULTRASONIC_TIMER_CHANNEL       TIM_CHANNEL_1

#define GPIO_TRIG_Pin_Pin              GPIO_PIN_5
#define GPIO_TRIG_Pin_GPIO_Port        GPIOB
#define ICT4_CH1__ECHO_Pin_Pin     	   GPIO_PIN_6
#define ICT4_CH1__ECHO_Pin_GPIO_Port   GPIOB
/******************************************* MACRO DEFINITION END ***********************************************/

/******************************************* Function Prototype Start *******************************************/
/* ultrasonic_sensor_init
 * Brief: function to initialize ultrasonic-sensor hc-sr04 by init the timer in input capture mode.
 */
void ultrasonic_sensor_init(void);

/* ultrasonic_sensor_start_distance_measurment
 * Brief: function to start the timer in input capture mode and send high to trig-pin for 10us in ultrasonic-sensor.
 */
void ultrasonic_sensor_start_distance_measurment(void);

/* ultrasonic_sensor_ic_handler
 * Brief: function called if input capture interrupt is fired to calculate the distance using ultrasonic-sensor.
 * 		  by calculate the time between two input capture.
 */
void ultrasonic_sensor_ic_handler(TIM_HandleTypeDef *ul_tim);
/******************************************* Function Prototype End *********************************************/


#endif /* ULTRASONIC_SENSOR_ULTRASONIC_SENSOR_H_ */
