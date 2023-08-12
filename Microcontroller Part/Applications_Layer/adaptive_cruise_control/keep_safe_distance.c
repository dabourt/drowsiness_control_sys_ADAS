/*
 * keep_safe_distance.c
 *
 *  Created on: Jun 26, 2023
 *      Author: DABOUR
 */


#include "../adaptive_cruise_control/keep_safe_distance.h"

extern uint8_t robot_car_speed;
extern clock_po_t car_clock;
extern uint8_t usr_drowsiness_level;
extern volatile uint8_t Distance;

#define ACC_LIMIT_SPEED 90

uint8_t acc_down_flag = 0;
void Adaptive_Cruise_Control(void)
{
	uint8_t sec_time = 0;
	if(usr_drowsiness_level == DROWSINESS_LEVEL_ONE)
	{
		if(car_clock.sec - sec_time > 0)
		{
			sec_time = car_clock.sec;
			if(acc_down_check() == ACC_DOWN)
			{
				acc_down_flag ++;
				if(robot_car_speed <= 70)
				{
					robot_car_speed = 0;
				}
				else
				{
					robot_car_speed -= 4;
				}
				robot_car_apply_control();
			}
			else if(((acc_up_check() == ACC_UP) && (robot_car_speed <= ACC_LIMIT_SPEED)) || (Distance >= 50))
			{
				if(acc_down_flag)
				{
					acc_down_flag--;
					if(robot_car_speed < 70)
					{
						robot_car_speed = 70;
					}
					else
					{
						robot_car_speed += 4;
					}
					if(robot_car_speed >= 99)
					{
						robot_car_speed = 0;
					}
					robot_car_apply_control();
				}
			}
			else
			{

			}
		}
		else
		{

		}
	}
	else
	{
		acc_down_flag = 0;
	}
}



uint8_t acc_down_check(void)
{
	uint8_t ret_val = NOT_READY;
	static uint8_t first_distance = 0;
	uint8_t second_distance = 0;
	static uint8_t first_read_flag = 0;
	int8_t distance_dif = 0;

	if((Distance <= 50))
	{
		if(first_read_flag == 0)
		{
			first_distance = Distance;
			first_read_flag = 1;
		}
		else
		{
			second_distance = Distance;
			first_read_flag = 0;

			distance_dif = first_distance - second_distance;

			if(distance_dif >= 3)
			{
				ret_val = ACC_DOWN;
			}
			else
			{
				ret_val = NOT_ACC_DOWN;
			}

		}
	}
	else
	{
		first_distance = 0;
		ret_val = NOT_ACC_DOWN;
	}
	return ret_val;
}

uint8_t acc_up_check(void)
{
	uint8_t ret_val = NOT_READY;
	static uint8_t first_distance = 0;
	uint8_t second_distance = 0;
	static uint8_t first_read_flag = 0;
	int8_t distance_dif = 0;

	if(Distance >= 20 )
	{
		if(first_read_flag == 0)
		{
			first_distance = Distance;
			first_read_flag = 1;
		}
		else
		{
			second_distance = Distance;
			first_read_flag = 0;

			distance_dif = second_distance - first_distance;

			if(distance_dif >= 3)
			{
				ret_val = ACC_UP;
			}
			else
			{
				ret_val = NOT_ACC_UP;
			}

		}
	}
	else
	{
		first_distance = 0;
		ret_val = NOT_ACC_UP;
	}
	return ret_val;
}

