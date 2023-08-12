/*
 * rte_time.h
 *
 *  Created on: Jul 2, 2023
 *      Author: DABOUR
 *       Brief: Serve the time in the system from the power on
 */

#ifndef RTE_TIME_H_
#define RTE_TIME_H_

/******************************************* FILES INCLUDE START ************************************************/
#include "stm32f4xx_hal.h"
/******************************************* FILES INCLUDE END **************************************************/

/******************************************* MACRO Definition START *********************************************/
#define clock_get_micro_sec() (((uint32_t)(SysTick->VAL)) / 84)
/******************************************* MACRO DEFINITION END ***********************************************/

/******************************************* Data Type Start ****************************************************/
typedef struct
{
	uint16_t milli_sec;
	uint8_t sec;
	uint8_t min;
	uint8_t hour;
}clock_po_t;
/******************************************* Data Type End ******************************************************/

/******************************************* Function Prototype Start *******************************************/
void clock_init(void);
void clock_micro_sec_handler(void);
/******************************************* Function Prototype End *********************************************/

#endif /* RTE_TIME_H_ */
