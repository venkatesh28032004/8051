#include <reg51.h>
void lcd_init ( void );
void lcd_cmd ( unsigned char a );
void lcd_data ( unsigned char b );
void lcd_print ( unsigned char *str );
void delay ( unsigned int value);
void checkMODE(void);
void checkPUMP( void );
void printWaterlevel(void);


sbit rs = P2^0 ;
sbit en = P2^1 ;
sfr ldata = 0xb0;

sbit l25 = P1^0 ;
sbit l50 = P1^1 ;
sbit l75 = P1^2 ;
sbit l100 = P1^3 ;
sbit motor = P2^2 ;
sbit motorENABLE = P2^3 ;
sbit modeSelect = P2^4 ;
// pump-off						 2,3-low
unsigned int mode = 0;
unsigned int pump = 0;
unsigned int level =0;

void main ( void ) {
	lcd_init();
	if(modeSelect == 0){
		mode=1;
		motorENABLE=0;
	}
	else if(modeSelect == 1){
		mode=0;
		motorENABLE=1;
		motor=1;
	}
	lcd_print(" WATER LEVEL: ");
	printWaterlevel();
	lcd_cmd(0xc0);
	lcd_print("PUMP:      ");
	checkPUMP();
	lcd_cmd(0xca);
	checkMODE();
	delay(65000);
}
void printWaterlevel(void){
	if(l100==0 && l75==0 && l50==0 && l25==0){
		lcd_cmd(0x8d);
		lcd_print("100%");
		if(mode == 1){
				motor=0;
				pump=0;
			motorENABLE=1;
		}
		
	}
	else if(l100==1 && l75==0 && l50==0 && l25==0){
		lcd_cmd(0x8d);
		lcd_print("75%");
		if(mode == 1){
				motor=1;
				pump=1;
		}
	}
	else if(l100==1 && l75==1 && l50==0 && l25==0){
		lcd_cmd(0x8d);
		lcd_print("50%");if(mode == 1){
				motor=1;
				pump=1;
		}
	}
	else if(l100==1 && l75==1 && l50==1 && l25==0){
		lcd_cmd(0x8d);
		lcd_print("25%");
		if(mode == 1){
				motor=1;
				pump=1;
		}
	}
	else if(l100==1 && l75==1 && l50==1 && l25==1){
		lcd_cmd(0x8d);
		lcd_print("0%");
		if(mode ==1){
			motor = 0;
			pump=1;
		}
	}
	else{
		lcd_cmd(0x8e);
		lcd_print("-");
	}
}
void checkPUMP( void ){
	// write code to check pump value
	lcd_cmd(0xc5);
	if(pump==0)
		lcd_print("OFF");
	else
		lcd_print("ON");
}
void checkMODE(void){
	// write code to check mode value
	lcd_cmd(0xca);
	if(mode==0){
		lcd_print("MANUAL");
	}
	else{
		lcd_print("AUTO");
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