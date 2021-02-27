
#include  "main.h"

#include "STC15.h"
#include  "delay.h"

// int Time_sys[6];
 int Tim_test;

void wifi_reset(void)
{

mcu_reset_wifi();
delay_ms(10);
	mcu_set_wifi_mode(SMART_CONFIG);
//mcu_get_reset_wifi_flag();



}
/*****************************************************************************
函数名称 : wifi_work_state_led
功能描述 : wifi状态查询
输入参数 : 无
返回参数 : 无
使用说明 : 无
*****************************************************************************/
void wifi_work_state_led(void)
{
  u16 wifi_state = mcu_get_wifi_work_state();
	switch(wifi_state)
	{
	case SMART_CONFIG_STATE:            //smartconfig配置状态
		
					OLED_ShowCHinese(17,0,9);//待
					OLED_ShowCHinese(35,0,10);
					OLED_ShowCHinese(54,0,11);//配置
					OLED_ShowString(74,0,"WIFI",16);
					OLED_ShowCHinese(110,0,20);


//		PrintString1("smartconfig配置状态!\r\n");	//SUART1发送一个字符串
	
		break;
		
	case AP_STATE:                      //AP配置状态
		
//			PrintString1("AP配置状态!\r\n");	//SUART1发送一个字符串

					OLED_ShowString(17,0,"AP",16);
					OLED_ShowCHinese(54,0,10);
					OLED_ShowCHinese(74,0,11);//配置
					OLED_ShowCHinese(95,0,20);
	
		break;
		
	case WIFI_NOT_CONNECTED:            //WIFI配置成功但未连上路由器
		

//		PrintString1("WIFI配置成功但未连上路由器\r\n");	//SUART1发送一个字符串
						OLED_ShowCHinese(0,0,9);//待
					OLED_ShowCHinese(18,0,15);
					OLED_ShowCHinese(37,0,16);//连接
					OLED_ShowCHinese(57,0,12);
					OLED_ShowCHinese(78,0,13);
					OLED_ShowCHinese(100,0,14);//路由器
//					OLED_ShowCHinese(140,0,20);
	
		break;
		
	case WIFI_CONNECTED:                //WIFI配置成功且连上路由器
		
//		PrintString1("WIFI配置成功且连上路由器\r\n");	//SUART1发送一个字符串
					OLED_ShowCHinese(0,0,9);//待
					OLED_ShowCHinese(18,0,15);
					OLED_ShowCHinese(37,0,16);//连接
					OLED_ShowCHinese(57,0,17);
					OLED_ShowCHinese(78,0,18);
					OLED_ShowCHinese(100,0,19);//
//					OLED_ShowCHinese(117,0,20);
	
		break;
		
	case WIFI_CONN_CLOUD:               //WIFI已经连接上云服务器

//		PrintString1("WIFI已经连接上云服务器\r\n");	//SUART1发送一个字符串
					OLED_ShowString(17,0,"OK",12);
		break;
		
	case WIFI_LOW_POWER:                //WIFI处于低功耗模式
//		PrintString1("WIFI处于低功耗模式\r\n");	//SUART1发送一个字符串
					OLED_ShowCHinese(17,0,9);//待
					OLED_ShowCHinese(35,0,21);
					OLED_ShowCHinese(54,0,22);//机中
					OLED_ShowCHinese(74,0,20);
		break;
		
	case SMART_AND_AP_STATE:            //WIFI smartconfig&AP 模式
//		PrintString1("WIFI smartconfig&AP 模式\r\n");	//SUART1发送一个字符串
	
		break;
		
	default:                            //未知状态
//		PrintString1("未知状态\r\n");	//SUART1发送一个字符串
					OLED_ShowCHinese(17,0,23);
					OLED_ShowCHinese(35,0,24);
					OLED_ShowCHinese(54,0,25);
					OLED_ShowCHinese(74,0,26);//未知状态
					OLED_ShowCHinese(95,0,20);
	 break;
	}
	/*
					OLED_ShowCHinese(17,0,9);//待
					OLED_ShowCHinese(35,0,15);
					OLED_ShowCHinese(54,0,16);//连接
					OLED_ShowCHinese(74,0,12);
					OLED_ShowCHinese(95,0,13);
					OLED_ShowCHinese(117,0,14);//路由器
					OLED_ShowCHinese(140,0,20);
	*/
}


 
/********************* Timer0中断函数************************/
void timer0_int (void) interrupt TIMER0_VECTOR
{
P55 = 0;

			Tim_test++;
P55 = 1;
P55 = 0;
}



