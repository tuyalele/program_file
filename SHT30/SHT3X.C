
#include "SHT3X.H"

/*================================================================
���� �ơ�
���� �ܡ�ģ��IICʹ�õ����Ŷ��壬ע��Ҫ��������
���� ע��
���� �ߡ�
��ʱ �䡿
================================================================*/
//sbit SDA=P3^3;  //��������Ŷ���
//sbit SCL=P5^4;



#define POLYNOMIAL  0x31 // P(x) = x^8 + x^5 + x^4 + 1 = 00110001

//==============================================================================
unsigned char SHT3X_CalcCrc(unsigned char *crcdata, unsigned char nbrOfBytes){
//==============================================================================
	unsigned char Bit;        // bit mask
  unsigned char crc = 0xFF; // calculated checksum
  unsigned char byteCtr;    // byte counter
  
  // calculates 8-Bit checksum with given polynomial 
  for(byteCtr = 0; byteCtr < nbrOfBytes; byteCtr++)
  {
    crc ^= (crcdata[byteCtr]);
    for(Bit = 8; Bit > 0; --Bit)
    {
      if(crc & 0x80) crc = (crc << 1) ^ POLYNOMIAL;
      else           crc = (crc << 1);
    }
  }
	return crc;
}
///*================================================================
//���� �ơ�void Delay(unsigned int t)
//���� �ܡ���ʱ��
//���� ע��
//���� �ߡ�
//��ʱ �䡿
//================================================================*/
//void Delay(unsigned int t)
//{
//	unsigned char i;
//	while(t--)
//	{
//		for(i=0;i<200;i++);
//	}					   
//}
//void Delay1ms()		//@24.000MHz
//{
//	unsigned char i, j;

//	i = 24;
//	j = 85;
//	do
//	{
//		while (--j);
//	} while (--i);
//}

