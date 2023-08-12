/*
 * wheel_speed.c
 *
 *  Created on: Jul 5, 2023
 *      Author: DABOUR
 */
#include "../Inc/wheel_speed.h"

void Wheel_Speed_init(void)
{
	Optical_Encoder_Init();
	Optical_Encoder_Read_data_IT();
}


int16_t Wheel_Speed_Read(uint8_t wheel)
{
	int16_t ret;
	if(wheel > 1 && wheel < 0)
	{
		ret = WHEEL_ERROR;
	}
	else
	{
		if(wheel == WHEEL_LEFT)
		{
			ret = (int16_t)opt_enc_motor_1_speed;
		}
		else if(wheel == WHEEL_RIGHT)
		{
			ret = (int16_t)opt_enc_motor_2_speed;
		}
		else
		{     }
	}
	return ret;
}

