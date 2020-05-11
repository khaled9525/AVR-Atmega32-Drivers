/*
 * motor.h
 *
 *  Created on: 19 Apr 2020
 *      Author: Khaled
 */

#ifndef MOTOR_H_
#define MOTOR_H_

void Motor_Init();
void Motor_Anti_Clock_Direction(unsigned char dutycucle);

void Motor_Clockwise_Direction(unsigned char dutycucle);

void Motor_Stop();

#endif /* MOTOR_H_ */
