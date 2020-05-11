/*
 * uart.c
 *
 *  Created on: 31 Jan 2019
 *      Author: Khaled
 */
#include<avr/io.h>
#include"uart.h"

void UART_Init(long BaudRate)
{
	UCSRB=(1<<RXEN)|(1<<TXEN);//Enable RX,TXU
	UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0); //8 bitsdata size
	UBRRL=(unsigned char)(((F_CPU)/(16*BaudRate))-1);//Set Baudrate

}

void UART_Send_Byte(char Data)
{

	while(!(UCSRA&(1<<UDRE))); //wait until UDR ready to receive
	UDR=Data;

}
char UART_Recieve_Byte(void)
{
	while((UCSRA & (1<<RXC)) ==0);

	return UDR;
}




void UART_Send_String(char*ptr)
{
	int i=0;
	while(ptr[i]!='\0')
	{
		UART_Send_Byte(ptr[i]);
		i++;

	}
	UART_Send_Byte(ptr[i]);//send NULL Char
}

void UART_Recieve_String(char*ptr)
{
	int i=0;
	ptr[i]=UART_Recieve_Byte();

	while(ptr[i]!='\0')
	{

		i++;
		ptr[i]=UART_Recieve_Byte();


	}
	ptr[i]='\0';
}



