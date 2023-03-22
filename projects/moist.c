#include <reg51.h>

void delay(unsigned int time);

sbit motor = P2^0;

sbit rd = P2^2 ;
sbit wr = P2^3 ;
sbit intr = P2^4 ;

sfr adc = 0x90 ; // port 1


void main(void){
	while(1){
		rd = 1 ;
		wr = 0; // start conversion
		delay(100);
		wr = 1;
		while(intr==1); // if zero conversion is completed
										// until conversion is finished
		rd = 0; // adc to micro controller read
		
		intr = 1; // for next conversion
		if((adc) > 400){
			motor = 1;
			delay(10000);
		}
		else {
			motor = 0;
			delay(10000);
		}
	}
	
	
}

void delay(unsigned int time){
	unsigned int i;
	for(i=0;i<time;i++);
}