//***********************������ģ��I2C����****************************//
/*================================================================
���� �ơ�void I2CDelay (unsigned char t)
���� �ܡ�ģ��IIC�õĶ���ʱ
���� ע��
���� �ߡ�
��ʱ �䡿
================================================================*/
void I2CDelay (unsigned char t)
{
	while(t--);
}
/*================================================================
���� �ơ�void I2CInit(void)
���� �ܡ�I2C��ʼ��������״̬
���� ע��
���� �ߡ�
��ʱ �䡿
================================================================*/
void I2CInit(void)
{
	SDA = 1; 
	SCL = 1;
}
/*================================================================
���� �ơ�void I2CStart(void)
���� �ܡ�I2C��ʼ�ź�
���� ע��SCL��SDAͬΪ�ߣ�SDA����ɵ�֮��SCL����ɵ�
���� �ߡ�
��ʱ �䡿
================================================================*/
void I2CStart(void)
{
  	SDA = 1;
  	SCL = 1;
  	I2CDelay(10);
  	SDA = 0;
  	I2CDelay(20);
  	SCL = 0;
  	I2CDelay(20);
}
/*================================================================
���� �ơ�void I2CStop(void)
���� �ܡ�I2Cֹͣ�ź�
���� ע��SCL��SDAͬΪ�ͣ�SCL����ɸ�֮��SDA����ɸ�
���� �ߡ�
��ʱ �䡿
================================================================*/
void I2CStop(void)
{
  	SDA = 0;
  	SCL = 0;
	  I2CDelay(10);
  	SCL = 1;
  	I2CDelay(10);
  	SDA = 1;
  	I2CDelay(10);
}
/*================================================================
���� �ơ�unsigned char I2CWRByte(unsigned char WRByte)
���� �ܡ�I2Cдһ���ֽ����ݣ�����ACK����NACK
���� ע���Ӹߵ��ͣ����η���
���� �ߡ�
��ʱ �䡿
================================================================*/
etError I2CWRByte(unsigned char WRByte)
{
	unsigned char i;
	SCL = 0;
	for(i=0;i<8;i++)
	{
		if(WRByte&0x80)
		{
			SDA = 1;	
		}
		else
		{
			SDA = 0;
		}
		I2CDelay(10);
		SCL=1;			//���SDA�ȶ�������SCL���������أ��ӻ���⵽��������ݲ���
		I2CDelay(50);
		SCL=0;
		I2CDelay(10);
		WRByte <<= 1;
	} 
	SDA = 1;
	SCL = 1;
	I2CDelay(20);
	if(SDA==1)			//SDAΪ�ߣ��յ�NACK
	{
		SCL=0;
		I2CDelay(50);
		return ACK_ERROR;	
	}
	else 				//SDAΪ�ͣ��յ�ACK
	{
		SCL=0;
		I2CDelay(50);
		return NO_ERROR;
	}
}
/*================================================================
���� �ơ�unsigned char I2CRDByte(unsigned char AckValue)
���� �ܡ�I2C��һ���ֽ����ݣ���ڲ������ڿ���Ӧ��״̬��ACK����NACK
���� ע���Ӹߵ��ͣ����ν���
���� �ߡ�
��ʱ �䡿
================================================================*/
unsigned char I2CRDByte(unsigned char AckValue)
{
	unsigned char i,RDByte=0;
	SCL = 0;
	SDA = 1;			//�ͷ�����	
	for (i=0;i<8;i++) 
	{
		RDByte <<= 1;	//��λ
		SCL = 1;		//����������
		I2CDelay(30);	//��ʱ�ȴ��ź��ȶ�
		if(SDA==1) 		//������ȡ����
		{
			RDByte |= 0x01;
		}
		else
		{
			RDByte &= 0xfe;
		}
		SCL = 0;   		//�½��أ��ӻ�������һλֵ
		I2CDelay(10);
	}   
	SDA =  AckValue;	//Ӧ��״̬
	I2CDelay(10);
	SCL = 1;                         
  	I2CDelay(50);          
  	SCL = 0;
  	SDA = 1;                
  	I2CDelay(1);
	return RDByte;
}
etError SHT3X_WriteCommand(etCommands cmd){
//==============================================================================
  etError error; // error code
  // write the upper 8 bits of the command to the sensor
  error  = I2CWRByte(cmd >> 8);
  // write the lower 8 bits of the command to the sensor
  error |= I2CWRByte(cmd & 0xFF);
	
  return error;
}
/*================================================================
���� �ơ�void SHT3XInit(void)
���� �ܡ�SHT3X��ʼ���������������е���
���� ע��
���� �ߡ�
��ʱ �䡿
================================================================*/
void SHT3XInit(void)
{

	I2CInit();//I2C��ʼ��
//	I2CStart();
//  I2CWRByte(SHT3XWriteHeader);
//	SHT3X_WriteCommand(CMD_CLEAR_STATUS); //
//	I2CStop();
//	
	
  I2CStart();
  I2CWRByte(SHT3XWriteHeader);
	SHT3X_WriteCommand(CMD_MEAS_PERI_1_H); //1��߾���ѭ������ģʽ
	I2CStop();
	
	
}




