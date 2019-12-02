#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __GAME__H_
#define __GAME__H_
#include <stdlib.h>
#include <stdio.h>
#define ROW 3
void menu();  //输出菜单
void game();  //进行游戏
void InitBoard(char board[][ROW], int row, int col, char set);  //初始化数组
void ShowBoard(char board[][ROW], int row, int col);  //输出三子棋盘
void PlayerMove(char board[][ROW], int row, int col);  //玩家移动
void ComputerMove(char board[][ROW], int row, int col);  //电脑移动
char Win(char board[][ROW], int row, int col);  //判断胜利条件
static int Full(char board[][ROW], int row, int col);  //判断棋盘是否满了
#endif
