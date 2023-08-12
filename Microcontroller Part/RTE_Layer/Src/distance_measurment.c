/*
 * distance_measurment.c
 *
 *  Created on: Jun 18, 2023
 *      Author: DABOUR
 */
#include "../Inc/distance_measurment.h"

extern uint8_t uart_car_buf[10];

void distance_mesurment_front_init(void)
{
	ultrasonic_sensor_init();
}


void distance_mesurment_front_start_measure(void)
{
	ultrasonic_sensor_start_distance_measurment();
}

void ultra_handler (void)
{
	if(uart_car_buf[0] == 'D' && uart_car_buf[1] == 'U')
	{
		Distance = (uart_car_buf[2]-48)*100 + (uart_car_buf[3]-48)*10 + (uart_car_buf[3]-48);
	}
}
