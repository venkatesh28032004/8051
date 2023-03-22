#include < reg51.h >

void lcd_init(void);
void lcd_cmd( unsigned char a );
void lcd_data( unsigned char b );
void lcd_print( unsigned int value);
void delay(unsigned int i);

sbit ir1 = P2^0;
sbit ir2 = P2^1;
sbit rs = P3^0;
sbit en = P3^1;

sfr ldata = 0x90;

unsigned int count=0;
void main(void){
	unsigned int one=0;
	unsigned int two=0;
	lcd_init();
	while(1){
		if(ir1==1){
			delay(50000);
			count++;
		}
		else if(ir2==1){
			delay(50000);
			count--;
		}
		lcd_init();
		lcd_print(count-1);
	}
}
void lcd_init(void){
	lcd_cmd(0x38);
	lcd_cmd(0x0c);
	lcd_cmd(0x01);
	lcd_cmd(0x80);
}
void lcd_cmd( unsigned char a ){
	rs=0;
	ldata = a ;
	en = 0;
	delay(500);
	en=1;
}
void lcd_data( unsigned char b ){
	rs=1;
	ldata = b ;
	en = 0;
	delay(500);
	en=1;
}
void lcd_print(unsigned int value){
//	value = 789;
	unsigned char a100;
	unsigned char a10;
	unsigned char a1;
	a1 = value%10;	// a1=9
	a100=value/10;	// a100=78
	a10=a100%10;	//a10=8
	a100=a100/10;	// a100=7
	lcd_data(a100+48);
	delay(500);
	lcd_data(a10+48);
	delay(500);
	lcd_data(a1+48);
	delay(5000);
}
void delay(unsigned int i){
	unsigned int j;
	for(j=0;j<i;j++);
}

























//#include <reg51.h>


//sfr ldata = 0x90;

//void main(void)
//{
//	
//	while(1)
//	{
//		if(sw == 1)
//			led = 1;
//		else 
//			led = 0;
//	}
//}