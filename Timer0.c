/*
 * Timer0.c
 *
 *  Created on: 29 Dec 2018
 *      Author: Khaled
 */

#include<avr/io.h>
#include"Timer0.h"

void Timer0_Init(void)
{
	TCCR0=(1<<FOC0)|(1<<CS02);// prescaler =256

}
void Timer0_Start(void)
{

	TCNT0=0;   //start timer

}
void Timer0_Stop(void)
{
	TCCR0=(1<<FOC0);

}
unsigned char Timer0_Read(void)
{

return TCNT0;
}
void Timer0_Clear(void)
{
	TCNT0=0;
}

