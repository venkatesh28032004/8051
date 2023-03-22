#include <reg51.h>
void lcd_init ( void );
void lcd_cmd ( unsigned char a );
void lcd_data ( unsigned char b );
void lcd_print ( unsigned char *str );
void delay ( unsigned int value);

sbit ir= P2^2;
sbit rs = P2^0 ;
sbit en = P2^1 ;
sbit buzEN=P2^3;
sfr ldata = 0xb0;

unsigned int value;

void main ( void ) {
	lcd_init();
	buzEN=0;
	
	while(1){
		if(ir==1){
			lcd_init();
			lcd_print(" you are IN ");
			buzEN=1;
			delay(10000);
		}
		if(ir==0){
			lcd_init();
			lcd_print(" you are OUT ");
			buzEN=0;
			delay(10000);
		}
		
	}
	
}
void delay ( unsigned int value ){
	unsigned int i ;
	for(i=0;i<value;i++);
}
void lcd_init ( void ) {
	lcd_cmd(0x38);
	lcd_cmd(0x0c);
	lcd_cmd(0x01);
	lcd_cmd(0x80);
}
void lcd_cmd ( unsigned char a ){
	rs = 0 ;
	ldata = a ;
	en = 1 ;
	delay(200);
	en = 0;
}
void lcd_data ( unsigned char b ){
	rs = 1 ;
	ldata = b ;
	en = 1 ;
	delay(100);
	en = 0;
}
void lcd_print ( unsigned char *str){
	while(*str)
		lcd_data(*str++);
}