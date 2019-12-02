#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _GAME_H_
#define _GAME_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW   10  //棋盘行
#define COL   10  //棋盘列
#define ROWS  12  //内部运行行
#define COLS  12  //内部运行列
#define MINE_NUM 20  //地雷数量
void menu();  //打印菜单
void game();  //开始游戏
void Show(char board[][ROWS], int row, int col);  //打印棋盘
void InitBoard(char board[][COLS], char mine[][COLS], int row, int col);  //棋盘初始化
void SetMine(char mine[][COLS], int row, int col, int num);  //设置雷
int FindMine(char mine[][ROWS], char board[][ROWS]);  //扫雷
int GetMineCount(char mine[][ROWS], int row, int col);  //计算附近雷数量
int Set_Assist(int i, int arr[], int brr[], int x, int y);  //设置雷的辅助函数
#endif