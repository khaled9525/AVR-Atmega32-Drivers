/*
  * LCD.h
 *
 *  Created on: 14 Jan 2019
 *      Author: Khaled
 */
#ifndef LCD_H_
#define LCD_H_
#include<avr/io.h>
#include <stdlib.h>

/* LCD PINS */
#define Bit_Mode  4// Set bit mode for LCD
#define D0 PB0
#define D1 PB1
#define D2 PB2
#define D3 PB3
#define D4 PB4
#define D5 PB5
#define D6 PB6
#define D7 PB7
#define RS PC6
#define E  PC7

#define LCD_DATA_PINS PORTB
#define LCD_DATA_Direction_PINS DDRB

#define LCD_CONTROL_PINS PORTC
#define LCD_CONTROL_Direction_PINS DDRC

/*LCD COMMANDS */
#define Four_Bit_Mode (4)
#define Eight_Bit_Mode (8)
#define _8BITS_2LINES (0x38)
#define _4BITS_2LINES (0x28)
#define Entry_Mode (0x06)
#define Display_Off_Cursor_OFF (0x08)
#define Display_ON_Cursor_ON (0x0E)
#define Display_ON_Cursor_Off (0x0C)
#define Display_ON_Cursor_Blinking (0x0F)
#define Shift_Diplay_left (0x18)
#define Shift_Display_Right (0x1C)
#define Move_Cursor_Left_By_One (0x10)
#define Move_Cursor_Right_By_One (0x14)
#define Clear_Display (0x01)
#define Set_Cursor_Position (0x80)
#define Return_Cursor_To_Beginning (0x02)

/*LCD Functions*/

void LCD_Init(void);
void LCD_Send_Command(unsigned char Command);
void LCD_Send_Char(char Character);
void LCD_Send_String( char *String);
void LCD_GoTO_Row_Column(char Row,char Column);
void LCD_Send_String_Row_Column(char Row,char Column,char *String);
void LCD_IntToString(int integer,char *String);
void LCD_Set_Custom_Char(unsigned char Location ,unsigned char * Pattern);
void LCD_Rotate_String_Right(char*string,char ROW);
void LCD_Rotate_String_Left(char*string,char ROW);
void LCD_Clear(void);

#endif /* LCD_H_ */
