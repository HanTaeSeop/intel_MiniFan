


#ifndef UART0_H_
#define UART0_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void UART0_init();
void UART0_ISR_Process();
void UART0_Transmit( unsigned char data ); // 송신, ref) data sheet 177p
unsigned char UART0_Receive( void ); // 수신, ref) data sheet 180p
void UART0_sendString(char *str);


uint8_t UART0_Avail();

void UART0_clearRxFlag();
void UART0_setRxFlag();
uint8_t UART0_getRxFlag();
uint8_t * UART0_readRxBuff();


#define QUEUE_SIZE 10
#define QUEUE_LENGTH 80




//void UART0_exe();

#endif /* UART0_H_ */