void STC_Init(void){

//GPIO初始化
	P0M1 = 0;	P0M0 = 0;	//设置为准双向口
	P1M1 = 0;	P1M0 = 0;	//设置为准双向口
	P2M1 = 0;	P2M0 = 0;	//设置为准双向口
	P3M1 = 0;	P3M0 = 0;	//设置为准双向口
	P4M1 = 0;	P4M0 = 0;	//设置为准双向口
	P5M1 = 0;	P5M0 = 0;	//设置为准双向口
	P6M1 = 0;	P6M0 = 0;	//设置为准双向口
	P7M1 = 0;	P7M0 = 0;	//设置为准双向口

	

	OLED_Init();			//初始化OLED  
	OLED_Clear(); 
	
	OLED_ShowString(0,0,"OLED",12);
	delay_ms(255);
	OLED_ShowString(33,0,">",12);
	delay_ms(255);
	OLED_ShowString(41,0,">",12);
	delay_ms(255);
	OLED_ShowString(49,0,">",12);
	delay_ms(255);
	OLED_ShowString(57,0,">",12);
	delay_ms(255);
	OLED_ShowString(67,0,"OK",12);
	delay_ms(255);
	


	

//UART初始化
//	UART1_config(1);	// 选择波特率, 2: 使用Timer2做波特率, 其它值: 使用Timer1做波特率.
	UART2_config(2);	// 选择波特率, 2: 使用Timer2做波特率, 其它值: 无效.
	EA = 1;			    	//允许全局中断

		OLED_ShowString(0,1,"UART",12);
	delay_ms(255);
	OLED_ShowString(33,1,">",12);
	delay_ms(255);
	OLED_ShowString(41,1,">",12);
	delay_ms(255);
	OLED_ShowString(49,1,">",12);
	delay_ms(255);
	OLED_ShowString(57,1,">",12);
	delay_ms(255);
	OLED_ShowString(67,1,"OK",12);
	delay_ms(255);
	
//	PrintString1("STC15F2K60S2 UART1 Test Prgramme!\r\n");	//SUART1发送一个字符串
	PrintString2("STC15F2K60S2 UART2 Test Prgramme!\r\n");	//SUART2发送一个字符串
	
	delay_ms(255);
	SHT3XInit();
	
		OLED_ShowString(0,2,"SHT30",12);
	delay_ms(255);
	OLED_ShowString(45,2,">",12);
	delay_ms(255);
	OLED_ShowString(53,2,">",12);
	delay_ms(255);
	OLED_ShowString(61,2,">",12);
	delay_ms(255);
	OLED_ShowString(69,2,">",12);
	delay_ms(255);
	OLED_ShowString(79,2,"OK",12);
	delay_ms(255);

	Timer0_init();
	
		OLED_ShowString(0,3,"Timer",12);
	delay_ms(255);
	OLED_ShowString(45,3,">",12);
	delay_ms(255);
	OLED_ShowString(53,3,">",12);
	delay_ms(255);
	OLED_ShowString(61,3,">",12);
	delay_ms(255);
	OLED_ShowString(69,3,">",12);
	delay_ms(255);
	OLED_ShowString(79,3,"OK",12);
	delay_ms(255);
	

	wifi_protocol_init();//涂鸦wifi协议初始化
	
		OLED_ShowString(0,4,"Tuya",12);
	delay_ms(255);
	OLED_ShowString(33,4,">",12);
	delay_ms(255);
	OLED_ShowString(41,4,">",12);
	delay_ms(255);
	OLED_ShowString(49,4,">",12);
	delay_ms(255);
	OLED_ShowString(57,4,">",12);
	delay_ms(255);
	OLED_ShowString(67,4,"OK",12);
	delay_ms(1000);
	OLED_Clear(); 
}

/*****************************************************************************
函数名称 : read_sensor
功能描述 : 读取传感器
输入参数 : 无
返回参数 : 无
使用说明 : 无
*****************************************************************************/
static void read_sensor(void)
{
		int temp,humi,temper,humidity;
	//=================================================================================温湿度
					SHT3X_XHGetTempAndHumi(&temp,&humi);
					temper = temp;
					humidity = humi;
	
	
					OLED_ShowCHinese(0,2,0);
					OLED_ShowCHinese(17,2,1);//温度
					OLED_ShowString(35,2,":",16);
					OLED_ShowNum(54,2,(temper/10),2,16);
					OLED_ShowString(74,2,".",16);
					OLED_ShowNum(83,2,(temper%10),1,16);
	
					OLED_ShowCHinese(0,4,2);
					OLED_ShowCHinese(17,4,1);//湿度
					OLED_ShowString(35,4,":",16);
					OLED_ShowNum(54,4,(humidity/10),2,16);
					OLED_ShowString(74,4,".",16);
					OLED_ShowNum(83,4,(humidity%10),1,16);
					OLED_ShowString(100,4,"%",16);
					
		mcu_dp_value_update(DPID_TEMP_CURRENT,temper); //VALUE型数据上报;当前温度
    mcu_dp_value_update(DPID_HUMIDITY_VALUE,humidity/10); //VALUE型数据上报;当前当前湿度
	//=======================================================================================
}

void key_set(void){


switch(key_scan())
        {
            case 1://RET
               
						wifi_reset();
						
					OLED_Clear(); 
					read_sensor();
					wifi_work_state_led();
						
            break;
            case 2://OK
							
						
             
            break;
            case 4://W

						
					
            break;
            case 8://E
                
						
						
            break;
            case 16://S
            
						
						
            break;
            case 32://D
                
						
						
            break;
						
            default:break;
        }



}

//========================================================================
// 函数: void main(void)
// 描述: 主函数。
// 参数: none.
// 返回: none.
// 版本: VER1.0
// 日期: 2014-11-28
// 备注: 
//========================================================================
void main(void)
{
	
	
	

		int count = 0;
	
STC_Init();


	while (1)
	{
		
			wifi_uart_service();//wifi循环
			key_set();

			if(Tim_test < -6000 || Tim_test > 6000){
				
				//============================================温湿度
				
					OLED_Clear(); 
					read_sensor();
					wifi_work_state_led();
					
					//============================================

	
				all_data_update();//数据上报
				wifi_work_state_led();
				Tim_test = 0;
		}
	
	}	
	
	
	
	
	
	
	
	
}