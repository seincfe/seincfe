#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<time.h>
#include <windows.h>
#define UI_WIDTH 14 //��ʾ����Ŀ��
#define UI_HEIGHT 25 //����ĸ߶�
#define WALL 1
#define BLOCK 2
#define VK_UP 72   //������������ҵĵڶ���ֵ,�����������ֵ,��һ����224,�ֱ���72,...
#define VK_DOWN 80
#define VK_LEFT 75
#define VK_RIGHT 77
#define TRUE 1
#define FALSE 0
void initia();			//��ʼ����һЩ����
void gameShow(); 	/*��Ϸ��ʾ����*/
void moveBlock(); 	/*������ƶ�*/
short isCanMoveBlock(short x, short y); 	//�Ƿ����ƶ�����
void produceBlock();   //��������
void toBottom(short x, short y);				//���鵽����֮��Ĳ��� ��bottom����
short cur_block_coord_x, cur_block_coord_y; //��ǰ����ĺ����꼰������
//int game_arr[UI_HEIGHT][UI_WIDTH]; //��Ϸ�Ľ�������
short next_blockarr[4][4];			//���������һ�����������
short cur_boxindex, next_boxindex; //��¼��ǰ������±����һ��������±�
int score;  //�ɼ�
char player_name[10] = "����";    //��ҵ�����
HANDLE hOutput;
struct _game_arr {
	short info;  //���������Ϸ���������
	short  var;  //������¼�������ĳ��λ���Ƿ�ռ�� ��������û���ƶ��ˣ�
	//��λ�òű�ռ�ã����ƶ��������Ǹ��ط���ռ�þͲ����ƶ��� ,��1��ʾռ�ã�0��ʾδռ��
}game_arr[UI_HEIGHT][UI_WIDTH];
struct _block
{
	short a[4][2]; /*���巽����״�����飬ÿ�����鹲��4��С����ɣ�
	 ��4��2������¼ÿ��С�������� ���꣬ */
	short next; //��һ������ĺ���
};
struct _block block[19] =
{  //��ʼ��������Ϸ����, �ܹ���19�ܷ�����״
	{1,1,1,2,1,3,2,3,1},
	{0,2,1,2,2,2,0,3,2},
	{0,1,1,1,1,2,1,3,3},
	{2,1,0,2,1,2,2,2,0},
	{1,1,1,2,0,3,1,3,5},
	{0,1,0,2,1,2,2,2,6},
	{1,1,2,1,1,2,1,3,7},
	{0,2,1,2,2,2,2,3,4},
	{1,1,0,2,1,2,2,2,9},
	{1,1,1,2,2,2,1,3,10},
	{0,2,1,2,2,2,1,3,11},
	{1,1,0,2,1,2,1,3,8},
	{1,1,1,2,2,2,2,3,13},
	{1,2,2,2,0,3,1,3,12},
	{2,1,1,2,2,2,1,3,15},
	{0,2,1,2,1,3,2,3,14},
	{1,0,1,1,1,2,1,3,17},
	{0,2,1,2,2,2,3,2,16},
	{1,1,2,1,1,2,2,2,18},
};