/*
 * servo.h
 *
 *  Created on: 8.10.2011
 *      Author: matous
 */

#ifndef SERVO_H_
#include <util/delay.h>
#include "SPI.h"
#define SERVO_H_
#define SERVO_CENTER 22
#define SERVO_MAX 39
#define SERVO_MIN 7
void servo_init(){

	TCNT1= 0;
	ICR1= 311;
	TCCR1A = (1<<COM1A1) | (1<<COM1B1)| (1<<WGM11);
	TCCR1B = (1<<WGM13)  | (1<<WGM12)| (1<<CS11) | (1<<CS10) ;
}
void servo_set_pos(){
	int serv=SPI_read();
	int pos=SPI_read();
	if(serv==1){
		OCR1A=pos;
	}else{
		OCR1B=pos;
	}

}
void servo_test(){
	OCR1A=1;
				OCR1B=1;
				_delay_ms(1000);
				OCR1A=20;
				OCR1B=20;
				_delay_ms(1000);
				OCR1A=38;
				OCR1B=38;
				_delay_ms(1000);
				OCR1A=23;
				OCR1B=23;
				_delay_ms(1000);
}


#endif /* SERVO_H_ */
