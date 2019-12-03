#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<time.h>
#include <windows.h>
#define UI_WIDTH 14 //显示界面的宽度
#define UI_HEIGHT 25 //界面的高度
#define WALL 1
#define BLOCK 2
#define VK_UP 72   //方向键上下左右的第二个值,方向键有两个值,第一个是224,分别是72,...
#define VK_DOWN 80
#define VK_LEFT 75
#define VK_RIGHT 77
#define TRUE 1
#define FALSE 0
void initia();			//初始化的一些工作
void gameShow(); 	/*游戏显示界面*/
void moveBlock(); 	/*方块的移动*/
short isCanMoveBlock(short x, short y); 	//是否能移动方块
void produceBlock();   //产生方块
void toBottom(short x, short y);				//方块到底了之后的操作 ，bottom：底
short cur_block_coord_x, cur_block_coord_y; //当前方块的横坐标及纵坐标
//int game_arr[UI_HEIGHT][UI_WIDTH]; //游戏的界面数组
short next_blockarr[4][4];			//用来存放下一个方块的数组
short cur_boxindex, next_boxindex; //记录当前方块的下标和下一个方块的下标
int score;  //成绩
char player_name[10] = "你大哥";    //玩家的姓名
HANDLE hOutput;
struct _game_arr {
	short info;  //用来存放游戏界面的数组
	short  var;  //用来记录该数组的某个位置是否被占用 ，当方块没有移动了，
	//该位置才被占用，当移动方块是那个地方被占用就不能移动了 ,用1表示占用，0表示未占用
}game_arr[UI_HEIGHT][UI_WIDTH];
struct _block
{
	short a[4][2]; /*定义方块形状的数组，每个方块共有4个小块组成，
	 用4行2列来记录每个小方块的相对 坐标， */
	short next; //下一个方块的号码
};
struct _block block[19] =
{  //初始化各个游戏方块, 总共有19总方块形状
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