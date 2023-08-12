/*
 * dc_motor_driver.h
 *
 *  Created on: Apr 28, 2023
 *      Author: DABOUR
 */

#ifndef DC_MOTOR_DRIVER_DC_MOTOR_H_
#define DC_MOTOR_DRIVER_DC_MOTOR_H_

/******************************************* FILES INCLUDE START ************************************************/
#include "../../ECU_Layer/dc_motor_driver/dc_gpio.h"
#include "../../ECU_Layer/dc_motor_driver/dc_timer.h"
/******************************************* FILES INCLUDE END **************************************************/

/******************************************* MACRO Definition START *********************************************/
#define DISABLE 		   0U
#define ENABLE 			   1U

#define MOTOR_ROT_FORWARD  0U
#define MOTOR_ROT_REVERSE  1U

#define MOTOR_DRIVER_CH_1  1U
#define MOTOR_DRIVER_CH_2  2U

#define DUAL_CHANNEL       ENABLE

#if DUAL_CHANNEL==DISABLE
#define SELECTED_CHANNEL   MOTOR_DRIVER_CH_2
#else
#define SELECTED_CHANNEL   DISABLE
#endif
/******************************************* MACRO DEFINITION END ***********************************************/

/******************************************* Function Prototype Start *******************************************/

/* dc_motor_driver_init
 * Brief: function to initialize from two channels motor driver L-298n
 */
void dc_motor_driver_init(void);

/* dc_motor_driver_move
 * Brief: function to control L-298n motor driver channel by control PWM and motor direction.
 * Parameter: motor_x -> select one channel from two motor_ch_1 or motor_ch_2
 * 		      motor_speed -> speed from 1 to 99
 * 		      motor_direction -> forward or reverse direction
 */
void dc_motor_driver_move(uint8_t motor_x, uint16_t motor_speed, int8_t motor_direction);

/* dc_motor_driver_move
 * Brief: function to Stop generate PWM in L-298n motor driver in one of two channels
 * Parameter: motor_x -> select one channel from two motor_ch_1 or motor_ch_2
 */
void dc_motor_driver_stop(uint8_t motor_x);
/******************************************* Function Prototype End *********************************************/

#endif /* DC_MOTOR_DRIVER_DC_MOTOR_H_ */
