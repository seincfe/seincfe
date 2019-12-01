#include"game.h"  //将所有头文件放在game.h中
void menu()  //输出菜单
{
	printf("****************\n");
	printf("*****0.exit*****\n");
	printf("*****1.play*****\n");
	printf("****************\n");
}
void InitBoard(char board[][ROW], int row, int col, char set)  //初始化数组,set均为‘ ’
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = set;
		}
	}
}
void ShowBoard(char board[][ROW], int row, int col)  //输出三子棋盘
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)  //在第一列和第二列后输出'|'
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < col - 1)
		{

			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)//两个'|'拼成一个大竖线，所以在第一列和第二列后再输出'|'
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}
void PlayerMove(char board[][ROW], int row, int col)  //玩家下棋
{
	int x, y;
	while (1)
	{
		printf("玩家移动\n");
		printf("请输入1 - 3的坐标:\n");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= 3 && y > 0 && y <= 3)  //判断下棋位置是否合法
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'x';  //若合法，则玩家在这个位置棋子为'x'
				break;
			}
			else
			{
				printf("提示：此坐标已经被占了\n");  //若合法但是位置已经被占用，则不能将棋子下在这个位置，再循环
			}
		}
		else
		{
			printf("输入坐标不合法\n");  //数组外的坐标均不合法，再循环
		}

	}
}
void ComputerMove(char board[][ROW], int row, int col)  //电脑下棋
{

	while (1)
	{
		int x = rand() % 3;  //生成随机数
		int y = rand() % 3;  //生成随机数
		printf("电脑移动\n");
		if (board[x][y] == ' ')  //当这个坐标没有占用时可以落子，否则再循环
		{
			board[x][y] = 'o';
			break;
		}
	}
}
static int Full(char board[][ROW], int row, int col)  //没人赢得情况下判断棋盘是否满了
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')  //当还有坐标是' '时，棋盘没满
			{
				return 0;  //棋盘没满，返回假
			}
		}
	}
	return 1;  //返回真
}
char Win(char board[][ROW], int row, int col)  //判断是否胜利
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')//有行相同
		{
			return board[i][0];
		}
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')//有列相同
		{
			return board[0][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')//左对角线相同
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')//右对角线相同
	{
		return board[0][2];
	}
	if (Full(board, row, col))  //判断返回的是真是假
	{
		return 'Q';  //棋盘满了且无人赢为真，平局
	}
	return 'W';  //棋盘没满没人赢  
}


void game()
{
	char board[3][3] = { 0 };
	InitBoard(board, ROW, ROW, ' ');  //初始化数组
	ShowBoard(board, ROW, ROW);  //输出当前数组
	char ret = 0;
	while (1)  //循环，有人赢或平局就跳出
	{
		PlayerMove(board, ROW, ROW);  //玩家移动
		ret = Win(board, ROW, ROW);  //判断每轮玩家落子后赢或平局
		if (ret != 'W')
		{
			break;
		}
		ShowBoard(board, ROW, ROW);  //输出每轮玩家落子后数组
		ComputerMove(board, ROW, ROW);  //电脑移动
		ret = Win(board, ROW, ROW);  //判断每轮电脑落子后赢或平局
		if (ret != 'W')
		{
			break;
		}
		ShowBoard(board, ROW, ROW);  //输出每轮电脑落子后数组
	}
	if (ret == 'x')  //若x先三子相连则玩家赢
	{
		printf("玩家赢了\n");
	}
	else if (ret == 'o')  //若o先三子相连则电脑赢
	{
		printf("电脑赢了\n");
	}
	else if (ret == 'Q')  //若棋盘满了且无人赢为真则为平局
	{
		printf("平局\n");
	}
}
