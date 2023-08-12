#include "../Inc/rte_layer.h"


uint8_t uart_car_buf[10];


void RTE_uart_init(void)
{
	MX_USART1_UART_Init();
	HAL_UART_Receive_DMA(&huart1, uart_car_buf, 10);
	huart1.RxCpltCallback = rte_uart_handler;
}

//extern DMA_HandleTypeDef hdma;
void RTE_Layer_Init(void)
{
	RTE_DMA_Init();

	clock_init();

	RTE_uart_init();

	dc_motor_driver_init();

	//ultrasonic_sensor_init();

	Wheel_Speed_init();
}

void rte_uart_handler()
{
	RTE_StatusTypeDef cheack_ret;

	if(uart_car_buf[0] != '\0')
 	{
		cheack_ret = usr_car_com(&huart1);

		if(cheack_ret != RTE_OK)
		{
			cheack_ret = usr_drossiness_com();
			ultra_handler();
		}
		if(cheack_ret != RTE_OK)
		{
			//ultra_handler();
		}
	}
	memset(uart_car_buf, '\0', 10);
}
