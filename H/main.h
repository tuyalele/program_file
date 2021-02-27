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
//变量定义
//==============================================================================

extern char DATA[50];


extern  int Time_sys[7];               //系统时间
extern	int temper;                    //当前温度
extern  int humidity;                  //当前湿度
extern	u8 CY_T_time;                  //当前温度采样时间设置
extern	u8 CY_H_time;                  //当前湿度采样时间设置
extern	int most_T;                    //当前温度上限设置
extern	int least_T;                   //当前温度下限设置
extern	int most_humidity;             //当前湿度上限设置
extern	int least_humidity;            //当前湿度下限设置
extern	int JB_T;                      //当前温度报警
extern	int JB_humidity;               //当前湿度报警
extern	int sun;                       //当前当前亮度值
//	char DATA[200];                    //当前DATA指针
extern	u8 DATA_long;                  //DATA长度
	//当前DATA数据长度 200
	
	




#endif