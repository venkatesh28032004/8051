#include < reg51.h >
sbit rs=P2^6;
sbit en=P2^7;
sfr ldata=P3;
void main(void )
	{
		lcd_init();
		
	}
void lcd_init(void)
{
	lcd_cmd(0x38);
	lcd_cmd(0x0c);
	lcd_cmd(0x01);
	lcd_cmd(0x80);
}
void lcd_cmd(unsigned char a)
{
	rs=0;
	ldata=a;
	
	