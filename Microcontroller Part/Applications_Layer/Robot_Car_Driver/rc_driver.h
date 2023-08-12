/*
 * rc_car.h
 *
 *  Created on: May 7, 2023
 *      Author: DABOUR
 *       Brief: Application to control the car movement.
 */

#ifndef ROBOT_CAR_DRIVER_RC_DRIVER_H_
#define ROBOT_CAR_DRIVER_RC_DRIVER_H_
/******************************************* FILES INCLUDE START ************************************************/
#include "../../ECU_Layer/dc_motor_driver/dc_motor.h"
#include "../../RTE_Layer/Inc/usr_car_interface.h"
#include "../../RTE_Layer/Inc/distance_measurment.h"
/******************************************* FILES INCLUDE END **************************************************/

/******************************************* MACRO Definition START *********************************************/
#define CAR_DESIRED_DISTANCE       8U
#define CAR_NON_DESIRED_DISTANCE   0U
/******************************************* MACRO DEFINITION END ***********************************************/

/******************************************* External Variable Start ********************************************/
extern uint8_t robot_car_speed;
extern int8_t robot_car_steering;
extern uint8_t robot_car_wheels_dir;
extern uint8_t usr_con_update_flag;
/******************************************* External Variable End **********************************************/

/******************************************* Function Prototype Start *******************************************/
void car_driving(void);
void robot_car_apply_control(void);
/******************************************* Function Prototype End *********************************************/

#endif /* ROBOT_CAR_DRIVER_RC_DRIVER_H_ */
