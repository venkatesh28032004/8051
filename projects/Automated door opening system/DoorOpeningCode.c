#include < reg51.h >
void delay(unsigned int time);
void lcd_init(void);
void lcd_cmd(unsigned char a);
void lcd_data(unsigned char b);
void lcd_print(unsigned char *str);


sbit rs=P2^0;
sbit en=P2^1;
sbit ir=P2^2;

sfr ldata = 0xb0;

void main( void ){
	lcd_init();
	lcd_print(" AUTOMATED DOOR ");
	lcd_cmd(0xc0);
	lcd_print(" OPENING SYSTEM ");
	delay(65000);
}
void delay(unsigned int time){
	unsigned int j;
	for(j=0;j<time;j++);
}
void lcd_init(void ){
	lcd_cmd(0x38);
	lcd_cmd(0x0c);
	lcd_cmd(0x01);
	lcd_cmd(0x80);
}
void lcd_cmd(unsigned char a){
	rs=0;
	ldata=a;
	en=1;
	delay(200);
	en=0;
}
void lcd_data(unsigned char b){
	rs=1;
	ldata=b;
	en=1;
	delay(100);
	en=0;
}
void lcd_print(unsigned char *str){
	while(*str)
		lcd_data(*str++);
}