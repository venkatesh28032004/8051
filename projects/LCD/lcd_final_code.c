#include < reg51.h >

void lcd_init(void);
void lcd_cmd( unsigned char a );
void lcd_data( unsigned char b );
void lcd_print( unsigned int start , unsigned int stop);
void delay(unsigned int i);

sbit rs = P2^0;
sbit en = P2^1;
sfr ldata = 0xb0;
unsigned int name[25];

unsigned int p;
unsigned int k;
unsigned int q;

char string[49] =" WELCOME MY NAME IS  VENKATESH  , ECE - 1 HONORS ";


void main(void){
	lcd_init();
	p=0;
	k=15;
	while(k<47){
		lcd_cmd(0x80);
		k=p+15;
		lcd_print(p,k);
		p=p+1;
		delay(56000);
		lcd_cmd(0x0c);
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
	delay(5);
	en=1;
}
void lcd_data( unsigned char b ){
	rs=1;
	ldata = b ;
	en = 0;
	delay(5);
	en=1;
}
void lcd_print(unsigned int start , unsigned int stop ){
	for( q = start ; q <stop ; q++){
	lcd_data(string[q]);
	}
	
}
void delay(unsigned int i){
	unsigned int j;
	for(j=0;j<i;j++);
}
