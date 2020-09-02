#include "reg52.h"
typedef unsigned char u8;
typedef unsigned int u16;
sbit lcdrs = P2 ^ 6; //P2端口的第二个引脚地址
sbit lcden = P2 ^ 7;
sbit lcdrw = P2 ^ 5;

sbit led_red = P2 ^ 0;//红灯
sbit led_green = P2 ^ 1;//绿灯

sbit k3 = P3 ^ 2;  //定义按键K3,用于结束

//三个按键对应不同的情况
sbit yes = P2 ^ 2;
sbit no = P2 ^ 3;
sbit g_up = P2 ^ 4;

u8 yes_shi = 0, yes_ge = 0;
u8 no_shi = 0, no_ge = 0;
u8 g_up_shi = 0, g_up_ge = 0;

int Yes = 0, No = 0, G_up = 0;

u8  table[] = "      Yes**No**G_UP||";
u8  table1[] = "0123456789";
int i = 0;
int j = 1;//控制结束
void get_wei()//得到每一位
{
	yes_shi = Yes / 10;
	yes_ge = Yes % 10;
	no_shi = No / 10;
	no_ge = No % 10;
	g_up_shi = G_up / 10;
	g_up_ge = G_up % 10;

}
void delay(u16 i)//软件延迟函数
{
	while (i--);
}
void write_com(u8 com)//地址写入lcd显示屏
{
	lcdrs = 0;
	lcdrw = 0;
	P0 = com;
	delay(5);
	lcden = 1;
	delay(5);
	lcden = 0;
}
void write_data(u8 date)//lcd屏幕内容写入函数
{
	lcdrs = 1;
	lcdrw = 0;
	P0 = date;
	delay(5);
	lcden = 1;
	delay(5);
	lcden = 0;
}
void init()//lcd屏幕初始化
{
	lcden = 0;
	write_com(0x38);
	write_com(0x0C);
	write_com(0x06);
	write_com(0x01);
}
void Int0Init()
{
	//设置INT0
	IT0 = 1;//跳变沿出发方式（下降沿）
	EX0 = 1;//打开INT0的中断允许。	
	EA = 1;//打开总中断	
}
void Int0()	interrupt 0		//外部中断0的中断函数
{
	delay(1000);	 //消抖
	if (k3 == 0)
	{
		j = 0;
		if (Yes > No)
		{
			led_green = 0;
			delay(10000);delay(10000); delay(10000); delay(10000); delay(10000); delay(10000); delay(10000);
			delay(10000); delay(10000); delay(10000); delay(10000);
			led_green = 1;
		}
		if (Yes < No)
		{
			led_red = 0;
			delay(10000);delay(10000); delay(10000); delay(10000); delay(10000); delay(10000); delay(10000);
			delay(10000); delay(10000); delay(10000); delay(10000);
			led_red = 1;
		}
		if (Yes == No)
		{
			led_green = 0;
			led_red = 0;
			delay(10000);delay(10000); delay(10000); delay(10000); delay(10000); delay(10000); delay(10000);
			delay(10000); delay(10000); delay(10000); delay(10000)
			led_green = 1;
			led_red = 1;
		}
	}
}
void main()
{
	int num = 0;
	Int0Init();
	init();
	write_com(0x80);
	for (i = 0; i < 22; i++)
	{
		write_data(table[i]);
		delay(5);
	}
	delay(5);
	while (j)
	{
		if (yes == 0)
		{
			delay(10);
			while (yes == 0)  //消抖
			{
			}
			Yes++;
		}
		if (no == 0)
		{
			delay(10);
			while (no == 0)
			{
			}
			No++;
		}
		if (g_up == 0)
		{
			delay(10);
			while (g_up == 0)
			{
			}
			G_up++;
		}
		get_wei();
		write_com(0x80 + 0x40);
		write_data(table1[yes_shi]);
		write_com(0x80 + 0x41);
		write_data(table1[yes_ge]);
		write_com(0x80 + 0x46);
		write_data(table1[no_shi]);
		write_com(0x80 + 0x47);
		write_data(table1[no_ge]);
		write_com(0x80 + 0x4A);
		write_data(table1[g_up_shi]);
		write_com(0x80 + 0x4B);
		write_data(table1[g_up_ge]);
	}
}
