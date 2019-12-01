#include "game.c"
int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请输入你的选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏退出\n");
			break;
		default:
			printf("请输入正确的操作\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}
