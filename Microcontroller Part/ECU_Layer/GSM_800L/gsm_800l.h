/*
 * gsm_800l.h
 *
 *  Created on: Jul 7, 2023
 *      Author: DABOUR
 */
#ifndef GSM_800L_H_
#define GSM_800L_H_
#include "stm32f4xx_hal.h"

/* USER CODE END Includes */

extern UART_HandleTypeDef huart2;

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_USART2_UART_Init(void);
void _HAL_UART_MspInit(UART_HandleTypeDef* uartHandle);
/* USER CODE BEGIN Prototypes */


#endif /* GSM_800L_H_ */



