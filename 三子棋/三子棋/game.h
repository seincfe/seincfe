#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __GAME__H_
#define __GAME__H_
#include <stdlib.h>
#include <stdio.h>
#define ROW 3
void menu();  //����˵�
void game();  //������Ϸ
void InitBoard(char board[][ROW], int row, int col, char set);  //��ʼ������
void ShowBoard(char board[][ROW], int row, int col);  //�����������
void PlayerMove(char board[][ROW], int row, int col);  //����ƶ�
void ComputerMove(char board[][ROW], int row, int col);  //�����ƶ�
char Win(char board[][ROW], int row, int col);  //�ж�ʤ������
static int Full(char board[][ROW], int row, int col);  //�ж������Ƿ�����
#endif
