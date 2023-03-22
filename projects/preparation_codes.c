#include <reg51.h>
void lcd_cmd(unsigned char a);	//
void lcd_data(unsigned char b);	//
void lcd_print(unsigned char *str);	//
void delay(unsigned int value);	//
void init(void);	//
void hexTOascii(unsigned int adc);
// LCD control pins
sbit rs = P2^0;
sbit en = P2^1;
sfr lcd = 0xb0; // port 3

// ADC control pins
sbit rd = P2^2;
sbit wr = P2^3;
sbit intr = P2^4;
sfr adc = 0x90; // port 1

int main(void){
	init();
	lcd_print(" hello world");
	delay(50000);
	init();
	while(1){
		lcd_cmd(0x80);
		lcd_print(" ADC value:     ");
		rd = 1;
		wr = 0 ;
		delay(100);
		wr = 1;
		while(intr ==1 );
		rd = 0;
		lcd_cmd(0x8b);
		hexTOascii(adc*2);
		intr = 1;
		delay(10000);
	}
}
void delay(unsigned int value){
	unsigned int i;
	for(i=0;i<value;i++);
}
void lcd_cmd(unsigned char a){
	rs = 0;
	lcd = a;
	en = 1;
	delay(100);
	en = 0;	
}
void lcd_data(unsigned char b){
	rs = 1;
	lcd = b;
	en = 1;
	delay(100);
	en = 0;	
}
// lcd_print("hello");
void lcd_print(unsigned char *str){
	while(*str){
		lcd_data(*str++);
	}
}
void init(void){
	lcd_cmd(0x38);	// 2 lines and 5 x 7 matrix	( 8 - bit mode )
	lcd_cmd(0x0c);	// display on, cursor off
	lcd_cmd(0x01);	// clear display
	lcd_cmd(0x80);	// forces cursor to beginning of 1st line
}
void hexTOascii(unsigned int adc){	// 00ff - 255
	unsigned int x3,x2,x1,x;
	x=adc/10;	// x=25
	x3=adc%10;	// x3=5
	x2=x%10;	// x2=5
	x1=x/10;	// x1=2
	lcd_data(x1+48);
	lcd_data(x2+48);
	lcd_data(x3+48);
}