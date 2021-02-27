#ifndef __INCLUDE_H__
#define __INCLUDE_H__

//#ifdef MAINWORK_GLOBALS
//#define MAINWORK_EXT
//#else
//#define MAINWORK_EXT extern 
//#endif




//==============================================================================
#include 		<intrins.h>
#include    <math.h>
#include "STC15.h"
//#include    "STC15Fxxxx.H"
#include    "UART1-2.h"
#include  "delay.h"
#include	"timer.h"
#include	"wifi.h"
#include "stdio.h"
#include "string.h"
#include "protocol.h"
#include "system.h"
#include "MCU_API.H"


#include        "reda_data.h"
#include 				"key.h"
#include 				"OLED.h"
#include 				"SHT3X.h"
//#include 				"ADC.h"



//==============================================================================
//��������
//==============================================================================

extern char DATA[50];


extern  int Time_sys[7];               //ϵͳʱ��
extern	int temper;                    //��ǰ�¶�
extern  int humidity;                  //��ǰʪ��
extern	u8 CY_T_time;                  //��ǰ�¶Ȳ���ʱ������
extern	u8 CY_H_time;                  //��ǰʪ�Ȳ���ʱ������
extern	int most_T;                    //��ǰ�¶���������
extern	int least_T;                   //��ǰ�¶���������
extern	int most_humidity;             //��ǰʪ����������
extern	int least_humidity;            //��ǰʪ����������
extern	int JB_T;                      //��ǰ�¶ȱ���
extern	int JB_humidity;               //��ǰʪ�ȱ���
extern	int sun;                       //��ǰ��ǰ����ֵ
//	char DATA[200];                    //��ǰDATAָ��
extern	u8 DATA_long;                  //DATA����
	//��ǰDATA���ݳ��� 200
	
	




#endif