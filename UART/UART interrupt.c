
#include	"STC15Fxxxx.H"
#include	"UART1-2.H"
#include	"wifi.h"



extern u8	TX1_Cnt;	//发送计数
extern u8	RX1_Cnt;	//接收计数
extern u8	TX2_Cnt;	//发送计数
extern u8	RX2_Cnt;	//接收计数
extern bit	B_TX1_Busy;	//发送忙标志
extern bit	B_TX2_Busy;	//发送忙标志
extern u8 	idata RX1_Buffer[UART1_BUF_LENGTH];	//接收缓冲
extern u8 	idata RX2_Buffer[UART2_BUF_LENGTH];	//接收缓冲
//========================================================================
// 函数: void UART1_int (void) interrupt UART1_VECTOR
// 描述: UART1中断函数。
// 参数: nine.
// 返回: none.
// 版本: VER1.0
// 日期: 2014-11-28
// 备注: 
//========================================================================
void UART1_int (void) interrupt UART1_VECTOR
{
//	if(RI)
//	{
//		RI = 0;
//		RX1_Buffer[RX1_Cnt] = SBUF;
//		
//		

//		if((TX1_Cnt != RX1_Cnt) && (!B_TX1_Busy))	//收到数据, 发送空闲
//		{
//			SBUF = RX1_Buffer[TX1_Cnt];
//			B_TX1_Busy = 1;
//			if(++TX1_Cnt >= UART1_BUF_LENGTH)	TX1_Cnt = 0;	

//		}
//		if(++RX1_Cnt >= UART1_BUF_LENGTH)	RX1_Cnt = 0;
//	}

//	if(TI)
//	{
//		TI = 0;
//		B_TX1_Busy = 0;
//	}
}

//========================================================================
// 函数: void UART2_int (void) interrupt UART2_VECTOR
// 描述: UART2中断函数。
// 参数: nine.
// 返回: none.
// 版本: VER1.0
// 日期: 2014-11-28
// 备注: 
//========================================================================
void UART2_int (void) interrupt UART2_VECTOR
{
	
	
	if((S2CON & 1) != 0)
	{
		S2CON &= ~1;	//Clear Rx flag
//		RX2_Buffer[RX2_Cnt] = S2BUF;
//			
//		
//		if(++RX2_Cnt >= UART2_BUF_LENGTH)	RX2_Cnt = 0;
		uart_receive_input(S2BUF);//调用涂鸦处理数据
	}

	if((S2CON & 2) != 0)
	{
		S2CON &= ~2;	//Clear Tx flag
		B_TX2_Busy = 0;
	}

	
	
	
	
	
}




















