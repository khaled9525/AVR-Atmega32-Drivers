/*
 * keypad.h
 *
 *  Created on: 17 Jan 2019
 *      Author: Khaled
 */
#include<avr/io.h>
#ifndef KEYPAD_H_
#define KEYPAD_H_

#define Rows    4
#define Columns 4

#define R0    PA0
#define R1    PA1
#define R2    PA2
#define R3    PA3


#define C0    PD0
#define C1    PD1
#define C2    PD2
#define C3    PD3



/*Functions prototypes*/
unsigned char Keypad_getPressedKey(void);
void Keypad_4x3_init(void);
void Keypad_4x4_init(void);


#endif /* KEYPAD_H_ */
