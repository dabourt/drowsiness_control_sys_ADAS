/*
 * rte_time.c
 *
 *  Created on: Jul 2, 2023
 *      Author: DABOUR
 */

#include "../inc/rte_time.h"

clock_po_t car_clock;
extern void (* SysTick_int_handler)(void);

void clock_init(void)
{
	/* Configure SysTick to interrupted every 1 micro-sec  */

	SysTick->LOAD = 84000 - 1;
	SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk;
	SysTick_int_handler = clock_micro_sec_handler;
}
void clock_micro_sec_handler(void)
{
	car_clock.milli_sec++;
	if(car_clock.milli_sec == 1000)
	{
		car_clock.milli_sec = 0;
		car_clock.sec++;
		if(car_clock.sec == 60)
		{
			car_clock.sec = 0;
			car_clock.min++;
			if(car_clock.min == 60)
			{
				car_clock.min = 0;
				car_clock.hour++;
				if(car_clock.hour == 24)
				{
					car_clock.hour = 0;
				}
			}
		}
	}
}
