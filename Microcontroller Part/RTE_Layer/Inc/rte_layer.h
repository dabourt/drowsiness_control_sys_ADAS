/*
 * rte_init.h
 *
 *  Created on: Jun 19, 2023
 *      Author: DABOUR
 *       Brief: This file provide all information in the system such as time clock or the sensors and other services.
 *       		Prefer include this file in any software component.
 */

#ifndef RTE_INIT_H_
#define RTE_INIT_H_

/******************************************* FILES INCLUDE START ************************************************/
#include "../../ECU_Layer/ecu_layer.h"
#include "dma.h"
#include "usart.h"
#include "usr_car_interface.h"
#include "distance_measurment.h"
#include "rte_time.h"
/******************************************* FILES INCLUDE END **************************************************/

/******************************************* Function Prototype Start *******************************************/
void RTE_Layer_Init(void);
void RTE_uart_init(void);
void rte_uart_handler();
/******************************************* Function Prototype End *********************************************/

#endif /* RTE_INIT_H_ */
