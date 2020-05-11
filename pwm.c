/*
iuyupy * pwm.c
 *
 *  Created on: 31 Dec 2018
 *      Author: Khaled
 */

#include<avr/io.h>
#include"pwm.h"


void PWM_Init(void)
{


	TCCR0=(1<<WGM01)|(1<<WGM00)|(1<<COM01)|(1<<CS01);   /* configure as fast PWM with "Non Inverting Mode" with prescaler 8*/
	DDRB|=(1<<PB3);     //Set OCR0 as o/p
	TCNT0=0; //Set timer from 0


}

void PWM_Start(unsigned char Duty_Cycle)  //Enter Duty Cycle
{

	OCR0=Duty_Cycle;


}
