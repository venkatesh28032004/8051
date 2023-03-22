# include <reg51.h >
void lcd_data(unsigned char b);	//
void lcd_cmd(unsigned int a);	//
void delay(unsigned int value);	//
void init(void);	//
void print(unsigned char *str);	//

void hexTOascii(unsigned char v);


// LCD control pins
sbit rs = P2^0;	// 0 - cmd , 1 - dataa
sbit en = P2^1;	// high - low
// ADC control pins
sbit read = P2^2;
sbit write = P2^3;
sbit intr = P2^4;

sfr adc = 0x90;
sfr lcd = 0xb0;

int main(void){
	init();
	print(" hello world");
	delay(10000);
	init();
	while(1){
		read = 1 ;
		write = 0;	// start conversion
		delay(50);
		write = 1;
		while(intr==1);	// while not conversion is over
		read = 0;
		lcd_cmd(0x80);
		hexTOascii(adc*2);
		intr = 1;
	}	
}
void delay(unsigned int value){
	unsigned int i;
	for(i=0;i<value;i++);
}
void lcd_cmd(unsigned char a){
	rs = 0;
	lcd = a ;
	en = 0;
	delay(5);
	en = 1;
}
void lcd_data(unsigned char b){
	rs = 1;
	lcd = b ;
	en = 0;
	delay(5);
	en = 1;
}
void init(void){
	lcd_cmd(0x38);
	lcd_cmd(0x0c);
	lcd_cmd(0x01);
	lcd_cmd(0x80);
}
void print(unsigned char *str){
	while(*str){
		lcd_data(*str++);
	}
}
void hexTOascii(unsigned char v){	// ff - 255
	unsigned int x3,x2,x1,x;
	x=v/10;	// x=25
	x3 = v %10;	// x3 = 5
	x2 = x %10;	// x2 = 5
	x1 = x / 10;	// x1 = 2
	lcd_data(x1+0x30);
	lcd_data(x2+0x30);
	lcd_data(x3+0x30);	
}