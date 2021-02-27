		if(Tim_test < -6000 || Tim_test > 6000){
	PrintString1("======================================================\r\n");	//SUART1发送一个字符串
	
//			PrintString1(Tim_test);	//SUART1发送一个字符串
			PrintN1(Tim_test);		PrintString1("!\r\n");													//SUART1发送一个字符串
			
			PrintString1("当前温度");						PrintN1(FlashBuffer.temper);					PrintString1("!\r\n");	//SUART1发送一个字符串
			PrintString1("当前湿度");						PrintN1(FlashBuffer.humidity);				PrintString1("!\r\n");	//SUART1发送一个字符串
			PrintString1("温度采样时间设置");		PrintN1(FlashBuffer.CY_T_time);				PrintString1("!\r\n");	//SUART1发送一个字符串
			PrintString1("湿度采样时间设置");		PrintN1(FlashBuffer.CY_H_time);				PrintString1("!\r\n");	//SUART1发送一个字符串
			PrintString1("温度上限设置");				PrintN1(FlashBuffer.most_T);					PrintString1("!\r\n");	//SUART1发送一个字符串
			PrintString1("温度下限设置");				PrintN1(FlashBuffer.least_T);					PrintString1("!\r\n");	//SUART1发送一个字符串
			PrintString1("湿度上限设置");				PrintN1(FlashBuffer.most_humidity);		PrintString1("!\r\n");	//SUART1发送一个字符串
			PrintString1("湿度下限设置");				PrintN1(FlashBuffer.least_humidity);	PrintString1("!\r\n");	//SUART1发送一个字符串
			PrintString1("温度报警");						PrintN1(FlashBuffer.JB_T);						PrintString1("!\r\n");	//SUART1发送一个字符串
			PrintString1("湿度报警");						PrintN1(FlashBuffer.JB_humidity);			PrintString1("!\r\n");	//SUART1发送一个字符串
			PrintString1("当前亮度值");					PrintN1(FlashBuffer.sun);							PrintString1("!\r\n");	//SUART1发送一个字符串
			PrintString1("当前DATA指针");				PrintD1(&DATA[0]);				PrintString1("!\r\n");	//SUART1发送一个字符串
			PrintString1("DATA长度");						PrintN1(FlashBuffer.DATA_long);				PrintString1("!\r\n");	//SUART1发送一个字符串
//			PrintString1("CCTU");				PrintStrinD1(0,20);		PrintString1("!\r\n");	//SUART1发送一个字符串
			
	
all_data_update();//数据上报
wifi_work_state_led();
			Tim_test = 0;
	PrintString1("======================================================\r\n");	//SUART1发送一个字符串
		}
		
		
		
		
		
		