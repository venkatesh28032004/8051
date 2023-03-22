#include <reg51.h>

sbit motor = P2^0;
sbit rd = P2^2 ;
sbit wr = P2^3 ;
sbit intr = P2^4 ;

sfr adc = 0x90 ; // port 1

void delay(unsigned int time){
	unsigned int i;
	for(i=0;i<time;i++);
}
void main(void){
	while(1){
		rd = 1 ;
		wr = 0; // start conversion
		delay(100);
		wr = 1;
		while(intr==1); // if zero conversion is completed
										// until conversion is finished
		rd = 0; // adc to micro controller read
//	hex2ascii(adc*2);	// let the adc value be 'ff'
		intr = 1; // for next conversion
		
		if(adc < 10){
			motor = 1;
			delay(1000);
			motor = 0;
			delay(10000);
		}
		else if(adc <30){
			motor = 1;
			delay(1000);
			motor = 0;
			delay(1000);
		}
		else if(adc <40){
			motor = 1;
			delay(1000);
			motor = 0;
			delay(50);
		}
		
	}
}