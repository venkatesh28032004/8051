#include < reg51.h >
sbit ir1=P2^0;
sbit ir2=P2^1;
sbit light1=P3^0;
sbit light2=P3^1;
unsigned int n;
unsigned int i;
void main(void){
	n=1;
	if(n==1){
		light1=0;
	light2=0;
	}
	
	
	
//	if(ir1==1 && ir2==0){
//		light1=1;
//		light2=0;
//	}
//	if(ir1==0 && ir2==1){
//		light2=1;
//		light1=0;
//	}
//	n++;
}