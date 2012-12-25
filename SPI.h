/*
 * SPI.h
 *
 *  Created on: 23.12.2012
 *      Author: matous
 */

#ifndef SPI_H_
#define SPI_H_
void SPI_init(){
	DDRB=(1<<PB4);
	SPCR=(1<<SPE);

}
int SPI_read(){
	while(!(SPSR&(1<<SPIF)));
	return SPDR;
}
void SPI_write(int data){
	SPDR=data;
	while(!(SPSR&(1<<SPIF)));

}


#endif /* SPI_H_ */
