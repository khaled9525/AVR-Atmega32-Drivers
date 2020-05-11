/*
 * uart.h
 *
 *  Created on: 31 Jan 2019
 *      Author: Khaled
 */

#ifndef UART_H_
#define UART_H_
void UART_Init(long BaudRate);
void UART_Send_Byte(char Data);
void UART_Send_String(char*ptr);
char UART_Recieve_Byte(void);
void UART_Recieve_String(char*ptr);
#endif /* UART_H_ */
