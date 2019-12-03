#include"game.h"
void initia()
{
	//��ʼ����һЩ����
	short i, j;
	for (i = 0; i < UI_HEIGHT; i++)
	{
		for (j = 0; j < UI_WIDTH; j++)
		{
			if (i == 0 || i == UI_HEIGHT - 1) { game_arr[i][j].info = WALL; game_arr[i][j].var = 1; continue; }  //.var=1��ʾ�õ㱻ռ��
			if (j == 0 || j == UI_WIDTH - 1) { game_arr[i][j].info = WALL; game_arr[i][j].var = 1; continue; }
		}
	}
	printf("\n\n\t��ӭ��ĵ���\n\t��������һ���ǳư�!>:");
	scanf("%s", &player_name);
	next_boxindex = rand() % 19;	 //��һ��Ҫ���������������
}
/*��Ϸ��ʾ����*/
void gameShow()
{
	//1��ʾ�߿򣬿ո񣬷���
	short i, j;
	system("cls");
	puts("\n\t\t<����˹����>");
	for (i = 0; i < UI_HEIGHT; i++)
	{
		for (j = 0; j < UI_WIDTH; j++)
		{
			if (game_arr[i][j].info == 0) { printf("��"); continue; }
			if (game_arr[i][j].info == WALL)
			{
				if (i == 0 || i == UI_HEIGHT - 1) printf("��");//����
				else printf("��"); continue;
			}
			if (game_arr[i][j].info == BLOCK) printf("��");
		}
		if (i == 1)  printf("  ��һ������");
		if (i >= 2 && i <= 5) //��һ������
		{
			printf("  ");
			for (j = 0; j < 4; j++)
			{
				if (next_blockarr[i - 2][j] == 0) printf("  "); //Ҫ��2����Ϊ��i�´�2��ʼ��
				else printf("��");
			}
		}
		if (i == 10) printf("  ��ң�%s", player_name);
		if (i == 11) printf("  �÷֣�%d", score);
		if (i == UI_HEIGHT - 6) printf("  ����");
		if (i == UI_HEIGHT - 5) printf("  ����ת");
		if (i == UI_HEIGHT - 4) printf("  ������");
		if (i == UI_HEIGHT - 3) printf("  ������");
		if (i == UI_HEIGHT - 2) printf("  ������");
		printf("\n");
	}
}
/*ÿһ������Ĳ���*/
void produceBlock()
{
	//����Ϸ������м���÷���
	short i, j;
	cur_boxindex = next_boxindex;
	next_boxindex = rand() % 19; //����ı���������
	cur_block_coord_x = (UI_WIDTH - 2) / 2; //���м�����
	cur_block_coord_y = 1;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			next_blockarr[i][j] = 0; //ÿ�β����µķ��飬��Ҫ�������һ���������������
	for (i = 0; i < 4; i++)
	{
		game_arr[cur_block_coord_y + block[cur_boxindex].a[i][1]][cur_block_coord_x + block[cur_boxindex].a[i][0]].info = BLOCK;
		next_blockarr[block[next_boxindex].a[i][1]][block[next_boxindex].a[i][0]] = BLOCK;
	}
	if (!isCanMoveBlock(cur_block_coord_x, cur_block_coord_y))  //�����·��������ط���ռ���ˣ��˳�
	{
		printf("��Ϸ�������ٽ�������"); getch(); exit(0);
	}
}
/*������ƶ�*/
void moveBlock()
{
	short i, j = 0, to_bottom = FALSE;	//����
	short old_x = cur_block_coord_x, old_y = cur_block_coord_y; //������¼�ɵķ����λ��
	short old_boxindex = cur_boxindex;    //��¼������±꣬���ϼ�ʱ�ı䷽����
	while (1)
	{
		old_x = cur_block_coord_x, old_y = cur_block_coord_y;
		old_boxindex = cur_boxindex;
		while (kbhit())  //�û�����
		{  // getch();
			switch (getch())
			{
			case VK_UP:   cur_boxindex = block[cur_boxindex].next;
				if (!isCanMoveBlock(cur_block_coord_x, cur_block_coord_y))
					cur_boxindex = old_boxindex;  //���������ת�Ļ�Ҫ��ԭ
				break;
			case VK_DOWN: for (i = 0; i < 4; i++) //һ�ο����½�4��
				if (isCanMoveBlock(cur_block_coord_x, cur_block_coord_y + 1)) cur_block_coord_y++;
				else { to_bottom = TRUE; break; }//����
						  break;
			case VK_LEFT:  if (isCanMoveBlock(cur_block_coord_x - 1, cur_block_coord_y)) cur_block_coord_x--;
				break;
			case VK_RIGHT: if (isCanMoveBlock(cur_block_coord_x + 1, cur_block_coord_y)) cur_block_coord_x++;
				break;
			}
		}
		if (to_bottom)
		{
			if (old_x != cur_block_coord_x || old_y != cur_block_coord_y || old_boxindex != cur_boxindex)
			{
				for (i = 0; i < 4; i++)
					game_arr[old_y + block[old_boxindex].a[i][1]][old_x + block[old_boxindex].a[i][0]].info = 0;
				for (i = 0; i < 4; i++)
					game_arr[cur_block_coord_y + block[cur_boxindex].a[i][1]][cur_block_coord_x + block[cur_boxindex].a[i][0]].info = BLOCK;
				gameShow();  //Ҫ����֮���ˢ��
			}
			to_bottom = FALSE; toBottom(cur_block_coord_x, cur_block_coord_y); gameShow();//����
		}
		else
		{
			if (j++ % 10 == 0)  //�Զ�����,Ҫ��ǰ�棬
			{
				if (isCanMoveBlock(cur_block_coord_x, cur_block_coord_y + 1)) cur_block_coord_y++;
				else  to_bottom = TRUE; //����
			}
			if (old_x != cur_block_coord_x || old_y != cur_block_coord_y || old_boxindex != cur_boxindex)
			{
				for (i = 0; i < 4; i++)
					game_arr[old_y + block[old_boxindex].a[i][1]][old_x + block[old_boxindex].a[i][0]].info = 0;
				for (i = 0; i < 4; i++)
					game_arr[cur_block_coord_y + block[cur_boxindex].a[i][1]][cur_block_coord_x + block[cur_boxindex].a[i][0]].info = BLOCK;
				gameShow();  //Ҫ����֮���ˢ��
			}
		}
		Sleep(20);
	}
}
short isCanMoveBlock(short x, short y)
{
	//�Ƿ����ƶ�����
	short i;
	for (i = 0; i < 4; i++)
		if (game_arr[y + block[cur_boxindex].a[i][1]][x + block[cur_boxindex].a[i][0]].var)
			return FALSE;	//�����λ���Լ��з�����䣬�����ƶ�
	return TRUE;
}
void toBottom(short x, short y)
{	//���鵽��֮��Ĳ�����1.�������λ�õ�״̬��Ϊ1����ʾ��ռ�á�2.�Ƿ����飬���У��ı�״̬ 3.�����µķ���
	short i, j;
	for (i = 0; i < 4; i++)
		game_arr[y + block[cur_boxindex].a[i][1]][x + block[cur_boxindex].a[i][0]].var = 1;
	//2.�Ƿ����飬���У��ı�״̬
	for (i = UI_HEIGHT - 2; i >= 1; i--) //��������ǽ ,�ӵ׿�ʼ������
	{
		for (j = 1; j <= UI_WIDTH - 2; j++)
		{
			if (!game_arr[i][j].var)
				break;//һ���пյľ��������ѭ�� ����������һ��
			if (j == UI_WIDTH - 2) 	//һ�ж�����,����,��ʱ��i��������
			{
				score += 10;	int h, v;
				for (v = i; v >= 2; v--) //��i�п�ʼ,
				{
					for (h = 1; h <= UI_WIDTH - 2; h++)
					{
						game_arr[v][h].info = game_arr[v - 1][h].info;
						game_arr[v][h].var = game_arr[v - 1][h].var;
					}
				}//Ҫ�ӵ�������,֮��i--,i =  UI_HEIGHT - 2,�ͻ���ֶ���һ����ʱ����������
				i = UI_HEIGHT - 1;
			}
		}
	}produceBlock();
}