/*************	功能说明	**************

本程序演示3个定时器的使用, 本例程均使用16位自动重装.

下载时, 选择时钟 24MHZ (用户可自行修改频率).

******************************************/


//#define 	MAIN_Fosc		24000000UL	//定义主时钟

#include "main.h"

#include	"timer.h"
#define	Timer0_Reload	(MAIN_Fosc / 2000)		//Timer 1 中断频率, 2000次/秒
#define	Timer1_Reload	(MAIN_Fosc / 2000)		//Timer 1 中断频率, 2000次/秒
#define	Timer2_Reload	(MAIN_Fosc / 3000)		//Timer 2 中断频率, 3000次/秒




//========================================================================
// 函数: void	Timer0_init(void)
// 描述: timer0初始化函数.
// 参数: none.
// 返回: none.
// 版本: V1.0, 2015-1-12
//========================================================================
void	Timer0_init(void)//1毫秒@22.1184MHz
{
		TR0 = 0;	//停止计数


		ET0 = 1;	//允许中断
	//	PT0 = 1;	//高优先级中断
		TMOD &= ~0x03;
		TMOD |= 0;	//工作模式, 0: 16位自动重装, 1: 16位定时/计数, 2: 8位自动重装, 3: 16位自动重装, 不可屏蔽中断
	//	TMOD |=  0x04;	//对外计数或分频
		TMOD &= ~0x04;	//定时
	//	INT_CLKO |=  0x01;	//输出时钟
		INT_CLKO &= ~0x01;	//不输出时钟

			AUXR |=  0x80;	//1T mode
			TH0 = (u8)((65536UL - Timer0_Reload) / 256);//0xA9
			TL0 = (u8)((65536UL - Timer0_Reload) % 256);//0x9A
		TR0 = 1;	//开始运行
}

//========================================================================
// 函数: void	Timer1_init(void)
// 描述: timer1初始化函数.
// 参数: none.
// 返回: none.
// 版本: V1.0, 2015-1-12
//========================================================================
void	Timer1_init(void)
{
		TR1 = 0;	//停止计数

	#if (Timer1_Reload < 64)	// 如果用户设置值不合适， 则不启动定时器
		#error "Timer1设置的中断过快!"

	#elif ((Timer1_Reload/12) < 65536UL)	// 如果用户设置值不合适， 则不启动定时器
		ET1 = 1;	//允许中断
	//	PT1 = 1;	//高优先级中断
		TMOD &= ~0x30;
		TMOD |= (0 << 4);	//工作模式, 0: 16位自动重装, 1: 16位定时/计数, 2: 8位自动重装
	//	TMOD |=  0x40;	//对外计数或分频
		TMOD &= ~0x40;	//定时
	//	INT_CLKO |=  0x02;	//输出时钟
		INT_CLKO &= ~0x02;	//不输出时钟

		#if (Timer1_Reload < 65536UL)
			AUXR |=  0x40;	//1T mode
			TH1 = (u8)((65536UL - Timer1_Reload) / 256);
			TL1 = (u8)((65536UL - Timer1_Reload) % 256);
		#else
			AUXR &= ~0x40;	//12T mode
			TH1 = (u8)((65536UL - Timer1_Reload/12) / 256);
			TL1 = (u8)((65536UL - Timer1_Reload/12) % 256);
		#endif

		TR1 = 1;	//开始运行

	#else
		#error "Timer1设置的中断过慢!"
	#endif
}

