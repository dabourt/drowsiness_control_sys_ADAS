#include "../Inc/usr_car_interface.h"


uint8_t robot_car_speed = 0;
int8_t robot_car_steering = 0;
uint8_t robot_car_wheels_dir = WHEELS_FORWARD;

uint8_t usr_drowsiness_level = DROWSINESS_LEVEL_ZERO;

uint8_t usr_con_update_flag  = USR_UPDATE_DATA_RESET;
uint8_t usr_drow_update_flag = USR_UPDATE_DATA_RESET;



RTE_StatusTypeDef usr_car_com(UART_HandleTypeDef * huart1)
{
	RTE_StatusTypeDef ret_val = RTE_NOT_OK;

	if(uart_car_buf[0] == 'K' && uart_car_buf[1] == 'S' && uart_car_buf[4] == ' ' && uart_car_buf[8] == ' ')
	{
		robot_car_speed = ((uart_car_buf[2]-48)*10) + (uart_car_buf[3]-48);

		robot_car_steering = ((uart_car_buf[6]-48)*10) + (uart_car_buf[7]-48);
		if(uart_car_buf[5] == '-')
		{
			robot_car_steering *= -1;
		}
		else
		{

		}

		robot_car_wheels_dir = (uart_car_buf[9]-48);
		usr_con_update_flag = USR_UPDATE_DATA_SET;
		ret_val = RTE_OK;
	}

	return ret_val;
}


//KDRO LEV 0
RTE_StatusTypeDef usr_drossiness_com(void)
{
	RTE_StatusTypeDef ret_val = RTE_NOT_OK;
	static uint8_t Drowsniess_Counter = 0;

	if(uart_car_buf[0] == 'K' && uart_car_buf[1] == 'D' && uart_car_buf[2] == 'R' && uart_car_buf[3] == 'O')
	{
		if(uart_car_buf[9] >= '0' && uart_car_buf[9] <= '2')
		{
			usr_drowsiness_level = uart_car_buf[9] - 48;
			if(usr_drowsiness_level == 1)
			{
				Drowsniess_Counter++;
			}
			else
			{
				Drowsniess_Counter = 0;
			}
			if(Drowsniess_Counter == 5)
			{
				usr_drowsiness_level = 2;
			}
		}
		usr_drow_update_flag = USR_UPDATE_DATA_SET;
		ret_val = RTE_OK;
	}
	return ret_val;
}
