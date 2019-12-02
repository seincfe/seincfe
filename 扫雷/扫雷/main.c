#include "game.h"
int main()
{
	int input;
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("游戏开始了\n");
			game();  //进入游戏函数
			break;
		case 0:
			printf("感谢使用\n");
			break;
		default:
			printf("请输入正确的指令\n");
		}
	} while (input);  //输入0时为假，跳出循环退出程序
}