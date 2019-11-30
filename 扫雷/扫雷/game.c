#include "game.h"
int row = 0, col = 0;
void menu()  //��ӡ�˵�
{
	printf("**********************\n");
	printf("********1 play********\n");
	printf("********0 exit********\n");
	printf("**********************\n");
}
void game()  //��ʼ��Ϸ
{
	int result = 0, num = 0;
	char board[ROWS][COLS] = { 0 };
	char mine[ROWS][COLS] = { 0 };
	InitBoard(board, mine, ROWS, COLS);
	SetMine(mine, ROW, COL, MINE_NUM);
	while (1)
	{
		Show(board, ROW, COL);
		result = FindMine(mine, board);
		if (result == 1)
		{
			break;
		}
		else
		{
			num = GetMineCount(mine, row, col);
			board[row][col] = num + '0';  //�ַ�1-�ַ�0=����1
		}
	}
	if (result == 1)
	{
		printf("�㱻ը����\n");
		Show(board, ROW, COL);
	}
}
void InitBoard(char board[][COLS], char mine[][COLS], int row, int col)  //���̳�ʼ��
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = '*';
			mine[i][j] = '*';
		}
	}

}
void Show(char board[][ROWS], int row, int col)  ////��ӡ����
{
	int i = 1, j = 1;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			printf("%-3c", board[i][j]);
		}
		printf("\n");
	}
}
void SetMine(char mine[][COLS], int row, int col, int num)  //������
{
	int x = 0, y = 0, count = 0;
	int i = 1, arr[100], brr[100];
	srand((unsigned int)time(NULL));  //����ֲ����õ���
	x = rand() % ROW + 1;
	y = rand() % COL + 1;
	mine[x][y] = 'X';
	arr[0] = x, brr[0] = y;  //��֤���õ��ײ����ص�
	while (i < num)
	{
		do
		{
			x = rand() % ROW + 1;
			y = rand() % COL + 1;
		} while (count = Set_Assist(i, arr, brr, x, y));  //for (i=0;i<i;i++) if arr[i]==x&&brr[i]=y;return 1;break;
		mine[x][y] = 'X';
		arr[i] = x; brr[i] = y;
		i++;
	}
}
int GetMineCount(char mine[][ROWS], int x, int y)  //���㸽��������
{
	int count = 0;
	int i = x + 1, j = y + 1;
	for (x = x - 1; x <= i; x++)
	{
		for (y = y - 1; y <= j; y++)
		{
			if (mine[x][y] == 'X')
			{
				count++;
			}
		}
	}
	return count;
}
int FindMine(char mine[][ROWS], char board[][ROWS])  //ɨ��
{
	int count = 0;
	printf("���������꣺");
	scanf("%d%d", &row, &col);
	if (mine[row][col] == 'X')
	{
		board[row][col] = 'X';
		return 1;
	}
	else
	{
		return 0;
	}
}
int Set_Assist(int i, int arr[], int brr[], int x, int y)   //�����׵ĸ�������
{
	int j = 0;
	for (j = 0; j < i; j++)
	{
		if (arr[j] == x && brr[j] == y)
		{
			return 1;
			break;
		}
	}
	return 0;
}