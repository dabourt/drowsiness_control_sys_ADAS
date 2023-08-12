/*
 * drowsiness_control.c
 *
 *  Created on: Jul 7, 2023
 *      Author: DABOUR
 */
#include "../../RTE_Layer/Inc/rte_layer.h"
#include "../Robot_Car_Driver/rc_driver.h"
extern uint8_t robot_car_speed;
extern int8_t robot_car_steering;
extern clock_po_t car_clock;
extern uint8_t usr_drowsiness_level;
void Drowsiness_Control(void)
{
	uint8_t first_time = 0;
	static uint8_t socend_time = 0;

	socend_time = car_clock.sec;
	robot_car_steering = 0;

	if(((socend_time - first_time) >= 1) && (usr_drowsiness_level == DROWSINESS_LEVEL_ONE))
	{
		first_time = socend_time;
		robot_car_speed -= 3;
		robot_car_apply_control();
	}
}
