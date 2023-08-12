/*
 * rc_driver.c
 *
 *  Created on: May 7, 2023
 *      Author: DABOUR
 */

#include "rc_driver.h"

#define CAR_DESIRED_DISTANCE       8U
#define CAR_NON_DESIRED_DISTANCE   0U


//uint8_t car_distance_limition = CAR_NON_DESIRED_DISTANCE;


void car_driving(void)
{
	 //distance_mesurment_front_start_measure();
	 if((Distance < CAR_DESIRED_DISTANCE) && (robot_car_wheels_dir == WHEELS_FORWARD))
	 {
		robot_car_speed = 0;
		robot_car_apply_control();
		usr_con_update_flag = USR_UPDATE_DATA_RESET;
	 }

	 if(usr_con_update_flag == USR_UPDATE_DATA_SET)
	 {
		robot_car_apply_control();
		usr_con_update_flag = USR_UPDATE_DATA_RESET;
	 }
	 else
	 {

	 }
}


void robot_car_apply_control(void)
{
	if(((robot_car_wheels_dir == WHEELS_REVERSE) || (robot_car_wheels_dir == WHEELS_FORWARD)) && (robot_car_speed <= 100))
	{
		if((Distance < CAR_DESIRED_DISTANCE) && (robot_car_wheels_dir == WHEELS_FORWARD))
		{
			robot_car_speed = 0;
		}
		if(robot_car_speed == 0)  // STOP
		{
			dc_motor_driver_stop(MOTOR_DRIVER_CH_1);
			dc_motor_driver_stop(MOTOR_DRIVER_CH_2);
			//dc_motor_driver_continue(MOTOR_DRIVER_CH_1, robot_car_speed);
			//dc_motor_driver_continue(MOTOR_DRIVER_CH_2, robot_car_speed);
		}
		else if((robot_car_steering >= 0) && (robot_car_steering <= robot_car_speed)) // Moving right
		{
			dc_motor_driver_move(MOTOR_DRIVER_CH_2, robot_car_speed, robot_car_wheels_dir);
			dc_motor_driver_move(MOTOR_DRIVER_CH_1, robot_car_speed - robot_car_steering, robot_car_wheels_dir);
		}
		else if((robot_car_steering < 0) && ((0U - robot_car_steering) <= robot_car_speed)) //Moving left
		{
			dc_motor_driver_move(MOTOR_DRIVER_CH_2, robot_car_speed + robot_car_steering, robot_car_wheels_dir);
			dc_motor_driver_move(MOTOR_DRIVER_CH_1, robot_car_speed, robot_car_wheels_dir);
		}
		else
		{

		}
	}
	else
	{

	}
}
