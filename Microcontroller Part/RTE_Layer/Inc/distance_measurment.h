/*
 * distance_measurment.h
 *
 *  Created on: Jun 18, 2023
 *      Author: DABOUR
 *       Brief: This file is provide all information about the distance sensors in the system.
 */

#ifndef DISTANCE_MEASURMENT_H_
#define DISTANCE_MEASURMENT_H_

/******************************************* FILES INCLUDE START ************************************************/
#include "../../ECU_Layer/ultrasonic_sensor/ultrasonic_sensor.h"
#include "rte_time.h"
/******************************************* FILES INCLUDE END **************************************************/

/******************************************* MACRO Definition START *********************************************/
//#define FRONT_DISTANCE  Distance
/******************************************* MACRO DEFINITION END ***********************************************/

/******************************************* External Variable Start ********************************************/
extern volatile uint8_t Distance;
/******************************************* External Variable End **********************************************/

/******************************************* Function Prototype Start *******************************************/
void distance_mesurment_front_init(void);
void distance_mesurment_front_start_measure(void);
void ultra_handler(void);
/******************************************* Function Prototype End *********************************************/

#endif /* DISTANCE_MEASURMENT_H_ */
