#define	UART1_BUF_LENGTH	32
#define	UART2_BUF_LENGTH	32




void	UART1_config(u8 brt);	// 选择波特率, 2: 使用Timer2做波特率, 其它值: 使用Timer1做波特率.
void	UART2_config(u8 brt);	// 选择波特率, 2: 使用Timer2做波特率, 其它值: 无效.


void Printchar1(char Data);//发字符
void 	PrintString1(u8 *puts);//发字符串
void 	PrintD1(const char *str);//发数组
void PrintN1(int num);//发数值





void 	PrintString2(u8 *puts);//发字符串
void Printchar2(char Data);//发字符