//==============================================================================ѭ����ȡģʽ
etError SHT3X_XHGetTempAndHumi(int        *temp,
                               int        *humi){
//==============================================================================
  etError error;           // error code
  unsigned long int    rawValueTemp;    // temperature raw value from sensor
  unsigned long int    rawValueHumi;    // humidity raw value from sensor
	unsigned char Rdata[6]={0};
  unsigned char i;																			 
  I2CStart();
  error  = I2CWRByte(SHT3XWriteHeader);
  // if no error ...
  if(error == NO_ERROR)
  {
    // start measurement in polling mode
    // use depending on the required repeatability, the corresponding command
     error = SHT3X_WriteCommand(CMD_FETCH_DATA);
  }
  // if no error, wait until measurement ready
  if(error == NO_ERROR)
  {
	 	I2CStart();
     error = I2CWRByte(SHT3XReadHeader);
      // if measurement has finished -> exit loop
  }
	// if no error, read temperature and humidity raw values
  if(error == NO_ERROR)
  {
		for(i=0;i<5;i++)
		{
			Rdata[i] = I2CRDByte(ACK);
		}
    Rdata[i] = I2CRDByte(NACK);
		I2CStop();
		if(Rdata[2]!=SHT3X_CalcCrc(Rdata,2))     error = CHECKSUM_ERROR;
	  if(Rdata[5]!=SHT3X_CalcCrc(&Rdata[3],2)) error = CHECKSUM_ERROR;	
  }
  // if no error, calculate temperature in  and humidity in %RH
  if(error == NO_ERROR)
  {
		rawValueTemp =(Rdata[0] << 8) | Rdata[1];
		rawValueHumi =(Rdata[3] << 8) | Rdata[4];
    *temp =(int)(1750 *rawValueTemp / 65535 - 450);
    *humi =(int)(1000 *rawValueHumi / 65535);
  }
  return error;
}






////==============================================================================  ���ζ�ȡģʽ
//etError SHT3X_GetTempAndHumi(int        *temp,
//                                     int         *humi,
//                                     etRepeatab repeatab,
//                                     unsigned char   timeout){
////==============================================================================
//  etError error;           // error code
//  unsigned long int    rawValueTemp;    // temperature raw value from sensor
//  unsigned long int    rawValueHumi;    // humidity raw value from sensor
//	unsigned char Rdata[6]={0};
//  unsigned char i;																			 
//  I2CStart();
//  error  = I2CWRByte(SHT3XWriteHeader);

//  // if no error ...
//  if(error == NO_ERROR)
//  {
//    // start measurement in polling mode
//    // use depending on the required repeatability, the corresponding command
//    switch(repeatab)
//    {
//      case REPEATAB_LOW:    error = SHT3X_WriteCommand(CMD_MEAS_POLLING_L); break;
//      case REPEATAB_MEDIUM: error = SHT3X_WriteCommand(CMD_MEAS_POLLING_M); break;
//      case REPEATAB_HIGH:		 error = SHT3X_WriteCommand(CMD_MEAS_POLLING_H); break;
//      default:         		 error = PARM_ERROR; break;
//    }
//  }
//	
//	
//  
//  // if no error, wait until measurement ready
//  if(error == NO_ERROR)
//  {
//    // poll every 1ms for measurement ready until timeout
//    while(timeout--)
//    {
//      // check if the measurement has finished
//			I2CStop();
//			
//			I2CStart();
//      error = I2CWRByte(SHT3XReadHeader);

//      // if measurement has finished -> exit loop
//      if(error == NO_ERROR) break;

//      // delay 1ms
//      Delay1ms();
//    }
//		 
//		// check for timeout error
//		if(timeout == 0) error = TIMEOUT_ERROR;
//  }
//	
//	// if no error, read temperature and humidity raw values
//  if(error == NO_ERROR)
//  {
//		for(i=0;i<5;i++)
//		{
//			Rdata[i] = I2CRDByte(ACK);
//		}
//    Rdata[i] = I2CRDByte(NACK);
//		I2CStop();
//		if(Rdata[2]!=SHT3X_CalcCrc(Rdata,2))     error = CHECKSUM_ERROR;
//	  if(Rdata[5]!=SHT3X_CalcCrc(&Rdata[3],2)) error = CHECKSUM_ERROR;	
//  }
//  // if no error, calculate temperature in  and humidity in %RH
//  if(error == NO_ERROR)
//  {
//		rawValueTemp =(Rdata[0] << 8) | Rdata[1];
//		rawValueHumi =(Rdata[3] << 8) | Rdata[4];
//    *temp =(int)( 1750 *rawValueTemp / 65535 - 450);
//    *humi =(int)(1000 *rawValueHumi / 65535);
//  }
//  return error;
//}

