
#include  "main.h"
#include 	"key.h"
sbit RET = P5^4;
sbit OK = P4^7;
sbit W = P1^2;
sbit E = P1^3;
sbit S = P1^4;
sbit D = P1^5;


u8 key_scan(void)//不允许同时按多个键
{
	u8 ke = 0;
	RET = 1;
	OK = 1;
	W = 1;
	E = 1;
	S = 1;
	D = 1;
	
	delay_us(10);
	
	if(RET == 0){
		ke = ke+1;
	}
	if(OK == 0){
		ke = ke+2;
	}
	if(W == 0){
		ke = ke+4;
	}
	if(E == 0){
		ke = ke+8;
	}
	if(S == 0){
		ke = ke+16;
	}
	if(D == 0){
		ke = ke+32;
	}
	
	return ke;
	
}



