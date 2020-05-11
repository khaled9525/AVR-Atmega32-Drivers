/*
 * motor.c
 *
 *  Created on: 19 Apr 2020
 *      Author: Khaled
 */
#include<avr/io.h>
#include"pwm.h"

void Motor_Init()
{
DDRB|=(1<<PB1)|(1<<PB2)|(1<<PB3);
PWM_Init();
}

void Motor_Anti_Clock_Direction(unsigned char dutycucle)
{
	PWM_Start(125);
	PORTB=(1<<PB1);
}
void Motor_Clockwise_Direction(unsigned char dutycucle)
{
	PWM_Start(125);

	PORTB=(1<<PB2);
}

void Motor_Stop()
{

PORTB&=~((1<<PB1)|(1<<PB2)|(1<<PB3));
}

