
#include	"STC15Fxxxx.H"
#include	"UART1-2.H"
#include	"wifi.h"



extern u8	TX1_Cnt;	//���ͼ���
extern u8	RX1_Cnt;	//���ռ���
extern u8	TX2_Cnt;	//���ͼ���
extern u8	RX2_Cnt;	//���ռ���
extern bit	B_TX1_Busy;	//����æ��־
extern bit	B_TX2_Busy;	//����æ��־
extern u8 	idata RX1_Buffer[UART1_BUF_LENGTH];	//���ջ���
extern u8 	idata RX2_Buffer[UART2_BUF_LENGTH];	//���ջ���
//========================================================================
// ����: void UART1_int (void) interrupt UART1_VECTOR
// ����: UART1�жϺ�����
// ����: nine.
// ����: none.
// �汾: VER1.0
// ����: 2014-11-28
// ��ע: 
//========================================================================
void UART1_int (void) interrupt UART1_VECTOR
{
//	if(RI)
//	{
//		RI = 0;
//		RX1_Buffer[RX1_Cnt] = SBUF;
//		
//		

//		if((TX1_Cnt != RX1_Cnt) && (!B_TX1_Busy))	//�յ�����, ���Ϳ���
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
// ����: void UART2_int (void) interrupt UART2_VECTOR
// ����: UART2�жϺ�����
// ����: nine.
// ����: none.
// �汾: VER1.0
// ����: 2014-11-28
// ��ע: 
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
		uart_receive_input(S2BUF);//����Ϳѻ��������
	}

	if((S2CON & 2) != 0)
	{
		S2CON &= ~2;	//Clear Tx flag
		B_TX2_Busy = 0;
	}

	
	
	
	
	
}




















