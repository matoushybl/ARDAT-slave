/*
 * usart.h
 *
 *  Created on: 4.10.2011
 *      Author: matous
 */

#ifndef USART_H_
#define USART_H_
#include <avr/io.h>
void usart_flush(){
	while ( !(UCSR0A & (1<<RXC0)) );
}
void usart_init( )
{
/*Set baud rate */
UBRR0=6;
UCSR0B = (1<<RXEN0)|(1<<TXEN0);
/* Set frame format: 8data, 2stop bit */
UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);
}

void usart_send_int(int data)
	{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) )
	;
	/* Put data into buffer, sends the data */
	UDR0 = data;
	}
int usart_receive_int(){
	int data;
	while ( !(UCSR0A & (1<<RXC0)) );
	data=UDR0;
	return data;

}



#endif /* USART_H_ */
