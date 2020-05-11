/*
 * Timer0.h
 *
 *  Created on: 29 Dec 2018
 *      Author: Khaled
 */

#ifndef TIMER0_H_
#define TIMER0_H_

void Timer0_Init(void);

void Timer0_Start(void);

void Timer0_Stop(void);

void Timer0_Clear(void);

unsigned char Timer0_Read(void);

#endif /* TIMER0_H_ */
