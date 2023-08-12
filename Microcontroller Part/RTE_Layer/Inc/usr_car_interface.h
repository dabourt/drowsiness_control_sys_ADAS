/*
 * usr_car_interface.h
 *
 *  Created on: May 8, 2023
 *      Author: DABOUR
 *       Brief: This file serve the communication between the user and the car.
 */

#ifndef USR_CAR_INTERFACE_H_
#define USR_CAR_INTERFACE_H_

/******************************************* FILES INCLUDE START ************************************************/
#include "string.h"
#include "stm32f4xx_hal.h"
#include "../Inc/rte_std_type.h"
#include "../Inc/usart.h"
/******************************************* FILES INCLUDE END **************************************************/

/******************************************* MACRO Definition START *********************************************/
#define RIGHT_DIR                  0U
#define LEFT_DIR                   1U

#define WHEELS_FORWARD	   MOTOR_ROT_FORWARD
#define WHEELS_REVERSE     MOTOR_ROT_REVERSE

#define USR_UPDATE_DATA_RESET	   0U
#define USR_UPDATE_DATA_SET        1U

#define DROWSINESS_LEVEL_ZERO 	   0U
#define DROWSINESS_LEVEL_ONE 	   1U
#define DROWSINESS_LEVEL_TWO 	   2U
/******************************************* MACRO DEFINITION END ***********************************************/

/******************************************* External Variable Start ********************************************/
extern uint8_t uart_car_buf[10];
/******************************************* External Variable End **********************************************/

/******************************************* Function Prototype Start *******************************************/
RTE_StatusTypeDef usr_car_com(UART_HandleTypeDef * huart1);
RTE_StatusTypeDef usr_drossiness_com(void);
/******************************************* Function Prototype End *********************************************/

#endif /* USR_CAR_INTERFACE_H_ */
