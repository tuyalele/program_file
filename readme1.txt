		if(Tim_test < -6000 || Tim_test > 6000){
	PrintString1("======================================================\r\n");	//SUART1����һ���ַ���
	
//			PrintString1(Tim_test);	//SUART1����һ���ַ���
			PrintN1(Tim_test);		PrintString1("!\r\n");													//SUART1����һ���ַ���
			
			PrintString1("��ǰ�¶�");						PrintN1(FlashBuffer.temper);					PrintString1("!\r\n");	//SUART1����һ���ַ���
			PrintString1("��ǰʪ��");						PrintN1(FlashBuffer.humidity);				PrintString1("!\r\n");	//SUART1����һ���ַ���
			PrintString1("�¶Ȳ���ʱ������");		PrintN1(FlashBuffer.CY_T_time);				PrintString1("!\r\n");	//SUART1����һ���ַ���
			PrintString1("ʪ�Ȳ���ʱ������");		PrintN1(FlashBuffer.CY_H_time);				PrintString1("!\r\n");	//SUART1����һ���ַ���
			PrintString1("�¶���������");				PrintN1(FlashBuffer.most_T);					PrintString1("!\r\n");	//SUART1����һ���ַ���
			PrintString1("�¶���������");				PrintN1(FlashBuffer.least_T);					PrintString1("!\r\n");	//SUART1����һ���ַ���
			PrintString1("ʪ����������");				PrintN1(FlashBuffer.most_humidity);		PrintString1("!\r\n");	//SUART1����һ���ַ���
			PrintString1("ʪ����������");				PrintN1(FlashBuffer.least_humidity);	PrintString1("!\r\n");	//SUART1����һ���ַ���
			PrintString1("�¶ȱ���");						PrintN1(FlashBuffer.JB_T);						PrintString1("!\r\n");	//SUART1����һ���ַ���
			PrintString1("ʪ�ȱ���");						PrintN1(FlashBuffer.JB_humidity);			PrintString1("!\r\n");	//SUART1����һ���ַ���
			PrintString1("��ǰ����ֵ");					PrintN1(FlashBuffer.sun);							PrintString1("!\r\n");	//SUART1����һ���ַ���
			PrintString1("��ǰDATAָ��");				PrintD1(&DATA[0]);				PrintString1("!\r\n");	//SUART1����һ���ַ���
			PrintString1("DATA����");						PrintN1(FlashBuffer.DATA_long);				PrintString1("!\r\n");	//SUART1����һ���ַ���
//			PrintString1("CCTU");				PrintStrinD1(0,20);		PrintString1("!\r\n");	//SUART1����һ���ַ���
			
	
all_data_update();//�����ϱ�
wifi_work_state_led();
			Tim_test = 0;
	PrintString1("======================================================\r\n");	//SUART1����һ���ַ���
		}
		
		
		
		
		
		