#include <avr/io.h>
#include "usart.h"
#include "servo.h"
#include "SPI.h"
#include "adc.h"
#define readBit(a,b) a&(1<<b)>0
#define sPORTB 1
#define sPORTC 2
#define sPORTD 3
#define sDDRB 4
#define sDDRC 5
#define sDDRD 6
#define sPINB 7
#define sPINC 8
#define sPIND 9
#define HIGH 1
#define LOW 0
void setup(void){
	usart_init();
	servo_init();
	initADC();
	SPI_init();
	DDRB=(1<<PB1);
	OCR1A=SERVO_CENTER;
	OCR1B=SERVO_CENTER;
}
int main (void){
	setup();
	for(;;){
		int com=SPI_read();
		switch(com){
			case 1:
				OCR1A=SPI_read();
				break;
			case 2:
				SPI_write(readADC(SPI_read())/1024*256);
				break;
			case 3:
				switch(SPI_read()){
					case sPORTB:
						PORTB|=(1<<SPI_read());
						break;
					case sPORTC:
						PORTC|=(1<<SPI_read());
						break;
					case sPORTD:
						PORTD|=(1<<SPI_read());
						break;
					case sDDRB:
						DDRB|=(1<<SPI_read());
						break;
					case sDDRC:
						DDRC|=(1<<SPI_read());
						break;
					case sDDRD:
						DDRD|=(1<<SPI_read());
						break;
				}
				break;
			case 4:
				switch(SPI_read()){
					case sPINB:
						SPI_write(readBit(PINB,SPI_read()));
						break;
					case sPINC:
						SPI_write(readBit(PINC,SPI_read()));
						break;
					case sPIND:
						SPI_write(readBit(PIND,SPI_read()));
						break;
				}
				break;
		}
		
	}
}
