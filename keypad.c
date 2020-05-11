/*
 * keypad.c
 *
 *  Created on: 17 Jan 2019
 *      Author: Khaled
 */

#include<avr/io.h>
#include"keypad.h"
#include<util/delay.h>

void Keypad_4x3_init(void)
{


	DDRD=0xFF;      // Make Columns as o/p
	PORTD|=(1<<PD5)|(1<<PD6)|(1<<PD7);    // Make Columns high

	DDRA&=~((1<<PA0)|(1<<PA1)|(1<<PA2)|(1<<PA3));      //make Rows as I/p
	PORTA|=(1<<PA0)|(1<<PA1)|(1<<PA2)|(1<<PA3);// active internal pull up resistor "pin initially active"


}
void Keypad_4x4_init(void)
{


	DDRD=0xFF;      // Make Columns as o/p
	PORTD=0xFF;    // Make Columns high

	DDRC=0x00;      //make Rows as I/p
	PORTC|=(1<<PC0)|(1<<PC1)|(1<<PC2)|(1<<PC3);// active internal pull up resistor "pin initially active"


}
/*In this case Keypad is 3x3*/
/*
 * keypad style
 *   c1 c2 c3
 * r0 1 2  3
 * r1 4 5  6
 * r2 7 8  9
 */
unsigned char Keypad_getPressedKey(void)
{
	int keypressed=0;


	_delay_ms(5);    //delay
	/*Checking first column*/
	PORTD&=~(1<<PD5);
	PORTD|=(1<<PD6);
	PORTD|=(1<<PD7);
	_delay_ms(5);
	if(!(PINA&(1<<PA0)))
	{
		keypressed='1';

	}
	else if(!(PINA&(1<<PA1)))
	{

		keypressed='4';
	}

	else if(!(PINA&(1<<PA2)))
	{

		keypressed='7';

	}

	else if(!(PINA&(1<<PA3)))
	{

		keypressed='*';

	}

	/*Checking second column*/


	_delay_ms(5);
	PORTD|=(1<<PB5);
	PORTD&=~(1<<PB6);
	PORTD|=(1<<PB7);
	_delay_ms(5);
	if(!(PINA&(1<<PA0)))
	{
		keypressed='2';

	}
	else if(!(PINA&(1<<PA1)))
	{

		keypressed='5';
	}

	else if(!(PINA&(1<<PA2)))
	{

		keypressed='8';

	}
	else if(!(PINA&(1<<PA3)))
	{

		keypressed='0';

	}


	/*Checking Third column*/



	_delay_ms(5);
	PORTD|=(1<<PB5);
	PORTD|=(1<<PB6);
	PORTD&=~(1<<PB7);
	_delay_ms(5);
	if(!(PINA&(1<<PA0)))
	{
		keypressed='3';

	}
	else if(!(PINA&(1<<PA1)))
	{

		keypressed='6';
	}

	else if(!(PINA&(1<<PA2)))
	{

		keypressed='9';

	}
	else if(!(PINA&(1<<PA3)))
	{

		keypressed='#';

	}


	return keypressed;



}
