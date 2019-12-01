#include"game.h"  //������ͷ�ļ�����game.h��
void menu()  //����˵�
{
	printf("****************\n");
	printf("*****0.exit*****\n");
	printf("*****1.play*****\n");
	printf("****************\n");
}
void InitBoard(char board[][ROW], int row, int col, char set)  //��ʼ������,set��Ϊ�� ��
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
void ShowBoard(char board[][ROW], int row, int col)  //�����������
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)  //�ڵ�һ�к͵ڶ��к����'|'
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
				if (j < col - 1)//����'|'ƴ��һ�������ߣ������ڵ�һ�к͵ڶ��к������'|'
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}
void PlayerMove(char board[][ROW], int row, int col)  //�������
{
	int x, y;
	while (1)
	{
		printf("����ƶ�\n");
		printf("������1 - 3������:\n");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= 3 && y > 0 && y <= 3)  //�ж�����λ���Ƿ�Ϸ�
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'x';  //���Ϸ�������������λ������Ϊ'x'
				break;
			}
			else
			{
				printf("��ʾ���������Ѿ���ռ��\n");  //���Ϸ�����λ���Ѿ���ռ�ã����ܽ������������λ�ã���ѭ��
			}
		}
		else
		{
			printf("�������겻�Ϸ�\n");  //���������������Ϸ�����ѭ��
		}

	}
}
void ComputerMove(char board[][ROW], int row, int col)  //��������
{

	while (1)
	{
		int x = rand() % 3;  //���������
		int y = rand() % 3;  //���������
		printf("�����ƶ�\n");
		if (board[x][y] == ' ')  //���������û��ռ��ʱ�������ӣ�������ѭ��
		{
			board[x][y] = 'o';
			break;
		}
	}
}
static int Full(char board[][ROW], int row, int col)  //û��Ӯ��������ж������Ƿ�����
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')  //������������' 'ʱ������û��
			{
				return 0;  //����û�������ؼ�
			}
		}
	}
	return 1;  //������
}
char Win(char board[][ROW], int row, int col)  //�ж��Ƿ�ʤ��
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')//������ͬ
		{
			return board[i][0];
		}
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')//������ͬ
		{
			return board[0][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')//��Խ�����ͬ
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')//�ҶԽ�����ͬ
	{
		return board[0][2];
	}
	if (Full(board, row, col))  //�жϷ��ص������Ǽ�
	{
		return 'Q';  //��������������ӮΪ�棬ƽ��
	}
	return 'W';  //����û��û��Ӯ  
}


void game()
{
	char board[3][3] = { 0 };
	InitBoard(board, ROW, ROW, ' ');  //��ʼ������
	ShowBoard(board, ROW, ROW);  //�����ǰ����
	char ret = 0;
	while (1)  //ѭ��������Ӯ��ƽ�־�����
	{
		PlayerMove(board, ROW, ROW);  //����ƶ�
		ret = Win(board, ROW, ROW);  //�ж�ÿ��������Ӻ�Ӯ��ƽ��
		if (ret != 'W')
		{
			break;
		}
		ShowBoard(board, ROW, ROW);  //���ÿ��������Ӻ�����
		ComputerMove(board, ROW, ROW);  //�����ƶ�
		ret = Win(board, ROW, ROW);  //�ж�ÿ�ֵ������Ӻ�Ӯ��ƽ��
		if (ret != 'W')
		{
			break;
		}
		ShowBoard(board, ROW, ROW);  //���ÿ�ֵ������Ӻ�����
	}
	if (ret == 'x')  //��x���������������Ӯ
	{
		printf("���Ӯ��\n");
	}
	else if (ret == 'o')  //��o���������������Ӯ
	{
		printf("����Ӯ��\n");
	}
	else if (ret == 'Q')  //����������������ӮΪ����Ϊƽ��
	{
		printf("ƽ��\n");
	}
}
