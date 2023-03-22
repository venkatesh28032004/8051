#include<reg51.h>
void timer_init(void);
void main()
{
	while(1)
	{
		timer_init();
	}
}
void timer_init(void)
{
	TMOD=0X02;
	TH0=0XFF;
	TL0=0XAD;
	TR0=1;
	while(TF0==1);
	{
	     TF0=0;
	     TR0=0;
	}
	return;
}