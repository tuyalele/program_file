#define	UART1_BUF_LENGTH	32
#define	UART2_BUF_LENGTH	32




void	UART1_config(u8 brt);	// ѡ������, 2: ʹ��Timer2��������, ����ֵ: ʹ��Timer1��������.
void	UART2_config(u8 brt);	// ѡ������, 2: ʹ��Timer2��������, ����ֵ: ��Ч.


void Printchar1(char Data);//���ַ�
void 	PrintString1(u8 *puts);//���ַ���
void 	PrintD1(const char *str);//������
void PrintN1(int num);//����ֵ





void 	PrintString2(u8 *puts);//���ַ���
void Printchar2(char Data);//���ַ