/*
 * wheel_speed.h
 *
 *  Created on: Jul 5, 2023
 *      Author: DABOUR
 */

#ifndef WHEEL_SPEED_H_
#define WHEEL_SPEED_H_

#include "../../ECU_Layer/optical_encoder/optical_encoder.h"

#define WHEEL_ERROR -1
#define WHEEL_STOP  0u
#define WHEEL_LEFT  0u
#define WHEEL_RIGHT 1u


extern uint16_t opt_enc_motor_1_speed;
extern uint16_t opt_enc_motor_2_speed;

void Wheel_Speed_init(void);
int16_t Wheel_Speed_Read(uint8_t wheel);

#endif /* INC_WHEEL_SPEED_H_ */
