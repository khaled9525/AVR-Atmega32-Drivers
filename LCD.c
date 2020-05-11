
/*
 * lcd.c
 *
 *  Created on: 10 Jan 2019
 *      Author: Khaled
 */
#include<avr/io.h>
#include<util/delay.h>
#include"lcd.h"

void LCD_Init(void)
{

	LCD_CONTROL_Direction_PINS|=(1<<RS)|(1<<E);

#if Bit_Mode == Four_Bit_Mode
	LCD_DATA_Direction_PINS=0xF0;
	LCD_Send_Command(Return_Cursor_To_Beginning);
	LCD_Send_Command(_4BITS_2LINES);
	_delay_ms(2);




#elif Bit_Mode == Eight_Bit_Mode
	LCD_DATA_Direction_PINS=0xFF;
	LCD_Send_Command(_8BITS_2LINES);
	_delay_ms(2);

	LCD_Send_Command(Return_Cursor_To_Beginning);

#endif
	LCD_Send_Command(Clear_Display);
	_delay_ms(2);


	LCD_Send_Command(Display_ON_Cursor_Off);
	_delay_ms(2);

}

void LCD_Send_Command(unsigned char Command)
{
#if Bit_Mode == Eight_Bit_Mode
	LCD_CONTROL_PINS&=~(1<<RS);  //Command Mode
	_delay_us(1);
	LCD_CONTROL_PINS|=(1<<E);   //Set Enable
	_delay_us(1);
	LCD_DATA_PINS=Command;
	LCD_CONTROL_PINS&=~(1<<E);
	_delay_us(40);
#elif Bit_Mode==Four_Bit_Mode
	LCD_CONTROL_PINS&=~(1<<RS);  //Command Mode
	_delay_us(1);
	LCD_CONTROL_PINS|=(1<<E);   //Set Enable
	_delay_us(1);
	LCD_DATA_PINS=(Command&0xF0);  //Because it's 4 bytes
	LCD_CONTROL_PINS&=~(1<<E);
	//_delay_ms(1);
	_delay_us(40);
	LCD_CONTROL_PINS&=~(1<<RS);  //Command Mode
	_delay_us(1);
	LCD_CONTROL_PINS|=(1<<E);   //Set Enable
	_delay_us(1);
	LCD_DATA_PINS=((Command<<4)&0xF0);  //Because it's 4 bytes
	LCD_CONTROL_PINS&=~(1<<E);
	_delay_us(40);
#endif
}
void LCD_Send_Char(char Character)
{

#if Bit_Mode == Four_Bit_Mode
	LCD_CONTROL_PINS|=(1<<RS);   //Data Mode
	LCD_CONTROL_PINS|=(1<<E);   //Set Enable
	_delay_ms(1);


	//_delay_ms(1);
	LCD_DATA_PINS=(Character& 0xF0);
	//_delay_ms(1);
	LCD_CONTROL_PINS&=~(1<<E);
	_delay_ms(1);


	LCD_CONTROL_PINS|=(1<<RS);   //Data Mode
	LCD_CONTROL_PINS|=(1<<E);   //Set Enable
	_delay_ms(1);
	LCD_DATA_PINS=((Character<<4)&0xF0);
	LCD_CONTROL_PINS&=~(1<<E);
	_delay_ms(1);


#elif Bit_Mode == Eight_Bit_Mode
	LCD_CONTROL_PINS|=(1<<RS);   //Data Mode
	LCD_CONTROL_PINS|=(1<<E);   //Set Enable
	_delay_ms(1);
	LCD_DATA_PINS=(Character);
	LCD_CONTROL_PINS&=~(1<<E);
	_delay_ms(1);
#endif
}

void LCD_Send_String( char *String)
{
	LCD_CONTROL_PINS|=(1<<RS);   //Data Mode
	int i;
	for(i=0;String[i]!='\0';i++)
	{
		_delay_us(1);
		LCD_CONTROL_PINS|=(1<<E);   //Set Enable
		_delay_us(1);
		LCD_Send_Char(String[i]);
		LCD_CONTROL_PINS&=~(1<<E);
		_delay_us(1);
	}

}

void LCD_GoTO_Row_Column(char Row,char Column)
{
	unsigned char address=0;


	switch (Row)
	{
	case 0:address =(Column);break;   //First Row
	case 1:address =(Column+0x40);break; // Second Row
	case 2:address =(Column+0x10);break;// Third Row in case of 4*16 LCd
	case 3:address =(Column+0x50);break;//Fourth Row in case of 4*16 LCD
	}
	LCD_Send_Command(address|(Set_Cursor_Position));  //Set cursor in the position

}

void LCD_Send_String_Row_Column(char Row,char Column,char *String)
{

	LCD_GoTO_Row_Column(Row,Column);
	LCD_Send_String(String);


}
/*
 * This Function used to convert int"greater than 9" to ASCII
 * because LCD print only Ascii
 *
 * itoa(integer,String,10);
 *integer:you want to display
 *String:Array that will integer saved in after converting
 * 10: is The base "We enter decimal no"
 *To print this no. use "send_String "Function
 * */
void LCD_IntToString(int integer,char *String)
{

	itoa(integer,String,10);



}
/*       SET CUSTOM CHARACTER    */
/* To Display any Custom char use "Send_Char(location of custom character on CGRAM)"   */
/* FOR EXAMPLE: LCD_Set_Custom_Char(0, Character1);  /* Build Character1 at position 0 */
///*MAKE YOUR CHARACTER	unsigned char Character2[8] = { 0x04, 0x1F, 0x11, 0x11, 0x1F, 0x1F, 0x1F, 0x1F };*/
/*Make sure you must choose column and row before display a special char*/
void LCD_Set_Custom_Char(unsigned char Location , unsigned char * Custom_Character)
{
	unsigned char ArrayIndex =0;
	/* the Add offset must be 0 to 7*/
	if (Location < 8)
	{
		LCD_Send_Command(0x40 + (Location * 8));// Set location on CGRAM we have only 8 locations
		for (ArrayIndex = 0; ArrayIndex < 8; ArrayIndex++)
		{
			LCD_Send_Char(Custom_Character[ArrayIndex]);
		}
	}
	else
	{

	}
}
void LCD_Rotate_String_Right(char*string,char ROW)
{
	int i;
	LCD_Send_String(string);
	for(i=0;i<16;i++)
	{
		LCD_Send_Command(Shift_Display_Right);
		_delay_ms(100);
		if(i==15&& ROW==0)
		{
			i=0;
			LCD_Send_Command(Return_Cursor_To_Beginning);
		}
		else if(i==15&&ROW==1)
		{

			i=0;
			LCD_Send_Command(0xC0);//Force curser to start from row 2
		}
	}
}
void LCD_Rotate_String_Left(char*string,char ROW)
{
	int i;
	int COL=16;    //End of LCD
	LCD_Send_String_Row_Column(ROW,COL,string);
	for(i=0;i<16;i++)
	{
		LCD_Send_Command(Shift_Diplay_left);
		_delay_ms(100);
		if(i==15&& ROW==0)
		{
			i=0;
			LCD_Send_Command(Return_Cursor_To_Beginning);
		}
		else if(i==15&&ROW==1)
		{

			i=0;
			LCD_Send_Command(0xC0);//Force cursor to start from row 2
		}
	}


}
void LCD_Clear(void)
{
	LCD_Send_Command(Clear_Display)	;
	_delay_ms(1);
}

