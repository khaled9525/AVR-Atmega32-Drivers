/*
 * EEPROM.c
 *
 *  Created on: 31 Mar 2020
 *      Author: Khaled
 */
#include"EEPROM.h"

/*
 *
 * Addresses from 0 to 1023
 * */
unsigned char EEPROM_Read_Byte(unsigned short address)
{
	WAIT_UNTIL_EEPROM_READY();

	EEAR=address&(0x03FF);//Masking To prevent Writing on reading registers

	EECR|=(1<<EERE);    //To start Reading process
	return EEDR;//Return data

}
void EEPROM_Write_Byte(unsigned short address,unsigned char data)
{
	WAIT_UNTIL_EEPROM_READY();
	EEAR=address&(0x03FF);//To prevent Writing on reading registers
	EEDR=data;            // put data on data register
	EECR|=(1<<EEMWE);
	EECR|=(1<<EEWE);      //Writing to EEPROM

}

