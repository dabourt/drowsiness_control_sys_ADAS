/*
 * keep_safe_distance.h
 *
 *  Created on: Jun 26, 2023
 *      Author: DABOUR
 */

#ifndef KEEP_SAFE_DISTANCE_H_
#define KEEP_SAFE_DISTANCE_H_

#include "../../RTE_Layer/Inc/rte_layer.h"

#define IS_SAFE_DISTANCE       0U
#define IS_NOT_SAFE_DISTANCE   1U

#define ACC_DOWN				   0U
#define NOT_ACC_DOWN			   1U

#define ACC_UP				   0U
#define NOT_ACC_UP			   1U

#define NOT_READY				2U

void Adaptive_Cruise_Control(void);
uint8_t acc_down_check(void);
uint8_t acc_up_check(void);


#endif /* KEEP_SAFE_DISTANCE_H_ */
