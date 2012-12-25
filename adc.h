void initADC(){
	ADMUX|=(1<<REFS0);
	ADCSRA|=(1<<ADEN)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
}
int readADC(int channel){
	int result=0;
	ADMUX=(1<<REFS0)|(channel&0b00000111);
	ADCSRA|=(1<<ADSC);
	while(!(ADCSRA&(1<<ADIF)));
	ADCSRA|=(1<<ADIF);
	ADMUX=0;
	result=ADCW;
	return result;

}
