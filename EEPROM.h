/*
 * EEPROM.h
 *
 *  Created on: 31 Mar 2020
 *      Author: Khaled
 */

#ifndef EEPROM_H_
#define EEPROM_H_
#include<avr/io.h>
# define WAIT_UNTIL_EEPROM_READY()		while(EECR & (1<<EEWE))


unsigned char EEPROM_Read_Byte(unsigned short address);
void EEPROM_Write_Byte(unsigned short address,unsigned char data);


#endif /* EEPROM_H_ */
